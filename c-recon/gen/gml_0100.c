/* generated from CODE 100 (gml_Object_obj_shooter2_Create_0), source start 3933120, end 3933972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0100(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3933120 constant */
    /* @3933124 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3933132 constant */
    /* @3933136 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3933144 constant */
    /* @3933148 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3933156 constant */
    /* @3933160 cast */
    /* @3933164 constant */
    /* @3933168 cast */
    /* @3933172 constant */
    /* @3933176 cast */
    /* @3933180 constant */
    /* @3933184 cast */
    /* @3933188 constant */
    /* @3933192 cast */
    /* @3933196 call */
    GM_SITE(vm, 100, 3933196);
    /* @3933204 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3933212 constant */
    /* @3933216 cast */
    /* @3933220 constant */
    /* @3933224 cast */
    /* @3933228 constant */
    /* @3933232 cast */
    /* @3933236 constant */
    /* @3933240 cast */
    /* @3933244 constant */
    /* @3933248 cast */
    /* @3933252 constant */
    /* @3933256 cast */
    /* @3933260 call */
    GM_SITE(vm, 100, 3933260);
    /* @3933268 store */
    v2 = GM_CALL(vm, "choose", 6, VAL(0), VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3933276 constant */
    /* @3933280 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3933288 constant */
    /* @3933292 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3933300 constant */
    /* @3933304 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3933312 constant */
    /* @3933316 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3933324 constant */
    /* @3933328 store */
    GM_WRITE(vm, -1, "hpshooter2frozen", VAL(0));
    /* @3933336 constant */
    /* @3933340 constant */
    /* @3933344 constant */
    /* @3933348 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(60));
    /* @3933356 constant */
    /* @3933360 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3933368 load */
    /* @3933376 constant */
    /* @3933380 cmp */
    /* @3933384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3933520;
    /* @3933388 load */
    /* @3933396 constant */
    /* @3933400 cmp */
    /* @3933404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3933420;
    /* @3933408 constant */
    /* @3933412 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(50));
    L_3933420: ;
    /* @3933420 load */
    /* @3933428 constant */
    /* @3933432 cmp */
    /* @3933436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3933452;
    /* @3933440 constant */
    /* @3933444 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(45));
    L_3933452: ;
    /* @3933452 load */
    /* @3933460 constant */
    /* @3933464 cmp */
    /* @3933468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3933484;
    /* @3933472 constant */
    /* @3933476 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(40));
    L_3933484: ;
    /* @3933484 load */
    /* @3933492 constant */
    /* @3933496 cmp */
    /* @3933500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3933516;
    /* @3933504 constant */
    /* @3933508 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(35));
    L_3933516: ;
    /* @3933516 b */
    goto L_3933972;
    L_3933520: ;
    /* @3933520 load */
    /* @3933528 constant */
    /* @3933532 cmp */
    /* @3933536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3933672;
    /* @3933540 load */
    /* @3933548 constant */
    /* @3933552 cmp */
    /* @3933556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3933572;
    /* @3933560 constant */
    /* @3933564 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(54));
    L_3933572: ;
    /* @3933572 load */
    /* @3933580 constant */
    /* @3933584 cmp */
    /* @3933588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3933604;
    /* @3933592 constant */
    /* @3933596 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(49));
    L_3933604: ;
    /* @3933604 load */
    /* @3933612 constant */
    /* @3933616 cmp */
    /* @3933620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3933636;
    /* @3933624 constant */
    /* @3933628 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(44));
    L_3933636: ;
    /* @3933636 load */
    /* @3933644 constant */
    /* @3933648 cmp */
    /* @3933652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3933668;
    /* @3933656 constant */
    /* @3933660 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(39));
    L_3933668: ;
    /* @3933668 b */
    goto L_3933972;
    L_3933672: ;
    /* @3933672 load */
    /* @3933680 constant */
    /* @3933684 cmp */
    /* @3933688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3933824;
    /* @3933692 load */
    /* @3933700 constant */
    /* @3933704 cmp */
    /* @3933708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3933724;
    /* @3933712 constant */
    /* @3933716 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(65));
    L_3933724: ;
    /* @3933724 load */
    /* @3933732 constant */
    /* @3933736 cmp */
    /* @3933740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3933756;
    /* @3933744 constant */
    /* @3933748 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(61));
    L_3933756: ;
    /* @3933756 load */
    /* @3933764 constant */
    /* @3933768 cmp */
    /* @3933772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3933788;
    /* @3933776 constant */
    /* @3933780 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(57));
    L_3933788: ;
    /* @3933788 load */
    /* @3933796 constant */
    /* @3933800 cmp */
    /* @3933804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3933820;
    /* @3933808 constant */
    /* @3933812 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(53));
    L_3933820: ;
    /* @3933820 b */
    goto L_3933972;
    L_3933824: ;
    /* @3933824 load */
    /* @3933832 constant */
    /* @3933836 cmp */
    /* @3933840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3933972;
    /* @3933844 load */
    /* @3933852 constant */
    /* @3933856 cmp */
    /* @3933860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3933876;
    /* @3933864 constant */
    /* @3933868 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(70));
    L_3933876: ;
    /* @3933876 load */
    /* @3933884 constant */
    /* @3933888 cmp */
    /* @3933892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3933908;
    /* @3933896 constant */
    /* @3933900 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(65));
    L_3933908: ;
    /* @3933908 load */
    /* @3933916 constant */
    /* @3933920 cmp */
    /* @3933924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3933940;
    /* @3933928 constant */
    /* @3933932 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(60));
    L_3933940: ;
    /* @3933940 load */
    /* @3933948 constant */
    /* @3933952 cmp */
    /* @3933956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3933972;
    /* @3933960 constant */
    /* @3933964 store */
    GM_WRITE(vm, -1, "hpshooter2", VAL(55));
    L_3933972: ;
    return;
}
