// 

inherit ITEM;

void create()
{
	set_name("《轻功图解上卷》",({"qinggongshang","shang"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	"一本记载躲闪纵跃的武学书籍。\n"
             );
	set("value",1000);
        set("skill", ([
	"name":"dodge",
        "exp_required":100,
        "max_skill":20,
        "sen_cost":10,
        ]) );
}
 
