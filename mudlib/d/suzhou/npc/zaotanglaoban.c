// music   yangzhou's 店小二
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("澡堂老板",({"zaotang laoban","laoban"}));
	set("gender", "男性" );
	set("age", 20);
	set("long",
	"此地澡堂的大老板。\n");
	set("combat_exp",200);
	set_temp("apply/defense",10);
	set_temp("apply/attack",5);
	set("attitude", "friendly");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
	command("say 洗一次一两银子，这是苏州最便宜的价了。");
			break;
		case 1:
	command("say 男客请往西走，女客东边。您老可别走错了地。");
			break;
                           }
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 100) 
	{
	tell_object(who,CYN"澡堂老板满脸堆欢道：您老请进。\n"NOR);

		who->set_temp("rent_paid",1);

// for if back money to who post in wizroom

		return 1;
	}

	return 0;
}
