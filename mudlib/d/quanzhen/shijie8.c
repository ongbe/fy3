// shijie8.c ʯ��


inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ���
��ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ���
�Կ���ȫ��������۵��ܽ��ˡ�
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"shijianyan",
		"southup" : __DIR__"shijie9",
	]));

set("outdoors","/d/quanzhen");
	set("objects",([
		__DIR__"npc/youke" : 1,
		__DIR__"npc/xiangke" : 1,
	]));

	setup();
	replace_program(ROOM);
}