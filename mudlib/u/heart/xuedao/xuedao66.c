// Room: /u/uuui/xuedao/xuedao66.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
这条碎石小路蜿蜒曲折，随说是通往石牢。但也做
的甚是精细。清风徐徐。也有种遐意的感觉。但是再往前
走。却感到死神似乎再向你招手。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xuedaomen/1");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xuedao65",
  "west" : __DIR__"xuedao67",
]));

	setup();
	replace_program(ROOM);
}
