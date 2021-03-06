// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能用侠客神功来提升自己的战斗力。\n");

        if( (int)me->query("force") < 200  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
return notify_fail("你已经在运作中了。\n");

        skill = me->query_skill("force");
        me->add("force", -100);
        me->receive_damage("kee", 0);

        message_vision(
       HIR "$N运起侠客神功,全身顿时散发出令人窒息的霸气。\n" NOR, me);

        me->add_temp("apply/attack", skill/1);
        me->add_temp("apply/dodge", skill/1);
        me->add_temp("apply/defense", skill/1);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/defense", - amount);
       me->delete_temp("powerup");
        tell_object(me, "你的侠客神功运行完毕，将内力收回丹田。\n");}
}
