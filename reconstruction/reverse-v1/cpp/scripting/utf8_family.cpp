// utf8_core.cpp — word-faithful transcription of the ten-member utf8_* C-helper family
// (Cally's Caves 2, libyoyo ARMv7), extending the family home that already holds
// utf8_extract_char (worktree scripting/utf8_core.cpp; its recovered body is NOT duplicated
// here — this TU links to it through the canonical declaration mirrored below).
//
// tier            : bytecode_anchored
// original image  : original-libyoyo-armv7.so (ARMv7 ELF32), sha256
//                   3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
// census          : gc-finalize-anchors/utf8-{get-char,strrchr,add-char,char-size,strlen,
//                   strcpy,strcmp,stricmp,strncmp,strstr}.asm.txt — every one of the 294
//                   words has an instruction-address comment below, in original order.
//
// The ten windows (dynsym identities parent-verified; window end = va + size):
//   utf8_get_char          va 0x10fae4 end 0x10fb38   84 B  21 words  sha256
//     42252315d5ae8ccfcfe498e20962625ebefc69be3b4af4d49e8157b220d4d820
//   utf8_strrchr           va 0x10fbbc end 0x10fc4c  144 B  36 words  sha256
//     a7b1ceb7072099a834827f12c48e030df652a5c7a4536f3bfef31a7fddd0d601
//   utf8_add_char          va 0x10fe28 end 0x10feb8  144 B  36 words  sha256
//     d5c28512cbc89c38530e862d9f6b37be94c73f606aa845dc8ea5c01b5dee70b3
//   utf8_char_size         va 0x110390 end 0x1103b0   32 B   8 words  sha256
//     7752c95f2a39d1f297a8c1a7687a9a7b391e7e0cde086954555c951a969a3571
//   utf8_strlen            va 0x110648 end 0x110690   72 B  18 words  sha256
//     1fd5ab6ba01afe0d205e37cabe45f6602b66e75920a86ad9c7d4152fe1f887ea
//   _Z11utf8_strcpyPcPKc   va 0x1109cc end 0x1109f4   40 B  10 words  sha256
//     5c5d4f95e5dfd02e35e9b3888ae9d1b383cc8eb34a0aa0b0de41f4fbe433f35e
//   utf8_strcmp            va 0x1109f4 end 0x110a74  128 B  32 words  sha256
//     6c48c6772f77175e51a2df37dd1e2af5bb81fd16fc5469521c8c9db740adfc6d
//   utf8_stricmp           va 0x110a74 end 0x110b34  192 B  48 words  sha256
//     5d363a8ba3e292da853502e6dc95a3571cea26d8b04e91d07085346f0a9d87a9
//   utf8_strncmp           va 0x110b34 end 0x110c04  208 B  52 words  sha256
//     1194f9810c64d3cc131ab643cf3bae9cfde2e2addebce64e56897357f609fd88
//   _Z11utf8_strstrPKcS0_  va 0x110c04 end 0x110c88  132 B  33 words  sha256
//     684d62972593c8efc089dd31f314cd864bcead5e5e66b4ea8df68ea68ec141c6
//   Total: 1176 B = 294 words (84+144+144+32+72+40+128+192+208+132; 21+36+36+8+18+10+32+48+52+33).
//
// Pool spans per census: exactly ONE of the ten windows contains literal-pool words —
// utf8_stricmp: code 0x110a74..0x110b2c (46 words), pool [0x110b2c,0x110b34) (2 words:
// 0x002dcecc at 0x110b2c, 0x002dceb0 at 0x110b30). Every other window is all-code.
//
// Slot resolution (.rel.dyn / .dynsym, read from the original image):
//   * the two stricmp pool words carry NO relocation — they are plain pc-relative
//     distance constants. 0x110ab8 ldrls r2,[pc,r2] reads pc(0x110ac0)+0x2dcecc =
//     0x3ed98c; 0x110ad4 ldrls r12,[pc,r12] reads pc(0x110adc)+0x2dceb0 = 0x3ed98c —
//     both paths converge on the SAME GOT entry.
//   * .rel.dyn @0x3ed98c = R_ARM_GLOB_DAT (0x15) -> dynsym OBJECT `_tolower_tab_`
//     (sym #464, UND, size 0 — an import from bionic libc; .got 0x3ed718..0x3f2000).
//     NAMED dynsym object -> declared as the named extern below. The deref chain is
//     r2 = GOT[0x3ed98c] (= &_tolower_tab_) ; r2 = *that (= the table pointer) ;
//     ldrsh at +2+2*c, i.e. _tolower_tab_[c+1] — the bionic `tolower(c)
//     _tolower_tab_[(c)+1]` macro shape. The census loads entries with ldrsh (signed
//     halfword), so the table is viewed as `const short *` here; bionic's own header
//     spells `const unsigned short *` — for the entries reachable here (c <= 255,
//     values < 0x8000 expected) the two spellings load identical values, but the
//     signed view is the one that reproduces the observed instruction.
//   * no other window reads data words: all GOT/anon-slot rules are exhausted by the
//     paragraph above; no anonymous slots were needed.
//
// gap paragraph: The caller family and the string producers feeding it are outside the
// recovered set. dynsym neighbours inside the same .text stretch (all FUNC GLOBAL,
// none recovered here): the windows sit interleaved with the F_String*/F_* GML-bound
// builtins — 0x10fc4c _Z5F_OrdR6RValueP9CInstanceS2_iPS_ (116B) fills the strrchr→
// add_char gap (with utf8_extract_char 0x10fb38, already recovered, between get_char
// and strrchr); 0x10feb8 _Z15F_StringLettersR6RValueP9CInstanceS2_iPS_ (180B),
// 0x10ff6c F_StringDigits (184B), 0x110024 F_StringLettersDigits (196B), 0x1100e8
// F_StringHashToNewline (680B) fill add_char→char_size; 0x1103b0 F_StringLower (332B)
// and 0x1104fc F_StringUpper (332B) fill char_size→strlen; 0x110690 F_StringLength
// (84B), 0x1106e4 F_StringCharAt (204B), 0x1107b0 F_StringOrdAt (164B), 0x110854
// F_StringInsert (376B) fill strlen→strcpy; 0x110c88 F_StringCount (144B) follows
// strstr. The producers of the strings these helpers walk, and every caller outside
// the family (e.g. the F_String* builtins), remain unrecovered. EHABI: the census
// windows contain only AAPCS push/pop register-pair sequences; no unwind-table bytes
// fall inside any window, so .ARM.exidx frame data for these functions is not
// asserted here. Final linked addresses are the prelinked .so virtual addresses as
// printed by the census. Nothing was executed in producing this file: census text,
// .rel.dyn (the single GLOB_DAT above; no other relocations touched) and .dynsym were
// read from the original image only. No equivalence claims of any kind are made; the
// compiled objects are shape carriers for this transcription, not verified
// replacements of the original code.
//
// Canonical declarations (grepped before declaring; frozen-seam/worktree shapes):
//   scripting/utf8_core.cpp:25 (worktree home)  extern "C" int utf8_extract_char(unsigned char **str)
//   vm_buffer.hpp:112                            extern "C" void *memcpy(void *, const void *, size_t);
//   gc_add_class_stat.cpp:96                     size_t strlen(const char *);  // + extern "C" here
//   memory_alloc.hpp:22 declares memset only — not needed by any of the ten bodies.

