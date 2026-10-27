/* generated from CODE 699 (gml_Object_obj_final_Draw_0), source start 5018436, end 5020848. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0699(GmVM* vm) {
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
    /* @5018436 load */
    /* @5018444 constant */
    /* @5018448 cmp */
    /* @5018452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_5019704;
    /* @5018456 load */
    /* @5018464 constant */
    /* @5018468 cmp */
    /* @5018472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5018632;
    /* @5018476 constant */
    /* @5018480 load */
    /* @5018488 cast */
    /* @5018492 load */
    /* @5018500 constant */
    /* @5018504 sub */
    /* @5018508 constant */
    /* @5018512 load */
    /* @5018520 cast */
    /* @5018524 load */
    /* @5018532 constant */
    /* @5018536 sub */
    /* @5018540 constant */
    /* @5018544 cast */
    /* @5018548 constant */
    /* @5018552 cast */
    /* @5018556 call */
    GM_SITE(vm, 699, 5018556);
    /* @5018564 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(176), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @5018568 constant */
    /* @5018572 load */
    /* @5018580 cast */
    /* @5018584 load */
    /* @5018592 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5018600 constant */
    /* @5018604 load */
    /* @5018612 cast */
    /* @5018616 load */
    /* @5018624 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5018632: ;
    /* @5018632 load */
    /* @5018640 constant */
    /* @5018644 cmp */
    /* @5018648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5018848;
    /* @5018652 constant */
    /* @5018656 cast */
    /* @5018660 constant */
    /* @5018664 cast */
    /* @5018668 constant */
    /* @5018672 cast */
    /* @5018676 constant */
    /* @5018688 cast */
    /* @5018692 constant */
    /* @5018704 cast */
    /* @5018708 constant */
    /* @5018712 load */
    /* @5018720 cast */
    /* @5018724 load */
    /* @5018732 constant */
    /* @5018736 load */
    /* @5018744 cast */
    /* @5018748 load */
    /* @5018756 constant */
    /* @5018760 cast */
    /* @5018764 constant */
    /* @5018768 cast */
    /* @5018772 call */
    GM_SITE(vm, 699, 5018772);
    /* @5018780 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(176), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @5018784 constant */
    /* @5018788 load */
    /* @5018796 cast */
    /* @5018800 load */
    /* @5018808 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5018816 constant */
    /* @5018820 load */
    /* @5018828 cast */
    /* @5018832 load */
    /* @5018840 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5018848: ;
    /* @5018848 load */
    /* @5018856 constant */
    /* @5018860 cmp */
    /* @5018864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5019072;
    /* @5018868 constant */
    /* @5018872 cast */
    /* @5018876 constant */
    /* @5018880 cast */
    /* @5018884 constant */
    /* @5018888 cast */
    /* @5018892 constant */
    /* @5018904 cast */
    /* @5018908 constant */
    /* @5018920 cast */
    /* @5018924 constant */
    /* @5018928 load */
    /* @5018936 cast */
    /* @5018940 load */
    /* @5018948 constant */
    /* @5018952 load */
    /* @5018960 cast */
    /* @5018964 load */
    /* @5018972 constant */
    /* @5018976 sub */
    /* @5018980 constant */
    /* @5018984 cast */
    /* @5018988 constant */
    /* @5018992 cast */
    /* @5018996 call */
    GM_SITE(vm, 699, 5018996);
    /* @5019004 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(176), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(35)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5019008 constant */
    /* @5019012 load */
    /* @5019020 cast */
    /* @5019024 load */
    /* @5019032 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019040 constant */
    /* @5019044 load */
    /* @5019052 cast */
    /* @5019056 load */
    /* @5019064 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5019072: ;
    /* @5019072 load */
    /* @5019080 constant */
    /* @5019084 cmp */
    /* @5019088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5019296;
    /* @5019092 constant */
    /* @5019096 cast */
    /* @5019100 constant */
    /* @5019104 cast */
    /* @5019108 constant */
    /* @5019112 cast */
    /* @5019116 constant */
    /* @5019128 cast */
    /* @5019132 constant */
    /* @5019144 cast */
    /* @5019148 constant */
    /* @5019152 load */
    /* @5019160 cast */
    /* @5019164 load */
    /* @5019172 constant */
    /* @5019176 load */
    /* @5019184 cast */
    /* @5019188 load */
    /* @5019196 constant */
    /* @5019200 sub */
    /* @5019204 constant */
    /* @5019208 cast */
    /* @5019212 constant */
    /* @5019216 cast */
    /* @5019220 call */
    GM_SITE(vm, 699, 5019220);
    /* @5019228 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(176), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(35)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @5019232 constant */
    /* @5019236 load */
    /* @5019244 cast */
    /* @5019248 load */
    /* @5019256 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019264 constant */
    /* @5019268 load */
    /* @5019276 cast */
    /* @5019280 load */
    /* @5019288 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5019296: ;
    /* @5019296 load */
    /* @5019304 constant */
    /* @5019308 cmp */
    /* @5019312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5019472;
    /* @5019316 constant */
    /* @5019320 load */
    /* @5019328 cast */
    /* @5019332 load */
    /* @5019340 constant */
    /* @5019344 sub */
    /* @5019348 constant */
    /* @5019352 load */
    /* @5019360 cast */
    /* @5019364 load */
    /* @5019372 constant */
    /* @5019376 sub */
    /* @5019380 constant */
    /* @5019384 cast */
    /* @5019388 constant */
    /* @5019392 cast */
    /* @5019396 call */
    GM_SITE(vm, 699, 5019396);
    /* @5019404 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(176), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @5019408 constant */
    /* @5019412 load */
    /* @5019420 cast */
    /* @5019424 load */
    /* @5019432 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019440 constant */
    /* @5019444 load */
    /* @5019452 cast */
    /* @5019456 load */
    /* @5019464 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5019472: ;
    /* @5019472 load */
    /* @5019480 constant */
    /* @5019484 cmp */
    /* @5019488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5019704;
    /* @5019492 constant */
    /* @5019496 cast */
    /* @5019500 constant */
    /* @5019504 cast */
    /* @5019508 constant */
    /* @5019512 cast */
    /* @5019516 constant */
    /* @5019528 cast */
    /* @5019532 constant */
    /* @5019544 cast */
    /* @5019548 constant */
    /* @5019552 load */
    /* @5019560 cast */
    /* @5019564 load */
    /* @5019572 constant */
    /* @5019576 sub */
    /* @5019580 constant */
    /* @5019584 load */
    /* @5019592 cast */
    /* @5019596 load */
    /* @5019604 constant */
    /* @5019608 sub */
    /* @5019612 constant */
    /* @5019616 cast */
    /* @5019620 constant */
    /* @5019624 cast */
    /* @5019628 call */
    GM_SITE(vm, 699, 5019628);
    /* @5019636 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(176), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10)), VAL(1.1), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @5019640 constant */
    /* @5019644 load */
    /* @5019652 cast */
    /* @5019656 load */
    /* @5019664 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019672 constant */
    /* @5019676 load */
    /* @5019684 cast */
    /* @5019688 load */
    /* @5019696 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    L_5019704: ;
    /* @5019704 load */
    /* @5019712 constant */
    /* @5019716 cmp */
    /* @5019720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_5019724;
    L_5019724: ;
    /* @5019724 load */
    /* @5019732 constant */
    /* @5019736 cmp */
    /* @5019740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel3") == VAL(1)))) goto L_5020848;
    /* @5019744 load */
    /* @5019752 constant */
    /* @5019756 cmp */
    /* @5019760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_5019960;
    /* @5019764 constant */
    /* @5019768 load */
    /* @5019776 cast */
    /* @5019780 load */
    /* @5019788 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019796 constant */
    /* @5019800 load */
    /* @5019808 cast */
    /* @5019812 load */
    /* @5019820 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5019828 load */
    /* @5019836 constant */
    /* @5019840 cmp */
    /* @5019844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5019960;
    /* @5019848 constant */
    /* @5019852 cast */
    /* @5019856 call */
    GM_SITE(vm, 699, 5019856);
    /* @5019864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5019868 constant */
    /* @5019872 cast */
    /* @5019876 call */
    GM_SITE(vm, 699, 5019876);
    /* @5019884 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5019888 string */
    /* @5019896 cast */
    /* @5019900 constant */
    /* @5019904 constant */
    /* @5019908 load */
    /* @5019916 constant */
    /* @5019920 add */
    /* @5019924 constant */
    /* @5019928 constant */
    /* @5019932 load */
    /* @5019940 constant */
    /* @5019944 add */
    /* @5019948 call */
    GM_SITE(vm, 699, 5019948);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(140));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(220));
    /* @5019956 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(743)));
    L_5019960: ;
    /* @5019960 load */
    /* @5019968 constant */
    /* @5019972 cmp */
    /* @5019976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_5020112;
    /* @5019980 load */
    /* @5019988 constant */
    /* @5019992 cmp */
    /* @5019996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5020112;
    /* @5020000 constant */
    /* @5020004 cast */
    /* @5020008 call */
    GM_SITE(vm, 699, 5020008);
    /* @5020016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5020020 constant */
    /* @5020024 cast */
    /* @5020028 call */
    GM_SITE(vm, 699, 5020028);
    /* @5020036 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5020040 string */
    /* @5020048 cast */
    /* @5020052 constant */
    /* @5020056 constant */
    /* @5020060 load */
    /* @5020068 constant */
    /* @5020072 add */
    /* @5020076 constant */
    /* @5020080 constant */
    /* @5020084 load */
    /* @5020092 constant */
    /* @5020096 add */
    /* @5020100 call */
    GM_SITE(vm, 699, 5020100);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @5020108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, v4, STR_REF(743)));
    L_5020112: ;
    /* @5020112 load */
    /* @5020120 constant */
    /* @5020124 cmp */
    /* @5020128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_5020264;
    /* @5020132 load */
    /* @5020140 constant */
    /* @5020144 cmp */
    /* @5020148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5020264;
    /* @5020152 constant */
    /* @5020156 cast */
    /* @5020160 call */
    GM_SITE(vm, 699, 5020160);
    /* @5020168 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5020172 constant */
    /* @5020176 cast */
    /* @5020180 call */
    GM_SITE(vm, 699, 5020180);
    /* @5020188 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5020192 string */
    /* @5020200 cast */
    /* @5020204 constant */
    /* @5020208 constant */
    /* @5020212 load */
    /* @5020220 constant */
    /* @5020224 add */
    /* @5020228 constant */
    /* @5020232 constant */
    /* @5020236 load */
    /* @5020244 constant */
    /* @5020248 add */
    /* @5020252 call */
    GM_SITE(vm, 699, 5020252);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(340));
    /* @5020260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_5020264: ;
    /* @5020264 load */
    /* @5020272 constant */
    /* @5020276 cmp */
    /* @5020280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_5020416;
    /* @5020284 load */
    /* @5020292 constant */
    /* @5020296 cmp */
    /* @5020300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5020416;
    /* @5020304 constant */
    /* @5020308 cast */
    /* @5020312 call */
    GM_SITE(vm, 699, 5020312);
    /* @5020320 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5020324 constant */
    /* @5020328 cast */
    /* @5020332 call */
    GM_SITE(vm, 699, 5020332);
    /* @5020340 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5020344 string */
    /* @5020352 cast */
    /* @5020356 constant */
    /* @5020360 constant */
    /* @5020364 load */
    /* @5020372 constant */
    /* @5020376 add */
    /* @5020380 constant */
    /* @5020384 constant */
    /* @5020388 load */
    /* @5020396 constant */
    /* @5020400 add */
    /* @5020404 call */
    GM_SITE(vm, 699, 5020404);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(340));
    /* @5020412 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, v8, STR_REF(743)));
    L_5020416: ;
    /* @5020416 load */
    /* @5020424 constant */
    /* @5020428 cmp */
    /* @5020432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_5020632;
    /* @5020436 constant */
    /* @5020440 load */
    /* @5020448 cast */
    /* @5020452 load */
    /* @5020460 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5020468 constant */
    /* @5020472 load */
    /* @5020480 cast */
    /* @5020484 load */
    /* @5020492 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5020500 load */
    /* @5020508 constant */
    /* @5020512 cmp */
    /* @5020516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5020632;
    /* @5020520 constant */
    /* @5020524 cast */
    /* @5020528 call */
    GM_SITE(vm, 699, 5020528);
    /* @5020536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5020540 constant */
    /* @5020544 cast */
    /* @5020548 call */
    GM_SITE(vm, 699, 5020548);
    /* @5020556 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5020560 string */
    /* @5020568 cast */
    /* @5020572 constant */
    /* @5020576 constant */
    /* @5020580 load */
    /* @5020588 constant */
    /* @5020592 add */
    /* @5020596 constant */
    /* @5020600 constant */
    /* @5020604 load */
    /* @5020612 constant */
    /* @5020616 add */
    /* @5020620 call */
    GM_SITE(vm, 699, 5020620);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(140));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(220));
    /* @5020628 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v9, v10, STR_REF(743)));
    L_5020632: ;
    /* @5020632 load */
    /* @5020640 constant */
    /* @5020644 cmp */
    /* @5020648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_5020848;
    /* @5020652 constant */
    /* @5020656 load */
    /* @5020664 cast */
    /* @5020668 load */
    /* @5020676 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5020684 constant */
    /* @5020688 load */
    /* @5020696 cast */
    /* @5020700 load */
    /* @5020708 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @5020716 load */
    /* @5020724 constant */
    /* @5020728 cmp */
    /* @5020732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5020848;
    /* @5020736 constant */
    /* @5020740 cast */
    /* @5020744 call */
    GM_SITE(vm, 699, 5020744);
    /* @5020752 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @5020756 constant */
    /* @5020760 cast */
    /* @5020764 call */
    GM_SITE(vm, 699, 5020764);
    /* @5020772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(0)));
    /* @5020776 string */
    /* @5020784 cast */
    /* @5020788 constant */
    /* @5020792 constant */
    /* @5020796 load */
    /* @5020804 constant */
    /* @5020808 add */
    /* @5020812 constant */
    /* @5020816 constant */
    /* @5020820 load */
    /* @5020828 constant */
    /* @5020832 add */
    /* @5020836 call */
    GM_SITE(vm, 699, 5020836);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(150));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(220));
    /* @5020844 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_5020848: ;
    return;
}
