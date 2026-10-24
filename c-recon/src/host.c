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

int32_t vm_resolve(GmVM* vm, Val selector) {
    int32_t s = (int32_t)selector;
    if (s == -1) return vm->cur;
    if (s == -2) return vm->other;
    if (s < 0) return -1; /* globals are handled by the accessors */
    return vm_first_of_object(vm, s);
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
    }
    if (selector <= -5) {
        GmGlobal* g = find_global(vm, name);
        return g ? g->value : 0.0;
    }
    int32_t id = vm_resolve(vm, (Val)selector);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) return 0.0;
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
    int32_t id = vm_resolve(vm, (Val)selector);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) return;
    GmField* f = ensure_field(in, name);
    if (f) f->value = value;
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
    int32_t id = vm_resolve(vm, target);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) return 0.0;
    if (strcmp(name, "alarm") == 0) {
        int32_t k = (int32_t)index;
        return (k >= 0 && k < 12) ? (Val)in->alarms[k] : 0.0;
    }
    GmArraySlot* s = find_slot(in, name, (int32_t)index);
    return s ? s->value : 0.0;
}

void GM_WRITE_ARR(GmVM* vm, Val target, const char* name, Val index, Val value) {
    int32_t id = vm_resolve(vm, target);
    GmInst* in = id >= 0 ? vm_inst(vm, id) : NULL;
    if (!in) return;
    if (strcmp(name, "alarm") == 0) {
        int32_t k = (int32_t)index;
        if (k >= 0 && k < 12) in->alarms[k] = (int32_t)value;
        return;
    }
    GmArraySlot* s = find_slot(in, name, (int32_t)index);
    if (!s) {
        if (in->narrays >= MAX_ARRAYS) return;
        s = &in->arrays[in->narrays++];
        snprintf(s->name, NAME_LEN, "%s", name);
        s->index = (int32_t)index;
    }
    s->value = value;
}

static double next_rand(uint64_t* seed) {
    *seed = *seed * 6364136223846793005ull + 1442695040888963407ull;
    return (double)(*seed >> 11) / 9007199254740992.0; /* 2^53 */
}

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
        int32_t id = vm_resolve(vm, a[0]);
        return id >= 0 && vm_inst(vm, id) ? 1.0 : 0.0;
    }
    if (strcmp(name, "instance_destroy") == 0) {
        GmInst* in = vm_inst(vm, vm->cur);
        if (in) in->alive = 0;
        return 0.0;
    }
    if (strcmp(name, "random_range") == 0) {
        double lo = a[0] < a[1] ? a[0] : a[1];
        double hi = a[0] < a[1] ? a[1] : a[0];
        return lo + (hi - lo) * next_rand(&vm->rng);
    }
    if (strcmp(name, "audio_play_sound") == 0) {
        /* M0: no voice table yet; return a synthetic id so callers stay alive */
        static int64_t next_voice = 1;
        return (Val)next_voice++;
    }
    fprintf(stderr, "GM_CALL: unimplemented builtin %s/%d\n", name, argc);
    return 0.0;
}

int GM_PUSHENV(GmVM* vm, Val selector) {
    if (vm->nenv >= MAX_ENV) return 0;
    int32_t s = (int32_t)selector;
    int32_t ids[MAX_ENV_SEL];
    int n = 0;
    if (s >= 100000) {
        if (vm_inst(vm, s)) ids[n++] = s;         /* instance id selector */
    } else if (s >= 0) {
        for (int i = 0; i < vm->ninst && n < MAX_ENV_SEL; i++)
            if (vm->inst[i].alive && vm->inst[i].object == s) ids[n++] = vm->inst[i].id;
    }
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
