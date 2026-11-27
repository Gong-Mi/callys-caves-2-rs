/* tier: bytecode_anchored. Static recovery of _Z11bucketCheckPc (0x27bee0,
 * 772B, 193 census words; the char* parameter is consumed by no instruction)
 * from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * gap: producers of the nine words below (unnamed in dynsym, unrelocated,
 * runtime-written .data), trap semantics recorded as observed stores not
 * intent, EHABI unwind data, final linked addresses; nothing executed; no
 * equivalence claims.
 *
 * GOT base staging (codegen detail, not a source construct):
 *   0x27bee0 ldr r0,[pc,#0x2d8] -> pool word 0x27c1c0 = 0x00175d64
 *   0x27beec add r0,pc,r0 with pc = 0x27bef4
 *            -> r0 = 0x27bef4 + 0x00175d64 = 0x3f2c58
 * bucketCheck's own GOT region 0x3f2c58 (distinct from the FADS/IsAllocated
 * 0x3f1c58 region; both valid). Every anon word below is reached in the
 * census as GOT base + signed delta; the source references them directly by
 * placement.
 *
 * Literal pool 0x27c1c0..0x27c1e4, nine words, consumed as:
 *   0x27c1c0  0x00175d64  GOT-base delta          (0x27bee0 -> 0x27beec)
 *   0x27c1c4  0xffffbf74  counter slot  -0x408c  (0x27bee8 -> 0x27befc) -> 0x3f2bcc
 *   0x27c1c8  0xfffffbe4  report slot   -0x41c  (0x27bef0 -> 0x27bf08) -> 0x3f2a3c
 *   0x27c1cc  0xfffffbe8  8KB holder    -0x418  (0x27bf00 -> 0x27bf10) -> 0x3f2840
 *   0x27c1d0  0xfffffbec  16KB holder   -0x414  (0x27bf74 -> 0x27bf80) -> 0x3f2844
 *   0x27c1d4  0xfffffbf0  32KB holder   -0x410  (0x27bfe8 -> 0x27bff4) -> 0x3f2848
 *   0x27c1d8  0xfffffbf4  64KB holder   -0x40c  (0x27c05c -> 0x27c068) -> 0x3f284c
 *   0x27c1dc  0xfffffbf8  128KB holder  -0x408  (0x27c0d0 -> 0x27c0dc) -> 0x3f2850
 *   0x27c1e0  0xfffffbfc  256KB holder  -0x404  (0x27c144 -> 0x27c150) -> 0x3f2854 */

extern "C" unsigned char anon_0x3f2bcc[4];   // check-failure counter word
extern "C" unsigned char anon_0x3f2a3c[4];   // current-size report word
extern "C" unsigned char anon_0x3f2840[4];   // bucket 8KB handle holder
extern "C" unsigned char anon_0x3f2844[4];   // bucket 16KB handle holder
extern "C" unsigned char anon_0x3f2848[4];   // bucket 32KB handle holder
extern "C" unsigned char anon_0x3f284c[4];   // bucket 64KB handle holder
extern "C" unsigned char anon_0x3f2850[4];   // bucket 128KB handle holder
extern "C" unsigned char anon_0x3f2854[4];   // bucket 256KB handle holder

void bucketCheck(char *); /* parameter unused by every instruction */

