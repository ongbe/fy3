// wuqing-jianfa.c  
// 五禽剑法

#include <ansi.h>

inherit SKILL;

mapping *action	=({
        ([      "action":"$N使一招「风卷落叶」，手中$w斜沉，倒卷上去，想截$n的$l",
		"dodge":		50,
		"damage":		80,
            "parry":          60, 
            "force":          70,
		"damage_type":	"刺伤"
	]),
        ([      "action":"$N手中$w突然急攻而起，刷！刷！刷！「抽撤连环」点$n的$l挂$l",
		"dodge":		60,
		"damage":		70,
            "parry":          50, 
            "force":          60,
		"damage_type":	"割伤"
	]),
        ([     "action":"$N一招「回风戏柳」，手中$w一卷，卷向$n的$l",
		"dodge":		80,
		"damage":		90,
            "parry":          100, 
            "force":          80,
		"damage_type":	"割伤"
	]),
	([	"action":"$N的$w一撩，招走「极目沧波」对准$n的$l刺出一剑",
		"dodge":		90,
		"damage":		80,
            "parry":          70, 
            "force":          90,
		"damage_type":	"刺伤"
	]),
	([	"action":"$N一招「迎风扫尘」身随$w，但见一圈银光滚向$n的$l",
		"dodge":		100,
		"damage":		100,
            "parry":          110, 
            "force":          90,
		"damage_type":	"刺伤"
	]),
	([	"action":"$N蹬左腿，欺身直进，$w走「白鹤亮翅」一招，刺向$n的$l",
		"dodge":		60,
		"damage":		70,
            "parry":          100, 
            "force":          85,
		"damage_type":	"刺伤"
	]),
	([	"action":"$N右手挽$w，打了个圈，突然使一招「白虹贯日」急如闪电，刺向$n$l",
		"dodge":		90,
		"damage":		75,
            "parry":          90, 
            "force":          80,
		"damage_type":	"刺伤"
	]),
	([	"action":"$N手中$w如风飘落叶，一式「展翼摩云」，倒划而上，向$n的$l划来",
		"dodge":		60,
		"damage":		90,
            "parry":          120, 
            "force":          100,
		"damage_type":	"割伤"
	]),
       ([	"action":"$N一招「猿猴摘桃」，手中$w挑$n的$l刺$n的$l",
		"dodge":		90,
		"damage":		70,
            "parry":          80, 
            "force":          100,
		"damage_type":	"割伤"
	]),
});

string *interattack = ({
        "$N紧握着手中的$w，伺机而动。\n",

});

int valid_learn(object me)
{
        object ob;

            if( (int)me->query_skill("xiantian-force", 1) < 70 )
            return notify_fail("你的先天气功火候不足，无法练五禽剑法。\n");

        if( (int)me->query("max_force") < 400 )
                return notify_fail("你的内力不够，没有办法练五禽剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的内力或气不够，没有办法练习五禽剑法。\n");
        me->receive_damage("kee", 35);
        me->add("force", -30);
        write("你按著所学练了一遍五禽剑法。\n");
        return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("xiake")+"/wuqin-sword/"+func;
}






