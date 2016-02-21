#include <ansi.h>;

inherit ROOM;

void create()
{
            set("short", YEL"小作坊"NOR);
	set("long", @LONG
这是一个小小的作坊，迎面是一座烈焰熊熊的大炉。
一个身系雪白肚兜的少年正坐在炉旁精心的制着陶器。
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 5 */
  "down" : "/d/zhongzhou/shizhongxin",
     "up" : "/d/wiz/meeting",
]));
       set("outdoors",1);
setup();
}
void init()
{
           add_action("do_full", "full_me");
}
   int do_full(string arg)
{
        object me;
        me = this_player();
        if( me->query("water") >= me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");
        if( me->query("food") >= me->max_food_capacity() )
                return notify_fail("你已经再也吃不下任何东西了。\n");
           message_vision("$N坐在火炉旁，"+HIW+HBYEL+"大吃大喝"+NOR+"一顿 ... \n", me);
        me->set("water", me->max_water_capacity());
           me->set("food", me->max_food_capacity());
        message_vision("$N水足饭饱,拍拍肚皮,站了起来 ... \n", me);
        return 1;
}




