/* Collision oracle for c-recon/src/collision.c.
 *
 * Every expected value is hand-computed from the Rust formula named in the
 * comment next to it; the arithmetic is spelled out. Three kinds of evidence:
 *
 *   1. pinned fixtures lifted from crates/core/tests/distance_bbox_ir.rs,
 *      whose numbers were probed on the original libyoyo ARM
 *      Compute_BoundingBox (@0x192340) -- independent of this port;
 *   2. edge probes: distance_to_object from a sprite-less point to the box
 *      under test returns the 1-pixel gap, so each of the four edges is
 *      pinned on its own (a wrong edge moves a probe by exactly 1);
 *   3. A/B flips (angle 0 vs 90, scale 1 vs -1 vs 0.28125) where the same
 *      instance pair must change its answer.
 *
 * Build/run:
 *   clang -std=c11 -O2 -Wall -Ic-recon/include \
 *       c-recon/src/host.c c-recon/src/collision.c \
 *       c-recon/tests/collision_test.c c-recon/gen/sprites.c \
 *       -o c-recon/build/collision_test && ./c-recon/build/collision_test
 */
#include "gml.h"

#include <stdio.h>

/* collision.c exports beyond gml.h; the shared header is owned elsewhere, so
 * these are declared here rather than appended there. */
void gm_collision_clear_parents(void);
void gm_collision_add_parent(int32_t child, int32_t parent);
Val  gm_distance_to_object(GmVM* vm, int32_t self, Val obj);

static GmVM g_vm;
static int g_checks;
static int g_fails;
static int32_t g_probe = -1;

#define CHECK_I(what, got, want) do {                                        \
        long long got_ = (long long)(got), want_ = (long long)(want);        \
        g_checks++;                                                          \
        if (got_ != want_) {                                                 \
            g_fails++;                                                       \
            printf("FAIL  %-62s got %lld want %lld\n", (what), got_, want_); \
        }                                                                    \
    } while (0)

#define CHECK_D(what, got, want) do {                                        \
        double got_ = (got), want_ = (want);                                 \
        g_checks++;                                                          \
        if (!(got_ == want_)) {                                              \
            g_fails++;                                                       \
            printf("FAIL  %-62s got %.17g want %.17g\n", (what), got_, want_);\
        }                                                                    \
    } while (0)

static void new_vm(void) {
    vm_init(&g_vm, 0);
    gm_collision_clear_parents();
    g_probe = -1;
}

/* One instance with the engine's named defaults; sprite -1 = no sprite. */
static int32_t mk(int32_t id, int32_t object, double x, double y, int32_t sprite) {
    if (!vm_add(&g_vm, id, object)) {
        printf("FATAL: vm_add(%d) failed\n", id);
        g_fails++;
        return id;
    }
    vm_set_field(&g_vm, id, "x", x);
    vm_set_field(&g_vm, id, "y", y);
    vm_set_field(&g_vm, id, "sprite_index", (Val)sprite);
    vm_set_field(&g_vm, id, "mask_index", -1.0);
    vm_set_field(&g_vm, id, "image_xscale", 1.0);
    vm_set_field(&g_vm, id, "image_yscale", 1.0);
    vm_set_field(&g_vm, id, "image_angle", 0.0);
    return id;
}

/* distance_to_object from a sprite-less point (an integer point box) to the
 * box of `object`: the return value is the per-axis gap, i.e. edge distance. */
static double gap_at(double x, double y, int32_t object) {
    if (g_probe < 0) g_probe = mk(9000, 99, x, y, -1);
    vm_set_field(&g_vm, g_probe, "x", x);
    vm_set_field(&g_vm, g_probe, "y", y);
    return gm_distance_to_object(&g_vm, g_probe, (Val)object);
}

/* --- 1. ARM-pinned player / Lloyd geometry --------------------------------
 * distance_bbox_ir.rs:172-189 pins these numbers against the original
 * Compute_BoundingBox, so they test the port rather than restate it. */
