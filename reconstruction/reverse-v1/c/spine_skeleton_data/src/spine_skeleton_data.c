/* Static C translation of spine data ownership and cleanup, ARM32 only.
 * Original image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. No original execution or whole-library closure claim.
 * Scalar slots retain neutral names; names of unknown fields are not invented.
 * Library-internal virtual callback implementations remain explicit dependencies. */
#include "spine_skeleton_data.h"

typedef uint32_t yy_alias_u32 __attribute__((may_alias));
static uint32_t rd(const void *p, uint32_t off)
{ return *(const volatile yy_alias_u32 *)((const unsigned char *)p+off); }
static void *at(uint32_t p) { return (void *)(uintptr_t)p; }
static uint32_t element(const void *p, uint32_t off, uint32_t i)
{
    /* ARM ldr [r3,r5,lsl#2]: both shift and address add are 32-bit. */
    uint32_t address=rd(p,off)+i*4u;
    return rd(at(address),0);
}

/* 0x28addc/28B: six instructions and one 4-byte literal, NOT seven instructions.
 * @0x28ade4 mov r1,#84; @0x28ade8 mov r3,#37; @0x28adf0 b _calloc.
 * add@28adec + original literal@28adf4 resolves to bytes at 0x357ab0. */
spSkeletonData *spSkeletonData_create(void)
{
    static const char tag[]="jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonData.c";
    return (spSkeletonData *)_calloc(1,84,tag,37);
}

/* This macro is source factoring only. Each expansion is a distinct original
 * loop. Never cache count/table across the callee, or table across final free. */
#define DISPOSE_VECTOR(SELF, COUNT, ARRAY, TYPE, FN) do { \
    if ((int32_t)rd((SELF),(COUNT))>0) { \
        uint32_t i=0; \
        do { \
            TYPE *item=(TYPE *)at(element((SELF),(ARRAY),i)); \
            ++i; \
            FN(item); \
        } while ((int32_t)rd((SELF),(COUNT))>(int32_t)i); \
    } \
    _free(at(rd((SELF),(ARRAY)))); \
} while (0)

/* 0x28adf8/452B: complete eight-vector control flow and tail.
 * Counts are signed. Nonpositive count skips elements but still frees the table.
 * Every iteration reloads its table, and every backedge reloads count after call.
 * No NULL-self check; no field zeroing. +8,+0xc,+0x28 are NOT released here. */
void spSkeletonData_dispose(spSkeletonData *self)
{
    DISPOSE_VECTOR(self,0x10,0x14,spBoneData,spBoneData_dispose); /* 28ae00..28ae30 */
    DISPOSE_VECTOR(self,0x18,0x1c,spSlotData,spSlotData_dispose); /* 28ae34..28ae64 */
    DISPOSE_VECTOR(self,0x20,0x24,spSkin,spSkin_dispose); /* 28ae68..28ae98 */
    DISPOSE_VECTOR(self,0x2c,0x30,spEventData,spEventData_dispose); /* 28ae9c..28aecc */
    DISPOSE_VECTOR(self,0x34,0x38,spAnimation,spAnimation_dispose); /* 28aed0..28af00 */
    DISPOSE_VECTOR(self,0x3c,0x40,spIkConstraintData,spIkConstraintData_dispose); /* 28af04..28af34 */
    DISPOSE_VECTOR(self,0x44,0x48,spTransformConstraintData,spTransformConstraintData_dispose); /* 28af38..28af68 */
    DISPOSE_VECTOR(self,0x4c,0x50,spPathConstraintData,spPathConstraintData_dispose); /* 28af6c..28af9c */
    _free(at(rd(self,4))); /* 28afa0..28afa4 */
    _free(at(rd(self,0))); /* 28afa8..28afac: reload after preceding free */
    _free(self);          /* 28afb0..28afb8 */
}

/* 0x285ac4/28B. */
void spBoneData_dispose(spBoneData *self)
{
    _free(at(rd(self,4))); /* 285acc..285ad0 */
    _free(self);          /* 285ad4..285adc */
}
/* 0x28efa8/36B. Do not prefetch +0xc before the first free. */
void spSlotData_dispose(spSlotData *self)
{
    _free(at(rd(self,4)));   /* 28efb0..28efb4 */
    _free(at(rd(self,0xc))); /* 28efb8..28efbc */
    _free(self);            /* 28efc0..28efc8 */
}
/* 0x285bec/36B. */
void spEventData_dispose(spEventData *self)
{
    _free(at(rd(self,0xc))); /* 285bf4..285bf8 */
    _free(at(rd(self,0)));   /* 285bfc..285c00 */
    _free(self);            /* 285c04..285c0c */
}
/* 0x286758/36B. */
void spIkConstraintData_dispose(spIkConstraintData *self)
{
    _free(at(rd(self,0))); /* 286760..286764 */
    _free(at(rd(self,8))); /* 286768..28676c */
    _free(self);          /* 286770..286778 */
}
/* 0x28f608/36B. */
void spTransformConstraintData_dispose(spTransformConstraintData *self)
{
    _free(at(rd(self,0))); /* 28f610..28f614 */
    _free(at(rd(self,8))); /* 28f618..28f61c */
    _free(self);          /* 28f620..28f628 */
}
/* 0x288f34/36B. */
void spPathConstraintData_dispose(spPathConstraintData *self)
{
    _free(at(rd(self,0))); /* 288f3c..288f40 */
    _free(at(rd(self,8))); /* 288f44..288f48 */
    _free(self);          /* 288f4c..288f54 */
}
/* 0x281468/20B: the callback owns cleanup; no unconditional free follows. */
void spTimeline_dispose(spTimeline *self)
{
    typedef void (*dispose_fn)(spTimeline *);
    dispose_fn fn=(dispose_fn)(uintptr_t)rd(at(rd(self,4)),4); /* 28146c..281470 */
    fn(self); /* 281474 blx r3 */
}
/* 0x284cb4/20B: a different object/table offset from timeline. */
void spAttachment_dispose(spAttachment *self)
{
    typedef void (*dispose_fn)(spAttachment *);
    dispose_fn fn=(dispose_fn)(uintptr_t)rd(at(rd(self,8)),0); /* 284cb8..284cbc */
    fn(self); /* 284cc0 blx r3 */
}
/* 0x28ec20/36B: attachment callback, then re-read name, then entry itself. */
void _Entry_dispose(void *self)
{
    spAttachment_dispose((spAttachment *)at(rd(self,8))); /* 28ec28..28ec2c */
    _free(at(rd(self,4))); /* 28ec30..28ec34 */
    _free(self);          /* 28ec38..28ec40 */
}
/* 0x28ec9c/60B: next captured before entry callback/free. */
void spSkin_dispose(spSkin *self)
{
    uint32_t node=rd(self,4); /* 28eca4 */
    while (node) {
        uint32_t next=rd(at(node),0xc); /* 28ecb0 */
        _Entry_dispose(at(node));      /* 28ecb4 */
        node=next;                    /* 28ecb8..28ecc0 */
    }
    _free(at(rd(self,0))); /* 28ecc4..28ecc8: after all callbacks */
    _free(self);          /* 28eccc..28ecd4 */
}
/* 0x28147c/80B: signed-count, reloaded timeline table and count. */
void spAnimation_dispose(spAnimation *self)
{
    DISPOSE_VECTOR(self,8,0xc,spTimeline,spTimeline_dispose); /* 281484..2814b4 */
    _free(at(rd(self,0))); /* 2814b8..2814bc */
    _free(self);          /* 2814c0..2814c8 */
}
#undef DISPOSE_VECTOR
