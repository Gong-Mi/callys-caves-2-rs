/* Engine builtins that do not need instance geometry.
 *
 * Every branch here mirrors an arm of `call()` in
 * crates/core/src/parts/host_impl.rs; the comment above each group names the
 * Rust line range it was ported from. Anything not listed here stays a host
 * gap on purpose: `scripts/batch_diff.py` classifies a body that calls an
 * unimplemented builtin as `c_gap` instead of pretending the diff passed.
 *
 * Drawing is deliberately a no-op. The VM records DrawCommand/TextCommand into
 * the scene and the state dump does not print them, so a no-op is
 * observationally equal for the differential; it is NOT a renderer and this
 * file never claims to produce a frame.
 */
#include "gml.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

/* ---------------------------------------------------------------- helpers */

static GmInst* self_of(GmVM* vm) { return vm_inst(vm, vm->cur); }

static double field_or(GmInst* in, const char* name, double dflt) {
    if (!in) return dflt;
    for (int i = 0; i < in->nfields; i++)
        if (strcmp(in->fields[i].name, name) == 0) return in->fields[i].value;
    return dflt;
}

static void set_field(GmInst* in, const char* name, double v) {
    if (!in) return;
    for (int i = 0; i < in->nfields; i++)
        if (strcmp(in->fields[i].name, name) == 0) { in->fields[i].value = v; return; }
    if (in->nfields >= MAX_FIELDS) return;
    snprintf(in->fields[in->nfields].name, NAME_LEN, "%s", name);
    in->fields[in->nfields].value = v;
    in->nfields++;
}

/* host.c owns next_rand; the LCG must be the same one. */
int32_t gm_resolve_sel(GmVM* vm, Val sel) { return vm_resolve(vm, sel); }

/* ------------------------------------------------------------------ maps */

typedef struct { double key, val; } GmKv;

void gm_vm_init_ext(GmVM* vm) {
    vm->display_w = 1136.0;
    vm->display_h = 640.0;
    vm->current_room = 0.0;
    vm->view_visible[0] = 1;
    for (int i = 0; i < 8; i++) { vm->view_pos[i][0] = vm->view_pos[i][1] = 0.0;
        vm->view_port[i][0] = vm->display_w; vm->view_port[i][1] = vm->display_h; }
    vm->current_font = 0.0;
    vm->draw_color = -1;
    vm->draw_alpha = 1.0;
    vm->next_map_id = 1;
    vm->nmaps = 0;
    vm->nini = 0;
    vm->ini_open_file = 0.0;
    vm->next_part_type = 1.0;
    vm->next_part_system = 1.0;
    vm->npart_types = 0;
}

static int map_slot(GmVM* vm, int id, int create) {
    for (int i = 0; i < vm->nmaps; i++) if (vm->maps[i].id == id) return i;
    if (!create || vm->nmaps >= GM_MAX_MAPS) return -1;
    int i = vm->nmaps++;
    vm->maps[i].id = id;
    vm->maps[i].n = 0;
    return i;
}

static double map_get(GmVM* vm, int id, double key) {
    int i = map_slot(vm, id, 0);
    if (i < 0) return 0.0;
    for (int k = 0; k < vm->maps[i].n; k++)
        if (vm->maps[i].kv[k].key == key) return vm->maps[i].kv[k].val;
    return 0.0;
}

static void map_put(GmVM* vm, int id, double key, double val) {
    int i = map_slot(vm, id, 1);
    if (i < 0) return;
    for (int k = 0; k < vm->maps[i].n; k++)
        if (vm->maps[i].kv[k].key == key) { vm->maps[i].kv[k].val = val; return; }
    if (vm->maps[i].n >= GM_MAP_MAX) return;
    vm->maps[i].kv[vm->maps[i].n].key = key;
    vm->maps[i].kv[vm->maps[i].n].val = val;
    vm->maps[i].n++;
}

/* --------------------------------------------------------------- builtins */

