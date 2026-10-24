/* Collision geometry for IR lowered to C.
 *
 * Everything here is a line-by-line port of the Rust oracle, not a redesign:
 *
 *   crates/core/src/ir_scene.rs:769-772   bounds_for_instance (half-open view)
 *   crates/core/src/ir_scene.rs:782-794   compute_bounding_box_for_instance
 *   crates/core/src/ir_scene.rs:800-872   compute_bounding_box_at
 *   crates/core/src/parts/host_impl.rs:11-30   select
 *   crates/core/src/parts/host_impl.rs:285-313 instance_place
 *   crates/core/src/parts/host_impl.rs:499-505 place_meeting
 *   crates/core/src/parts/host_impl.rs:468-498 distance_to_object
 *
 * The arithmetic stays in f32 exactly where the Rust casts to f32: the runner's
 * lrint path rounds the LOW edge first and then adds the scaled width, so the
 * width of the intermediate is load-bearing (see the half-pixel fixture in
 * tests/collision_test.c). Widening early changes the answer.
 *
 * One Rust input is still not available in the C host and is reported rather
 * than faked:
 *   - the compiled object table's parent chain: installed through
 *     gm_collision_add_parent() (direct edges, closed at query time).
 * SPRT collision masks are no longer in that list: they are emitted into
 * GM_SPRITE_MASKS (see gm_mask_frame) and drive collision_line(prec=1).
 */
#include "gml.h"

#include <math.h>
#include <string.h>
#include <stdio.h>

/* clang rewrites a sinf/cosf pair on the same argument into a sincosf call,
 * which bionic at this API level does not export (Rust's f32::sin_cos lowers
 * the same way, so the platform never needed the symbol for rustc either).
 * Keep the two libm calls separate instead of depending on it: noinline so the
 * pair never becomes visible to the optimiser. */
#if defined(__GNUC__)
__attribute__((noinline))
#endif
static float gm_sinf(float v) { return sinf(v); }

#if defined(__GNUC__)
__attribute__((noinline))
#endif
static float gm_cosf(float v) { return cosf(v); }

/* The runner's "no instance" result, as returned by instance_place. */
#define GM_NOONE (-4)

/* -------------------------------------------------------------------------
 * Object parent chain.
 *
 * Rust stores `object_parents: object -> parent_chain` (the flattened chain,
 * nearest ancestor first) and `select` asks `chain.contains(&sel)`
 * (host_impl.rs:24-25). The C host has no bundle loader yet, so the chain is
 * kept here as direct edges and closed at query time: reachability over direct
 * edges is the same set as a flattened transitive chain. The object-table
 * owner (c-recon/src/objects.c) must call gm_collision_add_parent() once per
 * edge; with no edges every object is a leaf and only self-matches.
 * ------------------------------------------------------------------------- */
#define GM_MAX_PARENT_EDGES 256
static int32_t g_edge_child[GM_MAX_PARENT_EDGES];
static int32_t g_edge_parent[GM_MAX_PARENT_EDGES];
static int g_edges;

void gm_collision_clear_parents(void) { g_edges = 0; }

void gm_collision_add_parent(int32_t child, int32_t parent) {
    if (g_edges >= GM_MAX_PARENT_EDGES) return;
    g_edge_child[g_edges] = child;
    g_edge_parent[g_edges] = parent;
    g_edges++;
}

/* Reflexive reachability: is `object` the selector or one of its descendants?
 * GM selects children when the selector names an ancestor. Cyclic data (which
 * a valid object tree never has) is cut by `seen`. */
int gm_object_is_a(int32_t object, int32_t sel) {
    int32_t stack[GM_MAX_PARENT_EDGES + 1];
    int32_t seen[GM_MAX_PARENT_EDGES + 1];
    int sp = 0, nseen = 0;
    if (object == sel) return 1;
    stack[sp++] = object;
    seen[nseen++] = object;
    while (sp > 0) {
        int32_t cur = stack[--sp];
        for (int i = 0; i < g_edges; i++) {
            if (g_edge_child[i] != cur) continue;
            int32_t p = g_edge_parent[i];
            if (p == sel) return 1;
            int dup = 0;
            for (int k = 0; k < nseen; k++)
                if (seen[k] == p) { dup = 1; break; }
            if (dup) continue;
            if (nseen < GM_MAX_PARENT_EDGES + 1) seen[nseen++] = p;
            if (sp < GM_MAX_PARENT_EDGES + 1) stack[sp++] = p;
        }
    }
    return 0;
}

