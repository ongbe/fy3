// 

inherit ITEM;

void create()
{
	set_name("《徒手格斗下卷》",({"gedouxia","xia"}));
        set_weight(100);
        set("unit", "本");
        set("long",
		"一本记载格斗术的武学书籍。\n"
             );
	set("value",3000);
        set("skill", ([
	"name": "unarmed",
        "exp_required":10000,
        "max_skill":60,
        "sen_cost":30,
        ]) );
}
 
