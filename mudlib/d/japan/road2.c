// Room: /d/japan/road2
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG
һ�������Ĵ��,ʱ��ʱ��������,���ε�,С��,���˾���.�������
���˴����·���ʮ������,����ǰ��û����.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"road1",
  "southwest" : __DIR__"road",
]));
  set("outdoors", "/d/japan");
  setup();
}