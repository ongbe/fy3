// mabudai.c 麻布袋

inherit ITEM;

void create()
{
	set_name("火摺子", ({ "huo zhezi", "huo", "fire" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "在某些暗处可以使用(use)的特殊物品。\n");
		set("value", 100);
	}
}

