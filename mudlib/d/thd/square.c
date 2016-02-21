// thd:square.c

inherit ROOM;

void create()
{
      set("short", "练武场");
	set("long", @LONG
这里是桃花岛的练武场。场地十分宽敞，但你一般见不到什么人，毕
竟能进这里的都可以算是江湖上的高手了。他们练的多的都是内功，谁还
来练那些粗浅的拳脚功夫。西面是休息室可练功房，再往北走就是桃花岛
的议事大厅了。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"in_road2",
	    "north" : __DIR__"in_road4",
	    "east" : __DIR__"in_road5",
	    "west" : __DIR__"in_road3",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

