/* generated from CODE 35 (gml_Object_obj_waterfill_Create_0), source start 3885420, end 3888952. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0035(GmVM* vm) {
    Val p3887192_0;
    Val p3887204_0;
    Val p3887220_0;
    Val p3887236_0;
    Val p3887252_0;
    Val p3887268_0;
    Val p3887284_0;
    Val p3887300_0;
    Val p3887316_0;
    Val p3887332_0;
    Val p3887348_0;
    Val p3887364_0;
    Val p3887380_0;
    Val p3887396_0;
    Val p3887412_0;
    Val p3887428_0;
    Val p3887444_0;
    Val p3887460_0;
    Val p3887476_0;
    Val p3887492_0;
    Val p3887508_0;
    Val p3887524_0;
    Val p3887540_0;
    Val p3887556_0;
    Val p3887572_0;
    Val p3887588_0;
    Val p3887604_0;
    Val p3887620_0;
    Val p3887636_0;
    Val p3887652_0;
    Val p3887668_0;
    Val p3887684_0;
    Val p3887700_0;
    Val p3887716_0;
    Val p3887732_0;
    Val p3887748_0;
    Val p3887764_0;
    Val p3887780_0;
    Val p3887796_0;
    Val p3887812_0;
    Val p3887828_0;
    Val p3887844_0;
    Val p3887860_0;
    Val p3887876_0;
    Val p3887892_0;
    Val p3887908_0;
    Val p3887924_0;
    Val p3887940_0;
    Val p3887956_0;
    Val p3887972_0;
    Val p3887988_0;
    Val p3888004_0;
    Val p3888020_0;
    Val p3888036_0;
    Val p3888052_0;
    Val p3888068_0;
    Val p3888084_0;
    Val p3888100_0;
    Val p3888116_0;
    Val p3888132_0;
    Val p3888148_0;
    Val p3888164_0;
    Val p3888180_0;
    Val p3888196_0;
    Val p3888212_0;
    Val p3888228_0;
    Val p3888244_0;
    Val p3888260_0;
    Val p3888276_0;
    Val p3888292_0;
    Val p3888308_0;
    Val p3888324_0;
    Val p3888340_0;
    Val p3888356_0;
    Val p3888372_0;
    Val p3888388_0;
    Val p3888404_0;
    Val p3888420_0;
    Val p3888436_0;
    Val p3888452_0;
    Val p3888468_0;
    Val p3888484_0;
    Val p3888500_0;
    Val p3888516_0;
    Val p3888532_0;
    Val p3888548_0;
    Val p3888564_0;
    Val p3888580_0;
    Val p3888596_0;
    Val p3888612_0;
    Val p3888628_0;
    Val p3888644_0;
    Val p3888660_0;
    Val p3888676_0;
    Val p3888692_0;
    Val p3888708_0;
    Val p3888724_0;
    Val p3888740_0;
    Val p3888756_0;
    Val p3888772_0;
    Val p3888788_0;
    Val p3888804_0;
    Val p3888820_0;
    Val p3888836_0;
    Val p3888852_0;
    Val p3888868_0;
    Val p3888884_0;
    Val p3888900_0;
    Val p3888916_0;
    Val p3888932_0;
    Val p3888948_0;
    /* @3885420 load */
    /* @3885428 dup */
    /* @3885432 constant */
    /* @3885436 cmp */
    /* @3885440 bt */
    p3887192_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(0)))) goto L_3887192;
    /* @3885444 dup */
    /* @3885448 constant */
    /* @3885452 cmp */
    /* @3885456 bt */
    p3887204_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_3887204;
    /* @3885460 dup */
    /* @3885464 constant */
    /* @3885468 cmp */
    /* @3885472 bt */
    p3887220_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_3887220;
    /* @3885476 dup */
    /* @3885480 constant */
    /* @3885484 cmp */
    /* @3885488 bt */
    p3887236_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_3887236;
    /* @3885492 dup */
    /* @3885496 constant */
    /* @3885500 cmp */
    /* @3885504 bt */
    p3887252_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_3887252;
    /* @3885508 dup */
    /* @3885512 constant */
    /* @3885516 cmp */
    /* @3885520 bt */
    p3887268_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_3887268;
    /* @3885524 dup */
    /* @3885528 constant */
    /* @3885532 cmp */
    /* @3885536 bt */
    p3887284_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_3887284;
    /* @3885540 dup */
    /* @3885544 constant */
    /* @3885548 cmp */
    /* @3885552 bt */
    p3887300_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_3887300;
    /* @3885556 dup */
    /* @3885560 constant */
    /* @3885564 cmp */
    /* @3885568 bt */
    p3887316_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_3887316;
    /* @3885572 dup */
    /* @3885576 constant */
    /* @3885580 cmp */
    /* @3885584 bt */
    p3887332_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_3887332;
    /* @3885588 dup */
    /* @3885592 constant */
    /* @3885596 cmp */
    /* @3885600 bt */
    p3887348_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3887348;
    /* @3885604 dup */
    /* @3885608 constant */
    /* @3885612 cmp */
    /* @3885616 bt */
    p3887364_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_3887364;
    /* @3885620 dup */
    /* @3885624 constant */
    /* @3885628 cmp */
    /* @3885632 bt */
    p3887380_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_3887380;
    /* @3885636 dup */
    /* @3885640 constant */
    /* @3885644 cmp */
    /* @3885648 bt */
    p3887396_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_3887396;
    /* @3885652 dup */
    /* @3885656 constant */
    /* @3885660 cmp */
    /* @3885664 bt */
    p3887412_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_3887412;
    /* @3885668 dup */
    /* @3885672 constant */
    /* @3885676 cmp */
    /* @3885680 bt */
    p3887428_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_3887428;
    /* @3885684 dup */
    /* @3885688 constant */
    /* @3885692 cmp */
    /* @3885696 bt */
    p3887444_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_3887444;
    /* @3885700 dup */
    /* @3885704 constant */
    /* @3885708 cmp */
    /* @3885712 bt */
    p3887460_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_3887460;
    /* @3885716 dup */
    /* @3885720 constant */
    /* @3885724 cmp */
    /* @3885728 bt */
    p3887476_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_3887476;
    /* @3885732 dup */
    /* @3885736 constant */
    /* @3885740 cmp */
    /* @3885744 bt */
    p3887492_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_3887492;
    /* @3885748 dup */
    /* @3885752 constant */
    /* @3885756 cmp */
    /* @3885760 bt */
    p3887508_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_3887508;
    /* @3885764 dup */
    /* @3885768 constant */
    /* @3885772 cmp */
    /* @3885776 bt */
    p3887524_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_3887524;
    /* @3885780 dup */
    /* @3885784 constant */
    /* @3885788 cmp */
    /* @3885792 bt */
    p3887540_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_3887540;
    /* @3885796 dup */
    /* @3885800 constant */
    /* @3885804 cmp */
    /* @3885808 bt */
    p3887556_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_3887556;
    /* @3885812 dup */
    /* @3885816 constant */
    /* @3885820 cmp */
    /* @3885824 bt */
    p3887572_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_3887572;
    /* @3885828 dup */
    /* @3885832 constant */
    /* @3885836 cmp */
    /* @3885840 bt */
    p3887588_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_3887588;
    /* @3885844 dup */
    /* @3885848 constant */
    /* @3885852 cmp */
    /* @3885856 bt */
    p3887604_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_3887604;
    /* @3885860 dup */
    /* @3885864 constant */
    /* @3885868 cmp */
    /* @3885872 bt */
    p3887620_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3887620;
    /* @3885876 dup */
    /* @3885880 constant */
    /* @3885884 cmp */
    /* @3885888 bt */
    p3887636_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_3887636;
    /* @3885892 dup */
    /* @3885896 constant */
    /* @3885900 cmp */
    /* @3885904 bt */
    p3887652_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_3887652;
    /* @3885908 dup */
    /* @3885912 constant */
    /* @3885916 cmp */
    /* @3885920 bt */
    p3887668_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_3887668;
    /* @3885924 dup */
    /* @3885928 constant */
    /* @3885932 cmp */
    /* @3885936 bt */
    p3887684_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_3887684;
    /* @3885940 dup */
    /* @3885944 constant */
    /* @3885948 cmp */
    /* @3885952 bt */
    p3887700_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_3887700;
    /* @3885956 dup */
    /* @3885960 constant */
    /* @3885964 cmp */
    /* @3885968 bt */
    p3887716_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_3887716;
    /* @3885972 dup */
    /* @3885976 constant */
    /* @3885980 cmp */
    /* @3885984 bt */
    p3887732_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_3887732;
    /* @3885988 dup */
    /* @3885992 constant */
    /* @3885996 cmp */
    /* @3886000 bt */
    p3887748_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_3887748;
    /* @3886004 dup */
    /* @3886008 constant */
    /* @3886012 cmp */
    /* @3886016 bt */
    p3887764_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_3887764;
    /* @3886020 dup */
    /* @3886024 constant */
    /* @3886028 cmp */
    /* @3886032 bt */
    p3887780_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_3887780;
    /* @3886036 dup */
    /* @3886040 constant */
    /* @3886044 cmp */
    /* @3886048 bt */
    p3887796_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_3887796;
    /* @3886052 dup */
    /* @3886056 constant */
    /* @3886060 cmp */
    /* @3886064 bt */
    p3887812_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_3887812;
    /* @3886068 dup */
    /* @3886072 constant */
    /* @3886076 cmp */
    /* @3886080 bt */
    p3887828_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_3887828;
    /* @3886084 dup */
    /* @3886088 constant */
    /* @3886092 cmp */
    /* @3886096 bt */
    p3887844_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_3887844;
    /* @3886100 dup */
    /* @3886104 constant */
    /* @3886108 cmp */
    /* @3886112 bt */
    p3887860_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_3887860;
    /* @3886116 dup */
    /* @3886120 constant */
    /* @3886124 cmp */
    /* @3886128 bt */
    p3887876_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_3887876;
    /* @3886132 dup */
    /* @3886136 constant */
    /* @3886140 cmp */
    /* @3886144 bt */
    p3887892_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_3887892;
    /* @3886148 dup */
    /* @3886152 constant */
    /* @3886156 cmp */
    /* @3886160 bt */
    p3887908_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_3887908;
    /* @3886164 dup */
    /* @3886168 constant */
    /* @3886172 cmp */
    /* @3886176 bt */
    p3887924_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_3887924;
    /* @3886180 dup */
    /* @3886184 constant */
    /* @3886188 cmp */
    /* @3886192 bt */
    p3887940_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_3887940;
    /* @3886196 dup */
    /* @3886200 constant */
    /* @3886204 cmp */
    /* @3886208 bt */
    p3887956_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3887956;
    /* @3886212 dup */
    /* @3886216 constant */
    /* @3886220 cmp */
    /* @3886224 bt */
    p3887972_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_3887972;
    /* @3886228 dup */
    /* @3886232 constant */
    /* @3886236 cmp */
    /* @3886240 bt */
    p3887988_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_3887988;
    /* @3886244 dup */
    /* @3886248 constant */
    /* @3886252 cmp */
    /* @3886256 bt */
    p3888004_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_3888004;
    /* @3886260 dup */
    /* @3886264 constant */
    /* @3886268 cmp */
    /* @3886272 bt */
    p3888020_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_3888020;
    /* @3886276 dup */
    /* @3886280 constant */
    /* @3886284 cmp */
    /* @3886288 bt */
    p3888036_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_3888036;
    /* @3886292 dup */
    /* @3886296 constant */
    /* @3886300 cmp */
    /* @3886304 bt */
    p3888052_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_3888052;
    /* @3886308 dup */
    /* @3886312 constant */
    /* @3886316 cmp */
    /* @3886320 bt */
    p3888068_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_3888068;
    /* @3886324 dup */
    /* @3886328 constant */
    /* @3886332 cmp */
    /* @3886336 bt */
    p3888084_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_3888084;
    /* @3886340 dup */
    /* @3886344 constant */
    /* @3886348 cmp */
    /* @3886352 bt */
    p3888100_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_3888100;
    /* @3886356 dup */
    /* @3886360 constant */
    /* @3886364 cmp */
    /* @3886368 bt */
    p3888116_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_3888116;
    /* @3886372 dup */
    /* @3886376 constant */
    /* @3886380 cmp */
    /* @3886384 bt */
    p3888132_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_3888132;
    /* @3886388 dup */
    /* @3886392 constant */
    /* @3886396 cmp */
    /* @3886400 bt */
    p3888148_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_3888148;
    /* @3886404 dup */
    /* @3886408 constant */
    /* @3886412 cmp */
    /* @3886416 bt */
    p3888164_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_3888164;
    /* @3886420 dup */
    /* @3886424 constant */
    /* @3886428 cmp */
    /* @3886432 bt */
    p3888180_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_3888180;
    /* @3886436 dup */
    /* @3886440 constant */
    /* @3886444 cmp */
    /* @3886448 bt */
    p3888196_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_3888196;
    /* @3886452 dup */
    /* @3886456 constant */
    /* @3886460 cmp */
    /* @3886464 bt */
    p3888212_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3888212;
    /* @3886468 dup */
    /* @3886472 constant */
    /* @3886476 cmp */
    /* @3886480 bt */
    p3888228_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_3888228;
    /* @3886484 dup */
    /* @3886488 constant */
    /* @3886492 cmp */
    /* @3886496 bt */
    p3888244_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_3888244;
    /* @3886500 dup */
    /* @3886504 constant */
    /* @3886508 cmp */
    /* @3886512 bt */
    p3888260_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_3888260;
    /* @3886516 dup */
    /* @3886520 constant */
    /* @3886524 cmp */
    /* @3886528 bt */
    p3888276_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_3888276;
    /* @3886532 dup */
    /* @3886536 constant */
    /* @3886540 cmp */
    /* @3886544 bt */
    p3888292_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_3888292;
    /* @3886548 dup */
    /* @3886552 constant */
    /* @3886556 cmp */
    /* @3886560 bt */
    p3888308_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_3888308;
    /* @3886564 dup */
    /* @3886568 constant */
    /* @3886572 cmp */
    /* @3886576 bt */
    p3888324_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_3888324;
    /* @3886580 dup */
    /* @3886584 constant */
    /* @3886588 cmp */
    /* @3886592 bt */
    p3888340_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_3888340;
    /* @3886596 dup */
    /* @3886600 constant */
    /* @3886604 cmp */
    /* @3886608 bt */
    p3888356_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_3888356;
    /* @3886612 dup */
    /* @3886616 constant */
    /* @3886620 cmp */
    /* @3886624 bt */
    p3888372_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_3888372;
    /* @3886628 dup */
    /* @3886632 constant */
    /* @3886636 cmp */
    /* @3886640 bt */
    p3888388_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_3888388;
    /* @3886644 dup */
    /* @3886648 constant */
    /* @3886652 cmp */
    /* @3886656 bt */
    p3888404_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_3888404;
    /* @3886660 dup */
    /* @3886664 constant */
    /* @3886668 cmp */
    /* @3886672 bt */
    p3888420_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_3888420;
    /* @3886676 dup */
    /* @3886680 constant */
    /* @3886684 cmp */
    /* @3886688 bt */
    p3888436_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_3888436;
    /* @3886692 dup */
    /* @3886696 constant */
    /* @3886700 cmp */
    /* @3886704 bt */
    p3888452_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_3888452;
    /* @3886708 dup */
    /* @3886712 constant */
    /* @3886716 cmp */
    /* @3886720 bt */
    p3888468_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_3888468;
    /* @3886724 dup */
    /* @3886728 constant */
    /* @3886732 cmp */
    /* @3886736 bt */
    p3888484_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_3888484;
    /* @3886740 dup */
    /* @3886744 constant */
    /* @3886748 cmp */
    /* @3886752 bt */
    p3888500_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3888500;
    /* @3886756 dup */
    /* @3886760 constant */
    /* @3886764 cmp */
    /* @3886768 bt */
    p3888516_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_3888516;
    /* @3886772 dup */
    /* @3886776 constant */
    /* @3886780 cmp */
    /* @3886784 bt */
    p3888532_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_3888532;
    /* @3886788 dup */
    /* @3886792 constant */
    /* @3886796 cmp */
    /* @3886800 bt */
    p3888548_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_3888548;
    /* @3886804 dup */
    /* @3886808 constant */
    /* @3886812 cmp */
    /* @3886816 bt */
    p3888564_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_3888564;
    /* @3886820 dup */
    /* @3886824 constant */
    /* @3886828 cmp */
    /* @3886832 bt */
    p3888580_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_3888580;
    /* @3886836 dup */
    /* @3886840 constant */
    /* @3886844 cmp */
    /* @3886848 bt */
    p3888596_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_3888596;
    /* @3886852 dup */
    /* @3886856 constant */
    /* @3886860 cmp */
    /* @3886864 bt */
    p3888612_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_3888612;
    /* @3886868 dup */
    /* @3886872 constant */
    /* @3886876 cmp */
    /* @3886880 bt */
    p3888628_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_3888628;
    /* @3886884 dup */
    /* @3886888 constant */
    /* @3886892 cmp */
    /* @3886896 bt */
    p3888644_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_3888644;
    /* @3886900 dup */
    /* @3886904 constant */
    /* @3886908 cmp */
    /* @3886912 bt */
    p3888660_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_3888660;
    /* @3886916 dup */
    /* @3886920 constant */
    /* @3886924 cmp */
    /* @3886928 bt */
    p3888676_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_3888676;
    /* @3886932 dup */
    /* @3886936 constant */
    /* @3886940 cmp */
    /* @3886944 bt */
    p3888692_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_3888692;
    /* @3886948 dup */
    /* @3886952 constant */
    /* @3886956 cmp */
    /* @3886960 bt */
    p3888708_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_3888708;
    /* @3886964 dup */
    /* @3886968 constant */
    /* @3886972 cmp */
    /* @3886976 bt */
    p3888724_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_3888724;
    /* @3886980 dup */
    /* @3886984 constant */
    /* @3886988 cmp */
    /* @3886992 bt */
    p3888740_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_3888740;
    /* @3886996 dup */
    /* @3887000 constant */
    /* @3887004 cmp */
    /* @3887008 bt */
    p3888756_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_3888756;
    /* @3887012 dup */
    /* @3887016 constant */
    /* @3887020 cmp */
    /* @3887024 bt */
    p3888772_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_3888772;
    /* @3887028 dup */
    /* @3887032 constant */
    /* @3887036 cmp */
    /* @3887040 bt */
    p3888788_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_3888788;
    /* @3887044 dup */
    /* @3887048 constant */
    /* @3887052 cmp */
    /* @3887056 bt */
    p3888804_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_3888804;
    /* @3887060 dup */
    /* @3887064 constant */
    /* @3887068 cmp */
    /* @3887072 bt */
    p3888820_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_3888820;
    /* @3887076 dup */
    /* @3887080 constant */
    /* @3887084 cmp */
    /* @3887088 bt */
    p3888836_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_3888836;
    /* @3887092 dup */
    /* @3887096 constant */
    /* @3887100 cmp */
    /* @3887104 bt */
    p3888852_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3888852;
    /* @3887108 dup */
    /* @3887112 constant */
    /* @3887116 cmp */
    /* @3887120 bt */
    p3888868_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(105)))) goto L_3888868;
    /* @3887124 dup */
    /* @3887128 constant */
    /* @3887132 cmp */
    /* @3887136 bt */
    p3888884_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(106)))) goto L_3888884;
    /* @3887140 dup */
    /* @3887144 constant */
    /* @3887148 cmp */
    /* @3887152 bt */
    p3888900_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(107)))) goto L_3888900;
    /* @3887156 dup */
    /* @3887160 constant */
    /* @3887164 cmp */
    /* @3887168 bt */
    p3888916_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(108)))) goto L_3888916;
    /* @3887172 dup */
    /* @3887176 constant */
    /* @3887180 cmp */
    /* @3887184 bt */
    p3888932_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(109)))) goto L_3888932;
    /* @3887188 b */
    p3888948_0 = GM_READ(vm, -1, "room");
    goto L_3888948;
    L_3887192: ;
    /* @3887192 constant */
    /* @3887196 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    p3887204_0 = p3887192_0;
    L_3887204: ;
    /* @3887204 constant */
    /* @3887208 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887216 b */
    p3888948_0 = p3887204_0;
    goto L_3888948;
    L_3887220: ;
    /* @3887220 constant */
    /* @3887224 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887232 b */
    p3888948_0 = p3887220_0;
    goto L_3888948;
    L_3887236: ;
    /* @3887236 constant */
    /* @3887240 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887248 b */
    p3888948_0 = p3887236_0;
    goto L_3888948;
    L_3887252: ;
    /* @3887252 constant */
    /* @3887256 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887264 b */
    p3888948_0 = p3887252_0;
    goto L_3888948;
    L_3887268: ;
    /* @3887268 constant */
    /* @3887272 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887280 b */
    p3888948_0 = p3887268_0;
    goto L_3888948;
    L_3887284: ;
    /* @3887284 constant */
    /* @3887288 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887296 b */
    p3888948_0 = p3887284_0;
    goto L_3888948;
    L_3887300: ;
    /* @3887300 constant */
    /* @3887304 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887312 b */
    p3888948_0 = p3887300_0;
    goto L_3888948;
    L_3887316: ;
    /* @3887316 constant */
    /* @3887320 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887328 b */
    p3888948_0 = p3887316_0;
    goto L_3888948;
    L_3887332: ;
    /* @3887332 constant */
    /* @3887336 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887344 b */
    p3888948_0 = p3887332_0;
    goto L_3888948;
    L_3887348: ;
    /* @3887348 constant */
    /* @3887352 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887360 b */
    p3888948_0 = p3887348_0;
    goto L_3888948;
    L_3887364: ;
    /* @3887364 constant */
    /* @3887368 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887376 b */
    p3888948_0 = p3887364_0;
    goto L_3888948;
    L_3887380: ;
    /* @3887380 constant */
    /* @3887384 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887392 b */
    p3888948_0 = p3887380_0;
    goto L_3888948;
    L_3887396: ;
    /* @3887396 constant */
    /* @3887400 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887408 b */
    p3888948_0 = p3887396_0;
    goto L_3888948;
    L_3887412: ;
    /* @3887412 constant */
    /* @3887416 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887424 b */
    p3888948_0 = p3887412_0;
    goto L_3888948;
    L_3887428: ;
    /* @3887428 constant */
    /* @3887432 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887440 b */
    p3888948_0 = p3887428_0;
    goto L_3888948;
    L_3887444: ;
    /* @3887444 constant */
    /* @3887448 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887456 b */
    p3888948_0 = p3887444_0;
    goto L_3888948;
    L_3887460: ;
    /* @3887460 constant */
    /* @3887464 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887472 b */
    p3888948_0 = p3887460_0;
    goto L_3888948;
    L_3887476: ;
    /* @3887476 constant */
    /* @3887480 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887488 b */
    p3888948_0 = p3887476_0;
    goto L_3888948;
    L_3887492: ;
    /* @3887492 constant */
    /* @3887496 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887504 b */
    p3888948_0 = p3887492_0;
    goto L_3888948;
    L_3887508: ;
    /* @3887508 constant */
    /* @3887512 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887520 b */
    p3888948_0 = p3887508_0;
    goto L_3888948;
    L_3887524: ;
    /* @3887524 constant */
    /* @3887528 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887536 b */
    p3888948_0 = p3887524_0;
    goto L_3888948;
    L_3887540: ;
    /* @3887540 constant */
    /* @3887544 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887552 b */
    p3888948_0 = p3887540_0;
    goto L_3888948;
    L_3887556: ;
    /* @3887556 constant */
    /* @3887560 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887568 b */
    p3888948_0 = p3887556_0;
    goto L_3888948;
    L_3887572: ;
    /* @3887572 constant */
    /* @3887576 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887584 b */
    p3888948_0 = p3887572_0;
    goto L_3888948;
    L_3887588: ;
    /* @3887588 constant */
    /* @3887592 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887600 b */
    p3888948_0 = p3887588_0;
    goto L_3888948;
    L_3887604: ;
    /* @3887604 constant */
    /* @3887608 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887616 b */
    p3888948_0 = p3887604_0;
    goto L_3888948;
    L_3887620: ;
    /* @3887620 constant */
    /* @3887624 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887632 b */
    p3888948_0 = p3887620_0;
    goto L_3888948;
    L_3887636: ;
    /* @3887636 constant */
    /* @3887640 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887648 b */
    p3888948_0 = p3887636_0;
    goto L_3888948;
    L_3887652: ;
    /* @3887652 constant */
    /* @3887656 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887664 b */
    p3888948_0 = p3887652_0;
    goto L_3888948;
    L_3887668: ;
    /* @3887668 constant */
    /* @3887672 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887680 b */
    p3888948_0 = p3887668_0;
    goto L_3888948;
    L_3887684: ;
    /* @3887684 constant */
    /* @3887688 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887696 b */
    p3888948_0 = p3887684_0;
    goto L_3888948;
    L_3887700: ;
    /* @3887700 constant */
    /* @3887704 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887712 b */
    p3888948_0 = p3887700_0;
    goto L_3888948;
    L_3887716: ;
    /* @3887716 constant */
    /* @3887720 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887728 b */
    p3888948_0 = p3887716_0;
    goto L_3888948;
    L_3887732: ;
    /* @3887732 constant */
    /* @3887736 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887744 b */
    p3888948_0 = p3887732_0;
    goto L_3888948;
    L_3887748: ;
    /* @3887748 constant */
    /* @3887752 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887760 b */
    p3888948_0 = p3887748_0;
    goto L_3888948;
    L_3887764: ;
    /* @3887764 constant */
    /* @3887768 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887776 b */
    p3888948_0 = p3887764_0;
    goto L_3888948;
    L_3887780: ;
    /* @3887780 constant */
    /* @3887784 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887792 b */
    p3888948_0 = p3887780_0;
    goto L_3888948;
    L_3887796: ;
    /* @3887796 constant */
    /* @3887800 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887808 b */
    p3888948_0 = p3887796_0;
    goto L_3888948;
    L_3887812: ;
    /* @3887812 constant */
    /* @3887816 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887824 b */
    p3888948_0 = p3887812_0;
    goto L_3888948;
    L_3887828: ;
    /* @3887828 constant */
    /* @3887832 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887840 b */
    p3888948_0 = p3887828_0;
    goto L_3888948;
    L_3887844: ;
    /* @3887844 constant */
    /* @3887848 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887856 b */
    p3888948_0 = p3887844_0;
    goto L_3888948;
    L_3887860: ;
    /* @3887860 constant */
    /* @3887864 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887872 b */
    p3888948_0 = p3887860_0;
    goto L_3888948;
    L_3887876: ;
    /* @3887876 constant */
    /* @3887880 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887888 b */
    p3888948_0 = p3887876_0;
    goto L_3888948;
    L_3887892: ;
    /* @3887892 constant */
    /* @3887896 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887904 b */
    p3888948_0 = p3887892_0;
    goto L_3888948;
    L_3887908: ;
    /* @3887908 constant */
    /* @3887912 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887920 b */
    p3888948_0 = p3887908_0;
    goto L_3888948;
    L_3887924: ;
    /* @3887924 constant */
    /* @3887928 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887936 b */
    p3888948_0 = p3887924_0;
    goto L_3888948;
    L_3887940: ;
    /* @3887940 constant */
    /* @3887944 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887952 b */
    p3888948_0 = p3887940_0;
    goto L_3888948;
    L_3887956: ;
    /* @3887956 constant */
    /* @3887960 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3887968 b */
    p3888948_0 = p3887956_0;
    goto L_3888948;
    L_3887972: ;
    /* @3887972 constant */
    /* @3887976 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3887984 b */
    p3888948_0 = p3887972_0;
    goto L_3888948;
    L_3887988: ;
    /* @3887988 constant */
    /* @3887992 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888000 b */
    p3888948_0 = p3887988_0;
    goto L_3888948;
    L_3888004: ;
    /* @3888004 constant */
    /* @3888008 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888016 b */
    p3888948_0 = p3888004_0;
    goto L_3888948;
    L_3888020: ;
    /* @3888020 constant */
    /* @3888024 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888032 b */
    p3888948_0 = p3888020_0;
    goto L_3888948;
    L_3888036: ;
    /* @3888036 constant */
    /* @3888040 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888048 b */
    p3888948_0 = p3888036_0;
    goto L_3888948;
    L_3888052: ;
    /* @3888052 constant */
    /* @3888056 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888064 b */
    p3888948_0 = p3888052_0;
    goto L_3888948;
    L_3888068: ;
    /* @3888068 constant */
    /* @3888072 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888080 b */
    p3888948_0 = p3888068_0;
    goto L_3888948;
    L_3888084: ;
    /* @3888084 constant */
    /* @3888088 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888096 b */
    p3888948_0 = p3888084_0;
    goto L_3888948;
    L_3888100: ;
    /* @3888100 constant */
    /* @3888104 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888112 b */
    p3888948_0 = p3888100_0;
    goto L_3888948;
    L_3888116: ;
    /* @3888116 constant */
    /* @3888120 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888128 b */
    p3888948_0 = p3888116_0;
    goto L_3888948;
    L_3888132: ;
    /* @3888132 constant */
    /* @3888136 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888144 b */
    p3888948_0 = p3888132_0;
    goto L_3888948;
    L_3888148: ;
    /* @3888148 constant */
    /* @3888152 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888160 b */
    p3888948_0 = p3888148_0;
    goto L_3888948;
    L_3888164: ;
    /* @3888164 constant */
    /* @3888168 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888176 b */
    p3888948_0 = p3888164_0;
    goto L_3888948;
    L_3888180: ;
    /* @3888180 constant */
    /* @3888184 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888192 b */
    p3888948_0 = p3888180_0;
    goto L_3888948;
    L_3888196: ;
    /* @3888196 constant */
    /* @3888200 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888208 b */
    p3888948_0 = p3888196_0;
    goto L_3888948;
    L_3888212: ;
    /* @3888212 constant */
    /* @3888216 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(103));
    /* @3888224 b */
    p3888948_0 = p3888212_0;
    goto L_3888948;
    L_3888228: ;
    /* @3888228 constant */
    /* @3888232 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888240 b */
    p3888948_0 = p3888228_0;
    goto L_3888948;
    L_3888244: ;
    /* @3888244 constant */
    /* @3888248 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888256 b */
    p3888948_0 = p3888244_0;
    goto L_3888948;
    L_3888260: ;
    /* @3888260 constant */
    /* @3888264 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888272 b */
    p3888948_0 = p3888260_0;
    goto L_3888948;
    L_3888276: ;
    /* @3888276 constant */
    /* @3888280 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888288 b */
    p3888948_0 = p3888276_0;
    goto L_3888948;
    L_3888292: ;
    /* @3888292 constant */
    /* @3888296 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888304 b */
    p3888948_0 = p3888292_0;
    goto L_3888948;
    L_3888308: ;
    /* @3888308 constant */
    /* @3888312 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888320 b */
    p3888948_0 = p3888308_0;
    goto L_3888948;
    L_3888324: ;
    /* @3888324 constant */
    /* @3888328 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888336 b */
    p3888948_0 = p3888324_0;
    goto L_3888948;
    L_3888340: ;
    /* @3888340 constant */
    /* @3888344 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888352 b */
    p3888948_0 = p3888340_0;
    goto L_3888948;
    L_3888356: ;
    /* @3888356 constant */
    /* @3888360 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888368 b */
    p3888948_0 = p3888356_0;
    goto L_3888948;
    L_3888372: ;
    /* @3888372 constant */
    /* @3888376 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888384 b */
    p3888948_0 = p3888372_0;
    goto L_3888948;
    L_3888388: ;
    /* @3888388 constant */
    /* @3888392 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888400 b */
    p3888948_0 = p3888388_0;
    goto L_3888948;
    L_3888404: ;
    /* @3888404 constant */
    /* @3888408 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888416 b */
    p3888948_0 = p3888404_0;
    goto L_3888948;
    L_3888420: ;
    /* @3888420 constant */
    /* @3888424 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888432 b */
    p3888948_0 = p3888420_0;
    goto L_3888948;
    L_3888436: ;
    /* @3888436 constant */
    /* @3888440 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888448 b */
    p3888948_0 = p3888436_0;
    goto L_3888948;
    L_3888452: ;
    /* @3888452 constant */
    /* @3888456 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888464 b */
    p3888948_0 = p3888452_0;
    goto L_3888948;
    L_3888468: ;
    /* @3888468 constant */
    /* @3888472 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888480 b */
    p3888948_0 = p3888468_0;
    goto L_3888948;
    L_3888484: ;
    /* @3888484 constant */
    /* @3888488 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888496 b */
    p3888948_0 = p3888484_0;
    goto L_3888948;
    L_3888500: ;
    /* @3888500 constant */
    /* @3888504 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888512 b */
    p3888948_0 = p3888500_0;
    goto L_3888948;
    L_3888516: ;
    /* @3888516 constant */
    /* @3888520 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888528 b */
    p3888948_0 = p3888516_0;
    goto L_3888948;
    L_3888532: ;
    /* @3888532 constant */
    /* @3888536 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888544 b */
    p3888948_0 = p3888532_0;
    goto L_3888948;
    L_3888548: ;
    /* @3888548 constant */
    /* @3888552 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888560 b */
    p3888948_0 = p3888548_0;
    goto L_3888948;
    L_3888564: ;
    /* @3888564 constant */
    /* @3888568 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888576 b */
    p3888948_0 = p3888564_0;
    goto L_3888948;
    L_3888580: ;
    /* @3888580 constant */
    /* @3888584 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888592 b */
    p3888948_0 = p3888580_0;
    goto L_3888948;
    L_3888596: ;
    /* @3888596 constant */
    /* @3888600 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888608 b */
    p3888948_0 = p3888596_0;
    goto L_3888948;
    L_3888612: ;
    /* @3888612 constant */
    /* @3888616 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888624 b */
    p3888948_0 = p3888612_0;
    goto L_3888948;
    L_3888628: ;
    /* @3888628 constant */
    /* @3888632 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888640 b */
    p3888948_0 = p3888628_0;
    goto L_3888948;
    L_3888644: ;
    /* @3888644 constant */
    /* @3888648 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888656 b */
    p3888948_0 = p3888644_0;
    goto L_3888948;
    L_3888660: ;
    /* @3888660 constant */
    /* @3888664 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888672 b */
    p3888948_0 = p3888660_0;
    goto L_3888948;
    L_3888676: ;
    /* @3888676 constant */
    /* @3888680 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888688 b */
    p3888948_0 = p3888676_0;
    goto L_3888948;
    L_3888692: ;
    /* @3888692 constant */
    /* @3888696 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888704 b */
    p3888948_0 = p3888692_0;
    goto L_3888948;
    L_3888708: ;
    /* @3888708 constant */
    /* @3888712 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888720 b */
    p3888948_0 = p3888708_0;
    goto L_3888948;
    L_3888724: ;
    /* @3888724 constant */
    /* @3888728 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888736 b */
    p3888948_0 = p3888724_0;
    goto L_3888948;
    L_3888740: ;
    /* @3888740 constant */
    /* @3888744 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888752 b */
    p3888948_0 = p3888740_0;
    goto L_3888948;
    L_3888756: ;
    /* @3888756 constant */
    /* @3888760 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888768 b */
    p3888948_0 = p3888756_0;
    goto L_3888948;
    L_3888772: ;
    /* @3888772 constant */
    /* @3888776 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888784 b */
    p3888948_0 = p3888772_0;
    goto L_3888948;
    L_3888788: ;
    /* @3888788 constant */
    /* @3888792 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888800 b */
    p3888948_0 = p3888788_0;
    goto L_3888948;
    L_3888804: ;
    /* @3888804 constant */
    /* @3888808 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888816 b */
    p3888948_0 = p3888804_0;
    goto L_3888948;
    L_3888820: ;
    /* @3888820 constant */
    /* @3888824 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888832 b */
    p3888948_0 = p3888820_0;
    goto L_3888948;
    L_3888836: ;
    /* @3888836 constant */
    /* @3888840 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888848 b */
    p3888948_0 = p3888836_0;
    goto L_3888948;
    L_3888852: ;
    /* @3888852 constant */
    /* @3888856 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888864 b */
    p3888948_0 = p3888852_0;
    goto L_3888948;
    L_3888868: ;
    /* @3888868 constant */
    /* @3888872 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888880 b */
    p3888948_0 = p3888868_0;
    goto L_3888948;
    L_3888884: ;
    /* @3888884 constant */
    /* @3888888 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888896 b */
    p3888948_0 = p3888884_0;
    goto L_3888948;
    L_3888900: ;
    /* @3888900 constant */
    /* @3888904 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888912 b */
    p3888948_0 = p3888900_0;
    goto L_3888948;
    L_3888916: ;
    /* @3888916 constant */
    /* @3888920 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888928 b */
    p3888948_0 = p3888916_0;
    goto L_3888948;
    L_3888932: ;
    /* @3888932 constant */
    /* @3888936 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(100));
    /* @3888944 b */
    p3888948_0 = p3888932_0;
    goto L_3888948;
    L_3888948: ;
    /* @3888948 popz */
    L_3888952: ;
    return;
}
