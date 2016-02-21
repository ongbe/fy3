// Room: /d/zhongzhou/yuanwan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这里是黄员外的前院，一面大大的墙门上画了个大的倒的富字。绕过
墙门可以到黄员外的前厅。不过据说黄员外是中州出了名的恶霸。没什么
事的话还是不要进去为妙。
LONG
	);
	set("objects",([
		__DIR__"npc/guanjia":1,
	]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yanlingdong1",
]));
	set("outdoors", "/d/zhongzhou");

	setup();
	replace_program(ROOM);
}
