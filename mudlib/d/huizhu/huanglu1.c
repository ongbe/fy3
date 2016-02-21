// Room: /d/huizhu/huanglu1
inherit ROOM;

void create()
{
  set ("short", "荒路");
  set ("long", @LONG
这是条荒野小路，路上几乎看不见什么人。阴风四起，让你觉得后
颈发凉。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huanglu2",
  "southeast" : __DIR__"guanwai",
]));
  set("outdoors", "/d/huizhu");
  setup();
  replace_program(ROOM);
}
