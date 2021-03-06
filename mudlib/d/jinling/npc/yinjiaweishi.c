// music   yangzhou's 兵勇

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"银甲卫士"NOR, ({ "yinjia weishi", "bing", "wei" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                HIW"隶属银甲卫队，是城守的近卫军，负责城守的安全和督管全城。\n"NOR);
        set("mingwang", 1);
        set("combat_exp", 180000);
        set_skill("blade",120);
        set_skill("parry",120);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set("max_kee",1000);
        set("kee",1000);
        set("str", 30);
        set("cor", 25);
        set("con", 20);
        set("int", 20);
        set("attitude", "peaceful");
        setup();
        carry_object("/obj/armor/yinjia")->wear();
        carry_object("obj/weapon/changdao")->wield();
        add_money("silver",50);
}
