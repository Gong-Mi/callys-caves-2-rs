/* generated from CODE 11 (gml_Object_obj_player_Alarm_0), source start 3764972, end 3770532. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0011(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3765296_0;
    Val v4;
    Val v5;
    Val v6;
    Val p3765540_0;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val p3765964_0;
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
    Val p3766408_0;
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
    Val p3766868_0;
    Val v36;
    Val v37;
    Val v38;
    Val p3767224_0;
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
    /* @3764972 load */
    /* @3764980 constant */
    /* @3764984 cmp */
    /* @3764988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_3765252;
    /* @3764992 load */
    /* @3765000 constant */
    /* @3765004 cmp */
    /* @3765008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3765068;
    /* @3765012 constant */
    /* @3765016 cast */
    /* @3765020 load */
    /* @3765028 constant */
    /* @3765032 add */
    /* @3765036 load */
    /* @3765044 constant */
    /* @3765048 add */
    /* @3765052 call */
    GM_SITE(vm, 11, 3765052);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3765060 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, v2, VAL(39)));
    /* @3765064 b */
    goto L_3765140;
    L_3765068: ;
    /* @3765068 load */
    /* @3765076 constant */
    /* @3765080 cmp */
    /* @3765084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3765140;
    /* @3765088 constant */
    /* @3765092 cast */
    /* @3765096 load */
    /* @3765104 constant */
    /* @3765108 add */
    /* @3765112 load */
    /* @3765120 constant */
    /* @3765124 sub */
    /* @3765128 call */
    GM_SITE(vm, 11, 3765128);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @3765136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), v3, VAL(39)));
    L_3765140: ;
    /* @3765140 load */
    /* @3765148 constant */
    /* @3765152 cmp */
    /* @3765156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3765164;
    /* @3765160 b */
    goto L_3765220;
    L_3765164: ;
    /* @3765164 load */
    /* @3765172 constant */
    /* @3765176 cmp */
    /* @3765180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3765220;
    /* @3765184 constant */
    /* @3765188 cast */
    /* @3765192 constant */
    /* @3765196 cast */
    /* @3765200 constant */
    /* @3765204 cast */
    /* @3765208 call */
    GM_SITE(vm, 11, 3765208);
    /* @3765216 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(10), VAL(0), VAL(0)));
    L_3765220: ;
    /* @3765220 constant */
    /* @3765224 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3765232 constant */
    /* @3765236 constant */
    /* @3765240 constant */
    /* @3765244 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3765252: ;
    /* @3765252 load */
    /* @3765260 constant */
    /* @3765264 cmp */
    /* @3765268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_3765292;
    /* @3765272 load */
    /* @3765280 constant */
    /* @3765284 cmp */
    /* @3765288 b */
    p3765296_0 = NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0));
    goto L_3765296;
    L_3765292: ;
    /* @3765292 constant */
    p3765296_0 = VAL(0);
    L_3765296: ;
    /* @3765296 bf */
    if (!TRUTH(p3765296_0)) goto L_3765496;
    /* @3765300 constant */
    /* @3765304 cast */
    /* @3765308 load */
    /* @3765316 constant */
    /* @3765320 add */
    /* @3765324 load */
    /* @3765332 constant */
    /* @3765336 add */
    /* @3765340 call */
    GM_SITE(vm, 11, 3765340);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3765348 store */
    v6 = GM_CALL(vm, "instance_create", 3, v4, v5, VAL(41));
    GM_WRITE(vm, -1, "i1", v6);
    /* @3765356 constant */
    /* @3765360 load */
    /* @3765368 cast */
    /* @3765372 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(2));
    /* @3765380 constant */
    /* @3765384 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3765392 constant */
    /* @3765396 constant */
    /* @3765400 constant */
    /* @3765404 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    /* @3765412 load */
    /* @3765420 constant */
    /* @3765424 cmp */
    /* @3765428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3765436;
    /* @3765432 b */
    goto L_3765492;
    L_3765436: ;
    /* @3765436 load */
    /* @3765444 constant */
    /* @3765448 cmp */
    /* @3765452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3765492;
    /* @3765456 constant */
    /* @3765460 cast */
    /* @3765464 constant */
    /* @3765468 cast */
    /* @3765472 constant */
    /* @3765476 cast */
    /* @3765480 call */
    GM_SITE(vm, 11, 3765480);
    /* @3765488 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(15), VAL(0), VAL(0)));
    L_3765492: ;
    /* @3765492 b */
    goto L_3765736;
    L_3765496: ;
    /* @3765496 load */
    /* @3765504 constant */
    /* @3765508 cmp */
    /* @3765512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_3765536;
    /* @3765516 load */
    /* @3765524 constant */
    /* @3765528 cmp */
    /* @3765532 b */
    p3765540_0 = NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1));
    goto L_3765540;
    L_3765536: ;
    /* @3765536 constant */
    p3765540_0 = VAL(0);
    L_3765540: ;
    /* @3765540 bf */
    if (!TRUTH(p3765540_0)) goto L_3765736;
    /* @3765544 constant */
    /* @3765548 cast */
    /* @3765552 load */
    /* @3765560 constant */
    /* @3765564 add */
    /* @3765568 load */
    /* @3765576 constant */
    /* @3765580 sub */
    /* @3765584 call */
    GM_SITE(vm, 11, 3765584);
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3765592 store */
    v8 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v7, VAL(41));
    GM_WRITE(vm, -1, "i1", v8);
    /* @3765600 constant */
    /* @3765604 load */
    /* @3765612 cast */
    /* @3765616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(2));
    /* @3765624 constant */
    /* @3765628 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3765636 constant */
    /* @3765640 constant */
    /* @3765644 constant */
    /* @3765648 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    /* @3765656 load */
    /* @3765664 constant */
    /* @3765668 cmp */
    /* @3765672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3765680;
    /* @3765676 b */
    goto L_3765736;
    L_3765680: ;
    /* @3765680 load */
    /* @3765688 constant */
    /* @3765692 cmp */
    /* @3765696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3765736;
    /* @3765700 constant */
    /* @3765704 cast */
    /* @3765708 constant */
    /* @3765712 cast */
    /* @3765716 constant */
    /* @3765720 cast */
    /* @3765724 call */
    GM_SITE(vm, 11, 3765724);
    /* @3765732 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(15), VAL(0), VAL(0)));
    L_3765736: ;
    /* @3765736 load */
    /* @3765744 constant */
    /* @3765748 cmp */
    /* @3765752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_3765920;
    /* @3765756 constant */
    /* @3765760 cast */
    /* @3765764 load */
    /* @3765772 constant */
    /* @3765776 add */
    /* @3765780 load */
    /* @3765788 constant */
    /* @3765792 add */
    /* @3765796 call */
    GM_SITE(vm, 11, 3765796);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    v10 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3765804 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v9, v10, VAL(40)));
    /* @3765808 load */
    /* @3765816 constant */
    /* @3765820 cmp */
    /* @3765824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3765832;
    /* @3765828 b */
    goto L_3765888;
    L_3765832: ;
    /* @3765832 load */
    /* @3765840 constant */
    /* @3765844 cmp */
    /* @3765848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3765888;
    /* @3765852 constant */
    /* @3765856 cast */
    /* @3765860 constant */
    /* @3765864 cast */
    /* @3765868 constant */
    /* @3765872 cast */
    /* @3765876 call */
    GM_SITE(vm, 11, 3765876);
    /* @3765884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(18), VAL(0), VAL(0)));
    L_3765888: ;
    /* @3765888 constant */
    /* @3765892 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3765900 constant */
    /* @3765904 constant */
    /* @3765908 constant */
    /* @3765912 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3765920: ;
    /* @3765920 load */
    /* @3765928 constant */
    /* @3765932 cmp */
    /* @3765936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_3765960;
    /* @3765940 load */
    /* @3765948 constant */
    /* @3765952 cmp */
    /* @3765956 b */
    p3765964_0 = NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0));
    goto L_3765964;
    L_3765960: ;
    /* @3765960 constant */
    p3765964_0 = VAL(0);
    L_3765964: ;
    /* @3765964 bf */
    if (!TRUTH(p3765964_0)) goto L_3766364;
    /* @3765968 constant */
    /* @3765972 cast */
    /* @3765976 load */
    /* @3765984 constant */
    /* @3765988 add */
    /* @3765992 load */
    /* @3766000 constant */
    /* @3766004 add */
    /* @3766008 call */
    GM_SITE(vm, 11, 3766008);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v12 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3766016 store */
    v13 = GM_CALL(vm, "instance_create", 3, v11, v12, VAL(39));
    GM_WRITE(vm, -1, "bullet1", v13);
    /* @3766024 constant */
    /* @3766028 cast */
    /* @3766032 load */
    /* @3766040 constant */
    /* @3766044 add */
    /* @3766048 load */
    /* @3766056 constant */
    /* @3766060 add */
    /* @3766064 call */
    GM_SITE(vm, 11, 3766064);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766072 store */
    v16 = GM_CALL(vm, "instance_create", 3, v14, v15, VAL(39));
    GM_WRITE(vm, -1, "bullet2", v16);
    /* @3766080 constant */
    /* @3766084 cast */
    /* @3766088 load */
    /* @3766096 constant */
    /* @3766100 add */
    /* @3766104 load */
    /* @3766112 constant */
    /* @3766116 add */
    /* @3766120 call */
    GM_SITE(vm, 11, 3766120);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v18 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766128 store */
    v19 = GM_CALL(vm, "instance_create", 3, v17, v18, VAL(39));
    GM_WRITE(vm, -1, "bullet3", v19);
    /* @3766136 constant */
    /* @3766140 cast */
    /* @3766144 load */
    /* @3766152 constant */
    /* @3766156 add */
    /* @3766160 load */
    /* @3766168 constant */
    /* @3766172 add */
    /* @3766176 call */
    GM_SITE(vm, 11, 3766176);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766184 store */
    v22 = GM_CALL(vm, "instance_create", 3, v20, v21, VAL(39));
    GM_WRITE(vm, -1, "bullet4", v22);
    /* @3766192 constant */
    /* @3766196 cast */
    /* @3766200 load */
    /* @3766208 constant */
    /* @3766212 add */
    /* @3766216 load */
    /* @3766224 constant */
    /* @3766228 add */
    /* @3766232 call */
    GM_SITE(vm, 11, 3766232);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v24 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766240 store */
    v25 = GM_CALL(vm, "instance_create", 3, v23, v24, VAL(39));
    GM_WRITE(vm, -1, "bullet5", v25);
    /* @3766248 load */
    /* @3766256 constant */
    /* @3766260 cmp */
    /* @3766264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3766272;
    /* @3766268 b */
    goto L_3766328;
    L_3766272: ;
    /* @3766272 load */
    /* @3766280 constant */
    /* @3766284 cmp */
    /* @3766288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3766328;
    /* @3766292 constant */
    /* @3766296 cast */
    /* @3766300 constant */
    /* @3766304 cast */
    /* @3766308 constant */
    /* @3766312 cast */
    /* @3766316 call */
    GM_SITE(vm, 11, 3766316);
    /* @3766324 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(11), VAL(0), VAL(0)));
    L_3766328: ;
    /* @3766328 constant */
    /* @3766332 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3766340 constant */
    /* @3766344 constant */
    /* @3766348 constant */
    /* @3766352 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    /* @3766360 b */
    goto L_3766804;
    L_3766364: ;
    /* @3766364 load */
    /* @3766372 constant */
    /* @3766376 cmp */
    /* @3766380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_3766404;
    /* @3766384 load */
    /* @3766392 constant */
    /* @3766396 cmp */
    /* @3766400 b */
    p3766408_0 = NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1));
    goto L_3766408;
    L_3766404: ;
    /* @3766404 constant */
    p3766408_0 = VAL(0);
    L_3766408: ;
    /* @3766408 bf */
    if (!TRUTH(p3766408_0)) goto L_3766804;
    /* @3766412 constant */
    /* @3766416 cast */
    /* @3766420 load */
    /* @3766428 constant */
    /* @3766432 add */
    /* @3766436 load */
    /* @3766444 constant */
    /* @3766448 sub */
    /* @3766452 call */
    GM_SITE(vm, 11, 3766452);
    v26 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3766460 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v26, VAL(39));
    GM_WRITE(vm, -1, "bullet1", v27);
    /* @3766468 constant */
    /* @3766472 cast */
    /* @3766476 load */
    /* @3766484 constant */
    /* @3766488 add */
    /* @3766492 load */
    /* @3766500 constant */
    /* @3766504 sub */
    /* @3766508 call */
    GM_SITE(vm, 11, 3766508);
    v28 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766516 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v28, VAL(39));
    GM_WRITE(vm, -1, "bullet2", v29);
    /* @3766524 constant */
    /* @3766528 cast */
    /* @3766532 load */
    /* @3766540 constant */
    /* @3766544 add */
    /* @3766548 load */
    /* @3766556 constant */
    /* @3766560 sub */
    /* @3766564 call */
    GM_SITE(vm, 11, 3766564);
    v30 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766572 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v30, VAL(39));
    GM_WRITE(vm, -1, "bullet3", v31);
    /* @3766580 constant */
    /* @3766584 cast */
    /* @3766588 load */
    /* @3766596 constant */
    /* @3766600 add */
    /* @3766604 load */
    /* @3766612 constant */
    /* @3766616 sub */
    /* @3766620 call */
    GM_SITE(vm, 11, 3766620);
    v32 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766628 store */
    v33 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v32, VAL(39));
    GM_WRITE(vm, -1, "bullet4", v33);
    /* @3766636 constant */
    /* @3766640 cast */
    /* @3766644 load */
    /* @3766652 constant */
    /* @3766656 add */
    /* @3766660 load */
    /* @3766668 constant */
    /* @3766672 sub */
    /* @3766676 call */
    GM_SITE(vm, 11, 3766676);
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3766684 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v34, VAL(39));
    GM_WRITE(vm, -1, "bullet5", v35);
    /* @3766692 load */
    /* @3766700 constant */
    /* @3766704 cmp */
    /* @3766708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3766716;
    /* @3766712 b */
    goto L_3766772;
    L_3766716: ;
    /* @3766716 load */
    /* @3766724 constant */
    /* @3766728 cmp */
    /* @3766732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3766772;
    /* @3766736 constant */
    /* @3766740 cast */
    /* @3766744 constant */
    /* @3766748 cast */
    /* @3766752 constant */
    /* @3766756 cast */
    /* @3766760 call */
    GM_SITE(vm, 11, 3766760);
    /* @3766768 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(11), VAL(0), VAL(0)));
    L_3766772: ;
    /* @3766772 constant */
    /* @3766776 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3766784 constant */
    /* @3766788 constant */
    /* @3766792 constant */
    /* @3766796 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3766804: ;
    /* @3766804 load */
    /* @3766812 constant */
    /* @3766816 cmp */
    /* @3766820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_3767160;
    /* @3766824 load */
    /* @3766832 constant */
    /* @3766836 cmp */
    /* @3766840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_3766864;
    /* @3766844 load */
    /* @3766852 constant */
    /* @3766856 cmp */
    /* @3766860 b */
    p3766868_0 = NUMBOOL(GM_READ(vm, -1, "assaultfire") == VAL(3));
    goto L_3766868;
    L_3766864: ;
    /* @3766864 constant */
    p3766868_0 = VAL(0);
    L_3766868: ;
    /* @3766868 bf */
    if (!TRUTH(p3766868_0)) goto L_3767160;
    /* @3766872 load */
    /* @3766880 constant */
    /* @3766884 cmp */
    /* @3766888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") <= VAL(9)))) goto L_3766948;
    /* @3766892 constant */
    /* @3766896 cast */
    /* @3766900 load */
    /* @3766908 constant */
    /* @3766912 add */
    /* @3766916 load */
    /* @3766924 constant */
    /* @3766928 sub */
    /* @3766932 call */
    GM_SITE(vm, 11, 3766932);
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @3766940 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v36, VAL(39)));
    /* @3766944 b */
    goto L_3767020;
    L_3766948: ;
    /* @3766948 load */
    /* @3766956 constant */
    /* @3766960 cmp */
    /* @3766964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(10)))) goto L_3767020;
    /* @3766968 constant */
    /* @3766972 cast */
    /* @3766976 load */
    /* @3766984 constant */
    /* @3766988 add */
    /* @3766992 load */
    /* @3767000 constant */
    /* @3767004 sub */
    /* @3767008 call */
    GM_SITE(vm, 11, 3767008);
    v37 = GM_ADD(GM_READ(vm, -1, "y"), VAL(10));
    /* @3767016 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), v37, VAL(39)));
    L_3767020: ;
    /* @3767020 load */
    /* @3767028 constant */
    /* @3767032 cmp */
    /* @3767036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3767044;
    /* @3767040 b */
    goto L_3767128;
    L_3767044: ;
    /* @3767044 load */
    /* @3767052 constant */
    /* @3767056 cmp */
    /* @3767060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3767128;
    /* @3767064 constant */
    /* @3767068 cast */
    /* @3767072 call */
    GM_SITE(vm, 11, 3767072);
    /* @3767080 cast */
    /* @3767084 bf */
    v38 = BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(9)));
    if (!TRUTH(v38)) goto L_3767092;
    /* @3767088 b */
    goto L_3767128;
    L_3767092: ;
    /* @3767092 constant */
    /* @3767096 cast */
    /* @3767100 constant */
    /* @3767104 cast */
    /* @3767108 constant */
    /* @3767112 cast */
    /* @3767116 call */
    GM_SITE(vm, 11, 3767116);
    /* @3767124 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(9), VAL(0), VAL(0)));
    L_3767128: ;
    /* @3767128 constant */
    /* @3767132 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3767140 constant */
    /* @3767144 constant */
    /* @3767148 constant */
    /* @3767152 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3767160: ;
    /* @3767160 load */
    /* @3767168 constant */
    /* @3767172 cmp */
    /* @3767176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_3767516;
    /* @3767180 load */
    /* @3767188 constant */
    /* @3767192 cmp */
    /* @3767196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_3767220;
    /* @3767200 load */
    /* @3767208 constant */
    /* @3767212 cmp */
    /* @3767216 b */
    p3767224_0 = NUMBOOL(GM_READ(vm, -1, "assaultfire") == VAL(3));
    goto L_3767224;
    L_3767220: ;
    /* @3767220 constant */
    p3767224_0 = VAL(0);
    L_3767224: ;
    /* @3767224 bf */
    if (!TRUTH(p3767224_0)) goto L_3767516;
    /* @3767228 load */
    /* @3767236 constant */
    /* @3767240 cmp */
    /* @3767244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") <= VAL(9)))) goto L_3767304;
    /* @3767248 constant */
    /* @3767252 cast */
    /* @3767256 load */
    /* @3767264 constant */
    /* @3767268 add */
    /* @3767272 load */
    /* @3767280 constant */
    /* @3767284 add */
    /* @3767288 call */
    GM_SITE(vm, 11, 3767288);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v40 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @3767296 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v39, v40, VAL(39)));
    /* @3767300 b */
    goto L_3767376;
    L_3767304: ;
    /* @3767304 load */
    /* @3767312 constant */
    /* @3767316 cmp */
    /* @3767320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(10)))) goto L_3767376;
    /* @3767324 constant */
    /* @3767328 cast */
    /* @3767332 load */
    /* @3767340 constant */
    /* @3767344 add */
    /* @3767348 load */
    /* @3767356 constant */
    /* @3767360 add */
    /* @3767364 call */
    GM_SITE(vm, 11, 3767364);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    v42 = GM_ADD(GM_READ(vm, -1, "y"), VAL(10));
    /* @3767372 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v41, v42, VAL(39)));
    L_3767376: ;
    /* @3767376 load */
    /* @3767384 constant */
    /* @3767388 cmp */
    /* @3767392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3767400;
    /* @3767396 b */
    goto L_3767484;
    L_3767400: ;
    /* @3767400 load */
    /* @3767408 constant */
    /* @3767412 cmp */
    /* @3767416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3767484;
    /* @3767420 constant */
    /* @3767424 cast */
    /* @3767428 call */
    GM_SITE(vm, 11, 3767428);
    /* @3767436 cast */
    /* @3767440 bf */
    v43 = BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(9)));
    if (!TRUTH(v43)) goto L_3767448;
    /* @3767444 b */
    goto L_3767484;
    L_3767448: ;
    /* @3767448 constant */
    /* @3767452 cast */
    /* @3767456 constant */
    /* @3767460 cast */
    /* @3767464 constant */
    /* @3767468 cast */
    /* @3767472 call */
    GM_SITE(vm, 11, 3767472);
    /* @3767480 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(9), VAL(0), VAL(0)));
    L_3767484: ;
    /* @3767484 constant */
    /* @3767488 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3767496 constant */
    /* @3767500 constant */
    /* @3767504 constant */
    /* @3767508 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3767516: ;
    /* @3767516 load */
    /* @3767524 constant */
    /* @3767528 cmp */
    /* @3767532 cast */
    /* @3767536 load */
    /* @3767544 constant */
    /* @3767548 cmp */
    /* @3767552 cast */
    /* @3767556 and */
    /* @3767560 cast */
    /* @3767564 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0))))))) goto L_3767732;
    /* @3767568 constant */
    /* @3767572 cast */
    /* @3767576 load */
    /* @3767584 constant */
    /* @3767588 add */
    /* @3767592 load */
    /* @3767600 constant */
    /* @3767604 add */
    /* @3767608 call */
    GM_SITE(vm, 11, 3767608);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    v45 = GM_ADD(GM_READ(vm, -1, "y"), VAL(3));
    /* @3767616 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v44, v45, VAL(44)));
    /* @3767620 load */
    /* @3767628 constant */
    /* @3767632 cmp */
    /* @3767636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3767644;
    /* @3767640 b */
    goto L_3767700;
    L_3767644: ;
    /* @3767644 load */
    /* @3767652 constant */
    /* @3767656 cmp */
    /* @3767660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3767700;
    /* @3767664 constant */
    /* @3767668 cast */
    /* @3767672 constant */
    /* @3767676 cast */
    /* @3767680 constant */
    /* @3767684 cast */
    /* @3767688 call */
    GM_SITE(vm, 11, 3767688);
    /* @3767696 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3767700: ;
    /* @3767700 constant */
    /* @3767704 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3767712 constant */
    /* @3767716 constant */
    /* @3767720 constant */
    /* @3767724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3767732: ;
    /* @3767732 load */
    /* @3767740 constant */
    /* @3767744 cmp */
    /* @3767748 cast */
    /* @3767752 load */
    /* @3767760 constant */
    /* @3767764 cmp */
    /* @3767768 cast */
    /* @3767772 and */
    /* @3767776 cast */
    /* @3767780 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1))))))) goto L_3767948;
    /* @3767784 constant */
    /* @3767788 cast */
    /* @3767792 load */
    /* @3767800 constant */
    /* @3767804 add */
    /* @3767808 load */
    /* @3767816 constant */
    /* @3767820 sub */
    /* @3767824 call */
    GM_SITE(vm, 11, 3767824);
    v46 = GM_ADD(GM_READ(vm, -1, "y"), VAL(3));
    /* @3767832 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(30)), v46, VAL(44)));
    /* @3767836 load */
    /* @3767844 constant */
    /* @3767848 cmp */
    /* @3767852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3767860;
    /* @3767856 b */
    goto L_3767916;
    L_3767860: ;
    /* @3767860 load */
    /* @3767868 constant */
    /* @3767872 cmp */
    /* @3767876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3767916;
    /* @3767880 constant */
    /* @3767884 cast */
    /* @3767888 constant */
    /* @3767892 cast */
    /* @3767896 constant */
    /* @3767900 cast */
    /* @3767904 call */
    GM_SITE(vm, 11, 3767904);
    /* @3767912 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3767916: ;
    /* @3767916 constant */
    /* @3767920 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3767928 constant */
    /* @3767932 constant */
    /* @3767936 constant */
    /* @3767940 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3767948: ;
    /* @3767948 load */
    /* @3767956 constant */
    /* @3767960 cmp */
    /* @3767964 cast */
    /* @3767968 load */
    /* @3767976 constant */
    /* @3767980 cmp */
    /* @3767984 cast */
    /* @3767988 and */
    /* @3767992 cast */
    /* @3767996 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bombgun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0))))))) goto L_3768164;
    /* @3768000 constant */
    /* @3768004 cast */
    /* @3768008 load */
    /* @3768016 constant */
    /* @3768020 add */
    /* @3768024 load */
    /* @3768032 constant */
    /* @3768036 add */
    /* @3768040 call */
    GM_SITE(vm, 11, 3768040);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    v48 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @3768048 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v47, v48, VAL(37)));
    /* @3768052 load */
    /* @3768060 constant */
    /* @3768064 cmp */
    /* @3768068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3768076;
    /* @3768072 b */
    goto L_3768132;
    L_3768076: ;
    /* @3768076 load */
    /* @3768084 constant */
    /* @3768088 cmp */
    /* @3768092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3768132;
    /* @3768096 constant */
    /* @3768100 cast */
    /* @3768104 constant */
    /* @3768108 cast */
    /* @3768112 constant */
    /* @3768116 cast */
    /* @3768120 call */
    GM_SITE(vm, 11, 3768120);
    /* @3768128 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3768132: ;
    /* @3768132 constant */
    /* @3768136 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3768144 constant */
    /* @3768148 constant */
    /* @3768152 constant */
    /* @3768156 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3768164: ;
    /* @3768164 load */
    /* @3768172 constant */
    /* @3768176 cmp */
    /* @3768180 cast */
    /* @3768184 load */
    /* @3768192 constant */
    /* @3768196 cmp */
    /* @3768200 cast */
    /* @3768204 and */
    /* @3768208 cast */
    /* @3768212 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bombgun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1))))))) goto L_3768380;
    /* @3768216 constant */
    /* @3768220 cast */
    /* @3768224 load */
    /* @3768232 constant */
    /* @3768236 add */
    /* @3768240 load */
    /* @3768248 constant */
    /* @3768252 sub */
    /* @3768256 call */
    GM_SITE(vm, 11, 3768256);
    v49 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @3768264 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), v49, VAL(37)));
    /* @3768268 load */
    /* @3768276 constant */
    /* @3768280 cmp */
    /* @3768284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3768292;
    /* @3768288 b */
    goto L_3768348;
    L_3768292: ;
    /* @3768292 load */
    /* @3768300 constant */
    /* @3768304 cmp */
    /* @3768308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3768348;
    /* @3768312 constant */
    /* @3768316 cast */
    /* @3768320 constant */
    /* @3768324 cast */
    /* @3768328 constant */
    /* @3768332 cast */
    /* @3768336 call */
    GM_SITE(vm, 11, 3768336);
    /* @3768344 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3768348: ;
    /* @3768348 constant */
    /* @3768352 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3768360 constant */
    /* @3768364 constant */
    /* @3768368 constant */
    /* @3768372 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3768380: ;
    /* @3768380 load */
    /* @3768388 constant */
    /* @3768392 cmp */
    /* @3768396 cast */
    /* @3768400 load */
    /* @3768408 constant */
    /* @3768412 cmp */
    /* @3768416 cast */
    /* @3768420 and */
    /* @3768424 cast */
    /* @3768428 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0))))))) goto L_3768600;
    /* @3768432 constant */
    /* @3768436 store */
    GM_WRITE(vm, -1, "throwingboomerang", VAL(1));
    /* @3768444 constant */
    /* @3768448 cast */
    /* @3768452 load */
    /* @3768460 constant */
    /* @3768464 add */
    /* @3768468 load */
    /* @3768476 call */
    GM_SITE(vm, 11, 3768476);
    v50 = GM_ADD(GM_READ(vm, -1, "y"), VAL(3));
    /* @3768484 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v50, VAL(38)));
    /* @3768488 load */
    /* @3768496 constant */
    /* @3768500 cmp */
    /* @3768504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3768512;
    /* @3768508 b */
    goto L_3768568;
    L_3768512: ;
    /* @3768512 load */
    /* @3768520 constant */
    /* @3768524 cmp */
    /* @3768528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3768568;
    /* @3768532 constant */
    /* @3768536 cast */
    /* @3768540 constant */
    /* @3768544 cast */
    /* @3768548 constant */
    /* @3768552 cast */
    /* @3768556 call */
    GM_SITE(vm, 11, 3768556);
    /* @3768564 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(16), VAL(0), VAL(0)));
    L_3768568: ;
    /* @3768568 constant */
    /* @3768572 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3768580 constant */
    /* @3768584 constant */
    /* @3768588 constant */
    /* @3768592 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3768600: ;
    /* @3768600 load */
    /* @3768608 constant */
    /* @3768612 cmp */
    /* @3768616 cast */
    /* @3768620 load */
    /* @3768628 constant */
    /* @3768632 cmp */
    /* @3768636 cast */
    /* @3768640 and */
    /* @3768644 cast */
    /* @3768648 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1))))))) goto L_3768828;
    /* @3768652 constant */
    /* @3768656 store */
    GM_WRITE(vm, -1, "throwingboomerang", VAL(1));
    /* @3768664 constant */
    /* @3768668 cast */
    /* @3768672 load */
    /* @3768680 constant */
    /* @3768684 add */
    /* @3768688 load */
    /* @3768696 constant */
    /* @3768700 sub */
    /* @3768704 call */
    GM_SITE(vm, 11, 3768704);
    v51 = GM_ADD(GM_READ(vm, -1, "y"), VAL(3));
    /* @3768712 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(3)), v51, VAL(38)));
    /* @3768716 load */
    /* @3768724 constant */
    /* @3768728 cmp */
    /* @3768732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3768740;
    /* @3768736 b */
    goto L_3768796;
    L_3768740: ;
    /* @3768740 load */
    /* @3768748 constant */
    /* @3768752 cmp */
    /* @3768756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3768796;
    /* @3768760 constant */
    /* @3768764 cast */
    /* @3768768 constant */
    /* @3768772 cast */
    /* @3768776 constant */
    /* @3768780 cast */
    /* @3768784 call */
    GM_SITE(vm, 11, 3768784);
    /* @3768792 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(16), VAL(0), VAL(0)));
    L_3768796: ;
    /* @3768796 constant */
    /* @3768800 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3768808 constant */
    /* @3768812 constant */
    /* @3768816 constant */
    /* @3768820 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3768828: ;
    /* @3768828 load */
    /* @3768836 constant */
    /* @3768840 cmp */
    /* @3768844 cast */
    /* @3768848 load */
    /* @3768856 constant */
    /* @3768860 cmp */
    /* @3768864 cast */
    /* @3768868 and */
    /* @3768872 cast */
    /* @3768876 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0))))))) goto L_3769044;
    /* @3768880 constant */
    /* @3768884 cast */
    /* @3768888 load */
    /* @3768896 constant */
    /* @3768900 add */
    /* @3768904 load */
    /* @3768912 constant */
    /* @3768916 add */
    /* @3768920 call */
    GM_SITE(vm, 11, 3768920);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    v53 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3768928 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v52, v53, VAL(36)));
    /* @3768932 load */
    /* @3768940 constant */
    /* @3768944 cmp */
    /* @3768948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3768956;
    /* @3768952 b */
    goto L_3769012;
    L_3768956: ;
    /* @3768956 load */
    /* @3768964 constant */
    /* @3768968 cmp */
    /* @3768972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3769012;
    /* @3768976 constant */
    /* @3768980 cast */
    /* @3768984 constant */
    /* @3768988 cast */
    /* @3768992 constant */
    /* @3768996 cast */
    /* @3769000 call */
    GM_SITE(vm, 11, 3769000);
    /* @3769008 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(17), VAL(0), VAL(0)));
    L_3769012: ;
    /* @3769012 constant */
    /* @3769016 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3769024 constant */
    /* @3769028 constant */
    /* @3769032 constant */
    /* @3769036 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3769044: ;
    /* @3769044 load */
    /* @3769052 constant */
    /* @3769056 cmp */
    /* @3769060 cast */
    /* @3769064 load */
    /* @3769072 constant */
    /* @3769076 cmp */
    /* @3769080 cast */
    /* @3769084 and */
    /* @3769088 cast */
    /* @3769092 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1))))))) goto L_3769260;
    /* @3769096 constant */
    /* @3769100 cast */
    /* @3769104 load */
    /* @3769112 constant */
    /* @3769116 add */
    /* @3769120 load */
    /* @3769128 constant */
    /* @3769132 sub */
    /* @3769136 call */
    GM_SITE(vm, 11, 3769136);
    v54 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3769144 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(3)), v54, VAL(36)));
    /* @3769148 load */
    /* @3769156 constant */
    /* @3769160 cmp */
    /* @3769164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3769172;
    /* @3769168 b */
    goto L_3769228;
    L_3769172: ;
    /* @3769172 load */
    /* @3769180 constant */
    /* @3769184 cmp */
    /* @3769188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3769228;
    /* @3769192 constant */
    /* @3769196 cast */
    /* @3769200 constant */
    /* @3769204 cast */
    /* @3769208 constant */
    /* @3769212 cast */
    /* @3769216 call */
    GM_SITE(vm, 11, 3769216);
    /* @3769224 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(17), VAL(0), VAL(0)));
    L_3769228: ;
    /* @3769228 constant */
    /* @3769232 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3769240 constant */
    /* @3769244 constant */
    /* @3769248 constant */
    /* @3769252 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3769260: ;
    /* @3769260 load */
    /* @3769268 constant */
    /* @3769272 cmp */
    /* @3769276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_3769464;
    /* @3769280 load */
    /* @3769288 constant */
    /* @3769292 cmp */
    /* @3769296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_3769464;
    /* @3769300 constant */
    /* @3769304 cast */
    /* @3769308 load */
    /* @3769316 constant */
    /* @3769320 add */
    /* @3769324 load */
    /* @3769332 constant */
    /* @3769336 sub */
    /* @3769340 call */
    GM_SITE(vm, 11, 3769340);
    v55 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3769348 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), v55, VAL(35)));
    /* @3769352 load */
    /* @3769360 constant */
    /* @3769364 cmp */
    /* @3769368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3769376;
    /* @3769372 b */
    goto L_3769432;
    L_3769376: ;
    /* @3769376 load */
    /* @3769384 constant */
    /* @3769388 cmp */
    /* @3769392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3769432;
    /* @3769396 constant */
    /* @3769400 cast */
    /* @3769404 constant */
    /* @3769408 cast */
    /* @3769412 constant */
    /* @3769416 cast */
    /* @3769420 call */
    GM_SITE(vm, 11, 3769420);
    /* @3769428 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(1), VAL(0), VAL(0)));
    L_3769432: ;
    /* @3769432 constant */
    /* @3769436 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3769444 constant */
    /* @3769448 constant */
    /* @3769452 constant */
    /* @3769456 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3769464: ;
    /* @3769464 load */
    /* @3769472 constant */
    /* @3769476 cmp */
    /* @3769480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_3769668;
    /* @3769484 load */
    /* @3769492 constant */
    /* @3769496 cmp */
    /* @3769500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_3769668;
    /* @3769504 constant */
    /* @3769508 cast */
    /* @3769512 load */
    /* @3769520 constant */
    /* @3769524 add */
    /* @3769528 load */
    /* @3769536 constant */
    /* @3769540 add */
    /* @3769544 call */
    GM_SITE(vm, 11, 3769544);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v57 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3769552 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v56, v57, VAL(35)));
    /* @3769556 load */
    /* @3769564 constant */
    /* @3769568 cmp */
    /* @3769572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3769580;
    /* @3769576 b */
    goto L_3769636;
    L_3769580: ;
    /* @3769580 load */
    /* @3769588 constant */
    /* @3769592 cmp */
    /* @3769596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3769636;
    /* @3769600 constant */
    /* @3769604 cast */
    /* @3769608 constant */
    /* @3769612 cast */
    /* @3769616 constant */
    /* @3769620 cast */
    /* @3769624 call */
    GM_SITE(vm, 11, 3769624);
    /* @3769632 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(1), VAL(0), VAL(0)));
    L_3769636: ;
    /* @3769636 constant */
    /* @3769640 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3769648 constant */
    /* @3769652 constant */
    /* @3769656 constant */
    /* @3769660 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3769668: ;
    /* @3769668 load */
    /* @3769676 constant */
    /* @3769680 cmp */
    /* @3769684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_3769884;
    /* @3769688 load */
    /* @3769696 constant */
    /* @3769700 cmp */
    /* @3769704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_3769884;
    /* @3769708 constant */
    /* @3769712 store */
    GM_WRITE(vm, -1, "throwingboomerang", VAL(1));
    /* @3769720 constant */
    /* @3769724 cast */
    /* @3769728 load */
    /* @3769736 constant */
    /* @3769740 add */
    /* @3769744 load */
    /* @3769752 constant */
    /* @3769756 sub */
    /* @3769760 call */
    GM_SITE(vm, 11, 3769760);
    v58 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3769768 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), v58, VAL(43)));
    /* @3769772 load */
    /* @3769780 constant */
    /* @3769784 cmp */
    /* @3769788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3769796;
    /* @3769792 b */
    goto L_3769852;
    L_3769796: ;
    /* @3769796 load */
    /* @3769804 constant */
    /* @3769808 cmp */
    /* @3769812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3769852;
    /* @3769816 constant */
    /* @3769820 cast */
    /* @3769824 constant */
    /* @3769828 cast */
    /* @3769832 constant */
    /* @3769836 cast */
    /* @3769840 call */
    GM_SITE(vm, 11, 3769840);
    /* @3769848 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(13), VAL(0), VAL(0)));
    L_3769852: ;
    /* @3769852 constant */
    /* @3769856 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3769864 constant */
    /* @3769868 constant */
    /* @3769872 constant */
    /* @3769876 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3769884: ;
    /* @3769884 load */
    /* @3769892 constant */
    /* @3769896 cmp */
    /* @3769900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_3770100;
    /* @3769904 load */
    /* @3769912 constant */
    /* @3769916 cmp */
    /* @3769920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_3770100;
    /* @3769924 constant */
    /* @3769928 store */
    GM_WRITE(vm, -1, "throwingboomerang", VAL(1));
    /* @3769936 constant */
    /* @3769940 cast */
    /* @3769944 load */
    /* @3769952 constant */
    /* @3769956 add */
    /* @3769960 load */
    /* @3769968 constant */
    /* @3769972 add */
    /* @3769976 call */
    GM_SITE(vm, 11, 3769976);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v60 = GM_ADD(GM_READ(vm, -1, "y"), VAL(7));
    /* @3769984 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v59, v60, VAL(43)));
    /* @3769988 load */
    /* @3769996 constant */
    /* @3770000 cmp */
    /* @3770004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3770012;
    /* @3770008 b */
    goto L_3770068;
    L_3770012: ;
    /* @3770012 load */
    /* @3770020 constant */
    /* @3770024 cmp */
    /* @3770028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3770068;
    /* @3770032 constant */
    /* @3770036 cast */
    /* @3770040 constant */
    /* @3770044 cast */
    /* @3770048 constant */
    /* @3770052 cast */
    /* @3770056 call */
    GM_SITE(vm, 11, 3770056);
    /* @3770064 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(13), VAL(0), VAL(0)));
    L_3770068: ;
    /* @3770068 constant */
    /* @3770072 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3770080 constant */
    /* @3770084 constant */
    /* @3770088 constant */
    /* @3770092 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3770100: ;
    /* @3770100 load */
    /* @3770108 constant */
    /* @3770112 cmp */
    /* @3770116 cast */
    /* @3770120 load */
    /* @3770128 constant */
    /* @3770132 cmp */
    /* @3770136 cast */
    /* @3770140 and */
    /* @3770144 cast */
    /* @3770148 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "spikegun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0))))))) goto L_3770316;
    /* @3770152 constant */
    /* @3770156 cast */
    /* @3770160 load */
    /* @3770168 constant */
    /* @3770172 sub */
    /* @3770176 load */
    /* @3770184 constant */
    /* @3770188 add */
    /* @3770192 call */
    GM_SITE(vm, 11, 3770192);
    v61 = GM_ADD(GM_READ(vm, -1, "x"), VAL(24));
    /* @3770200 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v61, (GM_READ(vm, -1, "y") - VAL(3)), VAL(42)));
    /* @3770204 load */
    /* @3770212 constant */
    /* @3770216 cmp */
    /* @3770220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3770228;
    /* @3770224 b */
    goto L_3770284;
    L_3770228: ;
    /* @3770228 load */
    /* @3770236 constant */
    /* @3770240 cmp */
    /* @3770244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3770284;
    /* @3770248 constant */
    /* @3770252 cast */
    /* @3770256 constant */
    /* @3770260 cast */
    /* @3770264 constant */
    /* @3770268 cast */
    /* @3770272 call */
    GM_SITE(vm, 11, 3770272);
    /* @3770280 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3770284: ;
    /* @3770284 constant */
    /* @3770288 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3770296 constant */
    /* @3770300 constant */
    /* @3770304 constant */
    /* @3770308 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3770316: ;
    /* @3770316 load */
    /* @3770324 constant */
    /* @3770328 cmp */
    /* @3770332 cast */
    /* @3770336 load */
    /* @3770344 constant */
    /* @3770348 cmp */
    /* @3770352 cast */
    /* @3770356 and */
    /* @3770360 cast */
    /* @3770364 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "spikegun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1))))))) goto L_3770532;
    /* @3770368 constant */
    /* @3770372 cast */
    /* @3770376 load */
    /* @3770384 constant */
    /* @3770388 sub */
    /* @3770392 load */
    /* @3770400 constant */
    /* @3770404 sub */
    /* @3770408 call */
    GM_SITE(vm, 11, 3770408);
    /* @3770416 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(24)), (GM_READ(vm, -1, "y") - VAL(3)), VAL(42)));
    /* @3770420 load */
    /* @3770428 constant */
    /* @3770432 cmp */
    /* @3770436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3770444;
    /* @3770440 b */
    goto L_3770500;
    L_3770444: ;
    /* @3770444 load */
    /* @3770452 constant */
    /* @3770456 cmp */
    /* @3770460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3770500;
    /* @3770464 constant */
    /* @3770468 cast */
    /* @3770472 constant */
    /* @3770476 cast */
    /* @3770480 constant */
    /* @3770484 cast */
    /* @3770488 call */
    GM_SITE(vm, 11, 3770488);
    /* @3770496 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(2), VAL(0), VAL(0)));
    L_3770500: ;
    /* @3770500 constant */
    /* @3770504 store */
    GM_WRITE(vm, -5, "firing", VAL(1));
    /* @3770512 constant */
    /* @3770516 constant */
    /* @3770520 constant */
    /* @3770524 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(5));
    L_3770532: ;
    return;
}
