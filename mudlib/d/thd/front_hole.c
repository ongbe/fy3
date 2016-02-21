// thd:front_hole.c
// 97.7.14 bu Aug

inherit ROOM;

void create()
{
      set("short", "囚龙洞前");
	set("long", @LONG
这是囚龙洞前的一块平地。四周怪石林立，有若猛兽者，有若山鬼者
，皆森然欲搏人，陡然见之，不由的会吃一大惊。从这里就可以忘记囚龙
洞的入口，那是桃花岛囚人之所，等闲你还是不要到这里来为好。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"qiulong_hole",
          "west" : __DIR__"hill4",
	]));
      
	setup();
	replace_program(ROOM);
}

