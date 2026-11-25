/* tier: bytecode_anchored. Static recovery of three dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch11_functions). Parent-direct
 * recovery after the jing channel flapped again post-smoke.
 *
 * Windows (dynsym va+size; code span / literal pool per census):
 *   _Z14FINALIZE_Scorev            0x1dc3bc, 580B  code ..0x1dc5e8,
 *                                                  pool 0x1dc5e8..0x1dc600 (6)
 *   _Z13CleanGesturesv             0x1dba70, 192B  code ..0x1dbb28,
 *                                                  pool 0x1dbb28..0x1dbb30 (2)
 *   _Z21FreeAllDataStructuresv     0x20b27c, 508B  code ..0x20b464,
 *                                                  pool 0x20b464..0x20b478 (5)
 *
 * Real links: MemoryManager::Free (recovered), ::operator delete
 * (recovered). All libc edges (fopen/fwrite/ftell/fseek/fclose/strlen/
 * __stack_chk_fail) resolve to imported dynsym symbols via standard
 * extern "C" declarations. EnsureDirectoryIsCreated resolves through its
 * natural C++ mangling (_Z24EnsureDirectoryIsCreatedPKc); LoadSave::
 * _GetSaveFileName and the DS_AutoMutex C2/D2 pair bind through extern "C"
 * exact-mangled declarations (D1/D2 folding precedent, batch 6). All other
 * callees are extern-only, NO stubs.
 *
 * GOT-delta resolutions (all R_ARM_RELATIVE (23) verified in-image; deltas
 * are relative to the GOT base 0x3f1c58, which both Score and
 * FreeAllDataStructures stage through an add-pc pair -- parent recomputed
 * every addend; an intermediate wrong-base pass (0x3f2c58) was caught and
 * corrected before any registry write):
 *   Score: 0x1dc3e0-0x4300 -> slot 0x3ed958 GLOB_DAT __stack_chk_guard
 *          (imported; the canary protocol reads the guard object through
 *          this slot's loaded address); 0x1dc3f0-0x0fbc -> 0x3f0c9c
 *          g_HighScore_Changed (dump-once flag, 4B); 0x1dc3f0-0x0fb8 ->
 *          0x3f0ca0 g_pHiScoreFilename (4B, holds the char* base name);
 *          0x1dc3f0-0x0fc4 -> 0x3f0c94 g_hiScores (0x544ab4, 10x8B table
 *          {char* name, uint32 value}); fopen mode literal "wb" at
 *          0x34034c (direct pc-relative .rodata string, byte-read "wb").
 *   CleanGestures: two DIRECT pc-indexed loads (no add stage):
 *          0x1dba80+0x0021519c = 0x3f2c1c and 0x1dbad0+0x00215138 =
 *          0x3f2c08; neither slot has a relocation and both file images
 *          are packed string bytes ("ying" / "xcoo"), so both are
 *          runtime-written .data pointer words -> anon representation.
 *   FreeAllDataStructures: -0x3fd8 -> 0x3edc80 mapnumb (4B count holder);
 *          -0x3fd4 -> 0x3edc84 listnumb (4B); -0x08b0 -> 0x3f13a8
 *          g_Network_DSMAP; -0x2138 -> 0x3efb20 g_HTTP_AsyncLoad (both
 *          set to 0xffffffff by the mvn tail store).
 *
 * gap: the DS destroy family (DestroyDsMap/DestroyDsList), the Get* family
 * (Stacks/Queues/Grids/PriorityQueues), DS_AutoMutex C2/D2, CDS_Grid D2,
 * CGestureEvent D2, EnsureDirectoryIsCreated, LoadSave::_GetSaveFileName
 * bodies are outside the recovered set; producers/writers of the six named
 * globals and the two anon words are unrecovered; the score-table payload
 * {char*, uint32} is the observed dump shape, element ownership beyond the
 * census is unproven; EHABI unwind records are not recovered (compiled
 * objects carry compiler EHABI plus __aeabi_unwind_cpp_pr0, a final-link
 * obligation); concurrency of the mutex bracket is unproved; final linked
 * addresses hold only if the final link honors the placement comments;
 * nothing was executed and no equivalence claim of any kind is made.
 */

