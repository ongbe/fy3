// Room: /city2/zhengmen.c

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "紫禁城");
	set("long", @LONG
这便是皇宫正门。巍峨雄伟的城墙上，'紫禁城'三个大字十分显眼，
气势辉煌。一带红色的宫墙把宫内外分隔开来,几个御林军在宫前守卫,南
边是玉带桥.
LONG );
	set("item_desc", ([
		"north" :"御林军喝道:贼眉贼眼的干什么,还不快走开.\n", 
	]));
	set("exits", ([
		"south" : __DIR__"bridge",
		"north" : "/d/huanggon/qihedian",
	]));
        set("objects", ([
__DIR__"npc/yulinjun": 2,
__DIR__"npc/duolong":1,
        ]));
	set("outdoors", "city2");
	setup();
}

int valid_leave(object me, string dir)
{
 object ob;
  if (dir=="north")  {
  	if (!me->query_temp("huanggon/enter")||me->query("gender")!="中性")  {
  if (ob=present("guard",this_object())) {
 message_vision("$N拦住$n:大胆,敢擅闯皇宫?\n",ob,me);
 return notify_fail("");
        }
  if (ob=present("duolong",this_object())) {
 message_vision("$N拦住$n:皇宫企是你能进的.\n",ob,me);
 return notify_fail("");
         }
    }
 }
return ::valid_leave(me,dir);
}	