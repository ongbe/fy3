// Room: /d/quanzhou/wstreet3.c

inherit ROOM;

void create()
{
	set("short", "开元寺大门");
	set("long", @LONG
开元寺是泉州最古老的一座寺院,据说这里的菩萨很是灵验,许多乡 
下人也常赶来烧香,寺院的门口不大,淡灰色的院墙,三五级不高的石阶,从 
敞开的门口看进去,能见到一堵照壁. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hufa.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wstreet2",
  "west" : __DIR__"daxiong",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
