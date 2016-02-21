// Room: /u/o/oldsix/room/crossroad.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
没有什么特别之处。由于快到大堂了，一般的人连大气都不敢喘一下。生
怕不小心得罪了谁。北面是演武厅，南面是牢房，西面是出府的必经之路，东
面则是苏州府大堂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" :__DIR__"ermen",
	"north" :__DIR__"yanwuting",
	"south" :__DIR__"road4",
	"east" :__DIR__"tangkou",
]));
	set("objects",([
		__DIR__"npc/gengfu":1,
		]));
	set("no_clean_up", 0);
	set("outdoors","room");
	setup();
	replace_program(ROOM);
}
