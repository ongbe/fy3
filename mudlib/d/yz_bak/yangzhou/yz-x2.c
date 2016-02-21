// music yangzhou's 叉路口 2

inherit ROOM;

void create()
{
  set ("short", "叉路口");
  set ("long", @LONG
	这是一个叉路口，南面通往砚池山庄，北面通往西北城郊，
西边传来郎郎书声，可能是个学堂。向东就是扬州最繁华的街道--
被誉为“春风十里扬州路”的东关街了。

LONG
    );

  set("objects", ([ 
                   __DIR__"npc/shusheng" : 1,
                 ]));
  set("outdoors", "/d/yangzhou");
  set("exits", ([  
    "west" : __DIR__"shuyuan",
    "south" : __DIR__"yanchi",
    "north" : __DIR__"jiedao2",
    "east"  : __DIR__"dongguan1",
]));

  setup();
}
