// Room: /d/huanggon/pianfang
inherit ROOM;

void create()
{
  set ("short", "偏房");
  set ("long", @LONG
宫中的一间偏房,无非是放些家具器皿,高高的门槛拦到小腿肚边,屋
中摆了张大桌子,几个人正赌得高兴,都是宫中的太监.
LONG);

  setup();
  replace_program(ROOM);
}
