/*
 * spine_read_skeleton.c — assembled spSkeletonJson_readSkeletonData @0x28b84c
 * (13044 B) of libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * Assembly only: every segment byte belongs to its own recovered module.  This
 * file owns the segment ORDER, the root/data lifetimes and the seven error
 * tails the segment modules report as codes (census §5.2 plus the out-of-window
 * 0x28e7f4 block, see the header).  Addresses in comments are the original
 * instructions each statement mirrors.
 *
 * Evidence tier: bytecode_anchored.  The original was never executed.
 */

#include "spine_read_skeleton.h"

#include "spine_read_entry.h"        /* readSkeletonData_entry   0x28b84c..0x28b8f0 */
#include "spine_read_meta.h"         /* metadata + bones array   0x28b8f4..0x28ba40 */
#include "spine_read_bones.h"        /* bone loop                0x28ba40..0x28bbcc */
#include "spine_read_slots.h"        /* slots segment            0x28bbcc..0x28bdd8 */
#include "spine_read_ik.h"           /* ik constraints           0x28bdd8..0x28bff8 */
#include "spine_read_transform.h"    /* transform constraints    0x28bff8..0x28c274 */
#include "spine_read_path.h"         /* path constraints         0x28c274..0x28c5ec */
#include "spine_read_skins.h"        /* skins array + one skin   0x28c5ec..0x28c6b4 */
#include "spine_read_attach_dispatch.h" /* name/path/type + 5 strcmp 0x28c6f0..0x28c79c */
#include "spine_skins_glue.h"        /* dispatch/create/add/advance + tails */
#include "spine_linked_postpass.h"   /* linkedmesh postpass      0x28ccb8..0x28cd6c */
#include "spine_read_animations.h"   /* B1 events + B2 animations 0x28d19c..0x28d2d4 */
#include "spine_animations_loop.h"   /* per-animation loop       0x28d318..0x28e79c */

#include "../../skeleton_find/src/skeleton_find.h"           /* findBone/findSlotIndex */
#include "../../spine_skin/src/spine_skin.h"                 /* spSkin* record       */
#include "../../spine_json_error/src/spine_json_error.h"     /* _spSkeletonJson_setError */
#include "../../spine_json_support/src/spine_json_support.h" /* Json_dispose         */

/*
 * The [sp,#0x24] root slot.  See the header's seam note: this is the one word
 * the entry module's C ABI cannot return, so the Json_create provider (named
 * boundary, unrecovered) publishes it here at 0x28b8ac / 0x28bf74 time.
 */
Json* readSkeletonData_rootSlot;

/* bionic: LC_CTYPE=0, LC_NUMERIC=1 (see c/spine_read_entry). */
#define CHAIN_LC_NUMERIC 1

/* setlocale@plt 0xb679c (called from 0x28b87c, 0x28b89c, 0x28b8b4, 0x28bf64,
 * 0x28bf7c; c/spine_read_entry already declares it as _setlocale). */
extern char* _setlocale(int category, const char* locale);

/* Json_getError 0x2872b8 — the parser's last error string.  Not recovered by
 * c/json_interface (which recovers the four accessors only); the fixture
 * supplies the parse-error model. */
extern const char* Json_getError(void);

/* ==================================================================== */
/* helpers                                                              */
/* ==================================================================== */

/*
 * json->scale (+0x00, binary32 bits) read AT THE CALL INSTANT — every original
 * scaling site is `vldr s15,[r8]` (census §2.3.3), never an entry-time cache.
 * Reading through the pointer each time is what keeps a second call from
 * inheriting a stale scale.
 */
static float chain_scale(const spSkeletonJson* json)
{
    uint32_t bits;
    float value;
    __asm__ volatile("ldr %0,[%1]" : "=r"(bits) : "r"(json) : "memory");
    __builtin_memcpy(&value, &bits, 4);
    return value;
}

/*
 * The shape shared by the ten dispose-bearing error tails (census §4.1/§6.1):
 *   spSkeletonData_dispose(data)                       (0x28bf2c, 0x28c10c, ...)
 *   _spSkeletonJson_setError(self, root, text, arg)    (root disposed inside)
 *   return NULL                                        (r0 = 0 via the exit)
 * The ORDER is the original's and must not be swapped: dispose first, report
 * second.  Keeping one C helper does not lose any register semantics — every
 * one of these exits returns 0 — but each call site still names its own
 * literal and argument below.
 */
