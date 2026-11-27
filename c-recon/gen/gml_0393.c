/* generated from CODE 393 (gml_Object_obj_bladegun_Step_0), source start 4517768, end 4518028. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0393(GmVM* vm) {
    Val v1;
    Val p4517820_0;
    /* @4517768 constant */
    /* @4517772 cast */
    /* @4517776 call */
    GM_SITE(vm, 393, 4517776);
    /* @4517784 constant */
    /* @4517788 cmp */
    /* @4517792 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4517816;
    /* @4517796 load */
    /* @4517804 constant */
    /* @4517808 cmp */
    /* @4517812 b */
    p4517820_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0));
    goto L_4517820;
    L_4517816: ;
    /* @4517816 constant */
    p4517820_0 = VAL(0);
    L_4517820: ;
    /* @4517820 bf */
    if (!TRUTH(p4517820_0)) goto L_4518028;
    /* @4517824 constant */
    /* @4517828 cast */
    /* @4517832 load */
    /* @4517840 load */
    /* @4517848 call */
    GM_SITE(vm, 393, 4517848);
    /* @4517856 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4517860 constant */
    /* @4517864 store */
    GM_WRITE(vm, -5, "bladegunbought", VAL(1));
    /* @4517872 constant */
    /* @4517876 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4517884 constant */
    /* @4517888 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4517896 constant */
    /* @4517900 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4517908 constant */
    /* @4517912 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4517920 constant */
    /* @4517924 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4517932 constant */
    /* @4517936 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4517944 constant */
    /* @4517948 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4517956 constant */
    /* @4517960 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4517968 constant */
    /* @4517972 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4517980 constant */
    /* @4517984 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4517992 constant */
    /* @4517996 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4518004 constant */
    /* @4518008 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4518016 call */
    GM_SITE(vm, 393, 4518016);
    /* @4518024 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4518028: ;
    return;
}
