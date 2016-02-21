inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("谢琳", ({ "xie lin","girl", "dizi" }));
	set("age", 16);
	set("gender", "女性");
	set("attitude", "peaceful");
       set("title","雁荡小师妹");
	set("str", 34);
	set("dex", 36);
	set("combat_exp", 10000);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("luoyan-jianfa", 60);
	set_skill("yuxuan-guizhen", 60);
	set_skill("tianfeng-xuan", 60);
	set_skill("tiangang-zhi", 60);
        set("shen_type",1);
	map_skill("force", "yuxuan-guizhen");
       map_skill("dodge","tianfeng-xuan");
      map_skill("sword","luoyan-jianfa");
       map_skill("parry","tiangang-zhi");
       map_skill("unarmed","tiangang-zhi");

   create_family("雁荡派",3,"弟子");
	set("inquiry", ([
		"花" : "是三师兄送来的,我......",
		"flower" : "是三师兄送来的,我......",
		]) );	
	setup();
	carry_object("obj/weapon/sword")->wield();
	carry_object("obj/cloth")->wear();
	add_money("silver",5);
	carry_object(__DIR__"obj/hongmeigui");
}
void attempt_apprentice(object ob)
 {  if (ob->query("gender")=="女性")   {
 	 command("say " + RANK_D->query_respect(ob) + 
 "，你既然诚心加入我雁荡一派,我就收你作个弟子吧！。\n");
        command("recruit " + ob->query("id") );
        return;
 }	
 else command("say 我可不像他们几个,你是男的耶.\n");
 return;
}
