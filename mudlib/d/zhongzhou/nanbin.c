//nanbin
  

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "男浴室");
	set("long", @LONG
	这里是男浴室，这里水气蒙蒙。靠墙一排木桶里好几个人正在沐浴。洗完可以
在旁边的躺椅上小酣一下。
LONG
	);

	set("bath_room" ,1);
	set("exits", ([
		"north" : __DIR__"xiuxian",
]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

	setup();
}


void init()
{
        object ob;

	if( interactive(ob = this_player()))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
        if( !ob || environment(ob) !=this_object()) return;
	if(ob->query("gender")=="女性")
        {
                write(RED
"你一走进来才发觉这是个男浴室，也就这么一瞥的时间，你顿时觉得脸上一阵发烧，心里一慌连忙退出去，不料脚下一滑，只绝得头好象撞到一件硬物，接下来就什么都不知道了。\n"NOR);
		ob->set("sen" ,-1);
		ob->move(__DIR__"wendingnan3");
        }
}
