inherit ROOM;

void create()
{
        set("short", "食堂");
        set("long", @LONG
这里是明教食堂，许多明教弟子正排队打饭，一股香喷喷的气味
迎面袭来，你也快去吃点吧.
LONG
        );

        set("resource/water", 1);
        set("objects", ([
                "/d/obj/food/hulu" : 1,
                "/d/obj/food/kaoji":3,
                            ]));
        set("exits", ([
  "east" : __DIR__"tonglu1",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}
