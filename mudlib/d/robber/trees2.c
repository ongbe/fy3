// Room: /d/robber/trees2.c

inherit ROOM;

void create()
{
	set("short", "松柏林");
	set("long", @LONG
稀疏的一片松柏林,脚下长年累月落下的树叶铺了厚厚的一层,踩上去
悉悉索索地响.几个甲虫沿着树干困难得爬着,树林中一片寂静.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"trees",
]));

	setup();
	replace_program(ROOM);
}
