// qufeng.c 驱蜂之术
// By Lgg,1998.9

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("驱蜂之术只能靠学习来提高。\n");
}