typedef __SIZE_TYPE__ size_t; // freestanding -nostdinc++: no <cstddef>; armv7a-none-eabi size_t = unsigned int

// ---- canonical declarations ----
extern "C" int utf8_extract_char(unsigned char **str); // scripting/utf8_core.cpp:25, mirrored EXACTLY
extern "C" size_t strlen(const char *);                // libc strlen@plt 0xb6538 (census bl targets)
extern "C" void *memcpy(void *, const void *, size_t); // libc memcpy@plt 0xb65bc (house spelling)
// dynsym OBJECT `_tolower_tab_` (#464 UND size 0, bionic import; held via GOT entry
// 0x3ed98c, R_ARM_GLOB_DAT): pointer to the int16 fold table, entry c at index c+1.
extern "C" const short *_tolower_tab_;

// ------------------------------------------------------------------
// utf8_get_char — va 0x10fae4, 84 B (21 words), leaf, no pool.
// Decodes the UTF-8 sequence AT str without advancing; same 1/2/3-byte
// shape as utf8_extract_char, 16-bit truncation on the 3-byte path.
// ------------------------------------------------------------------
extern "C" int utf8_get_char(const unsigned char *str) {
    const unsigned char b0 = str[0]; /* 0x10fae4 ldrb r3,[r0] */
    /* 0x10fae8 tst r3,#128 ; 0x10faec beq 0x10fb30 : ASCII fast path */
    if ((b0 & 0x80u) == 0u) {
        return b0; /* 0x10fb30 mov r0,r3 ; 0x10fb34 bx lr */
    }
    /* 0x10faf0 tst r3,#32 ; 0x10faf4 bne 0x10fb0c : three-byte branch when payload bit set */
    if ((b0 & 0x20u) != 0u) {
        const unsigned char b1 = str[1]; /* 0x10fb0c ldrb r2,[r0,#1] */
        const unsigned char b2 = str[2]; /* 0x10fb10 ldrb r0,[r0,#2] */
        /* 0x10fb14 and r2,r2,#63 ; 0x10fb18 and r0,r0,#63 ; 0x10fb1c lsl r2,r2,#6
         * 0x10fb20 add r3,r2,r3,lsl #12 ; 0x10fb24 add r0,r0,r3
         * 0x10fb28 uxth r0,r0 : 16-bit truncation ; 0x10fb2c bx lr */
        return static_cast<int>(static_cast<unsigned short>(
            (b2 & 0x3fu) + ((static_cast<unsigned int>(b1 & 0x3fu) << 6) + (static_cast<unsigned int>(b0) << 12))));
    }
    const unsigned char b1 = str[1]; /* 0x10faf8 ldrb r0,[r0,#1] */
    /* 0x10fafc and r3,r3,#31 ; 0x10fb00 and r0,r0,#63
     * 0x10fb04 add r0,r0,r3,lsl #6 ; 0x10fb08 bx lr */
    return static_cast<int>((b1 & 0x3fu) + (static_cast<unsigned int>(b0 & 0x1fu) << 6));
}

