// yapu4.c

inherit NPC;

void create()
{
	set_name("哑仆", ({ "yapu" }) );
//	set("title", "江南陆家庄家丁");
	set("gender", "男性");
	set("age", 43);
//	set_race("");
//	set_level(45);
	set("class","taohua");

	set("long","这是个温顺的哑仆。\n");
	set("rank_info", "桃花岛哑仆");

	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);

	set("max_atman", 500);
	set("atman", 500);
	set("max_force", 500);
	set("force", 500);
	set("max_mana", 500);
	set("mana", 500);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 20);
	set("per", 30);

	set("combat_exp", 30000);
	set("score",10000);
	
      set_skill("unarmed", 100);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("sword", 50);
	
//	gain_score("mortal sin", -400);
	
	setup();
	add_money("silver", 1);
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object who)
{
	message_vision("哑仆双手比划着什么，不过$N是没看懂。\n",this_player());

	return 1;
}

int accept_kill(object who)
{
	message_vision("哑仆双手比划着什么，脸露凶相，看来要杀$N。\n",this_player());

}

