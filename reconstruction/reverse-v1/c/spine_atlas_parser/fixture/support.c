/* Synthetic libc/heap/texture/table providers. Only declared ASCII decimal,
 * small-string fixture inputs are used. Not Android libc/GPU or original oracle.
 * Float arithmetic is supplied by the actual local ARM compiler-rt archive. */
#include "support.h"
#include "spine_alloc.h"
static union {uint64_t align;unsigned char bytes[262144];} heap;
static uint32_t used;
static struct {void *p;uint32_t line;int live;} allocations[1024];
static unsigned allocation_count,checks;
static unsigned char classes[257];
const char *_ctype_;
volatile uint8_t g_bFreeingSpineSprite;
unsigned fixture_texture_calls,fixture_texture_frees;
int fixture_width_at_texture,fixture_height_at_texture;
char fixture_last_path[256];
int fixture_bad;
uintptr_t __stack_chk_guard=0x6e945588u;
static void text(const char *p)
{
    register uint32_t a __asm__("r0")=1,b __asm__("r1")=(uint32_t)(uintptr_t)p;
    register uint32_t c __asm__("r2")=(uint32_t)strlen(p),n __asm__("r7")=4;
    __asm__ volatile("svc 0":"+r"(a):"r"(b),"r"(c),"r"(n):"memory","cc");
}
void fixture_exit(int status)
{
    register int a __asm__("r0")=status;
    register int n __asm__("r7")=1;
    __asm__ volatile("svc 0"::"r"(a),"r"(n):"memory","cc");
    __builtin_unreachable();
}
void __stack_chk_fail(void){text("STACK SMASH\n");fixture_exit(98);}
void fixture_check(int condition,const char *name)
{
    ++checks;if(!condition)++fixture_bad;
    text(condition?"PASS ":"FAIL ");text(name);text("\n");
}
void fixture_finish(void)
{
    if(!checks){text("EMPTY\n");fixture_exit(97);}
    text(fixture_bad?"ATLAS FAIL\n":"ATLAS CHECKS OK\n");fixture_exit(fixture_bad?1:0);
}
size_t strlen(const char *s){size_t n=0;while(s[n])++n;return n;}
char *strcpy(char *d,const char *s){char *p=d;while((*p++=*s++)){}return d;}
int strcmp(const char *a,const char *b)
{while(*a && *a==*b){++a;++b;}return (unsigned char)*a-(unsigned char)*b;}
int strncmp(const char *a,const char *b,size_t n)
{for(size_t i=0;i<n;++i){unsigned char x=a[i],y=b[i];if(x!=y)return (int)x-(int)y;if(!x)return 0;}return 0;}
void *memcpy(void *d,const void *s,size_t n)
{for(size_t i=0;i<n;++i)((unsigned char *)d)[i]=((const unsigned char *)s)[i];return d;}
void *memset(void *d,int c,size_t n)
{for(size_t i=0;i<n;++i)((unsigned char *)d)[i]=(unsigned char)c;return d;}
void *malloc(size_t bytes)
{
    uint32_t n=((uint32_t)bytes+7u)&~7u;
    if(n<bytes)fixture_exit(95);
    if(!n)n=8u;
    if(n>sizeof heap.bytes-used || allocation_count==1024)fixture_exit(95);
    void *p=heap.bytes+used;used+=n;
    allocations[allocation_count].p=p;allocations[allocation_count].line=0;
    allocations[allocation_count++].live=1;return p;
}
void free(void *p)
{
    if(!p)return;
    for(unsigned i=0;i<allocation_count;++i)if(allocations[i].p==p && allocations[i].live){allocations[i].live=0;return;}
    text("INVALID FREE\n");fixture_exit(94);
}
static void *debug_malloc(uint32_t bytes,const char *tag,uint32_t line)
{
    if(!tag)fixture_exit(93);
    void *p=malloc(bytes);allocations[allocation_count-1].line=line;return p;
}
size_t fixture_live(void)
{size_t n=0;for(unsigned i=0;i<allocation_count;++i)n+=allocations[i].live!=0;return n;}
size_t fixture_live_at_line(uint32_t line)
{size_t n=0;for(unsigned i=0;i<allocation_count;++i)n+=allocations[i].live && allocations[i].line==line;return n;}
long strtol(const char *s,char **end,int base)
{
    if(base!=10)fixture_exit(92);
    const char *original=s;
    while(*s==' '||*s=='\t'||*s=='\n'||*s=='\r'||*s=='\v'||*s=='\f')++s;
    int negative=*s=='-';if(*s=='+'||*s=='-')++s;
    const char *digits=s;uint32_t magnitude=0,limit=negative?0x80000000u:0x7fffffffu;int overflow=0;
    while(*s>='0'&&*s<='9'){
        unsigned d=(unsigned)(*s-'0');
        if(magnitude>limit/10u || (magnitude==limit/10u && d>limit%10u))overflow=1;
        if(!overflow)magnitude=magnitude*10u+d;
        ++s;
    }
    if(end)*end=(char *)(s==digits?original:s);
    if(s==digits)return 0;
    if(overflow)return negative?(long)(int32_t)0x80000000u:0x7fffffffL;
    return (long)(int32_t)(negative?0u-magnitude:magnitude);
}
int sprintf(char *d,const char *format,...)
{
    if(strcmp(format,"%d"))fixture_exit(91);
    __builtin_va_list ap;__builtin_va_start(ap,format);int v=__builtin_va_arg(ap,int);__builtin_va_end(ap);
    uint32_t m=v<0?0u-(uint32_t)v:(uint32_t)v;char tmp[12];unsigned n=0,pos=0;
    if(v<0)d[pos++]='-';do{tmp[n++]=(char)('0'+m%10u);m/=10u;}while(m);
    while(n)d[pos++]=tmp[--n];d[pos]=0;return (int)pos;
}
void _spAtlasPage_createTexture(spAtlasPage *page,const char *path)
{
    if(strlen(path)>=sizeof fixture_last_path)fixture_exit(90);
    strcpy(fixture_last_path,path);++fixture_texture_calls;
    fixture_width_at_texture=page->width;fixture_height_at_texture=page->height;
    if(!page->width)page->width=64;if(!page->height)page->height=32;
    page->texture_id=(int32_t)(100u+fixture_texture_calls);
}
void texture_free(int32_t id) __asm__("_Z15GR_Texture_Freei");
void texture_free(int32_t id){if(id<=100)fixture_exit(89);++fixture_texture_frees;}
void fixture_init(void)
{
    const char spaces[]=" \t\r\n\v\f";
    for(unsigned i=0;i<sizeof spaces-1;++i)classes[(unsigned char)spaces[i]+1]=8;
    _ctype_=(const char *)classes;
    g_bFreeingSpineSprite=1; /* explicit fixture prestate for the real release gate */
    _setDebugMalloc(debug_malloc);
}
