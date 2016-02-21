#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("扁诸神剑", ({"sword","jian"}));
   set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","剑身扁长而细，短而赤黑.。\n");
                set("unit", "把");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N从旱烟杆中慢慢抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回手中的旱烟杆。\n");
        }
        init_sword(40);
        setup();
}

