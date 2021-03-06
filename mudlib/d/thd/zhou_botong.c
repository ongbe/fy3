// zhou_botong.c
// str = 膂力, int = 悟性, cps = 定力, con = 根骨, wis = 慧根, dex = 机敏。
#include <npc.h>

inherit F_FIGHTER;

int leave_hole();
int answer1();

void create()
{
	set_name("周伯通", ({ "zhou botong","zhou" }) );
	set("title", "全真教名宿");
//	set("gender", "female");
	set("age", 63);
	set_race("human");
	set_level(140);
	set_class("quanzhen");

	set("long",
"周伯通是个鹤发童颜的老人，可是他一会儿扮个鬼脸，
一会儿又拉着你打弹子，实足的小孩子脾气。\n");
	set("rank_info", "全真高手");
	set("nick", "老玩童");
	
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("finger", 200);
	set_skill("sword", 200);

//	map_skill("dodge",  "bagua-steps");
//	map_skill("unarmed","lanhua-finger");
//	map_skill("parry",  "luoying-sword");
//	map_skill("force",  "suiyu-force");
//    map_skill("sword",  "luoying-sword");
	
	gain_score("mortal sin", 10000);

	create_family("全真教", 1);

	set("inquiry", ([
		"瑛姑" : (: answer1 :),
		"瑛姑来了" : (: leave_hole :),
	]) );	
	
	setup();
	carry_money("gold", 10);
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/chang_jian")->wield();
}

int accept_fight()
{
	do_chat("周伯通叫道：好啊，我最喜欢打架了。\n");
	return 1;
}

int accept_kill()
{
	do_chat("周伯通笑道：我又没抢你老婆，你找我拼命干什么？\n");
}

int leave_hole()
{
	message_vision(
"周伯通一听这话，脸“唰”的一下变红了，又“唰”的一下变白了。
接着飞也似的跑掉了。\n",this_object());

	this_object()->move(__DIR__"empty_room");
	
	call_out("go_back", 5);

	return 1;
}

void go_back()
{
	this_object()->move(__DIR__"qiulong_hole");
	message_vision("周伯通又跑了回来。\n",this_object());
}

int answer1()
{
	message_vision("周伯通脸色一变,似乎是害怕什么.\n",this_object());

	return 1;
}

