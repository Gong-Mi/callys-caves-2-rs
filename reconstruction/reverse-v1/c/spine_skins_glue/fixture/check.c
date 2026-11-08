/* Reconstructed ARM32 consumers only.  Heap, libc strings, the JSON tree
 * nodes, the attachment loader RECORD and its vtable, the five field parsers
 * and the fake attachments are SYNTHETIC providers.  qemu executes our linked
 * C, never original libyoyo bytes.  Original not executed; this is not an
 * original-equivalence claim.
 *
 * Subject: the eight unowned glue blocks of spSkeletonJson_readSkeletonData
 *   0x28c7a0..0x28c7e4  path stub + 5-arg loader call + NULL split + jump table
 *   0x28cc68..0x28ccb8  spSkin_addAttachment + three-level advance
 *   0x28cf24..0x28cf3c  mesh=2 / region=0 / linkedmesh=3 stubs
 *   0x28cf3c..0x28cf68  ik   "Target bone not found: "
 *   0x28cf68..0x28cf78  loader->error1 NULL split (silent skip)
 *   0x28cf78..0x28cfa8  loader error pair report + bbox=1 stub
 *   0x28d144..0x28d170  transform "Target bone not found: "
 *   0x28d170..0x28d19c  path      "Target slot not found: "
 *
 * REAL recovered bodies linked here (no stubs):
 *   spAttachmentLoader_createAttachment 0x284d58  c/spine_atlas_attachment
 *   spSkin_addAttachment / _Entry_create / spSkin_create  c/spine_skin
 *   spSkeletonData_create / spSkeletonData_dispose        c/spine_skeleton_data
 *   _spSkeletonJson_setError 0x28b784            c/spine_json_error
 *   Json_dispose / ReportSpineError              c/spine_json_support
 *   Json_getItem / Json_getString                c/json_interface
 *   _malloc / _calloc / _free                    c/spine_alloc
 *
 * SYNTHETIC boundaries (bodies NOT recovered here; each one records its
 * arguments so the wiring is provable):
 *   the attachment loader record + vtable slot +0x00 (the Atlas loader body
 *     0x284a08 is another module's scope; a recorder can answer NULL, answer
 *     with an object of ANY stored type, and publish error1/error2 exactly the
 *     way _spAttachmentLoader_setError 0x284df0 does),
 *   the four field parsers of the jump-table landings (region 0x28cdac,
 *     boundingbox 0x28cd6c, mesh/linkedmesh 0x28cb20, path 0x28ca5c — all owned
 *     by their own modules),
 *   the two "Target ..." argument records injected into the three tails.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_skins_glue.h"
#include "spine_skin.h"
#include "spine_json_error.h"
#include "spine_read_region.h"
#include "spine_read_mesh.h"
#include "spine_read_bbox_path.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* The SkeletonJson.c source tag at 0x357b08 (the same word c/spine_json_error
 * passes at line 90 and c/spine_read_tl_draworder names in its header). */
#define SPINE_JSON_SOURCE_TAG \
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_ADD 8

static struct {
    int create_n;
    spAttachmentLoader* loader;
    spSkin* skin;
    int32_t type;
    const char* name;
    const char* path;
    int answer_null;                 /* synthetic vtable returns NULL       */
    const char* fail_error1;         /* ... after publishing this pair      */
    const char* fail_error2;
    void* answer;                    /* object handed back when !answer_null */
} load;

static struct {
    int region_n, bbox_n, mesh_n, path_n;
    Json* map;
    void* att;
    const char* path;
    const void* json;
    spAttachmentLoader* loader;
    uint32_t slot;
    int mesh_rc;
    int entries_at_parse;            /* skin->entries count when called     */
} parse;

static struct {
    int add_n;
    spSkin* skin;
    uint32_t slot[MAX_ADD];
    const char* name[MAX_ADD];
    void* att[MAX_ADD];
    unsigned entries_before[MAX_ADD];
} add_obs;

static unsigned report_count;
static char reported[512], report_format[128];
static const char* alloc_tag[128];
static spSkin* observed_skin;        /* for entries_at_parse               */

/* ------------------------------------------------------------------ */
/* synthetic loader record + vtable                                    */
/* ------------------------------------------------------------------ */
struct fake_attachment {
    uint32_t opaque_00;              /* +0x00 */
    int32_t type;                    /* +0x04 — what the jump table reads  */
    uint32_t opaque_08, opaque_0c;
};

static struct fake_attachment att_region, att_bbox, att_mesh, att_linked,
                              att_path, att_type5, att_typeminus1, att_odd;

