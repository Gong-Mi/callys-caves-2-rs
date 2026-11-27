/* tier: bytecode_anchored.
 *
 * Source recovery for two exported C-linkage entries of the original ARMv7
 * ELF libyoyo_armv7.so, SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a:
 *   Timing_Time  0x215148..0x2151b4 (108 bytes, constant pool included)
 *   Timing_Init  0x2151b8..0x2151f0 (56 bytes, constant pool included)
 *
 * Anchors verified against the pool and pc-relative words in original-words.tsv:
 *   - d5 = bits 0x41CD CD65 0000 0000 (1e9) at 0x2151a0, d6 = 0x408F 4000 0000 0000
 *     (1000.0) at 0x2151a8 — both exact IEEE-754 doubles, loaded by vldr before
 *     the multiply-accumulate.
 *   - vmla.f64 at 0x215174 (non-fused single multiply/add), vdiv.f64 at 0x215178.
 *   - conversion helper call at 0x215180 targets 0x3194a0 (__fixdfdi).
 *     The parent primitive probe checked VMLA only; this TU's call is checked separately.
 *   - epoch address: Time 0x215190 + 0x540100 = 0x755290; Init 0x2151d0 + 0x5400C0
 *     = 0x755290. Both touch the same anonymous eight bytes, which is NOT
 *     g_TimingStart at 0x755280.
 *   - Init reaches g_TimingStart through a GOT-style double load (0x2151d4/0x2151d8),
 *     consistent with it being an external real object rather than local storage.
 *
 * gap: clock_gettime failure behaviour, FP exception/trap state, and concurrent
 * double-word epoch accesses are not certified. The original source spelling
 * (including the returned value's signedness) is unknown; this batch honours the
 * observed r0:r1 raw-bit contract. Plain decorated-free names establish C
 * linkage, not the original file's language.
 */

#include "timing.hpp"

/*
 * Timing_Time (0x215148): monotonic clock sample -> whole microseconds as the
 * raw r0:r1 bit pattern, with the anonymous epoch base subtracted modulo 2^64.
 */
extern "C" uint64_t Timing_Time() {
    /* The original passes a stack sample it never pre-initialises; the clock
     * supplies the sample on success; failure remains uncertified. Adding
     * zero-init here would invent a guarantee the bytes do not show. */
    RunnerTimespec32 sample;

    /* clock id literal 1 (CLOCK_MONOTONIC slot); the original discards the
     * return code outright, so nothing here branches on it. */
    (void)clock_gettime(1, &sample);

    /* Original read order: seconds from sample+0, converted first (vcvt.f64.s32
     * at 0x215160), then nanoseconds from sample+4 (0x215170). Both are signed
     * 32-bit into double. */
    const volatile RunnerTimespec32 *const sampled = &sample;
    const double seconds = static_cast<double>(sampled->seconds);
    const double nanoseconds = static_cast<double>(sampled->nanoseconds);

    /* vmla.f64 at 0x215174 computes ns += sec * 1e9 in one non-fused
     * multiply-accumulate; keep that exact instruction, never std::fma. */
    const double totalNanoseconds =
        timing_detail::multiplyAddNonFused(nanoseconds, seconds, 1000000000.0);

    /* vdiv.f64 at 0x215178: nanoseconds -> microseconds by a real division. */
    const double microseconds = totalNanoseconds / 1000.0;

    /* Conversion to the integer pair goes through the original internal helper
     * __fixdfdi (call at 0x215180 -> 0x3194a0), not a C++ cast: the helper's
     * out-of-range/exceptional contract differs and is not re-proven here. */
    const int64_t converted = __fixdfdi(microseconds);

    /* The helper result IS the r0:r1 bit pattern; reinterpret without changing
     * any bit. Only after that does the original read the epoch (ldrd at
     * 0x21518c) low word first, then high, and subtracts it with subs/sbc —
     * plain modulo-2^64 wraparound on unsigned. */
    const uint64_t raw = static_cast<uint64_t>(converted);
    const uint32_t epochLow = g_TimingEpochBase.low;
    const uint32_t epochHigh = g_TimingEpochBase.high;
    const uint64_t epochBase =
        (static_cast<uint64_t>(epochHigh) << 32) | static_cast<uint64_t>(epochLow);
    return raw - epochBase;
}

/*
 * Timing_Init (0x2151b8): rebase the epoch, then snapshot the fresh value into
 * both the anonymous epoch storage and g_TimingStart.
 */
extern "C" void Timing_Init() {
    /* Original order, first: both epoch words at 0x755290 go to zero (strd at
     * 0x2151cc) BEFORE the clock read, so the Time() call below subtracts a
     * zeroed base and returns the raw microsecond count. */
    g_TimingEpochBase.low = 0u;
    g_TimingEpochBase.high = 0u;

    /* Real call through the exported entry (bl at 0x2151d0); Time's own epoch
     * read and returned-bit copy stay inside it — no inlining of this boundary
     * and no reuse of g_TimingStart as a variable to compute with. */
    const uint64_t snapshot = Timing_Time();

    /* Same snapshot lands in the epoch (strd at 0x2151dc, low word r0 first)
     * and only then in g_TimingStart (strd at 0x2151e0). Both are external
     * real state; this file defines neither — no global, no stub here. */
    g_TimingEpochBase.low = static_cast<uint32_t>(snapshot);
    g_TimingEpochBase.high = static_cast<uint32_t>(snapshot >> 32);
    g_TimingStart.low = static_cast<uint32_t>(snapshot);
    g_TimingStart.high = static_cast<uint32_t>(snapshot >> 32);
}
