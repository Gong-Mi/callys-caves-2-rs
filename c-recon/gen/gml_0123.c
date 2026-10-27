/* generated from CODE 123 (gml_Object_obj_enemy2_Create_0), source start 3950120, end 3950952. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0123(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3950120 constant */
    /* @3950124 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3950132 constant */
    /* @3950136 store */
    GM_WRITE(vm, -1, "jumping", VAL(0));
    /* @3950144 constant */
    /* @3950148 cast */
    /* @3950152 constant */
    /* @3950156 cast */
    /* @3950160 constant */
    /* @3950164 cast */
    /* @3950168 constant */
    /* @3950172 cast */
    /* @3950176 constant */
    /* @3950180 cast */
    /* @3950184 call */
    GM_SITE(vm, 123, 3950184);
    /* @3950192 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3950200 constant */
    /* @3950204 cast */
    /* @3950208 constant */
    /* @3950212 cast */
    /* @3950216 constant */
    /* @3950220 cast */
    /* @3950224 constant */
    /* @3950228 cast */
    /* @3950232 constant */
    /* @3950236 cast */
    /* @3950240 call */
    GM_SITE(vm, 123, 3950240);
    /* @3950248 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3950256 constant */
    /* @3950260 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3950268 constant */
    /* @3950272 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3950280 constant */
    /* @3950284 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3950292 constant */
    /* @3950296 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3950304 constant */
    /* @3950308 store */
    GM_WRITE(vm, -1, "hptwofrozen", VAL(0));
    /* @3950316 constant */
    /* @3950320 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3950328 constant */
    /* @3950332 constant */
    /* @3950336 constant */
    /* @3950340 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(15));
    /* @3950348 load */
    /* @3950356 constant */
    /* @3950360 cmp */
    /* @3950364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3950500;
    /* @3950368 load */
    /* @3950376 constant */
    /* @3950380 cmp */
    /* @3950384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3950400;
    /* @3950388 constant */
    /* @3950392 store */
    GM_WRITE(vm, -1, "hptwo", VAL(40));
    L_3950400: ;
    /* @3950400 load */
    /* @3950408 constant */
    /* @3950412 cmp */
    /* @3950416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3950432;
    /* @3950420 constant */
    /* @3950424 store */
    GM_WRITE(vm, -1, "hptwo", VAL(38));
    L_3950432: ;
    /* @3950432 load */
    /* @3950440 constant */
    /* @3950444 cmp */
    /* @3950448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3950464;
    /* @3950452 constant */
    /* @3950456 store */
    GM_WRITE(vm, -1, "hptwo", VAL(36));
    L_3950464: ;
    /* @3950464 load */
    /* @3950472 constant */
    /* @3950476 cmp */
    /* @3950480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3950496;
    /* @3950484 constant */
    /* @3950488 store */
    GM_WRITE(vm, -1, "hptwo", VAL(33));
    L_3950496: ;
    /* @3950496 b */
    goto L_3950952;
    L_3950500: ;
    /* @3950500 load */
    /* @3950508 constant */
    /* @3950512 cmp */
    /* @3950516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3950652;
    /* @3950520 load */
    /* @3950528 constant */
    /* @3950532 cmp */
    /* @3950536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3950552;
    /* @3950540 constant */
    /* @3950544 store */
    GM_WRITE(vm, -1, "hptwo", VAL(44));
    L_3950552: ;
    /* @3950552 load */
    /* @3950560 constant */
    /* @3950564 cmp */
    /* @3950568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3950584;
    /* @3950572 constant */
    /* @3950576 store */
    GM_WRITE(vm, -1, "hptwo", VAL(42));
    L_3950584: ;
    /* @3950584 load */
    /* @3950592 constant */
    /* @3950596 cmp */
    /* @3950600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3950616;
    /* @3950604 constant */
    /* @3950608 store */
    GM_WRITE(vm, -1, "hptwo", VAL(40));
    L_3950616: ;
    /* @3950616 load */
    /* @3950624 constant */
    /* @3950628 cmp */
    /* @3950632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3950648;
    /* @3950636 constant */
    /* @3950640 store */
    GM_WRITE(vm, -1, "hptwo", VAL(38));
    L_3950648: ;
    /* @3950648 b */
    goto L_3950952;
    L_3950652: ;
    /* @3950652 load */
    /* @3950660 constant */
    /* @3950664 cmp */
    /* @3950668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3950804;
    /* @3950672 load */
    /* @3950680 constant */
    /* @3950684 cmp */
    /* @3950688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3950704;
    /* @3950692 constant */
    /* @3950696 store */
    GM_WRITE(vm, -1, "hptwo", VAL(50));
    L_3950704: ;
    /* @3950704 load */
    /* @3950712 constant */
    /* @3950716 cmp */
    /* @3950720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3950736;
    /* @3950724 constant */
    /* @3950728 store */
    GM_WRITE(vm, -1, "hptwo", VAL(46));
    L_3950736: ;
    /* @3950736 load */
    /* @3950744 constant */
    /* @3950748 cmp */
    /* @3950752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3950768;
    /* @3950756 constant */
    /* @3950760 store */
    GM_WRITE(vm, -1, "hptwo", VAL(42));
    L_3950768: ;
    /* @3950768 load */
    /* @3950776 constant */
    /* @3950780 cmp */
    /* @3950784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3950800;
    /* @3950788 constant */
    /* @3950792 store */
    GM_WRITE(vm, -1, "hptwo", VAL(40));
    L_3950800: ;
    /* @3950800 b */
    goto L_3950952;
    L_3950804: ;
    /* @3950804 load */
    /* @3950812 constant */
    /* @3950816 cmp */
    /* @3950820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3950952;
    /* @3950824 load */
    /* @3950832 constant */
    /* @3950836 cmp */
    /* @3950840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3950856;
    /* @3950844 constant */
    /* @3950848 store */
    GM_WRITE(vm, -1, "hptwo", VAL(60));
    L_3950856: ;
    /* @3950856 load */
    /* @3950864 constant */
    /* @3950868 cmp */
    /* @3950872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3950888;
    /* @3950876 constant */
    /* @3950880 store */
    GM_WRITE(vm, -1, "hptwo", VAL(55));
    L_3950888: ;
    /* @3950888 load */
    /* @3950896 constant */
    /* @3950900 cmp */
    /* @3950904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3950920;
    /* @3950908 constant */
    /* @3950912 store */
    GM_WRITE(vm, -1, "hptwo", VAL(50));
    L_3950920: ;
    /* @3950920 load */
    /* @3950928 constant */
    /* @3950932 cmp */
    /* @3950936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3950952;
    /* @3950940 constant */
    /* @3950944 store */
    GM_WRITE(vm, -1, "hptwo", VAL(45));
    L_3950952: ;
    return;
}
