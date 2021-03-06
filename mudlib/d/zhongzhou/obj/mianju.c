// mianju.c 人皮面具 
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"人皮面具"NOR, ({ "renpi mianju", "mianju" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", GRN"唱戏用的人皮面具。可以用来装扮(zhuangban)。\n");
	    set("value",50000);
  
        }
        setup();
}

void init()
{
        add_action("do_zhuang", "zhuangban");
}

int do_zhuang(string arg)
{
    object me,ob,who,*all;
        int i;

    me=this_player();
    seteuid(geteuid(me));

        all = users();

        if (!arg)
                return notify_fail("你想假装谁？\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
                this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                message_vision("$N从脸上取下了一张人皮面具。\n", this_player());
                return 1;
        }

        for(i=0; i<sizeof(all); i++)
        {
                if( arg == all[i]->query("name",1) || arg == geteuid(all[i]) )
                        ob = all[i];
        }

        if( !ob )
                return notify_fail("你要装扮的人现在不在游戏中！\n");

        if (ob->is_ghost())
                return notify_fail("你要扮死人？太过份了吧？\n");

        if(objectp(who = present(arg, environment(this_player()))) )
                return notify_fail("当着装扮对象的面扮人家？？太过分了耶！\n");
        write("你开始装扮" + ob->name() + "。\n");
        message_vision("$N戴上了一张精制的人皮面具。\n", this_player());
        this_player()->set_temp("apply/name", ({ob->name()}));
        this_player()->set_temp("apply/id", ({ob->id()}));
        this_player()->set_temp("apply/short", ({ob->short()}));
        this_player()->set_temp("apply/long", ({ob->long()}));
        return 1;
}

