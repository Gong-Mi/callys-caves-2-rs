#ifndef CALLY_RECOVERED_VM_BUFFER_HPP
#define CALLY_RECOVERED_VM_BUFFER_HPP

#include <stddef.h>
#include <stdint.h>

/* Recovered C++ interface, not the original source spelling.
 * tier: bytecode_anchored, ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchors: VMBuffer vtable 0x3eb8a8; VMWriteBuffer RTTI 0x3eb948;
 * CCode::CCode allocation/field stores 0xcf10c..0xcf144, 0xcf1fc..0xcf20c;
 * VMWriteBuffer constructor 0xec5b4..0xec604.
 * gap: field names/access levels are reconstructed; metadata08/metadata0c
 * meanings, cache writers and unlinked internal providers remain unproven.
 * This file does not replace the existing C translations or the game runtime.
 */
#if !defined(__arm__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "This recovered layout targets little-endian ARM32, not arm64"
#endif
static_assert(sizeof(void *) == 4 && sizeof(int) == 4, "original ARM32 ABI");
static_assert(sizeof(long long) == 8 && sizeof(double) == 8 && sizeof(float) == 4,
              "original scalar widths");

struct VMExec;
using VMInstructionHandler = uint8_t *(*)(uint32_t, uint8_t *, const uint8_t *, VMExec *);

class VMBuffer {
public:
    /* D1/D2: 0xce43c; compiler-supplied deleting variant D0: 0xce4c0. */
    virtual ~VMBuffer();
    void convertBuffer();                            // 0xec750..0xecb34

    // The C++ ABI supplies the vptr at +0x00; it is not an unknown data word.
    int32_t bufferSize;                               // +0x04: conversion span / writer capacity
    uint32_t metadata08;                              // +0x08: zero-extended CODE halfword
    uint32_t metadata0c;                              // +0x0c: zero-extended CODE halfword
    uint8_t *code;                                    // +0x10: owned bytes or borrowed WAD memory
    VMInstructionHandler *handlers;                   // +0x14: dense-slot handler array
    uint32_t *offsetToSlot;                           // +0x18: instruction-word offset -> slot
};

class VMWriteBuffer : public VMBuffer {
public:
    explicit VMWriteBuffer(int initialCapacity);      // 0xec5b4
    ~VMWriteBuffer() override;                        // D1/D2 0xec4a4; D0 0xec528
    void Reserve(int additionalBytes);                // 0xec604
    void Add(int wordCount, ...);                     // 0xec674: four bytes per argument word
    void AddVal(double value);                       // 0xec6dc
    void AddVal(float value);                        // 0xec6fc: preserves double promotion
    void AddVal(int value);                          // 0xec710
    void AddVal(long long value);                    // 0xec71c
    void AddVal(bool value);                         // 0xec73c

    uint8_t *writeCursor;                             // +0x1c: observed derived-class tail
};

/* Explicit bindings for the anonymous original cache at 0x47f3a0.
 * These descriptive names are NOT claimed as recovered original symbols.
 * Lookup consumes +8 hashes and +4 table pointers; it never reads keyWord.
 * The executable supplying these globals must restore the original initial
 * state. No default cache or handler stubs are defined in this source module.
 */
struct VMBufferCacheBucket {
    uint32_t keyWord;
    VMInstructionHandler *handlers;
    uint32_t hash;
};
struct VMBufferDispatchCache {
    uint32_t capacity;
    uint32_t count;
    uint32_t mask;
    uint32_t growAt;
    const volatile VMBufferCacheBucket *buckets;
};
extern volatile VMBufferDispatchCache g_VMBufferDispatchCache;
extern volatile VMInstructionHandler g_instructions[32];
extern const volatile uint32_t g_paramSize[16];

/* Preserve the original instantiated C++ template symbol at 0xec748. */
template <typename T> unsigned int CHashMapCalculateHash(T value);
template <> unsigned int CHashMapCalculateHash<unsigned char *>(unsigned char *value);

/* Internal original dependency, recovered in wad_memory.cpp (0x1aad50).
 * The two globals are original relocation-backed data, not runtime snapshots.
 */
extern uint8_t *g_pWADBaseAddress;
extern uint8_t *g_pWADEndAddress;
bool MemoryInWad(void *address);

/* Original internal providers still outside this batch; declarations are not
 * implementations. In particular the four Do* bodies are not synthetic here.
 */
class MemoryManager {
public:
    static void *Alloc(unsigned int, const char *, int, bool); // 0x27ce78
    static void *ReAlloc(void *, unsigned int, const char *, int, bool); // 0x27cedc
    static void Free(const void *);                           // 0x27c2d0
};
uint8_t *DoConvIntToVariable(uint32_t, uint8_t *, const uint8_t *, VMExec *);
uint8_t *DoPopLocalVariable(uint32_t, uint8_t *, const uint8_t *, VMExec *);
uint8_t *DoCallGML(uint32_t, uint8_t *, const uint8_t *, VMExec *);
uint8_t *DoCallLibrary(uint32_t, uint8_t *, const uint8_t *, VMExec *);

void *operator new[](size_t);                         // 0x27d14c
void operator delete[](void *) noexcept;              // 0x27d1d4
void operator delete(void *) noexcept;                // 0x27d1d0
extern "C" void *memcpy(void *, const void *, size_t); // original libc import

#endif
