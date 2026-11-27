/* readCurve (0x28b34c..0x28b3f8) — reconstruction fixture.
 *
 * Everything executable here is the rebuilt C in src/spine_read_curve.c plus
 * the shared synthetic runtime below (heap, allocator roster, libc string
 * providers) inherited from the mesh fixture.  qemu executes OUR linked C; the
 * original libyoyo bytes are never loaded or run.
 *
 * Declared boundaries (NOT recovered bodies):
 *   spCurveTimeline_setStepped — the double models the real body exactly:
 *     0x2817c0 ldr r3,[r0,#0x8] / 0x2817c4 mov r2,#76 / 0x2817c8 mov r12,#1.0f
 *     0x2817cc mla r1,r2,r1,r3 / 0x2817d0 str r12,[r1]
 *     => self->curves[frameIndex * 19 + 0] = 1.0f
 *   spCurveTimeline_setCurve — body (0x2817d8, 66 insns of Bezier expansion) is
 *     NOT recovered; the double records the six AAPCS words so the caller's
 *     argument order and bit-exact float passthrough are observable.
 *   The timeline struct itself is a fixture record (curves at +0x08), synthetic.
 *
 * The JSON trees are synthetic (node()/add()/floats()/string()), with node
 * types set exactly as the real parser 0x28677c writes them (see the enum in
 * spine_read_curve.h).  readCurve never allocates; the allocator roster is
 * armed by begin() only to PROVE that (na/nf stay 0).
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#include "spine_read_curve.h"

/* ---- spCurveTimeline double ------------------------------------------- */
#define TL_FRAME_FLOATS 19

struct TL {                       /* only +0x08 is pinned by the callees */
    uint32_t opaque_00;
    uint32_t opaque_04;
    float* curves;                /* +0x08 */
};

static struct TL tl;
static float tl_curves[TL_FRAME_FLOATS * 8];

static struct {
    int calls;                    /* 0 = no callee entered */
    int kind;                     /* 1 = setStepped, 2 = setCurve */
    int frame;
    uint32_t arg[4];
    void* timeline;
} obs;

void spCurveTimeline_setStepped(void* t, int frame)
{
    struct TL* self = (struct TL*)t;
    ++obs.calls; obs.kind = 1; obs.frame = frame; obs.timeline = t;
    CK(frame >= 0 && frame < 8, "setStepped double frame range");
    /* 0x2817cc mla r1,r2,r1,r3 with r2 = 76 (19 floats); 1.0f at +0 */
    self->curves[frame * TL_FRAME_FLOATS] = 1.0f;
}

void spCurveTimeline_setCurve(void* t, int frame,
                              float cx1, float cy1, float cx2, float cy2)
{
    ++obs.calls; obs.kind = 2; obs.frame = frame; obs.timeline = t;
    obs.arg[0] = bits(cx1);
    obs.arg[1] = bits(cy1);
    obs.arg[2] = bits(cx2);
    obs.arg[3] = bits(cy2);
}

#ifndef CURVE_NULL_PROBE
/* ---- helpers ---------------------------------------------------------- */
/* Snapshot roster: begin() rewinds the fixture heap, so snapshots live only
 * for one test (they are cleared by arm()). */
static Json saved[8];
static Json* saved_at[8];
static unsigned nsaved;

static void arm(const char* name)
{
    begin(name);
    memset(&tl, 0, sizeof(tl));
    tl.curves = tl_curves;
    memset(tl_curves, 0, sizeof(tl_curves));
    memset(&obs, 0, sizeof(obs));
    nsaved = 0;
}

/* A JSON object as the frame map: only the "curve" key is set (or not). */
static Json* frame_map(void) { return node(0); }

static void put_string(Json* f, const char* v)
{
    Json* n = string("curve", v);
    n->unk_08 = CURVE_JSON_STRING;     /* 0x2868c0/0x2868c8 in the parser */
    add(f, n);
}

/* Array of `chain` float children; `declared` is the node's +0x0c count word
 * (which the original never consults). */
static Json* put_array(Json* f, const float* v, unsigned chain, uint32_t declared)
{
    Json* a = floats("curve", v, chain, declared);
    a->unk_08 = CURVE_JSON_ARRAY;      /* 0x286fb4/0x286fb8 in the parser */
    add(f, a);
    return a;
}

