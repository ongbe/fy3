//Mr.music  yangzhou's 皮市街 3

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "皮市街");
        set("long", @LONG
	这里是城北大街--皮市街，因这条街沿街都是有名的酒楼、茶馆，
所以又被誉为“美食街”。沿街食品玲廊满目，菜香酒气阵阵扑鼻，你不由
自主的放慢了脚步。向西是城里最大的一家酒楼--明月酒楼，只见楼牌匾上
龙飞凤舞的写着“天下三分明月夜  二分无赖是扬州”。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("objects", ([
        //      __DIR__"obj/box" : 1,
        ]));

        set("exits", ([
              "south" : __DIR__"pishijie2",
              "north" : __DIR__"beimen",
              "west"  : __DIR__"startroom",
              "east"  : __DIR__"shuchang",
                     ]));
        setup();
        replace_program(ROOM);
}

