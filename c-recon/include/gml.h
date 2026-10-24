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
#include <setjmp.h>

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
/* Division reports a zero divisor the way the VM does instead of silently
 * yielding 0 — eight bodies in the corpus divide by a zero-initialised field
 * and the interpreter refuses them. */
Val  gm_div(Val a, Val b);
#define GM_DIV(a, b)  gm_div((a), (b))
#define GM_ADD(a, b)  ((a) + (b))

#define MAX_INST      256   /* a RoomCC body creates the whole room */
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
typedef struct { int32_t object, type, subtype, code; } GmEventRow;

#define GM_MAX_MAPS 8
#define GM_MAP_MAX 32
#define GM_INI_MAX 64

typedef struct {
    int32_t cur;                 /* current self */
    int32_t other;               /* `other` for collision dispatch, -1 when unset */
    /* pseudo-fields the VM answers for selector -1 (Scene::read special cases) */
    double  score;
    int32_t view;
    double  room_width, room_height;
    /* state the ext builtins own (c-recon/src/builtins2.c) */
    double  display_w, display_h, current_room;
    int     view_visible[8];
    double  view_pos[8][2];      /* view_xview / view_yview */
    double  view_port[8][2];     /* view_wport / view_hport */
    int     view_port_set[8];
    double  current_font;
    int32_t draw_color;
    double  draw_alpha;
    struct { int32_t id; int n; struct { double key, val; } kv[GM_MAP_MAX]; } maps[GM_MAX_MAPS];
    int     nmaps;
    int32_t next_map_id;
    struct { double file, sec, key, val; } ini[GM_INI_MAX];
    int     nini;
    double  ini_open_file;
    double  next_part_type;
    double  next_part_system;
    double  part_systems[64];
    int     npart_systems;
    int     ndyn_strings;        /* dynamic pool slots handed out */
    int     npart_types;
    GmInst inst[MAX_INST];
    int ninst;
    GmGlobal globals[MAX_GLOBALS];
    int nglobals;
    uint64_t rng;
    /* with-environment frames: selector results and cursor */
    struct { int32_t ids[MAX_ENV_SEL]; int n; int pos; int32_t prev; } env[MAX_ENV];
    int nenv;
} GmVM;

/* Error channel: the VM aborts a body on a bad receiver or a zero divisor and
 * reports why. Returning 0 instead made the C side silently succeed where the
 * interpreter refused, which no differential can call equivalent. */
extern jmp_buf gm_error_jmp;
extern int gm_error_active;
void gm_fail(const char* what, int32_t selector);
void gm_fail_msg(const char* msg);
extern char gm_error_msg[128];

/* lifecycle */
void  vm_init(GmVM* vm, int32_t self);
void  gm_vm_init_ext(GmVM* vm);
double gm_next_rand(GmVM* vm);
void   gm_rng_add(GmVM* vm, uint64_t delta);
int    gm_call_ext(GmVM* vm, const char* name, int argc, const Val* a, Val* out);
GmInst* vm_inst(GmVM* vm, int32_t id);
GmInst* vm_add(GmVM* vm, int32_t id, int32_t object);
int32_t vm_first_of_object(GmVM* vm, int32_t object);   /* -1 when none */
int     vm_select(GmVM* vm, Val selector, int32_t* out, int max);

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
int     gm_dispatch_event(GmVM* vm, int32_t id, int type, int subtype);
/* Field helpers objects.c shares with the tick integration. */
double  gm_field_or(GmInst* in, const char* name, double dflt);
GmField* gm_find_field(GmInst* in, const char* name);
void    gm_set_field(GmInst* in, const char* name, double v);
/* One scheduler tick: alarm decrement/dispatch (event 2), Step (3,0), then the
 * standard motion integration. */
int     gm_tick(GmVM* vm);
extern int gm_missing_body_code;
extern int gm_dispatch_code;
/* object table accessors (c-recon/gen/objects_data.c, generated) */
int32_t gm_object_sprite(int32_t id);
int     gm_object_create_code(int32_t id);
int     gm_object_parent_count(int32_t id);
int32_t gm_object_parent(int32_t id, int index);
int     gm_object_exists(int32_t id);
int32_t gm_object_id_at(int index);
const char* gm_object_name(int32_t id);
/* event table: own event first, then the first ancestor carrying one */
int     gm_event_code(int32_t object, int32_t type, int32_t subtype);
int     gm_event_code_chain(int32_t object, int32_t type, int32_t subtype);
/* register every declared object's parent chain into the collision graph */
void    gm_objects_register_parents(void);
extern const int GM_OBJECT_COUNT;
extern const int GM_STRING_TABLE_LEN;
/* audio voices (c-recon/src/objects.c) */
double  gm_audio_play(Val sound, Val priority, int looping);
int     gm_audio_is_playing(Val sound);
void    gm_audio_stop_sound(Val sound);
void    gm_audio_stop_all(void);
void    gm_audio_pause_all(void);
void    gm_audio_resume_all(void);

/* object inheritance (c-recon/src/collision.c) */
int     gm_object_is_a(int32_t object, int32_t sel);
int     gm_sprite_frames(int32_t sprite);
int     gm_instance_box(GmVM* vm, int32_t id, double* l, double* r, double* t, double* b);
int     gm_box_at(int32_t mask, int32_t sprite, double x, double y,
                  double sx, double sy, double angle,
                  double* l, double* r, double* t, double* b);

/* collision parent graph (c-recon/src/collision.c) */
void    gm_collision_add_parent(int32_t child, int32_t parent);
void    gm_collision_clear_parents(void);
Val     gm_distance_to_object(GmVM* vm, int32_t self, Val obj);

/* with-environment (pushenv/popenv) */
int   GM_PUSHENV(GmVM* vm, Val selector);
int   GM_POPENV_NEXT(GmVM* vm);

/* generated bodies (one per CODE id) */
void gml_0000(GmVM* vm);
void gml_0012(GmVM* vm);
void gml_0792(GmVM* vm);

#endif
