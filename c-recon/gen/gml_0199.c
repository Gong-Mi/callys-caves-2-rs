/* generated from CODE 199 (gml_Object_obj_boss5_Create_0), source start 4016692, end 4017072. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0199(GmVM* vm) {
    Val v1;
    /* @4016692 constant */
    /* @4016696 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4016704 constant */
    /* @4016708 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4016716 constant */
    /* @4016720 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4016728 constant */
    /* @4016732 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4016740 constant */
    /* @4016744 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4016752 constant */
    /* @4016756 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @4016764 constant */
    /* @4016768 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4016776 constant */
    /* @4016780 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @4016788 constant */
    /* @4016792 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @4016800 constant */
    /* @4016804 constant */
    /* @4016808 constant */
    /* @4016812 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(90));
    /* @4016820 constant */
    /* @4016824 cast */
    /* @4016828 constant */
    /* @4016832 cast */
    /* @4016836 constant */
    /* @4016840 cast */
    /* @4016844 constant */
    /* @4016848 cast */
    /* @4016852 constant */
    /* @4016856 cast */
    /* @4016860 call */
    GM_SITE(vm, 199, 4016860);
    /* @4016868 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @4016876 constant */
    /* @4016880 constant */
    /* @4016884 constant */
    /* @4016888 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(11), VAL(70));
    /* @4016896 load */
    /* @4016904 constant */
    /* @4016908 cmp */
    /* @4016912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4016940;
    /* @4016916 constant */
    /* @4016920 store */
    GM_WRITE(vm, -1, "hpboss5", VAL(1000));
    /* @4016928 constant */
    /* @4016932 store */
    GM_WRITE(vm, -1, "boss5maxhp", VAL(1000));
    L_4016940: ;
    /* @4016940 load */
    /* @4016948 constant */
    /* @4016952 cmp */
    /* @4016956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4016984;
    /* @4016960 constant */
    /* @4016964 store */
    GM_WRITE(vm, -1, "hpboss5", VAL(900));
    /* @4016972 constant */
    /* @4016976 store */
    GM_WRITE(vm, -1, "boss5maxhp", VAL(900));
    L_4016984: ;
    /* @4016984 load */
    /* @4016992 constant */
    /* @4016996 cmp */
    /* @4017000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4017028;
    /* @4017004 constant */
    /* @4017008 store */
    GM_WRITE(vm, -1, "hpboss5", VAL(800));
    /* @4017016 constant */
    /* @4017020 store */
    GM_WRITE(vm, -1, "boss5maxhp", VAL(800));
    L_4017028: ;
    /* @4017028 load */
    /* @4017036 constant */
    /* @4017040 cmp */
    /* @4017044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4017072;
    /* @4017048 constant */
    /* @4017052 store */
    GM_WRITE(vm, -1, "hpboss5", VAL(700));
    /* @4017060 constant */
    /* @4017064 store */
    GM_WRITE(vm, -1, "boss5maxhp", VAL(700));
    L_4017072: ;
    return;
}
