// Room: /d/suzhou/dadao1.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是条连接苏杭的大道。俗话说“上有天堂，下有苏杭”，因而此道人流
不息，极是热闹。由于官府的多次清剿，路人不必再担心安全问题了。但见道
路两旁风景如画，你的心情顿时舒畅了许多。北面是苏州，南下则是杭州。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" :__DIR__"dadao1",
	"south" :__DIR__"dadao3",
]));
	set("objects",([
		"/npc/man5":1,
	]));
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
