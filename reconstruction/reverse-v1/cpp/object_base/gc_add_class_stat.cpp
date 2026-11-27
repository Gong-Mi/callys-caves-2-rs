/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers exactly one body, word-ordered against the full window
 * gc-lifecycle-anchors/add-class-stat.asm.txt:
 *   CGCGeneration::AddClassStat(const char*)
 *   _ZN13CGCGeneration12AddClassStatEPKc 0x191578..0x191710, 408B GLOBAL
 *   (push {r4-r9,lr}, sub sp,sp,#12). The two tail pool words 0x191708
 *   (0x0019fa2c) and 0x19170c (0x0019f9ac) resolve through PC+8
 *   (add r1,pc,r1 @0x191604 pc=0x19160c; add r2,pc,r2 @0x191684
 *   pc=0x19168c) to the SAME .rodata tag @0x331038, byte-verified in the
 *   original file: "jni/../jni/yoyo/../../../Platform/MemoryManager.h".
 * Structure recovered verbatim: entry reads the HELD count (+0x4c, r6,
 * 0x191588) THEN the HELD table (+0x48, r5, 0x19158c) before the
 * name-NULL branch (subs 0x19157c / beq 0x191590) — the table loads even
 * when NULL; the non-NULL-name scan calls real strcmp (0x1915bc) ONLY for
 * slots whose name word is non-NULL (cmp/beq 0x1915b4/0x1915b8) and, on a
 * hit, increments +4 through the held slot address r8 formed BEFORE the
 * call (0x1915b0, 0x19164c..0x191654), popping without touching
 * +0x4c/+0x50/+0x48; the NULL-name scan compares the slot+0 payload word
 * against zero with NO strcmp (slot 0 peeled at 0x1916bc..0x1916d0, rest
 * ldr r1,[r2],#8 at 0x1916d4; hit 0x1916f8..0x191700 increments +4 and
 * pops the same way); only after a scan miss is the capacity (+0x50) read
 * (0x1915d4); growth keys on the raw equality cap == heldCount
 * (cmp/beq 0x1915d8/0x1915dc): lsls r3,r6,#1 — the doubled word is
 * published to +0x50 BEFORE the ReAlloc edge (strne 0x191668 / moveq+streq
 * 0x191670..0x191678 for the zero-doubling fallback cap=1/bytes=8), bytes
 * = heldCount<<4 wrap32 (lslne 0x19166c), then the real
 * ReAlloc(HELD table r5, bytes, tag@0x331038, line 74, false in [sp]) at
 * 0x191690 with the LIVE +0x4c re-read (0x191694) BEFORE the new table is
 * published to +0x48 (0x1916a0); the non-empty append (fall-through
 * 0x1915ec, or bne 0x1916ac re-entry after the grow edge, so strlen runs
 * after ReAlloc) reads the LIVE count (0x191610) then the LIVE table
 * (0x191614) after the Alloc return (bl 0x19160c: strlen+1,
 * tag@0x331038, line 70, hasHeader true), stores the Alloc result into
 * the HELD slot word (str r0,[r5,r6,lsl#3] 0x19161c), LOADS the strcpy
 * destination from the live table word at the live index (ldr
 * r0,[r3,r2,lsl#3] 0x191620 — never the Alloc result nor a held
 * substitute) and calls real strcpy (0x191624), then re-reads LIVE count
 * (0x191628) then LIVE table (0x19162c) and adds the index (0x191630) to
 * pick the tail slot; the shared tail adds 1 (0x191634), stores slot+4 = 1
 * FIRST (0x19163c) and the generation +0x4c count+1 store is LAST
 * (0x191640). The NULL-name append writes the zero name word straight
 * into the selected slot (streq r7 0x1915e4 no-grow / 0x1916a4 post-grow,
 * addeq slot address 0x1915e8/0x1916a8). Widths: every count, capacity,
 * name-pointer and slot-counter access is a plain 32-bit ldr/str; the
 * walks use cmp/bne equality against the raw word, so a negative held
 * count wraps the 32-bit walk instead of terminating. The slot words are
 * moved through the seam's may_alias volatile RawWord helpers (precedent:
 * gc_mutable_roots.cpp readRawWord, gc_add_root.cpp writeRawWord): at
 * -O2 a plain typed slot store need not stay ordered with the volatile
 * CGCGeneration::classStatsCount4c store. The reordered shape breaks the
 * 0x19163c-before-0x191640 order; the volatile raw words pin the width,
 * the address form and the store order at both -O0 and -O2.
 * gap: faults (a nonzero held count over a NULL table faults at the scan
 * ldr 0x1915a4; no ReAlloc/Alloc NULL-result check exists in the original;
 * count > cap skips the == grow and overruns the block — original
 * behaviour), unwind/EHABI records, exceptions, concurrency (held-vs-live
 * windows are plain memory) and any equivalence-by-execution claim remain
 * unproved; the original was never run for this recovery. This TU closes
 * the producer of the same 8B name/count slot whose +0 the recovered
 * consumer ResetClassStats (0x191530, gc_mutable_roots.cpp) frees.
 */
#include "gc_generation.hpp"

namespace {

typedef uint32_t RawWord __attribute__((may_alias));

/* Seam-precedent raw 32-bit word access at a computed address (plain
 * ldr/str width, direct address, no object walk). */
inline uint32_t readRawWord(uint32_t address) {
    return *reinterpret_cast<const volatile RawWord *>(static_cast<uintptr_t>(address));
}
inline void writeRawWord(uint32_t address, uint32_t value) {
    *reinterpret_cast<volatile RawWord *>(static_cast<uintptr_t>(address)) = value;
}

inline uint32_t wordOf(const void *p) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}
inline char *pointerOf(uint32_t w) {
    return reinterpret_cast<char *>(static_cast<uintptr_t>(w));
}

/* Both pc-relative pools (0x191604/0x191684) land on the same .rodata tag
 * @0x331038 the sibling seam edges publish; byte-verified at that offset. */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";

} // namespace

/* Real libc imports consumed by this body (image PLT stubs): */
extern "C" {
int strcmp(const char *, const char *); // strcmp@plt, bl at 0x1915bc
size_t strlen(const char *);            // strlen@plt, bl at 0x1915f4
char *strcpy(char *, const char *);     // strcpy@plt, bl at 0x191624
}

void CGCGeneration::AddClassStat(const char *name) {
    volatile CGCGeneration &self = *this;

    /* 0x191588 ldr r6,[r0,#76] THEN 0x19158c ldr r5,[r0,#72]: HELD count
     * first, HELD table second; the table word loads even when NULL, all
     * before the 0x191590 name-NULL branch. */
    int32_t heldCount = self.classStatsCount4c;
    GCClassStatEntry *heldTable = self.classStatsArray48;

    /* cmp/bne equality walk against the raw held word (0x1915c8/0x1916e8):
     * the bound is the 32-bit value; negatives wrap the walk. */
    const uint32_t bound = static_cast<uint32_t>(heldCount);

    if (name != nullptr) {
        /* 0x191594..0x1915d0 positive-name scan: the slot address is
         * formed before the call (0x1915b0 add r8) and the hit +4 rides
         * on that held address (0x19164c..0x191654, loaded AFTER strcmp
         * returns); strcmp runs only for a non-NULL slot name. */
        const uint32_t base = wordOf(heldTable); /* r5, unchanged across the walk */
        for (uint32_t i = 0; i != bound; ++i) {
            const uint32_t slot = base + (i << 3u);        /* 0x1915a4/0x1915b0 */
            const uint32_t slotNameWord = readRawWord(slot);
            if (slotNameWord == 0u) {
                continue;                                   /* 0x1915b8 no-strcmp skip */
            }
            if (strcmp(pointerOf(slotNameWord), name) == 0) {
                writeRawWord(slot + 4u, readRawWord(slot + 4u) + 1u); /* 0x19164c.. */
                return;                                     /* 0x191658 pop */
            }
        }
    } else {
        /* 0x1916b4..0x1916f0 NULL-name scan: the slot+0 payload word is
         * compared against zero (0x1916c0/0x1916d8) and strcmp is NEVER
         * called; a hit increments that held slot's +4 (0x1916f8..) and
         * pops — the generation count is not touched on either hit path. */
        const uint32_t base = wordOf(heldTable);
        for (uint32_t i = 0; i != bound; ++i) {
            const uint32_t slot = base + (i << 3u);
            if (readRawWord(slot) == 0u) {
                writeRawWord(slot + 4u, readRawWord(slot + 4u) + 1u);
                return;
            }
        }
    }

    /* 0x1915d4 scan miss: ONLY now is the capacity word read. */
    if (self.classStatsCapacity50 == heldCount) {
        /* 0x191660 lsls r3,r6,#1: the 32-bit wrap of heldCount<<1 drives
         * BOTH the +0x50 store and the byte size via ne/eq; the new
         * capacity is published BEFORE the ReAlloc edge. The doubled-to-
         * zero case (heldCount 0 or 0x80000000) picks cap=1/bytes=8. */
        const uint32_t doubled = static_cast<uint32_t>(heldCount) << 1u;
        unsigned int bytes;
        if (doubled != 0u) { /* 0x191668 strne / 0x19166c lslne r1,r6,#4 */
            self.classStatsCapacity50 = static_cast<int32_t>(doubled);
            bytes =
                static_cast<unsigned int>(static_cast<uint32_t>(heldCount) << 4u);
        } else { /* 0x191670/0x191674 moveq, 0x191678 streq */
            self.classStatsCapacity50 = 1;
            bytes = 8u;
        }
        /* 0x19167c mov r0,r5 feeds the HELD table into the real edge; the
         * false bool is the stack slot str r3,[sp] at 0x191688 with r3=#0,
         * written BEFORE r3:=74 at 0x19168c; tag via pool 0x19170c. */
        void *const grown = MemoryManager::ReAlloc(
            heldTable, bytes, memoryManagerHeaderSourcePath, 74, false);
        /* 0x191694 ldr r6,[r9,#76]: LIVE count re-read FIRST, then
         * 0x19169c mov r5,r0 / 0x1916a0 str r0,[r9,#72] publish. */
        heldCount = self.classStatsCount4c;
        heldTable = static_cast<GCClassStatEntry *>(grown);
        self.classStatsArray48 = heldTable;
    }

    uint32_t fillSlot; /* the tail r5 = slot address (0x1915e8/0x1916a8/0x191630) */
    if (name == nullptr) {
        /* 0x1915e4 streq r7,[r5,r6,lsl#3] (no-grow: entry-held r5/r6) or
         * 0x1916a4 (post-grow: new table, LIVE-re-read count): the zero
         * name word goes straight into the selected slot+0. */
        fillSlot = wordOf(heldTable) + (static_cast<uint32_t>(heldCount) << 3u);
        writeRawWord(fillSlot, 0u);
    } else {
        /* 0x1915f0..0x191630 non-empty append; the grow edge re-enters at
         * 0x1915f0 (bne 0x1916ac), so strlen runs AFTER the ReAlloc edge. */
        /* 0x1915f4 bl strlen; 0x1915fc/0x191600/0x191604 set r3=#1,
         * r2=#70, r1=tag; 0x191608 add r0,r0,r3 forms len+1 BEFORE the
         * call at 0x19160c (hasHeader true). */
        const size_t len = strlen(name);
        char *const copy = static_cast<char *>(MemoryManager::Alloc(
            static_cast<unsigned int>(len + 1u),
            memoryManagerHeaderSourcePath, 70, true));
        /* 0x191610 ldr r2,[r9,#76] THEN 0x191614 ldr r3,[r9,#72]: after
         * the Alloc return the LIVE count is read before the LIVE table. */
        const uint32_t liveCount =
            static_cast<uint32_t>(self.classStatsCount4c);
        const uint32_t liveBase = wordOf(self.classStatsArray48);
        /* 0x19161c str r0,[r5,r6,lsl#3]: the Alloc result goes into the
         * HELD slot (held r5 + held r6<<3), ... */
        writeRawWord(wordOf(heldTable) + (static_cast<uint32_t>(heldCount) << 3u),
                     wordOf(copy));
        /* 0x191620 ldr r0,[r3,r2,lsl#3] THEN 0x191624 bl strcpy: the copy
         * destination is LOADED from the live table word at the live
         * index (it observes the store above in the ordinary case); the
         * Alloc result and the held slot are never substituted for this
         * load. */
        strcpy(pointerOf(readRawWord(liveBase + (liveCount << 3u))), name);
        /* 0x191628 ldr r6,[r9,#76] THEN 0x19162c ldr r5,[r9,#72] THEN
         * 0x191630 add r5,r5,r6,lsl#3: after the copy returns, LIVE count
         * then LIVE table decide the tail slot. */
        heldCount = self.classStatsCount4c;
        const uint32_t tailBase = wordOf(self.classStatsArray48);
        fillSlot = tailBase + (static_cast<uint32_t>(heldCount) << 3u);
    }

    /* Shared tail 0x191634..0x191640: the slot's count=1 store comes
     * FIRST (str r3,[r5,#4] 0x19163c) and the generation +0x4c count+1
     * store is LAST (str r6,[r9,#76] 0x191640); +0x50 is written only on
     * the grow edge above. Both stores are
     * volatile here, so -O2 keeps the original store order. */
    writeRawWord(fillSlot + 4u, 1u);
    self.classStatsCount4c =
        static_cast<int32_t>(static_cast<uint32_t>(heldCount) + 1u);
}
