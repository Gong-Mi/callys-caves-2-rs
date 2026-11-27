/* Synthetic platform input object; real ReportSpineError reads dbg_csol and
 * calls address-point slot+0xc. No replacement report function or fake global. */
#include "spine_json_support.h"
#include <stdarg.h>
extern void fixture_report_sink(const char *,const char *);
static struct SpineErrorConsole console;
static void output(struct SpineErrorConsole *self,const char *format,...) {
    if(self!=&console)__builtin_trap();
    va_list ap;va_start(ap,format);const char *message=va_arg(ap,const char *);va_end(ap);
    fixture_report_sink(format,message);
}
static const struct SpineErrorConsoleVTable vtable={0,0,0,output};
void fixture_install_error_reporter(void) {
    console.vptr=&vtable;
    dbg_csol=&console;
}
