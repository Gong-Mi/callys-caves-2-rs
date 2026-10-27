/* generated from CODE 376 (gml_Object_obj_music_Alarm_0), source start 4494908, end 4495688. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0376(GmVM* vm) {
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
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    /* @4494908 load */
    /* @4494916 constant */
    /* @4494920 cmp */
    /* @4494924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4494932;
    /* @4494928 b */
    goto L_4495688;
    L_4494932: ;
    /* @4494932 load */
    /* @4494940 constant */
    /* @4494944 cmp */
    /* @4494948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4495688;
    /* @4494952 constant */
    /* @4494956 cast */
    /* @4494960 call */
    GM_SITE(vm, 376, 4494960);
    /* @4494968 cast */
    /* @4494972 not */
    /* @4494976 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(29))));
    if (!TRUTH(v1)) goto L_4495688;
    /* @4494980 constant */
    /* @4494984 cast */
    /* @4494988 call */
    GM_SITE(vm, 376, 4494988);
    /* @4494996 cast */
    /* @4495000 not */
    /* @4495004 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(30))));
    if (!TRUTH(v2)) goto L_4495688;
    /* @4495008 constant */
    /* @4495012 cast */
    /* @4495016 call */
    GM_SITE(vm, 376, 4495016);
    /* @4495024 cast */
    /* @4495028 not */
    /* @4495032 bf */
    v3 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(31))));
    if (!TRUTH(v3)) goto L_4495688;
    /* @4495036 constant */
    /* @4495040 cast */
    /* @4495044 call */
    GM_SITE(vm, 376, 4495044);
    /* @4495052 cast */
    /* @4495056 not */
    /* @4495060 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(32))));
    if (!TRUTH(v4)) goto L_4495688;
    /* @4495064 constant */
    /* @4495068 cast */
    /* @4495072 call */
    GM_SITE(vm, 376, 4495072);
    /* @4495080 cast */
    /* @4495084 not */
    /* @4495088 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(33))));
    if (!TRUTH(v5)) goto L_4495688;
    /* @4495092 constant */
    /* @4495096 cast */
    /* @4495100 call */
    GM_SITE(vm, 376, 4495100);
    /* @4495108 cast */
    /* @4495112 not */
    /* @4495116 bf */
    v6 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(34))));
    if (!TRUTH(v6)) goto L_4495688;
    /* @4495120 constant */
    /* @4495124 cast */
    /* @4495128 call */
    GM_SITE(vm, 376, 4495128);
    /* @4495136 cast */
    /* @4495140 not */
    /* @4495144 bf */
    v7 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(35))));
    if (!TRUTH(v7)) goto L_4495688;
    /* @4495148 constant */
    /* @4495152 cast */
    /* @4495156 call */
    GM_SITE(vm, 376, 4495156);
    /* @4495164 cast */
    /* @4495168 not */
    /* @4495172 bf */
    v8 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(36))));
    if (!TRUTH(v8)) goto L_4495688;
    /* @4495176 constant */
    /* @4495180 cast */
    /* @4495184 call */
    GM_SITE(vm, 376, 4495184);
    /* @4495192 cast */
    /* @4495196 not */
    /* @4495200 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(37))));
    if (!TRUTH(v9)) goto L_4495688;
    /* @4495204 constant */
    /* @4495208 cast */
    /* @4495212 call */
    GM_SITE(vm, 376, 4495212);
    /* @4495220 cast */
    /* @4495224 not */
    /* @4495228 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(38))));
    if (!TRUTH(v10)) goto L_4495688;
    /* @4495232 constant */
    /* @4495236 cast */
    /* @4495240 call */
    GM_SITE(vm, 376, 4495240);
    /* @4495248 cast */
    /* @4495252 not */
    /* @4495256 bf */
    v11 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(39))));
    if (!TRUTH(v11)) goto L_4495688;
    /* @4495260 constant */
    /* @4495264 cast */
    /* @4495268 call */
    GM_SITE(vm, 376, 4495268);
    /* @4495276 cast */
    /* @4495280 not */
    /* @4495284 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(40))));
    if (!TRUTH(v12)) goto L_4495688;
    /* @4495288 constant */
    /* @4495292 cast */
    /* @4495296 call */
    GM_SITE(vm, 376, 4495296);
    /* @4495304 cast */
    /* @4495308 not */
    /* @4495312 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(41))));
    if (!TRUTH(v13)) goto L_4495688;
    /* @4495316 constant */
    /* @4495320 cast */
    /* @4495324 call */
    GM_SITE(vm, 376, 4495324);
    /* @4495332 cast */
    /* @4495336 not */
    /* @4495340 bf */
    v14 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(42))));
    if (!TRUTH(v14)) goto L_4495688;
    /* @4495344 constant */
    /* @4495348 cast */
    /* @4495352 call */
    GM_SITE(vm, 376, 4495352);
    /* @4495360 cast */
    /* @4495364 not */
    /* @4495368 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(43))));
    if (!TRUTH(v15)) goto L_4495688;
    /* @4495372 constant */
    /* @4495376 cast */
    /* @4495380 call */
    GM_SITE(vm, 376, 4495380);
    /* @4495388 cast */
    /* @4495392 not */
    /* @4495396 bf */
    v16 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(44))));
    if (!TRUTH(v16)) goto L_4495688;
    /* @4495400 constant */
    /* @4495404 cast */
    /* @4495408 call */
    GM_SITE(vm, 376, 4495408);
    /* @4495416 cast */
    /* @4495420 not */
    /* @4495424 bf */
    v17 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(45))));
    if (!TRUTH(v17)) goto L_4495688;
    /* @4495428 constant */
    /* @4495432 cast */
    /* @4495436 call */
    GM_SITE(vm, 376, 4495436);
    /* @4495444 cast */
    /* @4495448 not */
    /* @4495452 bf */
    v18 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(46))));
    if (!TRUTH(v18)) goto L_4495688;
    /* @4495456 constant */
    /* @4495460 cast */
    /* @4495464 call */
    GM_SITE(vm, 376, 4495464);
    /* @4495472 cast */
    /* @4495476 not */
    /* @4495480 bf */
    v19 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(47))));
    if (!TRUTH(v19)) goto L_4495688;
    /* @4495484 constant */
    /* @4495488 cast */
    /* @4495492 call */
    GM_SITE(vm, 376, 4495492);
    /* @4495500 cast */
    /* @4495504 not */
    /* @4495508 bf */
    v20 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(48))));
    if (!TRUTH(v20)) goto L_4495688;
    /* @4495512 constant */
    /* @4495516 cast */
    /* @4495520 call */
    GM_SITE(vm, 376, 4495520);
    /* @4495528 cast */
    /* @4495532 not */
    /* @4495536 bf */
    v21 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(49))));
    if (!TRUTH(v21)) goto L_4495688;
    /* @4495540 constant */
    /* @4495544 cast */
    /* @4495548 call */
    GM_SITE(vm, 376, 4495548);
    /* @4495556 cast */
    /* @4495560 not */
    /* @4495564 bf */
    v22 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(50))));
    if (!TRUTH(v22)) goto L_4495688;
    /* @4495568 constant */
    /* @4495572 cast */
    /* @4495576 call */
    GM_SITE(vm, 376, 4495576);
    /* @4495584 cast */
    /* @4495588 not */
    /* @4495592 bf */
    v23 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(51))));
    if (!TRUTH(v23)) goto L_4495688;
    /* @4495596 constant */
    /* @4495600 cast */
    /* @4495604 call */
    GM_SITE(vm, 376, 4495604);
    /* @4495612 cast */
    /* @4495616 not */
    /* @4495620 bf */
    v24 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(52))));
    if (!TRUTH(v24)) goto L_4495676;
    /* @4495624 constant */
    /* @4495628 cast */
    /* @4495632 constant */
    /* @4495636 cast */
    /* @4495640 constant */
    /* @4495644 load */
    /* @4495652 cast */
    /* @4495656 load */
    /* @4495664 call */
    GM_SITE(vm, 376, 4495664);
    /* @4495672 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ_ARR(vm, VAL(-1), "theme", TO_INT(GM_READ(vm, -1, "soundplay"))), VAL(0), VAL(0)));
    L_4495676: ;
    /* @4495676 constant */
    /* @4495680 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    L_4495688: ;
    return;
}
