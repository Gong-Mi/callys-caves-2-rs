/* generated from CODE 29 (gml_Object_obj_bossboulder_Alarm_0), source start 3866992, end 3867684. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0029(GmVM* vm) {
    Val p3867036_0;
    Val p3867088_0;
    Val p3867148_0;
    Val p3867200_0;
    Val p3867260_0;
    Val p3867312_0;
    Val p3867372_0;
    Val p3867424_0;
    Val p3867484_0;
    Val p3867536_0;
    Val p3867596_0;
    Val p3867648_0;
    /* @3866992 load */
    /* @3867000 constant */
    /* @3867004 cmp */
    /* @3867008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3867032;
    /* @3867012 load */
    /* @3867020 constant */
    /* @3867024 cmp */
    /* @3867028 b */
    p3867036_0 = NUMBOOL(GM_READ(vm, -5, "boss1dead") == VAL(0));
    goto L_3867036;
    L_3867032: ;
    /* @3867032 constant */
    p3867036_0 = VAL(0);
    L_3867036: ;
    /* @3867036 bf */
    if (!TRUTH(p3867036_0)) goto L_3867044;
    /* @3867040 b */
    goto L_3867104;
    L_3867044: ;
    /* @3867044 load */
    /* @3867052 constant */
    /* @3867056 cmp */
    /* @3867060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_3867084;
    /* @3867064 load */
    /* @3867072 constant */
    /* @3867076 cmp */
    /* @3867080 b */
    p3867088_0 = NUMBOOL(GM_READ(vm, -5, "boss1dead") == VAL(1));
    goto L_3867088;
    L_3867084: ;
    /* @3867084 constant */
    p3867088_0 = VAL(0);
    L_3867088: ;
    /* @3867088 bf */
    if (!TRUTH(p3867088_0)) goto L_3867104;
    /* @3867092 call */
    GM_SITE(vm, 29, 3867092);
    /* @3867100 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867104: ;
    /* @3867104 load */
    /* @3867112 constant */
    /* @3867116 cmp */
    /* @3867120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3867144;
    /* @3867124 load */
    /* @3867132 constant */
    /* @3867136 cmp */
    /* @3867140 b */
    p3867148_0 = NUMBOOL(GM_READ(vm, -5, "boss2dead") == VAL(0));
    goto L_3867148;
    L_3867144: ;
    /* @3867144 constant */
    p3867148_0 = VAL(0);
    L_3867148: ;
    /* @3867148 bf */
    if (!TRUTH(p3867148_0)) goto L_3867156;
    /* @3867152 b */
    goto L_3867216;
    L_3867156: ;
    /* @3867156 load */
    /* @3867164 constant */
    /* @3867168 cmp */
    /* @3867172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_3867196;
    /* @3867176 load */
    /* @3867184 constant */
    /* @3867188 cmp */
    /* @3867192 b */
    p3867200_0 = NUMBOOL(GM_READ(vm, -5, "boss2dead") == VAL(1));
    goto L_3867200;
    L_3867196: ;
    /* @3867196 constant */
    p3867200_0 = VAL(0);
    L_3867200: ;
    /* @3867200 bf */
    if (!TRUTH(p3867200_0)) goto L_3867216;
    /* @3867204 call */
    GM_SITE(vm, 29, 3867204);
    /* @3867212 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867216: ;
    /* @3867216 load */
    /* @3867224 constant */
    /* @3867228 cmp */
    /* @3867232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3867256;
    /* @3867236 load */
    /* @3867244 constant */
    /* @3867248 cmp */
    /* @3867252 b */
    p3867260_0 = NUMBOOL(GM_READ(vm, -5, "boss3dead") == VAL(0));
    goto L_3867260;
    L_3867256: ;
    /* @3867256 constant */
    p3867260_0 = VAL(0);
    L_3867260: ;
    /* @3867260 bf */
    if (!TRUTH(p3867260_0)) goto L_3867268;
    /* @3867264 b */
    goto L_3867328;
    L_3867268: ;
    /* @3867268 load */
    /* @3867276 constant */
    /* @3867280 cmp */
    /* @3867284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_3867308;
    /* @3867288 load */
    /* @3867296 constant */
    /* @3867300 cmp */
    /* @3867304 b */
    p3867312_0 = NUMBOOL(GM_READ(vm, -5, "boss3dead") == VAL(1));
    goto L_3867312;
    L_3867308: ;
    /* @3867308 constant */
    p3867312_0 = VAL(0);
    L_3867312: ;
    /* @3867312 bf */
    if (!TRUTH(p3867312_0)) goto L_3867328;
    /* @3867316 call */
    GM_SITE(vm, 29, 3867316);
    /* @3867324 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867328: ;
    /* @3867328 load */
    /* @3867336 constant */
    /* @3867340 cmp */
    /* @3867344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3867368;
    /* @3867348 load */
    /* @3867356 constant */
    /* @3867360 cmp */
    /* @3867364 b */
    p3867372_0 = NUMBOOL(GM_READ(vm, -5, "boss4dead") == VAL(0));
    goto L_3867372;
    L_3867368: ;
    /* @3867368 constant */
    p3867372_0 = VAL(0);
    L_3867372: ;
    /* @3867372 bf */
    if (!TRUTH(p3867372_0)) goto L_3867380;
    /* @3867376 b */
    goto L_3867440;
    L_3867380: ;
    /* @3867380 load */
    /* @3867388 constant */
    /* @3867392 cmp */
    /* @3867396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_3867420;
    /* @3867400 load */
    /* @3867408 constant */
    /* @3867412 cmp */
    /* @3867416 b */
    p3867424_0 = NUMBOOL(GM_READ(vm, -5, "boss4dead") == VAL(1));
    goto L_3867424;
    L_3867420: ;
    /* @3867420 constant */
    p3867424_0 = VAL(0);
    L_3867424: ;
    /* @3867424 bf */
    if (!TRUTH(p3867424_0)) goto L_3867440;
    /* @3867428 call */
    GM_SITE(vm, 29, 3867428);
    /* @3867436 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867440: ;
    /* @3867440 load */
    /* @3867448 constant */
    /* @3867452 cmp */
    /* @3867456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3867480;
    /* @3867460 load */
    /* @3867468 constant */
    /* @3867472 cmp */
    /* @3867476 b */
    p3867484_0 = NUMBOOL(GM_READ(vm, -5, "boss5dead") == VAL(0));
    goto L_3867484;
    L_3867480: ;
    /* @3867480 constant */
    p3867484_0 = VAL(0);
    L_3867484: ;
    /* @3867484 bf */
    if (!TRUTH(p3867484_0)) goto L_3867492;
    /* @3867488 b */
    goto L_3867552;
    L_3867492: ;
    /* @3867492 load */
    /* @3867500 constant */
    /* @3867504 cmp */
    /* @3867508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_3867532;
    /* @3867512 load */
    /* @3867520 constant */
    /* @3867524 cmp */
    /* @3867528 b */
    p3867536_0 = NUMBOOL(GM_READ(vm, -5, "boss5dead") == VAL(1));
    goto L_3867536;
    L_3867532: ;
    /* @3867532 constant */
    p3867536_0 = VAL(0);
    L_3867536: ;
    /* @3867536 bf */
    if (!TRUTH(p3867536_0)) goto L_3867552;
    /* @3867540 call */
    GM_SITE(vm, 29, 3867540);
    /* @3867548 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867552: ;
    /* @3867552 load */
    /* @3867560 constant */
    /* @3867564 cmp */
    /* @3867568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3867592;
    /* @3867572 load */
    /* @3867580 constant */
    /* @3867584 cmp */
    /* @3867588 b */
    p3867596_0 = NUMBOOL(GM_READ(vm, -5, "boss6dead") == VAL(0));
    goto L_3867596;
    L_3867592: ;
    /* @3867592 constant */
    p3867596_0 = VAL(0);
    L_3867596: ;
    /* @3867596 bf */
    if (!TRUTH(p3867596_0)) goto L_3867604;
    /* @3867600 b */
    goto L_3867664;
    L_3867604: ;
    /* @3867604 load */
    /* @3867612 constant */
    /* @3867616 cmp */
    /* @3867620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_3867644;
    /* @3867624 load */
    /* @3867632 constant */
    /* @3867636 cmp */
    /* @3867640 b */
    p3867648_0 = NUMBOOL(GM_READ(vm, -5, "boss6dead") == VAL(1));
    goto L_3867648;
    L_3867644: ;
    /* @3867644 constant */
    p3867648_0 = VAL(0);
    L_3867648: ;
    /* @3867648 bf */
    if (!TRUTH(p3867648_0)) goto L_3867664;
    /* @3867652 call */
    GM_SITE(vm, 29, 3867652);
    /* @3867660 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3867664: ;
    /* @3867664 constant */
    /* @3867668 constant */
    /* @3867672 constant */
    /* @3867676 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_3867684: ;
    return;
}
