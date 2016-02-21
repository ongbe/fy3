// Room: /d/quanzhen/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
	前面好象有一个大山谷，走到这里，树木多了些，全都是柏树。西
面是一条弯曲的山路，隐藏在山间，要在夜里还真看不出来。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 2,
]));
	set("outdoors", "/d/quanzhen");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"cuipingu",
  "southwest" : __DIR__"shanlu2",
]));

	setup();
	replace_program(ROOM);
}
