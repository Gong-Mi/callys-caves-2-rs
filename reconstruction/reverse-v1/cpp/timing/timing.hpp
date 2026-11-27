#ifndef CALLY_RECOVERED_TIMING_HPP
#define CALLY_RECOVERED_TIMING_HPP

#include "../vm_buffer/vm_buffer.hpp"

/* tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Timing_Time 0x215148..0x2151b4, Timing_Init 0x2151b8..0x2151f0.
 * Plain names establish C linkage, not an independently proven source-file
 * language. This runner module uses C++ with the original exported C ABI.
 * gap: clock_gettime failure, FP exception/trap and epoch concurrency domains
 * are not certified. Globals and conversion helper are declarations only.
 */
struct RunnerTimespec32 { int32_t seconds, nanoseconds; };
struct alignas(8) TimingWords { uint32_t low, high; };

/* Descriptive binding for the anonymous original eight bytes at 0x755290;
 * both Time's LDRD and Init's STRD target it. It is NOT g_TimingStart+0. */
extern volatile TimingWords g_TimingEpochBase;
extern volatile TimingWords g_TimingStart;            // real exported object at 0x755280

extern "C" {
int32_t clock_gettime(int32_t clockId, RunnerTimespec32 *sample);
int64_t __fixdfdi(double value);                      // internal ARM helper 0x3194a0
uint64_t Timing_Time() __attribute__((noinline));      // preserve Init's explicit call boundary; raw r0:r1 bits
void Timing_Init();
}

/* Preserve the exact non-fused VFPv3 multiply/add instruction. Using this
 * narrow ISA primitive avoids silently substituting a fused FMA or dropping
 * its FP-environment behaviour; no claim about all trap domains is implied. */
namespace timing_detail {
inline double multiplyAddNonFused(double addend, double left, double right) {
    __asm__ volatile("vmla.f64 %P0, %P1, %P2"
                     : "+w"(addend) : "w"(left), "w"(right));
    return addend;
}
}
#endif
