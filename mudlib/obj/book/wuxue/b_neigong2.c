// 

inherit ITEM;

void create()
{
	set_name("《内功心法中卷》",({"neigongzhong","zhong"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	"一本记载着呼吸吐纳运气法门的武学书籍。\n"
             );
	set("value",2000);
        set("skill", ([
	"name":"force",
        "exp_required":5000,
        "max_skill":40,
        "sen_cost":20,
        ]) );
}
 
