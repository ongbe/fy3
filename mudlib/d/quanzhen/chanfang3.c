// chanfang3.c 禅房


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
	这里是全真弟子修身养性、打熬气力的地方。为了方便练功，桌椅
都没有摆放，仅仅在地下丢了几个小蒲团。
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaohuayuan2",
		"west" : __DIR__"chanfang2",
	]));

	setup();
	replace_program(ROOM);
}