// ------------------------------------------------------------------
// utf8_strrchr — va 0x10fbbc, 144 B (36 words), no pool.
// Backward UTF-8 scan from the string end; returns the start of the
// first (from the end) sequence whose codepoint equals c OR alt.
// extern edges: strlen@plt (0x10fbd0), utf8_extract_char (0x10fbf4,
// canonical declaration — the sibling body lives in the family home TU).
// The cursor slot [sp,#4] (r7) is modelled as the local `slot`.
// ------------------------------------------------------------------
extern "C" char *utf8_strrchr(char *str, int c, int alt) {
    /* 0x10fbbc push {r4,r5,r6,r7,r8,lr} ; 0x10fbc0 sub sp,sp,#8 */
    unsigned char *const start = reinterpret_cast<unsigned char *>(str); /* 0x10fbc4 mov r5,r0 */
    /* 0x10fbc8 mov r6,r1 : c ; 0x10fbcc mov r8,r2 : alt */
    /* 0x10fbd0 bl strlen@plt ; 0x10fbd4 adds r4,r5,r0 : end = start + strlen (flags = wrap check) */
    unsigned char *cursor = start + strlen(str);
    /* 0x10fbd8 addlo r7,sp,#4 ; 0x10fbdc blo 0x10fbec : proceed only when the add did NOT wrap
     * 0x10fbe0 b 0x10fc3c : wrap -> NULL. no-wrap <=> (unsigned)end >= (unsigned)start */
    if (cursor < start) {
        return 0; /* 0x10fc3c mov r4,#0 */
    }
    unsigned char *slot; /* [sp,#4]; r7 = 0x10fbd8 addlo r7,sp,#4 = &slot */
    for (;;) {
        /* 0x10fbe4 cmp r4,r5 ; 0x10fbe8 blo 0x10fc3c : back-edge guard (cursor below start -> NULL) */
        if (cursor < start) {
            return 0; /* 0x10fc3c mov r4,#0 */
        }
        slot = cursor;                            /* 0x10fbf0 str r4,[sp,#4] */
        /* 0x10fbec mov r0,r7 ; 0x10fbf4 bl utf8_extract_char */
        const int cp = utf8_extract_char(&slot);
        /* 0x10fbf8 cmp r6,r0 ; 0x10fbfc beq 0x10fc40 : match against c
         * 0x10fc00 cmp r8,r0 ; 0x10fc04 beq 0x10fc40 : match against alt
         * 0x10fc40 mov r0,r4 : return sequence start (cursor) */
        if (c == cp || alt == cp) {
            return reinterpret_cast<char *>(cursor);
        }
        /* 0x10fc08 ldrsb r3,[r4] ; 0x10fc0c cmp r3,#0 : signed byte at cursor */
        const signed char lead = static_cast<signed char>(*cursor);
        /* 0x10fc10 subge r4,r4,#1 ; 0x10fc14 bge 0x10fbe4 : ASCII/NUL -> step back one byte, loop */
        if (lead >= 0) {
            cursor -= 1;
            continue;
        }
        /* lead/continuation byte: 0x10fc18 sub r3,r4,#1 ; 0x10fc1c mov r4,r3 :
         * unconditional first step, then 0x10fc20 sub r3,r3,#1 (prepared) */
        cursor -= 1;
        /* 0x10fc24 ldrb r12,[r4] ; 0x10fc28 and r12,r12,#192 ; 0x10fc2c cmp r12,#128
         * 0x10fc30 beq 0x10fc1c : keep stepping back through 10xxxxxx continuation bytes */
        while ((*cursor & 0xC0u) == 0x80u) {
            cursor -= 1;
        }
        /* 0x10fc34 cmp r4,r5 ; 0x10fc38 bhs 0x10fbec : still inside the string -> next extract */
        if (cursor >= start) {
            continue;
        }
        return 0; /* 0x10fc3c mov r4,#0 */
    }
    /* 0x10fc44 add sp,sp,#8 ; 0x10fc48 pop {r4,r5,r6,r7,r8,pc} : shared epilogue */
}

