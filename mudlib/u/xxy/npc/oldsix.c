inherit NPC;
inherit F_VENDOR;

int give_dust();
int HAVE_DUST=1;

void create()
{
	set_name("老六", ({ "oldsix","laoliu" }) );
    set("title","太古的男秘书");
	set("gender", "男性" );
	set("age", 27);
	set("long",
		"老六是玩mud的高手,太古高薪聘请来的.\n");
	set("chat_chance", 5);
	set("chat_msg", ({
		"老六自得的说：别看咱不如你威风，可是咱薪水不少啊。\n",
		"老六悄声道：没事最好少来这,太古的脾气有点古怪。\n",
		"老六贼沓兮兮道：听说太古马上要给我加薪拉。\n",
		"老六道：你要是敢欺负我,你可小心了！\n",
	}));
	set("shen_type", 1);
	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ([
                     "人参":     "/d/yangzhou/npc/obj/renshen",
                     "鸡腿":     "/d/yangzhou/npc/obj/jitui",
                     "酒壶":     "/d/yangzhou/npc/obj/jiuhu",
	]) );
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 5);


        create_family("南海剑派", 6, "弟子");

        set("combat_exp", 5000);
        set("score", 5000);

		set_skill("force", 32);
		set_skill("parry", 32);
		set_skill("dodge", 32);
		set_skill("sword", 32);

      	set_skill("suiyu-force",20);
      	set_skill("lanhua-finger",15);
      	set_skill("bagua-steps",25);
	
		map_skill("dodge",  "bagua-steps");
		map_skill("unarmed","lanhua-finger");
		map_skill("parry",  "lanhua-finger");
		map_skill("force",  "suiyu-force");

		set("inquiry", ([
			"name" : "我就是老六， 老六就是我，吃葡萄不吐葡萄皮。。",
			"老六" : "我就是老六， 老六就是我，吃葡萄不吐葡萄皮。。",
			"here" : "嘘,你到了太古的家还敢大声嚷嚷么?俺可不敢。。",
			"jiuhua" : (: give_dust :),
		]) );	
		
		setup();
        carry_object("/obj/cloth")->wear();
		add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("buy_object", "buy");
        add_action("do_vendor_list", "list");
}
int give_dust()
{
  object me,ob;

  me=this_player();
  if ( me->query("family/family_name")!="南海剑派" ){
    command("say 你别是搞错了吧？ 我哪有什么好东西。。\n");  
//	kill_ob(me);
	return 1;
	}
  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");

  if(HAVE_DUST==0)
    write("老六说：你来晚了，九花玉露丸已经给别人了。\n");  
  else  
  {
  clone_object("/u/wen/obj/jiuhua")->move(me);

    write("老六说道： 好吧，这颗九花玉露丸你拿去吧。\n");  
    message_vision("老六给$n一颗丸药，边挤眉弄眼的笑了笑。\n",this_object(),me);   
    
    HAVE_DUST=0;   
  }

  return 1;
}
