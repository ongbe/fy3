//Mr.music yangzhou 书场

inherit ROOM;

void create()
{
        set("short", "书场");
        set("long", @LONG
	这里是全市闻名的书场，每天来这里听书的络绎不绝，场场
暴满，要知道今天说啥，先看看这里墙上张贴的海报。内容主要是这
里前辈们的酸甜苦辣，爱恨情仇，和英雄事迹。这里也有不少的武侠
书可以看, 有兴趣也可一读。

LONG
        );

        set("exits", ([ 
                      "west" : __DIR__"pishijie3",
                     ]));
        set("objects", ([
                __DIR__"npc/keren": 2,
//		 __DIR__"npc/obj/mud_book1":2 ,
//		__DIR__"npc/obj/mud_book2":2 ,
//		__DIR__"npc/obj/mud_wizard": 1,
        ]) );

        setup();
        replace_program(ROOM);
}


