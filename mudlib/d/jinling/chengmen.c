// Room: /d/jinling/chengmen.c

inherit ROOM;

void create()
{
	set("short", "南城门");
	set("long", @LONG
这里就是竟陵南门，近来局势不太稳定，城内外常因帮派间抢地盘而发
生流血事件，所以城门口兵卫很多，对过往之人盘查很严。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yinjiaweishi.c" : 1,
  __DIR__"npc/weibing.c" : 4,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"changjie.c",
  "south" : __DIR__"guandao",
]));
	set("outdoors", "/d/jingling");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
