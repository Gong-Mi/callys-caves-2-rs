/* Synthetic ARMv7 fixture. It links only our C and these explicit providers;
 * no original ELF, CODE file, Android runtime or original instruction runs. */
#include "vm_exec_release.h"

#define BYTES(p) ((uint8_t *)(p))
#define CODE(p) ((const uint8_t *)(p))

struct YYObjectBase { uint32_t opaque; };
volatile uint32_t g_execCount;
volatile uint32_t g_retCount;
volatile uint32_t g_ArgumentCount;
uint8_t *volatile Argument;
volatile uint8_t g_bProfile;
_Alignas(4) uint8_t g_profiler[128];
VMExec *volatile g_pCurrentExec;
volatile uint8_t g_fDoExceptionUnwind;
const volatile uint32_t g_paramSize[16] = {8, 4, 4, 8, 4, 4, 4, 4};
volatile uint32_t g_exceptionVar[4];
VMExec *volatile g_caughtExec;
uint8_t *volatile g_pExceptionSP;
volatile struct VMStackPages stackPages;

static void write_msg(const char *p)
{
    uint32_t n = 0;
    while (p[n])
        ++n;
    register unsigned r0 __asm__("r0") = 1;
    register const char *r1 __asm__("r1") = p;
    register uint32_t r2 __asm__("r2") = n;
    register unsigned r7 __asm__("r7") = 4;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "cc", "memory");
}

__attribute__((noreturn)) static void stop(unsigned status)
{
    register unsigned r0 __asm__("r0") = status;
    register unsigned r7 __asm__("r7") = 1;
    __asm__ volatile("svc #0" : : "r"(r0), "r"(r7) : "cc", "memory");
    __builtin_unreachable();
}

__attribute__((noreturn)) static void fail(const char *why)
{
    write_msg("FAIL ");
    write_msg(why);
    write_msg("\n");
    stop(1);
}

#define CHECK(test, label) do { if (!(test)) fail(label); } while (0)

static VMExec vm, other;
static struct YYObjectBase locals;
static uint32_t allocation, return_delete, result[4], values[16], thrown[16];
static const uint32_t ordinary_code[] = {0x12000000u, 0x4d330057u, 0xa0, 0xa1, 0xa2};
static const uint32_t target_code[] = {0x13, 0x14, 0x08000001u, 0x15};
static const uint32_t entry_map[] = {0, 2, 1, 0, 0};
static const uint32_t caller_map[] = {0, 0, 3, 1};
static const uint32_t reload_map[] = {0, 4, 2, 1};
static VMExecHandler slots_a[8], slots_b[8];
static VMBuffer caller, convert_target, reload_buffer;
static struct {
    struct VMCallFrame frame;
    uint32_t args[16];
} return_storage, profile_dummy;
static unsigned dispatch_count, return_calls, free_calls, free_locals_calls;
static unsigned profile_calls, delete_calls, rvalue_calls;
static unsigned check_provider_order, simulate_provider_reloads;
static unsigned rewrite_mode_on_free;
static void *freed;
static struct YYObjectBase *freed_locals;
static uint8_t *volatile seen_sp;

/* YYObjectBase::Free and MemoryManager::Free are observation-only models. */
void MemoryManager_Free(const void *p)
{
    if (p == &return_delete) {
        CHECK(return_calls == 1, "return-delete-after-convert");
        ++delete_calls;
        return;
    }
    CHECK(g_ArgumentCount == 29, "cleanup-restore-before-free");
    ++free_calls;
    freed = (void *)p;
    if (rewrite_mode_on_free)
        vm.locals_mode = 3;
}

void YYObjectBase_Free(struct YYObjectBase *p)
{
    ++free_locals_calls;
    freed_locals = p;
    vm.locals = p;
    if (simulate_provider_reloads) {
        CHECK(vm.buffer == &caller && vm.code == CODE(target_code), "return-locals-after-state-restore");
        vm.buffer = &convert_target;
    }
}

