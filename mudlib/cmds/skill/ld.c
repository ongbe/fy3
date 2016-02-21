// abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	int many;

	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢，没法使用炼丹术。\n");
//add ld busy lxh 0-2-13 4:20		
//         if ((time()-me->query("last_ld"))<90)
//                return notify_fail("休息一会再炼？当心累死!\n");
	if( me->is_ghost())
		return notify_fail("死人用不了道法！\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("这儿风水不好，无法施展炼丹术。\n");
	if((int)me->query_skill("daoxuexinde",1)<100)
		return notify_fail("你的道学心德不够，不会使用炼丹术。\n");
	if(! arg)	return notify_fail("你要使用多少道行进行炼丹？\n");
	if(sscanf(arg,"%d",many)!=1)
			return notify_fail("你要使用多少道行进行炼丹？\n");
	if(many<50)	return notify_fail("施展炼丹术至少要50点道行。\n");

	if((int)me->query("atman")<many)
		return notify_fail("你的道行不够，无法施展炼丹术。\n");
	message_vision(HIY"$N口中念念有词，突然间左手凌空一指！\n"NOR,me);
	me->add("atman",-many);
	if(random((int)me->query_spi())>10)	{
		//add bust time lxh 0-2-13 4:19
//                 me->set("last_ld",time());
		ob=new("/obj/medicine/jiuhuandan");
		ob->create(many);
		message_vision(HIY"只见$N左手上方白光一闪，掉下一粒"
		+ob->query("name")+HIY"！\n"NOR,me);
		if(! ob->move(me))	{
			destruct(ob);
			return notify_fail(HIY"可惜你身上无法装下这颗丹药！\n"NOR);
		}
		write(HIY"你一伸手，将这颗"+ob->query("name")+HIY"放入怀中。\n"NOR);
		return 1;
	}
	else	return notify_fail(HIY"你忽然感到脑中一阵昏阙，什么也没炼成。\n"NOR);
}

int help()
{
	write(@TEXT

指令格式：ld <道行点数>
道学心德学习到一百级，你便可以学得此项道法。
炼制的丹药药力，与你使用的道行有关系。
不过并非每次都可以成功炼得丹药，还与你的灵
性有一定关系。

TEXT
	);
	return 1;
}
