/* generated from CODE 623 (gml_Object_obj_lloydtutorial10_Draw_0), source start 4938792, end 4945112. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0623(GmVM* vm) {
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
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val p4945096_0;
    Val v85;
    /* @4938792 constant */
    /* @4938796 load */
    /* @4938804 cast */
    /* @4938808 load */
    /* @4938816 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4938824 constant */
    /* @4938828 load */
    /* @4938836 cast */
    /* @4938840 load */
    /* @4938848 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4938856 load */
    /* @4938864 constant */
    /* @4938868 cmp */
    /* @4938872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4939400;
    /* @4938876 constant */
    /* @4938880 cast */
    /* @4938884 constant */
    /* @4938888 cast */
    /* @4938892 constant */
    /* @4938896 cast */
    /* @4938900 constant */
    /* @4938912 cast */
    /* @4938916 constant */
    /* @4938928 cast */
    /* @4938932 constant */
    /* @4938936 constant */
    /* @4938940 load */
    /* @4938948 constant */
    /* @4938952 constant */
    /* @4938956 load */
    /* @4938964 constant */
    /* @4938968 sub */
    /* @4938972 constant */
    /* @4938976 cast */
    /* @4938980 constant */
    /* @4938984 cast */
    /* @4938988 call */
    GM_SITE(vm, 623, 4938988);
    /* @4938996 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4939000 constant */
    /* @4939004 cast */
    /* @4939008 constant */
    /* @4939012 cast */
    /* @4939016 constant */
    /* @4939020 cast */
    /* @4939024 constant */
    /* @4939028 cast */
    /* @4939032 constant */
    /* @4939036 cast */
    /* @4939040 constant */
    /* @4939044 load */
    /* @4939052 cast */
    /* @4939056 load */
    /* @4939064 constant */
    /* @4939068 add */
    /* @4939072 constant */
    /* @4939076 load */
    /* @4939084 cast */
    /* @4939088 load */
    /* @4939096 constant */
    /* @4939100 add */
    /* @4939104 constant */
    /* @4939108 cast */
    /* @4939112 constant */
    /* @4939116 cast */
    /* @4939120 call */
    GM_SITE(vm, 623, 4939120);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4939128 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4939132 constant */
    /* @4939136 cast */
    /* @4939140 constant */
    /* @4939144 cast */
    /* @4939148 constant */
    /* @4939152 cast */
    /* @4939156 constant */
    /* @4939160 cast */
    /* @4939164 constant */
    /* @4939168 cast */
    /* @4939172 constant */
    /* @4939176 load */
    /* @4939184 cast */
    /* @4939188 load */
    /* @4939196 constant */
    /* @4939200 add */
    /* @4939204 constant */
    /* @4939208 load */
    /* @4939216 cast */
    /* @4939220 load */
    /* @4939228 constant */
    /* @4939232 add */
    /* @4939236 constant */
    /* @4939240 cast */
    /* @4939244 constant */
    /* @4939248 cast */
    /* @4939252 call */
    GM_SITE(vm, 623, 4939252);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4939260 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4939264 load */
    /* @4939272 constant */
    /* @4939276 cmp */
    /* @4939280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4939400;
    /* @4939284 constant */
    /* @4939288 cast */
    /* @4939292 call */
    GM_SITE(vm, 623, 4939292);
    /* @4939300 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4939304 constant */
    /* @4939312 cast */
    /* @4939316 call */
    GM_SITE(vm, 623, 4939316);
    /* @4939324 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4939328 string */
    /* @4939336 cast */
    /* @4939340 constant */
    /* @4939344 constant */
    /* @4939348 load */
    /* @4939356 constant */
    /* @4939360 add */
    /* @4939364 constant */
    /* @4939368 constant */
    /* @4939372 load */
    /* @4939380 constant */
    /* @4939384 add */
    /* @4939388 call */
    GM_SITE(vm, 623, 4939388);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4939396 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4939400: ;
    /* @4939400 load */
    /* @4939408 constant */
    /* @4939412 cmp */
    /* @4939416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4939944;
    /* @4939420 constant */
    /* @4939424 cast */
    /* @4939428 constant */
    /* @4939432 cast */
    /* @4939436 constant */
    /* @4939440 cast */
    /* @4939444 constant */
    /* @4939456 cast */
    /* @4939460 constant */
    /* @4939472 cast */
    /* @4939476 constant */
    /* @4939480 constant */
    /* @4939484 load */
    /* @4939492 constant */
    /* @4939496 constant */
    /* @4939500 load */
    /* @4939508 constant */
    /* @4939512 sub */
    /* @4939516 constant */
    /* @4939520 cast */
    /* @4939524 constant */
    /* @4939528 cast */
    /* @4939532 call */
    GM_SITE(vm, 623, 4939532);
    /* @4939540 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4939544 constant */
    /* @4939548 cast */
    /* @4939552 constant */
    /* @4939556 cast */
    /* @4939560 constant */
    /* @4939564 cast */
    /* @4939568 constant */
    /* @4939572 cast */
    /* @4939576 constant */
    /* @4939580 cast */
    /* @4939584 constant */
    /* @4939588 load */
    /* @4939596 cast */
    /* @4939600 load */
    /* @4939608 constant */
    /* @4939612 add */
    /* @4939616 constant */
    /* @4939620 load */
    /* @4939628 cast */
    /* @4939632 load */
    /* @4939640 constant */
    /* @4939644 add */
    /* @4939648 constant */
    /* @4939652 cast */
    /* @4939656 constant */
    /* @4939660 cast */
    /* @4939664 call */
    GM_SITE(vm, 623, 4939664);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4939672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4939676 constant */
    /* @4939680 cast */
    /* @4939684 constant */
    /* @4939688 cast */
    /* @4939692 constant */
    /* @4939696 cast */
    /* @4939700 constant */
    /* @4939704 cast */
    /* @4939708 constant */
    /* @4939712 cast */
    /* @4939716 constant */
    /* @4939720 load */
    /* @4939728 cast */
    /* @4939732 load */
    /* @4939740 constant */
    /* @4939744 add */
    /* @4939748 constant */
    /* @4939752 load */
    /* @4939760 cast */
    /* @4939764 load */
    /* @4939772 constant */
    /* @4939776 add */
    /* @4939780 constant */
    /* @4939784 cast */
    /* @4939788 constant */
    /* @4939792 cast */
    /* @4939796 call */
    GM_SITE(vm, 623, 4939796);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4939804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4939808 load */
    /* @4939816 constant */
    /* @4939820 cmp */
    /* @4939824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4939944;
    /* @4939828 constant */
    /* @4939832 cast */
    /* @4939836 call */
    GM_SITE(vm, 623, 4939836);
    /* @4939844 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4939848 constant */
    /* @4939856 cast */
    /* @4939860 call */
    GM_SITE(vm, 623, 4939860);
    /* @4939868 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4939872 string */
    /* @4939880 cast */
    /* @4939884 constant */
    /* @4939888 constant */
    /* @4939892 load */
    /* @4939900 constant */
    /* @4939904 add */
    /* @4939908 constant */
    /* @4939912 constant */
    /* @4939916 load */
    /* @4939924 constant */
    /* @4939928 add */
    /* @4939932 call */
    GM_SITE(vm, 623, 4939932);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4939940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4939944: ;
    /* @4939944 load */
    /* @4939952 constant */
    /* @4939956 cmp */
    /* @4939960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4940488;
    /* @4939964 constant */
    /* @4939968 cast */
    /* @4939972 constant */
    /* @4939976 cast */
    /* @4939980 constant */
    /* @4939984 cast */
    /* @4939988 constant */
    /* @4940000 cast */
    /* @4940004 constant */
    /* @4940016 cast */
    /* @4940020 constant */
    /* @4940024 constant */
    /* @4940028 load */
    /* @4940036 constant */
    /* @4940040 constant */
    /* @4940044 load */
    /* @4940052 constant */
    /* @4940056 sub */
    /* @4940060 constant */
    /* @4940064 cast */
    /* @4940068 constant */
    /* @4940072 cast */
    /* @4940076 call */
    GM_SITE(vm, 623, 4940076);
    /* @4940084 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4940088 constant */
    /* @4940092 cast */
    /* @4940096 constant */
    /* @4940100 cast */
    /* @4940104 constant */
    /* @4940108 cast */
    /* @4940112 constant */
    /* @4940116 cast */
    /* @4940120 constant */
    /* @4940124 cast */
    /* @4940128 constant */
    /* @4940132 load */
    /* @4940140 cast */
    /* @4940144 load */
    /* @4940152 constant */
    /* @4940156 add */
    /* @4940160 constant */
    /* @4940164 load */
    /* @4940172 cast */
    /* @4940176 load */
    /* @4940184 constant */
    /* @4940188 add */
    /* @4940192 constant */
    /* @4940196 cast */
    /* @4940200 constant */
    /* @4940204 cast */
    /* @4940208 call */
    GM_SITE(vm, 623, 4940208);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4940216 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4940220 constant */
    /* @4940224 cast */
    /* @4940228 constant */
    /* @4940232 cast */
    /* @4940236 constant */
    /* @4940240 cast */
    /* @4940244 constant */
    /* @4940248 cast */
    /* @4940252 constant */
    /* @4940256 cast */
    /* @4940260 constant */
    /* @4940264 load */
    /* @4940272 cast */
    /* @4940276 load */
    /* @4940284 constant */
    /* @4940288 add */
    /* @4940292 constant */
    /* @4940296 load */
    /* @4940304 cast */
    /* @4940308 load */
    /* @4940316 constant */
    /* @4940320 add */
    /* @4940324 constant */
    /* @4940328 cast */
    /* @4940332 constant */
    /* @4940336 cast */
    /* @4940340 call */
    GM_SITE(vm, 623, 4940340);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4940348 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4940352 load */
    /* @4940360 constant */
    /* @4940364 cmp */
    /* @4940368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4940488;
    /* @4940372 constant */
    /* @4940376 cast */
    /* @4940380 call */
    GM_SITE(vm, 623, 4940380);
    /* @4940388 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4940392 constant */
    /* @4940400 cast */
    /* @4940404 call */
    GM_SITE(vm, 623, 4940404);
    /* @4940412 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4940416 string */
    /* @4940424 cast */
    /* @4940428 constant */
    /* @4940432 constant */
    /* @4940436 load */
    /* @4940444 constant */
    /* @4940448 add */
    /* @4940452 constant */
    /* @4940456 constant */
    /* @4940460 load */
    /* @4940468 constant */
    /* @4940472 add */
    /* @4940476 call */
    GM_SITE(vm, 623, 4940476);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4940484 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4940488: ;
    /* @4940488 load */
    /* @4940496 constant */
    /* @4940500 cmp */
    /* @4940504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4941032;
    /* @4940508 constant */
    /* @4940512 cast */
    /* @4940516 constant */
    /* @4940520 cast */
    /* @4940524 constant */
    /* @4940528 cast */
    /* @4940532 constant */
    /* @4940544 cast */
    /* @4940548 constant */
    /* @4940560 cast */
    /* @4940564 constant */
    /* @4940568 constant */
    /* @4940572 load */
    /* @4940580 constant */
    /* @4940584 constant */
    /* @4940588 load */
    /* @4940596 constant */
    /* @4940600 sub */
    /* @4940604 constant */
    /* @4940608 cast */
    /* @4940612 constant */
    /* @4940616 cast */
    /* @4940620 call */
    GM_SITE(vm, 623, 4940620);
    /* @4940628 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4940632 constant */
    /* @4940636 cast */
    /* @4940640 constant */
    /* @4940644 cast */
    /* @4940648 constant */
    /* @4940652 cast */
    /* @4940656 constant */
    /* @4940660 cast */
    /* @4940664 constant */
    /* @4940668 cast */
    /* @4940672 constant */
    /* @4940676 load */
    /* @4940684 cast */
    /* @4940688 load */
    /* @4940696 constant */
    /* @4940700 add */
    /* @4940704 constant */
    /* @4940708 load */
    /* @4940716 cast */
    /* @4940720 load */
    /* @4940728 constant */
    /* @4940732 add */
    /* @4940736 constant */
    /* @4940740 cast */
    /* @4940744 constant */
    /* @4940748 cast */
    /* @4940752 call */
    GM_SITE(vm, 623, 4940752);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4940760 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4940764 constant */
    /* @4940768 cast */
    /* @4940772 constant */
    /* @4940776 cast */
    /* @4940780 constant */
    /* @4940784 cast */
    /* @4940788 constant */
    /* @4940792 cast */
    /* @4940796 constant */
    /* @4940800 cast */
    /* @4940804 constant */
    /* @4940808 load */
    /* @4940816 cast */
    /* @4940820 load */
    /* @4940828 constant */
    /* @4940832 add */
    /* @4940836 constant */
    /* @4940840 load */
    /* @4940848 cast */
    /* @4940852 load */
    /* @4940860 constant */
    /* @4940864 add */
    /* @4940868 constant */
    /* @4940872 cast */
    /* @4940876 constant */
    /* @4940880 cast */
    /* @4940884 call */
    GM_SITE(vm, 623, 4940884);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4940892 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4940896 load */
    /* @4940904 constant */
    /* @4940908 cmp */
    /* @4940912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4941032;
    /* @4940916 constant */
    /* @4940920 cast */
    /* @4940924 call */
    GM_SITE(vm, 623, 4940924);
    /* @4940932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4940936 constant */
    /* @4940944 cast */
    /* @4940948 call */
    GM_SITE(vm, 623, 4940948);
    /* @4940956 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4940960 string */
    /* @4940968 cast */
    /* @4940972 constant */
    /* @4940976 constant */
    /* @4940980 load */
    /* @4940988 constant */
    /* @4940992 add */
    /* @4940996 constant */
    /* @4941000 constant */
    /* @4941004 load */
    /* @4941012 constant */
    /* @4941016 add */
    /* @4941020 call */
    GM_SITE(vm, 623, 4941020);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4941028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4941032: ;
    /* @4941032 load */
    /* @4941040 constant */
    /* @4941044 cmp */
    /* @4941048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4941576;
    /* @4941052 constant */
    /* @4941056 cast */
    /* @4941060 constant */
    /* @4941064 cast */
    /* @4941068 constant */
    /* @4941072 cast */
    /* @4941076 constant */
    /* @4941088 cast */
    /* @4941092 constant */
    /* @4941104 cast */
    /* @4941108 constant */
    /* @4941112 constant */
    /* @4941116 load */
    /* @4941124 constant */
    /* @4941128 constant */
    /* @4941132 load */
    /* @4941140 constant */
    /* @4941144 sub */
    /* @4941148 constant */
    /* @4941152 cast */
    /* @4941156 constant */
    /* @4941160 cast */
    /* @4941164 call */
    GM_SITE(vm, 623, 4941164);
    /* @4941172 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4941176 constant */
    /* @4941180 cast */
    /* @4941184 constant */
    /* @4941188 cast */
    /* @4941192 constant */
    /* @4941196 cast */
    /* @4941200 constant */
    /* @4941204 cast */
    /* @4941208 constant */
    /* @4941212 cast */
    /* @4941216 constant */
    /* @4941220 load */
    /* @4941228 cast */
    /* @4941232 load */
    /* @4941240 constant */
    /* @4941244 add */
    /* @4941248 constant */
    /* @4941252 load */
    /* @4941260 cast */
    /* @4941264 load */
    /* @4941272 constant */
    /* @4941276 add */
    /* @4941280 constant */
    /* @4941284 cast */
    /* @4941288 constant */
    /* @4941292 cast */
    /* @4941296 call */
    GM_SITE(vm, 623, 4941296);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4941304 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4941308 constant */
    /* @4941312 cast */
    /* @4941316 constant */
    /* @4941320 cast */
    /* @4941324 constant */
    /* @4941328 cast */
    /* @4941332 constant */
    /* @4941336 cast */
    /* @4941340 constant */
    /* @4941344 cast */
    /* @4941348 constant */
    /* @4941352 load */
    /* @4941360 cast */
    /* @4941364 load */
    /* @4941372 constant */
    /* @4941376 add */
    /* @4941380 constant */
    /* @4941384 load */
    /* @4941392 cast */
    /* @4941396 load */
    /* @4941404 constant */
    /* @4941408 add */
    /* @4941412 constant */
    /* @4941416 cast */
    /* @4941420 constant */
    /* @4941424 cast */
    /* @4941428 call */
    GM_SITE(vm, 623, 4941428);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4941436 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4941440 load */
    /* @4941448 constant */
    /* @4941452 cmp */
    /* @4941456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4941576;
    /* @4941460 constant */
    /* @4941464 cast */
    /* @4941468 call */
    GM_SITE(vm, 623, 4941468);
    /* @4941476 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4941480 constant */
    /* @4941488 cast */
    /* @4941492 call */
    GM_SITE(vm, 623, 4941492);
    /* @4941500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4941504 string */
    /* @4941512 cast */
    /* @4941516 constant */
    /* @4941520 constant */
    /* @4941524 load */
    /* @4941532 constant */
    /* @4941536 add */
    /* @4941540 constant */
    /* @4941544 constant */
    /* @4941548 load */
    /* @4941556 constant */
    /* @4941560 add */
    /* @4941564 call */
    GM_SITE(vm, 623, 4941564);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4941572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4941576: ;
    /* @4941576 load */
    /* @4941584 constant */
    /* @4941588 cmp */
    /* @4941592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4942120;
    /* @4941596 constant */
    /* @4941600 cast */
    /* @4941604 constant */
    /* @4941608 cast */
    /* @4941612 constant */
    /* @4941616 cast */
    /* @4941620 constant */
    /* @4941632 cast */
    /* @4941636 constant */
    /* @4941648 cast */
    /* @4941652 constant */
    /* @4941656 constant */
    /* @4941660 load */
    /* @4941668 constant */
    /* @4941672 constant */
    /* @4941676 load */
    /* @4941684 constant */
    /* @4941688 sub */
    /* @4941692 constant */
    /* @4941696 cast */
    /* @4941700 constant */
    /* @4941704 cast */
    /* @4941708 call */
    GM_SITE(vm, 623, 4941708);
    /* @4941716 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4941720 constant */
    /* @4941724 cast */
    /* @4941728 constant */
    /* @4941732 cast */
    /* @4941736 constant */
    /* @4941740 cast */
    /* @4941744 constant */
    /* @4941748 cast */
    /* @4941752 constant */
    /* @4941756 cast */
    /* @4941760 constant */
    /* @4941764 load */
    /* @4941772 cast */
    /* @4941776 load */
    /* @4941784 constant */
    /* @4941788 add */
    /* @4941792 constant */
    /* @4941796 load */
    /* @4941804 cast */
    /* @4941808 load */
    /* @4941816 constant */
    /* @4941820 add */
    /* @4941824 constant */
    /* @4941828 cast */
    /* @4941832 constant */
    /* @4941836 cast */
    /* @4941840 call */
    GM_SITE(vm, 623, 4941840);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4941848 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4941852 constant */
    /* @4941856 cast */
    /* @4941860 constant */
    /* @4941864 cast */
    /* @4941868 constant */
    /* @4941872 cast */
    /* @4941876 constant */
    /* @4941880 cast */
    /* @4941884 constant */
    /* @4941888 cast */
    /* @4941892 constant */
    /* @4941896 load */
    /* @4941904 cast */
    /* @4941908 load */
    /* @4941916 constant */
    /* @4941920 add */
    /* @4941924 constant */
    /* @4941928 load */
    /* @4941936 cast */
    /* @4941940 load */
    /* @4941948 constant */
    /* @4941952 add */
    /* @4941956 constant */
    /* @4941960 cast */
    /* @4941964 constant */
    /* @4941968 cast */
    /* @4941972 call */
    GM_SITE(vm, 623, 4941972);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4941980 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4941984 load */
    /* @4941992 constant */
    /* @4941996 cmp */
    /* @4942000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4942120;
    /* @4942004 constant */
    /* @4942008 cast */
    /* @4942012 call */
    GM_SITE(vm, 623, 4942012);
    /* @4942020 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4942024 constant */
    /* @4942032 cast */
    /* @4942036 call */
    GM_SITE(vm, 623, 4942036);
    /* @4942044 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4942048 string */
    /* @4942056 cast */
    /* @4942060 constant */
    /* @4942064 constant */
    /* @4942068 load */
    /* @4942076 constant */
    /* @4942080 add */
    /* @4942084 constant */
    /* @4942088 constant */
    /* @4942092 load */
    /* @4942100 constant */
    /* @4942104 add */
    /* @4942108 call */
    GM_SITE(vm, 623, 4942108);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4942116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4942120: ;
    /* @4942120 load */
    /* @4942128 constant */
    /* @4942132 cmp */
    /* @4942136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4943580;
    /* @4942140 load */
    /* @4942148 constant */
    /* @4942152 cmp */
    /* @4942156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4942380;
    /* @4942160 constant */
    /* @4942164 cast */
    /* @4942168 call */
    GM_SITE(vm, 623, 4942168);
    /* @4942176 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4942180 constant */
    /* @4942188 cast */
    /* @4942192 call */
    GM_SITE(vm, 623, 4942192);
    /* @4942200 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4942204 string */
    /* @4942212 cast */
    /* @4942216 constant */
    /* @4942220 load */
    /* @4942228 cast */
    /* @4942232 load */
    /* @4942240 constant */
    /* @4942244 add */
    /* @4942248 constant */
    /* @4942252 load */
    /* @4942260 cast */
    /* @4942264 load */
    /* @4942272 constant */
    /* @4942276 add */
    /* @4942280 call */
    GM_SITE(vm, 623, 4942280);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4942288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1106)));
    /* @4942292 string */
    /* @4942300 cast */
    /* @4942304 constant */
    /* @4942308 load */
    /* @4942316 cast */
    /* @4942320 load */
    /* @4942328 constant */
    /* @4942332 add */
    /* @4942336 constant */
    /* @4942340 load */
    /* @4942348 cast */
    /* @4942352 load */
    /* @4942360 constant */
    /* @4942364 add */
    /* @4942368 call */
    GM_SITE(vm, 623, 4942368);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4942376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1107)));
    L_4942380: ;
    /* @4942380 load */
    /* @4942388 constant */
    /* @4942392 cmp */
    /* @4942396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4942620;
    /* @4942400 constant */
    /* @4942404 cast */
    /* @4942408 call */
    GM_SITE(vm, 623, 4942408);
    /* @4942416 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4942420 constant */
    /* @4942428 cast */
    /* @4942432 call */
    GM_SITE(vm, 623, 4942432);
    /* @4942440 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4942444 string */
    /* @4942452 cast */
    /* @4942456 constant */
    /* @4942460 load */
    /* @4942468 cast */
    /* @4942472 load */
    /* @4942480 constant */
    /* @4942484 add */
    /* @4942488 constant */
    /* @4942492 load */
    /* @4942500 cast */
    /* @4942504 load */
    /* @4942512 constant */
    /* @4942516 add */
    /* @4942520 call */
    GM_SITE(vm, 623, 4942520);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4942528 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1106)));
    /* @4942532 string */
    /* @4942540 cast */
    /* @4942544 constant */
    /* @4942548 load */
    /* @4942556 cast */
    /* @4942560 load */
    /* @4942568 constant */
    /* @4942572 add */
    /* @4942576 constant */
    /* @4942580 load */
    /* @4942588 cast */
    /* @4942592 load */
    /* @4942600 constant */
    /* @4942604 add */
    /* @4942608 call */
    GM_SITE(vm, 623, 4942608);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4942616 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1107)));
    L_4942620: ;
    /* @4942620 load */
    /* @4942628 constant */
    /* @4942632 cmp */
    /* @4942636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4942860;
    /* @4942640 constant */
    /* @4942644 cast */
    /* @4942648 call */
    GM_SITE(vm, 623, 4942648);
    /* @4942656 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4942660 constant */
    /* @4942668 cast */
    /* @4942672 call */
    GM_SITE(vm, 623, 4942672);
    /* @4942680 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4942684 string */
    /* @4942692 cast */
    /* @4942696 constant */
    /* @4942700 load */
    /* @4942708 cast */
    /* @4942712 load */
    /* @4942720 constant */
    /* @4942724 add */
    /* @4942728 constant */
    /* @4942732 load */
    /* @4942740 cast */
    /* @4942744 load */
    /* @4942752 constant */
    /* @4942756 add */
    /* @4942760 call */
    GM_SITE(vm, 623, 4942760);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4942768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1106)));
    /* @4942772 string */
    /* @4942780 cast */
    /* @4942784 constant */
    /* @4942788 load */
    /* @4942796 cast */
    /* @4942800 load */
    /* @4942808 constant */
    /* @4942812 add */
    /* @4942816 constant */
    /* @4942820 load */
    /* @4942828 cast */
    /* @4942832 load */
    /* @4942840 constant */
    /* @4942844 add */
    /* @4942848 call */
    GM_SITE(vm, 623, 4942848);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4942856 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1107)));
    L_4942860: ;
    /* @4942860 load */
    /* @4942868 constant */
    /* @4942872 cmp */
    /* @4942876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4943100;
    /* @4942880 constant */
    /* @4942884 cast */
    /* @4942888 call */
    GM_SITE(vm, 623, 4942888);
    /* @4942896 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4942900 constant */
    /* @4942908 cast */
    /* @4942912 call */
    GM_SITE(vm, 623, 4942912);
    /* @4942920 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4942924 string */
    /* @4942932 cast */
    /* @4942936 constant */
    /* @4942940 load */
    /* @4942948 cast */
    /* @4942952 load */
    /* @4942960 constant */
    /* @4942964 add */
    /* @4942968 constant */
    /* @4942972 load */
    /* @4942980 cast */
    /* @4942984 load */
    /* @4942992 constant */
    /* @4942996 add */
    /* @4943000 call */
    GM_SITE(vm, 623, 4943000);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4943008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1106)));
    /* @4943012 string */
    /* @4943020 cast */
    /* @4943024 constant */
    /* @4943028 load */
    /* @4943036 cast */
    /* @4943040 load */
    /* @4943048 constant */
    /* @4943052 add */
    /* @4943056 constant */
    /* @4943060 load */
    /* @4943068 cast */
    /* @4943072 load */
    /* @4943080 constant */
    /* @4943084 add */
    /* @4943088 call */
    GM_SITE(vm, 623, 4943088);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4943096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1107)));
    L_4943100: ;
    /* @4943100 load */
    /* @4943108 constant */
    /* @4943112 cmp */
    /* @4943116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4943340;
    /* @4943120 constant */
    /* @4943124 cast */
    /* @4943128 call */
    GM_SITE(vm, 623, 4943128);
    /* @4943136 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4943140 constant */
    /* @4943148 cast */
    /* @4943152 call */
    GM_SITE(vm, 623, 4943152);
    /* @4943160 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4943164 string */
    /* @4943172 cast */
    /* @4943176 constant */
    /* @4943180 load */
    /* @4943188 cast */
    /* @4943192 load */
    /* @4943200 constant */
    /* @4943204 add */
    /* @4943208 constant */
    /* @4943212 load */
    /* @4943220 cast */
    /* @4943224 load */
    /* @4943232 constant */
    /* @4943236 add */
    /* @4943240 call */
    GM_SITE(vm, 623, 4943240);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4943248 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1106)));
    /* @4943252 string */
    /* @4943260 cast */
    /* @4943264 constant */
    /* @4943268 load */
    /* @4943276 cast */
    /* @4943280 load */
    /* @4943288 constant */
    /* @4943292 add */
    /* @4943296 constant */
    /* @4943300 load */
    /* @4943308 cast */
    /* @4943312 load */
    /* @4943320 constant */
    /* @4943324 add */
    /* @4943328 call */
    GM_SITE(vm, 623, 4943328);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4943336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1107)));
    L_4943340: ;
    /* @4943340 load */
    /* @4943348 constant */
    /* @4943352 cmp */
    /* @4943356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4943580;
    /* @4943360 constant */
    /* @4943364 cast */
    /* @4943368 call */
    GM_SITE(vm, 623, 4943368);
    /* @4943376 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4943380 constant */
    /* @4943388 cast */
    /* @4943392 call */
    GM_SITE(vm, 623, 4943392);
    /* @4943400 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4943404 string */
    /* @4943412 cast */
    /* @4943416 constant */
    /* @4943420 load */
    /* @4943428 cast */
    /* @4943432 load */
    /* @4943440 constant */
    /* @4943444 add */
    /* @4943448 constant */
    /* @4943452 load */
    /* @4943460 cast */
    /* @4943464 load */
    /* @4943472 constant */
    /* @4943476 add */
    /* @4943480 call */
    GM_SITE(vm, 623, 4943480);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4943488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1106)));
    /* @4943492 string */
    /* @4943500 cast */
    /* @4943504 constant */
    /* @4943508 load */
    /* @4943516 cast */
    /* @4943520 load */
    /* @4943528 constant */
    /* @4943532 add */
    /* @4943536 constant */
    /* @4943540 load */
    /* @4943548 cast */
    /* @4943552 load */
    /* @4943560 constant */
    /* @4943564 add */
    /* @4943568 call */
    GM_SITE(vm, 623, 4943568);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4943576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1107)));
    L_4943580: ;
    /* @4943580 load */
    /* @4943588 constant */
    /* @4943592 cmp */
    /* @4943596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4945040;
    /* @4943600 load */
    /* @4943608 constant */
    /* @4943612 cmp */
    /* @4943616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4943840;
    /* @4943620 constant */
    /* @4943624 cast */
    /* @4943628 call */
    GM_SITE(vm, 623, 4943628);
    /* @4943636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4943640 constant */
    /* @4943648 cast */
    /* @4943652 call */
    GM_SITE(vm, 623, 4943652);
    /* @4943660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4943664 string */
    /* @4943672 cast */
    /* @4943676 constant */
    /* @4943680 load */
    /* @4943688 cast */
    /* @4943692 load */
    /* @4943700 constant */
    /* @4943704 add */
    /* @4943708 constant */
    /* @4943712 load */
    /* @4943720 cast */
    /* @4943724 load */
    /* @4943732 constant */
    /* @4943736 add */
    /* @4943740 call */
    GM_SITE(vm, 623, 4943740);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4943748 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1108)));
    /* @4943752 string */
    /* @4943760 cast */
    /* @4943764 constant */
    /* @4943768 load */
    /* @4943776 cast */
    /* @4943780 load */
    /* @4943788 constant */
    /* @4943792 add */
    /* @4943796 constant */
    /* @4943800 load */
    /* @4943808 cast */
    /* @4943812 load */
    /* @4943820 constant */
    /* @4943824 add */
    /* @4943828 call */
    GM_SITE(vm, 623, 4943828);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4943836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1109)));
    L_4943840: ;
    /* @4943840 load */
    /* @4943848 constant */
    /* @4943852 cmp */
    /* @4943856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4944080;
    /* @4943860 constant */
    /* @4943864 cast */
    /* @4943868 call */
    GM_SITE(vm, 623, 4943868);
    /* @4943876 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4943880 constant */
    /* @4943888 cast */
    /* @4943892 call */
    GM_SITE(vm, 623, 4943892);
    /* @4943900 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4943904 string */
    /* @4943912 cast */
    /* @4943916 constant */
    /* @4943920 load */
    /* @4943928 cast */
    /* @4943932 load */
    /* @4943940 constant */
    /* @4943944 add */
    /* @4943948 constant */
    /* @4943952 load */
    /* @4943960 cast */
    /* @4943964 load */
    /* @4943972 constant */
    /* @4943976 add */
    /* @4943980 call */
    GM_SITE(vm, 623, 4943980);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4943988 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1108)));
    /* @4943992 string */
    /* @4944000 cast */
    /* @4944004 constant */
    /* @4944008 load */
    /* @4944016 cast */
    /* @4944020 load */
    /* @4944028 constant */
    /* @4944032 add */
    /* @4944036 constant */
    /* @4944040 load */
    /* @4944048 cast */
    /* @4944052 load */
    /* @4944060 constant */
    /* @4944064 add */
    /* @4944068 call */
    GM_SITE(vm, 623, 4944068);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4944076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1109)));
    L_4944080: ;
    /* @4944080 load */
    /* @4944088 constant */
    /* @4944092 cmp */
    /* @4944096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4944320;
    /* @4944100 constant */
    /* @4944104 cast */
    /* @4944108 call */
    GM_SITE(vm, 623, 4944108);
    /* @4944116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4944120 constant */
    /* @4944128 cast */
    /* @4944132 call */
    GM_SITE(vm, 623, 4944132);
    /* @4944140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4944144 string */
    /* @4944152 cast */
    /* @4944156 constant */
    /* @4944160 load */
    /* @4944168 cast */
    /* @4944172 load */
    /* @4944180 constant */
    /* @4944184 add */
    /* @4944188 constant */
    /* @4944192 load */
    /* @4944200 cast */
    /* @4944204 load */
    /* @4944212 constant */
    /* @4944216 add */
    /* @4944220 call */
    GM_SITE(vm, 623, 4944220);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4944228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1108)));
    /* @4944232 string */
    /* @4944240 cast */
    /* @4944244 constant */
    /* @4944248 load */
    /* @4944256 cast */
    /* @4944260 load */
    /* @4944268 constant */
    /* @4944272 add */
    /* @4944276 constant */
    /* @4944280 load */
    /* @4944288 cast */
    /* @4944292 load */
    /* @4944300 constant */
    /* @4944304 add */
    /* @4944308 call */
    GM_SITE(vm, 623, 4944308);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4944316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1109)));
    L_4944320: ;
    /* @4944320 load */
    /* @4944328 constant */
    /* @4944332 cmp */
    /* @4944336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4944560;
    /* @4944340 constant */
    /* @4944344 cast */
    /* @4944348 call */
    GM_SITE(vm, 623, 4944348);
    /* @4944356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4944360 constant */
    /* @4944368 cast */
    /* @4944372 call */
    GM_SITE(vm, 623, 4944372);
    /* @4944380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4944384 string */
    /* @4944392 cast */
    /* @4944396 constant */
    /* @4944400 load */
    /* @4944408 cast */
    /* @4944412 load */
    /* @4944420 constant */
    /* @4944424 add */
    /* @4944428 constant */
    /* @4944432 load */
    /* @4944440 cast */
    /* @4944444 load */
    /* @4944452 constant */
    /* @4944456 add */
    /* @4944460 call */
    GM_SITE(vm, 623, 4944460);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4944468 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1108)));
    /* @4944472 string */
    /* @4944480 cast */
    /* @4944484 constant */
    /* @4944488 load */
    /* @4944496 cast */
    /* @4944500 load */
    /* @4944508 constant */
    /* @4944512 add */
    /* @4944516 constant */
    /* @4944520 load */
    /* @4944528 cast */
    /* @4944532 load */
    /* @4944540 constant */
    /* @4944544 add */
    /* @4944548 call */
    GM_SITE(vm, 623, 4944548);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4944556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1109)));
    L_4944560: ;
    /* @4944560 load */
    /* @4944568 constant */
    /* @4944572 cmp */
    /* @4944576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4944800;
    /* @4944580 constant */
    /* @4944584 cast */
    /* @4944588 call */
    GM_SITE(vm, 623, 4944588);
    /* @4944596 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4944600 constant */
    /* @4944608 cast */
    /* @4944612 call */
    GM_SITE(vm, 623, 4944612);
    /* @4944620 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4944624 string */
    /* @4944632 cast */
    /* @4944636 constant */
    /* @4944640 load */
    /* @4944648 cast */
    /* @4944652 load */
    /* @4944660 constant */
    /* @4944664 add */
    /* @4944668 constant */
    /* @4944672 load */
    /* @4944680 cast */
    /* @4944684 load */
    /* @4944692 constant */
    /* @4944696 add */
    /* @4944700 call */
    GM_SITE(vm, 623, 4944700);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4944708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1108)));
    /* @4944712 string */
    /* @4944720 cast */
    /* @4944724 constant */
    /* @4944728 load */
    /* @4944736 cast */
    /* @4944740 load */
    /* @4944748 constant */
    /* @4944752 add */
    /* @4944756 constant */
    /* @4944760 load */
    /* @4944768 cast */
    /* @4944772 load */
    /* @4944780 constant */
    /* @4944784 add */
    /* @4944788 call */
    GM_SITE(vm, 623, 4944788);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4944796 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1109)));
    L_4944800: ;
    /* @4944800 load */
    /* @4944808 constant */
    /* @4944812 cmp */
    /* @4944816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4945040;
    /* @4944820 constant */
    /* @4944824 cast */
    /* @4944828 call */
    GM_SITE(vm, 623, 4944828);
    /* @4944836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4944840 constant */
    /* @4944848 cast */
    /* @4944852 call */
    GM_SITE(vm, 623, 4944852);
    /* @4944860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4944864 string */
    /* @4944872 cast */
    /* @4944876 constant */
    /* @4944880 load */
    /* @4944888 cast */
    /* @4944892 load */
    /* @4944900 constant */
    /* @4944904 add */
    /* @4944908 constant */
    /* @4944912 load */
    /* @4944920 cast */
    /* @4944924 load */
    /* @4944932 constant */
    /* @4944936 add */
    /* @4944940 call */
    GM_SITE(vm, 623, 4944940);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4944948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1108)));
    /* @4944952 string */
    /* @4944960 cast */
    /* @4944964 constant */
    /* @4944968 load */
    /* @4944976 cast */
    /* @4944980 load */
    /* @4944988 constant */
    /* @4944992 add */
    /* @4944996 constant */
    /* @4945000 load */
    /* @4945008 cast */
    /* @4945012 load */
    /* @4945020 constant */
    /* @4945024 add */
    /* @4945028 call */
    GM_SITE(vm, 623, 4945028);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4945036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1109)));
    L_4945040: ;
    /* @4945040 load */
    /* @4945048 constant */
    /* @4945052 cmp */
    /* @4945056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4945092;
    /* @4945060 constant */
    /* @4945064 cast */
    /* @4945068 constant */
    /* @4945072 cast */
    /* @4945076 call */
    GM_SITE(vm, 623, 4945076);
    /* @4945084 cast */
    /* @4945088 b */
    v85 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4945096_0 = v85;
    goto L_4945096;
    L_4945092: ;
    /* @4945092 constant */
    p4945096_0 = VAL(0);
    L_4945096: ;
    /* @4945096 bf */
    if (!TRUTH(p4945096_0)) goto L_4945112;
    /* @4945100 call */
    GM_SITE(vm, 623, 4945100);
    /* @4945108 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4945112: ;
    return;
}
