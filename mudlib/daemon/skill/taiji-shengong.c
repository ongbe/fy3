// taiji-shengong.c 太极神功
// By Xiang
// Modified by Hop

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/"+func;
}
int message(object me)
{
message_vision(RED+"$N双掌虚抱如球，微闭双目，凝神吐纳.\n"NOR,me);
return 1;
}
int power_point()	{	return 1.5;	}
int hard_point()	{	return 2;	}
