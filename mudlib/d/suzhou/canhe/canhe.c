// Room: /d/suzhou/canhe/canhe.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "参合山庄");
	set("long", @LONG
只见小岛上疏疏落落的四五间房舍。房舍小巧玲珑颇为雅致。正对面一座
大门，大门匾额上“参合”二字十分醒目。门两边立着两个庄丁，面目冷淡，
一副拒人于千里之外的模样。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" :__DIR__"huan",
		"east" :__DIR__"qianting",
]));
	set("objects",([
		__DIR__"npc/zhuangding" :2,
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me,string dir)
{
	object npc;
	if(me->query("family/family_name")=="姑苏慕容")
		return 1;
	if(dir!="east")	return 1;
	npc=present("zhuang ding",this_object());
	if(!npc)	return 1;
	return notify_fail(CYN"庄丁怒道：“非姑苏慕容弟子不得入内！\n"NOR);
}
