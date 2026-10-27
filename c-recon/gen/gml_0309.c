/* generated from CODE 309 (gml_Object_obj_sword_Create_0), source start 4163572, end 4163832. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0309(GmVM* vm) {
    Val v1;
    Val v2;
    Val loc_i;
    /* @4163572 constant */
    /* @4163576 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4163584 constant */
    /* @4163588 cast */
    /* @4163592 call */
    GM_SITE(vm, 309, 4163592);
    /* @4163600 cast */
    /* @4163604 not */
    /* @4163608 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46))));
    if (!TRUTH(v1)) goto L_4163732;
    /* @4163612 constant */
    /* @4163616 cast */
    /* @4163620 load */
    /* @4163628 load */
    /* @4163636 constant */
    /* @4163640 add */
    /* @4163644 call */
    GM_SITE(vm, 309, 4163644);
    v2 = GM_ADD(GM_READ(vm, 0, "x"), VAL(5));
    /* @4163652 store_local */
    loc_i = GM_CALL(vm, "instance_create", 3, v2, GM_READ(vm, 0, "y"), VAL(46));
    /* @4163660 load */
    /* @4163668 constant */
    /* @4163672 sub */
    /* @4163676 load_local */
    /* @4163684 cast */
    /* @4163688 store */
    GM_WRITE(vm, TO_INT(loc_i), "image_angle", (GM_READ(vm, -1, "image_angle") - VAL(90)));
    /* @4163696 load */
    /* @4163704 constant */
    /* @4163708 sub */
    /* @4163712 load_local */
    /* @4163720 cast */
    /* @4163724 store */
    GM_WRITE(vm, TO_INT(loc_i), "image_angle", (GM_READ(vm, -1, "image_angle") - VAL(90)));
    L_4163732: ;
    /* @4163732 constant */
    /* @4163736 constant */
    /* @4163740 constant */
    /* @4163744 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(7));
    /* @4163752 load */
    /* @4163760 constant */
    /* @4163764 cmp */
    /* @4163768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4163776;
    /* @4163772 b */
    goto L_4163832;
    L_4163776: ;
    /* @4163776 load */
    /* @4163784 constant */
    /* @4163788 cmp */
    /* @4163792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4163832;
    /* @4163796 constant */
    /* @4163800 cast */
    /* @4163804 constant */
    /* @4163808 cast */
    /* @4163812 load */
    /* @4163820 call */
    GM_SITE(vm, 309, 4163820);
    /* @4163828 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ(vm, -5, "swordsound"), VAL(0), VAL(0)));
    L_4163832: ;
    return;
}
