// thd:hill3.c

inherit ROOM;

void create()
{
      set("short", "山路");
	set("long", @LONG
这里的山路特别陡峭，有的地方甚至到达六十度以上的倾角，非有绝
顶轻功者绝难到达此处。道路两旁有些杂草野花确是长的很好，一派自然
风光。在上去就是囚龙洞了。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "northup" : __DIR__"hill4",  
          "southwest" : __DIR__"hill2",        
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

