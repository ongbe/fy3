#include <weapon.h>
inherit HAMMER;
int count;
void create()
{
	set_name("马头琴", ({"matou qin", "qin"}));
	if( clonep() )
                set_default_object(__FILE__);
 else {
	set("long","一把长琴,顶端雕刻成马头形.\n");
	set("unit", "把");
	set("weight", 10);
	set("value",100);
	set("no_drop",1);
     }
   init_hammer(4);
     setup();
 }
void init()
{
        add_action("do_play","play");
}
int do_play(string arg)
{
  object ob=this_player();
  if (!arg||arg!="马头琴") return notify_fail("你要弹什么?\n");
  if (count>=3)  {
 message_vision("$N拨动$n,深情的唱起草原牧歌.\n",ob,this_object());
 return 1;
     }
  count++;
 message_vision("$N拨动$n,发出一阵颤音,一块银子掉了下来.\n",ob,this_object());
 new("/obj/money/silver")->move(environment(ob));
 return 1;
 }
  	
  