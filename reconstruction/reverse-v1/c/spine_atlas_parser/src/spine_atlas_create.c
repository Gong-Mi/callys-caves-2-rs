/*
 * spine_atlas_create.c - static ARM32 translation of libyoyo's atlas loader.
 *
 * Original image sha256:
 *   3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Scope:
 *   spAtlas_create        0x284174  1824 B
 *   spAtlasPage_create    0x284058    96 B
 *   spAtlasRegion_create  0x2840d8    28 B
 *   and the six file-local helpers they call:
 *     trim       0x283d14  212 B
 *     readLine   0x283de8  148 B
 *     readValue  0x283e7c   84 B
 *     readTuple  0x283ed0  248 B
 *     mallocString 0x283fc8 72 B
 *     indexOf    0x284010   72 B
 *
 * Not implemented here (named boundaries, see header):
 *   spAtlas_dispose 0x284120 (already recovered in the main tree)
 *   _spAtlasPage_createTexture 0xbd6e4 (304 B, graphics side)
 *   _malloc/_calloc/_free 0x285c10/0x285c4c/0x285c80 (spine_alloc module)
 *
 * This is a translation, not a re-implementation from an upstream release.
 * Parent repair follows the actual ARM NZCV producer through MOV/LDRB/ADD
 * to BNE. The last valid byte IS compared. A miss reads *end, and the empty
 * readTuple EOF case performs a NULL load. Never replace these with a safety
 * guard. Imported ctype table contents remain an external contract.
 * No upstream version is assumed. See SEMANTICS.md for the rejected worker
 * account and the exact condition-code anchors.
 */
#include <stddef.h>
#include <stdint.h>

#include "spine_alloc.h"

#include "spine_atlas_create.h"

/* libc boundaries, exactly the PLT entries the original calls:
 *   0xb6538 strlen, 0xb65a4 strcpy, 0xb65bc memcpy,
 *   0xb65e0 strncmp, 0xb6670 strtol
 * and the bionic ctype table imported through GOT 0x3ed988 (R_ARM_GLOB_DAT
 * `_ctype_`).  `_ctype_` itself is a pointer variable (0x283d20 `ldr r1,[r3]`
 * loads its value); the table is indexed as table[(unsigned char)c + 1]. */
extern size_t strlen(const char*);
extern char* strcpy(char*, const char*);
extern void* memcpy(void*, const void*, size_t);
extern int strncmp(const char*, const char*, size_t);
extern long strtol(const char*, char**, int);
extern const char* _ctype_;

#if defined(__GNUC__) || defined(__clang__)
/* The original keeps these six helpers out of line (real bl sites from
 * 0x284254/0x2842b4/0x2842f0/0x2843e8/0x2846f0/...). */
#define YY_ATLAS_NOINLINE __attribute__((noinline))
#else
#define YY_ATLAS_NOINLINE
#endif

/* ARM32 add/sub values, not undefined signed-overflow or host pointer math. */
static int32_t yy_native_add_i32(int32_t a, int32_t b)
{ return (int32_t)((uint32_t)a + (uint32_t)b); }
static const char *yy_native_addr_add(const char *p, uint32_t n)
{ return (const char *)(uintptr_t)((uint32_t)(uintptr_t)p + n); }

/* Original numerical operations, not a nearest-only software approximation.
 * Base AAPCS32 still uses r0/r1. Explicit VFP primitives preserve FPSCR rounding,
 * cumulative flags and trap points; no production FPSCR normalization occurs. */
static float yy_native_i32_f32(int32_t input)
{
    union {float f;uint32_t u;} value;
    __asm__ volatile(".fpu vfpv3-d16\nvmov s0, %1\nvcvt.f32.s32 s0, s0\nvmov %0, s0"
                     : "=r"(value.u) : "r"(input) : "s0","memory");
    return value.f;
}
static float yy_native_div_f32(float numerator,float denominator)
{
    union {float f;uint32_t u;} a,b,result;a.f=numerator;b.f=denominator;
    __asm__ volatile(".fpu vfpv3-d16\nvmov s0, %1\nvmov s1, %2\nvdiv.f32 s0, s0, s1\nvmov %0, s0"
                     : "=r"(result.u) : "r"(a.u),"r"(b.u) : "s0","s1","memory");
    return result.f;
}

