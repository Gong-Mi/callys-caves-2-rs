#include "profiler_node_wire.hpp"
#include "vm_exec.hpp"

/* CProfiler::FindOrCreateNode(int kind, int id), original 0x2a04f4..0x2a06d0,
 * dynsym size 476 bytes = 119 words (118 code words + 1 literal-pool word at
 * 0x2a06cc); exclusive endpoint 0x2a06d0 is AddNodeDirect's first byte, so
 * that neighbouring entry is NOT swallowed. tier: bytecode_anchored,
 * pinned ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Stats header here is capacity+0/count+4/data+8 (Push's frame header is
 * data+0/count+4/cap+8; do not confuse them). Records stride 40 bytes, packed
 * kind4/id28 word at +0, firstChild+0x18, sibling+0x1c; record+4..7 and
 * +0x24..0x27 hexadecimal stay untouched (byte staging, no 40-byte memset, no
 * word packing).
 * Lookup compares the FULL raw requested id/kind against the stored packed
 * fields; the 28-bit id mask and 4-bit kind mask are applied ONLY on the
 * creation path (0x2a0580/0x2a0588), never before the comparison.
 * The grow path keeps two distinct receivers: this+0x70 and this+0x0c are
 * re-read LIVE after the ReAlloc callback (r6 = LIVE header, which may differ),
 * while the re-read count and the published newData still use the HELD old
 * header (r7). The fast path keeps r6 = held header and the pre-call data /
 * parent-offset snapshot. this+0x70 is never written back here; there is no
 * allocation-failure guard and no bad/cyclic-chain guard, because the original
 * has none.
 * gap: MemoryManager::ReAlloc body remains owed (declaration-only interface in
 * vm_buffer.hpp, 0x27cedc, verified rc0 at O0/O2 with the frozen
 * profiler_node_wire.hpp). Complete containers, producers, reentrant field
 * mutation during the callback, bad/cyclic tables and concurrency/unwind are
 * unproved. No target was executed; structure recovery, not runtime
 * equivalence.
 */
namespace {

/* 0x2a05ac pool word 0x2a06cc: 0x2a05c4 + 0x000b96b0 resolves the literal at
 * 0x359c7c. The ReAlloc tag names Debug/Profiler.h line 104. */
const char profilerNodeSourcePath[] =
    "jni/../jni/yoyo/../../../Files/Debug/Profiler.h";

constexpr uint32_t kSentinel = 0xFFFFFFFFu; // -1 chain terminator (cmn #1 / beq)

} // namespace

