/* generated from CODE 432 (gml_Object_obj_healthregen_Draw_0), source start 4608220, end 4611492. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0432(GmVM* vm) {
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
    /* @4608220 load */
    /* @4608228 constant */
    /* @4608232 cmp */
    /* @4608236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4608708;
    /* @4608240 constant */
    /* @4608244 cast */
    /* @4608248 constant */
    /* @4608252 cast */
    /* @4608256 constant */
    /* @4608260 cast */
    /* @4608264 constant */
    /* @4608276 cast */
    /* @4608280 constant */
    /* @4608292 cast */
    /* @4608296 load */
    /* @4608304 load */
    /* @4608312 constant */
    /* @4608316 cast */
    /* @4608320 constant */
    /* @4608324 cast */
    /* @4608328 call */
    GM_SITE(vm, 432, 4608328);
    /* @4608336 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4608340 constant */
    /* @4608344 cast */
    /* @4608348 call */
    GM_SITE(vm, 432, 4608348);
    /* @4608356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4608360 constant */
    /* @4608368 cast */
    /* @4608372 call */
    GM_SITE(vm, 432, 4608372);
    /* @4608380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4608384 string */
    /* @4608392 cast */
    /* @4608396 load */
    /* @4608404 load */
    /* @4608412 constant */
    /* @4608416 add */
    /* @4608420 call */
    GM_SITE(vm, 432, 4608420);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4608428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(811)));
    /* @4608432 string */
    /* @4608440 cast */
    /* @4608444 load */
    /* @4608452 constant */
    /* @4608456 add */
    /* @4608460 load */
    /* @4608468 constant */
    /* @4608472 add */
    /* @4608476 call */
    GM_SITE(vm, 432, 4608476);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4608484 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(812)));
    /* @4608488 constant */
    /* @4608492 cast */
    /* @4608496 constant */
    /* @4608500 cast */
    /* @4608504 constant */
    /* @4608508 cast */
    /* @4608512 constant */
    /* @4608516 cast */
    /* @4608520 constant */
    /* @4608524 cast */
    /* @4608528 load */
    /* @4608536 constant */
    /* @4608540 add */
    /* @4608544 load */
    /* @4608552 constant */
    /* @4608556 add */
    /* @4608560 constant */
    /* @4608564 cast */
    /* @4608568 constant */
    /* @4608572 cast */
    /* @4608576 call */
    GM_SITE(vm, 432, 4608576);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4608584 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4608588 load */
    /* @4608596 constant */
    /* @4608600 cmp */
    /* @4608604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4608708;
    /* @4608608 constant */
    /* @4608612 cast */
    /* @4608616 constant */
    /* @4608620 cast */
    /* @4608624 constant */
    /* @4608628 cast */
    /* @4608632 constant */
    /* @4608644 cast */
    /* @4608648 constant */
    /* @4608660 cast */
    /* @4608664 load */
    /* @4608672 load */
    /* @4608680 constant */
    /* @4608684 cast */
    /* @4608688 constant */
    /* @4608692 cast */
    /* @4608696 call */
    GM_SITE(vm, 432, 4608696);
    /* @4608704 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4608708: ;
    /* @4608708 load */
    /* @4608716 constant */
    /* @4608720 cmp */
    /* @4608724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4609268;
    /* @4608728 constant */
    /* @4608732 constant */
    /* @4608736 load */
    /* @4608744 constant */
    /* @4608748 add */
    /* @4608752 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4608760 constant */
    /* @4608764 constant */
    /* @4608768 load */
    /* @4608776 constant */
    /* @4608780 add */
    /* @4608784 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    GM_WRITE(vm, -1, "y", v7);
    /* @4608792 constant */
    /* @4608796 cast */
    /* @4608800 constant */
    /* @4608804 cast */
    /* @4608808 constant */
    /* @4608812 cast */
    /* @4608816 constant */
    /* @4608820 cast */
    /* @4608824 constant */
    /* @4608828 cast */
    /* @4608832 load */
    /* @4608840 load */
    /* @4608848 constant */
    /* @4608852 cast */
    /* @4608856 constant */
    /* @4608860 cast */
    /* @4608864 call */
    GM_SITE(vm, 432, 4608864);
    /* @4608872 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4608876 constant */
    /* @4608880 cast */
    /* @4608884 call */
    GM_SITE(vm, 432, 4608884);
    /* @4608892 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4608896 constant */
    /* @4608904 cast */
    /* @4608908 call */
    GM_SITE(vm, 432, 4608908);
    /* @4608916 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4608920 string */
    /* @4608928 cast */
    /* @4608932 load */
    /* @4608940 constant */
    /* @4608944 add */
    /* @4608948 load */
    /* @4608956 constant */
    /* @4608960 add */
    /* @4608964 call */
    GM_SITE(vm, 432, 4608964);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4608972 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(811)));
    /* @4608976 string */
    /* @4608984 cast */
    /* @4608988 load */
    /* @4608996 constant */
    /* @4609000 add */
    /* @4609004 load */
    /* @4609012 constant */
    /* @4609016 add */
    /* @4609020 call */
    GM_SITE(vm, 432, 4609020);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4609028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(812)));
    /* @4609032 constant */
    /* @4609036 cast */
    /* @4609040 constant */
    /* @4609044 cast */
    /* @4609048 constant */
    /* @4609052 cast */
    /* @4609056 constant */
    /* @4609068 cast */
    /* @4609072 constant */
    /* @4609084 cast */
    /* @4609088 load */
    /* @4609096 constant */
    /* @4609100 add */
    /* @4609104 load */
    /* @4609112 constant */
    /* @4609116 add */
    /* @4609120 constant */
    /* @4609124 cast */
    /* @4609128 constant */
    /* @4609132 cast */
    /* @4609136 call */
    GM_SITE(vm, 432, 4609136);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4609144 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4609148 load */
    /* @4609156 constant */
    /* @4609160 cmp */
    /* @4609164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4609268;
    /* @4609168 constant */
    /* @4609172 cast */
    /* @4609176 constant */
    /* @4609180 cast */
    /* @4609184 constant */
    /* @4609188 cast */
    /* @4609192 constant */
    /* @4609204 cast */
    /* @4609208 constant */
    /* @4609220 cast */
    /* @4609224 load */
    /* @4609232 load */
    /* @4609240 constant */
    /* @4609244 cast */
    /* @4609248 constant */
    /* @4609252 cast */
    /* @4609256 call */
    GM_SITE(vm, 432, 4609256);
    /* @4609264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4609268: ;
    /* @4609268 load */
    /* @4609276 constant */
    /* @4609280 cmp */
    /* @4609284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4609828;
    /* @4609288 constant */
    /* @4609292 constant */
    /* @4609296 load */
    /* @4609304 constant */
    /* @4609308 add */
    /* @4609312 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4609320 constant */
    /* @4609324 constant */
    /* @4609328 load */
    /* @4609336 constant */
    /* @4609340 add */
    /* @4609344 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(180));
    GM_WRITE(vm, -1, "y", v15);
    /* @4609352 constant */
    /* @4609356 cast */
    /* @4609360 constant */
    /* @4609364 cast */
    /* @4609368 constant */
    /* @4609372 cast */
    /* @4609376 constant */
    /* @4609388 cast */
    /* @4609392 constant */
    /* @4609404 cast */
    /* @4609408 load */
    /* @4609416 load */
    /* @4609424 constant */
    /* @4609428 cast */
    /* @4609432 constant */
    /* @4609436 cast */
    /* @4609440 call */
    GM_SITE(vm, 432, 4609440);
    /* @4609448 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4609452 constant */
    /* @4609456 cast */
    /* @4609460 call */
    GM_SITE(vm, 432, 4609460);
    /* @4609468 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4609472 constant */
    /* @4609480 cast */
    /* @4609484 call */
    GM_SITE(vm, 432, 4609484);
    /* @4609492 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4609496 string */
    /* @4609504 cast */
    /* @4609508 load */
    /* @4609516 constant */
    /* @4609520 add */
    /* @4609524 load */
    /* @4609532 constant */
    /* @4609536 add */
    /* @4609540 call */
    GM_SITE(vm, 432, 4609540);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4609548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(811)));
    /* @4609552 string */
    /* @4609560 cast */
    /* @4609564 load */
    /* @4609572 constant */
    /* @4609576 add */
    /* @4609580 load */
    /* @4609588 constant */
    /* @4609592 add */
    /* @4609596 call */
    GM_SITE(vm, 432, 4609596);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4609604 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(812)));
    /* @4609608 constant */
    /* @4609612 cast */
    /* @4609616 constant */
    /* @4609620 cast */
    /* @4609624 constant */
    /* @4609628 cast */
    /* @4609632 constant */
    /* @4609636 cast */
    /* @4609640 constant */
    /* @4609644 cast */
    /* @4609648 load */
    /* @4609656 constant */
    /* @4609660 add */
    /* @4609664 load */
    /* @4609672 constant */
    /* @4609676 add */
    /* @4609680 constant */
    /* @4609684 cast */
    /* @4609688 constant */
    /* @4609692 cast */
    /* @4609696 call */
    GM_SITE(vm, 432, 4609696);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4609704 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4609708 load */
    /* @4609716 constant */
    /* @4609720 cmp */
    /* @4609724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4609828;
    /* @4609728 constant */
    /* @4609732 cast */
    /* @4609736 constant */
    /* @4609740 cast */
    /* @4609744 constant */
    /* @4609748 cast */
    /* @4609752 constant */
    /* @4609764 cast */
    /* @4609768 constant */
    /* @4609780 cast */
    /* @4609784 load */
    /* @4609792 load */
    /* @4609800 constant */
    /* @4609804 cast */
    /* @4609808 constant */
    /* @4609812 cast */
    /* @4609816 call */
    GM_SITE(vm, 432, 4609816);
    /* @4609824 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4609828: ;
    /* @4609828 load */
    /* @4609836 constant */
    /* @4609840 cmp */
    /* @4609844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4610388;
    /* @4609848 constant */
    /* @4609852 constant */
    /* @4609856 load */
    /* @4609864 constant */
    /* @4609868 add */
    /* @4609872 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4609880 constant */
    /* @4609884 constant */
    /* @4609888 load */
    /* @4609896 constant */
    /* @4609900 add */
    /* @4609904 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(180));
    GM_WRITE(vm, -1, "y", v23);
    /* @4609912 constant */
    /* @4609916 cast */
    /* @4609920 constant */
    /* @4609924 cast */
    /* @4609928 constant */
    /* @4609932 cast */
    /* @4609936 constant */
    /* @4609948 cast */
    /* @4609952 constant */
    /* @4609964 cast */
    /* @4609968 load */
    /* @4609976 load */
    /* @4609984 constant */
    /* @4609988 cast */
    /* @4609992 constant */
    /* @4609996 cast */
    /* @4610000 call */
    GM_SITE(vm, 432, 4610000);
    /* @4610008 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4610012 constant */
    /* @4610016 cast */
    /* @4610020 call */
    GM_SITE(vm, 432, 4610020);
    /* @4610028 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4610032 constant */
    /* @4610040 cast */
    /* @4610044 call */
    GM_SITE(vm, 432, 4610044);
    /* @4610052 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4610056 string */
    /* @4610064 cast */
    /* @4610068 load */
    /* @4610076 constant */
    /* @4610080 add */
    /* @4610084 load */
    /* @4610092 constant */
    /* @4610096 add */
    /* @4610100 call */
    GM_SITE(vm, 432, 4610100);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4610108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(811)));
    /* @4610112 string */
    /* @4610120 cast */
    /* @4610124 load */
    /* @4610132 constant */
    /* @4610136 add */
    /* @4610140 load */
    /* @4610148 constant */
    /* @4610152 add */
    /* @4610156 call */
    GM_SITE(vm, 432, 4610156);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4610164 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(812)));
    /* @4610168 constant */
    /* @4610172 cast */
    /* @4610176 constant */
    /* @4610180 cast */
    /* @4610184 constant */
    /* @4610188 cast */
    /* @4610192 constant */
    /* @4610196 cast */
    /* @4610200 constant */
    /* @4610204 cast */
    /* @4610208 load */
    /* @4610216 constant */
    /* @4610220 add */
    /* @4610224 load */
    /* @4610232 constant */
    /* @4610236 add */
    /* @4610240 constant */
    /* @4610244 cast */
    /* @4610248 constant */
    /* @4610252 cast */
    /* @4610256 call */
    GM_SITE(vm, 432, 4610256);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4610264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v28, v29, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4610268 load */
    /* @4610276 constant */
    /* @4610280 cmp */
    /* @4610284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4610388;
    /* @4610288 constant */
    /* @4610292 cast */
    /* @4610296 constant */
    /* @4610300 cast */
    /* @4610304 constant */
    /* @4610308 cast */
    /* @4610312 constant */
    /* @4610324 cast */
    /* @4610328 constant */
    /* @4610340 cast */
    /* @4610344 load */
    /* @4610352 load */
    /* @4610360 constant */
    /* @4610364 cast */
    /* @4610368 constant */
    /* @4610372 cast */
    /* @4610376 call */
    GM_SITE(vm, 432, 4610376);
    /* @4610384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4610388: ;
    /* @4610388 load */
    /* @4610396 constant */
    /* @4610400 cmp */
    /* @4610404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4610940;
    /* @4610408 constant */
    /* @4610412 constant */
    /* @4610416 load */
    /* @4610424 constant */
    /* @4610428 add */
    /* @4610432 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4610440 constant */
    /* @4610444 constant */
    /* @4610448 load */
    /* @4610456 constant */
    /* @4610460 add */
    /* @4610464 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    GM_WRITE(vm, -1, "y", v31);
    /* @4610472 constant */
    /* @4610476 cast */
    /* @4610480 constant */
    /* @4610484 cast */
    /* @4610488 constant */
    /* @4610492 cast */
    /* @4610496 constant */
    /* @4610508 cast */
    /* @4610512 constant */
    /* @4610524 cast */
    /* @4610528 load */
    /* @4610536 load */
    /* @4610544 constant */
    /* @4610548 cast */
    /* @4610552 constant */
    /* @4610556 cast */
    /* @4610560 call */
    GM_SITE(vm, 432, 4610560);
    /* @4610568 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4610572 constant */
    /* @4610576 cast */
    /* @4610580 call */
    GM_SITE(vm, 432, 4610580);
    /* @4610588 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4610592 constant */
    /* @4610600 cast */
    /* @4610604 call */
    GM_SITE(vm, 432, 4610604);
    /* @4610612 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4610616 string */
    /* @4610624 cast */
    /* @4610628 load */
    /* @4610636 load */
    /* @4610644 constant */
    /* @4610648 add */
    /* @4610652 call */
    GM_SITE(vm, 432, 4610652);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4610660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(811)));
    /* @4610664 string */
    /* @4610672 cast */
    /* @4610676 load */
    /* @4610684 constant */
    /* @4610688 add */
    /* @4610692 load */
    /* @4610700 constant */
    /* @4610704 add */
    /* @4610708 call */
    GM_SITE(vm, 432, 4610708);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4610716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(812)));
    /* @4610720 constant */
    /* @4610724 cast */
    /* @4610728 constant */
    /* @4610732 cast */
    /* @4610736 constant */
    /* @4610740 cast */
    /* @4610744 constant */
    /* @4610748 cast */
    /* @4610752 constant */
    /* @4610756 cast */
    /* @4610760 load */
    /* @4610768 constant */
    /* @4610772 add */
    /* @4610776 load */
    /* @4610784 constant */
    /* @4610788 add */
    /* @4610792 constant */
    /* @4610796 cast */
    /* @4610800 constant */
    /* @4610804 cast */
    /* @4610808 call */
    GM_SITE(vm, 432, 4610808);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4610816 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4610820 load */
    /* @4610828 constant */
    /* @4610832 cmp */
    /* @4610836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4610940;
    /* @4610840 constant */
    /* @4610844 cast */
    /* @4610848 constant */
    /* @4610852 cast */
    /* @4610856 constant */
    /* @4610860 cast */
    /* @4610864 constant */
    /* @4610876 cast */
    /* @4610880 constant */
    /* @4610892 cast */
    /* @4610896 load */
    /* @4610904 load */
    /* @4610912 constant */
    /* @4610916 cast */
    /* @4610920 constant */
    /* @4610924 cast */
    /* @4610928 call */
    GM_SITE(vm, 432, 4610928);
    /* @4610936 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4610940: ;
    /* @4610940 load */
    /* @4610948 constant */
    /* @4610952 cmp */
    /* @4610956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4611492;
    /* @4610960 constant */
    /* @4610964 constant */
    /* @4610968 load */
    /* @4610976 constant */
    /* @4610980 add */
    /* @4610984 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4610992 constant */
    /* @4610996 constant */
    /* @4611000 load */
    /* @4611008 constant */
    /* @4611012 add */
    /* @4611016 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    GM_WRITE(vm, -1, "y", v38);
    /* @4611024 constant */
    /* @4611028 cast */
    /* @4611032 constant */
    /* @4611036 cast */
    /* @4611040 constant */
    /* @4611044 cast */
    /* @4611048 constant */
    /* @4611060 cast */
    /* @4611064 constant */
    /* @4611076 cast */
    /* @4611080 load */
    /* @4611088 load */
    /* @4611096 constant */
    /* @4611100 cast */
    /* @4611104 constant */
    /* @4611108 cast */
    /* @4611112 call */
    GM_SITE(vm, 432, 4611112);
    /* @4611120 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4611124 constant */
    /* @4611128 cast */
    /* @4611132 call */
    GM_SITE(vm, 432, 4611132);
    /* @4611140 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4611144 constant */
    /* @4611152 cast */
    /* @4611156 call */
    GM_SITE(vm, 432, 4611156);
    /* @4611164 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4611168 string */
    /* @4611176 cast */
    /* @4611180 load */
    /* @4611188 load */
    /* @4611196 constant */
    /* @4611200 add */
    /* @4611204 call */
    GM_SITE(vm, 432, 4611204);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4611212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(811)));
    /* @4611216 string */
    /* @4611224 cast */
    /* @4611228 load */
    /* @4611236 constant */
    /* @4611240 add */
    /* @4611244 load */
    /* @4611252 constant */
    /* @4611256 add */
    /* @4611260 call */
    GM_SITE(vm, 432, 4611260);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4611268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(812)));
    /* @4611272 constant */
    /* @4611276 cast */
    /* @4611280 constant */
    /* @4611284 cast */
    /* @4611288 constant */
    /* @4611292 cast */
    /* @4611296 constant */
    /* @4611300 cast */
    /* @4611304 constant */
    /* @4611308 cast */
    /* @4611312 load */
    /* @4611320 constant */
    /* @4611324 add */
    /* @4611328 load */
    /* @4611336 constant */
    /* @4611340 add */
    /* @4611344 constant */
    /* @4611348 cast */
    /* @4611352 constant */
    /* @4611356 cast */
    /* @4611360 call */
    GM_SITE(vm, 432, 4611360);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4611368 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4611372 load */
    /* @4611380 constant */
    /* @4611384 cmp */
    /* @4611388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "healthregenbought") == VAL(1)))) goto L_4611492;
    /* @4611392 constant */
    /* @4611396 cast */
    /* @4611400 constant */
    /* @4611404 cast */
    /* @4611408 constant */
    /* @4611412 cast */
    /* @4611416 constant */
    /* @4611428 cast */
    /* @4611432 constant */
    /* @4611444 cast */
    /* @4611448 load */
    /* @4611456 load */
    /* @4611464 constant */
    /* @4611468 cast */
    /* @4611472 constant */
    /* @4611476 cast */
    /* @4611480 call */
    GM_SITE(vm, 432, 4611480);
    /* @4611488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4611492: ;
    return;
}
