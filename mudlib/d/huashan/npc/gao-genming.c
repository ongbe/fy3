// gao-genming.c

inherit NPC;
void create()
{
        set_name("�߸���", ({ "gao genming","gao","genming" }) );
        set("nickname", "�о�����");
        set("gender", "����");
        set("age", 24);
        set("long",
                "�߸���������Ⱥ�ĵ���λ���ӡ�\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("force", 300);
        set("max_force", 300);

        set("combat_exp", 30000);
        set("score", 20000);
        set("shen_type", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("literate", 30);

        set_skill("huashan-jianfa", 50);
	 set_skill("huashan-quanfa",50);
        set_skill("zixia-shengong", 50);
        set_skill("feiyan-huixiang", 50);

        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-quanfa");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 14, "����");
        setup();

	carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/cloth")->wear();
}