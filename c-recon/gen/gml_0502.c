/* generated from CODE 502 (gml_Object_obj_poisoniap_Other_66), source start 4694028, end 4694744. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0502(GmVM* vm) {
    Val loc_val;
    Val p4694108_0;
    Val p4694552_0;
    Val p4694708_0;
    Val loc_map;
    Val loc_purchase_id;
    Val v1;
    Val p4694528_0;
    Val loc_product_id;
    Val p4694332_0;
    Val p4694332_1;
    Val p4694524_0;
    Val p4694524_1;
    Val v2;
    Val p4694684_0;
    /* @4694028 string */
    /* @4694036 cast */
    /* @4694040 load */
    /* @4694048 call */
    GM_SITE(vm, 502, 4694048);
    /* @4694056 store_local */
    loc_val = GM_CALL(vm, "ds_map_find_value", 2, GM_READ(vm, -1, "iap_data"), STR_REF(92));
    /* @4694064 load_local */
    /* @4694072 dup */
    /* @4694076 constant */
    /* @4694080 cmp */
    /* @4694084 bt */
    p4694108_0 = loc_val;
    if (TRUTH(NUMBOOL(loc_val == VAL(2)))) goto L_4694108;
    /* @4694088 dup */
    /* @4694092 constant */
    /* @4694096 cmp */
    /* @4694100 bt */
    p4694552_0 = loc_val;
    if (TRUTH(NUMBOOL(loc_val == VAL(3)))) goto L_4694552;
    /* @4694104 b */
    p4694708_0 = loc_val;
    goto L_4694708;
    L_4694108: ;
    /* @4694108 call */
    GM_SITE(vm, 502, 4694108);
    /* @4694116 store_local */
    loc_map = GM_CALL(vm, "ds_map_create", 0);
    /* @4694124 string */
    /* @4694132 cast */
    /* @4694136 load */
    /* @4694144 call */
    GM_SITE(vm, 502, 4694144);
    /* @4694152 store_local */
    loc_purchase_id = GM_CALL(vm, "ds_map_find_value", 2, GM_READ(vm, -1, "iap_data"), STR_REF(980));
    /* @4694160 load_local */
    /* @4694168 load_local */
    /* @4694176 call */
    GM_SITE(vm, 502, 4694176);
    /* @4694184 popz */
    (void)(GM_CALL(vm, "iap_purchase_details", 2, loc_purchase_id, loc_map));
    /* @4694188 string */
    /* @4694196 cast */
    /* @4694200 load_local */
    /* @4694208 call */
    GM_SITE(vm, 502, 4694208);
    /* @4694216 constant */
    /* @4694220 cmp */
    /* @4694224 bf */
    v1 = NUMBOOL(GM_CALL(vm, "ds_map_find_value", 2, loc_map, STR_REF(983)) == VAL(0));
    p4694528_0 = p4694108_0;
    if (!TRUTH(v1)) goto L_4694528;
    /* @4694228 string */
    /* @4694236 cast */
    /* @4694240 load_local */
    /* @4694248 call */
    GM_SITE(vm, 502, 4694248);
    /* @4694256 store_local */
    loc_product_id = GM_CALL(vm, "ds_map_find_value", 2, loc_map, STR_REF(984));
    /* @4694264 constant */
    /* @4694268 cast */
    /* @4694272 load_local */
    /* @4694280 load */
    /* @4694288 call */
    GM_SITE(vm, 502, 4694288);
    /* @4694296 popz */
    (void)(GM_CALL(vm, "ds_map_replace", 3, GM_READ(vm, -5, "purchaseMap"), loc_product_id, VAL(1)));
    /* @4694300 load_local */
    /* @4694308 dup */
    /* @4694312 string */
    /* @4694320 cmp */
    /* @4694324 bt */
    p4694332_0 = p4694108_0;
    p4694332_1 = loc_product_id;
    if (TRUTH(NUMBOOL(loc_product_id == STR_REF(971)))) goto L_4694332;
    /* @4694328 b */
    p4694524_0 = p4694108_0;
    p4694524_1 = loc_product_id;
    goto L_4694524;
    L_4694332: ;
    /* @4694332 constant */
    /* @4694336 store */
    GM_WRITE(vm, -5, "poisonenabled", VAL(1));
    /* @4694344 constant */
    /* @4694348 store */
    GM_WRITE(vm, -5, "gemdropenabled", VAL(1));
    /* @4694356 string */
    /* @4694364 cast */
    /* @4694368 call */
    GM_SITE(vm, 502, 4694368);
    /* @4694376 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4694380 constant */
    /* @4694384 cast */
    /* @4694388 string */
    /* @4694396 cast */
    /* @4694400 string */
    /* @4694408 cast */
    /* @4694412 call */
    GM_SITE(vm, 502, 4694412);
    /* @4694420 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(166), VAL(1)));
    /* @4694424 constant */
    /* @4694428 cast */
    /* @4694432 string */
    /* @4694440 cast */
    /* @4694444 string */
    /* @4694452 cast */
    /* @4694456 call */
    GM_SITE(vm, 502, 4694456);
    /* @4694464 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(165), VAL(1)));
    /* @4694468 call */
    GM_SITE(vm, 502, 4694468);
    /* @4694476 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4694480 constant */
    /* @4694484 cast */
    /* @4694488 call */
    GM_SITE(vm, 502, 4694488);
    /* @4694496 popz */
    (void)(GM_CALL(vm, "ads_disable", 1, VAL(1)));
    /* @4694500 constant */
    /* @4694504 cast */
    /* @4694508 call */
    GM_SITE(vm, 502, 4694508);
    /* @4694516 popz */
    (void)(GM_CALL(vm, "ads_disable", 1, VAL(0)));
    /* @4694520 b */
    p4694524_0 = p4694332_0;
    p4694524_1 = p4694332_1;
    goto L_4694524;
    L_4694524: ;
    /* @4694524 popz */
    p4694528_0 = p4694524_0;
    L_4694528: ;
    /* @4694528 load_local */
    /* @4694536 call */
    GM_SITE(vm, 502, 4694536);
    /* @4694544 popz */
    (void)(GM_CALL(vm, "ds_map_destroy", 1, loc_map));
    /* @4694548 b */
    p4694708_0 = p4694528_0;
    goto L_4694708;
    L_4694552: ;
    /* @4694552 string */
    /* @4694560 cast */
    /* @4694564 load */
    /* @4694572 call */
    GM_SITE(vm, 502, 4694572);
    /* @4694580 store_local */
    loc_product_id = GM_CALL(vm, "ds_map_find_value", 2, GM_READ(vm, -1, "iap_data"), STR_REF(984));
    /* @4694588 string */
    /* @4694596 cast */
    /* @4694600 load */
    /* @4694608 call */
    GM_SITE(vm, 502, 4694608);
    /* @4694616 cast */
    /* @4694620 bf */
    v2 = BOOL(GM_CALL(vm, "ds_map_find_value", 2, GM_READ(vm, -1, "iap_data"), STR_REF(989)));
    p4694684_0 = p4694552_0;
    if (!TRUTH(v2)) goto L_4694684;
    /* @4694624 constant */
    /* @4694628 cast */
    /* @4694632 load_local */
    /* @4694640 load */
    /* @4694648 call */
    GM_SITE(vm, 502, 4694648);
    /* @4694656 popz */
    (void)(GM_CALL(vm, "ds_map_replace", 3, GM_READ(vm, -5, "purchaseMap"), loc_product_id, VAL(0)));
    /* @4694660 load_local */
    /* @4694668 string */
    /* @4694676 cmp */
    /* @4694680 bf */
    p4694684_0 = p4694552_0;
    if (!TRUTH(NUMBOOL(loc_product_id == STR_REF(971)))) goto L_4694684;
    p4694684_0 = p4694552_0;
    L_4694684: ;
    /* @4694684 load_local */
    /* @4694692 call */
    GM_SITE(vm, 502, 4694692);
    /* @4694700 popz */
    (void)(GM_CALL(vm, "ds_map_destroy", 1, loc_map));
    /* @4694704 b */
    p4694708_0 = p4694684_0;
    goto L_4694708;
    L_4694708: ;
    /* @4694708 popz */
    /* @4694712 string */
    /* @4694720 cast */
    /* @4694724 load */
    /* @4694732 call */
    GM_SITE(vm, 502, 4694732);
    /* @4694740 popz */
    (void)(GM_CALL(vm, "ds_map_secure_save", 2, GM_READ(vm, -5, "purchaseMap"), STR_REF(990)));
    L_4694744: ;
    return;
}
