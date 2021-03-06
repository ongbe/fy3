#include <ansi.h>
#define QUEST_SHA "/u/ljty/quest/questsong"
inherit NPC;
inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("驿站官员",({"guanyuan"}));
        set("long",
                "这是一个忙碌的驿站官员。\n"
        );

        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 30);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 450);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);
        set("combat_exp", 10000);
        set("score", 100);
        set("env/wimpy", 100);
        set("inquiry", ([
                "任务": "你帮我做事吧, 我会给你好处的! \n",
        ]) );

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}


int give_quest()
{
        mapping quest ;
        object me,letter;
        int j, combatexp, timep, factor, num;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

if(combatexp > 200000)
        {
                message_vision("官员对$N说：您已是武林高手了，这种小事您就不用做了。\n",me);
                return 0;
        }
 
// Let's see if this player still carries an un-expired task
        if(quest == me->query("quest"))
        {
                if( ((int)me->query("task_time")) >  time() )
                        return 0;
        }
                if (((int)time() - (int)me->query("last_task_time")) < 480)
                 {
                   message_vision("驿站官员对$N说：现在没有什么活要你干，等会再来吧。\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("驿站官员对$N说：我现在正好有活让你干。\n",me);
                }

        quest = QUEST_SHA->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);

        tell_object(me, "送信给『" + quest["quest"] + "』我就给你一些好处。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        letter = new("/u/ljty/obj/letter");
        letter->move(me);
        quest["quest_type"] = "送信给";
        quest["exp_bonus"] = random(50) + 100;
        quest["pot_bonus"] = random(20) + 30;
        quest["score"] = 0;

        me->set("quest", quest);
        me->set("task_time", (int)time() + timep);
        me->set("quest_factor", factor);
        me->set("last_task_time", time());
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";

        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "驿站官员说道：\n在" + time + "内");

                return 1;
}
