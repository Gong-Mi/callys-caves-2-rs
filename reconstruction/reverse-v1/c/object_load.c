/* CObjectGM::LoadFromChunk (0x19d688) — header part of the OBJT record parser.
 *
 *     int CObjectGM::LoadFromChunk(CObjectGM* dst, const uchar* src, ...)
 *
 * The record is the OBJT object table entry. Only the fixed header is modelled
 * here; everything past src+0x20 is behind a data-version gate
 * (`cmp r2,#5` … `cmp r2,#8`) whose version global is read through a
 * pc-relative table that is not relocated in the oracle harness, so that tail
 * is out of this arm's domain (see claims OBJ-ORA-004).
 *
 * Field map, derived by sweeping one source byte at a time against the
 * original (probe + differential, not from the card):
 *     src+0x04..0x07  sprite index (bits 0..27), bit31 lifted into a global
 *     src+0x08        visible   -> dst[0] bit1
 *     src+0x0c        solid     -> dst[0] bit0
 *     src+0x14        persistent-> dst[0] bit2
 *     src+0x10..0x13  depth     -> dst+0x08
 *     src+0x18..0x1b            -> dst+0x0c
 *     src+0x1c..0x1f            -> dst+0x10
 * Clear() has already set dst[0] bit4 (0x10) before the parse, and the flags
 * bits are or/bic'd onto whatever is there.
 */
#include <stdint.h>
#include <string.h>

#define FLAG_SOLID      1u
#define FLAG_VISIBLE    2u
#define FLAG_PERSISTENT 4u
#define FLAG_CLEAR      0x10u

/* The original ORs bit31 of the sprite index into a process-wide word. The
 * differential carries the same accumulator so that side effect is compared
 * too, not just the destination struct. */
#ifdef MUTANT
#if MUTANT == 1
#  define M_SWAP_VISIBLE_SOLID 1
#elif MUTANT == 2
#  define M_KEEP_SPRITE_HI 1
#elif MUTANT == 3
#  define M_DEPTH_FROM_14 1
#elif MUTANT == 4
#  define M_PERSIST_FROM_18 1
#elif MUTANT == 5
#  define M_FLAGS_OVERWRITE 1
#else
#  error "unknown MUTANT"
#endif
#endif

static uint32_t g_hi_bits;

uint32_t object_load_hi_bits(void) { return g_hi_bits; }
void object_load_reset(void) { g_hi_bits = 0; }

static uint32_t rd32(const unsigned char *p)
{
    uint32_t v;
    memcpy(&v, p, 4);
    return v;
}

/* Returns 1 on success, matching the original's return value for this path. */
int CObjectGM_LoadFromChunk(unsigned char *dst, const unsigned char *src)
{
    uint32_t flags = FLAG_CLEAR;
    uint32_t sprite = rd32(src + 4);

    if (sprite & 0x70000000u) {
        memcpy(dst + 4, &sprite, 4);
    } else {
#ifndef M_KEEP_SPRITE_HI
        g_hi_bits |= sprite & 0x80000000u;
        sprite &= 0x7fffffffu;
#endif
        memcpy(dst + 4, &sprite, 4);
    }

#ifdef M_SWAP_VISIBLE_SOLID
    if (rd32(src + 0x0c))
        flags |= FLAG_VISIBLE;
    if (rd32(src + 0x08))
        flags |= FLAG_SOLID;
#else
    if (rd32(src + 0x0c))
        flags |= FLAG_SOLID;
    if (rd32(src + 0x08))
        flags |= FLAG_VISIBLE;
#endif
#ifdef M_PERSIST_FROM_18
    if (rd32(src + 0x18))
        flags |= FLAG_PERSISTENT;
#else
    if (rd32(src + 0x14))
        flags |= FLAG_PERSISTENT;
#endif
    /* or/bic onto what is already there, only our three bits change */
    uint32_t cur = rd32(dst);
#ifdef M_FLAGS_OVERWRITE
    cur = flags & 7u;
#else
    cur = (cur & ~7u) | (flags & 7u) | FLAG_CLEAR;
#endif
    memcpy(dst, &cur, 4);

#ifdef M_DEPTH_FROM_14
    memcpy(dst + 8, src + 0x14, 4);
#else
    memcpy(dst + 8, src + 0x10, 4);    /* depth */
#endif
    memcpy(dst + 0x0c, src + 0x18, 4);
    memcpy(dst + 0x10, src + 0x1c, 4);

    dst[0x1c] = 0;
    memset(dst + 0x40, 0, 8);
    return 1;
}
