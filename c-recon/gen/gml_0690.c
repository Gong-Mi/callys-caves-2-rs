/* generated from CODE 690 (gml_Object_obj_maptile_Destroy_0), source start 5016664, end 5016872. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0690(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @5016664 constant */
    /* @5016668 cast */
    /* @5016672 call */
    GM_SITE(vm, 690, 5016672);
    /* @5016680 cast */
    /* @5016684 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(122)));
    if (!TRUTH(v1)) goto L_5016712;
    /* @5016688 constant */
    /* @5016692 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_5016708;
    L_5016696: ;
    /* @5016696 call */
    GM_SITE(vm, 690, 5016696);
    /* @5016704 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5016708: ;
    /* @5016708 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5016696;
    L_5016712: ;
    /* @5016712 constant */
    /* @5016716 cast */
    /* @5016720 call */
    GM_SITE(vm, 690, 5016720);
    /* @5016728 cast */
    /* @5016732 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(123)));
    if (!TRUTH(v2)) goto L_5016760;
    /* @5016736 constant */
    /* @5016740 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_5016756;
    L_5016744: ;
    /* @5016744 call */
    GM_SITE(vm, 690, 5016744);
    /* @5016752 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5016756: ;
    /* @5016756 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5016744;
    L_5016760: ;
    /* @5016760 constant */
    /* @5016764 cast */
    /* @5016768 call */
    GM_SITE(vm, 690, 5016768);
    /* @5016776 cast */
    /* @5016780 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(118)));
    if (!TRUTH(v3)) goto L_5016808;
    /* @5016784 constant */
    /* @5016788 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_5016804;
    L_5016792: ;
    /* @5016792 call */
    GM_SITE(vm, 690, 5016792);
    /* @5016800 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5016804: ;
    /* @5016804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5016792;
    L_5016808: ;
    /* @5016808 constant */
    /* @5016812 cast */
    /* @5016816 call */
    GM_SITE(vm, 690, 5016816);
    /* @5016824 cast */
    /* @5016828 not */
    /* @5016832 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(68))));
    if (!TRUTH(v4)) goto L_5016872;
    /* @5016836 constant */
    /* @5016840 cast */
    /* @5016844 load */
    /* @5016852 load */
    /* @5016860 call */
    GM_SITE(vm, 690, 5016860);
    /* @5016868 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(68)));
    L_5016872: ;
    return;
}
