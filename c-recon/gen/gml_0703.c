/* generated from CODE 703 (gml_Object_obj_tease_Draw_0), source start 5021040, end 5022308. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0703(GmVM* vm) {
    /* @5021040 load */
    /* @5021048 constant */
    /* @5021052 cmp */
    /* @5021056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_5022308;
    /* @5021060 load */
    /* @5021068 constant */
    /* @5021072 cmp */
    /* @5021076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5021236;
    /* @5021080 constant */
    /* @5021084 load */
    /* @5021092 cast */
    /* @5021096 load */
    /* @5021104 constant */
    /* @5021108 sub */
    /* @5021112 constant */
    /* @5021116 load */
    /* @5021124 cast */
    /* @5021128 load */
    /* @5021136 constant */
    /* @5021140 sub */
    /* @5021144 constant */
    /* @5021148 cast */
    /* @5021152 constant */
    /* @5021156 cast */
    /* @5021160 call */
    GM_SITE(vm, 703, 5021160);
    /* @5021168 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(162), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @5021172 constant */
    /* @5021176 load */
    /* @5021184 cast */
    /* @5021188 load */
    /* @5021196 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5021204 constant */
    /* @5021208 load */
    /* @5021216 cast */
    /* @5021220 load */
    /* @5021228 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5021236: ;
    /* @5021236 load */
    /* @5021244 constant */
    /* @5021248 cmp */
    /* @5021252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5021452;
    /* @5021256 constant */
    /* @5021260 cast */
    /* @5021264 constant */
    /* @5021268 cast */
    /* @5021272 constant */
    /* @5021276 cast */
    /* @5021280 constant */
    /* @5021292 cast */
    /* @5021296 constant */
    /* @5021308 cast */
    /* @5021312 constant */
    /* @5021316 load */
    /* @5021324 cast */
    /* @5021328 load */
    /* @5021336 constant */
    /* @5021340 load */
    /* @5021348 cast */
    /* @5021352 load */
    /* @5021360 constant */
    /* @5021364 cast */
    /* @5021368 constant */
    /* @5021372 cast */
    /* @5021376 call */
    GM_SITE(vm, 703, 5021376);
    /* @5021384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(162), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @5021388 constant */
    /* @5021392 load */
    /* @5021400 cast */
    /* @5021404 load */
    /* @5021412 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5021420 constant */
    /* @5021424 load */
    /* @5021432 cast */
    /* @5021436 load */
    /* @5021444 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5021452: ;
    /* @5021452 load */
    /* @5021460 constant */
    /* @5021464 cmp */
    /* @5021468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5021676;
    /* @5021472 constant */
    /* @5021476 cast */
    /* @5021480 constant */
    /* @5021484 cast */
    /* @5021488 constant */
    /* @5021492 cast */
    /* @5021496 constant */
    /* @5021508 cast */
    /* @5021512 constant */
    /* @5021524 cast */
    /* @5021528 constant */
    /* @5021532 load */
    /* @5021540 cast */
    /* @5021544 load */
    /* @5021552 constant */
    /* @5021556 load */
    /* @5021564 cast */
    /* @5021568 load */
    /* @5021576 constant */
    /* @5021580 sub */
    /* @5021584 constant */
    /* @5021588 cast */
    /* @5021592 constant */
    /* @5021596 cast */
    /* @5021600 call */
    GM_SITE(vm, 703, 5021600);
    /* @5021608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(162), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(35)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5021612 constant */
    /* @5021616 load */
    /* @5021624 cast */
    /* @5021628 load */
    /* @5021636 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5021644 constant */
    /* @5021648 load */
    /* @5021656 cast */
    /* @5021660 load */
    /* @5021668 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5021676: ;
    /* @5021676 load */
    /* @5021684 constant */
    /* @5021688 cmp */
    /* @5021692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5021900;
    /* @5021696 constant */
    /* @5021700 cast */
    /* @5021704 constant */
    /* @5021708 cast */
    /* @5021712 constant */
    /* @5021716 cast */
    /* @5021720 constant */
    /* @5021732 cast */
    /* @5021736 constant */
    /* @5021748 cast */
    /* @5021752 constant */
    /* @5021756 load */
    /* @5021764 cast */
    /* @5021768 load */
    /* @5021776 constant */
    /* @5021780 load */
    /* @5021788 cast */
    /* @5021792 load */
    /* @5021800 constant */
    /* @5021804 sub */
    /* @5021808 constant */
    /* @5021812 cast */
    /* @5021816 constant */
    /* @5021820 cast */
    /* @5021824 call */
    GM_SITE(vm, 703, 5021824);
    /* @5021832 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(162), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(35)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5021836 constant */
    /* @5021840 load */
    /* @5021848 cast */
    /* @5021852 load */
    /* @5021860 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5021868 constant */
    /* @5021872 load */
    /* @5021880 cast */
    /* @5021884 load */
    /* @5021892 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5021900: ;
    /* @5021900 load */
    /* @5021908 constant */
    /* @5021912 cmp */
    /* @5021916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5022076;
    /* @5021920 constant */
    /* @5021924 load */
    /* @5021932 cast */
    /* @5021936 load */
    /* @5021944 constant */
    /* @5021948 sub */
    /* @5021952 constant */
    /* @5021956 load */
    /* @5021964 cast */
    /* @5021968 load */
    /* @5021976 constant */
    /* @5021980 sub */
    /* @5021984 constant */
    /* @5021988 cast */
    /* @5021992 constant */
    /* @5021996 cast */
    /* @5022000 call */
    GM_SITE(vm, 703, 5022000);
    /* @5022008 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(162), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @5022012 constant */
    /* @5022016 load */
    /* @5022024 cast */
    /* @5022028 load */
    /* @5022036 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5022044 constant */
    /* @5022048 load */
    /* @5022056 cast */
    /* @5022060 load */
    /* @5022068 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5022076: ;
    /* @5022076 load */
    /* @5022084 constant */
    /* @5022088 cmp */
    /* @5022092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5022308;
    /* @5022096 constant */
    /* @5022100 cast */
    /* @5022104 constant */
    /* @5022108 cast */
    /* @5022112 constant */
    /* @5022116 cast */
    /* @5022120 constant */
    /* @5022132 cast */
    /* @5022136 constant */
    /* @5022148 cast */
    /* @5022152 constant */
    /* @5022156 load */
    /* @5022164 cast */
    /* @5022168 load */
    /* @5022176 constant */
    /* @5022180 sub */
    /* @5022184 constant */
    /* @5022188 load */
    /* @5022196 cast */
    /* @5022200 load */
    /* @5022208 constant */
    /* @5022212 sub */
    /* @5022216 constant */
    /* @5022220 cast */
    /* @5022224 constant */
    /* @5022228 cast */
    /* @5022232 call */
    GM_SITE(vm, 703, 5022232);
    /* @5022240 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(162), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(1)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10)), VAL(1.04), VAL(1.04), VAL(0), VAL(-1), VAL(1)));
    /* @5022244 constant */
    /* @5022248 load */
    /* @5022256 cast */
    /* @5022260 load */
    /* @5022268 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5022276 constant */
    /* @5022280 load */
    /* @5022288 cast */
    /* @5022292 load */
    /* @5022300 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5022308: ;
    return;
}
