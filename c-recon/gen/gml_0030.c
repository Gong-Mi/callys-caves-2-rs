/* generated from CODE 30 (gml_Object_obj_wall_Create_0), source start 3867684, end 3871212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0030(GmVM* vm) {
    Val p3869464_0;
    Val p3869480_0;
    Val p3869496_0;
    Val p3869512_0;
    Val p3869528_0;
    Val p3869544_0;
    Val p3869560_0;
    Val p3869576_0;
    Val p3869592_0;
    Val p3869608_0;
    Val p3869624_0;
    Val p3869640_0;
    Val p3869656_0;
    Val p3869672_0;
    Val p3869688_0;
    Val p3869704_0;
    Val p3869720_0;
    Val p3869736_0;
    Val p3869752_0;
    Val p3869768_0;
    Val p3869784_0;
    Val p3869800_0;
    Val p3869816_0;
    Val p3869832_0;
    Val p3869848_0;
    Val p3869864_0;
    Val p3869880_0;
    Val p3869896_0;
    Val p3869912_0;
    Val p3869928_0;
    Val p3869944_0;
    Val p3869960_0;
    Val p3869976_0;
    Val p3869992_0;
    Val p3870008_0;
    Val p3870024_0;
    Val p3870040_0;
    Val p3870056_0;
    Val p3870072_0;
    Val p3870088_0;
    Val p3870104_0;
    Val p3870120_0;
    Val p3870136_0;
    Val p3870152_0;
    Val p3870168_0;
    Val p3870184_0;
    Val p3870200_0;
    Val p3870216_0;
    Val p3870232_0;
    Val p3870248_0;
    Val p3870264_0;
    Val p3870280_0;
    Val p3870296_0;
    Val p3870312_0;
    Val p3870328_0;
    Val p3870344_0;
    Val p3870360_0;
    Val p3870376_0;
    Val p3870392_0;
    Val p3870408_0;
    Val p3870424_0;
    Val p3870440_0;
    Val p3870456_0;
    Val p3870472_0;
    Val p3870488_0;
    Val p3870504_0;
    Val p3870520_0;
    Val p3870536_0;
    Val p3870552_0;
    Val p3870568_0;
    Val p3870584_0;
    Val p3870600_0;
    Val p3870616_0;
    Val p3870632_0;
    Val p3870648_0;
    Val p3870664_0;
    Val p3870680_0;
    Val p3870696_0;
    Val p3870712_0;
    Val p3870728_0;
    Val p3870744_0;
    Val p3870760_0;
    Val p3870776_0;
    Val p3870792_0;
    Val p3870808_0;
    Val p3870824_0;
    Val p3870840_0;
    Val p3870856_0;
    Val p3870872_0;
    Val p3870888_0;
    Val p3870904_0;
    Val p3870920_0;
    Val p3870936_0;
    Val p3870952_0;
    Val p3870968_0;
    Val p3870984_0;
    Val p3871000_0;
    Val p3871016_0;
    Val p3871032_0;
    Val p3871048_0;
    Val p3871064_0;
    Val p3871080_0;
    Val p3871096_0;
    Val p3871112_0;
    Val p3871128_0;
    Val p3871144_0;
    Val p3871160_0;
    Val p3871176_0;
    Val p3871192_0;
    Val p3871208_0;
    /* @3867684 constant */
    /* @3867688 store */
    GM_WRITE(vm, -1, "activate", VAL(0));
    /* @3867696 constant */
    /* @3867700 store */
    GM_WRITE(vm, -1, "type", VAL(1));
    /* @3867708 load */
    /* @3867716 dup */
    /* @3867720 constant */
    /* @3867724 cmp */
    /* @3867728 bt */
    p3869464_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_3869464;
    /* @3867732 dup */
    /* @3867736 constant */
    /* @3867740 cmp */
    /* @3867744 bt */
    p3869480_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_3869480;
    /* @3867748 dup */
    /* @3867752 constant */
    /* @3867756 cmp */
    /* @3867760 bt */
    p3869496_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_3869496;
    /* @3867764 dup */
    /* @3867768 constant */
    /* @3867772 cmp */
    /* @3867776 bt */
    p3869512_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_3869512;
    /* @3867780 dup */
    /* @3867784 constant */
    /* @3867788 cmp */
    /* @3867792 bt */
    p3869528_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_3869528;
    /* @3867796 dup */
    /* @3867800 constant */
    /* @3867804 cmp */
    /* @3867808 bt */
    p3869544_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_3869544;
    /* @3867812 dup */
    /* @3867816 constant */
    /* @3867820 cmp */
    /* @3867824 bt */
    p3869560_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_3869560;
    /* @3867828 dup */
    /* @3867832 constant */
    /* @3867836 cmp */
    /* @3867840 bt */
    p3869576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_3869576;
    /* @3867844 dup */
    /* @3867848 constant */
    /* @3867852 cmp */
    /* @3867856 bt */
    p3869592_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_3869592;
    /* @3867860 dup */
    /* @3867864 constant */
    /* @3867868 cmp */
    /* @3867872 bt */
    p3869608_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3869608;
    /* @3867876 dup */
    /* @3867880 constant */
    /* @3867884 cmp */
    /* @3867888 bt */
    p3869624_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_3869624;
    /* @3867892 dup */
    /* @3867896 constant */
    /* @3867900 cmp */
    /* @3867904 bt */
    p3869640_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_3869640;
    /* @3867908 dup */
    /* @3867912 constant */
    /* @3867916 cmp */
    /* @3867920 bt */
    p3869656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_3869656;
    /* @3867924 dup */
    /* @3867928 constant */
    /* @3867932 cmp */
    /* @3867936 bt */
    p3869672_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_3869672;
    /* @3867940 dup */
    /* @3867944 constant */
    /* @3867948 cmp */
    /* @3867952 bt */
    p3869688_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_3869688;
    /* @3867956 dup */
    /* @3867960 constant */
    /* @3867964 cmp */
    /* @3867968 bt */
    p3869704_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_3869704;
    /* @3867972 dup */
    /* @3867976 constant */
    /* @3867980 cmp */
    /* @3867984 bt */
    p3869720_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_3869720;
    /* @3867988 dup */
    /* @3867992 constant */
    /* @3867996 cmp */
    /* @3868000 bt */
    p3869736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_3869736;
    /* @3868004 dup */
    /* @3868008 constant */
    /* @3868012 cmp */
    /* @3868016 bt */
    p3869752_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_3869752;
    /* @3868020 dup */
    /* @3868024 constant */
    /* @3868028 cmp */
    /* @3868032 bt */
    p3869768_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_3869768;
    /* @3868036 dup */
    /* @3868040 constant */
    /* @3868044 cmp */
    /* @3868048 bt */
    p3869784_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_3869784;
    /* @3868052 dup */
    /* @3868056 constant */
    /* @3868060 cmp */
    /* @3868064 bt */
    p3869800_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_3869800;
    /* @3868068 dup */
    /* @3868072 constant */
    /* @3868076 cmp */
    /* @3868080 bt */
    p3869816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_3869816;
    /* @3868084 dup */
    /* @3868088 constant */
    /* @3868092 cmp */
    /* @3868096 bt */
    p3869832_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_3869832;
    /* @3868100 dup */
    /* @3868104 constant */
    /* @3868108 cmp */
    /* @3868112 bt */
    p3869848_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_3869848;
    /* @3868116 dup */
    /* @3868120 constant */
    /* @3868124 cmp */
    /* @3868128 bt */
    p3869864_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_3869864;
    /* @3868132 dup */
    /* @3868136 constant */
    /* @3868140 cmp */
    /* @3868144 bt */
    p3869880_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3869880;
    /* @3868148 dup */
    /* @3868152 constant */
    /* @3868156 cmp */
    /* @3868160 bt */
    p3869896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_3869896;
    /* @3868164 dup */
    /* @3868168 constant */
    /* @3868172 cmp */
    /* @3868176 bt */
    p3869912_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_3869912;
    /* @3868180 dup */
    /* @3868184 constant */
    /* @3868188 cmp */
    /* @3868192 bt */
    p3869928_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_3869928;
    /* @3868196 dup */
    /* @3868200 constant */
    /* @3868204 cmp */
    /* @3868208 bt */
    p3869944_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_3869944;
    /* @3868212 dup */
    /* @3868216 constant */
    /* @3868220 cmp */
    /* @3868224 bt */
    p3869960_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_3869960;
    /* @3868228 dup */
    /* @3868232 constant */
    /* @3868236 cmp */
    /* @3868240 bt */
    p3869976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_3869976;
    /* @3868244 dup */
    /* @3868248 constant */
    /* @3868252 cmp */
    /* @3868256 bt */
    p3869992_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_3869992;
    /* @3868260 dup */
    /* @3868264 constant */
    /* @3868268 cmp */
    /* @3868272 bt */
    p3870008_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_3870008;
    /* @3868276 dup */
    /* @3868280 constant */
    /* @3868284 cmp */
    /* @3868288 bt */
    p3870024_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_3870024;
    /* @3868292 dup */
    /* @3868296 constant */
    /* @3868300 cmp */
    /* @3868304 bt */
    p3870040_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_3870040;
    /* @3868308 dup */
    /* @3868312 constant */
    /* @3868316 cmp */
    /* @3868320 bt */
    p3870056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_3870056;
    /* @3868324 dup */
    /* @3868328 constant */
    /* @3868332 cmp */
    /* @3868336 bt */
    p3870072_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_3870072;
    /* @3868340 dup */
    /* @3868344 constant */
    /* @3868348 cmp */
    /* @3868352 bt */
    p3870088_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_3870088;
    /* @3868356 dup */
    /* @3868360 constant */
    /* @3868364 cmp */
    /* @3868368 bt */
    p3870104_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_3870104;
    /* @3868372 dup */
    /* @3868376 constant */
    /* @3868380 cmp */
    /* @3868384 bt */
    p3870120_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_3870120;
    /* @3868388 dup */
    /* @3868392 constant */
    /* @3868396 cmp */
    /* @3868400 bt */
    p3870136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_3870136;
    /* @3868404 dup */
    /* @3868408 constant */
    /* @3868412 cmp */
    /* @3868416 bt */
    p3870152_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_3870152;
    /* @3868420 dup */
    /* @3868424 constant */
    /* @3868428 cmp */
    /* @3868432 bt */
    p3870168_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_3870168;
    /* @3868436 dup */
    /* @3868440 constant */
    /* @3868444 cmp */
    /* @3868448 bt */
    p3870184_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_3870184;
    /* @3868452 dup */
    /* @3868456 constant */
    /* @3868460 cmp */
    /* @3868464 bt */
    p3870200_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_3870200;
    /* @3868468 dup */
    /* @3868472 constant */
    /* @3868476 cmp */
    /* @3868480 bt */
    p3870216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3870216;
    /* @3868484 dup */
    /* @3868488 constant */
    /* @3868492 cmp */
    /* @3868496 bt */
    p3870232_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_3870232;
    /* @3868500 dup */
    /* @3868504 constant */
    /* @3868508 cmp */
    /* @3868512 bt */
    p3870248_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_3870248;
    /* @3868516 dup */
    /* @3868520 constant */
    /* @3868524 cmp */
    /* @3868528 bt */
    p3870264_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_3870264;
    /* @3868532 dup */
    /* @3868536 constant */
    /* @3868540 cmp */
    /* @3868544 bt */
    p3870280_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_3870280;
    /* @3868548 dup */
    /* @3868552 constant */
    /* @3868556 cmp */
    /* @3868560 bt */
    p3870296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_3870296;
    /* @3868564 dup */
    /* @3868568 constant */
    /* @3868572 cmp */
    /* @3868576 bt */
    p3870312_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_3870312;
    /* @3868580 dup */
    /* @3868584 constant */
    /* @3868588 cmp */
    /* @3868592 bt */
    p3870328_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_3870328;
    /* @3868596 dup */
    /* @3868600 constant */
    /* @3868604 cmp */
    /* @3868608 bt */
    p3870344_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_3870344;
    /* @3868612 dup */
    /* @3868616 constant */
    /* @3868620 cmp */
    /* @3868624 bt */
    p3870360_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_3870360;
    /* @3868628 dup */
    /* @3868632 constant */
    /* @3868636 cmp */
    /* @3868640 bt */
    p3870376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_3870376;
    /* @3868644 dup */
    /* @3868648 constant */
    /* @3868652 cmp */
    /* @3868656 bt */
    p3870392_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_3870392;
    /* @3868660 dup */
    /* @3868664 constant */
    /* @3868668 cmp */
    /* @3868672 bt */
    p3870408_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_3870408;
    /* @3868676 dup */
    /* @3868680 constant */
    /* @3868684 cmp */
    /* @3868688 bt */
    p3870424_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_3870424;
    /* @3868692 dup */
    /* @3868696 constant */
    /* @3868700 cmp */
    /* @3868704 bt */
    p3870440_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_3870440;
    /* @3868708 dup */
    /* @3868712 constant */
    /* @3868716 cmp */
    /* @3868720 bt */
    p3870456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_3870456;
    /* @3868724 dup */
    /* @3868728 constant */
    /* @3868732 cmp */
    /* @3868736 bt */
    p3870472_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3870472;
    /* @3868740 dup */
    /* @3868744 constant */
    /* @3868748 cmp */
    /* @3868752 bt */
    p3870488_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_3870488;
    /* @3868756 dup */
    /* @3868760 constant */
    /* @3868764 cmp */
    /* @3868768 bt */
    p3870504_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_3870504;
    /* @3868772 dup */
    /* @3868776 constant */
    /* @3868780 cmp */
    /* @3868784 bt */
    p3870520_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_3870520;
    /* @3868788 dup */
    /* @3868792 constant */
    /* @3868796 cmp */
    /* @3868800 bt */
    p3870536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_3870536;
    /* @3868804 dup */
    /* @3868808 constant */
    /* @3868812 cmp */
    /* @3868816 bt */
    p3870552_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_3870552;
    /* @3868820 dup */
    /* @3868824 constant */
    /* @3868828 cmp */
    /* @3868832 bt */
    p3870568_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_3870568;
    /* @3868836 dup */
    /* @3868840 constant */
    /* @3868844 cmp */
    /* @3868848 bt */
    p3870584_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_3870584;
    /* @3868852 dup */
    /* @3868856 constant */
    /* @3868860 cmp */
    /* @3868864 bt */
    p3870600_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_3870600;
    /* @3868868 dup */
    /* @3868872 constant */
    /* @3868876 cmp */
    /* @3868880 bt */
    p3870616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_3870616;
    /* @3868884 dup */
    /* @3868888 constant */
    /* @3868892 cmp */
    /* @3868896 bt */
    p3870632_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_3870632;
    /* @3868900 dup */
    /* @3868904 constant */
    /* @3868908 cmp */
    /* @3868912 bt */
    p3870648_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_3870648;
    /* @3868916 dup */
    /* @3868920 constant */
    /* @3868924 cmp */
    /* @3868928 bt */
    p3870664_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_3870664;
    /* @3868932 dup */
    /* @3868936 constant */
    /* @3868940 cmp */
    /* @3868944 bt */
    p3870680_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_3870680;
    /* @3868948 dup */
    /* @3868952 constant */
    /* @3868956 cmp */
    /* @3868960 bt */
    p3870696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_3870696;
    /* @3868964 dup */
    /* @3868968 constant */
    /* @3868972 cmp */
    /* @3868976 bt */
    p3870712_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_3870712;
    /* @3868980 dup */
    /* @3868984 constant */
    /* @3868988 cmp */
    /* @3868992 bt */
    p3870728_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_3870728;
    /* @3868996 dup */
    /* @3869000 constant */
    /* @3869004 cmp */
    /* @3869008 bt */
    p3870744_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_3870744;
    /* @3869012 dup */
    /* @3869016 constant */
    /* @3869020 cmp */
    /* @3869024 bt */
    p3870760_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3870760;
    /* @3869028 dup */
    /* @3869032 constant */
    /* @3869036 cmp */
    /* @3869040 bt */
    p3870776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_3870776;
    /* @3869044 dup */
    /* @3869048 constant */
    /* @3869052 cmp */
    /* @3869056 bt */
    p3870792_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_3870792;
    /* @3869060 dup */
    /* @3869064 constant */
    /* @3869068 cmp */
    /* @3869072 bt */
    p3870808_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_3870808;
    /* @3869076 dup */
    /* @3869080 constant */
    /* @3869084 cmp */
    /* @3869088 bt */
    p3870824_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_3870824;
    /* @3869092 dup */
    /* @3869096 constant */
    /* @3869100 cmp */
    /* @3869104 bt */
    p3870840_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_3870840;
    /* @3869108 dup */
    /* @3869112 constant */
    /* @3869116 cmp */
    /* @3869120 bt */
    p3870856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_3870856;
    /* @3869124 dup */
    /* @3869128 constant */
    /* @3869132 cmp */
    /* @3869136 bt */
    p3870872_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_3870872;
    /* @3869140 dup */
    /* @3869144 constant */
    /* @3869148 cmp */
    /* @3869152 bt */
    p3870888_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_3870888;
    /* @3869156 dup */
    /* @3869160 constant */
    /* @3869164 cmp */
    /* @3869168 bt */
    p3870904_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_3870904;
    /* @3869172 dup */
    /* @3869176 constant */
    /* @3869180 cmp */
    /* @3869184 bt */
    p3870920_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_3870920;
    /* @3869188 dup */
    /* @3869192 constant */
    /* @3869196 cmp */
    /* @3869200 bt */
    p3870936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_3870936;
    /* @3869204 dup */
    /* @3869208 constant */
    /* @3869212 cmp */
    /* @3869216 bt */
    p3870952_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_3870952;
    /* @3869220 dup */
    /* @3869224 constant */
    /* @3869228 cmp */
    /* @3869232 bt */
    p3870968_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_3870968;
    /* @3869236 dup */
    /* @3869240 constant */
    /* @3869244 cmp */
    /* @3869248 bt */
    p3870984_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_3870984;
    /* @3869252 dup */
    /* @3869256 constant */
    /* @3869260 cmp */
    /* @3869264 bt */
    p3871000_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_3871000;
    /* @3869268 dup */
    /* @3869272 constant */
    /* @3869276 cmp */
    /* @3869280 bt */
    p3871016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_3871016;
    /* @3869284 dup */
    /* @3869288 constant */
    /* @3869292 cmp */
    /* @3869296 bt */
    p3871032_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_3871032;
    /* @3869300 dup */
    /* @3869304 constant */
    /* @3869308 cmp */
    /* @3869312 bt */
    p3871048_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_3871048;
    /* @3869316 dup */
    /* @3869320 constant */
    /* @3869324 cmp */
    /* @3869328 bt */
    p3871064_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_3871064;
    /* @3869332 dup */
    /* @3869336 constant */
    /* @3869340 cmp */
    /* @3869344 bt */
    p3871080_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_3871080;
    /* @3869348 dup */
    /* @3869352 constant */
    /* @3869356 cmp */
    /* @3869360 bt */
    p3871096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_3871096;
    /* @3869364 dup */
    /* @3869368 constant */
    /* @3869372 cmp */
    /* @3869376 bt */
    p3871112_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3871112;
    /* @3869380 dup */
    /* @3869384 constant */
    /* @3869388 cmp */
    /* @3869392 bt */
    p3871128_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(105)))) goto L_3871128;
    /* @3869396 dup */
    /* @3869400 constant */
    /* @3869404 cmp */
    /* @3869408 bt */
    p3871144_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(106)))) goto L_3871144;
    /* @3869412 dup */
    /* @3869416 constant */
    /* @3869420 cmp */
    /* @3869424 bt */
    p3871160_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(107)))) goto L_3871160;
    /* @3869428 dup */
    /* @3869432 constant */
    /* @3869436 cmp */
    /* @3869440 bt */
    p3871176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(108)))) goto L_3871176;
    /* @3869444 dup */
    /* @3869448 constant */
    /* @3869452 cmp */
    /* @3869456 bt */
    p3871192_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(109)))) goto L_3871192;
    /* @3869460 b */
    p3871208_0 = GM_READ(vm, -1, "room");
    goto L_3871208;
    L_3869464: ;
    /* @3869464 constant */
    /* @3869468 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869476 b */
    p3871208_0 = p3869464_0;
    goto L_3871208;
    L_3869480: ;
    /* @3869480 constant */
    /* @3869484 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869492 b */
    p3871208_0 = p3869480_0;
    goto L_3871208;
    L_3869496: ;
    /* @3869496 constant */
    /* @3869500 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869508 b */
    p3871208_0 = p3869496_0;
    goto L_3871208;
    L_3869512: ;
    /* @3869512 constant */
    /* @3869516 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869524 b */
    p3871208_0 = p3869512_0;
    goto L_3871208;
    L_3869528: ;
    /* @3869528 constant */
    /* @3869532 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869540 b */
    p3871208_0 = p3869528_0;
    goto L_3871208;
    L_3869544: ;
    /* @3869544 constant */
    /* @3869548 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869556 b */
    p3871208_0 = p3869544_0;
    goto L_3871208;
    L_3869560: ;
    /* @3869560 constant */
    /* @3869564 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869572 b */
    p3871208_0 = p3869560_0;
    goto L_3871208;
    L_3869576: ;
    /* @3869576 constant */
    /* @3869580 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869588 b */
    p3871208_0 = p3869576_0;
    goto L_3871208;
    L_3869592: ;
    /* @3869592 constant */
    /* @3869596 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869604 b */
    p3871208_0 = p3869592_0;
    goto L_3871208;
    L_3869608: ;
    /* @3869608 constant */
    /* @3869612 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(5));
    /* @3869620 b */
    p3871208_0 = p3869608_0;
    goto L_3871208;
    L_3869624: ;
    /* @3869624 constant */
    /* @3869628 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869636 b */
    p3871208_0 = p3869624_0;
    goto L_3871208;
    L_3869640: ;
    /* @3869640 constant */
    /* @3869644 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869652 b */
    p3871208_0 = p3869640_0;
    goto L_3871208;
    L_3869656: ;
    /* @3869656 constant */
    /* @3869660 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869668 b */
    p3871208_0 = p3869656_0;
    goto L_3871208;
    L_3869672: ;
    /* @3869672 constant */
    /* @3869676 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869684 b */
    p3871208_0 = p3869672_0;
    goto L_3871208;
    L_3869688: ;
    /* @3869688 constant */
    /* @3869692 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869700 b */
    p3871208_0 = p3869688_0;
    goto L_3871208;
    L_3869704: ;
    /* @3869704 constant */
    /* @3869708 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869716 b */
    p3871208_0 = p3869704_0;
    goto L_3871208;
    L_3869720: ;
    /* @3869720 constant */
    /* @3869724 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869732 b */
    p3871208_0 = p3869720_0;
    goto L_3871208;
    L_3869736: ;
    /* @3869736 constant */
    /* @3869740 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869748 b */
    p3871208_0 = p3869736_0;
    goto L_3871208;
    L_3869752: ;
    /* @3869752 constant */
    /* @3869756 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869764 b */
    p3871208_0 = p3869752_0;
    goto L_3871208;
    L_3869768: ;
    /* @3869768 constant */
    /* @3869772 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869780 b */
    p3871208_0 = p3869768_0;
    goto L_3871208;
    L_3869784: ;
    /* @3869784 constant */
    /* @3869788 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869796 b */
    p3871208_0 = p3869784_0;
    goto L_3871208;
    L_3869800: ;
    /* @3869800 constant */
    /* @3869804 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869812 b */
    p3871208_0 = p3869800_0;
    goto L_3871208;
    L_3869816: ;
    /* @3869816 constant */
    /* @3869820 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869828 b */
    p3871208_0 = p3869816_0;
    goto L_3871208;
    L_3869832: ;
    /* @3869832 constant */
    /* @3869836 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869844 b */
    p3871208_0 = p3869832_0;
    goto L_3871208;
    L_3869848: ;
    /* @3869848 constant */
    /* @3869852 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869860 b */
    p3871208_0 = p3869848_0;
    goto L_3871208;
    L_3869864: ;
    /* @3869864 constant */
    /* @3869868 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869876 b */
    p3871208_0 = p3869864_0;
    goto L_3871208;
    L_3869880: ;
    /* @3869880 constant */
    /* @3869884 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(8));
    /* @3869892 b */
    p3871208_0 = p3869880_0;
    goto L_3871208;
    L_3869896: ;
    /* @3869896 constant */
    /* @3869900 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869908 b */
    p3871208_0 = p3869896_0;
    goto L_3871208;
    L_3869912: ;
    /* @3869912 constant */
    /* @3869916 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869924 b */
    p3871208_0 = p3869912_0;
    goto L_3871208;
    L_3869928: ;
    /* @3869928 constant */
    /* @3869932 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869940 b */
    p3871208_0 = p3869928_0;
    goto L_3871208;
    L_3869944: ;
    /* @3869944 constant */
    /* @3869948 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869956 b */
    p3871208_0 = p3869944_0;
    goto L_3871208;
    L_3869960: ;
    /* @3869960 constant */
    /* @3869964 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869972 b */
    p3871208_0 = p3869960_0;
    goto L_3871208;
    L_3869976: ;
    /* @3869976 constant */
    /* @3869980 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3869988 b */
    p3871208_0 = p3869976_0;
    goto L_3871208;
    L_3869992: ;
    /* @3869992 constant */
    /* @3869996 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870004 b */
    p3871208_0 = p3869992_0;
    goto L_3871208;
    L_3870008: ;
    /* @3870008 constant */
    /* @3870012 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870020 b */
    p3871208_0 = p3870008_0;
    goto L_3871208;
    L_3870024: ;
    /* @3870024 constant */
    /* @3870028 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870036 b */
    p3871208_0 = p3870024_0;
    goto L_3871208;
    L_3870040: ;
    /* @3870040 constant */
    /* @3870044 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870052 b */
    p3871208_0 = p3870040_0;
    goto L_3871208;
    L_3870056: ;
    /* @3870056 constant */
    /* @3870060 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870068 b */
    p3871208_0 = p3870056_0;
    goto L_3871208;
    L_3870072: ;
    /* @3870072 constant */
    /* @3870076 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870084 b */
    p3871208_0 = p3870072_0;
    goto L_3871208;
    L_3870088: ;
    /* @3870088 constant */
    /* @3870092 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870100 b */
    p3871208_0 = p3870088_0;
    goto L_3871208;
    L_3870104: ;
    /* @3870104 constant */
    /* @3870108 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870116 b */
    p3871208_0 = p3870104_0;
    goto L_3871208;
    L_3870120: ;
    /* @3870120 constant */
    /* @3870124 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870132 b */
    p3871208_0 = p3870120_0;
    goto L_3871208;
    L_3870136: ;
    /* @3870136 constant */
    /* @3870140 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870148 b */
    p3871208_0 = p3870136_0;
    goto L_3871208;
    L_3870152: ;
    /* @3870152 constant */
    /* @3870156 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870164 b */
    p3871208_0 = p3870152_0;
    goto L_3871208;
    L_3870168: ;
    /* @3870168 constant */
    /* @3870172 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870180 b */
    p3871208_0 = p3870168_0;
    goto L_3871208;
    L_3870184: ;
    /* @3870184 constant */
    /* @3870188 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870196 b */
    p3871208_0 = p3870184_0;
    goto L_3871208;
    L_3870200: ;
    /* @3870200 constant */
    /* @3870204 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870212 b */
    p3871208_0 = p3870200_0;
    goto L_3871208;
    L_3870216: ;
    /* @3870216 constant */
    /* @3870220 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(11));
    /* @3870228 b */
    p3871208_0 = p3870216_0;
    goto L_3871208;
    L_3870232: ;
    /* @3870232 constant */
    /* @3870236 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870244 b */
    p3871208_0 = p3870232_0;
    goto L_3871208;
    L_3870248: ;
    /* @3870248 constant */
    /* @3870252 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870260 b */
    p3871208_0 = p3870248_0;
    goto L_3871208;
    L_3870264: ;
    /* @3870264 constant */
    /* @3870268 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870276 b */
    p3871208_0 = p3870264_0;
    goto L_3871208;
    L_3870280: ;
    /* @3870280 constant */
    /* @3870284 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870292 b */
    p3871208_0 = p3870280_0;
    goto L_3871208;
    L_3870296: ;
    /* @3870296 constant */
    /* @3870300 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870308 b */
    p3871208_0 = p3870296_0;
    goto L_3871208;
    L_3870312: ;
    /* @3870312 constant */
    /* @3870316 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870324 b */
    p3871208_0 = p3870312_0;
    goto L_3871208;
    L_3870328: ;
    /* @3870328 constant */
    /* @3870332 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870340 b */
    p3871208_0 = p3870328_0;
    goto L_3871208;
    L_3870344: ;
    /* @3870344 constant */
    /* @3870348 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870356 b */
    p3871208_0 = p3870344_0;
    goto L_3871208;
    L_3870360: ;
    /* @3870360 constant */
    /* @3870364 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870372 b */
    p3871208_0 = p3870360_0;
    goto L_3871208;
    L_3870376: ;
    /* @3870376 constant */
    /* @3870380 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870388 b */
    p3871208_0 = p3870376_0;
    goto L_3871208;
    L_3870392: ;
    /* @3870392 constant */
    /* @3870396 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870404 b */
    p3871208_0 = p3870392_0;
    goto L_3871208;
    L_3870408: ;
    /* @3870408 constant */
    /* @3870412 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870420 b */
    p3871208_0 = p3870408_0;
    goto L_3871208;
    L_3870424: ;
    /* @3870424 constant */
    /* @3870428 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870436 b */
    p3871208_0 = p3870424_0;
    goto L_3871208;
    L_3870440: ;
    /* @3870440 constant */
    /* @3870444 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870452 b */
    p3871208_0 = p3870440_0;
    goto L_3871208;
    L_3870456: ;
    /* @3870456 constant */
    /* @3870460 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870468 b */
    p3871208_0 = p3870456_0;
    goto L_3871208;
    L_3870472: ;
    /* @3870472 constant */
    /* @3870476 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(14));
    /* @3870484 b */
    p3871208_0 = p3870472_0;
    goto L_3871208;
    L_3870488: ;
    /* @3870488 constant */
    /* @3870492 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870500 b */
    p3871208_0 = p3870488_0;
    goto L_3871208;
    L_3870504: ;
    /* @3870504 constant */
    /* @3870508 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870516 b */
    p3871208_0 = p3870504_0;
    goto L_3871208;
    L_3870520: ;
    /* @3870520 constant */
    /* @3870524 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870532 b */
    p3871208_0 = p3870520_0;
    goto L_3871208;
    L_3870536: ;
    /* @3870536 constant */
    /* @3870540 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870548 b */
    p3871208_0 = p3870536_0;
    goto L_3871208;
    L_3870552: ;
    /* @3870552 constant */
    /* @3870556 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870564 b */
    p3871208_0 = p3870552_0;
    goto L_3871208;
    L_3870568: ;
    /* @3870568 constant */
    /* @3870572 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870580 b */
    p3871208_0 = p3870568_0;
    goto L_3871208;
    L_3870584: ;
    /* @3870584 constant */
    /* @3870588 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870596 b */
    p3871208_0 = p3870584_0;
    goto L_3871208;
    L_3870600: ;
    /* @3870600 constant */
    /* @3870604 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870612 b */
    p3871208_0 = p3870600_0;
    goto L_3871208;
    L_3870616: ;
    /* @3870616 constant */
    /* @3870620 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870628 b */
    p3871208_0 = p3870616_0;
    goto L_3871208;
    L_3870632: ;
    /* @3870632 constant */
    /* @3870636 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870644 b */
    p3871208_0 = p3870632_0;
    goto L_3871208;
    L_3870648: ;
    /* @3870648 constant */
    /* @3870652 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870660 b */
    p3871208_0 = p3870648_0;
    goto L_3871208;
    L_3870664: ;
    /* @3870664 constant */
    /* @3870668 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870676 b */
    p3871208_0 = p3870664_0;
    goto L_3871208;
    L_3870680: ;
    /* @3870680 constant */
    /* @3870684 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870692 b */
    p3871208_0 = p3870680_0;
    goto L_3871208;
    L_3870696: ;
    /* @3870696 constant */
    /* @3870700 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870708 b */
    p3871208_0 = p3870696_0;
    goto L_3871208;
    L_3870712: ;
    /* @3870712 constant */
    /* @3870716 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870724 b */
    p3871208_0 = p3870712_0;
    goto L_3871208;
    L_3870728: ;
    /* @3870728 constant */
    /* @3870732 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870740 b */
    p3871208_0 = p3870728_0;
    goto L_3871208;
    L_3870744: ;
    /* @3870744 constant */
    /* @3870748 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870756 b */
    p3871208_0 = p3870744_0;
    goto L_3871208;
    L_3870760: ;
    /* @3870760 constant */
    /* @3870764 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(17));
    /* @3870772 b */
    p3871208_0 = p3870760_0;
    goto L_3871208;
    L_3870776: ;
    /* @3870776 constant */
    /* @3870780 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870788 b */
    p3871208_0 = p3870776_0;
    goto L_3871208;
    L_3870792: ;
    /* @3870792 constant */
    /* @3870796 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870804 b */
    p3871208_0 = p3870792_0;
    goto L_3871208;
    L_3870808: ;
    /* @3870808 constant */
    /* @3870812 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870820 b */
    p3871208_0 = p3870808_0;
    goto L_3871208;
    L_3870824: ;
    /* @3870824 constant */
    /* @3870828 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870836 b */
    p3871208_0 = p3870824_0;
    goto L_3871208;
    L_3870840: ;
    /* @3870840 constant */
    /* @3870844 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870852 b */
    p3871208_0 = p3870840_0;
    goto L_3871208;
    L_3870856: ;
    /* @3870856 constant */
    /* @3870860 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870868 b */
    p3871208_0 = p3870856_0;
    goto L_3871208;
    L_3870872: ;
    /* @3870872 constant */
    /* @3870876 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870884 b */
    p3871208_0 = p3870872_0;
    goto L_3871208;
    L_3870888: ;
    /* @3870888 constant */
    /* @3870892 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870900 b */
    p3871208_0 = p3870888_0;
    goto L_3871208;
    L_3870904: ;
    /* @3870904 constant */
    /* @3870908 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870916 b */
    p3871208_0 = p3870904_0;
    goto L_3871208;
    L_3870920: ;
    /* @3870920 constant */
    /* @3870924 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870932 b */
    p3871208_0 = p3870920_0;
    goto L_3871208;
    L_3870936: ;
    /* @3870936 constant */
    /* @3870940 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870948 b */
    p3871208_0 = p3870936_0;
    goto L_3871208;
    L_3870952: ;
    /* @3870952 constant */
    /* @3870956 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870964 b */
    p3871208_0 = p3870952_0;
    goto L_3871208;
    L_3870968: ;
    /* @3870968 constant */
    /* @3870972 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870980 b */
    p3871208_0 = p3870968_0;
    goto L_3871208;
    L_3870984: ;
    /* @3870984 constant */
    /* @3870988 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3870996 b */
    p3871208_0 = p3870984_0;
    goto L_3871208;
    L_3871000: ;
    /* @3871000 constant */
    /* @3871004 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871012 b */
    p3871208_0 = p3871000_0;
    goto L_3871208;
    L_3871016: ;
    /* @3871016 constant */
    /* @3871020 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871028 b */
    p3871208_0 = p3871016_0;
    goto L_3871208;
    L_3871032: ;
    /* @3871032 constant */
    /* @3871036 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871044 b */
    p3871208_0 = p3871032_0;
    goto L_3871208;
    L_3871048: ;
    /* @3871048 constant */
    /* @3871052 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871060 b */
    p3871208_0 = p3871048_0;
    goto L_3871208;
    L_3871064: ;
    /* @3871064 constant */
    /* @3871068 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871076 b */
    p3871208_0 = p3871064_0;
    goto L_3871208;
    L_3871080: ;
    /* @3871080 constant */
    /* @3871084 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871092 b */
    p3871208_0 = p3871080_0;
    goto L_3871208;
    L_3871096: ;
    /* @3871096 constant */
    /* @3871100 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871108 b */
    p3871208_0 = p3871096_0;
    goto L_3871208;
    L_3871112: ;
    /* @3871112 constant */
    /* @3871116 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871124 b */
    p3871208_0 = p3871112_0;
    goto L_3871208;
    L_3871128: ;
    /* @3871128 constant */
    /* @3871132 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871140 b */
    p3871208_0 = p3871128_0;
    goto L_3871208;
    L_3871144: ;
    /* @3871144 constant */
    /* @3871148 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871156 b */
    p3871208_0 = p3871144_0;
    goto L_3871208;
    L_3871160: ;
    /* @3871160 constant */
    /* @3871164 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871172 b */
    p3871208_0 = p3871160_0;
    goto L_3871208;
    L_3871176: ;
    /* @3871176 constant */
    /* @3871180 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871188 b */
    p3871208_0 = p3871176_0;
    goto L_3871208;
    L_3871192: ;
    /* @3871192 constant */
    /* @3871196 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(20));
    /* @3871204 b */
    p3871208_0 = p3871192_0;
    goto L_3871208;
    L_3871208: ;
    /* @3871208 popz */
    L_3871212: ;
    return;
}