#include "quit_runtime.hpp"                  // FINALIZE_* declarations
#include "../memory_manager/memory_alloc.hpp" // canonical MemoryManager (Free) + memset decl

/* ---- libc imports (dynsym names verified) ---- */
struct __sFILE;
extern "C" struct __sFILE *fopen(const char *, const char *);
extern "C" int fwrite(const void *, int, int, struct __sFILE *);
extern "C" long ftell(struct __sFILE *);
extern "C" int fseek(struct __sFILE *, long, int);
extern "C" int fclose(struct __sFILE *);
extern "C" unsigned int strlen(const char *);
extern "C" void __stack_chk_fail(void);

/* ---- extern-only teardown callees (dynsym identity, NO stubs) ---- */
void DestroyDsMap(int);                          // _Z12DestroyDsMapi, 0x205334
void DestroyDsList(int);                         // _Z13DestroyDsListi, 0x205378
void GetTheStacks(int &);                        // _Z12GetTheStacksRi, 0xffc9c
void GetTheQueues(int &);                        // _Z12GetTheQueuesRi, 0xffee8
void GetTheGrids(int &);                         // _Z11GetTheGridsRi, 0x10026c
void GetThePriorityQueues(int &);                // _Z20GetThePriorityQueuesRi, 0x100244
void EnsureDirectoryIsCreated(const char *);     // _Z24EnsureDirectoryIsCreatedPKc, 0x13ad20

/* Named dynsym globals (R_ARM_RELATIVE verified), declared not defined. */
extern "C" volatile uint32_t mapnumb;            // 0x4836ac, 4B; GOT 0x3edc80
extern "C" volatile uint32_t listnumb;           // 0x4836b8, 4B; GOT 0x3edc84
extern "C" volatile uint32_t g_Network_DSMAP;    // 0x3f7814, 4B; GOT 0x3f13a8
extern "C" volatile uint32_t g_HTTP_AsyncLoad;   // 0x3f5254, 4B; GOT 0x3efb20
extern "C" volatile uint32_t g_HighScore_Changed;// 0x544b18, 4B; GOT 0x3f0c9c
extern "C" volatile uint32_t g_pHiScoreFilename;  // 0x3f51d8, 4B; GOT 0x3f0ca0
extern "C" volatile uint32_t g_hiScores[20];     // 0x544ab4, 80B (10 used); GOT 0x3f0c94

/* Unnamed runtime-written .data pointer words (file image = packed string
 * bytes); consumed through direct pc-indexed loads in CleanGestures. */
extern "C" unsigned char anon_0x3f2c1c[4];       // file image "ying"
extern "C" unsigned char anon_0x3f2c08[4];       // file image "xcoo"

/* Extern "C" exact-mangled C2/D2 pair for the RAII mutex storage (the
 * original brackets FreeAllDataStructures' body with them; dynsym shows
 * C2 at 0xfec18 and D2 at 0xfec6c). */
extern "C" void _ZN13CGestureEventD2Ev(void *self); // 0x1db510 (CleanGestures)
extern "C" void _ZN8CDS_GridD2Ev(void *self);       // 0x20b260 (FreeAllDataStructures)
extern "C" void _ZN12DS_AutoMutexC2Ev(void *self); // 0xfec18
extern "C" void _ZN12DS_AutoMutexD2Ev(void *self); // 0xfec6c

/* LoadSave::_GetSaveFileName(char*, int, const char*) binds the exact
 * census mangled name via extern "C" (return value unused at 0x1dc438). */
extern "C" void _ZN8LoadSave16_GetSaveFileNameEPciPKc(void *buf, int len,
                                                       const char *base);

/* Stack-guard import: slot 0x3ed958 is a GLOB_DAT against this symbol; the
 * original loads the guard ADDRESS from the slot, then the guard VALUE from
 * that address, and re-compares at exit. */
