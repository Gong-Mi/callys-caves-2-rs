/*
 * spine_skins_glue.h — the eight physical glue blocks of the skins /
 * attachments window of spSkeletonJson_readSkeletonData (0x28b84c, 13044 B)
 * in libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * The segment-chain census (reconstruction/reverse-v1/asm/segment_chain_map.md
 * §5.1) assigns exactly 368 B / 92 instructions to NO recovered module.  This
 * module owns those bytes and nothing else:
 *
 *   #1 0x28c7a0..0x28c7e4  68 B / 17 insn  path type stub (mov r2,#4) + the
 *                                         five-argument loader call + the
 *                                         NULL split + the `addls pc,pc,r3,lsl#2`
 *                                         type jump table (5 entries)
 *   #2 0x28cc68..0x28ccb8  80 B / 20 insn  spSkin_addAttachment + the three
 *                                         level advance (attachment -> slot ->
 *                                         skin) and its three back edges
 *   #3 0x28cf24..0x28cf3c  24 B /  6 insn  mesh=2 / region=0 / linkedmesh=3
 *                                         type load stubs
 *   #4 0x28cf3c..0x28cf68  44 B / 11 insn  ik  "Target bone not found: " tail
 *   #5 0x28cf68..0x28cf78  16 B /  4 insn  createAttachment NULL split on
 *                                         loader->error1 (silent skip)
 *   #6 0x28cf78..0x28cfa8  48 B / 12 insn  loader error pair report
 *                                         (dispose + setError(loader->error1,
 *                                         loader->error2)) + the bbox=1 stub
 *   #7 0x28d144..0x28d170  44 B / 11 insn  transform "Target bone not found: "
 *   #8 0x28d170..0x28d19c  44 B / 11 insn  path "Target slot not found: "
 *
 * NOT OWNED HERE (census §5.2, §5.3): the six semantic gaps that sit inside
 * other modules' declared windows (0x28bf00/0x28bf28/0x28bf58/0x28c104/
 * 0x28c384/0x28c3b4), the common epilogue 0x28bdcc..0x28bdd4, the chain-level
 * restores 0x28bdd8 / 0x28ccb4, and the field parsers the jump table lands in
 * (region 0x28cdac, boundingbox 0x28cd6c, mesh/linkedmesh 0x28cb20, path
 * 0x28ca5c).  The four parser entry points are linked from their own modules;
 * this module only performs the dispatch.
 *
 * Evidence tier: bytecode_anchored.  The original was never executed and no
 * original-equivalence claim is made.
 */
#ifndef YY_SPINE_SKINS_GLUE_H
#define YY_SPINE_SKINS_GLUE_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"
#include "spine_alloc.h"
#include "spine_attachment.h"
#include "../../spine_json_layout.h"

/*
 * spAttachment is opaque in spine_attachment.h; only the two words this window
 * reads are named here.  +0x04 is the type the JUMP TABLE switches on: it is
 * the type the loader STORED in the created object (0x28c7c0 ldr r3,[r6,#4]),
 * never the requested type handed to createAttachment.
 */
typedef struct skins_glue_attachment_head {
    uint32_t opaque_00;   /* +0x00 */
    int32_t  type;        /* +0x04 */
} skins_glue_attachment_head;
_Static_assert(offsetof(skins_glue_attachment_head, type) == 0x04,
               "0x28c7c0 ldr r3,[r6,#4] reads the stored type at +0x04");

/*
 * The five r2 constants the strcmp dispatch chain loads before the shared call
 * at 0x28c7a4.  Binary order = spAttachmentType order:
 *   region 0 (0x28cf2c mov r2,r0, r0 == 0 after strcmp)
 *   boundingbox 1 (0x28cfa0 mov r2,#1, physically the tail of block #6)
 *   mesh 2 (0x28cf24 mov r2,#2)
 *   linkedmesh 3 (0x28cf34 mov r2,#3)
 *   path 4 (0x28c7a0 mov r2,#4, the head of block #1)
 * c/spine_read_attach_dispatch owns the attachment-type enum in this order.
 */
enum {
    SKINS_GLUE_TYPE_REGION      = 0,
    SKINS_GLUE_TYPE_BOUNDINGBOX = 1,
    SKINS_GLUE_TYPE_MESH        = 2,
    SKINS_GLUE_TYPE_LINKEDMESH  = 3,
    SKINS_GLUE_TYPE_PATH        = 4,
    SKINS_GLUE_TYPE_UNKNOWN     = -1
};

