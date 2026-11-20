/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Sole free function: globalPageListFindAddr(const void*) @ 0x27be34..0x27bee0,
 * size 172 (43 words incl. the two trailing pool words), dynsym
 * _Z22globalPageListFindAddrPKv (boundary: defined_dynsym).
 * Anchor for both live variables comes from this very function's GOT path:
 * pool word 0x27bed8 (0x1759f4) + PC of 0x27be3c -> slot 0x3f1838 -> g_pages
 * variable 0x7566a0; pool word 0x27bedc (0x1759e8) + PC of 0x27be40 -> slot
 * 0x3f1830 -> g_bucketNumPages variable 0x7566a4. The original loads count
 * first (0x27be48) and the array pointer second (0x27be4c); both are the real
 * original variables bound in page_lookup.hpp, not defaults defined here.
 * g_pages is a POINTER to a boundary-address WORD array, not an inline array.
 * gap: the full page/list producers and complete BucketPrefix shape are still
 * unrecovered; corrupt-table, negative-cursor and overflow input domains and
 * concurrency are unproved. ARM32 32-bit wrapping of every address/count
 * operation below is preserved, not sanitised. No target execution, so
 * bit-exact equivalence to the original body remains unproved.
 */

#include "page_lookup.hpp"

namespace {

/* Raw words live in the shared page array and in bucket headers. may_alias
 * keeps the alias honest, volatile keeps every original ldr (0x27be74,
 * 0x27be90, 0x27bec8, 0x27bed0); addresses are carried as plain uint32_t so
 * every add/sub wraps exactly like ARM32 instead of leaning on pointer UB. */
typedef uint32_t BoundaryWord __attribute__((may_alias));

uint32_t readBoundaryWord(uint32_t address) {
    return *reinterpret_cast<const volatile BoundaryWord *>(
        static_cast<uintptr_t>(address));
}

} // namespace

BucketPrefix *globalPageListFindAddr(const void *target) {
    /* 0x27be48 first: the live count. 0x27be4c second: the live array
     * pointer. lsl r1,r1,#1 at 0x27be50 is a wrapping uint32 shift, then
     * consumed as a SIGNED length (cmp #0 / ble at 0x27be68-0x27be6c). */
    const uint32_t count = g_bucketNumPages;
    const uint32_t baseAddr =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(g_pages));
    int32_t len = static_cast<int32_t>(count << 1);
    uint32_t cursor = baseAddr; /* 0x27be54 mov r2, r5 */
    const uint32_t targetU =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(target));

    for (;;) {                              /* 0x27be68 outer check block */
        if (len <= 0) {                     /* 0x27be6c ble 0x27beac */
            break;
        }
        const int32_t half = len >> 1;      /* 0x27be70 asr r3, r1, #1 */
        const uint32_t mid =
            cursor + (static_cast<uint32_t>(half) << 2); /* 0x27be78 */
        const uint32_t pivot = readBoundaryWord(mid);     /* 0x27be74 */
        if (targetU > pivot) {              /* 0x27be7c cmp r0,r4; 0x27be80 bhi */
            /* mvn+add at 0x27be5c-0x27be64: len += ~half, i.e. the wrapping
             * len - half - 1, written exactly that way. */
            cursor = mid + 4u;
            len = static_cast<int32_t>(
                static_cast<uint32_t>(len) + ~static_cast<uint32_t>(half));
            continue;                       /* 0x27be64 falls into 0x27be68 */
        }
        len = half;                         /* 0x27be84 subs r1, r3, #0 */
        if (half == 0) {                    /* 0x27be8c beq 0x27beac: cursor
                                             * already holds a word >= target */
            break;
        }
        int32_t step = half >> 1;           /* 0x27be88 asr r3, r3, #1 */
        bool steppedToZero = true;
        for (;;) {                          /* 0x27be90..0x27bea8 inner halving,
                                             * entered at least once */
            const uint32_t mid2 =
                cursor + (static_cast<uint32_t>(step) << 2); /* 0x27be94 */
            const uint32_t pivot2 = readBoundaryWord(mid2);  /* 0x27be90 */
            if (pivot2 < targetU) {         /* 0x27be98 cmp r4,r0; 0x27be9c blo
                                             * -> 0x27be5c right-move, unsigned */
                cursor = mid2 + 4u;
                len = static_cast<int32_t>(
                    static_cast<uint32_t>(len) + ~static_cast<uint32_t>(step));
                steppedToZero = false;      /* re-enters the OUTER check */
                break;
            }
            len = step;                     /* 0x27bea0 subs r1, r3, #0 */
            step >>= 1;                     /* 0x27bea4 asr r3, r3, #1 */
            if (len != 0) {
                /* BNE uses SUBS@0x27bea0 (the OLD step copied to len).
                 * ASR@0x27bea4 has no S suffix: old step==1 must execute
                 * one more pivot read with new step==0. */
                continue;                   /* 0x27bea8 bne 0x27be90 */
            }
            break;
        }
        if (!steppedToZero) {
            continue;
        }
        break;                              /* SUBS produced zero: fall through
                                             * to 0x27beac without an outer test */
    }

    /* Tail 0x27beac..0x27bed4. difference = cursor - base as the original
     * 32-bit word (0x27beac rsb r1, r5, r2, r5 still holding the pre-loop
     * base). sign = difference >> 31 unsigned (0x27beb4 lsr). temp = sign +
     * arithmetic_shift_right(difference, 2) (0x27beb8 add r3, r1 asr #2).
     * odd = (temp & 1) - sign (0x27bebc/0x27bec0), computed as the wrapping
     * uint32 subtraction the original rsb performs, so a negative cursor
     * offset (sign==1) can never produce odd==1 - not "index & 1". */
    const uint32_t difference = cursor - baseAddr;
    const uint32_t sign = difference >> 31;
    const uint32_t temp =
        sign + static_cast<uint32_t>(static_cast<int32_t>(difference) >> 2);
    const uint32_t odd = (temp & 1u) - sign;
    if (odd != 1u) {                        /* 0x27bec4 cmp; 0x27becc movne r0,#0 */
        return nullptr;
    }
    /* The table is sorted ascending by raw address word, so the equal-boundary
     * case keeps moving left: a hit on the FIRST boundary leaves cursor==base,
     * odd==0 and returns null, while a hit on the second boundary reads the
     * stored previous boundary address. That asymmetry is the original
     * behaviour; it is not normalised to a [begin,end) convention here. */
    const uint32_t boundary = readBoundaryWord(cursor - 4u); /* 0x27bec8 ldreq [r2,#-4] */
    const uint32_t owner = readBoundaryWord(boundary + 4u);  /* 0x27bed0 ldreq [r3,#4] */
    return reinterpret_cast<BucketPrefix *>(static_cast<uintptr_t>(owner));
}
