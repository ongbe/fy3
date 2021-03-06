inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
    "$n一个月上柳梢头出白虎门，入天地门，随着$N的攻势飘起，从容躲过这一招。\n",
    "$n使出一招大漠孤烟直，出青龙门，入风云门，猛然纵起丈余，结果$N扑了个空。\n",
    "$n身形一摇，出天地门，入青龙门，幻出几个人影，一招碎影舞斜阳躲过了$N的攻势。\n",
    "$n一招燕子三抄水纵身跃起，出风云门，入玄武门，倏忽已落至$N身后。\n",
    "$n左一摇，右一晃，出玄武门，入朱雀门，一招云深不知处已轻松闪过。\n",
    "$n双足一点，出朱雀门，入白虎门，斜斜飞起，使出斜日杏花飞已闪到$N身侧。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge");
}
int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
            return notify_fail("你的体力太差了，不能练暗影浮香。\n");
        me->receive_damage("kee", 30);
        return 1;
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 1.5;	}
