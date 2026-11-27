/*
 * spine_read_tl_deform.c — deform timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B14   0x28e060..0x28e338  182 insns  deform map -> skin -> slot ->
 *                                        attachment-name node -> frames;
 *                                        weighted count; line-388 malloc;
 *                                        create; publish tail
 *   B14b  0x28e820..0x28e880   24 insns  out-of-line island: "vertices"
 *                                        absent branch + the scale != 1 copy
 *   E6    0x28e8ac..0x28e8ec   16 insns  "Slot not found: " (called from the
 *                                        drawOrder offsets loop, 0x28e464)
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted.  Keys ("vertices"/"offset"/"time"/"slot"), the
 * weighted gate, the magic /3, the line number 388, the one-float frame
 * stride and the E6 json argument (NULL) are all read off the instruction
 * stream (census §2.7 / §6 B14 / §7 opens #5 and #8).
 */

#include "spine_read_tl_deform.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */
#include "../../spine_json_error/src/spine_json_error.h"   /* _spSkeletonJson_setError */
#include "../../spine_skin/src/spine_skin.h"               /* real getAttachment */
#include "../../spine_alloc/src/spine_alloc.h"             /* _malloc/_free */

extern void* memset(void* dst, int value, size_t count);

#define ERR_SLOT_NOT_FOUND "Slot not found: "

/* 0x28e080 pool 0x28eac0 -> 0x357b08, loaded into [sp+0x50] at 0x28e0a0 and
 * handed to _malloc at 0x28e154. */
#define SKELETON_JSON_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* 0x28e150 mov r2,#388 — the malloc line.  It is a plain MOV immediate, not a
 * movw, which is why the card extractor recorded line = null for this site. */
#define DEFORM_MALLOC_LINE 388u

/*
 * ---------------------------------------------------------------------------
 * Weighted divide-by-3, 0x28e128..0x28e140.
 *
 * The magic is a stack constant written by B3:
 *   0x28d2d8 movw r1,#0x5556
 *   0x28d2e0 movt r1,#0x5555
 *   0x28d304 str  r1,[sp,#0x60]
 * and 0x28e128 is its only reader in the whole function:
 *   0x28e128 ldrne r1,[sp,#0x60]
 *   0x28e12c ldrne r3,[r8,#0x18]     verticesCount
 *   0x28e134 smullne r1,r2,r1,r3     r2 = high 32 of 0x55555556 * v
 *   0x28e13c subne  r3,r2,r3,asr #31 q = high - (v >> 31)
 *   0x28e140 lslne  r11,r3,#1       2*q
 *
 * `v >> 31` is an ARITHMETIC shift (asr), i.e. -1 for every negative v, so the
 * subtraction is the usual truncation correction and q == v / 3 rounding
 * toward zero.  C's signed `/` has the same definition; the checker proves the
 * equivalence over 25 values with a separate smull model, including INT_MIN.
 * ---------------------------------------------------------------------------
 */
int32_t
readSkeletonData_deformWeightedDivide3(int32_t vertexCount)
{
    return 2 * (vertexCount / 3);
}

/* 0x28e114 ldr r3,[r8,#0x14]      bones (NULL gate)
 * 0x28e118 adds r3,r3,#0
 * 0x28e11c movne r3,#1
 * 0x28e120 cmp r3,#0
 * 0x28e124 str r3,[sp,#0x34]      the shared weighted flag
 * 0x28e128 ldrne r1,[sp,#0x60]    magic
 * 0x28e12c ldrne r3,[r8,#0x18]
 * 0x28e130 ldreq r11,[r8,#0x18]   non-weighted: the count is used verbatim
 * 0x28e140 lslne r11,r3,#1
 */
int32_t
readSkeletonData_deformVertexFloatCount(const void* attachment_raw)
{
    const spVertexAttachmentDeformShape* a =
        (const spVertexAttachmentDeformShape*)attachment_raw;

    if (a->bones != 0)                                     /* 0x28e114..0x28e124 */
        return readSkeletonData_deformWeightedDivide3(a->verticesCount);
                                                           /* 0x28e128..0x28e140 */
    return a->verticesCount;                               /* 0x28e130 */
}