static void group_pinned_player_lloyd(void) {
    new_vm();
    int32_t p = mk(1, 0, 645.0, 494.0, 29);
    int32_t l = mk(2, 154, 768.0, 480.0, 1);
    /* spr_player 29 {32x34, origin 15,16, bbox 9..22 x 4..33} at (645,494):
     *   l = 645+(9-15) = 639;  r+1 = 639+(22-9+1) = 653 -> right 652
     *   t = 494+(4-16) = 482;  b+1 = 482+(33-4+1) = 512 -> bottom 511
     *   = "[x-6,x+7]x[y-12,y+17]" (distance_bbox_ir.rs:177)
     * spr_lloyd 1 {32x64, origin 16,32, bbox 1..29 x 21..63} at (768,480):
     *   l = 768+(1-16) = 753;  r+1 = 753+(29-1+1) = 782 -> right 781
     *   t = 480+(21-32) = 469; b+1 = 469+(63-21+1) = 512 -> bottom 511
     *   = Lloyd [753,781]x[469,511] (distance_bbox_ir.rs:176)
     * dx = 753-652 = 101;  dy = 0 (469..511 overlaps 482..511) -> 101. */
    CHECK_D("pinned: Lloyd->player gap at x=645 is 101", gm_distance_to_object(&g_vm, l, 0), 101.0);
    vm_set_field(&g_vm, p, "x", 646.0);
    /* player box becomes [640,653] -> dx = 753-653 = 100 */
    CHECK_D("pinned: Lloyd->player gap at x=646 is 100", gm_distance_to_object(&g_vm, l, 0), 100.0);
    /* instance_place boxes the CALLER at the candidate position:
     *   x=745 -> [739,752]: 752 >= 753 false -> -4
     *   x=746 -> [740,753]: 753 >= 753 true  -> Lloyd id 2 (inclusive edge) */
    CHECK_I("pinned: 1px short of Lloyd's left edge", gm_instance_place(&g_vm, p, 745.0, 494.0, 154), -4);
    CHECK_I("pinned: touching Lloyd's left edge", gm_instance_place(&g_vm, p, 746.0, 494.0, 154), 2);
    CHECK_I("pinned: place_meeting follows instance_place", gm_place_meeting(&g_vm, p, 746.0, 494.0, 154), 1);
    CHECK_I("pinned: place_meeting false at 745", gm_place_meeting(&g_vm, p, 745.0, 494.0, 154), 0);
}

/* --- 2. mask_index wins, signed scales normalize -------------------------- */
static void group_mask_and_signed_scale(void) {
    new_vm();
    int32_t a = mk(1, 1, 20.0, 30.0, 6);          /* visible wall 32x32 @0,0 */
    vm_set_field(&g_vm, a, "mask_index", 40.0);   /* spr_bullet 16x16, origin 9,9, bbox 0..15 x 1..14 */
    vm_set_field(&g_vm, a, "image_xscale", -2.0);
    vm_set_field(&g_vm, a, "image_yscale", 3.0);
    /* ir_scene.rs:851-855 on the mask box (same shape as the ARM probe in
     * distance_bbox_ir.rs:51-52, with spr_bullet's edges):
     *   l  = 20+(0-9)*(-2)            = 38
     *   r+1= 38+(15-0+1)*(-2)         = 6    -> min 6, max-1 37
     *   t  = 30+(1-9)*3               = 6
     *   b+1= 6+(14-1+1)*3             = 48   -> min 6, max-1 47 */
    CHECK_D("mask/signed: left edge 6 (gap from x=0)", gap_at(0.0, 47.0, 1), 6.0);
    CHECK_D("mask/signed: right edge 37, not 38", gap_at(38.0, 47.0, 1), 1.0);
    CHECK_D("mask/signed: (37,47) sits on the right edge", gap_at(37.0, 47.0, 1), 0.0);
    CHECK_D("mask/signed: top edge 6, not 5", gap_at(6.0, 5.0, 1), 1.0);
    CHECK_D("mask/signed: bottom edge 47, not 48", gap_at(6.0, 48.0, 1), 1.0);

    /* mask_index must win over the visible sprite, not merge with it. */
    new_vm();
    int32_t m = mk(1, 1, 100.0, 100.0, 6);
    vm_set_field(&g_vm, m, "mask_index", 40.0);
    mk(2, 2, 104.0, 116.0, 6);
    mk(3, 3, 104.0, 100.0, 6);
    /* mask box at (100,100): l = 100+(0-9) = 91;  r+1 = 91+16 = 107 -> 106
     *                        t = 100+(1-9) = 92;  b+1 = 92+14 = 106 -> 105
     * visible wall box would be [100,131]x[100,131].
     * target 2 box [104,135]x[116,147]: 105 >= 116 false -> miss (the wall
     * box would hit at 131 >= 116). target 3 box [104,135]x[100,131] hits. */
    CHECK_I("mask wins: target 2 is past the mask, inside the sprite", gm_instance_place(&g_vm, m, 100.0, 100.0, 2), -4);
    CHECK_I("mask wins: target 3 overlaps the mask box", gm_instance_place(&g_vm, m, 100.0, 100.0, 3), 3);
}

