/* generated from CODE 444 (gml_Object_obj_maxhpupgrade2_Draw_0), source start 4629132, end 4632404. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0444(GmVM* vm) {
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
    /* @4629132 load */
    /* @4629140 constant */
    /* @4629144 cmp */
    /* @4629148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4629620;
    /* @4629152 constant */
    /* @4629156 cast */
    /* @4629160 constant */
    /* @4629164 cast */
    /* @4629168 constant */
    /* @4629172 cast */
    /* @4629176 constant */
    /* @4629188 cast */
    /* @4629192 constant */
    /* @4629204 cast */
    /* @4629208 load */
    /* @4629216 load */
    /* @4629224 constant */
    /* @4629228 cast */
    /* @4629232 constant */
    /* @4629236 cast */
    /* @4629240 call */
    GM_SITE(vm, 444, 4629240);
    /* @4629248 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4629252 constant */
    /* @4629256 cast */
    /* @4629260 call */
    GM_SITE(vm, 444, 4629260);
    /* @4629268 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4629272 constant */
    /* @4629280 cast */
    /* @4629284 call */
    GM_SITE(vm, 444, 4629284);
    /* @4629292 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4629296 string */
    /* @4629304 cast */
    /* @4629308 load */
    /* @4629316 load */
    /* @4629324 constant */
    /* @4629328 add */
    /* @4629332 call */
    GM_SITE(vm, 444, 4629332);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4629340 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(820)));
    /* @4629344 string */
    /* @4629352 cast */
    /* @4629356 load */
    /* @4629364 constant */
    /* @4629368 add */
    /* @4629372 load */
    /* @4629380 constant */
    /* @4629384 add */
    /* @4629388 call */
    GM_SITE(vm, 444, 4629388);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4629396 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(799)));
    /* @4629400 constant */
    /* @4629404 cast */
    /* @4629408 constant */
    /* @4629412 cast */
    /* @4629416 constant */
    /* @4629420 cast */
    /* @4629424 constant */
    /* @4629428 cast */
    /* @4629432 constant */
    /* @4629436 cast */
    /* @4629440 load */
    /* @4629448 constant */
    /* @4629452 add */
    /* @4629456 load */
    /* @4629464 constant */
    /* @4629468 add */
    /* @4629472 constant */
    /* @4629476 cast */
    /* @4629480 constant */
    /* @4629484 cast */
    /* @4629488 call */
    GM_SITE(vm, 444, 4629488);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4629496 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4629500 load */
    /* @4629508 constant */
    /* @4629512 cmp */
    /* @4629516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4629620;
    /* @4629520 constant */
    /* @4629524 cast */
    /* @4629528 constant */
    /* @4629532 cast */
    /* @4629536 constant */
    /* @4629540 cast */
    /* @4629544 constant */
    /* @4629556 cast */
    /* @4629560 constant */
    /* @4629572 cast */
    /* @4629576 load */
    /* @4629584 load */
    /* @4629592 constant */
    /* @4629596 cast */
    /* @4629600 constant */
    /* @4629604 cast */
    /* @4629608 call */
    GM_SITE(vm, 444, 4629608);
    /* @4629616 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4629620: ;
    /* @4629620 load */
    /* @4629628 constant */
    /* @4629632 cmp */
    /* @4629636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4630180;
    /* @4629640 constant */
    /* @4629644 constant */
    /* @4629648 load */
    /* @4629656 constant */
    /* @4629660 add */
    /* @4629664 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4629672 constant */
    /* @4629676 constant */
    /* @4629680 load */
    /* @4629688 constant */
    /* @4629692 add */
    /* @4629696 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    GM_WRITE(vm, -1, "y", v7);
    /* @4629704 constant */
    /* @4629708 cast */
    /* @4629712 constant */
    /* @4629716 cast */
    /* @4629720 constant */
    /* @4629724 cast */
    /* @4629728 constant */
    /* @4629732 cast */
    /* @4629736 constant */
    /* @4629740 cast */
    /* @4629744 load */
    /* @4629752 load */
    /* @4629760 constant */
    /* @4629764 cast */
    /* @4629768 constant */
    /* @4629772 cast */
    /* @4629776 call */
    GM_SITE(vm, 444, 4629776);
    /* @4629784 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4629788 constant */
    /* @4629792 cast */
    /* @4629796 call */
    GM_SITE(vm, 444, 4629796);
    /* @4629804 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4629808 constant */
    /* @4629816 cast */
    /* @4629820 call */
    GM_SITE(vm, 444, 4629820);
    /* @4629828 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4629832 string */
    /* @4629840 cast */
    /* @4629844 load */
    /* @4629852 constant */
    /* @4629856 add */
    /* @4629860 load */
    /* @4629868 constant */
    /* @4629872 add */
    /* @4629876 call */
    GM_SITE(vm, 444, 4629876);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4629884 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(820)));
    /* @4629888 string */
    /* @4629896 cast */
    /* @4629900 load */
    /* @4629908 constant */
    /* @4629912 add */
    /* @4629916 load */
    /* @4629924 constant */
    /* @4629928 add */
    /* @4629932 call */
    GM_SITE(vm, 444, 4629932);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4629940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(799)));
    /* @4629944 constant */
    /* @4629948 cast */
    /* @4629952 constant */
    /* @4629956 cast */
    /* @4629960 constant */
    /* @4629964 cast */
    /* @4629968 constant */
    /* @4629980 cast */
    /* @4629984 constant */
    /* @4629996 cast */
    /* @4630000 load */
    /* @4630008 constant */
    /* @4630012 add */
    /* @4630016 load */
    /* @4630024 constant */
    /* @4630028 add */
    /* @4630032 constant */
    /* @4630036 cast */
    /* @4630040 constant */
    /* @4630044 cast */
    /* @4630048 call */
    GM_SITE(vm, 444, 4630048);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4630056 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4630060 load */
    /* @4630068 constant */
    /* @4630072 cmp */
    /* @4630076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4630180;
    /* @4630080 constant */
    /* @4630084 cast */
    /* @4630088 constant */
    /* @4630092 cast */
    /* @4630096 constant */
    /* @4630100 cast */
    /* @4630104 constant */
    /* @4630116 cast */
    /* @4630120 constant */
    /* @4630132 cast */
    /* @4630136 load */
    /* @4630144 load */
    /* @4630152 constant */
    /* @4630156 cast */
    /* @4630160 constant */
    /* @4630164 cast */
    /* @4630168 call */
    GM_SITE(vm, 444, 4630168);
    /* @4630176 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4630180: ;
    /* @4630180 load */
    /* @4630188 constant */
    /* @4630192 cmp */
    /* @4630196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4630740;
    /* @4630200 constant */
    /* @4630204 constant */
    /* @4630208 load */
    /* @4630216 constant */
    /* @4630220 add */
    /* @4630224 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4630232 constant */
    /* @4630236 constant */
    /* @4630240 load */
    /* @4630248 constant */
    /* @4630252 add */
    /* @4630256 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    GM_WRITE(vm, -1, "y", v15);
    /* @4630264 constant */
    /* @4630268 cast */
    /* @4630272 constant */
    /* @4630276 cast */
    /* @4630280 constant */
    /* @4630284 cast */
    /* @4630288 constant */
    /* @4630300 cast */
    /* @4630304 constant */
    /* @4630316 cast */
    /* @4630320 load */
    /* @4630328 load */
    /* @4630336 constant */
    /* @4630340 cast */
    /* @4630344 constant */
    /* @4630348 cast */
    /* @4630352 call */
    GM_SITE(vm, 444, 4630352);
    /* @4630360 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4630364 constant */
    /* @4630368 cast */
    /* @4630372 call */
    GM_SITE(vm, 444, 4630372);
    /* @4630380 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4630384 constant */
    /* @4630392 cast */
    /* @4630396 call */
    GM_SITE(vm, 444, 4630396);
    /* @4630404 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4630408 string */
    /* @4630416 cast */
    /* @4630420 load */
    /* @4630428 constant */
    /* @4630432 add */
    /* @4630436 load */
    /* @4630444 constant */
    /* @4630448 add */
    /* @4630452 call */
    GM_SITE(vm, 444, 4630452);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4630460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(820)));
    /* @4630464 string */
    /* @4630472 cast */
    /* @4630476 load */
    /* @4630484 constant */
    /* @4630488 add */
    /* @4630492 load */
    /* @4630500 constant */
    /* @4630504 add */
    /* @4630508 call */
    GM_SITE(vm, 444, 4630508);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4630516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(799)));
    /* @4630520 constant */
    /* @4630524 cast */
    /* @4630528 constant */
    /* @4630532 cast */
    /* @4630536 constant */
    /* @4630540 cast */
    /* @4630544 constant */
    /* @4630548 cast */
    /* @4630552 constant */
    /* @4630556 cast */
    /* @4630560 load */
    /* @4630568 constant */
    /* @4630572 add */
    /* @4630576 load */
    /* @4630584 constant */
    /* @4630588 add */
    /* @4630592 constant */
    /* @4630596 cast */
    /* @4630600 constant */
    /* @4630604 cast */
    /* @4630608 call */
    GM_SITE(vm, 444, 4630608);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4630616 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4630620 load */
    /* @4630628 constant */
    /* @4630632 cmp */
    /* @4630636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4630740;
    /* @4630640 constant */
    /* @4630644 cast */
    /* @4630648 constant */
    /* @4630652 cast */
    /* @4630656 constant */
    /* @4630660 cast */
    /* @4630664 constant */
    /* @4630676 cast */
    /* @4630680 constant */
    /* @4630692 cast */
    /* @4630696 load */
    /* @4630704 load */
    /* @4630712 constant */
    /* @4630716 cast */
    /* @4630720 constant */
    /* @4630724 cast */
    /* @4630728 call */
    GM_SITE(vm, 444, 4630728);
    /* @4630736 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4630740: ;
    /* @4630740 load */
    /* @4630748 constant */
    /* @4630752 cmp */
    /* @4630756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4631300;
    /* @4630760 constant */
    /* @4630764 constant */
    /* @4630768 load */
    /* @4630776 constant */
    /* @4630780 add */
    /* @4630784 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4630792 constant */
    /* @4630796 constant */
    /* @4630800 load */
    /* @4630808 constant */
    /* @4630812 add */
    /* @4630816 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(100));
    GM_WRITE(vm, -1, "y", v23);
    /* @4630824 constant */
    /* @4630828 cast */
    /* @4630832 constant */
    /* @4630836 cast */
    /* @4630840 constant */
    /* @4630844 cast */
    /* @4630848 constant */
    /* @4630860 cast */
    /* @4630864 constant */
    /* @4630876 cast */
    /* @4630880 load */
    /* @4630888 load */
    /* @4630896 constant */
    /* @4630900 cast */
    /* @4630904 constant */
    /* @4630908 cast */
    /* @4630912 call */
    GM_SITE(vm, 444, 4630912);
    /* @4630920 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4630924 constant */
    /* @4630928 cast */
    /* @4630932 call */
    GM_SITE(vm, 444, 4630932);
    /* @4630940 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4630944 constant */
    /* @4630952 cast */
    /* @4630956 call */
    GM_SITE(vm, 444, 4630956);
    /* @4630964 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4630968 string */
    /* @4630976 cast */
    /* @4630980 load */
    /* @4630988 constant */
    /* @4630992 add */
    /* @4630996 load */
    /* @4631004 constant */
    /* @4631008 add */
    /* @4631012 call */
    GM_SITE(vm, 444, 4631012);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4631020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(820)));
    /* @4631024 string */
    /* @4631032 cast */
    /* @4631036 load */
    /* @4631044 constant */
    /* @4631048 add */
    /* @4631052 load */
    /* @4631060 constant */
    /* @4631064 add */
    /* @4631068 call */
    GM_SITE(vm, 444, 4631068);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4631076 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(799)));
    /* @4631080 constant */
    /* @4631084 cast */
    /* @4631088 constant */
    /* @4631092 cast */
    /* @4631096 constant */
    /* @4631100 cast */
    /* @4631104 constant */
    /* @4631108 cast */
    /* @4631112 constant */
    /* @4631116 cast */
    /* @4631120 load */
    /* @4631128 constant */
    /* @4631132 add */
    /* @4631136 load */
    /* @4631144 constant */
    /* @4631148 add */
    /* @4631152 constant */
    /* @4631156 cast */
    /* @4631160 constant */
    /* @4631164 cast */
    /* @4631168 call */
    GM_SITE(vm, 444, 4631168);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4631176 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v28, v29, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4631180 load */
    /* @4631188 constant */
    /* @4631192 cmp */
    /* @4631196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4631300;
    /* @4631200 constant */
    /* @4631204 cast */
    /* @4631208 constant */
    /* @4631212 cast */
    /* @4631216 constant */
    /* @4631220 cast */
    /* @4631224 constant */
    /* @4631236 cast */
    /* @4631240 constant */
    /* @4631252 cast */
    /* @4631256 load */
    /* @4631264 load */
    /* @4631272 constant */
    /* @4631276 cast */
    /* @4631280 constant */
    /* @4631284 cast */
    /* @4631288 call */
    GM_SITE(vm, 444, 4631288);
    /* @4631296 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4631300: ;
    /* @4631300 load */
    /* @4631308 constant */
    /* @4631312 cmp */
    /* @4631316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4631852;
    /* @4631320 constant */
    /* @4631324 constant */
    /* @4631328 load */
    /* @4631336 constant */
    /* @4631340 add */
    /* @4631344 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4631352 constant */
    /* @4631356 constant */
    /* @4631360 load */
    /* @4631368 constant */
    /* @4631372 add */
    /* @4631376 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    GM_WRITE(vm, -1, "y", v31);
    /* @4631384 constant */
    /* @4631388 cast */
    /* @4631392 constant */
    /* @4631396 cast */
    /* @4631400 constant */
    /* @4631404 cast */
    /* @4631408 constant */
    /* @4631420 cast */
    /* @4631424 constant */
    /* @4631436 cast */
    /* @4631440 load */
    /* @4631448 load */
    /* @4631456 constant */
    /* @4631460 cast */
    /* @4631464 constant */
    /* @4631468 cast */
    /* @4631472 call */
    GM_SITE(vm, 444, 4631472);
    /* @4631480 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4631484 constant */
    /* @4631488 cast */
    /* @4631492 call */
    GM_SITE(vm, 444, 4631492);
    /* @4631500 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4631504 constant */
    /* @4631512 cast */
    /* @4631516 call */
    GM_SITE(vm, 444, 4631516);
    /* @4631524 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4631528 string */
    /* @4631536 cast */
    /* @4631540 load */
    /* @4631548 load */
    /* @4631556 constant */
    /* @4631560 add */
    /* @4631564 call */
    GM_SITE(vm, 444, 4631564);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4631572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(820)));
    /* @4631576 string */
    /* @4631584 cast */
    /* @4631588 load */
    /* @4631596 constant */
    /* @4631600 add */
    /* @4631604 load */
    /* @4631612 constant */
    /* @4631616 add */
    /* @4631620 call */
    GM_SITE(vm, 444, 4631620);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4631628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(799)));
    /* @4631632 constant */
    /* @4631636 cast */
    /* @4631640 constant */
    /* @4631644 cast */
    /* @4631648 constant */
    /* @4631652 cast */
    /* @4631656 constant */
    /* @4631660 cast */
    /* @4631664 constant */
    /* @4631668 cast */
    /* @4631672 load */
    /* @4631680 constant */
    /* @4631684 add */
    /* @4631688 load */
    /* @4631696 constant */
    /* @4631700 add */
    /* @4631704 constant */
    /* @4631708 cast */
    /* @4631712 constant */
    /* @4631716 cast */
    /* @4631720 call */
    GM_SITE(vm, 444, 4631720);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4631728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4631732 load */
    /* @4631740 constant */
    /* @4631744 cmp */
    /* @4631748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4631852;
    /* @4631752 constant */
    /* @4631756 cast */
    /* @4631760 constant */
    /* @4631764 cast */
    /* @4631768 constant */
    /* @4631772 cast */
    /* @4631776 constant */
    /* @4631788 cast */
    /* @4631792 constant */
    /* @4631804 cast */
    /* @4631808 load */
    /* @4631816 load */
    /* @4631824 constant */
    /* @4631828 cast */
    /* @4631832 constant */
    /* @4631836 cast */
    /* @4631840 call */
    GM_SITE(vm, 444, 4631840);
    /* @4631848 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4631852: ;
    /* @4631852 load */
    /* @4631860 constant */
    /* @4631864 cmp */
    /* @4631868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4632404;
    /* @4631872 constant */
    /* @4631876 constant */
    /* @4631880 load */
    /* @4631888 constant */
    /* @4631892 add */
    /* @4631896 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4631904 constant */
    /* @4631908 constant */
    /* @4631912 load */
    /* @4631920 constant */
    /* @4631924 add */
    /* @4631928 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    GM_WRITE(vm, -1, "y", v38);
    /* @4631936 constant */
    /* @4631940 cast */
    /* @4631944 constant */
    /* @4631948 cast */
    /* @4631952 constant */
    /* @4631956 cast */
    /* @4631960 constant */
    /* @4631972 cast */
    /* @4631976 constant */
    /* @4631988 cast */
    /* @4631992 load */
    /* @4632000 load */
    /* @4632008 constant */
    /* @4632012 cast */
    /* @4632016 constant */
    /* @4632020 cast */
    /* @4632024 call */
    GM_SITE(vm, 444, 4632024);
    /* @4632032 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4632036 constant */
    /* @4632040 cast */
    /* @4632044 call */
    GM_SITE(vm, 444, 4632044);
    /* @4632052 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4632056 constant */
    /* @4632064 cast */
    /* @4632068 call */
    GM_SITE(vm, 444, 4632068);
    /* @4632076 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4632080 string */
    /* @4632088 cast */
    /* @4632092 load */
    /* @4632100 load */
    /* @4632108 constant */
    /* @4632112 add */
    /* @4632116 call */
    GM_SITE(vm, 444, 4632116);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4632124 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(820)));
    /* @4632128 string */
    /* @4632136 cast */
    /* @4632140 load */
    /* @4632148 constant */
    /* @4632152 add */
    /* @4632156 load */
    /* @4632164 constant */
    /* @4632168 add */
    /* @4632172 call */
    GM_SITE(vm, 444, 4632172);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4632180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(799)));
    /* @4632184 constant */
    /* @4632188 cast */
    /* @4632192 constant */
    /* @4632196 cast */
    /* @4632200 constant */
    /* @4632204 cast */
    /* @4632208 constant */
    /* @4632212 cast */
    /* @4632216 constant */
    /* @4632220 cast */
    /* @4632224 load */
    /* @4632232 constant */
    /* @4632236 add */
    /* @4632240 load */
    /* @4632248 constant */
    /* @4632252 add */
    /* @4632256 constant */
    /* @4632260 cast */
    /* @4632264 constant */
    /* @4632268 cast */
    /* @4632272 call */
    GM_SITE(vm, 444, 4632272);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4632280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4632284 load */
    /* @4632292 constant */
    /* @4632296 cmp */
    /* @4632300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(1)))) goto L_4632404;
    /* @4632304 constant */
    /* @4632308 cast */
    /* @4632312 constant */
    /* @4632316 cast */
    /* @4632320 constant */
    /* @4632324 cast */
    /* @4632328 constant */
    /* @4632340 cast */
    /* @4632344 constant */
    /* @4632356 cast */
    /* @4632360 load */
    /* @4632368 load */
    /* @4632376 constant */
    /* @4632380 cast */
    /* @4632384 constant */
    /* @4632388 cast */
    /* @4632392 call */
    GM_SITE(vm, 444, 4632392);
    /* @4632400 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4632404: ;
    return;
}
