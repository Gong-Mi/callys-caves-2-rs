/*
 * spine_skins_glue.c — the eight unowned glue blocks of the skins/attachments
 * window of spSkeletonJson_readSkeletonData (0x28b84c).
 * Image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored.  Original never executed; no equivalence claim.
 *
 * Instruction-level map (every comment below names the address it came from):
 *
 *   #1 0x28c7a0  mov  r2,#4                 path stub head  (r2 = 4)
 *      0x28c7a4  ldr  r0,[r8,#4]            loader = json->loader
 *      0x28c7a8  mov  r3,r6                 name
 *      0x28c7ac  str  r5,[sp]               path = the STACK fifth argument
 *      0x28c7b0  mov  r1,r9                 skin
 *      0x28c7b4  bl   spAttachmentLoader_createAttachment (0x284d58)
 *      0x28c7b8  subs r6,r0,#0
 *      0x28c7bc  beq  0x28cf68              NULL split (block #5)
 *      0x28c7c0  ldr  r3,[r6,#4]            type STORED IN THE OBJECT
 *      0x28c7c4  cmp  r3,#4                 unsigned; >=5 falls through
 *      0x28c7c8  addls pc,pc,r3,lsl#2       base = 0x28c7d0
 *      0x28c7cc  b    0x28cc68              (r3 > 4) add only, no field parse
 *      0x28c7d0  b 0x28cdac                 entry[0] region
 *      0x28c7d4  b 0x28cd6c                 entry[1] boundingbox
 *      0x28c7d8  b 0x28cb20                 entry[2] mesh
 *      0x28c7dc  b 0x28cb20                 entry[3] linkedmesh -> same parser
 *      0x28c7e0  b 0x28ca5c                 entry[4] path
 *      (0x28c7e4.. is the literal pool)
 *
 *   #3 0x28cf24  mov r2,#2 ; b 0x28c7a4     mesh
 *      0x28cf2c  mov r2,r0 ; b 0x28c7a4     region (r0 == the strcmp result 0)
 *      0x28cf34  mov r2,#3 ; b 0x28c7a4     linkedmesh
 *      0x28cfa0  mov r2,#1 ; b 0x28c7a4     boundingbox (block #6's tail)
 *
 *   #5 0x28cf68  ldr  r3,[r8,#4]            loader
 *      0x28cf6c  ldr  r3,[r3]               loader->error1 (+0x00)
 *      0x28cf70  cmp  r3,#0
 *      0x28cf74  beq  0x28cc7c              silent skip -> advance, no add
 *
 *   #6 0x28cf78  ldr  r9,[sp,#0x34]         data (r9 held the skin)
 *      0x28cf7c/80 mov r0,r9 ; bl spSkeletonData_dispose (0x28adf8)
 *      0x28cf84  ldr  r3,[r8,#4]            loader
 *      0x28cf88  mov  r0,r8
 *      0x28cf8c  ldr  r1,[sp,#0x24]         root
 *      0x28cf90  ldm  r3,{r2,r3}            error1, error2  (NOT static text)
 *      0x28cf94  bl   _spSkeletonJson_setError (0x28b784)
 *      0x28cf98  mov  r0,r6                 failed attachment (0)
 *      0x28cf9c  b    0x28bdcc              shared epilogue
 *
 *   #2 0x28cc68  mov r2,r7 ; 0x28cc6c mov r3,r6 ; 0x28cc70 mov r0,r9
 *      0x28cc74  ldr r1,[sp,#0x28] ; 0x28cc78 bl spSkin_addAttachment
 *      0x28cc7c  ldr  r4,[r4]               attachment = attachment->next (+0x00)
 *      0x28cc80  cmp  r4,#0 ; 0x28cc84 bne 0x28c6e8
 *      0x28cc88  ldr  r0,[sp,#0x1c] ; 0x28cc8c ldr r0,[r0] ; 0x28cc94 str
 *      0x28cc90  cmp  r0,#0 ; 0x28cc98 bne 0x28c6c4   (slot back edge)
 *      0x28cc9c  ldr  r11,[sp,#0x34]        data restore (CHAIN LEVEL, §5.3)
 *      0x28cca0  ldr  r0,[sp,#0x18] ; 0x28cca4 ldr r0,[r0] ; 0x28ccac str
 *      0x28cca8  cmp  r0,#0 ; 0x28ccb0 bne 0x28c664   (skin back edge)
 *      0x28ccb4  mov  r9,r11                (CHAIN LEVEL, §5.3)
 *
 *   #4 0x28cf3c  mov r4,r0 ; 0x28cf40/44 dispose(data)
 *      0x28cf48  ldr r2,[pc,#-0x5a4] -> pool 0x28c9ac = 0xcad14
 *      0x28cf4c  mov r0,r8 ; 0x28cf50 ldr r1,[sp,#0x24] (root)
 *      0x28cf54  add r2,pc,r2        -> 0x28cf5c + 0xcad14 = 0x357c70
 *      0x28cf58  ldr r3,[r4,#0x1c]   argument THROUGH r4
 *      0x28cf5c  bl _spSkeletonJson_setError ; 0x28cf60 mov r0,r4 ; b 0x28bdcc
 *
 *   #7 0x28d144..0x28d16c   same shape, pool 0x28c9d0 = 0xcab0c,
 *                           add at 0x28d15c (pc 0x28d164) -> 0x357c70 too:
 *                           ik and transform share the "Target bone not found: "
 *                           literal, byte-verified at 0x357c70.
 *   #8 0x28d170..0x28d198   same shape, pool 0x28c9d4 = 0xcab84,
 *                           add at 0x28d188 (pc 0x28d190) -> 0x357d14
 *                           "Target slot not found: ".
 */
