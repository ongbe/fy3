// Room: /d/jinling/changjie2.c

inherit ROOM;

void create()
{
	set("short", "长街");
	set("long", @LONG
这里是竟陵城的主要街道，由于竟陵城南北长而东西短，所以就行成
了这条长达两里的街道。这也是竟陵最繁华的商业街．南面就是市中心了．
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jingling");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"changjie1.c",
  "north" : __DIR__"shizhong.c",
]));

	setup();
	replace_program(ROOM);
}
