/* Instance creation + Create-event dispatch for IR lowered to C.
 *
 * Every semantic here is copied from the Rust scene, not invented:
 *   - crates/core/src/ir_scene.rs create()/create_with_id(): id allocation,
 *     the named engine defaults a fresh instance carries, and the fact that
 *     Create runs before the caller sees the id;
 *   - crates/core/src/ir_scene.rs dispatch(): the object's own (type 0,
 *     subtype 0) handler runs; only when the object has none does the first
 *     ancestor in parent_chain that owns one run. Never both - this is the
 *     original runner's inheritance rule, and the parent's handler is not an
 *     additional pass;
 *   - crates/core/src/parts/host_impl.rs "instance_create" => create(...),
 *     whose result is the new instance id as a Val;
 *   - crates/core/src/ir_scene.rs call_audio_play()/audio_is_playing_sound()/
 *     call_audio_stop_sound(): the voice domain.
 *
 * The object table itself lives in c-recon/gen/objects_data.c, generated from
 * full_ir.json by scripts/gen_object_table.py; this file owns no table.
 */
#include "gml.h"

#include <stdio.h>

/* c-recon/gen/registry.c (scripts/gen_registry.py): 1 = ran, 0 = no body. */
int gml_dispatch(GmVM* vm, long code);

/* c-recon/gen/objects_data.c */
int32_t gm_object_sprite(int32_t id);          /* -1 when the id is unknown */
int gm_object_create_code(int32_t id);         /* -1: no own Create body */
int gm_object_parent_count(int32_t id);
int32_t gm_object_parent(int32_t id, int index); /* -1 past the end */
int gm_object_exists(int32_t id);

/* Scene::insert_external() allocates from max(next_id, 200000)+1, so the first
 * runtime instance is 200001 and room-placed ids (< 200000) can never collide
 * with a spawned one. */
#define GM_DYNAMIC_ID_FLOOR 200000
#define GM_MAX_VOICES 64
#define GM_DISPATCH_BUDGET 64 /* Scene::dispatch's depth guard */

/* Scene keeps these on the scene; GmVM has no room for them (gml.h is shared
 * host ABI), so they are file state and gm_objects_reset() is the fixture hook
 * that stands in for constructing a fresh Scene. */
static int32_t g_next_id;
static int g_dispatch_depth;

typedef struct {
    double sound;
    int32_t voice;
    int looping;
    int stopped;
    int paused;
    int64_t start_tick;
} GmVoice;

static GmVoice g_voices[GM_MAX_VOICES];
static int g_nvoices;
static int32_t g_next_voice = 1; /* Scene::next_voice_id starts at 1 */
static int64_t g_audio_tick;

/* ---------------------------------------------------------------- creation */

/* The named engine defaults from Scene::create(); a fresh instance reads these
 * instead of defaulting user fields to 0. */
static void apply_engine_defaults(GmVM* vm, int32_t id, int32_t sprite, Val x, Val y) {
    vm_set_field(vm, id, "id", VAL(id));
    vm_set_field(vm, id, "x", x);
    vm_set_field(vm, id, "y", y);
    vm_set_field(vm, id, "sprite_index", VAL(sprite));
    vm_set_field(vm, id, "image_index", VAL(0));
    vm_set_field(vm, id, "image_xscale", VAL(1));
    vm_set_field(vm, id, "image_yscale", VAL(1));
    vm_set_field(vm, id, "image_angle", VAL(0));
    vm_set_field(vm, id, "image_blend", VAL(16777215));
    vm_set_field(vm, id, "image_alpha", VAL(1));
    vm_set_field(vm, id, "image_speed", VAL(1));
    vm_set_field(vm, id, "hspeed", VAL(0));
    vm_set_field(vm, id, "vspeed", VAL(0));
    vm_set_field(vm, id, "speed", VAL(0));
    vm_set_field(vm, id, "direction", VAL(0));
    vm_set_field(vm, id, "friction", VAL(0));
    vm_set_field(vm, id, "gravity", VAL(0));
    vm_set_field(vm, id, "gravity_direction", VAL(270));
    vm_set_field(vm, id, "visible", VAL(1));
}

int32_t gm_instance_create(GmVM* vm, int32_t self, Val x, Val y, int32_t obj) {
    (void)self; /* instance_create does not depend on its caller (Scene::create) */
    if (!vm) return -1;
    if (!gm_object_exists(obj)) {
        /* Scene::create: "object {object} not compiled; no fallback Create" */
        fprintf(stderr, "gm_instance_create: object %d is not in the object table\n", obj);
        return -1;
    }
    g_next_id = (g_next_id > GM_DYNAMIC_ID_FLOOR ? g_next_id : GM_DYNAMIC_ID_FLOOR) + 1;
    int32_t id = g_next_id;

    GmInst* in = vm_add(vm, id, obj);
    if (!in) {
        fprintf(stderr, "gm_instance_create: instance table full (%d)\n", MAX_INST);
        return -1;
    }
    apply_engine_defaults(vm, id, gm_object_sprite(obj), x, y);

    if (gm_dispatch_create(vm, id) != 0) {
        /* The instance is now half-built: Create never ran. Report it rather
         * than handing back an id whose initialisation is silently missing. */
        fprintf(stderr, "gm_instance_create: Create dispatch failed for instance %d (object %d)\n",
                id, obj);
        return -1;
    }
    return id;
}

