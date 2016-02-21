// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;



void create()
{
	set_name("金创药", ({"jinchuang yao","yao"}));
		set("unit", "包");
		set("long","这种药可用来恢复内力。\n");
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
	me->set("force",(int)me->query("max_force"));
me->set("oldsix_flag/eat_yao",time());
	message_vision("$N吃下一包金创药。\n",me);
	destruct(this_object());
	return 1;
}

