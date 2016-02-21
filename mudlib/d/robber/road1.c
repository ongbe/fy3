// Room: /d/robber/road1.c

inherit ROOM;

void create()
{
	set("short", "杂草小路");
	set("long", @LONG
一条弯弯曲曲的小路，两边疯长的杂草几乎把路面完全盖住了，不断
有细小的昆虫在头顶跳越而过。讨厌的灌木丛也时时挡住你前进的路。南边
是一片凄惨的坟地，隐隐笼罩在一层悲凉之中。
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"tomb1",
  "northeast" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
