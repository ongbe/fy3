// tianlei-shou.c
// 天雷手
// made by cwj 97/7/6

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「乌云密布」，腾身半空，双手一合，击向$n的$l",
		"dodge":		30,
		"parry":		20,
		"force":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出「奔雷乍现」，突然间双手大开大阖，结果一掌拍在$n的$l上",
		"dodge":		30,
		"parry":		30,
		"force":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N吐气扬声，使出「雷霆万均」，双手带起无数雷鸣同时向$n的全身攻击",
		"dodge":		-20,
		"parry":		30,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N大喝一声，一招「滚滚春雷」带起连绵不断的气浪滚向$n的$l",
		"dodge":		-10,
		"parry":		30,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N突然使一招「雷电齐鸣」，双眼狠狠的瞪住$n,双手同时拍向$n的$l",
		"dodge":		50,
		"parry":		50,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双手一错，一招「法轮三转」对准$n的$l连续拍出三掌",
          "dodge":             30,
              "parry":		30,
		"force":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出一招「腾博九霄」，全身化作一道雷电从半空中全力击向$n",
		"dodge":		75,
		"parry":		20,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N神色凝重，双足运功深陷入地，双手施全力使出「雷光大状」，瞬时天地间只见雷鸣电闪",
		"dodge":		-55,
		"parry":		-30,
		"force":		75,
		"damage_type":	"瘀伤"
	]),
});

string *interattack = ({
        "$N双手拢起，伺机而动。\n",
});


string query_interattack(object me, object target)
{
	return interattack[random(sizeof(interattack))];
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_enable(string usage) 
{ 
     return (usage=="unarmed") || (usage=="parry");
}

int valid_learn(object me)
{
 mapping weapons;
 if ( mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) )
		return notify_fail("练天雷手必须空手。\n");
	if( (int)me->query_skill("jimie-dafa", 1) < 10 )
		return notify_fail("你的阿修罗寂灭大法火候不足，无法练天雷手。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("sen") < 20 )
		return notify_fail("你的元神不济了，休息一下再练吧。\n");

	me->receive_damage("kee", 10);
	me->receive_damage("sen", 10);
	write("你按着所学练了一遍天雷手。\n");
	return 1;
}