static spAttachment* loader_create(spAttachmentLoader* self, spSkin* skin,
                                   int32_t type, const char* name,
                                   const char* path)
{
    ++load.create_n;
    load.loader = self;
    load.skin = skin;
    load.type = type;
    load.name = name;
    load.path = path;
    /* _spAttachmentLoader_setError 0x284df0 shape: publish the pair in the
     * loader record; spAttachmentLoader_createAttachment already cleared it. */
    if (load.answer_null) {
        self->error1 = (char*)(uintptr_t)load.fail_error1;
        self->error2 = (char*)(uintptr_t)load.fail_error2;
        return 0;
    }
    return (spAttachment*)load.answer;
}

static struct spAttachmentLoaderVtable glue_vtable;
static spAttachmentLoader glue_loader;

/* ------------------------------------------------------------------ */
/* synthetic field parsers (one per jump-table landing)                */
/* ------------------------------------------------------------------ */
static void parse_note(Json* map, void* att, const void* json)
{
    parse.map = map;
    parse.att = att;
    parse.json = json;
    parse.entries_at_parse = observed_skin && observed_skin->entries
                                 ? 1 : 0;
}

void readSkeletonData_regionFields(Json* map, spRegionAttachment* a,
                                   const char* path, const spSkeletonJson* json)
{
    ++parse.region_n;
    parse_note(map, a, json);
    parse.path = path;
    /* the map really is the JSON node handed down: read a field through the
     * real accessor, which is what makes c/json_interface load-bearing. */
    CK(Json_getString(map, "type", 0) != 0, "region parser receives the map");
}

void readSkeletonData_boundingBoxFields(Json* map, spBoundingBoxAttachment* a,
                                        const void* json, spAttachmentLoader* loader)
{
    ++parse.bbox_n;
    parse_note(map, a, json);
    parse.loader = loader;
    CK(Json_getString(map, "type", 0) != 0, "bbox parser receives the map");
}

int readSkeletonData_meshFields(Json* map, spMeshAttachment* mesh,
                                const char* path, spSkeletonJson* json,
                                uint32_t slotIndex)
{
    ++parse.mesh_n;
    parse_note(map, mesh, json);
    parse.path = path;
    parse.slot = slotIndex;
    CK(Json_getString(map, "type", 0) != 0, "mesh parser receives the map");
    return parse.mesh_rc;
}

void readSkeletonData_pathAttachmentFields(Json* map, spPathAttachment* a,
                                           const void* json)
{
    ++parse.path_n;
    parse_note(map, a, json);
    CK(Json_getString(map, "type", 0) != 0, "path parser receives the map");
}

/* ------------------------------------------------------------------ */
/* real ReportSpineError sink                                          */
/* ------------------------------------------------------------------ */
void fixture_report_sink(const char* fmt, const char* message)
{
    ++report_count;
    strcpy(report_format, fmt);
    strcpy(reported, message);
}

/* setError imports strncat; the mesh fixture runtime has no strncat. */
char* strncat(char* d, const char* s, size_t n)
{
    char* r = d;
    d += strlen(d);
    while (n-- && *s) *d++ = *s++;
    *d = 0;
    return r;
}

/* ------------------------------------------------------------------ */
/* allocator wrapper (records line + tag, like the sibling fixtures)   */
/* ------------------------------------------------------------------ */
static void* glue_alloc(uint32_t n, const char* tag, uint32_t line)
{
    CK(na < 128 && tag, "skins-glue allocation roster/tag");
    void* p = reserve(n);
    alloc_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
    return p;
}

static unsigned alloc_count(uint32_t line)
{
    unsigned c = 0;
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) ++c;
    return c;
}
static int tag_is(uint32_t line, const char* want)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return alloc_tag[i] && strcmp(alloc_tag[i], want) == 0;
    return 0;
}
static unsigned free_hits(const void* p)
{
    unsigned c = 0;
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) ++c;
    return c;
}
static int free_slot(const void* p)
{
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) return (int)i;
    return -1;
}

/* ------------------------------------------------------------------ */
/* scaffolding                                                         */
/* ------------------------------------------------------------------ */
static spSkeletonJson parser_obj;

static void glue_begin(const char* name)
{
    begin(name);                    /* resets aa/na/nf, installs a recorder */
    _setDebugMalloc(glue_alloc);
    memset(&load, 0, sizeof(load));
    memset(&parse, 0, sizeof(parse));
    memset(&add_obs, 0, sizeof(add_obs));
    memset(&parser_obj, 0, sizeof(parser_obj));
    report_count = 0;
    reported[0] = report_format[0] = 0;
    observed_skin = 0;
    glue_vtable.createAttachment = loader_create;
    glue_vtable.configureAttachment = 0;
    glue_vtable.disposeAttachment = 0;
    glue_vtable.dispose = 0;
    glue_loader.error1 = 0;
    glue_loader.error2 = 0;
    glue_loader.vtable = &glue_vtable;
    glue_loader.atlas = 0;
    parser_obj.loader = (uint32_t)(uintptr_t)&glue_loader;
}

