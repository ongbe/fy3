// Room: /d/robber/tomb1.c

inherit ROOM;

void create()
{
	set("short", "坟场");
	set("long", @LONG
七八个高高低低的坟堆淹没在高高的茅草丛中，几个坟堆已经颓废倒塌。
露出其中的森森白骨，回首夕阳下落处，凄红如雪。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"road1",
  "south" : __DIR__"tomb",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/kulou.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
