// taixuan 太玄掌

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("太玄掌只能对战斗中的对手使用。\n");


	if( (int)me->query_skill("xiake-shengong", 1) < 150 )
		return notify_fail("你的侠客神功不够娴熟，不能使用太玄掌。\n");

	msg = HIY "$N高高跃起使出太玄掌，招式陡然变快。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
	{
		attack_time = random((int)me->query_skill("xiake-shengong", 1) / 30);
		if(attack_time < 1)
			attack_time = 1;

		msg += HIW " 结果$p只见到$P漫天掌影带着凌厉的罡气向下压了过来！\n" NOR;
		for(i = 0; i < attack_time; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

		me->start_busy(2);
		me->add("force", -150);
	}
	else
	{
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
