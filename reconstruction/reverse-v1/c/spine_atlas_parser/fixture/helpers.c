/* The actual production C is included solely to access its private helpers.
 * This is reconstructed-C contract/fault-shape evidence, never original execution. */
#include "../src/spine_atlas_create.c"
#include "support.h"
#ifndef YY_ATLAS_EOF_FAULT
static uint32_t get_fpscr(void)
{ uint32_t v;__asm__ volatile(".fpu vfpv3-d16\nvmrs %0, FPSCR":"=r"(v)::"memory");return v; }
static void set_fpscr(uint32_t v)
{ __asm__ volatile(".fpu vfpv3-d16\nvmsr FPSCR, %0"::"r"(v):"memory"); }
static uint32_t float_bits(float f)
{ union {float f;uint32_t u;} x;x.f=f;return x.u; }
static yy_atlas_str *allocation_input;
static void *alter_begin(uint32_t n,const char *tag,uint32_t line)
{
    (void)tag;(void)line;
    allocation_input->begin="WXYZ";
    return malloc(n);
}
#endif
void _start(void)
{
    fixture_init();
#ifdef YY_ATLAS_EOF_FAULT
    const char *cursor=0;yy_atlas_str tuple[4];
    (void)yy_atlas_readTuple(&cursor,0,tuple);
    fixture_exit(99); /* rejected candidate: original load at address 0 omitted */
#else
    char mixed[]=" \tab \t";
    yy_atlas_str s={mixed,mixed+sizeof mixed-1};
    yy_atlas_trim(&s);
    fixture_check(s.begin==mixed+2 && s.end==mixed+4,"helper_trim_byte_bounds");
    const char *cursor=0;s.begin=(const char *)0x11;s.end=(char *)0x22;
    fixture_check(yy_atlas_readLine(&cursor,0,&s)==0 && s.begin==(const char *)0x11 && s.end==(char *)0x22,"helper_readLine_eof_preserves_output");
    char terminal[]="k:";s.begin=terminal;s.end=terminal+2;
    fixture_check(yy_atlas_beginPast(&s,':')==1 && s.begin==terminal+2,"helper_last_valid_delimiter_is_compared");
    char absent[]="az";s.begin=absent;s.end=absent+2;
    fixture_check(yy_atlas_beginPast(&s,':')==0 && s.begin==absent,"helper_missing_delimiter_keeps_begin");
    char stale[]="old: x";cursor=stale+sizeof stale-1;s.begin=stale;s.end=(char *)cursor;
    fixture_check(yy_atlas_readValue(&cursor,cursor,&s)==1 && s.begin==stale+5 && s.end==stale+6,"helper_readValue_eof_uses_stale_range");
    char values[]="v:1,2,3,4";cursor=values;yy_atlas_str tuple[4];
    fixture_check(yy_atlas_readTuple(&cursor,values+sizeof values-1,tuple)==4,"helper_four_tuple_fields");
    fixture_check(tuple[0].begin==values+2 && tuple[0].end==values+2 && tuple[3].begin==values+8 && tuple[3].end==values+9,"helper_comma_minus_one_and_last_extent");
    fixture_check(yy_atlas_toInt(&tuple[0])==1 && tuple[0].end==values+3,"helper_strtol_writes_own_end_slot");
    const char *names[8]={"zero","one","two","three","four","five","six","seven"};
    char empty[]="";s.begin=empty;s.end=empty;
    fixture_check(yy_atlas_indexOf(names,&s)==7,"helper_fixed_eight_reverse_prefix_scan");
    const char *old=yy_atlas_formatNames[7];yy_atlas_formatNames[7]="Renamed";
    s.begin="Renamed";s.end=(char *)s.begin+7;
    fixture_check(yy_atlas_indexOf(yy_atlas_formatNames,&s)==7,"helper_writable_original_data_table");
    yy_atlas_formatNames[7]=old;
    s.begin="ABCD";s.end=(char *)s.begin+4;allocation_input=&s;
    _setDebugMalloc(alter_begin);
    char *copy=yy_atlas_mallocString(&s);
    fixture_check(!strcmp(copy,"WXYZ"),"helper_mallocString_reloads_begin_after_allocator");
    _free(copy);
    fixture_check(fixture_live()==0,"helper_owned_copy_released");
    uint32_t saved=get_fpscr();
    uint32_t base=saved&~((3u<<22)|(0x1fu<<8)|0x9fu);
    set_fpscr(base);
    float f=yy_native_div_f32(yy_native_i32_f32(1),yy_native_i32_f32(3));
    uint32_t state=get_fpscr();
    fixture_check(float_bits(f)==0x3eaaaaabu,"vfp_nearest_rounding_bits");
    fixture_check((state&16u)!=0,"vfp_cumulative_inexact_flag");
    set_fpscr(base|(3u<<22));
    f=yy_native_div_f32(yy_native_i32_f32(1),yy_native_i32_f32(3));
    fixture_check(float_bits(f)==0x3eaaaaaau,"vfp_caller_toward_zero_is_respected");
    set_fpscr(base);
    f=yy_native_div_f32(yy_native_i32_f32(1),yy_native_i32_f32(0));
    state=get_fpscr();
    fixture_check(float_bits(f)==0x7f800000u && (state&2u)!=0,"vfp_divzero_result_and_cumulative_flag");
    set_fpscr(saved);
    fixture_finish();
#endif
}
