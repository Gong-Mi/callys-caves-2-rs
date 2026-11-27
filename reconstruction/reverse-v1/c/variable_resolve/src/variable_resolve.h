/*
 * variable_resolve.h — the instance resolver of libyoyo ARMv7's variable read.
 *
 * Entry: _Z17Variable_GetValueiiiP6RValue @0x1f3ce0
 *        (684 B / 0x1f3ce0..0x1f3f8c, literal pool 0x1f3f70..0x1f3f88)
 * Pinned image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Signature: int Variable_GetValue(int id, int varid, int arrindex, RValue* out)
 *   r0 = id       -3 = "all", 0..99999 = object index, >99999 = instance id,
 *                 any other negative = unresolvable
 *   r1 = varid    passed straight through to Direct (this body never decodes it)
 *   r2 = arrindex passed straight through to Direct
 *   r3 = out      passed straight through to Direct
 *
 * This body reads no variable value and never writes `out`: it turns the id
 * into a CInstance* and tail-jumps Variable_GetValue_Direct @0x1f3b8c with
 * (instance, varid, arrindex, out).  Its only write is the 1-byte failure flag.
 *
 * The six .bss globals it reaches through the .got (base 0x3f1c58) are declared
 * here as the translation's own globals.  Their addresses come from the GOT
 * addends, which are materialised in the file (all six slots are R_ARM_RELATIVE
 * pointing at this module's own .bss), so they are read, not guessed:
 *
 *   slot 0x3edd68 (-0x3ef0) -> 0x75505c  g_var_resolve_failed   1 B
 *   slot 0x3edc4c (-0x400c) -> 0x536f28  g_inst_table           cell IS the table
 *   slot 0x3edc44 (-0x4014) -> 0x542374  g_object_hash          cell HOLDS a pointer
 *   slot 0x3edc48 (-0x4010) -> 0x542a64  g_scan_list1           cell IS the list
 *   slot 0x3edc50 (-0x4008) -> 0x542a4c  g_scan_list2           cell IS the list
 *   slot 0x3ed930 (-0x4328) -> 0x54298c  g_run_room             cell HOLDS the CRoom*
 *
 * The two indirection depths are the trap: g_inst_table and the two scan lists
 * are addressed directly (the GOT load already yields the structure), while
 * g_object_hash and g_run_room are pointer variables - one more load reaches
 * the body (0x1f3e84 for the object table, 0x1f3f14 for the room).  0x1f3e84 is
 * the `ldr r12,[r12]` that ms_ID2InstanceE does not have.
 */
#ifndef VARIABLE_RESOLVE_H
#define VARIABLE_RESOLVE_H

#include <stdint.h>

/* Dispatch boundaries.  0x1f3ce4 cmn r0,#3 (sel == -3), 0x1f3d08 blt (sel < 0),
 * 0x1f3d0c/0x1f3d10 movw/movt #0x869f = 99999, 0x1f3d18 ble. */
#define SEL_ALL_INSTANCES  (-3)
#define SEL_INSTANCE_MAX   99999

/* Bucket geometry.  8 B per bucket (`lsl #3`), mask in +4, bucket array in +0.
 * The instance table's node is {prev@0, next@4, id@8, inst@0xc}; the object
 * table's node is {prev@0, next@4, key@8, value@0xc}. */
#define BUCKET_STRIDE     8
#define HNODE_NEXT        0x04u
#define HNODE_KEY         0x08u
#define HNODE_VALUE       0x0cu

/* CObjectGM: the object index its constructor stores at +0x18, the parent
 * object at +0x48, and the instance list head at +0xd0. */
#define OGM_INDEX         0x18u
#define OGM_PARENT        0x48u
#define OGM_INST_CHAIN    0xd0u

/* That instance list: 12 B nodes {next@0, prev@4, inst@8}. */
#define CHAIN_NEXT        0x00u
#define CHAIN_INST        0x08u

/* CInstance fields this body reads. */
#define INST_OBJ          0x80u    /* CObjectGM*   0x1f3d98 / 0x1f3e10 / 0x1f3d98 */
#define INST_DESTROYED    0x68u    /* 0x1f3d64 / 0x1f3ee8 / 0x1f3f34 / 0x1f3dcc */
#define INST_DEACTIVATED  0x69u    /* 0x1f3ef4 / 0x1f3f44 / 0x1f3dd8 (never in the id path) */
#define INST_ROOM_NEXT    0x178u   /* 0x1f3f38 */

/* The two fallback lists: 12 B {items@0, pad@4, count@8}; elements are
 * CInstance* (4 B, `lsl #2`); a count <= 0 skips the whole list. */
#define CONT_ITEMS        0x00u
#define CONT_COUNT        0x08u
#define LIST_ITEM_STRIDE  4

/* CRoom: instance list head at +0x80. */
#define ROOM_INST_HEAD    0x80u   /* CRoom instance list head, 0x1f3f18 */

typedef struct {
    uint32_t buckets;
    uint32_t mask;
    uint32_t count;      /* never read by this body */
} var_hash_table;

typedef struct {
    uint32_t items;
    uint32_t pad;        /* never read by this body */
    int32_t count;
} var_scan_list;

/* The six .bss globals (see the address table above). */
extern unsigned char g_var_resolve_failed;      /* 0x75505c, 1 B               */
extern var_hash_table g_inst_table;             /* 0x536f28, cell IS the table */
extern var_hash_table *g_object_hash;           /* 0x542374, pointer variable  */
extern var_scan_list g_scan_list1;              /* 0x542a64                    */
extern var_scan_list g_scan_list2;              /* 0x542a4c                    */
extern void *g_run_room;                        /* 0x54298c, holds the CRoom*  */

/* The tail-jump target.  Variable_GetValue_Direct @0x1f3b8c is already
 * recovered (reconstruction/reverse-v1/c/variable_direct/) and the harness
 * links that translation for real - it is NOT stubbed here. */
int Variable_GetValue_Direct(void *obj, int varid, int arrindex, void *out);

int Variable_GetValue(int id, int varid, int arrindex, void *out);

#endif /* VARIABLE_RESOLVE_H */
