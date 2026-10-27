/* generated from CODE 377 (gml_Object_obj_music_Step_0), source start 4495688, end 4496544. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0377(GmVM* vm) {
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
    Val v25;
    /* @4495688 load */
    /* @4495696 constant */
    /* @4495700 cmp */
    /* @4495704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "soundplay") >= VAL(16)))) goto L_4495720;
    /* @4495708 constant */
    /* @4495712 store */
    GM_WRITE(vm, -1, "soundplay", VAL(0));
    L_4495720: ;
    /* @4495720 load */
    /* @4495728 constant */
    /* @4495732 cmp */
    /* @4495736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "soundplay") < VAL(0)))) goto L_4495752;
    /* @4495740 constant */
    /* @4495744 store */
    GM_WRITE(vm, -1, "soundplay", VAL(16));
    L_4495752: ;
    /* @4495752 load */
    /* @4495760 constant */
    /* @4495764 cmp */
    /* @4495768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4495776;
    /* @4495772 b */
    goto L_4496544;
    L_4495776: ;
    /* @4495776 load */
    /* @4495784 constant */
    /* @4495788 cmp */
    /* @4495792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4496544;
    /* @4495796 constant */
    /* @4495800 cast */
    /* @4495804 call */
    GM_SITE(vm, 377, 4495804);
    /* @4495812 cast */
    /* @4495816 not */
    /* @4495820 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(29))));
    if (!TRUTH(v1)) goto L_4496544;
    /* @4495824 constant */
    /* @4495828 cast */
    /* @4495832 call */
    GM_SITE(vm, 377, 4495832);
    /* @4495840 cast */
    /* @4495844 not */
    /* @4495848 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(30))));
    if (!TRUTH(v2)) goto L_4496544;
    /* @4495852 constant */
    /* @4495856 cast */
    /* @4495860 call */
    GM_SITE(vm, 377, 4495860);
    /* @4495868 cast */
    /* @4495872 not */
    /* @4495876 bf */
    v3 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(31))));
    if (!TRUTH(v3)) goto L_4496544;
    /* @4495880 constant */
    /* @4495884 cast */
    /* @4495888 call */
    GM_SITE(vm, 377, 4495888);
    /* @4495896 cast */
    /* @4495900 not */
    /* @4495904 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(32))));
    if (!TRUTH(v4)) goto L_4496544;
    /* @4495908 constant */
    /* @4495912 cast */
    /* @4495916 call */
    GM_SITE(vm, 377, 4495916);
    /* @4495924 cast */
    /* @4495928 not */
    /* @4495932 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(33))));
    if (!TRUTH(v5)) goto L_4496544;
    /* @4495936 constant */
    /* @4495940 cast */
    /* @4495944 call */
    GM_SITE(vm, 377, 4495944);
    /* @4495952 cast */
    /* @4495956 not */
    /* @4495960 bf */
    v6 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(34))));
    if (!TRUTH(v6)) goto L_4496544;
    /* @4495964 constant */
    /* @4495968 cast */
    /* @4495972 call */
    GM_SITE(vm, 377, 4495972);
    /* @4495980 cast */
    /* @4495984 not */
    /* @4495988 bf */
    v7 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(35))));
    if (!TRUTH(v7)) goto L_4496544;
    /* @4495992 constant */
    /* @4495996 cast */
    /* @4496000 call */
    GM_SITE(vm, 377, 4496000);
    /* @4496008 cast */
    /* @4496012 not */
    /* @4496016 bf */
    v8 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(36))));
    if (!TRUTH(v8)) goto L_4496544;
    /* @4496020 constant */
    /* @4496024 cast */
    /* @4496028 call */
    GM_SITE(vm, 377, 4496028);
    /* @4496036 cast */
    /* @4496040 not */
    /* @4496044 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(37))));
    if (!TRUTH(v9)) goto L_4496544;
    /* @4496048 constant */
    /* @4496052 cast */
    /* @4496056 call */
    GM_SITE(vm, 377, 4496056);
    /* @4496064 cast */
    /* @4496068 not */
    /* @4496072 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(38))));
    if (!TRUTH(v10)) goto L_4496544;
    /* @4496076 constant */
    /* @4496080 cast */
    /* @4496084 call */
    GM_SITE(vm, 377, 4496084);
    /* @4496092 cast */
    /* @4496096 not */
    /* @4496100 bf */
    v11 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(39))));
    if (!TRUTH(v11)) goto L_4496544;
    /* @4496104 constant */
    /* @4496108 cast */
    /* @4496112 call */
    GM_SITE(vm, 377, 4496112);
    /* @4496120 cast */
    /* @4496124 not */
    /* @4496128 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(40))));
    if (!TRUTH(v12)) goto L_4496544;
    /* @4496132 constant */
    /* @4496136 cast */
    /* @4496140 call */
    GM_SITE(vm, 377, 4496140);
    /* @4496148 cast */
    /* @4496152 not */
    /* @4496156 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(41))));
    if (!TRUTH(v13)) goto L_4496544;
    /* @4496160 constant */
    /* @4496164 cast */
    /* @4496168 call */
    GM_SITE(vm, 377, 4496168);
    /* @4496176 cast */
    /* @4496180 not */
    /* @4496184 bf */
    v14 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(42))));
    if (!TRUTH(v14)) goto L_4496544;
    /* @4496188 constant */
    /* @4496192 cast */
    /* @4496196 call */
    GM_SITE(vm, 377, 4496196);
    /* @4496204 cast */
    /* @4496208 not */
    /* @4496212 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(43))));
    if (!TRUTH(v15)) goto L_4496544;
    /* @4496216 constant */
    /* @4496220 cast */
    /* @4496224 call */
    GM_SITE(vm, 377, 4496224);
    /* @4496232 cast */
    /* @4496236 not */
    /* @4496240 bf */
    v16 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(44))));
    if (!TRUTH(v16)) goto L_4496544;
    /* @4496244 constant */
    /* @4496248 cast */
    /* @4496252 call */
    GM_SITE(vm, 377, 4496252);
    /* @4496260 cast */
    /* @4496264 not */
    /* @4496268 bf */
    v17 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(45))));
    if (!TRUTH(v17)) goto L_4496544;
    /* @4496272 constant */
    /* @4496276 cast */
    /* @4496280 call */
    GM_SITE(vm, 377, 4496280);
    /* @4496288 cast */
    /* @4496292 not */
    /* @4496296 bf */
    v18 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(46))));
    if (!TRUTH(v18)) goto L_4496544;
    /* @4496300 constant */
    /* @4496304 cast */
    /* @4496308 call */
    GM_SITE(vm, 377, 4496308);
    /* @4496316 cast */
    /* @4496320 not */
    /* @4496324 bf */
    v19 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(47))));
    if (!TRUTH(v19)) goto L_4496544;
    /* @4496328 constant */
    /* @4496332 cast */
    /* @4496336 call */
    GM_SITE(vm, 377, 4496336);
    /* @4496344 cast */
    /* @4496348 not */
    /* @4496352 bf */
    v20 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(48))));
    if (!TRUTH(v20)) goto L_4496544;
    /* @4496356 constant */
    /* @4496360 cast */
    /* @4496364 call */
    GM_SITE(vm, 377, 4496364);
    /* @4496372 cast */
    /* @4496376 not */
    /* @4496380 bf */
    v21 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(49))));
    if (!TRUTH(v21)) goto L_4496544;
    /* @4496384 constant */
    /* @4496388 cast */
    /* @4496392 call */
    GM_SITE(vm, 377, 4496392);
    /* @4496400 cast */
    /* @4496404 not */
    /* @4496408 bf */
    v22 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(50))));
    if (!TRUTH(v22)) goto L_4496544;
    /* @4496412 constant */
    /* @4496416 cast */
    /* @4496420 call */
    GM_SITE(vm, 377, 4496420);
    /* @4496428 cast */
    /* @4496432 not */
    /* @4496436 bf */
    v23 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(51))));
    if (!TRUTH(v23)) goto L_4496544;
    /* @4496440 constant */
    /* @4496444 cast */
    /* @4496448 call */
    GM_SITE(vm, 377, 4496448);
    /* @4496456 cast */
    /* @4496460 not */
    /* @4496464 bf */
    v24 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(52))));
    if (!TRUTH(v24)) goto L_4496544;
    /* @4496468 load */
    /* @4496476 constant */
    /* @4496480 add */
    /* @4496484 store */
    v25 = GM_ADD(GM_READ(vm, -1, "soundplay"), VAL(1));
    GM_WRITE(vm, -1, "soundplay", v25);
    /* @4496492 constant */
    /* @4496496 cast */
    /* @4496500 constant */
    /* @4496504 cast */
    /* @4496508 constant */
    /* @4496512 load */
    /* @4496520 cast */
    /* @4496524 load */
    /* @4496532 call */
    GM_SITE(vm, 377, 4496532);
    /* @4496540 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, GM_READ_ARR(vm, VAL(-1), "theme", TO_INT(GM_READ(vm, -1, "soundplay"))), VAL(0), VAL(0)));
    L_4496544: ;
    return;
}
