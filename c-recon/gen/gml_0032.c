/* generated from CODE 32 (gml_Object_obj_boulder_Create_0), source start 3874728, end 3878372. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0032(GmVM* vm) {
    Val p3876560_0;
    Val p3876576_0;
    Val p3876592_0;
    Val p3876608_0;
    Val p3876624_0;
    Val p3876640_0;
    Val p3876656_0;
    Val p3876672_0;
    Val p3876688_0;
    Val p3876704_0;
    Val p3876720_0;
    Val p3876736_0;
    Val p3876752_0;
    Val p3876768_0;
    Val p3876784_0;
    Val p3876800_0;
    Val p3876816_0;
    Val p3876832_0;
    Val p3876848_0;
    Val p3876864_0;
    Val p3876880_0;
    Val p3876896_0;
    Val p3876912_0;
    Val p3876928_0;
    Val p3876944_0;
    Val p3876960_0;
    Val p3876976_0;
    Val p3876992_0;
    Val p3877008_0;
    Val p3877024_0;
    Val p3877040_0;
    Val p3877056_0;
    Val p3877072_0;
    Val p3877088_0;
    Val p3877104_0;
    Val p3877120_0;
    Val p3877136_0;
    Val p3877152_0;
    Val p3877168_0;
    Val p3877184_0;
    Val p3877200_0;
    Val p3877216_0;
    Val p3877232_0;
    Val p3877248_0;
    Val p3877264_0;
    Val p3877280_0;
    Val p3877296_0;
    Val p3877312_0;
    Val p3877328_0;
    Val p3877344_0;
    Val p3877360_0;
    Val p3877376_0;
    Val p3877392_0;
    Val p3877408_0;
    Val p3877424_0;
    Val p3877440_0;
    Val p3877456_0;
    Val p3877472_0;
    Val p3877488_0;
    Val p3877504_0;
    Val p3877520_0;
    Val p3877536_0;
    Val p3877552_0;
    Val p3877568_0;
    Val p3877584_0;
    Val p3877600_0;
    Val p3877616_0;
    Val p3877632_0;
    Val p3877648_0;
    Val p3877664_0;
    Val p3877680_0;
    Val p3877696_0;
    Val p3877712_0;
    Val p3877728_0;
    Val p3877744_0;
    Val p3877760_0;
    Val p3877776_0;
    Val p3877792_0;
    Val p3877808_0;
    Val p3877824_0;
    Val p3877840_0;
    Val p3877856_0;
    Val p3877872_0;
    Val p3877888_0;
    Val p3877904_0;
    Val p3877920_0;
    Val p3877936_0;
    Val p3877952_0;
    Val p3877968_0;
    Val p3877984_0;
    Val p3878000_0;
    Val p3878016_0;
    Val p3878032_0;
    Val p3878048_0;
    Val p3878064_0;
    Val p3878080_0;
    Val p3878096_0;
    Val p3878112_0;
    Val p3878128_0;
    Val p3878144_0;
    Val p3878160_0;
    Val p3878176_0;
    Val p3878192_0;
    Val p3878208_0;
    Val p3878224_0;
    Val p3878240_0;
    Val p3878256_0;
    Val p3878272_0;
    Val p3878288_0;
    Val p3878304_0;
    Val p3878320_0;
    Val p3878336_0;
    Val p3878352_0;
    Val p3878368_0;
    /* @3874728 constant */
    /* @3874732 store */
    GM_WRITE(vm, -1, "type", VAL(1));
    /* @3874740 load */
    /* @3874748 dup */
    /* @3874752 constant */
    /* @3874756 cmp */
    /* @3874760 bt */
    p3876560_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(0)))) goto L_3876560;
    /* @3874764 dup */
    /* @3874768 constant */
    /* @3874772 cmp */
    /* @3874776 bt */
    p3876576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_3876576;
    /* @3874780 dup */
    /* @3874784 constant */
    /* @3874788 cmp */
    /* @3874792 bt */
    p3876592_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_3876592;
    /* @3874796 dup */
    /* @3874800 constant */
    /* @3874804 cmp */
    /* @3874808 bt */
    p3876608_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_3876608;
    /* @3874812 dup */
    /* @3874816 constant */
    /* @3874820 cmp */
    /* @3874824 bt */
    p3876624_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_3876624;
    /* @3874828 dup */
    /* @3874832 constant */
    /* @3874836 cmp */
    /* @3874840 bt */
    p3876640_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_3876640;
    /* @3874844 dup */
    /* @3874848 constant */
    /* @3874852 cmp */
    /* @3874856 bt */
    p3876656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_3876656;
    /* @3874860 dup */
    /* @3874864 constant */
    /* @3874868 cmp */
    /* @3874872 bt */
    p3876672_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_3876672;
    /* @3874876 dup */
    /* @3874880 constant */
    /* @3874884 cmp */
    /* @3874888 bt */
    p3876688_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_3876688;
    /* @3874892 dup */
    /* @3874896 constant */
    /* @3874900 cmp */
    /* @3874904 bt */
    p3876704_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_3876704;
    /* @3874908 dup */
    /* @3874912 constant */
    /* @3874916 cmp */
    /* @3874920 bt */
    p3876720_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3876720;
    /* @3874924 dup */
    /* @3874928 constant */
    /* @3874932 cmp */
    /* @3874936 bt */
    p3876736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_3876736;
    /* @3874940 dup */
    /* @3874944 constant */
    /* @3874948 cmp */
    /* @3874952 bt */
    p3876752_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_3876752;
    /* @3874956 dup */
    /* @3874960 constant */
    /* @3874964 cmp */
    /* @3874968 bt */
    p3876768_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_3876768;
    /* @3874972 dup */
    /* @3874976 constant */
    /* @3874980 cmp */
    /* @3874984 bt */
    p3876784_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_3876784;
    /* @3874988 dup */
    /* @3874992 constant */
    /* @3874996 cmp */
    /* @3875000 bt */
    p3876800_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_3876800;
    /* @3875004 dup */
    /* @3875008 constant */
    /* @3875012 cmp */
    /* @3875016 bt */
    p3876816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_3876816;
    /* @3875020 dup */
    /* @3875024 constant */
    /* @3875028 cmp */
    /* @3875032 bt */
    p3876832_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_3876832;
    /* @3875036 dup */
    /* @3875040 constant */
    /* @3875044 cmp */
    /* @3875048 bt */
    p3876848_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_3876848;
    /* @3875052 dup */
    /* @3875056 constant */
    /* @3875060 cmp */
    /* @3875064 bt */
    p3876864_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_3876864;
    /* @3875068 dup */
    /* @3875072 constant */
    /* @3875076 cmp */
    /* @3875080 bt */
    p3876880_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_3876880;
    /* @3875084 dup */
    /* @3875088 constant */
    /* @3875092 cmp */
    /* @3875096 bt */
    p3876896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_3876896;
    /* @3875100 dup */
    /* @3875104 constant */
    /* @3875108 cmp */
    /* @3875112 bt */
    p3876912_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_3876912;
    /* @3875116 dup */
    /* @3875120 constant */
    /* @3875124 cmp */
    /* @3875128 bt */
    p3876928_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_3876928;
    /* @3875132 dup */
    /* @3875136 constant */
    /* @3875140 cmp */
    /* @3875144 bt */
    p3876944_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_3876944;
    /* @3875148 dup */
    /* @3875152 constant */
    /* @3875156 cmp */
    /* @3875160 bt */
    p3876960_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_3876960;
    /* @3875164 dup */
    /* @3875168 constant */
    /* @3875172 cmp */
    /* @3875176 bt */
    p3876976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_3876976;
    /* @3875180 dup */
    /* @3875184 constant */
    /* @3875188 cmp */
    /* @3875192 bt */
    p3876992_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3876992;
    /* @3875196 dup */
    /* @3875200 constant */
    /* @3875204 cmp */
    /* @3875208 bt */
    p3877008_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_3877008;
    /* @3875212 dup */
    /* @3875216 constant */
    /* @3875220 cmp */
    /* @3875224 bt */
    p3877024_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_3877024;
    /* @3875228 dup */
    /* @3875232 constant */
    /* @3875236 cmp */
    /* @3875240 bt */
    p3877040_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_3877040;
    /* @3875244 dup */
    /* @3875248 constant */
    /* @3875252 cmp */
    /* @3875256 bt */
    p3877056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_3877056;
    /* @3875260 dup */
    /* @3875264 constant */
    /* @3875268 cmp */
    /* @3875272 bt */
    p3877072_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_3877072;
    /* @3875276 dup */
    /* @3875280 constant */
    /* @3875284 cmp */
    /* @3875288 bt */
    p3877088_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_3877088;
    /* @3875292 dup */
    /* @3875296 constant */
    /* @3875300 cmp */
    /* @3875304 bt */
    p3877104_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_3877104;
    /* @3875308 dup */
    /* @3875312 constant */
    /* @3875316 cmp */
    /* @3875320 bt */
    p3877120_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_3877120;
    /* @3875324 dup */
    /* @3875328 constant */
    /* @3875332 cmp */
    /* @3875336 bt */
    p3877136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_3877136;
    /* @3875340 dup */
    /* @3875344 constant */
    /* @3875348 cmp */
    /* @3875352 bt */
    p3877152_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_3877152;
    /* @3875356 dup */
    /* @3875360 constant */
    /* @3875364 cmp */
    /* @3875368 bt */
    p3877168_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_3877168;
    /* @3875372 dup */
    /* @3875376 constant */
    /* @3875380 cmp */
    /* @3875384 bt */
    p3877184_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_3877184;
    /* @3875388 dup */
    /* @3875392 constant */
    /* @3875396 cmp */
    /* @3875400 bt */
    p3877200_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_3877200;
    /* @3875404 dup */
    /* @3875408 constant */
    /* @3875412 cmp */
    /* @3875416 bt */
    p3877216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_3877216;
    /* @3875420 dup */
    /* @3875424 constant */
    /* @3875428 cmp */
    /* @3875432 bt */
    p3877232_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_3877232;
    /* @3875436 dup */
    /* @3875440 constant */
    /* @3875444 cmp */
    /* @3875448 bt */
    p3877248_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_3877248;
    /* @3875452 dup */
    /* @3875456 constant */
    /* @3875460 cmp */
    /* @3875464 bt */
    p3877264_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_3877264;
    /* @3875468 dup */
    /* @3875472 constant */
    /* @3875476 cmp */
    /* @3875480 bt */
    p3877280_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_3877280;
    /* @3875484 dup */
    /* @3875488 constant */
    /* @3875492 cmp */
    /* @3875496 bt */
    p3877296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_3877296;
    /* @3875500 dup */
    /* @3875504 constant */
    /* @3875508 cmp */
    /* @3875512 bt */
    p3877312_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_3877312;
    /* @3875516 dup */
    /* @3875520 constant */
    /* @3875524 cmp */
    /* @3875528 bt */
    p3877328_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3877328;
    /* @3875532 dup */
    /* @3875536 constant */
    /* @3875540 cmp */
    /* @3875544 bt */
    p3877344_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_3877344;
    /* @3875548 dup */
    /* @3875552 constant */
    /* @3875556 cmp */
    /* @3875560 bt */
    p3877360_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_3877360;
    /* @3875564 dup */
    /* @3875568 constant */
    /* @3875572 cmp */
    /* @3875576 bt */
    p3877376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_3877376;
    /* @3875580 dup */
    /* @3875584 constant */
    /* @3875588 cmp */
    /* @3875592 bt */
    p3877392_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_3877392;
    /* @3875596 dup */
    /* @3875600 constant */
    /* @3875604 cmp */
    /* @3875608 bt */
    p3877408_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_3877408;
    /* @3875612 dup */
    /* @3875616 constant */
    /* @3875620 cmp */
    /* @3875624 bt */
    p3877424_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_3877424;
    /* @3875628 dup */
    /* @3875632 constant */
    /* @3875636 cmp */
    /* @3875640 bt */
    p3877440_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_3877440;
    /* @3875644 dup */
    /* @3875648 constant */
    /* @3875652 cmp */
    /* @3875656 bt */
    p3877456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_3877456;
    /* @3875660 dup */
    /* @3875664 constant */
    /* @3875668 cmp */
    /* @3875672 bt */
    p3877472_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_3877472;
    /* @3875676 dup */
    /* @3875680 constant */
    /* @3875684 cmp */
    /* @3875688 bt */
    p3877488_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_3877488;
    /* @3875692 dup */
    /* @3875696 constant */
    /* @3875700 cmp */
    /* @3875704 bt */
    p3877504_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_3877504;
    /* @3875708 dup */
    /* @3875712 constant */
    /* @3875716 cmp */
    /* @3875720 bt */
    p3877520_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_3877520;
    /* @3875724 dup */
    /* @3875728 constant */
    /* @3875732 cmp */
    /* @3875736 bt */
    p3877536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_3877536;
    /* @3875740 dup */
    /* @3875744 constant */
    /* @3875748 cmp */
    /* @3875752 bt */
    p3877552_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_3877552;
    /* @3875756 dup */
    /* @3875760 constant */
    /* @3875764 cmp */
    /* @3875768 bt */
    p3877568_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_3877568;
    /* @3875772 dup */
    /* @3875776 constant */
    /* @3875780 cmp */
    /* @3875784 bt */
    p3877584_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3877584;
    /* @3875788 dup */
    /* @3875792 constant */
    /* @3875796 cmp */
    /* @3875800 bt */
    p3877600_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_3877600;
    /* @3875804 dup */
    /* @3875808 constant */
    /* @3875812 cmp */
    /* @3875816 bt */
    p3877616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_3877616;
    /* @3875820 dup */
    /* @3875824 constant */
    /* @3875828 cmp */
    /* @3875832 bt */
    p3877632_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_3877632;
    /* @3875836 dup */
    /* @3875840 constant */
    /* @3875844 cmp */
    /* @3875848 bt */
    p3877648_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_3877648;
    /* @3875852 dup */
    /* @3875856 constant */
    /* @3875860 cmp */
    /* @3875864 bt */
    p3877664_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_3877664;
    /* @3875868 dup */
    /* @3875872 constant */
    /* @3875876 cmp */
    /* @3875880 bt */
    p3877680_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_3877680;
    /* @3875884 dup */
    /* @3875888 constant */
    /* @3875892 cmp */
    /* @3875896 bt */
    p3877696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_3877696;
    /* @3875900 dup */
    /* @3875904 constant */
    /* @3875908 cmp */
    /* @3875912 bt */
    p3877712_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_3877712;
    /* @3875916 dup */
    /* @3875920 constant */
    /* @3875924 cmp */
    /* @3875928 bt */
    p3877728_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_3877728;
    /* @3875932 dup */
    /* @3875936 constant */
    /* @3875940 cmp */
    /* @3875944 bt */
    p3877744_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_3877744;
    /* @3875948 dup */
    /* @3875952 constant */
    /* @3875956 cmp */
    /* @3875960 bt */
    p3877760_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_3877760;
    /* @3875964 dup */
    /* @3875968 constant */
    /* @3875972 cmp */
    /* @3875976 bt */
    p3877776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_3877776;
    /* @3875980 dup */
    /* @3875984 constant */
    /* @3875988 cmp */
    /* @3875992 bt */
    p3877792_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_3877792;
    /* @3875996 dup */
    /* @3876000 constant */
    /* @3876004 cmp */
    /* @3876008 bt */
    p3877808_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_3877808;
    /* @3876012 dup */
    /* @3876016 constant */
    /* @3876020 cmp */
    /* @3876024 bt */
    p3877824_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_3877824;
    /* @3876028 dup */
    /* @3876032 constant */
    /* @3876036 cmp */
    /* @3876040 bt */
    p3877840_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_3877840;
    /* @3876044 dup */
    /* @3876048 constant */
    /* @3876052 cmp */
    /* @3876056 bt */
    p3877856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_3877856;
    /* @3876060 dup */
    /* @3876064 constant */
    /* @3876068 cmp */
    /* @3876072 bt */
    p3877872_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3877872;
    /* @3876076 dup */
    /* @3876080 constant */
    /* @3876084 cmp */
    /* @3876088 bt */
    p3877888_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_3877888;
    /* @3876092 dup */
    /* @3876096 constant */
    /* @3876100 cmp */
    /* @3876104 bt */
    p3877904_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_3877904;
    /* @3876108 dup */
    /* @3876112 constant */
    /* @3876116 cmp */
    /* @3876120 bt */
    p3877920_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_3877920;
    /* @3876124 dup */
    /* @3876128 constant */
    /* @3876132 cmp */
    /* @3876136 bt */
    p3877936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_3877936;
    /* @3876140 dup */
    /* @3876144 constant */
    /* @3876148 cmp */
    /* @3876152 bt */
    p3877952_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_3877952;
    /* @3876156 dup */
    /* @3876160 constant */
    /* @3876164 cmp */
    /* @3876168 bt */
    p3877968_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_3877968;
    /* @3876172 dup */
    /* @3876176 constant */
    /* @3876180 cmp */
    /* @3876184 bt */
    p3877984_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_3877984;
    /* @3876188 dup */
    /* @3876192 constant */
    /* @3876196 cmp */
    /* @3876200 bt */
    p3878000_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_3878000;
    /* @3876204 dup */
    /* @3876208 constant */
    /* @3876212 cmp */
    /* @3876216 bt */
    p3878016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_3878016;
    /* @3876220 dup */
    /* @3876224 constant */
    /* @3876228 cmp */
    /* @3876232 bt */
    p3878032_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_3878032;
    /* @3876236 dup */
    /* @3876240 constant */
    /* @3876244 cmp */
    /* @3876248 bt */
    p3878048_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_3878048;
    /* @3876252 dup */
    /* @3876256 constant */
    /* @3876260 cmp */
    /* @3876264 bt */
    p3878064_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_3878064;
    /* @3876268 dup */
    /* @3876272 constant */
    /* @3876276 cmp */
    /* @3876280 bt */
    p3878080_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_3878080;
    /* @3876284 dup */
    /* @3876288 constant */
    /* @3876292 cmp */
    /* @3876296 bt */
    p3878096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_3878096;
    /* @3876300 dup */
    /* @3876304 constant */
    /* @3876308 cmp */
    /* @3876312 bt */
    p3878112_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_3878112;
    /* @3876316 dup */
    /* @3876320 constant */
    /* @3876324 cmp */
    /* @3876328 bt */
    p3878128_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_3878128;
    /* @3876332 dup */
    /* @3876336 constant */
    /* @3876340 cmp */
    /* @3876344 bt */
    p3878144_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_3878144;
    /* @3876348 dup */
    /* @3876352 constant */
    /* @3876356 cmp */
    /* @3876360 bt */
    p3878160_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_3878160;
    /* @3876364 dup */
    /* @3876368 constant */
    /* @3876372 cmp */
    /* @3876376 bt */
    p3878176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_3878176;
    /* @3876380 dup */
    /* @3876384 constant */
    /* @3876388 cmp */
    /* @3876392 bt */
    p3878192_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_3878192;
    /* @3876396 dup */
    /* @3876400 constant */
    /* @3876404 cmp */
    /* @3876408 bt */
    p3878208_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_3878208;
    /* @3876412 dup */
    /* @3876416 constant */
    /* @3876420 cmp */
    /* @3876424 bt */
    p3878224_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3878224;
    /* @3876428 dup */
    /* @3876432 constant */
    /* @3876436 cmp */
    /* @3876440 bt */
    p3878240_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(105)))) goto L_3878240;
    /* @3876444 dup */
    /* @3876448 constant */
    /* @3876452 cmp */
    /* @3876456 bt */
    p3878256_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(106)))) goto L_3878256;
    /* @3876460 dup */
    /* @3876464 constant */
    /* @3876468 cmp */
    /* @3876472 bt */
    p3878272_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(107)))) goto L_3878272;
    /* @3876476 dup */
    /* @3876480 constant */
    /* @3876484 cmp */
    /* @3876488 bt */
    p3878288_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(108)))) goto L_3878288;
    /* @3876492 dup */
    /* @3876496 constant */
    /* @3876500 cmp */
    /* @3876504 bt */
    p3878304_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(109)))) goto L_3878304;
    /* @3876508 dup */
    /* @3876512 constant */
    /* @3876516 cmp */
    /* @3876520 bt */
    p3878320_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(111)))) goto L_3878320;
    /* @3876524 dup */
    /* @3876528 constant */
    /* @3876532 cmp */
    /* @3876536 bt */
    p3878336_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(112)))) goto L_3878336;
    /* @3876540 dup */
    /* @3876544 constant */
    /* @3876548 cmp */
    /* @3876552 bt */
    p3878352_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_3878352;
    /* @3876556 b */
    p3878368_0 = GM_READ(vm, -1, "room");
    goto L_3878368;
    L_3876560: ;
    /* @3876560 constant */
    /* @3876564 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876572 b */
    p3878368_0 = p3876560_0;
    goto L_3878368;
    L_3876576: ;
    /* @3876576 constant */
    /* @3876580 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876588 b */
    p3878368_0 = p3876576_0;
    goto L_3878368;
    L_3876592: ;
    /* @3876592 constant */
    /* @3876596 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876604 b */
    p3878368_0 = p3876592_0;
    goto L_3878368;
    L_3876608: ;
    /* @3876608 constant */
    /* @3876612 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876620 b */
    p3878368_0 = p3876608_0;
    goto L_3878368;
    L_3876624: ;
    /* @3876624 constant */
    /* @3876628 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876636 b */
    p3878368_0 = p3876624_0;
    goto L_3878368;
    L_3876640: ;
    /* @3876640 constant */
    /* @3876644 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876652 b */
    p3878368_0 = p3876640_0;
    goto L_3878368;
    L_3876656: ;
    /* @3876656 constant */
    /* @3876660 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876668 b */
    p3878368_0 = p3876656_0;
    goto L_3878368;
    L_3876672: ;
    /* @3876672 constant */
    /* @3876676 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876684 b */
    p3878368_0 = p3876672_0;
    goto L_3878368;
    L_3876688: ;
    /* @3876688 constant */
    /* @3876692 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876700 b */
    p3878368_0 = p3876688_0;
    goto L_3878368;
    L_3876704: ;
    /* @3876704 constant */
    /* @3876708 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876716 b */
    p3878368_0 = p3876704_0;
    goto L_3878368;
    L_3876720: ;
    /* @3876720 constant */
    /* @3876724 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3876732 b */
    p3878368_0 = p3876720_0;
    goto L_3878368;
    L_3876736: ;
    /* @3876736 constant */
    /* @3876740 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876748 b */
    p3878368_0 = p3876736_0;
    goto L_3878368;
    L_3876752: ;
    /* @3876752 constant */
    /* @3876756 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876764 b */
    p3878368_0 = p3876752_0;
    goto L_3878368;
    L_3876768: ;
    /* @3876768 constant */
    /* @3876772 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876780 b */
    p3878368_0 = p3876768_0;
    goto L_3878368;
    L_3876784: ;
    /* @3876784 constant */
    /* @3876788 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876796 b */
    p3878368_0 = p3876784_0;
    goto L_3878368;
    L_3876800: ;
    /* @3876800 constant */
    /* @3876804 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876812 b */
    p3878368_0 = p3876800_0;
    goto L_3878368;
    L_3876816: ;
    /* @3876816 constant */
    /* @3876820 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876828 b */
    p3878368_0 = p3876816_0;
    goto L_3878368;
    L_3876832: ;
    /* @3876832 constant */
    /* @3876836 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876844 b */
    p3878368_0 = p3876832_0;
    goto L_3878368;
    L_3876848: ;
    /* @3876848 constant */
    /* @3876852 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876860 b */
    p3878368_0 = p3876848_0;
    goto L_3878368;
    L_3876864: ;
    /* @3876864 constant */
    /* @3876868 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876876 b */
    p3878368_0 = p3876864_0;
    goto L_3878368;
    L_3876880: ;
    /* @3876880 constant */
    /* @3876884 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876892 b */
    p3878368_0 = p3876880_0;
    goto L_3878368;
    L_3876896: ;
    /* @3876896 constant */
    /* @3876900 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876908 b */
    p3878368_0 = p3876896_0;
    goto L_3878368;
    L_3876912: ;
    /* @3876912 constant */
    /* @3876916 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876924 b */
    p3878368_0 = p3876912_0;
    goto L_3878368;
    L_3876928: ;
    /* @3876928 constant */
    /* @3876932 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876940 b */
    p3878368_0 = p3876928_0;
    goto L_3878368;
    L_3876944: ;
    /* @3876944 constant */
    /* @3876948 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876956 b */
    p3878368_0 = p3876944_0;
    goto L_3878368;
    L_3876960: ;
    /* @3876960 constant */
    /* @3876964 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876972 b */
    p3878368_0 = p3876960_0;
    goto L_3878368;
    L_3876976: ;
    /* @3876976 constant */
    /* @3876980 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3876988 b */
    p3878368_0 = p3876976_0;
    goto L_3878368;
    L_3876992: ;
    /* @3876992 constant */
    /* @3876996 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(10));
    /* @3877004 b */
    p3878368_0 = p3876992_0;
    goto L_3878368;
    L_3877008: ;
    /* @3877008 constant */
    /* @3877012 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877020 b */
    p3878368_0 = p3877008_0;
    goto L_3878368;
    L_3877024: ;
    /* @3877024 constant */
    /* @3877028 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877036 b */
    p3878368_0 = p3877024_0;
    goto L_3878368;
    L_3877040: ;
    /* @3877040 constant */
    /* @3877044 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877052 b */
    p3878368_0 = p3877040_0;
    goto L_3878368;
    L_3877056: ;
    /* @3877056 constant */
    /* @3877060 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877068 b */
    p3878368_0 = p3877056_0;
    goto L_3878368;
    L_3877072: ;
    /* @3877072 constant */
    /* @3877076 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877084 b */
    p3878368_0 = p3877072_0;
    goto L_3878368;
    L_3877088: ;
    /* @3877088 constant */
    /* @3877092 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877100 b */
    p3878368_0 = p3877088_0;
    goto L_3878368;
    L_3877104: ;
    /* @3877104 constant */
    /* @3877108 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877116 b */
    p3878368_0 = p3877104_0;
    goto L_3878368;
    L_3877120: ;
    /* @3877120 constant */
    /* @3877124 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877132 b */
    p3878368_0 = p3877120_0;
    goto L_3878368;
    L_3877136: ;
    /* @3877136 constant */
    /* @3877140 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877148 b */
    p3878368_0 = p3877136_0;
    goto L_3878368;
    L_3877152: ;
    /* @3877152 constant */
    /* @3877156 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877164 b */
    p3878368_0 = p3877152_0;
    goto L_3878368;
    L_3877168: ;
    /* @3877168 constant */
    /* @3877172 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877180 b */
    p3878368_0 = p3877168_0;
    goto L_3878368;
    L_3877184: ;
    /* @3877184 constant */
    /* @3877188 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877196 b */
    p3878368_0 = p3877184_0;
    goto L_3878368;
    L_3877200: ;
    /* @3877200 constant */
    /* @3877204 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877212 b */
    p3878368_0 = p3877200_0;
    goto L_3878368;
    L_3877216: ;
    /* @3877216 constant */
    /* @3877220 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877228 b */
    p3878368_0 = p3877216_0;
    goto L_3878368;
    L_3877232: ;
    /* @3877232 constant */
    /* @3877236 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877244 b */
    p3878368_0 = p3877232_0;
    goto L_3878368;
    L_3877248: ;
    /* @3877248 constant */
    /* @3877252 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877260 b */
    p3878368_0 = p3877248_0;
    goto L_3878368;
    L_3877264: ;
    /* @3877264 constant */
    /* @3877268 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877276 b */
    p3878368_0 = p3877264_0;
    goto L_3878368;
    L_3877280: ;
    /* @3877280 constant */
    /* @3877284 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877292 b */
    p3878368_0 = p3877280_0;
    goto L_3878368;
    L_3877296: ;
    /* @3877296 constant */
    /* @3877300 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877308 b */
    p3878368_0 = p3877296_0;
    goto L_3878368;
    L_3877312: ;
    /* @3877312 constant */
    /* @3877316 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877324 b */
    p3878368_0 = p3877312_0;
    goto L_3878368;
    L_3877328: ;
    /* @3877328 constant */
    /* @3877332 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(13));
    /* @3877340 b */
    p3878368_0 = p3877328_0;
    goto L_3878368;
    L_3877344: ;
    /* @3877344 constant */
    /* @3877348 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877356 b */
    p3878368_0 = p3877344_0;
    goto L_3878368;
    L_3877360: ;
    /* @3877360 constant */
    /* @3877364 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877372 b */
    p3878368_0 = p3877360_0;
    goto L_3878368;
    L_3877376: ;
    /* @3877376 constant */
    /* @3877380 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877388 b */
    p3878368_0 = p3877376_0;
    goto L_3878368;
    L_3877392: ;
    /* @3877392 constant */
    /* @3877396 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877404 b */
    p3878368_0 = p3877392_0;
    goto L_3878368;
    L_3877408: ;
    /* @3877408 constant */
    /* @3877412 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877420 b */
    p3878368_0 = p3877408_0;
    goto L_3878368;
    L_3877424: ;
    /* @3877424 constant */
    /* @3877428 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877436 b */
    p3878368_0 = p3877424_0;
    goto L_3878368;
    L_3877440: ;
    /* @3877440 constant */
    /* @3877444 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877452 b */
    p3878368_0 = p3877440_0;
    goto L_3878368;
    L_3877456: ;
    /* @3877456 constant */
    /* @3877460 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877468 b */
    p3878368_0 = p3877456_0;
    goto L_3878368;
    L_3877472: ;
    /* @3877472 constant */
    /* @3877476 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877484 b */
    p3878368_0 = p3877472_0;
    goto L_3878368;
    L_3877488: ;
    /* @3877488 constant */
    /* @3877492 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877500 b */
    p3878368_0 = p3877488_0;
    goto L_3878368;
    L_3877504: ;
    /* @3877504 constant */
    /* @3877508 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877516 b */
    p3878368_0 = p3877504_0;
    goto L_3878368;
    L_3877520: ;
    /* @3877520 constant */
    /* @3877524 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877532 b */
    p3878368_0 = p3877520_0;
    goto L_3878368;
    L_3877536: ;
    /* @3877536 constant */
    /* @3877540 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877548 b */
    p3878368_0 = p3877536_0;
    goto L_3878368;
    L_3877552: ;
    /* @3877552 constant */
    /* @3877556 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877564 b */
    p3878368_0 = p3877552_0;
    goto L_3878368;
    L_3877568: ;
    /* @3877568 constant */
    /* @3877572 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877580 b */
    p3878368_0 = p3877568_0;
    goto L_3878368;
    L_3877584: ;
    /* @3877584 constant */
    /* @3877588 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(16));
    /* @3877596 b */
    p3878368_0 = p3877584_0;
    goto L_3878368;
    L_3877600: ;
    /* @3877600 constant */
    /* @3877604 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877612 b */
    p3878368_0 = p3877600_0;
    goto L_3878368;
    L_3877616: ;
    /* @3877616 constant */
    /* @3877620 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877628 b */
    p3878368_0 = p3877616_0;
    goto L_3878368;
    L_3877632: ;
    /* @3877632 constant */
    /* @3877636 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877644 b */
    p3878368_0 = p3877632_0;
    goto L_3878368;
    L_3877648: ;
    /* @3877648 constant */
    /* @3877652 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877660 b */
    p3878368_0 = p3877648_0;
    goto L_3878368;
    L_3877664: ;
    /* @3877664 constant */
    /* @3877668 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877676 b */
    p3878368_0 = p3877664_0;
    goto L_3878368;
    L_3877680: ;
    /* @3877680 constant */
    /* @3877684 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877692 b */
    p3878368_0 = p3877680_0;
    goto L_3878368;
    L_3877696: ;
    /* @3877696 constant */
    /* @3877700 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877708 b */
    p3878368_0 = p3877696_0;
    goto L_3878368;
    L_3877712: ;
    /* @3877712 constant */
    /* @3877716 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877724 b */
    p3878368_0 = p3877712_0;
    goto L_3878368;
    L_3877728: ;
    /* @3877728 constant */
    /* @3877732 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877740 b */
    p3878368_0 = p3877728_0;
    goto L_3878368;
    L_3877744: ;
    /* @3877744 constant */
    /* @3877748 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877756 b */
    p3878368_0 = p3877744_0;
    goto L_3878368;
    L_3877760: ;
    /* @3877760 constant */
    /* @3877764 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877772 b */
    p3878368_0 = p3877760_0;
    goto L_3878368;
    L_3877776: ;
    /* @3877776 constant */
    /* @3877780 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877788 b */
    p3878368_0 = p3877776_0;
    goto L_3878368;
    L_3877792: ;
    /* @3877792 constant */
    /* @3877796 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877804 b */
    p3878368_0 = p3877792_0;
    goto L_3878368;
    L_3877808: ;
    /* @3877808 constant */
    /* @3877812 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877820 b */
    p3878368_0 = p3877808_0;
    goto L_3878368;
    L_3877824: ;
    /* @3877824 constant */
    /* @3877828 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877836 b */
    p3878368_0 = p3877824_0;
    goto L_3878368;
    L_3877840: ;
    /* @3877840 constant */
    /* @3877844 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877852 b */
    p3878368_0 = p3877840_0;
    goto L_3878368;
    L_3877856: ;
    /* @3877856 constant */
    /* @3877860 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877868 b */
    p3878368_0 = p3877856_0;
    goto L_3878368;
    L_3877872: ;
    /* @3877872 constant */
    /* @3877876 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(19));
    /* @3877884 b */
    p3878368_0 = p3877872_0;
    goto L_3878368;
    L_3877888: ;
    /* @3877888 constant */
    /* @3877892 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877900 b */
    p3878368_0 = p3877888_0;
    goto L_3878368;
    L_3877904: ;
    /* @3877904 constant */
    /* @3877908 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877916 b */
    p3878368_0 = p3877904_0;
    goto L_3878368;
    L_3877920: ;
    /* @3877920 constant */
    /* @3877924 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877932 b */
    p3878368_0 = p3877920_0;
    goto L_3878368;
    L_3877936: ;
    /* @3877936 constant */
    /* @3877940 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877948 b */
    p3878368_0 = p3877936_0;
    goto L_3878368;
    L_3877952: ;
    /* @3877952 constant */
    /* @3877956 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877964 b */
    p3878368_0 = p3877952_0;
    goto L_3878368;
    L_3877968: ;
    /* @3877968 constant */
    /* @3877972 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877980 b */
    p3878368_0 = p3877968_0;
    goto L_3878368;
    L_3877984: ;
    /* @3877984 constant */
    /* @3877988 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3877996 b */
    p3878368_0 = p3877984_0;
    goto L_3878368;
    L_3878000: ;
    /* @3878000 constant */
    /* @3878004 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878012 b */
    p3878368_0 = p3878000_0;
    goto L_3878368;
    L_3878016: ;
    /* @3878016 constant */
    /* @3878020 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878028 b */
    p3878368_0 = p3878016_0;
    goto L_3878368;
    L_3878032: ;
    /* @3878032 constant */
    /* @3878036 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878044 b */
    p3878368_0 = p3878032_0;
    goto L_3878368;
    L_3878048: ;
    /* @3878048 constant */
    /* @3878052 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878060 b */
    p3878368_0 = p3878048_0;
    goto L_3878368;
    L_3878064: ;
    /* @3878064 constant */
    /* @3878068 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878076 b */
    p3878368_0 = p3878064_0;
    goto L_3878368;
    L_3878080: ;
    /* @3878080 constant */
    /* @3878084 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878092 b */
    p3878368_0 = p3878080_0;
    goto L_3878368;
    L_3878096: ;
    /* @3878096 constant */
    /* @3878100 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878108 b */
    p3878368_0 = p3878096_0;
    goto L_3878368;
    L_3878112: ;
    /* @3878112 constant */
    /* @3878116 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878124 b */
    p3878368_0 = p3878112_0;
    goto L_3878368;
    L_3878128: ;
    /* @3878128 constant */
    /* @3878132 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878140 b */
    p3878368_0 = p3878128_0;
    goto L_3878368;
    L_3878144: ;
    /* @3878144 constant */
    /* @3878148 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878156 b */
    p3878368_0 = p3878144_0;
    goto L_3878368;
    L_3878160: ;
    /* @3878160 constant */
    /* @3878164 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878172 b */
    p3878368_0 = p3878160_0;
    goto L_3878368;
    L_3878176: ;
    /* @3878176 constant */
    /* @3878180 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878188 b */
    p3878368_0 = p3878176_0;
    goto L_3878368;
    L_3878192: ;
    /* @3878192 constant */
    /* @3878196 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878204 b */
    p3878368_0 = p3878192_0;
    goto L_3878368;
    L_3878208: ;
    /* @3878208 constant */
    /* @3878212 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878220 b */
    p3878368_0 = p3878208_0;
    goto L_3878368;
    L_3878224: ;
    /* @3878224 constant */
    /* @3878228 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878236 b */
    p3878368_0 = p3878224_0;
    goto L_3878368;
    L_3878240: ;
    /* @3878240 constant */
    /* @3878244 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878252 b */
    p3878368_0 = p3878240_0;
    goto L_3878368;
    L_3878256: ;
    /* @3878256 constant */
    /* @3878260 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878268 b */
    p3878368_0 = p3878256_0;
    goto L_3878368;
    L_3878272: ;
    /* @3878272 constant */
    /* @3878276 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878284 b */
    p3878368_0 = p3878272_0;
    goto L_3878368;
    L_3878288: ;
    /* @3878288 constant */
    /* @3878292 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878300 b */
    p3878368_0 = p3878288_0;
    goto L_3878368;
    L_3878304: ;
    /* @3878304 constant */
    /* @3878308 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(22));
    /* @3878316 b */
    p3878368_0 = p3878304_0;
    goto L_3878368;
    L_3878320: ;
    /* @3878320 constant */
    /* @3878324 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3878332 b */
    p3878368_0 = p3878320_0;
    goto L_3878368;
    L_3878336: ;
    /* @3878336 constant */
    /* @3878340 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3878348 b */
    p3878368_0 = p3878336_0;
    goto L_3878368;
    L_3878352: ;
    /* @3878352 constant */
    /* @3878356 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(7));
    /* @3878364 b */
    p3878368_0 = p3878352_0;
    goto L_3878368;
    L_3878368: ;
    /* @3878368 popz */
    L_3878372: ;
    return;
}
