
#include <ansi.h>
inherit KZZNPC;
inherit F_MASTER;
string ask_me();
int do_join();
void create()
{
	set_name("马超兴", ({ "ma chaoxing", "ma"}));
	set("gender", "男性");
	set("long", "\n他就是天地会洪顺堂堂主，善使一柄大刀。\n");
	set("age", 45);

	set("int", 30);
	
	set("kee", 1500);
	set("max_kee", 1500);
	set("gin", 500);
	set("max_gin", 500);
	set("score",200);

	set("combat_exp", 250000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 70);
	set_skill("blade", 100);
	set_skill("whip", 70);
	set_skill("yunlong-shengong", 70);
	set_skill("yunlong-shenfa", 70);
	set_skill("wuhu-duanmendao", 80);
	set_skill("houquan", 50);
	set_skill("yunlong-jian", 50);
	set_skill("yunlong-bian", 50);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 25);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
        map_skill("blade","wuhu-duanmendao");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
        map_skill("unarmed","houquan");

	create_family("云龙门",2, "弟子");
	set("class", "yunlong-xinfa");
	set("book_count", 1);
        set("inquiry", ([
		"陈近南" :  "\n江湖威望值达到70就可以拜总舵主为师。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会.\n",
		"入会" : (:do_jiaru:),
                "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
		"云龙经" : (: ask_me :),
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
                      }) );
	setup();
	carry_object("/d/obj/weapon/whip/whip");
carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/weapon/gangdao");
	carry_object("/obj/cloth")->wear();
        add_money("silver",20);
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "云龙门")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/d/city2/obj/yljing1");
        ob->move(this_player());
        return "好吧，这本「云龙经」你拿回去好好钻研。";
}

void attempt_apprentice(object ob)
{
/*
if((string)ob->query("gender")=="女性")
           {
 		command("say 女人的名字是弱者，我云龙门顶天立地，怎会收你呢？！");
		return;
	   }
*/
if((string)ob->query("gender")=="无性")
           {
 		command("say 云龙门顶天立地，怎会收你这样的废人？！");
		return;
	   }
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}

void greeting(object ob)
{

               if(random(5)<2) say( "马超兴笑道：这位" + RANK_D->query_respect(ob)
				+ "，可有什么不平之事么？\n");
 
}
#include "tiandihui.h"
