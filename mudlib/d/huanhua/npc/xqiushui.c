inherit NPC;
void create()
{
    set_name("萧秋水",({"xiao","xiaoqiushui"}));
        set("shen_type",1);
    set("gender","男性");
    set("attitude","friendly");
    set("combat_exp",15000);
    set("int",50);
    set("spi",40);
    set("per",40);
    set("kar",50);
    set("str",25);
    set("long","浣花剑派萧西楼的第三个儿子.
自小就聪敏过人，读书过目不忘，能诗善画.\n");
    set_skill("parry",100);
    set_skill("dodge",100);
    set_skill("unarmed",100);
    set_skill("sword",100);
    set_skill("force",100);
    set_skill("literate",100);
    setup();
add_money("silver",10);
carry_object("/d/obj/weapon/sword/changjian")->wield();
}
