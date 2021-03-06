#include <ansi.h>

inherit NPC;

void create()
{
  set_name("蒙云",({ "meng yun", "dizi","girl" }) );
  set("gender", "女性" );
  set("title",YEL+"粉金刚"+NOR);
  set("long", "白云庵弟子之一,专门看管那些偷窥的人.\n");
  set("age", 15+random(10));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",40000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 400);
  set("max_kee", 400);
  set("max_sen", 400);
  set("inquiry",([
  "出去":"要想过去,先过了我这关.\n",
  ]));
  set_skill("unarmed",50);
  set_skill("dodge",50);
  set_skill("parry",50);
  set_skill("whip",50);
  set_skill("force",50);
  set_skill("baihua-zhang",50);
  set_skill("qiongya-bufa",50);
  map_skill("dodge","qiongya-bufa");
  map_skill("parry","baihua-zhang");
  map_skill("unarmed","baihua-zhang");
  
  set("chat_chance",6);
  set("chat_msg",({
  "蒙云说道:我最恨那些无赖流氓了.\n",
  "蒙云嘿嘿一笑,到了这里,想出去就难了.\n",
  "蒙云道:要想出去,得先过了我这关.\n",
}));

  setup();
  carry_object("/d/hainan/obj/triger_cloth")->wear();
  carry_object("/d/hainan/obj/whip")->wield();
}
