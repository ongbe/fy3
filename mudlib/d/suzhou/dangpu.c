// Room: /d/suzhou/npc/dangpu.c

inherit ROOM;

void create()
{
	set("short", "受和当铺");
	set("long", @LONG
当铺内十分安静，一人多高的柜台包着精光闪亮的铜皮，显得很是气派。店
主起家之前，曾饱受买卖之间的冤枉气。立业之后，便把和气生财置于心中，所
以给当铺起了个“受和”的名字。不过前些时因为有些经济问题被州府查封了。
现在整顿后重开了。

LONG
	);
        set("objects", ([
		__DIR__"npc/ye" :1,
        ]) );

set("no_steal",1);
//	set("objects",([
//		__DIR__"npc/ye.c" :1,
//	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengbeijie2",
]));
	set("no_clean_up", 0);

	setup();
	 replace_program(ROOM);
}