// ------------------------------------------------------------------
// utf8_add_char — va 0x10fe28, 144 B (36 words), leaf, no pool.
// Encodes c (1/2/3 bytes) at *str and advances *str past the sequence.
// Census reloads [r0] before every strb (aliasing-ignorant codegen);
// this body loads *str once — store order and byte values are identical.
// ------------------------------------------------------------------
extern "C" void utf8_add_char(unsigned char **str, unsigned int c) {
    unsigned char *p = *str; /* 0x10fe2c ldr r3,[r0] (loaded before the branch) */
    /* 0x10fe28 cmp r1,#127 ; 0x10fe30 bls 0x10fe78 : one-byte form (unsigned <=) */
    if (c <= 127u) {
        p[0] = static_cast<unsigned char>(c); /* 0x10fe78 strb r1,[r3] */
        /* 0x10fe7c ldr r3,[r0] ; 0x10fe80 add r3,r3,#1 ; 0x10fe84 str r3,[r0]
         * 0x10fe88 bx lr */
        *str = p + 1;
        return;
    }
    /* 0x10fe34 cmp r1,#2048 ; 0x10fe38 blo 0x10fe8c : two-byte form (c < 2048) */
    if (c < 2048u) {
        /* 0x10fe8c asr r2,r1,#6 ; 0x10fe90 and r1,r1,#63 ; 0x10fe94 sub r2,r2,#64 :
         * lead = (c>>6) - 64, == 0xC0|(c>>6) mod 256 on this branch's 128..2047 domain
         * 0x10fe98 strb r2,[r3] */
        p[0] = static_cast<unsigned char>((c >> 6) - 64u);
        /* 0x10fe9c ldr r3,[r0] ; 0x10fea0 sub r1,r1,#128 : == 0x80|(c&63) mod 256
         * 0x10fea4 strb r1,[r3,#1] */
        p[1] = static_cast<unsigned char>((c & 63u) - 128u);
        /* 0x10fea8 ldr r3,[r0] ; 0x10feac add r3,r3,#2 ; 0x10feb0 str r3,[r0]
         * 0x10feb4 bx lr */
        *str = p + 2;
        return;
    }
    /* three-byte form: 0x10fe3c lsr r12,r1,#12 ; 0x10fe40 ubfx r2,r1,#6,#6
     * 0x10fe44 sub r12,r12,#32 : lead = (c>>12) - 32, == 0xE0|(c>>12) mod 256
     * 0x10fe48 strb r12,[r3] */
    p[0] = static_cast<unsigned char>((c >> 12) - 32u);
    /* 0x10fe4c ldr r3,[r0] ; 0x10fe50 sub r2,r2,#128 ; 0x10fe54 and r1,r1,#63
     * 0x10fe58 sub r1,r1,#128 : continuation bytes as 0x80|x mod 256
     * 0x10fe5c strb r2,[r3,#1] ; 0x10fe60 ldr r3,[r0] ; 0x10fe64 strb r1,[r3,#2]
     * 0x10fe68 ldr r3,[r0] ; 0x10fe6c add r3,r3,#3 ; 0x10fe70 str r3,[r0]
     * 0x10fe74 bx lr */
    p[1] = static_cast<unsigned char>(((c >> 6) & 63u) - 128u);
    p[2] = static_cast<unsigned char>((c & 63u) - 128u);
    *str = p + 3;
}

// ------------------------------------------------------------------
// utf8_char_size — va 0x110390, 32 B (8 words), leaf, no pool.
// ------------------------------------------------------------------
extern "C" int utf8_char_size(unsigned int c) {
    /* 0x110390 cmp r0,#127 ; 0x110394 bls 0x1103a8 */
    if (c <= 127u) {
        return 1; /* 0x1103a8 mov r0,#1 ; 0x1103ac bx lr */
    }
    /* 0x110398 cmp r0,#2048 ; 0x11039c movlo r0,#2 ; 0x1103a0 movhs r0,#3 ; 0x1103a4 bx lr */
    return (c < 2048u) ? 2 : 3;
}

// ------------------------------------------------------------------
// utf8_strlen — va 0x110648, 72 B (18 words), no pool.
// Counts utf8_extract_char steps until the cursor lands on NUL.
// utf8_extract_char edge: extern declaration (0x110670 bl 0x10fb38 —
// the body lives in the family home TU).
// ------------------------------------------------------------------
extern "C" int utf8_strlen(const char *str) {
    /* 0x110648 push {r4,r5,lr} ; 0x11064c sub sp,sp,#12 */
    unsigned char *cursor = reinterpret_cast<unsigned char *>(const_cast<char *>(str));
    /* 0x110650 str r0,[sp,#4] : cursor slot = str
     * 0x110654 ldrb r4,[r0] ; 0x110658 cmp r4,#0 ; 0x11065c beq 0x110684 : empty -> 0 */
    if (*cursor == 0) {
        return 0; /* 0x110684 mov r0,r4 (r4 still holds the NUL byte read) */
    }
    unsigned char **const slot = &cursor; /* 0x110660 add r5,sp,#4 = &cursor slot */
    int count = 0;                        /* 0x110664 mov r4,#0 */
    do {
        count += 1; /* 0x11066c add r4,r4,#1 (counted BEFORE the extract) */
        /* 0x110668 mov r0,r5 ; 0x110670 bl utf8_extract_char */
        utf8_extract_char(slot);
        /* 0x110674 ldr r3,[sp,#4] ; 0x110678 ldrb r3,[r3] ; 0x11067c cmp r3,#0
         * 0x110680 bne 0x110668 */
    } while (*cursor != 0);
    return count; /* 0x110684 mov r0,r4 ; 0x110688 add sp,sp,#12 ; 0x11068c pop {r4,r5,pc} */
}

