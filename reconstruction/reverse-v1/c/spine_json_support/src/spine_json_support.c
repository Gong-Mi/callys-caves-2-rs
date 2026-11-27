/*
 * spine_json_support.c — reconstructed Json_dispose and ReportSpineError.
 *
 * Original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * Evidence tier: bytecode_anchored.  The original was not executed.
 *
 *   0x2872c8 Json_dispose       88 B, no literal pool
 *   0xc4404  ReportSpineError   52 B, 44 B code + 8 B pool at 0xc4430/0xc4434
 *
 * Allocation/free are the real reconstructed entry points in spine_alloc
 * (0x285c10/0x285c80); this file only calls them.
 */

#include "spine_json_support.h"
#include "../../spine_alloc/src/spine_alloc.h"

/*
 * 0x2872c8 Json_dispose:
 *   if (json == NULL) return;
 *   do {
 *       child = json->child;          @0x2872d4 ldr r0,[r4,#4]
 *       next  = json->next;           @0x2872d8 ldr r5,[r4]
 *       if (child) Json_dispose(child); @0x2872dc..0x2872e4
 *       if (json->string_value) _free(json->string_value); @0x2872e8..0x2872f4
 *       if (json->name)         _free(json->name);         @0x2872f8..0x287304
 *       _free(json);                  @0x287308..0x287310
 *       json = next;                  @0x28730c
 *   } while (json != NULL);           @0x287314..0x287318
 *
 * The child and next words are read before the recursive call.  The string
 * and name words are re-read after that call (and each after the preceding
 * free), so a provider that mutates the current node is observed.
 */
void Json_dispose(Json *json)
{
    while (json != NULL) {
        Json *child = json->child;
        __asm__ __volatile__("" ::: "memory");
        Json *next = json->next;
        if (child != NULL) {
            Json_dispose(child);
        }
        const char *string_value = json->string_value;
        if (string_value != NULL) {
            _free((void *)string_value);
        }
        const char *name = json->name;
        if (name != NULL) {
            _free((void *)name);
        }
        _free(json);
        json = next;
    }
}

/*
 * 0xc4404 ReportSpineError:
 *   r2 = message (r0)
 *   r3 = GOT[0x3ed71c] = 0x3eb70c (&dbg_csol), R_ARM_RELATIVE
 *   r1 = 0xc4420 + 0x26c6dc = 0x330afc ("Spine Error:%s\n")
 *   r0 = [0x3eb70c] = 0x47a118 (dbg_csol -> _dbg_csol, this)
 *   r3 = [r0] = vptr (Itanium address point)
 *   r3 = [vptr + 0xc] = Output
 *   blx r3 with r0=this, r1=format, r2=message
 *
 * The platform/global constructor that installs _dbg_csol's vptr is not
 * recovered; it is a typed input boundary, not a lib-internal extern stub.
 */
struct SpineErrorConsole _dbg_csol;
struct SpineErrorConsole *dbg_csol = &_dbg_csol;

/* The original is push {r3,lr}; ... blx r3; pop {r3,pc}.  Keep a real call
 * frame and return site; a tail bx would hand the sink its caller's lr. */
__attribute__((disable_tail_calls))
void ReportSpineError(const char *message)
{
    struct SpineErrorConsole *console = dbg_csol;
    console->vptr->output(console, "Spine Error:%s\n", message);
}