static spSkeletonData* chain_fail(spSkeletonJson* self, Json* root,
                                  spSkeletonData* data,
                                  const char* text, const char* arg)
{
    spSkeletonData_dispose(data);
    _spSkeletonJson_setError(self, root, text, arg);
    return 0;
}

/* Zero the B3/B4 frame slice before B3 writes it.  The original's
 * [sp,#0x18..0x74] words are stack garbage at entry; every one of them is
 * written by readSkeletonData_animationFrameInit / _animationKeys /
 * _animationTimelines before any reader runs, so zeroing cannot change the
 * recovered behaviour — it only keeps the C translation free of indeterminate
 * reads. */
static void chain_frame_zero(spAnimationFrame* frame)
{
    unsigned char* p = (unsigned char*)frame;
    unsigned i;
    for (i = 0; i < sizeof *frame; ++i) p[i] = 0;
}

/*
 * 0x28bf28..0x28bf58: the parent-bone tail's message argument is r10, the
 * parent name of the bone that failed (0x28bf3c mov r3,r10).  The bones module
 * reports only "parent not found", so the assembly re-walks the SAME child list
 * with the SAME lookup in the same order — exactly the technique
 * c/spine_animations_loop uses for its three handoffs.  This reproduces the
 * failing node: bones are appended in list order and never removed, so the
 * first miss of the re-walk is the index at which the original stopped (the
 * array state at that moment is a prefix of the final one, and every earlier
 * bone found its parent inside that prefix).
 */
static const char* chain_parent_miss(Json* firstBone, void* data_raw)
{
    Json* boneMap;

    for (boneMap = firstBone; boneMap != 0; boneMap = boneMap->next) {
        const char* parent = Json_getString(boneMap, "parent", 0);
        if (parent != 0 &&
            spSkeletonData_findBone((spSkeletonData*)data_raw, parent) == 0)
            return parent;
    }
    return 0;
}

/* ==================================================================== */
/* blocks #4 / #7 / #8 of census §5.1 — the three "Target ..." tails     */
/* ==================================================================== */

/*
 * c/spine_skins_glue owns 0x28cf3c / 0x28d144 / 0x28d170.  Each one begins
 * `mov r4,r0` and then loads the message argument with `ldr r3,[r4,#0x1c]`,
 * where r0 is the failed lookup result — 0 on the only edge into the block
 * (0x28bfa8 / 0x28c154 / 0x28c3fc), i.e. a latent NULL-page fault the shipped
 * data never takes (the census records it; the glue fixture injects a record).
 *
 * The assembly cannot route a fault, so it hands the block the register value
 * the lookup WOULD have produced: a record whose +0x1c word is the target name
 * the segment module reported.  Only that one word is ever read, and it is
 * read through the glue module's own instruction — the block still runs once,
 * from its owner.
 */
typedef struct chain_target_arg {
    uint32_t reserved[7];   /* +0x00..+0x18: never read by the tails */
    const char* name;       /* +0x1c: 0x28cf58 / 0x28d160 / 0x28d18c load */
} chain_target_arg;

_Static_assert(sizeof(chain_target_arg) == 0x20,
               "the tails read exactly one word at +0x1c");
_Static_assert(offsetof(chain_target_arg, name) == 0x1c,
               "message argument offsets in blocks #4/#7/#8");

static spSkeletonData* chain_target_tail(
    int (*tail)(spSkeletonJson*, Json*, void*, const void*),
    spSkeletonJson* self, Json* root, spSkeletonData* data, const char* name)
{
    chain_target_arg record;
    unsigned i;

    for (i = 0; i < 7; ++i) record.reserved[i] = 0;
    record.name = name;
    (void)tail(self, root, data, &record);
    return 0;                                   /* 0x28cf60 / 0x28d168 / 0x28d194 */
}

/* ==================================================================== */
/* skins window: skin -> slot -> attachment, driven by the glue cursor   */
/* ==================================================================== */

typedef struct chain_skins_ctx {
    spSkeletonJson* json;   /* r8           */
    Json* root;             /* [sp,#0x24]   */
    void* data_raw;         /* [sp,#0x34]   */
    spSkin* skin;           /* r9           */
    uint32_t slotIndex;     /* [sp,#0x28]   */
} chain_skins_ctx;

/*
 * 0x28c6e8 attachment body: classify (c/spine_read_attach_dispatch) -> one of
 * the five type stubs -> c/spine_read_skins/glue create + field parse + add.
 * The glue's createAttachment already ends at the shared spSkin_addAttachment
 * (0x28cc68), so nothing may be inserted between the two.
 */
