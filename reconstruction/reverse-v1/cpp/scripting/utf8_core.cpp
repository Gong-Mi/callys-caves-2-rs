/* tier: bytecode_anchored. Static recovery of utf8_extract_char (0x10fb38,
 * 132B, dynsym GLOBAL -- unmangled C symbol) from original image
 * libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (census gc-finalize-anchors/utf8-extract-char.asm.txt, batch12_functions).
 *
 * First member of the utf8_* C helper family (siblings utf8_get_char,
 * utf8_add_char, utf8_char_size, utf8_strlen, utf8_strcmp/ncmp/icmp,
 * utf8_strrchr, utf8_strcpy, utf8_strstr, UTF8ToASCII at 0x10fae4..0x11119c
 * remain unrecovered; this file is the family home for future members).
 *
 * No external edges: the body is a pure leaf (no bl/blx, no GOT pair, no
 * literal pool; r4 push/pop is codegen detail). Decodes a 1..3-byte UTF-8
 * lead byte from *str, advances *str past the sequence, returns the
 * codepoint truncated to 16 bits on the 3-byte path (uxth at 0x1fb80).
 * Sequences with the 4-byte lead pattern are consumed by the SAME 3-byte
 * path in the original (there is no 4-byte branch) -- reproduced as-is.
 *
 * gap: the caller family and the string producers feeding it are outside
 * the recovered set; no NUL/bounds guard exists in the original and none is
 * added; EHABI unwind records are not recovered; nothing was executed and
 * no equivalence claim of any kind is made.
 */

extern "C" int utf8_extract_char(unsigned char **str) {
    /* 0x10fb38 ldr r3,[r0] : p = *str (current read cursor)
     * 0x10fb3c mov r1,r0 : the out-param pointer
     * 0x10fb40 str r4,[sp,#-4]! : r4 save (codegen detail) */
    unsigned char *p = *str;
    const unsigned char b0 = *p; /* 0x10fb44 ldrb r2,[r3] */
    /* 0x10fb48 tst r2,#128 / 0x10fb4c beq 0x10fb88 : ASCII fast path */
    if ((b0 & 0x80u) == 0u) {
        *str = p + 1; /* 0x10fb8c add r3,r3,#1 ; 0x10fb90 str r3,[r1] */
        return b0;    /* 0x10fb88 mov r0,r2 */
    }
    /* 0x10fb50 tst r2,#32 / 0x10fb54 beq 0x10fb9c : two-byte form */
    if ((b0 & 0x20u) == 0u) {
        /* 0x10fb9c ldrb r0,[r3,#1] : continuation byte
         * 0x1fba0 and r2,r2,#31 : lead payload
         * 0x1fba4 add r3,r3,#2 ; 0x1fbb0 str r3,[r1] : advance *str by 2
         * 0x1fbac and r0,r0,#63 : continuation payload
         * 0x1fbb4 add r0,r0,r2,lsl #6 : (b1 & 63) + (b0 & 31)*64 */
        const unsigned char b1 = p[1];
        *str = p + 2;
        return static_cast<int>((b1 & 0x3fu) + static_cast<unsigned int>(b0 & 0x1fu) * 64u);
    }
    /* three-byte form (the original has NO four-byte branch): */
    /* 0x10fb58 ldrb r4,[r3,#1] : b1
     * 0x10fb5c add r12,r3,#3 ; 0x1fb68 str r12,[r1] : advance *str by 3
     * 0x10fb60 ldrb r0,[r3,#2] : b2
     * 0x1fb64 and r3,r4,#63 ; 0x1fb74 lsl r3,r3,#6
     * 0x1fb6c and r0,r0,#63
     * 0x1fb78 add r2,r3,r2,lsl #12 ; 0x1fb7c add r0,r0,r2
     * 0x1fb80 uxth r0,r0 : 16-bit truncation
     * 0x1fb70/0x1fb94 ldr r4,[sp],#4 ; 0x1fb84 bx lr */
    const unsigned char b1 = p[1];
    const unsigned char b2 = p[2];
    *str = p + 3;
    const unsigned int codepoint = (b2 & 0x3fu) + ((b1 & 0x3fu) << 6) + (static_cast<unsigned int>(b0) << 12);
    return static_cast<int>(static_cast<unsigned short>(codepoint)); /* 0x1fb80 uxth */
}