#include "spine_skins_glue.h"

#include "spine_skin.h"
#include "spine_skeleton_data.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_atlas_attachment/src/spine_atlas_attachment.h"
#include "../../spine_read_region/src/spine_read_region.h"
#include "../../spine_read_mesh/src/spine_read_mesh.h"
#include "../../spine_read_bbox_path/src/spine_read_bbox_path.h"

/* 0x357c70 / 0x357d14 — byte-verified literals, pinned again by the checker. */
#define SKINS_GLUE_ERR_TARGET_BONE "Target bone not found: "
#define SKINS_GLUE_ERR_TARGET_SLOT "Target slot not found: "

/* ==================================================================== */
/* the five type load stubs                                             */
/* ==================================================================== */

/* 0x28cf2c mov r2,r0 ; 0x28cf30 b 0x28c7a4
 * r0 is the strcmp("region") result, which is 0 on this branch. */
skins_glue_rc readSkeletonData_skinsCreateRegionAttachment(
        spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw)
{
    return readSkeletonData_skinsCreateAttachment(
        json, skin, SKINS_GLUE_TYPE_REGION, name, path,
        attachmentMap, slotIndex, root, data_raw);
}

/* 0x28cfa0 mov r2,#1 ; 0x28cfa4 b 0x28c7a4  (physically block #6's last pair) */
skins_glue_rc readSkeletonData_skinsCreateBoundingBoxAttachment(
        spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw)
{
    return readSkeletonData_skinsCreateAttachment(
        json, skin, SKINS_GLUE_TYPE_BOUNDINGBOX, name, path,
        attachmentMap, slotIndex, root, data_raw);
}

/* 0x28cf24 mov r2,#2 ; 0x28cf28 b 0x28c7a4 */
skins_glue_rc readSkeletonData_skinsCreateMeshAttachment(
        spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw)
{
    return readSkeletonData_skinsCreateAttachment(
        json, skin, SKINS_GLUE_TYPE_MESH, name, path,
        attachmentMap, slotIndex, root, data_raw);
}

/* 0x28cf34 mov r2,#3 ; 0x28cf38 b 0x28c7a4 */
skins_glue_rc readSkeletonData_skinsCreateLinkedMeshAttachment(
        spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw)
{
    return readSkeletonData_skinsCreateAttachment(
        json, skin, SKINS_GLUE_TYPE_LINKEDMESH, name, path,
        attachmentMap, slotIndex, root, data_raw);
}

