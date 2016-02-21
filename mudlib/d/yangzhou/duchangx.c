// Room: /d/yangzhou/duchangx
inherit ROOM;

void create ()
{
  set ("short", "赌场内室");
  set ("long", @LONG
这里就是赌场的内室了，从这里可以通往各个房间。西边是赌「骰子」
的房间，北边是赌「压签」的房间，楼上是赛龟的地方，在南边的大院里
是斗鸡的地方。大堂的墙上挂着一块牌子(paizi)。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "千金散尽复还来。",
]));
  set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"duchang4",
  "west" : __DIR__"duchang2",
  "north" : __DIR__"duchang1",
  "south" : __DIR__"duchang",
  "east":__DIR__"duchang3",
]));
  set("light_up", 1);

  setup();
}
