/* Host primitives for IR lowered to C.
 *
 * M0 scope: instance table, fields, arrays, globals, selector resolution and
 * the builtins CODE 12 uses. Every semantic below mirrors crates/core:
 *   - selector -1 self, -5 global, -2 other, >=0 first live instance of that
 *     object (parents included, matching Scene::select_for_access);
 *   - `alarm` is a 12-slot integer array, not a field;
 *   - the RNG is the VM's LCG so random_range agrees bit for bit.
 */
#include "gml.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void vm_init(GmVM* vm, int32_t self) {
    memset(vm, 0, sizeof(*vm));
    vm->cur = self;
    vm->other = -1;
    vm->rng = 305419896ull; /* Scene::default().rng_seed */
    gm_vm_init_ext(vm);
}

GmInst* vm_inst(GmVM* vm, int32_t id) {
    for (int i = 0; i < vm->ninst; i++)
        if (vm->inst[i].id == id) return &vm->inst[i];
    return NULL;
}

GmInst* vm_add(GmVM* vm, int32_t id, int32_t object) {
    if (vm->ninst >= MAX_INST) return NULL;
    GmInst* in = &vm->inst[vm->ninst++];
    memset(in, 0, sizeof(*in));
    in->id = id;
    in->object = object;
    in->alive = 1;
    in->active = 1;
    for (int k = 0; k < 12; k++) in->alarms[k] = -1;
    return in;
}

int32_t vm_first_of_object(GmVM* vm, int32_t object) {
    for (int i = 0; i < vm->ninst; i++)
        if (vm->inst[i].alive && vm->inst[i].object == object) return vm->inst[i].id;
    return -1;
}

/* Mirrors ir_scene.rs select(): alive && active, own object or any ancestor,
 * ascending id (the VM iterates a BTreeMap, so `with` picks the lowest id).
 * An id at or above 100000 is an absolute instance id, never an object
 * selector (ir_scene.rs:1474). */
int vm_select(GmVM* vm, Val selector, int32_t* out, int max) {
    int32_t s = (int32_t)selector;
    if (max <= 0) return 0;
    if (s == -1) { out[0] = vm->cur; return 1; }
    if (s == -2) { out[0] = vm->other >= 0 ? vm->other : vm->cur; return 1; }
    if (s < 0) return 0;
    int n = 0;
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (!in->alive || !in->active) continue;
        int hit = (s >= 100000) ? (in->id == s)
                                : (in->object == s || gm_object_is_a(in->object, s));
        if (!hit) continue;
        int k = n++;
        while (k > 0 && out[k - 1] > in->id) { out[k] = out[k - 1]; k--; }
        out[k] = in->id;
        if (n >= max) break;
    }
    return n;
}

jmp_buf gm_error_jmp;
int gm_error_active = 0;
char gm_error_msg[128];

void gm_fail_msg(const char* msg) {
    if (!gm_error_active) return;
    if (gm_dispatch_code >= 0)
        snprintf(gm_error_msg, sizeof gm_error_msg, "CODE %d: %s", gm_dispatch_code, msg);
    else
        snprintf(gm_error_msg, sizeof gm_error_msg, "%s", msg);
    longjmp(gm_error_jmp, 1);
}

Val gm_div(Val a, Val b) {
    if (b == 0.0) { gm_fail_msg("division by zero"); return 0.0; }
    return a / b;
}

void gm_fail(const char* what, int32_t selector) {
    if (gm_error_active) {
        /* The message text matches ir_scene.rs so both sides produce the same
         * ERROR line and a diff can compare them. */
        snprintf(gm_error_msg, sizeof gm_error_msg, "%s has no receiver for selector %d",
                 what, selector);
        longjmp(gm_error_jmp, 1);
    }
}

int32_t vm_resolve(GmVM* vm, Val selector) {
    int32_t ids[MAX_ENV_SEL];
    int n = vm_select(vm, selector, ids, MAX_ENV_SEL);
    if (n > 0) return ids[0];
    int32_t s = (int32_t)selector;
    if (s < 0) return -1;
    /* select_for_access(): a read still resolves a deactivated instance, so a
     * body that deactivates everything and then reads its own object keeps
     * working. */
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (!in->alive) continue;
        if ((s >= 100000) ? (in->id == s)
                          : (in->object == s || gm_object_is_a(in->object, s)))
            return in->id;
    }
    return -1;
}

