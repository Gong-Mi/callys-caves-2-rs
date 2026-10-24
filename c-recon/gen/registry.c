#include "gml.h"

int gml_dispatch(GmVM* vm, long code) {
    void gml_0012(GmVM* vm);
    void gml_0792(GmVM* vm);
    switch (code) {
        case 12: gml_0012(vm); return 1;
        case 792: gml_0792(vm); return 1;
        default: return 0;
    }
}
