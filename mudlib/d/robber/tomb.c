// Room: /d/new/robber/tomb.c

inherit ROOM;

void create()
{
	set("short", "坟场");
	set("long", @LONG
零零落落的七八个坟堆,却使此地平添几风凄惨,微风吹过,阴森森的,
高高的茅草微微摆动,几块残破的石碑在阳光下闪着惨白的颜色,西面过
去有片松柏林子.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "石碑" : "   先大人张公景德之墓
     不孝子张山率媳李氏谨立.
",
]));
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tomb1",
  "south" : __DIR__"hill",
  "west" : __DIR__"trees",
]));

	setup();
	replace_program(ROOM);
}
