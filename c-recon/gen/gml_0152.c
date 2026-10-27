/* generated from CODE 152 (gml_Object_obj_ghost_Step_0), source start 3971544, end 3972292. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0152(GmVM* vm) {
    Val v1;
    Val v2;
    Val p3971872_0;
    Val v3;
    Val p3971996_0;
    /* @3971544 load */
    /* @3971552 constant */
    /* @3971556 cmp */
    /* @3971560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_3972292;
    /* @3971564 load */
    /* @3971572 constant */
    /* @3971576 cmp */
    /* @3971580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpghost") >= VAL(0)))) goto L_3971604;
    /* @3971584 constant */
    /* @3971588 constant */
    /* @3971592 constant */
    /* @3971596 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3971604: ;
    /* @3971604 load */
    /* @3971612 constant */
    /* @3971616 cmp */
    /* @3971620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpghost") <= VAL(0)))) goto L_3971644;
    /* @3971624 constant */
    /* @3971628 constant */
    /* @3971632 constant */
    /* @3971636 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3971644: ;
    /* @3971644 constant */
    /* @3971648 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3971656 load */
    /* @3971664 load */
    /* @3971672 cmp */
    /* @3971676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_3971696;
    /* @3971680 constant */
    /* @3971684 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3971692 b */
    goto L_3971732;
    L_3971696: ;
    /* @3971696 load */
    /* @3971704 load */
    /* @3971712 cmp */
    /* @3971716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_3971732;
    /* @3971720 constant */
    /* @3971724 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3971732: ;
    /* @3971732 constant */
    /* @3971736 cast */
    /* @3971740 call */
    GM_SITE(vm, 152, 3971740);
    /* @3971748 constant */
    /* @3971752 cmp */
    /* @3971756 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) < VAL(220));
    if (!TRUTH(v1)) goto L_3972044;
    /* @3971760 constant */
    /* @3971764 cast */
    /* @3971768 call */
    GM_SITE(vm, 152, 3971768);
    /* @3971776 constant */
    /* @3971780 cmp */
    /* @3971784 bf */
    v2 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) < VAL(50));
    if (!TRUTH(v2)) goto L_3971924;
    /* @3971788 load */
    /* @3971796 constant */
    /* @3971800 cmp */
    /* @3971804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_3971920;
    /* @3971808 load */
    /* @3971816 constant */
    /* @3971820 cmp */
    /* @3971824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0)))) goto L_3971868;
    /* @3971828 load */
    /* @3971836 constant */
    /* @3971840 cmp */
    /* @3971844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") != VAL(1)))) goto L_3971868;
    /* @3971848 load */
    /* @3971856 constant */
    /* @3971860 cmp */
    /* @3971864 b */
    p3971872_0 = NUMBOOL(GM_READ(vm, -1, "hpghostfrozen") != VAL(1));
    goto L_3971872;
    L_3971868: ;
    /* @3971868 constant */
    p3971872_0 = VAL(0);
    L_3971872: ;
    /* @3971872 bf */
    if (!TRUTH(p3971872_0)) goto L_3971920;
    /* @3971876 constant */
    /* @3971880 cast */
    /* @3971884 constant */
    /* @3971888 cast */
    /* @3971892 load */
    /* @3971900 load */
    /* @3971908 call */
    GM_SITE(vm, 152, 3971908);
    /* @3971916 popz */
    (void)(GM_CALL(vm, "mp_potential_step", 4, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(3), VAL(0)));
    L_3971920: ;
    /* @3971920 b */
    goto L_3972044;
    L_3971924: ;
    /* @3971924 constant */
    /* @3971928 cast */
    /* @3971932 call */
    GM_SITE(vm, 152, 3971932);
    /* @3971940 constant */
    /* @3971944 cmp */
    /* @3971948 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(50));
    if (!TRUTH(v3)) goto L_3971992;
    /* @3971952 load */
    /* @3971960 constant */
    /* @3971964 cmp */
    /* @3971968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") != VAL(1)))) goto L_3971992;
    /* @3971972 load */
    /* @3971980 constant */
    /* @3971984 cmp */
    /* @3971988 b */
    p3971996_0 = NUMBOOL(GM_READ(vm, -1, "hpghostfrozen") != VAL(1));
    goto L_3971996;
    L_3971992: ;
    /* @3971992 constant */
    p3971996_0 = VAL(0);
    L_3971996: ;
    /* @3971996 bf */
    if (!TRUTH(p3971996_0)) goto L_3972044;
    /* @3972000 constant */
    /* @3972004 cast */
    /* @3972008 constant */
    /* @3972012 cast */
    /* @3972016 load */
    /* @3972024 load */
    /* @3972032 call */
    GM_SITE(vm, 152, 3972032);
    /* @3972040 popz */
    (void)(GM_CALL(vm, "mp_potential_step", 4, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(3), VAL(0)));
    L_3972044: ;
    /* @3972044 load */
    /* @3972052 constant */
    /* @3972056 cmp */
    /* @3972060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpghostfrozen") == VAL(1)))) goto L_3972108;
    /* @3972064 constant */
    /* @3972072 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3972080 constant */
    /* @3972084 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3972092 constant */
    /* @3972096 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3972104 b */
    goto L_3972124;
    L_3972108: ;
    /* @3972108 constant */
    /* @3972116 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3972124: ;
    /* @3972124 load */
    /* @3972132 constant */
    /* @3972136 cmp */
    /* @3972140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3972156;
    /* @3972144 constant */
    /* @3972148 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    L_3972156: ;
    /* @3972156 load */
    /* @3972164 constant */
    /* @3972168 cmp */
    /* @3972172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3972212;
    /* @3972176 constant */
    /* @3972180 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @3972188 constant */
    /* @3972192 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3972200 constant */
    /* @3972204 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3972212: ;
    /* @3972212 load */
    /* @3972220 constant */
    /* @3972224 cmp */
    /* @3972228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3972248;
    /* @3972232 constant */
    /* @3972240 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3972248: ;
    /* @3972248 load */
    /* @3972256 constant */
    /* @3972260 cmp */
    /* @3972264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3972292;
    /* @3972268 constant */
    /* @3972272 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3972280 constant */
    /* @3972284 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3972292: ;
    return;
}
