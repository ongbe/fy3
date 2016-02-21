// Room: /d/new/huanhua/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
剑庐大厅,平时萧西楼接见客人的所在.向南一面都是镶了玻璃的长窗.
里面沿墙摆了许多酸枣木椅子,大块的青石板铺地,使得此处比外面平白
高了近三尺.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tangrou.c" : 1,
  __DIR__"npc/zuoqiu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tianjin",
  "south" : __DIR__"huapath2",
  "east" : __DIR__"xiaolu",
]));
set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
