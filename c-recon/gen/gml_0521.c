/* generated from CODE 521 (gml_Object_obj_jumpbutton_Alarm_1), source start 4808932, end 4809364. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0521(GmVM* vm) {
    Val p4809244_0;
    /* @4808932 load */
    /* @4808940 cast */
    /* @4808944 bf */
    if (!TRUTH(BOOL(GM_READ(vm, 0, "grounded")))) goto L_4809056;
    /* @4808948 constant */
    /* @4808952 store */
    GM_WRITE(vm, 0, "vsp", VAL(-12));
    /* @4808960 load */
    /* @4808968 constant */
    /* @4808972 cmp */
    /* @4808976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4808984;
    /* @4808980 b */
    goto L_4809040;
    L_4808984: ;
    /* @4808984 load */
    /* @4808992 constant */
    /* @4808996 cmp */
    /* @4809000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4809040;
    /* @4809004 constant */
    /* @4809008 cast */
    /* @4809012 constant */
    /* @4809016 cast */
    /* @4809020 constant */
    /* @4809024 cast */
    /* @4809028 call */
    GM_SITE(vm, 521, 4809028);
    /* @4809036 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(3), VAL(0), VAL(0)));
    L_4809040: ;
    /* @4809040 constant */
    /* @4809044 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(32));
    /* @4809052 b */
    goto L_4809364;
    L_4809056: ;
    /* @4809056 load */
    /* @4809064 cast */
    /* @4809068 bf */
    if (!TRUTH(BOOL(GM_READ(vm, 0, "djump")))) goto L_4809204;
    /* @4809072 constant */
    /* @4809076 store */
    GM_WRITE(vm, 0, "vsp", VAL(-9));
    /* @4809084 load */
    /* @4809092 constant */
    /* @4809096 cmp */
    /* @4809100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4809108;
    /* @4809104 b */
    goto L_4809164;
    L_4809108: ;
    /* @4809108 load */
    /* @4809116 constant */
    /* @4809120 cmp */
    /* @4809124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4809164;
    /* @4809128 constant */
    /* @4809132 cast */
    /* @4809136 constant */
    /* @4809140 cast */
    /* @4809144 constant */
    /* @4809148 cast */
    /* @4809152 call */
    GM_SITE(vm, 521, 4809152);
    /* @4809160 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(3), VAL(0), VAL(0)));
    L_4809164: ;
    /* @4809164 constant */
    /* @4809168 store */
    GM_WRITE(vm, 0, "djump", VAL(0));
    /* @4809176 constant */
    /* @4809180 store */
    GM_WRITE(vm, 0, "tjump", VAL(1));
    /* @4809188 constant */
    /* @4809192 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(32));
    /* @4809200 b */
    goto L_4809364;
    L_4809204: ;
    /* @4809204 load */
    /* @4809212 cast */
    /* @4809216 bf */
    if (!TRUTH(BOOL(GM_READ(vm, 0, "tjump")))) goto L_4809240;
    /* @4809220 load */
    /* @4809228 constant */
    /* @4809232 cmp */
    /* @4809236 b */
    p4809244_0 = NUMBOOL(GM_READ(vm, -5, "tjumpactive") == VAL(1));
    goto L_4809244;
    L_4809240: ;
    /* @4809240 constant */
    p4809244_0 = VAL(0);
    L_4809244: ;
    /* @4809244 bf */
    if (!TRUTH(p4809244_0)) goto L_4809364;
    /* @4809248 constant */
    /* @4809252 store */
    GM_WRITE(vm, 0, "vsp", VAL(-9));
    /* @4809260 load */
    /* @4809268 constant */
    /* @4809272 cmp */
    /* @4809276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4809284;
    /* @4809280 b */
    goto L_4809340;
    L_4809284: ;
    /* @4809284 load */
    /* @4809292 constant */
    /* @4809296 cmp */
    /* @4809300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4809340;
    /* @4809304 constant */
    /* @4809308 cast */
    /* @4809312 constant */
    /* @4809316 cast */
    /* @4809320 constant */
    /* @4809324 cast */
    /* @4809328 call */
    GM_SITE(vm, 521, 4809328);
    /* @4809336 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(3), VAL(0), VAL(0)));
    L_4809340: ;
    /* @4809340 constant */
    /* @4809344 store */
    GM_WRITE(vm, 0, "tjump", VAL(0));
    /* @4809352 constant */
    /* @4809356 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(32));
    L_4809364: ;
    return;
}
