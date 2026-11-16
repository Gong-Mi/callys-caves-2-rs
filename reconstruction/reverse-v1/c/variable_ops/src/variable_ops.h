/*
 * variable_ops.h — the three variable *instruction-side* functions of libyoyo
 * ARMv7 (pinned image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 *   Code_Variable_Find_Name  _Z23Code_Variable_Find_NamePKcii   @0x000d25fc
 *       0x000d25fc..0x000d2618, 0x1c = 28 B, 7 instructions, NO literal pool.
 *       No frame, no saved register, both exits are `b` tail jumps -> the
 *       return value is the callee's, verbatim.
 *
 *   DoConvIntToVariable      _Z19DoConvIntToVariablejPhPKhP6VMExec @0x000d773c
 *       0x000d773c..0x000d7760, 0x24 = 36 B, 9 instructions, NO literal pool.
 *       No frame, no call: a leaf that rewrites the value-stack top in place.
 *
 *   DoPopLocalVariable       _Z18DoPopLocalVariablejPhPKhP6VMExec @0x000e1f5c
 *       0x000e1f5c..0x000e2014, 0xb8 = 184 B, 46 instructions, NO literal pool.
 *       Six-register frame; five callees; two exits (one of them shared).
 *
 * Each translation carries one `@0xADDR <verbatim llvm-objdump text>` comment
 * per machine instruction; harness/var_ops_diff.py machine-checks that comment
 * set against the pinned bytes (census gate) and re-verifies itself by
 * mutating the comments and requiring a red verdict.
 *
 * Callee status, stated per function because it differs:
 *   F1  Variable_BuiltIn_Find_Name @0x1f3b38 and Variable_GetName_Scope
 *       @0xd2228 are both UNRECOVERED -> identical stubs on both arms.
 *   F2  no callee at all: everything it does is in its own 9 instructions.
 *   F3  PushContextStack @0xd3968, PopContextStack @0xd3a34,
 *       FREE_RValue__Pre @0xc0a7c, SET_RValue @0xd0b24 and
 *       YYObjectBase::InternalGetYYVar @0x196a70 are all UNRECOVERED -> five
 *       identical stubs on both arms.  SET_RValue in particular is the callee
 *       that actually performs the store, so this arm proves *which* address
 *       and which instance id are handed over — not the copy itself.
 *
 * Nothing here is device equivalence: both arms run staged memory, and every
 * callee is either stubbed or absent.
 *
 * One caveat on the word "unrecovered": a parallel workstream (c/variable_misc/)
 * has since added its own translation of Variable_GetName_Scope @0xd2228.  This
 * arm does NOT link it — deliberately.  That body is 684 B with its own tables,
 * snprintf and Script_Find_Parent, so linking it would fold another workstream's
 * in-flight claims into this one and make F1's verdict depend on them; the stub
 * keeps the claim confined to F1's own seven instructions.
 */
#ifndef VARIABLE_OPS_H
#define VARIABLE_OPS_H

#include <stdint.h>

/* ── the shared arena: one contiguous block, same offsets on both arms ─────
 * The harness parses these defines and refuses to run if they drift from its
 * own copy, so an address logged as "offset 0x1a4" means the same object on
 * the Unicorn arm and under qemu-arm.  Addresses themselves are never
 * compared — only offsets from AO_BASE. */
#define AO_NAME      0x000u   /* 48 B  the case's variable name            */
#define AO_RETSTR    0x040u   /* 64 B  two canned callee answers           */
#define AO_VSTACK    0x080u   /* 64 B  the pseudo value stack              */
#define AO_SP        0x0a0u   /*   the sp handed to F2/F3 as r1            */
#define AO_CODE      0x0c0u   /* 16 B  the code-stream operand word (r2/F3) */
#define AO_EXEC      0x100u   /* 64 B  VMExec blob: +0x10 = self           */
#define AO_SELF      0x140u   /* 64 B  self object: +0x4 table, +0x24 gate  */
#define AO_TABLE     0x180u   /* 128 B local RValue table, 8 slots x 16 B   */
#define AO_DYN       0x200u   /* 48 B  what InternalGetYYVar hands back    */
#define ARENA_SIZE   0x280u

