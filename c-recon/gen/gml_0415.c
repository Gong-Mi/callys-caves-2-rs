/* generated from CODE 415 (gml_Object_obj_powerupgrade_Draw_0), source start 4579888, end 4583240. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0415(GmVM* vm) {
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
    /* @4579888 load */
    /* @4579896 constant */
    /* @4579900 cmp */
    /* @4579904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4580392;
    /* @4579908 constant */
    /* @4579912 cast */
    /* @4579916 constant */
    /* @4579920 cast */
    /* @4579924 constant */
    /* @4579928 cast */
    /* @4579932 constant */
    /* @4579944 cast */
    /* @4579948 constant */
    /* @4579960 cast */
    /* @4579964 load */
    /* @4579972 load */
    /* @4579980 constant */
    /* @4579984 cast */
    /* @4579988 constant */
    /* @4579992 cast */
    /* @4579996 call */
    GM_SITE(vm, 415, 4579996);
    /* @4580004 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4580008 constant */
    /* @4580012 cast */
    /* @4580016 call */
    GM_SITE(vm, 415, 4580016);
    /* @4580024 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4580028 constant */
    /* @4580036 cast */
    /* @4580040 call */
    GM_SITE(vm, 415, 4580040);
    /* @4580048 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4580052 string */
    /* @4580060 cast */
    /* @4580064 load */
    /* @4580072 load */
    /* @4580080 constant */
    /* @4580084 add */
    /* @4580088 call */
    GM_SITE(vm, 415, 4580088);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4580096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(796)));
    /* @4580100 string */
    /* @4580108 cast */
    /* @4580112 load */
    /* @4580120 constant */
    /* @4580124 add */
    /* @4580128 load */
    /* @4580136 constant */
    /* @4580140 add */
    /* @4580144 call */
    GM_SITE(vm, 415, 4580144);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4580152 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(797)));
    /* @4580156 constant */
    /* @4580160 cast */
    /* @4580164 constant */
    /* @4580168 cast */
    /* @4580172 constant */
    /* @4580176 cast */
    /* @4580180 constant */
    /* @4580192 cast */
    /* @4580196 constant */
    /* @4580208 cast */
    /* @4580212 load */
    /* @4580220 constant */
    /* @4580224 add */
    /* @4580228 load */
    /* @4580236 constant */
    /* @4580240 add */
    /* @4580244 constant */
    /* @4580248 cast */
    /* @4580252 constant */
    /* @4580256 cast */
    /* @4580260 call */
    GM_SITE(vm, 415, 4580260);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4580268 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4580272 load */
    /* @4580280 constant */
    /* @4580284 cmp */
    /* @4580288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4580392;
    /* @4580292 constant */
    /* @4580296 cast */
    /* @4580300 constant */
    /* @4580304 cast */
    /* @4580308 constant */
    /* @4580312 cast */
    /* @4580316 constant */
    /* @4580328 cast */
    /* @4580332 constant */
    /* @4580344 cast */
    /* @4580348 load */
    /* @4580356 load */
    /* @4580364 constant */
    /* @4580368 cast */
    /* @4580372 constant */
    /* @4580376 cast */
    /* @4580380 call */
    GM_SITE(vm, 415, 4580380);
    /* @4580388 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4580392: ;
    /* @4580392 load */
    /* @4580400 constant */
    /* @4580404 cmp */
    /* @4580408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4580952;
    /* @4580412 constant */
    /* @4580416 constant */
    /* @4580420 load */
    /* @4580428 constant */
    /* @4580432 add */
    /* @4580436 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4580444 constant */
    /* @4580448 constant */
    /* @4580452 load */
    /* @4580460 constant */
    /* @4580464 add */
    /* @4580468 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    GM_WRITE(vm, -1, "y", v7);
    /* @4580476 constant */
    /* @4580480 cast */
    /* @4580484 constant */
    /* @4580488 cast */
    /* @4580492 constant */
    /* @4580496 cast */
    /* @4580500 constant */
    /* @4580504 cast */
    /* @4580508 constant */
    /* @4580512 cast */
    /* @4580516 load */
    /* @4580524 load */
    /* @4580532 constant */
    /* @4580536 cast */
    /* @4580540 constant */
    /* @4580544 cast */
    /* @4580548 call */
    GM_SITE(vm, 415, 4580548);
    /* @4580556 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4580560 constant */
    /* @4580564 cast */
    /* @4580568 call */
    GM_SITE(vm, 415, 4580568);
    /* @4580576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4580580 constant */
    /* @4580588 cast */
    /* @4580592 call */
    GM_SITE(vm, 415, 4580592);
    /* @4580600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4580604 string */
    /* @4580612 cast */
    /* @4580616 load */
    /* @4580624 constant */
    /* @4580628 add */
    /* @4580632 load */
    /* @4580640 constant */
    /* @4580644 add */
    /* @4580648 call */
    GM_SITE(vm, 415, 4580648);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4580656 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(796)));
    /* @4580660 string */
    /* @4580668 cast */
    /* @4580672 load */
    /* @4580680 constant */
    /* @4580684 add */
    /* @4580688 load */
    /* @4580696 constant */
    /* @4580700 add */
    /* @4580704 call */
    GM_SITE(vm, 415, 4580704);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4580712 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(797)));
    /* @4580716 constant */
    /* @4580720 cast */
    /* @4580724 constant */
    /* @4580728 cast */
    /* @4580732 constant */
    /* @4580736 cast */
    /* @4580740 constant */
    /* @4580752 cast */
    /* @4580756 constant */
    /* @4580768 cast */
    /* @4580772 load */
    /* @4580780 constant */
    /* @4580784 add */
    /* @4580788 load */
    /* @4580796 constant */
    /* @4580800 add */
    /* @4580804 constant */
    /* @4580808 cast */
    /* @4580812 constant */
    /* @4580816 cast */
    /* @4580820 call */
    GM_SITE(vm, 415, 4580820);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4580828 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v12, v13, VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    /* @4580832 load */
    /* @4580840 constant */
    /* @4580844 cmp */
    /* @4580848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4580952;
    /* @4580852 constant */
    /* @4580856 cast */
    /* @4580860 constant */
    /* @4580864 cast */
    /* @4580868 constant */
    /* @4580872 cast */
    /* @4580876 constant */
    /* @4580888 cast */
    /* @4580892 constant */
    /* @4580904 cast */
    /* @4580908 load */
    /* @4580916 load */
    /* @4580924 constant */
    /* @4580928 cast */
    /* @4580932 constant */
    /* @4580936 cast */
    /* @4580940 call */
    GM_SITE(vm, 415, 4580940);
    /* @4580948 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4580952: ;
    /* @4580952 load */
    /* @4580960 constant */
    /* @4580964 cmp */
    /* @4580968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4581528;
    /* @4580972 constant */
    /* @4580976 constant */
    /* @4580980 load */
    /* @4580988 constant */
    /* @4580992 add */
    /* @4580996 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4581004 constant */
    /* @4581008 constant */
    /* @4581012 load */
    /* @4581020 constant */
    /* @4581024 add */
    /* @4581028 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(180));
    GM_WRITE(vm, -1, "y", v15);
    /* @4581036 constant */
    /* @4581040 cast */
    /* @4581044 constant */
    /* @4581048 cast */
    /* @4581052 constant */
    /* @4581056 cast */
    /* @4581060 constant */
    /* @4581072 cast */
    /* @4581076 constant */
    /* @4581088 cast */
    /* @4581092 load */
    /* @4581100 load */
    /* @4581108 constant */
    /* @4581112 cast */
    /* @4581116 constant */
    /* @4581120 cast */
    /* @4581124 call */
    GM_SITE(vm, 415, 4581124);
    /* @4581132 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4581136 constant */
    /* @4581140 cast */
    /* @4581144 call */
    GM_SITE(vm, 415, 4581144);
    /* @4581152 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4581156 constant */
    /* @4581164 cast */
    /* @4581168 call */
    GM_SITE(vm, 415, 4581168);
    /* @4581176 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4581180 string */
    /* @4581188 cast */
    /* @4581192 load */
    /* @4581200 constant */
    /* @4581204 add */
    /* @4581208 load */
    /* @4581216 constant */
    /* @4581220 add */
    /* @4581224 call */
    GM_SITE(vm, 415, 4581224);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4581232 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(796)));
    /* @4581236 string */
    /* @4581244 cast */
    /* @4581248 load */
    /* @4581256 constant */
    /* @4581260 add */
    /* @4581264 load */
    /* @4581272 constant */
    /* @4581276 add */
    /* @4581280 call */
    GM_SITE(vm, 415, 4581280);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4581288 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(797)));
    /* @4581292 constant */
    /* @4581296 cast */
    /* @4581300 constant */
    /* @4581304 cast */
    /* @4581308 constant */
    /* @4581312 cast */
    /* @4581316 constant */
    /* @4581328 cast */
    /* @4581332 constant */
    /* @4581344 cast */
    /* @4581348 load */
    /* @4581356 constant */
    /* @4581360 add */
    /* @4581364 load */
    /* @4581372 constant */
    /* @4581376 add */
    /* @4581380 constant */
    /* @4581384 cast */
    /* @4581388 constant */
    /* @4581392 cast */
    /* @4581396 call */
    GM_SITE(vm, 415, 4581396);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4581404 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v20, v21, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4581408 load */
    /* @4581416 constant */
    /* @4581420 cmp */
    /* @4581424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4581528;
    /* @4581428 constant */
    /* @4581432 cast */
    /* @4581436 constant */
    /* @4581440 cast */
    /* @4581444 constant */
    /* @4581448 cast */
    /* @4581452 constant */
    /* @4581464 cast */
    /* @4581468 constant */
    /* @4581480 cast */
    /* @4581484 load */
    /* @4581492 load */
    /* @4581500 constant */
    /* @4581504 cast */
    /* @4581508 constant */
    /* @4581512 cast */
    /* @4581516 call */
    GM_SITE(vm, 415, 4581516);
    /* @4581524 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4581528: ;
    /* @4581528 load */
    /* @4581536 constant */
    /* @4581540 cmp */
    /* @4581544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4582104;
    /* @4581548 constant */
    /* @4581552 constant */
    /* @4581556 load */
    /* @4581564 constant */
    /* @4581568 add */
    /* @4581572 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4581580 constant */
    /* @4581584 constant */
    /* @4581588 load */
    /* @4581596 constant */
    /* @4581600 add */
    /* @4581604 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(180));
    GM_WRITE(vm, -1, "y", v23);
    /* @4581612 constant */
    /* @4581616 cast */
    /* @4581620 constant */
    /* @4581624 cast */
    /* @4581628 constant */
    /* @4581632 cast */
    /* @4581636 constant */
    /* @4581648 cast */
    /* @4581652 constant */
    /* @4581664 cast */
    /* @4581668 load */
    /* @4581676 load */
    /* @4581684 constant */
    /* @4581688 cast */
    /* @4581692 constant */
    /* @4581696 cast */
    /* @4581700 call */
    GM_SITE(vm, 415, 4581700);
    /* @4581708 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4581712 constant */
    /* @4581716 cast */
    /* @4581720 call */
    GM_SITE(vm, 415, 4581720);
    /* @4581728 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4581732 constant */
    /* @4581740 cast */
    /* @4581744 call */
    GM_SITE(vm, 415, 4581744);
    /* @4581752 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4581756 string */
    /* @4581764 cast */
    /* @4581768 load */
    /* @4581776 constant */
    /* @4581780 add */
    /* @4581784 load */
    /* @4581792 constant */
    /* @4581796 add */
    /* @4581800 call */
    GM_SITE(vm, 415, 4581800);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4581808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(796)));
    /* @4581812 string */
    /* @4581820 cast */
    /* @4581824 load */
    /* @4581832 constant */
    /* @4581836 add */
    /* @4581840 load */
    /* @4581848 constant */
    /* @4581852 add */
    /* @4581856 call */
    GM_SITE(vm, 415, 4581856);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4581864 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(797)));
    /* @4581868 constant */
    /* @4581872 cast */
    /* @4581876 constant */
    /* @4581880 cast */
    /* @4581884 constant */
    /* @4581888 cast */
    /* @4581892 constant */
    /* @4581904 cast */
    /* @4581908 constant */
    /* @4581920 cast */
    /* @4581924 load */
    /* @4581932 constant */
    /* @4581936 add */
    /* @4581940 load */
    /* @4581948 constant */
    /* @4581952 add */
    /* @4581956 constant */
    /* @4581960 cast */
    /* @4581964 constant */
    /* @4581968 cast */
    /* @4581972 call */
    GM_SITE(vm, 415, 4581972);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4581980 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v28, v29, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4581984 load */
    /* @4581992 constant */
    /* @4581996 cmp */
    /* @4582000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4582104;
    /* @4582004 constant */
    /* @4582008 cast */
    /* @4582012 constant */
    /* @4582016 cast */
    /* @4582020 constant */
    /* @4582024 cast */
    /* @4582028 constant */
    /* @4582040 cast */
    /* @4582044 constant */
    /* @4582056 cast */
    /* @4582060 load */
    /* @4582068 load */
    /* @4582076 constant */
    /* @4582080 cast */
    /* @4582084 constant */
    /* @4582088 cast */
    /* @4582092 call */
    GM_SITE(vm, 415, 4582092);
    /* @4582100 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4582104: ;
    /* @4582104 load */
    /* @4582112 constant */
    /* @4582116 cmp */
    /* @4582120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4582672;
    /* @4582124 constant */
    /* @4582128 constant */
    /* @4582132 load */
    /* @4582140 constant */
    /* @4582144 add */
    /* @4582148 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4582156 constant */
    /* @4582160 constant */
    /* @4582164 load */
    /* @4582172 constant */
    /* @4582176 add */
    /* @4582180 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    GM_WRITE(vm, -1, "y", v31);
    /* @4582188 constant */
    /* @4582192 cast */
    /* @4582196 constant */
    /* @4582200 cast */
    /* @4582204 constant */
    /* @4582208 cast */
    /* @4582212 constant */
    /* @4582224 cast */
    /* @4582228 constant */
    /* @4582240 cast */
    /* @4582244 load */
    /* @4582252 load */
    /* @4582260 constant */
    /* @4582264 cast */
    /* @4582268 constant */
    /* @4582272 cast */
    /* @4582276 call */
    GM_SITE(vm, 415, 4582276);
    /* @4582284 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4582288 constant */
    /* @4582292 cast */
    /* @4582296 call */
    GM_SITE(vm, 415, 4582296);
    /* @4582304 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4582308 constant */
    /* @4582316 cast */
    /* @4582320 call */
    GM_SITE(vm, 415, 4582320);
    /* @4582328 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4582332 string */
    /* @4582340 cast */
    /* @4582344 load */
    /* @4582352 load */
    /* @4582360 constant */
    /* @4582364 add */
    /* @4582368 call */
    GM_SITE(vm, 415, 4582368);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4582376 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(796)));
    /* @4582380 string */
    /* @4582388 cast */
    /* @4582392 load */
    /* @4582400 constant */
    /* @4582404 add */
    /* @4582408 load */
    /* @4582416 constant */
    /* @4582420 add */
    /* @4582424 call */
    GM_SITE(vm, 415, 4582424);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4582432 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(797)));
    /* @4582436 constant */
    /* @4582440 cast */
    /* @4582444 constant */
    /* @4582448 cast */
    /* @4582452 constant */
    /* @4582456 cast */
    /* @4582460 constant */
    /* @4582472 cast */
    /* @4582476 constant */
    /* @4582488 cast */
    /* @4582492 load */
    /* @4582500 constant */
    /* @4582504 add */
    /* @4582508 load */
    /* @4582516 constant */
    /* @4582520 add */
    /* @4582524 constant */
    /* @4582528 cast */
    /* @4582532 constant */
    /* @4582536 cast */
    /* @4582540 call */
    GM_SITE(vm, 415, 4582540);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4582548 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4582552 load */
    /* @4582560 constant */
    /* @4582564 cmp */
    /* @4582568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4582672;
    /* @4582572 constant */
    /* @4582576 cast */
    /* @4582580 constant */
    /* @4582584 cast */
    /* @4582588 constant */
    /* @4582592 cast */
    /* @4582596 constant */
    /* @4582608 cast */
    /* @4582612 constant */
    /* @4582624 cast */
    /* @4582628 load */
    /* @4582636 load */
    /* @4582644 constant */
    /* @4582648 cast */
    /* @4582652 constant */
    /* @4582656 cast */
    /* @4582660 call */
    GM_SITE(vm, 415, 4582660);
    /* @4582668 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4582672: ;
    /* @4582672 load */
    /* @4582680 constant */
    /* @4582684 cmp */
    /* @4582688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4583240;
    /* @4582692 constant */
    /* @4582696 constant */
    /* @4582700 load */
    /* @4582708 constant */
    /* @4582712 add */
    /* @4582716 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4582724 constant */
    /* @4582728 constant */
    /* @4582732 load */
    /* @4582740 constant */
    /* @4582744 add */
    /* @4582748 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    GM_WRITE(vm, -1, "y", v38);
    /* @4582756 constant */
    /* @4582760 cast */
    /* @4582764 constant */
    /* @4582768 cast */
    /* @4582772 constant */
    /* @4582776 cast */
    /* @4582780 constant */
    /* @4582792 cast */
    /* @4582796 constant */
    /* @4582808 cast */
    /* @4582812 load */
    /* @4582820 load */
    /* @4582828 constant */
    /* @4582832 cast */
    /* @4582836 constant */
    /* @4582840 cast */
    /* @4582844 call */
    GM_SITE(vm, 415, 4582844);
    /* @4582852 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4582856 constant */
    /* @4582860 cast */
    /* @4582864 call */
    GM_SITE(vm, 415, 4582864);
    /* @4582872 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4582876 constant */
    /* @4582884 cast */
    /* @4582888 call */
    GM_SITE(vm, 415, 4582888);
    /* @4582896 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4582900 string */
    /* @4582908 cast */
    /* @4582912 load */
    /* @4582920 load */
    /* @4582928 constant */
    /* @4582932 add */
    /* @4582936 call */
    GM_SITE(vm, 415, 4582936);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4582944 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(796)));
    /* @4582948 string */
    /* @4582956 cast */
    /* @4582960 load */
    /* @4582968 constant */
    /* @4582972 add */
    /* @4582976 load */
    /* @4582984 constant */
    /* @4582988 add */
    /* @4582992 call */
    GM_SITE(vm, 415, 4582992);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4583000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(797)));
    /* @4583004 constant */
    /* @4583008 cast */
    /* @4583012 constant */
    /* @4583016 cast */
    /* @4583020 constant */
    /* @4583024 cast */
    /* @4583028 constant */
    /* @4583040 cast */
    /* @4583044 constant */
    /* @4583056 cast */
    /* @4583060 load */
    /* @4583068 constant */
    /* @4583072 add */
    /* @4583076 load */
    /* @4583084 constant */
    /* @4583088 add */
    /* @4583092 constant */
    /* @4583096 cast */
    /* @4583100 constant */
    /* @4583104 cast */
    /* @4583108 call */
    GM_SITE(vm, 415, 4583108);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4583116 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4583120 load */
    /* @4583128 constant */
    /* @4583132 cmp */
    /* @4583136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(1)))) goto L_4583240;
    /* @4583140 constant */
    /* @4583144 cast */
    /* @4583148 constant */
    /* @4583152 cast */
    /* @4583156 constant */
    /* @4583160 cast */
    /* @4583164 constant */
    /* @4583176 cast */
    /* @4583180 constant */
    /* @4583192 cast */
    /* @4583196 load */
    /* @4583204 load */
    /* @4583212 constant */
    /* @4583216 cast */
    /* @4583220 constant */
    /* @4583224 cast */
    /* @4583228 call */
    GM_SITE(vm, 415, 4583228);
    /* @4583236 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4583240: ;
    return;
}
