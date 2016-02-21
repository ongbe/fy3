// Room: /d/jinling/shanglin.c

inherit ROOM;

void create()
{
	set("short", "上林苑");
	set("long", @LONG
这里就是著名的上林苑了。上林苑是一座天然园林，加上人工管理，形
成一种独特的风格。而最令它出名的是苑内紫云楼上住着一个绝色美人，号称
“大家”尚秀芳。;使得很多文人骚客，达官贵人竟相前来拜访。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jingling");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu.c",
  "southeast" : __DIR__"chalu.c",
]));

	setup();
	replace_program(ROOM);
}
