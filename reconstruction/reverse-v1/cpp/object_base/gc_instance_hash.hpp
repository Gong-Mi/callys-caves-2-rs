#ifndef CALLY_GC_INSTANCE_HASH_HPP
#define CALLY_GC_INSTANCE_HASH_HPP
#include <stddef.h>
#include <stdint.h>

/* tier: bytecode_anchored; original ARMv7 image SHA-256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Hash<CInstance> D1/D2 are WEAK same-address aliases @0x190d2c (148B), the
 * destructor the .init fragment registers through GOT slot 0x3f0698
 * (0xb9868 ldr r3,[pc,#180]; 0xb9874 ldr r1,[r5,r3]; 0xb9878 bl __aeabi_atexit
 * with r0 = 0x536f28, the object slot 0x3edc4c resolves to).
 * Layout producers, all in that one fragment:
 *   0xb9848 str ip,[r6,#4]  mask = 511        (index bound, 512 buckets)
 *   0xb9850 str r4,[r6,#8]  live = 0
 *   0xb9854 MemoryManager::Alloc(4096, ...) then 0xb9860 str r0,[r6] table
 *   0xb9864 memset(table, 0, 4096)            4096 / 512 = 8 = bucket stride
 * The owner record is the real 12B .bss CInstance::ms_ID2Instance @0x536f28
 * (dynsym 950 STT_OBJECT GLOBAL size 12 shndx 19), which is what fixes
 * sizeof(Hash<CInstance>) == 12.
 * gap: bucket+0x04, node+0x00/+0x08 and every node word past +0x0c, the node
 * record extent, the allocator size class, and the receiver's real type and
 * vtable are unobserved here. CInstance stays a declaration-only nominal type
 * so the body still mangles to _ZN4HashI9CInstanceED1Ev, and the value call is
 * expressed as the receiver's own vptr word plus 0x04 - never as a CInstance
 * vtable this line has not recovered. Nothing in this header invents an
 * allocator, an element model or a key/value spelling.
 */
class CInstance; /* declaration-only nominal type; no layout or vtable claim */

struct InstanceHashNode;

/* One table slot, stride fixed by 0x190d3c lslge r7,r8,#3 and 0x190da8 sub r7,#8. */
struct InstanceHashBucket {
    InstanceHashNode *head00;  // +0x00 chain head, read then cleared per bucket
    uint32_t unknown04;        // +0x04 cleared with the head, never read (0x190d58)
};

/* Chain node. Only +0x04 and +0x0c are read by 0x190d2c; both words the
 * original ignores stay raw here instead of being renamed into a guess. */
struct InstanceHashNode {
    uint32_t unknown00;          // +0x00 never read here
    InstanceHashNode *next04;    // +0x04 next node, read before the value call
    uint32_t unknown08;          // +0x08 never read here
    void *value0c;               // +0x0c receiver of the real vptr+0x04 call
};

template <typename T> class Hash;

template <> class Hash<CInstance> {
public:
    ~Hash() noexcept(false) __attribute__((weak));  // original WEAK D1/D2 @0x190d2c

    InstanceHashBucket *buckets;  // +0x00 LIVE re-read after each exhausted chain
    int32_t mask;                 // +0x04 last bucket index; signed, <0 skips the walk
    uint32_t liveCount;            // +0x08 live node count, one decrement per freed node
};

/* Declaration only, never defined here: the 12B .bss record the .init fragment
 * hands to __aeabi_atexit. Its own owner TU still owes the storage. */
alignas(Hash<CInstance>) extern unsigned char ms_ID2Instance[sizeof(Hash<CInstance>)]
    __asm__("_ZN9CInstance14ms_ID2InstanceE");

static_assert(sizeof(InstanceHashBucket) == 8 &&
              offsetof(InstanceHashBucket, head00) == 0 &&
              offsetof(InstanceHashBucket, unknown04) == 4, "hash bucket stride");
static_assert(offsetof(InstanceHashNode, next04) == 4 &&
              offsetof(InstanceHashNode, value0c) == 12, "hash node words");
static_assert(sizeof(Hash<CInstance>) == 12 && alignof(Hash<CInstance>) == 4 &&
              offsetof(Hash<CInstance>, buckets) == 0 &&
              offsetof(Hash<CInstance>, mask) == 4 &&
              offsetof(Hash<CInstance>, liveCount) == 8, "ms_ID2Instance record");
#endif
