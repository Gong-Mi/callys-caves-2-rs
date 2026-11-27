/* generated from CODE 473 (gml_Object_obj_volumemusic_Draw_0), source start 4649512, end 4651328. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0473(GmVM* vm) {
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
    /* @4649512 load */
    /* @4649520 constant */
    /* @4649524 cmp */
    /* @4649528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4649772;
    /* @4649532 constant */
    /* @4649536 cast */
    /* @4649540 constant */
    /* @4649544 cast */
    /* @4649548 constant */
    /* @4649552 cast */
    /* @4649556 constant */
    /* @4649560 cast */
    /* @4649564 constant */
    /* @4649568 cast */
    /* @4649572 load */
    /* @4649580 load */
    /* @4649588 constant */
    /* @4649592 cast */
    /* @4649596 constant */
    /* @4649600 cast */
    /* @4649604 call */
    GM_SITE(vm, 473, 4649604);
    /* @4649612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4649616 constant */
    /* @4649620 cast */
    /* @4649624 call */
    GM_SITE(vm, 473, 4649624);
    /* @4649632 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4649636 load */
    /* @4649644 constant */
    /* @4649648 cmp */
    /* @4649652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4649704;
    /* @4649656 string */
    /* @4649664 cast */
    /* @4649668 load */
    /* @4649676 load */
    /* @4649684 constant */
    /* @4649688 add */
    /* @4649692 call */
    GM_SITE(vm, 473, 4649692);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4649700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4649704: ;
    /* @4649704 load */
    /* @4649712 constant */
    /* @4649716 cmp */
    /* @4649720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4649772;
    /* @4649724 string */
    /* @4649732 cast */
    /* @4649736 load */
    /* @4649744 load */
    /* @4649752 constant */
    /* @4649756 add */
    /* @4649760 call */
    GM_SITE(vm, 473, 4649760);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4649768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4649772: ;
    /* @4649772 load */
    /* @4649780 constant */
    /* @4649784 cmp */
    /* @4649788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4650112;
    /* @4649792 constant */
    /* @4649796 constant */
    /* @4649800 load */
    /* @4649808 constant */
    /* @4649812 add */
    /* @4649816 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(82));
    GM_WRITE(vm, -1, "x", v3);
    /* @4649824 constant */
    /* @4649828 constant */
    /* @4649832 load */
    /* @4649840 constant */
    /* @4649844 add */
    /* @4649848 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(115));
    GM_WRITE(vm, -1, "y", v4);
    /* @4649856 constant */
    /* @4649860 cast */
    /* @4649864 constant */
    /* @4649868 cast */
    /* @4649872 constant */
    /* @4649876 cast */
    /* @4649880 constant */
    /* @4649892 cast */
    /* @4649896 constant */
    /* @4649908 cast */
    /* @4649912 load */
    /* @4649920 load */
    /* @4649928 constant */
    /* @4649932 cast */
    /* @4649936 constant */
    /* @4649940 cast */
    /* @4649944 call */
    GM_SITE(vm, 473, 4649944);
    /* @4649952 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4649956 constant */
    /* @4649960 cast */
    /* @4649964 call */
    GM_SITE(vm, 473, 4649964);
    /* @4649972 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4649976 load */
    /* @4649984 constant */
    /* @4649988 cmp */
    /* @4649992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4650044;
    /* @4649996 string */
    /* @4650004 cast */
    /* @4650008 load */
    /* @4650016 load */
    /* @4650024 constant */
    /* @4650028 add */
    /* @4650032 call */
    GM_SITE(vm, 473, 4650032);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4650040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4650044: ;
    /* @4650044 load */
    /* @4650052 constant */
    /* @4650056 cmp */
    /* @4650060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4650112;
    /* @4650064 string */
    /* @4650072 cast */
    /* @4650076 load */
    /* @4650084 load */
    /* @4650092 constant */
    /* @4650096 add */
    /* @4650100 call */
    GM_SITE(vm, 473, 4650100);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4650108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4650112: ;
    /* @4650112 load */
    /* @4650120 constant */
    /* @4650124 cmp */
    /* @4650128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4650396;
    /* @4650132 constant */
    /* @4650136 constant */
    /* @4650140 load */
    /* @4650148 constant */
    /* @4650152 add */
    /* @4650156 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(190));
    GM_WRITE(vm, -1, "x", v7);
    /* @4650164 constant */
    /* @4650168 constant */
    /* @4650172 load */
    /* @4650180 constant */
    /* @4650184 add */
    /* @4650188 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(115));
    GM_WRITE(vm, -1, "y", v8);
    /* @4650196 load */
    /* @4650204 load */
    /* @4650212 constant */
    /* @4650216 cast */
    /* @4650220 constant */
    /* @4650224 cast */
    /* @4650228 call */
    GM_SITE(vm, 473, 4650228);
    /* @4650236 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4650240 constant */
    /* @4650244 cast */
    /* @4650248 call */
    GM_SITE(vm, 473, 4650248);
    /* @4650256 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4650260 load */
    /* @4650268 constant */
    /* @4650272 cmp */
    /* @4650276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4650328;
    /* @4650280 string */
    /* @4650288 cast */
    /* @4650292 load */
    /* @4650300 load */
    /* @4650308 constant */
    /* @4650312 add */
    /* @4650316 call */
    GM_SITE(vm, 473, 4650316);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4650324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v9, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4650328: ;
    /* @4650328 load */
    /* @4650336 constant */
    /* @4650340 cmp */
    /* @4650344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4650396;
    /* @4650348 string */
    /* @4650356 cast */
    /* @4650360 load */
    /* @4650368 load */
    /* @4650376 constant */
    /* @4650380 add */
    /* @4650384 call */
    GM_SITE(vm, 473, 4650384);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4650392 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4650396: ;
    /* @4650396 load */
    /* @4650404 constant */
    /* @4650408 cmp */
    /* @4650412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4650680;
    /* @4650416 constant */
    /* @4650420 constant */
    /* @4650424 load */
    /* @4650432 constant */
    /* @4650436 add */
    /* @4650440 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(190));
    GM_WRITE(vm, -1, "x", v11);
    /* @4650448 constant */
    /* @4650452 constant */
    /* @4650456 load */
    /* @4650464 constant */
    /* @4650468 add */
    /* @4650472 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(115));
    GM_WRITE(vm, -1, "y", v12);
    /* @4650480 load */
    /* @4650488 load */
    /* @4650496 constant */
    /* @4650500 cast */
    /* @4650504 constant */
    /* @4650508 cast */
    /* @4650512 call */
    GM_SITE(vm, 473, 4650512);
    /* @4650520 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4650524 constant */
    /* @4650528 cast */
    /* @4650532 call */
    GM_SITE(vm, 473, 4650532);
    /* @4650540 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4650544 load */
    /* @4650552 constant */
    /* @4650556 cmp */
    /* @4650560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4650612;
    /* @4650564 string */
    /* @4650572 cast */
    /* @4650576 load */
    /* @4650584 load */
    /* @4650592 constant */
    /* @4650596 add */
    /* @4650600 call */
    GM_SITE(vm, 473, 4650600);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4650608 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4650612: ;
    /* @4650612 load */
    /* @4650620 constant */
    /* @4650624 cmp */
    /* @4650628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4650680;
    /* @4650632 string */
    /* @4650640 cast */
    /* @4650644 load */
    /* @4650652 load */
    /* @4650660 constant */
    /* @4650664 add */
    /* @4650668 call */
    GM_SITE(vm, 473, 4650668);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4650676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v14, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4650680: ;
    /* @4650680 load */
    /* @4650688 constant */
    /* @4650692 cmp */
    /* @4650696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4651004;
    /* @4650700 constant */
    /* @4650704 constant */
    /* @4650708 load */
    /* @4650716 constant */
    /* @4650720 add */
    /* @4650724 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(100));
    GM_WRITE(vm, -1, "x", v15);
    /* @4650732 constant */
    /* @4650736 constant */
    /* @4650740 load */
    /* @4650748 constant */
    /* @4650752 add */
    /* @4650756 store */
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(100));
    GM_WRITE(vm, -1, "y", v16);
    /* @4650764 constant */
    /* @4650768 cast */
    /* @4650772 constant */
    /* @4650776 cast */
    /* @4650780 constant */
    /* @4650784 cast */
    /* @4650788 constant */
    /* @4650792 cast */
    /* @4650796 constant */
    /* @4650800 cast */
    /* @4650804 load */
    /* @4650812 load */
    /* @4650820 constant */
    /* @4650824 cast */
    /* @4650828 constant */
    /* @4650832 cast */
    /* @4650836 call */
    GM_SITE(vm, 473, 4650836);
    /* @4650844 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4650848 constant */
    /* @4650852 cast */
    /* @4650856 call */
    GM_SITE(vm, 473, 4650856);
    /* @4650864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4650868 load */
    /* @4650876 constant */
    /* @4650880 cmp */
    /* @4650884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4650936;
    /* @4650888 string */
    /* @4650896 cast */
    /* @4650900 load */
    /* @4650908 load */
    /* @4650916 constant */
    /* @4650920 add */
    /* @4650924 call */
    GM_SITE(vm, 473, 4650924);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4650932 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4650936: ;
    /* @4650936 load */
    /* @4650944 constant */
    /* @4650948 cmp */
    /* @4650952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4651004;
    /* @4650956 string */
    /* @4650964 cast */
    /* @4650968 load */
    /* @4650976 load */
    /* @4650984 constant */
    /* @4650988 add */
    /* @4650992 call */
    GM_SITE(vm, 473, 4650992);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4651000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4651004: ;
    /* @4651004 load */
    /* @4651012 constant */
    /* @4651016 cmp */
    /* @4651020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4651328;
    /* @4651024 constant */
    /* @4651028 constant */
    /* @4651032 load */
    /* @4651040 constant */
    /* @4651044 add */
    /* @4651048 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(100));
    GM_WRITE(vm, -1, "x", v19);
    /* @4651056 constant */
    /* @4651060 constant */
    /* @4651064 load */
    /* @4651072 constant */
    /* @4651076 add */
    /* @4651080 store */
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(100));
    GM_WRITE(vm, -1, "y", v20);
    /* @4651088 constant */
    /* @4651092 cast */
    /* @4651096 constant */
    /* @4651100 cast */
    /* @4651104 constant */
    /* @4651108 cast */
    /* @4651112 constant */
    /* @4651116 cast */
    /* @4651120 constant */
    /* @4651124 cast */
    /* @4651128 load */
    /* @4651136 load */
    /* @4651144 constant */
    /* @4651148 cast */
    /* @4651152 constant */
    /* @4651156 cast */
    /* @4651160 call */
    GM_SITE(vm, 473, 4651160);
    /* @4651168 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4651172 constant */
    /* @4651176 cast */
    /* @4651180 call */
    GM_SITE(vm, 473, 4651180);
    /* @4651188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4651192 load */
    /* @4651200 constant */
    /* @4651204 cmp */
    /* @4651208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4651260;
    /* @4651212 string */
    /* @4651220 cast */
    /* @4651224 load */
    /* @4651232 load */
    /* @4651240 constant */
    /* @4651244 add */
    /* @4651248 call */
    GM_SITE(vm, 473, 4651248);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4651256 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, GM_READ(vm, -1, "y"), STR_REF(860)));
    L_4651260: ;
    /* @4651260 load */
    /* @4651268 constant */
    /* @4651272 cmp */
    /* @4651276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4651328;
    /* @4651280 string */
    /* @4651288 cast */
    /* @4651292 load */
    /* @4651300 load */
    /* @4651308 constant */
    /* @4651312 add */
    /* @4651316 call */
    GM_SITE(vm, 473, 4651316);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4651324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v22, GM_READ(vm, -1, "y"), STR_REF(861)));
    L_4651328: ;
    return;
}
