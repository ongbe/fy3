// woodcutter.c

inherit NPC;

void create()
{
        set_name("小弟子",({"xiao dizi","dizi"}));
        set("gender", "男性" );
        set("age",14);
        set("long","可爱的小男孩。\n");
        set("combat_exp",10000);
        set_skill("unarmed",20);
        set_skill("parry",20);
        set_skill("dodge",20);
        set("max_force",50);
        set("force",50);
        set_temp("apply/parry",30);
        set_temp("apply/dodge",30);
        set_temp("apply/attack",20);
        set_temp("apply/defense",30);
        set_temp("apply/damage",15);
        set_temp("apply/armor",20);
        setup();
        carry_object(__DIR__"obj/qcloth")->wear();
        add_money("coin",50);
}