typedef struct yy_atlas_str {
    const char *begin;
    char *end; /* &end is passed directly to strtol(char **). */
} yy_atlas_str;

/* Target load/store primitives, not whole-function assembly. In particular,
 * preserve the original NULL/one-past reads without C pointer-dereference UB. */
static inline uint32_t yy_atlas_load8(uint32_t address)
{
    uint32_t value;
    __asm__ volatile ("ldrb %0, [%1]" : "=r"(value) : "r"(address) : "memory");
    return value;
}
static inline void yy_atlas_store8(uint32_t address,uint32_t value)
{ __asm__ volatile ("strb %1, [%0]" : : "r"(address),"r"(value) : "memory"); }
static inline uint32_t yy_atlas_addr(const void *p)
{ return (uint32_t)(uintptr_t)p; }
static inline const char *yy_atlas_ptr(uint32_t a)
{ return (const char *)(uintptr_t)a; }
/* Read actual word representations even when malformed input consumes an
 * untouched tuple slot. Do not turn native indeterminate stack reads into LLVM
 * uninitialized-pointer poison, and do not silently initialize those slots. */
static inline uint32_t yy_atlas_load32(uint32_t address)
{
    uint32_t value;
    __asm__ volatile("ldr %0, [%1]" : "=r"(value) : "r"(address) : "memory");
    return value;
}
static inline const char *yy_atlas_begin(const yy_atlas_str *str)
{ return yy_atlas_ptr(yy_atlas_load32(yy_atlas_addr(str))); }
static inline char *yy_atlas_end(const yy_atlas_str *str)
{ return (char *)(uintptr_t)yy_atlas_load32(yy_atlas_addr(str)+4u); }
static inline int yy_atlas_space(uint32_t table,uint32_t byte)
{ return (yy_atlas_load8(table+byte+1u)&8u)!=0; }

/* trim@0x283d14: cache table once; initial byte load precedes end-slot load. */
static YY_ATLAS_NOINLINE void yy_atlas_trim(yy_atlas_str *str)
{
    uint32_t begin=yy_atlas_addr(yy_atlas_begin(str));
    uint32_t table=yy_atlas_addr(_ctype_);
    uint32_t byte=yy_atlas_load8(begin);             /* 0x283d28 */
    uint32_t end=yy_atlas_addr(yy_atlas_end(str));           /* 0x283d2c */
    if (yy_atlas_space(table,byte) && begin<end) {
        uint32_t next=begin+1u,bound=end+1u;
        for (;;) {
            str->begin=yy_atlas_ptr(next);         /* 0x283d50 */
            begin=next;
            byte=yy_atlas_load8(next);             /* 0x283d58 */
            next+=1u;
            if (!yy_atlas_space(table,byte)) break;
            if (next==bound) break;                /* CMP after ADD in this loop */
        }
    }
    if (begin==end) return;
    uint32_t tested=end-1u;
    str->end=(char *)(uintptr_t)tested;             /* 0x283d84 */
    byte=yy_atlas_load8(end-1u);
    if (yy_atlas_space(table,byte) && tested>=begin) {
        uint32_t next=end-2u,bound=begin-2u;
        for (;;) {
            str->end=(char *)(uintptr_t)next;      /* 0x283dac */
            tested=next;
            byte=yy_atlas_load8(next);             /* 0x283db4 */
            next-=1u;
            if (!yy_atlas_space(table,byte)) break;
            if (next==bound) break;
        }
    }
    str->end=(char *)(uintptr_t)(tested+1u);        /* 0x283dd4 */
}
/* readLine@0x283de8: EOF does not write out. Preserve both cursor reloads. */
static YY_ATLAS_NOINLINE int yy_atlas_readLine(const char **cursor,const char *end,yy_atlas_str *out)
{
    uint32_t limit=yy_atlas_addr(end),current=yy_atlas_addr(*cursor);
    if (current==limit) return 0;
    out->begin=yy_atlas_ptr(current);
    current=yy_atlas_addr(*cursor);                /* 0x283e04 */
    if (current!=limit && yy_atlas_load8(current)!='\n') {
        uint32_t next=current+1u;
        for (;;) {
            int more=next!=limit;                  /* 0x283e30 CMP */
            *cursor=yy_atlas_ptr(next);            /* STR does not update NZCV */
            current=next;
            next+=1u;                             /* ADD, not ADDS */
            if (!more) break;
            if (yy_atlas_load8(current)=='\n') break;
        }
    }
    out->end=(char *)(uintptr_t)current;
    yy_atlas_trim(out);
    current=yy_atlas_addr(*cursor);                /* 0x283e50 */
    if (current!=limit) *cursor=yy_atlas_ptr(current+1u);
    return 1;
}
/* All three scans compare k with bound BEFORE unconditional LDRB and ADD.
 * Neither MOV/LDRB/ADD sets flags. BNE uses the earlier CMP, not advanced k.
 * Thus the last valid byte IS compared; a miss loads *end before returning.
 * Empty range also loads once (including NULL at readTuple EOF).
 * Anchors: 0x283ea0..eb0, 0x283f08..f18, 0x283f54..f64. */
