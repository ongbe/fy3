// thd:back_hole.c

inherit ROOM;

int HAVE_BOOK=1;

void create()
{
      set("short", "囚龙洞后");
	set("long", @LONG
这里是囚龙洞的后部。这里和囚龙前洞迥然不同，前洞很干燥，这里
去很潮湿。这都是因为一条瀑布－－也就是千丈瀑，就从洞的东面经过，
落向大海。因此洞中充满着水气。从这里向西可以看到囚龙前洞。左边的
石壁好象有点特别。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"qiulong_hole",
	]));
      

	setup();
//	replace_program(ROOM);
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("setup_obj");
		call_out("setup_obj", 1, ob);
	}

	add_action("do_hit", "hit");
	add_action("do_du", "du");
	add_action("do_du", "read");
	add_action("do_climb", "climb");
}

int do_hit(string arg)
{
	object me;

	if(arg!="石壁") return 0;

	me=this_player();

	message_vision("$N奋力击向石壁。\n",me);

	if(me->query_skill("force")<40)
	{
		message_vision("$N的内功太差了更本打不穿石壁。\n",me);
		return 1;
	}

	message_vision("$N击，$N你击，$N再击……\n",me);

	message_vision("$N终于把石壁给打穿了。\n",me);

	if(HAVE_BOOK==1)
	{
		message_vision("$N看到石壁中有本旧书。\n",me);

	      if( me->over_encumbranced() ) 
			write("但你已经负荷过重了，没法再拿书了 :-( \n");
	      else
      	{
			message_vision("$N拿到一本九阴真经。\n",me);
		      new(__DIR__"obj/jiuyin1")->move(me);
		      HAVE_BOOK=0;
	      }
	}
	else
	{
		message_vision("$N发现石壁中是空的，什么都没有。\n",me);
	}

	return 1;
}

int do_du(string arg)
{
	if((arg!="jiuyin jing1")&&(arg!="jing1")) return 0;

	write("这里不是安全的地方，你还是带出去再读吧！\n");
	
	return 1;
}

int do_climb(string arg)
{
	object me;

	if(arg!="up") return 0;

	me=this_player();
	
	message_vision("$N攀着岩石，奋力朝瀑布方向爬去。",me);

	if(me->query_skill("dodge")<40)
		message_vision("可惜$N轻功太差，爬了没多久，就在也爬不上去了，只的顺原路又爬下来。",me);	
	else
	{
		message_vision("$N爬啊，爬啊，总算爬上了瀑布中的一块岩石。\n",me);	
		me->move(__DIR__"rock");
		message_vision("$N爬上了独孤岩。\n",me);	
	}

	return 1;		
}

void setup_obj(object ob)
{
	write("你走啊，走啊，似乎囚龙后洞就在你眼前了，可一时又走不到。\n");

	remove_call_out("in_backhole");
	call_out("in_backhole", 5,ob);
}

void in_backhole()
{
	write("你绕了好几个圈总算真正走进了囚龙后洞。\n");
}

