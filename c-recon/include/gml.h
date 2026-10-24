/* GmVM host interface for IR lowered to C (see scripts/ir_to_c.py).
 *
 * The generated functions are the shipped control flow; this header only
 * supplies the primitives they call. Keep it small and auditable: every macro
 * below exists because a bytecode opcode needs it.
 */
#ifndef GML_H
#define GML_H

#include <stddef.h>
#include <stdint.h>

typedef double Val;

/* GML reals. String references keep the VM's encoding: pool refs live at or
 * above 2^40 so they can never collide with gameplay numbers. */
#define VAL(x)        ((Val)(x))
#define STR_REF(id)   (1099511627776.0 + (double)(id))
#define TRUTH(v)      ((v) >= 0.5)
#define BOOL(v)       (((v) >= 0.5) ? 1.0 : 0.0)
#define NOT(v)        (((v) >= 0.5) ? 0.0 : 1.0)
#define NUMBOOL(c)    ((c) ? 1.0 : 0.0)
#define TO_INT(v)     ((double)(int64_t)(v))
#define BAND(a, b)    ((double)((int32_t)(int64_t)(a) & (int32_t)(int64_t)(b)))
#define GM_DIV(a, b)  ((b) == 0.0 ? 0.0 : (a) / (b))
#define GM_ADD(a, b)  ((a) + (b))

#define MAX_INST       64
#define MAX_FIELDS    256
#define MAX_ARRAYS    256
#define MAX_GLOBALS   512
#define MAX_ENV        32
#define MAX_ENV_SEL    256
#define NAME_LEN       48

typedef struct { char name[NAME_LEN]; Val value; } GmField;
typedef struct { char name[NAME_LEN]; int32_t index; Val value; } GmArraySlot;

typedef struct {
    int32_t id;
    int32_t object;
    int alive;
    int active;
    GmField fields[MAX_FIELDS];
    int nfields;
    GmArraySlot arrays[MAX_ARRAYS];
    int narrays;
    int32_t alarms[12];
} GmInst;

typedef struct { char name[NAME_LEN]; Val value; } GmGlobal;

typedef struct {
    int32_t cur;                 /* current self */
    int32_t other;               /* `other` for collision dispatch, -1 when unset */
    /* pseudo-fields the VM answers for selector -1 (Scene::read special cases) */
    double  score;
    int32_t view;
    double  room_width, room_height;
    GmInst inst[MAX_INST];
    int ninst;
    GmGlobal globals[MAX_GLOBALS];
    int nglobals;
    uint64_t rng;
    /* with-environment frames: selector results and cursor */
    struct { int32_t ids[MAX_ENV_SEL]; int n; int pos; int32_t prev; } env[MAX_ENV];
    int nenv;
} GmVM;

/* lifecycle */
void  vm_init(GmVM* vm, int32_t self);
GmInst* vm_inst(GmVM* vm, int32_t id);
GmInst* vm_add(GmVM* vm, int32_t id, int32_t object);
int32_t vm_first_of_object(GmVM* vm, int32_t object);   /* -1 when none */

/* selector resolution: -1 current, -5 global sentinel, -2 other, >=0 object */
int32_t vm_resolve(GmVM* vm, Val selector);

/* field / array access used by generated code */
Val   GM_READ(GmVM* vm, int32_t selector, const char* name);
void  GM_WRITE(GmVM* vm, int32_t selector, const char* name, Val value);
/* fixture helpers: address one instance by id, bypassing selector semantics */
void  vm_set_field(GmVM* vm, int32_t id, const char* name, Val value);
void  vm_set_array(GmVM* vm, int32_t id, const char* name, int32_t index, Val value);
Val   GM_READ_ARR(GmVM* vm, Val target, const char* name, Val index);
void  GM_WRITE_ARR(GmVM* vm, Val target, const char* name, Val index, Val value);

/* builtin dispatch; argc is the shipped arity */
Val   GM_CALL(GmVM* vm, const char* name, int argc, ...);

/* geometry: emitted by crates/asset/examples/dump_sprites_c.rs */
typedef struct {
    int32_t id, width, height, origin_x, origin_y;
    int32_t has_bbox, l, r, t, b;   /* recorded manual SPRT box when has_bbox */
    int32_t frames;
} GmSprite;
extern const GmSprite GM_SPRITES[];
extern const int GM_SPRITE_COUNT;

/* collision (c-recon/src/collision.c) */
int32_t gm_instance_place(GmVM* vm, int32_t self, Val x, Val y, int32_t obj);
int     gm_place_meeting(GmVM* vm, int32_t self, Val x, Val y, int32_t obj);

/* object creation + Create dispatch (c-recon/src/objects.c) */
int32_t gm_instance_create(GmVM* vm, int32_t self, Val x, Val y, int32_t obj);
int     gm_dispatch_create(GmVM* vm, int32_t id);

/* with-environment (pushenv/popenv) */
int   GM_PUSHENV(GmVM* vm, Val selector);
int   GM_POPENV_NEXT(GmVM* vm);

/* generated bodies (one per CODE id) */
void gml_0000(GmVM* vm);
void gml_0012(GmVM* vm);
void gml_0792(GmVM* vm);

#endif
