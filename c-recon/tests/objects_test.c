/* Acceptance for c-recon/src/objects.c: instance_create, Create dispatch and
 * the audio voice table.
 *
 * The bodies used here are the two checked-in ones, so the assertions are about
 * shipped bytecode and not a reimplementation:
 *   - CODE 792 (obj_bosspuff Create, c-recon/gen/gml_0792.c) writes
 *     alarm[0..9] = 1,10,20,30,40,50,60,70,80,100;
 *   - obj_tree (1) has no Create event at all, so it is the "nothing to do"
 *     control.
 *
 * Build (from the repo root):
 *   clang -std=c11 -O2 -Wall -Ic-recon/include \
 *     c-recon/src/host.c c-recon/src/objects.c c-recon/gen/objects_data.c \
 *     c-recon/gen/registry.c c-recon/gen/gml_0792.c \
 *     c-recon/tests/objects_test.c -o c-recon/build/objects_test
 */
#include "gml.h"

#include <stdio.h>
#include <string.h>

/* Fixture-facing entries that are deliberately outside gml.h (the shared host
 * ABI), declared here so the host never depends on them. */
void gm_objects_reset(void);
double gm_audio_play(Val sound, Val priority, int looping);
int gm_audio_is_playing(Val sound);
void gm_audio_stop_sound(Val sound);
void gm_audio_pause_all(void);
void gm_audio_resume_all(void);
void gm_audio_stop_all(void);
void gm_audio_step_tick(void);
int gm_audio_voice_count(void);
int gm_audio_voice_info(int index, double* sound, int32_t* voice, int* looping, int* stopped,
                        int64_t* start_tick);
/* c-recon/gen/objects_data.c */
extern const int GM_OBJECT_COUNT;
extern const int GM_OBJECT_PARENT_EDGES;
int32_t gm_object_sprite(int32_t id);
int gm_object_create_code(int32_t id);
int gm_object_parent_count(int32_t id);
int32_t gm_object_parent(int32_t id, int index);
int gm_object_exists(int32_t id);
const char* gm_object_name(int32_t id);

static int checks;
static int failures;

#define CHECK(cond)                                                              \
    do {                                                                         \
        checks++;                                                                \
        if (!(cond)) {                                                           \
            failures++;                                                          \
            fprintf(stderr, "FAIL %s:%d  %s\n", __FILE__, __LINE__, #cond);      \
        }                                                                        \
    } while (0)

#define CHECK_EQ_D(actual, want)                                                 \
    do {                                                                         \
        double a_ = (double)(actual), w_ = (double)(want);                       \
        checks++;                                                                \
        if (!(a_ == w_)) {                                                       \
            failures++;                                                          \
            fprintf(stderr, "FAIL %s:%d  %s == %.17g, want %.17g\n", __FILE__,   \
                    __LINE__, #actual, a_, w_);                                  \
        }                                                                        \
    } while (0)

static GmVM* fresh_vm(int32_t self) {
    static GmVM backing[2];
    static int used;
    GmVM* vm = &backing[used++ % 2];
    vm_init(vm, self);
    gm_objects_reset(); /* stands in for "a new Scene": ids and voices restart */
    return vm;
}

static void test_object_table(void) {
    /* 191 objects ship in full_ir.json; the table must cover all of them. */
    CHECK(GM_OBJECT_COUNT == 191);
    CHECK(gm_object_exists(190));
    CHECK(strcmp(gm_object_name(190), "obj_bosspuff") == 0);
    CHECK_EQ_D(gm_object_sprite(190), 50);
    CHECK_EQ_D(gm_object_create_code(190), 792);

    /* obj_tree has no Create event at all (events[] is empty in full_ir.json),
     * and obj_bosspuff's sprite/Create pair is pinned to the shipped numbers. */
    CHECK(gm_object_exists(1));
    CHECK_EQ_D(gm_object_sprite(1), 177);
    CHECK_EQ_D(gm_object_create_code(1), -1);
    CHECK_EQ_D(gm_object_parent_count(190), 0);
    CHECK_EQ_D(gm_object_parent_count(1), 0);

    /* parent_chain windows must tile the flattened array exactly, and every
     * ancestor must itself be a declared object. */
    int edges = 0, bad = 0;
    for (int32_t id = 0; id < GM_OBJECT_COUNT; id++) {
        if (!gm_object_exists(id)) continue;
        int n = gm_object_parent_count(id);
        if (n < 0) bad++;
        edges += n;
        for (int k = 0; k < n; k++) {
            int32_t p = gm_object_parent(id, k);
            if (p < 0 || !gm_object_exists(p)) bad++;
        }
        if (gm_object_parent(id, n) != -1) bad++; /* one past the end */
    }
    CHECK_EQ_D(edges, GM_OBJECT_PARENT_EDGES);
    CHECK_EQ_D(bad, 0);

    CHECK(!gm_object_exists(9999));
    CHECK_EQ_D(gm_object_create_code(9999), -1);
    CHECK(gm_object_name(9999) == NULL);
}

/* The object that owns a Create body: CODE 792 through registry.c. */
static void test_create_with_body(void) {
    GmVM* vm = fresh_vm(0);
    int32_t id = gm_instance_create(vm, 0, VAL(128), VAL(96), 190);

    /* Scene::insert_external starts at max(next_id, 200000)+1. */
    CHECK_EQ_D(id, 200001);
    GmInst* in = vm_inst(vm, id);
    CHECK(in != NULL);
    if (!in) return;
    CHECK_EQ_D(in->object, 190);
    CHECK_EQ_D(in->alive, 1);
    CHECK_EQ_D(in->active, 1);

    /* engine defaults from Scene::create() */
    vm->cur = id;
    CHECK_EQ_D(GM_READ(vm, -1, "id"), 200001);
    CHECK_EQ_D(GM_READ(vm, -1, "x"), 128);
    CHECK_EQ_D(GM_READ(vm, -1, "y"), 96);
    CHECK_EQ_D(GM_READ(vm, -1, "sprite_index"), 50);
    CHECK_EQ_D(GM_READ(vm, -1, "image_index"), 0);
    CHECK_EQ_D(GM_READ(vm, -1, "image_xscale"), 1);
    CHECK_EQ_D(GM_READ(vm, -1, "image_yscale"), 1);
    CHECK_EQ_D(GM_READ(vm, -1, "image_angle"), 0);
    CHECK_EQ_D(GM_READ(vm, -1, "image_blend"), 16777215);
    CHECK_EQ_D(GM_READ(vm, -1, "image_alpha"), 1);
    CHECK_EQ_D(GM_READ(vm, -1, "image_speed"), 1);
    CHECK_EQ_D(GM_READ(vm, -1, "hspeed"), 0);
    CHECK_EQ_D(GM_READ(vm, -1, "visible"), 1);
    CHECK_EQ_D(GM_READ(vm, -1, "gravity_direction"), 270);

    /* Create really ran: CODE 792 armed ten alarms. */
    const int32_t want[10] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 100};
    for (int k = 0; k < 10; k++) CHECK_EQ_D(in->alarms[k], want[k]);
    CHECK_EQ_D(in->alarms[10], -1);
    CHECK_EQ_D(in->alarms[11], -1);

    /* ...and it wrote through the VM's own array path, i.e. dispatch set the
     * body's `self` to the new instance. */
    CHECK_EQ_D(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(0)), 1);
    CHECK_EQ_D(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(9)), 100);
}

