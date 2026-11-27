/* generated from CODE 197 (gml_Object_obj_boss4_Step_0), source start 4015584, end 4016500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0197(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p4016308_0;
    Val v4;
    Val v5;
    Val v6;
    /* @4015584 constant */
    /* @4015588 cast */
    /* @4015592 load */
    /* @4015600 constant */
    /* @4015604 add */
    /* @4015608 load */
    /* @4015616 call */
    GM_SITE(vm, 197, 4015616);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4015624 cast */
    /* @4015628 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4015660;
    /* @4015632 constant */
    /* @4015636 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4015644 constant */
    /* @4015648 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @4015656 b */
    goto L_4015692;
    L_4015660: ;
    /* @4015660 constant */
    /* @4015672 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @4015680 constant */
    /* @4015684 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_4015692: ;
    /* @4015692 load */
    /* @4015700 constant */
    /* @4015704 cmp */
    /* @4015708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss4") >= VAL(0)))) goto L_4015732;
    /* @4015712 constant */
    /* @4015716 constant */
    /* @4015720 constant */
    /* @4015724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_4015732: ;
    /* @4015732 load */
    /* @4015740 constant */
    /* @4015744 cmp */
    /* @4015748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss4") <= VAL(0)))) goto L_4015772;
    /* @4015752 constant */
    /* @4015756 constant */
    /* @4015760 constant */
    /* @4015764 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4015772: ;
    /* @4015772 constant */
    /* @4015776 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4015784 load */
    /* @4015792 constant */
    /* @4015796 cmp */
    /* @4015800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4015840;
    /* @4015804 constant */
    /* @4015808 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @4015816 constant */
    /* @4015820 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4015828 constant */
    /* @4015832 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4015840: ;
    /* @4015840 load */
    /* @4015848 constant */
    /* @4015852 cmp */
    /* @4015856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(0)))) goto L_4015872;
    /* @4015860 constant */
    /* @4015864 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(76));
    L_4015872: ;
    /* @4015872 load */
    /* @4015880 constant */
    /* @4015884 cmp */
    /* @4015888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4015908;
    /* @4015892 constant */
    /* @4015900 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4015908: ;
    /* @4015908 load */
    /* @4015916 constant */
    /* @4015920 cmp */
    /* @4015924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(1)))) goto L_4015984;
    /* @4015928 constant */
    /* @4015932 cast */
    /* @4015936 call */
    GM_SITE(vm, 197, 4015936);
    /* @4015944 constant */
    /* @4015948 cmp */
    /* @4015952 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(100));
    if (!TRUTH(v3)) goto L_4015972;
    /* @4015956 constant */
    /* @4015960 store */
    GM_WRITE(vm, -1, "swinging", VAL(1));
    /* @4015968 b */
    goto L_4015984;
    L_4015972: ;
    /* @4015972 constant */
    /* @4015976 store */
    GM_WRITE(vm, -1, "swinging", VAL(0));
    L_4015984: ;
    /* @4015984 load */
    /* @4015992 constant */
    /* @4015996 cmp */
    /* @4016000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(1)))) goto L_4016144;
    /* @4016004 load */
    /* @4016012 constant */
    /* @4016016 cmp */
    /* @4016020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "movelock") == VAL(1)))) goto L_4016072;
    /* @4016024 load */
    /* @4016032 load */
    /* @4016040 cmp */
    /* @4016044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_4016072;
    /* @4016048 constant */
    /* @4016052 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4016060 constant */
    /* @4016064 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_4016072: ;
    /* @4016072 load */
    /* @4016080 constant */
    /* @4016084 cmp */
    /* @4016088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "movelock") == VAL(1)))) goto L_4016140;
    /* @4016092 load */
    /* @4016100 load */
    /* @4016108 cmp */
    /* @4016112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_4016140;
    /* @4016116 constant */
    /* @4016120 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4016128 constant */
    /* @4016132 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_4016140: ;
    /* @4016140 b */
    goto L_4016264;
    L_4016144: ;
    /* @4016144 load */
    /* @4016152 constant */
    /* @4016156 cmp */
    /* @4016160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(0)))) goto L_4016216;
    /* @4016164 load */
    /* @4016172 load */
    /* @4016180 cmp */
    /* @4016184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_4016212;
    /* @4016188 constant */
    /* @4016192 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4016200 constant */
    /* @4016204 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_4016212: ;
    /* @4016212 b */
    goto L_4016264;
    L_4016216: ;
    /* @4016216 load */
    /* @4016224 load */
    /* @4016232 cmp */
    /* @4016236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_4016264;
    /* @4016240 constant */
    /* @4016244 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4016252 constant */
    /* @4016256 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_4016264: ;
    /* @4016264 load */
    /* @4016272 constant */
    /* @4016276 cmp */
    /* @4016280 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_4016304;
    /* @4016284 load */
    /* @4016292 constant */
    /* @4016296 cmp */
    /* @4016300 b */
    p4016308_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_4016308;
    L_4016304: ;
    /* @4016304 constant */
    p4016308_0 = VAL(1);
    L_4016308: ;
    /* @4016308 bf */
    if (!TRUTH(p4016308_0)) goto L_4016324;
    /* @4016312 constant */
    /* @4016316 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_4016324: ;
    /* @4016324 load */
    /* @4016332 constant */
    /* @4016336 cmp */
    /* @4016340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4016380;
    /* @4016344 constant */
    /* @4016348 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4016356 constant */
    /* @4016360 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4016368 constant */
    /* @4016372 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    L_4016380: ;
    /* @4016380 constant */
    /* @4016384 cast */
    /* @4016388 load */
    /* @4016396 load */
    /* @4016404 constant */
    /* @4016408 add */
    /* @4016412 call */
    GM_SITE(vm, 197, 4016412);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4016420 cast */
    /* @4016424 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v5)) goto L_4016440;
    /* @4016428 constant */
    /* @4016432 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_4016440: ;
    /* @4016440 constant */
    /* @4016444 cast */
    /* @4016448 load */
    /* @4016456 load */
    /* @4016464 constant */
    /* @4016468 sub */
    /* @4016472 call */
    GM_SITE(vm, 197, 4016472);
    /* @4016480 cast */
    /* @4016484 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(10)), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4016500;
    /* @4016488 constant */
    /* @4016492 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_4016500: ;
    return;
}
