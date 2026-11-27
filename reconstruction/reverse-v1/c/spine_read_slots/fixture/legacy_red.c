/* Pins the ORIGINAL legacy slot-reader behaviors, straight from the
 * disassembly of readSkeletonData's slots segment (libyoyo_armv7.so
 * 0x28bbcc-0x28bdd8, SHA 3bbedd09...):
 *   F1 blend mapping — first strcmp is "additive" (spilled 0x28bc40→[sp,#0x20])
 *      and a match stores 1 (0x28bd1c/20 moveq r3,#1; streq r3,[r5,#0x20]);
 *      "multiply"→2 (0x28bd3c/40), "screen"→3 (0x28bd5c/60). Stores are
 *      CONDITIONAL: an unrecognized blend string writes NOTHING.
 *   F4 creator result is never tested — after bl spSlotData_create (0x28bc78)
 *      the code goes straight to the color lookup; the publish at 0x28bd68
 *      (str r5,[r3,r6,lsl#2]) stores the NULL just like any slot.
 * These cases were RED against the pre-2026-11-08 reader (mapping reversed
 * additive→3/multiply→1/screen→2 plus an unconditional default-0 store, and an
 * early return on creator NULL); they must stay green now that the reader
 * follows the binary. Creator here is still a declared SYNTHETIC boundary
 * (no SlotData creator body in the base tree) — not acceptance of a recovered
 * creator or of original allocation-failure behavior. Original not executed. */
#define _start old_mesh_entry_unused
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#include "spine_read_slots.h"
struct ProbeSlot { int32_t index;const char *name;void *bone;char *attachment;float r,g,b,a;int32_t blend; };
static struct ProbeSlot probe;
void *spSlotData_create(int i,const char *n,void *b) {
#if RED_CASE==2
    (void)i;(void)n;(void)b;return 0;
#else
    memset(&probe,0,sizeof(probe));probe.index=i;probe.name=n;probe.bone=b;probe.r=probe.g=probe.b=probe.a=1;return &probe;
#endif
}
void spSlotData_setAttachmentName(void *s,const char *n) {(void)s;(void)n;fail("unexpected attachment provider");}
int _strcmp(const char *a,const char *b) {
#if RED_CASE==3
    probe.blend=77;
#endif
    return strcmp(a,b);
}
void _start(void) {
    test="legacy_slots_red";(void)&probe;init_heap();begin(test);Json *m=node(0);add(m,string("name","N"));
    spSkeletonData d={0};void *table[1]={(void *)(uintptr_t)0x1234};d.words[7]=(uint32_t)(uintptr_t)table;
#if RED_CASE==1
    add(m,string("blend","additive"));readSkeletonData_oneSlot(m,&d,(void *)(uintptr_t)0x3456,0);
    CK(probe.blend==1,"F1 additive is1, not3");
#elif RED_CASE==2
    void *s=readSkeletonData_oneSlot(m,&d,(void *)(uintptr_t)0x3456,0);
    CK(!s&&table[0]==0,"F4 forced NULL return still publishes slot and consumes remaining fields");
#elif RED_CASE==3
    add(m,string("blend","custom"));readSkeletonData_oneSlot(m,&d,(void *)(uintptr_t)0x3456,0);
    CK(probe.blend==77,"F1 unrecognized blend does not overwrite comparator-updated value");
#elif RED_CASE==4
    add(m,string("blend","multiply"));readSkeletonData_oneSlot(m,&d,(void *)(uintptr_t)0x3456,0);
    CK(probe.blend==2,"F1 multiply is2, not1");
#elif RED_CASE==5
    add(m,string("blend","screen"));readSkeletonData_oneSlot(m,&d,(void *)(uintptr_t)0x3456,0);
    CK(probe.blend==3,"F1 screen is3, not2");
#else
#error RED_CASE must be 1..5
#endif
    pass("legacy_bug_probe");quit(0);
}
