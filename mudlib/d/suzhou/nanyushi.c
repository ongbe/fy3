// Room: /d/suzhou/nanyushi.c

inherit ROOM;

void create()
{
	set("short", "男浴室");
	set("long", @LONG
专供男人洗澡的地方，室中摆放了不少大圆桶，几个青年小伙子在一旁侍侯。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yushi",
]));
	set("bath_room",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
