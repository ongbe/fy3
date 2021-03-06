#include <ansi.h>
inherit KZZNPC;
inherit F_BH;

void create()
{
	mapping data;
	data=get_npc_data();
	set_npc_data(data,1);
        setup();
	carry_object("/d/yeyangzai/npc/obj/zijindao")->wield();
	carry_object("/d/yeyangzai/npc/obj/wujinfu")->wield();
	carry_object("/d/yeyangzai/npc/obj/jinsijia")->wear();
	add_money("gold",5);
}
	
void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string banghui;
	if( !ob || environment(ob) != environment() ) return;
	if(! banghui=query("banghui"))	{
		command("say 竟敢闯入野羊寨禁地，我看你是不想活了！\n");
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
	else if(ob->query("banghui")!=banghui)	{
		command("say 竟敢闯入"+banghui+"野羊寨禁地，我看你是不想活了！\n");
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
	else	{
		command("say 这位"+RANK_D->query_respect(ob)+
		"，帮中一切可好？\n");
	}
}

void die()
{
	object killer;
	string banghui,file="/data/banghui/";
	mapping data;
	message_vision("$N挣扎了几下死了。\n",this_object());
	if(! killer=query_temp("last_damage_from"))	{
		destruct(this_object());
		return;
	}
	if(! (banghui=killer->query("banghui"))|| !check_file(file+banghui)) {
		destruct(this_object());
		return;
	}
	if(query("banghui")==banghui)	{
		destruct(this_object());
		return;
	}
	if(! do_jiaru(this_object(),killer))    return;
	data=get_file_data("/data/other/dipan");
	data["yeyangzai"]=banghui;
	if(! save_file_data(data,"/data/other/dipan"))  return;
	destruct(this_object());
	message("channel:rumor",YEL"【谣言】某人：野羊寨被"+
	banghui+
	"占据！\n"NOR,users());
	return;
}