/* Snapshot every Json node we hand in, to prove readCurve writes none of them. */
static void snap(Json* n)
{
    CK(nsaved < 8, "snapshot roster");
    saved_at[nsaved] = n;
    memcpy(&saved[nsaved], n, sizeof(Json));
    ++nsaved;
}

static void snap_check(void)
{
    for (unsigned i = 0; i < nsaved; ++i)
        for (unsigned k = 0; k < sizeof(Json) / 4; ++k)
            CK(word(saved_at[i], k) == word(&saved[i], k),
               "CURVE leaves every Json node byte-identical");
}

/* ---- contracts -------------------------------------------------------- */

/* No "curve" key at all: the 0x28b36c beq takes the epilogue; no callee. */
static void curve_absent(void)
{
    arm("curve_absent");
    Json* f = frame_map();
    add(f, string("time", "0"));
    add(f, string("angle", "90"));
    snap(f);
    readCurve(f, &tl, 5);
    CK(obs.calls == 0, "CURVE absent key performs no timeline write");
    CK(obs.timeline == 0 && obs.frame == 0, "CURVE absent key leaves no callee state");
    CK(tl_curves[0] == 0.0f, "CURVE absent key leaves curves[] untouched");
    CK(na == 0 && nf == 0, "CURVE performs no allocation or free");
    snap_check();
    /* Json_getItem's own NULL-child path: a frame with no keys at all. */
    Json* empty = frame_map();
    readCurve(empty, &tl, 5);
    CK(obs.calls == 0, "CURVE empty frame performs no timeline write");
    pass("curve_absent");
}

/* "curve":"stepped" -> tail call setStepped(timeline, frameIndex).  The key is
 * the SECOND child so Json_getItem's linked-list walk is exercised. */
static void curve_stepped(void)
{
    arm("curve_stepped");
    Json* f = frame_map();
    add(f, string("time", "0"));
    put_string(f, "stepped");
    snap(f);
    readCurve(f, &tl, 3);
    CK(obs.calls == 1 && obs.kind == 1, "CURVE stepped calls setStepped exactly once");
    CK(obs.frame == 3 && obs.timeline == (void*)&tl,
       "CURVE stepped passes timeline and frameIndex unchanged");
    CK(bits(tl_curves[3 * TL_FRAME_FLOATS]) == bits(1.0f),
       "CURVE stepped marks curves[frameIndex*19] via the real setStepped shape");
    CK(bits(tl_curves[3 * TL_FRAME_FLOATS + 1]) == 0,
       "CURVE stepped writes only the first curve word");
    CK(tl_curves[0] == 0.0f && tl_curves[2 * TL_FRAME_FLOATS] == 0.0f,
           "CURVE stepped does not touch other frames");
    CK(na == 0 && nf == 0, "CURVE stepped allocates nothing");
    snap_check();
    pass("curve_stepped");
}

/* Only the exact lowercase "stepped" is honoured (0x28b398 strcmp, 0x28b3a0 bne). */
static void curve_string_other(void)
{
    static const char* const reject[] = {"catmullrom", "STEPPED", "Stepped",
                                         "stepped ", " stepped", "", "s"};
    arm("curve_string_other");
    for (unsigned i = 0; i < sizeof(reject) / sizeof(reject[0]); ++i) {
        Json* f = frame_map();
        put_string(f, reject[i]);
        readCurve(f, &tl, 1);
        CK(obs.calls == 0, "CURVE only the exact lowercase 'stepped' is honoured");
        CK(tl_curves[TL_FRAME_FLOATS] == 0.0f,
           "CURVE rejected curve string writes no curve word");
    }
    pass("curve_string_other");
}

