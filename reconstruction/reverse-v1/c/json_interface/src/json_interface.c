/*
 * json_interface.c — JSON tree accessor interface used by the spine chain.
 *
 * Original image:
 *   libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to the original instruction address.  The original was not
 * executed.
 *
 * Symbols:
 *   0x2873c4  Json_getItem     100 B  25 insns  (linked-list search)
 *   0x287428  Json_getString    28 B   7 insns  (getItem + read +0x10)
 *   0x287444  Json_getFloat     28 B   7 insns  (getItem + read +0x18)
 *   0x287460  Json_getInt       28 B   7 insns  (getItem + read +0x14)
 *
 * Json_create (0x287320, 164 B, 41 insns) is NOT recovered here — it is
 * the JSON parser entry and involves the actual parse state machine.
 *
 * Json layout (32 B, pinned by these accessors + Json_create's calloc(1,32)):
 *   +0x00  next sibling      (from getItem loop: `ldr r4, [r4]`)
 *   +0x04  first child       (from getItem entry: `ldr r4, [r0, #0x4]`)
 *   +0x08  unknown           (no reader/writer in these 4 functions)
 *   +0x0c  unknown           (no reader/writer in these 4 functions)
 *   +0x10  string value      (from getString: `ldr r0, [r0, #0x10]`)
 *   +0x14  int value         (from getInt: `ldr r0, [r0, #0x14]`)
 *   +0x18  float value       (from getFloat: `ldr r0, [r0, #0x18]`)
 *   +0x1c  name/key          (from getItem: `ldr r0, [r4, #0x1c]`)
 *
 * Named boundaries: strcmp@plt, Json_create (parser).
 */

#include "json_interface.h"

/*
 * Json_getItem — walks the child linked list starting at json->child,
 * comparing each item's name field (+0x1c) with the search name.
 * Case-sensitivity flag is derived from whether name is non-NULL.
 * Returns NULL if not found or if json->child is NULL.
 */
Json*
Json_getItem(Json* json, const char* name)
{
    /* 0x2873cc ldr r4, [r0, #0x4] — first child */
    Json* item = json->child;

    /* 0x2873d0 cmp r4, #0; 0x2873d4 beq return_null */
    if (item == NULL)
        return NULL;

    /* 0x2873d8 adds r6, r1, #0; 0x2873dc movne r6, #1 — case flag */
    int case_sensitive = (name != NULL) ? 1 : 0;

    /* 0x2873e0 loop head */
    while (item != NULL) {
        /* 0x2873f8 ldr r0, [r4, #0x1c] — item->name */
        const char* item_name = item->name;

        /* 0x2873fc cmp r0, #0; 0x287400 moveq r3, #0 */
        /* 0x287404 andne r3, r6, #1 */
        int compare = (item_name != NULL) ? case_sensitive : 0;

        /* 0x287408 cmp r3, #0; 0x28740c beq skip_compare */
        if (compare) {
            /* 0x287410 mov r1, r5; 0x287414 bl strcmp */
            if (strcmp(item_name, name) == 0) {
                /* 0x287420 implicit: return r4 (item) */
                return item;
            }
        }

        /* 0x2873ec ldr r4, [r4] — item = item->next */
        item = item->next;

        /* 0x2873f0 cmp r4, #0; 0x2873f4 beq return_null */
        if (item == NULL)
            return NULL;

        /* 0x2873e4 cmp r0, r5; 0x2873e8 beq return_null — identity check */
        if ((void*)item == (void*)json)
            return NULL;
    }

    return NULL;
}

/*
 * Json_getString — getItem(json, name) then read +0x10, or return default.
 */
const char*
Json_getString(Json* json, const char* name, const char* default_value)
{
    /* 0x28742c mov r4, r2 — save default */
    /* 0x287430 bl Json_getItem */
    Json* item = Json_getItem(json, name);

    /* 0x287434 cmp r0, #0 */
    if (item != NULL) {
        /* 0x287438 ldrne r0, [r0, #0x10] */
        return item->string_value;
    }

    /* 0x28743c moveq r0, r4 */
    return default_value;
}

/*
 * Json_getFloat — getItem(json, name) then read +0x18, or return default.
 */
float
Json_getFloat(Json* json, const char* name, float default_value)
{
    /* 0x287448 mov r4, r2 — save default */
    /* 0x28744c bl Json_getItem */
    Json* item = Json_getItem(json, name);

    /* 0x287450 cmp r0, #0 */
    if (item != NULL) {
        /* 0x287454 ldrne r0, [r0, #0x18] */
        return item->float_value;
    }

    /* 0x287458 moveq r0, r4 */
    return default_value;
}

/*
 * Json_getInt — getItem(json, name) then read +0x14, or return default.
 */
int
Json_getInt(Json* json, const char* name, int default_value)
{
    /* 0x287464 mov r4, r2 — save default */
    /* 0x287468 bl Json_getItem */
    Json* item = Json_getItem(json, name);

    /* 0x28746c cmp r0, #0 */
    if (item != NULL) {
        /* 0x287470 ldrne r0, [r0, #0x14] */
        return item->int_value;
    }

    /* 0x287474 moveq r0, r4 */
    return default_value;
}
