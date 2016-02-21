// thd:dukou_thd.c

inherit ROOM;

void go_back();

void create()
{
      set("short", "桃花岛码头");
	set("long", @LONG
这里是桃花岛的码头，是桃花岛和外界向连通的门户。码头上停着不
少小船，上面都满载这干粮和清水，足可以支持到大路。但大海是难以预
测的，一出海谁又能预料会发生什么事呢。码头的东面就是一望无边的大
海，它此时虽然温顺的象你手中的小猫，但它发起努来就会变成一头恐龙
。这茫茫大海蕴含着多少神秘，多少危险啊！码头旁有个小茅草棚，有几
个船夫在休息。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/chuanfu1" :  1,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"bulletin" : "...\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"road1",
	]));
      
	set("outdoors", "thd");


	setup();
	replace_program(ROOM);
}

