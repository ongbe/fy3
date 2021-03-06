// Room: /d/quanzhou/dongmen.c

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是泉州府的东门,因为离此不远就是泉州的海港,来往装运的货 
物和商品特别多,所有看守也特别多一些,为的是盘查方便.旁边的城墙上
挂了张榜文(bangwen),围了一圈人在看. 
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "bangwen" : "从今日起,凡出海者,先到本府领取路引,方
能出海,路引每张白银五两.
                 泉州府.
",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/bing.c" : 2,
  __DIR__"npc/shoubei.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"estreet2",
  "east" : __DIR__"dalu1",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
