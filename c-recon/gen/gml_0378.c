/* generated from CODE 378 (gml_Object_obj_music_Other_4), source start 4496544, end 4515748. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0378(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4496544 load */
    /* @4496552 constant */
    /* @4496556 cmp */
    /* @4496560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4496568;
    /* @4496564 b */
    goto L_4496996;
    L_4496568: ;
    /* @4496568 load */
    /* @4496576 constant */
    /* @4496580 cmp */
    /* @4496584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4496996;
    /* @4496588 load */
    /* @4496596 constant */
    /* @4496600 cmp */
    /* @4496604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_4496656;
    /* @4496608 call */
    GM_SITE(vm, 378, 4496608);
    /* @4496616 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496620 constant */
    /* @4496624 cast */
    /* @4496628 constant */
    /* @4496632 cast */
    /* @4496636 constant */
    /* @4496640 cast */
    /* @4496644 call */
    GM_SITE(vm, 378, 4496644);
    /* @4496652 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4496656: ;
    /* @4496656 load */
    /* @4496664 constant */
    /* @4496668 cmp */
    /* @4496672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_4496724;
    /* @4496676 call */
    GM_SITE(vm, 378, 4496676);
    /* @4496684 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496688 constant */
    /* @4496692 cast */
    /* @4496696 constant */
    /* @4496700 cast */
    /* @4496704 constant */
    /* @4496708 cast */
    /* @4496712 call */
    GM_SITE(vm, 378, 4496712);
    /* @4496720 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4496724: ;
    /* @4496724 load */
    /* @4496732 constant */
    /* @4496736 cmp */
    /* @4496740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_4496792;
    /* @4496744 call */
    GM_SITE(vm, 378, 4496744);
    /* @4496752 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496756 constant */
    /* @4496760 cast */
    /* @4496764 constant */
    /* @4496768 cast */
    /* @4496772 constant */
    /* @4496776 cast */
    /* @4496780 call */
    GM_SITE(vm, 378, 4496780);
    /* @4496788 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4496792: ;
    /* @4496792 load */
    /* @4496800 constant */
    /* @4496804 cmp */
    /* @4496808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_4496860;
    /* @4496812 call */
    GM_SITE(vm, 378, 4496812);
    /* @4496820 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496824 constant */
    /* @4496828 cast */
    /* @4496832 constant */
    /* @4496836 cast */
    /* @4496840 constant */
    /* @4496844 cast */
    /* @4496848 call */
    GM_SITE(vm, 378, 4496848);
    /* @4496856 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4496860: ;
    /* @4496860 load */
    /* @4496868 constant */
    /* @4496872 cmp */
    /* @4496876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_4496928;
    /* @4496880 call */
    GM_SITE(vm, 378, 4496880);
    /* @4496888 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496892 constant */
    /* @4496896 cast */
    /* @4496900 constant */
    /* @4496904 cast */
    /* @4496908 constant */
    /* @4496912 cast */
    /* @4496916 call */
    GM_SITE(vm, 378, 4496916);
    /* @4496924 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4496928: ;
    /* @4496928 load */
    /* @4496936 constant */
    /* @4496940 cmp */
    /* @4496944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_4496996;
    /* @4496948 call */
    GM_SITE(vm, 378, 4496948);
    /* @4496956 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4496960 constant */
    /* @4496964 cast */
    /* @4496968 constant */
    /* @4496972 cast */
    /* @4496976 constant */
    /* @4496980 cast */
    /* @4496984 call */
    GM_SITE(vm, 378, 4496984);
    /* @4496992 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4496996: ;
    /* @4496996 load */
    /* @4497004 constant */
    /* @4497008 cmp */
    /* @4497012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_4500756;
    /* @4497016 call */
    GM_SITE(vm, 378, 4497016);
    /* @4497024 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4497028 constant */
    /* @4497032 constant */
    /* @4497036 constant */
    /* @4497040 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4497048 call */
    GM_SITE(vm, 378, 4497048);
    /* @4497056 popz */
    (void)(GM_CALL(vm, "randomize", 0));
    /* @4497060 constant */
    /* @4497064 cast */
    /* @4497068 constant */
    /* @4497072 cast */
    /* @4497076 constant */
    /* @4497080 cast */
    /* @4497084 constant */
    /* @4497088 cast */
    /* @4497092 constant */
    /* @4497096 cast */
    /* @4497100 constant */
    /* @4497104 cast */
    /* @4497108 constant */
    /* @4497112 cast */
    /* @4497116 constant */
    /* @4497120 cast */
    /* @4497124 constant */
    /* @4497128 cast */
    /* @4497132 constant */
    /* @4497136 cast */
    /* @4497140 call */
    GM_SITE(vm, 378, 4497140);
    /* @4497148 store */
    v1 = GM_CALL(vm, "choose", 10, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5), VAL(6), VAL(7), VAL(8), VAL(9), VAL(10));
    GM_WRITE(vm, -1, "playlist", v1);
    /* @4497156 load */
    /* @4497164 constant */
    /* @4497168 cmp */
    /* @4497172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(1)))) goto L_4497516;
    /* @4497176 constant */
    /* @4497180 constant */
    /* @4497184 constant */
    /* @4497188 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(37));
    /* @4497196 constant */
    /* @4497200 constant */
    /* @4497204 constant */
    /* @4497208 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(46));
    /* @4497216 constant */
    /* @4497220 constant */
    /* @4497224 constant */
    /* @4497228 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4497236 constant */
    /* @4497240 constant */
    /* @4497244 constant */
    /* @4497248 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(31));
    /* @4497256 constant */
    /* @4497260 constant */
    /* @4497264 constant */
    /* @4497268 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4497276 constant */
    /* @4497280 constant */
    /* @4497284 constant */
    /* @4497288 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(44));
    /* @4497296 constant */
    /* @4497300 constant */
    /* @4497304 constant */
    /* @4497308 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(30));
    /* @4497316 constant */
    /* @4497320 constant */
    /* @4497324 constant */
    /* @4497328 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(45));
    /* @4497336 constant */
    /* @4497340 constant */
    /* @4497344 constant */
    /* @4497348 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(39));
    /* @4497356 constant */
    /* @4497360 constant */
    /* @4497364 constant */
    /* @4497368 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4497376 constant */
    /* @4497380 constant */
    /* @4497384 constant */
    /* @4497388 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(34));
    /* @4497396 constant */
    /* @4497400 constant */
    /* @4497404 constant */
    /* @4497408 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4497416 constant */
    /* @4497420 constant */
    /* @4497424 constant */
    /* @4497428 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(52));
    /* @4497436 constant */
    /* @4497440 constant */
    /* @4497444 constant */
    /* @4497448 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4497456 constant */
    /* @4497460 constant */
    /* @4497464 constant */
    /* @4497468 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4497476 constant */
    /* @4497480 constant */
    /* @4497484 constant */
    /* @4497488 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(47));
    /* @4497496 constant */
    /* @4497500 constant */
    /* @4497504 constant */
    /* @4497508 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4497516: ;
    /* @4497516 load */
    /* @4497524 constant */
    /* @4497528 cmp */
    /* @4497532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(2)))) goto L_4497876;
    /* @4497536 constant */
    /* @4497540 constant */
    /* @4497544 constant */
    /* @4497548 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(44));
    /* @4497556 constant */
    /* @4497560 constant */
    /* @4497564 constant */
    /* @4497568 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4497576 constant */
    /* @4497580 constant */
    /* @4497584 constant */
    /* @4497588 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4497596 constant */
    /* @4497600 constant */
    /* @4497604 constant */
    /* @4497608 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(45));
    /* @4497616 constant */
    /* @4497620 constant */
    /* @4497624 constant */
    /* @4497628 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(38));
    /* @4497636 constant */
    /* @4497640 constant */
    /* @4497644 constant */
    /* @4497648 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(46));
    /* @4497656 constant */
    /* @4497660 constant */
    /* @4497664 constant */
    /* @4497668 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4497676 constant */
    /* @4497680 constant */
    /* @4497684 constant */
    /* @4497688 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(37));
    /* @4497696 constant */
    /* @4497700 constant */
    /* @4497704 constant */
    /* @4497708 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(32));
    /* @4497716 constant */
    /* @4497720 constant */
    /* @4497724 constant */
    /* @4497728 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4497736 constant */
    /* @4497740 constant */
    /* @4497744 constant */
    /* @4497748 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(30));
    /* @4497756 constant */
    /* @4497760 constant */
    /* @4497764 constant */
    /* @4497768 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(35));
    /* @4497776 constant */
    /* @4497780 constant */
    /* @4497784 constant */
    /* @4497788 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4497796 constant */
    /* @4497800 constant */
    /* @4497804 constant */
    /* @4497808 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(31));
    /* @4497816 constant */
    /* @4497820 constant */
    /* @4497824 constant */
    /* @4497828 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4497836 constant */
    /* @4497840 constant */
    /* @4497844 constant */
    /* @4497848 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4497856 constant */
    /* @4497860 constant */
    /* @4497864 constant */
    /* @4497868 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(47));
    L_4497876: ;
    /* @4497876 load */
    /* @4497884 constant */
    /* @4497888 cmp */
    /* @4497892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(3)))) goto L_4498236;
    /* @4497896 constant */
    /* @4497900 constant */
    /* @4497904 constant */
    /* @4497908 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4497916 constant */
    /* @4497920 constant */
    /* @4497924 constant */
    /* @4497928 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(35));
    /* @4497936 constant */
    /* @4497940 constant */
    /* @4497944 constant */
    /* @4497948 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(39));
    /* @4497956 constant */
    /* @4497960 constant */
    /* @4497964 constant */
    /* @4497968 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(37));
    /* @4497976 constant */
    /* @4497980 constant */
    /* @4497984 constant */
    /* @4497988 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4497996 constant */
    /* @4498000 constant */
    /* @4498004 constant */
    /* @4498008 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(30));
    /* @4498016 constant */
    /* @4498020 constant */
    /* @4498024 constant */
    /* @4498028 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(46));
    /* @4498036 constant */
    /* @4498040 constant */
    /* @4498044 constant */
    /* @4498048 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4498056 constant */
    /* @4498060 constant */
    /* @4498064 constant */
    /* @4498068 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(38));
    /* @4498076 constant */
    /* @4498080 constant */
    /* @4498084 constant */
    /* @4498088 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(31));
    /* @4498096 constant */
    /* @4498100 constant */
    /* @4498104 constant */
    /* @4498108 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4498116 constant */
    /* @4498120 constant */
    /* @4498124 constant */
    /* @4498128 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(32));
    /* @4498136 constant */
    /* @4498140 constant */
    /* @4498144 constant */
    /* @4498148 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4498156 constant */
    /* @4498160 constant */
    /* @4498164 constant */
    /* @4498168 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(41));
    /* @4498176 constant */
    /* @4498180 constant */
    /* @4498184 constant */
    /* @4498188 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4498196 constant */
    /* @4498200 constant */
    /* @4498204 constant */
    /* @4498208 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(33));
    /* @4498216 constant */
    /* @4498220 constant */
    /* @4498224 constant */
    /* @4498228 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4498236: ;
    /* @4498236 load */
    /* @4498244 constant */
    /* @4498248 cmp */
    /* @4498252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(4)))) goto L_4498596;
    /* @4498256 constant */
    /* @4498260 constant */
    /* @4498264 constant */
    /* @4498268 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4498276 constant */
    /* @4498280 constant */
    /* @4498284 constant */
    /* @4498288 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4498296 constant */
    /* @4498300 constant */
    /* @4498304 constant */
    /* @4498308 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(37));
    /* @4498316 constant */
    /* @4498320 constant */
    /* @4498324 constant */
    /* @4498328 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4498336 constant */
    /* @4498340 constant */
    /* @4498344 constant */
    /* @4498348 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4498356 constant */
    /* @4498360 constant */
    /* @4498364 constant */
    /* @4498368 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(34));
    /* @4498376 constant */
    /* @4498380 constant */
    /* @4498384 constant */
    /* @4498388 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(45));
    /* @4498396 constant */
    /* @4498400 constant */
    /* @4498404 constant */
    /* @4498408 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(31));
    /* @4498416 constant */
    /* @4498420 constant */
    /* @4498424 constant */
    /* @4498428 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(41));
    /* @4498436 constant */
    /* @4498440 constant */
    /* @4498444 constant */
    /* @4498448 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4498456 constant */
    /* @4498460 constant */
    /* @4498464 constant */
    /* @4498468 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4498476 constant */
    /* @4498480 constant */
    /* @4498484 constant */
    /* @4498488 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(46));
    /* @4498496 constant */
    /* @4498500 constant */
    /* @4498504 constant */
    /* @4498508 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(39));
    /* @4498516 constant */
    /* @4498520 constant */
    /* @4498524 constant */
    /* @4498528 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4498536 constant */
    /* @4498540 constant */
    /* @4498544 constant */
    /* @4498548 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4498556 constant */
    /* @4498560 constant */
    /* @4498564 constant */
    /* @4498568 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(30));
    /* @4498576 constant */
    /* @4498580 constant */
    /* @4498584 constant */
    /* @4498588 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4498596: ;
    /* @4498596 load */
    /* @4498604 constant */
    /* @4498608 cmp */
    /* @4498612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(5)))) goto L_4498956;
    /* @4498616 constant */
    /* @4498620 constant */
    /* @4498624 constant */
    /* @4498628 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4498636 constant */
    /* @4498640 constant */
    /* @4498644 constant */
    /* @4498648 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(30));
    /* @4498656 constant */
    /* @4498660 constant */
    /* @4498664 constant */
    /* @4498668 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4498676 constant */
    /* @4498680 constant */
    /* @4498684 constant */
    /* @4498688 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4498696 constant */
    /* @4498700 constant */
    /* @4498704 constant */
    /* @4498708 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(45));
    /* @4498716 constant */
    /* @4498720 constant */
    /* @4498724 constant */
    /* @4498728 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(52));
    /* @4498736 constant */
    /* @4498740 constant */
    /* @4498744 constant */
    /* @4498748 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4498756 constant */
    /* @4498760 constant */
    /* @4498764 constant */
    /* @4498768 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4498776 constant */
    /* @4498780 constant */
    /* @4498784 constant */
    /* @4498788 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(34));
    /* @4498796 constant */
    /* @4498800 constant */
    /* @4498804 constant */
    /* @4498808 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(46));
    /* @4498816 constant */
    /* @4498820 constant */
    /* @4498824 constant */
    /* @4498828 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4498836 constant */
    /* @4498840 constant */
    /* @4498844 constant */
    /* @4498848 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4498856 constant */
    /* @4498860 constant */
    /* @4498864 constant */
    /* @4498868 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(37));
    /* @4498876 constant */
    /* @4498880 constant */
    /* @4498884 constant */
    /* @4498888 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(36));
    /* @4498896 constant */
    /* @4498900 constant */
    /* @4498904 constant */
    /* @4498908 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(32));
    /* @4498916 constant */
    /* @4498920 constant */
    /* @4498924 constant */
    /* @4498928 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(38));
    /* @4498936 constant */
    /* @4498940 constant */
    /* @4498944 constant */
    /* @4498948 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(39));
    L_4498956: ;
    /* @4498956 load */
    /* @4498964 constant */
    /* @4498968 cmp */
    /* @4498972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(6)))) goto L_4499316;
    /* @4498976 constant */
    /* @4498980 constant */
    /* @4498984 constant */
    /* @4498988 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4498996 constant */
    /* @4499000 constant */
    /* @4499004 constant */
    /* @4499008 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(37));
    /* @4499016 constant */
    /* @4499020 constant */
    /* @4499024 constant */
    /* @4499028 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(44));
    /* @4499036 constant */
    /* @4499040 constant */
    /* @4499044 constant */
    /* @4499048 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4499056 constant */
    /* @4499060 constant */
    /* @4499064 constant */
    /* @4499068 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4499076 constant */
    /* @4499080 constant */
    /* @4499084 constant */
    /* @4499088 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(41));
    /* @4499096 constant */
    /* @4499100 constant */
    /* @4499104 constant */
    /* @4499108 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4499116 constant */
    /* @4499120 constant */
    /* @4499124 constant */
    /* @4499128 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4499136 constant */
    /* @4499140 constant */
    /* @4499144 constant */
    /* @4499148 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(35));
    /* @4499156 constant */
    /* @4499160 constant */
    /* @4499164 constant */
    /* @4499168 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4499176 constant */
    /* @4499180 constant */
    /* @4499184 constant */
    /* @4499188 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4499196 constant */
    /* @4499200 constant */
    /* @4499204 constant */
    /* @4499208 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(30));
    /* @4499216 constant */
    /* @4499220 constant */
    /* @4499224 constant */
    /* @4499228 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(38));
    /* @4499236 constant */
    /* @4499240 constant */
    /* @4499244 constant */
    /* @4499248 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4499256 constant */
    /* @4499260 constant */
    /* @4499264 constant */
    /* @4499268 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4499276 constant */
    /* @4499280 constant */
    /* @4499284 constant */
    /* @4499288 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(52));
    /* @4499296 constant */
    /* @4499300 constant */
    /* @4499304 constant */
    /* @4499308 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4499316: ;
    /* @4499316 load */
    /* @4499324 constant */
    /* @4499328 cmp */
    /* @4499332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(7)))) goto L_4499676;
    /* @4499336 constant */
    /* @4499340 constant */
    /* @4499344 constant */
    /* @4499348 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4499356 constant */
    /* @4499360 constant */
    /* @4499364 constant */
    /* @4499368 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(47));
    /* @4499376 constant */
    /* @4499380 constant */
    /* @4499384 constant */
    /* @4499388 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(32));
    /* @4499396 constant */
    /* @4499400 constant */
    /* @4499404 constant */
    /* @4499408 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4499416 constant */
    /* @4499420 constant */
    /* @4499424 constant */
    /* @4499428 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(46));
    /* @4499436 constant */
    /* @4499440 constant */
    /* @4499444 constant */
    /* @4499448 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(38));
    /* @4499456 constant */
    /* @4499460 constant */
    /* @4499464 constant */
    /* @4499468 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(44));
    /* @4499476 constant */
    /* @4499480 constant */
    /* @4499484 constant */
    /* @4499488 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4499496 constant */
    /* @4499500 constant */
    /* @4499504 constant */
    /* @4499508 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4499516 constant */
    /* @4499520 constant */
    /* @4499524 constant */
    /* @4499528 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4499536 constant */
    /* @4499540 constant */
    /* @4499544 constant */
    /* @4499548 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(52));
    /* @4499556 constant */
    /* @4499560 constant */
    /* @4499564 constant */
    /* @4499568 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(37));
    /* @4499576 constant */
    /* @4499580 constant */
    /* @4499584 constant */
    /* @4499588 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(30));
    /* @4499596 constant */
    /* @4499600 constant */
    /* @4499604 constant */
    /* @4499608 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(33));
    /* @4499616 constant */
    /* @4499620 constant */
    /* @4499624 constant */
    /* @4499628 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(31));
    /* @4499636 constant */
    /* @4499640 constant */
    /* @4499644 constant */
    /* @4499648 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(45));
    /* @4499656 constant */
    /* @4499660 constant */
    /* @4499664 constant */
    /* @4499668 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(35));
    L_4499676: ;
    /* @4499676 load */
    /* @4499684 constant */
    /* @4499688 cmp */
    /* @4499692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(8)))) goto L_4500036;
    /* @4499696 constant */
    /* @4499700 constant */
    /* @4499704 constant */
    /* @4499708 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(34));
    /* @4499716 constant */
    /* @4499720 constant */
    /* @4499724 constant */
    /* @4499728 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(38));
    /* @4499736 constant */
    /* @4499740 constant */
    /* @4499744 constant */
    /* @4499748 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(33));
    /* @4499756 constant */
    /* @4499760 constant */
    /* @4499764 constant */
    /* @4499768 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(52));
    /* @4499776 constant */
    /* @4499780 constant */
    /* @4499784 constant */
    /* @4499788 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4499796 constant */
    /* @4499800 constant */
    /* @4499804 constant */
    /* @4499808 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(37));
    /* @4499816 constant */
    /* @4499820 constant */
    /* @4499824 constant */
    /* @4499828 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4499836 constant */
    /* @4499840 constant */
    /* @4499844 constant */
    /* @4499848 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4499856 constant */
    /* @4499860 constant */
    /* @4499864 constant */
    /* @4499868 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(46));
    /* @4499876 constant */
    /* @4499880 constant */
    /* @4499884 constant */
    /* @4499888 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4499896 constant */
    /* @4499900 constant */
    /* @4499904 constant */
    /* @4499908 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4499916 constant */
    /* @4499920 constant */
    /* @4499924 constant */
    /* @4499928 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4499936 constant */
    /* @4499940 constant */
    /* @4499944 constant */
    /* @4499948 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(35));
    /* @4499956 constant */
    /* @4499960 constant */
    /* @4499964 constant */
    /* @4499968 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(30));
    /* @4499976 constant */
    /* @4499980 constant */
    /* @4499984 constant */
    /* @4499988 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4499996 constant */
    /* @4500000 constant */
    /* @4500004 constant */
    /* @4500008 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(32));
    /* @4500016 constant */
    /* @4500020 constant */
    /* @4500024 constant */
    /* @4500028 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(45));
    L_4500036: ;
    /* @4500036 load */
    /* @4500044 constant */
    /* @4500048 cmp */
    /* @4500052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(9)))) goto L_4500396;
    /* @4500056 constant */
    /* @4500060 constant */
    /* @4500064 constant */
    /* @4500068 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4500076 constant */
    /* @4500080 constant */
    /* @4500084 constant */
    /* @4500088 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(44));
    /* @4500096 constant */
    /* @4500100 constant */
    /* @4500104 constant */
    /* @4500108 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4500116 constant */
    /* @4500120 constant */
    /* @4500124 constant */
    /* @4500128 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4500136 constant */
    /* @4500140 constant */
    /* @4500144 constant */
    /* @4500148 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(33));
    /* @4500156 constant */
    /* @4500160 constant */
    /* @4500164 constant */
    /* @4500168 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(35));
    /* @4500176 constant */
    /* @4500180 constant */
    /* @4500184 constant */
    /* @4500188 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(37));
    /* @4500196 constant */
    /* @4500200 constant */
    /* @4500204 constant */
    /* @4500208 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(38));
    /* @4500216 constant */
    /* @4500220 constant */
    /* @4500224 constant */
    /* @4500228 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(30));
    /* @4500236 constant */
    /* @4500240 constant */
    /* @4500244 constant */
    /* @4500248 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(32));
    /* @4500256 constant */
    /* @4500260 constant */
    /* @4500264 constant */
    /* @4500268 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(39));
    /* @4500276 constant */
    /* @4500280 constant */
    /* @4500284 constant */
    /* @4500288 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4500296 constant */
    /* @4500300 constant */
    /* @4500304 constant */
    /* @4500308 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(46));
    /* @4500316 constant */
    /* @4500320 constant */
    /* @4500324 constant */
    /* @4500328 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(47));
    /* @4500336 constant */
    /* @4500340 constant */
    /* @4500344 constant */
    /* @4500348 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4500356 constant */
    /* @4500360 constant */
    /* @4500364 constant */
    /* @4500368 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4500376 constant */
    /* @4500380 constant */
    /* @4500384 constant */
    /* @4500388 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(41));
    L_4500396: ;
    /* @4500396 load */
    /* @4500404 constant */
    /* @4500408 cmp */
    /* @4500412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(10)))) goto L_4500756;
    /* @4500416 constant */
    /* @4500420 constant */
    /* @4500424 constant */
    /* @4500428 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4500436 constant */
    /* @4500440 constant */
    /* @4500444 constant */
    /* @4500448 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4500456 constant */
    /* @4500460 constant */
    /* @4500464 constant */
    /* @4500468 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4500476 constant */
    /* @4500480 constant */
    /* @4500484 constant */
    /* @4500488 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(30));
    /* @4500496 constant */
    /* @4500500 constant */
    /* @4500504 constant */
    /* @4500508 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(31));
    /* @4500516 constant */
    /* @4500520 constant */
    /* @4500524 constant */
    /* @4500528 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(33));
    /* @4500536 constant */
    /* @4500540 constant */
    /* @4500544 constant */
    /* @4500548 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(34));
    /* @4500556 constant */
    /* @4500560 constant */
    /* @4500564 constant */
    /* @4500568 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4500576 constant */
    /* @4500580 constant */
    /* @4500584 constant */
    /* @4500588 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4500596 constant */
    /* @4500600 constant */
    /* @4500604 constant */
    /* @4500608 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(41));
    /* @4500616 constant */
    /* @4500620 constant */
    /* @4500624 constant */
    /* @4500628 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(38));
    /* @4500636 constant */
    /* @4500640 constant */
    /* @4500644 constant */
    /* @4500648 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(39));
    /* @4500656 constant */
    /* @4500660 constant */
    /* @4500664 constant */
    /* @4500668 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(47));
    /* @4500676 constant */
    /* @4500680 constant */
    /* @4500684 constant */
    /* @4500688 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4500696 constant */
    /* @4500700 constant */
    /* @4500704 constant */
    /* @4500708 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(44));
    /* @4500716 constant */
    /* @4500720 constant */
    /* @4500724 constant */
    /* @4500728 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4500736 constant */
    /* @4500740 constant */
    /* @4500744 constant */
    /* @4500748 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(37));
    L_4500756: ;
    /* @4500756 load */
    /* @4500764 constant */
    /* @4500768 cmp */
    /* @4500772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_4504504;
    /* @4500776 call */
    GM_SITE(vm, 378, 4500776);
    /* @4500784 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4500788 constant */
    /* @4500792 constant */
    /* @4500796 constant */
    /* @4500800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4500808 constant */
    /* @4500812 cast */
    /* @4500816 constant */
    /* @4500820 cast */
    /* @4500824 constant */
    /* @4500828 cast */
    /* @4500832 constant */
    /* @4500836 cast */
    /* @4500840 constant */
    /* @4500844 cast */
    /* @4500848 constant */
    /* @4500852 cast */
    /* @4500856 constant */
    /* @4500860 cast */
    /* @4500864 constant */
    /* @4500868 cast */
    /* @4500872 constant */
    /* @4500876 cast */
    /* @4500880 constant */
    /* @4500884 cast */
    /* @4500888 call */
    GM_SITE(vm, 378, 4500888);
    /* @4500896 store */
    v2 = GM_CALL(vm, "choose", 10, VAL(2), VAL(4), VAL(6), VAL(8), VAL(10), VAL(1), VAL(3), VAL(5), VAL(7), VAL(9));
    GM_WRITE(vm, -1, "playlist", v2);
    /* @4500904 load */
    /* @4500912 constant */
    /* @4500916 cmp */
    /* @4500920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(1)))) goto L_4501264;
    /* @4500924 constant */
    /* @4500928 constant */
    /* @4500932 constant */
    /* @4500936 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(37));
    /* @4500944 constant */
    /* @4500948 constant */
    /* @4500952 constant */
    /* @4500956 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(46));
    /* @4500964 constant */
    /* @4500968 constant */
    /* @4500972 constant */
    /* @4500976 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4500984 constant */
    /* @4500988 constant */
    /* @4500992 constant */
    /* @4500996 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(31));
    /* @4501004 constant */
    /* @4501008 constant */
    /* @4501012 constant */
    /* @4501016 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4501024 constant */
    /* @4501028 constant */
    /* @4501032 constant */
    /* @4501036 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(44));
    /* @4501044 constant */
    /* @4501048 constant */
    /* @4501052 constant */
    /* @4501056 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(30));
    /* @4501064 constant */
    /* @4501068 constant */
    /* @4501072 constant */
    /* @4501076 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(45));
    /* @4501084 constant */
    /* @4501088 constant */
    /* @4501092 constant */
    /* @4501096 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(39));
    /* @4501104 constant */
    /* @4501108 constant */
    /* @4501112 constant */
    /* @4501116 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4501124 constant */
    /* @4501128 constant */
    /* @4501132 constant */
    /* @4501136 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(34));
    /* @4501144 constant */
    /* @4501148 constant */
    /* @4501152 constant */
    /* @4501156 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4501164 constant */
    /* @4501168 constant */
    /* @4501172 constant */
    /* @4501176 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(52));
    /* @4501184 constant */
    /* @4501188 constant */
    /* @4501192 constant */
    /* @4501196 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4501204 constant */
    /* @4501208 constant */
    /* @4501212 constant */
    /* @4501216 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4501224 constant */
    /* @4501228 constant */
    /* @4501232 constant */
    /* @4501236 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(47));
    /* @4501244 constant */
    /* @4501248 constant */
    /* @4501252 constant */
    /* @4501256 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4501264: ;
    /* @4501264 load */
    /* @4501272 constant */
    /* @4501276 cmp */
    /* @4501280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(2)))) goto L_4501624;
    /* @4501284 constant */
    /* @4501288 constant */
    /* @4501292 constant */
    /* @4501296 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(44));
    /* @4501304 constant */
    /* @4501308 constant */
    /* @4501312 constant */
    /* @4501316 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4501324 constant */
    /* @4501328 constant */
    /* @4501332 constant */
    /* @4501336 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4501344 constant */
    /* @4501348 constant */
    /* @4501352 constant */
    /* @4501356 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(45));
    /* @4501364 constant */
    /* @4501368 constant */
    /* @4501372 constant */
    /* @4501376 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(38));
    /* @4501384 constant */
    /* @4501388 constant */
    /* @4501392 constant */
    /* @4501396 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(46));
    /* @4501404 constant */
    /* @4501408 constant */
    /* @4501412 constant */
    /* @4501416 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4501424 constant */
    /* @4501428 constant */
    /* @4501432 constant */
    /* @4501436 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(37));
    /* @4501444 constant */
    /* @4501448 constant */
    /* @4501452 constant */
    /* @4501456 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(32));
    /* @4501464 constant */
    /* @4501468 constant */
    /* @4501472 constant */
    /* @4501476 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4501484 constant */
    /* @4501488 constant */
    /* @4501492 constant */
    /* @4501496 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(30));
    /* @4501504 constant */
    /* @4501508 constant */
    /* @4501512 constant */
    /* @4501516 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(35));
    /* @4501524 constant */
    /* @4501528 constant */
    /* @4501532 constant */
    /* @4501536 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4501544 constant */
    /* @4501548 constant */
    /* @4501552 constant */
    /* @4501556 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(31));
    /* @4501564 constant */
    /* @4501568 constant */
    /* @4501572 constant */
    /* @4501576 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4501584 constant */
    /* @4501588 constant */
    /* @4501592 constant */
    /* @4501596 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4501604 constant */
    /* @4501608 constant */
    /* @4501612 constant */
    /* @4501616 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(47));
    L_4501624: ;
    /* @4501624 load */
    /* @4501632 constant */
    /* @4501636 cmp */
    /* @4501640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(3)))) goto L_4501984;
    /* @4501644 constant */
    /* @4501648 constant */
    /* @4501652 constant */
    /* @4501656 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4501664 constant */
    /* @4501668 constant */
    /* @4501672 constant */
    /* @4501676 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(35));
    /* @4501684 constant */
    /* @4501688 constant */
    /* @4501692 constant */
    /* @4501696 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(39));
    /* @4501704 constant */
    /* @4501708 constant */
    /* @4501712 constant */
    /* @4501716 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(37));
    /* @4501724 constant */
    /* @4501728 constant */
    /* @4501732 constant */
    /* @4501736 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4501744 constant */
    /* @4501748 constant */
    /* @4501752 constant */
    /* @4501756 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(30));
    /* @4501764 constant */
    /* @4501768 constant */
    /* @4501772 constant */
    /* @4501776 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(46));
    /* @4501784 constant */
    /* @4501788 constant */
    /* @4501792 constant */
    /* @4501796 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4501804 constant */
    /* @4501808 constant */
    /* @4501812 constant */
    /* @4501816 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(38));
    /* @4501824 constant */
    /* @4501828 constant */
    /* @4501832 constant */
    /* @4501836 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(31));
    /* @4501844 constant */
    /* @4501848 constant */
    /* @4501852 constant */
    /* @4501856 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4501864 constant */
    /* @4501868 constant */
    /* @4501872 constant */
    /* @4501876 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(32));
    /* @4501884 constant */
    /* @4501888 constant */
    /* @4501892 constant */
    /* @4501896 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4501904 constant */
    /* @4501908 constant */
    /* @4501912 constant */
    /* @4501916 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(41));
    /* @4501924 constant */
    /* @4501928 constant */
    /* @4501932 constant */
    /* @4501936 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4501944 constant */
    /* @4501948 constant */
    /* @4501952 constant */
    /* @4501956 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(33));
    /* @4501964 constant */
    /* @4501968 constant */
    /* @4501972 constant */
    /* @4501976 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4501984: ;
    /* @4501984 load */
    /* @4501992 constant */
    /* @4501996 cmp */
    /* @4502000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(4)))) goto L_4502344;
    /* @4502004 constant */
    /* @4502008 constant */
    /* @4502012 constant */
    /* @4502016 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4502024 constant */
    /* @4502028 constant */
    /* @4502032 constant */
    /* @4502036 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4502044 constant */
    /* @4502048 constant */
    /* @4502052 constant */
    /* @4502056 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(37));
    /* @4502064 constant */
    /* @4502068 constant */
    /* @4502072 constant */
    /* @4502076 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4502084 constant */
    /* @4502088 constant */
    /* @4502092 constant */
    /* @4502096 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4502104 constant */
    /* @4502108 constant */
    /* @4502112 constant */
    /* @4502116 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(34));
    /* @4502124 constant */
    /* @4502128 constant */
    /* @4502132 constant */
    /* @4502136 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(45));
    /* @4502144 constant */
    /* @4502148 constant */
    /* @4502152 constant */
    /* @4502156 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(31));
    /* @4502164 constant */
    /* @4502168 constant */
    /* @4502172 constant */
    /* @4502176 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(41));
    /* @4502184 constant */
    /* @4502188 constant */
    /* @4502192 constant */
    /* @4502196 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4502204 constant */
    /* @4502208 constant */
    /* @4502212 constant */
    /* @4502216 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4502224 constant */
    /* @4502228 constant */
    /* @4502232 constant */
    /* @4502236 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(46));
    /* @4502244 constant */
    /* @4502248 constant */
    /* @4502252 constant */
    /* @4502256 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(39));
    /* @4502264 constant */
    /* @4502268 constant */
    /* @4502272 constant */
    /* @4502276 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4502284 constant */
    /* @4502288 constant */
    /* @4502292 constant */
    /* @4502296 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4502304 constant */
    /* @4502308 constant */
    /* @4502312 constant */
    /* @4502316 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(30));
    /* @4502324 constant */
    /* @4502328 constant */
    /* @4502332 constant */
    /* @4502336 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4502344: ;
    /* @4502344 load */
    /* @4502352 constant */
    /* @4502356 cmp */
    /* @4502360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(5)))) goto L_4502704;
    /* @4502364 constant */
    /* @4502368 constant */
    /* @4502372 constant */
    /* @4502376 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4502384 constant */
    /* @4502388 constant */
    /* @4502392 constant */
    /* @4502396 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(30));
    /* @4502404 constant */
    /* @4502408 constant */
    /* @4502412 constant */
    /* @4502416 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4502424 constant */
    /* @4502428 constant */
    /* @4502432 constant */
    /* @4502436 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4502444 constant */
    /* @4502448 constant */
    /* @4502452 constant */
    /* @4502456 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(45));
    /* @4502464 constant */
    /* @4502468 constant */
    /* @4502472 constant */
    /* @4502476 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(52));
    /* @4502484 constant */
    /* @4502488 constant */
    /* @4502492 constant */
    /* @4502496 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4502504 constant */
    /* @4502508 constant */
    /* @4502512 constant */
    /* @4502516 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4502524 constant */
    /* @4502528 constant */
    /* @4502532 constant */
    /* @4502536 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(34));
    /* @4502544 constant */
    /* @4502548 constant */
    /* @4502552 constant */
    /* @4502556 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(46));
    /* @4502564 constant */
    /* @4502568 constant */
    /* @4502572 constant */
    /* @4502576 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4502584 constant */
    /* @4502588 constant */
    /* @4502592 constant */
    /* @4502596 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4502604 constant */
    /* @4502608 constant */
    /* @4502612 constant */
    /* @4502616 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(37));
    /* @4502624 constant */
    /* @4502628 constant */
    /* @4502632 constant */
    /* @4502636 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(36));
    /* @4502644 constant */
    /* @4502648 constant */
    /* @4502652 constant */
    /* @4502656 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(32));
    /* @4502664 constant */
    /* @4502668 constant */
    /* @4502672 constant */
    /* @4502676 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(38));
    /* @4502684 constant */
    /* @4502688 constant */
    /* @4502692 constant */
    /* @4502696 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(39));
    L_4502704: ;
    /* @4502704 load */
    /* @4502712 constant */
    /* @4502716 cmp */
    /* @4502720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(6)))) goto L_4503064;
    /* @4502724 constant */
    /* @4502728 constant */
    /* @4502732 constant */
    /* @4502736 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4502744 constant */
    /* @4502748 constant */
    /* @4502752 constant */
    /* @4502756 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(37));
    /* @4502764 constant */
    /* @4502768 constant */
    /* @4502772 constant */
    /* @4502776 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(44));
    /* @4502784 constant */
    /* @4502788 constant */
    /* @4502792 constant */
    /* @4502796 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4502804 constant */
    /* @4502808 constant */
    /* @4502812 constant */
    /* @4502816 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4502824 constant */
    /* @4502828 constant */
    /* @4502832 constant */
    /* @4502836 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(41));
    /* @4502844 constant */
    /* @4502848 constant */
    /* @4502852 constant */
    /* @4502856 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4502864 constant */
    /* @4502868 constant */
    /* @4502872 constant */
    /* @4502876 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4502884 constant */
    /* @4502888 constant */
    /* @4502892 constant */
    /* @4502896 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(35));
    /* @4502904 constant */
    /* @4502908 constant */
    /* @4502912 constant */
    /* @4502916 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4502924 constant */
    /* @4502928 constant */
    /* @4502932 constant */
    /* @4502936 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4502944 constant */
    /* @4502948 constant */
    /* @4502952 constant */
    /* @4502956 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(30));
    /* @4502964 constant */
    /* @4502968 constant */
    /* @4502972 constant */
    /* @4502976 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(38));
    /* @4502984 constant */
    /* @4502988 constant */
    /* @4502992 constant */
    /* @4502996 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4503004 constant */
    /* @4503008 constant */
    /* @4503012 constant */
    /* @4503016 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4503024 constant */
    /* @4503028 constant */
    /* @4503032 constant */
    /* @4503036 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(52));
    /* @4503044 constant */
    /* @4503048 constant */
    /* @4503052 constant */
    /* @4503056 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4503064: ;
    /* @4503064 load */
    /* @4503072 constant */
    /* @4503076 cmp */
    /* @4503080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(7)))) goto L_4503424;
    /* @4503084 constant */
    /* @4503088 constant */
    /* @4503092 constant */
    /* @4503096 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4503104 constant */
    /* @4503108 constant */
    /* @4503112 constant */
    /* @4503116 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(47));
    /* @4503124 constant */
    /* @4503128 constant */
    /* @4503132 constant */
    /* @4503136 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(32));
    /* @4503144 constant */
    /* @4503148 constant */
    /* @4503152 constant */
    /* @4503156 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4503164 constant */
    /* @4503168 constant */
    /* @4503172 constant */
    /* @4503176 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(46));
    /* @4503184 constant */
    /* @4503188 constant */
    /* @4503192 constant */
    /* @4503196 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(38));
    /* @4503204 constant */
    /* @4503208 constant */
    /* @4503212 constant */
    /* @4503216 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(44));
    /* @4503224 constant */
    /* @4503228 constant */
    /* @4503232 constant */
    /* @4503236 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4503244 constant */
    /* @4503248 constant */
    /* @4503252 constant */
    /* @4503256 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4503264 constant */
    /* @4503268 constant */
    /* @4503272 constant */
    /* @4503276 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4503284 constant */
    /* @4503288 constant */
    /* @4503292 constant */
    /* @4503296 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(52));
    /* @4503304 constant */
    /* @4503308 constant */
    /* @4503312 constant */
    /* @4503316 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(37));
    /* @4503324 constant */
    /* @4503328 constant */
    /* @4503332 constant */
    /* @4503336 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(30));
    /* @4503344 constant */
    /* @4503348 constant */
    /* @4503352 constant */
    /* @4503356 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(33));
    /* @4503364 constant */
    /* @4503368 constant */
    /* @4503372 constant */
    /* @4503376 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(31));
    /* @4503384 constant */
    /* @4503388 constant */
    /* @4503392 constant */
    /* @4503396 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(45));
    /* @4503404 constant */
    /* @4503408 constant */
    /* @4503412 constant */
    /* @4503416 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(35));
    L_4503424: ;
    /* @4503424 load */
    /* @4503432 constant */
    /* @4503436 cmp */
    /* @4503440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(8)))) goto L_4503784;
    /* @4503444 constant */
    /* @4503448 constant */
    /* @4503452 constant */
    /* @4503456 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(34));
    /* @4503464 constant */
    /* @4503468 constant */
    /* @4503472 constant */
    /* @4503476 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(38));
    /* @4503484 constant */
    /* @4503488 constant */
    /* @4503492 constant */
    /* @4503496 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(33));
    /* @4503504 constant */
    /* @4503508 constant */
    /* @4503512 constant */
    /* @4503516 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(52));
    /* @4503524 constant */
    /* @4503528 constant */
    /* @4503532 constant */
    /* @4503536 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4503544 constant */
    /* @4503548 constant */
    /* @4503552 constant */
    /* @4503556 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(37));
    /* @4503564 constant */
    /* @4503568 constant */
    /* @4503572 constant */
    /* @4503576 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4503584 constant */
    /* @4503588 constant */
    /* @4503592 constant */
    /* @4503596 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4503604 constant */
    /* @4503608 constant */
    /* @4503612 constant */
    /* @4503616 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(46));
    /* @4503624 constant */
    /* @4503628 constant */
    /* @4503632 constant */
    /* @4503636 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4503644 constant */
    /* @4503648 constant */
    /* @4503652 constant */
    /* @4503656 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4503664 constant */
    /* @4503668 constant */
    /* @4503672 constant */
    /* @4503676 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4503684 constant */
    /* @4503688 constant */
    /* @4503692 constant */
    /* @4503696 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(35));
    /* @4503704 constant */
    /* @4503708 constant */
    /* @4503712 constant */
    /* @4503716 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(30));
    /* @4503724 constant */
    /* @4503728 constant */
    /* @4503732 constant */
    /* @4503736 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4503744 constant */
    /* @4503748 constant */
    /* @4503752 constant */
    /* @4503756 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(32));
    /* @4503764 constant */
    /* @4503768 constant */
    /* @4503772 constant */
    /* @4503776 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(45));
    L_4503784: ;
    /* @4503784 load */
    /* @4503792 constant */
    /* @4503796 cmp */
    /* @4503800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(9)))) goto L_4504144;
    /* @4503804 constant */
    /* @4503808 constant */
    /* @4503812 constant */
    /* @4503816 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4503824 constant */
    /* @4503828 constant */
    /* @4503832 constant */
    /* @4503836 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(44));
    /* @4503844 constant */
    /* @4503848 constant */
    /* @4503852 constant */
    /* @4503856 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4503864 constant */
    /* @4503868 constant */
    /* @4503872 constant */
    /* @4503876 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4503884 constant */
    /* @4503888 constant */
    /* @4503892 constant */
    /* @4503896 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(33));
    /* @4503904 constant */
    /* @4503908 constant */
    /* @4503912 constant */
    /* @4503916 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(35));
    /* @4503924 constant */
    /* @4503928 constant */
    /* @4503932 constant */
    /* @4503936 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(37));
    /* @4503944 constant */
    /* @4503948 constant */
    /* @4503952 constant */
    /* @4503956 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(38));
    /* @4503964 constant */
    /* @4503968 constant */
    /* @4503972 constant */
    /* @4503976 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(30));
    /* @4503984 constant */
    /* @4503988 constant */
    /* @4503992 constant */
    /* @4503996 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(32));
    /* @4504004 constant */
    /* @4504008 constant */
    /* @4504012 constant */
    /* @4504016 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(39));
    /* @4504024 constant */
    /* @4504028 constant */
    /* @4504032 constant */
    /* @4504036 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4504044 constant */
    /* @4504048 constant */
    /* @4504052 constant */
    /* @4504056 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(46));
    /* @4504064 constant */
    /* @4504068 constant */
    /* @4504072 constant */
    /* @4504076 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(47));
    /* @4504084 constant */
    /* @4504088 constant */
    /* @4504092 constant */
    /* @4504096 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4504104 constant */
    /* @4504108 constant */
    /* @4504112 constant */
    /* @4504116 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4504124 constant */
    /* @4504128 constant */
    /* @4504132 constant */
    /* @4504136 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(41));
    L_4504144: ;
    /* @4504144 load */
    /* @4504152 constant */
    /* @4504156 cmp */
    /* @4504160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(10)))) goto L_4504504;
    /* @4504164 constant */
    /* @4504168 constant */
    /* @4504172 constant */
    /* @4504176 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4504184 constant */
    /* @4504188 constant */
    /* @4504192 constant */
    /* @4504196 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4504204 constant */
    /* @4504208 constant */
    /* @4504212 constant */
    /* @4504216 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4504224 constant */
    /* @4504228 constant */
    /* @4504232 constant */
    /* @4504236 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(30));
    /* @4504244 constant */
    /* @4504248 constant */
    /* @4504252 constant */
    /* @4504256 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(31));
    /* @4504264 constant */
    /* @4504268 constant */
    /* @4504272 constant */
    /* @4504276 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(33));
    /* @4504284 constant */
    /* @4504288 constant */
    /* @4504292 constant */
    /* @4504296 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(34));
    /* @4504304 constant */
    /* @4504308 constant */
    /* @4504312 constant */
    /* @4504316 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4504324 constant */
    /* @4504328 constant */
    /* @4504332 constant */
    /* @4504336 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4504344 constant */
    /* @4504348 constant */
    /* @4504352 constant */
    /* @4504356 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(41));
    /* @4504364 constant */
    /* @4504368 constant */
    /* @4504372 constant */
    /* @4504376 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(38));
    /* @4504384 constant */
    /* @4504388 constant */
    /* @4504392 constant */
    /* @4504396 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(39));
    /* @4504404 constant */
    /* @4504408 constant */
    /* @4504412 constant */
    /* @4504416 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(47));
    /* @4504424 constant */
    /* @4504428 constant */
    /* @4504432 constant */
    /* @4504436 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4504444 constant */
    /* @4504448 constant */
    /* @4504452 constant */
    /* @4504456 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(44));
    /* @4504464 constant */
    /* @4504468 constant */
    /* @4504472 constant */
    /* @4504476 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4504484 constant */
    /* @4504488 constant */
    /* @4504492 constant */
    /* @4504496 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(37));
    L_4504504: ;
    /* @4504504 load */
    /* @4504512 constant */
    /* @4504516 cmp */
    /* @4504520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_4508252;
    /* @4504524 call */
    GM_SITE(vm, 378, 4504524);
    /* @4504532 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4504536 constant */
    /* @4504540 constant */
    /* @4504544 constant */
    /* @4504548 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4504556 constant */
    /* @4504560 cast */
    /* @4504564 constant */
    /* @4504568 cast */
    /* @4504572 constant */
    /* @4504576 cast */
    /* @4504580 constant */
    /* @4504584 cast */
    /* @4504588 constant */
    /* @4504592 cast */
    /* @4504596 constant */
    /* @4504600 cast */
    /* @4504604 constant */
    /* @4504608 cast */
    /* @4504612 constant */
    /* @4504616 cast */
    /* @4504620 constant */
    /* @4504624 cast */
    /* @4504628 constant */
    /* @4504632 cast */
    /* @4504636 call */
    GM_SITE(vm, 378, 4504636);
    /* @4504644 store */
    v3 = GM_CALL(vm, "choose", 10, VAL(2), VAL(4), VAL(6), VAL(8), VAL(10), VAL(1), VAL(3), VAL(5), VAL(7), VAL(9));
    GM_WRITE(vm, -1, "playlist", v3);
    /* @4504652 load */
    /* @4504660 constant */
    /* @4504664 cmp */
    /* @4504668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(1)))) goto L_4505012;
    /* @4504672 constant */
    /* @4504676 constant */
    /* @4504680 constant */
    /* @4504684 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(37));
    /* @4504692 constant */
    /* @4504696 constant */
    /* @4504700 constant */
    /* @4504704 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(46));
    /* @4504712 constant */
    /* @4504716 constant */
    /* @4504720 constant */
    /* @4504724 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4504732 constant */
    /* @4504736 constant */
    /* @4504740 constant */
    /* @4504744 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(31));
    /* @4504752 constant */
    /* @4504756 constant */
    /* @4504760 constant */
    /* @4504764 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4504772 constant */
    /* @4504776 constant */
    /* @4504780 constant */
    /* @4504784 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(44));
    /* @4504792 constant */
    /* @4504796 constant */
    /* @4504800 constant */
    /* @4504804 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(30));
    /* @4504812 constant */
    /* @4504816 constant */
    /* @4504820 constant */
    /* @4504824 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(45));
    /* @4504832 constant */
    /* @4504836 constant */
    /* @4504840 constant */
    /* @4504844 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(39));
    /* @4504852 constant */
    /* @4504856 constant */
    /* @4504860 constant */
    /* @4504864 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4504872 constant */
    /* @4504876 constant */
    /* @4504880 constant */
    /* @4504884 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(34));
    /* @4504892 constant */
    /* @4504896 constant */
    /* @4504900 constant */
    /* @4504904 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4504912 constant */
    /* @4504916 constant */
    /* @4504920 constant */
    /* @4504924 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(52));
    /* @4504932 constant */
    /* @4504936 constant */
    /* @4504940 constant */
    /* @4504944 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4504952 constant */
    /* @4504956 constant */
    /* @4504960 constant */
    /* @4504964 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4504972 constant */
    /* @4504976 constant */
    /* @4504980 constant */
    /* @4504984 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(47));
    /* @4504992 constant */
    /* @4504996 constant */
    /* @4505000 constant */
    /* @4505004 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4505012: ;
    /* @4505012 load */
    /* @4505020 constant */
    /* @4505024 cmp */
    /* @4505028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(2)))) goto L_4505372;
    /* @4505032 constant */
    /* @4505036 constant */
    /* @4505040 constant */
    /* @4505044 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(44));
    /* @4505052 constant */
    /* @4505056 constant */
    /* @4505060 constant */
    /* @4505064 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4505072 constant */
    /* @4505076 constant */
    /* @4505080 constant */
    /* @4505084 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4505092 constant */
    /* @4505096 constant */
    /* @4505100 constant */
    /* @4505104 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(45));
    /* @4505112 constant */
    /* @4505116 constant */
    /* @4505120 constant */
    /* @4505124 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(38));
    /* @4505132 constant */
    /* @4505136 constant */
    /* @4505140 constant */
    /* @4505144 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(46));
    /* @4505152 constant */
    /* @4505156 constant */
    /* @4505160 constant */
    /* @4505164 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4505172 constant */
    /* @4505176 constant */
    /* @4505180 constant */
    /* @4505184 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(37));
    /* @4505192 constant */
    /* @4505196 constant */
    /* @4505200 constant */
    /* @4505204 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(32));
    /* @4505212 constant */
    /* @4505216 constant */
    /* @4505220 constant */
    /* @4505224 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4505232 constant */
    /* @4505236 constant */
    /* @4505240 constant */
    /* @4505244 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(30));
    /* @4505252 constant */
    /* @4505256 constant */
    /* @4505260 constant */
    /* @4505264 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(35));
    /* @4505272 constant */
    /* @4505276 constant */
    /* @4505280 constant */
    /* @4505284 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4505292 constant */
    /* @4505296 constant */
    /* @4505300 constant */
    /* @4505304 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(31));
    /* @4505312 constant */
    /* @4505316 constant */
    /* @4505320 constant */
    /* @4505324 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4505332 constant */
    /* @4505336 constant */
    /* @4505340 constant */
    /* @4505344 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4505352 constant */
    /* @4505356 constant */
    /* @4505360 constant */
    /* @4505364 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(47));
    L_4505372: ;
    /* @4505372 load */
    /* @4505380 constant */
    /* @4505384 cmp */
    /* @4505388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(3)))) goto L_4505732;
    /* @4505392 constant */
    /* @4505396 constant */
    /* @4505400 constant */
    /* @4505404 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4505412 constant */
    /* @4505416 constant */
    /* @4505420 constant */
    /* @4505424 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(35));
    /* @4505432 constant */
    /* @4505436 constant */
    /* @4505440 constant */
    /* @4505444 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(39));
    /* @4505452 constant */
    /* @4505456 constant */
    /* @4505460 constant */
    /* @4505464 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(37));
    /* @4505472 constant */
    /* @4505476 constant */
    /* @4505480 constant */
    /* @4505484 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4505492 constant */
    /* @4505496 constant */
    /* @4505500 constant */
    /* @4505504 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(30));
    /* @4505512 constant */
    /* @4505516 constant */
    /* @4505520 constant */
    /* @4505524 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(46));
    /* @4505532 constant */
    /* @4505536 constant */
    /* @4505540 constant */
    /* @4505544 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4505552 constant */
    /* @4505556 constant */
    /* @4505560 constant */
    /* @4505564 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(38));
    /* @4505572 constant */
    /* @4505576 constant */
    /* @4505580 constant */
    /* @4505584 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(31));
    /* @4505592 constant */
    /* @4505596 constant */
    /* @4505600 constant */
    /* @4505604 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4505612 constant */
    /* @4505616 constant */
    /* @4505620 constant */
    /* @4505624 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(32));
    /* @4505632 constant */
    /* @4505636 constant */
    /* @4505640 constant */
    /* @4505644 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4505652 constant */
    /* @4505656 constant */
    /* @4505660 constant */
    /* @4505664 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(41));
    /* @4505672 constant */
    /* @4505676 constant */
    /* @4505680 constant */
    /* @4505684 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4505692 constant */
    /* @4505696 constant */
    /* @4505700 constant */
    /* @4505704 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(33));
    /* @4505712 constant */
    /* @4505716 constant */
    /* @4505720 constant */
    /* @4505724 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4505732: ;
    /* @4505732 load */
    /* @4505740 constant */
    /* @4505744 cmp */
    /* @4505748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(4)))) goto L_4506092;
    /* @4505752 constant */
    /* @4505756 constant */
    /* @4505760 constant */
    /* @4505764 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4505772 constant */
    /* @4505776 constant */
    /* @4505780 constant */
    /* @4505784 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4505792 constant */
    /* @4505796 constant */
    /* @4505800 constant */
    /* @4505804 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(37));
    /* @4505812 constant */
    /* @4505816 constant */
    /* @4505820 constant */
    /* @4505824 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4505832 constant */
    /* @4505836 constant */
    /* @4505840 constant */
    /* @4505844 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4505852 constant */
    /* @4505856 constant */
    /* @4505860 constant */
    /* @4505864 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(34));
    /* @4505872 constant */
    /* @4505876 constant */
    /* @4505880 constant */
    /* @4505884 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(45));
    /* @4505892 constant */
    /* @4505896 constant */
    /* @4505900 constant */
    /* @4505904 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(31));
    /* @4505912 constant */
    /* @4505916 constant */
    /* @4505920 constant */
    /* @4505924 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(41));
    /* @4505932 constant */
    /* @4505936 constant */
    /* @4505940 constant */
    /* @4505944 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4505952 constant */
    /* @4505956 constant */
    /* @4505960 constant */
    /* @4505964 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4505972 constant */
    /* @4505976 constant */
    /* @4505980 constant */
    /* @4505984 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(46));
    /* @4505992 constant */
    /* @4505996 constant */
    /* @4506000 constant */
    /* @4506004 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(39));
    /* @4506012 constant */
    /* @4506016 constant */
    /* @4506020 constant */
    /* @4506024 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4506032 constant */
    /* @4506036 constant */
    /* @4506040 constant */
    /* @4506044 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4506052 constant */
    /* @4506056 constant */
    /* @4506060 constant */
    /* @4506064 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(30));
    /* @4506072 constant */
    /* @4506076 constant */
    /* @4506080 constant */
    /* @4506084 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4506092: ;
    /* @4506092 load */
    /* @4506100 constant */
    /* @4506104 cmp */
    /* @4506108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(5)))) goto L_4506452;
    /* @4506112 constant */
    /* @4506116 constant */
    /* @4506120 constant */
    /* @4506124 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4506132 constant */
    /* @4506136 constant */
    /* @4506140 constant */
    /* @4506144 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(30));
    /* @4506152 constant */
    /* @4506156 constant */
    /* @4506160 constant */
    /* @4506164 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4506172 constant */
    /* @4506176 constant */
    /* @4506180 constant */
    /* @4506184 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4506192 constant */
    /* @4506196 constant */
    /* @4506200 constant */
    /* @4506204 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(45));
    /* @4506212 constant */
    /* @4506216 constant */
    /* @4506220 constant */
    /* @4506224 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(52));
    /* @4506232 constant */
    /* @4506236 constant */
    /* @4506240 constant */
    /* @4506244 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4506252 constant */
    /* @4506256 constant */
    /* @4506260 constant */
    /* @4506264 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4506272 constant */
    /* @4506276 constant */
    /* @4506280 constant */
    /* @4506284 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(34));
    /* @4506292 constant */
    /* @4506296 constant */
    /* @4506300 constant */
    /* @4506304 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(46));
    /* @4506312 constant */
    /* @4506316 constant */
    /* @4506320 constant */
    /* @4506324 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4506332 constant */
    /* @4506336 constant */
    /* @4506340 constant */
    /* @4506344 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4506352 constant */
    /* @4506356 constant */
    /* @4506360 constant */
    /* @4506364 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(37));
    /* @4506372 constant */
    /* @4506376 constant */
    /* @4506380 constant */
    /* @4506384 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(36));
    /* @4506392 constant */
    /* @4506396 constant */
    /* @4506400 constant */
    /* @4506404 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(32));
    /* @4506412 constant */
    /* @4506416 constant */
    /* @4506420 constant */
    /* @4506424 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(38));
    /* @4506432 constant */
    /* @4506436 constant */
    /* @4506440 constant */
    /* @4506444 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(39));
    L_4506452: ;
    /* @4506452 load */
    /* @4506460 constant */
    /* @4506464 cmp */
    /* @4506468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(6)))) goto L_4506812;
    /* @4506472 constant */
    /* @4506476 constant */
    /* @4506480 constant */
    /* @4506484 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4506492 constant */
    /* @4506496 constant */
    /* @4506500 constant */
    /* @4506504 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(37));
    /* @4506512 constant */
    /* @4506516 constant */
    /* @4506520 constant */
    /* @4506524 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(44));
    /* @4506532 constant */
    /* @4506536 constant */
    /* @4506540 constant */
    /* @4506544 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4506552 constant */
    /* @4506556 constant */
    /* @4506560 constant */
    /* @4506564 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4506572 constant */
    /* @4506576 constant */
    /* @4506580 constant */
    /* @4506584 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(41));
    /* @4506592 constant */
    /* @4506596 constant */
    /* @4506600 constant */
    /* @4506604 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4506612 constant */
    /* @4506616 constant */
    /* @4506620 constant */
    /* @4506624 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4506632 constant */
    /* @4506636 constant */
    /* @4506640 constant */
    /* @4506644 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(35));
    /* @4506652 constant */
    /* @4506656 constant */
    /* @4506660 constant */
    /* @4506664 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4506672 constant */
    /* @4506676 constant */
    /* @4506680 constant */
    /* @4506684 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4506692 constant */
    /* @4506696 constant */
    /* @4506700 constant */
    /* @4506704 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(30));
    /* @4506712 constant */
    /* @4506716 constant */
    /* @4506720 constant */
    /* @4506724 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(38));
    /* @4506732 constant */
    /* @4506736 constant */
    /* @4506740 constant */
    /* @4506744 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4506752 constant */
    /* @4506756 constant */
    /* @4506760 constant */
    /* @4506764 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4506772 constant */
    /* @4506776 constant */
    /* @4506780 constant */
    /* @4506784 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(52));
    /* @4506792 constant */
    /* @4506796 constant */
    /* @4506800 constant */
    /* @4506804 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4506812: ;
    /* @4506812 load */
    /* @4506820 constant */
    /* @4506824 cmp */
    /* @4506828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(7)))) goto L_4507172;
    /* @4506832 constant */
    /* @4506836 constant */
    /* @4506840 constant */
    /* @4506844 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4506852 constant */
    /* @4506856 constant */
    /* @4506860 constant */
    /* @4506864 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(47));
    /* @4506872 constant */
    /* @4506876 constant */
    /* @4506880 constant */
    /* @4506884 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(32));
    /* @4506892 constant */
    /* @4506896 constant */
    /* @4506900 constant */
    /* @4506904 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4506912 constant */
    /* @4506916 constant */
    /* @4506920 constant */
    /* @4506924 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(46));
    /* @4506932 constant */
    /* @4506936 constant */
    /* @4506940 constant */
    /* @4506944 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(38));
    /* @4506952 constant */
    /* @4506956 constant */
    /* @4506960 constant */
    /* @4506964 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(44));
    /* @4506972 constant */
    /* @4506976 constant */
    /* @4506980 constant */
    /* @4506984 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4506992 constant */
    /* @4506996 constant */
    /* @4507000 constant */
    /* @4507004 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4507012 constant */
    /* @4507016 constant */
    /* @4507020 constant */
    /* @4507024 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4507032 constant */
    /* @4507036 constant */
    /* @4507040 constant */
    /* @4507044 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(52));
    /* @4507052 constant */
    /* @4507056 constant */
    /* @4507060 constant */
    /* @4507064 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(37));
    /* @4507072 constant */
    /* @4507076 constant */
    /* @4507080 constant */
    /* @4507084 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(30));
    /* @4507092 constant */
    /* @4507096 constant */
    /* @4507100 constant */
    /* @4507104 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(33));
    /* @4507112 constant */
    /* @4507116 constant */
    /* @4507120 constant */
    /* @4507124 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(31));
    /* @4507132 constant */
    /* @4507136 constant */
    /* @4507140 constant */
    /* @4507144 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(45));
    /* @4507152 constant */
    /* @4507156 constant */
    /* @4507160 constant */
    /* @4507164 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(35));
    L_4507172: ;
    /* @4507172 load */
    /* @4507180 constant */
    /* @4507184 cmp */
    /* @4507188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(8)))) goto L_4507532;
    /* @4507192 constant */
    /* @4507196 constant */
    /* @4507200 constant */
    /* @4507204 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(34));
    /* @4507212 constant */
    /* @4507216 constant */
    /* @4507220 constant */
    /* @4507224 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(38));
    /* @4507232 constant */
    /* @4507236 constant */
    /* @4507240 constant */
    /* @4507244 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(33));
    /* @4507252 constant */
    /* @4507256 constant */
    /* @4507260 constant */
    /* @4507264 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(52));
    /* @4507272 constant */
    /* @4507276 constant */
    /* @4507280 constant */
    /* @4507284 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4507292 constant */
    /* @4507296 constant */
    /* @4507300 constant */
    /* @4507304 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(37));
    /* @4507312 constant */
    /* @4507316 constant */
    /* @4507320 constant */
    /* @4507324 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4507332 constant */
    /* @4507336 constant */
    /* @4507340 constant */
    /* @4507344 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4507352 constant */
    /* @4507356 constant */
    /* @4507360 constant */
    /* @4507364 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(46));
    /* @4507372 constant */
    /* @4507376 constant */
    /* @4507380 constant */
    /* @4507384 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4507392 constant */
    /* @4507396 constant */
    /* @4507400 constant */
    /* @4507404 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4507412 constant */
    /* @4507416 constant */
    /* @4507420 constant */
    /* @4507424 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4507432 constant */
    /* @4507436 constant */
    /* @4507440 constant */
    /* @4507444 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(35));
    /* @4507452 constant */
    /* @4507456 constant */
    /* @4507460 constant */
    /* @4507464 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(30));
    /* @4507472 constant */
    /* @4507476 constant */
    /* @4507480 constant */
    /* @4507484 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4507492 constant */
    /* @4507496 constant */
    /* @4507500 constant */
    /* @4507504 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(32));
    /* @4507512 constant */
    /* @4507516 constant */
    /* @4507520 constant */
    /* @4507524 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(45));
    L_4507532: ;
    /* @4507532 load */
    /* @4507540 constant */
    /* @4507544 cmp */
    /* @4507548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(9)))) goto L_4507892;
    /* @4507552 constant */
    /* @4507556 constant */
    /* @4507560 constant */
    /* @4507564 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4507572 constant */
    /* @4507576 constant */
    /* @4507580 constant */
    /* @4507584 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(44));
    /* @4507592 constant */
    /* @4507596 constant */
    /* @4507600 constant */
    /* @4507604 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4507612 constant */
    /* @4507616 constant */
    /* @4507620 constant */
    /* @4507624 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4507632 constant */
    /* @4507636 constant */
    /* @4507640 constant */
    /* @4507644 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(33));
    /* @4507652 constant */
    /* @4507656 constant */
    /* @4507660 constant */
    /* @4507664 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(35));
    /* @4507672 constant */
    /* @4507676 constant */
    /* @4507680 constant */
    /* @4507684 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(37));
    /* @4507692 constant */
    /* @4507696 constant */
    /* @4507700 constant */
    /* @4507704 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(38));
    /* @4507712 constant */
    /* @4507716 constant */
    /* @4507720 constant */
    /* @4507724 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(30));
    /* @4507732 constant */
    /* @4507736 constant */
    /* @4507740 constant */
    /* @4507744 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(32));
    /* @4507752 constant */
    /* @4507756 constant */
    /* @4507760 constant */
    /* @4507764 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(39));
    /* @4507772 constant */
    /* @4507776 constant */
    /* @4507780 constant */
    /* @4507784 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4507792 constant */
    /* @4507796 constant */
    /* @4507800 constant */
    /* @4507804 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(46));
    /* @4507812 constant */
    /* @4507816 constant */
    /* @4507820 constant */
    /* @4507824 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(47));
    /* @4507832 constant */
    /* @4507836 constant */
    /* @4507840 constant */
    /* @4507844 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4507852 constant */
    /* @4507856 constant */
    /* @4507860 constant */
    /* @4507864 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4507872 constant */
    /* @4507876 constant */
    /* @4507880 constant */
    /* @4507884 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(41));
    L_4507892: ;
    /* @4507892 load */
    /* @4507900 constant */
    /* @4507904 cmp */
    /* @4507908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(10)))) goto L_4508252;
    /* @4507912 constant */
    /* @4507916 constant */
    /* @4507920 constant */
    /* @4507924 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4507932 constant */
    /* @4507936 constant */
    /* @4507940 constant */
    /* @4507944 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4507952 constant */
    /* @4507956 constant */
    /* @4507960 constant */
    /* @4507964 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4507972 constant */
    /* @4507976 constant */
    /* @4507980 constant */
    /* @4507984 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(30));
    /* @4507992 constant */
    /* @4507996 constant */
    /* @4508000 constant */
    /* @4508004 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(31));
    /* @4508012 constant */
    /* @4508016 constant */
    /* @4508020 constant */
    /* @4508024 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(33));
    /* @4508032 constant */
    /* @4508036 constant */
    /* @4508040 constant */
    /* @4508044 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(34));
    /* @4508052 constant */
    /* @4508056 constant */
    /* @4508060 constant */
    /* @4508064 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4508072 constant */
    /* @4508076 constant */
    /* @4508080 constant */
    /* @4508084 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4508092 constant */
    /* @4508096 constant */
    /* @4508100 constant */
    /* @4508104 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(41));
    /* @4508112 constant */
    /* @4508116 constant */
    /* @4508120 constant */
    /* @4508124 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(38));
    /* @4508132 constant */
    /* @4508136 constant */
    /* @4508140 constant */
    /* @4508144 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(39));
    /* @4508152 constant */
    /* @4508156 constant */
    /* @4508160 constant */
    /* @4508164 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(47));
    /* @4508172 constant */
    /* @4508176 constant */
    /* @4508180 constant */
    /* @4508184 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4508192 constant */
    /* @4508196 constant */
    /* @4508200 constant */
    /* @4508204 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(44));
    /* @4508212 constant */
    /* @4508216 constant */
    /* @4508220 constant */
    /* @4508224 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4508232 constant */
    /* @4508236 constant */
    /* @4508240 constant */
    /* @4508244 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(37));
    L_4508252: ;
    /* @4508252 load */
    /* @4508260 constant */
    /* @4508264 cmp */
    /* @4508268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_4512000;
    /* @4508272 call */
    GM_SITE(vm, 378, 4508272);
    /* @4508280 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4508284 constant */
    /* @4508288 constant */
    /* @4508292 constant */
    /* @4508296 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4508304 constant */
    /* @4508308 cast */
    /* @4508312 constant */
    /* @4508316 cast */
    /* @4508320 constant */
    /* @4508324 cast */
    /* @4508328 constant */
    /* @4508332 cast */
    /* @4508336 constant */
    /* @4508340 cast */
    /* @4508344 constant */
    /* @4508348 cast */
    /* @4508352 constant */
    /* @4508356 cast */
    /* @4508360 constant */
    /* @4508364 cast */
    /* @4508368 constant */
    /* @4508372 cast */
    /* @4508376 constant */
    /* @4508380 cast */
    /* @4508384 call */
    GM_SITE(vm, 378, 4508384);
    /* @4508392 store */
    v4 = GM_CALL(vm, "choose", 10, VAL(2), VAL(4), VAL(6), VAL(8), VAL(10), VAL(1), VAL(3), VAL(5), VAL(7), VAL(9));
    GM_WRITE(vm, -1, "playlist", v4);
    /* @4508400 load */
    /* @4508408 constant */
    /* @4508412 cmp */
    /* @4508416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(1)))) goto L_4508760;
    /* @4508420 constant */
    /* @4508424 constant */
    /* @4508428 constant */
    /* @4508432 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(37));
    /* @4508440 constant */
    /* @4508444 constant */
    /* @4508448 constant */
    /* @4508452 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(46));
    /* @4508460 constant */
    /* @4508464 constant */
    /* @4508468 constant */
    /* @4508472 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4508480 constant */
    /* @4508484 constant */
    /* @4508488 constant */
    /* @4508492 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(31));
    /* @4508500 constant */
    /* @4508504 constant */
    /* @4508508 constant */
    /* @4508512 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4508520 constant */
    /* @4508524 constant */
    /* @4508528 constant */
    /* @4508532 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(44));
    /* @4508540 constant */
    /* @4508544 constant */
    /* @4508548 constant */
    /* @4508552 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(30));
    /* @4508560 constant */
    /* @4508564 constant */
    /* @4508568 constant */
    /* @4508572 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(45));
    /* @4508580 constant */
    /* @4508584 constant */
    /* @4508588 constant */
    /* @4508592 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(39));
    /* @4508600 constant */
    /* @4508604 constant */
    /* @4508608 constant */
    /* @4508612 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4508620 constant */
    /* @4508624 constant */
    /* @4508628 constant */
    /* @4508632 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(34));
    /* @4508640 constant */
    /* @4508644 constant */
    /* @4508648 constant */
    /* @4508652 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4508660 constant */
    /* @4508664 constant */
    /* @4508668 constant */
    /* @4508672 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(52));
    /* @4508680 constant */
    /* @4508684 constant */
    /* @4508688 constant */
    /* @4508692 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4508700 constant */
    /* @4508704 constant */
    /* @4508708 constant */
    /* @4508712 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4508720 constant */
    /* @4508724 constant */
    /* @4508728 constant */
    /* @4508732 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(47));
    /* @4508740 constant */
    /* @4508744 constant */
    /* @4508748 constant */
    /* @4508752 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4508760: ;
    /* @4508760 load */
    /* @4508768 constant */
    /* @4508772 cmp */
    /* @4508776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(2)))) goto L_4509120;
    /* @4508780 constant */
    /* @4508784 constant */
    /* @4508788 constant */
    /* @4508792 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(44));
    /* @4508800 constant */
    /* @4508804 constant */
    /* @4508808 constant */
    /* @4508812 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4508820 constant */
    /* @4508824 constant */
    /* @4508828 constant */
    /* @4508832 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4508840 constant */
    /* @4508844 constant */
    /* @4508848 constant */
    /* @4508852 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(45));
    /* @4508860 constant */
    /* @4508864 constant */
    /* @4508868 constant */
    /* @4508872 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(38));
    /* @4508880 constant */
    /* @4508884 constant */
    /* @4508888 constant */
    /* @4508892 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(46));
    /* @4508900 constant */
    /* @4508904 constant */
    /* @4508908 constant */
    /* @4508912 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4508920 constant */
    /* @4508924 constant */
    /* @4508928 constant */
    /* @4508932 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(37));
    /* @4508940 constant */
    /* @4508944 constant */
    /* @4508948 constant */
    /* @4508952 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(32));
    /* @4508960 constant */
    /* @4508964 constant */
    /* @4508968 constant */
    /* @4508972 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4508980 constant */
    /* @4508984 constant */
    /* @4508988 constant */
    /* @4508992 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(30));
    /* @4509000 constant */
    /* @4509004 constant */
    /* @4509008 constant */
    /* @4509012 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(35));
    /* @4509020 constant */
    /* @4509024 constant */
    /* @4509028 constant */
    /* @4509032 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4509040 constant */
    /* @4509044 constant */
    /* @4509048 constant */
    /* @4509052 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(31));
    /* @4509060 constant */
    /* @4509064 constant */
    /* @4509068 constant */
    /* @4509072 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4509080 constant */
    /* @4509084 constant */
    /* @4509088 constant */
    /* @4509092 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4509100 constant */
    /* @4509104 constant */
    /* @4509108 constant */
    /* @4509112 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(47));
    L_4509120: ;
    /* @4509120 load */
    /* @4509128 constant */
    /* @4509132 cmp */
    /* @4509136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(3)))) goto L_4509480;
    /* @4509140 constant */
    /* @4509144 constant */
    /* @4509148 constant */
    /* @4509152 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4509160 constant */
    /* @4509164 constant */
    /* @4509168 constant */
    /* @4509172 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(35));
    /* @4509180 constant */
    /* @4509184 constant */
    /* @4509188 constant */
    /* @4509192 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(39));
    /* @4509200 constant */
    /* @4509204 constant */
    /* @4509208 constant */
    /* @4509212 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(37));
    /* @4509220 constant */
    /* @4509224 constant */
    /* @4509228 constant */
    /* @4509232 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4509240 constant */
    /* @4509244 constant */
    /* @4509248 constant */
    /* @4509252 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(30));
    /* @4509260 constant */
    /* @4509264 constant */
    /* @4509268 constant */
    /* @4509272 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(46));
    /* @4509280 constant */
    /* @4509284 constant */
    /* @4509288 constant */
    /* @4509292 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4509300 constant */
    /* @4509304 constant */
    /* @4509308 constant */
    /* @4509312 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(38));
    /* @4509320 constant */
    /* @4509324 constant */
    /* @4509328 constant */
    /* @4509332 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(31));
    /* @4509340 constant */
    /* @4509344 constant */
    /* @4509348 constant */
    /* @4509352 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4509360 constant */
    /* @4509364 constant */
    /* @4509368 constant */
    /* @4509372 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(32));
    /* @4509380 constant */
    /* @4509384 constant */
    /* @4509388 constant */
    /* @4509392 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4509400 constant */
    /* @4509404 constant */
    /* @4509408 constant */
    /* @4509412 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(41));
    /* @4509420 constant */
    /* @4509424 constant */
    /* @4509428 constant */
    /* @4509432 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4509440 constant */
    /* @4509444 constant */
    /* @4509448 constant */
    /* @4509452 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(33));
    /* @4509460 constant */
    /* @4509464 constant */
    /* @4509468 constant */
    /* @4509472 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4509480: ;
    /* @4509480 load */
    /* @4509488 constant */
    /* @4509492 cmp */
    /* @4509496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(4)))) goto L_4509840;
    /* @4509500 constant */
    /* @4509504 constant */
    /* @4509508 constant */
    /* @4509512 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4509520 constant */
    /* @4509524 constant */
    /* @4509528 constant */
    /* @4509532 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4509540 constant */
    /* @4509544 constant */
    /* @4509548 constant */
    /* @4509552 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(37));
    /* @4509560 constant */
    /* @4509564 constant */
    /* @4509568 constant */
    /* @4509572 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4509580 constant */
    /* @4509584 constant */
    /* @4509588 constant */
    /* @4509592 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4509600 constant */
    /* @4509604 constant */
    /* @4509608 constant */
    /* @4509612 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(34));
    /* @4509620 constant */
    /* @4509624 constant */
    /* @4509628 constant */
    /* @4509632 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(45));
    /* @4509640 constant */
    /* @4509644 constant */
    /* @4509648 constant */
    /* @4509652 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(31));
    /* @4509660 constant */
    /* @4509664 constant */
    /* @4509668 constant */
    /* @4509672 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(41));
    /* @4509680 constant */
    /* @4509684 constant */
    /* @4509688 constant */
    /* @4509692 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4509700 constant */
    /* @4509704 constant */
    /* @4509708 constant */
    /* @4509712 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4509720 constant */
    /* @4509724 constant */
    /* @4509728 constant */
    /* @4509732 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(46));
    /* @4509740 constant */
    /* @4509744 constant */
    /* @4509748 constant */
    /* @4509752 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(39));
    /* @4509760 constant */
    /* @4509764 constant */
    /* @4509768 constant */
    /* @4509772 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4509780 constant */
    /* @4509784 constant */
    /* @4509788 constant */
    /* @4509792 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4509800 constant */
    /* @4509804 constant */
    /* @4509808 constant */
    /* @4509812 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(30));
    /* @4509820 constant */
    /* @4509824 constant */
    /* @4509828 constant */
    /* @4509832 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4509840: ;
    /* @4509840 load */
    /* @4509848 constant */
    /* @4509852 cmp */
    /* @4509856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(5)))) goto L_4510200;
    /* @4509860 constant */
    /* @4509864 constant */
    /* @4509868 constant */
    /* @4509872 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4509880 constant */
    /* @4509884 constant */
    /* @4509888 constant */
    /* @4509892 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(30));
    /* @4509900 constant */
    /* @4509904 constant */
    /* @4509908 constant */
    /* @4509912 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4509920 constant */
    /* @4509924 constant */
    /* @4509928 constant */
    /* @4509932 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4509940 constant */
    /* @4509944 constant */
    /* @4509948 constant */
    /* @4509952 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(45));
    /* @4509960 constant */
    /* @4509964 constant */
    /* @4509968 constant */
    /* @4509972 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(52));
    /* @4509980 constant */
    /* @4509984 constant */
    /* @4509988 constant */
    /* @4509992 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4510000 constant */
    /* @4510004 constant */
    /* @4510008 constant */
    /* @4510012 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4510020 constant */
    /* @4510024 constant */
    /* @4510028 constant */
    /* @4510032 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(34));
    /* @4510040 constant */
    /* @4510044 constant */
    /* @4510048 constant */
    /* @4510052 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(46));
    /* @4510060 constant */
    /* @4510064 constant */
    /* @4510068 constant */
    /* @4510072 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4510080 constant */
    /* @4510084 constant */
    /* @4510088 constant */
    /* @4510092 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4510100 constant */
    /* @4510104 constant */
    /* @4510108 constant */
    /* @4510112 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(37));
    /* @4510120 constant */
    /* @4510124 constant */
    /* @4510128 constant */
    /* @4510132 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(36));
    /* @4510140 constant */
    /* @4510144 constant */
    /* @4510148 constant */
    /* @4510152 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(32));
    /* @4510160 constant */
    /* @4510164 constant */
    /* @4510168 constant */
    /* @4510172 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(38));
    /* @4510180 constant */
    /* @4510184 constant */
    /* @4510188 constant */
    /* @4510192 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(39));
    L_4510200: ;
    /* @4510200 load */
    /* @4510208 constant */
    /* @4510212 cmp */
    /* @4510216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(6)))) goto L_4510560;
    /* @4510220 constant */
    /* @4510224 constant */
    /* @4510228 constant */
    /* @4510232 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4510240 constant */
    /* @4510244 constant */
    /* @4510248 constant */
    /* @4510252 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(37));
    /* @4510260 constant */
    /* @4510264 constant */
    /* @4510268 constant */
    /* @4510272 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(44));
    /* @4510280 constant */
    /* @4510284 constant */
    /* @4510288 constant */
    /* @4510292 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4510300 constant */
    /* @4510304 constant */
    /* @4510308 constant */
    /* @4510312 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4510320 constant */
    /* @4510324 constant */
    /* @4510328 constant */
    /* @4510332 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(41));
    /* @4510340 constant */
    /* @4510344 constant */
    /* @4510348 constant */
    /* @4510352 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4510360 constant */
    /* @4510364 constant */
    /* @4510368 constant */
    /* @4510372 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4510380 constant */
    /* @4510384 constant */
    /* @4510388 constant */
    /* @4510392 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(35));
    /* @4510400 constant */
    /* @4510404 constant */
    /* @4510408 constant */
    /* @4510412 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4510420 constant */
    /* @4510424 constant */
    /* @4510428 constant */
    /* @4510432 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4510440 constant */
    /* @4510444 constant */
    /* @4510448 constant */
    /* @4510452 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(30));
    /* @4510460 constant */
    /* @4510464 constant */
    /* @4510468 constant */
    /* @4510472 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(38));
    /* @4510480 constant */
    /* @4510484 constant */
    /* @4510488 constant */
    /* @4510492 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4510500 constant */
    /* @4510504 constant */
    /* @4510508 constant */
    /* @4510512 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4510520 constant */
    /* @4510524 constant */
    /* @4510528 constant */
    /* @4510532 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(52));
    /* @4510540 constant */
    /* @4510544 constant */
    /* @4510548 constant */
    /* @4510552 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4510560: ;
    /* @4510560 load */
    /* @4510568 constant */
    /* @4510572 cmp */
    /* @4510576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(7)))) goto L_4510920;
    /* @4510580 constant */
    /* @4510584 constant */
    /* @4510588 constant */
    /* @4510592 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4510600 constant */
    /* @4510604 constant */
    /* @4510608 constant */
    /* @4510612 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(47));
    /* @4510620 constant */
    /* @4510624 constant */
    /* @4510628 constant */
    /* @4510632 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(32));
    /* @4510640 constant */
    /* @4510644 constant */
    /* @4510648 constant */
    /* @4510652 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4510660 constant */
    /* @4510664 constant */
    /* @4510668 constant */
    /* @4510672 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(46));
    /* @4510680 constant */
    /* @4510684 constant */
    /* @4510688 constant */
    /* @4510692 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(38));
    /* @4510700 constant */
    /* @4510704 constant */
    /* @4510708 constant */
    /* @4510712 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(44));
    /* @4510720 constant */
    /* @4510724 constant */
    /* @4510728 constant */
    /* @4510732 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4510740 constant */
    /* @4510744 constant */
    /* @4510748 constant */
    /* @4510752 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4510760 constant */
    /* @4510764 constant */
    /* @4510768 constant */
    /* @4510772 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4510780 constant */
    /* @4510784 constant */
    /* @4510788 constant */
    /* @4510792 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(52));
    /* @4510800 constant */
    /* @4510804 constant */
    /* @4510808 constant */
    /* @4510812 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(37));
    /* @4510820 constant */
    /* @4510824 constant */
    /* @4510828 constant */
    /* @4510832 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(30));
    /* @4510840 constant */
    /* @4510844 constant */
    /* @4510848 constant */
    /* @4510852 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(33));
    /* @4510860 constant */
    /* @4510864 constant */
    /* @4510868 constant */
    /* @4510872 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(31));
    /* @4510880 constant */
    /* @4510884 constant */
    /* @4510888 constant */
    /* @4510892 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(45));
    /* @4510900 constant */
    /* @4510904 constant */
    /* @4510908 constant */
    /* @4510912 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(35));
    L_4510920: ;
    /* @4510920 load */
    /* @4510928 constant */
    /* @4510932 cmp */
    /* @4510936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(8)))) goto L_4511280;
    /* @4510940 constant */
    /* @4510944 constant */
    /* @4510948 constant */
    /* @4510952 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(34));
    /* @4510960 constant */
    /* @4510964 constant */
    /* @4510968 constant */
    /* @4510972 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(38));
    /* @4510980 constant */
    /* @4510984 constant */
    /* @4510988 constant */
    /* @4510992 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(33));
    /* @4511000 constant */
    /* @4511004 constant */
    /* @4511008 constant */
    /* @4511012 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(52));
    /* @4511020 constant */
    /* @4511024 constant */
    /* @4511028 constant */
    /* @4511032 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4511040 constant */
    /* @4511044 constant */
    /* @4511048 constant */
    /* @4511052 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(37));
    /* @4511060 constant */
    /* @4511064 constant */
    /* @4511068 constant */
    /* @4511072 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4511080 constant */
    /* @4511084 constant */
    /* @4511088 constant */
    /* @4511092 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4511100 constant */
    /* @4511104 constant */
    /* @4511108 constant */
    /* @4511112 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(46));
    /* @4511120 constant */
    /* @4511124 constant */
    /* @4511128 constant */
    /* @4511132 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4511140 constant */
    /* @4511144 constant */
    /* @4511148 constant */
    /* @4511152 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4511160 constant */
    /* @4511164 constant */
    /* @4511168 constant */
    /* @4511172 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4511180 constant */
    /* @4511184 constant */
    /* @4511188 constant */
    /* @4511192 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(35));
    /* @4511200 constant */
    /* @4511204 constant */
    /* @4511208 constant */
    /* @4511212 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(30));
    /* @4511220 constant */
    /* @4511224 constant */
    /* @4511228 constant */
    /* @4511232 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4511240 constant */
    /* @4511244 constant */
    /* @4511248 constant */
    /* @4511252 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(32));
    /* @4511260 constant */
    /* @4511264 constant */
    /* @4511268 constant */
    /* @4511272 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(45));
    L_4511280: ;
    /* @4511280 load */
    /* @4511288 constant */
    /* @4511292 cmp */
    /* @4511296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(9)))) goto L_4511640;
    /* @4511300 constant */
    /* @4511304 constant */
    /* @4511308 constant */
    /* @4511312 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4511320 constant */
    /* @4511324 constant */
    /* @4511328 constant */
    /* @4511332 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(44));
    /* @4511340 constant */
    /* @4511344 constant */
    /* @4511348 constant */
    /* @4511352 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4511360 constant */
    /* @4511364 constant */
    /* @4511368 constant */
    /* @4511372 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4511380 constant */
    /* @4511384 constant */
    /* @4511388 constant */
    /* @4511392 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(33));
    /* @4511400 constant */
    /* @4511404 constant */
    /* @4511408 constant */
    /* @4511412 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(35));
    /* @4511420 constant */
    /* @4511424 constant */
    /* @4511428 constant */
    /* @4511432 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(37));
    /* @4511440 constant */
    /* @4511444 constant */
    /* @4511448 constant */
    /* @4511452 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(38));
    /* @4511460 constant */
    /* @4511464 constant */
    /* @4511468 constant */
    /* @4511472 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(30));
    /* @4511480 constant */
    /* @4511484 constant */
    /* @4511488 constant */
    /* @4511492 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(32));
    /* @4511500 constant */
    /* @4511504 constant */
    /* @4511508 constant */
    /* @4511512 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(39));
    /* @4511520 constant */
    /* @4511524 constant */
    /* @4511528 constant */
    /* @4511532 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4511540 constant */
    /* @4511544 constant */
    /* @4511548 constant */
    /* @4511552 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(46));
    /* @4511560 constant */
    /* @4511564 constant */
    /* @4511568 constant */
    /* @4511572 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(47));
    /* @4511580 constant */
    /* @4511584 constant */
    /* @4511588 constant */
    /* @4511592 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4511600 constant */
    /* @4511604 constant */
    /* @4511608 constant */
    /* @4511612 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4511620 constant */
    /* @4511624 constant */
    /* @4511628 constant */
    /* @4511632 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(41));
    L_4511640: ;
    /* @4511640 load */
    /* @4511648 constant */
    /* @4511652 cmp */
    /* @4511656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(10)))) goto L_4512000;
    /* @4511660 constant */
    /* @4511664 constant */
    /* @4511668 constant */
    /* @4511672 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4511680 constant */
    /* @4511684 constant */
    /* @4511688 constant */
    /* @4511692 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4511700 constant */
    /* @4511704 constant */
    /* @4511708 constant */
    /* @4511712 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4511720 constant */
    /* @4511724 constant */
    /* @4511728 constant */
    /* @4511732 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(30));
    /* @4511740 constant */
    /* @4511744 constant */
    /* @4511748 constant */
    /* @4511752 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(31));
    /* @4511760 constant */
    /* @4511764 constant */
    /* @4511768 constant */
    /* @4511772 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(33));
    /* @4511780 constant */
    /* @4511784 constant */
    /* @4511788 constant */
    /* @4511792 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(34));
    /* @4511800 constant */
    /* @4511804 constant */
    /* @4511808 constant */
    /* @4511812 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4511820 constant */
    /* @4511824 constant */
    /* @4511828 constant */
    /* @4511832 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4511840 constant */
    /* @4511844 constant */
    /* @4511848 constant */
    /* @4511852 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(41));
    /* @4511860 constant */
    /* @4511864 constant */
    /* @4511868 constant */
    /* @4511872 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(38));
    /* @4511880 constant */
    /* @4511884 constant */
    /* @4511888 constant */
    /* @4511892 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(39));
    /* @4511900 constant */
    /* @4511904 constant */
    /* @4511908 constant */
    /* @4511912 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(47));
    /* @4511920 constant */
    /* @4511924 constant */
    /* @4511928 constant */
    /* @4511932 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4511940 constant */
    /* @4511944 constant */
    /* @4511948 constant */
    /* @4511952 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(44));
    /* @4511960 constant */
    /* @4511964 constant */
    /* @4511968 constant */
    /* @4511972 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4511980 constant */
    /* @4511984 constant */
    /* @4511988 constant */
    /* @4511992 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(37));
    L_4512000: ;
    /* @4512000 load */
    /* @4512008 constant */
    /* @4512012 cmp */
    /* @4512016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_4515748;
    /* @4512020 call */
    GM_SITE(vm, 378, 4512020);
    /* @4512028 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4512032 constant */
    /* @4512036 constant */
    /* @4512040 constant */
    /* @4512044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4512052 constant */
    /* @4512056 cast */
    /* @4512060 constant */
    /* @4512064 cast */
    /* @4512068 constant */
    /* @4512072 cast */
    /* @4512076 constant */
    /* @4512080 cast */
    /* @4512084 constant */
    /* @4512088 cast */
    /* @4512092 constant */
    /* @4512096 cast */
    /* @4512100 constant */
    /* @4512104 cast */
    /* @4512108 constant */
    /* @4512112 cast */
    /* @4512116 constant */
    /* @4512120 cast */
    /* @4512124 constant */
    /* @4512128 cast */
    /* @4512132 call */
    GM_SITE(vm, 378, 4512132);
    /* @4512140 store */
    v5 = GM_CALL(vm, "choose", 10, VAL(2), VAL(4), VAL(6), VAL(8), VAL(10), VAL(1), VAL(3), VAL(5), VAL(7), VAL(9));
    GM_WRITE(vm, -1, "playlist", v5);
    /* @4512148 load */
    /* @4512156 constant */
    /* @4512160 cmp */
    /* @4512164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(1)))) goto L_4512508;
    /* @4512168 constant */
    /* @4512172 constant */
    /* @4512176 constant */
    /* @4512180 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(37));
    /* @4512188 constant */
    /* @4512192 constant */
    /* @4512196 constant */
    /* @4512200 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(46));
    /* @4512208 constant */
    /* @4512212 constant */
    /* @4512216 constant */
    /* @4512220 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4512228 constant */
    /* @4512232 constant */
    /* @4512236 constant */
    /* @4512240 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(31));
    /* @4512248 constant */
    /* @4512252 constant */
    /* @4512256 constant */
    /* @4512260 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4512268 constant */
    /* @4512272 constant */
    /* @4512276 constant */
    /* @4512280 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(44));
    /* @4512288 constant */
    /* @4512292 constant */
    /* @4512296 constant */
    /* @4512300 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(30));
    /* @4512308 constant */
    /* @4512312 constant */
    /* @4512316 constant */
    /* @4512320 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(45));
    /* @4512328 constant */
    /* @4512332 constant */
    /* @4512336 constant */
    /* @4512340 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(39));
    /* @4512348 constant */
    /* @4512352 constant */
    /* @4512356 constant */
    /* @4512360 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4512368 constant */
    /* @4512372 constant */
    /* @4512376 constant */
    /* @4512380 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(34));
    /* @4512388 constant */
    /* @4512392 constant */
    /* @4512396 constant */
    /* @4512400 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4512408 constant */
    /* @4512412 constant */
    /* @4512416 constant */
    /* @4512420 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(52));
    /* @4512428 constant */
    /* @4512432 constant */
    /* @4512436 constant */
    /* @4512440 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4512448 constant */
    /* @4512452 constant */
    /* @4512456 constant */
    /* @4512460 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4512468 constant */
    /* @4512472 constant */
    /* @4512476 constant */
    /* @4512480 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(47));
    /* @4512488 constant */
    /* @4512492 constant */
    /* @4512496 constant */
    /* @4512500 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4512508: ;
    /* @4512508 load */
    /* @4512516 constant */
    /* @4512520 cmp */
    /* @4512524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(2)))) goto L_4512868;
    /* @4512528 constant */
    /* @4512532 constant */
    /* @4512536 constant */
    /* @4512540 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(44));
    /* @4512548 constant */
    /* @4512552 constant */
    /* @4512556 constant */
    /* @4512560 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4512568 constant */
    /* @4512572 constant */
    /* @4512576 constant */
    /* @4512580 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4512588 constant */
    /* @4512592 constant */
    /* @4512596 constant */
    /* @4512600 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(45));
    /* @4512608 constant */
    /* @4512612 constant */
    /* @4512616 constant */
    /* @4512620 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(38));
    /* @4512628 constant */
    /* @4512632 constant */
    /* @4512636 constant */
    /* @4512640 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(46));
    /* @4512648 constant */
    /* @4512652 constant */
    /* @4512656 constant */
    /* @4512660 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4512668 constant */
    /* @4512672 constant */
    /* @4512676 constant */
    /* @4512680 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(37));
    /* @4512688 constant */
    /* @4512692 constant */
    /* @4512696 constant */
    /* @4512700 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(32));
    /* @4512708 constant */
    /* @4512712 constant */
    /* @4512716 constant */
    /* @4512720 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4512728 constant */
    /* @4512732 constant */
    /* @4512736 constant */
    /* @4512740 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(30));
    /* @4512748 constant */
    /* @4512752 constant */
    /* @4512756 constant */
    /* @4512760 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(35));
    /* @4512768 constant */
    /* @4512772 constant */
    /* @4512776 constant */
    /* @4512780 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4512788 constant */
    /* @4512792 constant */
    /* @4512796 constant */
    /* @4512800 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(31));
    /* @4512808 constant */
    /* @4512812 constant */
    /* @4512816 constant */
    /* @4512820 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4512828 constant */
    /* @4512832 constant */
    /* @4512836 constant */
    /* @4512840 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4512848 constant */
    /* @4512852 constant */
    /* @4512856 constant */
    /* @4512860 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(47));
    L_4512868: ;
    /* @4512868 load */
    /* @4512876 constant */
    /* @4512880 cmp */
    /* @4512884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(3)))) goto L_4513228;
    /* @4512888 constant */
    /* @4512892 constant */
    /* @4512896 constant */
    /* @4512900 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4512908 constant */
    /* @4512912 constant */
    /* @4512916 constant */
    /* @4512920 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(35));
    /* @4512928 constant */
    /* @4512932 constant */
    /* @4512936 constant */
    /* @4512940 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(39));
    /* @4512948 constant */
    /* @4512952 constant */
    /* @4512956 constant */
    /* @4512960 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(37));
    /* @4512968 constant */
    /* @4512972 constant */
    /* @4512976 constant */
    /* @4512980 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4512988 constant */
    /* @4512992 constant */
    /* @4512996 constant */
    /* @4513000 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(30));
    /* @4513008 constant */
    /* @4513012 constant */
    /* @4513016 constant */
    /* @4513020 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(46));
    /* @4513028 constant */
    /* @4513032 constant */
    /* @4513036 constant */
    /* @4513040 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4513048 constant */
    /* @4513052 constant */
    /* @4513056 constant */
    /* @4513060 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(38));
    /* @4513068 constant */
    /* @4513072 constant */
    /* @4513076 constant */
    /* @4513080 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(31));
    /* @4513088 constant */
    /* @4513092 constant */
    /* @4513096 constant */
    /* @4513100 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4513108 constant */
    /* @4513112 constant */
    /* @4513116 constant */
    /* @4513120 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(32));
    /* @4513128 constant */
    /* @4513132 constant */
    /* @4513136 constant */
    /* @4513140 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(34));
    /* @4513148 constant */
    /* @4513152 constant */
    /* @4513156 constant */
    /* @4513160 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(41));
    /* @4513168 constant */
    /* @4513172 constant */
    /* @4513176 constant */
    /* @4513180 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4513188 constant */
    /* @4513192 constant */
    /* @4513196 constant */
    /* @4513200 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(33));
    /* @4513208 constant */
    /* @4513212 constant */
    /* @4513216 constant */
    /* @4513220 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4513228: ;
    /* @4513228 load */
    /* @4513236 constant */
    /* @4513240 cmp */
    /* @4513244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(4)))) goto L_4513588;
    /* @4513248 constant */
    /* @4513252 constant */
    /* @4513256 constant */
    /* @4513260 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4513268 constant */
    /* @4513272 constant */
    /* @4513276 constant */
    /* @4513280 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4513288 constant */
    /* @4513292 constant */
    /* @4513296 constant */
    /* @4513300 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(37));
    /* @4513308 constant */
    /* @4513312 constant */
    /* @4513316 constant */
    /* @4513320 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4513328 constant */
    /* @4513332 constant */
    /* @4513336 constant */
    /* @4513340 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4513348 constant */
    /* @4513352 constant */
    /* @4513356 constant */
    /* @4513360 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(34));
    /* @4513368 constant */
    /* @4513372 constant */
    /* @4513376 constant */
    /* @4513380 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(45));
    /* @4513388 constant */
    /* @4513392 constant */
    /* @4513396 constant */
    /* @4513400 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(31));
    /* @4513408 constant */
    /* @4513412 constant */
    /* @4513416 constant */
    /* @4513420 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(41));
    /* @4513428 constant */
    /* @4513432 constant */
    /* @4513436 constant */
    /* @4513440 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(35));
    /* @4513448 constant */
    /* @4513452 constant */
    /* @4513456 constant */
    /* @4513460 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4513468 constant */
    /* @4513472 constant */
    /* @4513476 constant */
    /* @4513480 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(46));
    /* @4513488 constant */
    /* @4513492 constant */
    /* @4513496 constant */
    /* @4513500 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(39));
    /* @4513508 constant */
    /* @4513512 constant */
    /* @4513516 constant */
    /* @4513520 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(38));
    /* @4513528 constant */
    /* @4513532 constant */
    /* @4513536 constant */
    /* @4513540 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4513548 constant */
    /* @4513552 constant */
    /* @4513556 constant */
    /* @4513560 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(30));
    /* @4513568 constant */
    /* @4513572 constant */
    /* @4513576 constant */
    /* @4513580 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(32));
    L_4513588: ;
    /* @4513588 load */
    /* @4513596 constant */
    /* @4513600 cmp */
    /* @4513604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(5)))) goto L_4513948;
    /* @4513608 constant */
    /* @4513612 constant */
    /* @4513616 constant */
    /* @4513620 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4513628 constant */
    /* @4513632 constant */
    /* @4513636 constant */
    /* @4513640 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(30));
    /* @4513648 constant */
    /* @4513652 constant */
    /* @4513656 constant */
    /* @4513660 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(41));
    /* @4513668 constant */
    /* @4513672 constant */
    /* @4513676 constant */
    /* @4513680 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(44));
    /* @4513688 constant */
    /* @4513692 constant */
    /* @4513696 constant */
    /* @4513700 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(45));
    /* @4513708 constant */
    /* @4513712 constant */
    /* @4513716 constant */
    /* @4513720 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(52));
    /* @4513728 constant */
    /* @4513732 constant */
    /* @4513736 constant */
    /* @4513740 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4513748 constant */
    /* @4513752 constant */
    /* @4513756 constant */
    /* @4513760 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4513768 constant */
    /* @4513772 constant */
    /* @4513776 constant */
    /* @4513780 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(34));
    /* @4513788 constant */
    /* @4513792 constant */
    /* @4513796 constant */
    /* @4513800 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(46));
    /* @4513808 constant */
    /* @4513812 constant */
    /* @4513816 constant */
    /* @4513820 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4513828 constant */
    /* @4513832 constant */
    /* @4513836 constant */
    /* @4513840 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(33));
    /* @4513848 constant */
    /* @4513852 constant */
    /* @4513856 constant */
    /* @4513860 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(37));
    /* @4513868 constant */
    /* @4513872 constant */
    /* @4513876 constant */
    /* @4513880 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(36));
    /* @4513888 constant */
    /* @4513892 constant */
    /* @4513896 constant */
    /* @4513900 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(32));
    /* @4513908 constant */
    /* @4513912 constant */
    /* @4513916 constant */
    /* @4513920 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(38));
    /* @4513928 constant */
    /* @4513932 constant */
    /* @4513936 constant */
    /* @4513940 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(39));
    L_4513948: ;
    /* @4513948 load */
    /* @4513956 constant */
    /* @4513960 cmp */
    /* @4513964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(6)))) goto L_4514308;
    /* @4513968 constant */
    /* @4513972 constant */
    /* @4513976 constant */
    /* @4513980 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4513988 constant */
    /* @4513992 constant */
    /* @4513996 constant */
    /* @4514000 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(37));
    /* @4514008 constant */
    /* @4514012 constant */
    /* @4514016 constant */
    /* @4514020 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(44));
    /* @4514028 constant */
    /* @4514032 constant */
    /* @4514036 constant */
    /* @4514040 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4514048 constant */
    /* @4514052 constant */
    /* @4514056 constant */
    /* @4514060 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(36));
    /* @4514068 constant */
    /* @4514072 constant */
    /* @4514076 constant */
    /* @4514080 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(41));
    /* @4514088 constant */
    /* @4514092 constant */
    /* @4514096 constant */
    /* @4514100 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(31));
    /* @4514108 constant */
    /* @4514112 constant */
    /* @4514116 constant */
    /* @4514120 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(47));
    /* @4514128 constant */
    /* @4514132 constant */
    /* @4514136 constant */
    /* @4514140 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(35));
    /* @4514148 constant */
    /* @4514152 constant */
    /* @4514156 constant */
    /* @4514160 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4514168 constant */
    /* @4514172 constant */
    /* @4514176 constant */
    /* @4514180 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(45));
    /* @4514188 constant */
    /* @4514192 constant */
    /* @4514196 constant */
    /* @4514200 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(30));
    /* @4514208 constant */
    /* @4514212 constant */
    /* @4514216 constant */
    /* @4514220 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(38));
    /* @4514228 constant */
    /* @4514232 constant */
    /* @4514236 constant */
    /* @4514240 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4514248 constant */
    /* @4514252 constant */
    /* @4514256 constant */
    /* @4514260 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(33));
    /* @4514268 constant */
    /* @4514272 constant */
    /* @4514276 constant */
    /* @4514280 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(52));
    /* @4514288 constant */
    /* @4514292 constant */
    /* @4514296 constant */
    /* @4514300 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(29));
    L_4514308: ;
    /* @4514308 load */
    /* @4514316 constant */
    /* @4514320 cmp */
    /* @4514324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(7)))) goto L_4514668;
    /* @4514328 constant */
    /* @4514332 constant */
    /* @4514336 constant */
    /* @4514340 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(29));
    /* @4514348 constant */
    /* @4514352 constant */
    /* @4514356 constant */
    /* @4514360 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(47));
    /* @4514368 constant */
    /* @4514372 constant */
    /* @4514376 constant */
    /* @4514380 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(32));
    /* @4514388 constant */
    /* @4514392 constant */
    /* @4514396 constant */
    /* @4514400 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4514408 constant */
    /* @4514412 constant */
    /* @4514416 constant */
    /* @4514420 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(46));
    /* @4514428 constant */
    /* @4514432 constant */
    /* @4514436 constant */
    /* @4514440 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(38));
    /* @4514448 constant */
    /* @4514452 constant */
    /* @4514456 constant */
    /* @4514460 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(44));
    /* @4514468 constant */
    /* @4514472 constant */
    /* @4514476 constant */
    /* @4514480 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4514488 constant */
    /* @4514492 constant */
    /* @4514496 constant */
    /* @4514500 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4514508 constant */
    /* @4514512 constant */
    /* @4514516 constant */
    /* @4514520 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(39));
    /* @4514528 constant */
    /* @4514532 constant */
    /* @4514536 constant */
    /* @4514540 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(52));
    /* @4514548 constant */
    /* @4514552 constant */
    /* @4514556 constant */
    /* @4514560 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(37));
    /* @4514568 constant */
    /* @4514572 constant */
    /* @4514576 constant */
    /* @4514580 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(30));
    /* @4514588 constant */
    /* @4514592 constant */
    /* @4514596 constant */
    /* @4514600 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(33));
    /* @4514608 constant */
    /* @4514612 constant */
    /* @4514616 constant */
    /* @4514620 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(31));
    /* @4514628 constant */
    /* @4514632 constant */
    /* @4514636 constant */
    /* @4514640 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(45));
    /* @4514648 constant */
    /* @4514652 constant */
    /* @4514656 constant */
    /* @4514660 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(35));
    L_4514668: ;
    /* @4514668 load */
    /* @4514676 constant */
    /* @4514680 cmp */
    /* @4514684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(8)))) goto L_4515028;
    /* @4514688 constant */
    /* @4514692 constant */
    /* @4514696 constant */
    /* @4514700 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(34));
    /* @4514708 constant */
    /* @4514712 constant */
    /* @4514716 constant */
    /* @4514720 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(38));
    /* @4514728 constant */
    /* @4514732 constant */
    /* @4514736 constant */
    /* @4514740 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(33));
    /* @4514748 constant */
    /* @4514752 constant */
    /* @4514756 constant */
    /* @4514760 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(52));
    /* @4514768 constant */
    /* @4514772 constant */
    /* @4514776 constant */
    /* @4514780 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(44));
    /* @4514788 constant */
    /* @4514792 constant */
    /* @4514796 constant */
    /* @4514800 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(37));
    /* @4514808 constant */
    /* @4514812 constant */
    /* @4514816 constant */
    /* @4514820 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(39));
    /* @4514828 constant */
    /* @4514832 constant */
    /* @4514836 constant */
    /* @4514840 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(41));
    /* @4514848 constant */
    /* @4514852 constant */
    /* @4514856 constant */
    /* @4514860 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(46));
    /* @4514868 constant */
    /* @4514872 constant */
    /* @4514876 constant */
    /* @4514880 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(36));
    /* @4514888 constant */
    /* @4514892 constant */
    /* @4514896 constant */
    /* @4514900 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(47));
    /* @4514908 constant */
    /* @4514912 constant */
    /* @4514916 constant */
    /* @4514920 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4514928 constant */
    /* @4514932 constant */
    /* @4514936 constant */
    /* @4514940 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(35));
    /* @4514948 constant */
    /* @4514952 constant */
    /* @4514956 constant */
    /* @4514960 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(30));
    /* @4514968 constant */
    /* @4514972 constant */
    /* @4514976 constant */
    /* @4514980 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(29));
    /* @4514988 constant */
    /* @4514992 constant */
    /* @4514996 constant */
    /* @4515000 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(32));
    /* @4515008 constant */
    /* @4515012 constant */
    /* @4515016 constant */
    /* @4515020 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(45));
    L_4515028: ;
    /* @4515028 load */
    /* @4515036 constant */
    /* @4515040 cmp */
    /* @4515044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(9)))) goto L_4515388;
    /* @4515048 constant */
    /* @4515052 constant */
    /* @4515056 constant */
    /* @4515060 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(36));
    /* @4515068 constant */
    /* @4515072 constant */
    /* @4515076 constant */
    /* @4515080 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(44));
    /* @4515088 constant */
    /* @4515092 constant */
    /* @4515096 constant */
    /* @4515100 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4515108 constant */
    /* @4515112 constant */
    /* @4515116 constant */
    /* @4515120 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(34));
    /* @4515128 constant */
    /* @4515132 constant */
    /* @4515136 constant */
    /* @4515140 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(33));
    /* @4515148 constant */
    /* @4515152 constant */
    /* @4515156 constant */
    /* @4515160 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(35));
    /* @4515168 constant */
    /* @4515172 constant */
    /* @4515176 constant */
    /* @4515180 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(37));
    /* @4515188 constant */
    /* @4515192 constant */
    /* @4515196 constant */
    /* @4515200 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(38));
    /* @4515208 constant */
    /* @4515212 constant */
    /* @4515216 constant */
    /* @4515220 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(30));
    /* @4515228 constant */
    /* @4515232 constant */
    /* @4515236 constant */
    /* @4515240 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(32));
    /* @4515248 constant */
    /* @4515252 constant */
    /* @4515256 constant */
    /* @4515260 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(39));
    /* @4515268 constant */
    /* @4515272 constant */
    /* @4515276 constant */
    /* @4515280 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(31));
    /* @4515288 constant */
    /* @4515292 constant */
    /* @4515296 constant */
    /* @4515300 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(46));
    /* @4515308 constant */
    /* @4515312 constant */
    /* @4515316 constant */
    /* @4515320 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(47));
    /* @4515328 constant */
    /* @4515332 constant */
    /* @4515336 constant */
    /* @4515340 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(52));
    /* @4515348 constant */
    /* @4515352 constant */
    /* @4515356 constant */
    /* @4515360 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4515368 constant */
    /* @4515372 constant */
    /* @4515376 constant */
    /* @4515380 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(41));
    L_4515388: ;
    /* @4515388 load */
    /* @4515396 constant */
    /* @4515400 cmp */
    /* @4515404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "playlist") == VAL(10)))) goto L_4515748;
    /* @4515408 constant */
    /* @4515412 constant */
    /* @4515416 constant */
    /* @4515420 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(0), VAL(32));
    /* @4515428 constant */
    /* @4515432 constant */
    /* @4515436 constant */
    /* @4515440 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(1), VAL(52));
    /* @4515448 constant */
    /* @4515452 constant */
    /* @4515456 constant */
    /* @4515460 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(2), VAL(45));
    /* @4515468 constant */
    /* @4515472 constant */
    /* @4515476 constant */
    /* @4515480 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(3), VAL(30));
    /* @4515488 constant */
    /* @4515492 constant */
    /* @4515496 constant */
    /* @4515500 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(4), VAL(31));
    /* @4515508 constant */
    /* @4515512 constant */
    /* @4515516 constant */
    /* @4515520 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(5), VAL(33));
    /* @4515528 constant */
    /* @4515532 constant */
    /* @4515536 constant */
    /* @4515540 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(6), VAL(34));
    /* @4515548 constant */
    /* @4515552 constant */
    /* @4515556 constant */
    /* @4515560 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(7), VAL(35));
    /* @4515568 constant */
    /* @4515572 constant */
    /* @4515576 constant */
    /* @4515580 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(8), VAL(36));
    /* @4515588 constant */
    /* @4515592 constant */
    /* @4515596 constant */
    /* @4515600 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(9), VAL(41));
    /* @4515608 constant */
    /* @4515612 constant */
    /* @4515616 constant */
    /* @4515620 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(10), VAL(38));
    /* @4515628 constant */
    /* @4515632 constant */
    /* @4515636 constant */
    /* @4515640 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(11), VAL(39));
    /* @4515648 constant */
    /* @4515652 constant */
    /* @4515656 constant */
    /* @4515660 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(12), VAL(47));
    /* @4515668 constant */
    /* @4515672 constant */
    /* @4515676 constant */
    /* @4515680 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(13), VAL(46));
    /* @4515688 constant */
    /* @4515692 constant */
    /* @4515696 constant */
    /* @4515700 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(14), VAL(44));
    /* @4515708 constant */
    /* @4515712 constant */
    /* @4515716 constant */
    /* @4515720 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(15), VAL(29));
    /* @4515728 constant */
    /* @4515732 constant */
    /* @4515736 constant */
    /* @4515740 store */
    GM_WRITE_ARR(vm, VAL(-1), "theme", VAL(16), VAL(37));
    L_4515748: ;
    return;
}
