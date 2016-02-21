// Room: /d/robber/trees1.c

inherit ROOM;

void create()
{
	set("short", "松柏林");
	set("long", @LONG
稀疏的一片松柏林,脚下是厚厚的一片树叶,阳光下,似乎有淡淡的水汽
从脚下冒出来,树林中充满腐烂的味道.迎面一棵树被刮去了树皮,上面还刻
了些歪歪扭扭的字(zi).
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "不知是谁用小刀刻了[擅闯者死]几个字,看上去歪歪扭扭的
肯定没学过读书写字.
",
]));
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"trees",
  "south" : __DIR__"trees3",
]));

	setup();
	replace_program(ROOM);
}
