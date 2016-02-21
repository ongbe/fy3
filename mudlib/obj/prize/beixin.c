// black_vest.c beixin.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��˿����", ({ "beixin","black vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"�����˿���Ŀ�����������ز��������ۣ����ұ�һ����·�\n"
			"����Щ������ϸһ�����������Ϸǽ�ǲ���ȴ��֪��ʲ�ᶫ��\n"
			"֯�ɵġ�\n");
		set("unit", "��");
		set("value", 14000);
		set("material", "blacksilk");
		set("armor_prop/armor", 30);
		set("armor_prop/armor_vs_force", 70);
		set("armor_prop/attack", -5);
	}
	setup();
}

int query_autoload() { return 1; }