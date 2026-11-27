/* generated from CODE 185 (gml_Object_obj_boss3_Step_0), source start 4004944, end 4005256. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0185(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4004944 load */
    /* @4004952 constant */
    /* @4004956 cmp */
    /* @4004960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss3") >= VAL(0)))) goto L_4004984;
    /* @4004964 constant */
    /* @4004968 constant */
    /* @4004972 constant */
    /* @4004976 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_4004984: ;
    /* @4004984 load */
    /* @4004992 constant */
    /* @4004996 cmp */
    /* @4005000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss3") <= VAL(0)))) goto L_4005024;
    /* @4005004 constant */
    /* @4005008 constant */
    /* @4005012 constant */
    /* @4005016 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4005024: ;
    /* @4005024 constant */
    /* @4005028 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4005036 constant */
    /* @4005040 cast */
    /* @4005044 load */
    /* @4005052 load */
    /* @4005060 add */
    /* @4005064 load */
    /* @4005072 load */
    /* @4005080 add */
    /* @4005084 call */
    GM_SITE(vm, 185, 4005084);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4005092 cast */
    /* @4005096 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, v1, v2, VAL(34)));
    if (!TRUTH(v3)) goto L_4005120;
    /* @4005100 constant */
    /* @4005104 cast */
    /* @4005108 call */
    GM_SITE(vm, 185, 4005108);
    /* @4005116 popz */
    (void)(GM_CALL(vm, "move_bounce_all", 1, VAL(0)));
    L_4005120: ;
    /* @4005120 load */
    /* @4005128 constant */
    /* @4005132 cmp */
    /* @4005136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4005176;
    /* @4005140 constant */
    /* @4005144 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @4005152 constant */
    /* @4005156 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4005164 constant */
    /* @4005168 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4005176: ;
    /* @4005176 load */
    /* @4005184 constant */
    /* @4005188 cmp */
    /* @4005192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4005212;
    /* @4005196 constant */
    /* @4005204 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4005212: ;
    /* @4005212 load */
    /* @4005220 constant */
    /* @4005224 cmp */
    /* @4005228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4005256;
    /* @4005232 constant */
    /* @4005236 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4005244 constant */
    /* @4005248 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4005256: ;
    return;
}