static YY_ATLAS_NOINLINE int yy_atlas_beginPast(yy_atlas_str *str,char delimiter)
{
    uint32_t k=yy_atlas_addr(yy_atlas_begin(str))+1u,bound=yy_atlas_addr(yy_atlas_end(str))+1u;
    for (;;) {
        int more=k!=bound;                         /* CMP */
        uint32_t after=k;                          /* MOV */
        uint32_t byte=yy_atlas_load8(k-1u);         /* unconditional LDRB */
        k+=1u;                                    /* ADD: preserves CMP flags */
        if (!more) return 0;
        if (byte==(unsigned char)delimiter) {
            str->begin=yy_atlas_ptr(after);
            return 1;
        }
    }
}
static YY_ATLAS_NOINLINE int yy_atlas_readValue(const char **cursor,const char *end,yy_atlas_str *str)
{
    (void)yy_atlas_readLine(cursor,end,str);
    if (!yy_atlas_beginPast(str,':')) return 0;
    yy_atlas_trim(str);
    return 1;
}
static YY_ATLAS_NOINLINE int yy_atlas_readTuple(const char **cursor,const char *end,yy_atlas_str tuple[4])
{
    yy_atlas_str line={0,0};
    (void)yy_atlas_readLine(cursor,end,&line);
    if (!yy_atlas_beginPast(&line,':')) return 0;    /* no EOF/null safety repair */
    const char *field=line.begin;
    for (uint32_t i=0;;++i) {
        line.begin=field;
        tuple[i].begin=field;
        if (!yy_atlas_beginPast(&line,',')) {
            tuple[i].begin=field;                  /* repeat store at 0x283f70 */
            tuple[i].end=line.end;
            yy_atlas_trim(&tuple[i]);
            return (int)i+1;
        }
        tuple[i].end=(char *)(uintptr_t)(yy_atlas_addr(line.begin)-2u);
        yy_atlas_trim(&tuple[i]);
        field=line.begin;
        if (i==2u) {
            tuple[3].begin=field;
            tuple[3].end=line.end;
            yy_atlas_trim(&tuple[3]);
            return 4;
        }
    }
}
/* mallocString@0x283fc8: len cached before allocation; begin reloaded after it.
 * 0x284000 uses memcpy's actual return as the result and terminator base. */
static YY_ATLAS_NOINLINE char *yy_atlas_mallocString(yy_atlas_str *str)
{
    const char *begin=yy_atlas_begin(str);
    uint32_t length=yy_atlas_addr(yy_atlas_end(str))-yy_atlas_addr(begin);
    char *string=(char *)_malloc(length+1u,YY_ATLAS_SRC_FILE,137u);
    string=(char *)memcpy(string,yy_atlas_begin(str),(size_t)length);
    yy_atlas_store8(yy_atlas_addr(string)+length,0);
    return string;
}
/* indexOf@0x284010 has TWO arguments: table=r0, Str*=r1. Eight entries fixed. */
static YY_ATLAS_NOINLINE int yy_atlas_indexOf(const char *const volatile *array,yy_atlas_str *str)
{
    const char *begin=yy_atlas_begin(str);
    uint32_t length=yy_atlas_addr(yy_atlas_end(str))-yy_atlas_addr(begin);
    for (int i=7;i>=0;--i)
        if (strncmp(array[i],begin,(size_t)length)==0) return i;
    return 0;
}
static int yy_atlas_toInt(yy_atlas_str *str)
{ return (int)strtol(yy_atlas_begin(str),&str->end,10); }
static int yy_atlas_equals(yy_atlas_str *str,const char *other)
{ const char *begin=yy_atlas_begin(str);
  uint32_t length=yy_atlas_addr(yy_atlas_end(str))-yy_atlas_addr(begin);
  return strncmp(other,begin,(size_t)length)==0; }

