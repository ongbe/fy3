// Room: /u/xxy/room/jiaojing2
inherit ROOM;

void create()
{
  set ("short", "小径");
  set ("long", @LONG
沿着小路向前,四周逐渐黑暗起来,最后只有你脚下的路还在光线
之中.抬头上望,两片陡峭的山崖把你包围起来,只剩下一线天光,前面
的路隐没在黑暗中,你发现旁边山壁上有条裂缝.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zhuling",
  "west" : __DIR__"jiulaofe",
  "east" : __DIR__"wanhegu",
]));
set("outdoors","/d/emei");
  setup();
}
