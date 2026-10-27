/* generated from CODE 135 (gml_Object_obj_wolf_Create_0), source start 3957660, end 3958492. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0135(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3957660 constant */
    /* @3957664 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3957672 constant */
    /* @3957676 store */
    GM_WRITE(vm, -1, "jumping", VAL(0));
    /* @3957684 constant */
    /* @3957688 cast */
    /* @3957692 constant */
    /* @3957696 cast */
    /* @3957700 constant */
    /* @3957704 cast */
    /* @3957708 constant */
    /* @3957712 cast */
    /* @3957716 constant */
    /* @3957720 cast */
    /* @3957724 call */
    GM_SITE(vm, 135, 3957724);
    /* @3957732 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3957740 constant */
    /* @3957744 cast */
    /* @3957748 constant */
    /* @3957752 cast */
    /* @3957756 constant */
    /* @3957760 cast */
    /* @3957764 constant */
    /* @3957768 cast */
    /* @3957772 constant */
    /* @3957776 cast */
    /* @3957780 call */
    GM_SITE(vm, 135, 3957780);
    /* @3957788 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3957796 constant */
    /* @3957800 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3957808 constant */
    /* @3957812 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3957820 constant */
    /* @3957824 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3957832 constant */
    /* @3957836 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3957844 constant */
    /* @3957848 store */
    GM_WRITE(vm, -1, "hpwolffrozen", VAL(0));
    /* @3957856 constant */
    /* @3957860 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3957868 constant */
    /* @3957872 constant */
    /* @3957876 constant */
    /* @3957880 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(15));
    /* @3957888 load */
    /* @3957896 constant */
    /* @3957900 cmp */
    /* @3957904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3958040;
    /* @3957908 load */
    /* @3957916 constant */
    /* @3957920 cmp */
    /* @3957924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3957940;
    /* @3957928 constant */
    /* @3957932 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(40));
    L_3957940: ;
    /* @3957940 load */
    /* @3957948 constant */
    /* @3957952 cmp */
    /* @3957956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3957972;
    /* @3957960 constant */
    /* @3957964 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(38));
    L_3957972: ;
    /* @3957972 load */
    /* @3957980 constant */
    /* @3957984 cmp */
    /* @3957988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3958004;
    /* @3957992 constant */
    /* @3957996 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(36));
    L_3958004: ;
    /* @3958004 load */
    /* @3958012 constant */
    /* @3958016 cmp */
    /* @3958020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3958036;
    /* @3958024 constant */
    /* @3958028 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(33));
    L_3958036: ;
    /* @3958036 b */
    goto L_3958492;
    L_3958040: ;
    /* @3958040 load */
    /* @3958048 constant */
    /* @3958052 cmp */
    /* @3958056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(9)))) goto L_3958192;
    /* @3958060 load */
    /* @3958068 constant */
    /* @3958072 cmp */
    /* @3958076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3958092;
    /* @3958080 constant */
    /* @3958084 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(44));
    L_3958092: ;
    /* @3958092 load */
    /* @3958100 constant */
    /* @3958104 cmp */
    /* @3958108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3958124;
    /* @3958112 constant */
    /* @3958116 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(40));
    L_3958124: ;
    /* @3958124 load */
    /* @3958132 constant */
    /* @3958136 cmp */
    /* @3958140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3958156;
    /* @3958144 constant */
    /* @3958148 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(38));
    L_3958156: ;
    /* @3958156 load */
    /* @3958164 constant */
    /* @3958168 cmp */
    /* @3958172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3958188;
    /* @3958176 constant */
    /* @3958180 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(35));
    L_3958188: ;
    /* @3958188 b */
    goto L_3958492;
    L_3958192: ;
    /* @3958192 load */
    /* @3958200 constant */
    /* @3958204 cmp */
    /* @3958208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3958344;
    /* @3958212 load */
    /* @3958220 constant */
    /* @3958224 cmp */
    /* @3958228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3958244;
    /* @3958232 constant */
    /* @3958236 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(55));
    L_3958244: ;
    /* @3958244 load */
    /* @3958252 constant */
    /* @3958256 cmp */
    /* @3958260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3958276;
    /* @3958264 constant */
    /* @3958268 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(51));
    L_3958276: ;
    /* @3958276 load */
    /* @3958284 constant */
    /* @3958288 cmp */
    /* @3958292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3958308;
    /* @3958296 constant */
    /* @3958300 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(48));
    L_3958308: ;
    /* @3958308 load */
    /* @3958316 constant */
    /* @3958320 cmp */
    /* @3958324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3958340;
    /* @3958328 constant */
    /* @3958332 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(45));
    L_3958340: ;
    /* @3958340 b */
    goto L_3958492;
    L_3958344: ;
    /* @3958344 load */
    /* @3958352 constant */
    /* @3958356 cmp */
    /* @3958360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3958492;
    /* @3958364 load */
    /* @3958372 constant */
    /* @3958376 cmp */
    /* @3958380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3958396;
    /* @3958384 constant */
    /* @3958388 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(65));
    L_3958396: ;
    /* @3958396 load */
    /* @3958404 constant */
    /* @3958408 cmp */
    /* @3958412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3958428;
    /* @3958416 constant */
    /* @3958420 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(60));
    L_3958428: ;
    /* @3958428 load */
    /* @3958436 constant */
    /* @3958440 cmp */
    /* @3958444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3958460;
    /* @3958448 constant */
    /* @3958452 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(55));
    L_3958460: ;
    /* @3958460 load */
    /* @3958468 constant */
    /* @3958472 cmp */
    /* @3958476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3958492;
    /* @3958480 constant */
    /* @3958484 store */
    GM_WRITE(vm, -1, "hpwolf", VAL(50));
    L_3958492: ;
    return;
}
