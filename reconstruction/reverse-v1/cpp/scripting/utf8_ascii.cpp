/* tier: bytecode_anchored. Static recovery of _Z10UTF8ToASCIIPKc (0x1110a0,
 * 144B = 36 words; LOCAL symbol -- no dynsym entry; boundary parent-derived:
 * next defined symbol _Z12YYGML_stringRK6RValue at 0x111130) from original
 * image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (batch 16; closes the utf8 cluster: all three edges are REAL links into
 * the recovered set -- utf8_strlen 0x110648 [utf8_family.cpp, batch 15],
 * MemoryManager::Alloc 0x27ce78 [memory_buckets.cpp, 4cd8354],
 * utf8_extract_char 0x10fb38 [utf8_core.cpp, batch 12]).
 *
 * The Alloc tag literal is a direct pc-relative .rodata read (add r1,pc,r1
 * @0x1110d0, pc 0x1110d8 + pool 0x11112c = 0x00227d74 -> 0x338b4c); the
 * parent byte-read the image: the tag is the single-character string "r"
 * (0x338b4c: 'r',0,0,0 followed by "instance_copy" etc.), embedded here as
 * the same literal.
 *
 * Semantics: null arg -> returns null; empty string -> returns 0 (the
 * first-byte load feeds the return register directly: moveq r0,r7 with
 * r7 = 0); otherwise Alloc(len+1, "r", 1536, true), walk the source with
 * utf8_extract_char through a stack cursor slot, store codepoints <= 127
 * (non-ASCII codepoints are DROPPED without store -- the strbls conditional
 * store at 0x1110fc), NUL-terminate, return the ASCII buffer.
 *
 * gap: Alloc's tag-string consumer, the string producers feeding this
 * converter, and the callers are outside the recovered set; EHABI unwind
 * records are not recovered; nothing was executed and no equivalence
 * claim of any kind is made.
 */

#include "../vm_buffer/vm_buffer.hpp" // MemoryManager::Alloc canonical declaration

/* utf8_strlen -- scripting/utf8_family.cpp (batch 15, recovered); the
 * extern declaration here binds the same C symbol. */
extern "C" unsigned int utf8_strlen(const unsigned char *str);
/* utf8_extract_char -- scripting/utf8_core.cpp (batch 12, recovered). */
extern "C" int utf8_extract_char(unsigned char **str);

char *UTF8ToASCII(const char *str) { // LOCAL symbol @0x1110a0, 144B
    /* 0x1110a4 subs r5,r0,#0 / 0x1110a8 sub sp,#12 / 0x1110ac beq 0x111124
     * 0x111124 mov r0,r5 : null arg -> returns the null pointer as-is
     * 0x111128 b 0x11111c : epilogue */
    if (str == nullptr) {
        return nullptr;
    }
    /* 0x1110b0 ldrb r7,[r5] : first byte; 0x1110b4 cmp #0
     * 0x1110b8 moveq r0,r7 (r7 = 0) / 0x1110bc beq 0x11111c : empty string
     *   -> returns 0 (the byte value feeds the return register directly) */
    if (*str == '\0') {
        return nullptr;
    }
    /* 0x1110c0 bl utf8_strlen : real edge (recovered, batch 15) */
    const unsigned int len = utf8_strlen(reinterpret_cast<const unsigned char *>(str));
    /* 0x1110c4 ldr r1,[pc,#0x60] (pool 0x11112c = 0x00227d74)
     * 0x1110d0 add r1,pc,r1 : Alloc tag literal "r" at 0x338b4c
     * 0x1110cc mov r2,#1536 ; 0x1110c8 mov r3,#1
     * 0x1110dc bl MemoryManager::Alloc(len+1, "r", 1536, true) : real edge */
    char *out = static_cast<char *>(
        MemoryManager::Alloc(len + 1u, "r", 1536, true));
    /* 0x1110e0 str r5,[r4,#-4]! : the source cursor lives in a stack slot
     * 0x1110e8/0x1110ec mov r7/r6,r0 : write cursor = allocation base
     * 0x1110f0 b 0x111104 : jump to the cursor-byte test first */
    const unsigned char *cursor = reinterpret_cast<const unsigned char *>(str);
    char *write = out;
    /* per iteration:
     *   0x111104 ldrb r3,[cursor] : test byte (NUL exits)
     *   0x111108 mov r0,r4 --&cursor : extract_char out-param
     *   0x1110f4 bl utf8_extract_char : real edge (recovered, batch 12)
     *   0x1110f8 cmp r0,#127 ; 0x1110fc strbls r0,[r6],#1 : store ASCII only
     *     (non-ASCII codepoints are DROPPED: no store, cursor advanced)
     *   0x111100 ldr r3,[sp,#4] : cursor reload from the stack slot
     *   0x111110 bne : loop while the (extract-advanced) cursor byte != 0 */
    while (*cursor != '\0') {
        const int cp = utf8_extract_char(const_cast<unsigned char **>(&cursor));
        if (static_cast<unsigned int>(cp) <= 127u) { /* 0x1110f8/0x1110fc strbls */
            *write++ = static_cast<char>(static_cast<unsigned char>(cp));
        }
    }
    /* 0x111114 mov r0,r7 (return the allocation base)
     * 0x111118 strb r3,[r6] : r3 = 0 (the loop-exit NUL byte read at
     *   0x111104) -> NUL-terminate the ASCII buffer */
    *write = '\0';
    return out;
}
