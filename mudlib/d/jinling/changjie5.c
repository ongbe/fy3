// Room: /d/jinling/changjie5.c

inherit ROOM;

void create()
{
	set("short", "长街");
	set("long", @LONG
这里是竟陵城的主要街道，由于竟陵城南北长而东西短，所以就行成
了这条长达两里的街道。这也是竟陵最繁华的商业街。往东就是竟陵的
城卫营，西面却是一个小店铺。.

LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jingling");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"doufudian.c",
  "east" : __DIR__"bingyin.c",
  "south" : __DIR__"changjie4.c",
  "north" : __DIR__"changjie6.c",
]));

	setup();
	replace_program(ROOM);
}
