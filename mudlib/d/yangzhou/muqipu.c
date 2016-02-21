// Room: /u/swordman/yangzhou/muqipu
inherit ROOM;

void create ()
{
  set ("short", "木器铺");
  set ("long", @LONG
这是一家专售木器的小店，店面不大，却很整洁。所卖木器不过是些
木刀，木枪之类，鲁老板也整日闲逛，无所事事。但私下听说他有门
祖传手艺，确谁也没见过。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"beijie",
]));

  setup();
}
