// zhuwanli.c 褚万里

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("褚万里", ({ "zhu wanli", "zhu" }));
	set("title",  "大理国护卫" );
	set("long", "他是大理国四大护卫之一。身穿黄衣，脸上英气逼人。手持一根铁杆。\n");
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 20);
	set("int", 20);
	set("con", 25);

	
	set("max_kee", 1000);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("combat_exp", 300000);
	set("score", 100000);


        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
       
        set_skill("sword", 50);
        set_skill("staff", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 50);
        set_skill("jinyu-quan", 50);
        set_skill("duanjia-sword", 50);
	set_skill("literate", 30);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object(__DIR__"obj/diaogan")->wield();
	add_money("silver", 10);

	create_family("大理段家",19,"护卫");
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
	string family;
        if(!ob || environment(ob)!=environment()) return;
	family=(string)ob->query("family/family_name");
	if(! family)	{
		command("say "+RANK_D->query_respect(ob)+
		"是来拜师的吧，快请进。");
	}
	else if(family=="大理段家")	{
		command("say "+ob->query("name")+
		"辛苦了，快进府休息一下吧。");
	}
	else	message_vision(HIC"$N瞪着$n哼了一声。\n"NOR,this_object(),ob);
}

