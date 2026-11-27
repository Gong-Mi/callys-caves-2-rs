/* generated from CODE 443 (gml_Object_obj_maxhpupgrade2_Mouse_0), source start 4628928, end 4629132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0443(GmVM* vm) {
    Val p4628972_0;
    Val v1;
    /* @4628928 load */
    /* @4628936 constant */
    /* @4628940 cmp */
    /* @4628944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(25000)))) goto L_4628968;
    /* @4628948 load */
    /* @4628956 constant */
    /* @4628960 cmp */
    /* @4628964 b */
    p4628972_0 = NUMBOOL(GM_READ(vm, -5, "maxhpupgrade2bought") == VAL(0));
    goto L_4628972;
    L_4628968: ;
    /* @4628968 constant */
    p4628972_0 = VAL(0);
    L_4628972: ;
    /* @4628972 bf */
    if (!TRUTH(p4628972_0)) goto L_4629132;
    /* @4628976 load */
    /* @4628984 constant */
    /* @4628988 sub */
    /* @4628992 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(25000)));
    /* @4629000 load */
    /* @4629008 constant */
    /* @4629012 add */
    /* @4629016 store */
    v1 = GM_ADD(GM_READ(vm, -5, "level"), VAL(1));
    GM_WRITE(vm, -5, "level", v1);
    /* @4629024 load */
    /* @4629032 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @4629040 constant */
    /* @4629044 store */
    GM_WRITE(vm, -5, "maxhpupgrade2bought", VAL(1));
    /* @4629052 load */
    /* @4629060 constant */
    /* @4629064 cmp */
    /* @4629068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4629076;
    /* @4629072 b */
    goto L_4629132;
    L_4629076: ;
    /* @4629076 load */
    /* @4629084 constant */
    /* @4629088 cmp */
    /* @4629092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4629132;
    /* @4629096 constant */
    /* @4629100 cast */
    /* @4629104 constant */
    /* @4629108 cast */
    /* @4629112 constant */
    /* @4629116 cast */
    /* @4629120 call */
    GM_SITE(vm, 443, 4629120);
    /* @4629128 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4629132: ;
    return;
}
