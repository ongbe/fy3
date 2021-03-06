// Room: /open/stst/sazai/lu4.c

inherit ROOM;
inherit F_BH;

int jian=5,dao=5,fu=5,tongjia=5,gangjia=5;

void create()
{
	set("short","野羊寨库房");
        set("long", @LONG
	这儿是野羊寨的库房，满屋子的柜子和架子。柜子里、架子上乱长八糟的
放了些兵器及防具，你可以用list查看一下。如果你和野羊寨是同一帮会的还可以
在这儿拿取(naqu)一些东西。不过由于这些东西都是抢来的，一般都无法变卖。
LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qianting",
]));

        setup();
}
void init()
{
	add_action("do_list","list");
	add_action("do_naqu","naqu");
}

int do_list()
{
	string msg;
	object me;
	me=this_player();
	if(! living(me))	return 0;
	msg="目前库房内有下列物品可以拿取(naqu)\n";
	msg +="----------------------------------\n";
	if( jian)
	msg +="  长剑(jian)             "+chinese_number(jian)+"把\n";
	if( dao)
	msg +="  单刀(dao)              "+chinese_number(dao)+"把\n";
	if(fu)
	msg +="  板斧(fu)               "+chinese_number(fu)+"把\n";
	if(tongjia)
	msg +="  铜甲(tongjia)          "+chinese_number(tongjia)+"件\n";
	if(gangjia)
	msg +="  钢甲(gangjia)          "+chinese_number(gangjia)+"件\n";
	msg +="----------------------------------\n";
	write(msg);
	return 1;
}

int do_naqu(string arg)
{
	object me,sth;
	string banghui;
	object area;
	me=this_player();
	if(! living(me))	return 0;
	if(! arg)	return notify_fail("你要拿取什么？\n");
	area=new("/obj/area");
	area->create("野羊寨");
	banghui=(string)area->query("banghui");
	destruct(area);
	if( !(string)me->query("banghui") ||
	(string)me->query("banghui")!=banghui)
		return notify_fail("门外的小喽罗叫道：别乱碰库房里的东西。\n");
	if( me->query_temp("have_naqu"))
		return notify_fail("门外的小喽罗叫道：给其他弟兄留些吧，别这么贪。\n");
	if(arg=="jian" && jian)	{
		sth=new("/obj/weapon/sword");
		if( me->query_encumbrance() + sth->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("这把剑对你而言太重了。\n");
		jian --;
		sth->move(me);
		message_vision("$N从架子上拿了把长剑。\n",me);
	}	else if(arg=="dao" && dao)	{
		sth=new("/obj/weapon/blade");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把刀对你而言太重了。\n");
                dao --;
		sth->move(me);
		message_vision("$N从架子上拿了把单刀。\n",me);
	}	else if(arg=="fu" && fu)	{
		sth=new(__DIR__"npc/obj/banfu");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把斧对你而言太重了。\n");
                fu --;
		sth->move(me);
		message_vision("$N从架子上拿了把板斧。\n",me);
	}	else if(arg=="tongjia" && tongjia) {
		sth=new(__DIR__"npc/obj/tongjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这件铜甲对你而言太重了。\n");
                tongjia --;
		sth->move(me);
		message_vision("$N从架子上拿了件铜甲。\n",me);
	}	else if(arg=="gangjia" && gangjia) {
		sth=new(__DIR__"npc/obj/gangjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这件钢甲对你而言太重了。\n");
                gangjia--;
		sth->move(me);
		message_vision("$N从架子上拿了件钢甲。\n",me);
	}	else	return notify_fail("这儿没有这样东西。\n");
	sth->set("no_sell",1);
	me->set_temp("have_naqu",1);
	return 1;
}