/* Scene::select_for_access(): the strict select (alive && active) wins; when it
 * is empty, every alive instance matching the selector still counts, including
 * deactivated ones. Writes go to ALL of them: GameMaker's `obj.var = v` is a
 * loop over instances, not a pick-first. Reading keeps using vm_resolve, which
 * takes the first of the same set. */
static int vm_select_access(GmVM* vm, Val selector, int32_t* ids, int cap) {
    int n = vm_select(vm, selector, ids, cap);
    if (n > 0) return n;
    int32_t s = (int32_t)selector;
    if (s < 0) return 0;
    n = 0;
    for (int i = 0; i < vm->ninst && n < cap; i++) {
        GmInst* in = &vm->inst[i];
        if (!in->alive) continue;
        if ((s >= 100000) ? (in->id == s)
                          : (in->object == s || gm_object_is_a(in->object, s)))
            ids[n++] = in->id;
    }
    return n;
}

static GmField* find_field(GmInst* in, const char* name) {
    for (int i = 0; i < in->nfields; i++)
        if (strcmp(in->fields[i].name, name) == 0) return &in->fields[i];
    return NULL;
}

static GmField* ensure_field(GmInst* in, const char* name) {
    GmField* f = find_field(in, name);
    if (f) return f;
    if (in->nfields >= MAX_FIELDS) return NULL;
    f = &in->fields[in->nfields++];
    snprintf(f->name, NAME_LEN, "%s", name);
    f->value = 0.0;
    return f;
}

static GmGlobal* find_global(GmVM* vm, const char* name) {
    for (int i = 0; i < vm->nglobals; i++)
        if (strcmp(vm->globals[i].name, name) == 0) return &vm->globals[i];
    return NULL;
}

static GmGlobal* ensure_global(GmVM* vm, const char* name) {
    GmGlobal* g = find_global(vm, name);
    if (g) return g;
    if (vm->nglobals >= MAX_GLOBALS) return NULL;
    g = &vm->globals[vm->nglobals++];
    snprintf(g->name, NAME_LEN, "%s", name);
    g->value = 0.0;
    return g;
}

Val GM_READ(GmVM* vm, int32_t selector, const char* name) {
    if (selector == -1) {
        if (strcmp(name, "score") == 0) return vm->score;
        if (strcmp(name, "view_current") == 0) return (Val)vm->view;
        if (strcmp(name, "room_width") == 0) return vm->room_width;
        if (strcmp(name, "room_height") == 0) return vm->room_height;
        if (strcmp(name, "view_xview") == 0 || strcmp(name, "view_yview") == 0) return 0.0;
        if (strcmp(name, "view_wport") == 0) return vm->room_width;
        if (strcmp(name, "view_hport") == 0) return vm->room_height;
        if (strcmp(name, "room") == 0) return vm->current_room;
    }
    if (selector <= -5) {
        GmGlobal* g = find_global(vm, name);
        return g ? g->value : 0.0;
    }
    int32_t id = vm_resolve(vm, (Val)selector);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) {
        if (selector >= 0) gm_fail("read", (int32_t)selector);
        return 0.0;
    }
    /* Built-in read-only instance fields (ir_scene.rs self_field). Without
     * `id` a body doing `with (other.id)` resolves id 0, i.e. "the first
     * instance of object 0", and can destroy the wrong instances. */
    if (strcmp(name, "id") == 0) return (Val)in->id;
    if (strcmp(name, "image_number") == 0 || strcmp(name, "image_single") == 0) {
        GmField* sp = find_field(in, "sprite_index");
        return (Val)gm_sprite_frames(sp ? (int32_t)sp->value : -1);
    }
    GmField* f = find_field(in, name);
    return f ? f->value : 0.0;
}

