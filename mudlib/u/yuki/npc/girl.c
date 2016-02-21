inherit NPC;
#include <ansi.h>;
void greeting(object);
void init();
string inquiry_a();

void create()
{
        set_name("神秘少女", ( { "girl", "little girl" }) );
        set("title", "白衣仙子");
        set("gender", "女性" );
        set("age", 16);
        set("long",
   "她是一位神医的女儿，清丽俏脸，双眼犹如电漆，顾盼间使人
消魂。她脸色洁白透明，肌肤吹弹得破。她不施脂粉，但是反倒让
她更显伶俐动人，姿态之美，比之绝世无双的西施也不逊色分毫。
\n"
             );
        set("attitude", "friendly");

        set("per", 30);
        set("max_kee", 200);
        set("max_gin", 200);
        set("force", 2000);
        set("max_force", 2000);

        set("combat_exp", 6000000);
        set("score", 1000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);

        set("inquiry", ([
            "" : "\n",
            "" : "\n",
            "" : (: inquiry_a :),
        ]));

        setup();
        carry_object("/u/yuki/obj/feather")->wear();
}

void init()
{
        object ob;
        ::init();

        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       add_action("do_kiss","kiss");    
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        if(random(2)==1)
            {say("神秘少女嫣然一笑，眼波流动：" + RANK_D->query_respect(ob)
                + "是怎么进来的？这里好久没有人来过了。\n");
             return;
            }
          else
          {say("神秘少女轻轻的抚摩身边的小猫：" + RANK_D->query_respect(ob)
                + "能帮我找些东西么？我好久没有出去过了。 \n");
             return;
            }
}

string inquiry_a()
{
object me;
me = this_player();
  say("这位" + RANK_D->query_respect(me)+
    "不瞒您说。师傅让我作『蛇胆膏』，\n可我",me);
  return "不知哪位好心人能帮帮我呢？\n";
}

int accept_object(object who, object ob)
{
        object obn;
        object me;
        me = this_player();     
        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

        if (  (string)ob->query("name") != "冰玉指环")
                    return notify_fail("不需要这件东西。\n");
        if ( (string)ob->query("name") == "冰玉指环" )
        {
                me->set_temp("mark/huan",1);
                  message_vision("神秘少女脸上露出一个甜蜜的微笑，轻轻的在$N面颊上印下一个吻。!\n",me);
        }
        return 1;               
}
int do_kiss(string arg)
{
        object me,ob;
        me = this_player();
        if (arg != "girl" && arg != "神秘少女")
                return notify_fail("乱亲什么？？\n");
        if (!me->query_temp("mark/huan"))
                return notify_fail("神秘少女朝地上淬了一口浓痰!\n");    
          message_vision("$N毛手毛脚的在神秘少女的脸上吻了一下，神秘少女的脸立刻羞得通红。\n",me);
        message_vision("谢谢你帮我找回指环，这把宝剑是小女子的心意，江湖多风浪，$N多保重!\n",me);
        ob=new("/u/yuki/obj/snowsword");
        ob->move(me);
        return 1;
}


