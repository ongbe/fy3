// Room: /d/suzhou/yushi.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "浴室");
	set("long", @LONG
这是苏州新近开放的浴室，设施也比较简单，但总算是个可以休息的地方。
西面乱糟糟嚷成一片当然是男浴室，东面则是女浴室，千万乱走啊。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" :__DIR__"nanyushi",
	"east" :__DIR__"nuyushi",
  "south" : __DIR__"chengdongjie2",
]));
	set("objects",([
		__DIR__"npc/zaotanglaoban":1,
]));
	set("no_fight",1);
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me,string dir)
{
	if((me->query("gender")=="男性"&&dir=="east")||(me->query("gender")=="女性"&&dir=="west")) {
	message_vision(CYN"澡堂老板怒喝一声："+me->query("name")+"，你这个淫贼，给我滚出去！\n"NOR,me);
	message_vision(CYN"说罢飞起一脚把$N给踢了出去。\n"NOR,me);
	me->set_temp("rent_paid",0);
   tell_room(__DIR__"chengdongjie2",CYN"只听得澡堂内老板一声怒喝："+me->query("name")+"，你这个淫贼，给我滚出去！\n\n但见"+me->query("name")+"不知被谁给踢了出来！\n"NOR);
	me->move(__DIR__"chengdongjie2");
	return notify_fail("\n");
	}
	if(dir=="south")	{
		me->set_temp("rent_paid",0);
		return 1;
	}
	if(me->query_temp("rent_paid")==1)	{
	tell_object(me,CYN"老板说道：您老慢慢享用。\n"NOR);
	return 1;
	}
	message_vision(CYN"老板冲$N冷哼一声：没付钱就想白洗？！\n"NOR,me);
	return notify_fail("\n");
}