/* Remaining callees are intentionally synthetic. PerformReturn is now
 * provided by its own C translation unit, not by this fixture. */
void VMBuffer_convertBuffer(VMBuffer *buffer)
{
    CHECK(buffer == (simulate_provider_reloads ? &convert_target : &caller), "return-converter-boundary");
    CHECK(vm.locals_mode == return_storage.frame.caller_locals_mode, "return-convert-after-locals");
    ++return_calls;
    if (simulate_provider_reloads) {
        buffer->handlers = slots_a;
        vm.buffer = &reload_buffer;
        vm.byte_pc = 4;
    } else {
        buffer->handlers = slots_b;
        buffer->offset_to_slot = caller_map;
    }
}

uint32_t CProfiler_Pop(void *profiler)
{
    CHECK(profiler == g_profiler && g_retCount == 0, "return-profile-order");
    ++profile_calls;
    vm.frame_base = BYTES(&return_storage.frame);
    vm.frame_depth = 2;
    return 0;
}

void FREE_RValue__Pre(void *value)
{
    CHECK(delete_calls == 1, "return-rvalue-after-delete");
    if (check_provider_order) {
        CHECK(value == return_storage.args + 4, "return-rvalue-tag-filter");
        g_ArgumentCount = 3; /* affects returned SP, not traversal count */
    }
    ++rvalue_calls;
}

static uint8_t *unexpected(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    (void)word;
    (void)payload;
    (void)sp;
    (void)exec;
    fail("wrong-handler");
}

static void init(void)
{
    vm.stack_allocation = &allocation;
    vm.locals = NULL;
    vm.locals_mode = 0;
    vm.code = CODE(ordinary_code);
    vm.frame_base = BYTES(values + 16);
    vm.byte_pc = 0;
    vm.last_byte_pc = -100;
    vm.byte_limit = 4;
    vm.next_slot = 7;
    vm.frame_depth = 0;
    vm.offset_to_slot = entry_map;
    vm.handlers = slots_a;
    for (unsigned i = 0; i < 8; ++i) {
        slots_a[i] = unexpected;
        slots_b[i] = unexpected;
    }
    for (unsigned i = 0; i < 16; ++i) {
        values[i] = 0x500u + i;
        thrown[i] = 0x600u + i;
    }
    for (unsigned i = 0; i < 4; ++i) {
        result[i] = 0x700u + i;
        g_exceptionVar[i] = 0x800u + i;
    }
    g_pCurrentExec = &other;
    g_caughtExec = NULL;
    g_pExceptionSP = BYTES(thrown + 12);
    g_fDoExceptionUnwind = 0;
    g_ArgumentCount = 29;
    g_execCount = UINT32_MAX;
    g_retCount = UINT32_MAX;
    Argument = NULL;
    g_bProfile = 0;
    stackPages.page_head = NULL;
    stackPages.free_head = NULL;
    stackPages.count_0c = 0;
    stackPages.count_10 = 0;
    free_calls = free_locals_calls = return_calls = dispatch_count = 0;
    profile_calls = delete_calls = rvalue_calls = 0;
    check_provider_order = simulate_provider_reloads = 0;
    rewrite_mode_on_free = 0;
    freed = NULL;
    freed_locals = NULL;
    seen_sp = NULL;
}

static void entry_at_limit(void)
{
    init();
    vm.byte_pc = 4;
    vm.code = NULL; /* table prefetch at exhaustion, but never read instruction */
    VM_ExecRelease(&vm, result);
    CHECK(vm.next_slot == 3, "entry-remap-before-limit");
    CHECK(vm.last_byte_pc == -100 && result[0] == 0x700u, "entry-no-dispatch-or-copy");
    CHECK(g_execCount == 0 && g_pCurrentExec == &vm, "entry-global-store");
    CHECK(free_calls == 1 && freed == &allocation && return_calls == 0, "exit-fallback-free");
}

