//make by temp
//ROOM: wumingsy.c

inherit ROOM;

void create()
{
        set("short", "无名山腰");
        set("long",@LONG
这就是无名山的山腰了，从这里向下望去，哦，好大的一片
森林呀，咦，森林里好像还有个小湖。你抬头向山顶望去。好象离
山顶不远了，加把劲吧。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"miling5",
                "northup" : __DIR__"xuesongl3"
        ]));
        setup();
        replace_program(ROOM);
}
