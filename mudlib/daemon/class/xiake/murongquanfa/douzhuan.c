// zhen.c 太极拳「震」字诀

#include <ansi.h>

inherit SSERVER;
int perform(object me,object target)
{
	int damage;
	string msg;
	string limb,*limbs,attack_skill,attack;
	object weapon;
	mapping my,your,action;
	if( !target ) target = offensive_target(me);

	if(!target||!target->is_character() || !me->is_fighting(target) )
	return notify_fail("斗转星移只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("murongquanfa",1)<40)
	return notify_fail("你的慕容拳法不够娴熟，不会使用「斗转星移」。\n");
	if( (int)me->query_skill("murongxinfa",1)<40)
	return notify_fail("你的慕容心法不够深厚，不会使用「斗转星移」。\n");
	                        
			
	if( (int)me->query("force",1)<200)
	return notify_fail("你现在内力太弱，不能使用「斗转星移」。\n");
			
	msg=CYN"$N身形虚晃，施展「斗转星移」神功！！\n"NOR;

	me->start_busy(3);
		target->start_busy(random(3));
		
	damage = (int)me->query_skill("murongquanfa",1);
		
		damage = damage/2 + random(damage);
		
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/3);
	me->add("force",-damage/10);
		
	weapon=target->query_temp("weapon");
	if(objectp(weapon))	attack_skill=weapon->query("skill_type");
	else				attack_skill="unarmed";
	attack=target->query_skill_mapped(attack_skill);
	if(!attack)	attack=attack_skill;
	msg +=CYN"$N突然使出$n所学的"+to_chinese(attack)+"！以彼之道还施彼身！\n"NOR;
//	my=target->query_entire_dbase();
//	your=me->query_entire_dbase();
		limbs=target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
	action=target->query("actions");
        if( !mapp(action) ) {
		target->reset_action();
		action=target->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"),
	target->query("actions",1)));
                        return 0;
                }
        }
	msg += action["action"]+"！\n";
	msg+=RED"$n惊慌失措之中躲闪不及，结果在$l造成"+action["damage_type"]+"！！\n\n"NOR;
	msg=replace_string(msg,"$l",limb);
	if(objectp(weapon)) msg=replace_string(msg,"$w",weapon->name());
//	msg +=RED"$n惊慌失措之中躲闪不及，只觉眼前一黑。\n"NOR;
	message_vision(msg, me, target);

	return 1;
}
