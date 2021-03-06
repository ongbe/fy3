// Room: /u/swordman/yangzhou/jiedao2.c

inherit ROOM;

void create()
{
	set("short", "长堤春柳");
	set("long", @LONG
你走在湖边的长堤上，湖水澄碧，堤畔三步一桃，五步一柳，
相间成行，柳绿桃红，“天地无私，春光秋月尽我流连”，使你
仿佛置身于世外桃园之中。向西北是四桥烟雨，向南是山庄大门。
堤岸有一小亭，供稍事小憩。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jiedao1",
  "northwest" : __DIR__"jiedao3",
  "east" : __DIR__"xiaoting",
]));
	set("outdoors", "/u/swordman");
	set("light_up", 1);

	setup();
	replace_program(ROOM);
}
