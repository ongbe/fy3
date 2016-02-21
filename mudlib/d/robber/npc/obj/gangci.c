
#include <weapon.h>

inherit SWORD;

void create()
{
   set_name("峨嵋钢刺", ({ "gang ci"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("value", 700);
     set("material", "steel");
     set("long", "用纯钢打造而成,刚中有柔,柔中有刚,是极犀利的兵器。\n");
     set("wield_msg", "$N舞起手中的$n,形成一个亮闪闪的光环。\n");
     set("unequip_msg", "$N手中的$n转了几转,不见了。\n");
   }
   init_sword(16);
   setup();
}
