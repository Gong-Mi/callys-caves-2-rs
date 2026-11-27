/* generated from CODE 739 (gml_Object_obj_boss1intro_Create_0), source start 5034720, end 5034924. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0739(GmVM* vm) {
    Val v1;
    /* @5034720 load */
    /* @5034728 constant */
    /* @5034732 cmp */
    /* @5034736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5034744;
    /* @5034740 b */
    goto L_5034800;
    L_5034744: ;
    /* @5034744 load */
    /* @5034752 constant */
    /* @5034756 cmp */
    /* @5034760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5034800;
    /* @5034764 constant */
    /* @5034768 cast */
    /* @5034772 constant */
    /* @5034776 cast */
    /* @5034780 constant */
    /* @5034784 cast */
    /* @5034788 call */
    GM_SITE(vm, 739, 5034788);
    /* @5034796 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5034800: ;
    /* @5034800 constant */
    /* @5034804 constant */
    /* @5034808 constant */
    /* @5034812 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5034820 constant */
    /* @5034824 cast */
    /* @5034828 load */
    /* @5034836 constant */
    /* @5034840 sub */
    /* @5034844 load */
    /* @5034852 constant */
    /* @5034856 add */
    /* @5034860 call */
    GM_SITE(vm, 739, 5034860);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5034868 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5034872 constant */
    /* @5034876 cast */
    /* @5034880 load */
    /* @5034888 constant */
    /* @5034892 sub */
    /* @5034896 load */
    /* @5034904 constant */
    /* @5034908 sub */
    /* @5034912 call */
    GM_SITE(vm, 739, 5034912);
    /* @5034920 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5034924: ;
    return;
}
