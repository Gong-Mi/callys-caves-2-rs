/* tier: host_authored
 * provenance: 重建实现，镜像 Scene::transition_to_room；房间/放置数据本身来自
 *             game.droid（gen/rooms_data.c，带 source_sha256）。
 * original_gap: 原版 libyoyo 的 room 载入与 RoomCC 绑定路径未逐函数取证。
 *
 * Room warp consumption and RoomData lifecycle for the C reconstruction.
 *
 * Mirrors Scene::transition_to_room: Room End on the active snapshot, retain
 * persistent instances, load every placement/RoomCC binding, then Room Start.
 * The client, not Scene::tick, consumes target_room_warp; the driver exposes
 * that boundary as the WARP operation instead of hiding it inside gm_tick.
 */
#include "gml.h"

#include <stdio.h>
#include <string.h>

static int dispatch_room_event(GmVM* vm, int type, int subtype) {
    int32_t ids[MAX_INST];
    int n = 0;
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (in->alive && in->active) ids[n++] = in->id;
    }
    for (int i = 1; i < n; i++) {
        int32_t v = ids[i];
        int j = i - 1;
        while (j >= 0 && ids[j] > v) { ids[j + 1] = ids[j]; j--; }
        ids[j + 1] = v;
    }
    for (int k = 0; k < n; k++) {
        int rc = gm_dispatch_event(vm, ids[k], type, subtype);
        if (rc < 0) return rc;
    }
    return 0;
}

static int load_room(GmVM* vm, int32_t room_id, const GmRoom* room) {
    vm->current_room = room_id;
    vm->target_room_warp = 0;
    vm->has_room_warp = 0;
    vm->room_width = room->width;
    vm->room_height = room->height;
    for (int i = 0; i < 8; i++) {
        vm->view_visible[i] = 0;
        vm->view_pos[i][0] = vm->view_pos[i][1] = 0.0;
        vm->view_port[i][0] = vm->display_w;
        vm->view_port[i][1] = vm->display_h;
        vm->view_port_set[i] = 0;
        if (i < room->nviews) {
            vm->view_visible[i] = room->views[i].visible;
            vm->view_pos[i][0] = room->views[i].xview;
            vm->view_pos[i][1] = room->views[i].yview;
            vm->view_port[i][0] = room->views[i].wport;
            vm->view_port[i][1] = room->views[i].hport;
            vm->view_port_set[i] = 1;
        }
    }

    for (int k = 0; k < room->nobjects; k++) {
        const GmRoomPlacement* p = &room->objects[k];
        /* The runner keeps a live persistent instance instead of re-placing
         * its object: skip Create AND RoomCC. `active` is deliberately ignored. */
        if (gm_object_persistent(p->object_id)) {
            int already_live = 0;
            for (int i = 0; i < vm->ninst; i++) {
                GmInst* in = &vm->inst[i];
                if (in->alive && in->object == p->object_id) { already_live = 1; break; }
            }
            if (already_live) continue;
        }
        int32_t id = gm_instance_create_placed(vm, p->instance_id, p->object_id, p->x, p->y);
        if (id < 0) return -1;
        GmInst* in = vm_inst(vm, id);
        if (p->scale_x != 0.0) gm_set_field(in, "image_xscale", p->scale_x);
        if (p->scale_y != 0.0) gm_set_field(in, "image_yscale", p->scale_y);
        gm_set_field(in, "image_angle", p->angle);

        /* Scene::load_room_from_data takes the first matching binding in the
         * shipped order: instance id, or object + creation_code fallback. */
        for (int j = 0; j < room->nbindings; j++) {
            const GmRoomBinding* b = &room->bindings[j];
            if (b->instance_id == p->instance_id ||
                (b->object_id == p->object_id && b->code_id == p->creation_code_id)) {
                int rc = gm_dispatch_body(vm, id, b->code_id);
                if (rc < 0) return rc;
                break;
            }
        }
    }
    return 0;
}

int gm_room_transition(GmVM* vm, uint64_t room_id) {
    if (!vm || room_id >= (uint64_t)GM_ROOM_COUNT) {
        gm_fail_msg("room target outside room table");
        return -1;
    }
    int rc = dispatch_room_event(vm, 7, 5); /* Room End before purging */
    if (rc < 0) return rc;

    int out = 0;
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        if (in->alive && gm_object_persistent(in->object)) {
            if (out != i) vm->inst[out] = vm->inst[i];
            out++;
        }
    }
    vm->ninst = out;

    rc = load_room(vm, (int32_t)room_id, &GM_ROOMS[room_id]);
    if (rc < 0) return rc;
    return dispatch_room_event(vm, 7, 4); /* Room Start after materialization */
}

int gm_room_consume_warp(GmVM* vm) {
    if (!vm || !vm->has_room_warp) return 0;
    return gm_room_transition(vm, vm->target_room_warp);
}
