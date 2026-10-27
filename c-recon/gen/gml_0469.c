/* generated from CODE 469 (gml_Object_obj_volume_Draw_0), source start 4644664, end 4646480. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0469(GmVM* vm) {
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
    /* @4644664 load */
    /* @4644672 constant */
    /* @4644676 cmp */
    /* @4644680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4644924;
    /* @4644684 constant */
    /* @4644688 cast */
    /* @4644692 constant */
    /* @4644696 cast */
    /* @4644700 constant */
    /* @4644704 cast */
    /* @4644708 constant */
    /* @4644712 cast */
    /* @4644716 constant */
    /* @4644720 cast */
    /* @4644724 load */
    /* @4644732 load */
    /* @4644740 constant */
    /* @4644744 cast */
    /* @4644748 constant */
    /* @4644752 cast */
    /* @4644756 call */
    GM_SITE(vm, 469, 4644756);
    /* @4644764 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4644768 constant */
    /* @4644772 cast */
    /* @4644776 call */
    GM_SITE(vm, 469, 4644776);
    /* @4644784 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4644788 load */
    /* @4644796 constant */
    /* @4644800 cmp */
    /* @4644804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4644856;
    /* @4644808 string */
    /* @4644816 cast */
    /* @4644820 load */
    /* @4644828 load */
    /* @4644836 constant */
    /* @4644840 add */
    /* @4644844 call */
    GM_SITE(vm, 469, 4644844);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    /* @4644852 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4644856: ;
    /* @4644856 load */
    /* @4644864 constant */
    /* @4644868 cmp */
    /* @4644872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4644924;
    /* @4644876 string */
    /* @4644884 cast */
    /* @4644888 load */
    /* @4644896 load */
    /* @4644904 constant */
    /* @4644908 add */
    /* @4644912 call */
    GM_SITE(vm, 469, 4644912);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4644920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4644924: ;
    /* @4644924 load */
    /* @4644932 constant */
    /* @4644936 cmp */
    /* @4644940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4645264;
    /* @4644944 constant */
    /* @4644948 constant */
    /* @4644952 load */
    /* @4644960 constant */
    /* @4644964 add */
    /* @4644968 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(82));
    GM_WRITE(vm, -1, "x", v3);
    /* @4644976 constant */
    /* @4644980 constant */
    /* @4644984 load */
    /* @4644992 constant */
    /* @4644996 add */
    /* @4645000 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(80));
    GM_WRITE(vm, -1, "y", v4);
    /* @4645008 constant */
    /* @4645012 cast */
    /* @4645016 constant */
    /* @4645020 cast */
    /* @4645024 constant */
    /* @4645028 cast */
    /* @4645032 constant */
    /* @4645044 cast */
    /* @4645048 constant */
    /* @4645060 cast */
    /* @4645064 load */
    /* @4645072 load */
    /* @4645080 constant */
    /* @4645084 cast */
    /* @4645088 constant */
    /* @4645092 cast */
    /* @4645096 call */
    GM_SITE(vm, 469, 4645096);
    /* @4645104 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4645108 constant */
    /* @4645112 cast */
    /* @4645116 call */
    GM_SITE(vm, 469, 4645116);
    /* @4645124 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4645128 load */
    /* @4645136 constant */
    /* @4645140 cmp */
    /* @4645144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4645196;
    /* @4645148 string */
    /* @4645156 cast */
    /* @4645160 load */
    /* @4645168 load */
    /* @4645176 constant */
    /* @4645180 add */
    /* @4645184 call */
    GM_SITE(vm, 469, 4645184);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4645192 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4645196: ;
    /* @4645196 load */
    /* @4645204 constant */
    /* @4645208 cmp */
    /* @4645212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4645264;
    /* @4645216 string */
    /* @4645224 cast */
    /* @4645228 load */
    /* @4645236 load */
    /* @4645244 constant */
    /* @4645248 add */
    /* @4645252 call */
    GM_SITE(vm, 469, 4645252);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4645260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4645264: ;
    /* @4645264 load */
    /* @4645272 constant */
    /* @4645276 cmp */
    /* @4645280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4645548;
    /* @4645284 constant */
    /* @4645288 constant */
    /* @4645292 load */
    /* @4645300 constant */
    /* @4645304 add */
    /* @4645308 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(190));
    GM_WRITE(vm, -1, "x", v7);
    /* @4645316 constant */
    /* @4645320 constant */
    /* @4645324 load */
    /* @4645332 constant */
    /* @4645336 add */
    /* @4645340 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "y", v8);
    /* @4645348 load */
    /* @4645356 load */
    /* @4645364 constant */
    /* @4645368 cast */
    /* @4645372 constant */
    /* @4645376 cast */
    /* @4645380 call */
    GM_SITE(vm, 469, 4645380);
    /* @4645388 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4645392 constant */
    /* @4645396 cast */
    /* @4645400 call */
    GM_SITE(vm, 469, 4645400);
    /* @4645408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4645412 load */
    /* @4645420 constant */
    /* @4645424 cmp */
    /* @4645428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4645480;
    /* @4645432 string */
    /* @4645440 cast */
    /* @4645444 load */
    /* @4645452 load */
    /* @4645460 constant */
    /* @4645464 add */
    /* @4645468 call */
    GM_SITE(vm, 469, 4645468);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    /* @4645476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v9, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4645480: ;
    /* @4645480 load */
    /* @4645488 constant */
    /* @4645492 cmp */
    /* @4645496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4645548;
    /* @4645500 string */
    /* @4645508 cast */
    /* @4645512 load */
    /* @4645520 load */
    /* @4645528 constant */
    /* @4645532 add */
    /* @4645536 call */
    GM_SITE(vm, 469, 4645536);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4645544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4645548: ;
    /* @4645548 load */
    /* @4645556 constant */
    /* @4645560 cmp */
    /* @4645564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4645832;
    /* @4645568 constant */
    /* @4645572 constant */
    /* @4645576 load */
    /* @4645584 constant */
    /* @4645588 add */
    /* @4645592 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(190));
    GM_WRITE(vm, -1, "x", v11);
    /* @4645600 constant */
    /* @4645604 constant */
    /* @4645608 load */
    /* @4645616 constant */
    /* @4645620 add */
    /* @4645624 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "y", v12);
    /* @4645632 load */
    /* @4645640 load */
    /* @4645648 constant */
    /* @4645652 cast */
    /* @4645656 constant */
    /* @4645660 cast */
    /* @4645664 call */
    GM_SITE(vm, 469, 4645664);
    /* @4645672 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4645676 constant */
    /* @4645680 cast */
    /* @4645684 call */
    GM_SITE(vm, 469, 4645684);
    /* @4645692 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4645696 load */
    /* @4645704 constant */
    /* @4645708 cmp */
    /* @4645712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4645764;
    /* @4645716 string */
    /* @4645724 cast */
    /* @4645728 load */
    /* @4645736 load */
    /* @4645744 constant */
    /* @4645748 add */
    /* @4645752 call */
    GM_SITE(vm, 469, 4645752);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    /* @4645760 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4645764: ;
    /* @4645764 load */
    /* @4645772 constant */
    /* @4645776 cmp */
    /* @4645780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4645832;
    /* @4645784 string */
    /* @4645792 cast */
    /* @4645796 load */
    /* @4645804 load */
    /* @4645812 constant */
    /* @4645816 add */
    /* @4645820 call */
    GM_SITE(vm, 469, 4645820);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4645828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v14, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4645832: ;
    /* @4645832 load */
    /* @4645840 constant */
    /* @4645844 cmp */
    /* @4645848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4646156;
    /* @4645852 constant */
    /* @4645856 constant */
    /* @4645860 load */
    /* @4645868 constant */
    /* @4645872 add */
    /* @4645876 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(100));
    GM_WRITE(vm, -1, "x", v15);
    /* @4645884 constant */
    /* @4645888 constant */
    /* @4645892 load */
    /* @4645900 constant */
    /* @4645904 add */
    /* @4645908 store */
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(60));
    GM_WRITE(vm, -1, "y", v16);
    /* @4645916 constant */
    /* @4645920 cast */
    /* @4645924 constant */
    /* @4645928 cast */
    /* @4645932 constant */
    /* @4645936 cast */
    /* @4645940 constant */
    /* @4645944 cast */
    /* @4645948 constant */
    /* @4645952 cast */
    /* @4645956 load */
    /* @4645964 load */
    /* @4645972 constant */
    /* @4645976 cast */
    /* @4645980 constant */
    /* @4645984 cast */
    /* @4645988 call */
    GM_SITE(vm, 469, 4645988);
    /* @4645996 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4646000 constant */
    /* @4646004 cast */
    /* @4646008 call */
    GM_SITE(vm, 469, 4646008);
    /* @4646016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4646020 load */
    /* @4646028 constant */
    /* @4646032 cmp */
    /* @4646036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4646088;
    /* @4646040 string */
    /* @4646048 cast */
    /* @4646052 load */
    /* @4646060 load */
    /* @4646068 constant */
    /* @4646072 add */
    /* @4646076 call */
    GM_SITE(vm, 469, 4646076);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    /* @4646084 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4646088: ;
    /* @4646088 load */
    /* @4646096 constant */
    /* @4646100 cmp */
    /* @4646104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4646156;
    /* @4646108 string */
    /* @4646116 cast */
    /* @4646120 load */
    /* @4646128 load */
    /* @4646136 constant */
    /* @4646140 add */
    /* @4646144 call */
    GM_SITE(vm, 469, 4646144);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4646152 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4646156: ;
    /* @4646156 load */
    /* @4646164 constant */
    /* @4646168 cmp */
    /* @4646172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4646480;
    /* @4646176 constant */
    /* @4646180 constant */
    /* @4646184 load */
    /* @4646192 constant */
    /* @4646196 add */
    /* @4646200 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(100));
    GM_WRITE(vm, -1, "x", v19);
    /* @4646208 constant */
    /* @4646212 constant */
    /* @4646216 load */
    /* @4646224 constant */
    /* @4646228 add */
    /* @4646232 store */
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(60));
    GM_WRITE(vm, -1, "y", v20);
    /* @4646240 constant */
    /* @4646244 cast */
    /* @4646248 constant */
    /* @4646252 cast */
    /* @4646256 constant */
    /* @4646260 cast */
    /* @4646264 constant */
    /* @4646268 cast */
    /* @4646272 constant */
    /* @4646276 cast */
    /* @4646280 load */
    /* @4646288 load */
    /* @4646296 constant */
    /* @4646300 cast */
    /* @4646304 constant */
    /* @4646308 cast */
    /* @4646312 call */
    GM_SITE(vm, 469, 4646312);
    /* @4646320 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4646324 constant */
    /* @4646328 cast */
    /* @4646332 call */
    GM_SITE(vm, 469, 4646332);
    /* @4646340 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4646344 load */
    /* @4646352 constant */
    /* @4646356 cmp */
    /* @4646360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4646412;
    /* @4646364 string */
    /* @4646372 cast */
    /* @4646376 load */
    /* @4646384 load */
    /* @4646392 constant */
    /* @4646396 add */
    /* @4646400 call */
    GM_SITE(vm, 469, 4646400);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(3));
    /* @4646408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, GM_READ(vm, -1, "y"), STR_REF(857)));
    L_4646412: ;
    /* @4646412 load */
    /* @4646420 constant */
    /* @4646424 cmp */
    /* @4646428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4646480;
    /* @4646432 string */
    /* @4646440 cast */
    /* @4646444 load */
    /* @4646452 load */
    /* @4646460 constant */
    /* @4646464 add */
    /* @4646468 call */
    GM_SITE(vm, 469, 4646468);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4646476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v22, GM_READ(vm, -1, "y"), STR_REF(858)));
    L_4646480: ;
    return;
}
