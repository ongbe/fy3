// attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

static object *enemy = ({});
static string *killer = ({});

// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}


//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	object *guard;
	int i;

	if(environment(ob)->query("no_fight"))	return;
	if(!ob || ob==this_object()) return;
//	if(ob->query("env/no_combat_msg"))	ob->delete("env/no_combat_msg");
//	if( query("env/no_combat_msg"))		delete("env/no_combat_msg");

	set_heart_beat(1);

	guard=ob->query_temp("guarded");
	if(sizeof(guard))	{
		for(i=0;i<sizeof(guard);i++)	{
		if(! objectp(guard[i]))	continue;
		if(environment(guard[i])!=environment(ob))	continue;
                if(query_temp("war_biwu")) continue;
		if(guard[i]==this_object())	continue;
		if( member_array(guard[i], enemy)==-1 ) 
			enemy += ({ guard[i] });
			message_vision(HIC"$N的保护者"+guard[i]->query("name")+
			"加入战斗！\n"NOR,ob);
			guard[i]->fight_ob(this_object());
		}
	}
	if( member_array(ob, enemy)==-1 ) 
		enemy += ({ ob });
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	object *guard;
	int i;

	if( environment(ob)->query("no_fight"))	return;
	guard=ob->query_temp("guarded");
	if(sizeof(guard))	{
	for(i=0;i<sizeof(guard);i++)	{
		if(! objectp(guard[i]))	continue;
		if(environment(guard[i])!=environment(ob))	continue;
		if(guard[i]==this_object())	continue;
                if(query_temp("war_biwu")) continue;
		if(member_array(guard[i]->query("id"),killer)==-1)
			killer += ({ guard[i]->query("id") });
		}
	}

	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

        if( this_object()->query_temp("war_biwu") && ob->query_temp("war_biwu"))
         tell_object(ob, HIC + this_object()->name() + "身形一闪,向你发动攻击！\n" NOR);
           else
	tell_object(ob, HIR "看起来" + this_object()->name() + "想杀死你！\n" NOR);

	fight_ob(ob);
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))&& userp(this_object()))
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))&& !enemy[i]->is_killing(query("id")) && !userp(this_object())))
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;
	if( ob->is_killing(query("id"))&& !userp(this_object()))
		return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object ob1,ob2;
	string type1,type2,skill;

	if( ob1 = query_temp("weapon") )	{
		type1=ob1->query("skill_type");
// add by oldsix for second weapon
		if( ob2=query_temp("secondary_weapon"))	{
			type2=ob2->query("skill_type");
		}
	}
// add over
	else 
		type1 = "unarmed";

	if( stringp(skill = query_skill_mapped(type1)) ) {
		// If using a mapped skill, call the skill daemon.
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob1 ) set("actions", ob1->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}

if(stringp(type2))	{
	if( stringp(skill = query_skill_mapped(type2)) ) {
		// If using a mapped skill, call the skill daemon.
		set("actions2", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob2 ) set("actions2", ob2->query("actions",1) );
	}
}

}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player()) 
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

	if(stringp(query("banghui"))&& query("banghui")==(string)ob->query("banghui")&& !userp(this_object()) && userp(ob))	{
	if(! ob->is_killing(query("id")))
		remove_killer(ob);
	call_out("canjian",0,this_object(),ob);
	}

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("banghui"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} else if( random((int)query("bellicosity") / 40) > (int)query("cps") ) {
		COMBAT_D->auto_fight(this_object(), ob, "berserk");
		return;
	} 
	else if(! userp(this_object())&& userp(ob))
		ob->remove_killer(this_object());
}

void canjian(object ob,object me)
{
	if(! me || environment(me)!=environment(ob))	return;
	if(is_killing(me->query("id")))
	message_vision(HIC"$N大喝一声：$n，今天"+
	RANK_D->query_self_rude(ob)+"要讨个公道！\n"NOR,ob,me);
	else if(me->query("vendetta/" +ob->query("banghui")))
	message_vision(HIC"$N对着$n道："+RANK_D->query_self(ob)+
	"奉命行事，还请"+RANK_D->query_respect(me)+"多多担待。\n"NOR,ob,me);
	else if(! stringp(ob->query("bh_rank")))	{
		if(stringp(me->query("bh_rank")))
		message_vision(HIC"$N躬身对$n道：属下参见"+me->query("bh_rank")+"。\n"NOR,ob,me);
	}
}