// ------------------------------------------------------------------
// _Z11utf8_strcpyPcPKc — va 0x1109cc, 40 B (10 words), no pool.
// C++ mangled member: utf8_strcpy(char*, char const*).
// extern edges: strlen@plt (0x1109dc), memcpy@plt tail call (0x1109f0).
// ------------------------------------------------------------------
void utf8_strcpy(char *dst, const char *src) {
    /* 0x1109cc push {r3,r4,r5,lr} ; 0x1109d0 mov r5,r0 (dst kept) ; 0x1109d4 mov r0,r1
     * 0x1109d8 mov r4,r1 (src kept) */
    /* 0x1109dc bl strlen@plt ; 0x1109e0 mov r1,r4 ; 0x1109e4 add r2,r0,#1 ; 0x1109e8 mov r0,r5 :
     * memcpy(dst, src, strlen(src) + 1)
     * 0x1109ec pop {r3,r4,r5,lr} ; 0x1109f0 b memcpy@plt : tail call (r0 passes through as dst) */
    memcpy(dst, src, strlen(src) + 1);
}

// ------------------------------------------------------------------
// utf8_strcmp — va 0x1109f4, 128 B (32 words), no pool.
// Codepoint-wise compare; on the first difference the census ROLLS the
// two cursor slots back (0x110a68/0x110a6c) and re-extracts at the
// mismatch position (0x110a48..0x110a58) — value-identical to returning
// the two just-compared codepoints, which is what this body does.
// utf8_extract_char edges: extern declaration (0x110a1c, 0x110a28,
// 0x110a4c, 0x110a58 — all bl 0x10fb38).
// ------------------------------------------------------------------
extern "C" int utf8_strcmp(const char *s1, const char *s2) {
    /* 0x1109f4 push {r4,r5,r6,r7,r8,lr} ; 0x1109f8 sub sp,sp,#8 */
    unsigned char *p1 = reinterpret_cast<unsigned char *>(const_cast<char *>(s1)); /* 0x110a00 str r0,[sp,#4] */
    unsigned char *p2 = reinterpret_cast<unsigned char *>(const_cast<char *>(s2)); /* 0x110a04 str r1,[sp] */
    unsigned char **const slot1 = &p1; /* 0x1109fc add r7,sp,#4 = &p1 slot */
    unsigned char **const slot2 = &p2; /* 0x110a04 [sp] = &p2 slot */
    /* 0x110a08 b 0x110a34 : enter at the loop head */
    for (;;) {
        /* head 0x110a34 ldr r4,[sp,#4] ; 0x110a38 mov r0,r7 ; 0x110a3c ldrb r3,[r4]
         * 0x110a40 cmp r3,#0 ; 0x110a44 bne 0x110a0c : *p1 != 0 -> body */
        if (*p1 == 0) {
            break;
        }
        /* body 0x110a0c ldr r5,[sp] ; 0x110a10 ldrb r3,[r5] ; 0x110a14 cmp r3,#0
         * 0x110a18 beq 0x110a48 : *p2 != 0 -> compare another pair */
        if (*p2 == 0) {
            break;
        }
        const int c1 = utf8_extract_char(slot1); /* 0x110a1c bl utf8_extract_char (r0=r7) ; 0x110a20 mov r6,r0 */
        const int c2 = utf8_extract_char(slot2); /* 0x110a24 mov r0,sp ; 0x110a28 bl utf8_extract_char */
        /* 0x110a2c cmp r6,r0 ; 0x110a30 bne 0x110a68 */
        if (c1 != c2) {
            /* 0x110a68 str r4,[sp,#4] ; 0x110a6c str r5,[sp] : slot rollback to pre-extract
             * 0x110a70 b 0x110a48 -> final re-extract returns c1 - c2 (0x110a5c rsb) */
            return c1 - c2;
        }
    }
    /* final 0x110a48 mov r0,r7 ; 0x110a4c bl utf8_extract_char ; 0x110a50 mov r4,r0
     * 0x110a54 mov r0,sp ; 0x110a58 bl utf8_extract_char
     * 0x110a5c rsb r0,r0,r4 : return c1 - c2 (unfolded, raw codepoints)
     * 0x110a60 add sp,sp,#8 ; 0x110a64 pop {r4,r5,r6,r7,r8,pc} */
    return utf8_extract_char(slot1) - utf8_extract_char(slot2);
}

