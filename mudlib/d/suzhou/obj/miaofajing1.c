// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("妙法莲华经",({"jing"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","一本破破烂烂的经书。封面上印着「第一卷」\n");
		set("value",5000);
		set("material", "paper");
		set("skill", ([
		"name" :"force",
		"exp_required":0,
			"sen_cost" :20,
		"difficulty" : 25,
		"max_skill" :50,
		]) );
	}
}
