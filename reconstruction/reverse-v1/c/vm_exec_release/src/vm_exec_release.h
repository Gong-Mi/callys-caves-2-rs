#ifndef CALLY_VM_EXEC_RELEASE_H
#define CALLY_VM_EXEC_RELEASE_H

#include <stddef.h>
#include <stdint.h>

/* The pinned original is little-endian ARMv7 with four-byte pointers. */
#if !defined(__arm__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "VM reconstruction requires a little-endian ARM32 target"
#endif
_Static_assert(sizeof(void *) == 4, "VM reconstruction requires AAPCS32 pointers");

struct YYObjectBase;
typedef struct VMExec VMExec;
typedef struct VMBuffer VMBuffer;
typedef uint8_t *(*VMExecHandler)(uint32_t word, uint8_t *sp,
                                  const uint8_t *payload, VMExec *exec);

/* Shared prefix used by ExecRelease and PerformReturn, not the full size. */
struct VMExec {
    uint8_t unused_00[0x08];
    void *stack_allocation;                           /* +0x08, e46cc */
    uint32_t locals_mode;                             /* +0x0c, e470c */
    struct YYObjectBase *locals;                      /* +0x10, e4718 */
    struct YYObjectBase *self;                        /* +0x14, e4388 */
    struct YYObjectBase *other;                       /* +0x18, e438c */
    uint8_t unused_1c[0x08];
    const uint8_t *code;                              /* +0x24, e45dc */
    uint8_t *frame_base;                              /* +0x28, e4560/e46bc */
    VMBuffer *buffer;                                 /* +0x2c, e4394 */
    uint32_t state_30, state_34, state_38, state_3c;
    uint8_t *frame_top;                               /* +0x40, e4360 */
    int32_t byte_pc;                                  /* +0x44, e4598/e4618 */
    uint32_t next_slot;                               /* +0x48, e45c8/e4628 */
    int32_t frame_depth;                              /* +0x4c, e46a0 */
    int32_t byte_limit;                               /* +0x50, e45a8/e4690 */
    int32_t last_byte_pc;                             /* +0x54, e45e4 */
    const volatile VMExecHandler *handlers;           /* +0x58, e45b0/e4630 */
    const volatile uint32_t *offset_to_slot;           /* +0x5c, e459c */
};

struct VMBuffer {
    uint8_t unused_00[4];
    int32_t byte_limit;                               /* +0x04, e4380 */
    uint8_t unused_08[8];
    const uint8_t *code;                              /* +0x10, e437c */
    const volatile VMExecHandler *handlers;           /* +0x14, e43d4 */
    const volatile uint32_t *offset_to_slot;           /* +0x18, e43d8 */
};

/* DoCallScript stores at e8614..e8684 place this record immediately before
 * the callee's argument slice; +0x34 is not consumed by PerformReturn. */
struct VMCallFrame {
    int32_t caller_pc;                                /* +0x00 */
    uint32_t caller_state_30;                         /* +0x04 */
    uint32_t caller_argc;                             /* +0x08 */
    int32_t caller_frame_distance;                    /* +0x0c */
    struct YYObjectBase *caller_self;                 /* +0x10 */
    struct YYObjectBase *caller_other;                /* +0x14 */
    VMBuffer *caller_buffer;                          /* +0x18 */
    uint32_t caller_state_38, caller_state_3c, caller_state_34;
    void *delete_on_return;                           /* +0x28 */
    uint32_t caller_locals_mode;                      /* +0x2c */
    struct YYObjectBase *caller_locals;               /* +0x30 */
    uint32_t unused_34;
    uint32_t caller_argument_offset;                  /* +0x38 */
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

/* Relocation-backed objects; the offline fixture supplies synthetic state. */
extern volatile uint32_t g_execCount;
extern volatile uint32_t g_retCount;
extern volatile uint32_t g_ArgumentCount;
extern uint8_t *volatile Argument;
extern volatile uint8_t g_bProfile;
extern uint8_t g_profiler[128];                       /* original inline g_Profiler */
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
void VMBuffer_convertBuffer(VMBuffer *buffer);         /* 0xec750 */
uint32_t CProfiler_Pop(void *profiler);               /* 0x2a08ac; return ignored here */
void FREE_RValue__Pre(void *value);                    /* 0xc0a7c */

/* Out is an optional aligned, 16-byte RValue image; no C return value is
 * consumed at the VM::Exec call site. */
void VM_ExecRelease(VMExec *exec, void *out);

#endif