/*
 * ---------------------------------------------------------------------------
 * B14 frame loop, 0x28e19c..0x28e2c0, plus the B14b islands 0x28e820..0x28e87c.
 *
 * Register roles in the original: r5 = frame, r4 = the shared vertex buffer,
 * r7 = timeline, r8 = attachment, r10 = animation, r6 = the pointer handed to
 * setFrame, s16 = 1.0f, [sp+0x30] = frame index, [sp+0x34] = weighted,
 * [sp+0x38] = buffer byte size, [sp+0x48]/[sp+0x54]/[sp+0x58] = "vertices"/
 * "offset"/"time", [sp+0x44] = buffer end (r4 + size).
 *
 *   0x28e19c mov r0,r5
 *   0x28e1a0 ldr r1,[sp,#0x48]     "vertices"
 *   0x28e1a4 bl  Json_getItem
 *   0x28e1a8 subs r12,r0,#0
 *   0x28e1ac beq 0x28e820           B14b: the key is absent
 *   0x28e1b0 ldr r1,[sp,#0x54]     "offset"
 *   0x28e1b4 mov r2,#0              default 0
 *   0x28e1b8 mov r0,r5
 *   0x28e1bc str r12,[sp,#0x14]     spill verticesJson
 *   0x28e1c0 bl  Json_getInt
 *   0x28e1c8 lsl r3,r0,#2           offset bytes
 *   0x28e1cc mov r6,r0              written = offset
 *   0x28e1d4 str r3,[sp,#0x10]
 *   0x28e1dc bl  memset(buffer,0,offset*4)
 *   0x28e1e0 ldr r0,[sp,#0x20]      parser
 *   0x28e1e4 vldr s15,[r0]          scale
 *   0x28e1e8 vcmp.f32 s15,s16       against 1.0f (0x28e184 vmov s16,#1.0)
 *   0x28e1fc bne 0x28e848           scale != 1 -> B14b scaled copy
 *   0x28e1f8 ldr r2,[r12,#0x4]      vertices array first element
 *   0x28e200 cmp r2,#0
 *   0x28e204 beq 0x28e228           empty array -> skip copy
 *   0x28e208 add r3,r4,r3           dst = buffer + offset bytes
 *   0x28e20c..0x28e220              *dst++ = element->float_value (+0x18); r6++
 *   0x28e224 lsl r3,r6,#2
 *   0x28e228 rsb r2,r6,r11          floatCount - written
 *   0x28e22c add r0,r4,r3
 *   0x28e238 bl  memset(buffer+written, 0, (floatCount-written)*4)
 *
 * The scaled island (B14b second half), entered only when scale != 1.0f:
 *   0x28e848 cmp r2,#0
 *   0x28e84c beq 0x28e228           empty array -> skip copy
 *   0x28e850 add r3,r4,r3           dst = buffer + offset bytes
 *   0x28e854 b   0x28e860           first iteration reuses s15 = scale
 *   0x28e858 vldr s15,[parser]      every later iteration reloads the scale
 *   0x28e860 vldr s14,[r2,#0x18]    element->float_value
 *   0x28e864 vmul.f32 s15,s15,s14
 *   0x28e868..0x28e874              next, r6++, store, loop
 *   0x28e87c b   0x28e224
 *
 * Then the non-weighted base addend, 0x28e23c..0x28e270:
 *   0x28e23c ldr r2,[sp,#0x34]      weighted
 *   0x28e240 cmp r2,#0
 *   0x28e244 bne 0x28e274           weighted -> skip
 *   0x28e248 cmp r11,#0
 *   0x28e24c ldr r2,[r8,#0x1c]      base vertices
 *   0x28e250 ble 0x28e274           floatCount <= 0 -> skip
 *   0x28e258..0x28e270              buffer[i] += base[i] until buffer == end
 *
 * And the publish:
 *   0x28e274 mov r6,r4              src = buffer
 *   0x28e278..0x28e284              time = Json_getFloat(frame,"time",0.0f)
 *   0x28e288 ldr r1,[sp,#0x30]      frameIndex
 *   0x28e28c mov r3,r6
 *   0x28e298 bl spDeformTimeline_setFrame(timeline,i,time,src)
 *   0x28e2a8 bl readCurve(frame,timeline,i)
 *   0x28e2ac ldr r5,[r5]            frame = frame->next
 *   0x28e2c0 bne 0x28e19c
 *
 * The absent-key island (B14b first half), 0x28e820..0x28e844:
 *   0x28e820 ldr r2,[sp,#0x34]      weighted
 *   0x28e824 cmp r2,#0
 *   0x28e828 ldreq r6,[r8,#0x1c]    non-weighted: src = attachment->vertices
 *   0x28e82c beq 0x28e278           (the buffer is not touched for this frame)
 *   0x28e830 mov r1,r12             r12 == 0 here (0x28e1a8 subs set it to the
 *                                   NULL getItem result), i.e. memset value 0
 *   0x28e834 mov r0,r4
 *   0x28e838 ldr r2,[sp,#0x38]      buffer byte size
 *   0x28e83c mov r6,r4
 *   0x28e840 bl memset(buffer,0,size)
 *   0x28e844 b 0x28e278
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_deformTimelineFrames(Json* timelineNode,
                                      const void* attachment_raw,
                                      void* timeline_raw, float* buffer,
                                      int32_t floatCount, int32_t weighted,
                                      const void* parser_raw)
{
    const spVertexAttachmentDeformShape* attachment =
        (const spVertexAttachmentDeformShape*)attachment_raw;
    const float scale = spSkeletonJson_deform_scale_float(
        (const spSkeletonJson*)parser_raw);
    Json* frame = timelineNode->child;                 /* 0x28e168 ldr r5,[r9,#4] */
    int32_t frameIndex = 0;                            /* 0x28e190 str r1,[sp,#0x30] */

    do {
        Json* verticesJson = Json_getItem(frame, "vertices");   /* 0x28e19c..0x28e1a4 */
        int32_t offset = Json_getInt(frame, "offset", 0);       /* 0x28e1b0..0x28e1c0 */
        int32_t written = offset;                      /* 0x28e1cc mov r6,r0 */
        uint8_t* dst = (uint8_t*)buffer + (uint32_t)offset * 4u;
                                                       /* 0x28e1c8 / 0x28e208 */
        const void* src;

        memset(buffer, 0, (uint32_t)offset * 4u);      /* 0x28e1dc */

        if (verticesJson == 0) {                       /* 0x28e1ac beq 0x28e820 */
            if (weighted != 0) {                       /* 0x28e820..0x28e824 */
                memset(buffer, 0, (uint32_t)floatCount * 4u);  /* 0x28e830..0x28e840 */
                src = buffer;                          /* 0x28e83c mov r6,r4 */
            } else {
                src = attachment->vertices;            /* 0x28e828 ldreq r6,[r8,#0x1c] */
            }
        } else {
            float* out = (float*)dst;                  /* 0x28e208 add r3,r4,r3 */
            Json* element = verticesJson->child;       /* 0x28e1f8 ldr r2,[r12,#4] */

            if (scale == 1.0f) {                       /* 0x28e1e8 / 0x28e1f4 / 0x28e1fc */
                while (element != 0) {                 /* 0x28e20c..0x28e220 */
                    *out++ = element->float_value;
                    ++written;                         /* 0x28e210 add r6,r6,#1 */
                    element = element->next;           /* 0x28e214 ldr r2,[r2] */
                }
            } else {
                while (element != 0) {                 /* 0x28e858..0x28e878 */
                    float scaled = scale * element->float_value;  /* 0x28e864 */
                    *out++ = scaled;
                    ++written;
                    element = element->next;
                }
            }

            memset((uint8_t*)buffer + (uint32_t)written * 4u, 0,
                   (uint32_t)(floatCount - written) * 4u);  /* 0x28e228..0x28e238 */
            src = buffer;                              /* 0x28e274 mov r6,r4 */
        }

        if (weighted == 0 && floatCount > 0) {         /* 0x28e23c..0x28e250 */
            int32_t i;
            for (i = 0; i < floatCount; ++i)           /* 0x28e258..0x28e270 */
                buffer[i] = buffer[i] + attachment->vertices[i];
        }

        {
            float time = Json_getFloat(frame, "time", 0.0f);  /* 0x28e278..0x28e284 */
            spDeformTimeline_setFrame(timeline_raw, frameIndex, time, src);
                                                       /* 0x28e288..0x28e298 */
        }
        readCurve(frame, timeline_raw, frameIndex);    /* 0x28e29c..0x28e2a8 */

        frame = frame->next;                           /* 0x28e2ac */
        ++frameIndex;                                  /* 0x28e2b0..0x28e2bc */
    } while (frame != 0);                              /* 0x28e2c0 */
}

