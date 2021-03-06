// Room: /d/suzhou/chengzhong.c

inherit ROOM;

void create()
{
	set("short", "城中广场");
	set("long", @LONG
广场四周绿树成荫，倒是个休息的好地方。西面人声鼎沸，象是个集市。东
边是些大贾富豪的宅院，显得相对安静些。广场中央一口泉眼正汩汩的冒着泉水。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengxijie3",
		"north" :__DIR__"chengbeijie1",
		"south" :__DIR__"chengnanjie1",
		"east" :__DIR__"chengdongjie1",
]));
	set("objects",([
		__DIR__"npc/xunbu" :4,
]));
	set("resource/water",1);
	set("outdoors","suzhou");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
