// thd:forest_road1.c

inherit ROOM;

void create()
{
      set("short", "竹林小径");
	set("long", @LONG
这是条泥土小径。你两旁是望不到尽头的竹林，现在你整个人已经
被绿所包围，你整个人也似乎被这醉人的绿所感染，平添一番诗情画意
。你脚下的路向南北两个方向延伸着。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"forest_start",
          "south" : __DIR__"np",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

