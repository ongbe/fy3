// Room: /d/huanggon/shilaoxiaotang
inherit ROOM;

void create()
{
  set ("short", "石牢小堂");
  set ("long", @LONG
石牢内的一座小堂,四面的石壁极为厚实,北面墙壁上开了个铁窗.里
面传来铁链叮当声,有人在里面大声咆哮,听说关押的就是权倾当朝的熬
拜了.南面是条走廊.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shilaozoulang",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "铁窗" : "铁窗上铁条极粗,看来不是随便能断开的.
",
]));
  setup();
}
void init()
{
  add_action("do_kan","kan");
}
int do_kan(string arg)
{
  object ob,inv;
  if (!arg||arg!="铁条") return notify_fail("你要砍什么?\n");
  ob=this_player();
  if (!present("yitian jian",ob)&&!present("tulong dao",ob))
  return notify_fail("你砍了一阵窗上的铁条,看来没什么起色.\n");
  if (present("yitian jian",ob))  {
  message_vision("$N取出依天剑,将铁窗上的铁条一一削落,墙上
 开了个大口子,看来能进去了.\n",ob);
  set("exits/down",__DIR__"shilaonei");
  ob->set_temp("aobai",1);
  return 1;
 }
 if (present("tulong dao",ob))  {
  message_vision("$N取出屠龙刀,对窗户上的铁条一阵乱削,
 窗户马上开了个大口子,看来能进了.\n",ob);
  set("exits/down",__DIR__"shilaonei");
  ob->set_temp("aobai",1);
  return 1;
 }
 return 1;
}