void bucketCheck(char * /* unused */) {
    /* 0x27bee0..0x27bef4 prologue: GOT staging as in the header; 0x27bee4
     * mov r2,#8 (block-1 report marker, deferred to 0x27bf0c); 0x27bef4
     * push {r4,r5,r6,r7,r8} (callee-saved; source level = plain locals,
     * popped at 0x27c1b8). The char* parameter arrived in r0 and is
     * overwritten at 0x27bee0 before any read. */

    /* 0x27bef8 mov r8,#0 (zero; also the block-1 trap target register).
     * 0x27befc ldr r1,[r0,r1] <- pool 0x27c1c4 = 0xffffbf74: counter slot
     * 0x3f2c58 - 0x408c = 0x3f2bcc; the word holds the counter pointer. */
    unsigned int *counter =
        *reinterpret_cast<unsigned int *volatile *>(anon_0x3f2bcc);
    *counter = 0u; /* 0x27bf04 str r8,[r1] */

    /* 0x27bf08 ldr r12,[r0,r12] <- pool 0x27c1c8 = 0xfffffbe4: report slot
     * 0x3f2c58 - 0x41c = 0x3f2a3c; the word holds the report pointer. */
    unsigned int *report =
        *reinterpret_cast<unsigned int *volatile *>(anon_0x3f2a3c);
    *report = 8u; /* 0x27bf0c str r2,[r12] (r2 = #8 from 0x27bee4) */

    /* ---- block 1: report marker 8, range 0x20000, trap store 0x27bf58
     * (0x27bf14..0x27bf70). Per-head loop: the head VALUE chains through
     * its own first word (register-held local r5; NOT a storage word).
     * Per-node range walk [node+8, node+0x20000+8) against the head VALUE;
     * walk exhausted without containment (or empty node list) -> trap
     * store of 42 through the null target, once per head iteration. ---- */
    /* 0x27bf10 ldr r6,[r0,r3] <- pool 0x27c1cc = 0xfffffbe8: 8KB holder
     * slot 0x3f2c58 - 0x418 = 0x3f2840; r6 = holder VALUE (GOT-indexed
     * value load). Blocks two..six use the same GOT-indexed form at their
     * own block heads, per census. */
    {
        unsigned int *b8 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f2840));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b8 + 2u); /* 0x27bf14 ldr r5,[r6,#8] */
        if (head != nullptr) { /* 0x27bf18 cmp r5,r8 (r8=0) / 0x27bf20 beq 0x27bf74 */
            /* 0x27bf1c movne r7,#42; trap target = prologue r8 = 0 (0x27bef8) */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* per-head iteration; re-entry 0x27bf24 (0x27bf70 bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b8 + 1u); /* 0x27bf24 ldr r3,[r6,#4] */
                if (node == nullptr) { /* 0x27bf28 cmp r3,#0 / 0x27bf2c beq 0x27bf58 */
                    *trap_target = trap_value; /* 0x27bf58 str r7,[r8]: 42 through NULL */
                } else {
                    bool contained = false;
                    do { /* per-node range walk */
                        unsigned int *low = node + 2u; /* 0x27bf30 add r4,r3,#8 */
                        unsigned int *high = node + 2u + 0x8000u;
                        /* 0x27bf34 add r2,r3,#131072 (0x20000 bytes = 0x8000 words)
                         * + 0x27bf3c add r2,r2,#8 */
                        if (head >= low) { /* 0x27bf38 cmp r5,r4; blo 0x27bf40 -> advance */
                            if (high > head) { /* 0x27bf44 cmp r2,r5 / 0x27bf48 bhi 0x27bf5c */
                                contained = true; /* contained -> past the trap */
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27bf4c ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27bf50 cmp r3,#0 / 0x27bf54 bne 0x27bf30 */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27bf58 str r7,[r8]: 42 through NULL */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27bf5c ldr r5,[r5] */
                *counter += 1u; /* 0x27bf60 ldr r3,[r1] / 0x27bf68 add r3,r3,#1 / 0x27bf6c str r3,[r1] */
            } while (head != nullptr); /* 0x27bf64 cmp r5,#0 (scheduled between the counter loads) / 0x27bf70 bne 0x27bf24 */
        }
    }

    /* ---- block 2: report marker 16, range 0x40000, trap store 0x27bfcc
     * (0x27bf74..0x27bfe4). Same per-head shape; trap pair re-set fresh
     * (movne both target and value). ---- */
    {
        *report = 16u; /* 0x27bf78 mov r2,#16 / 0x27bf7c str r2,[r12] */
        /* 0x27bf74 ldr r3,[pc,#0x254] <- pool 0x27c1d0 = 0xfffffbec;
         * 0x27bf80 ldr r6,[r0,r3]: 16KB holder slot 0x3f2c58 - 0x414 = 0x3f2844 */
        unsigned int *b16 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f2844));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b16 + 2u); /* 0x27bf84 ldr r5,[r6,#8] */
        if (head != nullptr) { /* 0x27bf88 cmp r5,#0 / 0x27bf94 beq 0x27bfe8 */
            /* 0x27bf8c movne r8,#0 (fresh trap target) / 0x27bf90 movne r7,#42 */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* re-entry 0x27bf98 (0x27bfe4 bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b16 + 1u); /* 0x27bf98 ldr r3,[r6,#4] */
                if (node == nullptr) { /* 0x27bf9c cmp r3,#0 / 0x27bfa0 beq 0x27bfcc */
                    *trap_target = trap_value; /* 0x27bfcc str r7,[r8] */
                } else {
                    bool contained = false;
                    do {
                        unsigned int *low = node + 2u; /* 0x27bfa4 add r4,r3,#8 */
                        unsigned int *high = node + 2u + 0x10000u;
                        /* 0x27bfa8 add r2,r3,#262144 (0x40000 bytes = 0x10000 words)
                         * + 0x27bfb0 add r2,r2,#8 */
                        if (head >= low) { /* 0x27bfac cmp r5,r4; blo 0x27bfb4 -> advance */
                            if (high > head) { /* 0x27bfb8 cmp r2,r5 / 0x27bfbc bhi 0x27bfd0 */
                                contained = true;
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27bfc0 ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27bfc4 cmp r3,#0 / 0x27bfc8 bne 0x27bfa4 */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27bfcc str r7,[r8] */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27bfd0 ldr r5,[r5] */
                *counter += 1u; /* 0x27bfd4 ldr r3,[r1] / 0x27bfdc add r3,r3,#1 / 0x27bfe0 str r3,[r1] */
            } while (head != nullptr); /* 0x27bfd8 cmp r5,#0 / 0x27bfe4 bne 0x27bf98 */
        }
    }

    /* ---- block 3: report marker 32, range 0x40000, trap store 0x27c040
     * (0x27bfe8..0x27c058). ---- */
    {
        *report = 32u; /* 0x27bfec mov r2,#32 / 0x27bff0 str r2,[r12] */
        /* 0x27bfe8 ldr r3,[pc,#0x1e4] <- pool 0x27c1d4 = 0xfffffbf0;
         * 0x27bff4 ldr r6,[r0,r3]: 32KB holder slot 0x3f2c58 - 0x410 = 0x3f2848 */
        unsigned int *b32 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f2848));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b32 + 2u); /* 0x27bff8 ldr r5,[r6,#8] */
        if (head != nullptr) { /* 0x27bffc cmp r5,#0 / 0x27c008 beq 0x27c05c */
            /* 0x27c000 movne r8,#0 / 0x27c004 movne r7,#42 */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* re-entry 0x27c00c (0x27c058 bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b32 + 1u); /* 0x27c00c ldr r3,[r6,#4] */
                if (node == nullptr) { /* 0x27c010 cmp r3,#0 / 0x27c014 beq 0x27c040 */
                    *trap_target = trap_value; /* 0x27c040 str r7,[r8] */
                } else {
                    bool contained = false;
                    do {
                        unsigned int *low = node + 2u; /* 0x27c018 add r4,r3,#8 */
                        unsigned int *high = node + 2u + 0x10000u;
                        /* 0x27c01c add r2,r3,#262144 (0x40000 bytes = 0x10000 words)
                         * + 0x27c024 add r2,r2,#8 */
                        if (head >= low) { /* 0x27c020 cmp r5,r4; blo 0x27c028 -> advance */
                            if (high > head) { /* 0x27c02c cmp r2,r5 / 0x27c030 bhi 0x27c044 */
                                contained = true;
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27c034 ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27c038 cmp r3,#0 / 0x27c03c bne 0x27c018 */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27c040 str r7,[r8] */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27c044 ldr r5,[r5] */
                *counter += 1u; /* 0x27c048 ldr r3,[r1] / 0x27c050 add r3,r3,#1 / 0x27c054 str r3,[r1] */
            } while (head != nullptr); /* 0x27c04c cmp r5,#0 / 0x27c058 bne 0x27c00c */
        }
    }

    /* ---- block 4: report marker 64, range 0x80000, trap store 0x27c0b4
     * (0x27c05c..0x27c0cc). ---- */
    {
        *report = 64u; /* 0x27c060 mov r2,#64 / 0x27c064 str r2,[r12] */
        /* 0x27c05c ldr r3,[pc,#0x174] <- pool 0x27c1d8 = 0xfffffbf4;
         * 0x27c068 ldr r6,[r0,r3]: 64KB holder slot 0x3f2c58 - 0x40c = 0x3f284c */
        unsigned int *b64 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f284c));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b64 + 2u); /* 0x27c06c ldr r5,[r6,#8] */
        if (head != nullptr) { /* 0x27c070 cmp r5,#0 / 0x27c07c beq 0x27c0d0 */
            /* 0x27c074 movne r8,#0 / 0x27c078 movne r7,#42 */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* re-entry 0x27c080 (0x27c0cc bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b64 + 1u); /* 0x27c080 ldr r3,[r6,#4] */
                if (node == nullptr) { /* 0x27c084 cmp r3,#0 / 0x27c088 beq 0x27c0b4 */
                    *trap_target = trap_value; /* 0x27c0b4 str r7,[r8] */
                } else {
                    bool contained = false;
                    do {
                        unsigned int *low = node + 2u; /* 0x27c08c add r4,r3,#8 */
                        unsigned int *high = node + 2u + 0x20000u;
                        /* 0x27c090 add r2,r3,#524288 (0x80000 bytes = 0x20000 words)
                         * + 0x27c098 add r2,r2,#8 */
                        if (head >= low) { /* 0x27c094 cmp r5,r4; blo 0x27c09c -> advance */
                            if (high > head) { /* 0x27c0a0 cmp r2,r5 / 0x27c0a4 bhi 0x27c0b8 */
                                contained = true;
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27c0a8 ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27c0ac cmp r3,#0 / 0x27c0b0 bne 0x27c08c */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27c0b4 str r7,[r8] */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27c0b8 ldr r5,[r5] */
                *counter += 1u; /* 0x27c0bc ldr r3,[r1] / 0x27c0c4 add r3,r3,#1 / 0x27c0c8 str r3,[r1] */
            } while (head != nullptr); /* 0x27c0c0 cmp r5,#0 / 0x27c0cc bne 0x27c080 */
        }
    }

    /* ---- block 5: report marker 128, range 0x80000, trap store 0x27c128
     * (0x27c0d0..0x27c140). ---- */
    {
        *report = 128u; /* 0x27c0d4 mov r2,#128 / 0x27c0d8 str r2,[r12] */
        /* 0x27c0d0 ldr r3,[pc,#0x104] <- pool 0x27c1dc = 0xfffffbf8;
         * 0x27c0dc ldr r6,[r0,r3]: 128KB holder slot 0x3f2c58 - 0x408 = 0x3f2850 */
        unsigned int *b128 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f2850));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b128 + 2u); /* 0x27c0e0 ldr r5,[r6,#8] */
        if (head != nullptr) { /* 0x27c0e4 cmp r5,#0 / 0x27c0f0 beq 0x27c144 */
            /* 0x27c0e8 movne r8,#0 / 0x27c0ec movne r7,#42 */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* re-entry 0x27c0f4 (0x27c140 bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b128 + 1u); /* 0x27c0f4 ldr r3,[r6,#4] */
                if (node == nullptr) { /* 0x27c0f8 cmp r3,#0 / 0x27c0fc beq 0x27c128 */
                    *trap_target = trap_value; /* 0x27c128 str r7,[r8] */
                } else {
                    bool contained = false;
                    do {
                        unsigned int *low = node + 2u; /* 0x27c100 add r4,r3,#8 */
                        unsigned int *high = node + 2u + 0x20000u;
                        /* 0x27c104 add r2,r3,#524288 (0x80000 bytes = 0x20000 words)
                         * + 0x27c10c add r2,r2,#8 */
                        if (head >= low) { /* 0x27c108 cmp r5,r4; blo 0x27c110 -> advance */
                            if (high > head) { /* 0x27c114 cmp r2,r5 / 0x27c118 bhi 0x27c12c */
                                contained = true;
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27c11c ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27c120 cmp r3,#0 / 0x27c124 bne 0x27c100 */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27c128 str r7,[r8] */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27c12c ldr r5,[r5] */
                *counter += 1u; /* 0x27c130 ldr r3,[r1] / 0x27c138 add r3,r3,#1 / 0x27c13c str r3,[r1] */
            } while (head != nullptr); /* 0x27c134 cmp r5,#0 / 0x27c140 bne 0x27c0f4 */
        }
    }

    /* ---- block 6: report marker 256, range 0x100000, trap store 0x27c19c
     * (0x27c144..0x27c1b4). Register-role swap only (census): holder VALUE
     * in r4, head cursor in r12 (self-advancing 0x27c1a0 ldr r12,[r12]),
     * trap target r6 / value r5; 0x27c174 add r0,r3,#8 clobbers r0 (the
     * GOT base is dead after this block's holder load). Same per-head
     * shape. ---- */
    {
        *report = 256u; /* 0x27c148 mov r2,#256 (e3a02c01) / 0x27c14c str r2,[r12] */
        /* 0x27c144 ldr r3,[pc,#0x94] <- pool 0x27c1e0 = 0xfffffbfc;
         * 0x27c150 ldr r4,[r0,r3]: 256KB holder slot 0x3f2c58 - 0x404 = 0x3f2854 */
        unsigned int *b256 = reinterpret_cast<unsigned int *>(
            *reinterpret_cast<volatile unsigned int *>(anon_0x3f2854));
        unsigned int *head =
            *reinterpret_cast<unsigned int *volatile *>(b256 + 2u); /* 0x27c154 ldr r12,[r4,#8] */
        if (head != nullptr) { /* 0x27c158 cmp r12,#0 / 0x27c164 beq 0x27c1b8 (epilogue) */
            /* 0x27c15c movne r6,#0 (fresh trap target) / 0x27c160 movne r5,#42 */
            unsigned int *trap_target = nullptr;
            unsigned int trap_value = 42u;
            do { /* re-entry 0x27c168 (0x27c1b4 bne) */
                unsigned int *node =
                    *reinterpret_cast<unsigned int *volatile *>(b256 + 1u); /* 0x27c168 ldr r3,[r4,#4] */
                if (node == nullptr) { /* 0x27c16c cmp r3,#0 / 0x27c170 beq 0x27c19c */
                    *trap_target = trap_value; /* 0x27c19c str r5,[r6]: 42 through NULL */
                } else {
                    bool contained = false;
                    do {
                        unsigned int *low = node + 2u; /* 0x27c174 add r0,r3,#8 (r0/GOT base clobbered) */
                        unsigned int *high = node + 2u + 0x40000u;
                        /* 0x27c178 add r2,r3,#1048576 (0x100000 bytes = 0x40000 words)
                         * + 0x27c180 add r2,r2,#8 */
                        if (head >= low) { /* 0x27c17c cmp r12,r0; blo 0x27c184 -> advance */
                            if (high > head) { /* 0x27c188 cmp r2,r12 / 0x27c18c bhi 0x27c1a0 */
                                contained = true;
                                break;
                            }
                        }
                        node = *reinterpret_cast<unsigned int *volatile *>(node); /* 0x27c190 ldr r3,[r3] */
                    } while (node != nullptr); /* 0x27c194 cmp r3,#0 / 0x27c198 bne 0x27c174 */
                    if (!contained) {
                        *trap_target = trap_value; /* 0x27c19c str r5,[r6] */
                    }
                }
                head = *reinterpret_cast<unsigned int *volatile *>(head); /* 0x27c1a0 ldr r12,[r12] */
                *counter += 1u; /* 0x27c1a4 ldr r3,[r1] / 0x27c1ac add r3,r3,#1 / 0x27c1b0 str r3,[r1] */
            } while (head != nullptr); /* 0x27c1a8 cmp r12,#0 / 0x27c1b4 bne 0x27c168 */
        }
    }

    /* 0x27c1b8 pop {r4,r5,r6,r7,r8} / 0x27c1bc bx lr — epilogue; also the
     * block-6 head==null exit (0x27c164 beq 0x27c1b8). */
}
