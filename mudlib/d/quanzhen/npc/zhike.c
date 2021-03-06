// zhike.c 知客道长


inherit NPC;

string ask_me();

void create()
{
	set_name("知客道长", ({"zhike daozhang","zhike"}));
	set("gender", "男性");
	set("age", 42);
	set("long",
		"他是全真教第四代弟子中年纪最大的一位，以前做过小买卖，\n"
		"走南闯北，见多识广，后来拜到全真门下。掌教见他岁数毕竟\n"
		"大了，不适宜再修练上乘功夫。且喜他能言善道，熟识礼节，\n"
		"就安排在山门处专事接待访客。\n"
);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);

	set("kee", 500);
	set("max_kee", 500);
	set("gin", 350);
	set("max_gin", 350);
	set("force", 600);
	set("max_force", 600);
	
	set("combat_exp", 20000);
	set("score", 15000);
	 
	set_skill("force", 40);
	set_skill("xiantian-qigong", 40);    //先天气功
	set_skill("sword", 40);             
	set_skill("quanzhen-jian",40);  //全真剑
	set_skill("dodge", 50);
	set_skill("jinyan-gong", 40);   //金雁功
	set_skill("parry", 50);
	set_skill("unarmed",50);
	set_skill("haotian-zhang", 50);    //昊天掌
	set_skill("literate",60);
	set_skill("daoxuexinde",50);

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("unarmed", "haotian-zhang");

	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
        set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"西毒" : (: ask_me :),
		"欧阳锋" : (: ask_me :),
        ]) );

	setup();
	
        carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/grayrobe")->wear();

}

string ask_me()
{
	object me=this_player();
	me->set_temp("tmark/指",1);
	return("去年祖师假死以诱西毒来抢夺九阴真经，结果西毒被祖师以一阳指破了修炼多年的蛤蟆功。\n");
}



