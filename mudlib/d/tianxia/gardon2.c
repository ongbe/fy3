// Room: /d/tianxia/gardon2
inherit ROOM;

void create()
{
  set ("short", "小花园");
  set ("long", @LONG
几块太湖石乱七八糟的堆叠着，一边的一个小池塘污浊不堪。堆
满了垃圾。仅有的几棵白扬也耷拉着脑袋，看来快枯死了。北边有
栋房子，看来还不错。
LONG);

  set("outdoors", "/d/tianxia");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"house",
  "southwest" : __DIR__"gardon",
]));
  setup();
}
