// wizlist.c
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int level(mixed, mixed);
string wiz_rank(string hood);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 0;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
        str = MUD_NAME +"巫师组成员：\n";
        str += "———————————————————\n";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood!= wiz_rank(wizhood(list[i]))) {
                        hood = wiz_rank(wizhood(list[i]));
                        if (j%7) str += "\n";
                        str += hood;
                        str = replace_string(str,"(",HIG);
                        str = replace_string(str,")",": "NOR);
                        j = 0;
                }
                str += sprintf(" %s%s", list[i],
                        ( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
        str += "\n———————————————————\n";
        str += sprintf("目前一共有: %d个巫师\n",sizeof(list) );
        me->start_more(str);
        return 1;
}
string wiz_rank(string hood)
{       switch(hood) {
                case "(admin)":                 
                        return HIW "【 天  神 】" NOR;
                 case "(sage)":                  
                        return HIR "【 圣  者 】" NOR;
                case "(arch)":                  
                        return HIY "【 大巫师 】" NOR;
                case "(wizard)":                
                        return HIG "【 巫  师 】" NOR;
                case "(apprentice)":                
                          return HIC "【巫师学徒】" NOR;
                case "(immortal)":              
                          return HIB "【 精  灵 】" NOR;
        }
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}
int help(object me)
{
        write("\n指令格式 : wizlist\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}
