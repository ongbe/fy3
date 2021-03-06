// Room: /u/swordman/yangzhou/shuyuan
inherit ROOM;

#include <localtime.h>;
int now_time();
void create ()
{
  set ("short", "扬州书院");
  set ("long", @LONG
门前两株绿柳，圆拱门上两个红色大字分外引人注目[扬州书院]，里面
不时地传来学生们抑扬顿挫的读书声。这里也是考童生的地方，东边的院墙
上贴了一张告示(gaoshi)。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kaoguan" : 1,
  __DIR__"npc/shutong.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ddajie",
]));
  set("outdoors", "y");
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "本处限考童生
1.凡已考中童生或以上功名者，不得入考。
2.读书写字未满10级者，不得入考。
3.使用[exam]请主考官出题，用[answer .....]回答问题。
4.若回答不对，请明天再来。
5.答题时间离开考场，作弃权论。
注意 回答的最后请勿加任何标点符号。

",
]));
  set("no_magic", 1);
  set("no_fight", 1);

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir=="west"&&me->query_temp("xxy/answer")){
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

