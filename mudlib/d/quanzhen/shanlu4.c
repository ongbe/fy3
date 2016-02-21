// Room: /d/quanzhen/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
	这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南
山的山脚了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"shanjiao",
  "northwest" : __DIR__"shanlu2",
]));

	setup();
set("outdoors","/d/quanzhen");
	replace_program(ROOM);
}
