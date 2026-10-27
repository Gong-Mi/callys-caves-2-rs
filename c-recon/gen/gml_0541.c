/* generated from CODE 541 (gml_Object_obj_youhavedied_Destroy_0), source start 4841092, end 4841224. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0541(GmVM* vm) {
    /* @4841092 call */
    GM_SITE(vm, 541, 4841092);
    /* @4841100 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4841104 constant */
    /* @4841108 store */
    GM_WRITE(vm, -5, "health1", VAL(4));
    /* @4841116 load */
    /* @4841124 load */
    /* @4841132 sub */
    /* @4841136 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - GM_READ(vm, -1, "coindeduct")));
    /* @4841144 constant */
    /* @4841148 store */
    GM_WRITE(vm, -5, "warpfrommap", VAL(1));
    /* @4841156 load */
    /* @4841164 constant */
    /* @4841168 cmp */
    /* @4841172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4841180;
    /* @4841176 b */
    goto L_4841212;
    L_4841180: ;
    /* @4841180 load */
    /* @4841188 constant */
    /* @4841192 cmp */
    /* @4841196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4841212;
    /* @4841200 call */
    GM_SITE(vm, 541, 4841200);
    /* @4841208 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    L_4841212: ;
    /* @4841212 call */
    GM_SITE(vm, 541, 4841212);
    /* @4841220 popz */
    (void)(GM_CALL(vm, "room_restart", 0));
    L_4841224: ;
    return;
}
