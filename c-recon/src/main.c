/* State dump / differential driver.
 *
 * Reads a line-oriented state file, runs one lowered CODE function, writes the
 * resulting state in the same format. The Rust side
 * (crates/core/examples/ir_state_dump.rs) speaks the same protocol, so the two
 * implementations can be diffed byte for byte:
 *
 *     CODE    <id>
 *     CURRENT <instance id>
 *     INST    <id> <object> <alive>
 *     FIELD   <instance id> <name> <value>
 *     ARRAY   <instance id> <name> <index> <value>
 *     GLOBAL  <name> <value>
 */
#include "gml.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gml_0012(GmVM* vm);
void gml_0792(GmVM* vm);

static int run_code(GmVM* vm, long code, int32_t self) {
    vm->cur = self;
    switch (code) {
        case 12:  gml_0012(vm); return 1;
        case 792: gml_0792(vm); return 1;
        default:
            fprintf(stderr, "no generated function for CODE %ld\n", code);
            return 0;
    }
}

static void dump(FILE* f, GmVM* vm) {
    for (int i = 0; i < vm->ninst; i++) {
        GmInst* in = &vm->inst[i];
        fprintf(f, "INST %d %d %d\n", in->id, in->object, in->alive);
        for (int k = 0; k < in->nfields; k++)
            fprintf(f, "FIELD %d %s %.17g\n", in->id, in->fields[k].name, in->fields[k].value);
        for (int k = 0; k < in->narrays; k++)
            fprintf(f, "ARRAY %d %s %d %.17g\n", in->id, in->arrays[k].name,
                    in->arrays[k].index, in->arrays[k].value);
        for (int k = 0; k < 12; k++)
            if (in->alarms[k] != -1)
                fprintf(f, "ARRAY %d alarm %d %d\n", in->id, k, in->alarms[k]);
    }
    for (int i = 0; i < vm->nglobals; i++)
        fprintf(f, "GLOBAL %s %.17g\n", vm->globals[i].name, vm->globals[i].value);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <state-in> <state-out>\n", argv[0]);
        return 2;
    }
    FILE* in = fopen(argv[1], "r");
    if (!in) { perror(argv[1]); return 2; }

    long code = -1;
    int32_t self = -1;
    GmVM* vm = calloc(1, sizeof(GmVM));
    if (!vm) return 2;
    vm_init(vm, 0);

    char line[512];
    while (fgets(line, sizeof(line), in)) {
        char kind[32], name[NAME_LEN];
        long a, b; double v;
        if (sscanf(line, "CODE %ld", &code) == 1) continue;
        if (sscanf(line, "CURRENT %ld", &a) == 1) { self = (int32_t)a; continue; }
        if (sscanf(line, "INST %ld %ld", &a, &b) == 2) {
            GmInst* inst = vm_add(vm, (int32_t)a, (int32_t)b);
            if (!inst) { fprintf(stderr, "instance table full\n"); return 2; }
            continue;
        }
        if (sscanf(line, "FIELD %ld %47s %lf", &a, name, &v) == 3) {
            vm_set_field(vm, (int32_t)a, name, v);
            continue;
        }
        if (sscanf(line, "ARRAY %ld %47s %ld %lf", &a, name, &b, &v) == 4) {
            vm_set_array(vm, (int32_t)a, name, (int32_t)b, v);
            continue;
        }
        if (sscanf(line, "GLOBAL %47s %lf", name, &v) == 2) {
            GM_WRITE(vm, -5, name, v);
            continue;
        }
        if (sscanf(line, "%31s", kind) == 1) {
            fprintf(stderr, "unparsed line: %s\n", line);
            return 2;
        }
    }
    fclose(in);
    if (code < 0) { fprintf(stderr, "no CODE line\n"); return 2; }
    if (self < 0) self = vm->ninst ? vm->inst[0].id : 0;

    if (!run_code(vm, code, self)) return 2;

    FILE* out = fopen(argv[2], "w");
    if (!out) { perror(argv[2]); return 2; }
    dump(out, vm);
    fclose(out);
    free(vm);
    return 0;
}
