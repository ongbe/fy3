inherit NPC;
void create()
{
   set_name("瑞栋",({"rui dong"}));
   set("gender","男性");
   set("age",36);
   set("nickname","侍卫副总管");
	set("shen_type",-1);
   set("combat_exp",500000);
   set("force",600);
   set("max_force",600);
   set("force_factor",20);
   
   set_skill("unarmed",40);
   set_skill("parry",40);
   set_skill("dodge",40);
   set_skill("huashan-quanfa",50);
   set_skill("anying-fuxiang",40);
   map_skill("parry","huashan-quanfa");
   map_skill("unarmed","huashan-quanfa");
   map_skill("dodge","anying-fuxiang");
   set("inquiry",([
   "四十二章经":"老子身上就有一部,怎的?\n",
   "太后":"我要为太后粉身碎骨,也在所不惜.\n",
   "韦小宝":"我也正在找这小子.\n",
   ]));
  set("chat_chance",5);
  set("chat_msg",({
  "瑞栋道:这部[四十二章经]是太后吩咐要的,可不能丢了.\n",
  "瑞栋道:今晚宫中闹刺客,听说死了好几个侍卫.\n",
  "瑞栋道:皇上大,还上太后大?那当然是太后大了.\n",
  }));
   
   setup();
   add_money("silver",10);
   carry_object(__DIR__"obj/42book1.c");
   carry_object("/obj/std/armor/tiejia")->wear();
   carry_object("/obj/std/armor/tiexue")->wear();
   carry_object("/obj/std/armor/tiekui")->wear();
}
#include "shiwei.h"
