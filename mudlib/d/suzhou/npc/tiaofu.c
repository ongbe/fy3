//music yangzhou' 挑夫

inherit NPC;

void create()
{
	set_name("挑夫",({"tiao fu","tiaofu","fu"}));
	set("gender", "男性" );
	set("age", 30);
	set("int", 28);
        set("combat_exp",800);
	set("long",
		"身强力壮的汉子。\n");

	set("mingwang",1);
	set("attitude", "peaceful");
	set_skill("literate", 0);
        set_skill("unarmed",10);
        set_skill("parry",20);
        set_skill("dodge",20);
	setup();
       carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/biandan")->wield();
	add_money("silver",1);
}

