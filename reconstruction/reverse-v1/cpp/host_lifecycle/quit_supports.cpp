/* tier: bytecode_anchored
 * Original image libyoyo-armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers three dynsym bodies from the teardown chain (callees of
 * Quit@0x2a27fc), per gc-finalize-anchors census (batch5_functions):
 *   _Z17QuitYoYoFunctionsv      0x15a0c0..0x15a0d0, 16B, 4 words, no pool
 *   _Z23QuitNetworkingFunctionsv 0x2998b8..0x2998d8, 32B, 8 words, no pool
 *   _Z19FINALIZE_Backgroundv    0xc42f4..0xc4370, 124B, 31 words incl. pool
 *
 * FINALIZE_Background GOT-style double-guard materialization (resolved from
 * the image, each slot verified as R_ARM_RELATIVE in .rel.dyn before the
 * target is claimed):
 *   pool word 0x00329650 @0xc4368, [pc,r5] @0xc42fc -> slot 0x3ed954,
 *     R_ARM_RELATIVE addend 0x479cbc = _ZN15Background_Main5namesE (4B .bss)
 *   pool word 0x00329638 @0xc436c, [pc,r6] @0xc4310 -> slot 0x3ed950,
 *     R_ARM_RELATIVE addend 0x479cb8 = _ZN15Background_Main6numberE (4B .bss)
 * Both targets are named dynsym OBJECT symbols, so no anonymous
 * `extern "C" unsigned char anon_0x<hex>[N];` representation is required.
 * The ET_REL object uses direct symbol relocations; the GOT slot addresses
 * above are original-image facts and this build does not reproduce them.
 *
 * gap: none of the referenced callees is recovered or defined here —
 * FlushAchievementCache 0x159640, QuitYoYoFunctionsM 0x15e2a0,
 * FreeSocket 0x299244, Background_FreeTextures 0xc35d8 and
 * Background_Free 0xc34d0 are declared from dynsym identity only (NO stubs);
 * the producers of Background_Main::names / ::number (which write the array
 * and count this function consumes) are outside the recovered set, their
 * element pointee types are not recovered, FreeSocket's return type is
 * unused by the original caller and therefore not claimed (declared void),
 * MemoryManager::Free is the existing seam declaration reached through
 * vm_buffer.hpp and never duplicated here; EHABI unwind records
 * (.ARM.extab/.ARM.exidx), stack-depth effects of push {r3,lr} padding,
 * thread/interleaving behaviour of the volatile names/number reloads, and
 * final linked addresses of every symbol stay unproved; nothing was
 * executed, loaded or emulated for this recovery, and no equivalence-by-
 * execution claim is made for any body below.
 */
#include "quit_runtime.hpp"
#include "../vm_buffer/vm_buffer.hpp" // canonical MemoryManager (Free 0x27c2d0)

/* Declared from dynsym identity only; bodies are outside the recovered set. */
void FlushAchievementCache(); // _Z21FlushAchievementCachev, 0x159640, 332B
void QuitYoYoFunctionsM();    // _Z18QuitYoYoFunctionsMv, 0x15e2a0, 4B
void FreeSocket(int);         // _Z10FreeSocketi, 0x299244, 312B; void return unproved
void Background_FreeTextures(); // _Z23Background_FreeTexturesv, 0xc35d8, 84B
void Background_Free();         // _Z15Background_Freev, 0xc34d0, 168B

/* Original class-static globals, 4B each in .bss, declared not defined:
 * the final link must supply them at 0x479cbc (names) and 0x479cb8 (number).
 * names holds the entries array pointer; number is the signed-compared
 * count (the original cmp/ble/bgt at 0xc4318/0xc431c/0xc4340/0xc4348 are
 * signed). Volatile on the scalars preserves every original reload. */
class Background_Main {
public:
    static void *volatile names;     // _ZN15Background_Main5namesE, 0x479cbc
    static volatile int32_t number;  // _ZN15Background_Main6numberE, 0x479cb8
};

