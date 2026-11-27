/* generated from CODE 458 (gml_Object_obj_pwrlevelinitialize_Create_0), source start 4641304, end 4642664. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0458(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    /* @4641304 constant */
    /* @4641308 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4641316 constant */
    /* @4641320 store */
    GM_WRITE(vm, -5, "pwr", VAL(1));
    /* @4641328 call */
    GM_SITE(vm, 458, 4641328);
    /* @4641336 store */
    v1 = GM_CALL(vm, "part_system_create", 0);
    GM_WRITE(vm, -5, "P_System", v1);
    /* @4641344 call */
    GM_SITE(vm, 458, 4641344);
    /* @4641352 store */
    v2 = GM_CALL(vm, "part_type_create", 0);
    GM_WRITE(vm, -5, "Particle1", v2);
    /* @4641360 constant */
    /* @4641364 cast */
    /* @4641368 constant */
    /* @4641380 cast */
    /* @4641384 constant */
    /* @4641388 cast */
    /* @4641392 constant */
    /* @4641396 cast */
    /* @4641400 load */
    /* @4641408 call */
    GM_SITE(vm, 458, 4641408);
    /* @4641416 popz */
    (void)(GM_CALL(vm, "part_type_size", 5, GM_READ(vm, -5, "Particle1"), VAL(1), VAL(1), VAL(-0.05), VAL(0)));
    /* @4641420 constant */
    /* @4641424 cast */
    /* @4641428 load */
    /* @4641436 call */
    GM_SITE(vm, 458, 4641436);
    /* @4641444 popz */
    (void)(GM_CALL(vm, "part_type_shape", 2, GM_READ(vm, -5, "Particle1"), VAL(0)));
    /* @4641448 constant */
    /* @4641452 cast */
    /* @4641456 constant */
    /* @4641468 cast */
    /* @4641472 constant */
    /* @4641476 cast */
    /* @4641480 constant */
    /* @4641484 cast */
    /* @4641488 load */
    /* @4641496 call */
    GM_SITE(vm, 458, 4641496);
    /* @4641504 popz */
    (void)(GM_CALL(vm, "part_type_speed", 5, GM_READ(vm, -5, "Particle1"), VAL(8), VAL(12), VAL(0.1), VAL(0)));
    /* @4641508 constant */
    /* @4641512 cast */
    /* @4641516 constant */
    /* @4641520 cast */
    /* @4641524 constant */
    /* @4641528 cast */
    /* @4641532 constant */
    /* @4641536 cast */
    /* @4641540 load */
    /* @4641548 call */
    GM_SITE(vm, 458, 4641548);
    /* @4641556 popz */
    (void)(GM_CALL(vm, "part_type_direction", 5, GM_READ(vm, -5, "Particle1"), VAL(0), VAL(360), VAL(0), VAL(0)));
    /* @4641560 constant */
    /* @4641564 cast */
    /* @4641568 constant */
    /* @4641580 cast */
    /* @4641584 load */
    /* @4641592 call */
    GM_SITE(vm, 458, 4641592);
    /* @4641600 popz */
    (void)(GM_CALL(vm, "part_type_gravity", 3, GM_READ(vm, -5, "Particle1"), VAL(0.02), VAL(270)));
    /* @4641604 constant */
    /* @4641608 cast */
    /* @4641612 constant */
    /* @4641616 cast */
    /* @4641620 constant */
    /* @4641624 cast */
    /* @4641628 constant */
    /* @4641632 cast */
    /* @4641636 constant */
    /* @4641640 cast */
    /* @4641644 load */
    /* @4641652 call */
    GM_SITE(vm, 458, 4641652);
    /* @4641660 popz */
    (void)(GM_CALL(vm, "part_type_orientation", 6, GM_READ(vm, -5, "Particle1"), VAL(0), VAL(0), VAL(0), VAL(0), VAL(1)));
    /* @4641664 constant */
    /* @4641668 cast */
    /* @4641672 constant */
    /* @4641676 cast */
    /* @4641680 load */
    /* @4641688 call */
    GM_SITE(vm, 458, 4641688);
    /* @4641696 popz */
    (void)(GM_CALL(vm, "part_type_life", 3, GM_READ(vm, -5, "Particle1"), VAL(1), VAL(12)));
    /* @4641700 constant */
    /* @4641708 cast */
    /* @4641712 constant */
    /* @4641720 cast */
    /* @4641724 load */
    /* @4641732 call */
    GM_SITE(vm, 458, 4641732);
    /* @4641740 popz */
    (void)(GM_CALL(vm, "part_type_color2", 3, GM_READ(vm, -5, "Particle1"), VAL(16777215), VAL(4235519)));
    /* @4641744 constant */
    /* @4641748 cast */
    /* @4641752 load */
    /* @4641760 call */
    GM_SITE(vm, 458, 4641760);
    /* @4641768 popz */
    (void)(GM_CALL(vm, "part_type_alpha1", 2, GM_READ(vm, -5, "Particle1"), VAL(1)));
    /* @4641772 call */
    GM_SITE(vm, 458, 4641772);
    /* @4641780 store */
    v3 = GM_CALL(vm, "part_system_create", 0);
    GM_WRITE(vm, -5, "P_System2", v3);
    /* @4641788 call */
    GM_SITE(vm, 458, 4641788);
    /* @4641796 store */
    v4 = GM_CALL(vm, "part_type_create", 0);
    GM_WRITE(vm, -5, "Particle2", v4);
    /* @4641804 constant */
    /* @4641808 cast */
    /* @4641812 constant */
    /* @4641824 cast */
    /* @4641828 constant */
    /* @4641832 cast */
    /* @4641836 constant */
    /* @4641840 cast */
    /* @4641844 load */
    /* @4641852 call */
    GM_SITE(vm, 458, 4641852);
    /* @4641860 popz */
    (void)(GM_CALL(vm, "part_type_size", 5, GM_READ(vm, -5, "Particle2"), VAL(1), VAL(1), VAL(0.05), VAL(0)));
    /* @4641864 constant */
    /* @4641868 cast */
    /* @4641872 load */
    /* @4641880 call */
    GM_SITE(vm, 458, 4641880);
    /* @4641888 popz */
    (void)(GM_CALL(vm, "part_type_shape", 2, GM_READ(vm, -5, "Particle2"), VAL(0)));
    /* @4641892 constant */
    /* @4641896 cast */
    /* @4641900 constant */
    /* @4641912 cast */
    /* @4641916 constant */
    /* @4641920 cast */
    /* @4641924 constant */
    /* @4641928 cast */
    /* @4641932 load */
    /* @4641940 call */
    GM_SITE(vm, 458, 4641940);
    /* @4641948 popz */
    (void)(GM_CALL(vm, "part_type_speed", 5, GM_READ(vm, -5, "Particle2"), VAL(4), VAL(8), VAL(0.2), VAL(2)));
    /* @4641952 constant */
    /* @4641956 cast */
    /* @4641960 constant */
    /* @4641964 cast */
    /* @4641968 constant */
    /* @4641972 cast */
    /* @4641976 constant */
    /* @4641980 cast */
    /* @4641984 load */
    /* @4641992 call */
    GM_SITE(vm, 458, 4641992);
    /* @4642000 popz */
    (void)(GM_CALL(vm, "part_type_direction", 5, GM_READ(vm, -5, "Particle2"), VAL(200), VAL(340), VAL(0), VAL(0)));
    /* @4642004 constant */
    /* @4642008 cast */
    /* @4642012 constant */
    /* @4642024 cast */
    /* @4642028 load */
    /* @4642036 call */
    GM_SITE(vm, 458, 4642036);
    /* @4642044 popz */
    (void)(GM_CALL(vm, "part_type_gravity", 3, GM_READ(vm, -5, "Particle2"), VAL(0.3), VAL(270)));
    /* @4642048 constant */
    /* @4642052 cast */
    /* @4642056 constant */
    /* @4642060 cast */
    /* @4642064 constant */
    /* @4642068 cast */
    /* @4642072 constant */
    /* @4642076 cast */
    /* @4642080 constant */
    /* @4642084 cast */
    /* @4642088 load */
    /* @4642096 call */
    GM_SITE(vm, 458, 4642096);
    /* @4642104 popz */
    (void)(GM_CALL(vm, "part_type_orientation", 6, GM_READ(vm, -5, "Particle2"), VAL(0), VAL(90), VAL(360), VAL(0), VAL(1)));
    /* @4642108 constant */
    /* @4642112 cast */
    /* @4642116 constant */
    /* @4642120 cast */
    /* @4642124 load */
    /* @4642132 call */
    GM_SITE(vm, 458, 4642132);
    /* @4642140 popz */
    (void)(GM_CALL(vm, "part_type_life", 3, GM_READ(vm, -5, "Particle2"), VAL(4), VAL(8)));
    /* @4642144 constant */
    /* @4642152 cast */
    /* @4642156 constant */
    /* @4642164 cast */
    /* @4642168 load */
    /* @4642176 call */
    GM_SITE(vm, 458, 4642176);
    /* @4642184 popz */
    (void)(GM_CALL(vm, "part_type_color2", 3, GM_READ(vm, -5, "Particle2"), VAL(16777215), VAL(16777215)));
    /* @4642188 constant */
    /* @4642192 cast */
    /* @4642196 load */
    /* @4642204 call */
    GM_SITE(vm, 458, 4642204);
    /* @4642212 popz */
    (void)(GM_CALL(vm, "part_type_alpha1", 2, GM_READ(vm, -5, "Particle2"), VAL(1)));
    /* @4642216 call */
    GM_SITE(vm, 458, 4642216);
    /* @4642224 store */
    v5 = GM_CALL(vm, "part_system_create", 0);
    GM_WRITE(vm, -5, "P_System3", v5);
    /* @4642232 call */
    GM_SITE(vm, 458, 4642232);
    /* @4642240 store */
    v6 = GM_CALL(vm, "part_type_create", 0);
    GM_WRITE(vm, -5, "Particle3", v6);
    /* @4642248 constant */
    /* @4642252 cast */
    /* @4642256 constant */
    /* @4642268 cast */
    /* @4642272 constant */
    /* @4642284 cast */
    /* @4642288 constant */
    /* @4642300 cast */
    /* @4642304 load */
    /* @4642312 call */
    GM_SITE(vm, 458, 4642312);
    /* @4642320 popz */
    (void)(GM_CALL(vm, "part_type_size", 5, GM_READ(vm, -5, "Particle3"), VAL(0.5), VAL(0.5), VAL(0.05), VAL(0)));
    /* @4642324 constant */
    /* @4642328 cast */
    /* @4642332 load */
    /* @4642340 call */
    GM_SITE(vm, 458, 4642340);
    /* @4642348 popz */
    (void)(GM_CALL(vm, "part_type_shape", 2, GM_READ(vm, -5, "Particle3"), VAL(0)));
    /* @4642352 constant */
    /* @4642356 cast */
    /* @4642360 constant */
    /* @4642372 cast */
    /* @4642376 constant */
    /* @4642380 cast */
    /* @4642384 constant */
    /* @4642388 cast */
    /* @4642392 load */
    /* @4642400 call */
    GM_SITE(vm, 458, 4642400);
    /* @4642408 popz */
    (void)(GM_CALL(vm, "part_type_speed", 5, GM_READ(vm, -5, "Particle3"), VAL(1), VAL(1), VAL(0.2), VAL(2)));
    /* @4642412 constant */
    /* @4642416 cast */
    /* @4642420 constant */
    /* @4642424 cast */
    /* @4642428 constant */
    /* @4642432 cast */
    /* @4642436 constant */
    /* @4642440 cast */
    /* @4642444 load */
    /* @4642452 call */
    GM_SITE(vm, 458, 4642452);
    /* @4642460 popz */
    (void)(GM_CALL(vm, "part_type_direction", 5, GM_READ(vm, -5, "Particle3"), VAL(60), VAL(120), VAL(0), VAL(0)));
    /* @4642464 constant */
    /* @4642468 cast */
    /* @4642472 constant */
    /* @4642476 cast */
    /* @4642480 load */
    /* @4642488 call */
    GM_SITE(vm, 458, 4642488);
    /* @4642496 popz */
    (void)(GM_CALL(vm, "part_type_gravity", 3, GM_READ(vm, -5, "Particle3"), VAL(0), VAL(90)));
    /* @4642500 constant */
    /* @4642504 cast */
    /* @4642508 constant */
    /* @4642512 cast */
    /* @4642516 constant */
    /* @4642520 cast */
    /* @4642524 constant */
    /* @4642528 cast */
    /* @4642532 constant */
    /* @4642536 cast */
    /* @4642540 load */
    /* @4642548 call */
    GM_SITE(vm, 458, 4642548);
    /* @4642556 popz */
    (void)(GM_CALL(vm, "part_type_orientation", 6, GM_READ(vm, -5, "Particle3"), VAL(0), VAL(90), VAL(360), VAL(0), VAL(1)));
    /* @4642560 constant */
    /* @4642564 cast */
    /* @4642568 constant */
    /* @4642572 cast */
    /* @4642576 load */
    /* @4642584 call */
    GM_SITE(vm, 458, 4642584);
    /* @4642592 popz */
    (void)(GM_CALL(vm, "part_type_life", 3, GM_READ(vm, -5, "Particle3"), VAL(10), VAL(10)));
    /* @4642596 constant */
    /* @4642600 cast */
    /* @4642604 constant */
    /* @4642612 cast */
    /* @4642616 load */
    /* @4642624 call */
    GM_SITE(vm, 458, 4642624);
    /* @4642632 popz */
    (void)(GM_CALL(vm, "part_type_color2", 3, GM_READ(vm, -5, "Particle3"), VAL(16777215), VAL(255)));
    /* @4642636 constant */
    /* @4642640 cast */
    /* @4642644 load */
    /* @4642652 call */
    GM_SITE(vm, 458, 4642652);
    /* @4642660 popz */
    (void)(GM_CALL(vm, "part_type_alpha1", 2, GM_READ(vm, -5, "Particle3"), VAL(1)));
    L_4642664: ;
    return;
}