/* -------------------------------------------------------------------------
 * Field access.
 *
 * GM_READ cannot be reused: it answers 0.0 for a missing field, while the Rust
 * box reads `unwrap_or(1.0)` for the scales and `unwrap_or(-1.0)` for the
 * indices. Missing x/y is not a default at all — the Rust box is None there
 * (ir_scene.rs:784-785), i.e. the instance never collides.
 * ------------------------------------------------------------------------- */
static const GmField* find_field_c(const GmInst* in, const char* name) {
    for (int i = 0; i < in->nfields; i++)
        if (strcmp(in->fields[i].name, name) == 0) return &in->fields[i];
    return NULL;
}

static double field_or(const GmInst* in, const char* name, double dflt) {
    const GmField* f = find_field_c(in, name);
    return f ? f->value : dflt;
}

/* Rust `f64 as i32`: truncate toward zero, saturate, NaN -> 0. The C cast is
 * undefined outside the representable range, so spell the Rust rule out. */
static int32_t sat_i32(double v) {
    if (v != v) return 0;
    if (v >= 2147483647.0) return INT32_MAX;
    if (v <= -2147483648.0) return INT32_MIN;
    return (int32_t)v;
}

/* Inclusive integer edges, matching compute_bounding_box_at's return. */
typedef struct { double l, r, t, b; } GmBox;

/* Linear scan; the table is 178 entries and ids are dense, so this is cold
 * enough that an index table would only add state to keep in sync. */
static const GmSprite* sprite_lookup(int32_t sid) {
    for (int i = 0; i < GM_SPRITE_COUNT; i++)
        if (GM_SPRITES[i].id == sid) return &GM_SPRITES[i];
    return NULL;
}

static int mask_pixel(const unsigned char* bits, int32_t w, int32_t h, int32_t x, int32_t y) {
    if (x < 0 || y < 0 || x >= w || y >= h) return 0;
    int32_t row = (w + 7) / 8;
    return (bits[y * row + x / 8] & (0x80 >> (x % 8))) != 0;
}

int gm_mask_frame(int32_t sprite, int32_t frame,
                  const unsigned char** bits, int32_t* w, int32_t* h) {
    for (int i = 0; i < GM_SPRITE_MASK_COUNT; i++) {
        const GmMaskSprite* m = &GM_SPRITE_MASKS[i];
        if (m->sprite != sprite || m->nframes <= 0) continue;
        int32_t f = frame < 0 ? 0 : (frame >= m->nframes ? m->nframes - 1 : frame);
        *bits = m->frames[f].bits;
        *w = m->frames[f].width;
        *h = m->frames[f].height;
        return 1;
    }
    return 0;
}

/* ---- per-pixel mask probes (collision_line prec=1 / collision_point prec=1)
 *
 * Mirrors ir_scene.rs `mask_hit`: inverse rotate, un-scale, add the origin,
 * truncate. `mask_probe` returns 1 when the target's mask is ready, 0 when
 * there is no instance or no mask data (caller keeps the bounding-box verdict)
 * and -1 when a zero scale makes every sample miss — Rust's Some(false). */
typedef struct {
    const unsigned char* bits;
    int32_t w, h;
    double ix, iy, sx, sy, ca, sa, ox, oy;
} GmMaskProbe;

static int mask_probe(GmVM* vm, int32_t tid, GmMaskProbe* p) {
    GmInst* in = NULL;
    for (int i = 0; i < vm->ninst; i++)
        if (vm->inst[i].id == tid) { in = &vm->inst[i]; break; }
    if (!in) return 0;
    /* mask_hit keys the mask off sprite_index only; mask_index is a broad-phase
     * input, not the pixel source. */
    int32_t spr = (int32_t)gm_field_or(in, "sprite_index", -1.0);
    int32_t frame = (int32_t)gm_field_or(in, "image_index", 0.0);
    if (!gm_mask_frame(spr, frame, &p->bits, &p->w, &p->h)) return 0;
    p->ix = gm_field_or(in, "x", 0.0);
    p->iy = gm_field_or(in, "y", 0.0);
    p->sx = gm_field_or(in, "image_xscale", 1.0);
    p->sy = gm_field_or(in, "image_yscale", 1.0);
    double ang = gm_field_or(in, "image_angle", 0.0) * (M_PI / 180.0);
    p->ca = cos(ang);
    p->sa = sin(ang);
    p->ox = 0.0;
    p->oy = 0.0;
    const GmSprite* sp = sprite_lookup(spr);
    if (sp) { p->ox = sp->origin_x; p->oy = sp->origin_y; }
    if (p->sx == 0.0 || p->sy == 0.0) return -1;
    return 1;
}

