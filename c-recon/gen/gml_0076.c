/* generated from CODE 76 (gml_Object_obj_skeleton_Alarm_1), source start 3911144, end 3911516. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0076(GmVM* vm) {
    Val v1;
    /* @3911144 load */
    /* @3911152 constant */
    /* @3911156 cmp */
    /* @3911160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3911168;
    /* @3911164 b */
    goto L_3911516;
    L_3911168: ;
    /* @3911168 load */
    /* @3911176 constant */
    /* @3911180 cmp */
    /* @3911184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3911332;
    /* @3911188 constant */
    /* @3911192 cast */
    /* @3911196 load */
    /* @3911204 constant */
    /* @3911208 sub */
    /* @3911212 load */
    /* @3911220 constant */
    /* @3911224 add */
    /* @3911228 call */
    GM_SITE(vm, 76, 3911228);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3911236 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(15)), VAL(56)));
    /* @3911240 constant */
    /* @3911244 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(111));
    /* @3911252 load */
    /* @3911260 constant */
    /* @3911264 cmp */
    /* @3911268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3911276;
    /* @3911272 b */
    goto L_3911332;
    L_3911276: ;
    /* @3911276 load */
    /* @3911284 constant */
    /* @3911288 cmp */
    /* @3911292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3911332;
    /* @3911296 constant */
    /* @3911300 cast */
    /* @3911304 constant */
    /* @3911308 cast */
    /* @3911312 constant */
    /* @3911316 cast */
    /* @3911320 call */
    GM_SITE(vm, 76, 3911320);
    /* @3911328 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(13), VAL(0), VAL(0)));
    L_3911332: ;
    /* @3911332 load */
    /* @3911340 constant */
    /* @3911344 cmp */
    /* @3911348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3911496;
    /* @3911352 constant */
    /* @3911356 cast */
    /* @3911360 load */
    /* @3911368 constant */
    /* @3911372 sub */
    /* @3911376 load */
    /* @3911384 constant */
    /* @3911388 sub */
    /* @3911392 call */
    GM_SITE(vm, 76, 3911392);
    /* @3911400 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(15)), VAL(56)));
    /* @3911404 constant */
    /* @3911408 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(111));
    /* @3911416 load */
    /* @3911424 constant */
    /* @3911428 cmp */
    /* @3911432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3911440;
    /* @3911436 b */
    goto L_3911496;
    L_3911440: ;
    /* @3911440 load */
    /* @3911448 constant */
    /* @3911452 cmp */
    /* @3911456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3911496;
    /* @3911460 constant */
    /* @3911464 cast */
    /* @3911468 constant */
    /* @3911472 cast */
    /* @3911476 constant */
    /* @3911480 cast */
    /* @3911484 call */
    GM_SITE(vm, 76, 3911484);
    /* @3911492 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(13), VAL(0), VAL(0)));
    L_3911496: ;
    /* @3911496 constant */
    /* @3911500 constant */
    /* @3911504 constant */
    /* @3911508 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(60));
    L_3911516: ;
    return;
}
