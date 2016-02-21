// nuerxiang.c Ů����
// By Marz 04/02/96

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("Ů����",({"nuer xiang", "xiang", "tea"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ҷ����ü�����紦�ӡ�����ǲ��м�Ʒ��Ů���㡹��\n");
		set("unit", "��");
		set("value", 8000);
        set("remaining", 1);
        set("drink_supply", 25);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{

	int heal, recover, jing, e_jing, m_jing;
	
	if( !living(this_player()))	return 0;
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));

	m_jing=(int)this_player()->query("max_gin");
	heal = (int)this_player()->query_con();
	e_jing=(int)this_player()->query("eff_gin");
	
    if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_gin",m_jing);
		} else
		{	
			this_player()->add("eff_gin",heal);
		}	
	} 

	e_jing=(int)this_player()->query("eff_gin");
	jing=(int)this_player()->query("gin");
	recover = 30+heal;
    
	if (jing < e_jing )
	{
        if ( (jing + recover) >= e_jing )
        {
		this_player()->set("gin",e_jing);
        } else
        {   
		this_player()->add("gin",recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N������裬������ζ��Ʒ�˼��ڡ�\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
   		 message_vision("$N�����С����������ġ�Ů���㡹һ��������\n"+
      		"һ������ֱ����Ƣ��$N��ʱ���þ������\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}