inherit NPC;
void create()
{
        set_name("小孩", ({ "kid" }));
        set("gender", "男性");
        set("age", 8);
        set("long", "邻街人家的小男孩\n");
        
        set("combat_exp", 50);
        set("random_move");
        set("attitude", "peaceful");
        set_temp("apply/defense", 5);
        setup();
}