static uint8_t *second_dispatch(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    CHECK(exec == &vm && word == 0x08000001u && payload == CODE(target_code + 3), "dispatch-reload-code");
    CHECK(sp == BYTES(values + 12), "dispatch-sp-handoff");
    CHECK(vm.last_byte_pc == 8 && vm.byte_pc == 12 && vm.next_slot == 5, "dispatch-second-pc");
    ++dispatch_count;
    vm.byte_limit = 12;
    return BYTES(values + 8);
}

static uint8_t *first_dispatch(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    CHECK(exec == &vm && word == 0x4d330057u && payload == CODE(ordinary_code + 2), "dispatch-args");
    CHECK(sp == BYTES(values + 16) && vm.next_slot == 3, "dispatch-entry-sp-slot");
    CHECK(vm.last_byte_pc == 4 && vm.byte_pc == 16, "dispatch-param-width");
    ++dispatch_count;
    g_ArgumentCount = 53;
    vm.code = CODE(target_code);
    vm.handlers = slots_b;
    vm.next_slot = 4;
    vm.byte_pc = 8;
    return BYTES(values + 12);
}

static void dispatch_reloads(void)
{
    init();
    vm.byte_pc = 4;
    vm.byte_limit = 20;
    vm.locals = &locals;
    slots_a[2] = first_dispatch;
    slots_b[4] = second_dispatch;
    VM_ExecRelease(&vm, values + 9); /* out overlaps its source by three words */
    CHECK(dispatch_count == 2 && vm.next_slot == 6 && return_calls == 0, "dispatch-prefetch-on-exit");
    for (unsigned i = 0; i < 4; ++i)
        CHECK(values[9 + i] == 0x508u + i, "result-copy-overlap");
    CHECK(free_calls == 1 && g_ArgumentCount == 29, "result-argument-restore");
    CHECK(free_locals_calls == 1 && freed_locals == &locals && vm.locals == NULL, "cleanup-local-call-clear");
}

static uint8_t *throw_from_handler(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    (void)word;
    (void)sp;
    (void)payload;
    (void)exec;
    ++dispatch_count;
    g_fDoExceptionUnwind = 7;
    g_pCurrentExec = &other;
    return BYTES(values + 4);
}

static void catch_live_exec(void)
{
    init();
    slots_a[0] = throw_from_handler;
    g_caughtExec = &other; /* differs from &vm, equal to the live current global after handler */
    vm.frame_base = BYTES(thrown + 16);
    VM_ExecRelease(&vm, result);
    CHECK(dispatch_count == 1 && g_fDoExceptionUnwind == 0, "catch-live-exec");
    CHECK(g_pCurrentExec == &other, "catch-current-exec-unchanged");
    for (unsigned i = 0; i < 4; ++i)
        CHECK(result[i] == 0x800u + i && thrown[8 + i] == result[i], "catch-four-word-image");
    CHECK(thrown[7] == 0x607u && thrown[12] == 0x60cu, "catch-write-span");
}

static void uncaught_exits_before_pc_limit(void)
{
    init();
    slots_a[0] = throw_from_handler;
    g_caughtExec = &vm;
    vm.byte_limit = 20; /* below exit PC limit; abort current frame on mismatch */
    VM_ExecRelease(&vm, result);
    CHECK(dispatch_count == 1 && g_fDoExceptionUnwind == 7, "unwind-no-match-stays-set");
    CHECK(thrown[8] == 0x608u && result[0] == 0x504u, "unwind-retains-returned-sp");
    CHECK(vm.next_slot == 2 && vm.byte_pc == 4, "unwind-prefetch-before-exit");
}

static uint8_t *resumed(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    CHECK(exec == &vm && word == 0x08000001u && payload == CODE(target_code + 3), "frame-remapped-handler-abi");
    CHECK(vm.next_slot == 4 && vm.last_byte_pc == 8 && vm.byte_pc == 12, "frame-remapped-slot");
    seen_sp = sp;
    ++dispatch_count;
    return sp;
}

