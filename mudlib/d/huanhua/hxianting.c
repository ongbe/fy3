// Room: /d/new/huanhua/hxianting.c

inherit ROOM;

void create()
{
	set("short", "会仙亭");
	set("long", @LONG
会仙亭位于娄山北麓,为纪念诗仙李白而建,但你看到的只是一座残
破不堪的破亭,连亭子中间都长上了草.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/3jue-jianke.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dloushan",
  "west" : __DIR__"dalu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