static int mask_probe_pixel(const GmMaskProbe* p, double px, double py) {
    double dx = px - p->ix, dy = py - p->iy;
    double rx = dx * p->ca + dy * p->sa;
    double ry = -dx * p->sa + dy * p->ca;
    int32_t lx = (int32_t)(floor(rx / p->sx) + p->ox);
    int32_t ly = (int32_t)(floor(ry / p->sy) + p->oy);
    return mask_pixel(p->bits, p->w, p->h, lx, ly);
}

int gm_mask_point_test(GmVM* vm, int32_t tid, double px, double py) {
    GmMaskProbe p;
    int r = mask_probe(vm, tid, &p);
    if (r == 0) return -1;
    if (r < 0) return 0;
    return mask_probe_pixel(&p, px, py);
}

int gm_line_mask_test(GmVM* vm, int32_t tid, double x1, double y1, double x2, double y2) {
    GmMaskProbe p;
    int r = mask_probe(vm, tid, &p);
    if (r == 0) return -1;
    if (r < 0) return 0;
    double len = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    long steps = (long)ceil(len * 2.0);
    if (steps < 1) steps = 1;
    if (steps > 4000) steps = 4000;
    for (long s = 0; s <= steps; s++) {
        double t = (double)s / (double)steps;
        if (mask_probe_pixel(&p, x1 + (x2 - x1) * t, y1 + (y2 - y1) * t)) return 1;
    }
    return 0;
}

/* ir_scene.rs:800-872. `mask`/`sprite` are the raw field values; mask_index
 * wins when >= 0 (the caller already resolved that). */
static GmBox box_at(int32_t mask, int32_t sprite, double xd, double yd,
                    double xscale, double yscale, double ang) {
    float x = (float)xd;
    float y = (float)yd;
    int32_t sid = (mask >= 0) ? mask : sprite;
    const GmSprite* sp = sprite_lookup(sid);
    GmBox box;

    if (!sp) {
        /* ir_scene.rs:805-809: no sprite is the integer point (x, y) -- never a
         * default 32x32 box. Note trunc, not floor. */
        float px = truncf(x), py = truncf(y);
        box.l = box.r = (double)px;
        box.t = box.b = (double)py;
        return box;
    }

    float left, right, top, bottom;
    if (sp->has_bbox) {
        /* ir_scene.rs:812-813: the recorded manual SPRT box. Width/origin are
         * not a substitute; the original edges are independent data. */
        left = (float)sp->l;
        right = (float)sp->r;
        top = (float)sp->t;
        bottom = (float)sp->b;
    } else {
        /* ir_scene.rs:840-842: whole-sprite rectangle, inclusive */
        left = 0.0f;
        right = (float)sp->width - 1.0f;
        top = 0.0f;
        bottom = (float)sp->height - 1.0f;
    }

    float ox = (float)sp->origin_x;
    float oy = (float)sp->origin_y;
    float sx = (float)xscale;
    float sy = (float)yscale;
    float angle = (float)ang;
    float l, r, t, b;

    if (angle == 0.0f) {
        /* ir_scene.rs:848-855. The runner's lrint path rounds the low edge
         * first and adds the scaled extent to that integer; scaling is not a
         * point distance. min/max normalize a mirrored (negative) scale. */
        l = rintf(x + (left - ox) * sx);
        r = rintf(l + (right - left + 1.0f) * sx);
        t = rintf(y + (top - oy) * sy);
        b = rintf(t + (bottom - top + 1.0f) * sy);
        float l2 = fminf(l, r), r2 = fmaxf(l, r) - 1.0f;
        float t2 = fminf(t, b), b2 = fmaxf(t, b) - 1.0f;
        l = l2; r = r2; t = t2; b = b2;
    } else {
        /* ir_scene.rs:856-870: project the four corners of the (inclusive)
         * rectangle, i.e. [left, right+1) x [top, bottom+1), then take the
         * axis-aligned hull and subtract the half-open +1 back off. */
        float rad = angle * 3.14159265358979323846f / 180.0f;
        float sn = gm_sinf(rad), cs = gm_cosf(rad);
        float cxs[2] = { left - ox, right + 1.0f - ox };
        float cys[2] = { top - oy, bottom + 1.0f - oy };
        l = INFINITY; r = -INFINITY;
        t = INFINITY; b = -INFINITY;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                float cx = cxs[i] * sx;
                float cy = cys[j] * sy;
                float px = x + cx * cs + cy * sn;
                float py = y + cy * cs - cx * sn;
                l = fminf(l, px); r = fmaxf(r, px);
                t = fminf(t, py); b = fmaxf(b, py);
            }
        }
        float l2 = rintf(l), r2 = rintf(r) - 1.0f;
        float t2 = rintf(t), b2 = rintf(b) - 1.0f;
        l = l2; r = r2; t = t2; b = b2;
    }

    box.l = (double)l;
    box.r = (double)r;
    box.t = (double)t;
    box.b = (double)b;
    return box;
}

