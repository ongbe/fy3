// Room: /d/tianshan/caoyuan.c

inherit ROOM;

void create()
{
	set("short", "藏边草原");
	set("long", @LONG
歌声杂着马铃飘荡在藏边的草原，一群卖唱的流浪者正在草原经过.
草原四望无边，喜马拉雅山绵延天际，晶莹的雪峰象一排排白玉雕成的
擎天玉柱，高插云霄，隐隐露出头来，似是正在倾听流浪者的哀弦凄诉。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liuliang.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/tianshan");

	setup();
	replace_program(ROOM);
}
