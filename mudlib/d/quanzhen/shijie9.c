// shijie9.c ʯ��


inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ���
��ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ���
�Կ���ȫ��������۵��ܽ��ˡ����������һ��С·��
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"shijie8",
		"south" : __DIR__"guanritai",
//		"westdown" : "/d/gumu/caodi2",
	]));

set("outdoors","/d/quanzhen");
	set("objects",([
		__DIR__"npc/daotong" : 2,
	]));

	setup();
	replace_program(ROOM);
}