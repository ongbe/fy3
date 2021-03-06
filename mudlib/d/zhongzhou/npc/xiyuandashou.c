// poorman.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("戏院打手", ({ "xiyuan dashou","dashou"}) );
        set("gender", "男性" );
        set("age", 26);
        set("long", "维护戏院治安的彪形大汉。\n");
        set("combat_exp", 50000+random(50000));
        set("shen_type", -1);
        set("xiyuan_dashou",1);
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set("max_kee",600);
        set("chat_chance", 35);
        set("chat_msg", ({
        "戏院打手恶狠狠的看着你。\n",
        "戏院打手恶狠狠的挽了挽袖子。\n",
        "戏院打手指着你道：你！给我小点声。\n",
        (: random_move :),
        }) );

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
	if( userp(ob) && ob->is_fighting())	{
		message_vision(HIC"$N怒吼道：$n，竟敢来此捣乱，我看你是不想活了！\n"NOR,
		this_object(),ob);
		command("follow "+ob->query("id"));
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}
