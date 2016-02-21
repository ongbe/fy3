// Room: /d/robber/trees3.c

inherit ROOM;

void create()
{
	set("short", "松柏林");
	set("long", @LONG
一片稀疏的松柏林,脚下是厚厚的落叶层.头顶的阳光透过交错的
枝条,给这片树林带来几许温暖.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/robber2.c" : 1,
  __DIR__"npc/robber3.c" : 1,
]));
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"trees1",
  "south" : __DIR__"trees4",
]));

	setup();
	replace_program(ROOM);
}