/* an spSkin whose entry list is the REAL c/spine_skin structure */
static spSkin* make_skin(const char* name)
{
    spSkin* s = spSkin_create(name);        /* real calloc 1*8 line 52 */
    observed_skin = s;
    return s;
}

/* the fake attachments the synthetic vtable can hand back */
static void make_attachments(void)
{
    att_region.type = SKINS_GLUE_TYPE_REGION;
    att_bbox.type = SKINS_GLUE_TYPE_BOUNDINGBOX;
    att_mesh.type = SKINS_GLUE_TYPE_MESH;
    att_linked.type = SKINS_GLUE_TYPE_LINKEDMESH;
    att_path.type = SKINS_GLUE_TYPE_PATH;
    att_type5.type = 5;
    att_typeminus1.type = -1;
    att_odd.type = 7;
}

/* the attachment MAP handed to the field parsers: key + "type" property */
static Json* attach_map(const char* key, const char* type)
{
    Json* m = node(key);
    add(m, string("type", type));
    add(m, string("name", type));       /* the "name" PROPERTY, not the key */
    return m;
}

/* three-level list: skins -> slots -> attachments, all real Json nodes */
typedef struct {
    Json* skins; Json* skinA; Json* skinB;
    Json* slotA; Json* slotB; Json* slotC;
    Json* att1; Json* att2; Json* att3; Json* att4;
} tree_t;

static void build_tree(tree_t* t)
{
    memset(t, 0, sizeof(*t));
    t->skins = node("skins");
    t->skinA = node("alpha");
    t->skinB = node("beta");
    t->slotA = node("body");
    t->slotB = node("hand");
    t->slotC = node("leg");
    t->att1 = attach_map("arm", "region");
    t->att2 = attach_map("forearm", "mesh");
    t->att3 = attach_map("finger", "path");
    t->att4 = attach_map("toe", "boundingbox");
    add(t->skins, t->skinA);
    add(t->skins, t->skinB);
    add(t->skinA, t->slotA);
    add(t->skinA, t->slotB);
    add(t->skinB, t->slotC);
    add(t->slotA, t->att1);
    add(t->slotA, t->att2);
    add(t->slotB, t->att3);
    add(t->slotC, t->att4);
}

