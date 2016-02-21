// Room: /d/suzhou/tuoman/hua2.c

inherit ROOM;

void create()
{
	set("short", "花林");
	set("long", @LONG
走出数十丈后，只见山茶花品种渐渐多了起来，偶尔也有一两本还算不错，
却也是栽种不得其法。这庄子枉自以‘曼陀’为名，却把佳种山茶给糟了蹋。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south":__DIR__"hua1",
		"west" :__DIR__"hualin1",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
