/* generated from CODE 487 (gml_Object_obj_restoredata_Draw_0), source start 4676704, end 4678144. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0487(GmVM* vm) {
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
    /* @4676704 load */
    /* @4676712 constant */
    /* @4676716 cmp */
    /* @4676720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4676900;
    /* @4676724 constant */
    /* @4676728 cast */
    /* @4676732 constant */
    /* @4676736 cast */
    /* @4676740 constant */
    /* @4676744 cast */
    /* @4676748 constant */
    /* @4676752 cast */
    /* @4676756 constant */
    /* @4676760 cast */
    /* @4676764 load */
    /* @4676772 load */
    /* @4676780 constant */
    /* @4676784 cast */
    /* @4676788 constant */
    /* @4676792 cast */
    /* @4676796 call */
    GM_SITE(vm, 487, 4676796);
    /* @4676804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4676808 constant */
    /* @4676812 cast */
    /* @4676816 call */
    GM_SITE(vm, 487, 4676816);
    /* @4676824 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4676828 constant */
    /* @4676836 cast */
    /* @4676840 call */
    GM_SITE(vm, 487, 4676840);
    /* @4676848 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4676852 string */
    /* @4676860 cast */
    /* @4676864 load */
    /* @4676872 load */
    /* @4676880 constant */
    /* @4676884 add */
    /* @4676888 call */
    GM_SITE(vm, 487, 4676888);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4676896 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(873)));
    L_4676900: ;
    /* @4676900 load */
    /* @4676908 constant */
    /* @4676912 cmp */
    /* @4676916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4677184;
    /* @4676920 constant */
    /* @4676924 constant */
    /* @4676928 load */
    /* @4676936 constant */
    /* @4676940 add */
    /* @4676944 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(5));
    GM_WRITE(vm, -1, "x", v2);
    /* @4676952 constant */
    /* @4676956 constant */
    /* @4676960 load */
    /* @4676968 constant */
    /* @4676972 add */
    /* @4676976 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "y", v3);
    /* @4676984 constant */
    /* @4676988 cast */
    /* @4676992 constant */
    /* @4676996 cast */
    /* @4677000 constant */
    /* @4677004 cast */
    /* @4677008 constant */
    /* @4677020 cast */
    /* @4677024 constant */
    /* @4677036 cast */
    /* @4677040 load */
    /* @4677048 load */
    /* @4677056 constant */
    /* @4677060 cast */
    /* @4677064 constant */
    /* @4677068 cast */
    /* @4677072 call */
    GM_SITE(vm, 487, 4677072);
    /* @4677080 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4677084 constant */
    /* @4677088 cast */
    /* @4677092 call */
    GM_SITE(vm, 487, 4677092);
    /* @4677100 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4677104 constant */
    /* @4677112 cast */
    /* @4677116 call */
    GM_SITE(vm, 487, 4677116);
    /* @4677124 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4677128 string */
    /* @4677136 cast */
    /* @4677140 load */
    /* @4677148 constant */
    /* @4677152 add */
    /* @4677156 load */
    /* @4677164 constant */
    /* @4677168 add */
    /* @4677172 call */
    GM_SITE(vm, 487, 4677172);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4677180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, v5, STR_REF(873)));
    L_4677184: ;
    /* @4677184 load */
    /* @4677192 constant */
    /* @4677196 cmp */
    /* @4677200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4677404;
    /* @4677204 constant */
    /* @4677208 constant */
    /* @4677212 load */
    /* @4677220 constant */
    /* @4677224 add */
    /* @4677228 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(30));
    GM_WRITE(vm, -1, "x", v6);
    /* @4677236 constant */
    /* @4677240 constant */
    /* @4677244 load */
    /* @4677252 constant */
    /* @4677256 add */
    /* @4677260 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "y", v7);
    /* @4677268 load */
    /* @4677276 load */
    /* @4677284 constant */
    /* @4677288 cast */
    /* @4677292 constant */
    /* @4677296 cast */
    /* @4677300 call */
    GM_SITE(vm, 487, 4677300);
    /* @4677308 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4677312 constant */
    /* @4677316 cast */
    /* @4677320 call */
    GM_SITE(vm, 487, 4677320);
    /* @4677328 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4677332 constant */
    /* @4677340 cast */
    /* @4677344 call */
    GM_SITE(vm, 487, 4677344);
    /* @4677352 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4677356 string */
    /* @4677364 cast */
    /* @4677368 load */
    /* @4677376 load */
    /* @4677384 constant */
    /* @4677388 add */
    /* @4677392 call */
    GM_SITE(vm, 487, 4677392);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4677400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, GM_READ(vm, -1, "y"), STR_REF(873)));
    L_4677404: ;
    /* @4677404 load */
    /* @4677412 constant */
    /* @4677416 cmp */
    /* @4677420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4677624;
    /* @4677424 constant */
    /* @4677428 constant */
    /* @4677432 load */
    /* @4677440 constant */
    /* @4677444 add */
    /* @4677448 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(30));
    GM_WRITE(vm, -1, "x", v9);
    /* @4677456 constant */
    /* @4677460 constant */
    /* @4677464 load */
    /* @4677472 constant */
    /* @4677476 add */
    /* @4677480 store */
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "y", v10);
    /* @4677488 load */
    /* @4677496 load */
    /* @4677504 constant */
    /* @4677508 cast */
    /* @4677512 constant */
    /* @4677516 cast */
    /* @4677520 call */
    GM_SITE(vm, 487, 4677520);
    /* @4677528 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4677532 constant */
    /* @4677536 cast */
    /* @4677540 call */
    GM_SITE(vm, 487, 4677540);
    /* @4677548 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4677552 constant */
    /* @4677560 cast */
    /* @4677564 call */
    GM_SITE(vm, 487, 4677564);
    /* @4677572 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4677576 string */
    /* @4677584 cast */
    /* @4677588 load */
    /* @4677596 load */
    /* @4677604 constant */
    /* @4677608 add */
    /* @4677612 call */
    GM_SITE(vm, 487, 4677612);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4677620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, GM_READ(vm, -1, "y"), STR_REF(873)));
    L_4677624: ;
    /* @4677624 load */
    /* @4677632 constant */
    /* @4677636 cmp */
    /* @4677640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4677884;
    /* @4677644 constant */
    /* @4677648 constant */
    /* @4677652 load */
    /* @4677660 constant */
    /* @4677664 add */
    /* @4677668 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(50));
    GM_WRITE(vm, -1, "x", v12);
    /* @4677676 constant */
    /* @4677680 constant */
    /* @4677684 load */
    /* @4677692 constant */
    /* @4677696 add */
    /* @4677700 store */
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v13);
    /* @4677708 constant */
    /* @4677712 cast */
    /* @4677716 constant */
    /* @4677720 cast */
    /* @4677724 constant */
    /* @4677728 cast */
    /* @4677732 constant */
    /* @4677736 cast */
    /* @4677740 constant */
    /* @4677744 cast */
    /* @4677748 load */
    /* @4677756 load */
    /* @4677764 constant */
    /* @4677768 cast */
    /* @4677772 constant */
    /* @4677776 cast */
    /* @4677780 call */
    GM_SITE(vm, 487, 4677780);
    /* @4677788 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4677792 constant */
    /* @4677796 cast */
    /* @4677800 call */
    GM_SITE(vm, 487, 4677800);
    /* @4677808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4677812 constant */
    /* @4677820 cast */
    /* @4677824 call */
    GM_SITE(vm, 487, 4677824);
    /* @4677832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4677836 string */
    /* @4677844 cast */
    /* @4677848 load */
    /* @4677856 load */
    /* @4677864 constant */
    /* @4677868 add */
    /* @4677872 call */
    GM_SITE(vm, 487, 4677872);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4677880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v14, GM_READ(vm, -1, "y"), STR_REF(873)));
    L_4677884: ;
    /* @4677884 load */
    /* @4677892 constant */
    /* @4677896 cmp */
    /* @4677900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4678144;
    /* @4677904 constant */
    /* @4677908 constant */
    /* @4677912 load */
    /* @4677920 constant */
    /* @4677924 add */
    /* @4677928 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(50));
    GM_WRITE(vm, -1, "x", v15);
    /* @4677936 constant */
    /* @4677940 constant */
    /* @4677944 load */
    /* @4677952 constant */
    /* @4677956 add */
    /* @4677960 store */
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    GM_WRITE(vm, -1, "y", v16);
    /* @4677968 constant */
    /* @4677972 cast */
    /* @4677976 constant */
    /* @4677980 cast */
    /* @4677984 constant */
    /* @4677988 cast */
    /* @4677992 constant */
    /* @4677996 cast */
    /* @4678000 constant */
    /* @4678004 cast */
    /* @4678008 load */
    /* @4678016 load */
    /* @4678024 constant */
    /* @4678028 cast */
    /* @4678032 constant */
    /* @4678036 cast */
    /* @4678040 call */
    GM_SITE(vm, 487, 4678040);
    /* @4678048 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4678052 constant */
    /* @4678056 cast */
    /* @4678060 call */
    GM_SITE(vm, 487, 4678060);
    /* @4678068 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4678072 constant */
    /* @4678080 cast */
    /* @4678084 call */
    GM_SITE(vm, 487, 4678084);
    /* @4678092 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4678096 string */
    /* @4678104 cast */
    /* @4678108 load */
    /* @4678116 load */
    /* @4678124 constant */
    /* @4678128 add */
    /* @4678132 call */
    GM_SITE(vm, 487, 4678132);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4678140 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, GM_READ(vm, -1, "y"), STR_REF(873)));
    L_4678144: ;
    return;
}
