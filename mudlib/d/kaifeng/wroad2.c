// Room: /d/kaifeng/wroad2.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
开封府内西面的主要交通要道，街道两边店铺林立，行人车马如梭。
商贩的吆喝，市民与小贩的讨价还价，喧闹无比。西面就是延庆观，东
面可以上到角楼。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qigai.c" : 1,
]));
	set("outdoors", "/d/kaifeng");
	set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"jiaolou",
  "west" : __DIR__"yanqing",
  "north" : __DIR__"wroad3",
  "south" : __DIR__"wroad1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
