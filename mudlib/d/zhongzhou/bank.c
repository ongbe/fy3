//bank
  

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这里是一家钱庄，据说这里的信誉很好。几个伙计在柜台上忙着。柜
台上还有一块牌子(paizi)，因是干钱的营生，这里的保镖身手不凡，让
你打不到什么坏主意。
LONG
	);

	set("exits", ([
		"east" : __DIR__"wendingnan1",
		 
	]));
set("no_fight",1);
set("item_desc",([
"paizi":"存钱:cun  查账:check    取钱:qu 换:huan \n",
"paizi":"存钱:cun  查账:check    取钱:qu 换:huan \n",
]));
		set("objects" , ([
		__DIR__"npc/yaodezhong":1,
	]));

	setup();
	replace_program(ROOM);
}