/* ir_scene.rs:782-794. Returns 0 where Rust returns None (unknown instance, or
 * an instance that never got x/y), so a half-built instance cannot collide. */
static int box_for_instance(GmVM* vm, int32_t id, GmBox* out);

/* GMS read-only sprite metadata (ir_scene.rs self_field): frame count of the
 * SPRT record behind a sprite id. */
int gm_sprite_frames(int32_t sprite) {
    const GmSprite* sp = sprite_lookup(sprite);
    return sp ? sp->frames : 0;
}

/* Candidate-position box for mp_potential_step: the same Compute_BoundingBox
 * the collision tests use, evaluated at (x, y) instead of the instance's own
 * position. Exporting it keeps one geometry path. */
int gm_box_at(int32_t mask, int32_t sprite, double x, double y,
              double sx, double sy, double angle,
              double* l, double* r, double* t, double* b) {
    GmBox box = box_at(mask, sprite, x, y, sx, sy, angle);
    *l = (double)box.l; *r = (double)box.r; *t = (double)box.t; *b = (double)box.b;
    return 1;
}

/* Exported for the ext builtins (collision_point): the same inclusive box the
 * overlap tests use, never a second geometry path. */
int gm_instance_box(GmVM* vm, int32_t id, double* l, double* r, double* t, double* b) {
    GmBox box;
    if (!box_for_instance(vm, id, &box)) return 0;
    *l = (double)box.l; *r = (double)box.r; *t = (double)box.t; *b = (double)box.b;
    return 1;
}

static int box_for_instance(GmVM* vm, int32_t id, GmBox* out) {
    GmInst* in = vm_inst(vm, id);
    if (!in) return 0;
    if (!find_field_c(in, "x") || !find_field_c(in, "y")) return 0;
    *out = box_at(sat_i32(field_or(in, "mask_index", -1.0)),
                  sat_i32(field_or(in, "sprite_index", -1.0)),
                  field_or(in, "x", 0.0),
                  field_or(in, "y", 0.0),
                  field_or(in, "image_xscale", 1.0),
                  field_or(in, "image_yscale", 1.0),
                  field_or(in, "image_angle", 0.0));
    return 1;
}

/* host_impl.rs:11-30. Target list for a selector. Results are in ascending
 * instance id order, matching the Rust BTreeMap iteration order -- the first
 * hit wins in instance_place, so the order is part of the answer. */
static void sort_ids(int32_t* a, int n) {
    for (int i = 1; i < n; i++) {         /* insertion sort: ids arrive nearly sorted */
        int32_t v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) { a[j + 1] = a[j]; j--; }
        a[j + 1] = v;
    }
}