/* An object with no Create anywhere: creation must still succeed and the
 * instance must be left with untouched alarms. */
static void test_create_without_body(void) {
    GmVM* vm = fresh_vm(0);
    int32_t first = gm_instance_create(vm, 0, VAL(10), VAL(20), 190);
    int32_t second = gm_instance_create(vm, 0, VAL(32), VAL(48), 1);

    CHECK(first > 0);
    CHECK(second > 0);
    CHECK(second != first);
    CHECK_EQ_D(second, 200002); /* +1 per creation, like insert_external */

    GmInst* in = vm_inst(vm, second);
    CHECK(in != NULL);
    if (!in) return;
    CHECK_EQ_D(in->object, 1);
    CHECK_EQ_D(in->alive, 1);
    vm->cur = second;
    CHECK_EQ_D(GM_READ(vm, -1, "sprite_index"), 177); /* obj_tree's shipped sprite */
    CHECK_EQ_D(GM_READ(vm, -1, "x"), 32);
    CHECK_EQ_D(GM_READ(vm, -1, "y"), 48);
    for (int k = 0; k < 12; k++) CHECK_EQ_D(in->alarms[k], -1);

    /* Both instances coexist: distinct ids, distinct rows. */
    GmInst* first_in = vm_inst(vm, first);
    CHECK(first_in != NULL && first_in != in);
    if (first_in) CHECK_EQ_D(first_in->object, 190);

    /* A failed create changes nothing (Scene::create errors out first). */
    int before = vm->ninst;
    CHECK_EQ_D(gm_instance_create(vm, 0, VAL(0), VAL(0), 9999), -1);
    CHECK_EQ_D(vm->ninst, before);
}