uint32_t CProfiler::FindOrCreateNode(int kind, int id) {
    static_assert(__is_standard_layout(CProfiler) && offsetof(CProfiler, unknownStorage) == 0,
                  "candidate first storage member is address-identical to the receiver");
    const uint32_t profiler = object_wire::address(unknownStorage);

    // 0x2a04fc..0x2a0514: HELD receivers snapshotted once at entry.
    uint32_t linkReceiver = profiler; // r6: this pre-create; fast path -> held header
    const uint32_t parentIndex = object_wire::read(profiler, 0x70); // 0x2a04fc first
    const uint32_t held = object_wire::read(profiler, 0x0c); // 0x2a0504 HELD statsHeader
    uint32_t parentOffset = parentIndex * 40u; // r8, uint32 wrap
    const uint32_t heldData = object_wire::read(held, 0x08); // r12 data snapshot
    uint32_t nodeData = heldData; // r12: still the snapshot until a grow publishes

    // 0x2a0518..0x2a053c: walk starts at the parent record's firstChild and
    // follows +0x1c siblings until -1. r0(lastIndex)/r4(currentIndex) are
    // kept as distinct variables exactly like the register pair; direct
    // creation (firstChild == -1, 0x2a0520 beq) leaves r0 holding the entry
    // value of r0 = this and r4 = -1, and a negative match restores r4 = r0
    // (0x2a0568 blt -> 0x2a0578 mov r4, r0). No loop or bad-index guards.
    uint32_t current = object_wire::read(heldData + parentOffset, 0x18); // r4
    uint32_t lastIndex = profiler; // r0 as-is on the direct-create path
    if (current != kSentinel) {
        uint32_t record = heldData + current * 40u;
        lastIndex = current; // 0x2a0524 mov r0, r4 before the first body
        for (;;) {
            record = heldData + current * 40u; // 0x2a0540..0x2a0548 (r12 snapshot)
            // 0x2a054c..0x2a0560: word0 low 28 vs FULL requested id, then
            // byte+3 >> 4 vs FULL requested kind; raw equality both times.
            const bool idMatch =
                (object_wire::read(record, 0x00) & 0x0FFFFFFFu) ==
                static_cast<uint32_t>(id);
            const bool kindMatch = idMatch &&
                (profiler_node_wire::readByte(record, 0x03u) >> 4) ==
                static_cast<uint32_t>(kind); // original BNE skips this byte read on id mismatch
            if (kindMatch) {
                if (static_cast<int32_t>(current) >= 0) {
                    return current; // 0x2a056c..0x2a0574: matched non-negative index
                }
                current = lastIndex; // 0x2a0578 mov r4, r0 (negative-match create)
                break;
            }
            const uint32_t sibling = object_wire::read(record, 0x1c); // 0x2a052c
            lastIndex = current; // 0x2a0530 r0 = r4 BEFORE r4 advances
            if (sibling == kSentinel) {
                break; // 0x2a0538: create; r0 == r4 == last walked node
            }
            current = sibling; // 0x2a053c
        }
    }

    // 0x2a057c..0x2a059c: creation path. Masks happen HERE, not earlier.
    const uint32_t createId = static_cast<uint32_t>(id) & 0x0FFFFFFFu; // 0x2a0580 bic
    const uint32_t kind4 = static_cast<uint32_t>(kind) & 15u;          // 0x2a0588 and
    const uint32_t capacity = object_wire::read(held, 0x00);           // 0x2a057c ldr r3,[r7]
    uint32_t count = object_wire::read(held, 0x04);                    // 0x2a0584
    // 0x2a058c..0x2a059c: no grow iff SIGNED count < SIGNED (capacity-1) with
    // the uint32-wrapped capacity-1; count >= cap-1 grows.
    if (static_cast<int32_t>(count) >= static_cast<int32_t>(capacity - 1u)) {
        // 0x2a05a0..0x2a05a4: HELD cap = oldcap << 1 is published BEFORE ReAlloc.
        const uint32_t newCapacity = capacity << 1;
        object_wire::write(held, 0x00, newCapacity);
        // 0x2a05a8/0x2a05bc: byte size (newcap + oldcap*8) * 8 == 80*oldcap,
        // every step uint32 wrap. r0 = HELD olddata, tag@0x359c7c line 104,
        // stack-passed false word from r12 (0x2a05c0).
        const uint32_t reallocBytes = (newCapacity + capacity * 8u) * 8u;
        nodeData = object_wire::address(MemoryManager::ReAlloc(
            reinterpret_cast<void *>(static_cast<uintptr_t>(heldData)),
            reallocBytes, profilerNodeSourcePath, 104, false));
        // 0x2a05cc..0x2a05e4: post-callback re-reads with distinct receivers.
        parentOffset = object_wire::read(profiler, 0x70) * 40u; // r8 from LIVE this
        count = object_wire::read(held, 0x04);                  // r1 from HELD old+4
        linkReceiver = object_wire::read(profiler, 0x0c);       // r6 = LIVE header
        object_wire::write(held, 0x08, nodeData);               // newData -> HELD old+8
    } else {
        linkReceiver = held; // 0x2a0598 movlt r6, r7; fast path keeps held + snapshot
    }

    // 0x2a05e8..0x2a05f0: common newIndex = count; HELD count = count+1 is
    // published BEFORE the record is initialized.
    const uint32_t newIndex = count;
    object_wire::write(held, 0x04, count + 1u);

    // 0x2a05f4..0x2a0698: byte staging in original order; +4..7 and +0x24..27
    // are never touched. The old +3 byte is read even though BFI later
    // replaces its high nibble with kind4; its low nibble keeps id bits [24:28).
    const uint32_t recordBase = nodeData + count * 40u; // 0x2a0600 r3 = r12 + r2
    profiler_node_wire::writeByte(recordBase, 0x00u,
                                  static_cast<uint8_t>(createId)); // 0x2a0608
    const uint8_t oldByte3 = profiler_node_wire::readByte(recordBase, 0x03u); // 0x2a0610
    profiler_node_wire::writeByte(recordBase, 0x01u,
                                  static_cast<uint8_t>(createId >> 8)); // 0x2a0614 r10
    profiler_node_wire::writeByte(recordBase, 0x02u,
                                  static_cast<uint8_t>(createId >> 16)); // 0x2a061c r7
    uint8_t packedByte3 = static_cast<uint8_t>(oldByte3 & ~15u); // 0x2a0618 bic
    packedByte3 = static_cast<uint8_t>(
        packedByte3 | static_cast<uint8_t>(createId >> 24)); // 0x2a0620 orr
    profiler_node_wire::writeByte(recordBase, 0x08u, 0u); // 0x2a0624
    profiler_node_wire::writeByte(recordBase, 0x09u, 0u); // 0x2a0628
    packedByte3 = static_cast<uint8_t>(
        (packedByte3 & 15u) | static_cast<uint8_t>(kind4 << 4)); // BFI REPLACES bits4..7, not OR
    profiler_node_wire::writeByte(recordBase, 0x0Au, 0u); // 0x2a0630 (+A lands before +3)
    profiler_node_wire::writeByte(recordBase, 0x03u, packedByte3); // 0x2a0634
    profiler_node_wire::writeByte(recordBase, 0x0Bu, 0u); // 0x2a0638..0x2a0658
    profiler_node_wire::writeByte(recordBase, 0x0Cu, 0u);
    profiler_node_wire::writeByte(recordBase, 0x0Du, 0u);
    profiler_node_wire::writeByte(recordBase, 0x0Eu, 0u);
    profiler_node_wire::writeByte(recordBase, 0x0Fu, 0u);
    profiler_node_wire::writeByte(recordBase, 0x10u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x11u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x12u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x13u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x14u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x15u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x16u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x17u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x20u, 0u); // 0x2a066c..0x2a0674
    profiler_node_wire::writeByte(recordBase, 0x21u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x22u, 0u);
    profiler_node_wire::writeByte(recordBase, 0x18u, 0xFFu); // 0x2a0678..0x2a0694 -1
    profiler_node_wire::writeByte(recordBase, 0x19u, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Au, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Bu, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Cu, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Du, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Eu, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x1Fu, 0xFFu);
    profiler_node_wire::writeByte(recordBase, 0x23u, 0u); // 0x2a0698 final byte

    // 0x2a069c..0x2a06c0: link under the r6 receiver. data is read live from
    // r6+8 (held on fast, LIVE header on grow); parentOffset is the snapshot
    // on fast and recomputed on grow. The signed CMP r2 vs 0 (0x2a06a8) is the
    // sole decision; its flags ride unchanged over the later non-S
    // arithmetic/assignments, so the tail path is NOT re-decided from the
    // tail/newIndex values.
    const uint32_t linkData = object_wire::read(linkReceiver, 0x08); // 0x2a069c
    const uint32_t parentRecord = linkData + parentOffset; // 0x2a06a0
    const uint32_t parentFirstChild = object_wire::read(parentRecord, 0x18); // 0x2a06a4
    if (static_cast<int32_t>(parentFirstChild) < 0) { // cmp r2, r0 (=0)
        object_wire::write(parentRecord, 0x18, newIndex); // 0x2a06ac strlt
    } else {
        // 0x2a06b0..0x2a06c0 strge: tail = data + current*40 with the HELD r4
        // (last walked node; 0xFFFFFFFF on direct create, lastIndex after a
        // negative match). uint32 wrap address.
        object_wire::write(linkData + current * 40u, 0x1c, newIndex);
    }

    // 0x2a06b8 mov r4, r1 / 0x2a06bc mov r0, r4: return the new INDEX.
    return newIndex;
}