static int select_ids(GmVM* vm, int32_t self, int32_t sel, int32_t* out, int cap) {
    int n = 0;
    if (cap <= 0) return 0;
    if (sel == -1) { out[0] = self; return 1; }
    if (sel == -2) {                       /* `other`; self when other is unset */
        out[0] = (vm->other >= 0) ? vm->other : self;
        return 1;
    }
    /* Rust: Err("unsupported instance selector") -- noone/global/absent
     * specials never reach instance_place from the compiler. The C host has no
     * error channel here, so the selector simply matches nothing. */
    if (sel < 0) return 0;
    for (int i = 0; i < vm->ninst && n < cap; i++) {
        const GmInst* in = &vm->inst[i];
        if (!in->alive || !in->active) continue;
        if (sel >= 100000) {               /* instance id selector */
            if (in->id != sel) continue;
        } else if (!gm_object_is_a(in->object, sel)) {
            continue;
        }
        out[n++] = in->id;
    }
    sort_ids(out, n);
    return n;
}

/* CSprite::PreciseCollision @0x1e4298: inside the box intersection both masks
 * must have a set pixel at the same world pixel. A sprite without mask data is
 * solid — the runner's `[sprite+0x31] == 0` branch skips the mask test — so the
 * box verdict stands. Only the axis-aligned mapping is wired: the runner's
 * general branch (@0x1e47a8) calls sinf/cosf for BOTH angles before the same
 * truncating cast, and that path is read but not implemented (sign convention
 * still needs an oracle), so rotated instances keep the box verdict. */
static int mask_probe_pos(GmVM* vm, int32_t tid, double x, double y, GmMaskProbe* p) {
    int r = mask_probe(vm, tid, p);
    if (r == 1) { p->ix = x; p->iy = y; }
    return r;
}

static int box_for_at(GmVM* vm, int32_t id, double x, double y, GmBox* out) {
    GmInst* in = vm_inst(vm, id);
    if (!in) return 0;
    *out = box_at(sat_i32(field_or(in, "mask_index", -1.0)),
                  sat_i32(field_or(in, "sprite_index", -1.0)),
                  x, y,
                  field_or(in, "image_xscale", 1.0),
                  field_or(in, "image_yscale", 1.0),
                  field_or(in, "image_angle", 0.0));
    return 1;
}

static int precise_overlap(GmVM* vm, int32_t a, double ax, double ay, int32_t b) {
    GmInst* ib = vm_inst(vm, b);
    if (!ib) return 1;
    /* Rotation: the runner loop we read maps with two linear terms only; its
     * rotated path is not pinned yet, so a rotated sprite keeps the box
     * verdict instead of silently using an unrotated mask. */
    GmInst* ia = vm_inst(vm, a);
    if ((ia && field_or(ia, "image_angle", 0.0) != 0.0) ||
        field_or(ib, "image_angle", 0.0) != 0.0) return 1;
    GmMaskProbe pa, pb;
    int ra = mask_probe_pos(vm, a, ax, ay, &pa);
    if (ra == 0) return 1;                 /* no mask data on A: the box speaks */
    if (ra < 0) return 0;                  /* zero scale: no pixel can hit */
    int rb = mask_probe_pos(vm, b, field_or(ib, "x", 0.0), field_or(ib, "y", 0.0), &pb);
    if (rb == 0) return 1;                 /* no mask data on B: the box speaks */
    if (rb < 0) return 0;
    GmBox ba, bb;
    if (!box_for_at(vm, a, ax, ay, &ba) || !box_for_instance(vm, b, &bb)) return 1;
    double left = ba.l > bb.l ? ba.l : bb.l;
    double right = ba.r < bb.r ? ba.r : bb.r;
    double top = ba.t > bb.t ? ba.t : bb.t;
    double bottom = ba.b < bb.b ? ba.b : bb.b;
    if (left > right || top > bottom) return 0;
    for (long y = (long)top; y <= (long)bottom; y++)
        for (long x = (long)left; x <= (long)right; x++)
            if (mask_probe_pixel(&pa, (double)x, (double)y) &&
                mask_probe_pixel(&pb, (double)x, (double)y))
                return 1;
    return 0;
}

