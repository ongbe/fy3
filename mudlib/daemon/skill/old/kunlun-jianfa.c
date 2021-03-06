 // kunlun-jianfa.c
//昆仑剑法--------------- Write by Wangzc & Ppl

inherit SKILL;

mapping *action = ({
        ([      "action": "$N手中$w一颤左右一抖，一式「分花拂柳」朝$n的$l直刺而去！",
          "lvl":10,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N使出昆仑剑法中的「左右逢源」这招，抖出两个剑尖，向$n的$l刺去！",
          "lvl":18,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N面色一沉，手中$w贯注真力， 一招“巍巍昆仑”排山倒海般向$n刺去！",
          "lvl":26,
                "damage_type":  "割伤"
        ]),
        ([      "action": "$N纵身一跃，一招「捕风捉影」$w化为点点寒星，罩向$n！",
          "lvl":32,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N微微一笑，身影陡然化作两条，一招「双燕齐飞」，向$n两侧攻来！",
            "lvl":38,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N身形一晃，一招「生生不息」，手中$w连绵不断地向$n刺去，仿佛无穷无尽！",
          "lvl":44,
                "damage_type":  "刺伤"
        ]),
         ([      "action": "$N突然身体一侧，背对$n,一招「峰回路转」，$w从胁下穿出，刺向$n的咽喉！",
          "lvl":48,
                "damage_type":  "刺伤"
        ]),
        ([   "action": "$N一招「惊涛拍石」，用$w向$n拍去，半途中手腕一转，$w离$n的面门已不到两寸！",
          "lvl":52,
                "damage_type":  "刺伤"
        ]),
      ([    "action": "$N突然间目光一滞，一招「生死相许」，$w向毒蛇般紧紧缠住$n！",
          "lvl":55,
               "damage_type": "刺伤"
     ]),
      ([    "action": "$N身形一沉，一招「石破天惊」，$w挟着隐隐的雷声，向$n头部刺到！",
          "lvl":58,
          "damage_type": "刺伤"
      ]),
      ([    "action": "$N长剑平举，天地间仿佛只有$N一个人，一招「无双无对」，杀得$n手忙脚乱！",
          "lvl":61,
          "damage_type": "刺伤"
      ]),
      ([    "action": "$N惨然一笑，一招「地老天荒」，霎时天地为之黯然，$w笔直向$n的心房刺去！",
          "lvl":65,
         "damage_type": "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
    return notify_fail("你的内力不够，没有办法练昆仑剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "kunlun-xinfa")
                 return notify_fail("昆仑剑法必须配合昆仑心法才能练。\n");

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
notify_fail("你的内力或气不够，没有办法练习昆仑剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          write("你按著所学练了一遍昆仑剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
    return CLASS_D("xiake")+"/kunlun-jianfa/"+action;
}
 
