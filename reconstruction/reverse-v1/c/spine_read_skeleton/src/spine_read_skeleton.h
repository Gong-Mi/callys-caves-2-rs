/*
 * spine_read_skeleton.h — the assembled top-level chain of
 * spSkeletonJson_readSkeletonData @0x28b84c (13044 B) in libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * This module owns NO new original bytes: it is the assembly layer that the
 * fourteen recovered segment/glue modules were built for.  It reproduces the
 * single-chain control flow of the original function
 *
 *   entry 0x28b84c..0x28b8f0   locale guard + Json_create + data + "skeleton"
 *   meta  0x28b8f4..0x28ba40   skeleton fields + bones array
 *   bones 0x28ba40..0x28bbcc   bone loop
 *   slots 0x28bbcc..0x28bdd8   slots segment (owns its own error tail)
 *   ik    0x28bdd8..0x28bff8   ik constraints
 *   xform 0x28bff8..0x28c274   transform constraints
 *   path  0x28c274..0x28c5ec   path constraints
 *   skins 0x28c5ec..0x28ccb8   skins -> slots -> attachments (glue dispatch)
 *   link  0x28ccb8..0x28d19c   linkedmesh postpass
 *   anim  0x28d19c..0x28e7a0   events + animations (B1/B2 + per-animation loop)
 *   B18   0x28e7a4..0x28e7b0   Json_dispose(root); return data
 *   tail  0x28bdcc..0x28bdd4   the single shared epilogue
 *
 * WHAT THE ASSEMBLY LAYER CLOSES HERE
 * -----------------------------------
 * 1. The six semantic gaps of census §5.2 (blocks that live inside another
 *    module's declared window but whose module returns a code instead of
 *    emitting them):
 *      0x28bf00..0x28bf28  ik        "IK bone not found: "
 *      0x28bf28..0x28bf58  bones     "Parent bone not found: "
 *      0x28bf58..0x28bf84  entry     the setlocale(LC_NUMERIC,NULL) fallback
 *      0x28c104..0x28c130  transform "Transform bone not found: "
 *      0x28c384..0x28c3b4  path      "Path bone not found: "
 *      0x28c3b4..0x28c3d8  entry     "Invalid skeleton JSON: "
 *    Every dispose-bearing tail keeps the original order
 *    dispose(data) -> setError(self, root, text, arg) -> return NULL.
 * 2. One gap that lies OUTSIDE the census window (0x28b84c..0x28d19c) and is
 *    therefore in none of §5.1's eight blocks:
 *      0x28e7f4..0x28e81c  "Unknown attachment type: " (the dispatch's
 *                          fall-through at 0x28c79c bne 0x28e7f4).  The
 *                          animations segment map already assigns these
 *                          out-of-line attachment tails to the attachment
 *                          window; no module claims it.
 * 3. The chain-level state that must be written exactly once (census §5.3):
 *    the shared epilogue 0x28bdcc..0x28bdd4 is the C `return` of one function,
 *    the 0x28bdd8 json restore and the 0x28ccb4 data restore are C locals, and
 *    the skins loop constants stay in c/spine_read_skins +
 *    c/spine_read_attach_dispatch (this file never re-loads them).
 *
 * THE ONE ABI SEAM
 * ----------------
 * The original keeps the parsed tree in the frame word [sp,#0x24]: written
 * twice (0x28b8ac normal, 0x28bf74 fallback), read by all eight top-level
 * Json_getItem calls and by every error tail.  c/spine_read_entry's C
 * signature returns the "skeleton" *child* and hands back the data record; it
 * has no out-parameter for the tree, and the tree cannot be re-derived from
 * its return value (Json has no parent link).  This header therefore exposes
 * the single word `readSkeletonData_rootSlot`: the Json_create provider (a
 * named, unrecovered boundary in this batch) publishes the tree it returned
 * there, exactly as 0x28b8ac / 0x28bf74 store r0.  A real Json_create would
 * have to store it too; that is the documented, open-ended part of this
 * batch's boundary, not an equivalence claim.
 *
 * COMPOSITION-LEVEL NEGATIVE CONTROLS
 * -----------------------------------
 * Per-module receipts that each PASS do not prove the linked chain, so
 * tools/check_skeleton.py injects three classes of defect on top of the
 * "omit a module source -> undefined symbol" link guards:
 *   1. segment order  — two stages exchanged at this layer (ik <-> transform,
 *      and the linkedmesh postpass moved before the skins window).  Both
 *      stages would still succeed alone, so the refusals come from observable
 *      ORDER evidence: each stage's own array allocation line and the
 *      synthetic creator call sequence ('B','S','I','X','P'), reported as
 *      "stage order: X must precede Y".
 *   2. handoff mismatch — a wrong inter-stage argument (slot index off by one,
 *      name/path exchanged on the createAttachment call), refused by a named
 *      value assertion.
 *   3. broken single segment — one semantic constant changed INSIDE a segment
 *      module (bones scaleX slot, slots blend word, ik bend offset).  Every
 *      per-segment assertion in chain_segment_attribution names its module, so
 *      the failure line says which segment broke.
 * A green run is composition-level evidence about the reconstructed C only:
 * equivalence with the original is NOT measured (axis 4 = not_measured), and
 * the original bytes were never executed.
 *
 * Evidence tier: bytecode_anchored for the chain, test_anchored for the
 * linked run.
 */
#ifndef YY_SPINE_READ_SKELETON_H
#define YY_SPINE_READ_SKELETON_H

#include "json_interface.h"
#include "../../spine_json_layout.h"
#include "spine_skeleton_data.h"

/* The [sp,#0x24] root slot (see the seam note above).  Written by the
 * Json_create provider at the moment the tree is created; read by the
 * assembly for every segment call.  The original never clears it. */
extern Json* readSkeletonData_rootSlot;

/*
 * spSkeletonJson_readSkeletonData — public .dynsym entry 0x28b84c, size 13044.
 * Returns the new spSkeletonData on success (root already disposed) or NULL on
 * any segment error (data disposed by the owning tail, root disposed by
 * setError unless the failing tail passed root = 0 — the linkedmesh "Skin not
 * found" / "Parent mesh not found" leak, kept as the original has it).
 *
 * c/spine_json_error's spSkeletonJson_readSkeletonDataFile (0x28eb40) calls
 * this symbol.
 */
spSkeletonData* spSkeletonJson_readSkeletonData(spSkeletonJson* self,
                                                const char* data);

#endif /* YY_SPINE_READ_SKELETON_H */
