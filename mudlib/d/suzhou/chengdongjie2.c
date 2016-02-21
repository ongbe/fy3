// Room: /d/suzhou/chengdongjie2.c

inherit ROOM;

void create()
{
	set("short", "城东街");
	set("long", @LONG
往日这条街上行人很少，今天不知为何北面周宅门口拥挤了不少看热闹的人
。南面是好大一个庄院，门匾上三个金黄色大字“金风庄”。街道东西走向，东
面是苏州府衙。北面是个浴室。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" :__DIR__"yushi",
		"south":__DIR__"jinfengzhuang",
		"west" :__DIR__"chengdongjie1",
		"east" :__DIR__"damen",
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