extern "C" void *__stack_chk_guard;

void FINALIZE_Score() { // _Z14FINALIZE_Scorev @0x1dc3bc
    /* 0x1dc3bc push {r4..r11,lr}; 0x1dc3c0 sub sp,#1056; 0x1dc3c8 sub sp,#12
     * 0x1dc3c4/0x1dc3d0 GOT-base pair (r5 = 0x3f1c58)
     * 0x1dc3cc/0x1dc3d8 canary ADDRESS load (slot 0x3ed958, GLOB_DAT
     *   __stack_chk_guard) -> [sp]; 0x1dc3e0 ldr r2,[r2] -> guard VALUE
     *   -> [sp+0x424] */
    /* 0x1dc3cc/0x1dc3d8: the GLOB_DAT slot loads the guard object ADDRESS;
     * 0x1dc3e0 reads the guard VALUE from it -- folded into the value read. */
    const void *guard_value_saved = *reinterpret_cast<void *volatile *>(&__stack_chk_guard);
    /* 0x1dc3e8/0x1dc3ec GOT pair -> r3 = g_HighScore_Changed (0x544b18)
     * 0x1dc3f0 ldrb r3,[r3] : the dump-once flag byte
     * 0x1dc3f4 cmp r3,#0 / 0x1dc3f8 bne 0x1dc41c : flag non-zero -> dump */
    if (g_HighScore_Changed != 0u) {
        /* 0x1dc41c ldr r3,[pc,#0x1d0] (pool 0x1dc5f4); 0x1dc430 ldr r3,[r5,r3]
         *   -> r3 = g_pHiScoreFilename (0x3f51d8); 0x1dc434 ldr r2,[r3] : the
         *   base-name pointer
         * 0x1dc420 add r4,sp,#36 : 1024B name buffer
         * 0x1dc424 mov r1,#1024; 0x1dc438 bl _GetSaveFileName(buf,1024,base) */
        /* The faithful form: a 1024B local buffer, filled by the exact
         * mangled extern "C" edge. */
        alignas(4) unsigned char name_buf[1024];
        const uint32_t base_name_word = g_pHiScoreFilename; /* 0x1dc434 ldr r2,[r3] */
        _ZN8LoadSave16_GetSaveFileNameEPciPKc(name_buf, 1024,
            reinterpret_cast<const char *>(base_name_word)); /* 0x1dc438 */
        /* 0x1dc43c/0x1dc440 bl EnsureDirectoryIsCreated(name_buf) */
        EnsureDirectoryIsCreated(reinterpret_cast<const char *>(name_buf));
        /* 0x1dc444 ldr r1,[pc,#0x1ac] (pool 0x1dc5f8 = 0x00163ef8)
         * 0x1dc44c add r1,pc,r1 -> mode literal "wb" at 0x34034c
         * 0x1dc450 bl fopen(name_buf, "wb"); 0x1dc454 subs r4,r0,#0
         * 0x1dc458 beq 0x1dc5a4 : fopen failed -> skip the dump */
        struct __sFILE *f = fopen(reinterpret_cast<const char *>(name_buf), "wb");
        if (f != nullptr) {
            /* 0x1dc45c..0x1dc484 : store the 4B magic 0x43534948 ("HISC"
             * little-endian) into a stack slot, then fwrite(slot,4,1,f) */
            const uint32_t magic = 0x43534948u; /* bytes 48 49 53 43 = "HISC" */
            fwrite(&magic, 4, 1, f);            /* 0x1dc484 fwrite@plt */
            /* 0x1dc488 bl ftell(f) -> r0 : position after the magic (8)
             * 0x1dc4b0 str r0,[sp,#0xc] : saved for the end-of-body rewrite */
            const long pos_after_magic = ftell(f); /* 0x1dc488 */
            /* 0x1dc494..0x1dc4b8 fwrite(&pos_after_magic,4,1,f) : the position
             * record at offset 8 */
            fwrite(&pos_after_magic, 4, 1, f); /* 0x1dc4b8 fwrite@plt */
            /* 0x1dc4bc/0x1dc4c0 GOT pair -> r10 = g_hiScores (0x544ab4)
             * 0x1dc4c4 add r8,r10,#4 ; 0x1dc4c8 add r10,r10,#84
             *   : entry cursor {+0 char* name, +4 uint32 value}, 10 entries */
            /* entry cursor r8 runs word1..word21 (ten 8B {name,value}
             * pairs); index form keeps the declared [20] bound intact. */
            for (uint32_t k = 1u; k != 21u; k += 2u) { /* 0x1dc564/0x1dc568 */
                const uint32_t name_ptr = g_hiScores[k - 1u]; /* [r8-4] */
                /* 0x1dc4d0 cmp r12,#0 / 0x1dc4d4 beq 0x1dc5b4 : null name ->
                 *   write two 4B zeros (0x1dc5b4..0x1dc5dc) and continue */
                if (name_ptr != 0u) {
                    /* 0x1dc4d8 bl strlen(name) -> r0 ; 0x1dc4ec str r0,[sp,#0x20]
                     * 0x1dc4f0/0x1dc4f4 fwrite(&len,4,1,f) : length word */
                    const uint32_t len = strlen(reinterpret_cast<const char *>(name_ptr));
                    fwrite(&len, 4, 1, f); /* 0x1dc4f4 */
                    /* 0x1dc4fc ldr r0,[r8,#-0x4]; 0x1dc500/0x1dc504 len reload
                     * 0x1dc508 fwrite(name,1,len,f) : the name bytes */
                    fwrite(reinterpret_cast<const void *>(name_ptr), 1,
                           len, f); /* 0x1dc508 */
                    /* 0x1dc50c..0x1dc548 : pad to 4-byte alignment with 0xF0
                     *   bytes (mvn r6,#15 -> byte 0xf0), one fwrite(1) per pad
                     *   byte, count = ((len+3)&~3) - len */
                    for (uint32_t written = 0u;
                         written < ((len + 3u) & ~3u) - len;) { /* 0x1dc510/0x1dc51c/0x1dc544 */
                        uint8_t pad = 0xf0u; /* 0x1dc4ac mvn r6,#15; 0x1dc53c strb */
                        fwrite(&pad, 1, 1, f); /* 0x1dc540 */
                        ++written; /* 0x1dc530 add r5,r5,r1 (#1) */
                    }
                }
                /* 0x1dc54c..0x1dc558 fwrite(cursor,4,1,f) : the entry value word
                 * 0x1dc560 add r8,r8,#8 ; 0x1dc564 cmp r8,r10 */
                fwrite(const_cast<const uint32_t *>(&g_hiScores[k]), 4, 1, f); /* 0x1dc55c : the value word */
                /* 0x1dc560 add r8,r8,#8 : two words per entry */
            }
            /* 0x1dc56c bl ftell(f) -> total size
             * 0x1dc574 ldr r1,[sp,#0xc] (position after magic)
             * 0x1dc57c/0x1dc580/0x1dc584 fseek(f, pos_after_magic, 0) : rewind */
            const long total = ftell(f); /* 0x1dc56c */
            fseek(f, pos_after_magic, 0); /* 0x1dc584 (whence 0 = SEEK_SET) */
            /* 0x1dc588..0x1dc598 fwrite(&total,4,1,f) : rewrite the record */
            fwrite(&total, 4, 1, f); /* 0x1dc598 */
            /* 0x1dc59c/0x1dc5a0 bl fclose(f) */
            fclose(f); /* 0x1dc5a0 */
        }
        /* 0x1dc5a4 ldr r1,[sp,#4] (g_HighScore_Changed address)
         * 0x1dc5a8/0x1dc5ac mov r3,#0 / strb r3,[r1] : flag byte = 0
         * 0x1dc5b0 b 0x1dc3fc : join the canary check */
        g_HighScore_Changed = 0u;
        /* 0x1dc3fc ldr r1,[sp] (guard address); 0x1dc400 ldr r2,[sp,#0x424]
         * 0x1dc404 ldr r3,[r1] : current guard value
         * 0x1dc408 cmp r2,r3 / 0x1dc40c bne 0x1dc5e4
         * 0x1dc5e4 bl __stack_chk_fail@plt */
        const void *guard_value_now = *reinterpret_cast<void *volatile *>(&__stack_chk_guard);
        if (guard_value_saved != guard_value_now) {
            __stack_chk_fail(); /* 0x1dc5e4 */
        }
        return; /* 0x1dc410..0x1dc418 add sp; pop {r4..r11,pc} */
    }
    /* flag == 0 path: 0x1dc3fc canary check (same shape) then 0x1dc410
     * add sp / pop {r4..r11,pc} -- no dump, no flag store. */
    const void *guard_value_now0 = *reinterpret_cast<void *volatile *>(&__stack_chk_guard);
    if (guard_value_saved != guard_value_now0) {
        __stack_chk_fail();
    }
}

