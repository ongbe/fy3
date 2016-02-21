// Room: /d/new/tianxia/river1
inherit ROOM;

void create ()
{
  set ("short", "地下河");
  set ("long", @LONG
冰冷汹涌的水流冲刷着你,无边的黑暗笼罩着你.顺着水流似乎飘下
来一些东西,你看不清是些什么.旁边的石壁看来能爬上去.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "石壁" : "这片石壁突起很多,看来能爬上去.(climb 石壁)
",
]));

  setup();
}
void init()
{
 object ob;
 ob=this_player();
 remove_call_out("greeting");
 call_out("greeting",30,ob);
 add_action("do_climb","climb");
}
void greeting(object ob)
{
 if (!ob||environment(ob)!=this_object()) return;
 message_vision("一阵激流冲来,把$N一下子卷入水底.\n",ob);
 ob->move(__DIR__"river2");
 return;
}
int do_climb(string arg)
{
  object ob;
  ob=this_player();
  if (!ob||environment(ob)!=this_object()) 
      return notify_fail("");
  if (!arg||arg!="石壁") return notify_fail("你要爬什么?\n");
  tell_room(__DIR__"incave2",ob->name()+"从地下河中狼狈地爬了上来!\n");
  message_vision("$N攀着石壁爬了上去!\n",ob);
  ob->move(__DIR__"incave2");
  return 1;
 }
