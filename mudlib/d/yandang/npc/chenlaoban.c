inherit KZZNPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/陈老板"; }
void create()
{
#include <kzznpc.h>
	set("area_name","陈家铺子");
	set("area_file","/d/yandang/cahuopu.c");
	set("vendor_goods", ([
                     "金戒指":     __DIR__"obj/jinjiezhi",
                     "钻石介指":   __DIR__"obj/zuanshijiezhi",
                     "玉镯":   __DIR__"obj/yuzhuo",
                     "玉坠子":   __DIR__"obj/yuzhui",
                     "珍珠项链":   __DIR__"obj/xianglian",
	]) );
	setup();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_vendor_list", "list");

}
void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			message_vision("陈老板打量了$N一会，笑道：这位"+
			RANK_D->query_respect(ob)+"，您想要点什么？\n",ob);
			break;
		case 1:
			say( "陈老板说道：这位" + RANK_D->query_respect(ob)
				+ "，你也是上雁荡拜师的吧。\n");
			break;
                           }
}



