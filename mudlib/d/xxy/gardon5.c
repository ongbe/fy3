// Room: /d/xxy/gardon5.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是花园中的一条五彩石子路,从无数的花木中穿过.远处雾霭中露出红
檐一角,那就是天风楼.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"gardon4",
  "northeast" : __DIR__"gardon1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "n" : "",
]));
	set("outdoors", "/d/xxy");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
