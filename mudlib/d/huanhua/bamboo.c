// Room: /d/new/huanhua/bamboo.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片青脆的竹林,绿色的竹叶梢还滴着露水,四外空无一人,唯有
鸟儿的轻鸣响彻林间.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/3e1.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/new");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jianlu",
  "south" : __DIR__"bamboo1",
]));

	setup();
	replace_program(ROOM);
}
