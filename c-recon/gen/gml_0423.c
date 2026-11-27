/* generated from CODE 423 (gml_Object_obj_swordupgrade_Mouse_0), source start 4593836, end 4594060. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0423(GmVM* vm) {
    Val p4593880_0;
    Val p4593928_0;
    /* @4593836 load */
    /* @4593844 constant */
    /* @4593848 cmp */
    /* @4593852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") != VAL(1)))) goto L_4593876;
    /* @4593856 load */
    /* @4593864 constant */
    /* @4593868 cmp */
    /* @4593872 b */
    p4593880_0 = NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") != VAL(1));
    goto L_4593880;
    L_4593876: ;
    /* @4593876 constant */
    p4593880_0 = VAL(0);
    L_4593880: ;
    /* @4593880 bf */
    if (!TRUTH(p4593880_0)) goto L_4594060;
    /* @4593884 load */
    /* @4593892 constant */
    /* @4593896 cmp */
    /* @4593900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(3000)))) goto L_4593924;
    /* @4593904 load */
    /* @4593912 constant */
    /* @4593916 cmp */
    /* @4593920 b */
    p4593928_0 = NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(0));
    goto L_4593928;
    L_4593924: ;
    /* @4593924 constant */
    p4593928_0 = VAL(0);
    L_4593928: ;
    /* @4593928 bf */
    if (!TRUTH(p4593928_0)) goto L_4594060;
    /* @4593932 constant */
    /* @4593936 store */
    GM_WRITE(vm, -5, "swordupgradebought", VAL(1));
    /* @4593944 load */
    /* @4593952 constant */
    /* @4593956 sub */
    /* @4593960 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(3000)));
    /* @4593968 constant */
    /* @4593972 store */
    GM_WRITE(vm, -5, "sword", VAL(1));
    /* @4593980 load */
    /* @4593988 constant */
    /* @4593992 cmp */
    /* @4593996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4594004;
    /* @4594000 b */
    goto L_4594060;
    L_4594004: ;
    /* @4594004 load */
    /* @4594012 constant */
    /* @4594016 cmp */
    /* @4594020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4594060;
    /* @4594024 constant */
    /* @4594028 cast */
    /* @4594032 constant */
    /* @4594036 cast */
    /* @4594040 constant */
    /* @4594044 cast */
    /* @4594048 call */
    GM_SITE(vm, 423, 4594048);
    /* @4594056 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4594060: ;
    return;
}
