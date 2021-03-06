// Room: /u/uuui/huatuo.c

inherit ROOM;

void create()
{
        set("short", "华佗殿");
        set("long", @LONG
华佗殿顾名思义，是凝王府的神医住的，但这里似乎
有些不同，进门正面的墙上有一幅对联，但只有上联
左手是卧室。里面床柜，衣服，桌椅一一俱全右手是
烈震北看病的场所。一面医柜，一把太师椅。茶几摆
设虽简单，但齐全实用。明间中央桌子供了一尊华佗
像，案几上还有一些摆设。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huihong",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

