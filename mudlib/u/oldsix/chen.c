// chen.c 陈近南

#include <ansi.h>

inherit KZZNPC;
inherit F_MASTER;
string ask_me();
int do_join();
void create()
{
	set_name("陈近南", ({ "chen jin nan", "chen","nan" }));
	set("nickname", HIC "英雄无敌" NOR);
	set("long", 
		"\n这是一个文士打扮的中年书生，神色和蔼。\n"
		"他就是天下闻名的天地会总舵主陈近南,\n"
		"据说十八般武艺，样样精通。\n"
		"偶尔向这边看过来，顿觉他目光如电，英气逼人。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_kee", 5000);
	set("max_gin", 2000);
	set("force", 5000);
	set("max_force", 5000);
	set("force_factor", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("houquan", 150);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 150);
	set_skill("yunlong-jian", 200);

	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 150);
	set_skill("ningxue-zhua", 150);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "ningxue-zhua");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "yunlong-shou");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	create_family("云龙门",1, "开山祖师");
	set("class", "yunlong-xinfa");
	set("book_count", 1);
        set("inquiry", ([
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :(:do_join:),
                "反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",
		"云龙剑谱" : (: ask_me :),
       ]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		"\n陈近南摇头叹道：螳臂当车，不自量力。唉，你这又是何苦呢?\n",
		(: command("smile") :),
		(: command("poem") :),
		(: command("nomatch") :),
		(: command("haha") :),
		(: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),
                (: perform_action, "sword.xian" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object(__DIR__"leftsword")->wield();
	carry_object("/d/city2/obj/hlbian")->wield();
carry_object("/obj/weapon/gangdao")->wield();
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
        ob = new("/d/city2/obj/yljianpu");
        ob->move(this_player());
        return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}


void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 50) {
		command("say 我云龙神功乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在云龙神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("score") <600) {
		command("say 我云龙门武功天下无敌，凡入我门，\n必闯荡江湖，行侠仗义，为天下苍生谋福利。\n"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否应该先出去闯一闯，做几件惊天动地的大事？");
	return ;
	}
	if ((int)ob->query("score") < 500) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
	return ;
	}
	if(ob->query("score")<80)
	{
	if((int)ob->query("mingwang")<0) command("say "+ RANK_D->query_respect(ob) +"虽然是邪派中人，但也还做了些好事。\n");
	command("chat 我天地会所作所为，无一不是前人所未行之事。\n");
	command("chat 万事开创在我，骇人听闻，物议沸然，又何足论？\n");
	command("chat 今天就收了你吧！！\n");
	command("chat 想不到我一身惊人艺业，今日终于有了传人，哈哈哈哈！！！！\n");
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}
