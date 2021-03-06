// gaoshengtai.c 高升泰

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("高升泰", ({ "gao shengtai", "gao" }));
	set("title",  "大理善阐侯" );
	set("long", "大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。\n");
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_kee",1500);
	set("max_gin",500);
	set("force",1500);
	set("max_force",1500);
	set("force_factor",80);
	set("combat_exp", 800000);
	set("score", 150000);

	set_skill("force", 110);
	set_skill("unarmed",110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("kurong-changong", 110);
	set_skill("tiannan-step", 120);
	set_skill("jinyu-quan", 110);
	set_skill("wuluo-zhang", 110);
	set_skill("duanjia-sword", 110);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("unarmed","wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
	carry_object(__DIR__"obj/tiedi")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武将");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 30 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if( (int)ob->query("mingwang")<10000)
	{
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
        command("say 很好，既然入我门来就得忠心为主。");
        command("recruit " + ob->query("id"));
	ob->set("title","大理镇南王府护卫");
}
 

