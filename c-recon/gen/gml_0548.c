/* generated from CODE 548 (gml_Object_obj_introduction_Create_0), source start 4846044, end 4846408. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0548(GmVM* vm) {
    /* @4846044 constant */
    /* @4846048 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4846056 constant */
    /* @4846060 store */
    GM_WRITE(vm, -1, "moving", VAL(1));
    /* @4846068 constant */
    /* @4846072 store */
    GM_WRITE(vm, -1, "moving2", VAL(0));
    /* @4846080 constant */
    /* @4846084 store */
    GM_WRITE(vm, -1, "xx1", VAL(110));
    /* @4846092 constant */
    /* @4846096 store */
    GM_WRITE(vm, -1, "x1", VAL(200));
    /* @4846104 constant */
    /* @4846108 store */
    GM_WRITE(vm, -1, "xx2", VAL(100));
    /* @4846116 constant */
    /* @4846120 store */
    GM_WRITE(vm, -1, "x2", VAL(175));
    /* @4846128 constant */
    /* @4846132 store */
    GM_WRITE(vm, -1, "xx3", VAL(120));
    /* @4846140 constant */
    /* @4846144 store */
    GM_WRITE(vm, -1, "x3", VAL(240));
    /* @4846152 constant */
    /* @4846156 store */
    GM_WRITE(vm, -1, "xx4", VAL(120));
    /* @4846164 constant */
    /* @4846168 store */
    GM_WRITE(vm, -1, "x4", VAL(240));
    /* @4846176 constant */
    /* @4846180 cast */
    /* @4846184 call */
    GM_SITE(vm, 548, 4846184);
    /* @4846192 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4846196 constant */
    /* @4846200 cast */
    /* @4846204 call */
    GM_SITE(vm, 548, 4846204);
    /* @4846212 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(137)));
    /* @4846216 constant */
    /* @4846220 cast */
    /* @4846224 call */
    GM_SITE(vm, 548, 4846224);
    /* @4846232 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(133)));
    /* @4846236 constant */
    /* @4846240 cast */
    /* @4846244 constant */
    /* @4846248 cast */
    /* @4846252 constant */
    /* @4846256 cast */
    /* @4846260 call */
    GM_SITE(vm, 548, 4846260);
    /* @4846268 popz */
    (void)(GM_CALL(vm, "instance_create", 3, VAL(0), VAL(0), VAL(136)));
    /* @4846272 constant */
    /* @4846284 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0.3));
    /* @4846292 constant */
    /* @4846296 cast */
    /* @4846300 constant */
    /* @4846304 cast */
    /* @4846308 constant */
    /* @4846312 cast */
    /* @4846316 call */
    GM_SITE(vm, 548, 4846316);
    /* @4846324 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(31), VAL(0), VAL(0)));
    /* @4846328 constant */
    /* @4846332 constant */
    /* @4846336 constant */
    /* @4846340 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(120));
    /* @4846348 constant */
    /* @4846352 constant */
    /* @4846356 constant */
    /* @4846360 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    /* @4846368 constant */
    /* @4846372 constant */
    /* @4846376 constant */
    /* @4846380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(70));
    /* @4846388 constant */
    /* @4846392 constant */
    /* @4846396 constant */
    /* @4846400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(70));
    L_4846408: ;
    return;
}
