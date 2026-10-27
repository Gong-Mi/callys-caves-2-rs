/* generated from CODE 495 (gml_Object_obj_firstpause_Destroy_0), source start 4687340, end 4687652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0495(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    /* @4687340 constant */
    /* @4687344 cast */
    /* @4687348 call */
    GM_SITE(vm, 495, 4687348);
    /* @4687356 cast */
    /* @4687360 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(108)));
    if (!TRUTH(v1)) goto L_4687388;
    /* @4687364 constant */
    /* @4687368 pushenv */
    if (!GM_PUSHENV(vm, VAL(108))) goto L_4687384;
    L_4687372: ;
    /* @4687372 call */
    GM_SITE(vm, 495, 4687372);
    /* @4687380 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687384: ;
    /* @4687384 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687372;
    L_4687388: ;
    /* @4687388 constant */
    /* @4687392 cast */
    /* @4687396 call */
    GM_SITE(vm, 495, 4687396);
    /* @4687404 cast */
    /* @4687408 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(122)));
    if (!TRUTH(v2)) goto L_4687436;
    /* @4687412 constant */
    /* @4687416 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_4687432;
    L_4687420: ;
    /* @4687420 call */
    GM_SITE(vm, 495, 4687420);
    /* @4687428 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687432: ;
    /* @4687432 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687420;
    L_4687436: ;
    /* @4687436 constant */
    /* @4687440 cast */
    /* @4687444 call */
    GM_SITE(vm, 495, 4687444);
    /* @4687452 cast */
    /* @4687456 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(110)));
    if (!TRUTH(v3)) goto L_4687484;
    /* @4687460 constant */
    /* @4687464 pushenv */
    if (!GM_PUSHENV(vm, VAL(110))) goto L_4687480;
    L_4687468: ;
    /* @4687468 call */
    GM_SITE(vm, 495, 4687468);
    /* @4687476 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687480: ;
    /* @4687480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687468;
    L_4687484: ;
    /* @4687484 constant */
    /* @4687488 cast */
    /* @4687492 call */
    GM_SITE(vm, 495, 4687492);
    /* @4687500 cast */
    /* @4687504 bf */
    v4 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(107)));
    if (!TRUTH(v4)) goto L_4687532;
    /* @4687508 constant */
    /* @4687512 pushenv */
    if (!GM_PUSHENV(vm, VAL(107))) goto L_4687528;
    L_4687516: ;
    /* @4687516 call */
    GM_SITE(vm, 495, 4687516);
    /* @4687524 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687528: ;
    /* @4687528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687516;
    L_4687532: ;
    /* @4687532 constant */
    /* @4687536 cast */
    /* @4687540 call */
    GM_SITE(vm, 495, 4687540);
    /* @4687548 cast */
    /* @4687552 bf */
    v5 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(109)));
    if (!TRUTH(v5)) goto L_4687580;
    /* @4687556 constant */
    /* @4687560 pushenv */
    if (!GM_PUSHENV(vm, VAL(109))) goto L_4687576;
    L_4687564: ;
    /* @4687564 call */
    GM_SITE(vm, 495, 4687564);
    /* @4687572 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687576: ;
    /* @4687576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687564;
    L_4687580: ;
    /* @4687580 constant */
    /* @4687584 cast */
    /* @4687588 call */
    GM_SITE(vm, 495, 4687588);
    /* @4687596 cast */
    /* @4687600 bf */
    v6 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(111)));
    if (!TRUTH(v6)) goto L_4687628;
    /* @4687604 constant */
    /* @4687608 pushenv */
    if (!GM_PUSHENV(vm, VAL(111))) goto L_4687624;
    L_4687612: ;
    /* @4687612 call */
    GM_SITE(vm, 495, 4687612);
    /* @4687620 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4687624: ;
    /* @4687624 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4687612;
    L_4687628: ;
    /* @4687628 call */
    GM_SITE(vm, 495, 4687628);
    /* @4687636 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4687640 call */
    GM_SITE(vm, 495, 4687640);
    /* @4687648 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    L_4687652: ;
    return;
}