/* ================================================================== */
/* 1. the five-argument call: which word lands in which register       */
/* ================================================================== */
static void create_args_five_pointer(void)
{
    static const char name[] = "the-name-property";
    static const char path[] = "the-path-argument";
    Json* map;

    glue_begin("create_args_five_pointer");
    make_attachments();
    spSkin* skin = make_skin("s");
    map = attach_map("key", "path");
    load.answer = &att_path;

    CK(readSkeletonData_skinsCreatePathAttachment(&parser_obj, skin, name, path,
                                                 map, 33u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "path stub publishes through the shared call");
    CK(load.create_n == 1, "exactly one spAttachmentLoader_createAttachment call");
    CK(load.loader == &glue_loader,
       "r0 = loader: json->loader (+0x04), not the parser itself (0x28c7a4)");
    CK(load.skin == skin, "r1 = skin: the spSkin pointer (0x28c7b0/0x28c7b4)");
    CK(load.type == SKINS_GLUE_TYPE_PATH, "r2 = 4 for the path stub (0x28c7a0)");
    CK(load.name == name && strcmp(load.name, name) == 0,
       "r3 = the attachment name (0x28c7a8 mov r3,r6)");
    CK(load.path == path && strcmp(load.path, path) == 0,
       "5th argument = path on the STACK (0x28c7ac str r5,[sp]) — not swapped with name");
    CK(load.name != load.path, "name and path are distinct pointers: no aliasing");
    pass("create_args_five_pointer");
}

/* ================================================================== */
/* 2. the five type load stubs and their jump-table landing            */
/* ================================================================== */
static void type_stub_five_landings(void)
{
    static const struct {
        int32_t want_type;
        const char* type_text;
        void* object;
        int which;                  /* 0 region 1 bbox 2 mesh 3 path */
    } cases[5] = {
        { SKINS_GLUE_TYPE_REGION,      "region",      &att_region, 0 },
        { SKINS_GLUE_TYPE_BOUNDINGBOX, "boundingbox", &att_bbox,   1 },
        { SKINS_GLUE_TYPE_MESH,        "mesh",        &att_mesh,   2 },
        { SKINS_GLUE_TYPE_LINKEDMESH,  "linkedmesh",  &att_linked, 2 },
        { SKINS_GLUE_TYPE_PATH,        "path",        &att_path,   3 },
    };
    static const char path_arg[] = "p";

    for (int i = 0; i < 5; ++i) {
        glue_begin("type_stub_five_landings");
        make_attachments();
        spSkin* skin = make_skin("s");
        Json* map = attach_map("key", cases[i].type_text);
        load.answer = cases[i].object;

        skins_glue_rc rc;
        switch (i) {
        case 0: rc = readSkeletonData_skinsCreateRegionAttachment(
                    &parser_obj, skin, "n", path_arg, map, 7u, 0, 0); break;
        case 1: rc = readSkeletonData_skinsCreateBoundingBoxAttachment(
                    &parser_obj, skin, "n", path_arg, map, 7u, 0, 0); break;
        case 2: rc = readSkeletonData_skinsCreateMeshAttachment(
                    &parser_obj, skin, "n", path_arg, map, 7u, 0, 0); break;
        case 3: rc = readSkeletonData_skinsCreateLinkedMeshAttachment(
                    &parser_obj, skin, "n", path_arg, map, 7u, 0, 0); break;
        default: rc = readSkeletonData_skinsCreatePathAttachment(
                    &parser_obj, skin, "n", path_arg, map, 7u, 0, 0); break;
        }
        CK(rc == SKINS_GLUE_PUBLISHED, "every type stub publishes");
        CK(load.type == cases[i].want_type,
           "the stub loads exactly the r2 constant of its branch (0x28cf24/2c/34, 0x28cfa0, 0x28c7a0)");
        CK(parse.region_n == (cases[i].which == 0)
           && parse.bbox_n == (cases[i].which == 1)
           && parse.mesh_n == (cases[i].which == 2)
           && parse.path_n == (cases[i].which == 3),
           "the jump table lands in the parser of the STORED type (0x28c7d0..0x28c7e0)");
        CK(parse.map == map && parse.att == cases[i].object,
           "the parser receives the attachment map (r4) and the created object (r6)");
        CK(parse.json == &parser_obj, "the parser receives the parser record (r8)");
        if (cases[i].which == 2) {
            CK(parse.path == path_arg && parse.slot == 7u,
               "mesh/linkedmesh parser also gets path (r5) and slotIndex ([sp,#0x28])");
        }
        if (cases[i].which == 1)
            CK(parse.loader == &glue_loader,
               "boundingbox parser gets json->loader for its configure call");
        CK(add_obs.add_n == 0 && skin->entries != 0,
           "the object is published through the real spSkin_addAttachment");
    }
    pass("type_stub_five_landings");
}

/* ================================================================== */
/* 3. the jump table reads the type STORED IN THE OBJECT               */
/* ================================================================== */
static void stored_type_table(void)
{
    glue_begin("stored_type_table");
    make_attachments();
    spSkin* skin = make_skin("s");
    Json* map = attach_map("key", "path");
    load.answer = &att_mesh;                   /* stored 2, requested 4 */

    CK(readSkeletonData_skinsCreatePathAttachment(&parser_obj, skin, "n", "p",
                                                 map, 1u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "requested path still publishes");
    CK(load.type == SKINS_GLUE_TYPE_PATH, "the loader was asked for type 4");
    CK(parse.mesh_n == 1 && parse.path_n == 0,
       "0x28c7c0 ldr r3,[r6,#4] dispatches on the STORED type (2 -> mesh), not the request");

    glue_begin("stored_type_table:region");
    make_attachments();
    skin = make_skin("s");
    map = attach_map("key", "mesh");
    load.answer = &att_region;                 /* stored 0, requested 2 */
    CK(readSkeletonData_skinsCreateMeshAttachment(&parser_obj, skin, "n", "p",
                                                 map, 1u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "requested mesh publishes");
    CK(load.type == SKINS_GLUE_TYPE_MESH && parse.region_n == 1 && parse.mesh_n == 0,
       "a loader that answers with a region object sends it to the region parser");

    glue_begin("stored_type_table:linked3");
    make_attachments();
    skin = make_skin("s");
    map = attach_map("key", "linkedmesh");
    load.answer = &att_linked;                 /* stored 3 */
    CK(readSkeletonData_skinsCreateLinkedMeshAttachment(&parser_obj, skin, "n", "p",
                                                       map, 5u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "requested linkedmesh publishes");
    CK(parse.mesh_n == 1, "table entry 3 (0x28c7dc) shares the mesh parser with entry 2");
    pass("stored_type_table");
}

/* ================================================================== */
/* 4. stored type outside 0..4: add only, no field parse               */
/* ================================================================== */
static void stored_type_out_of_range(void)
{
    glue_begin("stored_type_out_of_range");
    make_attachments();
    spSkin* skin = make_skin("s");
    Json* map = attach_map("key", "region");
    load.answer = &att_type5;

    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 9u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "a stored type 5 still publishes");
    CK(parse.region_n == 0 && parse.bbox_n == 0 && parse.mesh_n == 0
       && parse.path_n == 0,
       "0x28c7c4 cmp r3,#4 + addls is unsigned: 5 falls through 0x28c7cc, no parser");
    CK(skin->entries != 0, "the fall-through still runs spSkin_addAttachment (0x28cc68)");

    glue_begin("stored_type_out_of_range:minus1");
    make_attachments();
    skin = make_skin("s");
    map = attach_map("key", "region");
    load.answer = &att_typeminus1;
    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 9u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "0xffffffff publishes");
    CK(parse.region_n == 0 && skin->entries != 0,
       "a negative stored type is > 4 unsigned, so it skips the table but is added");
    pass("stored_type_out_of_range");
}

/* ================================================================== */
/* 5. NULL answer with a silent loader: 0x28cf74 skip                  */
/* ================================================================== */
static void null_loader_silent_skip(void)
{
    glue_begin("null_loader_silent_skip");
    make_attachments();
    spSkin* skin = make_skin("s");
    spSkeletonData* data = spSkeletonData_create();
    Json* root = node("root");
    Json* map = attach_map("key", "region");
    load.answer_null = 1;
    load.fail_error1 = 0;
    load.fail_error2 = 0;

    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 3u, root, data)
       == SKINS_GLUE_SKIPPED,
       "createAttachment NULL + loader->error1 == 0 returns the skip code (0x28cf74)");
    CK(load.create_n == 1 && parse.region_n == 0,
       "no field parser runs for an attachment that was never created");
    CK(skin->entries == 0, "the skipped attachment never reaches spSkin_addAttachment");
    CK(report_count == 0 && parser_obj.error == 0,
       "a silent loader produces NO setError and no parser error");
    CK(free_hits(data) == 0 && free_hits(root) == 0,
       "the silent skip disposes neither the skeleton data nor the root");
    CK(nf == 2 && ff[0] == 0 && ff[1] == 0,
       "the only frees are the wrapper's two unconditional _free(NULL) calls (0x284d78/0x284d7c)");

    /* the stale-error variant: the REAL wrapper 0x284d58 frees and clears the
     * previous pair BEFORE the vtable call, so a NULL answer still skips. */
    glue_begin("null_loader_silent_skip:stale");
    make_attachments();
    skin = make_skin("s");
    data = spSkeletonData_create();
    root = node("root");
    map = attach_map("key", "region");
    glue_loader.error1 = (char*)(uintptr_t)"stale-error";
    load.answer_null = 1;
    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 3u, root, data)
       == SKINS_GLUE_SKIPPED,
       "a stale loader->error1 is cleared by the wrapper, so the split still skips");
    CK(free_hits("stale-error") == 1 && glue_loader.error1 == 0,
       "spAttachmentLoader_createAttachment freed and NULLed the stale error1 (0x284d78/0x284da4)");
    CK(report_count == 0 && free_hits(data) == 0, "still no report, no data dispose");
    pass("null_loader_silent_skip");
}

