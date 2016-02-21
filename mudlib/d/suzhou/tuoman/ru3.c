// Room: /u/oldsix/room1/ru1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
鹅卵石铺成的小径，曲曲折折一直通向远方。小径两边山石花木。虽说山茶
花不怎么让人顺眼，但微风拂面，倒也叫人精神一振。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south":__DIR__"lukou",
		"north":__DIR__"hongxia",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
