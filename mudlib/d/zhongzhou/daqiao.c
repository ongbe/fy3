// Room: /d/zhongzhou/daqiao.c

inherit ROOM;

void create()
{
	set("short", "中州大桥");
	set("long", @LONG
好一座气势宏伟的大桥，桥下没有石墩，全靠不知什么的东西拉于
江上，不知有无危险。大桥被长江雾气笼罩，根本看不清对面的景象。
桥中央站着一位巨汉，目光倪视着你，不知在打些什么主意。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south":__DIR__"dukou",
  "north":"/d/yangzhou/dukou",
]));
	set("outdoors", "zhongzhou");
	set("objects",([
		__DIR__"npc/konglaoer":1,
	]));

	setup();
}

int valid_leave(object me,string dir)
{
	string banghui;
	object ob;

	ob=present("kong laoer",this_object());
	if(!objectp(ob) || !living(ob))
		return ::valid_leave(me,dir);
	banghui=(string)me->query("banghui");
	if(me->query_temp("oldsix/can_leave"))  {
                me->delete_temp("oldsix/can_leave");
                return ::valid_leave(me,dir);
	}
	if(banghui && banghui==(string)ob->query("banghui"))
		return ::valid_leave(me,dir);
	if(dir!="north")	return ::valid_leave(me,dir);
	return notify_fail("孔老二拦在桥头道：要过江先付(pay)白银五两！\n");
}


