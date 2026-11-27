/* generated from CODE 373 (gml_Object_obj_muting_Step_0), source start 4446252, end 4450212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0373(GmVM* vm) {
    Val v1;
    /* @4446252 load */
    /* @4446260 constant */
    /* @4446264 add */
    /* @4446268 store */
    v1 = GM_ADD(GM_READ(vm, -1, "frame"), VAL(1));
    GM_WRITE(vm, -1, "frame", v1);
    /* @4446276 load */
    /* @4446284 constant */
    /* @4446288 cmp */
    /* @4446292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "frame") >= VAL(6)))) goto L_4446308;
    /* @4446296 constant */
    /* @4446300 store */
    GM_WRITE(vm, -1, "frame", VAL(0));
    L_4446308: ;
    /* @4446308 load */
    /* @4446316 constant */
    /* @4446320 cmp */
    /* @4446324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4447376;
    /* @4446328 constant */
    /* @4446332 cast */
    /* @4446336 constant */
    /* @4446340 cast */
    /* @4446344 constant */
    /* @4446348 cast */
    /* @4446352 call */
    GM_SITE(vm, 373, 4446352);
    /* @4446360 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(0), VAL(0), VAL(0)));
    /* @4446364 constant */
    /* @4446368 cast */
    /* @4446372 constant */
    /* @4446376 cast */
    /* @4446380 constant */
    /* @4446384 cast */
    /* @4446388 call */
    GM_SITE(vm, 373, 4446388);
    /* @4446396 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(1), VAL(0), VAL(0)));
    /* @4446400 constant */
    /* @4446404 cast */
    /* @4446408 constant */
    /* @4446412 cast */
    /* @4446416 constant */
    /* @4446420 cast */
    /* @4446424 call */
    GM_SITE(vm, 373, 4446424);
    /* @4446432 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(2), VAL(0), VAL(0)));
    /* @4446436 constant */
    /* @4446440 cast */
    /* @4446444 constant */
    /* @4446448 cast */
    /* @4446452 constant */
    /* @4446456 cast */
    /* @4446460 call */
    GM_SITE(vm, 373, 4446460);
    /* @4446468 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(3), VAL(0), VAL(0)));
    /* @4446472 constant */
    /* @4446476 cast */
    /* @4446480 constant */
    /* @4446484 cast */
    /* @4446488 constant */
    /* @4446492 cast */
    /* @4446496 call */
    GM_SITE(vm, 373, 4446496);
    /* @4446504 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(4), VAL(0), VAL(0)));
    /* @4446508 constant */
    /* @4446512 cast */
    /* @4446516 constant */
    /* @4446520 cast */
    /* @4446524 constant */
    /* @4446528 cast */
    /* @4446532 call */
    GM_SITE(vm, 373, 4446532);
    /* @4446540 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(5), VAL(0), VAL(0)));
    /* @4446544 constant */
    /* @4446548 cast */
    /* @4446552 constant */
    /* @4446556 cast */
    /* @4446560 constant */
    /* @4446564 cast */
    /* @4446568 call */
    GM_SITE(vm, 373, 4446568);
    /* @4446576 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(6), VAL(0), VAL(0)));
    /* @4446580 constant */
    /* @4446584 cast */
    /* @4446588 constant */
    /* @4446592 cast */
    /* @4446596 constant */
    /* @4446600 cast */
    /* @4446604 call */
    GM_SITE(vm, 373, 4446604);
    /* @4446612 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(7), VAL(0), VAL(0)));
    /* @4446616 constant */
    /* @4446620 cast */
    /* @4446624 constant */
    /* @4446628 cast */
    /* @4446632 constant */
    /* @4446636 cast */
    /* @4446640 call */
    GM_SITE(vm, 373, 4446640);
    /* @4446648 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(8), VAL(0), VAL(0)));
    /* @4446652 constant */
    /* @4446656 cast */
    /* @4446660 constant */
    /* @4446664 cast */
    /* @4446668 constant */
    /* @4446672 cast */
    /* @4446676 call */
    GM_SITE(vm, 373, 4446676);
    /* @4446684 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(9), VAL(0), VAL(0)));
    /* @4446688 constant */
    /* @4446692 cast */
    /* @4446696 constant */
    /* @4446700 cast */
    /* @4446704 constant */
    /* @4446708 cast */
    /* @4446712 call */
    GM_SITE(vm, 373, 4446712);
    /* @4446720 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(10), VAL(0), VAL(0)));
    /* @4446724 constant */
    /* @4446728 cast */
    /* @4446732 constant */
    /* @4446736 cast */
    /* @4446740 constant */
    /* @4446744 cast */
    /* @4446748 call */
    GM_SITE(vm, 373, 4446748);
    /* @4446756 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(11), VAL(0), VAL(0)));
    /* @4446760 constant */
    /* @4446764 cast */
    /* @4446768 constant */
    /* @4446772 cast */
    /* @4446776 constant */
    /* @4446780 cast */
    /* @4446784 call */
    GM_SITE(vm, 373, 4446784);
    /* @4446792 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(12), VAL(0), VAL(0)));
    /* @4446796 constant */
    /* @4446800 cast */
    /* @4446804 constant */
    /* @4446808 cast */
    /* @4446812 constant */
    /* @4446816 cast */
    /* @4446820 call */
    GM_SITE(vm, 373, 4446820);
    /* @4446828 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(13), VAL(0), VAL(0)));
    /* @4446832 constant */
    /* @4446836 cast */
    /* @4446840 constant */
    /* @4446844 cast */
    /* @4446848 constant */
    /* @4446852 cast */
    /* @4446856 call */
    GM_SITE(vm, 373, 4446856);
    /* @4446864 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(14), VAL(0), VAL(0)));
    /* @4446868 constant */
    /* @4446872 cast */
    /* @4446876 constant */
    /* @4446880 cast */
    /* @4446884 constant */
    /* @4446888 cast */
    /* @4446892 call */
    GM_SITE(vm, 373, 4446892);
    /* @4446900 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(15), VAL(0), VAL(0)));
    /* @4446904 constant */
    /* @4446908 cast */
    /* @4446912 constant */
    /* @4446916 cast */
    /* @4446920 constant */
    /* @4446924 cast */
    /* @4446928 call */
    GM_SITE(vm, 373, 4446928);
    /* @4446936 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(16), VAL(0), VAL(0)));
    /* @4446940 constant */
    /* @4446944 cast */
    /* @4446948 constant */
    /* @4446952 cast */
    /* @4446956 constant */
    /* @4446960 cast */
    /* @4446964 call */
    GM_SITE(vm, 373, 4446964);
    /* @4446972 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(17), VAL(0), VAL(0)));
    /* @4446976 constant */
    /* @4446980 cast */
    /* @4446984 constant */
    /* @4446988 cast */
    /* @4446992 constant */
    /* @4446996 cast */
    /* @4447000 call */
    GM_SITE(vm, 373, 4447000);
    /* @4447008 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(18), VAL(0), VAL(0)));
    /* @4447012 constant */
    /* @4447016 cast */
    /* @4447020 constant */
    /* @4447024 cast */
    /* @4447028 constant */
    /* @4447032 cast */
    /* @4447036 call */
    GM_SITE(vm, 373, 4447036);
    /* @4447044 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(19), VAL(0), VAL(0)));
    /* @4447048 constant */
    /* @4447052 cast */
    /* @4447056 constant */
    /* @4447060 cast */
    /* @4447064 constant */
    /* @4447068 cast */
    /* @4447072 call */
    GM_SITE(vm, 373, 4447072);
    /* @4447080 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(20), VAL(0), VAL(0)));
    /* @4447084 constant */
    /* @4447088 cast */
    /* @4447092 constant */
    /* @4447096 cast */
    /* @4447100 constant */
    /* @4447104 cast */
    /* @4447108 call */
    GM_SITE(vm, 373, 4447108);
    /* @4447116 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(21), VAL(0), VAL(0)));
    /* @4447120 constant */
    /* @4447124 cast */
    /* @4447128 constant */
    /* @4447132 cast */
    /* @4447136 constant */
    /* @4447140 cast */
    /* @4447144 call */
    GM_SITE(vm, 373, 4447144);
    /* @4447152 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(22), VAL(0), VAL(0)));
    /* @4447156 constant */
    /* @4447160 cast */
    /* @4447164 constant */
    /* @4447168 cast */
    /* @4447172 constant */
    /* @4447176 cast */
    /* @4447180 call */
    GM_SITE(vm, 373, 4447180);
    /* @4447188 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(23), VAL(0), VAL(0)));
    /* @4447192 constant */
    /* @4447196 cast */
    /* @4447200 constant */
    /* @4447204 cast */
    /* @4447208 constant */
    /* @4447212 cast */
    /* @4447216 call */
    GM_SITE(vm, 373, 4447216);
    /* @4447224 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(24), VAL(0), VAL(0)));
    /* @4447228 constant */
    /* @4447232 cast */
    /* @4447236 constant */
    /* @4447240 cast */
    /* @4447244 constant */
    /* @4447248 cast */
    /* @4447252 call */
    GM_SITE(vm, 373, 4447252);
    /* @4447260 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(25), VAL(0), VAL(0)));
    /* @4447264 constant */
    /* @4447268 cast */
    /* @4447272 constant */
    /* @4447276 cast */
    /* @4447280 constant */
    /* @4447284 cast */
    /* @4447288 call */
    GM_SITE(vm, 373, 4447288);
    /* @4447296 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(26), VAL(0), VAL(0)));
    /* @4447300 constant */
    /* @4447304 cast */
    /* @4447308 constant */
    /* @4447312 cast */
    /* @4447316 constant */
    /* @4447320 cast */
    /* @4447324 call */
    GM_SITE(vm, 373, 4447324);
    /* @4447332 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(27), VAL(0), VAL(0)));
    /* @4447336 constant */
    /* @4447340 cast */
    /* @4447344 constant */
    /* @4447348 cast */
    /* @4447352 constant */
    /* @4447356 cast */
    /* @4447360 call */
    GM_SITE(vm, 373, 4447360);
    /* @4447368 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(28), VAL(0), VAL(0)));
    /* @4447372 b */
    goto L_4448440;
    L_4447376: ;
    /* @4447376 load */
    /* @4447384 constant */
    /* @4447388 cmp */
    /* @4447392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4448440;
    /* @4447396 constant */
    /* @4447400 cast */
    /* @4447404 constant */
    /* @4447408 cast */
    /* @4447412 constant */
    /* @4447416 cast */
    /* @4447420 call */
    GM_SITE(vm, 373, 4447420);
    /* @4447428 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(0), VAL(1), VAL(0)));
    /* @4447432 constant */
    /* @4447436 cast */
    /* @4447440 constant */
    /* @4447444 cast */
    /* @4447448 constant */
    /* @4447452 cast */
    /* @4447456 call */
    GM_SITE(vm, 373, 4447456);
    /* @4447464 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(1), VAL(1), VAL(0)));
    /* @4447468 constant */
    /* @4447472 cast */
    /* @4447476 constant */
    /* @4447480 cast */
    /* @4447484 constant */
    /* @4447488 cast */
    /* @4447492 call */
    GM_SITE(vm, 373, 4447492);
    /* @4447500 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(2), VAL(1), VAL(0)));
    /* @4447504 constant */
    /* @4447508 cast */
    /* @4447512 constant */
    /* @4447516 cast */
    /* @4447520 constant */
    /* @4447524 cast */
    /* @4447528 call */
    GM_SITE(vm, 373, 4447528);
    /* @4447536 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(3), VAL(1), VAL(0)));
    /* @4447540 constant */
    /* @4447544 cast */
    /* @4447548 constant */
    /* @4447552 cast */
    /* @4447556 constant */
    /* @4447560 cast */
    /* @4447564 call */
    GM_SITE(vm, 373, 4447564);
    /* @4447572 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(4), VAL(1), VAL(0)));
    /* @4447576 constant */
    /* @4447580 cast */
    /* @4447584 constant */
    /* @4447588 cast */
    /* @4447592 constant */
    /* @4447596 cast */
    /* @4447600 call */
    GM_SITE(vm, 373, 4447600);
    /* @4447608 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(5), VAL(1), VAL(0)));
    /* @4447612 constant */
    /* @4447616 cast */
    /* @4447620 constant */
    /* @4447624 cast */
    /* @4447628 constant */
    /* @4447632 cast */
    /* @4447636 call */
    GM_SITE(vm, 373, 4447636);
    /* @4447644 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(6), VAL(1), VAL(0)));
    /* @4447648 constant */
    /* @4447652 cast */
    /* @4447656 constant */
    /* @4447660 cast */
    /* @4447664 constant */
    /* @4447668 cast */
    /* @4447672 call */
    GM_SITE(vm, 373, 4447672);
    /* @4447680 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(7), VAL(1), VAL(0)));
    /* @4447684 constant */
    /* @4447688 cast */
    /* @4447692 constant */
    /* @4447696 cast */
    /* @4447700 constant */
    /* @4447704 cast */
    /* @4447708 call */
    GM_SITE(vm, 373, 4447708);
    /* @4447716 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(8), VAL(1), VAL(0)));
    /* @4447720 constant */
    /* @4447724 cast */
    /* @4447728 constant */
    /* @4447732 cast */
    /* @4447736 constant */
    /* @4447740 cast */
    /* @4447744 call */
    GM_SITE(vm, 373, 4447744);
    /* @4447752 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(9), VAL(1), VAL(0)));
    /* @4447756 constant */
    /* @4447760 cast */
    /* @4447764 constant */
    /* @4447768 cast */
    /* @4447772 constant */
    /* @4447776 cast */
    /* @4447780 call */
    GM_SITE(vm, 373, 4447780);
    /* @4447788 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(10), VAL(1), VAL(0)));
    /* @4447792 constant */
    /* @4447796 cast */
    /* @4447800 constant */
    /* @4447804 cast */
    /* @4447808 constant */
    /* @4447812 cast */
    /* @4447816 call */
    GM_SITE(vm, 373, 4447816);
    /* @4447824 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(11), VAL(1), VAL(0)));
    /* @4447828 constant */
    /* @4447832 cast */
    /* @4447836 constant */
    /* @4447840 cast */
    /* @4447844 constant */
    /* @4447848 cast */
    /* @4447852 call */
    GM_SITE(vm, 373, 4447852);
    /* @4447860 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(12), VAL(1), VAL(0)));
    /* @4447864 constant */
    /* @4447868 cast */
    /* @4447872 constant */
    /* @4447876 cast */
    /* @4447880 constant */
    /* @4447884 cast */
    /* @4447888 call */
    GM_SITE(vm, 373, 4447888);
    /* @4447896 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(13), VAL(1), VAL(0)));
    /* @4447900 constant */
    /* @4447904 cast */
    /* @4447908 constant */
    /* @4447912 cast */
    /* @4447916 constant */
    /* @4447920 cast */
    /* @4447924 call */
    GM_SITE(vm, 373, 4447924);
    /* @4447932 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(14), VAL(1), VAL(0)));
    /* @4447936 constant */
    /* @4447940 cast */
    /* @4447944 constant */
    /* @4447948 cast */
    /* @4447952 constant */
    /* @4447956 cast */
    /* @4447960 call */
    GM_SITE(vm, 373, 4447960);
    /* @4447968 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(15), VAL(1), VAL(0)));
    /* @4447972 constant */
    /* @4447976 cast */
    /* @4447980 constant */
    /* @4447984 cast */
    /* @4447988 constant */
    /* @4447992 cast */
    /* @4447996 call */
    GM_SITE(vm, 373, 4447996);
    /* @4448004 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(16), VAL(1), VAL(0)));
    /* @4448008 constant */
    /* @4448012 cast */
    /* @4448016 constant */
    /* @4448020 cast */
    /* @4448024 constant */
    /* @4448028 cast */
    /* @4448032 call */
    GM_SITE(vm, 373, 4448032);
    /* @4448040 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(17), VAL(1), VAL(0)));
    /* @4448044 constant */
    /* @4448048 cast */
    /* @4448052 constant */
    /* @4448056 cast */
    /* @4448060 constant */
    /* @4448064 cast */
    /* @4448068 call */
    GM_SITE(vm, 373, 4448068);
    /* @4448076 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(18), VAL(1), VAL(0)));
    /* @4448080 constant */
    /* @4448084 cast */
    /* @4448088 constant */
    /* @4448092 cast */
    /* @4448096 constant */
    /* @4448100 cast */
    /* @4448104 call */
    GM_SITE(vm, 373, 4448104);
    /* @4448112 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(19), VAL(1), VAL(0)));
    /* @4448116 constant */
    /* @4448120 cast */
    /* @4448124 constant */
    /* @4448128 cast */
    /* @4448132 constant */
    /* @4448136 cast */
    /* @4448140 call */
    GM_SITE(vm, 373, 4448140);
    /* @4448148 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(20), VAL(1), VAL(0)));
    /* @4448152 constant */
    /* @4448156 cast */
    /* @4448160 constant */
    /* @4448164 cast */
    /* @4448168 constant */
    /* @4448172 cast */
    /* @4448176 call */
    GM_SITE(vm, 373, 4448176);
    /* @4448184 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(21), VAL(1), VAL(0)));
    /* @4448188 constant */
    /* @4448192 cast */
    /* @4448196 constant */
    /* @4448200 cast */
    /* @4448204 constant */
    /* @4448208 cast */
    /* @4448212 call */
    GM_SITE(vm, 373, 4448212);
    /* @4448220 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(22), VAL(1), VAL(0)));
    /* @4448224 constant */
    /* @4448228 cast */
    /* @4448232 constant */
    /* @4448236 cast */
    /* @4448240 constant */
    /* @4448244 cast */
    /* @4448248 call */
    GM_SITE(vm, 373, 4448248);
    /* @4448256 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(23), VAL(1), VAL(0)));
    /* @4448260 constant */
    /* @4448264 cast */
    /* @4448268 constant */
    /* @4448272 cast */
    /* @4448276 constant */
    /* @4448280 cast */
    /* @4448284 call */
    GM_SITE(vm, 373, 4448284);
    /* @4448292 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(24), VAL(1), VAL(0)));
    /* @4448296 constant */
    /* @4448300 cast */
    /* @4448304 constant */
    /* @4448308 cast */
    /* @4448312 constant */
    /* @4448316 cast */
    /* @4448320 call */
    GM_SITE(vm, 373, 4448320);
    /* @4448328 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(25), VAL(1), VAL(0)));
    /* @4448332 constant */
    /* @4448336 cast */
    /* @4448340 constant */
    /* @4448344 cast */
    /* @4448348 constant */
    /* @4448352 cast */
    /* @4448356 call */
    GM_SITE(vm, 373, 4448356);
    /* @4448364 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(26), VAL(1), VAL(0)));
    /* @4448368 constant */
    /* @4448372 cast */
    /* @4448376 constant */
    /* @4448380 cast */
    /* @4448384 constant */
    /* @4448388 cast */
    /* @4448392 call */
    GM_SITE(vm, 373, 4448392);
    /* @4448400 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(27), VAL(1), VAL(0)));
    /* @4448404 constant */
    /* @4448408 cast */
    /* @4448412 constant */
    /* @4448416 cast */
    /* @4448420 constant */
    /* @4448424 cast */
    /* @4448428 call */
    GM_SITE(vm, 373, 4448428);
    /* @4448436 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(28), VAL(1), VAL(0)));
    L_4448440: ;
    /* @4448440 load */
    /* @4448448 constant */
    /* @4448452 cmp */
    /* @4448456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4449328;
    /* @4448460 constant */
    /* @4448464 cast */
    /* @4448468 constant */
    /* @4448472 cast */
    /* @4448476 constant */
    /* @4448480 cast */
    /* @4448484 call */
    GM_SITE(vm, 373, 4448484);
    /* @4448492 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(29), VAL(0), VAL(0)));
    /* @4448496 constant */
    /* @4448500 cast */
    /* @4448504 constant */
    /* @4448508 cast */
    /* @4448512 constant */
    /* @4448516 cast */
    /* @4448520 call */
    GM_SITE(vm, 373, 4448520);
    /* @4448528 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(30), VAL(0), VAL(0)));
    /* @4448532 constant */
    /* @4448536 cast */
    /* @4448540 constant */
    /* @4448544 cast */
    /* @4448548 constant */
    /* @4448552 cast */
    /* @4448556 call */
    GM_SITE(vm, 373, 4448556);
    /* @4448564 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(31), VAL(0), VAL(0)));
    /* @4448568 constant */
    /* @4448572 cast */
    /* @4448576 constant */
    /* @4448580 cast */
    /* @4448584 constant */
    /* @4448588 cast */
    /* @4448592 call */
    GM_SITE(vm, 373, 4448592);
    /* @4448600 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(32), VAL(0), VAL(0)));
    /* @4448604 constant */
    /* @4448608 cast */
    /* @4448612 constant */
    /* @4448616 cast */
    /* @4448620 constant */
    /* @4448624 cast */
    /* @4448628 call */
    GM_SITE(vm, 373, 4448628);
    /* @4448636 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(33), VAL(0), VAL(0)));
    /* @4448640 constant */
    /* @4448644 cast */
    /* @4448648 constant */
    /* @4448652 cast */
    /* @4448656 constant */
    /* @4448660 cast */
    /* @4448664 call */
    GM_SITE(vm, 373, 4448664);
    /* @4448672 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(34), VAL(0), VAL(0)));
    /* @4448676 constant */
    /* @4448680 cast */
    /* @4448684 constant */
    /* @4448688 cast */
    /* @4448692 constant */
    /* @4448696 cast */
    /* @4448700 call */
    GM_SITE(vm, 373, 4448700);
    /* @4448708 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(35), VAL(0), VAL(0)));
    /* @4448712 constant */
    /* @4448716 cast */
    /* @4448720 constant */
    /* @4448724 cast */
    /* @4448728 constant */
    /* @4448732 cast */
    /* @4448736 call */
    GM_SITE(vm, 373, 4448736);
    /* @4448744 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(36), VAL(0), VAL(0)));
    /* @4448748 constant */
    /* @4448752 cast */
    /* @4448756 constant */
    /* @4448760 cast */
    /* @4448764 constant */
    /* @4448768 cast */
    /* @4448772 call */
    GM_SITE(vm, 373, 4448772);
    /* @4448780 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(37), VAL(0), VAL(0)));
    /* @4448784 constant */
    /* @4448788 cast */
    /* @4448792 constant */
    /* @4448796 cast */
    /* @4448800 constant */
    /* @4448804 cast */
    /* @4448808 call */
    GM_SITE(vm, 373, 4448808);
    /* @4448816 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(38), VAL(0), VAL(0)));
    /* @4448820 constant */
    /* @4448824 cast */
    /* @4448828 constant */
    /* @4448832 cast */
    /* @4448836 constant */
    /* @4448840 cast */
    /* @4448844 call */
    GM_SITE(vm, 373, 4448844);
    /* @4448852 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(39), VAL(0), VAL(0)));
    /* @4448856 constant */
    /* @4448860 cast */
    /* @4448864 constant */
    /* @4448868 cast */
    /* @4448872 constant */
    /* @4448876 cast */
    /* @4448880 call */
    GM_SITE(vm, 373, 4448880);
    /* @4448888 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(40), VAL(0), VAL(0)));
    /* @4448892 constant */
    /* @4448896 cast */
    /* @4448900 constant */
    /* @4448904 cast */
    /* @4448908 constant */
    /* @4448912 cast */
    /* @4448916 call */
    GM_SITE(vm, 373, 4448916);
    /* @4448924 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(41), VAL(0), VAL(0)));
    /* @4448928 constant */
    /* @4448932 cast */
    /* @4448936 constant */
    /* @4448940 cast */
    /* @4448944 constant */
    /* @4448948 cast */
    /* @4448952 call */
    GM_SITE(vm, 373, 4448952);
    /* @4448960 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(42), VAL(0), VAL(0)));
    /* @4448964 constant */
    /* @4448968 cast */
    /* @4448972 constant */
    /* @4448976 cast */
    /* @4448980 constant */
    /* @4448984 cast */
    /* @4448988 call */
    GM_SITE(vm, 373, 4448988);
    /* @4448996 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(43), VAL(0), VAL(0)));
    /* @4449000 constant */
    /* @4449004 cast */
    /* @4449008 constant */
    /* @4449012 cast */
    /* @4449016 constant */
    /* @4449020 cast */
    /* @4449024 call */
    GM_SITE(vm, 373, 4449024);
    /* @4449032 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(44), VAL(0), VAL(0)));
    /* @4449036 constant */
    /* @4449040 cast */
    /* @4449044 constant */
    /* @4449048 cast */
    /* @4449052 constant */
    /* @4449056 cast */
    /* @4449060 call */
    GM_SITE(vm, 373, 4449060);
    /* @4449068 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(45), VAL(0), VAL(0)));
    /* @4449072 constant */
    /* @4449076 cast */
    /* @4449080 constant */
    /* @4449084 cast */
    /* @4449088 constant */
    /* @4449092 cast */
    /* @4449096 call */
    GM_SITE(vm, 373, 4449096);
    /* @4449104 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(46), VAL(0), VAL(0)));
    /* @4449108 constant */
    /* @4449112 cast */
    /* @4449116 constant */
    /* @4449120 cast */
    /* @4449124 constant */
    /* @4449128 cast */
    /* @4449132 call */
    GM_SITE(vm, 373, 4449132);
    /* @4449140 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(47), VAL(0), VAL(0)));
    /* @4449144 constant */
    /* @4449148 cast */
    /* @4449152 constant */
    /* @4449156 cast */
    /* @4449160 constant */
    /* @4449164 cast */
    /* @4449168 call */
    GM_SITE(vm, 373, 4449168);
    /* @4449176 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(48), VAL(0), VAL(0)));
    /* @4449180 constant */
    /* @4449184 cast */
    /* @4449188 constant */
    /* @4449192 cast */
    /* @4449196 constant */
    /* @4449200 cast */
    /* @4449204 call */
    GM_SITE(vm, 373, 4449204);
    /* @4449212 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(49), VAL(0), VAL(0)));
    /* @4449216 constant */
    /* @4449220 cast */
    /* @4449224 constant */
    /* @4449228 cast */
    /* @4449232 constant */
    /* @4449236 cast */
    /* @4449240 call */
    GM_SITE(vm, 373, 4449240);
    /* @4449248 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(50), VAL(0), VAL(0)));
    /* @4449252 constant */
    /* @4449256 cast */
    /* @4449260 constant */
    /* @4449264 cast */
    /* @4449268 constant */
    /* @4449272 cast */
    /* @4449276 call */
    GM_SITE(vm, 373, 4449276);
    /* @4449284 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(51), VAL(0), VAL(0)));
    /* @4449288 constant */
    /* @4449292 cast */
    /* @4449296 constant */
    /* @4449300 cast */
    /* @4449304 constant */
    /* @4449308 cast */
    /* @4449312 call */
    GM_SITE(vm, 373, 4449312);
    /* @4449320 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(52), VAL(0), VAL(0)));
    /* @4449324 b */
    goto L_4450212;
    L_4449328: ;
    /* @4449328 load */
    /* @4449336 constant */
    /* @4449340 cmp */
    /* @4449344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4450212;
    /* @4449348 constant */
    /* @4449352 cast */
    /* @4449356 constant */
    /* @4449360 cast */
    /* @4449364 constant */
    /* @4449368 cast */
    /* @4449372 call */
    GM_SITE(vm, 373, 4449372);
    /* @4449380 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(29), VAL(1), VAL(0)));
    /* @4449384 constant */
    /* @4449388 cast */
    /* @4449392 constant */
    /* @4449396 cast */
    /* @4449400 constant */
    /* @4449404 cast */
    /* @4449408 call */
    GM_SITE(vm, 373, 4449408);
    /* @4449416 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(30), VAL(1), VAL(0)));
    /* @4449420 constant */
    /* @4449424 cast */
    /* @4449428 constant */
    /* @4449432 cast */
    /* @4449436 constant */
    /* @4449440 cast */
    /* @4449444 call */
    GM_SITE(vm, 373, 4449444);
    /* @4449452 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(31), VAL(1), VAL(0)));
    /* @4449456 constant */
    /* @4449460 cast */
    /* @4449464 constant */
    /* @4449468 cast */
    /* @4449472 constant */
    /* @4449476 cast */
    /* @4449480 call */
    GM_SITE(vm, 373, 4449480);
    /* @4449488 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(32), VAL(1), VAL(0)));
    /* @4449492 constant */
    /* @4449496 cast */
    /* @4449500 constant */
    /* @4449504 cast */
    /* @4449508 constant */
    /* @4449512 cast */
    /* @4449516 call */
    GM_SITE(vm, 373, 4449516);
    /* @4449524 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(33), VAL(1), VAL(0)));
    /* @4449528 constant */
    /* @4449532 cast */
    /* @4449536 constant */
    /* @4449540 cast */
    /* @4449544 constant */
    /* @4449548 cast */
    /* @4449552 call */
    GM_SITE(vm, 373, 4449552);
    /* @4449560 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(34), VAL(1), VAL(0)));
    /* @4449564 constant */
    /* @4449568 cast */
    /* @4449572 constant */
    /* @4449576 cast */
    /* @4449580 constant */
    /* @4449584 cast */
    /* @4449588 call */
    GM_SITE(vm, 373, 4449588);
    /* @4449596 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(35), VAL(1), VAL(0)));
    /* @4449600 constant */
    /* @4449604 cast */
    /* @4449608 constant */
    /* @4449612 cast */
    /* @4449616 constant */
    /* @4449620 cast */
    /* @4449624 call */
    GM_SITE(vm, 373, 4449624);
    /* @4449632 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(36), VAL(1), VAL(0)));
    /* @4449636 constant */
    /* @4449640 cast */
    /* @4449644 constant */
    /* @4449648 cast */
    /* @4449652 constant */
    /* @4449656 cast */
    /* @4449660 call */
    GM_SITE(vm, 373, 4449660);
    /* @4449668 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(37), VAL(1), VAL(0)));
    /* @4449672 constant */
    /* @4449676 cast */
    /* @4449680 constant */
    /* @4449684 cast */
    /* @4449688 constant */
    /* @4449692 cast */
    /* @4449696 call */
    GM_SITE(vm, 373, 4449696);
    /* @4449704 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(38), VAL(1), VAL(0)));
    /* @4449708 constant */
    /* @4449712 cast */
    /* @4449716 constant */
    /* @4449720 cast */
    /* @4449724 constant */
    /* @4449728 cast */
    /* @4449732 call */
    GM_SITE(vm, 373, 4449732);
    /* @4449740 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(39), VAL(1), VAL(0)));
    /* @4449744 constant */
    /* @4449748 cast */
    /* @4449752 constant */
    /* @4449756 cast */
    /* @4449760 constant */
    /* @4449764 cast */
    /* @4449768 call */
    GM_SITE(vm, 373, 4449768);
    /* @4449776 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(40), VAL(1), VAL(0)));
    /* @4449780 constant */
    /* @4449784 cast */
    /* @4449788 constant */
    /* @4449792 cast */
    /* @4449796 constant */
    /* @4449800 cast */
    /* @4449804 call */
    GM_SITE(vm, 373, 4449804);
    /* @4449812 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(41), VAL(1), VAL(0)));
    /* @4449816 constant */
    /* @4449820 cast */
    /* @4449824 constant */
    /* @4449828 cast */
    /* @4449832 constant */
    /* @4449836 cast */
    /* @4449840 call */
    GM_SITE(vm, 373, 4449840);
    /* @4449848 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(42), VAL(1), VAL(0)));
    /* @4449852 constant */
    /* @4449856 cast */
    /* @4449860 constant */
    /* @4449864 cast */
    /* @4449868 constant */
    /* @4449872 cast */
    /* @4449876 call */
    GM_SITE(vm, 373, 4449876);
    /* @4449884 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(43), VAL(1), VAL(0)));
    /* @4449888 constant */
    /* @4449892 cast */
    /* @4449896 constant */
    /* @4449900 cast */
    /* @4449904 constant */
    /* @4449908 cast */
    /* @4449912 call */
    GM_SITE(vm, 373, 4449912);
    /* @4449920 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(44), VAL(1), VAL(0)));
    /* @4449924 constant */
    /* @4449928 cast */
    /* @4449932 constant */
    /* @4449936 cast */
    /* @4449940 constant */
    /* @4449944 cast */
    /* @4449948 call */
    GM_SITE(vm, 373, 4449948);
    /* @4449956 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(45), VAL(1), VAL(0)));
    /* @4449960 constant */
    /* @4449964 cast */
    /* @4449968 constant */
    /* @4449972 cast */
    /* @4449976 constant */
    /* @4449980 cast */
    /* @4449984 call */
    GM_SITE(vm, 373, 4449984);
    /* @4449992 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(46), VAL(1), VAL(0)));
    /* @4449996 constant */
    /* @4450000 cast */
    /* @4450004 constant */
    /* @4450008 cast */
    /* @4450012 constant */
    /* @4450016 cast */
    /* @4450020 call */
    GM_SITE(vm, 373, 4450020);
    /* @4450028 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(47), VAL(1), VAL(0)));
    /* @4450032 constant */
    /* @4450036 cast */
    /* @4450040 constant */
    /* @4450044 cast */
    /* @4450048 constant */
    /* @4450052 cast */
    /* @4450056 call */
    GM_SITE(vm, 373, 4450056);
    /* @4450064 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(48), VAL(1), VAL(0)));
    /* @4450068 constant */
    /* @4450072 cast */
    /* @4450076 constant */
    /* @4450080 cast */
    /* @4450084 constant */
    /* @4450088 cast */
    /* @4450092 call */
    GM_SITE(vm, 373, 4450092);
    /* @4450100 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(49), VAL(1), VAL(0)));
    /* @4450104 constant */
    /* @4450108 cast */
    /* @4450112 constant */
    /* @4450116 cast */
    /* @4450120 constant */
    /* @4450124 cast */
    /* @4450128 call */
    GM_SITE(vm, 373, 4450128);
    /* @4450136 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(50), VAL(1), VAL(0)));
    /* @4450140 constant */
    /* @4450144 cast */
    /* @4450148 constant */
    /* @4450152 cast */
    /* @4450156 constant */
    /* @4450160 cast */
    /* @4450164 call */
    GM_SITE(vm, 373, 4450164);
    /* @4450172 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(51), VAL(1), VAL(0)));
    /* @4450176 constant */
    /* @4450180 cast */
    /* @4450184 constant */
    /* @4450188 cast */
    /* @4450192 constant */
    /* @4450196 cast */
    /* @4450200 call */
    GM_SITE(vm, 373, 4450200);
    /* @4450208 popz */
    (void)(GM_CALL(vm, "audio_sound_gain", 3, VAL(52), VAL(1), VAL(0)));
    L_4450212: ;
    return;
}
