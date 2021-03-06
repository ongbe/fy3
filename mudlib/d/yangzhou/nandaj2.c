// Room: /u/swordman/yangzhou/nandaj2.c

inherit ROOM;

void create ()
{
  set ("short", "南大街");
  set ("long", @LONG
你走在扬州城的一条大街上，街上人声鼎沸，车马如龙。沿街边
满是各类的商家、店铺和小贩。这里南来北往的路人不断，还不时有
游方郎中，算命打卦的来回游荡。从这里往北就是城市的中心了。西
边是一家顾客众多的茶馆，三教九流人士都在那里谈天说地。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/langzhong" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jiulou",
  "west" : __DIR__"chaguan",
  "north" : __DIR__"nandaj1",
  "south" : __DIR__"nandaj3",
]));
  set("outdoors", "/u/swordman");

  setup();
}