static void init_return(void)
{
    /* Exercise the original offset formula, but keep all final pointers
     * in live fixture objects. For this static ARM ELF allocation is low. */
    vm.frame_top = BYTES(return_storage.args + 12);
    return_storage.frame.caller_frame_distance = (int32_t)(uintptr_t)&allocation;
    CHECK(return_storage.frame.caller_frame_distance >= 0, "fixture-frame-distance");
    return_storage.frame.caller_pc = 8;
    return_storage.frame.caller_state_30 = 30;
    return_storage.frame.caller_state_34 = 34;
    return_storage.frame.caller_state_38 = 38;
    return_storage.frame.caller_state_3c = 0x3c;
    return_storage.frame.caller_argc = 29;
    return_storage.frame.caller_self = &locals;
    return_storage.frame.caller_other = NULL;
    return_storage.frame.caller_buffer = &caller;
    return_storage.frame.delete_on_return = &return_delete;
    return_storage.frame.caller_locals_mode = 7;
    return_storage.frame.caller_locals = NULL;
    return_storage.frame.caller_argument_offset = 0;
    caller.byte_limit = 12;
    caller.code = CODE(target_code);
    caller.handlers = slots_a;
    caller.offset_to_slot = entry_map;
    convert_target.handlers = slots_b;
    convert_target.offset_to_slot = caller_map;
    reload_buffer.offset_to_slot = reload_map;
    vm.frame_base = BYTES(&return_storage.frame);
    vm.frame_depth = 1;
    vm.locals_mode = 9;
    for (unsigned i = 0; i < 16; ++i)
        return_storage.args[i] = 0x900u + i;
    Argument = BYTES(return_storage.args);
}

static uint8_t *fall_off_inner_frame(uint32_t word, uint8_t *sp, const uint8_t *payload, VMExec *exec)
{
    CHECK(word == 0x12000000u && sp == BYTES(&return_storage.frame)
          && payload == CODE(ordinary_code + 1) && exec == &vm, "inner-frame-handler-abi");
    g_ArgumentCount = 2;
    return sp;
}

static void frame_return(void)
{
    init();
    init_return();
    return_storage.args[3] = 0;
    return_storage.args[7] = 0xab000004u;
    check_provider_order = 1;
    slots_a[0] = fall_off_inner_frame;
    slots_b[3] = resumed;
    VM_ExecRelease(&vm, result);
    CHECK(return_calls == 1 && dispatch_count == 1 && seen_sp == BYTES(return_storage.args + 8), "frame-return-does-not-exit");
    CHECK(vm.next_slot == 5 && vm.frame_depth == 0, "frame-return-sentinel-prefetch");
    CHECK(result[0] == 0 && result[1] == 0 && result[2] == 0x90au && result[3] == 0, "frame-three-zeros");
    CHECK(g_ArgumentCount == 29 && g_execCount == 0 && g_retCount == 0, "frame-save-only-on-function-entry");
}

static void perform_return_null(void)
{
    init();
    init_return();
    return_storage.frame.caller_buffer = NULL;
    g_bProfile = 2;
    vm.frame_base = BYTES(&profile_dummy.frame);
    uint8_t *sp = PerformReturn(BYTES(values), &vm);
    CHECK(sp == BYTES(return_storage.args), "return-null-frame-end");
    CHECK(profile_calls == 1 && vm.frame_depth == 1 && g_retCount == 0, "return-entry-profile-count");
    CHECK(!return_calls && !delete_calls && Argument == BYTES(return_storage.args) && g_ArgumentCount == 29, "return-null-skips-release");
}

