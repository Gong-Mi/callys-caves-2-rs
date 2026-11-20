/* The four ordinary C++ allocation/deallocation operators only.
 * tier: bytecode_anchored; original libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchors: _Znwj 0x27c524/24B, _Znaj 0x27d14c/24B, _ZdlPv 0x27d1d0/4B,
 * _ZdaPv 0x27d1d4/4B. Each new wrapper passes the shared tag at 0x3571e8,
 * the original line (0x525=1317 and 0x52b=1323), and bool true to Alloc.
 * Both deletes unconditionally transfer to Free, even for a null argument.
 *
 * The static ARM32 build recipe disables exceptions for THIS TU only.
 * Otherwise Clang adds a noexcept wrapper frame and terminate path to
 * delete, which are absent from the original one-instruction tail edges.
 * Do not add a noexcept promise to the shared MemoryManager::Free API.
 * gap: general unwind/LR and failure/exception behavior in providers are
 * not certified; sized/nothrow/placement/aligned variants are out of scope.
 */
#include "memory_buckets.hpp"

#if defined(__cpp_exceptions) || defined(__EXCEPTIONS)
#error "The ordinary ARM32 allocator operators need the scoped -fno-exceptions recipe"
#endif

namespace {
constexpr char kMemoryManagerFileTag[] = "jni/../jni/yoyo/../../../Platform/MemoryManager.cpp";
} // namespace

void *operator new(size_t size) {   // 0x27c524
    return MemoryManager::Alloc(size, kMemoryManagerFileTag, 1317, true);
}

void *operator new[](size_t size) { // 0x27d14c
    return MemoryManager::Alloc(size, kMemoryManagerFileTag, 1323, true);
}

void operator delete(void *block) noexcept {   // 0x27d1d0
    MemoryManager::Free(block);
}

void operator delete[](void *block) noexcept { // 0x27d1d4
    MemoryManager::Free(block);
}