/*
 * ---------------------------------------------------------------------------
 * B14 driver, 0x28e060..0x28e338.
 *
 *   0x28e060 ldr r1,[sp,#0x50]      deform map
 *   0x28e068 beq 0x28e338           absent -> drawOrder
 *   0x28e06c..0x28e078              skinNode = map->child; [sp+0x2c] = it
 *   0x28e07c beq 0x28e338           no children -> drawOrder
 *   0x28e080..0x28e0b0              four literals: tag -> [sp+0x50],
 *                                   "vertices" -> [sp+0x48], "offset" ->
 *                                   [sp+0x54], "time" -> [sp+0x58]
 *   0x28e084 mov r10,r11            save animation
 *   --- skin loop: head 0x28e0b4, advance 0x28e320..0x28e330 ---
 *   0x28e0bc ldr r1,[r2,#0x1c]      skinNode->name
 *   0x28e0c0 bl spSkeletonData_findSkin
 *   0x28e0c8 ldr r8,[r3,#0x4]       slotNode = skinNode->child
 *   0x28e0d0 movne r11,r8
 *   0x28e0d4 str r0,[sp,#0x40]      skin result (may be NULL; never tested)
 *   0x28e0d8 beq 0x28e320           no slots -> next skin
 *   --- slot loop: head 0x28e0dc, advance 0x28e314..0x28e31c ---
 *   0x28e0e0 ldr r1,[r11,#0x1c]     slotNode->name
 *   0x28e0e4 bl spSkeletonData_findSlotIndex
 *   0x28e0e8 ldr r9,[r11,#0x4]      tlNode = slotNode->child
 *   0x28e0ec..0x28e0f4              [sp+0x5c] = slotNode, [sp+0x3c] = index
 *   0x28e0f8 beq 0x28e314           no timelines -> next slot
 *   --- timeline loop: head 0x28e0fc, advance 0x28e2ec/0x28e30c ---
 *   0x28e0fc..0x28e108              getAttachment(skin, index, tlNode->name)
 *   0x28e10c subs r8,r0,#0
 *   0x28e110 beq 0x28e55c           NULL -> E4 (OUT OF SCOPE -> handoff)
 *   0x28e114..0x28e124              weighted flag from attachment->bones
 *   0x28e128..0x28e140              floatCount
 *   0x28e144 lsl r2,r11,#2          size = floatCount*4
 *   0x28e14c..0x28e154              _malloc(size, tag, 388)
 *   0x28e158 mov r1,r11
 *   0x28e160 ldr r0,[r9,#0xc]       declared frame count
 *   0x28e164 bl spDeformTimeline_create(count, floatCount)
 *   0x28e16c..0x28e17c              +0x1c = slotIndex, +0x20 = attachment
 *   0x28e180 beq 0x28e2c4           no frames -> free + tail
 *   (frame loop)
 *   0x28e2c4..0x28e2c8              _free(buffer)
 *   0x28e2cc..0x28e308              publish: count++, timelines[count] =
 *                                   timeline, last = frames[declared-1] with a
 *                                   ONE-float stride (r2,lsl#2 / [r3,#-4]),
 *                                   duration = max(duration,last)
 *   0x28e2ec ldr r9,[r9]            next timeline node
 *   0x28e30c bne 0x28e0fc
 *   0x28e310 ldr r11,[sp,#0x5c]
 *   0x28e314 ldr r11,[r11]          next slot
 *   0x28e31c bne 0x28e0dc
 *   0x28e320..0x28e330              skinNode = *skinNode; bne 0x28e0b4
 *   0x28e334 mov r11,r10            restore animation; fall into 0x28e338
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_deformTimelines(Json* deform_map, void* data_raw,
                                 void* animation_raw, void* parser_raw)
{
    spAnimationDeformShape* animation = (spAnimationDeformShape*)animation_raw;
    Json* skinNode;

    if (deform_map == 0)                               /* 0x28e060..0x28e068 */
        return DEFORM_TL_REACHED_DRAWORDER;            /* 0x28e068 beq 0x28e338 */

    skinNode = deform_map->child;                      /* 0x28e06c..0x28e070 */
    if (skinNode == 0)                                 /* 0x28e074 cmp */
        return DEFORM_TL_REACHED_DRAWORDER;            /* 0x28e07c beq 0x28e338 */

    while (skinNode != 0) {                            /* 0x28e0b4 / 0x28e330 bne */
        spSkin* skin = spSkeletonData_findSkin((spSkeletonData*)data_raw,
                                               skinNode->name);
                                                       /* 0x28e0b4..0x28e0c0 */
        Json* slotNode = skinNode->child;              /* 0x28e0c8 */

        if (slotNode != 0) {                           /* 0x28e0d8 beq 0x28e320 */
            do {
                int32_t slotIndex = spSkeletonData_findSlotIndex(
                    (spSkeletonData*)data_raw, slotNode->name);
                                                       /* 0x28e0dc..0x28e0e4 */
                Json* tlNode = slotNode->child;        /* 0x28e0e8 */

                if (tlNode != 0) {                     /* 0x28e0f8 beq 0x28e314 */
                    do {
                        const spVertexAttachmentDeformShape* attachment =
                            (const spVertexAttachmentDeformShape*)
                            spSkin_getAttachment(skin, (uint32_t)slotIndex,
                                                 tlNode->name);
                                                       /* 0x28e0fc..0x28e108 */
                        spDeformTimelineShape* timeline;
                        int32_t weighted;
                        int32_t floatCount;
                        float* buffer;

                        if (attachment == 0)
                            return DEFORM_TL_HANDOFF_ATTACHMENT;
                                                       /* 0x28e10c/0x28e110 -> E4 */
                        weighted = attachment->bones != 0 ? 1 : 0;
                                                       /* 0x28e114..0x28e124 */
                        floatCount = readSkeletonData_deformVertexFloatCount(
                            attachment);                   /* 0x28e128..0x28e140 */

                        buffer = (float*)_malloc((uint32_t)floatCount * 4u,
                                                 SKELETON_JSON_TAG,
                                                 DEFORM_MALLOC_LINE);
                                                       /* 0x28e144..0x28e154 */
                        timeline = (spDeformTimelineShape*)spDeformTimeline_create(
                            (int)tlNode->unk_0c, floatCount);
                                                       /* 0x28e158..0x28e164 */
                        timeline->slotIndex = slotIndex;   /* 0x28e178 */
                        timeline->attachment = (void*)attachment; /* 0x28e17c */

                        if (tlNode->child != 0)            /* 0x28e168..0x28e180 */
                            readSkeletonData_deformTimelineFrames(
                                tlNode, attachment, timeline, buffer,
                                floatCount, weighted, parser_raw);
                                                       /* 0x28e19c..0x28e2c0 */

                        _free(buffer);                     /* 0x28e2c4..0x28e2c8 */

                        {
                            int32_t count = animation->timelineCount;
                                                       /* 0x28e2cc ldr r3,[r10,#8] */
                            float duration = animation->duration;
                                                       /* 0x28e2d4 vldr s14,[r10,#4] */
                            void** timelines = animation->timelines;
                                                       /* 0x28e2d0 ldr r1,[r10,#0xc] */
                            uint32_t declared = tlNode->unk_0c;
                                                       /* 0x28e2e0 ldr r2,[r9,#0xc] */
                            float last;

                            animation->timelineCount = count + 1;  /* 0x28e2d8 */
                            timelines[count] = (void*)timeline;    /* 0x28e2e4 */
                            last = timeline->frames[declared - 1u];
                                                       /* 0x28e2e8..0x28e2f4 */
                            animation->duration =
                                (duration > last) ? duration : last;
                                                       /* 0x28e2f8..0x28e308 */
                        }

                        tlNode = tlNode->next;             /* 0x28e2ec ldr r9,[r9] */
                    } while (tlNode != 0);                 /* 0x28e30c bne */
                }

                slotNode = slotNode->next;                 /* 0x28e310..0x28e314 */
            } while (slotNode != 0);                       /* 0x28e31c bne */
        }

        skinNode = skinNode->next;                         /* 0x28e320..0x28e330 */
    }

    return DEFORM_TL_REACHED_DRAWORDER;                    /* 0x28e334 -> 0x28e338 */
}

