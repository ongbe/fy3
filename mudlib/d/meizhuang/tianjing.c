// Room: /d/suzhou/meizhuang/tianjing.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
这是个不太大的小院，左右各植一棵老梅，枝叶如铁，极是苍劲。天
井正中有一口水井，隐隐透出股凉气。院内铺着青石板，上面竟有两个脚
印，不知是哪位高人留下的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" :__DIR__"keting",
  "south" : __DIR__"qingshilu2",
]));
	set("objects",([
		__DIR__"npc/tongnan":1,
		__DIR__"npc/tongnu":1,
]));
	set("no_clean_up", 0);
	set("outdoors","meizhuang");
	set("item_desc",([
	"水井"  :"你可以在这儿灌水（fill）呀。\n",
	"shuijing" :"你可以在这儿灌水（fill）呀。\n",
	]));
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
