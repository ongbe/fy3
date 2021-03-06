// perform2.c    昆仑绝招之二    绝地风暴(KKND)  write by Wangzc & ppl.
//                                                   1997.9.2

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("绝地风暴只能对战斗中的对手使用。\n");

		
    if( (int)me->query_skill("kunlun-jianfa",1)<80)
    return notify_fail("你的昆仑剑法不够娴熟，不会使用「绝地风暴」。\n");
     if( (int)me->query_skill("kunlun-xinfa",1)<80)
        return notify_fail("你的昆仑心法不够深厚，不会使用「绝地风暴」。\n"); 
			
    if( (int)me->query("force",1)<500)
    return notify_fail("你现在内力太弱，不能使用「绝地风暴」。\n");
			
 msg=HIY "$N衣衫无风自动，使出昆仑派的震山绝技「绝地风暴」。\n"
HIG "刹那间天昏地暗，飞沙走石，无数剑影向$n的全身要害或刺，或砍，或劈而去。\n" NOR;
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
{
        me->start_busy(3);
                target->start_busy(random(3));
		
    damage= (int)me->query_skill("kunlun-jianfa",1);
         damage = damage/2 + random(damage);
		
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/3);
	me->add("force",-damage/10);
        if( damage < 20 ) msg += HIY"结果$n被$N刺中了一剑，闷哼一声。\n"NOR;
else
if( damage < 55 ) msg += HIY"结果$n被$N连刺两剑，「啊」地一声退了两步。\n"NOR;
else if( damage < 80 ) msg += RED"结果$n被$N重重的连砍数剑，有如受到数记雷击一般，连退了五六步！\n"NOR;
else msg += HIR"结果$n被$N的「绝地风暴」剑透前心，眼前一黑，身子向后飞出丈许！！\n"NOR;
}
else
{
         me->start_busy(1);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
}
	message_vision(msg, me, target);

	return 1;
}
