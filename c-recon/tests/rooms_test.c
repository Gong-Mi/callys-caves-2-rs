/* Room-data and room-builtin acceptance, independent of generated CODE bodies. */
#include "gml.h"
#include <stdio.h>

static int checks, failures;
#define CHECK_EQ_D(actual, want) do { \
    double a_ = (double)(actual), w_ = (double)(want); \
    checks++; \
    if (a_ != w_) { failures++; \
        fprintf(stderr, "FAIL %s:%d %s == %.17g, want %.17g\n", \
                __FILE__, __LINE__, #actual, a_, w_); } \
} while (0)

static void test_room_data_is_complete(void) {
    int total = 0, bindings = 0, largest = 0;
    for (int i = 0; i < GM_ROOM_COUNT; i++) {
        total += GM_ROOMS[i].nobjects;
        bindings += GM_ROOMS[i].nbindings;
        if (GM_ROOMS[i].nobjects > largest) largest = GM_ROOMS[i].nobjects;
    }
    CHECK_EQ_D(GM_ROOM_COUNT, 114);
    CHECK_EQ_D(total, 71014);
    CHECK_EQ_D(bindings, 551);
    CHECK_EQ_D(largest, 1472);
    CHECK_EQ_D(largest < MAX_INST, 1);
    CHECK_EQ_D(largest <= MAX_ENV_SEL, 1);
    CHECK_EQ_D(GM_ROOMS[0].width, 1024);
    CHECK_EQ_D(GM_ROOMS[0].height, 576);
    CHECK_EQ_D(GM_ROOMS[0].nobjects, 170);
    CHECK_EQ_D(GM_ROOMS[0].nbindings, 2);
    CHECK_EQ_D(GM_ROOMS[0].nviews, 8);
    CHECK_EQ_D(GM_ROOMS[1].width, 2048);
    CHECK_EQ_D(GM_ROOMS[1].height, 1280);
    CHECK_EQ_D(GM_ROOMS[1].nobjects, 1341);
    CHECK_EQ_D(GM_ROOMS[110].width, 2880);
    CHECK_EQ_D(GM_ROOMS[110].height, 480);
    CHECK_EQ_D(GM_ROOMS[110].nobjects, 623);
}

static void test_persistent_flags(void) {
    CHECK_EQ_D(gm_object_persistent(0), 1);   /* obj_player */
    CHECK_EQ_D(gm_object_persistent(68), 1);  /* obj_music */
    CHECK_EQ_D(gm_object_persistent(66), 0);  /* obj_UI is re-placed per room */
    CHECK_EQ_D(gm_object_persistent(69), 0);  /* warp doors are room-local */
}

static void test_room_builtins_only_queue(void) {
    static GmVM backing;
    GmVM* vm = &backing;
    vm_init(vm, 100000);
    CHECK_EQ_D(vm->has_room_warp, 0);
    vm->current_room = 25;
    CHECK_EQ_D(GM_CALL(vm, "action_current_room", 0), 25);
    (void)GM_CALL(vm, "room_goto", 1, VAL(110));
    CHECK_EQ_D(vm->target_room_warp, 110);
    CHECK_EQ_D(vm->current_room, 25); /* queued, not consumed inside the body */
    (void)GM_CALL(vm, "room_restart", 0);
    CHECK_EQ_D(vm->target_room_warp, 25);
    (void)GM_CALL(vm, "game_restart", 0);
    CHECK_EQ_D(vm->target_room_warp, 0);
    CHECK_EQ_D(vm->has_room_warp, 1);
    (void)GM_CALL(vm, "room_goto", 1, VAL(-1)); /* Rust `as usize`: negative => 0 */
    CHECK_EQ_D(vm->target_room_warp, 0);
}

int main(void) {
    test_room_data_is_complete();
    test_persistent_flags();
    test_room_builtins_only_queue();
    printf("room checks: %d, failures: %d\n", checks, failures);
    return failures == 0 ? 0 : 1;
}