/* --- 3. rotation ---------------------------------------------------------- */
static void group_rotation(void) {
    new_vm();
    int32_t a = mk(1, 1, 100.0, 100.0, 40);
    /* angle 0: l = 100+(0-9) = 91;  r+1 = 91+16 = 107 -> 106
     *          t = 100+(1-9) = 92;  b+1 = 92+14 = 106 -> 105  */
    CHECK_D("rot0: right edge 106", gap_at(107.0, 100.0, 1), 1.0);
    /* angle 90, ir_scene.rs:856-870 with corners cx in {-9,7}, cy in {-8,6}:
     *   px = 100 + cx*cos + cy*sin ~= 100+cy  -> 92 .. 106
     *   py = 100 + cy*cos - cx*sin ~= 100-cx  -> 93 .. 109
     *   -> l 92, r+1 106 -> 105, t 93, b+1 109 -> 108 */
    vm_set_field(&g_vm, a, "image_angle", 90.0);
    CHECK_D("rot90: left edge 92, not 91", gap_at(91.0, 100.0, 1), 1.0);
    CHECK_D("rot90: right edge 105, not 106", gap_at(106.0, 100.0, 1), 1.0);
    CHECK_D("rot90: top edge 93, not 92", gap_at(100.0, 92.0, 1), 1.0);
    CHECK_D("rot90: bottom edge 108, not 109", gap_at(100.0, 109.0, 1), 1.0);
    CHECK_D("rot90: centre probe is inside", gap_at(100.0, 100.0, 1), 0.0);
    /* Same pair, opposite answers: target 2 box [106,137]x[95,126] reaches
     * x=106, which is one past the rotated right edge but exactly the
     * unrotated right edge. Target 3 box [100,131]x[106,137] reaches y=106,
     * inside the rotated bottom (108) but past the unrotated bottom (105). */
    mk(2, 2, 106.0, 95.0, 6);
    mk(3, 3, 100.0, 106.0, 6);
    CHECK_I("rot90: box rotated away from target 2", gm_instance_place(&g_vm, a, 100.0, 100.0, 2), -4);
    CHECK_I("rot90: box rotated onto target 3", gm_instance_place(&g_vm, a, 100.0, 100.0, 3), 3);
    vm_set_field(&g_vm, a, "image_angle", 0.0);
    CHECK_I("rot0: target 2 hit at the unrotated right edge", gm_instance_place(&g_vm, a, 100.0, 100.0, 2), 2);
    CHECK_I("rot0: target 3 missed above the unrotated box", gm_instance_place(&g_vm, a, 100.0, 100.0, 3), -4);

    /* A 128x1 line turning into a 1x128 column makes the projection obvious. */
    new_vm();
    int32_t s = mk(1, 1, 100.0, 100.0, 0);
    /* angle 0: l = 100, r+1 = 100+(127-0+1) = 228 -> 227
     *          t = 103, b+1 = 103+(3-3+1) = 104 -> 103 */
    CHECK_D("line0: right edge 227", gap_at(228.0, 103.0, 1), 1.0);
    CHECK_D("line0: left edge 100", gap_at(99.0, 103.0, 1), 1.0);
    CHECK_D("line0: top edge 103", gap_at(100.0, 102.0, 1), 1.0);
    CHECK_D("line0: bottom edge 103", gap_at(100.0, 104.0, 1), 1.0);
    /* angle 90: corners cx in {0,128}, cy in {3,4}
     *   px ~= 100+cy -> 103..104  -> l 103, r 103
     *   py ~= 100-cx -> -28..100  -> t -28, b 99 */
    vm_set_field(&g_vm, s, "image_angle", 90.0);
    CHECK_D("line90: column is 1px wide at x=103", gap_at(102.0, 50.0, 1), 1.0);
    CHECK_D("line90: column right edge 103", gap_at(104.0, 50.0, 1), 1.0);
    CHECK_D("line90: column still on the edge at x=103", gap_at(103.0, 50.0, 1), 0.0);
    CHECK_D("line90: top edge -28", gap_at(103.0, -29.0, 1), 1.0);
    CHECK_D("line90: bottom edge 99", gap_at(103.0, 100.0, 1), 1.0);
    /* target 2 box [100,131]x[20,51] sits 79px above the line's y=103 row,
     * but inside the rotated column's -28..99 span. */
    mk(2, 2, 100.0, 20.0, 6);
    CHECK_I("line90: target above the row is hit by the column", gm_instance_place(&g_vm, s, 100.0, 100.0, 2), 2);
    vm_set_field(&g_vm, s, "image_angle", 0.0);
    CHECK_I("line0: same target misses the horizontal row", gm_instance_place(&g_vm, s, 100.0, 100.0, 2), -4);
}