/* 0x28c7a0 mov r2,#4 — falls straight into 0x28c7a4, it is block #1's head */
skins_glue_rc readSkeletonData_skinsCreatePathAttachment(
        spSkeletonJson* json, spSkin* skin, const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex, Json* root, void* data_raw)
{
    return readSkeletonData_skinsCreateAttachment(
        json, skin, SKINS_GLUE_TYPE_PATH, name, path,
        attachmentMap, slotIndex, root, data_raw);
}

/* ==================================================================== */
/* block #1: createAttachment + NULL split + type jump table            */
/* ==================================================================== */

skins_glue_rc readSkeletonData_skinsCreateAttachment(
        spSkeletonJson* json, spSkin* skin, int32_t type,
        const char* name, const char* path,
        Json* attachmentMap, uint32_t slotIndex,
        Json* root, void* data_raw)
{
    /* 0x28c7a4 ldr r0,[r8,#4] — the loader word of the parser record */
    spAttachmentLoader* loader = (spAttachmentLoader*)(uintptr_t)json->loader;
    void* attachment;
    int32_t stored_type;

    /* 0x28c7a8 mov r3,r6 ; 0x28c7ac str r5,[sp] ; 0x28c7b0 mov r1,r9 ;
     * 0x28c7b4 bl 0x284d58.  Five arguments: r0 loader, r1 skin, r2 type,
     * r3 name, [sp] path.  The real recovered wrapper (c/spine_atlas_attachment)
     * frees and clears loader->error1/error2 BEFORE the vtable call. */
    attachment = spAttachmentLoader_createAttachment(loader, skin, type, name, path);

    /* 0x28c7b8 subs r6,r0,#0 ; 0x28c7bc beq 0x28cf68 */
    if (attachment == 0) {
        /* ---- block #5: 0x28cf68..0x28cf78 ---- */
        /* 0x28cf68 ldr r3,[r8,#4] — json->loader is reloaded here, not reused
         * from 0x28c7a4, so the split sees the word the parser record holds at
         * this instant. */
        spAttachmentLoader* current = (spAttachmentLoader*)(uintptr_t)json->loader;
        /* 0x28cf6c ldr r3,[r3] ; 0x28cf70 cmp r3,#0 */
        if (current->error1 == 0) {
            /* 0x28cf74 beq 0x28cc7c — the attachment is dropped silently and
             * the loop advances.  Original quirk, kept. */
            return SKINS_GLUE_SKIPPED;
        }
        /* ---- block #6: 0x28cf78..0x28cfa0 ---- */
        (void)readSkeletonData_skinsLoaderErrorTail(json, root, data_raw, attachment);
        /* 0x28cf98 mov r0,r6 ; 0x28cf9c b 0x28bdcc -> caller returns NULL */
        return SKINS_GLUE_ERROR;
    }

    /* 0x28c7c0 ldr r3,[r6,#4] — the type stored in the created object, which
     * is NOT necessarily the requested type (e.g. a loader may answer a
     * linkedmesh request with an object whose +0x04 is 2). */
    stored_type = ((const skins_glue_attachment_head*)attachment)->type;

    /* 0x28c7c4 cmp r3,#4 ; 0x28c7c8 addls pc,pc,r3,lsl#2 (base 0x28c7d0).
     * `ls` is unsigned: any stored type outside 0..4 takes the fall-through
     * 0x28c7cc b 0x28cc68, i.e. add without a field parse. */
    if ((uint32_t)stored_type <= (uint32_t)SKINS_GLUE_TYPE_PATH) {
        switch (stored_type) {
        case SKINS_GLUE_TYPE_REGION:       /* 0x28c7d0 b 0x28cdac */
            readSkeletonData_regionFields(attachmentMap, attachment, path, json);
            break;
        case SKINS_GLUE_TYPE_BOUNDINGBOX:  /* 0x28c7d4 b 0x28cd6c */
            readSkeletonData_boundingBoxFields(attachmentMap, attachment, json, loader);
            break;
        case SKINS_GLUE_TYPE_MESH:         /* 0x28c7d8 b 0x28cb20 */
        case SKINS_GLUE_TYPE_LINKEDMESH:   /* 0x28c7dc b 0x28cb20 */
            /* Both entries point at the same parser.  Its return value is
             * ignored here exactly like 0x28cb1c `b 0x28cc68`: a mesh that was
             * queued for the linkedmesh postpass is STILL added to the skin. */
            (void)readSkeletonData_meshFields(
                attachmentMap, attachment, path, json, slotIndex);
            break;
        case SKINS_GLUE_TYPE_PATH:         /* 0x28c7e0 b 0x28ca5c */
            readSkeletonData_pathAttachmentFields(attachmentMap, attachment, json);
            break;
        default:
            /* unreachable: the unsigned test above already excluded it */
            break;
        }
    }

    /* 0x28cc68..0x28cc78 */
    readSkeletonData_skinsAttachmentAdd(skin, slotIndex, name, attachment);
    return SKINS_GLUE_PUBLISHED;
}

