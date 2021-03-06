// yapu6.c

inherit NPC;

void create()
{
	set_name("哑仆", ({ "yapu" }) );
//	set("title", "江南陆家庄家丁");
	set("gender", "男性");
	set("age", 48);
//	set_race("human");
//	set_level(20);
	set("class","taohua");

	set("long","这是个温顺的哑仆，黄岛主让他做烧饭的工作。\n");
	set("rank_info", "哑仆");

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

	set("combat_exp", 10000);
	set("score",5000);

	
      set_skill("unarmed", 40);
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	set_skill("sword", 30);
	
//	gain_score("mortal sin", -200);
	
	setup();
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object who)
{
	message_vision("哑仆双手比划着什么，不过$N是没看懂。\n",this_player());

	return 0;
}

int accept_kill(object who)
{
	message_vision("哑仆双手比划着什么，脸露凶相，看来要杀$N。\n",this_player());

}

void init()
{
	add_action("do_yao", "yao");
	add_action("do_list", "list");
}

int do_list(string arg)
{
	message_vision(
"$N问哑仆有什么东西可以吃,哑仆拿出几样东西:
白切肉(rou)、嫩豆腐(doufu)、腊八粥(zhou)、翡翠白菜(baicai)
\n",this_player());

	return 1;
}

int do_yao(string arg)
{
	object me;

	me=this_player();

	message_vision("$N问哑仆有东西可以吃。\n",me);

      if( me->over_encumbranced() ) 
	{
          write("但你已经负荷过重了，没法再拿吃的了 :-( \n");
	    return 1;	
	}

	switch(arg)
	{
		case "rou"  : { new(__DIR__"obj/rou")->move(me); 
				     message_vision("哑仆给$N一盘白切肉。\n",me);
				     return 1; }	
		case "doufu" : { new(__DIR__"obj/doufu")->move(me); 
				     message_vision("哑仆给$N一盘嫩豆腐。\n",me);
				     return 1; }	
		case "zhou"  : { new(__DIR__"obj/zhou")->move(me); 
				     message_vision("哑仆给$N一碗腊八粥。\n",me);
				     return 1; }	
		case "baicai": { new(__DIR__"obj/baicai")->move(me); 
				     message_vision("哑仆给$N一盘翡翠白菜。\n",me);
				     return 1; }	
		default:{ message_vision("哑仆双肩一耸，大概是说$N要的东西他没有。\n",this_player()); 
			    return 1; }	

	}
}