/* --- 4. rounding order and scale ------------------------------------------ */
static void group_rounding_and_scale(void) {
    new_vm();
    int32_t a = mk(1, 1, 100.5, 100.0, 6);
    vm_set_field(&g_vm, a, "image_xscale", 0.28125);  /* 9/32 -> width 9 */
    /* ir_scene.rs:851-852 rounds the LOW edge first, then adds the scaled
     * width: l = rint(100.5) = 100 (ties to even), r+1 = rint(100+9) = 109
     * -> right 108. Rounding x+width in one go would give rint(109.5) = 110
     * -> right 109, which the x=109 probe rejects. */
    CHECK_D("lrint order: right edge 108 at x=100.5, width 9", gap_at(109.0, 100.0, 1), 1.0);
    CHECK_D("lrint order: (108,100) is on the right edge", gap_at(108.0, 100.0, 1), 0.0);
    CHECK_D("lrint order: left edge 100 (100.5 ties to even)", gap_at(99.0, 100.0, 1), 1.0);
    /* sx=2: l = 100, r+1 = 100+32*2 = 164 -> 163 */
    vm_set_field(&g_vm, a, "image_xscale", 2.0);
    CHECK_D("scale2: right edge 163", gap_at(164.0, 100.0, 1), 1.0);
    CHECK_D("scale2: (163,100) is on the right edge", gap_at(163.0, 100.0, 1), 0.0);
    /* sx=-1: l = 100, r+1 = 100-32 = 68 -> min 68, max 99 (mirrored) */
    vm_set_field(&g_vm, a, "image_xscale", -1.0);
    CHECK_D("mirror: left edge 68", gap_at(67.0, 100.0, 1), 1.0);
    CHECK_D("mirror: (68,100) is on the left edge", gap_at(68.0, 100.0, 1), 0.0);
    CHECK_D("mirror: right edge 99", gap_at(100.0, 100.0, 1), 1.0);
}

