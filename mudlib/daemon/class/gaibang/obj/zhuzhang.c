#include <weapon.h>

inherit STAFF;

void create()
{
set_name("竹棒", ({"zhu bang", "bang", "staff"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "根");
                set("value", 100);
set("material", "bamboo");
set("long","一根颜色泛黄的竹棒,看上去还挺结实.\n");
set("wield_msg","$N大喝一声:打尽天下赖皮狗。抽出一根$n.\n");
set("unwield_msg","$N哼一声，把$n插入腰间草绳。\n");
        }
        init_staff(15);
        setup();
}

