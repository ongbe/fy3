// luoying-sword.c by ksusan 07/08/1997
// 97/9/27 by Aug

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「海天一色」，一剑飘向$n的$l",
		"dodge":		20,
		"parry":		20,
		"force":		25,
		"damage":         30,
		"lvl":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一招「雷霆万钧」，一剑砍向$n的$l",
		"dodge":		10,
		"parry":		30,
		"force":		50,
		"damage":         40,
		"lvl":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出「一剑穿心」，一道白光闪向$n的心脏",
		"dodge":		60,
		"parry":		-20,
		"force":		20,
		"damage":         60,
		"lvl":		9,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N吐气扬声，使出「落英缤纷」，数十把$w向$n的$l斩去",
		"dodge":		60,
		"parry":		60,
		"force":		50,
		"damage":         50,
		"lvl":		9,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N微微一笑，使出「招花引蝶」，手中$w不着边际的刺出，可招招都落在了$n的身上",
		"dodge":		80,
		"parry":		80,
		"force":		60,
		"damage":         80,
		"lvl":		19,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一式「雷厉风行」，手中$w卷起一阵狂风袭向$n",
		"dodge":		-40,
		"parry":		-40,
		"force":		85,
		"damage":         85,
		"lvl":		29,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一飞冲天，一式「洋洋洒洒」点向$n三十六大死穴",
		"dodge":		90,
		"parry":		90,
		"force":		50,
		"damage":         50,
		"lvl":		29,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身行一闪，$n顿时看到数十把$w从四面八方袭来，缺不见了$N的身形，好一招「如鱼得水」",
		"dodge":		100,
		"parry":		100,
		"force":		60,
		"damage":         60,
		"lvl":		39,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N神色凝重，$w"+HIW"平刺，使出「乾坤一剑」，瞬时天地为之一黯"NOR,
		"dodge":		-60,
		"parry":		-30,
		"force":		100,
		"damage":         100,
		"lvl":		49,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N一连向$n刺出九剑，把$n裹在剑网之中，再也分不清东西南北，好一招「如醉如梦」"NOR,
		"dodge":		120,
		"parry":		120,
		"force":		75,
		"damage":         75,
		"lvl":		59,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N一招「源源不绝」使出，联绵不断的向$n刺出三十六剑，$n被搞的手忙脚乱，应接不暇"NOR,
		"dodge":		100,
		"parry":		100,
		"force":		90,
		"damage":         90,
		"lvl":		69,
		"damage_type":	"刺伤"
	]), 
	([	"action":		HIW"$N一招「风花雪月」使出，$n顿时感到一股寒气袭了，似乎到了冰天雪地之中"NOR,
		"dodge":		90,
		"parry":		90,
		"force":		120,
		"damage":         120,
		"lvl":		79,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIY"$N脸色一变，不再顾忌自身的安危，一招「天地同寿」身剑合一向$n刺去"NOR,
		"dodge":		-100,
		"parry":		-100,
		"force":		160,
		"damage":         150,
		"lvl":		89,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIY"$N哈哈大笑，手中$w"+YEL"随随便便的挥向$n，「惟我独尊」使出，$N充满了自信"NOR,
		"dodge":		150,
		"parry":		150,
		"force":		200,
		"damage":         200,
		"lvl":		99,
		"damage_type":	"刺伤"
	]),

});

int valid_learn(object me)
{
        object ob;

		if( (int)me->query_skill("suiyu-force", 1) < 20 )
			return notify_fail("你的碎玉神功火候不足，无法练落英剑法。\n");
		
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练落英剑法。\n");

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
notify_fail("你的内力或气不够，没有办法练习落英剑法。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍落英剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/luoying-sword/" + action;
}
 