/* ================================================================== */
/* 6. NULL answer with a reporting loader: error pair pass-through     */
/* ================================================================== */
static void loader_error_pair_report(void)
{
    static const char e1[] = "atlas: region not found: ";
    static const char e2[] = "hand";
    glue_begin("loader_error_pair_report");
    make_attachments();
    spSkin* skin = make_skin("s");
    spSkeletonData* data = spSkeletonData_create();
    Json* root = node("root");
    Json* child = node("child");
    Json* map = attach_map("key", "region");
    add(root, child);
    load.answer_null = 1;
    load.fail_error1 = e1;
    load.fail_error2 = e2;

    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 3u, root, data)
       == SKINS_GLUE_ERROR,
       "a reporting loader turns the NULL answer into the error code (0x28bdcc)");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "the tail reports through the real console vcall");
    CK(strcmp(reported, "atlas: region not found: hand") == 0,
       "0x28cf90 ldm r3,{r2,r3}: message = loader->error1 and argument = loader->error2");
    CK(parser_obj.error != 0
       && strcmp((char*)(uintptr_t)parser_obj.error, "atlas: region not found: hand") == 0,
       "the pair is stored in parser->error, not a static literal");
    CK(alloc_count(90u) == 1 && tag_is(90u, SPINE_JSON_SOURCE_TAG),
       "the error copy is a line-90 SkeletonJson.c allocation");
    CK(free_hits(data) == 1, "spSkeletonData_dispose(data) ran exactly once (0x28cf80)");
    CK(free_hits(root) == 1 && free_hits(child) == 1,
       "the setError root argument is [sp,#0x24]: the JSON tree is disposed by setError");
    CK(free_slot(data) < free_slot(root),
       "the ORDER is dispose(data) -> setError(root) (0x28cf80 before 0x28cf94)");
    CK(skin->entries == 0, "the failing attachment is never added to the skin");
    CK(free_hits(skin) == 0, "the skin is not disposed by this tail");
    pass("loader_error_pair_report");
}

