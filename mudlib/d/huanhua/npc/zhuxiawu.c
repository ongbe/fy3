inherit NPC;
void create()
{
    set_name("朱侠武",({"zhu xiawu","zhu"}));
        set("shen_type",1);
    set("gender","男性");
    set("age",43);
    set("str",30);
    set("title","铁衣铁脸铁罗网");
    set("per",26);
    set("combat_exp",120000);
    set("long","一代大侠,是朝庭公门公认的第一流罕见高手.\n");
    set_skill("parry",100);
    set_skill("dodge",100);
    set_skill("unarmed",100);
    set_skill("force",60);
    setup();
add_money("silver",15);
}
