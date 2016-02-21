inherit ROOM;

void create()
{
        set("short", "小树林");
        set("long", @LONG
喜鹊从你的头顶飞过。这里生长着郁郁葱葱的灌木丛。张目四望，
你发现有几个粗壮的树干上有利器砍过的痕迹。好象有人在这里呆过
。海风阵阵吹过，你感觉快意无比。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"xiaoyucun.c",
]));
        set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/girl.c" : 1,
]));
    set("outdoors", "taohua");

        setup();
        replace_program(ROOM);
}

