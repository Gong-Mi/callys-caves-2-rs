/* generated from CODE 477 (gml_Object_obj_mapmenu_Draw_0), source start 4654276, end 4655708. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0477(GmVM* vm) {
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
    /* @4654276 load */
    /* @4654284 constant */
    /* @4654288 cmp */
    /* @4654292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4654472;
    /* @4654296 constant */
    /* @4654300 cast */
    /* @4654304 constant */
    /* @4654308 cast */
    /* @4654312 constant */
    /* @4654316 cast */
    /* @4654320 constant */
    /* @4654324 cast */
    /* @4654328 constant */
    /* @4654332 cast */
    /* @4654336 load */
    /* @4654344 load */
    /* @4654352 constant */
    /* @4654356 cast */
    /* @4654360 constant */
    /* @4654364 cast */
    /* @4654368 call */
    GM_SITE(vm, 477, 4654368);
    /* @4654376 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4654380 constant */
    /* @4654384 cast */
    /* @4654388 call */
    GM_SITE(vm, 477, 4654388);
    /* @4654396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4654400 constant */
    /* @4654408 cast */
    /* @4654412 call */
    GM_SITE(vm, 477, 4654412);
    /* @4654420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4654424 string */
    /* @4654432 cast */
    /* @4654436 load */
    /* @4654444 load */
    /* @4654452 constant */
    /* @4654456 add */
    /* @4654460 call */
    GM_SITE(vm, 477, 4654460);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(42));
    /* @4654468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4654472: ;
    /* @4654472 load */
    /* @4654480 constant */
    /* @4654484 cmp */
    /* @4654488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4654748;
    /* @4654492 constant */
    /* @4654496 constant */
    /* @4654500 load */
    /* @4654508 constant */
    /* @4654512 add */
    /* @4654516 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(202));
    GM_WRITE(vm, -1, "x", v2);
    /* @4654524 constant */
    /* @4654528 constant */
    /* @4654532 load */
    /* @4654540 constant */
    /* @4654544 add */
    /* @4654548 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(115));
    GM_WRITE(vm, -1, "y", v3);
    /* @4654556 constant */
    /* @4654560 cast */
    /* @4654564 constant */
    /* @4654568 cast */
    /* @4654572 constant */
    /* @4654576 cast */
    /* @4654580 constant */
    /* @4654592 cast */
    /* @4654596 constant */
    /* @4654608 cast */
    /* @4654612 load */
    /* @4654620 load */
    /* @4654628 constant */
    /* @4654632 cast */
    /* @4654636 constant */
    /* @4654640 cast */
    /* @4654644 call */
    GM_SITE(vm, 477, 4654644);
    /* @4654652 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4654656 constant */
    /* @4654660 cast */
    /* @4654664 call */
    GM_SITE(vm, 477, 4654664);
    /* @4654672 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4654676 constant */
    /* @4654684 cast */
    /* @4654688 call */
    GM_SITE(vm, 477, 4654688);
    /* @4654696 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4654700 string */
    /* @4654708 cast */
    /* @4654712 load */
    /* @4654720 load */
    /* @4654728 constant */
    /* @4654732 add */
    /* @4654736 call */
    GM_SITE(vm, 477, 4654736);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(35));
    /* @4654744 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4654748: ;
    /* @4654748 load */
    /* @4654756 constant */
    /* @4654760 cmp */
    /* @4654764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4654968;
    /* @4654768 constant */
    /* @4654772 constant */
    /* @4654776 load */
    /* @4654784 constant */
    /* @4654788 add */
    /* @4654792 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(190));
    GM_WRITE(vm, -1, "x", v5);
    /* @4654800 constant */
    /* @4654804 constant */
    /* @4654808 load */
    /* @4654816 constant */
    /* @4654820 add */
    /* @4654824 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(185));
    GM_WRITE(vm, -1, "y", v6);
    /* @4654832 load */
    /* @4654840 load */
    /* @4654848 constant */
    /* @4654852 cast */
    /* @4654856 constant */
    /* @4654860 cast */
    /* @4654864 call */
    GM_SITE(vm, 477, 4654864);
    /* @4654872 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4654876 constant */
    /* @4654880 cast */
    /* @4654884 call */
    GM_SITE(vm, 477, 4654884);
    /* @4654892 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4654896 constant */
    /* @4654904 cast */
    /* @4654908 call */
    GM_SITE(vm, 477, 4654908);
    /* @4654916 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4654920 string */
    /* @4654928 cast */
    /* @4654932 load */
    /* @4654940 load */
    /* @4654948 constant */
    /* @4654952 add */
    /* @4654956 call */
    GM_SITE(vm, 477, 4654956);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(45));
    /* @4654964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4654968: ;
    /* @4654968 load */
    /* @4654976 constant */
    /* @4654980 cmp */
    /* @4654984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4655188;
    /* @4654988 constant */
    /* @4654992 constant */
    /* @4654996 load */
    /* @4655004 constant */
    /* @4655008 add */
    /* @4655012 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(190));
    GM_WRITE(vm, -1, "x", v8);
    /* @4655020 constant */
    /* @4655024 constant */
    /* @4655028 load */
    /* @4655036 constant */
    /* @4655040 add */
    /* @4655044 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(185));
    GM_WRITE(vm, -1, "y", v9);
    /* @4655052 load */
    /* @4655060 load */
    /* @4655068 constant */
    /* @4655072 cast */
    /* @4655076 constant */
    /* @4655080 cast */
    /* @4655084 call */
    GM_SITE(vm, 477, 4655084);
    /* @4655092 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4655096 constant */
    /* @4655100 cast */
    /* @4655104 call */
    GM_SITE(vm, 477, 4655104);
    /* @4655112 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4655116 constant */
    /* @4655124 cast */
    /* @4655128 call */
    GM_SITE(vm, 477, 4655128);
    /* @4655136 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4655140 string */
    /* @4655148 cast */
    /* @4655152 load */
    /* @4655160 load */
    /* @4655168 constant */
    /* @4655172 add */
    /* @4655176 call */
    GM_SITE(vm, 477, 4655176);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(45));
    /* @4655184 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4655188: ;
    /* @4655188 load */
    /* @4655196 constant */
    /* @4655200 cmp */
    /* @4655204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4655448;
    /* @4655208 constant */
    /* @4655212 constant */
    /* @4655216 load */
    /* @4655224 constant */
    /* @4655228 add */
    /* @4655232 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    GM_WRITE(vm, -1, "x", v11);
    /* @4655240 constant */
    /* @4655244 constant */
    /* @4655248 load */
    /* @4655256 constant */
    /* @4655260 add */
    /* @4655264 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(100));
    GM_WRITE(vm, -1, "y", v12);
    /* @4655272 constant */
    /* @4655276 cast */
    /* @4655280 constant */
    /* @4655284 cast */
    /* @4655288 constant */
    /* @4655292 cast */
    /* @4655296 constant */
    /* @4655300 cast */
    /* @4655304 constant */
    /* @4655308 cast */
    /* @4655312 load */
    /* @4655320 load */
    /* @4655328 constant */
    /* @4655332 cast */
    /* @4655336 constant */
    /* @4655340 cast */
    /* @4655344 call */
    GM_SITE(vm, 477, 4655344);
    /* @4655352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4655356 constant */
    /* @4655360 cast */
    /* @4655364 call */
    GM_SITE(vm, 477, 4655364);
    /* @4655372 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4655376 constant */
    /* @4655384 cast */
    /* @4655388 call */
    GM_SITE(vm, 477, 4655388);
    /* @4655396 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4655400 string */
    /* @4655408 cast */
    /* @4655412 load */
    /* @4655420 load */
    /* @4655428 constant */
    /* @4655432 add */
    /* @4655436 call */
    GM_SITE(vm, 477, 4655436);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(42));
    /* @4655444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4655448: ;
    /* @4655448 load */
    /* @4655456 constant */
    /* @4655460 cmp */
    /* @4655464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4655708;
    /* @4655468 constant */
    /* @4655472 constant */
    /* @4655476 load */
    /* @4655484 constant */
    /* @4655488 add */
    /* @4655492 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    GM_WRITE(vm, -1, "x", v14);
    /* @4655500 constant */
    /* @4655504 constant */
    /* @4655508 load */
    /* @4655516 constant */
    /* @4655520 add */
    /* @4655524 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(100));
    GM_WRITE(vm, -1, "y", v15);
    /* @4655532 constant */
    /* @4655536 cast */
    /* @4655540 constant */
    /* @4655544 cast */
    /* @4655548 constant */
    /* @4655552 cast */
    /* @4655556 constant */
    /* @4655560 cast */
    /* @4655564 constant */
    /* @4655568 cast */
    /* @4655572 load */
    /* @4655580 load */
    /* @4655588 constant */
    /* @4655592 cast */
    /* @4655596 constant */
    /* @4655600 cast */
    /* @4655604 call */
    GM_SITE(vm, 477, 4655604);
    /* @4655612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4655616 constant */
    /* @4655620 cast */
    /* @4655624 call */
    GM_SITE(vm, 477, 4655624);
    /* @4655632 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4655636 constant */
    /* @4655644 cast */
    /* @4655648 call */
    GM_SITE(vm, 477, 4655648);
    /* @4655656 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4655660 string */
    /* @4655668 cast */
    /* @4655672 load */
    /* @4655680 load */
    /* @4655688 constant */
    /* @4655692 add */
    /* @4655696 call */
    GM_SITE(vm, 477, 4655696);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(42));
    /* @4655704 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(865)));
    L_4655708: ;
    return;
}
