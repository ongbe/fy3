inherit NPC;

void create()
{
   set_name("午马", ({ "horse"}) );
   set("race", "野兽");
   set("age", 12);
   set("long", "一匹强健的骏马,不时发出两声长嘶。\n");
   
   set("str", 23);
   set("cor", 24);
   set("combat_exp",45000);
   set("kee",700);
   set("max_kee",700);

   set("limbs", ({ "头部", "身体", "尾巴", "前蹄","后蹄"}) );
   set("verbs", ({ "bite","claw"}) );

   set_temp("apply/attack", 15);
   set_temp("apply/armor", 20);

   set("chat_chance",5);
   set("chat_msg",({
   "骏马不住长嘶,髯毛飞扬,神骏无比.\n",
   "骏马不安地用蹄刨着地面.\n",
   }));
   setup();
}
void die()
{
  message_vision("$N对着你长嘶一声,倒地死了.\n",this_object());
  new(__DIR__"obj/matilian")->move(environment(this_object()));
  destruct(this_object());
  return;
}