int32_t gm_instance_place(GmVM* vm, int32_t self, Val x, Val y, int32_t obj) {
    GmInst* caller = vm_inst(vm, self);
    if (!caller) return GM_NOONE;
    /* The CALLER is boxed at the candidate position with its own mask/sprite,
     * exactly like the runner's Compute_BoundingBox (host_impl.rs:288-301). */
    GmBox pbox = box_at(sat_i32(field_or(caller, "mask_index", -1.0)),
                        sat_i32(field_or(caller, "sprite_index", -1.0)),
                        (double)x, (double)y,
                        field_or(caller, "image_xscale", 1.0),
                        field_or(caller, "image_yscale", 1.0),
                        field_or(caller, "image_angle", 0.0));
    int32_t ids[MAX_INST];
    int n = select_ids(vm, self, obj, ids, MAX_INST);
#ifdef GM_TRACE
    fprintf(stderr, "IP self=%d at %.17g,%.17g obj=%d pbox=%.1f..%.1f x %.1f..%.1f cands=%d\n",
            self, (double)x, (double)y, obj, pbox.l, pbox.r, pbox.t, pbox.b, n);
#endif
    for (int i = 0; i < n; i++) {
        int32_t tid = ids[i];
        if (tid == self) continue;
        GmBox tb;
        if (!box_for_instance(vm, tid, &tb)) continue;
        /* host_impl.rs:306: the runner's inclusive edge test. */
        #ifdef GM_TRACE
        fprintf(stderr, "   cand %d obj=%d box=%.1f..%.1f x %.1f..%.1f hit=%d\n",
                tid, vm_inst(vm,tid)?vm_inst(vm,tid)->object:-1, tb.l, tb.r, tb.t, tb.b,
                (pbox.l <= tb.r && pbox.r >= tb.l && pbox.t <= tb.b && pbox.b >= tb.t));
        #endif
        if (pbox.l <= tb.r && pbox.r >= tb.l && pbox.t <= tb.b && pbox.b >= tb.t) {
            /* The runner continues into Collision_Instance -> PreciseCollision:
             * the recorded box is only the broad phase. */
            if (!precise_overlap(vm, self, (double)x, (double)y, tid)) continue;
            return tid;
        }
    }
    return GM_NOONE;
}

int gm_place_meeting(GmVM* vm, int32_t self, Val x, Val y, int32_t obj) {
    /* host_impl.rs:499-505: place_meeting is instance_place > 0, and an error
     * (missing caller) reads as false. */
    return gm_instance_place(vm, self, x, y, obj) > 0 ? 1 : 0;
}

/* host_impl.rs:468-498. FindDist measures inclusive bbox gaps (never origin
 * gaps), rejects self and dead/inactive targets, and starts at 1e6.
 *
 * Rust reads the selector through `int(a[0])?`, which rejects non-integral or
 * non-finite values by erroring the whole call. The C entry point takes a Val
 * (the GM_CALL wrapper owns the raw argument), so it truncates instead; that
 * check belongs one layer up, next to `GM_READ`. */
Val gm_distance_to_object(GmVM* vm, int32_t self, Val obj) {
    double min_dist = 1000000.0;
    int32_t sel = sat_i32((double)obj);
    GmBox sb;

    if (!box_for_instance(vm, self, &sb)) return min_dist;

    int32_t ids[MAX_INST];
    int n = 0;
    if (sel == -3) {
        /* `all`: every instance, then filtered below */
        for (int i = 0; i < vm->ninst && n < MAX_INST; i++) ids[n++] = vm->inst[i].id;
        sort_ids(ids, n);
    } else if (sel < -3) {
        n = 0;                             /* noone / absent special object */
    } else {
        n = select_ids(vm, self, sel, ids, MAX_INST);
    }

    for (int i = 0; i < n; i++) {
        int32_t tid = ids[i];
        if (tid == self) continue;
        GmInst* tin = vm_inst(vm, tid);
        if (!tin || !tin->alive || !tin->active) continue;
        GmBox tb;
        if (!box_for_instance(vm, tid, &tb)) continue;
        /* (left-tr).max(tl-right).max(0.0) as i32 -- f64 max ignores NaN,
         * `as i32` truncates, and values are >= 0 by construction. */
        double dxd = fmax(fmax(sb.l - tb.r, tb.l - sb.r), 0.0);
        double dyd = fmax(fmax(sb.t - tb.b, tb.t - sb.b), 0.0);
        int32_t dx = (int32_t)dxd, dy = (int32_t)dyd;
        /* Original ARM integer mul/mla, then sqrtf, promoted to the RValue. */
        int32_t squared = (int32_t)((uint32_t)dx * (uint32_t)dx +
                                    (uint32_t)dy * (uint32_t)dy);
        float d = sqrtf((float)squared);
        if ((double)d < min_dist) min_dist = (double)d;
    }
    return min_dist;
}
