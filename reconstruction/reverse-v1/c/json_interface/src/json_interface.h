/*
 * json_interface.h — JSON tree accessor interface for the spine chain.
 */
#ifndef YY_JSON_INTERFACE_H
#define YY_JSON_INTERFACE_H

#include <stdint.h>
#include <stddef.h>

/*
 * Json: 32 B, layout pinned by the four accessors below.
 * Fields +0x08/+0x0c have no reader/writer in these functions;
 * their identity is unknown and left unnamed.
 */
struct Json {
    struct Json* next;           /* +0x00  sibling in linked list */
    struct Json* child;          /* +0x04  first child (for objects/arrays) */
    uint32_t     unk_08;         /* +0x08  no accessor in this batch */
    uint32_t     unk_0c;         /* +0x0c  no accessor in this batch */
    const char*  string_value;   /* +0x10  from Json_getString */
    int32_t      int_value;      /* +0x14  from Json_getInt */
    float        float_value;    /* +0x18  from Json_getFloat */
    const char*  name;           /* +0x1c  key, from Json_getItem */
};
typedef struct Json Json;

/* libc (bare-metal). */
extern int strcmp(const char* a, const char* b);
extern int strcasecmp(const char* a, const char* b);

/* Public API (matches dynsym). */
Json*        Json_getItem(Json* json, const char* name);
const char*  Json_getString(Json* json, const char* name, const char* default_value);
float        Json_getFloat(Json* json, const char* name, float default_value);
int          Json_getInt(Json* json, const char* name, int default_value);

/* Named boundary — not recovered in this module. */
Json*        Json_create(const char* str);

#endif /* YY_JSON_INTERFACE_H */