void GM_WRITE(GmVM* vm, int32_t selector, const char* name, Val value) {
    if (selector == -1 && strcmp(name, "score") == 0) { vm->score = value; return; }
    if (selector <= -5) {
        GmGlobal* g = ensure_global(vm, name);
        if (g) g->value = value;
        return;
    }
    int32_t ids[MAX_ENV_SEL];
    int n = vm_select_access(vm, (Val)selector, ids, MAX_ENV_SEL);
    if (n == 0) {
        if (selector >= 0) gm_fail("write", (int32_t)selector);
        return;
    }
    for (int i = 0; i < n; i++) {
        GmInst* in = vm_inst(vm, ids[i]);
        if (!in) continue;
        GmField* f = ensure_field(in, name);
        if (f) f->value = value;
    }
}

/* Fixture addressing: the state-file protocol names an instance id directly, so
 * these bypass object-selector semantics instead of pretending the id is one. */
static GmArraySlot* find_slot(GmInst* in, const char* name, int32_t index);

void vm_set_field(GmVM* vm, int32_t id, const char* name, Val value) {
    GmInst* in = vm_inst(vm, id);
    if (!in) return;
    GmField* f = ensure_field(in, name);
    if (f) f->value = value;
}

void vm_set_array(GmVM* vm, int32_t id, const char* name, int32_t index, Val value) {
    GmInst* in = vm_inst(vm, id);
    if (!in) return;
    if (strcmp(name, "alarm") == 0) {
        if (index >= 0 && index < 12) in->alarms[index] = (int32_t)value;
        return;
    }
    GmArraySlot* s = find_slot(in, name, index);
    if (!s) {
        if (in->narrays >= MAX_ARRAYS) return;
        s = &in->arrays[in->narrays++];
        snprintf(s->name, NAME_LEN, "%s", name);
        s->index = index;
    }
    s->value = value;
}

static GmArraySlot* find_slot(GmInst* in, const char* name, int32_t index) {
    for (int i = 0; i < in->narrays; i++)
        if (in->arrays[i].index == index && strcmp(in->arrays[i].name, name) == 0)
            return &in->arrays[i];
    return NULL;
}

Val GM_READ_ARR(GmVM* vm, Val target, const char* name, Val index) {
    /* Scene::read answers the view_* arrays for selector -1 before any instance
     * lookup; a body that stores view_visible[0] must not create an instance
     * array of that name. */
    if ((int32_t)target == -1) {
        int32_t k = (int32_t)index;
        int ok = (k >= 0 && k < 8);
        if (strcmp(name, "view_visible") == 0) return (ok && vm->view_visible[k]) ? 1.0 : 0.0;
        if (strcmp(name, "view_xview") == 0) return ok ? vm->view_pos[k][0] : 0.0;
        if (strcmp(name, "view_yview") == 0) return ok ? vm->view_pos[k][1] : 0.0;
        if (strcmp(name, "view_wport") == 0) return ok ? (vm->view_port_set[k] ? vm->view_port[k][0] : vm->display_w) : vm->display_w;
        if (strcmp(name, "view_hport") == 0) return ok ? (vm->view_port_set[k] ? vm->view_port[k][1] : vm->display_h) : vm->display_h;
    }
    int32_t id = vm_resolve(vm, target);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) {
        if (target >= 0) gm_fail("read", (int32_t)target);
        return 0.0;
    }
    if (strcmp(name, "alarm") == 0) {
        int32_t k = (int32_t)index;
        return (k >= 0 && k < 12) ? (Val)in->alarms[k] : 0.0;
    }
    GmArraySlot* s = find_slot(in, name, (int32_t)index);
    return s ? s->value : 0.0;
}