/* 4-element array: the four numbers land in cx1,cy1,cx2,cy2 order, bit exact. */
static void curve_array_four(void)
{
    arm("curve_array_four");
    const float v[4] = {fb(0x3e800000u),  /* 0.25 */
                        fb(0xbf000000u),  /* -0.5 */
                        fb(0x3fc00000u),  /* 1.5 */
                        fb(0xc0000000u)}; /* -2.0 */
    Json* f = frame_map();
    Json* a = put_array(f, v, 4, 4);
    snap(f); snap(a);
    readCurve(f, &tl, 6);
    CK(obs.calls == 1 && obs.kind == 2, "CURVE array calls setCurve exactly once");
    CK(obs.frame == 6 && obs.timeline == (void*)&tl,
       "CURVE array passes timeline and frameIndex unchanged");
    CK(obs.arg[0] == bits(v[0]), "CURVE array arg1 is cx1 from child 0");
    CK(obs.arg[1] == bits(v[1]), "CURVE array arg2 is cy1 from child 1");
    CK(obs.arg[2] == bits(v[2]), "CURVE array arg3 is cx2 from child 2");
    CK(obs.arg[3] == bits(v[3]), "CURVE array arg4 is cy2 from child 3");
    CK(na == 0 && nf == 0, "CURVE array allocates nothing");
    snap_check();
    pass("curve_array_four");
}

/* Chain length 1..4 with tail values 5,6,7,8 appended after the "array": the
 * original reads four nodes unconditionally, so short chains leak the
 * following nodes into cx2/cy2. */
static void curve_array_chain_lengths(void)
{
    arm("curve_array_chain_lengths");
    const float chain8[8] = {fb(0x3f800000u), fb(0x40000000u), fb(0x40400000u),
                             fb(0x40800000u), fb(0x40a00000u), fb(0x40c00000u),
                             fb(0x40e00000u), fb(0x41000000u)}; /* 1..8 */
    const uint32_t want[4][4] = {
        {0x3f800000u, 0x40a00000u, 0x40c00000u, 0x40e00000u}, /* 1,5,6,7 */
        {0x3f800000u, 0x40000000u, 0x40a00000u, 0x40c00000u}, /* 1,2,5,6 */
        {0x3f800000u, 0x40000000u, 0x40400000u, 0x40a00000u}, /* 1,2,3,5 */
        {0x3f800000u, 0x40000000u, 0x40400000u, 0x40800000u}  /* 1,2,3,4 */
    };
    for (unsigned n = 1; n <= 4; ++n) {
        memset(&obs, 0, sizeof(obs));
        Json* f = frame_map();
        /* A logical n-element curve array: n real elements, then the following
         * sibling nodes (values 5,6,7) that the original walks into because it
         * never consults the count and never stops at a bound. */
        Json* a = put_array(f, chain8, n, n);
        for (unsigned k = n; k < 4; ++k) {
            Json* e = node(0);
            memcpy(&e->float_value, &chain8[4 + (k - n)], 4);
            add(a, e);
        }
        readCurve(f, &tl, (int)n);
        CK(obs.calls == 1 && obs.kind == 2, "CURVE chain of n elements still calls setCurve");
        for (unsigned i = 0; i < 4; ++i)
            CK(obs.arg[i] == want[n - 1][i],
               "CURVE reads four ->next nodes regardless of length (short chain continues)");
        CK(obs.frame == (int)n, "CURVE chain keeps the frame index");
    }
    pass("curve_array_chain_lengths");
}

/* The +0x0c count word is never read: 0 or 9 changes nothing, the four reads
 * are identical.  This is also the "declared length 0" contract: a 0 count is
 * indistinguishable from 4 because no count is consulted at all. */
static void curve_array_declared_count(void)
{
    const uint32_t decl[] = {0u, 1u, 3u, 4u, 9u, 0xffffffffu};
    const float v[4] = {fb(0x3e800000u), fb(0xbf000000u), fb(0x3fc00000u),
                        fb(0xc0000000u)};
    for (unsigned i = 0; i < sizeof(decl) / sizeof(decl[0]); ++i) {
        arm("curve_array_declared_count");
        Json* f = frame_map();
        put_array(f, v, 4, decl[i]);
        readCurve(f, &tl, 2);
        CK(obs.calls == 1 && obs.kind == 2, "CURVE array ignores the declared count");
        for (unsigned k = 0; k < 4; ++k)
            CK(obs.arg[k] == bits(v[k]),
               "CURVE ignores Json+0x0c: same four values for any declared count");
    }
    pass("curve_array_declared_count");
}

