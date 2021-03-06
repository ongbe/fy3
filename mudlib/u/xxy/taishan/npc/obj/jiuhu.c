// music  yangzhou's  酒壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒壶", ({"jiuhu", "bottle", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "上面写着：醉里乾坤短，壶中日月长。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "XO",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
