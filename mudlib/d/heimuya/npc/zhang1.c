// zhang1.c
#include <ansi.h>
inherit NPC;

int shang_ya();
void create()
{
    set_name("张乘风", ({"zhang chengfeng", "zhang", "chengfeng"}));
    set("nickname", HIY "金猴神魔" NOR );
    set("banghui", "日月教");
	set("bh_rank","长老");
    set("gender", "男性");
    set("age", 42);
    set("shen_type", -1);
    set("long",
        "他是日月神教长老。\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("kee", 3000);
    set("max_kee", 3000);
    set("gin", 1000);
    set("max_gin", 1000);
    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 300);

    set("combat_exp", 1500000);
    set("score", 0);
    set("inquiry", ([
        "黑木崖" : "本教弟子或持教主令牌方能上崖！\n",
        "日月神教" : "本教弟子或持教主令牌方能上崖！\n",
        "日月教" : "本教弟子或持教主令牌方能上崖！\n",
        "黑木令" : "那是本教教主令牌，见牌如见教主亲临！\n",
        "上崖" :   (: shang_ya :),
    ]) );

	set_skill("force",180);
	set_skill("hunyuan-yiqi",180);
	set_skill("unarmed",180);
	set_skill("dodge",180);
	set_skill("shaolin-shenfa",180);
	set_skill("parry",180);
	set_skill("club",200);
	set_skill("weituo-gun",200);
	set_skill("houquan",200);

	map_skill("force","hunyuan-yiqi");
    map_skill("club", "weituo-gun");
    map_skill("parry", "weituo-gun");
	map_skill("dodge","shaolin-shenfa");
	map_skill("unarmed","houquan");

    setup();
    carry_object(__DIR__"obj/shutonggun")->wield();
carry_object("/obj/cloth")->wear();
}

int shang_ya()
{
    object ob, myenv ;
    ob = this_player ( ) ;
    if (ob->query("banghui") == "日月教")
    {
        message_vision("张乘风一招手，崖上落下一个大吊篮。\n",ob);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", ob);
        myenv = environment (ob) ;
        ob->move ("/d/heimuya/basket");
	call_out("goto_heimuya", 10, ob) ;
       	return 1;
    }
    else  
    message_vision("张乘风上上下下打量了$N一下：什么！上崖？你的黑木令呢？！\n",ob);
    return 1;
}

int accept_object(object who, object ob)
{
    object myenv ;
    if (ob->query("id") == "heimu ling")
    {
        message_vision("张乘风对$N说：好！这位" + RANK_D->query_respect(who) + "不错，那就请吧！\n" , who);
        message_vision("张乘风一招手，崖上落下一个大吊篮。\n", who);
        message_vision("$N一弯腰进了吊篮，吊篮缓缓地铰上崖去......\n", who);
        myenv = environment (who) ;
        who->move ("/d/heimuya/basket");
	call_out("goto_heimuya",10,who) ;
       	return 1;
    }
    else  
    {
	message_vision("张乘风对$N说：你敢耍我？！\n", who);
        this_object()->kill_ob(who);
    }
    return 0;
}

void goto_heimuya (object ob)
{
    tell_object(ob , "你眼前一亮，一幢幢白色建筑屹立眼前，霎是辉煌。\n");
    ob->move ("/d/heimuya/chengdedian") ;
}
int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<1000)
        return notify_fail(query("name")+"道：你还是多为本教做些实事吧。\n");
        return 1;
}
