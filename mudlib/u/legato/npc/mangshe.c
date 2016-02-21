#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"万年巨蟒"NOR, ({ "mang she", "she" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只罕见的大蟒蛇，它的胆是大补之物。\n");
        set("attitude", "peaceful");

       

        set("max_gin",1000);
        set("max_kee",1000);
        set("max_sen",1000);
        set("chat_chance", 20);
        set("chat_msg", ({
            "大蟒蛇警惕的看着你！\n",
            "大蟒蛇将长长的身体盘了起来！\n",
            "大蟒蛇向你吐着红色的舌头\n",
                       
      }) );
                      
      setup();
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 100000);

        set_temp("apply/attack", 150);
        set_temp("apply/damage", 100);
       set_temp("apply/defence",120);
        set_temp("apply/armor",80);
        setup();
        carry_object("/u/legato/obj/shedan");
}