/* --- 5. no sprite / unknown sprite is an integer point --------------------
 * No shipped sprite has has_bbox == 0: all 178 rows in c-recon/gen/sprites.c
 * carry the recorded SPRT box, so the whole-sprite fallback (ir_scene.rs:840-842)
 * cannot be reached from this data. It is a two-line mirror of that branch.
 * The other fallback in the same function -- no sprite entry at all
 * (ir_scene.rs:805-808) -- is exercised here, and it is the one the game does
 * use: bullets, particles and every fx instance live on it. */
static void group_point_fallback(void) {
    new_vm();
    int32_t a = mk(1, 1, -10.9, -20.9, -1);
    /* ir_scene.rs:805-808: x.trunc() = -10, y.trunc() = -20 (trunc, not floor) */
    mk(2, 2, -10.0, -20.0, -1);
    mk(3, 3, -11.0, -20.0, -1);
    mk(4, 4, -10.0, -21.0, -1);
    CHECK_I("point: sprite-less caller hits the same integer point", gm_instance_place(&g_vm, a, -10.9, -20.9, 2), 2);
    CHECK_I("point: one pixel left of the truncated point", gm_instance_place(&g_vm, a, -10.9, -20.9, 3), -4);
    CHECK_I("point: one pixel above the truncated point", gm_instance_place(&g_vm, a, -10.9, -20.9, 4), -4);
    /* target side: caller box [200,231]^2 against a point target */
    new_vm();
    int32_t w = mk(1, 1, 200.0, 200.0, 6);
    mk(2, 2, 200.0, 200.0, -1);
    mk(3, 3, 199.0, 200.0, -1);
    CHECK_I("point: target point on the box corner", gm_instance_place(&g_vm, w, 200.0, 200.0, 2), 2);
    CHECK_I("point: target point outside the box", gm_instance_place(&g_vm, w, 200.0, 200.0, 3), -4);
    /* unknown sprite id takes the same path as no sprite at all */
    new_vm();
    int32_t u = mk(1, 1, 200.5, 200.9, 999);
    mk(2, 2, 200.0, 200.0, -1);
    mk(3, 3, 201.0, 200.0, -1);
    CHECK_I("point: unknown sprite id truncates to (200,200)", gm_instance_place(&g_vm, u, 200.5, 200.9, 2), 2);
    CHECK_I("point: unknown sprite does not become a 32x32 box", gm_instance_place(&g_vm, u, 200.5, 200.9, 3), -4);
    /* An instance that never got x/y has no box at all (ir_scene.rs:784-785). */
    new_vm();
    int32_t c = mk(1, 1, 700.0, 700.0, 6);
    vm_add(&g_vm, 2, 2);                   /* object 2, no fields at all */
    CHECK_I("half-built: target without x/y cannot be hit", gm_instance_place(&g_vm, c, 700.0, 700.0, 2), -4);
    CHECK_D("half-built: target without x/y is never measured", gm_distance_to_object(&g_vm, c, 2), 1000000.0);
}

/* --- 6. selector order: lowest instance id wins --------------------------- */
static void group_hit_order(void) {
    new_vm();
    int32_t c = mk(1, 1, 300.0, 300.0, 6);
    mk(30, 60, 300.0, 300.0, 6);
    mk(20, 61, 300.0, 300.0, 6);
    gm_collision_add_parent(60, 70);
    gm_collision_add_parent(61, 70);
    CHECK_I("order: lowest id wins (Rust BTreeMap order)", gm_instance_place(&g_vm, c, 300.0, 300.0, 70), 20);
    vm_inst(&g_vm, 20)->active = 0;
    CHECK_I("order: next id once the lowest is inactive", gm_instance_place(&g_vm, c, 300.0, 300.0, 70), 30);
    vm_inst(&g_vm, 30)->alive = 0;
    CHECK_I("order: nothing left alive", gm_instance_place(&g_vm, c, 300.0, 300.0, 70), -4);
}

