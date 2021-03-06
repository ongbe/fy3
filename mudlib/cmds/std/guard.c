// guard.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dir;
        object ob, *guards;
        mixed old_target;
	int i;

        if( me->is_busy() )
                return notify_fail("你现在没有办法分心去做这类事！\n");

        old_target = me->query_temp("guarding");

        if( !arg || arg=="" ) {
                if( !old_target )
                        return notify_fail("指令格式：guard <生物>|<物品>|<方向>\n");
                if( objectp(old_target) )
                        if( living(old_target) )
                                write("你正在守护著" + old_target->name() + "。\n");
                        else
                                write("你正守在" + old_target->name() + "一旁，防止别人拿走。\n");
                else
                        write("你正守住 " + old_target + " 的方向，不准任何人离开。\n");
                return 1;
        }

        ob = present(arg, environment(me));

        if( ob ) {
                if( ob==me ) return notify_fail("守卫自己？不用说你也会做，对吧。\n");
                me->set_temp("guarding", ob);
        }
        else if( environment(me)->query("exits/" + arg) ) {
                if( environment(me)->query("no_fight") )
                        return notify_fail("这里不准战斗——也不准堵住别人去路！\n");
                me->set_temp("guarding", arg);
        }
        else if( arg!= "cancel" )
                return notify_fail("你要守卫谁，什麽，或是哪个方向？\n");

        if( objectp(old_target) ) {
                guards = old_target->query_temp("guarded");
                guards -= ({ me });
                old_target->set_temp("guarded", guards);
                if( living(old_target) )
                        tell_object( old_target, me->name() + "不再保护你了。\n");
        } else if( stringp(dir=old_target) ) {
                guards = environment(me)->query("guarded/" + dir);
                if( arrayp(guards) ) {
                        guards -= ({ me });
                        environment(me)->set("guarded/" + dir, guards);
                }
        }

        if( arg=="cancel" ) {
		  me->delete_temp("guarding");
                write("Ok.\n");
                return 1;
        }

        if( objectp(ob) ) {

//clean not exist objects

		guards=ob->query_temp("guarded");
		if(sizeof(guards))	{
		for(i=0;i<sizeof(guards);i++)
			if(! objectp(guards[i]))	guards[i]=0;
		guards-=({ 0 });
		ob->set_temp("guarded",guards);
		}
                ob->add_temp("guarded", ({ me }) );
                if( living(ob) )
                        message_vision("$N开始保护$n。\n", me, ob);
                else
                        message_vision("$N站到地上的$n一旁守著，以免别人取走。\n", me, ob);
        } else {

//clean not exist objects

		guards=environment(me)->query("guarded/"+arg);
		if(sizeof(guards))	{
		for(i=0;i<sizeof(guards);i++)
			if(! objectp(guards[i]))	guards[i]=0;
		guards-=({0});
		environment(me)->set("guarded/"+arg, guards);
		}

                environment(me)->add("guarded/" + arg, ({ me }));
                message_vision("$N开始守住往 " + arg + " 的方向不让任何人通行。\n", me);
        }

        return 1;
}

int help(object me)
{
        write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某个出口>|cancel]

这个指令有三种作用方式，分别如後：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由於只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙著其他事，别人就无法拿走这件东西。

guard <某个出口>  守住某个出口防止所有人从这个出口离开，可以用来阻拦善於逃跑
                  的敌人或拦路打劫做坏事。

guard cancel      取消先前的 guard 对象。
guard             不接任何参数会显示你目前 guard 的对象。

注意，通常除了 guard <某人> 的情形以外，只要你一移动，guard 的状态就会解除。
TEXT
        );
        return 1;
}
