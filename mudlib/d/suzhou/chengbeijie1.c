// Room: /d/suzhou/npc/chengbeijie1.c

inherit ROOM;

void create()
{
	set("short", "城北街");
	set("long", @LONG
西边是家酒楼，人来人往倒也着实热闹，一面黄底金边的锦旗随风飘扬，上
面绣着三个大字“松鹤楼”。东边则飘来温柔圆润的歌声，在“叮咚叮咚”的乐
器伴奏下更令人回肠荡气。街道向北延伸，南面是城中广场。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east" :__DIR__"sizhuxuan",
		"south" :__DIR__"chengzhong",
		"north" :__DIR__"chengbeijie2",
		"west" :__DIR__"songhelou",
]));
	set("objects",([
		__DIR__"npc/feizei":1,
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