void QuitYoYoFunctions() { // _Z17QuitYoYoFunctionsv @0x15a0c0
    /* 0x15a0c0 push {r3,lr}; 0x15a0c4 bl 0x159640; 0x15a0c8 pop {r3,lr};
     * 0x15a0cc tail b 0x15e2a0 after the epilogue. */
    FlushAchievementCache();
    QuitYoYoFunctionsM();
}

void QuitNetworkingFunctions() { // _Z23QuitNetworkingFunctionsv @0x2998b8
    /* 0x2998b8 push {r4,lr}; 0x2998bc mov r4,#0; loop body 0x2998c0
     * mov r0,r4, 0x2998c4 add r4,r4,#1 (pre-call increment of the next
     * index), 0x2998c8 bl 0x299244, 0x2998cc cmp r4,#64, 0x2998d0 bne
     * back to 0x2998c0; epilogue 0x2998d4 pop {r4,pc}. Exactly 64 calls
     * with arguments 0..63; r7-style reuse of the incremented register
     * is the compiler's addressing order, not extra semantics. */
    for (int slot = 0; slot < 64; slot = slot + 1) {
        FreeSocket(slot);
    }
}

namespace {
/* One volatile lvalue read of names per call site, reinterpreted as the
 * entries array base (the original ldr r0,[r5] is a plain 32-bit load). */
inline void **readNames() { return reinterpret_cast<void **>(Background_Main::names); }
} // namespace

void FINALIZE_Background() { // _Z19FINALIZE_Backgroundv @0xc42f4
    /* 0xc42f4 push {r3,r4,r5,r6,r7,lr}; 0xc42f8/0xc42fc pool + GOT load
     * of &Background_Main::names (slot 0x3ed954); first load of names at
     * 0xc4300 feeds both the guard and the initial array base. */
    void **entries = readNames(); /* 0xc4300 ldr r0,[r5] */
    if (entries != nullptr) {                /* 0xc4304 cmp / 0xc4308 beq -> 0xc435c */
        /* 0xc430c/0xc4310 pool + GOT load of &Background_Main::number
         * (slot 0x3ed950); 0xc4314 ldr r3,[r6]; 0xc4318 cmp r3,#0;
         * 0xc431c ble -> 0xc434c (array is still freed and both globals
         * still zeroed when count <= 0). */
        if (Background_Main::number > 0) {
            uint32_t index = 0u; /* 0xc4320 mov r4,#0; 0xc4324 mov r7,r4 keeps r7 #0 */
            for (;;) {
                MemoryManager::Free(entries[index]); /* 0xc4328 ldr r0,[r0,r4,lsl #2]; 0xc432c bl */
                void **store = readNames(); /* 0xc4330 ldr r2,[r5] reload */
                const int32_t live = Background_Main::number; /* 0xc4334 ldr r3,[r6] reload */
                store[index] = nullptr;              /* 0xc4338 str r7,[r2,r4,lsl #2] */
                index = index + 1u;                  /* 0xc433c add r4,r4,#1 */
                entries = readNames();     /* 0xc4344 ldr r0,[r5] reload */
                if (!(live > (int32_t)index)) {      /* 0xc4340 cmp r3,r4 / 0xc4348 bgt */
                    break;
                }
            }
        }
        MemoryManager::Free(entries);                /* 0xc434c bl; r0 = freshest names load */
        Background_Main::names = nullptr;            /* 0xc4350 mov r3,#0 / 0xc4354 str r3,[r5] */
        Background_Main::number = 0;                 /* 0xc4358 str r3,[r6] */
    }
    Background_FreeTextures();                       /* 0xc435c bl, reached from both paths */
    /* 0xc4360 pop {r3,r4,r5,r6,r7,lr}; 0xc4364 tail b 0xc34d0. */
    Background_Free();
}
