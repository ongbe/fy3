// handu.c 寒冰剧毒
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("hanbing-mianzhang",1);

        if( !(me->is_fighting() ))
                return notify_fail("「寒冰剧毒」只能对战斗中的对手使用。\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你使用了武器。\n");

        if( skill < 120)
                return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「寒冰剧毒」！\n");

        if( me->query_skill("dodge",1) < 50 )
                return notify_fail("你的轻功不够，无法运用「寒冰剧毒」！\n");
        if( me->query_skill("neili",1) < 350 )
                return notify_fail("你的内力不够，无法运用「寒冰剧毒」！\n");
 
 
        msg = HIC "$N突然身形一闪，欺到$n的身前，双手忽然像$n推去。\n"NOR;
        message_vision(msg, me, target);
 
        ap = me->query("combat_exp") + skill * 400;
        dp = target->query("combat_exp") / 4;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-250);

                msg = HIG "$n只觉得身体一颤，全身软弱无力！\n"NOR;
                neili_wound = 160 + random(skill);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                qi_wound = neili_wound / 5;
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->start_busy(3);
                me->start_busy(random(2));
                target->apply_condition("icehd_poison",10);
        }
        else
        {
                msg = HIG " $n大吃一惊，慌忙间双手用尽全力拼死一抵，居然挡住了$N的寒毒！\n但是$N的寒毒还是被$n吸入少许\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                target->start_busy(4);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