/* The three evidence windows printed verbatim by both arms: the value stack
 * (where F2/F3 write), the local table (where F3 aims the store) and the
 * dynamic-variable block (where F3 falls back to). */
#define AO_W1        0x090u
#define AO_W1LEN     0x030u
#define AO_W2        0x180u
#define AO_W2LEN     0x020u
#define AO_W3        0x200u
#define AO_W3LEN     0x010u

/* ── field offsets these bodies read (nothing else is assumed) ──────────── */
#define EXEC_SELF      0x010u  /* 0xe1f68 ldr r5, [r3, #0x10]              */
#define YYB_VAR_TABLE  0x004u  /* 0xe1fdc ldr r3, [r5, #0x4]               */
#define YYB_CTX_GATE   0x024u  /* 0xe1f90 ldr r3, [r5, #0x24]              */

#define RV_SLOT_STRIDE 16      /* 0xe1ff4 add r0, r3, r1, lsl #4           */
#define RV_TAG         0x00cu  /* 0xe1fa0 ldr r3, [r4, #0xc]               */
#define VARID_SLOT_BASE 100000 /* 0xe1fe4 sub r6,r6,#99328 + 0xe1fec #672  */
#define VARID_BUILTIN_MAX 99999/* 0xd25fc movw #0x869f + 0xd2600 movt #0x1 */

/* 0xe1fe0 bic r6, r6, #-268435456 keeps only the low 28 bits of the operand */
#define CODE_VARID_MASK  0x0fffffffu
/* 0xe1f78 tst r6, #536870912: set means "one word only on the value stack" */
#define CODE_ONE_WORD    0x20000000u
/* 0xe1f74 movlt r7, #-2147483648: the "self" instance id */
#define INSTANCE_SELF    0x80000000u

/* ── F1: Code_Variable_Find_Name ─────────────────────────────────────────
 * Dispatch key is the THIRD parameter only.  id > 99999 (signed bgt) goes to
 * the scope lookup with all three arguments live; anything else collapses to
 * the built-in table with only the id (0xd260c mov r0, r2), which is why the
 * built-in namespace has no scope dimension. */
extern const char *Variable_BuiltIn_Find_Name(int id);                     /* 0x1f3b38 */
extern const char *Variable_GetName_Scope(const char *name, int type,
                                          int id);                          /* 0xd2228 */
const char *Code_Variable_Find_Name(const char *name, int type, int id);

/* ── F2: DoConvIntToVariable ─────────────────────────────────────────────
 * r1 is the value-stack top, not the CPU sp: the body reads the int32 at
 * [r1], widens it to a double and writes the 16-byte RValue at r1-12:
 *   +0  low  word of the double  (via vstr s14 — s14 IS d7's low half here,
 *                                  written by vcvt.f64.s32 d7, s15)
 *   +4  high word of the double  (str r3)
 *   +8  NOT written              (hole: no instruction stores there)
 *   +0xc tag word 0              (str r12, [r0], #-12 with r12 = 0)
 * Return value is r1-12 (the post-index writeback), so the value stack GROWS
 * by 12 bytes downward and the old top word is still at the new +12. */
unsigned char *DoConvIntToVariable(unsigned int arg, unsigned char *sp,
                                   const unsigned char *base, void *exec);

/* ── F3: DoPopLocalVariable ──────────────────────────────────────────────
 * Pop form of "local variable = value": consumes the optional 4-byte instance
 * id from the value stack, decodes the variable id out of the code-stream
 * operand, aims the store at self->[4] + idx*16 (or InternalGetYYVar when the
 * table is not materialised yet) and rewrites the consumed value slot into the
 * tag-5 result {+0=0, +8=0, +0xc=5}, returning slot+16. */
extern void  PushContextStack(void *self);                    /* 0xd3968 */
extern void  PopContextStack(void);                           /* 0xd3a34 */
extern void  FREE_RValue__Pre(void *rv);                      /* 0xc0a7c */
extern void  SET_RValue(void *dst, void *src, int instance);   /* 0xd0b24 */
extern void *InternalGetYYVar(void *self, int idx);            /* 0x196a70 */
unsigned char *DoPopLocalVariable(unsigned int arg, unsigned char *sp,
                                  const unsigned char *base, void *exec);

#endif /* VARIABLE_OPS_H */