// ------------------------------------------------------------------
// utf8_stricmp — va 0x110a74, 192 B = 46 code words + 2 pool words
// (pool [0x110b2c,0x110b34)), the only pooled window in this family.
// Codepoint-wise case-insensitive compare: codepoints <= 255 are folded
// through _tolower_tab_ (GOT entry 0x3ed98c, R_ARM_GLOB_DAT) at index
// c+1 with SIGNED halfword loads; the comparison uses folded values but
// the returned difference is the RAW (unfolded) pair — on mismatch the
// census rolls the slots back (0x110b20/0x110b24) and re-extracts raw
// (0x110b00..0x110b10), value-identical to returning the raw pair.
// utf8_extract_char edges: extern declaration (0x110a9c, 0x110aa8,
// 0x110b04, 0x110b10 — all bl 0x10fb38).
// ------------------------------------------------------------------
extern "C" int utf8_stricmp(const char *s1, const char *s2) {
    /* 0x110a74 push {r4,r5,r6,r7,r8,lr} ; 0x110a78 sub sp,sp,#8 */
    unsigned char *p1 = reinterpret_cast<unsigned char *>(const_cast<char *>(s1)); /* 0x110a80 str r0,[sp,#4] */
    unsigned char *p2 = reinterpret_cast<unsigned char *>(const_cast<char *>(s2)); /* 0x110a84 str r1,[sp] */
    unsigned char **const slot1 = &p1; /* 0x110a7c add r5,sp,#4 = &p1 slot */
    unsigned char **const slot2 = &p2; /* 0x110a84 [sp] = &p2 slot */
    /* 0x110a88 b 0x110aec : enter at the loop head */
    for (;;) {
        /* head 0x110aec ldr r7,[sp,#4] ; 0x110af0 mov r0,r5 ; 0x110af4 ldrb r3,[r7]
         * 0x110af8 cmp r3,#0 ; 0x110afc bne 0x110a8c : *p1 != 0 -> body */
        if (*p1 == 0) {
            break;
        }
        /* body 0x110a8c ldr r8,[sp] ; 0x110a90 ldrb r3,[r8] ; 0x110a94 cmp r3,#0
         * 0x110a98 beq 0x110b00 : *p2 != 0 -> compare another pair */
        if (*p2 == 0) {
            break;
        }
        const int c1 = utf8_extract_char(slot1); /* 0x110a9c bl utf8_extract_char (r0=r5) ; 0x110aa0 mov r4,r0 */
        const int c2 = utf8_extract_char(slot2); /* 0x110aa4 mov r0,sp ; 0x110aa8 bl utf8_extract_char */
        /* fold c1 (c1 <= 255 only):
         * 0x110aac ldr r2,[pc,#0x78] @ 0x110b2c = 0x002dcecc (no-reloc distance constant)
         * 0x110ab0 cmp r4,#255 ; 0x110ab4 mov r1,r4 (default: raw)
         * 0x110ab8 ldrls r2,[pc,r2] : pc 0x110ac0 + 0x2dcecc = 0x3ed98c (GOT entry)
         * 0x110abc ldr r12,[pc,#0x6c] @ 0x110b30 = 0x002dceb0 (no-reloc distance constant)
         * 0x110ac0 ldrls r2,[r2] : *GOT -> _tolower_tab_ pointer value
         * 0x110ac4 addls r4,r2,r4,lsl #1 ; 0x110ac8 ldrshls r1,[r4,#2] : _tolower_tab_[c1+1] */
        const int f1 = (static_cast<unsigned int>(c1) > 255u) ? c1 : _tolower_tab_[c1 + 1];
        /* fold c2 (c2 <= 255 only):
         * 0x110acc cmp r0,#255 ; 0x110ad0 mov r2,r0 (default: raw)
         * 0x110ad4 ldrls r12,[pc,r12] : pc 0x110adc + 0x2dceb0 = 0x3ed98c (SAME GOT entry)
         * 0x110ad8 ldrls r2,[r12] ; 0x110adc addls r3,r2,r0,lsl #1
         * 0x110ae0 ldrshls r2,[r3,#2] : _tolower_tab_[c2+1] */
        const int f2 = (static_cast<unsigned int>(c2) > 255u) ? c2 : _tolower_tab_[c2 + 1];
        /* 0x110ae4 cmp r1,r2 ; 0x110ae8 bne 0x110b20 */
        if (f1 != f2) {
            /* 0x110b20 str r7,[sp,#4] ; 0x110b24 str r8,[sp] : slot rollback to pre-extract
             * 0x110b28 b 0x110b00 -> final re-extract returns the RAW c1 - c2 (0x110b14 rsb) */
            return c1 - c2;
        }
    }
    /* final 0x110b00 mov r0,r5 ; 0x110b04 bl utf8_extract_char ; 0x110b08 mov r4,r0
     * 0x110b0c mov r0,sp ; 0x110b10 bl utf8_extract_char
     * 0x110b14 rsb r0,r0,r4 : return raw c1 - c2
     * 0x110b18 add sp,sp,#8 ; 0x110b1c pop {r4,r5,r6,r7,r8,pc}
     * pool 0x110b2c .word 0x002dcecc ; pool 0x110b30 .word 0x002dceb0 (disassembled
     * as eoreq/<unknown> in the census — data, transcribed above) */
    return utf8_extract_char(slot1) - utf8_extract_char(slot2);
}