/* Original abortAtlas is inlined at 0x284638/0x28481c/0x284830/0x284844:
 * call 0x284120 then return NULL. */
static spAtlas* yy_atlas_abort(spAtlas* self)
{
    spAtlas_dispose(self);
    return 0;
}

/* Original tables at 0x3f7750 (format) and 0x3f7770 (filter), 8 pointers
 * each; copied as data only.  Index 0 is the empty string. */
static const char* volatile yy_atlas_formatNames[8] = {
    "", "Alpha", "Intensity", "LuminanceAlpha", "RGB565", "RGBA4444", "RGB888", "RGBA8888"
};
static const char* volatile yy_atlas_textureFilterNames[8] = {
    "", "Nearest", "Linear", "MipMap", "MipMapNearestNearest",
    "MipMapLinearNearest", "MipMapNearestLinear", "MipMapLinearLinear"
};

/* 0x284058.  calloc(1,44,Atlas.c,37); atlas=+0, name=+4 (strdup at line 39).
 * No NULL check in the original. */
YY_ATLAS_NOINLINE spAtlasPage* spAtlasPage_create(spAtlas* atlas, const char* name)
{
    spAtlasPage* self = (spAtlasPage*)_calloc(1u, YY_ATLAS_ALLOC_PAGE, YY_ATLAS_SRC_FILE, 37u);
    size_t length;

    self->atlas = atlas; /* 0x284084 */

    length = strlen(name) + 1u; /* 0x28408c..0x284098 */
    self->name = (char*)_malloc((uint32_t)length, YY_ATLAS_SRC_FILE, 39u); /* 0x28409c */
    strcpy(self->name, name); /* 0x2840a8 */
    return self;
}

/* 0x2840d8: tail-call calloc(1,80,Atlas.c,52). */
YY_ATLAS_NOINLINE spAtlasRegion* spAtlasRegion_create(void)
{
    return (spAtlasRegion*)_calloc(1u, YY_ATLAS_ALLOC_REGION, YY_ATLAS_SRC_FILE, 52u);
}

/* 0x284174.  AAPCS32 ABI: r0=data, r1=dataLen, r2=dir, r3=renderer.
 * The original never checks dir for NULL (strlen at 0x284190). */
