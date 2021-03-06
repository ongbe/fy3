// xiaoyao-you.c
//逍遥游
inherit SKILL;

string *dodge_msg = ({
	"$n一招「瞻忽在前」轻轻松松地避了开去。\n",
	"只见$n身形一转，一式「动若脱兔」早已闪开$N的攻击。\n",
	"$n使出「微尘不惊」，身形微动，$N又扑了个空。\n",
	"$n左足一退，右足一分，一招「若有若无」已避了开去。\n",
	"可是$n使一招「姑射仙人」，身子象轻纱一样飘了开去。\n",
	"$n下身不动，上身轻侧，已经藉一招「静若处子」轻轻闪过。\n",
	"但是$n一招「瞻忽在后」使出，竟然绕到$N身後！\n"
});

string *dodge_msg_low = ({
	"$n一招「瞻忽在前」，踉踉跄跄地避了开去。\n",
	"只见$n身形一转，半生不熟地使一式「动若脱兔」总算闪开了$N的攻击。\n",
	"$n使出「微尘不惊」，身形晃来晃去，却带起一片尘埃，$N又扑了个空。\n",
	"可是$n使一招「姑射仙人」，飞也似地逃到远处去了。\n",
	"$n下身不动，上身向左边一趴，一招「静若处子」，还好躲开了。\n",
	"$n哇地惊呼一声，事出突然，只能使出狗吃屎，幸好没被$N打中！\n",
// above item is not dodge skill in lingbo-steps, but is 本能反应
});

int valid_enable(string usage) { return (usage == "dodge");}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力太差了，无法练习逍遥游。\n");
		me->receive_damage("kee",30);
        return 1;
}