// ------------------------------------------------------------------
// utf8_strncmp — va 0x110b34, 208 B (52 words), no pool.
// Codepoint-wise bounded compare with int n (signed `ble` gate).
// Entry gate: *s1, *s2, n <= 0 all route to the tail; the first extract
// pair runs WITHOUT re-checking (entry already checked). On mismatch the
// census rolls the slots back (0x110bc0/0x110bc4) and re-extracts raw
// (0x110bc8..0x110bd8) — value-identical to returning the compared pair.
// utf8_extract_char edges: extern declaration (0x110ba8, 0x110bb4,
// 0x110bcc, 0x110bd8 — all bl 0x10fb38).
// ------------------------------------------------------------------
extern "C" int utf8_strncmp(const char *s1, const char *s2, int n) {
    /* 0x110b34 push {r4,r5,r6,r7,r8,r9,lr} ; 0x110b38 sub sp,sp,#12
     * 0x110b3c mov r5,r0 : s1 kept */
    unsigned char *p1 = reinterpret_cast<unsigned char *>(const_cast<char *>(s1)); /* 0x110b44 str r0,[sp,#4] */
    unsigned char *p2 = reinterpret_cast<unsigned char *>(const_cast<char *>(s2)); /* 0x110b48 str r1,[sp] */
    unsigned char **const slot1 = &p1; /* 0x110b70 add r9,sp,#4 = &p1 slot (also re-set at 0x110bfc on the tail path) */
    unsigned char **const slot2 = &p2; /* 0x110b48 [sp] = &p2 slot */
    /* remaining lives in r4: 0x110b40 mov r4,r2 */
    /* 0x110b4c ldrb r3,[r0] ; 0x110b50 cmp r3,#0 ; 0x110b54 beq 0x110be8 :
     * 0x110b58 ldrb r3,[r1] ; 0x110b5c mov r6,r1 ; 0x110b60 cmp r3,#0 ; 0x110b64 beq 0x110be8 :
     * 0x110b68 cmp r2,#0 ; 0x110b6c ble 0x110be8 : entry gate -> tail
     * 0x110b74 b 0x110ba0 : first extract pair runs without re-check */
    if (*p1 != 0 && *p2 != 0 && n > 0) {
        int remaining = n;
        for (;;) {
            remaining -= 1;                        /* 0x110ba4 sub r4,r4,#1 (before the extract) */
            const int c1 = utf8_extract_char(slot1); /* 0x110ba0 mov r0,r9 ; 0x110ba8 bl utf8_extract_char ; 0x110bac mov r7,r0 */
            const int c2 = utf8_extract_char(slot2); /* 0x110bb0 mov r0,sp ; 0x110bb4 bl utf8_extract_char */
            /* 0x110bb8 cmp r7,r0 ; 0x110bbc beq 0x110b78 : equal -> body checks */
            if (c1 != c2) {
                /* 0x110bc0 str r5,[sp,#4] ; 0x110bc4 str r6,[sp] : slot rollback to pre-extract,
                 * then the shared tail at 0x110bc8 re-extracts raw -> returns c1 - c2 */
                return c1 - c2;
            }
            /* body 0x110b78 ldr r5,[sp,#4] ; 0x110b7c ldrb r3,[r5] ; 0x110b80 cmp r3,#0
             * 0x110b84 beq 0x110be8 ; 0x110b88 ldr r6,[sp] ; 0x110b8c ldrb r3,[r6]
             * 0x110b90 cmp r3,#0 ; 0x110b94 beq 0x110be8 : a string ended */
            if (*p1 == 0 || *p2 == 0) {
                /* 0x110b98 cmp r4,#0 ; 0x110b9c beq 0x110bf0 : exhausted -> equal */
                if (remaining == 0) {
                    return 0; /* 0x110bf0 mov r0,r4 (r4 == 0) */
                }
                /* 0x110be8 cmp r4,#0 ; 0x110bec bne 0x110bfc ; 0x110bfc add r9,sp,#4
                 * 0x110c00 b 0x110bc8 : extract the terminating pair raw and diff them
                 * (0x110bc8 mov r0,r9 ; 0x110bcc bl utf8_extract_char ; 0x110bd0 mov r4,r0
                 *  0x110bd4 mov r0,sp ; 0x110bd8 bl utf8_extract_char ; 0x110bdc rsb r0,r0,r4) */
                return utf8_extract_char(slot1) - utf8_extract_char(slot2); /* 0x110bc8..0x110bdc */
            }
            /* 0x110b98 cmp r4,#0 ; 0x110b9c beq 0x110bf0 : n codepoints all equal */
            if (remaining == 0) {
                return 0; /* 0x110bf0 mov r0,r4 */
            }
        }
    }
    /* tail (entry with *p1 == 0, or *p2 == 0, or n <= 0):
     * 0x110be8 cmp r4,#0 ; 0x110bec bne 0x110bfc ; 0x110bf0 mov r0,r4
     * 0x110bf4 add sp,sp,#12 ; 0x110bf8 pop {r4,r5,r6,r7,r8,r9,pc} */
    if (n == 0) {
        return 0;
    }
    /* 0x110bfc add r9,sp,#4 ; 0x110c00 b 0x110bc8 : extract both at the current
     * (entry) positions and return the raw difference (0x110bdc rsb) */
    return utf8_extract_char(slot1) - utf8_extract_char(slot2);
    /* 0x110be0 add sp,sp,#12 ; 0x110be4 pop {r4,r5,r6,r7,r8,r9,pc} : shared epilogue */
}

