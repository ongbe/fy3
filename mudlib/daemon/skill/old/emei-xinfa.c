#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

// #include "force.h"

int valid_learn(object me)
{
        int i, nb, nf, nh;
//        nb = (int)me->query_skill("dacheng-fofa", 1);
        nf = (int)me->query_skill("force", 1);
        nh = (int)me->query_skill("emei-xinfa", 1);

//        if ( nb < 10 && nb <= nh )
//                return notify_fail("你的大乘佛法修为不够，无法领会更高深的临济十二庄。\n");

        if ( nf < 15)
 return notify_fail("你的基本内功火候还不够，无法领会峨眉心法。\n");
          return 1;
     //   return valid_public(me);
}


int practice_skill(object me)
{
        return notify_fail("峨眉心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"emei-xinfa/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"脸上红光隐现，双手搭落在膝盖上" NOR,
    "start_my_msg" : HIR"你席地而坐，五心向天，脸上红光时隐时现，内息顺经脉缓缓流动。\n"NOR,
    "start_other_msg" : MAG + me->name() +"席地而坐，五心向天，脸上红光时隐时现。\n"NOR,
    "halt_msg" : HIW"$N长出一口气，将内息急速退了回去，站了起来。\n"NOR,
    "end_my_msg" : HIC"你将内息走了个小周天，流回丹田，收功站了起来。\n"NOR,
"end_other_msg" : HIR"不一会儿"+me->name()+"便神采弈弈地站了起来。\n"NOR
                    ]);
}
