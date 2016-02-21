// Room: /d/city2/duchang2.c

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
"这个大厅的四面有走廊通向不同的房间,你一眼看去,房门都
关着,看来今天休息,老板不想作生意了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"duchang",
]));

	setup();
	replace_program(ROOM);
}
