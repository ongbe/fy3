// Room: /u/uuui/xuedao/xuedao79.c

inherit ROOM;

void create()
{
	set("short", "黄土小径");
	set("long", @LONG
一条通往血刀门的黄土小路，路上空荡荡的，十分安
静，让人觉得有些安静的过分。地上坑坑洼洼的，看起
来平常经过的人并不多。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xuedaomen/1");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xuedao78",
  "east" : __DIR__"xuedao80",
]));

	setup();
	replace_program(ROOM);
}