/* Dispatch on an instance the fixture inserted directly, with no create(). */
static void test_dispatch_direct(void) {
    GmVM* vm = fresh_vm(0);
    GmInst* fixture = vm_add(vm, 42, 190);
    CHECK(fixture != NULL);
    if (!fixture) return;
    CHECK_EQ_D(gm_dispatch_create(vm, 42), 0);
    /* CODE 792's shipped ladder: 1, then 10..80 by tens, then 100. */
    const int32_t want[10] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 100};
    for (int k = 0; k < 10; k++) CHECK_EQ_D(vm_inst(vm, 42)->alarms[k], want[k]);

    /* no body anywhere in the chain is a valid no-op, not a failure */
    GmInst* tree = vm_add(vm, 43, 1);
    CHECK(tree != NULL);
    CHECK_EQ_D(gm_dispatch_create(vm, 43), 0);
    for (int k = 0; k < 12; k++) CHECK_EQ_D(vm_inst(vm, 43)->alarms[k], -1);

    /* unknown instance is an error (Scene::dispatch: "unknown instance") */
    CHECK_EQ_D(gm_dispatch_create(vm, 12345), -1);
}

static void test_audio_voices(void) {
    GmVM* vm = fresh_vm(0);
    (void)vm;

    /* first voice id is 1 (Scene::next_voice_id starts at 1) */
    double v1 = gm_audio_play(VAL(7), VAL(1), 0);
    CHECK_EQ_D(v1, 1);
    CHECK_EQ_D(gm_audio_is_playing(VAL(7)), 1);
    CHECK_EQ_D(gm_audio_is_playing(VAL(8)), 0); /* other sound untouched */
    CHECK_EQ_D(gm_audio_voice_count(), 1);

    gm_audio_step_tick();
    double v2 = gm_audio_play(VAL(7), VAL(0.5), 1);
    CHECK_EQ_D(v2, 2);

    double sound = -1;
    int32_t voice = -1;
    int looping = -1, stopped = -1;
    int64_t start = -1;
    CHECK(gm_audio_voice_info(0, &sound, &voice, &looping, &stopped, &start));
    CHECK_EQ_D(sound, 7);
    CHECK_EQ_D(voice, 1);
    CHECK_EQ_D(looping, 0);
    CHECK_EQ_D(stopped, 0);
    CHECK_EQ_D((double)start, 0); /* recorded the tick it started on */

    CHECK(gm_audio_voice_info(1, &sound, &voice, &looping, &stopped, &start));
    CHECK_EQ_D(voice, 2);
    CHECK_EQ_D(looping, 1);
    CHECK_EQ_D((double)start, 1);

    /* stopping sound 7 retires both voices of that sound, not other sounds */
    CHECK_EQ_D(gm_audio_play(VAL(9), VAL(1), 0), 3);
    gm_audio_stop_sound(VAL(7));
    CHECK_EQ_D(gm_audio_is_playing(VAL(7)), 0);
    CHECK_EQ_D(gm_audio_is_playing(VAL(9)), 1);
    CHECK(gm_audio_voice_info(0, NULL, NULL, NULL, &stopped, NULL));
    CHECK_EQ_D(stopped, 1);

    /* pause/resume is the Scene's global gate */
    gm_audio_pause_all();
    CHECK_EQ_D(gm_audio_is_playing(VAL(9)), 0);
    gm_audio_resume_all();
    CHECK_EQ_D(gm_audio_is_playing(VAL(9)), 1);

    gm_audio_stop_all();
    CHECK_EQ_D(gm_audio_is_playing(VAL(9)), 0);

    /* unchanged: a stopped voice is not resurrected by resume */
    gm_audio_resume_all();
    CHECK_EQ_D(gm_audio_is_playing(VAL(7)), 0);

    /* the table is not infinite; overflow reports instead of aliasing a voice */
    gm_objects_reset();
    int played = 0;
    for (int i = 0; i < 70; i++)
        if (gm_audio_play(VAL(3), VAL(1), 1) > 0) played++;
    CHECK_EQ_D(played, 64);
    CHECK_EQ_D(gm_audio_voice_count(), 64);
}

/* A fresh scene restarts ids and voices; the first id is reproducible. */
static void test_reset_semantics(void) {
    GmVM* vm = fresh_vm(0);
    CHECK_EQ_D(gm_instance_create(vm, 0, VAL(1), VAL(1), 190), 200001);
    CHECK_EQ_D(gm_instance_create(vm, 0, VAL(2), VAL(2), 190), 200002);

    GmVM* vm2 = fresh_vm(0); /* also resets objects.c state */
    CHECK_EQ_D(vm2->ninst, 0);
    CHECK_EQ_D(gm_instance_create(vm2, 0, VAL(1), VAL(1), 190), 200001);
    CHECK_EQ_D(gm_audio_play(VAL(7), VAL(1), 0), 1);
}

int main(void) {
    test_object_table();
    test_create_with_body();
    test_create_without_body();
    test_dispatch_direct();
    test_audio_voices();
    test_reset_semantics();

    printf("object rows: %d, parent edges: %d\n", GM_OBJECT_COUNT, GM_OBJECT_PARENT_EDGES);
    printf("checks: %d, failures: %d\n", checks, failures);
    return failures == 0 ? 0 : 1;
}
