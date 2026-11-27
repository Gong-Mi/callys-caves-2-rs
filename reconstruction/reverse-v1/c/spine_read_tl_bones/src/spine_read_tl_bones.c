/*
 * spine_read_tl_bones.c — the bones timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B6    0x28d640..0x28d740   64 insns  bones loop + findBoneIndex + dispatch
 *   B6b   0x28d740..0x28d840   64 insns  translate/scale/shear frames + tail
 *   B9    0x28da54..0x28da74    8 insns  translate select (s16 = parser->scale)
 *   B10   0x28da74..0x28db48   53 insns  rotate frames (time + angle) + tail
 *   B11   0x28db48..0x28db5c    5 insns  scale select (s16 = 1.0)
 *   B11b  0x28dbb4..0x28dbc4    4 insns  shear select (s16 = 1.0)
 *   E2    0x28db5c..0x28db88   11 insns  "Bone not found: "
 *   E3    0x28db88..0x28dbb4   11 insns  "Invalid timeline type for a bone: "
 *
 * Evidence tier: bytecode_anchored; original never executed.  Keys, field
 * offsets and the three error arguments were read from the instruction stream
 * (census §2.4/§5.3/§5.4) and cross-checked against the resolved pc-relative
 * literal pool words; no stock spine-c source was consulted.
 */

#include "spine_read_tl_bones.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */
#include "../../spine_json_error/src/spine_json_error.h"   /* _spSkeletonJson_setError */

/* 0x357eb4 — exact literal, trailing space included (pool word 0x28ea90
 * resolved by the add at 0x28db7c: pc 0x28db84 + 0x000ca330). */
static const char* const ERR_BONE_NOT_FOUND = "Bone not found: ";

/* 0x357eec — exact literal (pool word 0x28ea94 resolved by the add at
 * 0x28dba8: pc 0x28dbb0 + 0x000ca33c). */
static const char* const ERR_INVALID_BONE_TIMELINE =
    "Invalid timeline type for a bone: ";

/* Word load with the original `ldr` semantics; used for the bone table where
 * the pointer comes out of a stored 32-bit word (no C object type to lean on). */
static uint32_t load_word(uint32_t address)
{
    uint32_t value;
    __asm__ volatile("ldr %0,[%1]" : "=r"(value) : "r"(address) : "memory");
    return value;
}

/*
 * ---------------------------------------------------------------------------
 * spSkeletonData_findBoneIndex — 0x28b018..0x28b06c (88 B, 21 insns).
 * Recovered here because no other module owns this .dynsym symbol.
 *
 *   0x28b018 push {r3,r4,r5,r6,r7,lr}
 *   0x28b01c mov  r7,r1              name
 *   0x28b020 ldr  r6,[r0,#0x10]      count = data->bonesCount
 *   0x28b024 cmp  r6,#0
 *   0x28b028 ble  0x28b068           signed <= 0 -> miss
 *   0x28b02c ldr  r5,[r0,#0x14]      table = data->bones
 *   0x28b030 mov  r4,#0              i = 0
 *   0x28b034 sub  r5,r5,#4           pre-index base
 *   0x28b038 b    0x28b048
 *   0x28b03c add  r4,r4,#1           ++i
 *   0x28b040 cmp  r4,r6
 *   0x28b044 beq  0x28b068           i == count -> miss
 *   0x28b048 ldr  r3,[r5,#0x4]!      bone = table[i]
 *   0x28b04c mov  r1,r7              name
 *   0x28b050 ldr  r0,[r3,#0x4]       bone->name (+0x04)
 *   0x28b054 bl   strcmp@plt
 *   0x28b058 cmp  r0,#0
 *   0x28b05c bne  0x28b03c
 *   0x28b060 mov  r0,r4              return i (FIRST match wins)
 *   0x28b064 pop  {r3,r4,r5,r6,r7,pc}
 *   0x28b068 mvn  r0,#0              return -1
 * ---------------------------------------------------------------------------
 */
