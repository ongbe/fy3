// Room: /d/hangzhou/tanei.c

inherit ROOM;

void create()
{
	set("short", "雷峰塔内");
	set("long", @LONG
庄严宏伟的雷峰塔内空空如也,抬头上望,一线天光从塔尖镇塔葫芦 
的口子直射而下.四壁的条石上雕刻了经文.在塔壁还有金刚,菩萨等小佛 
像.一面壁上挂着张法偈(fajie),塔正中的莆团上坐了个僧人. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"leifeng",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "fajie" : "佛亦爱财,二两不少!
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fahai.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
