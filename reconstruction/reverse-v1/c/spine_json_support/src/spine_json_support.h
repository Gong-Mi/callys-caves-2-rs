/*
 * spine_json_support.h — reconstructed shared support for the spine JSON chain.
 *
 * Original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered here (ARM32, byte-anchored, original never executed):
 *   Json_dispose       0x2872c8  88 B
 *   ReportSpineError   0xc4404   52 B (44 B code + 8 B literal pool)
 *
 * Platform reporter input boundary (typed, not a permanent internal stub):
 *   dbg_csol    original 0x3eb70c, .data, 4-byte pointer word -> &_dbg_csol
 *   _dbg_csol   original 0x47a118, .bss,  4-byte object
 *
 * The original ReportSpineError loads, in order:
 *   GOT[0x3ed71c] = 0x3eb70c  (&dbg_csol, R_ARM_RELATIVE)
 *   [0x3eb70c]    = 0x47a118  (dbg_csol value / &_dbg_csol)
 *   [0x47a118]    = vptr      (Itanium address point)
 *   [vptr + 0xc]  = Output(this, format, message)
 *
 * The producer of _dbg_csol's vptr (the unrecovered platform/global
 * constructor) is an explicit gap.  A fixture installs a real vcall sink by
 * assigning dbg_csol; it must not replace ReportSpineError.
 */
#ifndef YY_SPINE_JSON_SUPPORT_H
#define YY_SPINE_JSON_SUPPORT_H

#include <stdint.h>
#include <stddef.h>

#include "../../json_interface/src/json_interface.h"

struct SpineErrorConsole;

/* Exact AAPCS32 callback shape of the original blx target:
 * r0 = this, r1 = format, r2 = message. */
typedef void (*SpineErrorOutputFn)(struct SpineErrorConsole *self,
                                   const char *format, ...); /* OutputEPKcz */

/*
 * The object's vptr is the Itanium C++ address point.  The original vtable
 * _ZTV12DummyConsole at 0x3eb6a0 is [offset-to-top, typeinfo, D1, D0,
 * Create, Output]; the object points at +8, so address-point +0xc is
 * DummyConsole::Output at 0xc4390.  Only that slot is consumed here.
 */
struct SpineErrorConsoleVTable {
    void (*destructor_complete)(struct SpineErrorConsole *self); /* +0x00 */
    void (*destructor_deleting)(struct SpineErrorConsole *self); /* +0x04 */
    void (*create)(struct SpineErrorConsole *self, const char *name,
                   int flag);                                   /* +0x08 */
    SpineErrorOutputFn output;                                  /* +0x0c */
};

struct SpineErrorConsole {
    const struct SpineErrorConsoleVTable *vptr; /* +0x00; 4 bytes on ARM32 */
};

/* Original storage, same names and widths.  _dbg_csol starts zeroed here:
 * its vptr producer is not recovered. A fixture must install a sink;
 * exact uninitialised-pointer fault equivalence is not certified. */
extern struct SpineErrorConsole _dbg_csol;
extern struct SpineErrorConsole *dbg_csol;

__attribute__((noinline, disable_tail_calls))
void ReportSpineError(const char *message);
void Json_dispose(Json *json);

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(struct SpineErrorConsole) == 4,
               "original _dbg_csol object is one pointer word");
_Static_assert(offsetof(struct SpineErrorConsoleVTable, output) == 0x0c,
               "original vcall loads vptr+0xc");
#endif

#endif /* YY_SPINE_JSON_SUPPORT_H */
