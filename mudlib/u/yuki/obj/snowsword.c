#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"紫雪无痕"NOR,({ "snowsword","sword"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",        HIW"这是一把两指宽由寒冰做成的短剑。\n"NOR);
                set("value",500000);
                set("material", "steel");                              
        }
         init_sword(150);

        set("wield_msg", HIW"只听“铮”的一声，一道耀眼的白光闪过，$N的手中多了把冰菱做的宝剑。\n"NOR);
        set("unwield_msg", HIW"白光咋敛,$N手中的冰雪无痕已经收入腰间的剑鞘内。\n"NOR);


        setup();
}

mixed weapon_action(object me,object victim)
{
        object ob,target_weapon;
        string msg;
        target_weapon=victim->query_temp("weapon");
        if(! target_weapon)     return 0;
        if( target_weapon->query("oldsix/qjdy"))        {
                msg=HIW"“铛”的一声，"+this_object()->query("name")+MAG"与"+
                target_weapon->query("name")+HIW"相交，冒出点点火星！\n"NOR;
                return msg;
        }
        msg=MAG"只见白光一闪，"+victim->query("name")+HIW"手中的"+target_weapon->query("name")+HIW"被"+this_object()->query("name")+HIW"打成无数冰晶，激飞开去。！\n"NOR;
                        
                        destruct(this_object());
                        return msg;

}

