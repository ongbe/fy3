// Room: /d/yangzhou/gongyuan.c

inherit ROOM;
#include <localtime.h>
int now_time();
void create()
{
	set("short", "中州贡院");
	set("long", @LONG
中州贡院是天下最热闹的一所考场，每月初一，全国各地的士子都来此处赶考。
院门两边由士兵看守，要想夹带可不行，围墙上有张新贴的告示(gaoshi).
LONG
	);
	set("no_magic", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhukao4.c" : 1,
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "本处限考进士
1.凡已考中进士或以上功名者，不得入考。
2.读书写字未满120级者，不得入考。
3.非举人者不得入考,开考仅限于每月初一。
4.使用[exam]请主考官出题，用[answer .....]回答问题。
5.回答问题限时1分钟.
6.若回答不对，请下月再来。
7.答题时间离开考场，作弃权论。
注意 回答的最后请勿加任何标点符号。
",
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yanling2",
]));
	set("no_fight", 1);
        set("no_steal",1);
        set("no_sleep",1);

	setup();
}
int valid_leave(object me, string dir)
{
  if (dir=="south"&&me->query_temp("xxy/answer")){
  tell_room(this_object(),me->query("name")+"摇摇头长叹一声：看来我还得多读两年!\n");
  me->delete_temp("xxy");
  me->set("xxy/last_check",now_time());
   }
        return ::valid_leave(me, dir);
}
int now_time()
{int i;
 object ob=this_player();
 mixed *local;
 local = localtime(time()*60);
 i=local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0);
 return i;
}