/* Result of one attachment's trip through block #1. */
typedef enum {
    SKINS_GLUE_PUBLISHED = 1,   /* created, field-parsed, added to the skin     */
    SKINS_GLUE_SKIPPED   = 0,   /* 0x28cf74 beq 0x28cc7c: loader reported nothing */
    SKINS_GLUE_ERROR     = -1   /* 0x28cf78 tail: data disposed, NULL returned  */
} skins_glue_rc;

/*
 * Block #3 and its two siblings: the five type load stubs.  Each one is two
 * instructions in the original — load r2 with the constant, then branch to the
 * shared call at 0x28c7a4 (path is the exception: 0x28c7a0 loads r2,#4 and
 * FALLS THROUGH into 0x28c7a4).  Recovering them as five entry points keeps the
 * per-branch r2 and its address visible instead of collapsing the chain into a
 * table; the strcmp chain that picks a branch stays in
 * c/spine_read_attach_dispatch.
 */
skins_glue_rc readSkeletonData_skinsCreateRegionAttachment(
    spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw);
skins_glue_rc readSkeletonData_skinsCreateBoundingBoxAttachment(
    spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw);
skins_glue_rc readSkeletonData_skinsCreateMeshAttachment(
    spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw);
skins_glue_rc readSkeletonData_skinsCreateLinkedMeshAttachment(
    spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw);
skins_glue_rc readSkeletonData_skinsCreatePathAttachment(
    spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw);

/*
 * Block #1 + #3 + #5 + #6 (one attachment).
 *
 *   json            r8      spSkeletonJson*: +0x00 scale, +0x04 loader
 *   skin            r9      spSkin* handed to createAttachment
 *   type            r2      one of the five SKINS_GLUE_TYPE_* stubs
 *   name            r3/r6   attachment name (JSON map member key)
 *   path            [sp]    the FIFTH argument (0x28c7ac str r5,[sp])
 *   attachmentMap   r4      the JSON node the field parser reads
 *   slotIndex       [sp,#0x28]  only the mesh/linkedmesh parser needs it
 *   root            [sp,#0x24]  setError's json argument ONLY on block #6
 *   data_raw        [sp,#0x34]  spSkeletonData* disposed ONLY on block #6
 *
 * On SKINS_GLUE_ERROR the skeleton data has already been disposed and
 * setError() has already disposed the root; the caller must unwind to NULL and
 * must NOT dispose either object again.
 */
skins_glue_rc readSkeletonData_skinsCreateAttachment(
    spSkeletonJson* json, spSkin* skin, int32_t type,
    const char* name, const char* path,
    Json* attachmentMap, uint32_t slotIndex,
    Json* root, void* data_raw);

/*
 * Block #6 first half, 0x28cf78..0x28cfa0 (10 of its 12 instructions; the last
 * two are the boundingbox stub, see readSkeletonData_attachmentTypeLoad):
 *
 *   0x28cf78 ldr r9,[sp,#0x34]      spSkeletonData_dispose(data)
 *   0x28cf7c/80                      ... BEFORE the report
 *   0x28cf84 ldr r3,[r8,#4]         loader
 *   0x28cf88 mov r0,r8 ; 0x28cf8c ldr r1,[sp,#0x24]   json, root
 *   0x28cf90 ldm r3,{r2,r3}         message pair = loader->error1, loader->error2
 *   0x28cf94 bl _spSkeletonJson_setError
 *   0x28cf98 mov r0,r6              returns the failed attachment (0)
 *
 * `attachment` is r6: the NULL createAttachment result.  The message pair is
 * NOT a static string; it is read out of the loader record, whose +0x00/+0x04
 * fields spAttachmentLoader_createAttachment (0x284d58) clears before the
 * vtable call, so only a callee that reported can reach this tail.
 */
int readSkeletonData_skinsLoaderErrorTail(spSkeletonJson* json, Json* root,
                                          void* data_raw, void* attachment);

/*
 * Block #2 first half, 0x28cc68..0x28cc78:
 *   r0=r9 skin, r1=[sp,#0x28] slotIndex, r2=r7 name, r3=r6 attachment,
 *   bl 0x28ecd8 spSkin_addAttachment  (the REAL c/spine_skin body).
 */
void readSkeletonData_skinsAttachmentAdd(spSkin* skin, uint32_t slotIndex,
                                         const char* name, void* attachment);

