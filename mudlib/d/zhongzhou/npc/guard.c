

inherit NPC;

void create()
{
        set_name("门卫",({"guard man","man","guard"}));
        set("gender", "男性" );
        set("age", 20);
        set("long",
                "俊秀的小伙子，整天一脸严肃的，僵直的战立着。\n");
        set("combat_exp",2000000);
        set_temp("apply/defense",10);
        set_temp("apply/attack",5);
        set("attitude", "friendly");
        set("rank_info/respect", "门卫");

        set_skill("force", 250);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        
        setup();
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
        switch( random(2) ) {
                case 0:
                        message_vision("门卫打量了$N一会，冷冷的道：这位"+
                        RANK_D->query_respect(ob)+"，可能不是本地人吧？\n",ob);
                        break;
                case 1:
                        say( "门卫将目光盯着你，说道：这位" + RANK_D->query_respect(ob)
                                + "，想比武吗。\n");
                        break;
                           }
}

int accept_object(object who, object ob)
{
        
         if (ob->query("money_id") && ob->value() >= 20000) 
        {
                tell_object(who, "门卫一哈腰，露出难得的笑容说道：多谢您老，请。\n");

                 who->set_temp("war_money",1);


                return 1;
        }

        return 0;
}
