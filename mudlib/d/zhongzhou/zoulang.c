//zoulang
  

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是衙门大堂后面的走廊，走廊西面有一小石拱门，里面是一个小
花园，花丛中有两个花匠正在修剪花草。北面走廊的尽头的门开着，不
知是不是就是师爷处.
LONG
	);

	set("exits", ([
		"west" : __DIR__"huayuan",
		"north" : __DIR__"zoulang1",
		"out"  : __DIR__"yamen",

	]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

	setup();
	replace_program(ROOM);
}

