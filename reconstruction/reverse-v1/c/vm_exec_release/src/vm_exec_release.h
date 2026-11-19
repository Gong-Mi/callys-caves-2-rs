#ifndef CALLY_VM_EXEC_RELEASE_H
#define CALLY_VM_EXEC_RELEASE_H

#include <stddef.h>
#include <stdint.h>

/* The pinned original is little-endian ARMv7 with four-byte pointers. */
#if !defined(__arm__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "ExecRelease requires a little-endian ARM32 target"
#endif
_Static_assert(sizeof(void *) == 4, "ExecRelease requires AAPCS32 pointers");

struct YYObjectBase;
typedef struct VMExec VMExec;
typedef uint8_t *(*VMExecHandler)(uint32_t word, uint8_t *sp,
                                  const uint8_t *payload, VMExec *exec);

/* Prefix used by ExecRelease, not a declaration of the full object size. */
struct VMExec {
    uint8_t unused_00[0x08];
    void *stack_allocation;                           /* +0x08, e46cc */
    uint32_t locals_mode;                             /* +0x0c, e470c */
    struct YYObjectBase *locals;                      /* +0x10, e4718 */
    uint8_t unused_14[0x10];
    const uint8_t *code;                              /* +0x24, e45dc */
    uint8_t *frame_base;                              /* +0x28, e4560/e46bc */
    uint8_t unused_2c[0x18];
    int32_t byte_pc;                                  /* +0x44, e4598/e4618 */
    uint32_t next_slot;                               /* +0x48, e45c8/e4628 */
    int32_t frame_depth;                              /* +0x4c, e46a0 */
    int32_t byte_limit;                               /* +0x50, e45a8/e4690 */
    int32_t last_byte_pc;                             /* +0x54, e45e4 */
    const volatile VMExecHandler *handlers;           /* +0x58, e45b0/e4630 */
    const volatile uint32_t *offset_to_slot;           /* +0x5c, e459c */
};

struct VMStackPage {
    const struct VMStackPage *next;                  /* e46fc */
};

struct VMStackPages {
    uint32_t unused_00;
    const struct VMStackPage *page_head;              /* +0x04, e46d4 */
    void *free_head;                                  /* +0x08, e4754/e476c */
    uint32_t count_0c;                                /* +0x0c, e475c/e4774 */
    uint32_t count_10;                                /* +0x10, e4758/e4770 */
};

/* Relocation-backed objects. The rebuilt linker must supply them;
 * the offline fixture supplies only synthetic state. */
extern volatile uint32_t g_execCount;
extern volatile uint32_t g_ArgumentCount;
extern VMExec *volatile g_pCurrentExec;
extern volatile uint8_t g_fDoExceptionUnwind;
extern const volatile uint32_t g_paramSize[16];
extern volatile uint32_t g_exceptionVar[4];
extern VMExec *volatile g_caughtExec;
extern uint8_t *volatile g_pExceptionSP;
extern volatile struct VMStackPages stackPages;

/* Internal original callees (not libc imports). No default stubs. */
uint8_t *PerformReturn(uint8_t *sp, VMExec *exec);     /* 0xe42d8 */
void MemoryManager_Free(const void *ptr);             /* 0x27c2d0 */
void YYObjectBase_Free(struct YYObjectBase *locals);   /* 0x198f88 */

/* Out is an optional aligned, 16-byte RValue image; no C return value is
 * consumed at the VM::Exec call site. */
void VM_ExecRelease(VMExec *exec, void *out);

#endif
