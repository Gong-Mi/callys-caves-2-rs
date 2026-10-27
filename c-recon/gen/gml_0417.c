/* generated from CODE 417 (gml_Object_obj_powerupgrade2_Draw_0), source start 4583416, end 4586768. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0417(GmVM* vm) {
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
    /* @4583416 load */
    /* @4583424 constant */
    /* @4583428 cmp */
    /* @4583432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4583920;
    /* @4583436 constant */
    /* @4583440 cast */
    /* @4583444 constant */
    /* @4583448 cast */
    /* @4583452 constant */
    /* @4583456 cast */
    /* @4583460 constant */
    /* @4583472 cast */
    /* @4583476 constant */
    /* @4583488 cast */
    /* @4583492 load */
    /* @4583500 load */
    /* @4583508 constant */
    /* @4583512 cast */
    /* @4583516 constant */
    /* @4583520 cast */
    /* @4583524 call */
    GM_SITE(vm, 417, 4583524);
    /* @4583532 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4583536 constant */
    /* @4583540 cast */
    /* @4583544 call */
    GM_SITE(vm, 417, 4583544);
    /* @4583552 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4583556 constant */
    /* @4583564 cast */
    /* @4583568 call */
    GM_SITE(vm, 417, 4583568);
    /* @4583576 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4583580 string */
    /* @4583588 cast */
    /* @4583592 load */
    /* @4583600 load */
    /* @4583608 constant */
    /* @4583612 add */
    /* @4583616 call */
    GM_SITE(vm, 417, 4583616);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4583624 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(798)));
    /* @4583628 string */
    /* @4583636 cast */
    /* @4583640 load */
    /* @4583648 constant */
    /* @4583652 add */
    /* @4583656 load */
    /* @4583664 constant */
    /* @4583668 add */
    /* @4583672 call */
    GM_SITE(vm, 417, 4583672);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4583680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(799)));
    /* @4583684 constant */
    /* @4583688 cast */
    /* @4583692 constant */
    /* @4583696 cast */
    /* @4583700 constant */
    /* @4583704 cast */
    /* @4583708 constant */
    /* @4583720 cast */
    /* @4583724 constant */
    /* @4583736 cast */
    /* @4583740 load */
    /* @4583748 constant */
    /* @4583752 add */
    /* @4583756 load */
    /* @4583764 constant */
    /* @4583768 add */
    /* @4583772 constant */
    /* @4583776 cast */
    /* @4583780 constant */
    /* @4583784 cast */
    /* @4583788 call */
    GM_SITE(vm, 417, 4583788);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4583796 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4583800 load */
    /* @4583808 constant */
    /* @4583812 cmp */
    /* @4583816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4583920;
    /* @4583820 constant */
    /* @4583824 cast */
    /* @4583828 constant */
    /* @4583832 cast */
    /* @4583836 constant */
    /* @4583840 cast */
    /* @4583844 constant */
    /* @4583856 cast */
    /* @4583860 constant */
    /* @4583872 cast */
    /* @4583876 load */
    /* @4583884 load */
    /* @4583892 constant */
    /* @4583896 cast */
    /* @4583900 constant */
    /* @4583904 cast */
    /* @4583908 call */
    GM_SITE(vm, 417, 4583908);
    /* @4583916 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4583920: ;
    /* @4583920 load */
    /* @4583928 constant */
    /* @4583932 cmp */
    /* @4583936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4584480;
    /* @4583940 constant */
    /* @4583944 constant */
    /* @4583948 load */
    /* @4583956 constant */
    /* @4583960 add */
    /* @4583964 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4583972 constant */
    /* @4583976 constant */
    /* @4583980 load */
    /* @4583988 constant */
    /* @4583992 add */
    /* @4583996 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    GM_WRITE(vm, -1, "y", v7);
    /* @4584004 constant */
    /* @4584008 cast */
    /* @4584012 constant */
    /* @4584016 cast */
    /* @4584020 constant */
    /* @4584024 cast */
    /* @4584028 constant */
    /* @4584032 cast */
    /* @4584036 constant */
    /* @4584040 cast */
    /* @4584044 load */
    /* @4584052 load */
    /* @4584060 constant */
    /* @4584064 cast */
    /* @4584068 constant */
    /* @4584072 cast */
    /* @4584076 call */
    GM_SITE(vm, 417, 4584076);
    /* @4584084 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4584088 constant */
    /* @4584092 cast */
    /* @4584096 call */
    GM_SITE(vm, 417, 4584096);
    /* @4584104 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4584108 constant */
    /* @4584116 cast */
    /* @4584120 call */
    GM_SITE(vm, 417, 4584120);
    /* @4584128 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4584132 string */
    /* @4584140 cast */
    /* @4584144 load */
    /* @4584152 constant */
    /* @4584156 add */
    /* @4584160 load */
    /* @4584168 constant */
    /* @4584172 add */
    /* @4584176 call */
    GM_SITE(vm, 417, 4584176);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4584184 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(798)));
    /* @4584188 string */
    /* @4584196 cast */
    /* @4584200 load */
    /* @4584208 constant */
    /* @4584212 add */
    /* @4584216 load */
    /* @4584224 constant */
    /* @4584228 add */
    /* @4584232 call */
    GM_SITE(vm, 417, 4584232);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4584240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(799)));
    /* @4584244 constant */
    /* @4584248 cast */
    /* @4584252 constant */
    /* @4584256 cast */
    /* @4584260 constant */
    /* @4584264 cast */
    /* @4584268 constant */
    /* @4584280 cast */
    /* @4584284 constant */
    /* @4584296 cast */
    /* @4584300 load */
    /* @4584308 constant */
    /* @4584312 add */
    /* @4584316 load */
    /* @4584324 constant */
    /* @4584328 add */
    /* @4584332 constant */
    /* @4584336 cast */
    /* @4584340 constant */
    /* @4584344 cast */
    /* @4584348 call */
    GM_SITE(vm, 417, 4584348);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4584356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v12, v13, VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    /* @4584360 load */
    /* @4584368 constant */
    /* @4584372 cmp */
    /* @4584376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4584480;
    /* @4584380 constant */
    /* @4584384 cast */
    /* @4584388 constant */
    /* @4584392 cast */
    /* @4584396 constant */
    /* @4584400 cast */
    /* @4584404 constant */
    /* @4584416 cast */
    /* @4584420 constant */
    /* @4584432 cast */
    /* @4584436 load */
    /* @4584444 load */
    /* @4584452 constant */
    /* @4584456 cast */
    /* @4584460 constant */
    /* @4584464 cast */
    /* @4584468 call */
    GM_SITE(vm, 417, 4584468);
    /* @4584476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4584480: ;
    /* @4584480 load */
    /* @4584488 constant */
    /* @4584492 cmp */
    /* @4584496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4585056;
    /* @4584500 constant */
    /* @4584504 constant */
    /* @4584508 load */
    /* @4584516 constant */
    /* @4584520 add */
    /* @4584524 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4584532 constant */
    /* @4584536 constant */
    /* @4584540 load */
    /* @4584548 constant */
    /* @4584552 add */
    /* @4584556 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(180));
    GM_WRITE(vm, -1, "y", v15);
    /* @4584564 constant */
    /* @4584568 cast */
    /* @4584572 constant */
    /* @4584576 cast */
    /* @4584580 constant */
    /* @4584584 cast */
    /* @4584588 constant */
    /* @4584600 cast */
    /* @4584604 constant */
    /* @4584616 cast */
    /* @4584620 load */
    /* @4584628 load */
    /* @4584636 constant */
    /* @4584640 cast */
    /* @4584644 constant */
    /* @4584648 cast */
    /* @4584652 call */
    GM_SITE(vm, 417, 4584652);
    /* @4584660 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4584664 constant */
    /* @4584668 cast */
    /* @4584672 call */
    GM_SITE(vm, 417, 4584672);
    /* @4584680 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4584684 constant */
    /* @4584692 cast */
    /* @4584696 call */
    GM_SITE(vm, 417, 4584696);
    /* @4584704 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4584708 string */
    /* @4584716 cast */
    /* @4584720 load */
    /* @4584728 constant */
    /* @4584732 add */
    /* @4584736 load */
    /* @4584744 constant */
    /* @4584748 add */
    /* @4584752 call */
    GM_SITE(vm, 417, 4584752);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4584760 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(798)));
    /* @4584764 string */
    /* @4584772 cast */
    /* @4584776 load */
    /* @4584784 constant */
    /* @4584788 add */
    /* @4584792 load */
    /* @4584800 constant */
    /* @4584804 add */
    /* @4584808 call */
    GM_SITE(vm, 417, 4584808);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4584816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(799)));
    /* @4584820 constant */
    /* @4584824 cast */
    /* @4584828 constant */
    /* @4584832 cast */
    /* @4584836 constant */
    /* @4584840 cast */
    /* @4584844 constant */
    /* @4584856 cast */
    /* @4584860 constant */
    /* @4584872 cast */
    /* @4584876 load */
    /* @4584884 constant */
    /* @4584888 add */
    /* @4584892 load */
    /* @4584900 constant */
    /* @4584904 add */
    /* @4584908 constant */
    /* @4584912 cast */
    /* @4584916 constant */
    /* @4584920 cast */
    /* @4584924 call */
    GM_SITE(vm, 417, 4584924);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4584932 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v20, v21, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4584936 load */
    /* @4584944 constant */
    /* @4584948 cmp */
    /* @4584952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4585056;
    /* @4584956 constant */
    /* @4584960 cast */
    /* @4584964 constant */
    /* @4584968 cast */
    /* @4584972 constant */
    /* @4584976 cast */
    /* @4584980 constant */
    /* @4584992 cast */
    /* @4584996 constant */
    /* @4585008 cast */
    /* @4585012 load */
    /* @4585020 load */
    /* @4585028 constant */
    /* @4585032 cast */
    /* @4585036 constant */
    /* @4585040 cast */
    /* @4585044 call */
    GM_SITE(vm, 417, 4585044);
    /* @4585052 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4585056: ;
    /* @4585056 load */
    /* @4585064 constant */
    /* @4585068 cmp */
    /* @4585072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4585632;
    /* @4585076 constant */
    /* @4585080 constant */
    /* @4585084 load */
    /* @4585092 constant */
    /* @4585096 add */
    /* @4585100 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4585108 constant */
    /* @4585112 constant */
    /* @4585116 load */
    /* @4585124 constant */
    /* @4585128 add */
    /* @4585132 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(180));
    GM_WRITE(vm, -1, "y", v23);
    /* @4585140 constant */
    /* @4585144 cast */
    /* @4585148 constant */
    /* @4585152 cast */
    /* @4585156 constant */
    /* @4585160 cast */
    /* @4585164 constant */
    /* @4585176 cast */
    /* @4585180 constant */
    /* @4585192 cast */
    /* @4585196 load */
    /* @4585204 load */
    /* @4585212 constant */
    /* @4585216 cast */
    /* @4585220 constant */
    /* @4585224 cast */
    /* @4585228 call */
    GM_SITE(vm, 417, 4585228);
    /* @4585236 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4585240 constant */
    /* @4585244 cast */
    /* @4585248 call */
    GM_SITE(vm, 417, 4585248);
    /* @4585256 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4585260 constant */
    /* @4585268 cast */
    /* @4585272 call */
    GM_SITE(vm, 417, 4585272);
    /* @4585280 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4585284 string */
    /* @4585292 cast */
    /* @4585296 load */
    /* @4585304 constant */
    /* @4585308 add */
    /* @4585312 load */
    /* @4585320 constant */
    /* @4585324 add */
    /* @4585328 call */
    GM_SITE(vm, 417, 4585328);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4585336 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(798)));
    /* @4585340 string */
    /* @4585348 cast */
    /* @4585352 load */
    /* @4585360 constant */
    /* @4585364 add */
    /* @4585368 load */
    /* @4585376 constant */
    /* @4585380 add */
    /* @4585384 call */
    GM_SITE(vm, 417, 4585384);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4585392 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(799)));
    /* @4585396 constant */
    /* @4585400 cast */
    /* @4585404 constant */
    /* @4585408 cast */
    /* @4585412 constant */
    /* @4585416 cast */
    /* @4585420 constant */
    /* @4585432 cast */
    /* @4585436 constant */
    /* @4585448 cast */
    /* @4585452 load */
    /* @4585460 constant */
    /* @4585464 add */
    /* @4585468 load */
    /* @4585476 constant */
    /* @4585480 add */
    /* @4585484 constant */
    /* @4585488 cast */
    /* @4585492 constant */
    /* @4585496 cast */
    /* @4585500 call */
    GM_SITE(vm, 417, 4585500);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4585508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v28, v29, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4585512 load */
    /* @4585520 constant */
    /* @4585524 cmp */
    /* @4585528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4585632;
    /* @4585532 constant */
    /* @4585536 cast */
    /* @4585540 constant */
    /* @4585544 cast */
    /* @4585548 constant */
    /* @4585552 cast */
    /* @4585556 constant */
    /* @4585568 cast */
    /* @4585572 constant */
    /* @4585584 cast */
    /* @4585588 load */
    /* @4585596 load */
    /* @4585604 constant */
    /* @4585608 cast */
    /* @4585612 constant */
    /* @4585616 cast */
    /* @4585620 call */
    GM_SITE(vm, 417, 4585620);
    /* @4585628 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4585632: ;
    /* @4585632 load */
    /* @4585640 constant */
    /* @4585644 cmp */
    /* @4585648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4586200;
    /* @4585652 constant */
    /* @4585656 constant */
    /* @4585660 load */
    /* @4585668 constant */
    /* @4585672 add */
    /* @4585676 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4585684 constant */
    /* @4585688 constant */
    /* @4585692 load */
    /* @4585700 constant */
    /* @4585704 add */
    /* @4585708 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    GM_WRITE(vm, -1, "y", v31);
    /* @4585716 constant */
    /* @4585720 cast */
    /* @4585724 constant */
    /* @4585728 cast */
    /* @4585732 constant */
    /* @4585736 cast */
    /* @4585740 constant */
    /* @4585752 cast */
    /* @4585756 constant */
    /* @4585768 cast */
    /* @4585772 load */
    /* @4585780 load */
    /* @4585788 constant */
    /* @4585792 cast */
    /* @4585796 constant */
    /* @4585800 cast */
    /* @4585804 call */
    GM_SITE(vm, 417, 4585804);
    /* @4585812 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4585816 constant */
    /* @4585820 cast */
    /* @4585824 call */
    GM_SITE(vm, 417, 4585824);
    /* @4585832 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4585836 constant */
    /* @4585844 cast */
    /* @4585848 call */
    GM_SITE(vm, 417, 4585848);
    /* @4585856 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4585860 string */
    /* @4585868 cast */
    /* @4585872 load */
    /* @4585880 load */
    /* @4585888 constant */
    /* @4585892 add */
    /* @4585896 call */
    GM_SITE(vm, 417, 4585896);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4585904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(798)));
    /* @4585908 string */
    /* @4585916 cast */
    /* @4585920 load */
    /* @4585928 constant */
    /* @4585932 add */
    /* @4585936 load */
    /* @4585944 constant */
    /* @4585948 add */
    /* @4585952 call */
    GM_SITE(vm, 417, 4585952);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4585960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(799)));
    /* @4585964 constant */
    /* @4585968 cast */
    /* @4585972 constant */
    /* @4585976 cast */
    /* @4585980 constant */
    /* @4585984 cast */
    /* @4585988 constant */
    /* @4586000 cast */
    /* @4586004 constant */
    /* @4586016 cast */
    /* @4586020 load */
    /* @4586028 constant */
    /* @4586032 add */
    /* @4586036 load */
    /* @4586044 constant */
    /* @4586048 add */
    /* @4586052 constant */
    /* @4586056 cast */
    /* @4586060 constant */
    /* @4586064 cast */
    /* @4586068 call */
    GM_SITE(vm, 417, 4586068);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4586076 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4586080 load */
    /* @4586088 constant */
    /* @4586092 cmp */
    /* @4586096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4586200;
    /* @4586100 constant */
    /* @4586104 cast */
    /* @4586108 constant */
    /* @4586112 cast */
    /* @4586116 constant */
    /* @4586120 cast */
    /* @4586124 constant */
    /* @4586136 cast */
    /* @4586140 constant */
    /* @4586152 cast */
    /* @4586156 load */
    /* @4586164 load */
    /* @4586172 constant */
    /* @4586176 cast */
    /* @4586180 constant */
    /* @4586184 cast */
    /* @4586188 call */
    GM_SITE(vm, 417, 4586188);
    /* @4586196 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4586200: ;
    /* @4586200 load */
    /* @4586208 constant */
    /* @4586212 cmp */
    /* @4586216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4586768;
    /* @4586220 constant */
    /* @4586224 constant */
    /* @4586228 load */
    /* @4586236 constant */
    /* @4586240 add */
    /* @4586244 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4586252 constant */
    /* @4586256 constant */
    /* @4586260 load */
    /* @4586268 constant */
    /* @4586272 add */
    /* @4586276 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    GM_WRITE(vm, -1, "y", v38);
    /* @4586284 constant */
    /* @4586288 cast */
    /* @4586292 constant */
    /* @4586296 cast */
    /* @4586300 constant */
    /* @4586304 cast */
    /* @4586308 constant */
    /* @4586320 cast */
    /* @4586324 constant */
    /* @4586336 cast */
    /* @4586340 load */
    /* @4586348 load */
    /* @4586356 constant */
    /* @4586360 cast */
    /* @4586364 constant */
    /* @4586368 cast */
    /* @4586372 call */
    GM_SITE(vm, 417, 4586372);
    /* @4586380 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4586384 constant */
    /* @4586388 cast */
    /* @4586392 call */
    GM_SITE(vm, 417, 4586392);
    /* @4586400 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4586404 constant */
    /* @4586412 cast */
    /* @4586416 call */
    GM_SITE(vm, 417, 4586416);
    /* @4586424 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4586428 string */
    /* @4586436 cast */
    /* @4586440 load */
    /* @4586448 load */
    /* @4586456 constant */
    /* @4586460 add */
    /* @4586464 call */
    GM_SITE(vm, 417, 4586464);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4586472 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(798)));
    /* @4586476 string */
    /* @4586484 cast */
    /* @4586488 load */
    /* @4586496 constant */
    /* @4586500 add */
    /* @4586504 load */
    /* @4586512 constant */
    /* @4586516 add */
    /* @4586520 call */
    GM_SITE(vm, 417, 4586520);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4586528 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(799)));
    /* @4586532 constant */
    /* @4586536 cast */
    /* @4586540 constant */
    /* @4586544 cast */
    /* @4586548 constant */
    /* @4586552 cast */
    /* @4586556 constant */
    /* @4586568 cast */
    /* @4586572 constant */
    /* @4586584 cast */
    /* @4586588 load */
    /* @4586596 constant */
    /* @4586600 add */
    /* @4586604 load */
    /* @4586612 constant */
    /* @4586616 add */
    /* @4586620 constant */
    /* @4586624 cast */
    /* @4586628 constant */
    /* @4586632 cast */
    /* @4586636 call */
    GM_SITE(vm, 417, 4586636);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4586644 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4586648 load */
    /* @4586656 constant */
    /* @4586660 cmp */
    /* @4586664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade2bought") == VAL(1)))) goto L_4586768;
    /* @4586668 constant */
    /* @4586672 cast */
    /* @4586676 constant */
    /* @4586680 cast */
    /* @4586684 constant */
    /* @4586688 cast */
    /* @4586692 constant */
    /* @4586704 cast */
    /* @4586708 constant */
    /* @4586720 cast */
    /* @4586724 load */
    /* @4586732 load */
    /* @4586740 constant */
    /* @4586744 cast */
    /* @4586748 constant */
    /* @4586752 cast */
    /* @4586756 call */
    GM_SITE(vm, 417, 4586756);
    /* @4586764 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4586768: ;
    return;
}