/* ==================================================================== */
/* block #6: loader error pair report                                   */
/* ==================================================================== */

int readSkeletonData_skinsLoaderErrorTail(spSkeletonJson* json, Json* root,
                                          void* data_raw, void* attachment)
{
    spAttachmentLoader* loader = (spAttachmentLoader*)(uintptr_t)json->loader;

    /* 0x28cf78 ldr r9,[sp,#0x34] — the skins segment's data cell; r9 currently
     * holds the skin, so the data pointer is reloaded from the frame. */
    /* 0x28cf7c mov r0,r9 ; 0x28cf80 bl 0x28adf8 */
    spSkeletonData_dispose((spSkeletonData*)data_raw);

    /* 0x28cf84 ldr r3,[r8,#4] ; 0x28cf88 mov r0,r8 ; 0x28cf8c ldr r1,[sp,#0x24] ;
     * 0x28cf90 ldm r3,{r2,r3} — the message and its argument come out of the
     * loader record (+0x00 / +0x04), they are not static text. */
    /* 0x28cf94 bl 0x28b784 */
    _spSkeletonJson_setError(json, root, loader->error1, loader->error2);

    /* 0x28cf98 mov r0,r6 — the failed attachment (0) */
    return (int)(intptr_t)attachment;
}

/* ==================================================================== */
/* block #2: add + three-level advance                                  */
/* ==================================================================== */

void readSkeletonData_skinsAttachmentAdd(spSkin* skin, uint32_t slotIndex,
                                         const char* name, void* attachment)
{
    /* 0x28cc68 mov r2,r7 ; 0x28cc6c mov r3,r6 ; 0x28cc70 mov r0,r9 ;
     * 0x28cc74 ldr r1,[sp,#0x28] ; 0x28cc78 bl 0x28ecd8 (c/spine_skin) */
    spSkin_addAttachment(skin, slotIndex, name, (spAttachment*)attachment);
}

skins_glue_next readSkeletonData_skinsAdvance(skins_glue_cursor* cursor)
{
    Json* next;

    /* 0x28cc7c ldr r4,[r4] — Json +0x00 is the sibling link */
    next = cursor->attachment->next;
    cursor->attachment = next;
    /* 0x28cc80 cmp r4,#0 ; 0x28cc84 bne 0x28c6e8 */
    if (next != 0)
        return SKINS_GLUE_NEXT_ATTACHMENT;

    /* 0x28cc88 ldr r0,[sp,#0x1c] ; 0x28cc8c ldr r0,[r0] ; 0x28cc94 str r0,[sp,#0x1c] */
    next = cursor->slot->next;
    cursor->slot = next;
    /* 0x28cc90 cmp r0,#0 ; 0x28cc98 bne 0x28c6c4 */
    if (next != 0)
        return SKINS_GLUE_NEXT_SLOT;

    /* 0x28cca0 ldr r0,[sp,#0x18] ; 0x28cca4 ldr r0,[r0] ; 0x28ccac str r0,[sp,#0x18] */
    next = cursor->skin->next;
    cursor->skin = next;
    /* 0x28cca8 cmp r0,#0 ; 0x28ccb0 bne 0x28c664 */
    if (next != 0)
        return SKINS_GLUE_NEXT_SKIN;

    /* 0x28ccb4 mov r9,r11 is the chain-level data restore (census §5.3) and is
     * NOT re-emitted here; falling out means the three lists are exhausted. */
    return SKINS_GLUE_NEXT_DONE;
}