int gm_call_ext(GmVM* vm, const char* name, int argc, const Val* a, Val* out) {
    *out = 0.0;

    /* host_impl.rs:314 window/display */
    if (!strcmp(name, "display_get_width") || !strcmp(name, "window_get_width")) { *out = vm->display_w; return 1; }
    if (!strcmp(name, "display_get_height") || !strcmp(name, "window_get_height")) { *out = vm->display_h; return 1; }

    /* host_impl.rs:534 point_direction */
    if (!strcmp(name, "point_direction")) {
        double dir = atan2(-(a[3] - a[1]), a[2] - a[0]) * 180.0 / M_PI;
        if (dir < 0.0) dir += 360.0;
        *out = dir;
        return 1;
    }

    /* host_impl.rs:332 irandom_range / 860 random / 328 randomize */
    if (!strcmp(name, "irandom_range")) {
        double lo = a[0] < a[1] ? a[0] : a[1];
        double hi = a[0] < a[1] ? a[1] : a[0];
        double span = (hi - lo + 1.0) > 1.0 ? (hi - lo + 1.0) : 1.0;
        double r = gm_next_rand(vm);
        double v = floor(lo + r * span);
        *out = v < hi ? v : hi;
        return 1;
    }
    if (!strcmp(name, "random")) { *out = gm_next_rand(vm) * a[0]; return 1; }
    if (!strcmp(name, "randomize")) { gm_rng_add(vm, 0x9e3779b97f4a7c15ULL); return 1; }

    /* host_impl.rs:856 object_exists */
    if (!strcmp(name, "object_exists")) { *out = gm_object_exists((int32_t)a[0]) ? 1.0 : 0.0; return 1; }

    /* host_impl.rs:506 motion_set / 518 move_towards_point */
    if (!strcmp(name, "motion_set") || !strcmp(name, "move_towards_point")) {
        double dir;
        double spd;
        if (!strcmp(name, "motion_set")) {
            dir = a[0];
            spd = a[1];
        } else {
            GmInst* in = self_of(vm);
            double ix = field_or(in, "x", 0.0);
            double iy = field_or(in, "y", 0.0);
            dir = atan2(-(a[1] - iy), a[0] - ix) * 180.0 / M_PI;
            if (dir < 0.0) dir += 360.0;
            spd = a[2];
        }
        double rad = dir * M_PI / 180.0;
        GmInst* in = self_of(vm);
        set_field(in, "direction", dir);
        set_field(in, "speed", spd);
        set_field(in, "hspeed", spd * cos(rad));
        set_field(in, "vspeed", -spd * sin(rad));
        return 1;
    }

    /* host_impl.rs:155 instance_deactivate_all / 171 activate_region */
    if (!strcmp(name, "instance_activate_region") || !strcmp(name, "instance_deactivate_region")) {
        double x0 = a[0], y0 = a[1];
        double x1 = x0 + a[2], y1 = y0 + a[3];
        int on = !strcmp(name, "instance_activate_region");
        int inside = a[4] >= 0.5;   /* `inside` flag: 1 = act on the region */
        for (int i = 0; i < vm->ninst; i++) {
            GmInst* in = &vm->inst[i];
            if (!in->alive) continue;
            double ix = field_or(in, "x", 0.0);
            double iy = field_or(in, "y", 0.0);
            int hit = (ix >= x0 && ix <= x1 && iy >= y0 && iy <= y1);
            if (inside ? hit : !hit) in->active = on;
        }
        return 1;
    }

    /* host_impl.rs: room warps only change the scheduler target; nothing in a
     * single-body run observes it. */
    if (!strcmp(name, "room_goto") || !strcmp(name, "room_restart") ||
        !strcmp(name, "action_current_room") || !strcmp(name, "game_restart")) return 1;

    /* host_impl.rs:375 file_exists / file_delete: no disk dir is configured for
     * a single body, so both reduce to the in-memory ini view. */
    if (!strcmp(name, "file_exists")) {
        for (int i = 0; i < vm->nini; i++)
            if (vm->ini[i].file == a[0]) { *out = 1.0; return 1; }
        return 1;
    }
    if (!strcmp(name, "file_delete")) return 1;

    /* host_impl.rs:339-352 draw state; the commands themselves are not dumped */
    if (!strcmp(name, "draw_set_font")) { vm->current_font = a[0]; return 1; }
    if (!strcmp(name, "draw_set_color")) { vm->draw_color = (int32_t)a[0]; return 1; }
    if (!strcmp(name, "draw_set_alpha")) { vm->draw_alpha = a[0]; return 1; }
    if (!strncmp(name, "draw_", 5)) {
        /* draw_self reads its own fields first in the VM; if one is missing the
         * VM errors and this body is classified vm_reject, so a no-op here is
         * only ever compared when the VM also produced a dump. */
        if (!strcmp(name, "draw_text_color") && argc >= 8) { vm->draw_color = (int32_t)a[7]; }
        return 1;
    }

    /* host_impl.rs:609-640 ds_map */
    if (!strcmp(name, "ds_map_create")) { *out = (Val)vm->next_map_id++; map_slot(vm, (int)*out, 1); return 1; }
    if (!strcmp(name, "ds_map_destroy")) {
        int id = (int)a[0];
        for (int i = 0; i < vm->nmaps; i++)
            if (vm->maps[i].id == id) { vm->maps[i] = vm->maps[--vm->nmaps]; break; }
        return 1;
    }
    if (!strcmp(name, "ds_map_find_value")) { *out = map_get(vm, (int)a[0], a[1]); return 1; }
    if (!strcmp(name, "ds_map_replace") || !strcmp(name, "ds_map_add")) {
        map_put(vm, (int)a[0], a[1], a[2]);
        return 1;
    }
    if (!strcmp(name, "ds_map_secure_save")) return 1;

    /* host_impl.rs:392-460 ini: in-memory (key, section, file) triples keyed by
     * the string reference; a reference and its text are interchangeable while
     * every key comes from the same bytecode constants. */
    if (!strcmp(name, "ini_open")) { vm->ini_open_file = a[0]; return 1; }
    if (!strcmp(name, "ini_close")) return 1;
    if (!strcmp(name, "ini_read_real")) {
        for (int i = 0; i < vm->nini; i++)
            if (vm->ini[i].file == vm->ini_open_file && vm->ini[i].sec == a[0] && vm->ini[i].key == a[1]) {
                *out = vm->ini[i].val;
                return 1;
            }
        *out = a[2];
        return 1;
    }
    if (!strcmp(name, "ini_write_real")) {
        for (int i = 0; i < vm->nini; i++)
            if (vm->ini[i].file == vm->ini_open_file && vm->ini[i].sec == a[0] && vm->ini[i].key == a[1]) {
                vm->ini[i].val = a[2];
                return 1;
            }
        if (vm->nini < GM_INI_MAX) {
            vm->ini[vm->nini].file = vm->ini_open_file;
            vm->ini[vm->nini].sec = a[0];
            vm->ini[vm->nini].key = a[1];
            vm->ini[vm->nini].val = a[2];
            vm->nini++;
        }
        return 1;
    }

    /* host_impl.rs:650-690 particles: ids are handed out, setters are no-ops
     * because no dumped field can observe them. */
    if (!strcmp(name, "part_type_create")) { *out = vm->next_part_type; vm->next_part_type += 1.0; vm->npart_types++; return 1; }
    if (!strcmp(name, "part_system_create")) {
        /* host_impl.rs:644 — a fresh id per call, starting at 1 */
        *out = vm->next_part_system;
        vm->next_part_system += 1.0;
        return 1;
    }
    if (!strncmp(name, "part_", 5)) return 1;

    /* host_impl.rs: platform stubs that must not stop a body */
    if (!strcmp(name, "iap_acquire") || !strcmp(name, "iap_purchase_details") ||
        !strcmp(name, "ads_disable") || !strcmp(name, "AdColony_Init") ||
        !strcmp(name, "AdColony_ShowVideo") || !strcmp(name, "shop_leave_rating") ||
        !strcmp(name, "application_surface_enable") ||
        !strcmp(name, "device_mouse_dbclick_enable") || !strcmp(name, "mouse_clear")) return 1;

    if (!strcmp(name, "device_mouse_x") || !strcmp(name, "device_mouse_y")) { *out = 0.0; return 1; }
    if (!strcmp(name, "device_mouse_check_button") ||
        !strcmp(name, "device_mouse_check_button_pressed") ||
        !strcmp(name, "device_mouse_check_button_released") ||
        !strcmp(name, "mouse_check_button_pressed")) { *out = 0.0; return 1; }

    /* host_impl.rs:264 collision_point — inclusive box test on the instance's
     * own box. The `precise` flag is not modelled (no mask bits in the C host),
     * which is the same boundary the other collision builtins carry. */
    if (!strcmp(name, "collision_point")) {
        double px = a[0], py = a[1];
        int32_t s = (int32_t)a[2];
        int notme = a[4] >= 0.5;
        int32_t ids[MAX_ENV_SEL];
        int n = vm_select(vm, (Val)s, ids, MAX_ENV_SEL);
        for (int i = 0; i < n; i++) {
            if (notme && ids[i] == vm->cur) continue;
            double l, r, t, b;
            if (!gm_instance_box(vm, ids[i], &l, &r, &t, &b)) continue;
            if (px >= l && px <= r && py >= t && py <= b) { *out = ids[i]; return 1; }
        }
        *out = -4.0;
        return 1;
    }

    /* host_impl.rs:724 d3d_set_fog only feeds the draw state */
    if (!strcmp(name, "d3d_set_fog")) return 1;
    /* host_impl.rs:213 audio_sound_gain mutates the voice command, not state */
    if (!strcmp(name, "audio_sound_gain")) return 1;

    if (!strcmp(name, "action_bounce") || !strcmp(name, "move_bounce_all") ||
        !strcmp(name, "move_bounce_solid") || !strcmp(name, "mp_potential_step")) return 1;

    return 0;   /* not handled: caller falls through to the unimplemented path */
}
