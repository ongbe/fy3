inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
     这里是光明顶的后花园，种满了花草。几个小童正在浇花
北边有一个幽雅的小屋。

LONG
        );

        set("exits", ([
                "south" : __DIR__"dadian",
                 "north":__DIR__"guifang.c",
              "west": __DIR__"tan",
                ]));

        setup();
        replace_program(ROOM);
}