int
spSkeletonData_findBoneIndex(spSkeletonData* data, const char* name)
{
    int32_t count = (int32_t)data->words[4];        /* 0x28b020 */
    uint32_t table;
    int32_t i = 0;
    uint32_t bone;

    if (count <= 0)                                 /* 0x28b024 / 0x28b028 */
        return -1;
    table = data->words[5];                         /* 0x28b02c */
    do {
        bone = load_word(table + (uint32_t)i * 4u); /* 0x28b048 */
        if (strcmp((const char*)(uintptr_t)load_word(bone + 4u), name) == 0)
            return i;                               /* 0x28b050..0x28b060 */
        ++i;                                        /* 0x28b03c */
    } while (i != count);                           /* 0x28b040 / 0x28b044 */
    return -1;                                      /* 0x28b068 */
}

/*
 * ---------------------------------------------------------------------------
 * B6b, 0x28d740..0x28d840 — shared translate/scale/shear frame loop + tail.
 *
 *   0x28d740 ldr  r6,[r7,#0x4]        frame = timelineJson->child
 *   0x28d744 str  r8,[r4,#0x14]       timeline->boneIndex = boneIndex
 *   0x28d748 cmp  r6,#0
 *   0x28d74c beq  0x28d7e4            no frames -> tail
 *   0x28d750 ldr  r10,[pc,#-0xd18]    pool 0x28ca40 -> 0x33087c "x"
 *   0x28d754 mov  r5,#0               frameIndex = 0
 *   0x28d758 ldr  r3,[pc,#-0xd1c]     pool 0x28ca44 -> 0x330880 "y"
 *   0x28d75c add  r10,pc,r10
 *   0x28d760 add  r3,pc,r3
 *   0x28d764 str  r3,[sp,#0x2c]       "y" spilled
 *
 *   0x28d768 mov  r0,r6               frame
 *   0x28d76c ldr  r1,[sp,#0x30]       "time"
 *   0x28d770 mov  r2,#0
 *   0x28d774 bl   Json_getFloat       time
 *   0x28d778 mov  r1,r10              "x"
 *   0x28d77c mov  r2,#0
 *   0x28d780 mov  r9,r0               time bits saved
 *   0x28d784 mov  r0,r6
 *   0x28d788 bl   Json_getFloat       x
 *   0x28d78c ldr  r1,[sp,#0x2c]       "y"
 *   0x28d790 mov  r2,#0
 *   0x28d794 vmov s14,r0              s14 = x
 *   0x28d798 mov  r0,r6
 *   0x28d79c vmul.f32 s17,s14,s16     s17 = x * s16
 *   0x28d7a0 bl   Json_getFloat       y
 *   0x28d7a4 mov  r1,r5               frameIndex
 *   0x28d7a8 mov  r2,r9               time
 *   0x28d7ac vmov r3,s17              arg4 = x*s16
 *   0x28d7b0 vmov s14,r0              s14 = y
 *   0x28d7b4 mov  r0,r4               timeline
 *   0x28d7b8 vmul.f32 s15,s16,s14     s15 = s16 * y   (operand order kept)
 *   0x28d7bc vstr s15,[sp]            arg5 = y*s16
 *   0x28d7c0 bl   spTranslateTimeline_setFrame   <-- one call site for all 3
 *   0x28d7c4 mov  r0,r6
 *   0x28d7c8 mov  r2,r5
 *   0x28d7cc mov  r1,r4
 *   0x28d7d0 bl   readCurve           (frame, timeline, frameIndex)
 *   0x28d7d4 ldr  r6,[r6]             frame = frame->next
 *   0x28d7d8 add  r5,r5,#1
 *   0x28d7dc cmp  r6,#0
 *   0x28d7e0 bne  0x28d768
 *
 * Tail:
 *   0x28d7e4 ldr  r2,[r7,#0xc]        declared frame count (Json +0x0c)
 *   0x28d7e8 vldr s14,[r11,#4]        duration
 *   0x28d7ec ldr  r3,[r11,#0x8]       timelineCount
 *   0x28d7f0 ldr  r1,[r11,#0xc]       timelines
 *   0x28d7f4 sub  r2,r2,#1            declared-1
 *   0x28d7f8 add  r0,r3,#1
 *   0x28d7fc str  r0,[r11,#0x8]       timelineCount = count+1
 *   0x28d800 add  r2,r2,r2,lsl#1      (declared-1)*3   three-float stride
 *   0x28d804 str  r4,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28d808 ldr  r3,[r4,#0x10]       frames
 *   0x28d80c add  r3,r3,r2,lsl#2      &frames[(declared-1)*3]
 *   0x28d810 vldr s15,[r3]
 *   0x28d814..0x28d81c               vcmpe.f32 + vmovgt.f32: max()
 *   0x28d820 vstr s15,[r11,#4]        duration
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_boneXYTimeline(Json* timelineJson, void* animation_raw,
                                int boneIndex, float coordScale,
                                void* timeline_raw)
{
    spAnimationShape* animation = (spAnimationShape*)animation_raw;
    spBoneTimelineShape* timeline = (spBoneTimelineShape*)timeline_raw;
    Json* frame = timelineJson->child;                 /* 0x28d740 */

    timeline->boneIndex = boneIndex;                   /* 0x28d744 */
    if (frame != 0) {                                  /* 0x28d748 / 0x28d74c */
        int frameIndex = 0;                            /* 0x28d754 mov r5,#0 */
        do {
            float time = Json_getFloat(frame, "time", 0.0f);   /* 0x28d768..0x28d774 */
            float x = Json_getFloat(frame, "x", 0.0f);         /* 0x28d778..0x28d788 */
            float y = Json_getFloat(frame, "y", 0.0f);         /* 0x28d78c..0x28d7a0 */

            /* 0x28d79c s17 = x*s16 ; 0x28d7b8 s15 = s16*y.
             * softfp passes the bits in r3 / [sp] exactly like vmov+vstr. */
            spTranslateTimeline_setFrame(timeline, frameIndex, time,
                                         x * coordScale, coordScale * y);
                                                       /* 0x28d7a4..0x28d7c0 */
            readCurve(frame, timeline, frameIndex);    /* 0x28d7c4..0x28d7d0 */
            frame = frame->next;                       /* 0x28d7d4 */
            ++frameIndex;                              /* 0x28d7d8 */
        } while (frame != 0);                          /* 0x28d7dc / 0x28d7e0 */
    }

    /* 0x28d7e4..0x28d820: publish and extend the animation duration,
     * three floats per frame. */
    {
        uint32_t declared = timelineJson->unk_0c;          /* 0x28d7e4 */
        float duration = animation->duration;              /* 0x28d7e8 */
        int32_t count = animation->timelineCount;          /* 0x28d7ec */
        void** timelines = animation->timelines;           /* 0x28d7f0 */
        uint32_t word_index = (declared - 1u) * 3u;        /* 0x28d7f4 / 0x28d800 */
        float last;

        animation->timelineCount = count + 1;              /* 0x28d7f8 / 0x28d7fc */
        timelines[count] = (void*)timeline;                /* 0x28d804 */
        last = timeline->frames[word_index];               /* 0x28d808..0x28d810 */
        animation->duration = (duration > last) ? duration : last;
                                                           /* 0x28d814..0x28d820 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * B10, 0x28da74..0x28db48 — rotate timeline.
 *
 *   0x28da74 ldr  r0,[r7,#0xc]        frameCount = timelineJson->unk_0c
 *   0x28da78 bl   spRotateTimeline_create
 *   0x28da7c ldr  r4,[r7,#0x4]        frame = timelineJson->child
 *   0x28da80 cmp  r4,#0
 *   0x28da84 mov  r5,r0               timeline
 *   0x28da88 str  r8,[r0,#0x14]       boneIndex
 *   0x28da8c beq  0x28db0c            no frames -> tail
 *   0x28da90 ldr  r6,[pc,#0xff0]      pool 0x28ea88 -> 0x34c1d4 "time"
 *   0x28da94 mov  r12,r7              timelineJson saved
 *   0x28da98 ldr  r10,[pc,#0xfec]     pool 0x28ea8c -> 0x330884 "angle"
 *   0x28da9c add  r6,pc,r6
 *   0x28daa0 add  r10,pc,r10
 *   0x28daa4 mov  r7,r6               r7 = "time" inside the loop
 *
 *   0x28daa8 mov  r0,r4
 *   0x28daac mov  r1,r7               "time"
 *   0x28dab0 mov  r2,#0
 *   0x28dab4 str  r12,[sp,#0x14]      timelineJson re-spilled
 *   0x28dab8 bl   Json_getFloat
 *   0x28dabc mov  r1,r10              "angle"
 *   0x28dac0 mov  r2,#0
 *   0x28dac4 mov  r6,r0               time bits
 *   0x28dac8 mov  r0,r4
 *   0x28dacc bl   Json_getFloat       angle
 *   0x28dad0 mov  r1,r9               frameIndex
 *   0x28dad4 mov  r2,r6               time
 *   0x28dad8 mov  r3,r0               angle
 *   0x28dadc mov  r0,r5               timeline
 *   0x28dae0 bl   spRotateTimeline_setFrame
 *   0x28dae4 mov  r0,r4
 *   0x28dae8 mov  r2,r9
 *   0x28daec mov  r1,r5
 *   0x28daf0 bl   readCurve
 *   0x28daf4 ldr  r4,[r4]             next frame
 *   0x28daf8 add  r9,r9,#1
 *   0x28dafc ldr  r12,[sp,#0x14]
 *   0x28db00 cmp  r4,#0
 *   0x28db04 bne  0x28daa8
 *   0x28db08 mov  r7,r12              timelineJson restored
 *
 * Tail (rotate stride is TWO floats, and the address is declared*2-2):
 *   0x28db0c ldr  r3,[r11,#0x8]       timelineCount
 *   0x28db10 vldr s14,[r11,#4]        duration
 *   0x28db14 ldr  r1,[r11,#0xc]       timelines
 *   0x28db18 add  r2,r3,#1
 *   0x28db1c str  r2,[r11,#0x8]
 *   0x28db20 ldr  r2,[r7,#0xc]        declared
 *   0x28db24 str  r5,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28db28 ldr  r3,[r5,#0x10]       frames
 *   0x28db2c add  r3,r3,r2,lsl#3      &frames[declared*2]
 *   0x28db30 vldr s15,[r3,#-8]        frames[(declared-1)*2]
 *   0x28db34..0x28db40               max() -> duration
 *   0x28db44 b    0x28d824            rejoin the shared timeline loop
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_boneRotateTimeline(Json* timelineJson, void* animation_raw,
                                    int boneIndex)
{
    spAnimationShape* animation = (spAnimationShape*)animation_raw;
    spBoneTimelineShape* timeline;
    Json* frame;
    /* The dispatch left r9 == 0 (0x28d6d0 `subs r9,r0,#0`, rotate branch taken
     * on r0 == 0); there is no explicit clear inside B10. */
    int frameIndex = 0;

    timeline = (spBoneTimelineShape*)spRotateTimeline_create((int)timelineJson->unk_0c);
                                                       /* 0x28da74 / 0x28da78 */
    frame = timelineJson->child;                       /* 0x28da7c */
    timeline->boneIndex = boneIndex;                   /* 0x28da88 */

    if (frame != 0) {                                  /* 0x28da80 / 0x28da8c */
        do {
            float time = Json_getFloat(frame, "time", 0.0f);   /* 0x28daa8..0x28dab8 */
            float angle = Json_getFloat(frame, "angle", 0.0f); /* 0x28dabc..0x28dacc */

            spRotateTimeline_setFrame(timeline, frameIndex, time, angle);
                                                       /* 0x28dad0..0x28dae0 */
            readCurve(frame, timeline, frameIndex);    /* 0x28dae4..0x28daf0 */
            frame = frame->next;                       /* 0x28daf4 */
            ++frameIndex;                              /* 0x28daf8 */
        } while (frame != 0);                          /* 0x28db00 / 0x28db04 */
    }

    /* 0x28db0c..0x28db40: publish, two floats per frame. */
    {
        int32_t count = animation->timelineCount;          /* 0x28db0c */
        float duration = animation->duration;              /* 0x28db10 */
        void** timelines = animation->timelines;           /* 0x28db14 */
        uint32_t declared = timelineJson->unk_0c;          /* 0x28db20 */
        float last;

        animation->timelineCount = count + 1;              /* 0x28db18 / 0x28db1c */
        timelines[count] = (void*)timeline;                /* 0x28db24 */
        last = timeline->frames[declared * 2u - 2u];       /* 0x28db28..0x28db30 */
        animation->duration = (duration > last) ? duration : last;
                                                           /* 0x28db34..0x28db40 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * E2, 0x28db5c..0x28db88 (+ the shared tail 0x28da44..0x28da50).
 *
 *   0x28db5c ldr  r8,[sp,#0x20]       parser
 *   0x28db60 mov  r0,r11              animation
 *   0x28db64 ldr  r9,[sp,#0x18]       data
 *   0x28db68 bl   spAnimation_dispose
 *   0x28db6c ldr  r2,[pc,#0xf1c]      pool 0x28ea90 -> 0x357eb4 "Bone not found: "
 *   0x28db70 mov  r0,r8               parser
 *   0x28db74 ldr  r1,[sp,#0x1c]       <-- json arg = CURRENT ANIMATION NODE
 *   0x28db78 ldr  r3,[r6,#0x1c]       extra = boneNode->name
 *   0x28db7c add  r2,pc,r2
 *   0x28db80 bl   _spSkeletonJson_setError
 *   0x28db84 b    0x28da44            common tail
 *   0x28da44 mov  r0,r9 ; 0x28da48 bl spSkeletonData_dispose
 *   0x28da4c mov  r0,#0 ; 0x28da50 b 0x28bdcc
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_boneNotFound(Json* boneNode, Json* animationJson,
                              void* data_raw, void* animation_raw,
                              void* parser_raw)
{
    spAnimation_dispose((spAnimation*)animation_raw);              /* 0x28db68 */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             animationJson,                        /* 0x28db74 */
                             ERR_BONE_NOT_FOUND,                   /* 0x28db6c/0x28db7c */
                             boneNode->name);                      /* 0x28db78 */
    spSkeletonData_dispose((spSkeletonData*)data_raw);             /* 0x28da48 */
    return 0;                                                      /* 0x28da4c..0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * E3, 0x28db88..0x28dbb4 (+ the same tail).
 *
 *   0x28db88 ldr  r8,[sp,#0x20]       parser
 *   0x28db8c mov  r0,r11              animation
 *   0x28db90 ldr  r9,[sp,#0x18]       data
 *   0x28db94 bl   spAnimation_dispose
 *   0x28db98 ldr  r2,[pc,#0xef4]      pool 0x28ea94 -> 0x357eec
 *   0x28db9c mov  r1,r4               r4 == 0 (see below) -> json arg is NULL
 *   0x28dba0 mov  r0,r8
 *   0x28dba4 ldr  r3,[r7,#0x1c]       extra = timelineJson->name
 *   0x28dba8 add  r2,pc,r2
 *   0x28dbac bl   _spSkeletonJson_setError
 *   0x28dbb0 b    0x28da44
 *
 * r4 at this point is the OR of the four strcmp match flags:
 *   0x28d70c orr  r4,r9,r5
 *   0x28d718 orrs r4,r0,r4
 *   0x28d71c beq  0x28db88      (taken only when the OR is zero)
 * so the json argument is exactly NULL even though the register is not cleared.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_invalidTimelineTypeForBone(Json* timelineJson,
                                            void* data_raw,
                                            void* animation_raw,
                                            void* parser_raw)
{
    spAnimation_dispose((spAnimation*)animation_raw);              /* 0x28db94 */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             0,                                    /* 0x28db9c mov r1,r4, r4 == 0 */
                             ERR_INVALID_BONE_TIMELINE,            /* 0x28db98/0x28dba8 */
                             timelineJson->name);                  /* 0x28dba4 */
    spSkeletonData_dispose((spSkeletonData*)data_raw);             /* 0x28da48 */
    return 0;                                                      /* 0x28da4c..0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * B6, 0x28d640..0x28d740 (+ the shared loops 0x28d824..0x28d83c).
 *
 *   0x28d640 ldr  r3,[sp,#0x30]       bones node
 *   0x28d644 cmp  r3,#0
 *   0x28d648 beq  0x28d840            absent -> ik block
 *   0x28d64c ldr  r0,[sp,#0x30]
 *   0x28d650 ldr  r6,[r0,#0x4]        boneNode = bones->child
 *   0x28d654 cmp  r6,#0
 *   0x28d658 beq  0x28d840            no children -> ik block
 *   0x28d65c..0x28d694                five key pointers cached:
 *        r1 -> [sp+0x3c] "rotate"    (pool 0x28ca2c -> 0x357ec8)
 *        r2 -> [sp+0x40] "scale"     (pool 0x28ca30 -> 0x357ed0)
 *        r3 -> [sp+0x48] "translate" (pool 0x28ca34 -> 0x357ed8)
 *        r0 -> [sp+0x54] "shear"     (pool 0x28ca38 -> 0x357ee4)
 *        r1 -> [sp+0x30] "time"      (pool 0x28ca3c -> 0x34c1d4)  ** overwrites
 *                                     the bones-node spill **
 *
 *   0x28d698 ldr  r0,[sp,#0x18]       data
 *   0x28d69c ldr  r1,[r6,#0x1c]       boneNode->name
 *   0x28d6a0 bl   spSkeletonData_findBoneIndex    <-- real .dynsym body
 *   0x28d6a4 cmn  r0,#1               -1 test
 *   0x28d6a8 mov  r8,r0               boneIndex
 *   0x28d6ac beq  0x28db5c            -> E2
 *   0x28d6b0 ldr  r7,[r6,#0x4]        timelineNode = boneNode->child
 *   0x28d6b4 cmp  r7,#0
 *   0x28d6b8 strne r6,[sp,#0x58]      spill the bone node (only if children)
 *   0x28d6bc beq  0x28d834            no timelines -> next bone
 *
 *   0x28d6c0 ldr  r4,[r7,#0x1c]       type = timelineNode->name
 *   0x28d6c4..0x28d6d0               strcmp(type,"rotate"); r9 = (result==0)
 *   0x28d6d4 beq  0x28da74            -> B10
 *   0x28d6d8..0x28d6e8               strcmp(type,"scale");   r5 = (result==0)
 *   0x28d6ec..0x28d6fc               strcmp(type,"translate"); r9 = (result==0)
 *   0x28d700..0x28d710               strcmp(type,"shear");   r0 = (result==0)
 *   0x28d70c orr  r4,r9,r5
 *   0x28d718 orrs r4,r0,r4
 *   0x28d71c beq  0x28db88            no match -> E3 (and r4 == 0 for E3)
 *   0x28d720 cmp  r9,#0 ; 0x28d724 bne 0x28da54   -> translate (B9)
 *   0x28d728 cmp  r5,#0 ; 0x28d72c bne 0x28db48   -> scale (B11)
 *   0x28d730 cmp  r0,#0 ; 0x28d734/0x28d738       vmov s16,#1.0 / r4 = 0
 *   0x28d73c bne  0x28dbb4                        -> shear (B11b)
 *   (the 0x28d730..0x28d73c fall-through into 0x28d740 is unreachable in the
 *    original: every matching type has already branched)
 *
 * Back edges:
 *   0x28d824 ldr  r7,[r7]             timelineNode = timelineNode->next
 *   0x28d828 cmp  r7,#0
 *   0x28d82c bne  0x28d6c0
 *   0x28d830 ldr  r6,[sp,#0x58]       restore the bone node (B10 clobbers r6)
 *   0x28d834 ldr  r6,[r6]             boneNode = boneNode->next
 *   0x28d838 cmp  r6,#0
 *   0x28d83c bne  0x28d698
 *   0x28d840                          ik block (out of scope)
 *
 * Selection blocks the dispatch jumps to:
 *   B9  0x28da54 cmp r5,#0 ; 0x28da58 ldr r2,[sp,#0x20] ;
 *       0x28da5c vldr s16,[r2]       s16 = parser->scale (binary32 at +0x00)
 *       0x28da60 bne 0x28db4c        (cannot happen here: scale took B11)
 *       0x28da64 ldr r0,[r7,#0xc] ; 0x28da68 bl spTranslateTimeline_create
 *       0x28da6c mov r4,r0 ; 0x28da70 b 0x28d740
 *   B11 0x28db48 vmov.f32 s16,#1.0 ; 0x28db4c ldr r0,[r7,#0xc] ;
 *       0x28db50 bl spScaleTimeline_create ; 0x28db54 mov r4,r0 ;
 *       0x28db58 b 0x28d740
 *   B11b 0x28dbb4 ldr r0,[r7,#0xc] ; 0x28dbb8 vmov.f32 s16,#1.0 ;
 *       0x28dbbc bl spShearTimeline_create ; 0x28dbc0 mov r4,r0 ;
 *       0x28dbc4 b 0x28d740
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_boneTimelines(Json* bonesJson, Json* animationJson,
                               void* data_raw, void* animation_raw,
                               void* parser_raw)
{
    spSkeletonData* data = (spSkeletonData*)data_raw;
    spSkeletonJson* parser = (spSkeletonJson*)parser_raw;
    Json* boneNode;

    if (bonesJson == 0)                                /* 0x28d640..0x28d648 */
        return 1;
    boneNode = bonesJson->child;                       /* 0x28d64c / 0x28d650 */
    if (boneNode == 0)                                 /* 0x28d654 / 0x28d658 */
        return 1;

    while (boneNode != 0) {                            /* 0x28d698 / 0x28d83c */
        int boneIndex = spSkeletonData_findBoneIndex(data, boneNode->name);
                                                       /* 0x28d698..0x28d6a0 */
        Json* timelineJson;

        if (boneIndex == -1)                           /* 0x28d6a4 / 0x28d6ac */
            return readSkeletonData_boneNotFound(boneNode, animationJson,
                                                 data, animation_raw, parser);

        timelineJson = boneNode->child;                /* 0x28d6b0 */
        if (timelineJson != 0) {                       /* 0x28d6b4 / 0x28d6bc */
            do {
                /* 0x28d6c0: the type text is the timeline node's JSON key */
                const char* type = timelineJson->name;

                /* The original performs all four strcmps unconditionally in
                 * this order (0x28d6cc/0x28d6e0/0x28d6f4/0x28d708) and then
                 * branches translate -> scale -> shear.  Since the four
                 * literals are distinct, the if-chain is equivalent. */
                if (strcmp(type, "rotate") == 0) {          /* 0x28d6c4..0x28d6d4 */
                    readSkeletonData_boneRotateTimeline(timelineJson,
                                                        animation_raw, boneIndex);
                } else if (strcmp(type, "scale") == 0) {    /* 0x28d6d8..0x28d6e8 */
                    /* B11: 0x28db48 s16 = 1.0 ; 0x28db50 create */
                    void* timeline = spScaleTimeline_create((int)timelineJson->unk_0c);
                    readSkeletonData_boneXYTimeline(timelineJson, animation_raw,
                                                    boneIndex, 1.0f, timeline);
                } else if (strcmp(type, "translate") == 0) { /* 0x28d6ec..0x28d6fc */
                    /* B9: 0x28da5c s16 = parser->scale ; 0x28da68 create */
                    float coord_scale = spSkeletonJson_scale_float(parser);
                    void* timeline = spTranslateTimeline_create((int)timelineJson->unk_0c);
                    readSkeletonData_boneXYTimeline(timelineJson, animation_raw,
                                                    boneIndex, coord_scale, timeline);
                } else if (strcmp(type, "shear") == 0) {     /* 0x28d700..0x28d710 */
                    /* B11b: 0x28dbb8 s16 = 1.0 ; 0x28dbbc create */
                    void* timeline = spShearTimeline_create((int)timelineJson->unk_0c);
                    readSkeletonData_boneXYTimeline(timelineJson, animation_raw,
                                                    boneIndex, 1.0f, timeline);
                } else {
                    /* 0x28d718/0x28d71c: r4 == 0 here, see E3 */
                    return readSkeletonData_invalidTimelineTypeForBone(
                        timelineJson, data, animation_raw, parser);
                }
                timelineJson = timelineJson->next;       /* 0x28d824 */
            } while (timelineJson != 0);                 /* 0x28d828 / 0x28d82c */
        }
        boneNode = boneNode->next;                       /* 0x28d830 / 0x28d834 */
    }
    return 1;                                            /* 0x28d840 fall-through */
}