static void perform_return_reloads(void)
{
    init();
    init_return();
    simulate_provider_reloads = 1;
    check_provider_order = 1;
    vm.locals = &locals;
    vm.locals_mode = 0;
    return_storage.frame.caller_frame_distance = -1;
    return_storage.args[3] = 0;           /* not a ref */
    return_storage.args[7] = 0xab000004u; /* lower 24-bit tag=4 */
    return_storage.args[11] = 3;          /* outside original two slots */
    g_ArgumentCount = 2;
    uint8_t *sp = PerformReturn(BYTES(values + 4), &vm);
    CHECK(sp == BYTES(return_storage.args + 12), "return-uses-live-argc-after-release");
    CHECK(vm.frame_base == NULL && vm.frame_depth == 0, "return-negative-distance");
    CHECK(vm.handlers == slots_a && vm.offset_to_slot == reload_map && vm.next_slot == 4, "return-split-table-reload");
    CHECK(vm.state_30 == 30 && vm.state_34 == 34 && vm.state_38 == 38 && vm.state_3c == 0x3c && vm.self == &locals, "return-state-snapshot");
    CHECK(free_locals_calls == 1 && delete_calls == 1 && rvalue_calls == 1, "return-cleanup-counts");
    CHECK(return_storage.args[0] == 0 && return_storage.args[1] == 0x901u && return_storage.args[2] == 0 && return_storage.args[3] == 5, "return-three-word-arg-clear");
    CHECK(return_storage.args[4] == 0 && return_storage.args[5] == 0x905u && return_storage.args[6] == 0 && return_storage.args[7] == 5, "return-ref-slot-clear");
    CHECK(return_storage.args[8] == 0x908u && return_storage.args[11] == 3 && g_ArgumentCount == 29 && Argument == BYTES(&allocation), "return-restores-argument-state");
}

static void perform_return_empty_args(void)
{
    init();
    init_return();
    vm.stack_allocation = values;
    return_storage.frame.caller_frame_distance = -1;
    return_storage.frame.caller_argument_offset = 8;
    g_ArgumentCount = 0;
    Argument = NULL;
    uint8_t *sp = PerformReturn(BYTES(thrown), &vm);
    CHECK(sp == BYTES(return_storage.args) && !rvalue_calls && delete_calls == 1, "return-empty-args");
    CHECK(g_ArgumentCount == 29 && Argument == BYTES(values + 2), "return-relative-argument-offset");
}

static struct {
    struct VMStackPage header;
    uint32_t unused_04;
    uint32_t payload[0x40001];
    struct VMStackPage unmatched;
} pool = { .unmatched = { &pool.header } };

static void pool_boundary_and_cleanup(void)
{
    init();
    vm.byte_limit = 0;
    vm.stack_allocation = pool.payload;
    vm.locals_mode = 0x100;
    vm.locals = &locals;
    stackPages.page_head = &pool.unmatched;
    stackPages.free_head = values;
    stackPages.count_0c = 0;
    stackPages.count_10 = UINT32_MAX;
    VM_ExecRelease(&vm, NULL);
    CHECK(free_calls == 0 && stackPages.free_head == pool.payload, "pool-inclusive-start-next-page");
    CHECK(pool.payload[0] == (uint32_t)(uintptr_t)values, "pool-intrusive-link");
    CHECK(stackPages.count_0c == UINT32_MAX && stackPages.count_10 == 0, "pool-count-wrap");
    CHECK(vm.locals == &locals && free_locals_calls == 0, "cleanup-retain-nonzero-mode");

    init();
    vm.byte_limit = 0;
    vm.stack_allocation = pool.payload + 0x40000;
    vm.locals = &locals;
    stackPages.page_head = &pool.header;
    rewrite_mode_on_free = 1;
    VM_ExecRelease(&vm, NULL);
    CHECK(free_calls == 1 && freed == pool.payload + 0x40000, "pool-exclusive-end");
    CHECK(free_locals_calls == 0 && vm.locals_mode == 3 && vm.locals == &locals, "cleanup-reload-mode-after-free");
}

__attribute__((noreturn)) void _start(void)
{
    entry_at_limit();
    dispatch_reloads();
    catch_live_exec();
    uncaught_exits_before_pc_limit();
    frame_return();
    perform_return_null();
    perform_return_reloads();
    perform_return_empty_args();
    pool_boundary_and_cleanup();
    write_msg("PASS exec-release: entry dispatch catch unwind return pool; perform-return: null reloads empty-args\n");
    stop(0);
}