/* ================================================================== */
/* 7. the error pair with a NULL second word                           */
/* ================================================================== */
static void loader_error_pair_null_arg(void)
{
    static const char e1[] = "atlas: region not found: ";
    glue_begin("loader_error_pair_null_arg");
    make_attachments();
    spSkin* skin = make_skin("s");
    spSkeletonData* data = spSkeletonData_create();
    Json* root = node("root");
    Json* map = attach_map("key", "region");
    load.answer_null = 1;
    load.fail_error1 = e1;
    load.fail_error2 = 0;

    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "n", "p",
                                                   map, 3u, root, data)
       == SKINS_GLUE_ERROR, "a one-word error pair still errors");
    CK(strcmp(reported, "atlas: region not found: ") == 0,
       "a NULL loader->error2 skips strncat (0x28b7cc cmp r9,#0)");
    CK(parser_obj.error != 0
       && strcmp((char*)(uintptr_t)parser_obj.error, "atlas: region not found: ") == 0,
       "the stored message is error1 alone");
    pass("loader_error_pair_null_arg");
}

/* ================================================================== */
/* 8. the real spSkin_addAttachment enqueue                            */
/* ================================================================== */
static void add_attachment_real_queue(void)
{
    glue_begin("add_attachment_real_queue");
    make_attachments();
    spSkin* skin = make_skin("sk");
    Json* map = attach_map("key", "region");
    load.answer = &att_region;

    CK(readSkeletonData_skinsCreateRegionAttachment(&parser_obj, skin, "first", "p",
                                                   map, 11u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "first attachment publishes");
    CK(skin->entries != 0 && skin->entries->slotIndex == 11u,
       "spSkin_addAttachment stores the slotIndex (r1 = [sp,#0x28])");
    CK(skin->entries->name != 0 && strcmp(skin->entries->name, "first") == 0,
       "the entry name is the caller's r2 word (the loop hands the JSON member key), copied by _Entry_create");
    CK(skin->entries->name != (const char*)map->name,
       "_Entry_create made its own heap copy (0x28ec00), it does not alias the Json key");
    CK(skin->entries->attachment == (spAttachment*)&att_region,
       "the attachment pointer itself is stored (r3 = r6)");
    CK(alloc_count(36u) == 1 && alloc_count(38u) == 1,
       "entry calloc line 36 and name copy line 38 are the real c/spine_skin lines");

    /* head insertion: a second add lands in front, no replacement */
    CK(readSkeletonData_skinsCreatePathAttachment(&parser_obj, skin, "second", "q",
                                                 map, 12u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "second attachment publishes");
    CK(skin->entries->slotIndex == 12u && skin->entries->next != 0
       && skin->entries->next->slotIndex == 11u,
       "duplicates are not replaced: the newest entry becomes the head");
    pass("add_attachment_real_queue");
}

/* ================================================================== */
/* 9. the add happens AFTER the field parser                           */
/* ================================================================== */
static void add_precedes_advance(void)
{
    glue_begin("add_precedes_advance");
    make_attachments();
    spSkin* skin = make_skin("s");
    Json* map = attach_map("key", "mesh");
    load.answer = &att_mesh;
    parse.mesh_rc = 1;              /* "queued for the linkedmesh postpass" */

    CK(readSkeletonData_skinsCreateMeshAttachment(&parser_obj, skin, "n", "p",
                                                 map, 1u, 0, 0)
       == SKINS_GLUE_PUBLISHED, "a queued mesh still publishes");
    CK(parse.mesh_n == 1 && parse.entries_at_parse == 0,
       "the field parser runs BEFORE the add (skin->entries was empty)");
    CK(skin->entries != 0, "and the queued mesh is added anyway (0x28cb1c b 0x28cc68)");
    pass("add_precedes_advance");
}

/* ================================================================== */
/* 10. the three-level advance                                         */
/* ================================================================== */
static void advance_three_levels(void)
{
    tree_t t;
    skins_glue_cursor c;

    glue_begin("advance_three_levels");
    build_tree(&t);
    c.attachment = t.att1;
    c.slot = t.slotA;
    c.skin = t.skinA;

    CK(readSkeletonData_skinsAdvance(&c) == SKINS_GLUE_NEXT_ATTACHMENT,
       "0x28cc7c ldr r4,[r4]: att1 -> att2 keeps the attachment loop");
    CK(c.attachment == t.att2 && c.slot == t.slotA && c.skin == t.skinA,
       "only the attachment cell moved");
    CK(readSkeletonData_skinsAdvance(&c) == SKINS_GLUE_NEXT_SLOT,
       "0x28cc88..0x28cc98: att2 has no sibling, the SLOT advances");
    CK(c.attachment == 0 && c.slot == t.slotB && c.skin == t.skinA,
       "the slot cell now holds slotB and the attachment cell is NULL");
    c.attachment = t.att3;                       /* slot head 0x28c6d8 */
    CK(readSkeletonData_skinsAdvance(&c) == SKINS_GLUE_NEXT_SKIN,
       "0x28cca0..0x28ccb0: slotB has no sibling, the SKIN advances");
    CK(c.slot == 0 && c.skin == t.skinB, "the skin cell now holds skinB");
    c.slot = t.slotC;                            /* skin head 0x28c664 */
    c.attachment = t.att4;
    CK(readSkeletonData_skinsAdvance(&c) == SKINS_GLUE_NEXT_DONE,
       "an empty attachment list, an empty slot list and an empty skin list end the walk");
    CK(c.attachment == 0 && c.slot == 0 && c.skin == 0, "all three cells are NULL");
    pass("advance_three_levels");
}

/* ================================================================== */
/* 11. the attachment level of the loop, end to end                    */
/* ================================================================== */
static int loop_body(void* ctx, Json* attachmentMap)
{
    int* calls = (int*)ctx;
    ++*calls;
    /* This body is the per-attachment pipeline the total assembly will hand to
     * the loop: classify -> type stub -> createAttachment -> field parse ->
     * 0x28cc68 add.  The r7 name it passes on is the attachment map's +0x1c
     * member key, loaded by the classify level at 0x28c6e8. */
    if (strcmp(attachmentMap->name, "finger") == 0) {
        load.answer_null = 1;                 /* exercise 0x28cf74 in the loop */
        load.fail_error1 = 0;
    } else {
        load.answer_null = 0;
        load.answer = (strcmp(attachmentMap->name, "arm") == 0)
                          ? (void*)&att_region : (void*)&att_mesh;
    }
    return readSkeletonData_skinsCreateRegionAttachment(
        &parser_obj, observed_skin, (const char*)attachmentMap->name, "p",
        attachmentMap, 0u, 0, 0);
}

static void attachment_level_loop(void)
{
    tree_t t;
    skins_glue_cursor c;
    int calls = 0;
    spSkin* skin;
    spSkinEntry* e;

    glue_begin("attachment_level_loop");
    make_attachments();
    build_tree(&t);
    skin = make_skin("sk");
    c.attachment = t.att1;
    c.slot = t.slotA;
    c.skin = t.skinA;

    CK(readSkeletonData_skinsAttachmentLevel(&c, loop_body, &calls)
       == SKINS_GLUE_NEXT_SLOT,
       "the two attachments of slotA are consumed, then the SLOT back edge is reported");
    CK(calls == 2, "two body calls for slotA");
    e = skin->entries;
    CK(e != 0 && e->next != 0 && e->next->next == 0,
       "exactly two real spSkin_addAttachment entries: the loop never adds twice");
    CK(strcmp(e->name, "forearm") == 0 && strcmp(e->next->name, "arm") == 0,
       "head insertion, and the entry name is the JSON member key (r7), not the 'name' property");
    CK(c.slot == t.slotB && c.attachment == 0, "the advance left the cursor on slotB");

    c.attachment = t.att3;                       /* slot head 0x28c6d8 */
    CK(readSkeletonData_skinsAttachmentLevel(&c, loop_body, &calls)
       == SKINS_GLUE_NEXT_SKIN,
       "slotB holds one attachment whose createAttachment is silently skipped");
    CK(calls == 3, "the skipped attachment still consumed one body call");
    CK(skin->entries == e && skin->entries->next->next == 0,
       "the skipped attachment was NOT added: still two entries");
    CK(c.skin == t.skinB, "and the skin back edge is the one to take");

    c.slot = t.slotC;                            /* skin head 0x28c664 */
    c.attachment = t.att4;
    CK(readSkeletonData_skinsAttachmentLevel(&c, loop_body, &calls)
       == SKINS_GLUE_NEXT_DONE, "the last skin ends the three-level walk");
    CK(calls == 4 && c.attachment == 0 && c.slot == 0 && c.skin == 0,
       "four body calls in list order, all cells NULL at the end");
    CK(skin->entries != e && strcmp(skin->entries->name, "toe") == 0,
       "the last skin's boundingbox attachment is added at the head");
    pass("attachment_level_loop");
}

/* ================================================================== */
/* 12..14. the three "Target ..." tails                                */
/* ================================================================== */
typedef struct { char pad[0x1c]; const char* name; } fake_named;

static void tail_common(const char* id, int which, const char* literal)
{
    static fake_named target;
    spSkeletonData* data;
    Json* root;
    Json* child;
    char want[128];
    int rc;

    glue_begin(id);
    target.name = "missing-name";
    data = spSkeletonData_create();
    root = node("root");
    child = node("child");
    add(root, child);

    if (which == 0)
        rc = readSkeletonData_ikTargetNotFoundTail(&parser_obj, root, data, &target);
    else if (which == 1)
        rc = readSkeletonData_transformTargetNotFoundTail(&parser_obj, root, data, &target);
    else
        rc = readSkeletonData_pathTargetSlotNotFoundTail(&parser_obj, root, data, &target);

    strcpy(want, literal);
    strncat(want, "missing-name", 100);
    CK(rc == (int)(intptr_t)&target,
       "the tail returns r4 (0x28cf60/0x28d168/0x28d194 mov r0,r4)");
    CK(report_count == 1 && strcmp(reported, want) == 0,
       "the message is the exact literal plus the [r4+0x1c] argument");
    CK(parser_obj.error != 0 && strcmp((char*)(uintptr_t)parser_obj.error, want) == 0,
       "parser->error holds the same formatted text");
    CK(free_hits(data) == 1, "spSkeletonData_dispose(data) ran exactly once");
    CK(free_hits(root) == 1 && free_hits(child) == 1,
       "the setError json argument is [sp,#0x24]: the whole root tree is disposed");
    CK(free_slot(data) < free_slot(root),
       "dispose(data) precedes setError(root) (0x28cf44 < 0x28cf5c, etc.)");
    CK(alloc_count(90u) == 1, "one line-90 error copy");
}

static void ik_target_not_found_tail(void)
{
    tail_common("ik_target_not_found_tail", 0, "Target bone not found: ");
    pass("ik_target_not_found_tail");
}

static void transform_target_not_found_tail(void)
{
    tail_common("transform_target_not_found_tail", 1, "Target bone not found: ");
    pass("transform_target_not_found_tail");
}

static void path_target_slot_not_found_tail(void)
{
    tail_common("path_target_slot_not_found_tail", 2, "Target slot not found: ");
    pass("path_target_slot_not_found_tail");
}

/* ================================================================== */
/* 15. the argument is read through r4 at +0x1c                        */
/* ================================================================== */
static void tail_argument_through_r4(void)
{
    static fake_named a, b;
    spSkeletonData* data;

    glue_begin("tail_argument_through_r4");
    a.name = "alpha";
    b.name = "beta";
    data = spSkeletonData_create();
    Json* root = node("root");

    (void)readSkeletonData_ikTargetNotFoundTail(&parser_obj, root, data, &a);
    CK(strcmp(reported, "Target bone not found: alpha") == 0,
       "the same literal with a different r4 record yields a different argument");

    glue_begin("tail_argument_through_r4:beta");
    data = spSkeletonData_create();
    root = node("root");
    (void)readSkeletonData_pathTargetSlotNotFoundTail(&parser_obj, root, data, &b);
    CK(strcmp(reported, "Target slot not found: beta") == 0,
       "0x28d18c ldr r3,[r4,#0x1c] reads offset 0x1c of the injected record");
    CK(*(const char* const*)((const char*)&b + 0x1c) == b.name,
       "the record really stores its name word at +0x1c, the offset the tail loads");
    pass("tail_argument_through_r4");
}

void _start(void)
{
    test = "startup";
    init_heap();
    fixture_install_error_reporter();
    create_args_five_pointer();
    type_stub_five_landings();
    stored_type_table();
    stored_type_out_of_range();
    null_loader_silent_skip();
    loader_error_pair_report();
    loader_error_pair_null_arg();
    add_attachment_real_queue();
    add_precedes_advance();
    advance_three_levels();
    attachment_level_loop();
    ik_target_not_found_tail();
    transform_target_not_found_tail();
    path_target_slot_not_found_tail();
    tail_argument_through_r4();
    out("SUMMARY all declared skins glue contracts passed\n");
    quit(0);
}
