/*
 * _readVertices — original static helper 0x28b3fc..0x28b670, ARM.
 * 0x28b670..0x28b680 is a four-word literal pool, not four instructions.
 * tier: bytecode_anchored; source SHA and remaining gaps: ../functions.json.
 *
 * Preserve 32-bit wrapping index arithmetic, signed branch comparisons,
 * binary32 VFP conversion/multiply and allocator-visible field ordering.
 * VFP primitives deliberately execute the target instructions: a C cast of
 * NaN/out-of-range floats would be undefined, and host double is not a model.
 * No original machine code is executed by this reconstructed source.
 */
#include "spine_read_vertices.h"

static const char tag[] =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

static int32_t s32(uint32_t v) {
    int32_t r;
    __builtin_memcpy(&r, &v, 4);
    return r;
}
static void *at(const void *p, uint32_t index) {
    return (void *)(uintptr_t)((uint32_t)(uintptr_t)p + (index << 2));
}
static float load_f32(const void *p) {
    float f;
    __asm__ volatile("vldr %0, [%1]" : "=t"(f) : "r"(p) : "memory");
    return f;
}
static uint32_t cvt_i32(float f) {
    float raw;
    uint32_t bits;
    __asm__ volatile("vcvt.s32.f32 %0, %1" : "=t"(raw) : "t"(f) : "memory");
    __builtin_memcpy(&bits, &raw, 4);
    return bits;
}
/* Keep the compare even when count <= 0. A plain C && can let Clang
 * drop/reorder the comparison and lose sNaN's FPSCR invalid flag. */
static int scale_equal_one(float scale) {
    uint32_t fpscr;
    float one = 1.0f;
    __asm__ volatile("vcmp.f32 %1, %2\n\tvmrs %0, fpscr"
                     : "=r"(fpscr) : "t"(scale), "t"(one) : "cc", "memory");
    return (fpscr & 0x40000000u) != 0;
}
static float mul_f32(float x, float scale) {
    float r;
    __asm__ volatile("vmul.f32 %0, %1, %2" : "=t"(r) : "t"(x), "t"(scale) : "memory");
    return r;
}

void _readVertices(const void *json, Json *attachmentMap,
                   spVertexAttachment *attachment, uint32_t verticesCount) {
    volatile spVertexAttachment *a = attachment;
    /* @0x28b414 str r3,[r9,#0x20] — before lookup and first allocation. */
    a->worldVerticesLength = verticesCount;
    Json *array = Json_getItem(attachmentMap, "vertices"); /* 0x28b420 */
    uint32_t size = array->unk_0c; /* 0x28b430; array size is a snapshot. */
    float *values = _malloc(size << 2, tag, 513u); /* 0x28b43c */
    /* 0x28b440..464: walk child->next, NOT a size-bounded copy. Read child
     * after allocation, because a configured allocator may change the tree. */
    uint32_t j = 0;
    Json *child = array->child;
    while (child) {
        float value;
        __builtin_memcpy(&value, &child->float_value, 4); /* 0x28b454 */
        Json *next = child->next; /* 0x28b458, BEFORE output store. */
        __builtin_memcpy(at(values, j++), &value, 4); /* 0x28b460 */
        child = next;
    }

    if (verticesCount == size) { /* 0x28b468..46c; sole unweighted gate. */
        float scale = load_f32(json); /* 0x28b5e4; read even for size zero. */
        if (!scale_equal_one(scale) && s32(verticesCount) > 0) {
            uint32_t i = 0;
            do {
                float x = load_f32(at(values, i));
                *(float *)at(values, i) = mul_f32(x, scale); /* 0x28b610 */
                ++i;
                if (i == verticesCount) break;
                scale = load_f32(json); /* 0x28b608; no permanent caching. */
            } while (1);
        }
        /* 0x28b624..630: values ownership transferred, no temporary free. */
        a->opaque_18 = verticesCount;
        a->owned_1c = values;
        a->opaque_10 = 0;
        a->owned_14 = 0;
        return;
    }

    /* 0x28b474..47c: zero in this order, even for nonpositive array size. */
    a->opaque_18 = 0;
    a->opaque_10 = 0;
    uint32_t boneWords = 0, floatWords = 0;
    if (s32(size) > 0) {
        uint32_t i = 0;
        do {
            uint32_t count = cvt_i32(load_f32(at(values, i))); /* 0x28b498 */
            i = i + (count << 2) + 1u; /* 0x28b4a0..4a8, wraps as ARM32. */
            boneWords += count + 1u;
            floatWords += count * 3u;
        } while (s32(size) > s32(i)); /* 0x28b4b0/4bc */
        a->opaque_10 = boneWords; /* 0x28b4c8 */
        a->opaque_18 = floatWords; /* 0x28b4d4 */
    }
    float *vertices = _malloc(floatWords << 2, tag, 537u); /* 4dc or 64c */
    /* 0x28b4e0/650 reload count AFTER first allocator, BEFORE storing ptr. */
    uint32_t reloadedBoneWords = a->opaque_10;
    a->owned_1c = vertices; /* 0x28b4ec/65c */
    int32_t *bones = _malloc(reloadedBoneWords << 2, tag, 538u); /* 4f4/664 */
    a->owned_14 = bones; /* 0x28b508/668 */

    if (s32(size) > 0) {
        uint32_t i = 0, boneIndex = 0, vertexIndex = 0;
        do {
            float *row = at(values, i); /* 0x28b50c */
            uint32_t count = cvt_i32(load_f32(row));
            uint32_t cursor = i + 1u;
            uint32_t boneNext = boneIndex + 1u;
            int32_t *boneOut = at(bones, boneIndex);
            uint32_t end = cursor + (count << 2);
            *boneOut = s32(count); /* 0x28b52c */
            if (s32(cursor) < s32(end)) {
                float *out = at(a->owned_1c, vertexIndex); /* 0x28b538 */
                do {
                    /* Original x multiply precedes index conversion; y gets
                     * a distinct scale reload. Weight is a raw word copy. */
                    float xInput = load_f32(at(row, 2));
                    float xScale = load_f32(json);
                    float x = mul_f32(xInput, xScale);
                    uint32_t index = cvt_i32(load_f32(at(row, 1)));
                    cursor += 4u;
                    boneOut = at(boneOut, 1);
                    *boneOut = s32(index); /* 0x28b564 */
                    out[0] = x;
                    float yInput = load_f32(at(row, 3));
                    float yScale = load_f32(json);
                    out[1] = mul_f32(yInput, yScale);
                    __builtin_memcpy(out + 2, at(row, 4), 4); /* 0x28b57c/580 */
                    row = at(row, 4);
                    out += 3;
                } while (s32(end) > s32(cursor));
                /* Exact unsigned post-loop formula 0x28b588..5b4. This is
                 * NOT an arithmetic-right shift or a second count cast. */
                uint32_t extra = (end - i - 2u) >> 2;
                boneIndex = boneNext + 1u + extra;
                vertexIndex += 3u + 3u * extra;
                i += 5u + (extra << 2);
            } else {
                /* 0x28b5d4..5dc: zero/nonpositive group consumes one word. */
                i = cursor;
                boneIndex = boneNext;
            }
        } while (s32(size) > s32(i));
    }
    _free(values); /* 0x28b5c4..5d0: weighted only, after both allocations. */
}
