#include "gml.h"

int gml_dispatch(GmVM* vm, long code) {
    void gml_0012(GmVM* vm);
    void gml_0018(GmVM* vm);
    void gml_0146(GmVM* vm);
    void gml_0164(GmVM* vm);
    void gml_0172(GmVM* vm);
    void gml_0245(GmVM* vm);
    void gml_0257(GmVM* vm);
    void gml_0345(GmVM* vm);
    void gml_0361(GmVM* vm);
    void gml_0364(GmVM* vm);
    void gml_0536(GmVM* vm);
    void gml_0670(GmVM* vm);
    void gml_0693(GmVM* vm);
    void gml_0782(GmVM* vm);
    void gml_0792(GmVM* vm);
    switch (code) {
        case 12: gml_0012(vm); return 1;
        case 18: gml_0018(vm); return 1;
        case 146: gml_0146(vm); return 1;
        case 164: gml_0164(vm); return 1;
        case 172: gml_0172(vm); return 1;
        case 245: gml_0245(vm); return 1;
        case 257: gml_0257(vm); return 1;
        case 345: gml_0345(vm); return 1;
        case 361: gml_0361(vm); return 1;
        case 364: gml_0364(vm); return 1;
        case 536: gml_0536(vm); return 1;
        case 670: gml_0670(vm); return 1;
        case 693: gml_0693(vm); return 1;
        case 782: gml_0782(vm); return 1;
        case 792: gml_0792(vm); return 1;
        default: return 0;
    }
}
