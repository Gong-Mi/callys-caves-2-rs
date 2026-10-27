/* generated from CODE 31 (gml_Object_obj_wall_2_Create_0), source start 3871212, end 3874728. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0031(GmVM* vm) {
    Val p3872980_0;
    Val p3872996_0;
    Val p3873012_0;
    Val p3873028_0;
    Val p3873044_0;
    Val p3873060_0;
    Val p3873076_0;
    Val p3873092_0;
    Val p3873108_0;
    Val p3873124_0;
    Val p3873140_0;
    Val p3873156_0;
    Val p3873172_0;
    Val p3873188_0;
    Val p3873204_0;
    Val p3873220_0;
    Val p3873236_0;
    Val p3873252_0;
    Val p3873268_0;
    Val p3873284_0;
    Val p3873300_0;
    Val p3873316_0;
    Val p3873332_0;
    Val p3873348_0;
    Val p3873364_0;
    Val p3873380_0;
    Val p3873396_0;
    Val p3873412_0;
    Val p3873428_0;
    Val p3873444_0;
    Val p3873460_0;
    Val p3873476_0;
    Val p3873492_0;
    Val p3873508_0;
    Val p3873524_0;
    Val p3873540_0;
    Val p3873556_0;
    Val p3873572_0;
    Val p3873588_0;
    Val p3873604_0;
    Val p3873620_0;
    Val p3873636_0;
    Val p3873652_0;
    Val p3873668_0;
    Val p3873684_0;
    Val p3873700_0;
    Val p3873716_0;
    Val p3873732_0;
    Val p3873748_0;
    Val p3873764_0;
    Val p3873780_0;
    Val p3873796_0;
    Val p3873812_0;
    Val p3873828_0;
    Val p3873844_0;
    Val p3873860_0;
    Val p3873876_0;
    Val p3873892_0;
    Val p3873908_0;
    Val p3873924_0;
    Val p3873940_0;
    Val p3873956_0;
    Val p3873972_0;
    Val p3873988_0;
    Val p3874004_0;
    Val p3874020_0;
    Val p3874036_0;
    Val p3874052_0;
    Val p3874068_0;
    Val p3874084_0;
    Val p3874100_0;
    Val p3874116_0;
    Val p3874132_0;
    Val p3874148_0;
    Val p3874164_0;
    Val p3874180_0;
    Val p3874196_0;
    Val p3874212_0;
    Val p3874228_0;
    Val p3874244_0;
    Val p3874260_0;
    Val p3874276_0;
    Val p3874292_0;
    Val p3874308_0;
    Val p3874324_0;
    Val p3874340_0;
    Val p3874356_0;
    Val p3874372_0;
    Val p3874388_0;
    Val p3874404_0;
    Val p3874420_0;
    Val p3874436_0;
    Val p3874452_0;
    Val p3874468_0;
    Val p3874484_0;
    Val p3874500_0;
    Val p3874516_0;
    Val p3874532_0;
    Val p3874548_0;
    Val p3874564_0;
    Val p3874580_0;
    Val p3874596_0;
    Val p3874612_0;
    Val p3874628_0;
    Val p3874644_0;
    Val p3874660_0;
    Val p3874676_0;
    Val p3874692_0;
    Val p3874708_0;
    Val p3874724_0;
    /* @3871212 constant */
    /* @3871216 store */
    GM_WRITE(vm, -1, "type", VAL(1));
    /* @3871224 load */
    /* @3871232 dup */
    /* @3871236 constant */
    /* @3871240 cmp */
    /* @3871244 bt */
    p3872980_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_3872980;
    /* @3871248 dup */
    /* @3871252 constant */
    /* @3871256 cmp */
    /* @3871260 bt */
    p3872996_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_3872996;
    /* @3871264 dup */
    /* @3871268 constant */
    /* @3871272 cmp */
    /* @3871276 bt */
    p3873012_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_3873012;
    /* @3871280 dup */
    /* @3871284 constant */
    /* @3871288 cmp */
    /* @3871292 bt */
    p3873028_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_3873028;
    /* @3871296 dup */
    /* @3871300 constant */
    /* @3871304 cmp */
    /* @3871308 bt */
    p3873044_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_3873044;
    /* @3871312 dup */
    /* @3871316 constant */
    /* @3871320 cmp */
    /* @3871324 bt */
    p3873060_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_3873060;
    /* @3871328 dup */
    /* @3871332 constant */
    /* @3871336 cmp */
    /* @3871340 bt */
    p3873076_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_3873076;
    /* @3871344 dup */
    /* @3871348 constant */
    /* @3871352 cmp */
    /* @3871356 bt */
    p3873092_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_3873092;
    /* @3871360 dup */
    /* @3871364 constant */
    /* @3871368 cmp */
    /* @3871372 bt */
    p3873108_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_3873108;
    /* @3871376 dup */
    /* @3871380 constant */
    /* @3871384 cmp */
    /* @3871388 bt */
    p3873124_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3873124;
    /* @3871392 dup */
    /* @3871396 constant */
    /* @3871400 cmp */
    /* @3871404 bt */
    p3873140_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_3873140;
    /* @3871408 dup */
    /* @3871412 constant */
    /* @3871416 cmp */
    /* @3871420 bt */
    p3873156_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_3873156;
    /* @3871424 dup */
    /* @3871428 constant */
    /* @3871432 cmp */
    /* @3871436 bt */
    p3873172_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_3873172;
    /* @3871440 dup */
    /* @3871444 constant */
    /* @3871448 cmp */
    /* @3871452 bt */
    p3873188_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_3873188;
    /* @3871456 dup */
    /* @3871460 constant */
    /* @3871464 cmp */
    /* @3871468 bt */
    p3873204_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_3873204;
    /* @3871472 dup */
    /* @3871476 constant */
    /* @3871480 cmp */
    /* @3871484 bt */
    p3873220_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_3873220;
    /* @3871488 dup */
    /* @3871492 constant */
    /* @3871496 cmp */
    /* @3871500 bt */
    p3873236_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_3873236;
    /* @3871504 dup */
    /* @3871508 constant */
    /* @3871512 cmp */
    /* @3871516 bt */
    p3873252_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_3873252;
    /* @3871520 dup */
    /* @3871524 constant */
    /* @3871528 cmp */
    /* @3871532 bt */
    p3873268_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_3873268;
    /* @3871536 dup */
    /* @3871540 constant */
    /* @3871544 cmp */
    /* @3871548 bt */
    p3873284_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_3873284;
    /* @3871552 dup */
    /* @3871556 constant */
    /* @3871560 cmp */
    /* @3871564 bt */
    p3873300_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_3873300;
    /* @3871568 dup */
    /* @3871572 constant */
    /* @3871576 cmp */
    /* @3871580 bt */
    p3873316_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_3873316;
    /* @3871584 dup */
    /* @3871588 constant */
    /* @3871592 cmp */
    /* @3871596 bt */
    p3873332_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_3873332;
    /* @3871600 dup */
    /* @3871604 constant */
    /* @3871608 cmp */
    /* @3871612 bt */
    p3873348_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_3873348;
    /* @3871616 dup */
    /* @3871620 constant */
    /* @3871624 cmp */
    /* @3871628 bt */
    p3873364_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_3873364;
    /* @3871632 dup */
    /* @3871636 constant */
    /* @3871640 cmp */
    /* @3871644 bt */
    p3873380_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_3873380;
    /* @3871648 dup */
    /* @3871652 constant */
    /* @3871656 cmp */
    /* @3871660 bt */
    p3873396_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3873396;
    /* @3871664 dup */
    /* @3871668 constant */
    /* @3871672 cmp */
    /* @3871676 bt */
    p3873412_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_3873412;
    /* @3871680 dup */
    /* @3871684 constant */
    /* @3871688 cmp */
    /* @3871692 bt */
    p3873428_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_3873428;
    /* @3871696 dup */
    /* @3871700 constant */
    /* @3871704 cmp */
    /* @3871708 bt */
    p3873444_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_3873444;
    /* @3871712 dup */
    /* @3871716 constant */
    /* @3871720 cmp */
    /* @3871724 bt */
    p3873460_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_3873460;
    /* @3871728 dup */
    /* @3871732 constant */
    /* @3871736 cmp */
    /* @3871740 bt */
    p3873476_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_3873476;
    /* @3871744 dup */
    /* @3871748 constant */
    /* @3871752 cmp */
    /* @3871756 bt */
    p3873492_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_3873492;
    /* @3871760 dup */
    /* @3871764 constant */
    /* @3871768 cmp */
    /* @3871772 bt */
    p3873508_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_3873508;
    /* @3871776 dup */
    /* @3871780 constant */
    /* @3871784 cmp */
    /* @3871788 bt */
    p3873524_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_3873524;
    /* @3871792 dup */
    /* @3871796 constant */
    /* @3871800 cmp */
    /* @3871804 bt */
    p3873540_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_3873540;
    /* @3871808 dup */
    /* @3871812 constant */
    /* @3871816 cmp */
    /* @3871820 bt */
    p3873556_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_3873556;
    /* @3871824 dup */
    /* @3871828 constant */
    /* @3871832 cmp */
    /* @3871836 bt */
    p3873572_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_3873572;
    /* @3871840 dup */
    /* @3871844 constant */
    /* @3871848 cmp */
    /* @3871852 bt */
    p3873588_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_3873588;
    /* @3871856 dup */
    /* @3871860 constant */
    /* @3871864 cmp */
    /* @3871868 bt */
    p3873604_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_3873604;
    /* @3871872 dup */
    /* @3871876 constant */
    /* @3871880 cmp */
    /* @3871884 bt */
    p3873620_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_3873620;
    /* @3871888 dup */
    /* @3871892 constant */
    /* @3871896 cmp */
    /* @3871900 bt */
    p3873636_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_3873636;
    /* @3871904 dup */
    /* @3871908 constant */
    /* @3871912 cmp */
    /* @3871916 bt */
    p3873652_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_3873652;
    /* @3871920 dup */
    /* @3871924 constant */
    /* @3871928 cmp */
    /* @3871932 bt */
    p3873668_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_3873668;
    /* @3871936 dup */
    /* @3871940 constant */
    /* @3871944 cmp */
    /* @3871948 bt */
    p3873684_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_3873684;
    /* @3871952 dup */
    /* @3871956 constant */
    /* @3871960 cmp */
    /* @3871964 bt */
    p3873700_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_3873700;
    /* @3871968 dup */
    /* @3871972 constant */
    /* @3871976 cmp */
    /* @3871980 bt */
    p3873716_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_3873716;
    /* @3871984 dup */
    /* @3871988 constant */
    /* @3871992 cmp */
    /* @3871996 bt */
    p3873732_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3873732;
    /* @3872000 dup */
    /* @3872004 constant */
    /* @3872008 cmp */
    /* @3872012 bt */
    p3873748_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_3873748;
    /* @3872016 dup */
    /* @3872020 constant */
    /* @3872024 cmp */
    /* @3872028 bt */
    p3873764_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_3873764;
    /* @3872032 dup */
    /* @3872036 constant */
    /* @3872040 cmp */
    /* @3872044 bt */
    p3873780_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_3873780;
    /* @3872048 dup */
    /* @3872052 constant */
    /* @3872056 cmp */
    /* @3872060 bt */
    p3873796_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_3873796;
    /* @3872064 dup */
    /* @3872068 constant */
    /* @3872072 cmp */
    /* @3872076 bt */
    p3873812_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_3873812;
    /* @3872080 dup */
    /* @3872084 constant */
    /* @3872088 cmp */
    /* @3872092 bt */
    p3873828_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_3873828;
    /* @3872096 dup */
    /* @3872100 constant */
    /* @3872104 cmp */
    /* @3872108 bt */
    p3873844_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_3873844;
    /* @3872112 dup */
    /* @3872116 constant */
    /* @3872120 cmp */
    /* @3872124 bt */
    p3873860_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_3873860;
    /* @3872128 dup */
    /* @3872132 constant */
    /* @3872136 cmp */
    /* @3872140 bt */
    p3873876_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_3873876;
    /* @3872144 dup */
    /* @3872148 constant */
    /* @3872152 cmp */
    /* @3872156 bt */
    p3873892_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_3873892;
    /* @3872160 dup */
    /* @3872164 constant */
    /* @3872168 cmp */
    /* @3872172 bt */
    p3873908_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_3873908;
    /* @3872176 dup */
    /* @3872180 constant */
    /* @3872184 cmp */
    /* @3872188 bt */
    p3873924_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_3873924;
    /* @3872192 dup */
    /* @3872196 constant */
    /* @3872200 cmp */
    /* @3872204 bt */
    p3873940_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_3873940;
    /* @3872208 dup */
    /* @3872212 constant */
    /* @3872216 cmp */
    /* @3872220 bt */
    p3873956_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_3873956;
    /* @3872224 dup */
    /* @3872228 constant */
    /* @3872232 cmp */
    /* @3872236 bt */
    p3873972_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_3873972;
    /* @3872240 dup */
    /* @3872244 constant */
    /* @3872248 cmp */
    /* @3872252 bt */
    p3873988_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3873988;
    /* @3872256 dup */
    /* @3872260 constant */
    /* @3872264 cmp */
    /* @3872268 bt */
    p3874004_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_3874004;
    /* @3872272 dup */
    /* @3872276 constant */
    /* @3872280 cmp */
    /* @3872284 bt */
    p3874020_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_3874020;
    /* @3872288 dup */
    /* @3872292 constant */
    /* @3872296 cmp */
    /* @3872300 bt */
    p3874036_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_3874036;
    /* @3872304 dup */
    /* @3872308 constant */
    /* @3872312 cmp */
    /* @3872316 bt */
    p3874052_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_3874052;
    /* @3872320 dup */
    /* @3872324 constant */
    /* @3872328 cmp */
    /* @3872332 bt */
    p3874068_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_3874068;
    /* @3872336 dup */
    /* @3872340 constant */
    /* @3872344 cmp */
    /* @3872348 bt */
    p3874084_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_3874084;
    /* @3872352 dup */
    /* @3872356 constant */
    /* @3872360 cmp */
    /* @3872364 bt */
    p3874100_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_3874100;
    /* @3872368 dup */
    /* @3872372 constant */
    /* @3872376 cmp */
    /* @3872380 bt */
    p3874116_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_3874116;
    /* @3872384 dup */
    /* @3872388 constant */
    /* @3872392 cmp */
    /* @3872396 bt */
    p3874132_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_3874132;
    /* @3872400 dup */
    /* @3872404 constant */
    /* @3872408 cmp */
    /* @3872412 bt */
    p3874148_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_3874148;
    /* @3872416 dup */
    /* @3872420 constant */
    /* @3872424 cmp */
    /* @3872428 bt */
    p3874164_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_3874164;
    /* @3872432 dup */
    /* @3872436 constant */
    /* @3872440 cmp */
    /* @3872444 bt */
    p3874180_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_3874180;
    /* @3872448 dup */
    /* @3872452 constant */
    /* @3872456 cmp */
    /* @3872460 bt */
    p3874196_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_3874196;
    /* @3872464 dup */
    /* @3872468 constant */
    /* @3872472 cmp */
    /* @3872476 bt */
    p3874212_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_3874212;
    /* @3872480 dup */
    /* @3872484 constant */
    /* @3872488 cmp */
    /* @3872492 bt */
    p3874228_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_3874228;
    /* @3872496 dup */
    /* @3872500 constant */
    /* @3872504 cmp */
    /* @3872508 bt */
    p3874244_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_3874244;
    /* @3872512 dup */
    /* @3872516 constant */
    /* @3872520 cmp */
    /* @3872524 bt */
    p3874260_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_3874260;
    /* @3872528 dup */
    /* @3872532 constant */
    /* @3872536 cmp */
    /* @3872540 bt */
    p3874276_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3874276;
    /* @3872544 dup */
    /* @3872548 constant */
    /* @3872552 cmp */
    /* @3872556 bt */
    p3874292_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_3874292;
    /* @3872560 dup */
    /* @3872564 constant */
    /* @3872568 cmp */
    /* @3872572 bt */
    p3874308_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_3874308;
    /* @3872576 dup */
    /* @3872580 constant */
    /* @3872584 cmp */
    /* @3872588 bt */
    p3874324_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_3874324;
    /* @3872592 dup */
    /* @3872596 constant */
    /* @3872600 cmp */
    /* @3872604 bt */
    p3874340_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_3874340;
    /* @3872608 dup */
    /* @3872612 constant */
    /* @3872616 cmp */
    /* @3872620 bt */
    p3874356_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_3874356;
    /* @3872624 dup */
    /* @3872628 constant */
    /* @3872632 cmp */
    /* @3872636 bt */
    p3874372_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_3874372;
    /* @3872640 dup */
    /* @3872644 constant */
    /* @3872648 cmp */
    /* @3872652 bt */
    p3874388_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_3874388;
    /* @3872656 dup */
    /* @3872660 constant */
    /* @3872664 cmp */
    /* @3872668 bt */
    p3874404_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_3874404;
    /* @3872672 dup */
    /* @3872676 constant */
    /* @3872680 cmp */
    /* @3872684 bt */
    p3874420_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_3874420;
    /* @3872688 dup */
    /* @3872692 constant */
    /* @3872696 cmp */
    /* @3872700 bt */
    p3874436_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_3874436;
    /* @3872704 dup */
    /* @3872708 constant */
    /* @3872712 cmp */
    /* @3872716 bt */
    p3874452_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_3874452;
    /* @3872720 dup */
    /* @3872724 constant */
    /* @3872728 cmp */
    /* @3872732 bt */
    p3874468_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_3874468;
    /* @3872736 dup */
    /* @3872740 constant */
    /* @3872744 cmp */
    /* @3872748 bt */
    p3874484_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_3874484;
    /* @3872752 dup */
    /* @3872756 constant */
    /* @3872760 cmp */
    /* @3872764 bt */
    p3874500_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_3874500;
    /* @3872768 dup */
    /* @3872772 constant */
    /* @3872776 cmp */
    /* @3872780 bt */
    p3874516_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_3874516;
    /* @3872784 dup */
    /* @3872788 constant */
    /* @3872792 cmp */
    /* @3872796 bt */
    p3874532_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_3874532;
    /* @3872800 dup */
    /* @3872804 constant */
    /* @3872808 cmp */
    /* @3872812 bt */
    p3874548_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_3874548;
    /* @3872816 dup */
    /* @3872820 constant */
    /* @3872824 cmp */
    /* @3872828 bt */
    p3874564_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_3874564;
    /* @3872832 dup */
    /* @3872836 constant */
    /* @3872840 cmp */
    /* @3872844 bt */
    p3874580_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_3874580;
    /* @3872848 dup */
    /* @3872852 constant */
    /* @3872856 cmp */
    /* @3872860 bt */
    p3874596_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_3874596;
    /* @3872864 dup */
    /* @3872868 constant */
    /* @3872872 cmp */
    /* @3872876 bt */
    p3874612_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_3874612;
    /* @3872880 dup */
    /* @3872884 constant */
    /* @3872888 cmp */
    /* @3872892 bt */
    p3874628_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3874628;
    /* @3872896 dup */
    /* @3872900 constant */
    /* @3872904 cmp */
    /* @3872908 bt */
    p3874644_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(105)))) goto L_3874644;
    /* @3872912 dup */
    /* @3872916 constant */
    /* @3872920 cmp */
    /* @3872924 bt */
    p3874660_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(106)))) goto L_3874660;
    /* @3872928 dup */
    /* @3872932 constant */
    /* @3872936 cmp */
    /* @3872940 bt */
    p3874676_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(107)))) goto L_3874676;
    /* @3872944 dup */
    /* @3872948 constant */
    /* @3872952 cmp */
    /* @3872956 bt */
    p3874692_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(108)))) goto L_3874692;
    /* @3872960 dup */
    /* @3872964 constant */
    /* @3872968 cmp */
    /* @3872972 bt */
    p3874708_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(109)))) goto L_3874708;
    /* @3872976 b */
    p3874724_0 = GM_READ(vm, -1, "room");
    goto L_3874724;
    L_3872980: ;
    /* @3872980 constant */
    /* @3872984 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3872992 b */
    p3874724_0 = p3872980_0;
    goto L_3874724;
    L_3872996: ;
    /* @3872996 constant */
    /* @3873000 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873008 b */
    p3874724_0 = p3872996_0;
    goto L_3874724;
    L_3873012: ;
    /* @3873012 constant */
    /* @3873016 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873024 b */
    p3874724_0 = p3873012_0;
    goto L_3874724;
    L_3873028: ;
    /* @3873028 constant */
    /* @3873032 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873040 b */
    p3874724_0 = p3873028_0;
    goto L_3874724;
    L_3873044: ;
    /* @3873044 constant */
    /* @3873048 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873056 b */
    p3874724_0 = p3873044_0;
    goto L_3874724;
    L_3873060: ;
    /* @3873060 constant */
    /* @3873064 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873072 b */
    p3874724_0 = p3873060_0;
    goto L_3874724;
    L_3873076: ;
    /* @3873076 constant */
    /* @3873080 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873088 b */
    p3874724_0 = p3873076_0;
    goto L_3874724;
    L_3873092: ;
    /* @3873092 constant */
    /* @3873096 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873104 b */
    p3874724_0 = p3873092_0;
    goto L_3874724;
    L_3873108: ;
    /* @3873108 constant */
    /* @3873112 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873120 b */
    p3874724_0 = p3873108_0;
    goto L_3874724;
    L_3873124: ;
    /* @3873124 constant */
    /* @3873128 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(6));
    /* @3873136 b */
    p3874724_0 = p3873124_0;
    goto L_3874724;
    L_3873140: ;
    /* @3873140 constant */
    /* @3873144 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873152 b */
    p3874724_0 = p3873140_0;
    goto L_3874724;
    L_3873156: ;
    /* @3873156 constant */
    /* @3873160 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873168 b */
    p3874724_0 = p3873156_0;
    goto L_3874724;
    L_3873172: ;
    /* @3873172 constant */
    /* @3873176 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873184 b */
    p3874724_0 = p3873172_0;
    goto L_3874724;
    L_3873188: ;
    /* @3873188 constant */
    /* @3873192 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873200 b */
    p3874724_0 = p3873188_0;
    goto L_3874724;
    L_3873204: ;
    /* @3873204 constant */
    /* @3873208 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873216 b */
    p3874724_0 = p3873204_0;
    goto L_3874724;
    L_3873220: ;
    /* @3873220 constant */
    /* @3873224 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873232 b */
    p3874724_0 = p3873220_0;
    goto L_3874724;
    L_3873236: ;
    /* @3873236 constant */
    /* @3873240 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873248 b */
    p3874724_0 = p3873236_0;
    goto L_3874724;
    L_3873252: ;
    /* @3873252 constant */
    /* @3873256 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873264 b */
    p3874724_0 = p3873252_0;
    goto L_3874724;
    L_3873268: ;
    /* @3873268 constant */
    /* @3873272 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873280 b */
    p3874724_0 = p3873268_0;
    goto L_3874724;
    L_3873284: ;
    /* @3873284 constant */
    /* @3873288 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873296 b */
    p3874724_0 = p3873284_0;
    goto L_3874724;
    L_3873300: ;
    /* @3873300 constant */
    /* @3873304 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873312 b */
    p3874724_0 = p3873300_0;
    goto L_3874724;
    L_3873316: ;
    /* @3873316 constant */
    /* @3873320 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873328 b */
    p3874724_0 = p3873316_0;
    goto L_3874724;
    L_3873332: ;
    /* @3873332 constant */
    /* @3873336 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873344 b */
    p3874724_0 = p3873332_0;
    goto L_3874724;
    L_3873348: ;
    /* @3873348 constant */
    /* @3873352 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873360 b */
    p3874724_0 = p3873348_0;
    goto L_3874724;
    L_3873364: ;
    /* @3873364 constant */
    /* @3873368 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873376 b */
    p3874724_0 = p3873364_0;
    goto L_3874724;
    L_3873380: ;
    /* @3873380 constant */
    /* @3873384 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873392 b */
    p3874724_0 = p3873380_0;
    goto L_3874724;
    L_3873396: ;
    /* @3873396 constant */
    /* @3873400 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(9));
    /* @3873408 b */
    p3874724_0 = p3873396_0;
    goto L_3874724;
    L_3873412: ;
    /* @3873412 constant */
    /* @3873416 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873424 b */
    p3874724_0 = p3873412_0;
    goto L_3874724;
    L_3873428: ;
    /* @3873428 constant */
    /* @3873432 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873440 b */
    p3874724_0 = p3873428_0;
    goto L_3874724;
    L_3873444: ;
    /* @3873444 constant */
    /* @3873448 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873456 b */
    p3874724_0 = p3873444_0;
    goto L_3874724;
    L_3873460: ;
    /* @3873460 constant */
    /* @3873464 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873472 b */
    p3874724_0 = p3873460_0;
    goto L_3874724;
    L_3873476: ;
    /* @3873476 constant */
    /* @3873480 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873488 b */
    p3874724_0 = p3873476_0;
    goto L_3874724;
    L_3873492: ;
    /* @3873492 constant */
    /* @3873496 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873504 b */
    p3874724_0 = p3873492_0;
    goto L_3874724;
    L_3873508: ;
    /* @3873508 constant */
    /* @3873512 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873520 b */
    p3874724_0 = p3873508_0;
    goto L_3874724;
    L_3873524: ;
    /* @3873524 constant */
    /* @3873528 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873536 b */
    p3874724_0 = p3873524_0;
    goto L_3874724;
    L_3873540: ;
    /* @3873540 constant */
    /* @3873544 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873552 b */
    p3874724_0 = p3873540_0;
    goto L_3874724;
    L_3873556: ;
    /* @3873556 constant */
    /* @3873560 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873568 b */
    p3874724_0 = p3873556_0;
    goto L_3874724;
    L_3873572: ;
    /* @3873572 constant */
    /* @3873576 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873584 b */
    p3874724_0 = p3873572_0;
    goto L_3874724;
    L_3873588: ;
    /* @3873588 constant */
    /* @3873592 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873600 b */
    p3874724_0 = p3873588_0;
    goto L_3874724;
    L_3873604: ;
    /* @3873604 constant */
    /* @3873608 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873616 b */
    p3874724_0 = p3873604_0;
    goto L_3874724;
    L_3873620: ;
    /* @3873620 constant */
    /* @3873624 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873632 b */
    p3874724_0 = p3873620_0;
    goto L_3874724;
    L_3873636: ;
    /* @3873636 constant */
    /* @3873640 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873648 b */
    p3874724_0 = p3873636_0;
    goto L_3874724;
    L_3873652: ;
    /* @3873652 constant */
    /* @3873656 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873664 b */
    p3874724_0 = p3873652_0;
    goto L_3874724;
    L_3873668: ;
    /* @3873668 constant */
    /* @3873672 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873680 b */
    p3874724_0 = p3873668_0;
    goto L_3874724;
    L_3873684: ;
    /* @3873684 constant */
    /* @3873688 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873696 b */
    p3874724_0 = p3873684_0;
    goto L_3874724;
    L_3873700: ;
    /* @3873700 constant */
    /* @3873704 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873712 b */
    p3874724_0 = p3873700_0;
    goto L_3874724;
    L_3873716: ;
    /* @3873716 constant */
    /* @3873720 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873728 b */
    p3874724_0 = p3873716_0;
    goto L_3874724;
    L_3873732: ;
    /* @3873732 constant */
    /* @3873736 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(12));
    /* @3873744 b */
    p3874724_0 = p3873732_0;
    goto L_3874724;
    L_3873748: ;
    /* @3873748 constant */
    /* @3873752 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873760 b */
    p3874724_0 = p3873748_0;
    goto L_3874724;
    L_3873764: ;
    /* @3873764 constant */
    /* @3873768 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873776 b */
    p3874724_0 = p3873764_0;
    goto L_3874724;
    L_3873780: ;
    /* @3873780 constant */
    /* @3873784 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873792 b */
    p3874724_0 = p3873780_0;
    goto L_3874724;
    L_3873796: ;
    /* @3873796 constant */
    /* @3873800 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873808 b */
    p3874724_0 = p3873796_0;
    goto L_3874724;
    L_3873812: ;
    /* @3873812 constant */
    /* @3873816 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873824 b */
    p3874724_0 = p3873812_0;
    goto L_3874724;
    L_3873828: ;
    /* @3873828 constant */
    /* @3873832 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873840 b */
    p3874724_0 = p3873828_0;
    goto L_3874724;
    L_3873844: ;
    /* @3873844 constant */
    /* @3873848 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873856 b */
    p3874724_0 = p3873844_0;
    goto L_3874724;
    L_3873860: ;
    /* @3873860 constant */
    /* @3873864 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873872 b */
    p3874724_0 = p3873860_0;
    goto L_3874724;
    L_3873876: ;
    /* @3873876 constant */
    /* @3873880 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873888 b */
    p3874724_0 = p3873876_0;
    goto L_3874724;
    L_3873892: ;
    /* @3873892 constant */
    /* @3873896 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873904 b */
    p3874724_0 = p3873892_0;
    goto L_3874724;
    L_3873908: ;
    /* @3873908 constant */
    /* @3873912 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873920 b */
    p3874724_0 = p3873908_0;
    goto L_3874724;
    L_3873924: ;
    /* @3873924 constant */
    /* @3873928 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873936 b */
    p3874724_0 = p3873924_0;
    goto L_3874724;
    L_3873940: ;
    /* @3873940 constant */
    /* @3873944 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873952 b */
    p3874724_0 = p3873940_0;
    goto L_3874724;
    L_3873956: ;
    /* @3873956 constant */
    /* @3873960 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873968 b */
    p3874724_0 = p3873956_0;
    goto L_3874724;
    L_3873972: ;
    /* @3873972 constant */
    /* @3873976 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3873984 b */
    p3874724_0 = p3873972_0;
    goto L_3874724;
    L_3873988: ;
    /* @3873988 constant */
    /* @3873992 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(15));
    /* @3874000 b */
    p3874724_0 = p3873988_0;
    goto L_3874724;
    L_3874004: ;
    /* @3874004 constant */
    /* @3874008 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874016 b */
    p3874724_0 = p3874004_0;
    goto L_3874724;
    L_3874020: ;
    /* @3874020 constant */
    /* @3874024 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874032 b */
    p3874724_0 = p3874020_0;
    goto L_3874724;
    L_3874036: ;
    /* @3874036 constant */
    /* @3874040 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874048 b */
    p3874724_0 = p3874036_0;
    goto L_3874724;
    L_3874052: ;
    /* @3874052 constant */
    /* @3874056 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874064 b */
    p3874724_0 = p3874052_0;
    goto L_3874724;
    L_3874068: ;
    /* @3874068 constant */
    /* @3874072 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874080 b */
    p3874724_0 = p3874068_0;
    goto L_3874724;
    L_3874084: ;
    /* @3874084 constant */
    /* @3874088 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874096 b */
    p3874724_0 = p3874084_0;
    goto L_3874724;
    L_3874100: ;
    /* @3874100 constant */
    /* @3874104 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874112 b */
    p3874724_0 = p3874100_0;
    goto L_3874724;
    L_3874116: ;
    /* @3874116 constant */
    /* @3874120 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874128 b */
    p3874724_0 = p3874116_0;
    goto L_3874724;
    L_3874132: ;
    /* @3874132 constant */
    /* @3874136 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874144 b */
    p3874724_0 = p3874132_0;
    goto L_3874724;
    L_3874148: ;
    /* @3874148 constant */
    /* @3874152 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874160 b */
    p3874724_0 = p3874148_0;
    goto L_3874724;
    L_3874164: ;
    /* @3874164 constant */
    /* @3874168 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874176 b */
    p3874724_0 = p3874164_0;
    goto L_3874724;
    L_3874180: ;
    /* @3874180 constant */
    /* @3874184 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874192 b */
    p3874724_0 = p3874180_0;
    goto L_3874724;
    L_3874196: ;
    /* @3874196 constant */
    /* @3874200 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874208 b */
    p3874724_0 = p3874196_0;
    goto L_3874724;
    L_3874212: ;
    /* @3874212 constant */
    /* @3874216 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874224 b */
    p3874724_0 = p3874212_0;
    goto L_3874724;
    L_3874228: ;
    /* @3874228 constant */
    /* @3874232 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874240 b */
    p3874724_0 = p3874228_0;
    goto L_3874724;
    L_3874244: ;
    /* @3874244 constant */
    /* @3874248 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874256 b */
    p3874724_0 = p3874244_0;
    goto L_3874724;
    L_3874260: ;
    /* @3874260 constant */
    /* @3874264 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874272 b */
    p3874724_0 = p3874260_0;
    goto L_3874724;
    L_3874276: ;
    /* @3874276 constant */
    /* @3874280 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(18));
    /* @3874288 b */
    p3874724_0 = p3874276_0;
    goto L_3874724;
    L_3874292: ;
    /* @3874292 constant */
    /* @3874296 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874304 b */
    p3874724_0 = p3874292_0;
    goto L_3874724;
    L_3874308: ;
    /* @3874308 constant */
    /* @3874312 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874320 b */
    p3874724_0 = p3874308_0;
    goto L_3874724;
    L_3874324: ;
    /* @3874324 constant */
    /* @3874328 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874336 b */
    p3874724_0 = p3874324_0;
    goto L_3874724;
    L_3874340: ;
    /* @3874340 constant */
    /* @3874344 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874352 b */
    p3874724_0 = p3874340_0;
    goto L_3874724;
    L_3874356: ;
    /* @3874356 constant */
    /* @3874360 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874368 b */
    p3874724_0 = p3874356_0;
    goto L_3874724;
    L_3874372: ;
    /* @3874372 constant */
    /* @3874376 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874384 b */
    p3874724_0 = p3874372_0;
    goto L_3874724;
    L_3874388: ;
    /* @3874388 constant */
    /* @3874392 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874400 b */
    p3874724_0 = p3874388_0;
    goto L_3874724;
    L_3874404: ;
    /* @3874404 constant */
    /* @3874408 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874416 b */
    p3874724_0 = p3874404_0;
    goto L_3874724;
    L_3874420: ;
    /* @3874420 constant */
    /* @3874424 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874432 b */
    p3874724_0 = p3874420_0;
    goto L_3874724;
    L_3874436: ;
    /* @3874436 constant */
    /* @3874440 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874448 b */
    p3874724_0 = p3874436_0;
    goto L_3874724;
    L_3874452: ;
    /* @3874452 constant */
    /* @3874456 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874464 b */
    p3874724_0 = p3874452_0;
    goto L_3874724;
    L_3874468: ;
    /* @3874468 constant */
    /* @3874472 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874480 b */
    p3874724_0 = p3874468_0;
    goto L_3874724;
    L_3874484: ;
    /* @3874484 constant */
    /* @3874488 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874496 b */
    p3874724_0 = p3874484_0;
    goto L_3874724;
    L_3874500: ;
    /* @3874500 constant */
    /* @3874504 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874512 b */
    p3874724_0 = p3874500_0;
    goto L_3874724;
    L_3874516: ;
    /* @3874516 constant */
    /* @3874520 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874528 b */
    p3874724_0 = p3874516_0;
    goto L_3874724;
    L_3874532: ;
    /* @3874532 constant */
    /* @3874536 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874544 b */
    p3874724_0 = p3874532_0;
    goto L_3874724;
    L_3874548: ;
    /* @3874548 constant */
    /* @3874552 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874560 b */
    p3874724_0 = p3874548_0;
    goto L_3874724;
    L_3874564: ;
    /* @3874564 constant */
    /* @3874568 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874576 b */
    p3874724_0 = p3874564_0;
    goto L_3874724;
    L_3874580: ;
    /* @3874580 constant */
    /* @3874584 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874592 b */
    p3874724_0 = p3874580_0;
    goto L_3874724;
    L_3874596: ;
    /* @3874596 constant */
    /* @3874600 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874608 b */
    p3874724_0 = p3874596_0;
    goto L_3874724;
    L_3874612: ;
    /* @3874612 constant */
    /* @3874616 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874624 b */
    p3874724_0 = p3874612_0;
    goto L_3874724;
    L_3874628: ;
    /* @3874628 constant */
    /* @3874632 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874640 b */
    p3874724_0 = p3874628_0;
    goto L_3874724;
    L_3874644: ;
    /* @3874644 constant */
    /* @3874648 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874656 b */
    p3874724_0 = p3874644_0;
    goto L_3874724;
    L_3874660: ;
    /* @3874660 constant */
    /* @3874664 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874672 b */
    p3874724_0 = p3874660_0;
    goto L_3874724;
    L_3874676: ;
    /* @3874676 constant */
    /* @3874680 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874688 b */
    p3874724_0 = p3874676_0;
    goto L_3874724;
    L_3874692: ;
    /* @3874692 constant */
    /* @3874696 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874704 b */
    p3874724_0 = p3874692_0;
    goto L_3874724;
    L_3874708: ;
    /* @3874708 constant */
    /* @3874712 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(21));
    /* @3874720 b */
    p3874724_0 = p3874708_0;
    goto L_3874724;
    L_3874724: ;
    /* @3874724 popz */
    L_3874728: ;
    return;
}
