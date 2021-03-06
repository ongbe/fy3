// Room: /d/suzhou/chengdongjie1.c

inherit ROOM;

void create()
{
	set("short", "城东街");
	set("long", @LONG
由于东街靠近苏州府，更具安全，因此本地大贾富豪大都迁至此街。北边的
高大宅院是顾宅，面南背北实是个好地方。正对面是陆宅，家境虽不如顾家，但
也是苏州巨富之一。街道东西走向，西面是城中广场。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengzhong",
		"east" :__DIR__"chengdongjie2",
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
