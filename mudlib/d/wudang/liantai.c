// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;

void create()
{
    set("short", "十二莲台");
    set("long", @LONG
你走在一条宽敞的石廊上，南边是一个高高的牌楼，雕梁画栋很是好看。
南面是三天门，北面是紫金城，还有一条路是向西的，不知道到哪去。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zijincheng",
	"south" : __DIR__"santian",
    ]));
}