void GM_WRITE_ARR(GmVM* vm, Val target, const char* name, Val index, Val value) {
    if ((int32_t)target == -1) {
        int32_t k = (int32_t)index;
        if (k >= 0 && k < 8) {
            if (strcmp(name, "view_visible") == 0) { vm->view_visible[k] = value >= 0.5; return; }
            if (strcmp(name, "view_xview") == 0) { vm->view_pos[k][0] = value; return; }
            if (strcmp(name, "view_yview") == 0) { vm->view_pos[k][1] = value; return; }
            if (strcmp(name, "view_wport") == 0) { vm->view_port[k][0] = value; vm->view_port_set[k] = 1; return; }
            if (strcmp(name, "view_hport") == 0) { vm->view_port[k][1] = value; vm->view_port_set[k] = 1; return; }
        } else if (strcmp(name, "view_visible") == 0) {
            return;   /* out of range is a silent no-op in the VM */
        }
    }
    int32_t ids[MAX_ENV_SEL];
    int n = vm_select_access(vm, target, ids, MAX_ENV_SEL);
    if (n == 0) {
        if (target >= 0) gm_fail("write", (int32_t)target);
        return;
    }
    for (int i = 0; i < n; i++) {
        GmInst* in = vm_inst(vm, ids[i]);
        if (!in) continue;
        if (strcmp(name, "alarm") == 0) {
            int32_t k = (int32_t)index;
            if (k >= 0 && k < 12) in->alarms[k] = (int32_t)value;
            continue;
        }
        GmArraySlot* s = find_slot(in, name, (int32_t)index);
        if (!s) {
            if (in->narrays >= MAX_ARRAYS) continue;
            s = &in->arrays[in->narrays++];
            snprintf(s->name, NAME_LEN, "%s", name);
            s->index = (int32_t)index;
        }
        s->value = value;
    }
}

static double next_rand(uint64_t* seed) {
    *seed = *seed * 6364136223846793005ull + 1442695040888963407ull;
    return (double)(*seed >> 11) / 9007199254740992.0; /* 2^53 */
}

/* The ext builtins draw from the same LCG; exposing it keeps one stream. */
double gm_next_rand(GmVM* vm) { return next_rand(&vm->rng); }
void gm_rng_add(GmVM* vm, uint64_t delta) { vm->rng += delta; }

static double gm_sign(Val v) { return v > 0 ? 1.0 : (v < 0 ? -1.0 : 0.0); }

