/* generated from CODE 244 (gml_Object_obj_slime_Create_0), source start 4040872, end 4041772. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0244(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4040872 constant */
    /* @4040876 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4040884 constant */
    /* @4040888 cast */
    /* @4040892 constant */
    /* @4040896 cast */
    /* @4040900 constant */
    /* @4040904 cast */
    /* @4040908 constant */
    /* @4040912 cast */
    /* @4040916 constant */
    /* @4040920 cast */
    /* @4040924 call */
    GM_SITE(vm, 244, 4040924);
    /* @4040932 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v1);
    /* @4040940 constant */
    /* @4040944 cast */
    /* @4040948 constant */
    /* @4040952 cast */
    /* @4040956 constant */
    /* @4040960 cast */
    /* @4040964 constant */
    /* @4040968 cast */
    /* @4040972 constant */
    /* @4040976 cast */
    /* @4040980 call */
    GM_SITE(vm, 244, 4040980);
    /* @4040988 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v2);
    /* @4040996 constant */
    /* @4041000 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4041008 constant */
    /* @4041012 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4041020 constant */
    /* @4041024 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4041032 constant */
    /* @4041036 store */
    GM_WRITE(vm, -1, "blobjump", VAL(45));
    /* @4041044 constant */
    /* @4041048 constant */
    /* @4041052 constant */
    /* @4041056 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    /* @4041064 constant */
    /* @4041068 constant */
    /* @4041072 constant */
    /* @4041076 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(40));
    /* @4041084 constant */
    /* @4041088 cast */
    /* @4041092 constant */
    /* @4041096 cast */
    /* @4041100 call */
    GM_SITE(vm, 244, 4041100);
    /* @4041108 store */
    v3 = GM_CALL(vm, "choose", 2, VAL(-3), VAL(3));
    GM_WRITE(vm, -1, "slimedirection", v3);
    /* @4041116 constant */
    /* @4041120 store */
    GM_WRITE(vm, -1, "hpslimefrozen", VAL(0));
    /* @4041128 load */
    /* @4041136 store */
    GM_WRITE(vm, -1, "hspeed", GM_READ(vm, -1, "slimedirection"));
    /* @4041144 constant */
    /* @4041148 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @4041156 constant */
    /* @4041160 store */
    GM_WRITE(vm, -1, "jumping", VAL(0));
    /* @4041168 load */
    /* @4041176 constant */
    /* @4041180 cmp */
    /* @4041184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_4041320;
    /* @4041188 load */
    /* @4041196 constant */
    /* @4041200 cmp */
    /* @4041204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4041220;
    /* @4041208 constant */
    /* @4041212 store */
    GM_WRITE(vm, -1, "hpslime", VAL(50));
    L_4041220: ;
    /* @4041220 load */
    /* @4041228 constant */
    /* @4041232 cmp */
    /* @4041236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4041252;
    /* @4041240 constant */
    /* @4041244 store */
    GM_WRITE(vm, -1, "hpslime", VAL(46));
    L_4041252: ;
    /* @4041252 load */
    /* @4041260 constant */
    /* @4041264 cmp */
    /* @4041268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4041284;
    /* @4041272 constant */
    /* @4041276 store */
    GM_WRITE(vm, -1, "hpslime", VAL(42));
    L_4041284: ;
    /* @4041284 load */
    /* @4041292 constant */
    /* @4041296 cmp */
    /* @4041300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4041316;
    /* @4041304 constant */
    /* @4041308 store */
    GM_WRITE(vm, -1, "hpslime", VAL(38));
    L_4041316: ;
    /* @4041316 b */
    goto L_4041772;
    L_4041320: ;
    /* @4041320 load */
    /* @4041328 constant */
    /* @4041332 cmp */
    /* @4041336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_4041472;
    /* @4041340 load */
    /* @4041348 constant */
    /* @4041352 cmp */
    /* @4041356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4041372;
    /* @4041360 constant */
    /* @4041364 store */
    GM_WRITE(vm, -1, "hpslime", VAL(55));
    L_4041372: ;
    /* @4041372 load */
    /* @4041380 constant */
    /* @4041384 cmp */
    /* @4041388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4041404;
    /* @4041392 constant */
    /* @4041396 store */
    GM_WRITE(vm, -1, "hpslime", VAL(50));
    L_4041404: ;
    /* @4041404 load */
    /* @4041412 constant */
    /* @4041416 cmp */
    /* @4041420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4041436;
    /* @4041424 constant */
    /* @4041428 store */
    GM_WRITE(vm, -1, "hpslime", VAL(46));
    L_4041436: ;
    /* @4041436 load */
    /* @4041444 constant */
    /* @4041448 cmp */
    /* @4041452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4041468;
    /* @4041456 constant */
    /* @4041460 store */
    GM_WRITE(vm, -1, "hpslime", VAL(41));
    L_4041468: ;
    /* @4041468 b */
    goto L_4041772;
    L_4041472: ;
    /* @4041472 load */
    /* @4041480 constant */
    /* @4041484 cmp */
    /* @4041488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_4041624;
    /* @4041492 load */
    /* @4041500 constant */
    /* @4041504 cmp */
    /* @4041508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4041524;
    /* @4041512 constant */
    /* @4041516 store */
    GM_WRITE(vm, -1, "hpslime", VAL(65));
    L_4041524: ;
    /* @4041524 load */
    /* @4041532 constant */
    /* @4041536 cmp */
    /* @4041540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4041556;
    /* @4041544 constant */
    /* @4041548 store */
    GM_WRITE(vm, -1, "hpslime", VAL(60));
    L_4041556: ;
    /* @4041556 load */
    /* @4041564 constant */
    /* @4041568 cmp */
    /* @4041572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4041588;
    /* @4041576 constant */
    /* @4041580 store */
    GM_WRITE(vm, -1, "hpslime", VAL(55));
    L_4041588: ;
    /* @4041588 load */
    /* @4041596 constant */
    /* @4041600 cmp */
    /* @4041604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4041620;
    /* @4041608 constant */
    /* @4041612 store */
    GM_WRITE(vm, -1, "hpslime", VAL(50));
    L_4041620: ;
    /* @4041620 b */
    goto L_4041772;
    L_4041624: ;
    /* @4041624 load */
    /* @4041632 constant */
    /* @4041636 cmp */
    /* @4041640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_4041772;
    /* @4041644 load */
    /* @4041652 constant */
    /* @4041656 cmp */
    /* @4041660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4041676;
    /* @4041664 constant */
    /* @4041668 store */
    GM_WRITE(vm, -1, "hpslime", VAL(75));
    L_4041676: ;
    /* @4041676 load */
    /* @4041684 constant */
    /* @4041688 cmp */
    /* @4041692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4041708;
    /* @4041696 constant */
    /* @4041700 store */
    GM_WRITE(vm, -1, "hpslime", VAL(70));
    L_4041708: ;
    /* @4041708 load */
    /* @4041716 constant */
    /* @4041720 cmp */
    /* @4041724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4041740;
    /* @4041728 constant */
    /* @4041732 store */
    GM_WRITE(vm, -1, "hpslime", VAL(65));
    L_4041740: ;
    /* @4041740 load */
    /* @4041748 constant */
    /* @4041752 cmp */
    /* @4041756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4041772;
    /* @4041760 constant */
    /* @4041764 store */
    GM_WRITE(vm, -1, "hpslime", VAL(60));
    L_4041772: ;
    return;
}
