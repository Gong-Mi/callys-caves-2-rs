/* generated from CODE 428 (gml_Object_obj_swordupgrade3_Draw_0), source start 4601172, end 4604524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0428(GmVM* vm) {
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
    /* @4601172 load */
    /* @4601180 constant */
    /* @4601184 cmp */
    /* @4601188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4601676;
    /* @4601192 constant */
    /* @4601196 cast */
    /* @4601200 constant */
    /* @4601204 cast */
    /* @4601208 constant */
    /* @4601212 cast */
    /* @4601216 constant */
    /* @4601228 cast */
    /* @4601232 constant */
    /* @4601244 cast */
    /* @4601248 load */
    /* @4601256 load */
    /* @4601264 constant */
    /* @4601268 cast */
    /* @4601272 constant */
    /* @4601276 cast */
    /* @4601280 call */
    GM_SITE(vm, 428, 4601280);
    /* @4601288 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4601292 constant */
    /* @4601296 cast */
    /* @4601300 call */
    GM_SITE(vm, 428, 4601300);
    /* @4601308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4601312 constant */
    /* @4601320 cast */
    /* @4601324 call */
    GM_SITE(vm, 428, 4601324);
    /* @4601332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4601336 string */
    /* @4601344 cast */
    /* @4601348 load */
    /* @4601356 load */
    /* @4601364 constant */
    /* @4601368 add */
    /* @4601372 call */
    GM_SITE(vm, 428, 4601372);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4601380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(807)));
    /* @4601384 string */
    /* @4601392 cast */
    /* @4601396 load */
    /* @4601404 constant */
    /* @4601408 add */
    /* @4601412 load */
    /* @4601420 constant */
    /* @4601424 add */
    /* @4601428 call */
    GM_SITE(vm, 428, 4601428);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4601436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(808)));
    /* @4601440 constant */
    /* @4601444 cast */
    /* @4601448 constant */
    /* @4601452 cast */
    /* @4601456 constant */
    /* @4601460 cast */
    /* @4601464 constant */
    /* @4601476 cast */
    /* @4601480 constant */
    /* @4601492 cast */
    /* @4601496 load */
    /* @4601504 constant */
    /* @4601508 add */
    /* @4601512 load */
    /* @4601520 constant */
    /* @4601524 add */
    /* @4601528 constant */
    /* @4601532 cast */
    /* @4601536 constant */
    /* @4601540 cast */
    /* @4601544 call */
    GM_SITE(vm, 428, 4601544);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4601552 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4601556 load */
    /* @4601564 constant */
    /* @4601568 cmp */
    /* @4601572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4601676;
    /* @4601576 constant */
    /* @4601580 cast */
    /* @4601584 constant */
    /* @4601588 cast */
    /* @4601592 constant */
    /* @4601596 cast */
    /* @4601600 constant */
    /* @4601612 cast */
    /* @4601616 constant */
    /* @4601628 cast */
    /* @4601632 load */
    /* @4601640 load */
    /* @4601648 constant */
    /* @4601652 cast */
    /* @4601656 constant */
    /* @4601660 cast */
    /* @4601664 call */
    GM_SITE(vm, 428, 4601664);
    /* @4601672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4601676: ;
    /* @4601676 load */
    /* @4601684 constant */
    /* @4601688 cmp */
    /* @4601692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4602236;
    /* @4601696 constant */
    /* @4601700 constant */
    /* @4601704 load */
    /* @4601712 constant */
    /* @4601716 add */
    /* @4601720 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4601728 constant */
    /* @4601732 constant */
    /* @4601736 load */
    /* @4601744 constant */
    /* @4601748 add */
    /* @4601752 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    GM_WRITE(vm, -1, "y", v7);
    /* @4601760 constant */
    /* @4601764 cast */
    /* @4601768 constant */
    /* @4601772 cast */
    /* @4601776 constant */
    /* @4601780 cast */
    /* @4601784 constant */
    /* @4601788 cast */
    /* @4601792 constant */
    /* @4601796 cast */
    /* @4601800 load */
    /* @4601808 load */
    /* @4601816 constant */
    /* @4601820 cast */
    /* @4601824 constant */
    /* @4601828 cast */
    /* @4601832 call */
    GM_SITE(vm, 428, 4601832);
    /* @4601840 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4601844 constant */
    /* @4601848 cast */
    /* @4601852 call */
    GM_SITE(vm, 428, 4601852);
    /* @4601860 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4601864 constant */
    /* @4601872 cast */
    /* @4601876 call */
    GM_SITE(vm, 428, 4601876);
    /* @4601884 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4601888 string */
    /* @4601896 cast */
    /* @4601900 load */
    /* @4601908 constant */
    /* @4601912 add */
    /* @4601916 load */
    /* @4601924 constant */
    /* @4601928 add */
    /* @4601932 call */
    GM_SITE(vm, 428, 4601932);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4601940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(807)));
    /* @4601944 string */
    /* @4601952 cast */
    /* @4601956 load */
    /* @4601964 constant */
    /* @4601968 add */
    /* @4601972 load */
    /* @4601980 constant */
    /* @4601984 add */
    /* @4601988 call */
    GM_SITE(vm, 428, 4601988);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4601996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(808)));
    /* @4602000 constant */
    /* @4602004 cast */
    /* @4602008 constant */
    /* @4602012 cast */
    /* @4602016 constant */
    /* @4602020 cast */
    /* @4602024 constant */
    /* @4602036 cast */
    /* @4602040 constant */
    /* @4602052 cast */
    /* @4602056 load */
    /* @4602064 constant */
    /* @4602068 add */
    /* @4602072 load */
    /* @4602080 constant */
    /* @4602084 add */
    /* @4602088 constant */
    /* @4602092 cast */
    /* @4602096 constant */
    /* @4602100 cast */
    /* @4602104 call */
    GM_SITE(vm, 428, 4602104);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4602112 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v12, v13, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4602116 load */
    /* @4602124 constant */
    /* @4602128 cmp */
    /* @4602132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4602236;
    /* @4602136 constant */
    /* @4602140 cast */
    /* @4602144 constant */
    /* @4602148 cast */
    /* @4602152 constant */
    /* @4602156 cast */
    /* @4602160 constant */
    /* @4602172 cast */
    /* @4602176 constant */
    /* @4602188 cast */
    /* @4602192 load */
    /* @4602200 load */
    /* @4602208 constant */
    /* @4602212 cast */
    /* @4602216 constant */
    /* @4602220 cast */
    /* @4602224 call */
    GM_SITE(vm, 428, 4602224);
    /* @4602232 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4602236: ;
    /* @4602236 load */
    /* @4602244 constant */
    /* @4602248 cmp */
    /* @4602252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4602812;
    /* @4602256 constant */
    /* @4602260 constant */
    /* @4602264 load */
    /* @4602272 constant */
    /* @4602276 add */
    /* @4602280 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4602288 constant */
    /* @4602292 constant */
    /* @4602296 load */
    /* @4602304 constant */
    /* @4602308 add */
    /* @4602312 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    GM_WRITE(vm, -1, "y", v15);
    /* @4602320 constant */
    /* @4602324 cast */
    /* @4602328 constant */
    /* @4602332 cast */
    /* @4602336 constant */
    /* @4602340 cast */
    /* @4602344 constant */
    /* @4602356 cast */
    /* @4602360 constant */
    /* @4602372 cast */
    /* @4602376 load */
    /* @4602384 load */
    /* @4602392 constant */
    /* @4602396 cast */
    /* @4602400 constant */
    /* @4602404 cast */
    /* @4602408 call */
    GM_SITE(vm, 428, 4602408);
    /* @4602416 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4602420 constant */
    /* @4602424 cast */
    /* @4602428 call */
    GM_SITE(vm, 428, 4602428);
    /* @4602436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4602440 constant */
    /* @4602448 cast */
    /* @4602452 call */
    GM_SITE(vm, 428, 4602452);
    /* @4602460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4602464 string */
    /* @4602472 cast */
    /* @4602476 load */
    /* @4602484 constant */
    /* @4602488 add */
    /* @4602492 load */
    /* @4602500 constant */
    /* @4602504 add */
    /* @4602508 call */
    GM_SITE(vm, 428, 4602508);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4602516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(807)));
    /* @4602520 string */
    /* @4602528 cast */
    /* @4602532 load */
    /* @4602540 constant */
    /* @4602544 add */
    /* @4602548 load */
    /* @4602556 constant */
    /* @4602560 add */
    /* @4602564 call */
    GM_SITE(vm, 428, 4602564);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4602572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(808)));
    /* @4602576 constant */
    /* @4602580 cast */
    /* @4602584 constant */
    /* @4602588 cast */
    /* @4602592 constant */
    /* @4602596 cast */
    /* @4602600 constant */
    /* @4602612 cast */
    /* @4602616 constant */
    /* @4602628 cast */
    /* @4602632 load */
    /* @4602640 constant */
    /* @4602644 add */
    /* @4602648 load */
    /* @4602656 constant */
    /* @4602660 add */
    /* @4602664 constant */
    /* @4602668 cast */
    /* @4602672 constant */
    /* @4602676 cast */
    /* @4602680 call */
    GM_SITE(vm, 428, 4602680);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4602688 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4602692 load */
    /* @4602700 constant */
    /* @4602704 cmp */
    /* @4602708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4602812;
    /* @4602712 constant */
    /* @4602716 cast */
    /* @4602720 constant */
    /* @4602724 cast */
    /* @4602728 constant */
    /* @4602732 cast */
    /* @4602736 constant */
    /* @4602748 cast */
    /* @4602752 constant */
    /* @4602764 cast */
    /* @4602768 load */
    /* @4602776 load */
    /* @4602784 constant */
    /* @4602788 cast */
    /* @4602792 constant */
    /* @4602796 cast */
    /* @4602800 call */
    GM_SITE(vm, 428, 4602800);
    /* @4602808 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4602812: ;
    /* @4602812 load */
    /* @4602820 constant */
    /* @4602824 cmp */
    /* @4602828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4603388;
    /* @4602832 constant */
    /* @4602836 constant */
    /* @4602840 load */
    /* @4602848 constant */
    /* @4602852 add */
    /* @4602856 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4602864 constant */
    /* @4602868 constant */
    /* @4602872 load */
    /* @4602880 constant */
    /* @4602884 add */
    /* @4602888 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(100));
    GM_WRITE(vm, -1, "y", v23);
    /* @4602896 constant */
    /* @4602900 cast */
    /* @4602904 constant */
    /* @4602908 cast */
    /* @4602912 constant */
    /* @4602916 cast */
    /* @4602920 constant */
    /* @4602932 cast */
    /* @4602936 constant */
    /* @4602948 cast */
    /* @4602952 load */
    /* @4602960 load */
    /* @4602968 constant */
    /* @4602972 cast */
    /* @4602976 constant */
    /* @4602980 cast */
    /* @4602984 call */
    GM_SITE(vm, 428, 4602984);
    /* @4602992 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4602996 constant */
    /* @4603000 cast */
    /* @4603004 call */
    GM_SITE(vm, 428, 4603004);
    /* @4603012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4603016 constant */
    /* @4603024 cast */
    /* @4603028 call */
    GM_SITE(vm, 428, 4603028);
    /* @4603036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4603040 string */
    /* @4603048 cast */
    /* @4603052 load */
    /* @4603060 constant */
    /* @4603064 add */
    /* @4603068 load */
    /* @4603076 constant */
    /* @4603080 add */
    /* @4603084 call */
    GM_SITE(vm, 428, 4603084);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4603092 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(807)));
    /* @4603096 string */
    /* @4603104 cast */
    /* @4603108 load */
    /* @4603116 constant */
    /* @4603120 add */
    /* @4603124 load */
    /* @4603132 constant */
    /* @4603136 add */
    /* @4603140 call */
    GM_SITE(vm, 428, 4603140);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4603148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(808)));
    /* @4603152 constant */
    /* @4603156 cast */
    /* @4603160 constant */
    /* @4603164 cast */
    /* @4603168 constant */
    /* @4603172 cast */
    /* @4603176 constant */
    /* @4603188 cast */
    /* @4603192 constant */
    /* @4603204 cast */
    /* @4603208 load */
    /* @4603216 constant */
    /* @4603220 add */
    /* @4603224 load */
    /* @4603232 constant */
    /* @4603236 add */
    /* @4603240 constant */
    /* @4603244 cast */
    /* @4603248 constant */
    /* @4603252 cast */
    /* @4603256 call */
    GM_SITE(vm, 428, 4603256);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4603264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v28, v29, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4603268 load */
    /* @4603276 constant */
    /* @4603280 cmp */
    /* @4603284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4603388;
    /* @4603288 constant */
    /* @4603292 cast */
    /* @4603296 constant */
    /* @4603300 cast */
    /* @4603304 constant */
    /* @4603308 cast */
    /* @4603312 constant */
    /* @4603324 cast */
    /* @4603328 constant */
    /* @4603340 cast */
    /* @4603344 load */
    /* @4603352 load */
    /* @4603360 constant */
    /* @4603364 cast */
    /* @4603368 constant */
    /* @4603372 cast */
    /* @4603376 call */
    GM_SITE(vm, 428, 4603376);
    /* @4603384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4603388: ;
    /* @4603388 load */
    /* @4603396 constant */
    /* @4603400 cmp */
    /* @4603404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4603956;
    /* @4603408 constant */
    /* @4603412 constant */
    /* @4603416 load */
    /* @4603424 constant */
    /* @4603428 add */
    /* @4603432 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4603440 constant */
    /* @4603444 constant */
    /* @4603448 load */
    /* @4603456 constant */
    /* @4603460 add */
    /* @4603464 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    GM_WRITE(vm, -1, "y", v31);
    /* @4603472 constant */
    /* @4603476 cast */
    /* @4603480 constant */
    /* @4603484 cast */
    /* @4603488 constant */
    /* @4603492 cast */
    /* @4603496 constant */
    /* @4603508 cast */
    /* @4603512 constant */
    /* @4603524 cast */
    /* @4603528 load */
    /* @4603536 load */
    /* @4603544 constant */
    /* @4603548 cast */
    /* @4603552 constant */
    /* @4603556 cast */
    /* @4603560 call */
    GM_SITE(vm, 428, 4603560);
    /* @4603568 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4603572 constant */
    /* @4603576 cast */
    /* @4603580 call */
    GM_SITE(vm, 428, 4603580);
    /* @4603588 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4603592 constant */
    /* @4603600 cast */
    /* @4603604 call */
    GM_SITE(vm, 428, 4603604);
    /* @4603612 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4603616 string */
    /* @4603624 cast */
    /* @4603628 load */
    /* @4603636 load */
    /* @4603644 constant */
    /* @4603648 add */
    /* @4603652 call */
    GM_SITE(vm, 428, 4603652);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4603660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(807)));
    /* @4603664 string */
    /* @4603672 cast */
    /* @4603676 load */
    /* @4603684 constant */
    /* @4603688 add */
    /* @4603692 load */
    /* @4603700 constant */
    /* @4603704 add */
    /* @4603708 call */
    GM_SITE(vm, 428, 4603708);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4603716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(808)));
    /* @4603720 constant */
    /* @4603724 cast */
    /* @4603728 constant */
    /* @4603732 cast */
    /* @4603736 constant */
    /* @4603740 cast */
    /* @4603744 constant */
    /* @4603756 cast */
    /* @4603760 constant */
    /* @4603772 cast */
    /* @4603776 load */
    /* @4603784 constant */
    /* @4603788 add */
    /* @4603792 load */
    /* @4603800 constant */
    /* @4603804 add */
    /* @4603808 constant */
    /* @4603812 cast */
    /* @4603816 constant */
    /* @4603820 cast */
    /* @4603824 call */
    GM_SITE(vm, 428, 4603824);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4603832 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4603836 load */
    /* @4603844 constant */
    /* @4603848 cmp */
    /* @4603852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4603956;
    /* @4603856 constant */
    /* @4603860 cast */
    /* @4603864 constant */
    /* @4603868 cast */
    /* @4603872 constant */
    /* @4603876 cast */
    /* @4603880 constant */
    /* @4603892 cast */
    /* @4603896 constant */
    /* @4603908 cast */
    /* @4603912 load */
    /* @4603920 load */
    /* @4603928 constant */
    /* @4603932 cast */
    /* @4603936 constant */
    /* @4603940 cast */
    /* @4603944 call */
    GM_SITE(vm, 428, 4603944);
    /* @4603952 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4603956: ;
    /* @4603956 load */
    /* @4603964 constant */
    /* @4603968 cmp */
    /* @4603972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4604524;
    /* @4603976 constant */
    /* @4603980 constant */
    /* @4603984 load */
    /* @4603992 constant */
    /* @4603996 add */
    /* @4604000 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4604008 constant */
    /* @4604012 constant */
    /* @4604016 load */
    /* @4604024 constant */
    /* @4604028 add */
    /* @4604032 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    GM_WRITE(vm, -1, "y", v38);
    /* @4604040 constant */
    /* @4604044 cast */
    /* @4604048 constant */
    /* @4604052 cast */
    /* @4604056 constant */
    /* @4604060 cast */
    /* @4604064 constant */
    /* @4604076 cast */
    /* @4604080 constant */
    /* @4604092 cast */
    /* @4604096 load */
    /* @4604104 load */
    /* @4604112 constant */
    /* @4604116 cast */
    /* @4604120 constant */
    /* @4604124 cast */
    /* @4604128 call */
    GM_SITE(vm, 428, 4604128);
    /* @4604136 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4604140 constant */
    /* @4604144 cast */
    /* @4604148 call */
    GM_SITE(vm, 428, 4604148);
    /* @4604156 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4604160 constant */
    /* @4604168 cast */
    /* @4604172 call */
    GM_SITE(vm, 428, 4604172);
    /* @4604180 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4604184 string */
    /* @4604192 cast */
    /* @4604196 load */
    /* @4604204 load */
    /* @4604212 constant */
    /* @4604216 add */
    /* @4604220 call */
    GM_SITE(vm, 428, 4604220);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4604228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(807)));
    /* @4604232 string */
    /* @4604240 cast */
    /* @4604244 load */
    /* @4604252 constant */
    /* @4604256 add */
    /* @4604260 load */
    /* @4604268 constant */
    /* @4604272 add */
    /* @4604276 call */
    GM_SITE(vm, 428, 4604276);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4604284 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(808)));
    /* @4604288 constant */
    /* @4604292 cast */
    /* @4604296 constant */
    /* @4604300 cast */
    /* @4604304 constant */
    /* @4604308 cast */
    /* @4604312 constant */
    /* @4604324 cast */
    /* @4604328 constant */
    /* @4604340 cast */
    /* @4604344 load */
    /* @4604352 constant */
    /* @4604356 add */
    /* @4604360 load */
    /* @4604368 constant */
    /* @4604372 add */
    /* @4604376 constant */
    /* @4604380 cast */
    /* @4604384 constant */
    /* @4604388 cast */
    /* @4604392 call */
    GM_SITE(vm, 428, 4604392);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4604400 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(48), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4604404 load */
    /* @4604412 constant */
    /* @4604416 cmp */
    /* @4604420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_4604524;
    /* @4604424 constant */
    /* @4604428 cast */
    /* @4604432 constant */
    /* @4604436 cast */
    /* @4604440 constant */
    /* @4604444 cast */
    /* @4604448 constant */
    /* @4604460 cast */
    /* @4604464 constant */
    /* @4604476 cast */
    /* @4604480 load */
    /* @4604488 load */
    /* @4604496 constant */
    /* @4604500 cast */
    /* @4604504 constant */
    /* @4604508 cast */
    /* @4604512 call */
    GM_SITE(vm, 428, 4604512);
    /* @4604520 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4604524: ;
    return;
}