/*
 * ---------------------------------------------------------------------------
 * E6, 0x28e8ac..0x28e8ec plus the shared tail 0x28da44..0x28da50.
 * Read per block: dispose ANIMATION FIRST (0x28e8bc), then read the failing
 * slot name with Json_getString from the offsets element (0x28e8c4..0x28e8cc),
 * then setError with the json argument = NULL (0x28e8d4 mov r1,#0) — this is
 * the NULL form of the three json-argument shapes (root / NULL / animation
 * node).  Only then is the skeleton data disposed by the shared tail.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_drawOrderSlotNotFound(Json* offsetsNode, void* data_raw,
                                       void* animation_raw, void* parser_raw)
{
    const char* name;

    spAnimation_dispose((spAnimation*)animation_raw);      /* 0x28e8b8..0x28e8bc */
    name = Json_getString(offsetsNode, "slot", 0);         /* 0x28e8c4..0x28e8cc */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             0,                            /* 0x28e8d4 mov r1,#0 */
                             ERR_SLOT_NOT_FOUND,           /* 0x28e8d0/0x28e8d8 */
                             name);                        /* 0x28e8e4 */
    spSkeletonData_dispose((spSkeletonData*)data_raw);     /* 0x28da48 */
    return 0;                                              /* 0x28da4c..0x28da50 */
}
