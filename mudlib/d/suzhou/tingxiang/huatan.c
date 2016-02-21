// Room: /u/oldsix/room1/huatan.c

inherit ROOM;

void create()
{
	set("short", "花坛");
	set("long", @LONG
未进花坛，便闻到阵阵的花香。这里种满了各种名贵的茉莉花，都是“听香
水榭”的主人阿朱从各地采购而来的，这儿还专门有花匠种植照料。
    东边是厨房，西边通往客厅。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west":__DIR__"yuemen",
		"east":__DIR__"chufang",
]));
	set("objects",([
		__DIR__"npc/huajiang":1,
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
