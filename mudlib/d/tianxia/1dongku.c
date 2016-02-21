// Room: /d/tianxia/1dongku
inherit ROOM;

void create()
{
  set ("short", "地牢");
  set ("long", @LONG
黑暗的地牢，你走在一条石头甬道中，这是在天然通道的基础上改造
而成的。水滴从甬道的四壁滴落下来，地上湿漉漉的，整个通道向下倾斜。
就象野兽张开的巨口。东面是刑室，西面是看守室。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"1dongku3",
  "west" : __DIR__"1dongku2",
  "northdown" : __DIR__"1dongku1",
  "southup" : __DIR__"1road3",
]));
  setup();
  replace_program(ROOM);
}
