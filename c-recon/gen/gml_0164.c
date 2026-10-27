/* generated from CODE 164 (gml_Object_obj_boss2_Destroy_0), source start 3983680, end 3983908. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0164(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3983680 call */
    GM_SITE(vm, 164, 3983680);
    /* @3983688 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @3983692 constant */
    /* @3983696 cast */
    /* @3983700 call */
    GM_SITE(vm, 164, 3983700);
    /* @3983708 cast */
    /* @3983712 bf */
    v1 = BOOL(GM_CALL(vm, "object_exists", 1, VAL(32)));
    if (!TRUTH(v1)) goto L_3983740;
    /* @3983716 constant */
    /* @3983720 pushenv */
    if (!GM_PUSHENV(vm, VAL(32))) goto L_3983736;
    L_3983724: ;
    /* @3983724 call */
    GM_SITE(vm, 164, 3983724);
    /* @3983732 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3983736: ;
    /* @3983736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3983724;
    L_3983740: ;
    /* @3983740 constant */
    /* @3983744 cast */
    /* @3983748 call */
    GM_SITE(vm, 164, 3983748);
    /* @3983756 cast */
    /* @3983760 bf */
    v2 = BOOL(GM_CALL(vm, "object_exists", 1, VAL(33)));
    if (!TRUTH(v2)) goto L_3983788;
    /* @3983764 constant */
    /* @3983768 pushenv */
    if (!GM_PUSHENV(vm, VAL(33))) goto L_3983784;
    L_3983772: ;
    /* @3983772 call */
    GM_SITE(vm, 164, 3983772);
    /* @3983780 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3983784: ;
    /* @3983784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3983772;
    L_3983788: ;
    /* @3983788 constant */
    /* @3983792 cast */
    /* @3983796 constant */
    /* @3983800 cast */
    /* @3983804 constant */
    /* @3983808 cast */
    /* @3983812 call */
    GM_SITE(vm, 164, 3983812);
    /* @3983820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, VAL(1024), VAL(256), VAL(154)));
    /* @3983824 call */
    GM_SITE(vm, 164, 3983824);
    /* @3983832 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @3983836 constant */
    /* @3983840 cast */
    /* @3983844 constant */
    /* @3983848 cast */
    /* @3983852 constant */
    /* @3983856 cast */
    /* @3983860 call */
    GM_SITE(vm, 164, 3983860);
    /* @3983868 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(49), VAL(0), VAL(0)));
    /* @3983872 constant */
    /* @3983876 cast */
    /* @3983880 load */
    /* @3983888 load */
    /* @3983896 call */
    GM_SITE(vm, 164, 3983896);
    /* @3983904 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_3983908: ;
    return;
}
