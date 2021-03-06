 // chushan-jianfa.c
//楚山剑法(未完篇)

inherit SKILL;

mapping *action = ({
        ([      "action": "$N口中吟道：「若有人兮山之阿」手中$w向前一引，一剑直朝$n的$l划了过去！",
          "lvl":40,
                "damage_type":  "划伤"
        ]),
        ([      "action": "$N口中吟道：「背薛荔兮带女萝」，双眼带着万般柔情，手里$w也应和着发出阵阵“嗡嗡”的声响，向$n的$l划去！",
          "lvl":65,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N口中吟道：「及含涕兮又宜笑」右手使剑挽出一道剑花，左手剑鞘却直奔$n的$l刺了过来！",
          "lvl":90,
                "damade_type":  "刺伤"
        ]),
        ([      "action": "$N似乎想起什么心事似的，口中又再喃喃念道：「子慕予兮善窈窕」手中$w由上而下划出一个半圆，剑尖指地，顿时将$n全身上下笼罩在无边的剑气当中！",
          "lvl":150,
                "damade_type":  "劈伤"
        ]),
 
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
    return notify_fail("你的内力不够，没有办法练楚山剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "kunlun-xinfa")
                 return notify_fail("楚山剑法必须配合楚山心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
           return usage=="sword";
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
notify_fail("你的内力或气不够，没有办法练习楚山剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          write("你按著所学练了一遍楚山剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
    return CLASS_D("xiake")+"/chushan-jianfa/"+action;
}