/* ----------------------------------------------------------------- dispatch */

/* Scene::dispatch(): the instance's own event wins; otherwise the first
 * ancestor that carries one. `type`/`subtype` are the raw event ids. */
/* Set when a dispatch names a body this binary does not carry. The driver turns
 * it into exit code 4 so a corpus run can tell "not compiled in" apart from
 * "ran and disagreed" — the difference matters when reading a diff. */
int gm_missing_body_code = -1;

int gm_dispatch_event(GmVM* vm, int32_t id, int type, int subtype) {
    if (!vm) return -1;
    GmInst* in = vm_inst(vm, id);
    if (!in) return -1; /* Scene::dispatch: "unknown instance" */

    int code = gm_event_code_chain(in->object, type, subtype);
    if (code < 0) return 0; /* no such event anywhere in the chain: a no-op */
    if (g_dispatch_depth >= GM_DISPATCH_BUDGET) {
        fprintf(stderr, "gm_dispatch: event recursion budget exhausted for CODE %d\n", code);
        return -3;
    }

    int32_t prev = vm->cur;
    vm->cur = id; /* the body's selector -1 is this instance */
    g_dispatch_depth++;
    int ran = gml_dispatch(vm, (long)code);
    g_dispatch_depth--;
    vm->cur = prev;

    if (!ran) {
        /* Never silently skip: the table names a body the registry cannot run. */
        fprintf(stderr, "gm_dispatch: CODE %d (object %d) has no generated body\n", code,
                in->object);
        gm_missing_body_code = code;
        return -4;
    }
    return 0;
}

/* ------------------------------------------------------------------- audio */

double gm_audio_play(Val sound, Val priority, int looping) {
    (void)priority; /* Scene::AudioVoice keeps no priority; only the command does */
    if (g_nvoices >= GM_MAX_VOICES) {
        fprintf(stderr, "gm_audio_play: voice table full (%d)\n", GM_MAX_VOICES);
        return 0.0; /* 0 is never a live voice id */
    }
    GmVoice* v = &g_voices[g_nvoices++];
    v->sound = sound;
    v->voice = g_next_voice++;
    v->looping = looping ? 1 : 0;
    v->stopped = 0;
    v->paused = 0;
    v->start_tick = g_audio_tick;
    return (double)v->voice;
}

/* Scene::audio_is_playing_sound, minus the expires_tick half: this host has no
 * sond duration table yet, so every voice is "duration unknown" and therefore
 * keeps playing until it is stopped. */
int gm_audio_is_playing(Val sound) {
    for (int i = 0; i < g_nvoices; i++) {
        const GmVoice* v = &g_voices[i];
        if (v->sound == sound && !v->stopped && !v->paused) return 1;
    }
    return 0;
}

/* Scene::call_audio_stop_sound marks every undrained voice of that sound. */
void gm_audio_stop_sound(Val sound) {
    for (int i = 0; i < g_nvoices; i++)
        if (g_voices[i].sound == sound) g_voices[i].stopped = 1;
}

void gm_audio_pause_all(void) {
    for (int i = 0; i < g_nvoices; i++) g_voices[i].paused = 1;
}

void gm_audio_resume_all(void) {
    for (int i = 0; i < g_nvoices; i++) g_voices[i].paused = 0;
}

void gm_audio_stop_all(void) {
    for (int i = 0; i < g_nvoices; i++) g_voices[i].stopped = 1;
}

/* Tick source for voice start times. GmVM carries no tick counter, so the
 * scheduler that drives this host advances it; the value only ever labels a
 * voice, it does not gate playback yet. */
void gm_audio_step_tick(void) { g_audio_tick++; }

int gm_audio_voice_count(void) { return g_nvoices; }

/* Read-only row access for fixtures and the future scheduler. Returns 0 when
 * the index is out of range. */
int gm_audio_voice_info(int index, double* sound, int32_t* voice, int* looping, int* stopped,
                        int64_t* start_tick) {
    if (index < 0 || index >= g_nvoices) return 0;
    const GmVoice* v = &g_voices[index];
    if (sound) *sound = v->sound;
    if (voice) *voice = v->voice;
    if (looping) *looping = v->looping;
    if (stopped) *stopped = v->stopped;
    if (start_tick) *start_tick = v->start_tick;
    return 1;
}

/* Fixture hook: the equivalent of constructing a fresh Scene. Not part of
 * gml.h - nothing in the generated bodies may call it. */
void gm_objects_reset(void) {
    g_next_id = 0;
    g_dispatch_depth = 0;
    g_nvoices = 0;
    g_next_voice = 1;
    g_audio_tick = 0;
}

/* Integration hook: the collision module keeps its own parent graph because it
 * must answer object_is_a() without a bundle. Feed it the whole declared roster
 * once, before any body runs. */
void gm_objects_register_parents(void) {
    gm_collision_clear_parents();
    for (int i = 0; i < GM_OBJECT_COUNT; i++) {
        int32_t id = gm_object_id_at(i);
        int n = gm_object_parent_count(id);
        for (int k = 0; k < n; k++) gm_collision_add_parent(id, gm_object_parent(id, k));
    }
}

int gm_dispatch_create(GmVM* vm, int32_t id) {
    return gm_dispatch_event(vm, id, 0, 0);
}
