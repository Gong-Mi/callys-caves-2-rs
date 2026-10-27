/* generated from CODE 282 (gml_Object_obj_bullet_Create_0), source start 4089820, end 4090464. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0282(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @4089820 constant */
    /* @4089824 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4089832 load */
    /* @4089840 constant */
    /* @4089844 cmp */
    /* @4089848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4089864;
    /* @4089852 constant */
    /* @4089856 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-25));
    L_4089864: ;
    /* @4089864 load */
    /* @4089872 constant */
    /* @4089876 cmp */
    /* @4089880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4089896;
    /* @4089884 constant */
    /* @4089888 store */
    GM_WRITE(vm, -1, "hspeed", VAL(25));
    L_4089896: ;
    /* @4089896 load */
    /* @4089904 constant */
    /* @4089908 cmp */
    /* @4089912 cast */
    /* @4089916 load */
    /* @4089924 constant */
    /* @4089928 cmp */
    /* @4089932 cast */
    /* @4089936 and */
    /* @4089940 cast */
    /* @4089944 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0))))))) goto L_4090040;
    /* @4089948 constant */
    /* @4089952 cast */
    /* @4089956 load */
    /* @4089964 constant */
    /* @4089968 cast */
    /* @4089972 call */
    GM_SITE(vm, 282, 4089972);
    /* @4089980 constant */
    /* @4089984 cast */
    /* @4089988 constant */
    /* @4089992 cast */
    /* @4089996 call */
    GM_SITE(vm, 282, 4089996);
    /* @4090004 mul */
    /* @4090008 add */
    /* @4090012 call */
    GM_SITE(vm, 282, 4090012);
    v1 = GM_ADD(GM_READ(vm, -1, "image_angle"), (GM_CALL(vm, "random", 1, VAL(15)) * GM_CALL(vm, "choose", 2, VAL(1), VAL(-1))));
    /* @4090020 popz */
    (void)(GM_CALL(vm, "motion_set", 2, v1, VAL(32)));
    /* @4090024 load */
    /* @4090032 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    L_4090040: ;
    /* @4090040 load */
    /* @4090048 constant */
    /* @4090052 cmp */
    /* @4090056 cast */
    /* @4090060 load */
    /* @4090068 constant */
    /* @4090072 cmp */
    /* @4090076 cast */
    /* @4090080 and */
    /* @4090084 cast */
    /* @4090088 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1))))))) goto L_4090196;
    /* @4090092 constant */
    /* @4090096 cast */
    /* @4090100 load */
    /* @4090108 constant */
    /* @4090112 cast */
    /* @4090116 call */
    GM_SITE(vm, 282, 4090116);
    /* @4090124 constant */
    /* @4090128 cast */
    /* @4090132 constant */
    /* @4090136 cast */
    /* @4090140 call */
    GM_SITE(vm, 282, 4090140);
    /* @4090148 mul */
    /* @4090152 add */
    /* @4090156 call */
    GM_SITE(vm, 282, 4090156);
    v2 = GM_ADD(GM_READ(vm, -1, "image_angle"), (GM_CALL(vm, "random", 1, VAL(15)) * GM_CALL(vm, "choose", 2, VAL(1), VAL(-1))));
    /* @4090164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, v2, VAL(-32)));
    /* @4090168 load */
    /* @4090176 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4090184 constant */
    /* @4090188 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4090196: ;
    /* @4090196 load */
    /* @4090204 constant */
    /* @4090208 cmp */
    /* @4090212 cast */
    /* @4090216 load */
    /* @4090224 constant */
    /* @4090228 cmp */
    /* @4090232 cast */
    /* @4090236 and */
    /* @4090240 cast */
    /* @4090244 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0))))))) goto L_4090324;
    /* @4090248 constant */
    /* @4090252 cast */
    /* @4090256 load */
    /* @4090264 constant */
    /* @4090268 cast */
    /* @4090272 call */
    GM_SITE(vm, 282, 4090272);
    /* @4090280 constant */
    /* @4090284 cast */
    /* @4090288 constant */
    /* @4090292 cast */
    /* @4090296 call */
    GM_SITE(vm, 282, 4090296);
    /* @4090304 mul */
    /* @4090308 add */
    /* @4090312 call */
    GM_SITE(vm, 282, 4090312);
    v3 = GM_ADD(GM_READ(vm, -1, "image_angle"), (GM_CALL(vm, "random", 1, VAL(3)) * GM_CALL(vm, "choose", 2, VAL(1), VAL(-1))));
    /* @4090320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, v3, VAL(32)));
    L_4090324: ;
    /* @4090324 load */
    /* @4090332 constant */
    /* @4090336 cmp */
    /* @4090340 cast */
    /* @4090344 load */
    /* @4090352 constant */
    /* @4090356 cmp */
    /* @4090360 cast */
    /* @4090364 and */
    /* @4090368 cast */
    /* @4090372 bf */
    if (!TRUTH(BOOL(BAND(TO_INT(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1))), TO_INT(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1))))))) goto L_4090464;
    /* @4090376 constant */
    /* @4090380 cast */
    /* @4090384 load */
    /* @4090392 constant */
    /* @4090396 cast */
    /* @4090400 call */
    GM_SITE(vm, 282, 4090400);
    /* @4090408 constant */
    /* @4090412 cast */
    /* @4090416 constant */
    /* @4090420 cast */
    /* @4090424 call */
    GM_SITE(vm, 282, 4090424);
    /* @4090432 mul */
    /* @4090436 add */
    /* @4090440 call */
    GM_SITE(vm, 282, 4090440);
    v4 = GM_ADD(GM_READ(vm, -1, "image_angle"), (GM_CALL(vm, "random", 1, VAL(3)) * GM_CALL(vm, "choose", 2, VAL(1), VAL(-1))));
    /* @4090448 popz */
    (void)(GM_CALL(vm, "motion_set", 2, v4, VAL(-32)));
    /* @4090452 constant */
    /* @4090456 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4090464: ;
    return;
}
