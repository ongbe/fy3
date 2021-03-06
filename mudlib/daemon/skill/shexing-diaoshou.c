
// shexing-diaoshou.c 蛇形刁手

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「灵蛇出洞」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"damage":60,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N侧身一晃，一式「虎头蛇尾」，左手拿向$n的肩头，右拳打向$n的胸口",
	"damage":80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「画蛇添足」，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"damage":100,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚招，右掌直立，一式「杯弓蛇影」，错步飘出，疾拍$n的面门",
	"damage":120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「蛇行鼠窜」，左拳上格，右手探底突出，抓向$n的裆部",
	"damage":140,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「蛇磐青竹」，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"damage":160,
        "damage_type" : "内伤"
]),
([	"action" : "$N双手抱拳，一式「万蛇汹涌」，掌影翻飞，同时向$n施出九九八十一招",
	"damage":180,
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「白蛇吐信」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
	"damage":200,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed"  || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练蛇形刁手。\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}
string perform_action_file(string action)
{
return "/daemon/class/baituo/shexing-diaoshou/" + action;
}

