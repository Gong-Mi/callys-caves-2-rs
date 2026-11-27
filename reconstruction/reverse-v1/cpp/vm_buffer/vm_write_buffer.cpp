#include "vm_buffer.hpp"

/* -------------------------------------------------------------------------
 * VMWriteBuffer — recovered writer subclass of VMBuffer.
 * tier: bytecode_anchored.
 * ARMv7 ELF SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * shared header SHA256 c601b9cf5eee566bdde9be168452fe5ec043e5092f1d6f4e8ebabbe892985cbe
 * RTTI 0x3eb948 proves single inheritance from VMBuffer; the observed derived
 * prefix contains writeCursor at +0x1c. Unobserved tail members are not ruled out.
 * gap: metadata08/metadata0c are never written by any function in this batch
 * (the original constructor leaves them untouched) and their meanings stay
 * unproven, so nothing below initialises them. Do* handler bodies, the
 * dispatch cache semantics and the +0x14/+0x18 conversion tables belong to
 * other recovery units.
 * ------------------------------------------------------------------------- */

/* 0xec5b4 VMWriteBuffer(int initialCapacity) — C1/C2.
 * The original clears code/handlers/offsetToSlot to zero, calls the array
 * operator 0x27d14c with the raw int widened to size_t, and only after the
 * allocation returns publishes bufferSize (+0x04 = initial capacity),
 * code (+0x10) and writeCursor (+0x1c, empty stream). metadata08/0c are
 * deliberately not zeroed here, matching the original store pattern.
 */
VMWriteBuffer::VMWriteBuffer(int initialCapacity) {
    volatile VMWriteBuffer *state = this;
    volatile VMBuffer *base = this;
    base->code = nullptr;
    base->handlers = nullptr;
    base->offsetToSlot = nullptr;
    uint8_t *const block =
        static_cast<uint8_t *>(operator new[](static_cast<unsigned>(initialCapacity)));
    base->bufferSize = initialCapacity;
    base->code = block;
    state->writeCursor = block;
}

/* 0xec4a4 D1/D2 and 0xec528 D0 — ~VMWriteBuffer().
 * Both original bodies perform exactly the VMBuffer cleanup (Free handlers,
 * Free offsetToSlot, delete[] code unless MemoryInWad says the block is
 * borrowed WAD memory) while writing the base-class vtable: the compiler
 * inlined VMBuffer::~VMBuffer into the derived destructor. A defaulted
 * derived destructor reproduces that shape — the cleanup is provided by the
 * real base destructor (sibling recovery unit, written on the parent line),
 * and the deleting variant D0 comes from the ABI (cleanup + operator delete),
 * so no stand-in body is written here.
 */
VMWriteBuffer::~VMWriteBuffer() = default;

/* 0xec604 void Reserve(int additionalBytes).
 * Headroom is a BYTE count computed with 32-bit arithmetic:
 * bufferSize + (code - writeCursor),
 * then reinterpreted as signed for the early-out (cmp/bgt at 0xec624). The
 * growth loop allocates bufferSize<<1, memcpy's the already-written span,
 * doubles the stored capacity, and re-bases code/writeCursor onto the new
 * block, repeating until the request fits. This body contains no old-block
 * release and no max/overflow guard; allocator-wide reclamation is outside scope,
 * so all capacity math stays in uint32_t to keep the original wrap behaviour
 * out of C++ signed-overflow UB.
 */
