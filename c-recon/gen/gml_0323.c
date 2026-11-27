/* generated from CODE 323 (gml_Object_obj_finalbossgrenade_Step_0), source start 4190260, end 4190904. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0323(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val p4190540_0;
    /* @4190260 constant */
    /* @4190264 cast */
    /* @4190268 call */
    GM_SITE(vm, 323, 4190268);
    /* @4190276 cast */
    /* @4190280 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4190400;
    /* @4190284 constant */
    /* @4190288 cast */
    /* @4190292 load */
    /* @4190300 load */
    /* @4190308 add */
    /* @4190312 load */
    /* @4190320 load */
    /* @4190328 add */
    /* @4190332 call */
    GM_SITE(vm, 323, 4190332);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4190340 cast */
    /* @4190344 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4190400;
    /* @4190348 constant */
    /* @4190352 cast */
    /* @4190356 load */
    /* @4190364 load */
    /* @4190372 call */
    GM_SITE(vm, 323, 4190372);
    /* @4190380 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4190388 call */
    GM_SITE(vm, 323, 4190388);
    /* @4190396 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4190400: ;
    /* @4190400 load */
    /* @4190408 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4190416 constant */
    /* @4190420 cast */
    /* @4190424 load */
    /* @4190432 load */
    /* @4190440 call */
    GM_SITE(vm, 323, 4190440);
    /* @4190448 store */
    v6 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0));
    GM_WRITE(vm, -1, "hit", v6);
    /* @4190456 load */
    /* @4190464 constant */
    /* @4190468 cmp */
    /* @4190472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4190536;
    /* @4190476 load */
    /* @4190484 constant */
    /* @4190488 cmp */
    /* @4190492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4190536;
    /* @4190496 load */
    /* @4190504 constant */
    /* @4190508 cmp */
    /* @4190512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0)))) goto L_4190536;
    /* @4190516 load */
    /* @4190524 constant */
    /* @4190528 cmp */
    /* @4190532 b */
    p4190540_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4190540;
    L_4190536: ;
    /* @4190536 constant */
    p4190540_0 = VAL(0);
    L_4190540: ;
    /* @4190540 bf */
    if (!TRUTH(p4190540_0)) goto L_4190904;
    /* @4190544 load */
    /* @4190552 constant */
    /* @4190556 cmp */
    /* @4190560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4190604;
    /* @4190564 constant */
    /* @4190568 cast */
    /* @4190572 constant */
    /* @4190576 cast */
    /* @4190580 constant */
    /* @4190584 cast */
    /* @4190588 call */
    GM_SITE(vm, 323, 4190588);
    /* @4190596 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4190600 b */
    goto L_4190624;
    L_4190604: ;
    /* @4190604 load */
    /* @4190612 constant */
    /* @4190616 cmp */
    /* @4190620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4190624;
    L_4190624: ;
    /* @4190624 constant */
    /* @4190628 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4190636 constant */
    /* @4190640 cast */
    /* @4190644 load */
    /* @4190652 load */
    /* @4190660 load */
    /* @4190668 load */
    /* @4190676 call */
    GM_SITE(vm, 323, 4190676);
    /* @4190684 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4190688 load */
    /* @4190696 load */
    /* @4190704 cmp */
    /* @4190708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4190740;
    /* @4190712 constant */
    /* @4190716 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4190724 constant */
    /* @4190728 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4190736 b */
    goto L_4190788;
    L_4190740: ;
    /* @4190740 load */
    /* @4190748 load */
    /* @4190756 cmp */
    /* @4190760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4190788;
    /* @4190764 constant */
    /* @4190768 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4190776 constant */
    /* @4190780 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4190788: ;
    /* @4190788 constant */
    /* @4190792 constant */
    /* @4190796 constant */
    /* @4190800 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4190808 constant */
    /* @4190812 constant */
    /* @4190816 constant */
    /* @4190820 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4190828 constant */
    /* @4190832 constant */
    /* @4190836 constant */
    /* @4190840 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4190848 load */
    /* @4190856 constant */
    /* @4190860 sub */
    /* @4190864 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4190872 constant */
    /* @4190876 constant */
    /* @4190880 constant */
    /* @4190884 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4190892 constant */
    /* @4190896 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4190904: ;
    return;
}
