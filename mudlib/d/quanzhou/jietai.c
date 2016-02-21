// Room: /d/quanzhou/jietai.c

inherit ROOM;

void create()
{
	set("short", "甘露戒坛");
	set("long", @LONG
这是一个高无层的高坛,供佛五级,自顶而下为'卢舍那佛','菩萨'四 
尊,'金刚'八位,'护法'三位,'护五戒神主牌头'六十四座,最顶上则有一 
口甘露井,据说以之服药,很有灵效. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dongta",
  "westup" : __DIR__"cangjinge",
  "eastdown" : __DIR__"daxiong",
  "south" : __DIR__"xita",
]));
	set("outdoors", "/d/quanzhou");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/foxiang.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
