/* generated from CODE 80 (gml_Object_obj_firehulk_Create_0), source start 3918276, end 3918976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0080(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3918276 constant */
    /* @3918280 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3918288 constant */
    /* @3918292 cast */
    /* @3918296 constant */
    /* @3918300 cast */
    /* @3918304 constant */
    /* @3918308 cast */
    /* @3918312 constant */
    /* @3918316 cast */
    /* @3918320 constant */
    /* @3918324 cast */
    /* @3918328 call */
    GM_SITE(vm, 80, 3918328);
    /* @3918336 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3918344 constant */
    /* @3918348 cast */
    /* @3918352 constant */
    /* @3918356 cast */
    /* @3918360 constant */
    /* @3918364 cast */
    /* @3918368 constant */
    /* @3918372 cast */
    /* @3918376 constant */
    /* @3918380 cast */
    /* @3918384 constant */
    /* @3918388 cast */
    /* @3918392 call */
    GM_SITE(vm, 80, 3918392);
    /* @3918400 store */
    v2 = GM_CALL(vm, "choose", 6, VAL(0), VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3918408 constant */
    /* @3918412 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3918420 constant */
    /* @3918424 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3918432 constant */
    /* @3918436 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3918444 constant */
    /* @3918448 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3918456 constant */
    /* @3918460 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3918468 constant */
    /* @3918472 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3918480 constant */
    /* @3918484 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3918492 constant */
    /* @3918496 store */
    GM_WRITE(vm, -1, "hpfirehulkfrozen", VAL(0));
    /* @3918504 constant */
    /* @3918508 constant */
    /* @3918512 constant */
    /* @3918516 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    /* @3918524 load */
    /* @3918532 constant */
    /* @3918536 cmp */
    /* @3918540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3918676;
    /* @3918544 load */
    /* @3918552 constant */
    /* @3918556 cmp */
    /* @3918560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3918576;
    /* @3918564 constant */
    /* @3918568 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(100));
    L_3918576: ;
    /* @3918576 load */
    /* @3918584 constant */
    /* @3918588 cmp */
    /* @3918592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3918608;
    /* @3918596 constant */
    /* @3918600 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(95));
    L_3918608: ;
    /* @3918608 load */
    /* @3918616 constant */
    /* @3918620 cmp */
    /* @3918624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3918640;
    /* @3918628 constant */
    /* @3918632 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(90));
    L_3918640: ;
    /* @3918640 load */
    /* @3918648 constant */
    /* @3918652 cmp */
    /* @3918656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3918672;
    /* @3918660 constant */
    /* @3918664 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(80));
    L_3918672: ;
    /* @3918672 b */
    goto L_3918976;
    L_3918676: ;
    /* @3918676 load */
    /* @3918684 constant */
    /* @3918688 cmp */
    /* @3918692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3918828;
    /* @3918696 load */
    /* @3918704 constant */
    /* @3918708 cmp */
    /* @3918712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3918728;
    /* @3918716 constant */
    /* @3918720 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(115));
    L_3918728: ;
    /* @3918728 load */
    /* @3918736 constant */
    /* @3918740 cmp */
    /* @3918744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3918760;
    /* @3918748 constant */
    /* @3918752 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(110));
    L_3918760: ;
    /* @3918760 load */
    /* @3918768 constant */
    /* @3918772 cmp */
    /* @3918776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3918792;
    /* @3918780 constant */
    /* @3918784 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(105));
    L_3918792: ;
    /* @3918792 load */
    /* @3918800 constant */
    /* @3918804 cmp */
    /* @3918808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3918824;
    /* @3918812 constant */
    /* @3918816 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(95));
    L_3918824: ;
    /* @3918824 b */
    goto L_3918976;
    L_3918828: ;
    /* @3918828 load */
    /* @3918836 constant */
    /* @3918840 cmp */
    /* @3918844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3918976;
    /* @3918848 load */
    /* @3918856 constant */
    /* @3918860 cmp */
    /* @3918864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3918880;
    /* @3918868 constant */
    /* @3918872 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(130));
    L_3918880: ;
    /* @3918880 load */
    /* @3918888 constant */
    /* @3918892 cmp */
    /* @3918896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3918912;
    /* @3918900 constant */
    /* @3918904 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(120));
    L_3918912: ;
    /* @3918912 load */
    /* @3918920 constant */
    /* @3918924 cmp */
    /* @3918928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3918944;
    /* @3918932 constant */
    /* @3918936 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(115));
    L_3918944: ;
    /* @3918944 load */
    /* @3918952 constant */
    /* @3918956 cmp */
    /* @3918960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3918976;
    /* @3918964 constant */
    /* @3918968 store */
    GM_WRITE(vm, -1, "hpfirehulk", VAL(105));
    L_3918976: ;
    return;
}
