// music   yangzhou's ����

inherit NPC;

void create()
{
	set_name("�ٱ�", ({ "guan bing", "bing", "guanbing" }) );
	set("gender", "����" );
	set("age", 20);
	set("long",
		"��Ӫ��ľ�ʿ��\n");
	set("mingwang", 1);
	set("combat_exp", 80000);
        set("str", 30);
        set("cps", 20);
        set("con", 20);
        set("int", 20);
        set_skill("dodge",60);
        set_skill("unarmed",50);
	set_skill("parry",80);
	set_skill("blade",70);
	set("attitude", "peaceful");
	setup();
        carry_object("/obj/armor/tiejia")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
	add_money("silver", 20);
}

