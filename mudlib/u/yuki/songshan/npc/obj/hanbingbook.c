inherit ITEM;

void create()
{
        set_name("《寒冰真气》",({"hanbingbook","hanbing"}));
        set_weight(100);
        set("unit", "本");
        set("long",
         "一本记载着有关嵩山寒冰真气心法修炼要诀的武功秘芨。\n"
             );
        set("value",3000);
        set("skill", ([
        "name":"hanbing",
        "exp_required":10000,
        "max_skill":60,
        "sen_cost":30,
        ]) );
}

