// Room: /d/kaifeng/dadao1
inherit ROOM;

void create()
{
  set ("short", "三叉路口");
  set ("long", @LONG
道路至此分为三路，一路向北就是开封城，东南面是一座树林。林
中隐有条小道穿过。西南面的路通向野猪林。
LONG);

  set("outdoors", "/d/kaifeng");
  set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"dadao2",
  "southeast" : __DIR__"shulin",
  "north" : __DIR__"dadao",
]));
  setup();
  replace_program(ROOM);
}
