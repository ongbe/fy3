// Room: /d/wudang/road1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
�������ٵ�����ʯ�̳ɡ������������߿��Ե��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast":__DIR__"road2",
  "southwest":__DIR__"road5",
]));
set("outdoors","/d/wudang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}