// ------------------------------------------------------------------
// _Z11utf8_strstrPKcS0_ — va 0x110c04, 132 B (33 words), no pool.
// C++ mangled member: utf8_strstr(char const*, char const*).
// FAMILY-INTERNAL edges (both sides recovered in THIS TU): utf8_strlen
// (0x110c14, 0x110c20) and utf8_strncmp (0x110c5c) — real intra-TU links.
// utf8_extract_char edge: extern declaration (0x110c44 bl 0x10fb38).
// ------------------------------------------------------------------
const char *utf8_strstr(const char *haystack, const char *needle) {
    /* 0x110c04 push {r4,r5,r6,r7,r8,lr} ; 0x110c08 sub sp,sp,#8
     * 0x110c0c mov r4,r0 ; 0x110c10 mov r5,r1 */
    const int len1 = utf8_strlen(haystack); /* 0x110c14 bl utf8_strlen ; 0x110c18 mov r6,r0 */
    const int len2 = utf8_strlen(needle);   /* 0x110c1c mov r0,r5 ; 0x110c20 bl utf8_strlen */
    /* 0x110c24 cmp r6,#0 ; 0x110c2c addgt r8,sp,#4 ; 0x110c34 movgt r0,r4 ; 0x110c38 movgt r4,#0
     * 0x110c3c bgt 0x110c54 ; 0x110c40 b 0x110c7c : empty haystack -> NULL */
    if (len1 <= 0) {
        return 0; /* 0x110c7c mov r0,#0 */
    }
    char *cursor = const_cast<char *>(haystack); /* 0x110c28 str r4,[sp,#4] (slot = haystack; never written through) */
    char **const slot = &cursor;      /* 0x110c2c addgt r8,sp,#4 = &cursor slot */
    int attempts = 0;                 /* 0x110c38 movgt r4,#0 */
    for (;;) {
        /* head 0x110c54 mov r1,r5 ; 0x110c58 mov r2,r7 (r7 = len2, set at 0x110c30)
         * r0 = slot value (first pass: 0x110c34 movgt r0,r4 = haystack; later: 0x110c50 ldr r0,[sp,#4])
         * 0x110c5c bl utf8_strncmp */
        if (utf8_strncmp(cursor, needle, len2) == 0) {
            /* 0x110c64 cmp r0,#0 (equal) -> fall through
             * 0x110c70 ldr r0,[sp,#4] : return the position where strncmp matched
             * (the slot was not advanced after the successful compare)
             * 0x110c74 add sp,sp,#8 ; 0x110c78 pop {r4,r5,r6,r7,r8,pc} */
            return cursor;
        }
        attempts += 1;                      /* 0x110c60 add r4,r4,#1 */
        /* 0x110c68 mov r0,r8 (=&slot, set before the branch) ; 0x110c6c bne 0x110c44
         * 0x110c44 bl utf8_extract_char : advance the haystack cursor (writes the slot) */
        utf8_extract_char(reinterpret_cast<unsigned char **>(slot));
        /* 0x110c48 cmp r4,r6 ; 0x110c4c beq 0x110c7c : exhausted -> NULL (mov r0,#0)
         * 0x110c7c mov r0,#0 ; 0x110c80 add sp,sp,#8 ; 0x110c84 pop {r4,r5,r6,r7,r8,pc} */
        if (attempts == len1) {
            return 0;
        }
    }
}
