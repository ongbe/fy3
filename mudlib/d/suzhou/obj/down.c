// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>

inherit ITEM;
void create()
{
	seteuid("");
	set_name("嘿衣",({"cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("material","iron");
	}
	setup();
}
void init()
{
	add_action("do_kick","kick");
}
int do_kick(string str)
{
	object link_ob;
	object target,me;
	if(!str)	return notify_fail("玩家名。\n");
	target=find_player(str);
	if(!target)	return notify_fail("没有这个玩家。\n");
	link_ob=target->query_temp("link_ob");
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
				exec(link_ob,target);
                        link_ob->setup();
                        return 1;
                }
                link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(target));
//		link_ob->save();
		destruct(link_ob);
        }
//    CHANNEL_D->do_channel(this_object(), "rumor",target->name()+"被踢出游戏了！\n");
	target->command("quit");

        return 1;
}
