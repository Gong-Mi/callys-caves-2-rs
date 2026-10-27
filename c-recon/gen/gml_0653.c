/* generated from CODE 653 (gml_Object_obj_lloydtutorial14_Draw_0), source start 4982424, end 4987284. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0653(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val v39;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    Val v55;
    Val v56;
    Val v57;
    Val v58;
    Val v59;
    Val v60;
    Val p4987268_0;
    Val v61;
    /* @4982424 constant */
    /* @4982428 load */
    /* @4982436 cast */
    /* @4982440 load */
    /* @4982448 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4982456 constant */
    /* @4982460 load */
    /* @4982468 cast */
    /* @4982472 load */
    /* @4982480 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4982488 load */
    /* @4982496 constant */
    /* @4982500 cmp */
    /* @4982504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4983032;
    /* @4982508 constant */
    /* @4982512 cast */
    /* @4982516 constant */
    /* @4982520 cast */
    /* @4982524 constant */
    /* @4982528 cast */
    /* @4982532 constant */
    /* @4982544 cast */
    /* @4982548 constant */
    /* @4982560 cast */
    /* @4982564 constant */
    /* @4982568 constant */
    /* @4982572 load */
    /* @4982580 constant */
    /* @4982584 constant */
    /* @4982588 load */
    /* @4982596 constant */
    /* @4982600 sub */
    /* @4982604 constant */
    /* @4982608 cast */
    /* @4982612 constant */
    /* @4982616 cast */
    /* @4982620 call */
    GM_SITE(vm, 653, 4982620);
    /* @4982628 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4982632 constant */
    /* @4982636 cast */
    /* @4982640 constant */
    /* @4982644 cast */
    /* @4982648 constant */
    /* @4982652 cast */
    /* @4982656 constant */
    /* @4982660 cast */
    /* @4982664 constant */
    /* @4982668 cast */
    /* @4982672 constant */
    /* @4982676 load */
    /* @4982684 cast */
    /* @4982688 load */
    /* @4982696 constant */
    /* @4982700 add */
    /* @4982704 constant */
    /* @4982708 load */
    /* @4982716 cast */
    /* @4982720 load */
    /* @4982728 constant */
    /* @4982732 add */
    /* @4982736 constant */
    /* @4982740 cast */
    /* @4982744 constant */
    /* @4982748 cast */
    /* @4982752 call */
    GM_SITE(vm, 653, 4982752);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4982760 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4982764 constant */
    /* @4982768 cast */
    /* @4982772 constant */
    /* @4982776 cast */
    /* @4982780 constant */
    /* @4982784 cast */
    /* @4982788 constant */
    /* @4982792 cast */
    /* @4982796 constant */
    /* @4982800 cast */
    /* @4982804 constant */
    /* @4982808 load */
    /* @4982816 cast */
    /* @4982820 load */
    /* @4982828 constant */
    /* @4982832 add */
    /* @4982836 constant */
    /* @4982840 load */
    /* @4982848 cast */
    /* @4982852 load */
    /* @4982860 constant */
    /* @4982864 add */
    /* @4982868 constant */
    /* @4982872 cast */
    /* @4982876 constant */
    /* @4982880 cast */
    /* @4982884 call */
    GM_SITE(vm, 653, 4982884);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4982892 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4982896 load */
    /* @4982904 constant */
    /* @4982908 cmp */
    /* @4982912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4983032;
    /* @4982916 constant */
    /* @4982920 cast */
    /* @4982924 call */
    GM_SITE(vm, 653, 4982924);
    /* @4982932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4982936 constant */
    /* @4982944 cast */
    /* @4982948 call */
    GM_SITE(vm, 653, 4982948);
    /* @4982956 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4982960 string */
    /* @4982968 cast */
    /* @4982972 constant */
    /* @4982976 constant */
    /* @4982980 load */
    /* @4982988 constant */
    /* @4982992 add */
    /* @4982996 constant */
    /* @4983000 constant */
    /* @4983004 load */
    /* @4983012 constant */
    /* @4983016 add */
    /* @4983020 call */
    GM_SITE(vm, 653, 4983020);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4983028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4983032: ;
    /* @4983032 load */
    /* @4983040 constant */
    /* @4983044 cmp */
    /* @4983048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4983576;
    /* @4983052 constant */
    /* @4983056 cast */
    /* @4983060 constant */
    /* @4983064 cast */
    /* @4983068 constant */
    /* @4983072 cast */
    /* @4983076 constant */
    /* @4983088 cast */
    /* @4983092 constant */
    /* @4983104 cast */
    /* @4983108 constant */
    /* @4983112 constant */
    /* @4983116 load */
    /* @4983124 constant */
    /* @4983128 constant */
    /* @4983132 load */
    /* @4983140 constant */
    /* @4983144 sub */
    /* @4983148 constant */
    /* @4983152 cast */
    /* @4983156 constant */
    /* @4983160 cast */
    /* @4983164 call */
    GM_SITE(vm, 653, 4983164);
    /* @4983172 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4983176 constant */
    /* @4983180 cast */
    /* @4983184 constant */
    /* @4983188 cast */
    /* @4983192 constant */
    /* @4983196 cast */
    /* @4983200 constant */
    /* @4983204 cast */
    /* @4983208 constant */
    /* @4983212 cast */
    /* @4983216 constant */
    /* @4983220 load */
    /* @4983228 cast */
    /* @4983232 load */
    /* @4983240 constant */
    /* @4983244 add */
    /* @4983248 constant */
    /* @4983252 load */
    /* @4983260 cast */
    /* @4983264 load */
    /* @4983272 constant */
    /* @4983276 add */
    /* @4983280 constant */
    /* @4983284 cast */
    /* @4983288 constant */
    /* @4983292 cast */
    /* @4983296 call */
    GM_SITE(vm, 653, 4983296);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4983304 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4983308 constant */
    /* @4983312 cast */
    /* @4983316 constant */
    /* @4983320 cast */
    /* @4983324 constant */
    /* @4983328 cast */
    /* @4983332 constant */
    /* @4983336 cast */
    /* @4983340 constant */
    /* @4983344 cast */
    /* @4983348 constant */
    /* @4983352 load */
    /* @4983360 cast */
    /* @4983364 load */
    /* @4983372 constant */
    /* @4983376 add */
    /* @4983380 constant */
    /* @4983384 load */
    /* @4983392 cast */
    /* @4983396 load */
    /* @4983404 constant */
    /* @4983408 add */
    /* @4983412 constant */
    /* @4983416 cast */
    /* @4983420 constant */
    /* @4983424 cast */
    /* @4983428 call */
    GM_SITE(vm, 653, 4983428);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4983436 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4983440 load */
    /* @4983448 constant */
    /* @4983452 cmp */
    /* @4983456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4983576;
    /* @4983460 constant */
    /* @4983464 cast */
    /* @4983468 call */
    GM_SITE(vm, 653, 4983468);
    /* @4983476 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4983480 constant */
    /* @4983488 cast */
    /* @4983492 call */
    GM_SITE(vm, 653, 4983492);
    /* @4983500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4983504 string */
    /* @4983512 cast */
    /* @4983516 constant */
    /* @4983520 constant */
    /* @4983524 load */
    /* @4983532 constant */
    /* @4983536 add */
    /* @4983540 constant */
    /* @4983544 constant */
    /* @4983548 load */
    /* @4983556 constant */
    /* @4983560 add */
    /* @4983564 call */
    GM_SITE(vm, 653, 4983564);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4983572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4983576: ;
    /* @4983576 load */
    /* @4983584 constant */
    /* @4983588 cmp */
    /* @4983592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4984120;
    /* @4983596 constant */
    /* @4983600 cast */
    /* @4983604 constant */
    /* @4983608 cast */
    /* @4983612 constant */
    /* @4983616 cast */
    /* @4983620 constant */
    /* @4983632 cast */
    /* @4983636 constant */
    /* @4983648 cast */
    /* @4983652 constant */
    /* @4983656 constant */
    /* @4983660 load */
    /* @4983668 constant */
    /* @4983672 constant */
    /* @4983676 load */
    /* @4983684 constant */
    /* @4983688 sub */
    /* @4983692 constant */
    /* @4983696 cast */
    /* @4983700 constant */
    /* @4983704 cast */
    /* @4983708 call */
    GM_SITE(vm, 653, 4983708);
    /* @4983716 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4983720 constant */
    /* @4983724 cast */
    /* @4983728 constant */
    /* @4983732 cast */
    /* @4983736 constant */
    /* @4983740 cast */
    /* @4983744 constant */
    /* @4983748 cast */
    /* @4983752 constant */
    /* @4983756 cast */
    /* @4983760 constant */
    /* @4983764 load */
    /* @4983772 cast */
    /* @4983776 load */
    /* @4983784 constant */
    /* @4983788 add */
    /* @4983792 constant */
    /* @4983796 load */
    /* @4983804 cast */
    /* @4983808 load */
    /* @4983816 constant */
    /* @4983820 add */
    /* @4983824 constant */
    /* @4983828 cast */
    /* @4983832 constant */
    /* @4983836 cast */
    /* @4983840 call */
    GM_SITE(vm, 653, 4983840);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4983848 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4983852 constant */
    /* @4983856 cast */
    /* @4983860 constant */
    /* @4983864 cast */
    /* @4983868 constant */
    /* @4983872 cast */
    /* @4983876 constant */
    /* @4983880 cast */
    /* @4983884 constant */
    /* @4983888 cast */
    /* @4983892 constant */
    /* @4983896 load */
    /* @4983904 cast */
    /* @4983908 load */
    /* @4983916 constant */
    /* @4983920 add */
    /* @4983924 constant */
    /* @4983928 load */
    /* @4983936 cast */
    /* @4983940 load */
    /* @4983948 constant */
    /* @4983952 add */
    /* @4983956 constant */
    /* @4983960 cast */
    /* @4983964 constant */
    /* @4983968 cast */
    /* @4983972 call */
    GM_SITE(vm, 653, 4983972);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4983980 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4983984 load */
    /* @4983992 constant */
    /* @4983996 cmp */
    /* @4984000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4984120;
    /* @4984004 constant */
    /* @4984008 cast */
    /* @4984012 call */
    GM_SITE(vm, 653, 4984012);
    /* @4984020 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4984024 constant */
    /* @4984032 cast */
    /* @4984036 call */
    GM_SITE(vm, 653, 4984036);
    /* @4984044 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4984048 string */
    /* @4984056 cast */
    /* @4984060 constant */
    /* @4984064 constant */
    /* @4984068 load */
    /* @4984076 constant */
    /* @4984080 add */
    /* @4984084 constant */
    /* @4984088 constant */
    /* @4984092 load */
    /* @4984100 constant */
    /* @4984104 add */
    /* @4984108 call */
    GM_SITE(vm, 653, 4984108);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4984116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4984120: ;
    /* @4984120 load */
    /* @4984128 constant */
    /* @4984132 cmp */
    /* @4984136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4984664;
    /* @4984140 constant */
    /* @4984144 cast */
    /* @4984148 constant */
    /* @4984152 cast */
    /* @4984156 constant */
    /* @4984160 cast */
    /* @4984164 constant */
    /* @4984176 cast */
    /* @4984180 constant */
    /* @4984192 cast */
    /* @4984196 constant */
    /* @4984200 constant */
    /* @4984204 load */
    /* @4984212 constant */
    /* @4984216 constant */
    /* @4984220 load */
    /* @4984228 constant */
    /* @4984232 sub */
    /* @4984236 constant */
    /* @4984240 cast */
    /* @4984244 constant */
    /* @4984248 cast */
    /* @4984252 call */
    GM_SITE(vm, 653, 4984252);
    /* @4984260 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4984264 constant */
    /* @4984268 cast */
    /* @4984272 constant */
    /* @4984276 cast */
    /* @4984280 constant */
    /* @4984284 cast */
    /* @4984288 constant */
    /* @4984292 cast */
    /* @4984296 constant */
    /* @4984300 cast */
    /* @4984304 constant */
    /* @4984308 load */
    /* @4984316 cast */
    /* @4984320 load */
    /* @4984328 constant */
    /* @4984332 add */
    /* @4984336 constant */
    /* @4984340 load */
    /* @4984348 cast */
    /* @4984352 load */
    /* @4984360 constant */
    /* @4984364 add */
    /* @4984368 constant */
    /* @4984372 cast */
    /* @4984376 constant */
    /* @4984380 cast */
    /* @4984384 call */
    GM_SITE(vm, 653, 4984384);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4984392 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4984396 constant */
    /* @4984400 cast */
    /* @4984404 constant */
    /* @4984408 cast */
    /* @4984412 constant */
    /* @4984416 cast */
    /* @4984420 constant */
    /* @4984424 cast */
    /* @4984428 constant */
    /* @4984432 cast */
    /* @4984436 constant */
    /* @4984440 load */
    /* @4984448 cast */
    /* @4984452 load */
    /* @4984460 constant */
    /* @4984464 add */
    /* @4984468 constant */
    /* @4984472 load */
    /* @4984480 cast */
    /* @4984484 load */
    /* @4984492 constant */
    /* @4984496 add */
    /* @4984500 constant */
    /* @4984504 cast */
    /* @4984508 constant */
    /* @4984512 cast */
    /* @4984516 call */
    GM_SITE(vm, 653, 4984516);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4984524 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4984528 load */
    /* @4984536 constant */
    /* @4984540 cmp */
    /* @4984544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4984664;
    /* @4984548 constant */
    /* @4984552 cast */
    /* @4984556 call */
    GM_SITE(vm, 653, 4984556);
    /* @4984564 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4984568 constant */
    /* @4984576 cast */
    /* @4984580 call */
    GM_SITE(vm, 653, 4984580);
    /* @4984588 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4984592 string */
    /* @4984600 cast */
    /* @4984604 constant */
    /* @4984608 constant */
    /* @4984612 load */
    /* @4984620 constant */
    /* @4984624 add */
    /* @4984628 constant */
    /* @4984632 constant */
    /* @4984636 load */
    /* @4984644 constant */
    /* @4984648 add */
    /* @4984652 call */
    GM_SITE(vm, 653, 4984652);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4984660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4984664: ;
    /* @4984664 load */
    /* @4984672 constant */
    /* @4984676 cmp */
    /* @4984680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4985208;
    /* @4984684 constant */
    /* @4984688 cast */
    /* @4984692 constant */
    /* @4984696 cast */
    /* @4984700 constant */
    /* @4984704 cast */
    /* @4984708 constant */
    /* @4984720 cast */
    /* @4984724 constant */
    /* @4984736 cast */
    /* @4984740 constant */
    /* @4984744 constant */
    /* @4984748 load */
    /* @4984756 constant */
    /* @4984760 constant */
    /* @4984764 load */
    /* @4984772 constant */
    /* @4984776 sub */
    /* @4984780 constant */
    /* @4984784 cast */
    /* @4984788 constant */
    /* @4984792 cast */
    /* @4984796 call */
    GM_SITE(vm, 653, 4984796);
    /* @4984804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4984808 constant */
    /* @4984812 cast */
    /* @4984816 constant */
    /* @4984820 cast */
    /* @4984824 constant */
    /* @4984828 cast */
    /* @4984832 constant */
    /* @4984836 cast */
    /* @4984840 constant */
    /* @4984844 cast */
    /* @4984848 constant */
    /* @4984852 load */
    /* @4984860 cast */
    /* @4984864 load */
    /* @4984872 constant */
    /* @4984876 add */
    /* @4984880 constant */
    /* @4984884 load */
    /* @4984892 cast */
    /* @4984896 load */
    /* @4984904 constant */
    /* @4984908 add */
    /* @4984912 constant */
    /* @4984916 cast */
    /* @4984920 constant */
    /* @4984924 cast */
    /* @4984928 call */
    GM_SITE(vm, 653, 4984928);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4984936 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4984940 constant */
    /* @4984944 cast */
    /* @4984948 constant */
    /* @4984952 cast */
    /* @4984956 constant */
    /* @4984960 cast */
    /* @4984964 constant */
    /* @4984968 cast */
    /* @4984972 constant */
    /* @4984976 cast */
    /* @4984980 constant */
    /* @4984984 load */
    /* @4984992 cast */
    /* @4984996 load */
    /* @4985004 constant */
    /* @4985008 add */
    /* @4985012 constant */
    /* @4985016 load */
    /* @4985024 cast */
    /* @4985028 load */
    /* @4985036 constant */
    /* @4985040 add */
    /* @4985044 constant */
    /* @4985048 cast */
    /* @4985052 constant */
    /* @4985056 cast */
    /* @4985060 call */
    GM_SITE(vm, 653, 4985060);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4985068 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4985072 load */
    /* @4985080 constant */
    /* @4985084 cmp */
    /* @4985088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4985208;
    /* @4985092 constant */
    /* @4985096 cast */
    /* @4985100 call */
    GM_SITE(vm, 653, 4985100);
    /* @4985108 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4985112 constant */
    /* @4985120 cast */
    /* @4985124 call */
    GM_SITE(vm, 653, 4985124);
    /* @4985132 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4985136 string */
    /* @4985144 cast */
    /* @4985148 constant */
    /* @4985152 constant */
    /* @4985156 load */
    /* @4985164 constant */
    /* @4985168 add */
    /* @4985172 constant */
    /* @4985176 constant */
    /* @4985180 load */
    /* @4985188 constant */
    /* @4985192 add */
    /* @4985196 call */
    GM_SITE(vm, 653, 4985196);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4985204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4985208: ;
    /* @4985208 load */
    /* @4985216 constant */
    /* @4985220 cmp */
    /* @4985224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4985752;
    /* @4985228 constant */
    /* @4985232 cast */
    /* @4985236 constant */
    /* @4985240 cast */
    /* @4985244 constant */
    /* @4985248 cast */
    /* @4985252 constant */
    /* @4985264 cast */
    /* @4985268 constant */
    /* @4985280 cast */
    /* @4985284 constant */
    /* @4985288 constant */
    /* @4985292 load */
    /* @4985300 constant */
    /* @4985304 constant */
    /* @4985308 load */
    /* @4985316 constant */
    /* @4985320 sub */
    /* @4985324 constant */
    /* @4985328 cast */
    /* @4985332 constant */
    /* @4985336 cast */
    /* @4985340 call */
    GM_SITE(vm, 653, 4985340);
    /* @4985348 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4985352 constant */
    /* @4985356 cast */
    /* @4985360 constant */
    /* @4985364 cast */
    /* @4985368 constant */
    /* @4985372 cast */
    /* @4985376 constant */
    /* @4985380 cast */
    /* @4985384 constant */
    /* @4985388 cast */
    /* @4985392 constant */
    /* @4985396 load */
    /* @4985404 cast */
    /* @4985408 load */
    /* @4985416 constant */
    /* @4985420 add */
    /* @4985424 constant */
    /* @4985428 load */
    /* @4985436 cast */
    /* @4985440 load */
    /* @4985448 constant */
    /* @4985452 add */
    /* @4985456 constant */
    /* @4985460 cast */
    /* @4985464 constant */
    /* @4985468 cast */
    /* @4985472 call */
    GM_SITE(vm, 653, 4985472);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4985480 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4985484 constant */
    /* @4985488 cast */
    /* @4985492 constant */
    /* @4985496 cast */
    /* @4985500 constant */
    /* @4985504 cast */
    /* @4985508 constant */
    /* @4985512 cast */
    /* @4985516 constant */
    /* @4985520 cast */
    /* @4985524 constant */
    /* @4985528 load */
    /* @4985536 cast */
    /* @4985540 load */
    /* @4985548 constant */
    /* @4985552 add */
    /* @4985556 constant */
    /* @4985560 load */
    /* @4985568 cast */
    /* @4985572 load */
    /* @4985580 constant */
    /* @4985584 add */
    /* @4985588 constant */
    /* @4985592 cast */
    /* @4985596 constant */
    /* @4985600 cast */
    /* @4985604 call */
    GM_SITE(vm, 653, 4985604);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4985612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4985616 load */
    /* @4985624 constant */
    /* @4985628 cmp */
    /* @4985632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4985752;
    /* @4985636 constant */
    /* @4985640 cast */
    /* @4985644 call */
    GM_SITE(vm, 653, 4985644);
    /* @4985652 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4985656 constant */
    /* @4985664 cast */
    /* @4985668 call */
    GM_SITE(vm, 653, 4985668);
    /* @4985676 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4985680 string */
    /* @4985688 cast */
    /* @4985692 constant */
    /* @4985696 constant */
    /* @4985700 load */
    /* @4985708 constant */
    /* @4985712 add */
    /* @4985716 constant */
    /* @4985720 constant */
    /* @4985724 load */
    /* @4985732 constant */
    /* @4985736 add */
    /* @4985740 call */
    GM_SITE(vm, 653, 4985740);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4985748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4985752: ;
    /* @4985752 load */
    /* @4985760 constant */
    /* @4985764 cmp */
    /* @4985768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4987212;
    /* @4985772 load */
    /* @4985780 constant */
    /* @4985784 cmp */
    /* @4985788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4986012;
    /* @4985792 constant */
    /* @4985796 cast */
    /* @4985800 call */
    GM_SITE(vm, 653, 4985800);
    /* @4985808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4985812 constant */
    /* @4985820 cast */
    /* @4985824 call */
    GM_SITE(vm, 653, 4985824);
    /* @4985832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4985836 string */
    /* @4985844 cast */
    /* @4985848 constant */
    /* @4985852 load */
    /* @4985860 cast */
    /* @4985864 load */
    /* @4985872 constant */
    /* @4985876 add */
    /* @4985880 constant */
    /* @4985884 load */
    /* @4985892 cast */
    /* @4985896 load */
    /* @4985904 constant */
    /* @4985908 add */
    /* @4985912 call */
    GM_SITE(vm, 653, 4985912);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4985920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1142)));
    /* @4985924 string */
    /* @4985932 cast */
    /* @4985936 constant */
    /* @4985940 load */
    /* @4985948 cast */
    /* @4985952 load */
    /* @4985960 constant */
    /* @4985964 add */
    /* @4985968 constant */
    /* @4985972 load */
    /* @4985980 cast */
    /* @4985984 load */
    /* @4985992 constant */
    /* @4985996 add */
    /* @4986000 call */
    GM_SITE(vm, 653, 4986000);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4986008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1143)));
    L_4986012: ;
    /* @4986012 load */
    /* @4986020 constant */
    /* @4986024 cmp */
    /* @4986028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4986252;
    /* @4986032 constant */
    /* @4986036 cast */
    /* @4986040 call */
    GM_SITE(vm, 653, 4986040);
    /* @4986048 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4986052 constant */
    /* @4986060 cast */
    /* @4986064 call */
    GM_SITE(vm, 653, 4986064);
    /* @4986072 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4986076 string */
    /* @4986084 cast */
    /* @4986088 constant */
    /* @4986092 load */
    /* @4986100 cast */
    /* @4986104 load */
    /* @4986112 constant */
    /* @4986116 add */
    /* @4986120 constant */
    /* @4986124 load */
    /* @4986132 cast */
    /* @4986136 load */
    /* @4986144 constant */
    /* @4986148 add */
    /* @4986152 call */
    GM_SITE(vm, 653, 4986152);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4986160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1142)));
    /* @4986164 string */
    /* @4986172 cast */
    /* @4986176 constant */
    /* @4986180 load */
    /* @4986188 cast */
    /* @4986192 load */
    /* @4986200 constant */
    /* @4986204 add */
    /* @4986208 constant */
    /* @4986212 load */
    /* @4986220 cast */
    /* @4986224 load */
    /* @4986232 constant */
    /* @4986236 add */
    /* @4986240 call */
    GM_SITE(vm, 653, 4986240);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4986248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1143)));
    L_4986252: ;
    /* @4986252 load */
    /* @4986260 constant */
    /* @4986264 cmp */
    /* @4986268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4986492;
    /* @4986272 constant */
    /* @4986276 cast */
    /* @4986280 call */
    GM_SITE(vm, 653, 4986280);
    /* @4986288 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4986292 constant */
    /* @4986300 cast */
    /* @4986304 call */
    GM_SITE(vm, 653, 4986304);
    /* @4986312 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4986316 string */
    /* @4986324 cast */
    /* @4986328 constant */
    /* @4986332 load */
    /* @4986340 cast */
    /* @4986344 load */
    /* @4986352 constant */
    /* @4986356 add */
    /* @4986360 constant */
    /* @4986364 load */
    /* @4986372 cast */
    /* @4986376 load */
    /* @4986384 constant */
    /* @4986388 add */
    /* @4986392 call */
    GM_SITE(vm, 653, 4986392);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4986400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1142)));
    /* @4986404 string */
    /* @4986412 cast */
    /* @4986416 constant */
    /* @4986420 load */
    /* @4986428 cast */
    /* @4986432 load */
    /* @4986440 constant */
    /* @4986444 add */
    /* @4986448 constant */
    /* @4986452 load */
    /* @4986460 cast */
    /* @4986464 load */
    /* @4986472 constant */
    /* @4986476 add */
    /* @4986480 call */
    GM_SITE(vm, 653, 4986480);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4986488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1143)));
    L_4986492: ;
    /* @4986492 load */
    /* @4986500 constant */
    /* @4986504 cmp */
    /* @4986508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4986732;
    /* @4986512 constant */
    /* @4986516 cast */
    /* @4986520 call */
    GM_SITE(vm, 653, 4986520);
    /* @4986528 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4986532 constant */
    /* @4986540 cast */
    /* @4986544 call */
    GM_SITE(vm, 653, 4986544);
    /* @4986552 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4986556 string */
    /* @4986564 cast */
    /* @4986568 constant */
    /* @4986572 load */
    /* @4986580 cast */
    /* @4986584 load */
    /* @4986592 constant */
    /* @4986596 add */
    /* @4986600 constant */
    /* @4986604 load */
    /* @4986612 cast */
    /* @4986616 load */
    /* @4986624 constant */
    /* @4986628 add */
    /* @4986632 call */
    GM_SITE(vm, 653, 4986632);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4986640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1142)));
    /* @4986644 string */
    /* @4986652 cast */
    /* @4986656 constant */
    /* @4986660 load */
    /* @4986668 cast */
    /* @4986672 load */
    /* @4986680 constant */
    /* @4986684 add */
    /* @4986688 constant */
    /* @4986692 load */
    /* @4986700 cast */
    /* @4986704 load */
    /* @4986712 constant */
    /* @4986716 add */
    /* @4986720 call */
    GM_SITE(vm, 653, 4986720);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4986728 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1143)));
    L_4986732: ;
    /* @4986732 load */
    /* @4986740 constant */
    /* @4986744 cmp */
    /* @4986748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4986972;
    /* @4986752 constant */
    /* @4986756 cast */
    /* @4986760 call */
    GM_SITE(vm, 653, 4986760);
    /* @4986768 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4986772 constant */
    /* @4986780 cast */
    /* @4986784 call */
    GM_SITE(vm, 653, 4986784);
    /* @4986792 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4986796 string */
    /* @4986804 cast */
    /* @4986808 constant */
    /* @4986812 load */
    /* @4986820 cast */
    /* @4986824 load */
    /* @4986832 constant */
    /* @4986836 add */
    /* @4986840 constant */
    /* @4986844 load */
    /* @4986852 cast */
    /* @4986856 load */
    /* @4986864 constant */
    /* @4986868 add */
    /* @4986872 call */
    GM_SITE(vm, 653, 4986872);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4986880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1142)));
    /* @4986884 string */
    /* @4986892 cast */
    /* @4986896 constant */
    /* @4986900 load */
    /* @4986908 cast */
    /* @4986912 load */
    /* @4986920 constant */
    /* @4986924 add */
    /* @4986928 constant */
    /* @4986932 load */
    /* @4986940 cast */
    /* @4986944 load */
    /* @4986952 constant */
    /* @4986956 add */
    /* @4986960 call */
    GM_SITE(vm, 653, 4986960);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4986968 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1143)));
    L_4986972: ;
    /* @4986972 load */
    /* @4986980 constant */
    /* @4986984 cmp */
    /* @4986988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4987212;
    /* @4986992 constant */
    /* @4986996 cast */
    /* @4987000 call */
    GM_SITE(vm, 653, 4987000);
    /* @4987008 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4987012 constant */
    /* @4987020 cast */
    /* @4987024 call */
    GM_SITE(vm, 653, 4987024);
    /* @4987032 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4987036 string */
    /* @4987044 cast */
    /* @4987048 constant */
    /* @4987052 load */
    /* @4987060 cast */
    /* @4987064 load */
    /* @4987072 constant */
    /* @4987076 add */
    /* @4987080 constant */
    /* @4987084 load */
    /* @4987092 cast */
    /* @4987096 load */
    /* @4987104 constant */
    /* @4987108 add */
    /* @4987112 call */
    GM_SITE(vm, 653, 4987112);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4987120 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1142)));
    /* @4987124 string */
    /* @4987132 cast */
    /* @4987136 constant */
    /* @4987140 load */
    /* @4987148 cast */
    /* @4987152 load */
    /* @4987160 constant */
    /* @4987164 add */
    /* @4987168 constant */
    /* @4987172 load */
    /* @4987180 cast */
    /* @4987184 load */
    /* @4987192 constant */
    /* @4987196 add */
    /* @4987200 call */
    GM_SITE(vm, 653, 4987200);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4987208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1143)));
    L_4987212: ;
    /* @4987212 load */
    /* @4987220 constant */
    /* @4987224 cmp */
    /* @4987228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4987264;
    /* @4987232 constant */
    /* @4987236 cast */
    /* @4987240 constant */
    /* @4987244 cast */
    /* @4987248 call */
    GM_SITE(vm, 653, 4987248);
    /* @4987256 cast */
    /* @4987260 b */
    v61 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4987268_0 = v61;
    goto L_4987268;
    L_4987264: ;
    /* @4987264 constant */
    p4987268_0 = VAL(0);
    L_4987268: ;
    /* @4987268 bf */
    if (!TRUTH(p4987268_0)) goto L_4987284;
    /* @4987272 call */
    GM_SITE(vm, 653, 4987272);
    /* @4987280 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4987284: ;
    return;
}
