//xian.c 

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
        if( ((int)me->query("force") < 600 ) || ( (int)me->query_skill("jiuyin-shengong") < 20) )
                return notify_fail("你鼓足真气\"喵\"的吼了一声, 结果吓走了几只老鼠。\n");


        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

        me->start_busy(1);
        message_vision(
                BLU "$N深深地吸一囗气，纵声长啸,真气直冲云霄!!!\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
                
                damage = skill * 3 - ((int)ob[i]->query("max_neili") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("gin", damage * 2 );
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("gin", damage);
                        tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样。\n");
                }
                if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
        }

        return 1;
}
