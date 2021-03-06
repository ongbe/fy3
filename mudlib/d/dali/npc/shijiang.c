#include <ansi.h>

inherit KZZNPC;
inherit F_VENDOR;
string query_save_file() { return DATA_DIR + "npc/赵老杆"; }
void create()
{
#include <kzznpc.h>

set("long", "他是一个打磨大理石的石匠，身上只穿了一件坎肩，全身布满了厚实的肌肉。\n");
set("chat_chance",2);
set("chat_msg", ({
"赵老杆有一下没一下的凿着手中的一块碑文，嘴里嘟囔着，“苍山之腹盛产奇石，
世称大理石，大理也因石而名扬天下。”\n",
"赵老杆放下手中铁锤，擦了擦额头的汗水。\n",
        }));
       set("area_name","大理石铺");
       set("area_file","/d/dali/stoneshop.c");
	set("ziyuan","矿石");
	set("jizhi",30);
	set("kaifa",30);

set("vendor_goods",([
"stone":__DIR__"obj/stone",
]));
        setup();
carry_object("/obj/std/weapon/tiezhang")->wield();
carry_object("/obj/cloth")->wear();
add_money("silver",2);
}
void init()
{
	::init();
  add_action("do_vendor_list","list");
  }

#include <die.h>