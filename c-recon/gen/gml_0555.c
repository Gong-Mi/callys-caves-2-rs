/* generated from CODE 555 (gml_Object_obj_introduction_Draw_0), source start 4846900, end 4847648. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0555(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    /* @4846900 constant */
    /* @4846904 load */
    /* @4846912 cast */
    /* @4846916 load */
    /* @4846924 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4846932 constant */
    /* @4846936 load */
    /* @4846944 cast */
    /* @4846948 load */
    /* @4846956 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4846964 load */
    /* @4846972 constant */
    /* @4846976 cmp */
    /* @4846980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4847076;
    /* @4846984 constant */
    /* @4846988 cast */
    /* @4846992 call */
    GM_SITE(vm, 555, 4846992);
    /* @4847000 cast */
    /* @4847004 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v1)) goto L_4847036;
    /* @4847008 load */
    /* @4847016 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx1"));
    /* @4847024 constant */
    /* @4847028 store */
    GM_WRITE(vm, 136, "y", VAL(-2));
    L_4847036: ;
    /* @4847036 constant */
    /* @4847040 cast */
    /* @4847044 call */
    GM_SITE(vm, 555, 4847044);
    /* @4847052 cast */
    /* @4847056 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v2)) goto L_4847076;
    /* @4847060 load */
    /* @4847068 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x1"));
    L_4847076: ;
    /* @4847076 load */
    /* @4847084 constant */
    /* @4847088 cmp */
    /* @4847092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4847176;
    /* @4847096 constant */
    /* @4847100 cast */
    /* @4847104 call */
    GM_SITE(vm, 555, 4847104);
    /* @4847112 cast */
    /* @4847116 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v3)) goto L_4847136;
    /* @4847120 load */
    /* @4847128 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx2"));
    L_4847136: ;
    /* @4847136 constant */
    /* @4847140 cast */
    /* @4847144 call */
    GM_SITE(vm, 555, 4847144);
    /* @4847152 cast */
    /* @4847156 bf */
    v4 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v4)) goto L_4847176;
    /* @4847160 load */
    /* @4847168 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x2"));
    L_4847176: ;
    /* @4847176 load */
    /* @4847184 constant */
    /* @4847188 cmp */
    /* @4847192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4847300;
    /* @4847196 constant */
    /* @4847200 cast */
    /* @4847204 call */
    GM_SITE(vm, 555, 4847204);
    /* @4847212 cast */
    /* @4847216 bf */
    v5 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v5)) goto L_4847248;
    /* @4847220 load */
    /* @4847228 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx3"));
    /* @4847236 constant */
    /* @4847240 store */
    GM_WRITE(vm, 136, "y", VAL(30));
    L_4847248: ;
    /* @4847248 constant */
    /* @4847252 cast */
    /* @4847256 call */
    GM_SITE(vm, 555, 4847256);
    /* @4847264 cast */
    /* @4847268 bf */
    v6 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v6)) goto L_4847300;
    /* @4847272 load */
    /* @4847280 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x3"));
    /* @4847288 constant */
    /* @4847292 store */
    GM_WRITE(vm, 135, "y", VAL(70));
    L_4847300: ;
    /* @4847300 load */
    /* @4847308 constant */
    /* @4847312 cmp */
    /* @4847316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4847424;
    /* @4847320 constant */
    /* @4847324 cast */
    /* @4847328 call */
    GM_SITE(vm, 555, 4847328);
    /* @4847336 cast */
    /* @4847340 bf */
    v7 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v7)) goto L_4847372;
    /* @4847344 load */
    /* @4847352 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx4"));
    /* @4847360 constant */
    /* @4847364 store */
    GM_WRITE(vm, 136, "y", VAL(30));
    L_4847372: ;
    /* @4847372 constant */
    /* @4847376 cast */
    /* @4847380 call */
    GM_SITE(vm, 555, 4847380);
    /* @4847388 cast */
    /* @4847392 bf */
    v8 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v8)) goto L_4847424;
    /* @4847396 load */
    /* @4847404 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x4"));
    /* @4847412 constant */
    /* @4847416 store */
    GM_WRITE(vm, 135, "y", VAL(70));
    L_4847424: ;
    /* @4847424 load */
    /* @4847432 constant */
    /* @4847436 cmp */
    /* @4847440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4847536;
    /* @4847444 constant */
    /* @4847448 cast */
    /* @4847452 call */
    GM_SITE(vm, 555, 4847452);
    /* @4847460 cast */
    /* @4847464 bf */
    v9 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v9)) goto L_4847496;
    /* @4847468 load */
    /* @4847476 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx1"));
    /* @4847484 constant */
    /* @4847488 store */
    GM_WRITE(vm, 136, "y", VAL(-2));
    L_4847496: ;
    /* @4847496 constant */
    /* @4847500 cast */
    /* @4847504 call */
    GM_SITE(vm, 555, 4847504);
    /* @4847512 cast */
    /* @4847516 bf */
    v10 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v10)) goto L_4847536;
    /* @4847520 load */
    /* @4847528 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x1"));
    L_4847536: ;
    /* @4847536 load */
    /* @4847544 constant */
    /* @4847548 cmp */
    /* @4847552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4847648;
    /* @4847556 constant */
    /* @4847560 cast */
    /* @4847564 call */
    GM_SITE(vm, 555, 4847564);
    /* @4847572 cast */
    /* @4847576 bf */
    v11 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v11)) goto L_4847608;
    /* @4847580 load */
    /* @4847588 store */
    GM_WRITE(vm, 136, "x", GM_READ(vm, -1, "xx1"));
    /* @4847596 constant */
    /* @4847600 store */
    GM_WRITE(vm, 136, "y", VAL(-2));
    L_4847608: ;
    /* @4847608 constant */
    /* @4847612 cast */
    /* @4847616 call */
    GM_SITE(vm, 555, 4847616);
    /* @4847624 cast */
    /* @4847628 bf */
    v12 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v12)) goto L_4847648;
    /* @4847632 load */
    /* @4847640 store */
    GM_WRITE(vm, 135, "x", GM_READ(vm, -1, "x1"));
    L_4847648: ;
    return;
}
