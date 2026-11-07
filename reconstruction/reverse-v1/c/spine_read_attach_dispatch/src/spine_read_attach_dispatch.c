/*
 * readSkeletonData skins slot/attachment dispatch level
 *   (0x28c6b4–0x28c7a0, ~40 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Slot level:
 *   slotIndex = spSkeletonData_findSlotIndex(data, slotMap->name [+0x1c])
 *   for each attachmentMap in slotMap->child [+0x4]:
 *     name = getString(attachmentMap, "name", attachmentMap->name [+0x1c])
 *     path = getString(attachmentMap, "path", name)  ← same string reused
 *     type = getString(attachmentMap, "type", "region")
 *
 * Type dispatch (5 types + error, NO point/clipping — version marker):
 *   strcmp(type, "region")      == 0 → 0x28cf2c
 *   strcmp(type, "mesh")        == 0 → 0x28cf24
 *   strcmp(type, "linkedmesh")  == 0 → 0x28cf34
 *   strcmp(type, "boundingbox") == 0 → 0x28cfa0
 *   strcmp(type, "path")        == 0 → fall-through 0x28c7a0
 *   else → error 0x28e7f4 ("Unknown attachment type: ")
 *
 * VERSION MARKER: no "point"/"clipping" attachment types. Stock spine-c
 * 3.8 has 7 types; this binary has 5. Combined with "bendPositive" (3.6/3.7
 * style) and transform constraints (3.8 feature), the GameMaker version is
 * an early-3.8 development snapshot or custom hybrid.
 */

#include "spine_read_attach_dispatch.h"

extern int _strcmp(const char* a, const char* b);

extern const char* Json_getString(Json* json, const char* key, const char* fallback);

/*
 * Classify one attachment map. Returns the type enum.
 * *out_name / *out_path / *out_type receive the parsed strings.
 * data_raw is unused at this level (reserved for the slot index in the
 * caller's loop; kept for signature stability).
 */
attach_type_e readSkeletonData_classifyAttachment(
    Json* attachmentMap, void* data_raw,
    const char** out_name, const char** out_path, const char** out_type) {
    (void)data_raw;

    const char* map_name;
    const char* name;
    const char* path;
    const char* type;

    /* 0x28c6e8: attachmentMap->name from +0x1c (the JSON key) */
    map_name = (const char*)*(void**)((char*)attachmentMap + 0x1c);

    /* 0x28c6fc: name = getString(map, "name", map_name) */
    name = Json_getString(attachmentMap, "name", map_name);

    /* 0x28c718: path = getString(map, "path", name) — same "path" string
     * literal reused for both the JSON key and the type strcmp below */
    path = Json_getString(attachmentMap, "path", name);

    /* 0x28c72c: type = getString(map, "type", "region") */
    type = Json_getString(attachmentMap, "type", "region");

    *out_name = name;
    *out_path = path;
    *out_type = type;

    /* Dispatch chain (0x28c738–0x28c79c) */
    if (_strcmp(type, "region") == 0) return ATTACH_REGION;
    if (_strcmp(type, "mesh") == 0) return ATTACH_MESH;
    if (_strcmp(type, "linkedmesh") == 0) return ATTACH_LINKEDMESH;
    if (_strcmp(type, "boundingbox") == 0) return ATTACH_BOUNDINGBOX;
    if (_strcmp(type, "path") == 0) return ATTACH_PATH;
    return ATTACH_UNKNOWN;  /* → error 0x28e7f4 */
}
