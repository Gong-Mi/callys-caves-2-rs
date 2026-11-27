/* generated from CODE 760 (gml_Object_obj_hulkingbanditintro_Create_0), source start 5036820, end 5037024. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0760(GmVM* vm) {
    Val v1;
    /* @5036820 load */
    /* @5036828 constant */
    /* @5036832 cmp */
    /* @5036836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5036844;
    /* @5036840 b */
    goto L_5036900;
    L_5036844: ;
    /* @5036844 load */
    /* @5036852 constant */
    /* @5036856 cmp */
    /* @5036860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5036900;
    /* @5036864 constant */
    /* @5036868 cast */
    /* @5036872 constant */
    /* @5036876 cast */
    /* @5036880 constant */
    /* @5036884 cast */
    /* @5036888 call */
    GM_SITE(vm, 760, 5036888);
    /* @5036896 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5036900: ;
    /* @5036900 constant */
    /* @5036904 constant */
    /* @5036908 constant */
    /* @5036912 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5036920 constant */
    /* @5036924 cast */
    /* @5036928 load */
    /* @5036936 constant */
    /* @5036940 sub */
    /* @5036944 load */
    /* @5036952 constant */
    /* @5036956 add */
    /* @5036960 call */
    GM_SITE(vm, 760, 5036960);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5036968 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5036972 constant */
    /* @5036976 cast */
    /* @5036980 load */
    /* @5036988 constant */
    /* @5036992 sub */
    /* @5036996 load */
    /* @5037004 constant */
    /* @5037008 sub */
    /* @5037012 call */
    GM_SITE(vm, 760, 5037012);
    /* @5037020 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5037024: ;
    return;
}