/* Extra elements are ignored: only the first four are consumed. */
static void curve_array_extra_ignored(void)
{
    arm("curve_array_extra_ignored");
    const float v[6] = {fb(0x3f800000u), fb(0x40000000u), fb(0x40400000u),
                        fb(0x40800000u), fb(0x40a00000u), fb(0x40c00000u)};
    Json* f = frame_map();
    put_array(f, v, 6, 6);
    readCurve(f, &tl, 0);
    CK(obs.calls == 1 && obs.kind == 2, "CURVE six-element array calls setCurve once");
    for (unsigned i = 0; i < 4; ++i)
        CK(obs.arg[i] == bits(v[i]), "CURVE ignores elements past the fourth");
    pass("curve_array_extra_ignored");
}

/* Every other node type (null/true/false/number/object) is a no-op. */
static void curve_type_other(void)
{
    const uint32_t types[] = {CURVE_JSON_NULL, CURVE_JSON_TRUE, CURVE_JSON_FALSE,
                              CURVE_JSON_NUMBER, CURVE_JSON_OBJECT};
    for (unsigned i = 0; i < sizeof(types) / sizeof(types[0]); ++i) {
        arm("curve_type_other");
        Json* f = frame_map();
        Json* n = node("curve");
        n->unk_08 = types[i];
        if (types[i] == CURVE_JSON_NUMBER) n->float_value = fb(0x3f800000u);
        if (types[i] == CURVE_JSON_OBJECT) add(n, string("x", "y"));
        add(f, n);
        snap(f); snap(n);
        readCurve(f, &tl, 4);
        CK(obs.calls == 0, "CURVE non-string/non-array type performs no timeline write");
        CK(tl_curves[4 * TL_FRAME_FLOATS] == 0.0f,
           "CURVE non-string/non-array type writes no curve word");
        snap_check();
    }
    pass("curve_type_other");
}

/* Frame index is a whole 32-bit word, passed through unmodified. */
static void curve_frame_index(void)
{
    const int idx[] = {0, 1, 7, -1, -2147483647 - 1};
    const float v[4] = {fb(0x00000000u), fb(0x80000000u), fb(0x7fc00001u),
                        fb(0xff800000u)};  /* +0, -0, NaN, -inf */
    for (unsigned i = 0; i < sizeof(idx) / sizeof(idx[0]); ++i) {
        arm("curve_frame_index");
        Json* f = frame_map();
        put_array(f, v, 4, 4);
        readCurve(f, &tl, idx[i]);
        CK(obs.calls == 1 && obs.kind == 2, "CURVE frame index still calls setCurve");
        CK(obs.frame == idx[i], "CURVE frame index passes through as a signed 32-bit word");
        for (unsigned k = 0; k < 4; ++k)
            CK(obs.arg[k] == bits(v[k]),
               "CURVE floats pass through bit-exactly (+0/-0/NaN/-inf)");
    }
    pass("curve_frame_index");
}

#endif /* !CURVE_NULL_PROBE: the fault probe needs no contracts */

#ifndef CURVE_NULL_PROBE
void _start(void)
{
    test = "startup"; init_heap();
    curve_absent();
    curve_stepped();
    curve_string_other();
    curve_array_four();
    curve_array_chain_lengths();
    curve_array_declared_count();
    curve_array_extra_ignored();
    curve_type_other();
    curve_frame_index();
    out("SUMMARY all declared readCurve contracts passed\n");
    quit(0);
}
#else
/* Zero-element "curve": child == 0.  The original has no NULL guard between
 * 0x28b3b8 (ldr child) and 0x28b3c8 (ldr [child,#0x18]); the rebuild must fault
 * identically.  This probe is expected to die on SIGSEGV — surviving is the
 * failure. */
void _start(void)
{
    test = "curve_zero_elements";
    init_heap();
    memset(&tl, 0, sizeof(tl)); tl.curves = tl_curves;
    out("PROBE armed\n");
    Json* f = node(0);
    Json* a = node("curve");
    a->unk_08 = CURVE_JSON_ARRAY;   /* child stays NULL: zero elements */
    add(f, a);
    readCurve(f, &tl, 0);
    out("FAIL curve_zero_elements: CURVE survived a zero-element curve array\n");
    quit(1);
}
#endif
