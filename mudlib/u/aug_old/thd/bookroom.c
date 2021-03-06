// thd:bookroom.c

inherit ROOM;

void create()
{
      set("short", "书房");
	set("long", @LONG
这里是黄药师的书房。虽说黄药师薄古非今，但他的书可真不少，整
整摆满了西面的那个大书架。屋子的东边是张竹制的书几，书几上摊着几
本黄岛主正在看的书，甚至有一本还是竹简呢。东面的墙上还挂着幅水墨
山水，画的是一条山路在浓雾中若隐若现的盘曲着，看来十分神秘，让人
搞不懂是什么意思。书房的北面是黄岛主的寝室，东面是大厅。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/hyaoshi" :  1,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
	    "southeast" : __DIR__"hall",
	    "north" : __DIR__"bedroom",
	]));
      
	setup();
	replace_program(ROOM);
}

