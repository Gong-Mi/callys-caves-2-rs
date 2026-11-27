#include "vm_exec.hpp"

/* CProfiler::Pop(), original 0x2a08ac..0x2a0960 (45 ARM words, no pool).
 * tier: bytecode_anchored; ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * gap: opaque object/frame fields, timing unit and original return spelling
 * remain unresolved; this batch's caller ignores the result. No target was
 * executed. Paired-transfer atomicity, invalid-pointer/empty-stack faults and
 * exception unwinding are not certified by these word-wise source accesses.
 */
extern "C" uint64_t Timing_Time(); // original internal 0x215148, not a stub

namespace {
using ProfileWord = uint32_t __attribute__((may_alias));

uint32_t addressOf(const void *p) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}
uint32_t readWord(uint32_t base, uint32_t offset) {
    return *reinterpret_cast<const volatile ProfileWord *>(
        static_cast<uintptr_t>(base + offset));
}
void writeWord(uint32_t base, uint32_t offset, uint32_t value) {
    *reinterpret_cast<volatile ProfileWord *>(
        static_cast<uintptr_t>(base + offset)) = value;
}
uint64_t readPair(uint32_t base, uint32_t offset) {
    const uint32_t low = readWord(base, offset);
    const uint32_t high = readWord(base, offset + 4u);
    return static_cast<uint64_t>(low) | (static_cast<uint64_t>(high) << 32);
}
void writePair(uint32_t base, uint32_t offset, uint64_t value) {
    writeWord(base, offset, static_cast<uint32_t>(value));
    writeWord(base, offset + 4u, static_cast<uint32_t>(value >> 32));
}
} // namespace

void CProfiler::Pop() {
    const uint32_t profiler = addressOf(unknownStorage);

    // 0x2a08b4..0x2a08c4: clock FIRST, then stack, base pair, stats and header.
    const uint64_t now = Timing_Time();
    const uint32_t stack = readWord(profiler, 0x08);
    const uint64_t baseTick = readPair(profiler, 0x00);
    const uint32_t stats = readWord(profiler, 0x0c);
    const uint32_t frames = readWord(stack, 0x00);
    const uint32_t oldCount = readWord(stack, 0x04);
    const uint64_t elapsed = now - baseTick;

    // 0x2a08d0..0x2a08e4: SUBGT has NO S suffix. Address selection still
    // uses the OLD count's CMP flags: oldCount==1 selects frames[0], not null.
    const bool hadFrame = static_cast<int32_t>(oldCount) > 0;
    const uint32_t remaining = hadFrame ? oldCount - 1u : oldCount;
    if (hadFrame) {
        writeWord(stack, 0x04, remaining);
    }
    const uint32_t frame = hadFrame ? frames + remaining * 24u : 0u;

    // 0x2a08e8..0x2a0900: no empty-stack/bounds guard is invented. Retain
    // BOTH excluded-tick words, although the adjusted high word is later dead.
    const uint32_t entryId = readWord(frame, 0x08);
    const uint64_t excluded = readPair(frame, 0x10);
    const uint32_t records = readWord(stats, 0x08);
    const uint32_t adjustedLow = static_cast<uint32_t>(elapsed - excluded);
    const uint32_t record = records + entryId * 40u; // ARM32 address wrap

    // 0x2a0904..0x2a0910: snapshot count pair, accumulated-tick pair, low sum.
    const uint64_t calls = readPair(record, 0x08);
    const uint64_t ticks = readPair(record, 0x10);
    const uint32_t lowSum = readWord(record, 0x20);

    // 0x2a0900 overwrites the adjusted HIGH word. ADDS/ADC #0 at
    // 0x2a0918/0x2a091c adds ZERO-EXTENDED LOW32, not the full 64-bit delta.
    // 0x2a0928..0x2a0930: pair -> pair -> word publication order.
    writePair(record, 0x08, calls + 1u);
    writePair(record, 0x10, ticks + static_cast<uint64_t>(adjustedLow));
    writeWord(record, 0x20, lowSum + adjustedLow);

    // 0x2a0920..0x2a0958: this later comparison DOES use the remaining count.
    // Parent address is tested after 32-bit arithmetic, even if it wraps to 0.
    uint32_t parentId = 0;
    if (static_cast<int32_t>(remaining) > 0) {
        const uint32_t parentFrame = frames + remaining * 24u - 24u;
        if (parentFrame != 0) {
            parentId = readWord(parentFrame, 0x08);
        }
    }
    writeWord(profiler, 0x70, parentId);
}
