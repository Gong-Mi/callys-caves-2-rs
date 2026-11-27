#include "profiler_push_wire.hpp"
#include "vm_exec.hpp"

/* CProfiler::Push(int, int), original 0x2a0738..0x2a0870, 312 bytes =
 * 77 instruction words + 1 literal pool word. tier: bytecode_anchored,
 * pinned ARMv7 ELF SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * FindOrCreateNode stays a declaration-only debt returning the node INDEX
 * (this+0x70 / frame+8), not a pointer; Timing_Time/MMAlloc/MMFree are the
 * committed real bodies. No target was executed; this is structure recovery,
 * not a runtime equivalence claim.
 * gap: the 24-byte local stack image initializes ONLY kind/id/nodeIndex; the
 * three tail words (+0xc/+0x10/+0x14) are unauthenticated private-stack
 * garbage copied verbatim through the parent rc0 raw primitive (no zero
 * fill). ldrd/strd paired atomicity, the null-selection tail store fault and
 * unwinding are not certified.
 */
extern "C" void *memcpy(void *destination, const void *source, size_t length);

namespace {

/* 0x2a081c / pool 0x2a086c: 0x2a0834 + 0x000b49d8 resolves to the literal
 * at 0x35520c. The Alloc tag names PhysicsContactStack.h line 40. */
const char profilerPushSourcePath[] =
    "jni/../jni/yoyo/../../../Files/Physics/PhysicsContactStack.h";

uint64_t readPair(uint32_t base, uint32_t offset) {
    const uint32_t low = object_wire::read(base, offset);
    const uint32_t high = object_wire::read(base, offset + 4u);
    return static_cast<uint64_t>(low) | (static_cast<uint64_t>(high) << 32);
}
void writePair(uint32_t base, uint32_t offset, uint64_t value) {
    object_wire::write(base, offset, static_cast<uint32_t>(value));
    object_wire::write(base, offset + 4u, static_cast<uint32_t>(value >> 32));
}

} // namespace

void CProfiler::Push(int kind, int id) {
    const uint32_t profiler = object_wire::address(unknownStorage);

    // 0x2a074c: capture the raw first64 BEFORE FindOrCreateNode.
    const uint64_t firstTime = Timing_Time();

    // 0x2a0764: node index return (canonical FindOrCreateNode debt).
    const uint32_t nodeIndex = FindOrCreateNode(kind, id);

    // 0x2a0768..0x2a0788: held header, count/capacity read, this+0x70 and
    // the three defined words of the local image. count == capacity ONLY
    // grows; >= would be wrong.
    const uint32_t heldHeader = object_wire::read(profiler, 0x08);
    volatile ProfilerPushFrameImage image;
    image.kind = static_cast<uint32_t>(kind);
    image.id = static_cast<uint32_t>(id);
    uint32_t count = object_wire::read(heldHeader, 0x04);
    const uint32_t capacity = object_wire::read(heldHeader, 0x08);
    object_wire::write(profiler, 0x70, nodeIndex);
    image.nodeIndex = nodeIndex;

    uint32_t frames;
    if (count == capacity) {
        // 0x2a0818..0x2a0834: newcap and byte size are uint32 wraps
        // (add 10; *3<<3). Alloc(file@0x35520c, 40, true).
        const uint32_t newCap = count + 10u;
        const uint32_t allocBytes = newCap * 24u;
        const uint32_t heldNew = object_wire::address(
            MemoryManager::Alloc(allocBytes, profilerPushSourcePath, 40, true));
        // 0x2a0838..0x2a0844: LIVE re-read of the HELD header AFTER the
        // callback: capacity (+8) supplies the copy length, data (+0) the
        // source. Neither value is cached from before Alloc. memcpy's
        // return is NOT consumed; only the HELD Alloc result is used.
        const uint32_t copyBytes = object_wire::read(heldHeader, 0x08) * 24u;
        const uint32_t oldData = object_wire::read(heldHeader, 0x00);
        memcpy(reinterpret_cast<void *>(static_cast<uintptr_t>(heldNew)),
               reinterpret_cast<const void *>(static_cast<uintptr_t>(oldData)),
               copyBytes);
        // 0x2a0850..0x2a0864: re-read header data LIVE for Free, re-read
        // count AFTER Free, then publish newCap and heldNew in that order.
        MemoryManager::Free(reinterpret_cast<const void *>(
            static_cast<uintptr_t>(object_wire::read(heldHeader, 0x00))));
        count = object_wire::read(heldHeader, 0x04);
        object_wire::write(heldHeader, 0x08, newCap);
        object_wire::write(heldHeader, 0x00, heldNew);
        frames = heldNew; // join: r9 = r10, the HELD Alloc pointer
    } else {
        // 0x2a078c: the non-grow path reads the HELD data pointer only
        // here, after the branch decision.
        frames = object_wire::read(heldHeader, 0x00);
    }

    // 0x2a0790..0x2a07bc: raw 24-byte move into frames + count*24 (uint32
    // address wrap), tail garbage included via the rc0 primitive.
    profiler_push_wire::copyFrame24(frames + count * 24u, &image);

    // 0x2a07c0..0x2a07d0: LIVE re-read this+8 first, then HELD count +1
    // publish, then ONE captured live-header read of data/count.
    const uint32_t liveHeader = object_wire::read(profiler, 0x08);
    const uint32_t heldCount = object_wire::read(heldHeader, 0x04);
    object_wire::write(heldHeader, 0x04, heldCount + 1u);
    const uint32_t liveData = object_wire::read(liveHeader, 0x00);
    const uint32_t liveCount = object_wire::read(liveHeader, 0x04);

    // 0x2a07d4..0x2a07e4: signed gate only. The newest frame is
    // data + count*24 - 24; otherwise the selection is null and NO guard
    // replaces the original's unconditional tail store.
    uint32_t selectedFrame = 0u;
    if (static_cast<int32_t>(liveCount) > 0) {
        selectedFrame = liveData + liveCount * 24u - 24u;
    }

    // 0x2a07e8..0x2a080c: second Timing_Time only AFTER selection; base is
    // read live after that call. delta = base_afterSecond - firstTime;
    // this.base = secondTime + delta, frame+16 = 0 - delta, all u64 wrap.
    const uint64_t secondTime = Timing_Time();
    const uint64_t baseAfterSecond = readPair(profiler, 0x00);
    const uint64_t delta = baseAfterSecond - firstTime;
    writePair(profiler, 0x00, secondTime + delta);
    writePair(selectedFrame, 0x10, 0ull - delta);
}
