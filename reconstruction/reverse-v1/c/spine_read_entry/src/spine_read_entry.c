/*
 * readSkeletonData entry segment (0x28b84c–0x28b9cc, ~55 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 * SHA256: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Locale guard pattern: JSON decimal points require '.' separator.
 * The original saves LC_NUMERIC (bionic category 1), forces "C" for
 * Json_create, then restores. Verified strings:
 *   0x3390a8 = "C"
 *   0x357b5c = "skeleton"
 *
 * Instruction trace:
 *   28b84c push {r4-r11, lr}; vpush {d8}
 *   28b854 mov r8, r0        (json)
 *   28b858 sub sp, sp, #124
 *   28b85c ldr r0, [r0,#0x8] (json->error)
 *   28b860 mov r5, r1        (path)
 *   28b864 bl free           — free(json->error)
 *   28b868 mov r3, #0
 *   28b870 mov r1, r3        (NULL)
 *   28b874 str r3, [r8,#0x8] json->error = NULL
 *   28b878 str r3, [r8,#0x10] json->unk_10 = NULL
 *   28b87c bl setlocale      — setlocale(LC_NUMERIC=1, NULL) → r0
 *   28b880 subs r4, r0, #0
 *   28b884 beq 0x28bf58      — if NULL skip guard
 *   28b888 bl strdup         — copy = strdup(saved)
 *   28b88c ldr r1, [pc,#0xf50] → "C"
 *   28b894 mov r4, r0        (copy)
 *   28b898 mov r0, #1
 *   28b89c bl setlocale      — setlocale(LC_NUMERIC, "C")
 *   28b8a0 mov r0, r5
 *   28b8a4 bl Json_create    — tree = Json_create(path)
 *   28b8a8 str r0, [sp,#0x24] (tree slot)
 *   28b8b0 mov r0, #1
 *   28b8b4 bl setlocale      — setlocale(LC_NUMERIC, copy) — restore
 *   28b8b8 cmp r4, #0
 *   28b8bc beq 0x28b8c8
 *   28b8c0 mov r0, r4
 *   28b8c4 bl free           — free(copy)
 *   28b8c8 ldr r0, [sp,#0x24] (tree)
 *   28b8cc cmp r0, #0
 *   28b8d0 beq 0x28c3b4      — if (!tree) → error
 *   28b8d4 bl spSkeletonData_create — data
 *   28b8d8 ldr r1, [pc,#0xf08] → "skeleton"
 *   28b8e0 mov r9, r0        (data)
 *   28b8e4 ldr r0, [sp,#0x24] (tree)
 *   28b8e8 bl Json_getItem   — root = Json_getItem(tree, "skeleton")
 *   28b8ec subs r4, r0, #0
 *   28b8f0 beq 0x28b9cc      — if (!root) skip metadata
 *   ... skeleton metadata parsing follows ...
 */

#include "spine_read_entry.h"

/* setlocale categories (bionic): LC_CTYPE=0, LC_NUMERIC=1 */
#define LC_NUMERIC_BIONIC 1

/* External: bare-metal extern (no libc headers — hosted by harness) */
extern char* _setlocale(int category, const char* locale);
extern char* _strdup(const char* s);
extern void _free(void* p);

/* External: recovered spine chain */
extern Json* Json_create(const char* path);
extern Json* Json_getItem(Json* json, const char* key);
extern spSkeletonData* spSkeletonData_create(void);
extern void spSkeletonJson_setError(spSkeletonJson* json, const char* fmt,
                                     const char* a, const char* b, int c);

/*
 * Entry segment of spSkeletonJson_readSkeletonData.
 * Returns the skeleton-data root Json item, or NULL if the "skeleton"
 * key is absent. Sets *out_data to the freshly allocated spSkeletonData.
 * Caller must check json->error after a NULL tree.
 *
 * This function covers 0x28b84c–0x28b8f0 (guard + create + first lookup).
 * The full readSkeletonData continues into metadata parsing (not here).
 */
Json* readSkeletonData_entry(spSkeletonJson* json, const char* path,
                             spSkeletonData** out_data)
{
    Json* tree;
    Json* root;
    spSkeletonData* data;
    char* saved = 0;
    char* copy = 0;

    /* 28b85c–28b864: free previous error, clear slots */
    _free((void*)json->error);
    json->error = 0;
    json->unk_10 = 0;

    /* 28b87c: saved = setlocale(LC_NUMERIC, NULL) */
    saved = _setlocale(LC_NUMERIC_BIONIC, (const char*)0);

    if (saved != 0) {
        /* 28b888: copy = strdup(saved) */
        copy = _strdup(saved);
        /* 28b89c: setlocale(LC_NUMERIC, "C") */
        _setlocale(LC_NUMERIC_BIONIC, "C");
    }

    /* 28b8a4: tree = Json_create(path) */
    tree = Json_create(path);

    if (copy != 0) {
        /* 28b8b4: restore, then free the copy */
        _setlocale(LC_NUMERIC_BIONIC, copy);
        _free((void*)copy);
    }

    /* 28b8cc: if (!tree) → error path (caller checks json->error) */
    if (tree == 0) {
        *out_data = 0;
        return 0;
    }

    /* 28b8d4: data = spSkeletonData_create() */
    data = spSkeletonData_create();
    *out_data = data;

    /* 28b8e8: root = Json_getItem(tree, "skeleton") */
    root = Json_getItem(tree, "skeleton");

    /* 28b8ec–28b8f0: if (!root) → metadata skipped by caller */
    return root;
}
