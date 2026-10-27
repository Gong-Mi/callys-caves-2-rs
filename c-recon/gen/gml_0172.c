/* generated from CODE 172 (gml_Object_obj_boss3_Destroy_0), source start 3994656, end 3994836. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0172(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3994656 constant */
    /* @3994660 cast */
    /* @3994664 call */
    GM_SITE(vm, 172, 3994664);
    /* @3994672 cast */
    /* @3994676 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(24)));
    if (!TRUTH(v1)) goto L_3994704;
    /* @3994680 constant */
    /* @3994684 pushenv */
    if (!GM_PUSHENV(vm, VAL(24))) goto L_3994700;
    L_3994688: ;
    /* @3994688 call */
    GM_SITE(vm, 172, 3994688);
    /* @3994696 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3994700: ;
    /* @3994700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3994688;
    L_3994704: ;
    /* @3994704 constant */
    /* @3994708 cast */
    /* @3994712 call */
    GM_SITE(vm, 172, 3994712);
    /* @3994720 cast */
    /* @3994724 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(55)));
    if (!TRUTH(v2)) goto L_3994752;
    /* @3994728 constant */
    /* @3994732 pushenv */
    if (!GM_PUSHENV(vm, VAL(55))) goto L_3994748;
    L_3994736: ;
    /* @3994736 call */
    GM_SITE(vm, 172, 3994736);
    /* @3994744 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3994748: ;
    /* @3994748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3994736;
    L_3994752: ;
    /* @3994752 call */
    GM_SITE(vm, 172, 3994752);
    /* @3994760 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @3994764 constant */
    /* @3994768 cast */
    /* @3994772 constant */
    /* @3994776 cast */
    /* @3994780 constant */
    /* @3994784 cast */
    /* @3994788 call */
    GM_SITE(vm, 172, 3994788);
    /* @3994796 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(50), VAL(0), VAL(0)));
    /* @3994800 constant */
    /* @3994804 cast */
    /* @3994808 load */
    /* @3994816 load */
    /* @3994824 call */
    GM_SITE(vm, 172, 3994824);
    /* @3994832 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_3994836: ;
    return;
}
