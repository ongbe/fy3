// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;

void create()
{
    set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("rank_info/self","谢某");
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("banghui","明教");
	set("bh_rank","金毛狮王");
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
        set("force_factor",80);

        set("combat_exp",400000);
      set("score",15000);

       set_skill("force",170);
      set_skill("sanyang-shengong",170);
	set_skill("dodge", 170);
	set_skill("tianlong-bu",170);
        set_skill("parry",170);
	set_skill("unarmed",170);
       set_skill("qishang-quan",200);
    	set_skill("literate", 100);

       map_skill("force","sanyang-shengong");
        map_skill("parry", "qishang-quan");
	map_skill("dodge","tianlong-bu");
	map_skill("unarmed","qishang-quan");


	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
	}) );
	setup();

    	carry_object("/d/mingjiao/obj/baipao")->wear();
}
int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<1000)
                return notify_fail(query("name")+"道：你还是多为本教做些实事吧。
\n");
        return 1;
}