spAtlas* spAtlas_create(const char* data, int dataLen, const char* dir, void* renderer)
{
    spAtlas* self;
    const char* end = yy_native_addr_add(data, (uint32_t)dataLen);                 /* 0x28417c r5 */
    int dirLength = (int)strlen(dir);                 /* 0x284190, [sp+0x14] */
    int needsSlash;                                   /* [sp+0x20] */
    spAtlasPage* page = 0;                            /* fp */
    spAtlasPage* lastPage = 0;                        /* [sp+0x1c] */
    spAtlasRegion* lastRegion = 0;                    /* r8 */
    yy_atlas_str str;
    yy_atlas_str tuple[4];
    int count;

    /* 0x284194..0x2841bc: dirLen <= 0 or trailing '/' or '\' => 0. */
    needsSlash = dirLength > 0 &&
                 dir[dirLength - 1] != '/' &&
                 dir[dirLength - 1] != '\\';

    self = (spAtlas*)_calloc(1u, YY_ATLAS_ALLOC_ATLAS, YY_ATLAS_SRC_FILE, 182u); /* 0x2841e0 */
    self->renderer = renderer; /* 0x284230 */

    while (yy_atlas_readLine(&data, end, &str)) { /* 0x284254 */
        if (str.end == str.begin) { /* 0x284240..0x28424c: blank line */
            page = 0;               /* 0x284250 */
        } else if (!page) {
            /* ---- page header (0x284654..0x2847d8) ---- */
            char* name = yy_atlas_mallocString(&str); /* 0x284664 */
            char* path = (char*)_malloc(
                (uint32_t)dirLength + (uint32_t)needsSlash + (uint32_t)strlen(name) + 1u,
                YY_ATLAS_SRC_FILE, 190u);             /* 0x284680 */
            memcpy(path, dir, (size_t)dirLength);     /* 0x284690 */
            if (needsSlash)
                path[dirLength] = '/' ;               /* 0x2846b0 */
            strcpy((char *)yy_native_addr_add(path, (uint32_t)dirLength + (uint32_t)needsSlash), name); /* 0x2846b4 */

            page = spAtlasPage_create(self, name);    /* 0x2846c0 */
            _free(name);                              /* 0x2846cc */
            if (lastPage)
                lastPage->next = page;                /* 0x2846e4 */
            else
                self->pages = page;                   /* 0x2846ec */
            lastPage = page;

            switch (yy_atlas_readTuple(&data, end, tuple)) { /* 0x2846f0 */
            case 0:
                return yy_atlas_abort(self);          /* 0x2846f4 -> 0x28481c */
            case 2: /* old TexturePacker: size line optional */
                page->width = yy_atlas_toInt(&tuple[0]);  /* 0x2847f4 */
                page->height = yy_atlas_toInt(&tuple[1]); /* 0x284808 */
                if (!yy_atlas_readTuple(&data, end, tuple))
                    return yy_atlas_abort(self);      /* 0x284810..0x284818 */
                /* fallthrough */
            }

            page->format = (spAtlasFormat)yy_atlas_indexOf(
                yy_atlas_formatNames, &tuple[0]);  /* 0x284704..0x284718 */

            if (!yy_atlas_readTuple(&data, end, tuple))
                return yy_atlas_abort(self);          /* 0x28471c */
            page->minFilter = (spAtlasFilter)yy_atlas_indexOf(
                yy_atlas_textureFilterNames, &tuple[0]); /* 0x284730 */
            page->magFilter = (spAtlasFilter)yy_atlas_indexOf(
                yy_atlas_textureFilterNames, &tuple[1]); /* 0x284740 */

            if (!yy_atlas_readValue(&data, end, &str))
                return yy_atlas_abort(self);          /* 0x284754..0x284760 */

            page->uWrap = SP_ATLAS_CLAMPTOEDGE;       /* 0x284778 */
            page->vWrap = SP_ATLAS_CLAMPTOEDGE;       /* 0x284780 */
            if (!yy_atlas_equals(&str, "none")) {     /* 0x284788 */
                if (str.end - str.begin == 1) {
                    if (*str.begin == 'x')
                        page->uWrap = SP_ATLAS_REPEAT; /* 0x28485c */
                    else if (*str.begin == 'y')
                        page->vWrap = SP_ATLAS_REPEAT; /* 0x28486c */
                } else if (yy_atlas_equals(&str, "xy")) { /* 0x28479c */
                    page->uWrap = SP_ATLAS_REPEAT;
                    page->vWrap = SP_ATLAS_REPEAT;
                }
            }

            _spAtlasPage_createTexture(page, path);   /* 0x2847c8, body open */
            _free(path);                               /* 0x2847d0 */
        } else {
            /* ---- region (0x284280..0x28448c) ---- */
            spAtlasRegion* region = spAtlasRegion_create(); /* 0x284280 */
            if (lastRegion)
                lastRegion->next = region;            /* 0x28428c */
            else
                self->regions = region;               /* 0x284294 */
            region->page = page;                      /* 0x284298 */
            region->name = yy_atlas_mallocString(&str); /* 0x2842a0..0x2842ac */

            if (!yy_atlas_readValue(&data, end, &str))
                return yy_atlas_abort(self);          /* 0x2842b4..0x2842bc */

            /* 0x2842c0..0x2842e8: rotate = (value == "true"), 0/1 only.
             * This build has no `degrees` field: "90" would yield 0. */
            region->rotate = yy_atlas_equals(&str, "true");

            if (yy_atlas_readTuple(&data, end, tuple) != 2)
                return yy_atlas_abort(self);          /* 0x2842f0..0x2842f8 */
            region->x = yy_atlas_toInt(&tuple[0]);    /* 0x284310..0x28431c */
            region->y = yy_atlas_toInt(&tuple[1]);    /* 0x284324..0x284330 */

            if (yy_atlas_readTuple(&data, end, tuple) != 2)
                return yy_atlas_abort(self);          /* 0x284338..0x284340 */
            region->width = yy_atlas_toInt(&tuple[0]);  /* 0x284350..0x28435c */
            int32_t parsedHeight=yy_atlas_toInt(&tuple[1]);
            /* 0x284368..0x2843d8: exact conversion/division and height-store
             * ordering, including FPSCR-visible side effects. */
            int32_t x=region->x,y=region->y;
            int32_t pageWidth=page->width,pageHeight=page->height;
            float fw=yy_native_i32_f32(pageWidth);
            int32_t rotate=region->rotate,width=region->width;
            float fx=yy_native_i32_f32(x);
            float fh=yy_native_i32_f32(pageHeight);
            float fy=yy_native_i32_f32(y);
            float u=yy_native_div_f32(fx,fw);
            region->height=parsedHeight;             /* 0x2843a0, after first VDIV */
            float v=yy_native_div_f32(fy,fh);
            region->u=u;region->v=v;
            if(rotate){
                int32_t right=yy_native_add_i32(x,parsedHeight);
                int32_t bottom=yy_native_add_i32(y,width);
                float a=yy_native_i32_f32(right),b=yy_native_i32_f32(bottom);
                float u2=yy_native_div_f32(a,fw),v2=yy_native_div_f32(b,fh);
                region->u2=u2;region->v2=v2;          /* rotated: U2 before V2 */
            }else{
                int32_t bottom=yy_native_add_i32(y,parsedHeight);
                int32_t right=yy_native_add_i32(x,width);
                float b=yy_native_i32_f32(bottom),a=yy_native_i32_f32(right);
                float v2=yy_native_div_f32(b,fh),u2=yy_native_div_f32(a,fw);
                region->v2=v2;region->u2=u2;          /* ordinary: V2 before U2 */
            }

            count = yy_atlas_readTuple(&data, end, tuple); /* 0x2843e8 */
            if (!count)
                return yy_atlas_abort(self);          /* 0x2843f0 */
            if (count == 4) { /* splits optional */
                region->splits = (int*)_malloc(16u, YY_ATLAS_SRC_FILE, 269u); /* 0x2844c8..0x2844ec */
                region->splits[0] = yy_atlas_toInt(&tuple[0]);
                region->splits[1] = yy_atlas_toInt(&tuple[1]);
                region->splits[2] = yy_atlas_toInt(&tuple[2]);
                region->splits[3] = yy_atlas_toInt(&tuple[3]);

                count = yy_atlas_readTuple(&data, end, tuple); /* 0x284574 */
                if (!count)
                    return yy_atlas_abort(self);      /* 0x284580 */
                if (count == 4) { /* pads only with splits */
                    region->pads = (int*)_malloc(16u, YY_ATLAS_SRC_FILE, 277u); /* 0x28458c..0x2845a8 */
                    region->pads[0] = yy_atlas_toInt(&tuple[0]);
                    region->pads[1] = yy_atlas_toInt(&tuple[1]);
                    region->pads[2] = yy_atlas_toInt(&tuple[2]);
                    region->pads[3] = yy_atlas_toInt(&tuple[3]);

                    if (!yy_atlas_readTuple(&data, end, tuple))
                        return yy_atlas_abort(self);  /* 0x284628..0x284634 */
                }
            }

            /* 0x2843fc..0x284428: orig line (tuple[0],tuple[1]).  Nothing
             * checks count here, exactly like the original: a 1-field line
             * leaves tuple[1] stale and is still consumed. */
            region->originalWidth = yy_atlas_toInt(&tuple[0]);
            region->originalHeight = yy_atlas_toInt(&tuple[1]);

            /* 0x28442c: offset line; return value deliberately ignored. */
            yy_atlas_readTuple(&data, end, tuple);
            region->offsetX = yy_atlas_toInt(&tuple[0]);
            region->offsetY = yy_atlas_toInt(&tuple[1]);

            if (!yy_atlas_readValue(&data, end, &str))
                return yy_atlas_abort(self);          /* 0x284468..0x284470 */
            lastRegion = region;                      /* 0x284480 */
            region->index = yy_atlas_toInt(&str);     /* 0x284484..0x284488 */
        }
    }

    return self; /* 0x28426c */
}
