// yapu2.c
// 97.7.13 by Aug

#include "thd.h"
inherit NPC;

int go_in();

void create()
{
	set_name("��·����", ({ "yapu" }) );
//	set("title", "����½��ׯ�Ҷ�");
	set("gender", "����");
	set("age", 43);
//	set_race("human");
//	set_level(28);
	set("class","taohua");

	set("long","���Ǹ���˳�����͡�\n");
	set("rank_info", "����");
	
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);

	set("max_atman", 600);
	set("atman", 600);
	set("max_force", 600);
	set("force", 600);
	set("max_mana", 600);
	set("mana", 600);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 20);
	set("per", 30);

	set("combat_exp", 50000);
	set("score",10000);

      set_skill("unarmed",100);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	
//	gain_score("mortal sin", -600);

	setup();
	add_money("silver", 1);
	carry_object("/obj/cloth")->wear();
}

int accept_fight(object who)
{
	message_vision("����˫�ֱȻ���ʲô������$N��û������\n",this_player());

	return 0;
}

int accept_kill(object who)
{
	message_vision("����˫�ֱȻ���ʲô����¶���࣬����Ҫɱ$N��\n",this_player());

}

void init()
{
	add_action("do_ask", "ask");
}

int do_ask(string arg)
{
	object me;

	me=this_player();	
	
      if((arg!="yapu about out")&&(arg!="yapu about ��ȥ"))
	{
		message_vision("��������¶����ã����ɫ��˫�ֱȻ���ʲô����Ȼ��֪��$N��˵ʲô��\n",me);		
		return 1;
	}


      write(
"
�������������ͷ���Ȼ���һ�£�ת��������ȥ������æ������ȥ��

����������߰����߰�����֪�߹��˶���·��ת�˶����䡣

���ڣ�����ͣ��������˫����ǰһָ�����������ˡ�

\n");

    me->move(NOWDIR+"wroad"); 

    return 1;
}

