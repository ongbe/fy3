// Room: /chengdu/qingshidadao3.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ�������ʯ���г����������͵���ݣ���
·����������������ż��ô�׳����������·��ʱ����Щ����
��ʿ����ȥȥ����ʱ����װ�кܶ����ӵĴ󳵾�������������
�����ǳɶ���
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"qingshidadao4",
                "east" : __DIR__"qingshidadao2",
	]));
        set("objects", ([
            __DIR__"npc/kid" : 2,
        ]));

	setup();
	replace_program(ROOM);
}
