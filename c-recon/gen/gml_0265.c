/* generated from CODE 265 (gml_Object_obj_fireslime_Step_0), source start 4054656, end 4055640. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0265(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val p4055256_0;
    Val v9;
    /* @4054656 load */
    /* @4054664 constant */
    /* @4054668 cmp */
    /* @4054672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfireslime") >= VAL(0)))) goto L_4054696;
    /* @4054676 constant */
    /* @4054680 constant */
    /* @4054684 constant */
    /* @4054688 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(0));
    L_4054696: ;
    /* @4054696 load */
    /* @4054704 constant */
    /* @4054708 cmp */
    /* @4054712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfireslime") <= VAL(0)))) goto L_4054736;
    /* @4054716 constant */
    /* @4054720 constant */
    /* @4054724 constant */
    /* @4054728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    L_4054736: ;
    /* @4054736 constant */
    /* @4054740 cast */
    /* @4054744 load */
    /* @4054752 load */
    /* @4054760 add */
    /* @4054764 load */
    /* @4054772 call */
    GM_SITE(vm, 265, 4054772);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4054780 cast */
    /* @4054784 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4054828;
    /* @4054788 constant */
    /* @4054792 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4054800 constant */
    /* @4054804 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4054812 constant */
    /* @4054816 store */
    GM_WRITE(vm, -1, "gravity_direction", VAL(270));
    /* @4054824 b */
    goto L_4054860;
    L_4054828: ;
    /* @4054828 constant */
    /* @4054840 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.7));
    /* @4054848 constant */
    /* @4054852 store */
    GM_WRITE(vm, -1, "gravity_direction", VAL(270));
    L_4054860: ;
    /* @4054860 constant */
    /* @4054864 cast */
    /* @4054868 load */
    /* @4054876 constant */
    /* @4054880 sub */
    /* @4054884 load */
    /* @4054892 call */
    GM_SITE(vm, 265, 4054892);
    /* @4054900 cast */
    /* @4054904 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(3)), VAL(34)));
    if (!TRUTH(v3)) goto L_4054940;
    /* @4054908 load */
    /* @4054916 constant */
    /* @4054920 cmp */
    /* @4054924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfireslimefrozen") == VAL(0)))) goto L_4054940;
    /* @4054928 constant */
    /* @4054932 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4054940: ;
    /* @4054940 load */
    /* @4054948 constant */
    /* @4054960 cmp */
    /* @4054964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") >= VAL(0.01)))) goto L_4055036;
    /* @4054968 constant */
    /* @4054972 cast */
    /* @4054976 load */
    /* @4054984 constant */
    /* @4054988 sub */
    /* @4054992 load */
    /* @4055000 constant */
    /* @4055004 add */
    /* @4055008 call */
    GM_SITE(vm, 265, 4055008);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4055016 cast */
    /* @4055020 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(2)), VAL(34)));
    if (!TRUTH(v5)) goto L_4055036;
    /* @4055024 constant */
    /* @4055028 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_4055036: ;
    /* @4055036 load */
    /* @4055044 constant */
    /* @4055056 cmp */
    /* @4055060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") <= VAL(-0.01)))) goto L_4055132;
    /* @4055064 constant */
    /* @4055068 cast */
    /* @4055072 load */
    /* @4055080 constant */
    /* @4055084 sub */
    /* @4055088 load */
    /* @4055096 constant */
    /* @4055100 sub */
    /* @4055104 call */
    GM_SITE(vm, 265, 4055104);
    /* @4055112 cast */
    /* @4055116 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(2)), VAL(34)));
    if (!TRUTH(v6)) goto L_4055132;
    /* @4055120 constant */
    /* @4055124 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_4055132: ;
    /* @4055132 load */
    /* @4055140 load */
    /* @4055148 cmp */
    /* @4055152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4055172;
    /* @4055156 constant */
    /* @4055160 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4055168 b */
    goto L_4055184;
    L_4055172: ;
    /* @4055172 constant */
    /* @4055176 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4055184: ;
    /* @4055184 constant */
    /* @4055188 cast */
    /* @4055192 load */
    /* @4055200 constant */
    /* @4055204 add */
    /* @4055208 load */
    /* @4055216 call */
    GM_SITE(vm, 265, 4055216);
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4055224 cast */
    /* @4055228 bf */
    v8 = BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v7, VAL(34)));
    if (!TRUTH(v8)) goto L_4055252;
    /* @4055232 load */
    /* @4055240 constant */
    /* @4055244 cmp */
    /* @4055248 b */
    p4055256_0 = NUMBOOL(GM_READ(vm, -1, "hpfireslimefrozen") == VAL(0));
    goto L_4055256;
    L_4055252: ;
    /* @4055252 constant */
    p4055256_0 = VAL(0);
    L_4055256: ;
    /* @4055256 bf */
    if (!TRUTH(p4055256_0)) goto L_4055360;
    /* @4055260 constant */
    /* @4055264 cast */
    /* @4055268 constant */
    /* @4055272 cast */
    /* @4055276 constant */
    /* @4055280 cast */
    /* @4055284 load */
    /* @4055292 load */
    /* @4055300 load */
    /* @4055308 load */
    /* @4055316 call */
    GM_SITE(vm, 265, 4055316);
    /* @4055324 cast */
    /* @4055328 not */
    /* @4055332 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "collision_line", 7, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34), VAL(0), VAL(0))));
    if (!TRUTH(v9)) goto L_4055360;
    /* @4055336 constant */
    /* @4055340 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-8));
    /* @4055348 constant */
    /* @4055352 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(75));
    L_4055360: ;
    /* @4055360 load */
    /* @4055368 constant */
    /* @4055372 cmp */
    /* @4055376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfireslimefrozen") == VAL(1)))) goto L_4055424;
    /* @4055380 constant */
    /* @4055388 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @4055396 constant */
    /* @4055400 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4055408 constant */
    /* @4055412 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4055420 b */
    goto L_4055440;
    L_4055424: ;
    /* @4055424 constant */
    /* @4055432 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_4055440: ;
    /* @4055440 load */
    /* @4055448 constant */
    /* @4055452 cmp */
    /* @4055456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_4055472;
    /* @4055460 constant */
    /* @4055464 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(72));
    L_4055472: ;
    /* @4055472 load */
    /* @4055480 constant */
    /* @4055484 cmp */
    /* @4055488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4055528;
    /* @4055492 constant */
    /* @4055496 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @4055504 constant */
    /* @4055508 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4055516 constant */
    /* @4055520 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4055528: ;
    /* @4055528 load */
    /* @4055536 constant */
    /* @4055540 cmp */
    /* @4055544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4055564;
    /* @4055548 constant */
    /* @4055556 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4055564: ;
    /* @4055564 load */
    /* @4055572 constant */
    /* @4055576 cmp */
    /* @4055580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4055608;
    /* @4055584 constant */
    /* @4055588 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4055596 constant */
    /* @4055600 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4055608: ;
    /* @4055608 load */
    /* @4055616 constant */
    /* @4055620 cmp */
    /* @4055624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(1)))) goto L_4055640;
    /* @4055628 constant */
    /* @4055632 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(75));
    L_4055640: ;
    return;
}