/*
 * Block #2 second half, 0x28cc7c..0x28ccb8: the three-level advance.
 * The two stack cells [sp,#0x1c] (slot map) and [sp,#0x18] (skin map) hold the
 * CURRENT Json node and are advanced by reading that node's +0x00 next word:
 *   0x28cc7c ldr r4,[r4]        attachment -> attachment->next
 *   0x28cc88 ldr r0,[sp,#0x1c] / 0x28cc8c ldr r0,[r0] / 0x28cc94 str ...
 *   0x28cca0 ldr r0,[sp,#0x18] / 0x28cca4 ldr r0,[r0] / 0x28ccac str ...
 * Modelling the two cells as the cursor fields is exact: each cell's only
 * reader in this window is the loop head, which loads the node itself.
 */
typedef struct skins_glue_cursor {
    Json* attachment;   /* r4                 */
    Json* slot;         /* [sp,#0x1c]         */
    Json* skin;         /* [sp,#0x18]         */
} skins_glue_cursor;

typedef enum {
    SKINS_GLUE_NEXT_ATTACHMENT = 0,  /* 0x28cc84 bne 0x28c6e8 */
    SKINS_GLUE_NEXT_SLOT       = 1,  /* 0x28cc98 bne 0x28c6c4 */
    SKINS_GLUE_NEXT_SKIN       = 2,  /* 0x28ccb0 bne 0x28c664 */
    SKINS_GLUE_NEXT_DONE       = 3,  /* fall through to 0x28ccb4 mov r9,r11 */
    SKINS_GLUE_NEXT_ABORT      = -1
} skins_glue_next;

skins_glue_next readSkeletonData_skinsAdvance(skins_glue_cursor* cursor);

/*
 * The attachment level of the three-level loop: 0x28c6e8 body + block #2.
 * One iteration = body -> advance; the advance is 0x28cc7c..0x28ccb8 and the
 * back edge is 0x28cc84 bne 0x28c6e8.  The slot head (0x28c6c4) and skin head
 * (0x28c664) belong to other modules, so the function returns which back edge
 * the caller must take; it never re-enters them itself.
 *
 * The body is the per-attachment pipeline (classify -> type stub -> create ->
 * field parse -> 0x28cc68 add) and MUST end at 0x28cc68 for PUBLISHED; the add
 * lives there because every one of the five jump-table paths converges on it.
 * SKINS_GLUE_SKIPPED (0x28cf74) branches straight to 0x28cc7c, so nothing is
 * added; SKINS_GLUE_ERROR unwinds without advancing.
 */
typedef int (*skins_glue_body_fn)(void* ctx, Json* attachmentMap);

skins_glue_next readSkeletonData_skinsAttachmentLevel(
    skins_glue_cursor* cursor, skins_glue_body_fn body, void* ctx);

/*
 * Blocks #4, #7, #8 — the three "Target ..." tails.  All three share the shape
 *
 *   mov r4,r0                r4 = the failed lookup result (0 on this path)
 *   mov r0,r9 / bl spSkeletonData_dispose
 *   mov r0,r8 ; ldr r1,[sp,#0x24] ; add r2,pc,<pool>
 *   ldr r3,[r4,#0x1c]        the message ARGUMENT is read through r4
 *   bl _spSkeletonJson_setError
 *   mov r0,r4 ; b 0x28bdcc
 *
 * and differ only in the message literal and therefore in which upstream
 * lookup failed.  They are kept as three functions on purpose (census §6.2:
 * the r0 sources are per-site, a generic tail would lose them).
 *
 * `target_result` is the register value r0 held at the branch:
 *   #4 0x28bfa8 beq  (spSkeletonData_findBone on ik "target")
 *   #7 0x28c154 beq  (spSkeletonData_findBone on transform "target")
 *   #8 0x28c3fc beq  (spSkeletonData_findSlot  on path "target")
 * In the original all three branches are taken only when r0 == 0, so the
 * argument load at 0x28cf58/0x28d160/0x28d18c reads VA 0x1c — a latent
 * NULL-page fault on these error paths.  The translation keeps the load
 * (`[r4+0x1c]`) verbatim; see the fixture note on why the value is injected.
 */
int readSkeletonData_ikTargetNotFoundTail(spSkeletonJson* json, Json* root,
                                          void* data_raw, const void* target_result);
int readSkeletonData_transformTargetNotFoundTail(spSkeletonJson* json, Json* root,
                                                 void* data_raw, const void* target_result);
int readSkeletonData_pathTargetSlotNotFoundTail(spSkeletonJson* json, Json* root,
                                                void* data_raw, const void* target_result);

#endif /* YY_SPINE_SKINS_GLUE_H */
