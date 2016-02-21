// Room: /d/taiwan/boss.c

inherit ROOM;

void create()
{
	set("short", "巨大山洞");
	set("long", @LONG
沿着石阶向下,你站在一个巨大的山洞中,抬头向上,是一层层的岩石 
一直伸向数百丈的高处.在靠近一边的石壁旁,依地势凿起了几级台阶,台 
阶的尽头是一尊奇怪的神像.旁边两个大木架上还挂着两副骷髅. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southup" : __DIR__"shandong2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "骷髅" : "这是两具骷髅,森森的白骨似乎在向你狞笑. 
",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/shenxiang.c" : 1,
  __DIR__"npc/hufa.c" : 1,
  __DIR__"npc/mentu.c" : 2,
]));

	setup();
}
void init()
{
 add_action("do_push","push");
}
int do_push(string arg)
{
  object ob;
  ob=this_player();
	if(!ob || environment(ob)!=this_object())	return;
  if (!arg||arg!="shenxiang") return notify_fail("
  你要推什么东西?\n");
  message_vision("$N推开神像跳了下去.\n",ob);
  ob->move(__DIR__"mishi");
  return 1;
 }