void CleanGestures() { // _Z13CleanGesturesv @0x1dba70
    /* 0x1dba70 push {r3,r4,r5,r6,r7,lr}
     * 0x1dba74 ldr r6,[pc,#0xac] (pool 0x1dbb28 = 0x0021519c)
     * 0x1dba78 ldr r6,[pc,r6] : DIRECT pc-indexed -> word at 0x3f2c1c
     *   (runtime-written, file image "ying") : list-header one pointer */
    uint32_t *head1 = reinterpret_cast<uint32_t *>(anon_0x3f2c1c);
    /* 0x1dba7c ldr r4,[r6] : first list node */
    uint32_t *node = *reinterpret_cast<uint32_t *volatile *>(head1);
    /* 0x1dba80 cmp r4,#0 / 0x1dba84 beq 0x1dbabc */
    while (node != nullptr) {
        /* 0x1dba88 ldr r3,[r4,#8] : the gesture event object
         * 0x1dba8c ldr r5,[r4] : next node
         * 0x1dba90 cmp r3,#0 / 0x1dba94 mov r0,r3 / 0x1dba98 beq 0x1dbaa8
         * 0x1dba9c ldr r3,[r3] : vtable; 0x1dbaa0 ldr r3,[r3,#4] : +4
         * 0x1dbaa4 blx r3 : INDIRECT destruct (r0 = event), target unresolved */
        uint32_t *event = *reinterpret_cast<uint32_t *volatile *>(node + 2u); /* +8 */
        uint32_t *next = *reinterpret_cast<uint32_t *volatile *>(node);       /* +0 */
        if (event != nullptr) {
            reinterpret_cast<void (*)(void *)>(
                *reinterpret_cast<uint32_t *>(*event + 4u))(
                reinterpret_cast<void *>(event)); /* 0x1dbaa4 blx r3 */
        }
        /* 0x1dbaa8 mov r0,r4 (node); 0x1dbaac mov r4,r5 (advance)
         * 0x1dbab0 bl Free(node) : real edge
         * 0x1dbab4 cmp r5,#0 / 0x1dbab8 bne 0x1dba88 */
        MemoryManager::Free(reinterpret_cast<const void *>(node));
        node = next;
    }
    /* 0x1dbabc ldr r7,[pc,#0x68] (pool 0x1dbb2c = 0x00215138)
     * 0x1dbac0 mov r3,#0; 0x1dbac4 str r3,[r6,#8] : header1[+8] = 0
     * 0x1dbac8 ldr r7,[pc,r7] : DIRECT pc-indexed -> word at 0x3f2c08
     *   (runtime-written, file image "xcoo") : list-header two pointer
     * 0x1dbacc str r3,[r6,#4] : header1[+4] = 0
     * 0x1dbad0 str r3,[r6] : header1[+0] = 0 */
    uint32_t *head2 = reinterpret_cast<uint32_t *>(anon_0x3f2c08);
    head1[2] = 0u; /* 0x1dbac4 */
    head1[1] = 0u; /* 0x1dbacc */
    head1[0] = 0u; /* 0x1dbad0 */
    /* 0x1dbad4 ldr r4,[r7] : first node of list two
     * 0x1dbad8 cmp r4,r3(#0) / 0x1dbadc beq 0x1dbb14 */
    node = *reinterpret_cast<uint32_t *volatile *>(head2);
    while (node != nullptr) {
        /* 0x1dbae0 ldr r5,[r4,#8] : the CGestureEvent object
         * 0x1dbae4 ldr r6,[r4] : next node
         * 0x1dbae8 cmp r5,#0 / 0x1dbaec mov r0,r5 / 0x1dbaf0 beq 0x1dbb00
         * 0x1dbaf4 bl _ZN13CGestureEventD2Ev(event) : exact D2 mangled edge
         * 0x1dbaf8 mov r0,r5; 0x1dbafc bl _ZdlPv : operator delete(event) */
        uint32_t *event = *reinterpret_cast<uint32_t *volatile *>(node + 2u); /* +8 */
        uint32_t *next = *reinterpret_cast<uint32_t *volatile *>(node);       /* +0 */
        if (event != nullptr) {
            _ZN13CGestureEventD2Ev(reinterpret_cast<void *>(event)); /* 0x1dbaf4 */
            ::operator delete(reinterpret_cast<void *>(event));       /* 0x1dbafc */
        }
        /* 0x1dbb00 mov r0,r4 (node); 0x1dbb04 mov r4,r6 (advance)
         * 0x1dbb08 bl Free(node) : real edge
         * 0x1dbb0c cmp r6,#0 / 0x1dbb10 bne 0x1dbae0 */
        MemoryManager::Free(reinterpret_cast<const void *>(node));
        node = next;
    }
    /* 0x1dbb14 mov r3,#0; 0x1dbb18 str r3,[r7,#8]; 0x1dbb1c str r3,[r7,#4]
     * 0x1dbb20 str r3,[r7] : header2 {+8,+4,+0} = 0
     * 0x1dbb24 pop {r3,r4,r5,r6,r7,pc} */
    head2[2] = 0u; /* 0x1dbb18 */
    head2[1] = 0u; /* 0x1dbb1c */
    head2[0] = 0u; /* 0x1dbb20 */
}

