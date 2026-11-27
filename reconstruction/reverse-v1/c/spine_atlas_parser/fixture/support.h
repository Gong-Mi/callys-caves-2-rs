#ifndef YY_ATLAS_FIXTURE_SUPPORT_H
#define YY_ATLAS_FIXTURE_SUPPORT_H
#include <stddef.h>
#include <stdint.h>
#include "spine_atlas_create.h"
void fixture_init(void);
void fixture_check(int condition,const char *name);
void fixture_finish(void) __attribute__((noreturn));
void fixture_exit(int status) __attribute__((noreturn));
size_t fixture_live(void);
size_t fixture_live_at_line(uint32_t line);
extern unsigned fixture_texture_calls,fixture_texture_frees;
extern int fixture_width_at_texture,fixture_height_at_texture;
extern char fixture_last_path[256];
extern int fixture_bad;
extern void *malloc(size_t);
extern void free(void *);
extern void *memset(void *,int,size_t);
extern size_t strlen(const char *);
extern int strcmp(const char *,const char *);
extern char *strcpy(char *,const char *);
#endif
