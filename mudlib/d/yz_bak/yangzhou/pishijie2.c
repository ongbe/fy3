//Mr.music  yangzhou's 皮市街 2

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "皮市街");
        set("long", @LONG
	这里是城北大街--皮市街，因这条街沿街都是有名的酒楼、茶馆，
所以又被誉为“美食街”。沿街食品玲廊满目，菜香酒气阵阵扑鼻，你不由
自主的放慢了脚步。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("objects", ([
              __DIR__"npc/qigai" : 2,
        ]));

        set("exits", ([
              "south" : __DIR__"pishijie1",
              "north" : __DIR__"pishijie3",
              "east": __DIR__"kendeji" ,
                     ]));
        setup();
        replace_program(ROOM);
}