static int chain_skins_body(void* vctx, Json* attachmentMap)
{
    chain_skins_ctx* ctx = (chain_skins_ctx*)vctx;
    const char* name = 0;
    const char* path = 0;
    const char* type = 0;
    attach_type_e kind;

    /* 0x28c6f0..0x28c79c (the five strcmp + the fall-through branch). */
    kind = readSkeletonData_classifyAttachment(attachmentMap, ctx->data_raw,
                                               &name, &path, &type);

    switch (kind) {
    case ATTACH_REGION:        /* 0x28cf2c -> 0x28c7a4 */
        return readSkeletonData_skinsCreateRegionAttachment(
            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,
            ctx->root, ctx->data_raw);
    case ATTACH_BOUNDINGBOX:   /* 0x28cfa0 -> 0x28c7a4 */
        return readSkeletonData_skinsCreateBoundingBoxAttachment(
            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,
            ctx->root, ctx->data_raw);
    case ATTACH_MESH:          /* 0x28cf24 -> 0x28c7a4 */
        return readSkeletonData_skinsCreateMeshAttachment(
            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,
            ctx->root, ctx->data_raw);
    case ATTACH_LINKEDMESH:    /* 0x28cf34 -> 0x28c7a4 */
        return readSkeletonData_skinsCreateLinkedMeshAttachment(
            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,
            ctx->root, ctx->data_raw);
    case ATTACH_PATH:          /* 0x28c7a0 falls into 0x28c7a4 */
        return readSkeletonData_skinsCreatePathAttachment(
            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,
            ctx->root, ctx->data_raw);
    case ATTACH_UNKNOWN:
    default:
        /*
         * 0x28c79c bne 0x28e7f4 — the dispatch's unknown-type tail, physically
         * inside the animations address range (0x28e7f4..0x28e81c) and owned by
         * no module:
         *   0x28e7f4 ldr r9,[sp,#0x34] ; 0x28e7f8 mov r0,r9
         *   0x28e7fc bl spSkeletonData_dispose
         *   0x28e800/0x28e810 r2 = "Unknown attachment type: "
         *   0x28e808 ldr r1,[sp,#0x24] (root) ; 0x28e80c mov r3,r10 (the type)
         *   0x28e814 bl _spSkeletonJson_setError
         *   0x28e818 mov r0,#0 ; 0x28e81c b 0x28bdcc
         */
        spSkeletonData_dispose((spSkeletonData*)ctx->data_raw);
        _spSkeletonJson_setError(ctx->json, ctx->root,
                                 "Unknown attachment type: ", type);
        return SKINS_GLUE_ERROR;
    }
}

/*
 * 0x28c5ec..0x28ccb8 — the three-level skins window.
 *
 *   skins   0x28c5ec  getItem(tree,"skins"); absent -> 0x28ccb8
 *           0x28c618  data+0x24 = _malloc(size*4, line 839)
 *           0x28c61c  first skin child; childless -> 0x28ccb8
 *   skin    0x28c664  spSkin_create(skinMap->name); running count; default check
 *           0x28c69c  slotMap = skinMap->child; childless -> 0x28cca0 (advance)
 *   slot    0x28c6c4  slotIndex = findSlotIndex(data, slotMap->name)
 *           0x28c6d4  attachmentMap = slotMap->child; childless -> 0x28cc88
 *   attach  0x28c6e8  body -> 0x28cc7c advance (glue cursor)
 *
 * Returns 1 when the three lists are exhausted, 0 when an attachment reported
 * an error (the owning tail already disposed the data and reported).
 */