/* --- 7. parent chain ------------------------------------------------------ */
static void group_parents(void) {
    new_vm();
    int32_t c = mk(1, 1, 400.0, 400.0, 6);
    mk(5, 52, 400.0, 400.0, 6);
    CHECK_I("parents: without edges object 52 is not object 50", gm_instance_place(&g_vm, c, 400.0, 400.0, 50), -4);
    CHECK_I("parents: exact object matches", gm_instance_place(&g_vm, c, 400.0, 400.0, 52), 5);
    gm_collision_add_parent(52, 51);
    gm_collision_add_parent(51, 50);
    gm_collision_add_parent(54, 51);   /* sibling edge must not leak */
    CHECK_I("parents: direct parent selector", gm_instance_place(&g_vm, c, 400.0, 400.0, 51), 5);
    CHECK_I("parents: grandparent selector (transitive)", gm_instance_place(&g_vm, c, 400.0, 400.0, 50), 5);
    CHECK_I("parents: unrelated object", gm_instance_place(&g_vm, c, 400.0, 400.0, 53), -4);
    CHECK_I("parents: fallback for an object with no instance", gm_instance_place(&g_vm, c, 400.0, 400.0, 54), -4);
    CHECK_I("parents: chain still answers after the sibling edge", gm_instance_place(&g_vm, c, 400.0, 400.0, 52), 5);
    gm_collision_clear_parents();
    CHECK_I("parents: clear removes the ancestor match", gm_instance_place(&g_vm, c, 400.0, 400.0, 50), -4);
}

/* --- 8. selector forms ---------------------------------------------------- */
static void group_selectors(void) {
    new_vm();
    int32_t c = mk(1, 1, 500.0, 500.0, 6);
    int32_t t = mk(2, 2, 510.0, 500.0, 6);
    CHECK_I("selector -1: self only, and self is skipped", gm_instance_place(&g_vm, c, 500.0, 500.0, -1), -4);
    g_vm.other = t;
    CHECK_I("selector -2: follows `other`", gm_instance_place(&g_vm, c, 500.0, 500.0, -2), 2);
    g_vm.other = -1;
    CHECK_I("selector -2: unset other falls back to self", gm_instance_place(&g_vm, c, 500.0, 500.0, -2), -4);
    CHECK_I("selector -3: `all` matches nothing (Rust call errors)", gm_instance_place(&g_vm, c, 500.0, 500.0, -3), -4);
    vm_inst(&g_vm, t)->active = 0;
    CHECK_I("flags: inactive target is invisible", gm_instance_place(&g_vm, c, 500.0, 500.0, 2), -4);
    vm_inst(&g_vm, t)->active = 1;
    vm_inst(&g_vm, t)->alive = 0;
    CHECK_I("flags: dead target is invisible", gm_instance_place(&g_vm, c, 500.0, 500.0, 2), -4);

    /* instance id selectors (>= 100000, host_impl.rs:20-21) */
    new_vm();
    int32_t c2 = mk(100001, 1, 500.0, 500.0, 6);
    mk(100002, 2, 510.0, 500.0, 6);
    CHECK_I("selector id: exact instance id", gm_instance_place(&g_vm, c2, 500.0, 500.0, 100002), 100002);
    CHECK_I("selector id: absent instance id", gm_instance_place(&g_vm, c2, 500.0, 500.0, 100003), -4);
    CHECK_I("selector id: the caller's own id is skipped", gm_instance_place(&g_vm, c2, 500.0, 500.0, 100001), -4);
}

/* --- 9. place_meeting is instance_place > 0 ------------------------------- */
static void group_place_meeting(void) {
    new_vm();
    int32_t c = mk(1, 1, 600.0, 600.0, 6);
    mk(2, 2, 610.0, 600.0, 6);
    CHECK_I("place_meeting: overlapping boxes", gm_place_meeting(&g_vm, c, 600.0, 600.0, 2), 1);
    CHECK_I("place_meeting: separated boxes", gm_place_meeting(&g_vm, c, 700.0, 600.0, 2), 0);
    CHECK_I("place_meeting: caller's own object is skipped", gm_place_meeting(&g_vm, c, 600.0, 600.0, 1), 0);
    CHECK_I("place_meeting: missing caller is false", gm_place_meeting(&g_vm, 424242, 600.0, 600.0, 2), 0);
    CHECK_I("instance_place: missing caller is noone", gm_instance_place(&g_vm, 424242, 600.0, 600.0, 2), -4);
}

