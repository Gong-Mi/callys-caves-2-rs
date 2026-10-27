/* generated from CODE 436 (gml_Object_obj_strengthupgrade2_Draw_0), source start 4615172, end 4618524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0436(GmVM* vm) {
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
    /* @4615172 load */
    /* @4615180 constant */
    /* @4615184 cmp */
    /* @4615188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4615676;
    /* @4615192 constant */
    /* @4615196 cast */
    /* @4615200 constant */
    /* @4615204 cast */
    /* @4615208 constant */
    /* @4615212 cast */
    /* @4615216 constant */
    /* @4615228 cast */
    /* @4615232 constant */
    /* @4615244 cast */
    /* @4615248 load */
    /* @4615256 load */
    /* @4615264 constant */
    /* @4615268 cast */
    /* @4615272 constant */
    /* @4615276 cast */
    /* @4615280 call */
    GM_SITE(vm, 436, 4615280);
    /* @4615288 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4615292 constant */
    /* @4615296 cast */
    /* @4615300 call */
    GM_SITE(vm, 436, 4615300);
    /* @4615308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4615312 constant */
    /* @4615320 cast */
    /* @4615324 call */
    GM_SITE(vm, 436, 4615324);
    /* @4615332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4615336 string */
    /* @4615344 cast */
    /* @4615348 load */
    /* @4615356 load */
    /* @4615364 constant */
    /* @4615368 add */
    /* @4615372 call */
    GM_SITE(vm, 436, 4615372);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4615380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(814)));
    /* @4615384 string */
    /* @4615392 cast */
    /* @4615396 load */
    /* @4615404 constant */
    /* @4615408 add */
    /* @4615412 load */
    /* @4615420 constant */
    /* @4615424 add */
    /* @4615428 call */
    GM_SITE(vm, 436, 4615428);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4615436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(815)));
    /* @4615440 constant */
    /* @4615444 cast */
    /* @4615448 constant */
    /* @4615452 cast */
    /* @4615456 constant */
    /* @4615460 cast */
    /* @4615464 constant */
    /* @4615476 cast */
    /* @4615480 constant */
    /* @4615492 cast */
    /* @4615496 load */
    /* @4615504 constant */
    /* @4615508 add */
    /* @4615512 load */
    /* @4615520 constant */
    /* @4615524 add */
    /* @4615528 constant */
    /* @4615532 cast */
    /* @4615536 constant */
    /* @4615540 cast */
    /* @4615544 call */
    GM_SITE(vm, 436, 4615544);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4615552 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4615556 load */
    /* @4615564 constant */
    /* @4615568 cmp */
    /* @4615572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4615676;
    /* @4615576 constant */
    /* @4615580 cast */
    /* @4615584 constant */
    /* @4615588 cast */
    /* @4615592 constant */
    /* @4615596 cast */
    /* @4615600 constant */
    /* @4615612 cast */
    /* @4615616 constant */
    /* @4615628 cast */
    /* @4615632 load */
    /* @4615640 load */
    /* @4615648 constant */
    /* @4615652 cast */
    /* @4615656 constant */
    /* @4615660 cast */
    /* @4615664 call */
    GM_SITE(vm, 436, 4615664);
    /* @4615672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4615676: ;
    /* @4615676 load */
    /* @4615684 constant */
    /* @4615688 cmp */
    /* @4615692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4616236;
    /* @4615696 constant */
    /* @4615700 constant */
    /* @4615704 load */
    /* @4615712 constant */
    /* @4615716 add */
    /* @4615720 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4615728 constant */
    /* @4615732 constant */
    /* @4615736 load */
    /* @4615744 constant */
    /* @4615748 add */
    /* @4615752 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    GM_WRITE(vm, -1, "y", v7);
    /* @4615760 constant */
    /* @4615764 cast */
    /* @4615768 constant */
    /* @4615772 cast */
    /* @4615776 constant */
    /* @4615780 cast */
    /* @4615784 constant */
    /* @4615788 cast */
    /* @4615792 constant */
    /* @4615796 cast */
    /* @4615800 load */
    /* @4615808 load */
    /* @4615816 constant */
    /* @4615820 cast */
    /* @4615824 constant */
    /* @4615828 cast */
    /* @4615832 call */
    GM_SITE(vm, 436, 4615832);
    /* @4615840 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4615844 constant */
    /* @4615848 cast */
    /* @4615852 call */
    GM_SITE(vm, 436, 4615852);
    /* @4615860 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4615864 constant */
    /* @4615872 cast */
    /* @4615876 call */
    GM_SITE(vm, 436, 4615876);
    /* @4615884 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4615888 string */
    /* @4615896 cast */
    /* @4615900 load */
    /* @4615908 constant */
    /* @4615912 add */
    /* @4615916 load */
    /* @4615924 constant */
    /* @4615928 add */
    /* @4615932 call */
    GM_SITE(vm, 436, 4615932);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4615940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(814)));
    /* @4615944 string */
    /* @4615952 cast */
    /* @4615956 load */
    /* @4615964 constant */
    /* @4615968 add */
    /* @4615972 load */
    /* @4615980 constant */
    /* @4615984 add */
    /* @4615988 call */
    GM_SITE(vm, 436, 4615988);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4615996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(815)));
    /* @4616000 constant */
    /* @4616004 cast */
    /* @4616008 constant */
    /* @4616012 cast */
    /* @4616016 constant */
    /* @4616020 cast */
    /* @4616024 constant */
    /* @4616036 cast */
    /* @4616040 constant */
    /* @4616052 cast */
    /* @4616056 load */
    /* @4616064 constant */
    /* @4616068 add */
    /* @4616072 load */
    /* @4616080 constant */
    /* @4616084 add */
    /* @4616088 constant */
    /* @4616092 cast */
    /* @4616096 constant */
    /* @4616100 cast */
    /* @4616104 call */
    GM_SITE(vm, 436, 4616104);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4616112 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v12, v13, VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    /* @4616116 load */
    /* @4616124 constant */
    /* @4616128 cmp */
    /* @4616132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4616236;
    /* @4616136 constant */
    /* @4616140 cast */
    /* @4616144 constant */
    /* @4616148 cast */
    /* @4616152 constant */
    /* @4616156 cast */
    /* @4616160 constant */
    /* @4616172 cast */
    /* @4616176 constant */
    /* @4616188 cast */
    /* @4616192 load */
    /* @4616200 load */
    /* @4616208 constant */
    /* @4616212 cast */
    /* @4616216 constant */
    /* @4616220 cast */
    /* @4616224 call */
    GM_SITE(vm, 436, 4616224);
    /* @4616232 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4616236: ;
    /* @4616236 load */
    /* @4616244 constant */
    /* @4616248 cmp */
    /* @4616252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4616812;
    /* @4616256 constant */
    /* @4616260 constant */
    /* @4616264 load */
    /* @4616272 constant */
    /* @4616276 add */
    /* @4616280 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4616288 constant */
    /* @4616292 constant */
    /* @4616296 load */
    /* @4616304 constant */
    /* @4616308 add */
    /* @4616312 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(180));
    GM_WRITE(vm, -1, "y", v15);
    /* @4616320 constant */
    /* @4616324 cast */
    /* @4616328 constant */
    /* @4616332 cast */
    /* @4616336 constant */
    /* @4616340 cast */
    /* @4616344 constant */
    /* @4616356 cast */
    /* @4616360 constant */
    /* @4616372 cast */
    /* @4616376 load */
    /* @4616384 load */
    /* @4616392 constant */
    /* @4616396 cast */
    /* @4616400 constant */
    /* @4616404 cast */
    /* @4616408 call */
    GM_SITE(vm, 436, 4616408);
    /* @4616416 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4616420 constant */
    /* @4616424 cast */
    /* @4616428 call */
    GM_SITE(vm, 436, 4616428);
    /* @4616436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4616440 constant */
    /* @4616448 cast */
    /* @4616452 call */
    GM_SITE(vm, 436, 4616452);
    /* @4616460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4616464 string */
    /* @4616472 cast */
    /* @4616476 load */
    /* @4616484 constant */
    /* @4616488 add */
    /* @4616492 load */
    /* @4616500 constant */
    /* @4616504 add */
    /* @4616508 call */
    GM_SITE(vm, 436, 4616508);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4616516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(814)));
    /* @4616520 string */
    /* @4616528 cast */
    /* @4616532 load */
    /* @4616540 constant */
    /* @4616544 add */
    /* @4616548 load */
    /* @4616556 constant */
    /* @4616560 add */
    /* @4616564 call */
    GM_SITE(vm, 436, 4616564);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4616572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(815)));
    /* @4616576 constant */
    /* @4616580 cast */
    /* @4616584 constant */
    /* @4616588 cast */
    /* @4616592 constant */
    /* @4616596 cast */
    /* @4616600 constant */
    /* @4616612 cast */
    /* @4616616 constant */
    /* @4616628 cast */
    /* @4616632 load */
    /* @4616640 constant */
    /* @4616644 add */
    /* @4616648 load */
    /* @4616656 constant */
    /* @4616660 add */
    /* @4616664 constant */
    /* @4616668 cast */
    /* @4616672 constant */
    /* @4616676 cast */
    /* @4616680 call */
    GM_SITE(vm, 436, 4616680);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4616688 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v20, v21, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4616692 load */
    /* @4616700 constant */
    /* @4616704 cmp */
    /* @4616708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4616812;
    /* @4616712 constant */
    /* @4616716 cast */
    /* @4616720 constant */
    /* @4616724 cast */
    /* @4616728 constant */
    /* @4616732 cast */
    /* @4616736 constant */
    /* @4616748 cast */
    /* @4616752 constant */
    /* @4616764 cast */
    /* @4616768 load */
    /* @4616776 load */
    /* @4616784 constant */
    /* @4616788 cast */
    /* @4616792 constant */
    /* @4616796 cast */
    /* @4616800 call */
    GM_SITE(vm, 436, 4616800);
    /* @4616808 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4616812: ;
    /* @4616812 load */
    /* @4616820 constant */
    /* @4616824 cmp */
    /* @4616828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4617388;
    /* @4616832 constant */
    /* @4616836 constant */
    /* @4616840 load */
    /* @4616848 constant */
    /* @4616852 add */
    /* @4616856 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4616864 constant */
    /* @4616868 constant */
    /* @4616872 load */
    /* @4616880 constant */
    /* @4616884 add */
    /* @4616888 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(180));
    GM_WRITE(vm, -1, "y", v23);
    /* @4616896 constant */
    /* @4616900 cast */
    /* @4616904 constant */
    /* @4616908 cast */
    /* @4616912 constant */
    /* @4616916 cast */
    /* @4616920 constant */
    /* @4616932 cast */
    /* @4616936 constant */
    /* @4616948 cast */
    /* @4616952 load */
    /* @4616960 load */
    /* @4616968 constant */
    /* @4616972 cast */
    /* @4616976 constant */
    /* @4616980 cast */
    /* @4616984 call */
    GM_SITE(vm, 436, 4616984);
    /* @4616992 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4616996 constant */
    /* @4617000 cast */
    /* @4617004 call */
    GM_SITE(vm, 436, 4617004);
    /* @4617012 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4617016 constant */
    /* @4617024 cast */
    /* @4617028 call */
    GM_SITE(vm, 436, 4617028);
    /* @4617036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4617040 string */
    /* @4617048 cast */
    /* @4617052 load */
    /* @4617060 constant */
    /* @4617064 add */
    /* @4617068 load */
    /* @4617076 constant */
    /* @4617080 add */
    /* @4617084 call */
    GM_SITE(vm, 436, 4617084);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4617092 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(814)));
    /* @4617096 string */
    /* @4617104 cast */
    /* @4617108 load */
    /* @4617116 constant */
    /* @4617120 add */
    /* @4617124 load */
    /* @4617132 constant */
    /* @4617136 add */
    /* @4617140 call */
    GM_SITE(vm, 436, 4617140);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4617148 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(815)));
    /* @4617152 constant */
    /* @4617156 cast */
    /* @4617160 constant */
    /* @4617164 cast */
    /* @4617168 constant */
    /* @4617172 cast */
    /* @4617176 constant */
    /* @4617188 cast */
    /* @4617192 constant */
    /* @4617204 cast */
    /* @4617208 load */
    /* @4617216 constant */
    /* @4617220 add */
    /* @4617224 load */
    /* @4617232 constant */
    /* @4617236 add */
    /* @4617240 constant */
    /* @4617244 cast */
    /* @4617248 constant */
    /* @4617252 cast */
    /* @4617256 call */
    GM_SITE(vm, 436, 4617256);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4617264 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v28, v29, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4617268 load */
    /* @4617276 constant */
    /* @4617280 cmp */
    /* @4617284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4617388;
    /* @4617288 constant */
    /* @4617292 cast */
    /* @4617296 constant */
    /* @4617300 cast */
    /* @4617304 constant */
    /* @4617308 cast */
    /* @4617312 constant */
    /* @4617324 cast */
    /* @4617328 constant */
    /* @4617340 cast */
    /* @4617344 load */
    /* @4617352 load */
    /* @4617360 constant */
    /* @4617364 cast */
    /* @4617368 constant */
    /* @4617372 cast */
    /* @4617376 call */
    GM_SITE(vm, 436, 4617376);
    /* @4617384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4617388: ;
    /* @4617388 load */
    /* @4617396 constant */
    /* @4617400 cmp */
    /* @4617404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4617956;
    /* @4617408 constant */
    /* @4617412 constant */
    /* @4617416 load */
    /* @4617424 constant */
    /* @4617428 add */
    /* @4617432 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4617440 constant */
    /* @4617444 constant */
    /* @4617448 load */
    /* @4617456 constant */
    /* @4617460 add */
    /* @4617464 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    GM_WRITE(vm, -1, "y", v31);
    /* @4617472 constant */
    /* @4617476 cast */
    /* @4617480 constant */
    /* @4617484 cast */
    /* @4617488 constant */
    /* @4617492 cast */
    /* @4617496 constant */
    /* @4617508 cast */
    /* @4617512 constant */
    /* @4617524 cast */
    /* @4617528 load */
    /* @4617536 load */
    /* @4617544 constant */
    /* @4617548 cast */
    /* @4617552 constant */
    /* @4617556 cast */
    /* @4617560 call */
    GM_SITE(vm, 436, 4617560);
    /* @4617568 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4617572 constant */
    /* @4617576 cast */
    /* @4617580 call */
    GM_SITE(vm, 436, 4617580);
    /* @4617588 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4617592 constant */
    /* @4617600 cast */
    /* @4617604 call */
    GM_SITE(vm, 436, 4617604);
    /* @4617612 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4617616 string */
    /* @4617624 cast */
    /* @4617628 load */
    /* @4617636 load */
    /* @4617644 constant */
    /* @4617648 add */
    /* @4617652 call */
    GM_SITE(vm, 436, 4617652);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4617660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(814)));
    /* @4617664 string */
    /* @4617672 cast */
    /* @4617676 load */
    /* @4617684 constant */
    /* @4617688 add */
    /* @4617692 load */
    /* @4617700 constant */
    /* @4617704 add */
    /* @4617708 call */
    GM_SITE(vm, 436, 4617708);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4617716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(815)));
    /* @4617720 constant */
    /* @4617724 cast */
    /* @4617728 constant */
    /* @4617732 cast */
    /* @4617736 constant */
    /* @4617740 cast */
    /* @4617744 constant */
    /* @4617756 cast */
    /* @4617760 constant */
    /* @4617772 cast */
    /* @4617776 load */
    /* @4617784 constant */
    /* @4617788 add */
    /* @4617792 load */
    /* @4617800 constant */
    /* @4617804 add */
    /* @4617808 constant */
    /* @4617812 cast */
    /* @4617816 constant */
    /* @4617820 cast */
    /* @4617824 call */
    GM_SITE(vm, 436, 4617824);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4617832 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4617836 load */
    /* @4617844 constant */
    /* @4617848 cmp */
    /* @4617852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4617956;
    /* @4617856 constant */
    /* @4617860 cast */
    /* @4617864 constant */
    /* @4617868 cast */
    /* @4617872 constant */
    /* @4617876 cast */
    /* @4617880 constant */
    /* @4617892 cast */
    /* @4617896 constant */
    /* @4617908 cast */
    /* @4617912 load */
    /* @4617920 load */
    /* @4617928 constant */
    /* @4617932 cast */
    /* @4617936 constant */
    /* @4617940 cast */
    /* @4617944 call */
    GM_SITE(vm, 436, 4617944);
    /* @4617952 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4617956: ;
    /* @4617956 load */
    /* @4617964 constant */
    /* @4617968 cmp */
    /* @4617972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4618524;
    /* @4617976 constant */
    /* @4617980 constant */
    /* @4617984 load */
    /* @4617992 constant */
    /* @4617996 add */
    /* @4618000 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4618008 constant */
    /* @4618012 constant */
    /* @4618016 load */
    /* @4618024 constant */
    /* @4618028 add */
    /* @4618032 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    GM_WRITE(vm, -1, "y", v38);
    /* @4618040 constant */
    /* @4618044 cast */
    /* @4618048 constant */
    /* @4618052 cast */
    /* @4618056 constant */
    /* @4618060 cast */
    /* @4618064 constant */
    /* @4618076 cast */
    /* @4618080 constant */
    /* @4618092 cast */
    /* @4618096 load */
    /* @4618104 load */
    /* @4618112 constant */
    /* @4618116 cast */
    /* @4618120 constant */
    /* @4618124 cast */
    /* @4618128 call */
    GM_SITE(vm, 436, 4618128);
    /* @4618136 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4618140 constant */
    /* @4618144 cast */
    /* @4618148 call */
    GM_SITE(vm, 436, 4618148);
    /* @4618156 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4618160 constant */
    /* @4618168 cast */
    /* @4618172 call */
    GM_SITE(vm, 436, 4618172);
    /* @4618180 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4618184 string */
    /* @4618192 cast */
    /* @4618196 load */
    /* @4618204 load */
    /* @4618212 constant */
    /* @4618216 add */
    /* @4618220 call */
    GM_SITE(vm, 436, 4618220);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4618228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(814)));
    /* @4618232 string */
    /* @4618240 cast */
    /* @4618244 load */
    /* @4618252 constant */
    /* @4618256 add */
    /* @4618260 load */
    /* @4618268 constant */
    /* @4618272 add */
    /* @4618276 call */
    GM_SITE(vm, 436, 4618276);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4618284 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(815)));
    /* @4618288 constant */
    /* @4618292 cast */
    /* @4618296 constant */
    /* @4618300 cast */
    /* @4618304 constant */
    /* @4618308 cast */
    /* @4618312 constant */
    /* @4618324 cast */
    /* @4618328 constant */
    /* @4618340 cast */
    /* @4618344 load */
    /* @4618352 constant */
    /* @4618356 add */
    /* @4618360 load */
    /* @4618368 constant */
    /* @4618372 add */
    /* @4618376 constant */
    /* @4618380 cast */
    /* @4618384 constant */
    /* @4618388 cast */
    /* @4618392 call */
    GM_SITE(vm, 436, 4618392);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4618400 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4618404 load */
    /* @4618412 constant */
    /* @4618416 cmp */
    /* @4618420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4618524;
    /* @4618424 constant */
    /* @4618428 cast */
    /* @4618432 constant */
    /* @4618436 cast */
    /* @4618440 constant */
    /* @4618444 cast */
    /* @4618448 constant */
    /* @4618460 cast */
    /* @4618464 constant */
    /* @4618476 cast */
    /* @4618480 load */
    /* @4618488 load */
    /* @4618496 constant */
    /* @4618500 cast */
    /* @4618504 constant */
    /* @4618508 cast */
    /* @4618512 call */
    GM_SITE(vm, 436, 4618512);
    /* @4618520 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4618524: ;
    return;
}
