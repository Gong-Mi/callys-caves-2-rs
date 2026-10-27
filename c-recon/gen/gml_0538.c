/* generated from CODE 538 (gml_Object_obj_viewresolution_Alarm_0), source start 4837552, end 4840892. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0538(GmVM* vm) {
    Val v1;
    Val p4837596_0;
    Val v2;
    Val v3;
    Val p4837788_0;
    Val v4;
    Val v5;
    Val p4837980_0;
    Val v6;
    Val v7;
    Val p4838172_0;
    Val v8;
    Val v9;
    Val p4838364_0;
    Val v10;
    Val v11;
    Val p4838556_0;
    Val v12;
    Val v13;
    Val p4838748_0;
    Val v14;
    Val v15;
    Val p4838940_0;
    Val v16;
    Val v17;
    Val p4839172_0;
    Val v18;
    Val v19;
    Val p4839404_0;
    Val v20;
    Val v21;
    Val p4839636_0;
    Val v22;
    Val v23;
    Val p4839868_0;
    Val v24;
    Val v25;
    Val p4840100_0;
    Val v26;
    Val v27;
    Val p4840332_0;
    Val v28;
    Val v29;
    Val p4840564_0;
    Val v30;
    /* @4837552 call */
    GM_SITE(vm, 538, 4837552);
    /* @4837560 constant */
    /* @4837564 cmp */
    /* @4837568 bf */
    v1 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(960));
    if (!TRUTH(v1)) goto L_4837592;
    /* @4837572 call */
    GM_SITE(vm, 538, 4837572);
    /* @4837580 constant */
    /* @4837584 cmp */
    /* @4837588 b */
    v2 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(640));
    p4837596_0 = v2;
    goto L_4837596;
    L_4837592: ;
    /* @4837592 constant */
    p4837596_0 = VAL(0);
    L_4837596: ;
    /* @4837596 bf */
    if (!TRUTH(p4837596_0)) goto L_4837744;
    /* @4837600 constant */
    /* @4837604 constant */
    /* @4837608 constant */
    /* @4837612 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4837620 constant */
    /* @4837624 constant */
    /* @4837628 constant */
    /* @4837632 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(1));
    /* @4837640 constant */
    /* @4837644 constant */
    /* @4837648 constant */
    /* @4837652 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4837660 constant */
    /* @4837664 constant */
    /* @4837668 constant */
    /* @4837672 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4837680 constant */
    /* @4837684 constant */
    /* @4837688 constant */
    /* @4837692 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4837700 constant */
    /* @4837704 constant */
    /* @4837708 constant */
    /* @4837712 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4837720 constant */
    /* @4837724 constant */
    /* @4837728 constant */
    /* @4837732 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4837740 b */
    goto L_4840892;
    L_4837744: ;
    /* @4837744 call */
    GM_SITE(vm, 538, 4837744);
    /* @4837752 constant */
    /* @4837756 cmp */
    /* @4837760 bf */
    v3 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1136));
    if (!TRUTH(v3)) goto L_4837784;
    /* @4837764 call */
    GM_SITE(vm, 538, 4837764);
    /* @4837772 constant */
    /* @4837776 cmp */
    /* @4837780 b */
    v4 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(640));
    p4837788_0 = v4;
    goto L_4837788;
    L_4837784: ;
    /* @4837784 constant */
    p4837788_0 = VAL(0);
    L_4837788: ;
    /* @4837788 bf */
    if (!TRUTH(p4837788_0)) goto L_4837936;
    /* @4837792 constant */
    /* @4837796 constant */
    /* @4837800 constant */
    /* @4837804 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(1));
    /* @4837812 constant */
    /* @4837816 constant */
    /* @4837820 constant */
    /* @4837824 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4837832 constant */
    /* @4837836 constant */
    /* @4837840 constant */
    /* @4837844 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4837852 constant */
    /* @4837856 constant */
    /* @4837860 constant */
    /* @4837864 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4837872 constant */
    /* @4837876 constant */
    /* @4837880 constant */
    /* @4837884 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4837892 constant */
    /* @4837896 constant */
    /* @4837900 constant */
    /* @4837904 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4837912 constant */
    /* @4837916 constant */
    /* @4837920 constant */
    /* @4837924 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4837932 b */
    goto L_4840892;
    L_4837936: ;
    /* @4837936 call */
    GM_SITE(vm, 538, 4837936);
    /* @4837944 constant */
    /* @4837948 cmp */
    /* @4837952 bf */
    v5 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(480));
    if (!TRUTH(v5)) goto L_4837976;
    /* @4837956 call */
    GM_SITE(vm, 538, 4837956);
    /* @4837964 constant */
    /* @4837968 cmp */
    /* @4837972 b */
    v6 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(320));
    p4837980_0 = v6;
    goto L_4837980;
    L_4837976: ;
    /* @4837976 constant */
    p4837980_0 = VAL(0);
    L_4837980: ;
    /* @4837980 bf */
    if (!TRUTH(p4837980_0)) goto L_4838128;
    /* @4837984 constant */
    /* @4837988 constant */
    /* @4837992 constant */
    /* @4837996 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4838004 constant */
    /* @4838008 constant */
    /* @4838012 constant */
    /* @4838016 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4838024 constant */
    /* @4838028 constant */
    /* @4838032 constant */
    /* @4838036 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(1));
    /* @4838044 constant */
    /* @4838048 constant */
    /* @4838052 constant */
    /* @4838056 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4838064 constant */
    /* @4838068 constant */
    /* @4838072 constant */
    /* @4838076 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4838084 constant */
    /* @4838088 constant */
    /* @4838092 constant */
    /* @4838096 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4838104 constant */
    /* @4838108 constant */
    /* @4838112 constant */
    /* @4838116 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4838124 b */
    goto L_4840892;
    L_4838128: ;
    /* @4838128 call */
    GM_SITE(vm, 538, 4838128);
    /* @4838136 constant */
    /* @4838140 cmp */
    /* @4838144 bf */
    v7 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1024));
    if (!TRUTH(v7)) goto L_4838168;
    /* @4838148 call */
    GM_SITE(vm, 538, 4838148);
    /* @4838156 constant */
    /* @4838160 cmp */
    /* @4838164 b */
    v8 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(768));
    p4838172_0 = v8;
    goto L_4838172;
    L_4838168: ;
    /* @4838168 constant */
    p4838172_0 = VAL(0);
    L_4838172: ;
    /* @4838172 bf */
    if (!TRUTH(p4838172_0)) goto L_4838320;
    /* @4838176 constant */
    /* @4838180 constant */
    /* @4838184 constant */
    /* @4838188 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(1));
    /* @4838196 constant */
    /* @4838200 constant */
    /* @4838204 constant */
    /* @4838208 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4838216 constant */
    /* @4838220 constant */
    /* @4838224 constant */
    /* @4838228 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4838236 constant */
    /* @4838240 constant */
    /* @4838244 constant */
    /* @4838248 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4838256 constant */
    /* @4838260 constant */
    /* @4838264 constant */
    /* @4838268 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4838276 constant */
    /* @4838280 constant */
    /* @4838284 constant */
    /* @4838288 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4838296 constant */
    /* @4838300 constant */
    /* @4838304 constant */
    /* @4838308 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4838316 b */
    goto L_4840892;
    L_4838320: ;
    /* @4838320 call */
    GM_SITE(vm, 538, 4838320);
    /* @4838328 constant */
    /* @4838332 cmp */
    /* @4838336 bf */
    v9 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(2048));
    if (!TRUTH(v9)) goto L_4838360;
    /* @4838340 call */
    GM_SITE(vm, 538, 4838340);
    /* @4838348 constant */
    /* @4838352 cmp */
    /* @4838356 b */
    v10 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(1536));
    p4838364_0 = v10;
    goto L_4838364;
    L_4838360: ;
    /* @4838360 constant */
    p4838364_0 = VAL(0);
    L_4838364: ;
    /* @4838364 bf */
    if (!TRUTH(p4838364_0)) goto L_4838512;
    /* @4838368 constant */
    /* @4838372 constant */
    /* @4838376 constant */
    /* @4838380 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(1));
    /* @4838388 constant */
    /* @4838392 constant */
    /* @4838396 constant */
    /* @4838400 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4838408 constant */
    /* @4838412 constant */
    /* @4838416 constant */
    /* @4838420 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4838428 constant */
    /* @4838432 constant */
    /* @4838436 constant */
    /* @4838440 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4838448 constant */
    /* @4838452 constant */
    /* @4838456 constant */
    /* @4838460 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4838468 constant */
    /* @4838472 constant */
    /* @4838476 constant */
    /* @4838480 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4838488 constant */
    /* @4838492 constant */
    /* @4838496 constant */
    /* @4838500 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4838508 b */
    goto L_4840892;
    L_4838512: ;
    /* @4838512 call */
    GM_SITE(vm, 538, 4838512);
    /* @4838520 constant */
    /* @4838524 cmp */
    /* @4838528 bf */
    v11 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1334));
    if (!TRUTH(v11)) goto L_4838552;
    /* @4838532 call */
    GM_SITE(vm, 538, 4838532);
    /* @4838540 constant */
    /* @4838544 cmp */
    /* @4838548 b */
    v12 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(750));
    p4838556_0 = v12;
    goto L_4838556;
    L_4838552: ;
    /* @4838552 constant */
    p4838556_0 = VAL(0);
    L_4838556: ;
    /* @4838556 bf */
    if (!TRUTH(p4838556_0)) goto L_4838704;
    /* @4838560 constant */
    /* @4838564 constant */
    /* @4838568 constant */
    /* @4838572 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(1));
    /* @4838580 constant */
    /* @4838584 constant */
    /* @4838588 constant */
    /* @4838592 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4838600 constant */
    /* @4838604 constant */
    /* @4838608 constant */
    /* @4838612 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4838620 constant */
    /* @4838624 constant */
    /* @4838628 constant */
    /* @4838632 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4838640 constant */
    /* @4838644 constant */
    /* @4838648 constant */
    /* @4838652 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4838660 constant */
    /* @4838664 constant */
    /* @4838668 constant */
    /* @4838672 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4838680 constant */
    /* @4838684 constant */
    /* @4838688 constant */
    /* @4838692 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4838700 b */
    goto L_4840892;
    L_4838704: ;
    /* @4838704 call */
    GM_SITE(vm, 538, 4838704);
    /* @4838712 constant */
    /* @4838716 cmp */
    /* @4838720 bf */
    v13 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(2208));
    if (!TRUTH(v13)) goto L_4838744;
    /* @4838724 call */
    GM_SITE(vm, 538, 4838724);
    /* @4838732 constant */
    /* @4838736 cmp */
    /* @4838740 b */
    v14 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(1242));
    p4838748_0 = v14;
    goto L_4838748;
    L_4838744: ;
    /* @4838744 constant */
    p4838748_0 = VAL(0);
    L_4838748: ;
    /* @4838748 bf */
    if (!TRUTH(p4838748_0)) goto L_4838896;
    /* @4838752 constant */
    /* @4838756 constant */
    /* @4838760 constant */
    /* @4838764 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4838772 constant */
    /* @4838776 constant */
    /* @4838780 constant */
    /* @4838784 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4838792 constant */
    /* @4838796 constant */
    /* @4838800 constant */
    /* @4838804 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4838812 constant */
    /* @4838816 constant */
    /* @4838820 constant */
    /* @4838824 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4838832 constant */
    /* @4838836 constant */
    /* @4838840 constant */
    /* @4838844 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4838852 constant */
    /* @4838856 constant */
    /* @4838860 constant */
    /* @4838864 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4838872 constant */
    /* @4838876 constant */
    /* @4838880 constant */
    /* @4838884 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4838892 b */
    goto L_4840892;
    L_4838896: ;
    /* @4838896 call */
    GM_SITE(vm, 538, 4838896);
    /* @4838904 constant */
    /* @4838908 cmp */
    /* @4838912 bf */
    v15 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(800));
    if (!TRUTH(v15)) goto L_4838936;
    /* @4838916 call */
    GM_SITE(vm, 538, 4838916);
    /* @4838924 constant */
    /* @4838928 cmp */
    /* @4838932 b */
    v16 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(480));
    p4838940_0 = v16;
    goto L_4838940;
    L_4838936: ;
    /* @4838936 constant */
    p4838940_0 = VAL(0);
    L_4838940: ;
    /* @4838940 bf */
    if (!TRUTH(p4838940_0)) goto L_4839128;
    /* @4838944 constant */
    /* @4838948 constant */
    /* @4838952 constant */
    /* @4838956 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4838964 constant */
    /* @4838968 constant */
    /* @4838972 constant */
    /* @4838976 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4838984 constant */
    /* @4838988 constant */
    /* @4838992 constant */
    /* @4838996 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4839004 constant */
    /* @4839008 constant */
    /* @4839012 constant */
    /* @4839016 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4839024 constant */
    /* @4839028 constant */
    /* @4839032 constant */
    /* @4839036 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4839044 constant */
    /* @4839048 constant */
    /* @4839052 constant */
    /* @4839056 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4839064 constant */
    /* @4839068 constant */
    /* @4839072 constant */
    /* @4839076 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4839084 constant */
    /* @4839088 constant */
    /* @4839092 constant */
    /* @4839096 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(6), VAL(800));
    /* @4839104 constant */
    /* @4839108 constant */
    /* @4839112 constant */
    /* @4839116 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(6), VAL(480));
    /* @4839124 b */
    goto L_4840892;
    L_4839128: ;
    /* @4839128 call */
    GM_SITE(vm, 538, 4839128);
    /* @4839136 constant */
    /* @4839140 cmp */
    /* @4839144 bf */
    v17 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(854));
    if (!TRUTH(v17)) goto L_4839168;
    /* @4839148 call */
    GM_SITE(vm, 538, 4839148);
    /* @4839156 constant */
    /* @4839160 cmp */
    /* @4839164 b */
    v18 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(480));
    p4839172_0 = v18;
    goto L_4839172;
    L_4839168: ;
    /* @4839168 constant */
    p4839172_0 = VAL(0);
    L_4839172: ;
    /* @4839172 bf */
    if (!TRUTH(p4839172_0)) goto L_4839360;
    /* @4839176 constant */
    /* @4839180 constant */
    /* @4839184 constant */
    /* @4839188 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4839196 constant */
    /* @4839200 constant */
    /* @4839204 constant */
    /* @4839208 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(1));
    /* @4839216 constant */
    /* @4839220 constant */
    /* @4839224 constant */
    /* @4839228 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4839236 constant */
    /* @4839240 constant */
    /* @4839244 constant */
    /* @4839248 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4839256 constant */
    /* @4839260 constant */
    /* @4839264 constant */
    /* @4839268 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4839276 constant */
    /* @4839280 constant */
    /* @4839284 constant */
    /* @4839288 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4839296 constant */
    /* @4839300 constant */
    /* @4839304 constant */
    /* @4839308 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4839316 constant */
    /* @4839320 constant */
    /* @4839324 constant */
    /* @4839328 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(5), VAL(854));
    /* @4839336 constant */
    /* @4839340 constant */
    /* @4839344 constant */
    /* @4839348 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(5), VAL(480));
    /* @4839356 b */
    goto L_4840892;
    L_4839360: ;
    /* @4839360 call */
    GM_SITE(vm, 538, 4839360);
    /* @4839368 constant */
    /* @4839372 cmp */
    /* @4839376 bf */
    v19 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(960));
    if (!TRUTH(v19)) goto L_4839400;
    /* @4839380 call */
    GM_SITE(vm, 538, 4839380);
    /* @4839388 constant */
    /* @4839392 cmp */
    /* @4839396 b */
    v20 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(540));
    p4839404_0 = v20;
    goto L_4839404;
    L_4839400: ;
    /* @4839400 constant */
    p4839404_0 = VAL(0);
    L_4839404: ;
    /* @4839404 bf */
    if (!TRUTH(p4839404_0)) goto L_4839592;
    /* @4839408 constant */
    /* @4839412 constant */
    /* @4839416 constant */
    /* @4839420 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4839428 constant */
    /* @4839432 constant */
    /* @4839436 constant */
    /* @4839440 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4839448 constant */
    /* @4839452 constant */
    /* @4839456 constant */
    /* @4839460 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4839468 constant */
    /* @4839472 constant */
    /* @4839476 constant */
    /* @4839480 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4839488 constant */
    /* @4839492 constant */
    /* @4839496 constant */
    /* @4839500 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4839508 constant */
    /* @4839512 constant */
    /* @4839516 constant */
    /* @4839520 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4839528 constant */
    /* @4839532 constant */
    /* @4839536 constant */
    /* @4839540 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4839548 constant */
    /* @4839552 constant */
    /* @4839556 constant */
    /* @4839560 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(1), VAL(960));
    /* @4839568 constant */
    /* @4839572 constant */
    /* @4839576 constant */
    /* @4839580 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(1), VAL(540));
    /* @4839588 b */
    goto L_4840892;
    L_4839592: ;
    /* @4839592 call */
    GM_SITE(vm, 538, 4839592);
    /* @4839600 constant */
    /* @4839604 cmp */
    /* @4839608 bf */
    v21 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1280));
    if (!TRUTH(v21)) goto L_4839632;
    /* @4839612 call */
    GM_SITE(vm, 538, 4839612);
    /* @4839620 constant */
    /* @4839624 cmp */
    /* @4839628 b */
    v22 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(720));
    p4839636_0 = v22;
    goto L_4839636;
    L_4839632: ;
    /* @4839632 constant */
    p4839636_0 = VAL(0);
    L_4839636: ;
    /* @4839636 bf */
    if (!TRUTH(p4839636_0)) goto L_4839824;
    /* @4839640 constant */
    /* @4839644 constant */
    /* @4839648 constant */
    /* @4839652 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4839660 constant */
    /* @4839664 constant */
    /* @4839668 constant */
    /* @4839672 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4839680 constant */
    /* @4839684 constant */
    /* @4839688 constant */
    /* @4839692 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4839700 constant */
    /* @4839704 constant */
    /* @4839708 constant */
    /* @4839712 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4839720 constant */
    /* @4839724 constant */
    /* @4839728 constant */
    /* @4839732 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4839740 constant */
    /* @4839744 constant */
    /* @4839748 constant */
    /* @4839752 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4839760 constant */
    /* @4839764 constant */
    /* @4839768 constant */
    /* @4839772 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4839780 constant */
    /* @4839784 constant */
    /* @4839788 constant */
    /* @4839792 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(6), VAL(1280));
    /* @4839800 constant */
    /* @4839804 constant */
    /* @4839808 constant */
    /* @4839812 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(6), VAL(720));
    /* @4839820 b */
    goto L_4840892;
    L_4839824: ;
    /* @4839824 call */
    GM_SITE(vm, 538, 4839824);
    /* @4839832 constant */
    /* @4839836 cmp */
    /* @4839840 bf */
    v23 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1920));
    if (!TRUTH(v23)) goto L_4839864;
    /* @4839844 call */
    GM_SITE(vm, 538, 4839844);
    /* @4839852 constant */
    /* @4839856 cmp */
    /* @4839860 b */
    v24 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(1080));
    p4839868_0 = v24;
    goto L_4839868;
    L_4839864: ;
    /* @4839864 constant */
    p4839868_0 = VAL(0);
    L_4839868: ;
    /* @4839868 bf */
    if (!TRUTH(p4839868_0)) goto L_4840056;
    /* @4839872 constant */
    /* @4839876 constant */
    /* @4839880 constant */
    /* @4839884 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4839892 constant */
    /* @4839896 constant */
    /* @4839900 constant */
    /* @4839904 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4839912 constant */
    /* @4839916 constant */
    /* @4839920 constant */
    /* @4839924 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4839932 constant */
    /* @4839936 constant */
    /* @4839940 constant */
    /* @4839944 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4839952 constant */
    /* @4839956 constant */
    /* @4839960 constant */
    /* @4839964 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4839972 constant */
    /* @4839976 constant */
    /* @4839980 constant */
    /* @4839984 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4839992 constant */
    /* @4839996 constant */
    /* @4840000 constant */
    /* @4840004 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4840012 constant */
    /* @4840016 constant */
    /* @4840020 constant */
    /* @4840024 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(6), VAL(1920));
    /* @4840032 constant */
    /* @4840036 constant */
    /* @4840040 constant */
    /* @4840044 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(6), VAL(1080));
    /* @4840052 b */
    goto L_4840892;
    L_4840056: ;
    /* @4840056 call */
    GM_SITE(vm, 538, 4840056);
    /* @4840064 constant */
    /* @4840068 cmp */
    /* @4840072 bf */
    v25 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(1280));
    if (!TRUTH(v25)) goto L_4840096;
    /* @4840076 call */
    GM_SITE(vm, 538, 4840076);
    /* @4840084 constant */
    /* @4840088 cmp */
    /* @4840092 b */
    v26 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(800));
    p4840100_0 = v26;
    goto L_4840100;
    L_4840096: ;
    /* @4840096 constant */
    p4840100_0 = VAL(0);
    L_4840100: ;
    /* @4840100 bf */
    if (!TRUTH(p4840100_0)) goto L_4840288;
    /* @4840104 constant */
    /* @4840108 constant */
    /* @4840112 constant */
    /* @4840116 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4840124 constant */
    /* @4840128 constant */
    /* @4840132 constant */
    /* @4840136 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4840144 constant */
    /* @4840148 constant */
    /* @4840152 constant */
    /* @4840156 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4840164 constant */
    /* @4840168 constant */
    /* @4840172 constant */
    /* @4840176 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4840184 constant */
    /* @4840188 constant */
    /* @4840192 constant */
    /* @4840196 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(1));
    /* @4840204 constant */
    /* @4840208 constant */
    /* @4840212 constant */
    /* @4840216 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4840224 constant */
    /* @4840228 constant */
    /* @4840232 constant */
    /* @4840236 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4840244 constant */
    /* @4840248 constant */
    /* @4840252 constant */
    /* @4840256 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(1), VAL(1280));
    /* @4840264 constant */
    /* @4840268 constant */
    /* @4840272 constant */
    /* @4840276 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(1), VAL(800));
    /* @4840284 b */
    goto L_4840892;
    L_4840288: ;
    /* @4840288 call */
    GM_SITE(vm, 538, 4840288);
    /* @4840296 constant */
    /* @4840300 cmp */
    /* @4840304 bf */
    v27 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(2560));
    if (!TRUTH(v27)) goto L_4840328;
    /* @4840308 call */
    GM_SITE(vm, 538, 4840308);
    /* @4840316 constant */
    /* @4840320 cmp */
    /* @4840324 b */
    v28 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(1440));
    p4840332_0 = v28;
    goto L_4840332;
    L_4840328: ;
    /* @4840328 constant */
    p4840332_0 = VAL(0);
    L_4840332: ;
    /* @4840332 bf */
    if (!TRUTH(p4840332_0)) goto L_4840520;
    /* @4840336 constant */
    /* @4840340 constant */
    /* @4840344 constant */
    /* @4840348 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(1));
    /* @4840356 constant */
    /* @4840360 constant */
    /* @4840364 constant */
    /* @4840368 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4840376 constant */
    /* @4840380 constant */
    /* @4840384 constant */
    /* @4840388 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4840396 constant */
    /* @4840400 constant */
    /* @4840404 constant */
    /* @4840408 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4840416 constant */
    /* @4840420 constant */
    /* @4840424 constant */
    /* @4840428 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4840436 constant */
    /* @4840440 constant */
    /* @4840444 constant */
    /* @4840448 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4840456 constant */
    /* @4840460 constant */
    /* @4840464 constant */
    /* @4840468 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4840476 constant */
    /* @4840480 constant */
    /* @4840484 constant */
    /* @4840488 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(6), VAL(2560));
    /* @4840496 constant */
    /* @4840500 constant */
    /* @4840504 constant */
    /* @4840508 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(6), VAL(1440));
    /* @4840516 b */
    goto L_4840892;
    L_4840520: ;
    /* @4840520 call */
    GM_SITE(vm, 538, 4840520);
    /* @4840528 constant */
    /* @4840532 cmp */
    /* @4840536 bf */
    v29 = NUMBOOL(GM_CALL(vm, "display_get_width", 0) == VAL(2560));
    if (!TRUTH(v29)) goto L_4840560;
    /* @4840540 call */
    GM_SITE(vm, 538, 4840540);
    /* @4840548 constant */
    /* @4840552 cmp */
    /* @4840556 b */
    v30 = NUMBOOL(GM_CALL(vm, "display_get_height", 0) == VAL(1600));
    p4840564_0 = v30;
    goto L_4840564;
    L_4840560: ;
    /* @4840560 constant */
    p4840564_0 = VAL(0);
    L_4840564: ;
    /* @4840564 bf */
    if (!TRUTH(p4840564_0)) goto L_4840752;
    /* @4840568 constant */
    /* @4840572 constant */
    /* @4840576 constant */
    /* @4840580 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    /* @4840588 constant */
    /* @4840592 constant */
    /* @4840596 constant */
    /* @4840600 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4840608 constant */
    /* @4840612 constant */
    /* @4840616 constant */
    /* @4840620 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4840628 constant */
    /* @4840632 constant */
    /* @4840636 constant */
    /* @4840640 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(0));
    /* @4840648 constant */
    /* @4840652 constant */
    /* @4840656 constant */
    /* @4840660 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(1));
    /* @4840668 constant */
    /* @4840672 constant */
    /* @4840676 constant */
    /* @4840680 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4840688 constant */
    /* @4840692 constant */
    /* @4840696 constant */
    /* @4840700 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4840708 constant */
    /* @4840712 constant */
    /* @4840716 constant */
    /* @4840720 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_wport", VAL(1), VAL(2560));
    /* @4840728 constant */
    /* @4840732 constant */
    /* @4840736 constant */
    /* @4840740 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_hport", VAL(1), VAL(1600));
    /* @4840748 b */
    goto L_4840892;
    L_4840752: ;
    /* @4840752 constant */
    /* @4840756 constant */
    /* @4840760 constant */
    /* @4840764 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(0), VAL(1));
    /* @4840772 constant */
    /* @4840776 constant */
    /* @4840780 constant */
    /* @4840784 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(1), VAL(0));
    /* @4840792 constant */
    /* @4840796 constant */
    /* @4840800 constant */
    /* @4840804 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(2), VAL(0));
    /* @4840812 constant */
    /* @4840816 constant */
    /* @4840820 constant */
    /* @4840824 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(3), VAL(0));
    /* @4840832 constant */
    /* @4840836 constant */
    /* @4840840 constant */
    /* @4840844 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(4), VAL(0));
    /* @4840852 constant */
    /* @4840856 constant */
    /* @4840860 constant */
    /* @4840864 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(5), VAL(0));
    /* @4840872 constant */
    /* @4840876 constant */
    /* @4840880 constant */
    /* @4840884 store */
    GM_WRITE_ARR(vm, VAL(-1), "view_visible", VAL(6), VAL(0));
    L_4840892: ;
    return;
}