/* --- 10. distance_to_object selector matrix (distance_bbox_ir.rs:78-104) -- */
static void group_distance_selectors(void) {
    new_vm();
    int32_t a = mk(100001, 10, 0.0, 0.0, -1);      /* integer point (0,0)  */
    int32_t child = mk(100002, 11, 3.0, 4.0, -1);  /* point (3,4)  -> 5   */
    int32_t far = mk(100003, 11, 30.0, 40.0, -1);  /* point (30,40)-> 50  */
    gm_collision_add_parent(11, 12);
    CHECK_D("distance: parent selector includes the child", gm_distance_to_object(&g_vm, a, 12), 5.0);
    CHECK_D("distance: -3 (all) picks the nearest", gm_distance_to_object(&g_vm, a, -3), 5.0);
    CHECK_D("distance: -4 (noone) is the 1e6 sentinel", gm_distance_to_object(&g_vm, a, -4), 1000000.0);
    CHECK_D("distance: absent object is the sentinel", gm_distance_to_object(&g_vm, a, 999), 1000000.0);
    CHECK_D("distance: -1 is self only, never zero", gm_distance_to_object(&g_vm, a, -1), 1000000.0);
    CHECK_D("distance: explicit self instance is excluded", gm_distance_to_object(&g_vm, a, 100001), 1000000.0);
    CHECK_D("distance: own object holds only the caller", gm_distance_to_object(&g_vm, a, 10), 1000000.0);
    g_vm.other = child;
    CHECK_D("distance: -2 follows `other`", gm_distance_to_object(&g_vm, a, -2), 5.0);
    vm_inst(&g_vm, child)->active = 0;
    CHECK_D("distance: explicit inactive target is excluded", gm_distance_to_object(&g_vm, a, 100002), 1000000.0);
    CHECK_D("distance: -2 does not bypass the flag filter", gm_distance_to_object(&g_vm, a, -2), 1000000.0);
    CHECK_D("distance: inactive child cannot win the minimum", gm_distance_to_object(&g_vm, a, 12), 50.0);
    vm_inst(&g_vm, child)->active = 1;
    vm_inst(&g_vm, far)->alive = 0;
    vm_inst(&g_vm, a)->active = 0;
    CHECK_D("distance: inactive caller still measures targets", gm_distance_to_object(&g_vm, a, 12), 5.0);
    vm_inst(&g_vm, child)->alive = 0;
    CHECK_D("distance: every candidate destroyed", gm_distance_to_object(&g_vm, a, 12), 1000000.0);
}

/* --- 11. collision_line(prec=1): per-pixel mask walk ----------------------
 * The sprite table is emitted from the same SPRT records the runner reads, so
 * this pins the C mask walk itself: a segment through a transparent pixel must
 * miss, through a set pixel must hit, and a sprite with no mask data must
 * report "no data" (-1) instead of inventing a pixel answer. */
