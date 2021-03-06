// Room: /u/swordman/yangzhou/wuguan
inherit ROOM;

void create ()
{
  set ("short", "扬州武馆");
  set ("long", @LONG
你现在正站在一个扬州武馆的教练场中，地上铺着黄色的细砂，
一群二十来岁的年轻人正在这里努力地操练着, 还有一个中年汉子
在不停的喊着号子，让人振奋。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youngman" : 4,
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beijie1",
  "east" : __DIR__"wuguan1",
]));

  setup();
}
