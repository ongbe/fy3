
inherit ITEM;
void create()
{
	set_name("湿婆神像", ({"shenxiang", "shipo"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个三首六臂的神像,每个脑袋上都有三只眼睛.\n");
		set("unit", "个");
             set("no_get",1);
	}
setup();
}
