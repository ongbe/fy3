//duanyu.c
//小岛修改(islet@wx.jsinfo.net)
//1999/10/31

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
           set_name("段誉", ({ "duan yu","duan" }));
        set("title",  "大理镇南王之子" );
        set("long", "这就是大理国的镇南王独生子，他性格腼腆, 自幼不好习武。\n");
        set("gender", "男性");
        set("age", 20);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
            set("str", 30);
        set("int", 30);
          set("per",29);
        set("con", 35);
        
        set("max_kee", 3000);
        set("max_gin", 800);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 100);
            set("combat_exp", 2000000);
        set("score", 300000);

            set_skill("force",200);
        set_skill("dodge",220);
            set_skill("parry",200);
      
        set_skill("sword",200);
        set_skill("staff",200);
        set_skill("kurong-changong",220);
        set_skill("tiannan-step",200);
        set_skill("jinyu-quan",200);
        set_skill("wuluo-zhang",200);
        set_skill("duanjia-sword",200);
        set_skill("unarmed",230);
        set_skill("yiyang-zhi",230);
        set_skill("literate", 100);
        set_skill("six-finger",230);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("unarmed","yiyang-zhi");
        map_skill("parry","yiyang-zhi");
        map_skill("sword", "duanjia-sword");
        map_skill("staff", "duanjia-sword");
        map_skill("unarmed","six-finger");
        map_skill("parry","six-finger");

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("gold", 2);

          create_family("大理段家",17,"镇南王之子");
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("kurong-changong",1) <100)
        {
                command("say 你的枯荣禅功太低了，还是努努力先提高一下吧。");
                return;
        }

        if ((int)ob->query("mingwang")<1000000)   {
                command("say 我大理段氏向来行侠仗义，您请回吧！");
                return;
        }
        command("say 很好，既然入我门来就得忠心为主。");
        command("recruit " + ob->query("id"));
        ob->set("title","大理镇南王府武将");
}
