#include "ccode.hpp"

/* CCode lifetime methods; tier: bytecode_anchored.
 * ARMv7 ELF SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * D1/D2 0xce2b8..0xce36c (includes its literal pool), D0 0xce36c..0xce388,
 * GetText 0xcf470..0xcf478. The compiler supplies the vptr reset and D0;
 * normal C++ virtual delete below uses the real VMBuffer/derived destructor.
 * gap: field names and return constness are reconstructed. Registry validity,
 * cycle/fault domains and exception unwinding are not certified by this source.
 */
CCode::~CCode() {
    volatile CCode *state = this;
    CCode *volatile &registryHead = g_pFirstCode;
    uint32_t volatile &blockCount = g_TotalCodeBlocks;

    // 0xce2b8..0xce2e4: capture both fields before the skip branch.
    const uint8_t skip = state->skipRegistryRemoval;
    CCode *const head = registryHead;
    if (skip == 0) {
        if (head == this) {
            // 0xce354..0xce35c: remove the first node.
            registryHead = state->nextCode;
        } else if (head != nullptr) {
            // 0xce2fc..0xce310 / 0xce348..0xce350: walk predecessor links.
            // No cycle detector or early return on a missing node is added.
            CCode *previous = head;
            CCode *node = static_cast<volatile CCode *>(previous)->nextCode;
            while (node != nullptr) {
                if (node == this) {
                    static_cast<volatile CCode *>(previous)->nextCode = state->nextCode;
                    break;
                }
                previous = node;
                node = static_cast<volatile CCode *>(previous)->nextCode;
            }
        }
        // 0xce314..0xce324: even null-head and not-found paths decrement.
        const uint32_t oldCount = blockCount;
        blockCount = oldCount - 1u;
    }

    // 0xce328..0xce33c: skip affects registration only, not primary ownership.
    VMBuffer *const ownedBuffer = state->buffer;
    if (ownedBuffer != nullptr) {
        delete ownedBuffer; // actual virtual deleting destructor, not a stub
    }
    // 0xce340..0xce344: do not clear buffer, delete debugBuffer or free names.
}

// 0xcf470 ldr r0,[r0,#0x10]; bx lr. This is a non-const member function;
// const char* is a recovered type spelling, not proof of the original spelling.
const char *CCode::GetText() {
    return text;
}
