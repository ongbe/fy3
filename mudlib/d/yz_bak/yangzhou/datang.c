//Mr.music yangzhou 大堂

inherit ROOM;

void create()
{
        set("short", "知府大堂");
        set("long", @LONG
	这里就是扬州府大堂，大堂正前方是一位仙风道骨的老人，他就是
扬州知府，名扬四海的大文豪--欧阳修。欧阳修历来以爱才闻名海内，如果
你的能得到他的赏识，就是万幸了。堂前醒目的大字是“肃静”。

LONG
        );

        set("exits", ([ 
                      "north" : __DIR__"yamen",
                     ]));
        set("objects", ([
                __DIR__"npc/shutong": 2,
		__DIR__"npc/ouyang":1,
        ]) );

        setup();
}

