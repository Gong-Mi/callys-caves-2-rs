/* generated from CODE 462 (gml_Object_obj_weaponname_Create_0), source start 4642928, end 4643396. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0462(GmVM* vm) {
    /* @4642928 constant */
    /* @4642932 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-6));
    /* @4642940 constant */
    /* @4642944 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4642952 constant */
    /* @4642956 store */
    GM_WRITE(vm, -1, "alpha", VAL(1));
    /* @4642964 load */
    /* @4642972 constant */
    /* @4642976 cmp */
    /* @4642980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4643000;
    /* @4642984 string */
    /* @4642992 store */
    GM_WRITE(vm, -1, "damage", STR_REF(843));
    L_4643000: ;
    /* @4643000 load */
    /* @4643008 constant */
    /* @4643012 cmp */
    /* @4643016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4643036;
    /* @4643020 string */
    /* @4643028 store */
    GM_WRITE(vm, -1, "damage", STR_REF(844));
    L_4643036: ;
    /* @4643036 load */
    /* @4643044 constant */
    /* @4643048 cmp */
    /* @4643052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_4643072;
    /* @4643056 string */
    /* @4643064 store */
    GM_WRITE(vm, -1, "damage", STR_REF(845));
    L_4643072: ;
    /* @4643072 load */
    /* @4643080 constant */
    /* @4643084 cmp */
    /* @4643088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegun") == VAL(1)))) goto L_4643108;
    /* @4643092 string */
    /* @4643100 store */
    GM_WRITE(vm, -1, "damage", STR_REF(846));
    L_4643108: ;
    /* @4643108 load */
    /* @4643116 constant */
    /* @4643120 cmp */
    /* @4643124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4643144;
    /* @4643128 string */
    /* @4643136 store */
    GM_WRITE(vm, -1, "damage", STR_REF(847));
    L_4643144: ;
    /* @4643144 load */
    /* @4643152 constant */
    /* @4643156 cmp */
    /* @4643160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4643180;
    /* @4643164 string */
    /* @4643172 store */
    GM_WRITE(vm, -1, "damage", STR_REF(848));
    L_4643180: ;
    /* @4643180 load */
    /* @4643188 constant */
    /* @4643192 cmp */
    /* @4643196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4643216;
    /* @4643200 string */
    /* @4643208 store */
    GM_WRITE(vm, -1, "damage", STR_REF(849));
    L_4643216: ;
    /* @4643216 load */
    /* @4643224 constant */
    /* @4643228 cmp */
    /* @4643232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_4643252;
    /* @4643236 string */
    /* @4643244 store */
    GM_WRITE(vm, -1, "damage", STR_REF(850));
    L_4643252: ;
    /* @4643252 load */
    /* @4643260 constant */
    /* @4643264 cmp */
    /* @4643268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4643288;
    /* @4643272 string */
    /* @4643280 store */
    GM_WRITE(vm, -1, "damage", STR_REF(851));
    L_4643288: ;
    /* @4643288 load */
    /* @4643296 constant */
    /* @4643300 cmp */
    /* @4643304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgun") == VAL(1)))) goto L_4643324;
    /* @4643308 string */
    /* @4643316 store */
    GM_WRITE(vm, -1, "damage", STR_REF(852));
    L_4643324: ;
    /* @4643324 load */
    /* @4643332 constant */
    /* @4643336 cmp */
    /* @4643340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4643360;
    /* @4643344 string */
    /* @4643352 store */
    GM_WRITE(vm, -1, "damage", STR_REF(853));
    L_4643360: ;
    /* @4643360 load */
    /* @4643368 constant */
    /* @4643372 cmp */
    /* @4643376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4643396;
    /* @4643380 string */
    /* @4643388 store */
    GM_WRITE(vm, -1, "damage", STR_REF(854));
    L_4643396: ;
    return;
}
