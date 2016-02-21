// guard.c

#include <ansi.h>

inherit NPC;
int do_catch(object ob);

void create()
{
	set_name("巡捕",({"xun bu","xun","bu"}));

	set("nickname","千里追命");
	set("title","苏州府");
	set("gender", "男性" );
	set("age",25);
	set("long",
	"英俊潇洒，貌似潘安。你最好还是不要招惹他。\n"
	);
	set("pursuer",1);
	set("attitude", "heroism");
	set("chat_chance",40);
        set("chat_msg", ({
			"巡捕从身上掏出要犯画像，正仔细的和你比较。\n",
			"巡捕小声嘀咕着：这年头只要花银子，啥事不好办？\n",
                (: random_move :),
        }) );
	set("inquiry", ([
	"通缉" : "去找包大人问问看吧。\n",
	"tong" : "去找包大人问问看吧。\n",
	]) );


	setup();
	carry_object("obj/weapon/sword");
}

void init()
{
	object ob;
	ob=this_player();
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
			call_out("greeting",1,ob);
}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
	add_action("do_steal","steal");
}
int do_steal()
{
	object me;
	me=this_player();
	message_vision(CYN"巡捕“哼”的冷笑一声：居然有人敢在我面前干从偷鸡摸狗的事！\n"NOR,me);
	tell_object(me,"你只觉头皮发麻，赶忙把手缩了回来。\n");
	return 1;
}
int do_kill(string str)
{
	object ob,npc;
	ob=this_player();
	npc=present(str,environment());
	if(npc==this_object())	{
message_vision(CYN"巡捕对着$N长叹一声：我早已厌倦了江湖上的恩恩怨怨，别逼我了。\n"NOR,ob);
	return 1;
			}
	return 0;
}
int do_catch(object ob)
{
	string str;
	switch(ob->query("oldsix_flag/long"))	{
		case 1 :	{
	str="/d/suzhou/dalao3.c";
	break;
				}
		case 2 :	{
	str="/d/suzhou/dalao2.c";
	break;
				}
		case 3 :	{
	str="/d/suzhou/dalao1.c";
	break;
				}
				}
	ob->set("oldsix_flag/tongji",0);
	ob->set("oldsix_flag/lao",1);
	ob->set("oldsix_flag/time",ob->query("mud_age"));
	ob->set("startroom",str);
	ob->apply_condition("lao_cancle");
	ob->set_temp("block_msg/all",1);
	ob->move(str);
	ob->set_temp("block_msg/all",0);
	command("rumor "+ob->query("name")+"被捉拿归案。");
	ob->set("sen",-1);
}
void greeting(object ob)
{
         if( !ob || environment(ob) != environment() ) return;
	if(ob->query("oldsix_flag/tongji")==1)
			{
	message_vision(RED"\n巡捕冲着$N怒喝一声："+ob->query("name")+"！哪里跑！！跟我回去见官！！\n"NOR,ob);
	message_vision(RED"\n说罢，巡捕掏出怀中铁链冲$N劈头盖脸的砸了下来！\n\n"NOR,ob);
	do_catch(ob);
	return;
			}
	(: random_move() :);
}
int accept_fight(object who)
{
	message_vision(CYN"巡捕对着$N长叹一声：我早已厌倦了江湖上的恩恩怨怨，别逼我了。\n"NOR,who);
return 0;
}
