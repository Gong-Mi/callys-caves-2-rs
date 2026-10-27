/* generated from CODE 527 (gml_Object_obj_swordbutton_Draw_0), source start 4817968, end 4821212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0527(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val p4818332_0;
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
    Val p4818880_0;
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
    Val p4819432_0;
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
    Val p4819948_0;
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
    Val p4820480_0;
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
    Val p4821028_0;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    /* @4817968 load */
    /* @4817976 constant */
    /* @4817980 cmp */
    /* @4817984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4818516;
    /* @4817988 constant */
    /* @4818000 cast */
    /* @4818004 constant */
    /* @4818008 cast */
    /* @4818012 constant */
    /* @4818016 cast */
    /* @4818020 constant */
    /* @4818032 cast */
    /* @4818036 constant */
    /* @4818048 cast */
    /* @4818052 constant */
    /* @4818056 constant */
    /* @4818060 load */
    /* @4818068 constant */
    /* @4818072 add */
    /* @4818076 constant */
    /* @4818080 constant */
    /* @4818084 load */
    /* @4818092 constant */
    /* @4818096 add */
    /* @4818100 constant */
    /* @4818104 cast */
    /* @4818108 constant */
    /* @4818112 cast */
    /* @4818116 call */
    GM_SITE(vm, 527, 4818116);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(125));
    /* @4818124 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v1, v2, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4818128 constant */
    /* @4818132 constant */
    /* @4818136 load */
    /* @4818144 constant */
    /* @4818148 add */
    /* @4818152 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    GM_WRITE(vm, -1, "x", v3);
    /* @4818160 constant */
    /* @4818164 constant */
    /* @4818168 load */
    /* @4818176 constant */
    /* @4818180 add */
    /* @4818184 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(125));
    GM_WRITE(vm, -1, "y", v4);
    /* @4818192 constant */
    /* @4818196 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4818204: ;
    /* @4818204 load */
    /* @4818212 constant */
    /* @4818216 cmp */
    /* @4818220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4818516;
    /* @4818224 constant */
    /* @4818228 cast */
    /* @4818232 load */
    /* @4818240 call */
    GM_SITE(vm, 527, 4818240);
    /* @4818248 cast */
    /* @4818252 bf */
    v5 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v5)) goto L_4818328;
    /* @4818256 constant */
    /* @4818260 cast */
    /* @4818264 constant */
    /* @4818268 cast */
    /* @4818272 constant */
    /* @4818276 cast */
    /* @4818280 load */
    /* @4818288 call */
    GM_SITE(vm, 527, 4818288);
    /* @4818296 load */
    /* @4818304 call */
    GM_SITE(vm, 527, 4818304);
    /* @4818312 call */
    GM_SITE(vm, 527, 4818312);
    v6 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v7 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4818320 cast */
    /* @4818324 b */
    v8 = BOOL(GM_CALL(vm, "collision_point", 5, v6, v7, VAL(129), VAL(0), VAL(0)));
    p4818332_0 = v8;
    goto L_4818332;
    L_4818328: ;
    /* @4818328 constant */
    p4818332_0 = VAL(0);
    L_4818332: ;
    /* @4818332 bf */
    if (!TRUTH(p4818332_0)) goto L_4818488;
    /* @4818336 constant */
    /* @4818340 constant */
    /* @4818344 constant */
    /* @4818348 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4818356 constant */
    /* @4818360 cast */
    /* @4818364 constant */
    /* @4818368 cast */
    /* @4818372 constant */
    /* @4818376 cast */
    /* @4818380 constant */
    /* @4818392 cast */
    /* @4818396 constant */
    /* @4818408 cast */
    /* @4818412 constant */
    /* @4818416 constant */
    /* @4818420 load */
    /* @4818428 constant */
    /* @4818432 add */
    /* @4818436 constant */
    /* @4818440 constant */
    /* @4818444 load */
    /* @4818452 constant */
    /* @4818456 add */
    /* @4818460 constant */
    /* @4818464 cast */
    /* @4818468 constant */
    /* @4818472 cast */
    /* @4818476 call */
    GM_SITE(vm, 527, 4818476);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(125));
    /* @4818484 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v9, v10, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4818488: ;
    /* @4818488 load */
    /* @4818496 constant */
    /* @4818500 add */
    /* @4818504 store */
    v11 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v11);
    /* @4818512 b */
    goto L_4818204;
    L_4818516: ;
    /* @4818516 load */
    /* @4818524 constant */
    /* @4818528 cmp */
    /* @4818532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4819064;
    /* @4818536 constant */
    /* @4818548 cast */
    /* @4818552 constant */
    /* @4818556 cast */
    /* @4818560 constant */
    /* @4818564 cast */
    /* @4818568 constant */
    /* @4818580 cast */
    /* @4818584 constant */
    /* @4818596 cast */
    /* @4818600 constant */
    /* @4818604 constant */
    /* @4818608 load */
    /* @4818616 constant */
    /* @4818620 add */
    /* @4818624 constant */
    /* @4818628 constant */
    /* @4818632 load */
    /* @4818640 constant */
    /* @4818644 add */
    /* @4818648 constant */
    /* @4818652 cast */
    /* @4818656 constant */
    /* @4818660 cast */
    /* @4818664 call */
    GM_SITE(vm, 527, 4818664);
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(145));
    /* @4818672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(0.6)));
    /* @4818676 constant */
    /* @4818680 constant */
    /* @4818684 load */
    /* @4818692 constant */
    /* @4818696 add */
    /* @4818700 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    GM_WRITE(vm, -1, "x", v14);
    /* @4818708 constant */
    /* @4818712 constant */
    /* @4818716 load */
    /* @4818724 constant */
    /* @4818728 add */
    /* @4818732 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(145));
    GM_WRITE(vm, -1, "y", v15);
    /* @4818740 constant */
    /* @4818744 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4818752: ;
    /* @4818752 load */
    /* @4818760 constant */
    /* @4818764 cmp */
    /* @4818768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4819064;
    /* @4818772 constant */
    /* @4818776 cast */
    /* @4818780 load */
    /* @4818788 call */
    GM_SITE(vm, 527, 4818788);
    /* @4818796 cast */
    /* @4818800 bf */
    v16 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v16)) goto L_4818876;
    /* @4818804 constant */
    /* @4818808 cast */
    /* @4818812 constant */
    /* @4818816 cast */
    /* @4818820 constant */
    /* @4818824 cast */
    /* @4818828 load */
    /* @4818836 call */
    GM_SITE(vm, 527, 4818836);
    /* @4818844 load */
    /* @4818852 call */
    GM_SITE(vm, 527, 4818852);
    /* @4818860 call */
    GM_SITE(vm, 527, 4818860);
    v17 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v18 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4818868 cast */
    /* @4818872 b */
    v19 = BOOL(GM_CALL(vm, "collision_point", 5, v17, v18, VAL(129), VAL(0), VAL(0)));
    p4818880_0 = v19;
    goto L_4818880;
    L_4818876: ;
    /* @4818876 constant */
    p4818880_0 = VAL(0);
    L_4818880: ;
    /* @4818880 bf */
    if (!TRUTH(p4818880_0)) goto L_4819036;
    /* @4818884 constant */
    /* @4818888 constant */
    /* @4818892 constant */
    /* @4818896 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4818904 constant */
    /* @4818908 cast */
    /* @4818912 constant */
    /* @4818916 cast */
    /* @4818920 constant */
    /* @4818924 cast */
    /* @4818928 constant */
    /* @4818940 cast */
    /* @4818944 constant */
    /* @4818956 cast */
    /* @4818960 constant */
    /* @4818964 constant */
    /* @4818968 load */
    /* @4818976 constant */
    /* @4818980 add */
    /* @4818984 constant */
    /* @4818988 constant */
    /* @4818992 load */
    /* @4819000 constant */
    /* @4819004 add */
    /* @4819008 constant */
    /* @4819012 cast */
    /* @4819016 constant */
    /* @4819020 cast */
    /* @4819024 call */
    GM_SITE(vm, 527, 4819024);
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(145));
    /* @4819032 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4819036: ;
    /* @4819036 load */
    /* @4819044 constant */
    /* @4819048 add */
    /* @4819052 store */
    v22 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v22);
    /* @4819060 b */
    goto L_4818752;
    L_4819064: ;
    /* @4819064 load */
    /* @4819072 constant */
    /* @4819076 cmp */
    /* @4819080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4819084;
    L_4819084: ;
    /* @4819084 load */
    /* @4819092 constant */
    /* @4819096 cmp */
    /* @4819100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4819600;
    /* @4819104 constant */
    /* @4819116 cast */
    /* @4819120 constant */
    /* @4819124 cast */
    /* @4819128 constant */
    /* @4819132 cast */
    /* @4819136 constant */
    /* @4819140 cast */
    /* @4819144 constant */
    /* @4819148 cast */
    /* @4819152 constant */
    /* @4819156 constant */
    /* @4819160 load */
    /* @4819168 constant */
    /* @4819172 add */
    /* @4819176 constant */
    /* @4819180 constant */
    /* @4819184 load */
    /* @4819192 constant */
    /* @4819196 add */
    /* @4819200 constant */
    /* @4819204 cast */
    /* @4819208 constant */
    /* @4819212 cast */
    /* @4819216 call */
    GM_SITE(vm, 527, 4819216);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(245));
    /* @4819224 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v23, v24, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4819228 constant */
    /* @4819232 constant */
    /* @4819236 load */
    /* @4819244 constant */
    /* @4819248 add */
    /* @4819252 store */
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    GM_WRITE(vm, -1, "x", v25);
    /* @4819260 constant */
    /* @4819264 constant */
    /* @4819268 load */
    /* @4819276 constant */
    /* @4819280 add */
    /* @4819284 store */
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(245));
    GM_WRITE(vm, -1, "y", v26);
    /* @4819292 constant */
    /* @4819296 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4819304: ;
    /* @4819304 load */
    /* @4819312 constant */
    /* @4819316 cmp */
    /* @4819320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4819600;
    /* @4819324 constant */
    /* @4819328 cast */
    /* @4819332 load */
    /* @4819340 call */
    GM_SITE(vm, 527, 4819340);
    /* @4819348 cast */
    /* @4819352 bf */
    v27 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v27)) goto L_4819428;
    /* @4819356 constant */
    /* @4819360 cast */
    /* @4819364 constant */
    /* @4819368 cast */
    /* @4819372 constant */
    /* @4819376 cast */
    /* @4819380 load */
    /* @4819388 call */
    GM_SITE(vm, 527, 4819388);
    /* @4819396 load */
    /* @4819404 call */
    GM_SITE(vm, 527, 4819404);
    /* @4819412 call */
    GM_SITE(vm, 527, 4819412);
    v28 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v29 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4819420 cast */
    /* @4819424 b */
    v30 = BOOL(GM_CALL(vm, "collision_point", 5, v28, v29, VAL(129), VAL(0), VAL(0)));
    p4819432_0 = v30;
    goto L_4819432;
    L_4819428: ;
    /* @4819428 constant */
    p4819432_0 = VAL(0);
    L_4819432: ;
    /* @4819432 bf */
    if (!TRUTH(p4819432_0)) goto L_4819572;
    /* @4819436 constant */
    /* @4819440 constant */
    /* @4819444 constant */
    /* @4819448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4819456 constant */
    /* @4819460 cast */
    /* @4819464 constant */
    /* @4819468 cast */
    /* @4819472 constant */
    /* @4819476 cast */
    /* @4819480 constant */
    /* @4819484 cast */
    /* @4819488 constant */
    /* @4819492 cast */
    /* @4819496 constant */
    /* @4819500 constant */
    /* @4819504 load */
    /* @4819512 constant */
    /* @4819516 add */
    /* @4819520 constant */
    /* @4819524 constant */
    /* @4819528 load */
    /* @4819536 constant */
    /* @4819540 add */
    /* @4819544 constant */
    /* @4819548 cast */
    /* @4819552 constant */
    /* @4819556 cast */
    /* @4819560 call */
    GM_SITE(vm, 527, 4819560);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(245));
    /* @4819568 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v31, v32, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4819572: ;
    /* @4819572 load */
    /* @4819580 constant */
    /* @4819584 add */
    /* @4819588 store */
    v33 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v33);
    /* @4819596 b */
    goto L_4819304;
    L_4819600: ;
    /* @4819600 load */
    /* @4819608 constant */
    /* @4819612 cmp */
    /* @4819616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4820116;
    /* @4819620 constant */
    /* @4819632 cast */
    /* @4819636 constant */
    /* @4819640 cast */
    /* @4819644 constant */
    /* @4819648 cast */
    /* @4819652 constant */
    /* @4819656 cast */
    /* @4819660 constant */
    /* @4819664 cast */
    /* @4819668 constant */
    /* @4819672 constant */
    /* @4819676 load */
    /* @4819684 constant */
    /* @4819688 add */
    /* @4819692 constant */
    /* @4819696 constant */
    /* @4819700 load */
    /* @4819708 constant */
    /* @4819712 add */
    /* @4819716 constant */
    /* @4819720 cast */
    /* @4819724 constant */
    /* @4819728 cast */
    /* @4819732 call */
    GM_SITE(vm, 527, 4819732);
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(245));
    /* @4819740 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v34, v35, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4819744 constant */
    /* @4819748 constant */
    /* @4819752 load */
    /* @4819760 constant */
    /* @4819764 add */
    /* @4819768 store */
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    GM_WRITE(vm, -1, "x", v36);
    /* @4819776 constant */
    /* @4819780 constant */
    /* @4819784 load */
    /* @4819792 constant */
    /* @4819796 add */
    /* @4819800 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(245));
    GM_WRITE(vm, -1, "y", v37);
    /* @4819808 constant */
    /* @4819812 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4819820: ;
    /* @4819820 load */
    /* @4819828 constant */
    /* @4819832 cmp */
    /* @4819836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4820116;
    /* @4819840 constant */
    /* @4819844 cast */
    /* @4819848 load */
    /* @4819856 call */
    GM_SITE(vm, 527, 4819856);
    /* @4819864 cast */
    /* @4819868 bf */
    v38 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v38)) goto L_4819944;
    /* @4819872 constant */
    /* @4819876 cast */
    /* @4819880 constant */
    /* @4819884 cast */
    /* @4819888 constant */
    /* @4819892 cast */
    /* @4819896 load */
    /* @4819904 call */
    GM_SITE(vm, 527, 4819904);
    /* @4819912 load */
    /* @4819920 call */
    GM_SITE(vm, 527, 4819920);
    /* @4819928 call */
    GM_SITE(vm, 527, 4819928);
    v39 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v40 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4819936 cast */
    /* @4819940 b */
    v41 = BOOL(GM_CALL(vm, "collision_point", 5, v39, v40, VAL(129), VAL(0), VAL(0)));
    p4819948_0 = v41;
    goto L_4819948;
    L_4819944: ;
    /* @4819944 constant */
    p4819948_0 = VAL(0);
    L_4819948: ;
    /* @4819948 bf */
    if (!TRUTH(p4819948_0)) goto L_4820088;
    /* @4819952 constant */
    /* @4819956 constant */
    /* @4819960 constant */
    /* @4819964 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4819972 constant */
    /* @4819976 cast */
    /* @4819980 constant */
    /* @4819984 cast */
    /* @4819988 constant */
    /* @4819992 cast */
    /* @4819996 constant */
    /* @4820000 cast */
    /* @4820004 constant */
    /* @4820008 cast */
    /* @4820012 constant */
    /* @4820016 constant */
    /* @4820020 load */
    /* @4820028 constant */
    /* @4820032 add */
    /* @4820036 constant */
    /* @4820040 constant */
    /* @4820044 load */
    /* @4820052 constant */
    /* @4820056 add */
    /* @4820060 constant */
    /* @4820064 cast */
    /* @4820068 constant */
    /* @4820072 cast */
    /* @4820076 call */
    GM_SITE(vm, 527, 4820076);
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(245));
    /* @4820084 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4820088: ;
    /* @4820088 load */
    /* @4820096 constant */
    /* @4820100 add */
    /* @4820104 store */
    v44 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v44);
    /* @4820112 b */
    goto L_4819820;
    L_4820116: ;
    /* @4820116 load */
    /* @4820124 constant */
    /* @4820128 cmp */
    /* @4820132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4820664;
    /* @4820136 constant */
    /* @4820148 cast */
    /* @4820152 constant */
    /* @4820156 cast */
    /* @4820160 constant */
    /* @4820164 cast */
    /* @4820168 constant */
    /* @4820180 cast */
    /* @4820184 constant */
    /* @4820196 cast */
    /* @4820200 constant */
    /* @4820204 constant */
    /* @4820208 load */
    /* @4820216 constant */
    /* @4820220 add */
    /* @4820224 constant */
    /* @4820228 constant */
    /* @4820232 load */
    /* @4820240 constant */
    /* @4820244 add */
    /* @4820248 constant */
    /* @4820252 cast */
    /* @4820256 constant */
    /* @4820260 cast */
    /* @4820264 call */
    GM_SITE(vm, 527, 4820264);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(125));
    /* @4820272 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v45, v46, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4820276 constant */
    /* @4820280 constant */
    /* @4820284 load */
    /* @4820292 constant */
    /* @4820296 add */
    /* @4820300 store */
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    GM_WRITE(vm, -1, "x", v47);
    /* @4820308 constant */
    /* @4820312 constant */
    /* @4820316 load */
    /* @4820324 constant */
    /* @4820328 add */
    /* @4820332 store */
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(125));
    GM_WRITE(vm, -1, "y", v48);
    /* @4820340 constant */
    /* @4820344 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4820352: ;
    /* @4820352 load */
    /* @4820360 constant */
    /* @4820364 cmp */
    /* @4820368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4820664;
    /* @4820372 constant */
    /* @4820376 cast */
    /* @4820380 load */
    /* @4820388 call */
    GM_SITE(vm, 527, 4820388);
    /* @4820396 cast */
    /* @4820400 bf */
    v49 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v49)) goto L_4820476;
    /* @4820404 constant */
    /* @4820408 cast */
    /* @4820412 constant */
    /* @4820416 cast */
    /* @4820420 constant */
    /* @4820424 cast */
    /* @4820428 load */
    /* @4820436 call */
    GM_SITE(vm, 527, 4820436);
    /* @4820444 load */
    /* @4820452 call */
    GM_SITE(vm, 527, 4820452);
    /* @4820460 call */
    GM_SITE(vm, 527, 4820460);
    v50 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v51 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4820468 cast */
    /* @4820472 b */
    v52 = BOOL(GM_CALL(vm, "collision_point", 5, v50, v51, VAL(129), VAL(0), VAL(0)));
    p4820480_0 = v52;
    goto L_4820480;
    L_4820476: ;
    /* @4820476 constant */
    p4820480_0 = VAL(0);
    L_4820480: ;
    /* @4820480 bf */
    if (!TRUTH(p4820480_0)) goto L_4820636;
    /* @4820484 constant */
    /* @4820488 constant */
    /* @4820492 constant */
    /* @4820496 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4820504 constant */
    /* @4820508 cast */
    /* @4820512 constant */
    /* @4820516 cast */
    /* @4820520 constant */
    /* @4820524 cast */
    /* @4820528 constant */
    /* @4820540 cast */
    /* @4820544 constant */
    /* @4820556 cast */
    /* @4820560 constant */
    /* @4820564 constant */
    /* @4820568 load */
    /* @4820576 constant */
    /* @4820580 add */
    /* @4820584 constant */
    /* @4820588 constant */
    /* @4820592 load */
    /* @4820600 constant */
    /* @4820604 add */
    /* @4820608 constant */
    /* @4820612 cast */
    /* @4820616 constant */
    /* @4820620 cast */
    /* @4820624 call */
    GM_SITE(vm, 527, 4820624);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(125));
    /* @4820632 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v53, v54, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4820636: ;
    /* @4820636 load */
    /* @4820644 constant */
    /* @4820648 add */
    /* @4820652 store */
    v55 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v55);
    /* @4820660 b */
    goto L_4820352;
    L_4820664: ;
    /* @4820664 load */
    /* @4820672 constant */
    /* @4820676 cmp */
    /* @4820680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4821212;
    /* @4820684 constant */
    /* @4820696 cast */
    /* @4820700 constant */
    /* @4820704 cast */
    /* @4820708 constant */
    /* @4820712 cast */
    /* @4820716 constant */
    /* @4820728 cast */
    /* @4820732 constant */
    /* @4820744 cast */
    /* @4820748 constant */
    /* @4820752 constant */
    /* @4820756 load */
    /* @4820764 constant */
    /* @4820768 add */
    /* @4820772 constant */
    /* @4820776 constant */
    /* @4820780 load */
    /* @4820788 constant */
    /* @4820792 add */
    /* @4820796 constant */
    /* @4820800 cast */
    /* @4820804 constant */
    /* @4820808 cast */
    /* @4820812 call */
    GM_SITE(vm, 527, 4820812);
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(145));
    /* @4820820 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(0), v56, v57, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4820824 constant */
    /* @4820828 constant */
    /* @4820832 load */
    /* @4820840 constant */
    /* @4820844 add */
    /* @4820848 store */
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    GM_WRITE(vm, -1, "x", v58);
    /* @4820856 constant */
    /* @4820860 constant */
    /* @4820864 load */
    /* @4820872 constant */
    /* @4820876 add */
    /* @4820880 store */
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(145));
    GM_WRITE(vm, -1, "y", v59);
    /* @4820888 constant */
    /* @4820892 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4820900: ;
    /* @4820900 load */
    /* @4820908 constant */
    /* @4820912 cmp */
    /* @4820916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4821212;
    /* @4820920 constant */
    /* @4820924 cast */
    /* @4820928 load */
    /* @4820936 call */
    GM_SITE(vm, 527, 4820936);
    /* @4820944 cast */
    /* @4820948 bf */
    v60 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v60)) goto L_4821024;
    /* @4820952 constant */
    /* @4820956 cast */
    /* @4820960 constant */
    /* @4820964 cast */
    /* @4820968 constant */
    /* @4820972 cast */
    /* @4820976 load */
    /* @4820984 call */
    GM_SITE(vm, 527, 4820984);
    /* @4820992 load */
    /* @4821000 call */
    GM_SITE(vm, 527, 4821000);
    /* @4821008 call */
    GM_SITE(vm, 527, 4821008);
    v61 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v62 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4821016 cast */
    /* @4821020 b */
    v63 = BOOL(GM_CALL(vm, "collision_point", 5, v61, v62, VAL(129), VAL(0), VAL(0)));
    p4821028_0 = v63;
    goto L_4821028;
    L_4821024: ;
    /* @4821024 constant */
    p4821028_0 = VAL(0);
    L_4821028: ;
    /* @4821028 bf */
    if (!TRUTH(p4821028_0)) goto L_4821184;
    /* @4821032 constant */
    /* @4821036 constant */
    /* @4821040 constant */
    /* @4821044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4821052 constant */
    /* @4821056 cast */
    /* @4821060 constant */
    /* @4821064 cast */
    /* @4821068 constant */
    /* @4821072 cast */
    /* @4821076 constant */
    /* @4821088 cast */
    /* @4821092 constant */
    /* @4821104 cast */
    /* @4821108 constant */
    /* @4821112 constant */
    /* @4821116 load */
    /* @4821124 constant */
    /* @4821128 add */
    /* @4821132 constant */
    /* @4821136 constant */
    /* @4821140 load */
    /* @4821148 constant */
    /* @4821152 add */
    /* @4821156 constant */
    /* @4821160 cast */
    /* @4821164 constant */
    /* @4821168 cast */
    /* @4821172 call */
    GM_SITE(vm, 527, 4821172);
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(145));
    /* @4821180 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(157), VAL(1), v64, v65, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4821184: ;
    /* @4821184 load */
    /* @4821192 constant */
    /* @4821196 add */
    /* @4821200 store */
    v66 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v66);
    /* @4821208 b */
    goto L_4820900;
    L_4821212: ;
    return;
}
