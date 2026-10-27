/* tier: host_authored
 * provenance: 重建实现，命令流与调度镜像 Scene::draw_view；不是原件绘制管线。
 * original_gap: 原版跨类别绘制顺序未取证（draw-stream-fingerprint.md 自述该指纹是
 *               remake 回归基线，不是原件等价 oracle）。
 *
 * Draw command storage and the original two-pass instance Draw scheduler.
 *
 * This is a command-stream host, not a rasterizer. Payloads and provenance are
 * the same four GML queues that Scene exposes: sprite, text, healthbar and
 * background. Room tiles and particles are separate inputs and are outside this
 * slice. The scheduler mirrors Scene::draw_view, including newest-first ties,
 * default sprites, deactivated-instance filtering and the Draw GUI phase.
 */
#include "gml.h"

#include <math.h>
#include <stdio.h>

void gm_draw_clear(GmVM* vm) {
    vm->ndraws = 0;
    vm->draw_phase = 0;
    vm->has_draw_depth = 0;
    vm->draw_depth = 0.0;
}

GmDrawCommand* gm_draw_push(GmVM* vm, GmDrawKind kind) {
    if (vm->ndraws >= GM_MAX_DRAWS) {
        gm_fail_msg("draw command table full");
        return NULL;
    }
    GmDrawCommand* c = &vm->draws[vm->ndraws];
    c->kind = kind;
    c->code = vm->site_code;
    c->offset = vm->site_offset;
    c->instance = vm->cur;
    c->view = vm->view;
    c->phase = vm->draw_phase;
    c->emit_order = vm->ndraws;
    GmInst* in = vm_inst(vm, vm->cur);
    c->depth = vm->has_draw_depth ? vm->draw_depth
                                  : (in ? gm_field_or(in, "depth", gm_object_depth(in->object)) : 0.0);
    vm->ndraws++;
    return c;
}

typedef struct {
    int32_t id;
    uint64_t spawn_seq;
    double depth;
} GmDrawRow;

static double instance_depth(GmVM* vm, GmInst* in) {
    return gm_field_or(in, "depth", gm_object_depth(in->object));
}

/* Draw GUI in the Rust scene uses f64::total_cmp rather than the runner's
 * numeric normal-Draw comparison. Preserve its signed-zero distinction. */
static int gui_depth_compare(double a, double b) {
    if (a == 0.0 && b == 0.0) {
        int sa = signbit(a) ? 1 : 0, sb = signbit(b) ? 1 : 0;
        return (sa < sb) - (sa > sb); /* +0 sorts above -0 */
    }
    return (a > b) - (a < b);
}

static int default_sprite(GmVM* vm, int32_t id) {
    GmInst* in = vm_inst(vm, id);
    if (!in || !in->alive || !in->active || gm_field_or(in, "visible", 1.0) < 0.5) return 0;
    static const char* names[9] = {
        "sprite_index", "image_index", "x", "y", "image_xscale", "image_yscale",
        "image_angle", "image_blend", "image_alpha"
    };
    Val a[9];
    /* A directly inserted fixture with incomplete engine defaults takes the
     * same no-default-sprite branch as Scene::draw_view (Option<Vec<_>>). */
    for (int k = 0; k < 9; k++) {
        GmField* f = gm_find_field(in, names[k]);
        if (!f) return 0;
        a[k] = f->value;
    }
    int32_t old_code = vm->site_code;
    int64_t old_offset = vm->site_offset;
    int32_t old_cur = vm->cur;
    vm->cur = id;
    vm->site_code = -1; /* engine-generated, not the preceding CODE's site */
    vm->site_offset = 0;
    (void)GM_CALL(vm, "draw_sprite_ext", 9,
                  a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
    vm->cur = old_cur;
    vm->site_code = old_code;
    vm->site_offset = old_offset;
    return 0;
}

int gm_draw_view(GmVM* vm, int32_t view) {
    if (!vm || view < 0 || view >= 8 || !vm->view_port_set[view]) {
        char msg[80];
        snprintf(msg, sizeof msg, "view %d is not configured", view);
        gm_fail_msg(msg);
        return -1;
    }
    vm->view = view;
    gm_draw_clear(vm);
    vm->fog_enabled = 0;

    GmDrawRow rows[MAX_INST];
    int n = 0;
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (!in->alive || !in->active) continue;
        rows[n].id = in->id;
        rows[n].spawn_seq = in->spawn_seq;
        rows[n].depth = instance_depth(vm, in);
        n++;
    }
    /* Rust starts from BTreeMap's ascending absolute ids and uses a stable
     * depth/spawn-seq sort. The final id tie gives the same result even when
     * ROOM placement or a textual fixture arrives in a different order.
     * Signed zero compares equal, as in the runner's plain float comparison. */
    for (int i = 1; i < n; i++) {
        GmDrawRow row = rows[i];
        int j = i - 1;
        while (j >= 0 && (row.depth > rows[j].depth ||
               (row.depth == rows[j].depth &&
                (row.spawn_seq > rows[j].spawn_seq ||
                 (row.spawn_seq == rows[j].spawn_seq && row.id < rows[j].id))))) {
            rows[j + 1] = rows[j];
            j--;
        }
        rows[j + 1] = row;
    }
    for (int k = 0; k < n; k++) {
        GmInst* in = vm_inst(vm, rows[k].id);
        if (!in) continue;
        vm->draw_depth = rows[k].depth;
        vm->has_draw_depth = 1;
        int rc;
        if (gm_event_code_chain(in->object, 8, 0) >= 0) {
            rc = gm_dispatch_event(vm, rows[k].id, 8, 0);
        } else {
            rc = default_sprite(vm, rows[k].id);
        }
        vm->has_draw_depth = 0;
        if (rc < 0) return rc;
    }

    /* Draw GUI is a separate phase. The Rust scene intentionally uses own
     * object events here (not the inherited normal-Draw lookup) and id ties. */
    n = 0;
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (!in->alive || !in->active || gm_event_code(in->object, 8, 65) < 0) continue;
        rows[n].id = in->id;
        rows[n].spawn_seq = 0;
        rows[n].depth = instance_depth(vm, in);
        n++;
    }
    for (int i = 1; i < n; i++) {
        GmDrawRow row = rows[i];
        int j = i - 1;
        while (j >= 0 && (gui_depth_compare(row.depth, rows[j].depth) > 0 ||
               (gui_depth_compare(row.depth, rows[j].depth) == 0 && row.id < rows[j].id))) {
            rows[j + 1] = rows[j];
            j--;
        }
        rows[j + 1] = row;
    }
    vm->draw_phase = 1;
    for (int k = 0; k < n; k++) {
        GmInst* in = vm_inst(vm, rows[k].id);
        if (!in || gm_event_code(in->object, 8, 65) < 0) continue;
        vm->draw_depth = rows[k].depth;
        vm->has_draw_depth = 1;
        int rc = gm_dispatch_event(vm, rows[k].id, 8, 65);
        vm->has_draw_depth = 0;
        if (rc < 0) {
            vm->draw_phase = 0;
            return rc;
        }
    }
    vm->draw_phase = 0;
    return 0;
}
