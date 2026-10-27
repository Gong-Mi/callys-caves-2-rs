/* generated from CODE 464 (gml_Object_obj_weaponname_Draw_0), source start 4643460, end 4644344. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0464(GmVM* vm) {
    /* @4643460 constant */
    /* @4643464 cast */
    /* @4643468 call */
    GM_SITE(vm, 464, 4643468);
    /* @4643476 popz */
    (void)(GM_CALL(vm, "draw_set_alpha", 1, VAL(1)));
    /* @4643480 constant */
    /* @4643488 cast */
    /* @4643492 call */
    GM_SITE(vm, 464, 4643492);
    /* @4643500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4643504 load */
    /* @4643512 constant */
    /* @4643516 cmp */
    /* @4643520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4643644;
    /* @4643524 constant */
    /* @4643528 cast */
    /* @4643532 call */
    GM_SITE(vm, 464, 4643532);
    /* @4643540 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4643544 load */
    /* @4643552 constant */
    /* @4643560 cast */
    /* @4643564 constant */
    /* @4643572 cast */
    /* @4643576 constant */
    /* @4643584 cast */
    /* @4643588 constant */
    /* @4643596 cast */
    /* @4643600 load */
    /* @4643608 load */
    /* @4643616 constant */
    /* @4643620 sub */
    /* @4643624 load */
    /* @4643632 call */
    GM_SITE(vm, 464, 4643632);
    /* @4643640 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4643644: ;
    /* @4643644 load */
    /* @4643652 constant */
    /* @4643656 cmp */
    /* @4643660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4643784;
    /* @4643664 constant */
    /* @4643668 cast */
    /* @4643672 call */
    GM_SITE(vm, 464, 4643672);
    /* @4643680 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4643684 load */
    /* @4643692 constant */
    /* @4643700 cast */
    /* @4643704 constant */
    /* @4643712 cast */
    /* @4643716 constant */
    /* @4643724 cast */
    /* @4643728 constant */
    /* @4643736 cast */
    /* @4643740 load */
    /* @4643748 load */
    /* @4643756 constant */
    /* @4643760 sub */
    /* @4643764 load */
    /* @4643772 call */
    GM_SITE(vm, 464, 4643772);
    /* @4643780 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4643784: ;
    /* @4643784 load */
    /* @4643792 constant */
    /* @4643796 cmp */
    /* @4643800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4643924;
    /* @4643804 constant */
    /* @4643808 cast */
    /* @4643812 call */
    GM_SITE(vm, 464, 4643812);
    /* @4643820 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4643824 load */
    /* @4643832 constant */
    /* @4643840 cast */
    /* @4643844 constant */
    /* @4643852 cast */
    /* @4643856 constant */
    /* @4643864 cast */
    /* @4643868 constant */
    /* @4643876 cast */
    /* @4643880 load */
    /* @4643888 load */
    /* @4643896 constant */
    /* @4643900 sub */
    /* @4643904 load */
    /* @4643912 call */
    GM_SITE(vm, 464, 4643912);
    /* @4643920 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4643924: ;
    /* @4643924 load */
    /* @4643932 constant */
    /* @4643936 cmp */
    /* @4643940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4644064;
    /* @4643944 constant */
    /* @4643948 cast */
    /* @4643952 call */
    GM_SITE(vm, 464, 4643952);
    /* @4643960 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4643964 load */
    /* @4643972 constant */
    /* @4643980 cast */
    /* @4643984 constant */
    /* @4643992 cast */
    /* @4643996 constant */
    /* @4644004 cast */
    /* @4644008 constant */
    /* @4644016 cast */
    /* @4644020 load */
    /* @4644028 load */
    /* @4644036 constant */
    /* @4644040 sub */
    /* @4644044 load */
    /* @4644052 call */
    GM_SITE(vm, 464, 4644052);
    /* @4644060 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4644064: ;
    /* @4644064 load */
    /* @4644072 constant */
    /* @4644076 cmp */
    /* @4644080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4644204;
    /* @4644084 constant */
    /* @4644088 cast */
    /* @4644092 call */
    GM_SITE(vm, 464, 4644092);
    /* @4644100 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4644104 load */
    /* @4644112 constant */
    /* @4644120 cast */
    /* @4644124 constant */
    /* @4644132 cast */
    /* @4644136 constant */
    /* @4644144 cast */
    /* @4644148 constant */
    /* @4644156 cast */
    /* @4644160 load */
    /* @4644168 load */
    /* @4644176 constant */
    /* @4644180 sub */
    /* @4644184 load */
    /* @4644192 call */
    GM_SITE(vm, 464, 4644192);
    /* @4644200 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4644204: ;
    /* @4644204 load */
    /* @4644212 constant */
    /* @4644216 cmp */
    /* @4644220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4644344;
    /* @4644224 constant */
    /* @4644228 cast */
    /* @4644232 call */
    GM_SITE(vm, 464, 4644232);
    /* @4644240 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4644244 load */
    /* @4644252 constant */
    /* @4644260 cast */
    /* @4644264 constant */
    /* @4644272 cast */
    /* @4644276 constant */
    /* @4644284 cast */
    /* @4644288 constant */
    /* @4644296 cast */
    /* @4644300 load */
    /* @4644308 load */
    /* @4644316 constant */
    /* @4644320 sub */
    /* @4644324 load */
    /* @4644332 call */
    GM_SITE(vm, 464, 4644332);
    /* @4644340 popz */
    (void)(GM_CALL(vm, "draw_text_color", 8, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), GM_READ(vm, -1, "damage"), VAL(16777215), VAL(16777215), VAL(16777215), VAL(16777215), GM_READ(vm, -1, "alpha")));
    L_4644344: ;
    return;
}
