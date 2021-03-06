// zhangyuan.c 掌园道长


inherit NPC;

void create()
{
	set_name("掌园道长", ({"zhangyuan"}));
	set("gender", "男性");
	set("age", 52);
	set("long",
		"他本是服侍重阳祖师的童子，现在年纪大了。重阳祖师见他忠\n"
		"心耿耿，就分配他一个闲差，到小花园来打理花木。\n"
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
	set("force", 900);
	set("max_force", 900);
	set("force_factor", 0);
	
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
	set_skill("literate",40);
	set_skill("daoxuexinde",30);

	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("unarmed", "haotian-zhang");

	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
        set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

	setup();
	
        carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/grayrobe")->wear();

}