static int chain_skins_stage(spSkeletonJson* self, Json* tree,
                            spSkeletonData* data_raw)
{
    Json* skinMap;
    chain_skins_ctx ctx;

    skinMap = readSkeletonData_skinsArray(tree, data_raw);   /* 0x28c5ec..0x28c62c */
    if (skinMap == 0)
        return 1;                                            /* 0x28c600 / 0x28c62c */

    ctx.json = self;
    ctx.root = tree;
    ctx.data_raw = data_raw;
    ctx.skin = 0;
    ctx.slotIndex = 0;

    for (;;) {
        Json* slotMap;
        int is_default;

        /* 0x28c664..0x28c6a8 */
        ctx.skin = (spSkin*)readSkeletonData_oneSkin(skinMap, data_raw, &is_default);
        (void)is_default;                 /* data+0x28 written inside oneSkin */
        slotMap = skinMap->child;         /* 0x28c69c/0x28c6a0 */
        if (slotMap == 0) {               /* 0x28c6ac/0x28c6b0 beq 0x28cca0 */
            skinMap = skinMap->next;
            if (skinMap == 0) return 1;
            continue;
        }

        for (;;) {
            Json* attachmentMap;
            skins_glue_cursor cursor;
            skins_glue_next next;

            /* 0x28c6c4..0x28c6d8 */
            ctx.slotIndex = (uint32_t)spSkeletonData_findSlotIndex(
                (spSkeletonData*)data_raw, slotMap->name);
            attachmentMap = slotMap->child;
            if (attachmentMap == 0) {     /* 0x28c6e4 beq 0x28cc88 */
                slotMap = slotMap->next;
                if (slotMap == 0) {       /* 0x28cc88..0x28ccb0 */
                    skinMap = skinMap->next;
                    break;                /* re-enter the skin head 0x28c664 */
                }
                continue;
            }

            /* 0x28c6e8 body + 0x28cc68..0x28ccb8 advance, in the glue module. */
            cursor.attachment = attachmentMap;
            cursor.slot = slotMap;
            cursor.skin = skinMap;
            next = readSkeletonData_skinsAttachmentLevel(&cursor,
                                                         chain_skins_body, &ctx);
            if (next == SKINS_GLUE_NEXT_ABORT)
                return 0;                 /* 0x28cf9c b 0x28bdcc */
            if (next == SKINS_GLUE_NEXT_DONE)
                return 1;                 /* 0x28ccb0 fall-through -> 0x28ccb4 */
            if (next == SKINS_GLUE_NEXT_SKIN) {
                skinMap = cursor.skin;
                break;                    /* the skin head starts over */
            }
            slotMap = cursor.slot;        /* SKINS_GLUE_NEXT_SLOT */
        }
        if (skinMap == 0)
            return 1;                     /* 0x28ccb0 not taken: done */
    }
}

/* ==================================================================== */
/* the assembled loader                                                */
/* ==================================================================== */