void FreeAllDataStructures() { // _Z21FreeAllDataStructuresv @0x20b27c
    /* 0x20b27c push {r4..r9,lr}; 0x20b280 sub sp,#28
     * 0x20b284 add r6,sp,#4 : the DS_AutoMutex lives in this stack slice
     * 0x20b288/0x20b290 GOT-base pair (r5 = 0x3f1c58)
     * 0x20b294 bl _ZN12DS_AutoMutexC2Ev(mutex) : RAII bracket open */
    alignas(4) unsigned char auto_mutex[8];
    _ZN12DS_AutoMutexC2Ev(auto_mutex); /* 0x20b294 */
    /* 0x20b298/0x20b29c GOT pair (delta -0x3fd8) -> r7 = mapnumb (0x4836ac)
     * 0x20b2a0 ldr r3,[r7] : map count; 0x20b2a4 cmp #0 / movgt r4,#0
     * 0x20b2ac ble 0x20b2c8 : count <= 0 -> skip to the list ladder
     * 0x20b2b0 mov r0,r4; 0x20b2b4 add r4,#1
     * 0x20b2b8 bl DestroyDsMap(i) : extern edge
     * 0x20b2bc ldr r3,[r7] live reload; 0x20b2c0 cmp r3,r4
     * 0x20b2c4 bgt loop */
    for (uint32_t i = 0u; static_cast<int32_t>(mapnumb) > 0 &&
                          static_cast<int32_t>(i) < static_cast<int32_t>(mapnumb); ++i) { /* 0x20b2a8..0x20b2c4 */
        DestroyDsMap(static_cast<int>(i)); /* 0x20b2b8 */
    }
    /* 0x20b2c8/0x20b2cc/0x20b2f0 : listnumb (0x4836b8) count ladder
     * 0x20b2e8 bl DestroyDsList(i), identical shape */
    for (uint32_t i = 0u; static_cast<int32_t>(listnumb) > 0 &&
                          static_cast<int32_t>(i) < static_cast<int32_t>(listnumb); ++i) { /* 0x20b2d8..0x20b2f4 */
        DestroyDsList(static_cast<int>(i)); /* 0x20b2e8 */
    }
    /* 0x20b2f8 add r0,sp,#8; 0x20b2fc bl GetTheStacks(out) : out-param ladder
     * 0x20b300 ldr r2,[sp,#8] : count; 0x20b304 cmp/0x20b308 movgt r4,#0
     * 0x20b30c movgt r8,r4 (zero mirror); 0x20b310 movgt r7,r0 (cursor)
     * 0x20b314 ble 0x20b348
     * 0x20b318 ldr r3,[r7],#4 : post-increment handle load
     * 0x20b31c add r4,#1; 0x20b320 cmp r3,#0 / 0x1a... beq skip
     * 0x20b32c ldr r3,[r3] : vtable; 0x20b330 ldr r3,[r3,#4] : +4
     * 0x20b334 blx r3 : INDIRECT destroy (r0 = handle), target unresolved
     * 0x20b338 reload count; 0x20b33c str r8,[r7,#-4] : null-store
     * 0x20b340 cmp r2,r4 / 0x20b344 bgt loop */
    int stacks_out = 0;
    GetTheStacks(stacks_out); /* 0x20b2fc */
    if (stacks_out > 0) { /* 0x20b308 movgt */
        /* The original walks the returned handle ARRAY base (GetTheStacks
         * fills the int& with the base) with a post-increment cursor and a
         * live count reload: */
        volatile uint32_t *array = reinterpret_cast<volatile uint32_t *>(stacks_out);
        for (uint32_t i = 0u; static_cast<int32_t>(stacks_out) > static_cast<int32_t>(i);) { /* 0x20b340/0x20b344 */
            uint32_t handle = array[i]; /* 0x20b318 ldr r3,[r7],#4 */
            ++i; /* 0x20b31c add r4,r4,#1 (pre-advance in the original) */
            if (handle != 0u) { /* 0x20b320/0x20b328 */
                reinterpret_cast<void (*)(void *)>(
                    *reinterpret_cast<uint32_t *>(
                        *reinterpret_cast<uint32_t *>(handle) + 4u))(
                    reinterpret_cast<void *>(handle)); /* 0x20b334 blx r3 */
                /* 0x20b338/0x20b33c live count reload + null-store */
                array[i - 1u] = 0u; /* 0x20b33c str r8,[r7,#-4] */
            }
        }
    }
    /* 0x20b348/0x20b34c bl GetTheQueues(out) : identical walk shape */
    int queues_out = 0;
    GetTheQueues(queues_out); /* 0x20b34c */
    if (queues_out > 0) { /* 0x20b354/0x20b358 */
        volatile uint32_t *array = reinterpret_cast<volatile uint32_t *>(queues_out);
        for (uint32_t i = 0u; static_cast<int32_t>(queues_out) > static_cast<int32_t>(i);) { /* 0x20b390/0x20b394 */
            uint32_t handle = array[i]; /* 0x20b368 */
            ++i; /* 0x20b36c */
            if (handle != 0u) { /* 0x20b370/0x20b378 */
                reinterpret_cast<void (*)(void *)>(
                    *reinterpret_cast<uint32_t *>(
                        *reinterpret_cast<uint32_t *>(handle) + 4u))(
                    reinterpret_cast<void *>(handle)); /* 0x20b384 blx r3 */
                array[i - 1u] = 0u; /* 0x20b38c */
            }
        }
    }
    /* 0x20b398/0x20b39c bl GetTheGrids(out)
     * 0x20b3a0 ldr r3,[sp,#0x10] : count; 0x20b3a4 cmp/0x20b3a8 movgt r7,#0
     * 0x20b3ac movgt r9,r7 (zero); 0x20b3b0 movgt r8,r0 (cursor)
     * 0x20b3b8 ldr r4,[r8],#4 : grid handle; 0x20b3bc add r7,#1
     * 0x20b3c0 cmp r4,#0 / beq skip
     * 0x20b3cc bl _ZN8CDS_GridD2Ev(grid) : exact D2 mangled edge
     * 0x20b3d0 mov r0,r4; 0x20b3d4 bl _ZdlPv : operator delete(grid)
     * 0x20b3d8/0x20b3dc live count reload + null-store
     * 0x20b3e0 cmp r3,r7 / 0x20b3e4 bgt loop */
    int grids_out = 0;
    GetTheGrids(grids_out); /* 0x20b39c */
    if (grids_out > 0) { /* 0x20b3a4/0x20b3a8 */
        volatile uint32_t *array = reinterpret_cast<volatile uint32_t *>(grids_out);
        for (uint32_t i = 0u; static_cast<int32_t>(grids_out) > static_cast<int32_t>(i); ++i) { /* 0x20b3e0/0x20b3e4 */
            uint32_t grid = array[i]; /* 0x20b3b8 */
            if (grid != 0u) { /* 0x20b3c0/0x20b3c8 */
                _ZN8CDS_GridD2Ev(reinterpret_cast<void *>(grid)); /* 0x20b3cc */
                ::operator delete(reinterpret_cast<void *>(grid)); /* 0x20b3d4 */
                array[i] = 0u; /* 0x20b3dc */
            }
        }
    }
    /* 0x20b3e8/0x20b3ec bl GetThePriorityQueues(out) : identical walk shape */
    int pq_out = 0;
    GetThePriorityQueues(pq_out); /* 0x20b3ec */
    if (pq_out > 0) { /* 0x20b3f4/0x20b3f8 */
        volatile uint32_t *array = reinterpret_cast<volatile uint32_t *>(pq_out);
        for (uint32_t i = 0u; static_cast<int32_t>(pq_out) > static_cast<int32_t>(i);) { /* 0x20b430/0x20b434 */
            uint32_t handle = array[i]; /* 0x20b408 */
            ++i; /* 0x20b40c */
            if (handle != 0u) { /* 0x20b410/0x20b418 */
                reinterpret_cast<void (*)(void *)>(
                    *reinterpret_cast<uint32_t *>(
                        *reinterpret_cast<uint32_t *>(handle) + 4u))(
                    reinterpret_cast<void *>(handle)); /* 0x20b424 blx r3 */
                array[i - 1u] = 0u; /* 0x20b42c */
            }
        }
    }
    /* 0x20b438 ldr r1,[pc,#0x30] (pool 0x20b470 = 0xfffff750) -> slot
     *   0x3f13a8 -> g_Network_DSMAP; 0x20b43c mvn r3,#0 -> 0xffffffff
     * 0x20b440 ldr r2,[pc,#0x2c] (pool 0x20b474 = 0xffffdec8) -> slot
     *   0x3efb20 -> g_HTTP_AsyncLoad
     * 0x20b448 ldr r1,[r5,r1]; 0x20b44c str r3,[r1] : g_Network_DSMAP = -1
     * 0x20b450 ldr r2,[r5,r2]; 0x20b454 str r3,[r2] : g_HTTP_AsyncLoad = -1
     * 0x20b458 bl _ZN12DS_AutoMutexD2Ev(mutex) : RAII bracket close
     * 0x20b45c add sp,#28; 0x20b460 pop {r4..r9,pc} */
    g_Network_DSMAP = 0xffffffffu; /* 0x20b44c (mvn r3,#0) */
    g_HTTP_AsyncLoad = 0xffffffffu; /* 0x20b454 */
    _ZN12DS_AutoMutexD2Ev(auto_mutex); /* 0x20b458 */
}
