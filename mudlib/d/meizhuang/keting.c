// Room: /d/suzhou/meizhuang/keting.c

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
这儿是招待来访客人的大厅。厅两侧摆放着座椅，正当中悬挂着一幅
画，虽只寥寥数笔，气势可着实不凡。两个家丁装束的老者立于大厅两旁，
目光炯炯，显是武功不低。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" :__DIR__"heilang1",
  "south" : __DIR__"tianjing",
]));
	set("objects",([
		__DIR__"npc/dingjian":1,
		__DIR__"npc/shilingwei":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