Val GM_CALL(GmVM* vm, const char* name, int argc, ...) {
    Val a[16] = {0};
    va_list ap;
    va_start(ap, argc);
    for (int i = 0; i < argc && i < 16; i++) a[i] = va_arg(ap, Val);
    va_end(ap);

    if (strcmp(name, "sign") == 0) return gm_sign(a[0]);
    if (strcmp(name, "min") == 0) return a[0] < a[1] ? a[0] : a[1];
    if (strcmp(name, "max") == 0) return a[0] > a[1] ? a[0] : a[1];
    if (strcmp(name, "instance_exists") == 0) {
        int32_t ids[MAX_ENV_SEL];
        return vm_select(vm, a[0], ids, MAX_ENV_SEL) > 0 ? 1.0 : 0.0;
    }
    if (strcmp(name, "instance_destroy") == 0) {
        /* Scene::destroy(): retire first, then run the Destroy event once. */
        GmInst* in = vm_inst(vm, vm->cur);
        if (in && in->alive) { in->alive = 0; gm_dispatch_event(vm, vm->cur, 1, 0); }
        return 0.0;
    }
    if (strcmp(name, "action_kill_object") == 0) {
        GmInst* in = vm_inst(vm, vm->cur);
        if (in && in->alive) { in->alive = 0; gm_dispatch_event(vm, vm->cur, 1, 0); }
        return 0.0;
    }
    if (strcmp(name, "choose") == 0) {
        if (argc <= 0) return 0.0;
        double r = next_rand(&vm->rng);
        int idx = (int)(r * (double)argc);
        if (idx >= argc) idx = argc - 1;
        if (idx < 0) idx = 0;
        return a[idx];
    }
    if (strcmp(name, "instance_number") == 0) {
        int32_t ids[MAX_ENV_SEL];
        return (Val)vm_select(vm, a[0], ids, MAX_ENV_SEL);
    }
    if (strcmp(name, "instance_activate_all") == 0) {
        for (int i = 0; i < vm->ninst; i++) if (vm->inst[i].alive) vm->inst[i].active = 1;
        return 0.0;
    }
    if (strcmp(name, "instance_deactivate_all") == 0) {
        int keep_self = a[0] >= 0.5;
        for (int i = 0; i < vm->ninst; i++)
            if (vm->inst[i].alive && !(keep_self && vm->inst[i].id == vm->cur))
                vm->inst[i].active = 0;
        return 0.0;
    }
    if (strcmp(name, "instance_activate_object") == 0 ||
        strcmp(name, "instance_deactivate_object") == 0) {
        int32_t s = (int32_t)a[0];
        if (s < 0) { fprintf(stderr, "GM_CALL: negative activation selector %d\n", s); return 0.0; }
        int on = strcmp(name, "instance_activate_object") == 0;
        for (int i = 0; i < vm->ninst; i++) {
            GmInst* in = &vm->inst[i];
            if (!in->alive) continue;
            int hit = (s >= 100000) ? (in->id == s)
                                    : (in->object == s || gm_object_is_a(in->object, s));
            if (hit) in->active = on;
        }
        return 0.0;
    }
    if (strcmp(name, "random_range") == 0) {
        double lo = a[0] < a[1] ? a[0] : a[1];
        double hi = a[0] < a[1] ? a[1] : a[0];
        return lo + (hi - lo) * next_rand(&vm->rng);
    }
    /* ---- wired to the ported engine primitives ------------------------ */
    if (strcmp(name, "instance_place") == 0)
        return (Val)gm_instance_place(vm, vm->cur, a[0], a[1], (int32_t)a[2]);
    if (strcmp(name, "place_meeting") == 0)
        return gm_place_meeting(vm, vm->cur, a[0], a[1], (int32_t)a[2]) ? 1.0 : 0.0;
    if (strcmp(name, "distance_to_object") == 0)
        return gm_distance_to_object(vm, vm->cur, a[0]);
    if (strcmp(name, "instance_create") == 0)
        return (Val)gm_instance_create(vm, vm->cur, a[0], a[1], (int32_t)a[2]);
    if (strcmp(name, "audio_play_sound") == 0)
        return gm_audio_play(a[0], a[1], a[2] >= 0.5);
    if (strcmp(name, "audio_is_playing") == 0)
        return (Val)gm_audio_is_playing(a[0]);
    if (strcmp(name, "audio_stop_sound") == 0) { gm_audio_stop_sound(a[0]); return 0.0; }
    if (strcmp(name, "audio_stop_all") == 0) { gm_audio_stop_all(); return 0.0; }
    if (strcmp(name, "audio_pause_all") == 0) { gm_audio_pause_all(); return 0.0; }
    if (strcmp(name, "audio_resume_all") == 0) { gm_audio_resume_all(); return 0.0; }
    Val ext = 0.0;
    if (gm_call_ext(vm, name, argc, a, &ext)) return ext;
    fprintf(stderr, "GM_CALL: unimplemented builtin %s/%d\n", name, argc);
    return 0.0;
}

int GM_PUSHENV(GmVM* vm, Val selector) {
    if (vm->nenv >= MAX_ENV) return 0;
    int32_t ids[MAX_ENV_SEL];
    /* alive && active && own object or any ancestor, ascending id */
    int n = vm_select(vm, selector, ids, MAX_ENV_SEL);
    if (n == 0) return 0;                          /* empty: jump to popenv */
    int f = vm->nenv++;
    memcpy(vm->env[f].ids, ids, sizeof(int32_t) * (size_t)n);
    vm->env[f].n = n;
    vm->env[f].pos = 0;
    vm->env[f].prev = vm->cur;
    vm->cur = ids[0];
    return 1;
}

int GM_POPENV_NEXT(GmVM* vm) {
    if (vm->nenv == 0) return 0;
    int f = vm->nenv - 1;
    if (vm->env[f].pos + 1 < vm->env[f].n) {
        vm->env[f].pos++;
        vm->cur = vm->env[f].ids[vm->env[f].pos];
        return 1;
    }
    vm->cur = vm->env[f].prev;
    vm->nenv--;
    return 0;
}
