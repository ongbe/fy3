#include <ansi.h>

inherit NPC;
void create()
{       
        set_name("高进昌",({"gao jinchang","gao"}));
        set("title",HIC"竟陵城守"NOR);
        set("gender","男性");
        set("age",40);
        set("long",
                HIC"看上去长的很威武，不愧是一城之长。\n"NOR);
        set("combat_exp",500000);
        set_temp("apply/attack",15);
        set_temp("apply/defense",15);
        set_skill("unarmed",150);
        set_skill("blade",150);
        set("max_kee",2000);
        set("kee",2000);
        set("mingwang",3);
        set_skill("dodge",150);
        set_skill("parry",150);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/yinjia")->wear();
        carry_object("/obj/weapon/changdao")->wield();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        if(ob->query("age")<16) {
                message_vision(HIC"高进昌对着$N大喝道：这里可不是"+
                RANK_D->query_respect(ob)+"来的地方。\n"NOR,ob);
                return ;
        }
        switch( random(2) ) {
                case 0:
                message_vision(HIC"城守和颜悦色地对$N道：这位"+
                RANK_D->query_respect(ob)+"有什么冤情要申诉啊！\n"NOR,ob);
                        break;
                case 1:
                message_vision(HIC"升堂......\n"NOR,ob);
                        break;
                           }
}
int accept_fight(object who)
{
        int i;
        object npc,env,*inv;
        npc=new(__DIR__"yinjiaweishi");
        env=environment(this_object());
        message_vision("城守对$N怒喝一声：你竟然改杀官造反？\n"+
        HIR"近卫何在！！给我把这刁民拿下。\n"NOR
        "顿时，两旁的银甲卫士都拔刀冲向$N。\n",who);
        if(sizeof(children(base_name(npc)))<=4)
                npc->move(env);
        else    destruct(npc);
        this_object()->kill_ob(who);
        inv=all_inventory(env);
        for(i=0;i<sizeof(inv);i++)      {
		if (inv[i]->query("id")!="yinjia weishi")      continue;
                inv[i]->kill_ob(who);
        }
        return 1;
}
