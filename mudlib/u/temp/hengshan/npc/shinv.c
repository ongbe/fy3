//make by temp

//shinv.c

inherit NPC;
string ask_me();
void create()
{
set_name("阿兰",({"a lan","lan"}) );
set("title","恒山派俗家弟子");
set("gender", "女性");
set("age", 15);
set("shen_type",1);
set("attitude", "peaceful");
set("str", 25);
set("int", 25);
set("con", 30);
set("dex", 30);
set("qi", 800);
set("max_qi", 800);
set("jing", 500);
set("max_jing", 500);
set("neili", 1000);
set("max_neili", 1000);
set("jiali", 20);
set("combat_exp", 100000);
set("score", 10000);
set_skill("force", 100);
set_skill("unarmed", 100);
set_skill("dodge", 100);
set_skill("parry", 100);
set_skill("hand",100);
set_skill("strike", 100);
create_family("恒山派", 15, "弟子");
set("inquiry",([
            "进餐" : (: ask_me :),
            "食物" : (: ask_me :),
            "吃饭" : (: ask_me :),
]) );
setup();
}
string ask_me()
{
 say("阿兰说道：食物在橱柜里，你自己拿吧。\n");
 message_vision("$N从橱柜里拿出一大堆的食物，放在桌上狼吞虎咽的吃了起来\n" , this_player());
 this_player()->set("food", this_player()->max_food_capacity());
 this_player()->set("water", this_player()->max_water_capacity());
 return "慢点吃呀，不要哽住了";

}