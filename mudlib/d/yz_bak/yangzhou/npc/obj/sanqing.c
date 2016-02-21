// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;



void create()
{
	set_name("三清丹",({"sanqing dan","dan"}));
		set("unit","粒");
		set("long","道家炼制的丹药，可用来恢复道行。\n");
		set("value",2500);
	setup();
}
void init()
{
    add_action("do_eat", "eat");
}
int do_eat(string arg)
{
	object me=this_player();
	if(!living(me))	return 0;
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
if ((int)time()-me->query("oldsix_flag/eat_yao")<60)
return notify_fail("你刚吃过补药,连续吃身体受不了.\n");
	me->set("atman",(int)me->query("max_atman"));
me->set("oldsix_flag/eat_yao",time());
	message_vision("$N吃下一粒三清丹。\n",me);
	destruct(this_object());
	return 1;
}