spSkeletonData* spSkeletonJson_readSkeletonData(spSkeletonJson* self,
                                                const char* data)
{
    spSkeletonData* sd = 0;
    Json* tree;

    /*
     * 0x28b87c / 0x28bf58: the locale guard of c/spine_read_entry closes over
     * `saved = setlocale(LC_NUMERIC,NULL) != NULL`.  When `saved` is NULL the
     * original takes the out-of-line fallback at 0x28bf58
     *   setlocale(LC_NUMERIC,"C") -> Json_create -> setlocale(LC_NUMERIC,NULL)
     * and never restores (the census quirk).  The entry module cannot report
     * `saved`, so the assembly performs the fallback itself: probe once, and if
     * the probe is NULL set "C" BEFORE entry's Json_create runs and reset the
     * locale AFTER it.  The probe is a read-only setlocale(NULL) call; on the
     * normal path it repeats that one read, which changes no state.
     */
    if (_setlocale(CHAIN_LC_NUMERIC, 0) == 0) {
        _setlocale(CHAIN_LC_NUMERIC, "C");                /* 0x28bf5c/0x28bf64 */
        (void)readSkeletonData_entry(self, data, &sd);    /* 0x28bf68..0x28bf6c */
        _setlocale(CHAIN_LC_NUMERIC, 0);                  /* 0x28bf78/0x28bf7c: no restore */
    } else {
        (void)readSkeletonData_entry(self, data, &sd);    /* 0x28b84c..0x28b8f0 */
    }

    if (sd == 0) {
        /*
         * 0x28c3b4..0x28c3d8 — Json_create returned NULL (entry only returns
         * out_data == 0 on that path: the data record is created before the
         * "skeleton" lookup, so a missing key still yields a live record).
         *   0x28c3b4 bl Json_getError
         *   0x28c3b8/0x28c3c0 r2 = "Invalid skeleton JSON: "
         *   0x28c3bc ldr r1,[sp,#0x24] (still 0) ; 0x28c3c4 mov r3,r0
         *   0x28c3cc bl _spSkeletonJson_setError
         *   0x28c3d0 ldr r0,[sp,#0x24] ; 0x28c3d4 b 0x28bdcc  -> NULL
         * No data exists yet, so nothing is disposed here.
         */
        _spSkeletonJson_setError(self, 0, "Invalid skeleton JSON: ",
                                 Json_getError());
        return 0;
    }

    tree = readSkeletonData_rootSlot;          /* [sp,#0x24], written at 0x28b8ac */

    /* 0x28b8f4..0x28b9cc — meta (hash 607 / spine 608 / width / height). */
    readSkeletonData_metadata(tree, sd);

    /* 0x28b9cc..0x28bbcc — bones array 615 then the bone loop. */
    {
        int declared = 0;
        Json* firstBone = readSkeletonData_bonesArray(tree, sd, &declared);
        (void)declared;                        /* count is a running counter here */
        if (readSkeletonData_boneLoop(firstBone, sd, chain_scale(self)) == 0) {
            /* 0x28bf28..0x28bf58 */
            return chain_fail(self, tree, sd, "Parent bone not found: ",
                              chain_parent_miss(firstBone, sd));
        }
    }

    /* 0x28bbcc..0x28bdd8 — the slots segment emits its own tail (0x28bda4). */
    if (readSkeletonData_slotsSegment(tree, sd, self) == 0)
        return 0;                              /* 0x28bdc8 mov r0,r7 -> 0x28bdcc */

    /* 0x28bdd8..0x28bff8 — ik constraints. */
    {
        int which = 0;
        const char* name = 0;
        if (readSkeletonData_ikSection(tree, sd, &which, &name) == 0) {
            if (which == 1) {
                /* 0x28bf00..0x28bf24 */
                return chain_fail(self, tree, sd, "IK bone not found: ", name);
            }
            /* 0x28bfa8 beq 0x28cf3c (block #4, owned by the glue). */
            return chain_target_tail(readSkeletonData_ikTargetNotFoundTail,
                                     self, tree, sd, name);
        }
    }

    /* 0x28bff8..0x28c274 — transform constraints. */
    {
        int which = 0;
        const char* name = 0;
        if (readSkeletonData_transformSection(tree, sd, chain_scale(self),
                                              &which, &name) == 0) {
            if (which == 1) {
                /* 0x28c104..0x28c12c */
                return chain_fail(self, tree, sd, "Transform bone not found: ", name);
            }
            /* 0x28c154 beq 0x28d144 */
            return chain_target_tail(readSkeletonData_transformTargetNotFoundTail,
                                     self, tree, sd, name);
        }
    }

    /* 0x28c274..0x28c5ec — path constraints (target is a SLOT). */
    {
        int which = 0;
        const char* name = 0;
        if (readSkeletonData_pathSection(tree, sd, chain_scale(self),
                                         &which, &name) == 0) {
            if (which == 1) {
                /* 0x28c384..0x28c3b0 */
                return chain_fail(self, tree, sd, "Path bone not found: ", name);
            }
            /* 0x28c3fc beq 0x28d170 */
            return chain_target_tail(readSkeletonData_pathTargetSlotNotFoundTail,
                                     self, tree, sd, name);
        }
    }

    /* 0x28c5ec..0x28ccb8 — skins -> slots -> attachments. */
    if (chain_skins_stage(self, tree, sd) == 0)
        return 0;                              /* tail already disposed + reported */

    /* 0x28ccb8..0x28d19c — linkedmesh postpass (owns both of its tails). */
    if (readSkeletonData_resolveLinkedMeshes(self, sd) == 0)
        return 0;

    /* 0x28d19c..0x28d290 — B1: skeleton-wide events. */
    readSkeletonData_eventsSegment(tree, sd);

    /* 0x28d290..0x28e79c — B2 animations array + the per-animation loop. */
    {
        Json* firstAnimation = readSkeletonData_animationsArray(tree, sd);
        if (firstAnimation != 0) {             /* 0x28d2a0/0x28d2d0 beq 0x28e7a4 */
            spAnimationFrame frame;
            chain_frame_zero(&frame);
            frame.animation = firstAnimation;  /* 0x28d2c8 str r4,[sp,#0x1c] */
            if (readSkeletonData_animationsLoop(firstAnimation, &frame, sd,
                                                self) == 0)
                return 0;                      /* family tail disposed the data */
        }
    }

    /*
     * 0x28e7a0 mov r9,r0 ; 0x28e7a4 ldr r0,[sp,#0x24] ;
     * 0x28e7a8 bl Json_dispose ; 0x28e7ac mov r0,r9 ; 0x28e7b0 b 0x28bdcc.
     * The one and only root release on the success path.
     */
    Json_dispose(tree);
    return sd;
}
