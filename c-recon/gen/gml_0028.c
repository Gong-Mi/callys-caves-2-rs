/* generated from CODE 28 (gml_Object_obj_bossboulder_Create_0), source start 3863584, end 3866992. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0028(GmVM* vm) {
    Val p3865308_0;
    Val p3865324_0;
    Val p3865340_0;
    Val p3865356_0;
    Val p3865372_0;
    Val p3865388_0;
    Val p3865404_0;
    Val p3865420_0;
    Val p3865436_0;
    Val p3865452_0;
    Val p3865468_0;
    Val p3865484_0;
    Val p3865500_0;
    Val p3865516_0;
    Val p3865532_0;
    Val p3865548_0;
    Val p3865564_0;
    Val p3865580_0;
    Val p3865596_0;
    Val p3865612_0;
    Val p3865628_0;
    Val p3865644_0;
    Val p3865660_0;
    Val p3865676_0;
    Val p3865692_0;
    Val p3865708_0;
    Val p3865724_0;
    Val p3865740_0;
    Val p3865756_0;
    Val p3865772_0;
    Val p3865788_0;
    Val p3865804_0;
    Val p3865820_0;
    Val p3865836_0;
    Val p3865852_0;
    Val p3865868_0;
    Val p3865884_0;
    Val p3865900_0;
    Val p3865916_0;
    Val p3865932_0;
    Val p3865948_0;
    Val p3865964_0;
    Val p3865980_0;
    Val p3865996_0;
    Val p3866012_0;
    Val p3866028_0;
    Val p3866044_0;
    Val p3866060_0;
    Val p3866076_0;
    Val p3866092_0;
    Val p3866108_0;
    Val p3866124_0;
    Val p3866140_0;
    Val p3866156_0;
    Val p3866172_0;
    Val p3866188_0;
    Val p3866204_0;
    Val p3866220_0;
    Val p3866236_0;
    Val p3866252_0;
    Val p3866268_0;
    Val p3866284_0;
    Val p3866300_0;
    Val p3866316_0;
    Val p3866332_0;
    Val p3866348_0;
    Val p3866364_0;
    Val p3866380_0;
    Val p3866396_0;
    Val p3866412_0;
    Val p3866428_0;
    Val p3866444_0;
    Val p3866460_0;
    Val p3866476_0;
    Val p3866492_0;
    Val p3866508_0;
    Val p3866524_0;
    Val p3866540_0;
    Val p3866556_0;
    Val p3866572_0;
    Val p3866588_0;
    Val p3866604_0;
    Val p3866620_0;
    Val p3866636_0;
    Val p3866652_0;
    Val p3866668_0;
    Val p3866684_0;
    Val p3866700_0;
    Val p3866716_0;
    Val p3866732_0;
    Val p3866748_0;
    Val p3866764_0;
    Val p3866780_0;
    Val p3866796_0;
    Val p3866812_0;
    Val p3866828_0;
    Val p3866844_0;
    Val p3866860_0;
    Val p3866876_0;
    Val p3866892_0;
    Val p3866908_0;
    Val p3866924_0;
    Val p3866940_0;
    Val p3866956_0;
    Val p3866972_0;
    Val p3866988_0;
    /* @3863584 constant */
    /* @3863588 constant */
    /* @3863592 constant */
    /* @3863596 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    /* @3863604 constant */
    /* @3863608 store */
    GM_WRITE(vm, -1, "type", VAL(1));
    /* @3863616 load */
    /* @3863624 dup */
    /* @3863628 constant */
    /* @3863632 cmp */
    /* @3863636 bt */
    p3865308_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(0)))) goto L_3865308;
    /* @3863640 dup */
    /* @3863644 constant */
    /* @3863648 cmp */
    /* @3863652 bt */
    p3865324_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_3865324;
    /* @3863656 dup */
    /* @3863660 constant */
    /* @3863664 cmp */
    /* @3863668 bt */
    p3865340_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_3865340;
    /* @3863672 dup */
    /* @3863676 constant */
    /* @3863680 cmp */
    /* @3863684 bt */
    p3865356_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_3865356;
    /* @3863688 dup */
    /* @3863692 constant */
    /* @3863696 cmp */
    /* @3863700 bt */
    p3865372_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_3865372;
    /* @3863704 dup */
    /* @3863708 constant */
    /* @3863712 cmp */
    /* @3863716 bt */
    p3865388_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_3865388;
    /* @3863720 dup */
    /* @3863724 constant */
    /* @3863728 cmp */
    /* @3863732 bt */
    p3865404_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_3865404;
    /* @3863736 dup */
    /* @3863740 constant */
    /* @3863744 cmp */
    /* @3863748 bt */
    p3865420_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_3865420;
    /* @3863752 dup */
    /* @3863756 constant */
    /* @3863760 cmp */
    /* @3863764 bt */
    p3865436_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_3865436;
    /* @3863768 dup */
    /* @3863772 constant */
    /* @3863776 cmp */
    /* @3863780 bt */
    p3865452_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_3865452;
    /* @3863784 dup */
    /* @3863788 constant */
    /* @3863792 cmp */
    /* @3863796 bt */
    p3865468_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3865468;
    /* @3863800 dup */
    /* @3863804 constant */
    /* @3863808 cmp */
    /* @3863812 bt */
    p3865484_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_3865484;
    /* @3863816 dup */
    /* @3863820 constant */
    /* @3863824 cmp */
    /* @3863828 bt */
    p3865500_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_3865500;
    /* @3863832 dup */
    /* @3863836 constant */
    /* @3863840 cmp */
    /* @3863844 bt */
    p3865516_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_3865516;
    /* @3863848 dup */
    /* @3863852 constant */
    /* @3863856 cmp */
    /* @3863860 bt */
    p3865532_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_3865532;
    /* @3863864 dup */
    /* @3863868 constant */
    /* @3863872 cmp */
    /* @3863876 bt */
    p3865548_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_3865548;
    /* @3863880 dup */
    /* @3863884 constant */
    /* @3863888 cmp */
    /* @3863892 bt */
    p3865564_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_3865564;
    /* @3863896 dup */
    /* @3863900 constant */
    /* @3863904 cmp */
    /* @3863908 bt */
    p3865580_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_3865580;
    /* @3863912 dup */
    /* @3863916 constant */
    /* @3863920 cmp */
    /* @3863924 bt */
    p3865596_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_3865596;
    /* @3863928 dup */
    /* @3863932 constant */
    /* @3863936 cmp */
    /* @3863940 bt */
    p3865612_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_3865612;
    /* @3863944 dup */
    /* @3863948 constant */
    /* @3863952 cmp */
    /* @3863956 bt */
    p3865628_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_3865628;
    /* @3863960 dup */
    /* @3863964 constant */
    /* @3863968 cmp */
    /* @3863972 bt */
    p3865644_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_3865644;
    /* @3863976 dup */
    /* @3863980 constant */
    /* @3863984 cmp */
    /* @3863988 bt */
    p3865660_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_3865660;
    /* @3863992 dup */
    /* @3863996 constant */
    /* @3864000 cmp */
    /* @3864004 bt */
    p3865676_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_3865676;
    /* @3864008 dup */
    /* @3864012 constant */
    /* @3864016 cmp */
    /* @3864020 bt */
    p3865692_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_3865692;
    /* @3864024 dup */
    /* @3864028 constant */
    /* @3864032 cmp */
    /* @3864036 bt */
    p3865708_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_3865708;
    /* @3864040 dup */
    /* @3864044 constant */
    /* @3864048 cmp */
    /* @3864052 bt */
    p3865724_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_3865724;
    /* @3864056 dup */
    /* @3864060 constant */
    /* @3864064 cmp */
    /* @3864068 bt */
    p3865740_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3865740;
    /* @3864072 dup */
    /* @3864076 constant */
    /* @3864080 cmp */
    /* @3864084 bt */
    p3865756_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_3865756;
    /* @3864088 dup */
    /* @3864092 constant */
    /* @3864096 cmp */
    /* @3864100 bt */
    p3865772_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_3865772;
    /* @3864104 dup */
    /* @3864108 constant */
    /* @3864112 cmp */
    /* @3864116 bt */
    p3865788_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_3865788;
    /* @3864120 dup */
    /* @3864124 constant */
    /* @3864128 cmp */
    /* @3864132 bt */
    p3865804_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_3865804;
    /* @3864136 dup */
    /* @3864140 constant */
    /* @3864144 cmp */
    /* @3864148 bt */
    p3865820_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_3865820;
    /* @3864152 dup */
    /* @3864156 constant */
    /* @3864160 cmp */
    /* @3864164 bt */
    p3865836_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_3865836;
    /* @3864168 dup */
    /* @3864172 constant */
    /* @3864176 cmp */
    /* @3864180 bt */
    p3865852_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_3865852;
    /* @3864184 dup */
    /* @3864188 constant */
    /* @3864192 cmp */
    /* @3864196 bt */
    p3865868_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_3865868;
    /* @3864200 dup */
    /* @3864204 constant */
    /* @3864208 cmp */
    /* @3864212 bt */
    p3865884_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_3865884;
    /* @3864216 dup */
    /* @3864220 constant */
    /* @3864224 cmp */
    /* @3864228 bt */
    p3865900_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_3865900;
    /* @3864232 dup */
    /* @3864236 constant */
    /* @3864240 cmp */
    /* @3864244 bt */
    p3865916_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_3865916;
    /* @3864248 dup */
    /* @3864252 constant */
    /* @3864256 cmp */
    /* @3864260 bt */
    p3865932_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_3865932;
    /* @3864264 dup */
    /* @3864268 constant */
    /* @3864272 cmp */
    /* @3864276 bt */
    p3865948_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_3865948;
    /* @3864280 dup */
    /* @3864284 constant */
    /* @3864288 cmp */
    /* @3864292 bt */
    p3865964_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_3865964;
    /* @3864296 dup */
    /* @3864300 constant */
    /* @3864304 cmp */
    /* @3864308 bt */
    p3865980_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_3865980;
    /* @3864312 dup */
    /* @3864316 constant */
    /* @3864320 cmp */
    /* @3864324 bt */
    p3865996_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_3865996;
    /* @3864328 dup */
    /* @3864332 constant */
    /* @3864336 cmp */
    /* @3864340 bt */
    p3866012_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_3866012;
    /* @3864344 dup */
    /* @3864348 constant */
    /* @3864352 cmp */
    /* @3864356 bt */
    p3866028_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_3866028;
    /* @3864360 dup */
    /* @3864364 constant */
    /* @3864368 cmp */
    /* @3864372 bt */
    p3866044_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_3866044;
    /* @3864376 dup */
    /* @3864380 constant */
    /* @3864384 cmp */
    /* @3864388 bt */
    p3866060_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_3866060;
    /* @3864392 dup */
    /* @3864396 constant */
    /* @3864400 cmp */
    /* @3864404 bt */
    p3866076_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3866076;
    /* @3864408 dup */
    /* @3864412 constant */
    /* @3864416 cmp */
    /* @3864420 bt */
    p3866092_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_3866092;
    /* @3864424 dup */
    /* @3864428 constant */
    /* @3864432 cmp */
    /* @3864436 bt */
    p3866108_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_3866108;
    /* @3864440 dup */
    /* @3864444 constant */
    /* @3864448 cmp */
    /* @3864452 bt */
    p3866124_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_3866124;
    /* @3864456 dup */
    /* @3864460 constant */
    /* @3864464 cmp */
    /* @3864468 bt */
    p3866140_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_3866140;
    /* @3864472 dup */
    /* @3864476 constant */
    /* @3864480 cmp */
    /* @3864484 bt */
    p3866156_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_3866156;
    /* @3864488 dup */
    /* @3864492 constant */
    /* @3864496 cmp */
    /* @3864500 bt */
    p3866172_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_3866172;
    /* @3864504 dup */
    /* @3864508 constant */
    /* @3864512 cmp */
    /* @3864516 bt */
    p3866188_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_3866188;
    /* @3864520 dup */
    /* @3864524 constant */
    /* @3864528 cmp */
    /* @3864532 bt */
    p3866204_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_3866204;
    /* @3864536 dup */
    /* @3864540 constant */
    /* @3864544 cmp */
    /* @3864548 bt */
    p3866220_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_3866220;
    /* @3864552 dup */
    /* @3864556 constant */
    /* @3864560 cmp */
    /* @3864564 bt */
    p3866236_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_3866236;
    /* @3864568 dup */
    /* @3864572 constant */
    /* @3864576 cmp */
    /* @3864580 bt */
    p3866252_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_3866252;
    /* @3864584 dup */
    /* @3864588 constant */
    /* @3864592 cmp */
    /* @3864596 bt */
    p3866268_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_3866268;
    /* @3864600 dup */
    /* @3864604 constant */
    /* @3864608 cmp */
    /* @3864612 bt */
    p3866284_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_3866284;
    /* @3864616 dup */
    /* @3864620 constant */
    /* @3864624 cmp */
    /* @3864628 bt */
    p3866300_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_3866300;
    /* @3864632 dup */
    /* @3864636 constant */
    /* @3864640 cmp */
    /* @3864644 bt */
    p3866316_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_3866316;
    /* @3864648 dup */
    /* @3864652 constant */
    /* @3864656 cmp */
    /* @3864660 bt */
    p3866332_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3866332;
    /* @3864664 dup */
    /* @3864668 constant */
    /* @3864672 cmp */
    /* @3864676 bt */
    p3866348_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_3866348;
    /* @3864680 dup */
    /* @3864684 constant */
    /* @3864688 cmp */
    /* @3864692 bt */
    p3866364_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_3866364;
    /* @3864696 dup */
    /* @3864700 constant */
    /* @3864704 cmp */
    /* @3864708 bt */
    p3866380_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_3866380;
    /* @3864712 dup */
    /* @3864716 constant */
    /* @3864720 cmp */
    /* @3864724 bt */
    p3866396_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_3866396;
    /* @3864728 dup */
    /* @3864732 constant */
    /* @3864736 cmp */
    /* @3864740 bt */
    p3866412_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_3866412;
    /* @3864744 dup */
    /* @3864748 constant */
    /* @3864752 cmp */
    /* @3864756 bt */
    p3866428_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_3866428;
    /* @3864760 dup */
    /* @3864764 constant */
    /* @3864768 cmp */
    /* @3864772 bt */
    p3866444_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_3866444;
    /* @3864776 dup */
    /* @3864780 constant */
    /* @3864784 cmp */
    /* @3864788 bt */
    p3866460_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_3866460;
    /* @3864792 dup */
    /* @3864796 constant */
    /* @3864800 cmp */
    /* @3864804 bt */
    p3866476_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_3866476;
    /* @3864808 dup */
    /* @3864812 constant */
    /* @3864816 cmp */
    /* @3864820 bt */
    p3866492_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_3866492;
    /* @3864824 dup */
    /* @3864828 constant */
    /* @3864832 cmp */
    /* @3864836 bt */
    p3866508_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_3866508;
    /* @3864840 dup */
    /* @3864844 constant */
    /* @3864848 cmp */
    /* @3864852 bt */
    p3866524_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_3866524;
    /* @3864856 dup */
    /* @3864860 constant */
    /* @3864864 cmp */
    /* @3864868 bt */
    p3866540_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_3866540;
    /* @3864872 dup */
    /* @3864876 constant */
    /* @3864880 cmp */
    /* @3864884 bt */
    p3866556_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_3866556;
    /* @3864888 dup */
    /* @3864892 constant */
    /* @3864896 cmp */
    /* @3864900 bt */
    p3866572_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_3866572;
    /* @3864904 dup */
    /* @3864908 constant */
    /* @3864912 cmp */
    /* @3864916 bt */
    p3866588_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_3866588;
    /* @3864920 dup */
    /* @3864924 constant */
    /* @3864928 cmp */
    /* @3864932 bt */
    p3866604_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_3866604;
    /* @3864936 dup */
    /* @3864940 constant */
    /* @3864944 cmp */
    /* @3864948 bt */
    p3866620_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3866620;
    /* @3864952 dup */
    /* @3864956 constant */
    /* @3864960 cmp */
    /* @3864964 bt */
    p3866636_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_3866636;
    /* @3864968 dup */
    /* @3864972 constant */
    /* @3864976 cmp */
    /* @3864980 bt */
    p3866652_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_3866652;
    /* @3864984 dup */
    /* @3864988 constant */
    /* @3864992 cmp */
    /* @3864996 bt */
    p3866668_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_3866668;
    /* @3865000 dup */
    /* @3865004 constant */
    /* @3865008 cmp */
    /* @3865012 bt */
    p3866684_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_3866684;
    /* @3865016 dup */
    /* @3865020 constant */
    /* @3865024 cmp */
    /* @3865028 bt */
    p3866700_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_3866700;
    /* @3865032 dup */
    /* @3865036 constant */
    /* @3865040 cmp */
    /* @3865044 bt */
    p3866716_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_3866716;
    /* @3865048 dup */
    /* @3865052 constant */
    /* @3865056 cmp */
    /* @3865060 bt */
    p3866732_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_3866732;
    /* @3865064 dup */
    /* @3865068 constant */
    /* @3865072 cmp */
    /* @3865076 bt */
    p3866748_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_3866748;
    /* @3865080 dup */
    /* @3865084 constant */
    /* @3865088 cmp */
    /* @3865092 bt */
    p3866764_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_3866764;
    /* @3865096 dup */
    /* @3865100 constant */
    /* @3865104 cmp */
    /* @3865108 bt */
    p3866780_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_3866780;
    /* @3865112 dup */
    /* @3865116 constant */
    /* @3865120 cmp */
    /* @3865124 bt */
    p3866796_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_3866796;
    /* @3865128 dup */
    /* @3865132 constant */
    /* @3865136 cmp */
    /* @3865140 bt */
    p3866812_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_3866812;
    /* @3865144 dup */
    /* @3865148 constant */
    /* @3865152 cmp */
    /* @3865156 bt */
    p3866828_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_3866828;
    /* @3865160 dup */
    /* @3865164 constant */
    /* @3865168 cmp */
    /* @3865172 bt */
    p3866844_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_3866844;
    /* @3865176 dup */
    /* @3865180 constant */
    /* @3865184 cmp */
    /* @3865188 bt */
    p3866860_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_3866860;
    /* @3865192 dup */
    /* @3865196 constant */
    /* @3865200 cmp */
    /* @3865204 bt */
    p3866876_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_3866876;
    /* @3865208 dup */
    /* @3865212 constant */
    /* @3865216 cmp */
    /* @3865220 bt */
    p3866892_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_3866892;
    /* @3865224 dup */
    /* @3865228 constant */
    /* @3865232 cmp */
    /* @3865236 bt */
    p3866908_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_3866908;
    /* @3865240 dup */
    /* @3865244 constant */
    /* @3865248 cmp */
    /* @3865252 bt */
    p3866924_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_3866924;
    /* @3865256 dup */
    /* @3865260 constant */
    /* @3865264 cmp */
    /* @3865268 bt */
    p3866940_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_3866940;
    /* @3865272 dup */
    /* @3865276 constant */
    /* @3865280 cmp */
    /* @3865284 bt */
    p3866956_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_3866956;
    /* @3865288 dup */
    /* @3865292 constant */
    /* @3865296 cmp */
    /* @3865300 bt */
    p3866972_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3866972;
    /* @3865304 b */
    p3866988_0 = GM_READ(vm, -1, "room");
    goto L_3866988;
    L_3865308: ;
    /* @3865308 constant */
    /* @3865312 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865320 b */
    p3866988_0 = p3865308_0;
    goto L_3866988;
    L_3865324: ;
    /* @3865324 constant */
    /* @3865328 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865336 b */
    p3866988_0 = p3865324_0;
    goto L_3866988;
    L_3865340: ;
    /* @3865340 constant */
    /* @3865344 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865352 b */
    p3866988_0 = p3865340_0;
    goto L_3866988;
    L_3865356: ;
    /* @3865356 constant */
    /* @3865360 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865368 b */
    p3866988_0 = p3865356_0;
    goto L_3866988;
    L_3865372: ;
    /* @3865372 constant */
    /* @3865376 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865384 b */
    p3866988_0 = p3865372_0;
    goto L_3866988;
    L_3865388: ;
    /* @3865388 constant */
    /* @3865392 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865400 b */
    p3866988_0 = p3865388_0;
    goto L_3866988;
    L_3865404: ;
    /* @3865404 constant */
    /* @3865408 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865416 b */
    p3866988_0 = p3865404_0;
    goto L_3866988;
    L_3865420: ;
    /* @3865420 constant */
    /* @3865424 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865432 b */
    p3866988_0 = p3865420_0;
    goto L_3866988;
    L_3865436: ;
    /* @3865436 constant */
    /* @3865440 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865448 b */
    p3866988_0 = p3865436_0;
    goto L_3866988;
    L_3865452: ;
    /* @3865452 constant */
    /* @3865456 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865464 b */
    p3866988_0 = p3865452_0;
    goto L_3866988;
    L_3865468: ;
    /* @3865468 constant */
    /* @3865472 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3865480 b */
    p3866988_0 = p3865468_0;
    goto L_3866988;
    L_3865484: ;
    /* @3865484 constant */
    /* @3865488 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865496 b */
    p3866988_0 = p3865484_0;
    goto L_3866988;
    L_3865500: ;
    /* @3865500 constant */
    /* @3865504 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865512 b */
    p3866988_0 = p3865500_0;
    goto L_3866988;
    L_3865516: ;
    /* @3865516 constant */
    /* @3865520 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865528 b */
    p3866988_0 = p3865516_0;
    goto L_3866988;
    L_3865532: ;
    /* @3865532 constant */
    /* @3865536 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865544 b */
    p3866988_0 = p3865532_0;
    goto L_3866988;
    L_3865548: ;
    /* @3865548 constant */
    /* @3865552 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865560 b */
    p3866988_0 = p3865548_0;
    goto L_3866988;
    L_3865564: ;
    /* @3865564 constant */
    /* @3865568 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865576 b */
    p3866988_0 = p3865564_0;
    goto L_3866988;
    L_3865580: ;
    /* @3865580 constant */
    /* @3865584 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865592 b */
    p3866988_0 = p3865580_0;
    goto L_3866988;
    L_3865596: ;
    /* @3865596 constant */
    /* @3865600 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865608 b */
    p3866988_0 = p3865596_0;
    goto L_3866988;
    L_3865612: ;
    /* @3865612 constant */
    /* @3865616 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865624 b */
    p3866988_0 = p3865612_0;
    goto L_3866988;
    L_3865628: ;
    /* @3865628 constant */
    /* @3865632 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865640 b */
    p3866988_0 = p3865628_0;
    goto L_3866988;
    L_3865644: ;
    /* @3865644 constant */
    /* @3865648 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865656 b */
    p3866988_0 = p3865644_0;
    goto L_3866988;
    L_3865660: ;
    /* @3865660 constant */
    /* @3865664 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865672 b */
    p3866988_0 = p3865660_0;
    goto L_3866988;
    L_3865676: ;
    /* @3865676 constant */
    /* @3865680 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865688 b */
    p3866988_0 = p3865676_0;
    goto L_3866988;
    L_3865692: ;
    /* @3865692 constant */
    /* @3865696 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865704 b */
    p3866988_0 = p3865692_0;
    goto L_3866988;
    L_3865708: ;
    /* @3865708 constant */
    /* @3865712 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865720 b */
    p3866988_0 = p3865708_0;
    goto L_3866988;
    L_3865724: ;
    /* @3865724 constant */
    /* @3865728 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865736 b */
    p3866988_0 = p3865724_0;
    goto L_3866988;
    L_3865740: ;
    /* @3865740 constant */
    /* @3865744 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3865752 b */
    p3866988_0 = p3865740_0;
    goto L_3866988;
    L_3865756: ;
    /* @3865756 constant */
    /* @3865760 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865768 b */
    p3866988_0 = p3865756_0;
    goto L_3866988;
    L_3865772: ;
    /* @3865772 constant */
    /* @3865776 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865784 b */
    p3866988_0 = p3865772_0;
    goto L_3866988;
    L_3865788: ;
    /* @3865788 constant */
    /* @3865792 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865800 b */
    p3866988_0 = p3865788_0;
    goto L_3866988;
    L_3865804: ;
    /* @3865804 constant */
    /* @3865808 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865816 b */
    p3866988_0 = p3865804_0;
    goto L_3866988;
    L_3865820: ;
    /* @3865820 constant */
    /* @3865824 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865832 b */
    p3866988_0 = p3865820_0;
    goto L_3866988;
    L_3865836: ;
    /* @3865836 constant */
    /* @3865840 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865848 b */
    p3866988_0 = p3865836_0;
    goto L_3866988;
    L_3865852: ;
    /* @3865852 constant */
    /* @3865856 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865864 b */
    p3866988_0 = p3865852_0;
    goto L_3866988;
    L_3865868: ;
    /* @3865868 constant */
    /* @3865872 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865880 b */
    p3866988_0 = p3865868_0;
    goto L_3866988;
    L_3865884: ;
    /* @3865884 constant */
    /* @3865888 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865896 b */
    p3866988_0 = p3865884_0;
    goto L_3866988;
    L_3865900: ;
    /* @3865900 constant */
    /* @3865904 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865912 b */
    p3866988_0 = p3865900_0;
    goto L_3866988;
    L_3865916: ;
    /* @3865916 constant */
    /* @3865920 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865928 b */
    p3866988_0 = p3865916_0;
    goto L_3866988;
    L_3865932: ;
    /* @3865932 constant */
    /* @3865936 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865944 b */
    p3866988_0 = p3865932_0;
    goto L_3866988;
    L_3865948: ;
    /* @3865948 constant */
    /* @3865952 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865960 b */
    p3866988_0 = p3865948_0;
    goto L_3866988;
    L_3865964: ;
    /* @3865964 constant */
    /* @3865968 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865976 b */
    p3866988_0 = p3865964_0;
    goto L_3866988;
    L_3865980: ;
    /* @3865980 constant */
    /* @3865984 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3865992 b */
    p3866988_0 = p3865980_0;
    goto L_3866988;
    L_3865996: ;
    /* @3865996 constant */
    /* @3866000 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866008 b */
    p3866988_0 = p3865996_0;
    goto L_3866988;
    L_3866012: ;
    /* @3866012 constant */
    /* @3866016 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866024 b */
    p3866988_0 = p3866012_0;
    goto L_3866988;
    L_3866028: ;
    /* @3866028 constant */
    /* @3866032 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866040 b */
    p3866988_0 = p3866028_0;
    goto L_3866988;
    L_3866044: ;
    /* @3866044 constant */
    /* @3866048 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866056 b */
    p3866988_0 = p3866044_0;
    goto L_3866988;
    L_3866060: ;
    /* @3866060 constant */
    /* @3866064 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866072 b */
    p3866988_0 = p3866060_0;
    goto L_3866988;
    L_3866076: ;
    /* @3866076 constant */
    /* @3866080 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3866088 b */
    p3866988_0 = p3866076_0;
    goto L_3866988;
    L_3866092: ;
    /* @3866092 constant */
    /* @3866096 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866104 b */
    p3866988_0 = p3866092_0;
    goto L_3866988;
    L_3866108: ;
    /* @3866108 constant */
    /* @3866112 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866120 b */
    p3866988_0 = p3866108_0;
    goto L_3866988;
    L_3866124: ;
    /* @3866124 constant */
    /* @3866128 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866136 b */
    p3866988_0 = p3866124_0;
    goto L_3866988;
    L_3866140: ;
    /* @3866140 constant */
    /* @3866144 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866152 b */
    p3866988_0 = p3866140_0;
    goto L_3866988;
    L_3866156: ;
    /* @3866156 constant */
    /* @3866160 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866168 b */
    p3866988_0 = p3866156_0;
    goto L_3866988;
    L_3866172: ;
    /* @3866172 constant */
    /* @3866176 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866184 b */
    p3866988_0 = p3866172_0;
    goto L_3866988;
    L_3866188: ;
    /* @3866188 constant */
    /* @3866192 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866200 b */
    p3866988_0 = p3866188_0;
    goto L_3866988;
    L_3866204: ;
    /* @3866204 constant */
    /* @3866208 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866216 b */
    p3866988_0 = p3866204_0;
    goto L_3866988;
    L_3866220: ;
    /* @3866220 constant */
    /* @3866224 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866232 b */
    p3866988_0 = p3866220_0;
    goto L_3866988;
    L_3866236: ;
    /* @3866236 constant */
    /* @3866240 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866248 b */
    p3866988_0 = p3866236_0;
    goto L_3866988;
    L_3866252: ;
    /* @3866252 constant */
    /* @3866256 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866264 b */
    p3866988_0 = p3866252_0;
    goto L_3866988;
    L_3866268: ;
    /* @3866268 constant */
    /* @3866272 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866280 b */
    p3866988_0 = p3866268_0;
    goto L_3866988;
    L_3866284: ;
    /* @3866284 constant */
    /* @3866288 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866296 b */
    p3866988_0 = p3866284_0;
    goto L_3866988;
    L_3866300: ;
    /* @3866300 constant */
    /* @3866304 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866312 b */
    p3866988_0 = p3866300_0;
    goto L_3866988;
    L_3866316: ;
    /* @3866316 constant */
    /* @3866320 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866328 b */
    p3866988_0 = p3866316_0;
    goto L_3866988;
    L_3866332: ;
    /* @3866332 constant */
    /* @3866336 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3866344 b */
    p3866988_0 = p3866332_0;
    goto L_3866988;
    L_3866348: ;
    /* @3866348 constant */
    /* @3866352 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866360 b */
    p3866988_0 = p3866348_0;
    goto L_3866988;
    L_3866364: ;
    /* @3866364 constant */
    /* @3866368 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866376 b */
    p3866988_0 = p3866364_0;
    goto L_3866988;
    L_3866380: ;
    /* @3866380 constant */
    /* @3866384 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866392 b */
    p3866988_0 = p3866380_0;
    goto L_3866988;
    L_3866396: ;
    /* @3866396 constant */
    /* @3866400 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866408 b */
    p3866988_0 = p3866396_0;
    goto L_3866988;
    L_3866412: ;
    /* @3866412 constant */
    /* @3866416 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866424 b */
    p3866988_0 = p3866412_0;
    goto L_3866988;
    L_3866428: ;
    /* @3866428 constant */
    /* @3866432 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866440 b */
    p3866988_0 = p3866428_0;
    goto L_3866988;
    L_3866444: ;
    /* @3866444 constant */
    /* @3866448 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866456 b */
    p3866988_0 = p3866444_0;
    goto L_3866988;
    L_3866460: ;
    /* @3866460 constant */
    /* @3866464 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866472 b */
    p3866988_0 = p3866460_0;
    goto L_3866988;
    L_3866476: ;
    /* @3866476 constant */
    /* @3866480 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866488 b */
    p3866988_0 = p3866476_0;
    goto L_3866988;
    L_3866492: ;
    /* @3866492 constant */
    /* @3866496 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866504 b */
    p3866988_0 = p3866492_0;
    goto L_3866988;
    L_3866508: ;
    /* @3866508 constant */
    /* @3866512 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866520 b */
    p3866988_0 = p3866508_0;
    goto L_3866988;
    L_3866524: ;
    /* @3866524 constant */
    /* @3866528 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866536 b */
    p3866988_0 = p3866524_0;
    goto L_3866988;
    L_3866540: ;
    /* @3866540 constant */
    /* @3866544 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866552 b */
    p3866988_0 = p3866540_0;
    goto L_3866988;
    L_3866556: ;
    /* @3866556 constant */
    /* @3866560 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866568 b */
    p3866988_0 = p3866556_0;
    goto L_3866988;
    L_3866572: ;
    /* @3866572 constant */
    /* @3866576 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866584 b */
    p3866988_0 = p3866572_0;
    goto L_3866988;
    L_3866588: ;
    /* @3866588 constant */
    /* @3866592 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866600 b */
    p3866988_0 = p3866588_0;
    goto L_3866988;
    L_3866604: ;
    /* @3866604 constant */
    /* @3866608 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866616 b */
    p3866988_0 = p3866604_0;
    goto L_3866988;
    L_3866620: ;
    /* @3866620 constant */
    /* @3866624 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3866632 b */
    p3866988_0 = p3866620_0;
    goto L_3866988;
    L_3866636: ;
    /* @3866636 constant */
    /* @3866640 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866648 b */
    p3866988_0 = p3866636_0;
    goto L_3866988;
    L_3866652: ;
    /* @3866652 constant */
    /* @3866656 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866664 b */
    p3866988_0 = p3866652_0;
    goto L_3866988;
    L_3866668: ;
    /* @3866668 constant */
    /* @3866672 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866680 b */
    p3866988_0 = p3866668_0;
    goto L_3866988;
    L_3866684: ;
    /* @3866684 constant */
    /* @3866688 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866696 b */
    p3866988_0 = p3866684_0;
    goto L_3866988;
    L_3866700: ;
    /* @3866700 constant */
    /* @3866704 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866712 b */
    p3866988_0 = p3866700_0;
    goto L_3866988;
    L_3866716: ;
    /* @3866716 constant */
    /* @3866720 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866728 b */
    p3866988_0 = p3866716_0;
    goto L_3866988;
    L_3866732: ;
    /* @3866732 constant */
    /* @3866736 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866744 b */
    p3866988_0 = p3866732_0;
    goto L_3866988;
    L_3866748: ;
    /* @3866748 constant */
    /* @3866752 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866760 b */
    p3866988_0 = p3866748_0;
    goto L_3866988;
    L_3866764: ;
    /* @3866764 constant */
    /* @3866768 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866776 b */
    p3866988_0 = p3866764_0;
    goto L_3866988;
    L_3866780: ;
    /* @3866780 constant */
    /* @3866784 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866792 b */
    p3866988_0 = p3866780_0;
    goto L_3866988;
    L_3866796: ;
    /* @3866796 constant */
    /* @3866800 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866808 b */
    p3866988_0 = p3866796_0;
    goto L_3866988;
    L_3866812: ;
    /* @3866812 constant */
    /* @3866816 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866824 b */
    p3866988_0 = p3866812_0;
    goto L_3866988;
    L_3866828: ;
    /* @3866828 constant */
    /* @3866832 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866840 b */
    p3866988_0 = p3866828_0;
    goto L_3866988;
    L_3866844: ;
    /* @3866844 constant */
    /* @3866848 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866856 b */
    p3866988_0 = p3866844_0;
    goto L_3866988;
    L_3866860: ;
    /* @3866860 constant */
    /* @3866864 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866872 b */
    p3866988_0 = p3866860_0;
    goto L_3866988;
    L_3866876: ;
    /* @3866876 constant */
    /* @3866880 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866888 b */
    p3866988_0 = p3866876_0;
    goto L_3866988;
    L_3866892: ;
    /* @3866892 constant */
    /* @3866896 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866904 b */
    p3866988_0 = p3866892_0;
    goto L_3866988;
    L_3866908: ;
    /* @3866908 constant */
    /* @3866912 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866920 b */
    p3866988_0 = p3866908_0;
    goto L_3866988;
    L_3866924: ;
    /* @3866924 constant */
    /* @3866928 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866936 b */
    p3866988_0 = p3866924_0;
    goto L_3866988;
    L_3866940: ;
    /* @3866940 constant */
    /* @3866944 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866952 b */
    p3866988_0 = p3866940_0;
    goto L_3866988;
    L_3866956: ;
    /* @3866956 constant */
    /* @3866960 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866968 b */
    p3866988_0 = p3866956_0;
    goto L_3866988;
    L_3866972: ;
    /* @3866972 constant */
    /* @3866976 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3866984 b */
    p3866988_0 = p3866972_0;
    goto L_3866988;
    L_3866988: ;
    /* @3866988 popz */
    L_3866992: ;
    return;
}
