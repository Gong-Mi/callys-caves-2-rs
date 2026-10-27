/* generated from CODE 498 (gml_Object_obj_iapmenu_Create_0), source start 4690904, end 4692848. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0498(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    /* @4690904 load */
    /* @4690912 constant */
    /* @4690916 cmp */
    /* @4690920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4691228;
    /* @4690924 constant */
    /* @4690928 cast */
    /* @4690932 call */
    GM_SITE(vm, 498, 4690932);
    /* @4690940 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4690944 constant */
    /* @4690948 cast */
    /* @4690952 constant */
    /* @4690956 constant */
    /* @4690960 load */
    /* @4690968 constant */
    /* @4690972 add */
    /* @4690976 constant */
    /* @4690980 constant */
    /* @4690984 load */
    /* @4690992 constant */
    /* @4690996 add */
    /* @4691000 call */
    GM_SITE(vm, 498, 4691000);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(120));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(100));
    /* @4691008 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, v2, VAL(120)));
    /* @4691012 constant */
    /* @4691016 cast */
    /* @4691020 constant */
    /* @4691024 constant */
    /* @4691028 load */
    /* @4691036 constant */
    /* @4691040 add */
    /* @4691044 constant */
    /* @4691048 constant */
    /* @4691052 load */
    /* @4691060 constant */
    /* @4691064 add */
    /* @4691068 call */
    GM_SITE(vm, 498, 4691068);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(270));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4691076 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, v4, VAL(108)));
    /* @4691080 constant */
    /* @4691084 cast */
    /* @4691088 constant */
    /* @4691092 constant */
    /* @4691096 load */
    /* @4691104 constant */
    /* @4691108 add */
    /* @4691112 constant */
    /* @4691116 constant */
    /* @4691120 load */
    /* @4691128 constant */
    /* @4691132 add */
    /* @4691136 call */
    GM_SITE(vm, 498, 4691136);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4691144 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v5, v6, VAL(121)));
    /* @4691148 constant */
    /* @4691152 cast */
    /* @4691156 call */
    GM_SITE(vm, 498, 4691156);
    /* @4691164 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4691168 constant */
    /* @4691172 cast */
    /* @4691176 call */
    GM_SITE(vm, 498, 4691176);
    /* @4691184 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4691188 constant */
    /* @4691192 cast */
    /* @4691196 call */
    GM_SITE(vm, 498, 4691196);
    /* @4691204 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4691208 constant */
    /* @4691212 cast */
    /* @4691216 call */
    GM_SITE(vm, 498, 4691216);
    /* @4691224 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4691228: ;
    /* @4691228 load */
    /* @4691236 constant */
    /* @4691240 cmp */
    /* @4691244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4691552;
    /* @4691248 constant */
    /* @4691252 cast */
    /* @4691256 call */
    GM_SITE(vm, 498, 4691256);
    /* @4691264 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4691268 constant */
    /* @4691272 cast */
    /* @4691276 constant */
    /* @4691280 constant */
    /* @4691284 load */
    /* @4691292 constant */
    /* @4691296 add */
    /* @4691300 constant */
    /* @4691304 constant */
    /* @4691308 load */
    /* @4691316 constant */
    /* @4691320 add */
    /* @4691324 call */
    GM_SITE(vm, 498, 4691324);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(10));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(100));
    /* @4691332 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v7, v8, VAL(120)));
    /* @4691336 constant */
    /* @4691340 cast */
    /* @4691344 constant */
    /* @4691348 constant */
    /* @4691352 load */
    /* @4691360 constant */
    /* @4691364 add */
    /* @4691368 constant */
    /* @4691372 constant */
    /* @4691376 load */
    /* @4691384 constant */
    /* @4691388 add */
    /* @4691392 call */
    GM_SITE(vm, 498, 4691392);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(220));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4691400 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v9, v10, VAL(108)));
    /* @4691404 constant */
    /* @4691408 cast */
    /* @4691412 constant */
    /* @4691416 constant */
    /* @4691420 load */
    /* @4691428 constant */
    /* @4691432 add */
    /* @4691436 constant */
    /* @4691440 constant */
    /* @4691444 load */
    /* @4691452 constant */
    /* @4691456 add */
    /* @4691460 call */
    GM_SITE(vm, 498, 4691460);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(30));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4691468 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v11, v12, VAL(121)));
    /* @4691472 constant */
    /* @4691476 cast */
    /* @4691480 call */
    GM_SITE(vm, 498, 4691480);
    /* @4691488 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4691492 constant */
    /* @4691496 cast */
    /* @4691500 call */
    GM_SITE(vm, 498, 4691500);
    /* @4691508 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4691512 constant */
    /* @4691516 cast */
    /* @4691520 call */
    GM_SITE(vm, 498, 4691520);
    /* @4691528 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4691532 constant */
    /* @4691536 cast */
    /* @4691540 call */
    GM_SITE(vm, 498, 4691540);
    /* @4691548 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4691552: ;
    /* @4691552 load */
    /* @4691560 constant */
    /* @4691564 cmp */
    /* @4691568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4691876;
    /* @4691572 constant */
    /* @4691576 cast */
    /* @4691580 call */
    GM_SITE(vm, 498, 4691580);
    /* @4691588 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4691592 constant */
    /* @4691596 cast */
    /* @4691600 constant */
    /* @4691604 constant */
    /* @4691608 load */
    /* @4691616 constant */
    /* @4691620 add */
    /* @4691624 constant */
    /* @4691628 constant */
    /* @4691632 load */
    /* @4691640 constant */
    /* @4691644 add */
    /* @4691648 call */
    GM_SITE(vm, 498, 4691648);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(150));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(180));
    /* @4691656 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v13, v14, VAL(120)));
    /* @4691660 constant */
    /* @4691664 cast */
    /* @4691668 constant */
    /* @4691672 constant */
    /* @4691676 load */
    /* @4691684 constant */
    /* @4691688 add */
    /* @4691692 constant */
    /* @4691696 constant */
    /* @4691700 load */
    /* @4691708 constant */
    /* @4691712 add */
    /* @4691716 call */
    GM_SITE(vm, 498, 4691716);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(270));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(190));
    /* @4691724 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v15, v16, VAL(108)));
    /* @4691728 constant */
    /* @4691732 cast */
    /* @4691736 constant */
    /* @4691740 constant */
    /* @4691744 load */
    /* @4691752 constant */
    /* @4691756 add */
    /* @4691760 constant */
    /* @4691764 constant */
    /* @4691768 load */
    /* @4691776 constant */
    /* @4691780 add */
    /* @4691784 call */
    GM_SITE(vm, 498, 4691784);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(190));
    /* @4691792 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v17, v18, VAL(121)));
    /* @4691796 constant */
    /* @4691800 cast */
    /* @4691804 call */
    GM_SITE(vm, 498, 4691804);
    /* @4691812 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4691816 constant */
    /* @4691820 cast */
    /* @4691824 call */
    GM_SITE(vm, 498, 4691824);
    /* @4691832 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4691836 constant */
    /* @4691840 cast */
    /* @4691844 call */
    GM_SITE(vm, 498, 4691844);
    /* @4691852 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4691856 constant */
    /* @4691860 cast */
    /* @4691864 call */
    GM_SITE(vm, 498, 4691864);
    /* @4691872 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4691876: ;
    /* @4691876 load */
    /* @4691884 constant */
    /* @4691888 cmp */
    /* @4691892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4692200;
    /* @4691896 constant */
    /* @4691900 cast */
    /* @4691904 call */
    GM_SITE(vm, 498, 4691904);
    /* @4691912 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4691916 constant */
    /* @4691920 cast */
    /* @4691924 constant */
    /* @4691928 constant */
    /* @4691932 load */
    /* @4691940 constant */
    /* @4691944 add */
    /* @4691948 constant */
    /* @4691952 constant */
    /* @4691956 load */
    /* @4691964 constant */
    /* @4691968 add */
    /* @4691972 call */
    GM_SITE(vm, 498, 4691972);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(150));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(180));
    /* @4691980 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v19, v20, VAL(120)));
    /* @4691984 constant */
    /* @4691988 cast */
    /* @4691992 constant */
    /* @4691996 constant */
    /* @4692000 load */
    /* @4692008 constant */
    /* @4692012 add */
    /* @4692016 constant */
    /* @4692020 constant */
    /* @4692024 load */
    /* @4692032 constant */
    /* @4692036 add */
    /* @4692040 call */
    GM_SITE(vm, 498, 4692040);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(270));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(190));
    /* @4692048 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v21, v22, VAL(108)));
    /* @4692052 constant */
    /* @4692056 cast */
    /* @4692060 constant */
    /* @4692064 constant */
    /* @4692068 load */
    /* @4692076 constant */
    /* @4692080 add */
    /* @4692084 constant */
    /* @4692088 constant */
    /* @4692092 load */
    /* @4692100 constant */
    /* @4692104 add */
    /* @4692108 call */
    GM_SITE(vm, 498, 4692108);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(190));
    /* @4692116 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v23, v24, VAL(121)));
    /* @4692120 constant */
    /* @4692124 cast */
    /* @4692128 call */
    GM_SITE(vm, 498, 4692128);
    /* @4692136 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4692140 constant */
    /* @4692144 cast */
    /* @4692148 call */
    GM_SITE(vm, 498, 4692148);
    /* @4692156 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4692160 constant */
    /* @4692164 cast */
    /* @4692168 call */
    GM_SITE(vm, 498, 4692168);
    /* @4692176 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4692180 constant */
    /* @4692184 cast */
    /* @4692188 call */
    GM_SITE(vm, 498, 4692188);
    /* @4692196 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4692200: ;
    /* @4692200 load */
    /* @4692208 constant */
    /* @4692212 cmp */
    /* @4692216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4692524;
    /* @4692220 constant */
    /* @4692224 cast */
    /* @4692228 call */
    GM_SITE(vm, 498, 4692228);
    /* @4692236 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4692240 constant */
    /* @4692244 cast */
    /* @4692248 constant */
    /* @4692252 constant */
    /* @4692256 load */
    /* @4692264 constant */
    /* @4692268 add */
    /* @4692272 constant */
    /* @4692276 constant */
    /* @4692280 load */
    /* @4692288 constant */
    /* @4692292 add */
    /* @4692296 call */
    GM_SITE(vm, 498, 4692296);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(120));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(100));
    /* @4692304 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v25, v26, VAL(120)));
    /* @4692308 constant */
    /* @4692312 cast */
    /* @4692316 constant */
    /* @4692320 constant */
    /* @4692324 load */
    /* @4692332 constant */
    /* @4692336 add */
    /* @4692340 constant */
    /* @4692344 constant */
    /* @4692348 load */
    /* @4692356 constant */
    /* @4692360 add */
    /* @4692364 call */
    GM_SITE(vm, 498, 4692364);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(270));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4692372 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v27, v28, VAL(108)));
    /* @4692376 constant */
    /* @4692380 cast */
    /* @4692384 constant */
    /* @4692388 constant */
    /* @4692392 load */
    /* @4692400 constant */
    /* @4692404 add */
    /* @4692408 constant */
    /* @4692412 constant */
    /* @4692416 load */
    /* @4692424 constant */
    /* @4692428 add */
    /* @4692432 call */
    GM_SITE(vm, 498, 4692432);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4692440 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v29, v30, VAL(121)));
    /* @4692444 constant */
    /* @4692448 cast */
    /* @4692452 call */
    GM_SITE(vm, 498, 4692452);
    /* @4692460 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4692464 constant */
    /* @4692468 cast */
    /* @4692472 call */
    GM_SITE(vm, 498, 4692472);
    /* @4692480 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4692484 constant */
    /* @4692488 cast */
    /* @4692492 call */
    GM_SITE(vm, 498, 4692492);
    /* @4692500 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4692504 constant */
    /* @4692508 cast */
    /* @4692512 call */
    GM_SITE(vm, 498, 4692512);
    /* @4692520 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4692524: ;
    /* @4692524 load */
    /* @4692532 constant */
    /* @4692536 cmp */
    /* @4692540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4692848;
    /* @4692544 constant */
    /* @4692548 cast */
    /* @4692552 call */
    GM_SITE(vm, 498, 4692552);
    /* @4692560 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(0)));
    /* @4692564 constant */
    /* @4692568 cast */
    /* @4692572 constant */
    /* @4692576 constant */
    /* @4692580 load */
    /* @4692588 constant */
    /* @4692592 add */
    /* @4692596 constant */
    /* @4692600 constant */
    /* @4692604 load */
    /* @4692612 constant */
    /* @4692616 add */
    /* @4692620 call */
    GM_SITE(vm, 498, 4692620);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(120));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(100));
    /* @4692628 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v31, v32, VAL(120)));
    /* @4692632 constant */
    /* @4692636 cast */
    /* @4692640 constant */
    /* @4692644 constant */
    /* @4692648 load */
    /* @4692656 constant */
    /* @4692660 add */
    /* @4692664 constant */
    /* @4692668 constant */
    /* @4692672 load */
    /* @4692680 constant */
    /* @4692684 add */
    /* @4692688 call */
    GM_SITE(vm, 498, 4692688);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(270));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    /* @4692696 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v33, v34, VAL(108)));
    /* @4692700 constant */
    /* @4692704 cast */
    /* @4692708 constant */
    /* @4692712 constant */
    /* @4692716 load */
    /* @4692724 constant */
    /* @4692728 add */
    /* @4692732 constant */
    /* @4692736 constant */
    /* @4692740 load */
    /* @4692748 constant */
    /* @4692752 add */
    /* @4692756 call */
    GM_SITE(vm, 498, 4692756);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    /* @4692764 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v35, v36, VAL(121)));
    /* @4692768 constant */
    /* @4692772 cast */
    /* @4692776 call */
    GM_SITE(vm, 498, 4692776);
    /* @4692784 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(120)));
    /* @4692788 constant */
    /* @4692792 cast */
    /* @4692796 call */
    GM_SITE(vm, 498, 4692796);
    /* @4692804 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(119)));
    /* @4692808 constant */
    /* @4692812 cast */
    /* @4692816 call */
    GM_SITE(vm, 498, 4692816);
    /* @4692824 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4692828 constant */
    /* @4692832 cast */
    /* @4692836 call */
    GM_SITE(vm, 498, 4692836);
    /* @4692844 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(121)));
    L_4692848: ;
    return;
}
