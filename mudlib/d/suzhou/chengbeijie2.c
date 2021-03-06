// Room: /d/suzhou/chengbeijie2.c

inherit ROOM;

void create()
{
	set("short", "城北街");
	set("long", @LONG
街东一座宅院，墙壁上醒目的“当”字告诉你这是个当铺。对面的楼匾上三
个大字“回春堂”擦的精光闪亮。上门求医者络绎不绝，可见主人医术不弱。街
道南北延伸，来往行人不断。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" :__DIR__"chengbeijie1",
		"west" :__DIR__"yaopu",
		"north" :__DIR__"chengbeijie3",
		"east" :__DIR__"dangpu",
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
