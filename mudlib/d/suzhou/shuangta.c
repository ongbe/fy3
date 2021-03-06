// Room: /d/suzhou/shuangta.c

inherit ROOM;

void create()
{
	set("short", "双塔下");
	set("long", @LONG
但见双塔玲珑挺拔，恰似两支插着的笔，别具风韵；塔前三间平房，夕阳西
下，塔影斜卧屋面，宛如笔架； 塔的东侧是四方形五层钟楼，酷如一锭粗墨，正
所谓“双塔为笔，钟楼为墨”。据载此双塔建于北宋年间，一为舍利一为功德。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengnanjie3",
		"east" :__DIR__"gongdeta",
]));
	set("objects",([
		__DIR__"npc/baobiao":2,
		__DIR__"npc/makepilo":1,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
