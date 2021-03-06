// Room: /d/suzhou/chengxijie.c

inherit ROOM;

void create()
{
	set("short", "城西街");
	set("long", @LONG
好一个热闹的街道，来来往往尽是行人。卖杂货的小贩、打巴式卖艺的艺人、
前来游玩的路人、偷鸡摸狗的地痞，真是集天下各式各样的人物。你的脑海中
不时闪现在“上有天堂，下有苏杭”这句话。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"xichengmen",
		"east" :__DIR__"chengxijie2",
]));
	set("objects",([
		__DIR__"npc/dipi":1,
		__DIR__"npc/xiaofan" :1,
]));
	set("outdoors","suzhou");

	setup();
	replace_program(ROOM);
}
