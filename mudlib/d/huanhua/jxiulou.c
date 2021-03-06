// Room: /d/new/huanhua/jxiulou.c

inherit ROOM;

void create()
{
	set("short", "甲秀楼");
	set("long", @LONG
    水从碧玉环中出， 
        人在青莲瓣里行。 
贵州名胜南明河上的甲秀楼,既可观赏风景,又可品尝佳肴. 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"jhongqiao",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/2jian2.c" : 1,
  __DIR__"npc/2jian1.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
