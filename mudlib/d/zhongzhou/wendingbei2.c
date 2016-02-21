//wendingbei2
  

inherit ROOM;

void create()
{
	set("short", "文定北街");
	set("long", @LONG
这是中州城文定北街，宽敞的街道看的人不竟心情一畅。街道的东
面有一间药铺。走到这里就可以闻见一阵浓浓的药味。西面人声鼎沸，
原来是一座戏院子。
LONG
	);
set("outdoors","/d/zhongzhou");

	set("exits", ([
		"east" : __DIR__"yaopu",
		"south" : __DIR__"wendingbei1",
		"west" : __DIR__"xiyuan",
		"north" : __DIR__"wendingbei3",
	]));
	set("objects", ([
	__DIR__"npc/xiashi.c" : 1,
	]));

	setup();
	replace_program(ROOM);
}

