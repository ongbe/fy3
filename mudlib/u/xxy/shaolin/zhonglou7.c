// Room: /d/shaolin/zhonglou7.c
// Date: YZC 96/01/19

inherit ROOM;

string look_bell();
string look_out();

void create()
{
	set("short", "��¥�߲�");
	set("long", @LONG
���������¥֮����ֱ�������ı����ǿڴ��Ӻ�һ�����ҿ�
�еľ��ơ�ϸ�����ӣ��������������ߣ�ֱ��Ҳ��������������
����ͭ�����������������������ӡ�Ĺ�׭������������ǧ�
���ƴֿɺϱ����ɰ�������һͷ���Ժ�Ƥ������������������ɽ
�紵��������˭������ס��ײһ����(bell)���ԡ����⿴���и���
��ĺ�����̨(out)���������վһ���ˡ�
LONG
	);

	set("exits", ([
		"down" : __DIR__"zhonglou6",
	]));

	set("item_desc",([
		"bell"		:	(: look_bell :),
		"out"		:	(: look_out :),
	]));
	set("objects",([
		CLASS_D("shaolin") + "/qing-xiao" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_out", "out");
}

int do_knock(string arg)
{
	object me, killer;

	me = this_player();
	if ( !arg || ( arg != "bell" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");

	if((int)me->query("qi") < 20 || random((int)me->query_str()) < 15)
	{
		killer = new(CLASS_D("shaolin") + "/qing-xiao");
		COMBAT_D->killer_reward(killer, me);
		me->die();
		destruct(killer);
		return 1;
	}
	else
		me->add("kee", -10);

	if ( random((int)me->query("str")) < 18 )
	{
		message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
		//me->add("kee", -10 - me->query("kee"));
		me->unconcious();
	}

	else
	{
		mapping mine;

		mine = me->query_entire_dbase();
		message_vision("$N����һ�´��ӣ����ۡ�����������������������\n", me);
		write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
			"ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
			"���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");

		mine["combat_exp"] += 10;
	}
	return 1;
}

int do_out(string arg)
{
	object me, killer;
	int i, gin_cost, kee_cost;

	me = this_player();
	i = (int)me->query_skill("dodge", 0) + random(200);
	gin_cost = 600 / (int)me->query("int");
	kee_cost = 500 / (int)me->query("int");
	if(((int)me->query("gin") < gin_cost) || ((int)me->query("kee") < kee_cost))
		i = 0;

	message_vision("$N���ϴ�̨��һ��������������ȥ��\n", me);
	me->move(__DIR__"zhonglou");
	message_vision("ֻ�����须��һ��$N����������������\n", me);
	if ( i < 50)
	{
		killer = new(CLASS_D("shaolin") + "/qing-xiao");
		COMBAT_D->killer_reward(killer, me);
                me->die();
		destruct(killer);
	}
	else if( i < 125)
		me->unconcious();
	else {
		message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
		if( i > 175)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("gin", gin_cost );
		me->receive_damage("kee", kee_cost );
	}

	return 1;
}

string look_bell()
{
	return
	"����������������������������������������������\n"
	"����������������������������������������������\n"
	"������������������������Ի��������������������\n"
	"����������������������������������������������\n"
	"��������������һ����У�ײһ���ӡ�������������\n"
	"����������������������������������������������\n"
	"�����������������롡����죩������������\n"
	"����������������������������������������������\n"
	"����������������������������������������������\n";
}

string look_out()
{
	return  "��������¥����Ĵ�̨�����������ң����������ɽ����\n"
"�Լ��������Ƶ���ɽ�������̳��������۵ס���˵�ڴ˵�\n"
"������������ֱ�ӽ����������޴����洦��\n";
}