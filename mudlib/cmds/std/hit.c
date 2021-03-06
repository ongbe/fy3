// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");
/*
	if( !living(obj) )
		return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 
*/

	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");

	if( userp(obj) ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
攻击某人。
 
其他相关指令: kill

HELP
    );
    return 1;
}
 