static void group_line_mask(void) {
    new_vm();
    int32_t spr = -1, zx = -1, zy = -1, nxp = -1;
    for (int i = 0; i < GM_SPRITE_MASK_COUNT && spr < 0; i++) {
        const GmMaskSprite* m = &GM_SPRITE_MASKS[i];
        if (m->nframes <= 0) continue;
        const GmMaskFrame* f = &m->frames[0];
        int row = (f->width + 7) / 8;
        for (int y = 0; y < f->height && zx < 0; y++) {
            for (int x = 0; x + 1 < f->width; x++) {
                int off = (f->bits[y * row + x / 8] & (0x80 >> (x % 8))) != 0;
                int on = (f->bits[y * row + (x + 1) / 8] & (0x80 >> ((x + 1) % 8))) != 0;
                if (!off && on) { zx = x; zy = y; nxp = x + 1; break; }
            }
        }
        if (zx >= 0) spr = m->sprite;
    }
    CHECK_I("mask: a sprite with a transparent pixel exists", spr > 0, 1);
    if (spr < 0) return;
    const GmSprite* sp = NULL;
    for (int i = 0; i < GM_SPRITE_COUNT; i++)
        if (GM_SPRITES[i].id == spr) sp = &GM_SPRITES[i];
    double ox = sp ? sp->origin_x : 0.0;
    double oy = sp ? sp->origin_y : 0.0;
    int32_t id = mk(100010, 34, 0.0, 0.0, spr);
    /* mask_hit: lx = floor(px/1) + ox, so a world x of zx-ox+0.5 lands on zx. */
    double px = (double)zx - ox + 0.5, py = (double)zy - oy + 0.5;
    double qx = (double)nxp - ox + 0.5;
    CHECK_I("line mask: segment through a transparent pixel misses",
            gm_line_mask_test(&g_vm, id, px - 0.3, py, px + 0.3, py), 0);
    CHECK_I("line mask: segment through a set pixel hits",
            gm_line_mask_test(&g_vm, id, qx - 0.3, py, qx + 0.3, py), 1);
    CHECK_I("point mask: point on a transparent pixel misses",
            gm_mask_point_test(&g_vm, id, px, py), 0);
    CHECK_I("point mask: point on a set pixel hits",
            gm_mask_point_test(&g_vm, id, qx, py), 1);
    vm_set_field(&g_vm, id, "sprite_index", -1.0);
    CHECK_I("line mask: sprite -1 reports no mask data",
            gm_line_mask_test(&g_vm, id, 0.0, 0.0, 1.0, 1.0), -1);
}

/* --- 12. instance_place is precise, not box-only --------------------------
 * The runner's Command_InstancePlace goes through Collision_Instance ->
 * CSprite::PreciseCollision, so two recorded boxes can overlap while the
 * sprites are not touching. Scan sprite 1 (32x64 with a hole) for such an
 * offset: the boxes overlap, the pixel test does not. */
static void group_precise_place(void) {
    new_vm();
    /* Sprite 1 (caller) vs sprite 4 at (16, 8): the recorded boxes overlap but
     * the two solid-pixel sets are disjoint (mask search over the emitted
     * tables). That is exactly the case the box-only version called a hit. */
    int32_t a = mk(100020, 34, 0.0, 0.0, 1);
    int32_t b = mk(100021, 34, 16.0, 8.0, 4);
    CHECK_I("precise place: overlapping boxes with disjoint pixels miss",
            gm_instance_place(&g_vm, a, (Val)0.0, (Val)0.0, 34), -4);
    /* Control: the same pair at the same position does share solid pixels. */
    vm_set_field(&g_vm, b, "x", 0.0);
    vm_set_field(&g_vm, b, "y", 0.0);
    CHECK_I("precise place: a shared solid pixel still hits",
            gm_instance_place(&g_vm, a, (Val)0.0, (Val)0.0, 34), b);
    /* Rotation is not in this path yet: a rotated pair keeps the box verdict. */
    vm_set_field(&g_vm, b, "x", 16.0);
    vm_set_field(&g_vm, b, "y", 8.0);
    vm_set_field(&g_vm, a, "image_angle", 90.0);
    CHECK_I("precise place: rotated caller falls back to the box verdict",
            gm_instance_place(&g_vm, a, (Val)0.0, (Val)0.0, 34), b);
}

int main(void) {
    group_pinned_player_lloyd();
    group_mask_and_signed_scale();
    group_rotation();
    group_rounding_and_scale();
    group_point_fallback();
    group_hit_order();
    group_parents();
    group_selectors();
    group_place_meeting();
    group_distance_selectors();
    group_line_mask();
    group_precise_place();
    printf("collision_test: %d checks, %d failed\n", g_checks, g_fails);
    return g_fails ? 1 : 0;
}