void VMWriteBuffer::Reserve(int additionalBytes) {
    volatile VMWriteBuffer *state = this;
    volatile VMBuffer *base = this;
    uint8_t *cursor = state->writeCursor; // 0xec60c, before code/capacity
    uint8_t *current = base->code;       // 0xec614
    uint32_t capacity = static_cast<uint32_t>(base->bufferSize); // 0xec618
    const uint32_t occupied = reinterpret_cast<uintptr_t>(cursor) -
                              reinterpret_cast<uintptr_t>(current);
    if (additionalBytes <= static_cast<int32_t>(capacity - occupied)) {
        return; // 0xec624..0xec628
    }
    for (;;) {
        const uint32_t used = reinterpret_cast<uintptr_t>(cursor) -
                              reinterpret_cast<uintptr_t>(current); // 0xec62c
        void *const block = operator new[](capacity << 1);           // 0xec630..34
        // 0xec638: re-read the source after new[]. Use memcpy's actual return.
        uint8_t *const replacement = static_cast<uint8_t *>(memcpy(block, base->code, used));
        capacity = static_cast<uint32_t>(base->bufferSize) << 1;    // 0xec644..48
        base->bufferSize = static_cast<int32_t>(capacity);         // 0xec64c
        cursor = reinterpret_cast<uint8_t *>(reinterpret_cast<uintptr_t>(replacement) + used);
        state->writeCursor = cursor;                               // 0xec65c
        base->code = replacement;                                 // 0xec664
        current = replacement;
        // No old-block delete is present in the original growth loop.
        if (additionalBytes <= static_cast<int32_t>(capacity - used)) {
            return;                                               // 0xec668..70
        }
    }
}

/* 0xec674 void Add(int wordCount, ...).
 * Internal calling convention: every variadic argument is one 32-bit word;
 * all AddVal overloads below pass explicit uint32_t words, so nothing here
 * ever va_arg's a float/double/long long through the wrong type. Reserves
 * wordCount<<2 BYTES first (unconditionally, as in the original), ignores
 * non-positive counts without reading the argument list, then copies one
 * word at a time from the saved register/stack window and publishes
 * writeCursor exactly once, after the final store.
 */
void VMWriteBuffer::Add(int wordCount, ...) {
    Reserve(static_cast<int>(static_cast<uint32_t>(wordCount) << 2));
    if (wordCount <= 0) {
        return;
    }
    __builtin_va_list args;
    __builtin_va_start(args, wordCount);
    volatile VMWriteBuffer *state = this;
    uintptr_t at = reinterpret_cast<uintptr_t>(state->writeCursor);
    typedef uint32_t StreamWord __attribute__((may_alias));
    for (int i = 0; i < wordCount; ++i) {
        const uint32_t word = __builtin_va_arg(args, uint32_t);
        // Original STR, not an external memcpy per argument. Normal CODE
        // streams have a four-byte-aligned cursor and advance by four bytes.
        *reinterpret_cast<volatile StreamWord *>(at) = word;
        at += sizeof(word);
    }
    __builtin_va_end(args);
    state->writeCursor = reinterpret_cast<uint8_t *>(at);
}

/* 0xec6dc void AddVal(double).
 * The original round-trips the double through the stack (strd/ldm) and hands
 * Add two raw words, low half first (little-endian stream layout).
 */
void VMWriteBuffer::AddVal(double value) {
    const uint64_t bits = __builtin_bit_cast(uint64_t, value);
    Add(2, static_cast<uint32_t>(bits), static_cast<uint32_t>(bits >> 32));
}

/* 0xec6fc void AddVal(float) — preserved original quirk.
 * vcvt.f64.f32 promotes to double, then Add is tail-called with count = 1,
 * so the stream receives only the LOW 32 bits of the promoted double — not
 * the float's own bit pattern. This is faithful, not a bug being introduced;
 * it must not be "fixed" into a normal float serialisation.
 */
void VMWriteBuffer::AddVal(float value) {
    const uint64_t bits = __builtin_bit_cast(uint64_t, static_cast<double>(value));
    Add(1, static_cast<uint32_t>(bits));
}

/* 0xec710 void AddVal(int) — mov r2,r1; tail Add(1, word). */
void VMWriteBuffer::AddVal(int value) {
    Add(1, static_cast<uint32_t>(value));
}

/* 0xec71c void AddVal(long long) — stack round-trip, low word then high word,
 * identical word order to the double path above. */
void VMWriteBuffer::AddVal(long long value) {
    const uint64_t bits = static_cast<uint64_t>(value);
    Add(2, static_cast<uint32_t>(bits), static_cast<uint32_t>(bits >> 32));
}

/* 0xec73c void AddVal(bool) — same shape as the int path, one word. */
void VMWriteBuffer::AddVal(bool value) {
    Add(1, static_cast<uint32_t>(value));
}
