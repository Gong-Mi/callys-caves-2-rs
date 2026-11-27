/* generated from CODE 650 (gml_Object_obj_lloydtutorial14_Create_0), source start 4981864, end 4982100. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0650(GmVM* vm) {
    /* @4981864 constant */
    /* @4981868 cast */
    /* @4981872 call */
    GM_SITE(vm, 650, 4981872);
    /* @4981880 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4981884 constant */
    /* @4981888 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4981896 constant */
    /* @4981900 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @4981908 constant */
    /* @4981912 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @4981920 constant */
    /* @4981924 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @4981932 constant */
    /* @4981936 store */
    GM_WRITE(vm, -1, "drawpanel4", VAL(0));
    /* @4981944 constant */
    /* @4981948 store */
    GM_WRITE(vm, -1, "drawpanel5", VAL(0));
    /* @4981956 constant */
    /* @4981960 store */
    GM_WRITE(vm, -1, "drawpanel6", VAL(0));
    /* @4981968 constant */
    /* @4981972 constant */
    /* @4981976 constant */
    /* @4981980 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @4981988 constant */
    /* @4981992 constant */
    /* @4981996 constant */
    /* @4982000 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(5), VAL(100));
    /* @4982008 load */
    /* @4982016 constant */
    /* @4982020 cmp */
    /* @4982024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4982032;
    /* @4982028 b */
    goto L_4982100;
    L_4982032: ;
    /* @4982032 load */
    /* @4982040 constant */
    /* @4982044 cmp */
    /* @4982048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4982100;
    /* @4982052 call */
    GM_SITE(vm, 650, 4982052);
    /* @4982060 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4982064 constant */
    /* @4982068 cast */
    /* @4982072 constant */
    /* @4982076 cast */
    /* @4982080 constant */
    /* @4982084 cast */
    /* @4982088 call */
    GM_SITE(vm, 650, 4982088);
    /* @4982096 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(32), VAL(0), VAL(1)));
    L_4982100: ;
    return;
}