skins_glue_next readSkeletonData_skinsAttachmentLevel(
        skins_glue_cursor* cursor, skins_glue_body_fn body, void* ctx)
{
    for (;;) {
        int rc = body(ctx, cursor->attachment);

        /* 0x28cf9c b 0x28bdcc: an error unwinds to NULL, it never advances. */
        if (rc == SKINS_GLUE_ERROR)
            return SKINS_GLUE_NEXT_ABORT;
        /* PUBLISHED already ran 0x28cc68 inside the body, SKIPPED (0x28cf74)
         * branched over it; both land here on 0x28cc7c. */

        {
            skins_glue_next which = readSkeletonData_skinsAdvance(cursor);
            if (which != SKINS_GLUE_NEXT_ATTACHMENT)   /* 0x28cc84 bne 0x28c6e8 */
                return which;
        }
    }
}

/* ==================================================================== */
/* blocks #4 / #7 / #8: the three "Target ..." error tails              */
/* ==================================================================== */
/*
 * All three read the message ARGUMENT through r4 = r0 = the failed lookup's
 * result, which is 0 on the only edge into these blocks:
 *   #4 0x28bfa8 beq 0x28cf3c   (ik target bone)
 *   #7 0x28c154 beq 0x28d144   (transform target bone)
 *   #8 0x28c3fc beq 0x28d170   (path target slot)
 * so `ldr r3,[r4,#0x1c]` reads VA 0x1c in the original — a latent fault on an
 * error path the shipped data never takes.  The load is reproduced verbatim;
 * the fixture injects a record to observe offset and register source.
 */

int readSkeletonData_ikTargetNotFoundTail(spSkeletonJson* json, Json* root,
                                          void* data_raw, const void* target_result)
{
    const void* r4 = target_result;                     /* 0x28cf3c mov r4,r0 */

    spSkeletonData_dispose((spSkeletonData*)data_raw);  /* 0x28cf40/0x28cf44 */
    /* 0x28cf48 ldr r2,[pc,#-0x5a4] -> pool 0x28c9ac = 0x000cad14
     * 0x28cf54 add r2,pc,r2 -> 0x28cf5c + 0xcad14 = 0x357c70 */
    _spSkeletonJson_setError(json, root, SKINS_GLUE_ERR_TARGET_BONE,
                             /* 0x28cf58 */ *(const char* const*)
                             ((const char*)(uintptr_t)r4 + 0x1c));
    return (int)(intptr_t)r4;                           /* 0x28cf60 mov r0,r4 */
}

int readSkeletonData_transformTargetNotFoundTail(spSkeletonJson* json, Json* root,
                                                 void* data_raw, const void* target_result)
{
    const void* r4 = target_result;                     /* 0x28d144 mov r4,r0 */

    spSkeletonData_dispose((spSkeletonData*)data_raw);  /* 0x28d148/0x28d14c */
    /* 0x28d150 ldr r2,[pc,#-0x788] -> pool 0x28c9d0 = 0x000cab0c
     * 0x28d15c add r2,pc,r2 -> 0x28d164 + 0xcab0c = 0x357c70 (same literal) */
    _spSkeletonJson_setError(json, root, SKINS_GLUE_ERR_TARGET_BONE,
                             /* 0x28d160 */ *(const char* const*)
                             ((const char*)(uintptr_t)r4 + 0x1c));
    return (int)(intptr_t)r4;                           /* 0x28d168 mov r0,r4 */
}

int readSkeletonData_pathTargetSlotNotFoundTail(spSkeletonJson* json, Json* root,
                                                void* data_raw, const void* target_result)
{
    const void* r4 = target_result;                     /* 0x28d170 mov r4,r0 */

    spSkeletonData_dispose((spSkeletonData*)data_raw);  /* 0x28d174/0x28d178 */
    /* 0x28d17c ldr r2,[pc,#-0x7b0] -> pool 0x28c9d4 = 0x000cab84
     * 0x28d188 add r2,pc,r2 -> 0x28d190 + 0xcab84 = 0x357d14 */
    _spSkeletonJson_setError(json, root, SKINS_GLUE_ERR_TARGET_SLOT,
                             /* 0x28d18c */ *(const char* const*)
                             ((const char*)(uintptr_t)r4 + 0x1c));
    return (int)(intptr_t)r4;                           /* 0x28d194 mov r0,r4 */
}
