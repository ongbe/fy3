#include <ansi.h>
inherit NPC;
void create()
{  
	set_name("许仙",({"xuxian","xu xian","xu"}));
       set("shen_type",1);
       set("age",24);
       set("gender","男性");
       set("combat_exp",20000);
       set("str",15);
       set("per",30);
       set_skill("unarmed",30);
       set_skill("parry",30);
       set_skill("dodge",30);
	set("chat_chance", 5);
       set("chat_msg",({
               HIC+"许仙偷偷地斜眼瞟了下身边的白娘子.\n"+NOR,
               HIC+"许仙见靠得白素贞太近了,赶快移开一点!\n"+NOR,
               HIC+"许仙见白素贞在打量他,连忙装作向桥下观鱼!\n"+NOR,
            }));
       setup();
      carry_object("/obj/cloth")->wear();
      add_money("silver",10);
}   
