// wen's workroom

inherit ROOM;

void create()
{
	set("short","老六的测试室");
      set("long", @LONG
    只是个测试房间，其他巫师请不要随意update这儿，多谢啦。
LONG);
       set("no_fight",1);
	set("exits", ([ /* sizeof() == 3 */
		"out":"/d/wiz/meeting.c",
	]));
	set("objects",([
		"/d/suzhou/npc/cui":1,
	]));
      	setup();
	replace_program(ROOM);
}
