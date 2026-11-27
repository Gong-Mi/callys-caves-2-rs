/* generated from CODE 519 (gml_Object_obj_weaponswap_Alarm_0), source start 4715676, end 4737360. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0519(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p4715832_0;
    Val p4716048_0;
    Val p4716284_0;
    Val p4716540_0;
    Val p4716816_0;
    Val p4717112_0;
    Val p4717428_0;
    Val p4717764_0;
    Val p4718120_0;
    Val p4718496_0;
    Val p4718892_0;
    Val p4719288_0;
    Val p4719484_0;
    Val p4719712_0;
    Val p4719960_0;
    Val p4720228_0;
    Val p4720516_0;
    Val p4720824_0;
    Val p4721152_0;
    Val p4721500_0;
    Val p4721868_0;
    Val p4722256_0;
    Val p4722644_0;
    Val p4722852_0;
    Val p4723080_0;
    Val p4723328_0;
    Val p4723596_0;
    Val p4723884_0;
    Val p4724192_0;
    Val p4724520_0;
    Val p4724868_0;
    Val p4725236_0;
    Val p4725584_0;
    Val p4725792_0;
    Val p4726020_0;
    Val p4726268_0;
    Val p4726536_0;
    Val p4726824_0;
    Val p4727132_0;
    Val p4727460_0;
    Val p4727808_0;
    Val p4728156_0;
    Val p4728364_0;
    Val p4728592_0;
    Val p4728840_0;
    Val p4729108_0;
    Val p4729396_0;
    Val p4729704_0;
    Val p4730032_0;
    Val p4730360_0;
    Val p4730568_0;
    Val p4730796_0;
    Val p4731044_0;
    Val p4731312_0;
    Val p4731600_0;
    Val p4731908_0;
    Val p4732216_0;
    Val p4732424_0;
    Val p4732652_0;
    Val p4732900_0;
    Val p4733168_0;
    Val p4733456_0;
    Val p4733744_0;
    Val p4733952_0;
    Val p4734180_0;
    Val p4734428_0;
    Val p4734696_0;
    Val p4734964_0;
    Val p4735172_0;
    Val p4735400_0;
    Val p4735648_0;
    Val p4735896_0;
    Val p4736104_0;
    Val p4736332_0;
    Val p4736560_0;
    Val p4736768_0;
    Val p4736976_0;
    /* @4715676 constant */
    /* @4715680 cast */
    /* @4715684 call */
    GM_SITE(vm, 519, 4715684);
    /* @4715692 cast */
    /* @4715696 not */
    /* @4715700 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(5))));
    if (!TRUTH(v1)) goto L_4715740;
    /* @4715704 constant */
    /* @4715708 cast */
    /* @4715712 constant */
    /* @4715716 cast */
    /* @4715720 constant */
    /* @4715724 cast */
    /* @4715728 call */
    GM_SITE(vm, 519, 4715728);
    /* @4715736 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(5), VAL(0), VAL(0)));
    L_4715740: ;
    /* @4715740 load */
    /* @4715748 constant */
    /* @4715752 add */
    /* @4715756 store */
    v2 = GM_ADD(GM_READ(vm, -5, "weaponswapped"), VAL(1));
    GM_WRITE(vm, -5, "weaponswapped", v2);
    /* @4715764 load */
    /* @4715772 constant */
    /* @4715776 add */
    /* @4715780 store */
    v3 = GM_ADD(GM_READ(vm, -5, "weaponswapped"), VAL(1));
    GM_WRITE(vm, -5, "weaponswapped", v3);
    /* @4715788 load */
    /* @4715796 constant */
    /* @4715800 cmp */
    /* @4715804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4715828;
    /* @4715808 load */
    /* @4715816 constant */
    /* @4715820 cmp */
    /* @4715824 b */
    p4715832_0 = NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(1));
    goto L_4715832;
    L_4715828: ;
    /* @4715828 constant */
    p4715832_0 = VAL(0);
    L_4715832: ;
    /* @4715832 bf */
    if (!TRUTH(p4715832_0)) goto L_4715984;
    /* @4715836 constant */
    /* @4715840 store */
    GM_WRITE(vm, -5, "shotgun", VAL(1));
    /* @4715848 constant */
    /* @4715852 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4715860 constant */
    /* @4715864 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4715872 constant */
    /* @4715876 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4715884 constant */
    /* @4715888 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4715896 constant */
    /* @4715900 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4715908 constant */
    /* @4715912 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4715920 constant */
    /* @4715924 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4715932 constant */
    /* @4715936 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4715944 constant */
    /* @4715948 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4715956 constant */
    /* @4715960 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4715968 constant */
    /* @4715972 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4715980 b */
    goto L_4737316;
    L_4715984: ;
    /* @4715984 load */
    /* @4715992 constant */
    /* @4715996 cmp */
    /* @4716000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4716044;
    /* @4716004 load */
    /* @4716012 constant */
    /* @4716016 cmp */
    /* @4716020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4716044;
    /* @4716024 load */
    /* @4716032 constant */
    /* @4716036 cmp */
    /* @4716040 b */
    p4716048_0 = NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(1));
    goto L_4716048;
    L_4716044: ;
    /* @4716044 constant */
    p4716048_0 = VAL(0);
    L_4716048: ;
    /* @4716048 bf */
    if (!TRUTH(p4716048_0)) goto L_4716200;
    /* @4716052 constant */
    /* @4716056 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(1));
    /* @4716064 constant */
    /* @4716068 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4716076 constant */
    /* @4716080 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4716088 constant */
    /* @4716092 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4716100 constant */
    /* @4716104 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4716112 constant */
    /* @4716116 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4716124 constant */
    /* @4716128 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4716136 constant */
    /* @4716140 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4716148 constant */
    /* @4716152 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4716160 constant */
    /* @4716164 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4716172 constant */
    /* @4716176 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4716184 constant */
    /* @4716188 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4716196 b */
    goto L_4737316;
    L_4716200: ;
    /* @4716200 load */
    /* @4716208 constant */
    /* @4716212 cmp */
    /* @4716216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4716280;
    /* @4716220 load */
    /* @4716228 constant */
    /* @4716232 cmp */
    /* @4716236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4716280;
    /* @4716240 load */
    /* @4716248 constant */
    /* @4716252 cmp */
    /* @4716256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4716280;
    /* @4716260 load */
    /* @4716268 constant */
    /* @4716272 cmp */
    /* @4716276 b */
    p4716284_0 = NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(1));
    goto L_4716284;
    L_4716280: ;
    /* @4716280 constant */
    p4716284_0 = VAL(0);
    L_4716284: ;
    /* @4716284 bf */
    if (!TRUTH(p4716284_0)) goto L_4716436;
    /* @4716288 constant */
    /* @4716292 store */
    GM_WRITE(vm, -5, "rocket", VAL(1));
    /* @4716300 constant */
    /* @4716304 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4716312 constant */
    /* @4716316 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4716324 constant */
    /* @4716328 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4716336 constant */
    /* @4716340 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4716348 constant */
    /* @4716352 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4716360 constant */
    /* @4716364 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4716372 constant */
    /* @4716376 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4716384 constant */
    /* @4716388 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4716396 constant */
    /* @4716400 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4716408 constant */
    /* @4716412 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4716420 constant */
    /* @4716424 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4716432 b */
    goto L_4737316;
    L_4716436: ;
    /* @4716436 load */
    /* @4716444 constant */
    /* @4716448 cmp */
    /* @4716452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4716536;
    /* @4716456 load */
    /* @4716464 constant */
    /* @4716468 cmp */
    /* @4716472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4716536;
    /* @4716476 load */
    /* @4716484 constant */
    /* @4716488 cmp */
    /* @4716492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4716536;
    /* @4716496 load */
    /* @4716504 constant */
    /* @4716508 cmp */
    /* @4716512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4716536;
    /* @4716516 load */
    /* @4716524 constant */
    /* @4716528 cmp */
    /* @4716532 b */
    p4716540_0 = NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(1));
    goto L_4716540;
    L_4716536: ;
    /* @4716536 constant */
    p4716540_0 = VAL(0);
    L_4716540: ;
    /* @4716540 bf */
    if (!TRUTH(p4716540_0)) goto L_4716692;
    /* @4716544 constant */
    /* @4716548 store */
    GM_WRITE(vm, -5, "icegun", VAL(1));
    /* @4716556 constant */
    /* @4716560 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4716568 constant */
    /* @4716572 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4716580 constant */
    /* @4716584 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4716592 constant */
    /* @4716596 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4716604 constant */
    /* @4716608 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4716616 constant */
    /* @4716620 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4716628 constant */
    /* @4716632 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4716640 constant */
    /* @4716644 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4716652 constant */
    /* @4716656 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4716664 constant */
    /* @4716668 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4716676 constant */
    /* @4716680 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4716688 b */
    goto L_4737316;
    L_4716692: ;
    /* @4716692 load */
    /* @4716700 constant */
    /* @4716704 cmp */
    /* @4716708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4716812;
    /* @4716712 load */
    /* @4716720 constant */
    /* @4716724 cmp */
    /* @4716728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4716812;
    /* @4716732 load */
    /* @4716740 constant */
    /* @4716744 cmp */
    /* @4716748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4716812;
    /* @4716752 load */
    /* @4716760 constant */
    /* @4716764 cmp */
    /* @4716768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4716812;
    /* @4716772 load */
    /* @4716780 constant */
    /* @4716784 cmp */
    /* @4716788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4716812;
    /* @4716792 load */
    /* @4716800 constant */
    /* @4716804 cmp */
    /* @4716808 b */
    p4716816_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1));
    goto L_4716816;
    L_4716812: ;
    /* @4716812 constant */
    p4716816_0 = VAL(0);
    L_4716816: ;
    /* @4716816 bf */
    if (!TRUTH(p4716816_0)) goto L_4716968;
    /* @4716820 constant */
    /* @4716824 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4716832 constant */
    /* @4716836 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4716844 constant */
    /* @4716848 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4716856 constant */
    /* @4716860 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4716868 constant */
    /* @4716872 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4716880 constant */
    /* @4716884 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4716892 constant */
    /* @4716896 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4716904 constant */
    /* @4716908 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4716916 constant */
    /* @4716920 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4716928 constant */
    /* @4716932 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4716940 constant */
    /* @4716944 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4716952 constant */
    /* @4716956 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4716964 b */
    goto L_4737316;
    L_4716968: ;
    /* @4716968 load */
    /* @4716976 constant */
    /* @4716980 cmp */
    /* @4716984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4717108;
    /* @4716988 load */
    /* @4716996 constant */
    /* @4717000 cmp */
    /* @4717004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4717108;
    /* @4717008 load */
    /* @4717016 constant */
    /* @4717020 cmp */
    /* @4717024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4717108;
    /* @4717028 load */
    /* @4717036 constant */
    /* @4717040 cmp */
    /* @4717044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4717108;
    /* @4717048 load */
    /* @4717056 constant */
    /* @4717060 cmp */
    /* @4717064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4717108;
    /* @4717068 load */
    /* @4717076 constant */
    /* @4717080 cmp */
    /* @4717084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4717108;
    /* @4717088 load */
    /* @4717096 constant */
    /* @4717100 cmp */
    /* @4717104 b */
    p4717112_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4717112;
    L_4717108: ;
    /* @4717108 constant */
    p4717112_0 = VAL(0);
    L_4717112: ;
    /* @4717112 bf */
    if (!TRUTH(p4717112_0)) goto L_4717264;
    /* @4717116 constant */
    /* @4717120 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4717128 constant */
    /* @4717132 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4717140 constant */
    /* @4717144 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4717152 constant */
    /* @4717156 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4717164 constant */
    /* @4717168 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4717176 constant */
    /* @4717180 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4717188 constant */
    /* @4717192 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4717200 constant */
    /* @4717204 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4717212 constant */
    /* @4717216 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4717224 constant */
    /* @4717228 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4717236 constant */
    /* @4717240 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4717248 constant */
    /* @4717252 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4717260 b */
    goto L_4737316;
    L_4717264: ;
    /* @4717264 load */
    /* @4717272 constant */
    /* @4717276 cmp */
    /* @4717280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4717424;
    /* @4717284 load */
    /* @4717292 constant */
    /* @4717296 cmp */
    /* @4717300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4717424;
    /* @4717304 load */
    /* @4717312 constant */
    /* @4717316 cmp */
    /* @4717320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4717424;
    /* @4717324 load */
    /* @4717332 constant */
    /* @4717336 cmp */
    /* @4717340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4717424;
    /* @4717344 load */
    /* @4717352 constant */
    /* @4717356 cmp */
    /* @4717360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4717424;
    /* @4717364 load */
    /* @4717372 constant */
    /* @4717376 cmp */
    /* @4717380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4717424;
    /* @4717384 load */
    /* @4717392 constant */
    /* @4717396 cmp */
    /* @4717400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4717424;
    /* @4717404 load */
    /* @4717412 constant */
    /* @4717416 cmp */
    /* @4717420 b */
    p4717428_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4717428;
    L_4717424: ;
    /* @4717424 constant */
    p4717428_0 = VAL(0);
    L_4717428: ;
    /* @4717428 bf */
    if (!TRUTH(p4717428_0)) goto L_4717580;
    /* @4717432 constant */
    /* @4717436 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4717444 constant */
    /* @4717448 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4717456 constant */
    /* @4717460 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4717468 constant */
    /* @4717472 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4717480 constant */
    /* @4717484 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4717492 constant */
    /* @4717496 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4717504 constant */
    /* @4717508 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4717516 constant */
    /* @4717520 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4717528 constant */
    /* @4717532 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4717540 constant */
    /* @4717544 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4717552 constant */
    /* @4717556 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4717564 constant */
    /* @4717568 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4717576 b */
    goto L_4737316;
    L_4717580: ;
    /* @4717580 load */
    /* @4717588 constant */
    /* @4717592 cmp */
    /* @4717596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4717760;
    /* @4717600 load */
    /* @4717608 constant */
    /* @4717612 cmp */
    /* @4717616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4717760;
    /* @4717620 load */
    /* @4717628 constant */
    /* @4717632 cmp */
    /* @4717636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4717760;
    /* @4717640 load */
    /* @4717648 constant */
    /* @4717652 cmp */
    /* @4717656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4717760;
    /* @4717660 load */
    /* @4717668 constant */
    /* @4717672 cmp */
    /* @4717676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4717760;
    /* @4717680 load */
    /* @4717688 constant */
    /* @4717692 cmp */
    /* @4717696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4717760;
    /* @4717700 load */
    /* @4717708 constant */
    /* @4717712 cmp */
    /* @4717716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4717760;
    /* @4717720 load */
    /* @4717728 constant */
    /* @4717732 cmp */
    /* @4717736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4717760;
    /* @4717740 load */
    /* @4717748 constant */
    /* @4717752 cmp */
    /* @4717756 b */
    p4717764_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4717764;
    L_4717760: ;
    /* @4717760 constant */
    p4717764_0 = VAL(0);
    L_4717764: ;
    /* @4717764 bf */
    if (!TRUTH(p4717764_0)) goto L_4717916;
    /* @4717768 constant */
    /* @4717772 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4717780 constant */
    /* @4717784 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4717792 constant */
    /* @4717796 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4717804 constant */
    /* @4717808 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4717816 constant */
    /* @4717820 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4717828 constant */
    /* @4717832 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4717840 constant */
    /* @4717844 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4717852 constant */
    /* @4717856 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4717864 constant */
    /* @4717868 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4717876 constant */
    /* @4717880 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4717888 constant */
    /* @4717892 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4717900 constant */
    /* @4717904 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4717912 b */
    goto L_4737316;
    L_4717916: ;
    /* @4717916 load */
    /* @4717924 constant */
    /* @4717928 cmp */
    /* @4717932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4718116;
    /* @4717936 load */
    /* @4717944 constant */
    /* @4717948 cmp */
    /* @4717952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4718116;
    /* @4717956 load */
    /* @4717964 constant */
    /* @4717968 cmp */
    /* @4717972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4718116;
    /* @4717976 load */
    /* @4717984 constant */
    /* @4717988 cmp */
    /* @4717992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4718116;
    /* @4717996 load */
    /* @4718004 constant */
    /* @4718008 cmp */
    /* @4718012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4718116;
    /* @4718016 load */
    /* @4718024 constant */
    /* @4718028 cmp */
    /* @4718032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4718116;
    /* @4718036 load */
    /* @4718044 constant */
    /* @4718048 cmp */
    /* @4718052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4718116;
    /* @4718056 load */
    /* @4718064 constant */
    /* @4718068 cmp */
    /* @4718072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4718116;
    /* @4718076 load */
    /* @4718084 constant */
    /* @4718088 cmp */
    /* @4718092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4718116;
    /* @4718096 load */
    /* @4718104 constant */
    /* @4718108 cmp */
    /* @4718112 b */
    p4718120_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4718120;
    L_4718116: ;
    /* @4718116 constant */
    p4718120_0 = VAL(0);
    L_4718120: ;
    /* @4718120 bf */
    if (!TRUTH(p4718120_0)) goto L_4718272;
    /* @4718124 constant */
    /* @4718128 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4718136 constant */
    /* @4718140 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4718148 constant */
    /* @4718152 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4718160 constant */
    /* @4718164 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4718172 constant */
    /* @4718176 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4718184 constant */
    /* @4718188 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4718196 constant */
    /* @4718200 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4718208 constant */
    /* @4718212 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4718220 constant */
    /* @4718224 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4718232 constant */
    /* @4718236 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4718244 constant */
    /* @4718248 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4718256 constant */
    /* @4718260 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4718268 b */
    goto L_4737316;
    L_4718272: ;
    /* @4718272 load */
    /* @4718280 constant */
    /* @4718284 cmp */
    /* @4718288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4718492;
    /* @4718292 load */
    /* @4718300 constant */
    /* @4718304 cmp */
    /* @4718308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4718492;
    /* @4718312 load */
    /* @4718320 constant */
    /* @4718324 cmp */
    /* @4718328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4718492;
    /* @4718332 load */
    /* @4718340 constant */
    /* @4718344 cmp */
    /* @4718348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4718492;
    /* @4718352 load */
    /* @4718360 constant */
    /* @4718364 cmp */
    /* @4718368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4718492;
    /* @4718372 load */
    /* @4718380 constant */
    /* @4718384 cmp */
    /* @4718388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4718492;
    /* @4718392 load */
    /* @4718400 constant */
    /* @4718404 cmp */
    /* @4718408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4718492;
    /* @4718412 load */
    /* @4718420 constant */
    /* @4718424 cmp */
    /* @4718428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4718492;
    /* @4718432 load */
    /* @4718440 constant */
    /* @4718444 cmp */
    /* @4718448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4718492;
    /* @4718452 load */
    /* @4718460 constant */
    /* @4718464 cmp */
    /* @4718468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4718492;
    /* @4718472 load */
    /* @4718480 constant */
    /* @4718484 cmp */
    /* @4718488 b */
    p4718496_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4718496;
    L_4718492: ;
    /* @4718492 constant */
    p4718496_0 = VAL(0);
    L_4718496: ;
    /* @4718496 bf */
    if (!TRUTH(p4718496_0)) goto L_4718648;
    /* @4718500 constant */
    /* @4718504 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4718512 constant */
    /* @4718516 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4718524 constant */
    /* @4718528 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4718536 constant */
    /* @4718540 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4718548 constant */
    /* @4718552 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4718560 constant */
    /* @4718564 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4718572 constant */
    /* @4718576 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4718584 constant */
    /* @4718588 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4718596 constant */
    /* @4718600 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4718608 constant */
    /* @4718612 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4718620 constant */
    /* @4718624 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4718632 constant */
    /* @4718636 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4718644 b */
    goto L_4737316;
    L_4718648: ;
    /* @4718648 load */
    /* @4718656 constant */
    /* @4718660 cmp */
    /* @4718664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4718888;
    /* @4718668 load */
    /* @4718676 constant */
    /* @4718680 cmp */
    /* @4718684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4718888;
    /* @4718688 load */
    /* @4718696 constant */
    /* @4718700 cmp */
    /* @4718704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4718888;
    /* @4718708 load */
    /* @4718716 constant */
    /* @4718720 cmp */
    /* @4718724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4718888;
    /* @4718728 load */
    /* @4718736 constant */
    /* @4718740 cmp */
    /* @4718744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4718888;
    /* @4718748 load */
    /* @4718756 constant */
    /* @4718760 cmp */
    /* @4718764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4718888;
    /* @4718768 load */
    /* @4718776 constant */
    /* @4718780 cmp */
    /* @4718784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4718888;
    /* @4718788 load */
    /* @4718796 constant */
    /* @4718800 cmp */
    /* @4718804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4718888;
    /* @4718808 load */
    /* @4718816 constant */
    /* @4718820 cmp */
    /* @4718824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4718888;
    /* @4718828 load */
    /* @4718836 constant */
    /* @4718840 cmp */
    /* @4718844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4718888;
    /* @4718848 load */
    /* @4718856 constant */
    /* @4718860 cmp */
    /* @4718864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4718888;
    /* @4718868 load */
    /* @4718876 constant */
    /* @4718880 cmp */
    /* @4718884 b */
    p4718892_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4718892;
    L_4718888: ;
    /* @4718888 constant */
    p4718892_0 = VAL(0);
    L_4718892: ;
    /* @4718892 bf */
    if (!TRUTH(p4718892_0)) goto L_4719044;
    /* @4718896 constant */
    /* @4718900 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4718908 constant */
    /* @4718912 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4718920 constant */
    /* @4718924 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4718932 constant */
    /* @4718936 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4718944 constant */
    /* @4718948 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4718956 constant */
    /* @4718960 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4718968 constant */
    /* @4718972 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4718980 constant */
    /* @4718984 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4718992 constant */
    /* @4718996 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4719004 constant */
    /* @4719008 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4719016 constant */
    /* @4719020 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4719028 constant */
    /* @4719032 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4719040 b */
    goto L_4737316;
    L_4719044: ;
    /* @4719044 load */
    /* @4719052 constant */
    /* @4719056 cmp */
    /* @4719060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistol") == VAL(1)))) goto L_4719284;
    /* @4719064 load */
    /* @4719072 constant */
    /* @4719076 cmp */
    /* @4719080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0)))) goto L_4719284;
    /* @4719084 load */
    /* @4719092 constant */
    /* @4719096 cmp */
    /* @4719100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4719284;
    /* @4719104 load */
    /* @4719112 constant */
    /* @4719116 cmp */
    /* @4719120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4719284;
    /* @4719124 load */
    /* @4719132 constant */
    /* @4719136 cmp */
    /* @4719140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4719284;
    /* @4719144 load */
    /* @4719152 constant */
    /* @4719156 cmp */
    /* @4719160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4719284;
    /* @4719164 load */
    /* @4719172 constant */
    /* @4719176 cmp */
    /* @4719180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4719284;
    /* @4719184 load */
    /* @4719192 constant */
    /* @4719196 cmp */
    /* @4719200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4719284;
    /* @4719204 load */
    /* @4719212 constant */
    /* @4719216 cmp */
    /* @4719220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4719284;
    /* @4719224 load */
    /* @4719232 constant */
    /* @4719236 cmp */
    /* @4719240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4719284;
    /* @4719244 load */
    /* @4719252 constant */
    /* @4719256 cmp */
    /* @4719260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4719284;
    /* @4719264 load */
    /* @4719272 constant */
    /* @4719276 cmp */
    /* @4719280 b */
    p4719288_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4719288;
    L_4719284: ;
    /* @4719284 constant */
    p4719288_0 = VAL(0);
    L_4719288: ;
    /* @4719288 bf */
    if (!TRUTH(p4719288_0)) goto L_4719440;
    /* @4719292 constant */
    /* @4719296 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4719304 constant */
    /* @4719308 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4719316 constant */
    /* @4719320 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4719328 constant */
    /* @4719332 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4719340 constant */
    /* @4719344 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4719352 constant */
    /* @4719356 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4719364 constant */
    /* @4719368 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4719376 constant */
    /* @4719380 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4719388 constant */
    /* @4719392 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4719400 constant */
    /* @4719404 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4719412 constant */
    /* @4719416 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4719424 constant */
    /* @4719428 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4719436 b */
    goto L_4737316;
    L_4719440: ;
    /* @4719440 load */
    /* @4719448 constant */
    /* @4719452 cmp */
    /* @4719456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4719480;
    /* @4719460 load */
    /* @4719468 constant */
    /* @4719472 cmp */
    /* @4719476 b */
    p4719484_0 = NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(1));
    goto L_4719484;
    L_4719480: ;
    /* @4719480 constant */
    p4719484_0 = VAL(0);
    L_4719484: ;
    /* @4719484 bf */
    if (!TRUTH(p4719484_0)) goto L_4719648;
    /* @4719488 constant */
    /* @4719492 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4719500 constant */
    /* @4719504 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(1));
    /* @4719512 constant */
    /* @4719516 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4719524 constant */
    /* @4719528 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4719536 constant */
    /* @4719540 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4719548 constant */
    /* @4719552 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4719560 constant */
    /* @4719564 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4719572 constant */
    /* @4719576 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4719584 constant */
    /* @4719588 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4719596 constant */
    /* @4719600 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4719608 constant */
    /* @4719612 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4719620 constant */
    /* @4719624 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4719632 constant */
    /* @4719636 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4719644 b */
    goto L_4737316;
    L_4719648: ;
    /* @4719648 load */
    /* @4719656 constant */
    /* @4719660 cmp */
    /* @4719664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4719708;
    /* @4719668 load */
    /* @4719676 constant */
    /* @4719680 cmp */
    /* @4719684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4719708;
    /* @4719688 load */
    /* @4719696 constant */
    /* @4719700 cmp */
    /* @4719704 b */
    p4719712_0 = NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(1));
    goto L_4719712;
    L_4719708: ;
    /* @4719708 constant */
    p4719712_0 = VAL(0);
    L_4719712: ;
    /* @4719712 bf */
    if (!TRUTH(p4719712_0)) goto L_4719876;
    /* @4719716 constant */
    /* @4719720 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4719728 constant */
    /* @4719732 store */
    GM_WRITE(vm, -5, "rocket", VAL(1));
    /* @4719740 constant */
    /* @4719744 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4719752 constant */
    /* @4719756 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4719764 constant */
    /* @4719768 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4719776 constant */
    /* @4719780 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4719788 constant */
    /* @4719792 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4719800 constant */
    /* @4719804 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4719812 constant */
    /* @4719816 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4719824 constant */
    /* @4719828 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4719836 constant */
    /* @4719840 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4719848 constant */
    /* @4719852 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4719860 constant */
    /* @4719864 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4719872 b */
    goto L_4737316;
    L_4719876: ;
    /* @4719876 load */
    /* @4719884 constant */
    /* @4719888 cmp */
    /* @4719892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4719956;
    /* @4719896 load */
    /* @4719904 constant */
    /* @4719908 cmp */
    /* @4719912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4719956;
    /* @4719916 load */
    /* @4719924 constant */
    /* @4719928 cmp */
    /* @4719932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4719956;
    /* @4719936 load */
    /* @4719944 constant */
    /* @4719948 cmp */
    /* @4719952 b */
    p4719960_0 = NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(1));
    goto L_4719960;
    L_4719956: ;
    /* @4719956 constant */
    p4719960_0 = VAL(0);
    L_4719960: ;
    /* @4719960 bf */
    if (!TRUTH(p4719960_0)) goto L_4720124;
    /* @4719964 constant */
    /* @4719968 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4719976 constant */
    /* @4719980 store */
    GM_WRITE(vm, -5, "icegun", VAL(1));
    /* @4719988 constant */
    /* @4719992 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720000 constant */
    /* @4720004 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4720012 constant */
    /* @4720016 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720024 constant */
    /* @4720028 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4720036 constant */
    /* @4720040 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4720048 constant */
    /* @4720052 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4720060 constant */
    /* @4720064 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4720072 constant */
    /* @4720076 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4720084 constant */
    /* @4720088 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4720096 constant */
    /* @4720100 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4720108 constant */
    /* @4720112 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4720120 b */
    goto L_4737316;
    L_4720124: ;
    /* @4720124 load */
    /* @4720132 constant */
    /* @4720136 cmp */
    /* @4720140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4720224;
    /* @4720144 load */
    /* @4720152 constant */
    /* @4720156 cmp */
    /* @4720160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4720224;
    /* @4720164 load */
    /* @4720172 constant */
    /* @4720176 cmp */
    /* @4720180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4720224;
    /* @4720184 load */
    /* @4720192 constant */
    /* @4720196 cmp */
    /* @4720200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4720224;
    /* @4720204 load */
    /* @4720212 constant */
    /* @4720216 cmp */
    /* @4720220 b */
    p4720228_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1));
    goto L_4720228;
    L_4720224: ;
    /* @4720224 constant */
    p4720228_0 = VAL(0);
    L_4720228: ;
    /* @4720228 bf */
    if (!TRUTH(p4720228_0)) goto L_4720392;
    /* @4720232 constant */
    /* @4720236 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4720244 constant */
    /* @4720248 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4720256 constant */
    /* @4720260 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720268 constant */
    /* @4720272 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4720280 constant */
    /* @4720284 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720292 constant */
    /* @4720296 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4720304 constant */
    /* @4720308 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4720316 constant */
    /* @4720320 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4720328 constant */
    /* @4720332 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4720340 constant */
    /* @4720344 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4720352 constant */
    /* @4720356 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4720364 constant */
    /* @4720368 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4720376 constant */
    /* @4720380 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4720388 b */
    goto L_4737316;
    L_4720392: ;
    /* @4720392 load */
    /* @4720400 constant */
    /* @4720404 cmp */
    /* @4720408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4720512;
    /* @4720412 load */
    /* @4720420 constant */
    /* @4720424 cmp */
    /* @4720428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4720512;
    /* @4720432 load */
    /* @4720440 constant */
    /* @4720444 cmp */
    /* @4720448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4720512;
    /* @4720452 load */
    /* @4720460 constant */
    /* @4720464 cmp */
    /* @4720468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4720512;
    /* @4720472 load */
    /* @4720480 constant */
    /* @4720484 cmp */
    /* @4720488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4720512;
    /* @4720492 load */
    /* @4720500 constant */
    /* @4720504 cmp */
    /* @4720508 b */
    p4720516_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4720516;
    L_4720512: ;
    /* @4720512 constant */
    p4720516_0 = VAL(0);
    L_4720516: ;
    /* @4720516 bf */
    if (!TRUTH(p4720516_0)) goto L_4720680;
    /* @4720520 constant */
    /* @4720524 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4720532 constant */
    /* @4720536 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720544 constant */
    /* @4720548 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4720556 constant */
    /* @4720560 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4720568 constant */
    /* @4720572 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720580 constant */
    /* @4720584 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4720592 constant */
    /* @4720596 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4720604 constant */
    /* @4720608 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4720616 constant */
    /* @4720620 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4720628 constant */
    /* @4720632 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4720640 constant */
    /* @4720644 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4720652 constant */
    /* @4720656 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4720664 constant */
    /* @4720668 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4720676 b */
    goto L_4737316;
    L_4720680: ;
    /* @4720680 load */
    /* @4720688 constant */
    /* @4720692 cmp */
    /* @4720696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4720820;
    /* @4720700 load */
    /* @4720708 constant */
    /* @4720712 cmp */
    /* @4720716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4720820;
    /* @4720720 load */
    /* @4720728 constant */
    /* @4720732 cmp */
    /* @4720736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4720820;
    /* @4720740 load */
    /* @4720748 constant */
    /* @4720752 cmp */
    /* @4720756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4720820;
    /* @4720760 load */
    /* @4720768 constant */
    /* @4720772 cmp */
    /* @4720776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4720820;
    /* @4720780 load */
    /* @4720788 constant */
    /* @4720792 cmp */
    /* @4720796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4720820;
    /* @4720800 load */
    /* @4720808 constant */
    /* @4720812 cmp */
    /* @4720816 b */
    p4720824_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4720824;
    L_4720820: ;
    /* @4720820 constant */
    p4720824_0 = VAL(0);
    L_4720824: ;
    /* @4720824 bf */
    if (!TRUTH(p4720824_0)) goto L_4720988;
    /* @4720828 constant */
    /* @4720832 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4720840 constant */
    /* @4720844 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720852 constant */
    /* @4720856 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4720864 constant */
    /* @4720868 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4720876 constant */
    /* @4720880 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4720888 constant */
    /* @4720892 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4720900 constant */
    /* @4720904 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4720912 constant */
    /* @4720916 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4720924 constant */
    /* @4720928 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4720936 constant */
    /* @4720940 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4720948 constant */
    /* @4720952 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4720960 constant */
    /* @4720964 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4720972 constant */
    /* @4720976 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4720984 b */
    goto L_4737316;
    L_4720988: ;
    /* @4720988 load */
    /* @4720996 constant */
    /* @4721000 cmp */
    /* @4721004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4721148;
    /* @4721008 load */
    /* @4721016 constant */
    /* @4721020 cmp */
    /* @4721024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4721148;
    /* @4721028 load */
    /* @4721036 constant */
    /* @4721040 cmp */
    /* @4721044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4721148;
    /* @4721048 load */
    /* @4721056 constant */
    /* @4721060 cmp */
    /* @4721064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4721148;
    /* @4721068 load */
    /* @4721076 constant */
    /* @4721080 cmp */
    /* @4721084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4721148;
    /* @4721088 load */
    /* @4721096 constant */
    /* @4721100 cmp */
    /* @4721104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4721148;
    /* @4721108 load */
    /* @4721116 constant */
    /* @4721120 cmp */
    /* @4721124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4721148;
    /* @4721128 load */
    /* @4721136 constant */
    /* @4721140 cmp */
    /* @4721144 b */
    p4721152_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4721152;
    L_4721148: ;
    /* @4721148 constant */
    p4721152_0 = VAL(0);
    L_4721152: ;
    /* @4721152 bf */
    if (!TRUTH(p4721152_0)) goto L_4721316;
    /* @4721156 constant */
    /* @4721160 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4721168 constant */
    /* @4721172 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721180 constant */
    /* @4721184 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4721192 constant */
    /* @4721196 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4721204 constant */
    /* @4721208 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721216 constant */
    /* @4721220 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4721228 constant */
    /* @4721232 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4721240 constant */
    /* @4721244 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4721252 constant */
    /* @4721256 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4721264 constant */
    /* @4721268 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4721276 constant */
    /* @4721280 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4721288 constant */
    /* @4721292 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4721300 constant */
    /* @4721304 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4721312 b */
    goto L_4737316;
    L_4721316: ;
    /* @4721316 load */
    /* @4721324 constant */
    /* @4721328 cmp */
    /* @4721332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4721496;
    /* @4721336 load */
    /* @4721344 constant */
    /* @4721348 cmp */
    /* @4721352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4721496;
    /* @4721356 load */
    /* @4721364 constant */
    /* @4721368 cmp */
    /* @4721372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4721496;
    /* @4721376 load */
    /* @4721384 constant */
    /* @4721388 cmp */
    /* @4721392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4721496;
    /* @4721396 load */
    /* @4721404 constant */
    /* @4721408 cmp */
    /* @4721412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4721496;
    /* @4721416 load */
    /* @4721424 constant */
    /* @4721428 cmp */
    /* @4721432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4721496;
    /* @4721436 load */
    /* @4721444 constant */
    /* @4721448 cmp */
    /* @4721452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4721496;
    /* @4721456 load */
    /* @4721464 constant */
    /* @4721468 cmp */
    /* @4721472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4721496;
    /* @4721476 load */
    /* @4721484 constant */
    /* @4721488 cmp */
    /* @4721492 b */
    p4721500_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4721500;
    L_4721496: ;
    /* @4721496 constant */
    p4721500_0 = VAL(0);
    L_4721500: ;
    /* @4721500 bf */
    if (!TRUTH(p4721500_0)) goto L_4721664;
    /* @4721504 constant */
    /* @4721508 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4721516 constant */
    /* @4721520 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721528 constant */
    /* @4721532 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4721540 constant */
    /* @4721544 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721552 constant */
    /* @4721556 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4721564 constant */
    /* @4721568 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4721576 constant */
    /* @4721580 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4721588 constant */
    /* @4721592 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4721600 constant */
    /* @4721604 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4721612 constant */
    /* @4721616 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4721624 constant */
    /* @4721628 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4721636 constant */
    /* @4721640 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4721648 constant */
    /* @4721652 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4721660 b */
    goto L_4737316;
    L_4721664: ;
    /* @4721664 load */
    /* @4721672 constant */
    /* @4721676 cmp */
    /* @4721680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4721864;
    /* @4721684 load */
    /* @4721692 constant */
    /* @4721696 cmp */
    /* @4721700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4721864;
    /* @4721704 load */
    /* @4721712 constant */
    /* @4721716 cmp */
    /* @4721720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4721864;
    /* @4721724 load */
    /* @4721732 constant */
    /* @4721736 cmp */
    /* @4721740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4721864;
    /* @4721744 load */
    /* @4721752 constant */
    /* @4721756 cmp */
    /* @4721760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4721864;
    /* @4721764 load */
    /* @4721772 constant */
    /* @4721776 cmp */
    /* @4721780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4721864;
    /* @4721784 load */
    /* @4721792 constant */
    /* @4721796 cmp */
    /* @4721800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4721864;
    /* @4721804 load */
    /* @4721812 constant */
    /* @4721816 cmp */
    /* @4721820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4721864;
    /* @4721824 load */
    /* @4721832 constant */
    /* @4721836 cmp */
    /* @4721840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4721864;
    /* @4721844 load */
    /* @4721852 constant */
    /* @4721856 cmp */
    /* @4721860 b */
    p4721868_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4721868;
    L_4721864: ;
    /* @4721864 constant */
    p4721868_0 = VAL(0);
    L_4721868: ;
    /* @4721868 bf */
    if (!TRUTH(p4721868_0)) goto L_4722032;
    /* @4721872 constant */
    /* @4721876 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4721884 constant */
    /* @4721888 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721896 constant */
    /* @4721900 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4721908 constant */
    /* @4721912 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4721920 constant */
    /* @4721924 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4721932 constant */
    /* @4721936 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4721944 constant */
    /* @4721948 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4721956 constant */
    /* @4721960 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4721968 constant */
    /* @4721972 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4721980 constant */
    /* @4721984 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4721992 constant */
    /* @4721996 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4722004 constant */
    /* @4722008 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4722016 constant */
    /* @4722020 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4722028 b */
    goto L_4737316;
    L_4722032: ;
    /* @4722032 load */
    /* @4722040 constant */
    /* @4722044 cmp */
    /* @4722048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4722252;
    /* @4722052 load */
    /* @4722060 constant */
    /* @4722064 cmp */
    /* @4722068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4722252;
    /* @4722072 load */
    /* @4722080 constant */
    /* @4722084 cmp */
    /* @4722088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4722252;
    /* @4722092 load */
    /* @4722100 constant */
    /* @4722104 cmp */
    /* @4722108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4722252;
    /* @4722112 load */
    /* @4722120 constant */
    /* @4722124 cmp */
    /* @4722128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4722252;
    /* @4722132 load */
    /* @4722140 constant */
    /* @4722144 cmp */
    /* @4722148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4722252;
    /* @4722152 load */
    /* @4722160 constant */
    /* @4722164 cmp */
    /* @4722168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4722252;
    /* @4722172 load */
    /* @4722180 constant */
    /* @4722184 cmp */
    /* @4722188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4722252;
    /* @4722192 load */
    /* @4722200 constant */
    /* @4722204 cmp */
    /* @4722208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4722252;
    /* @4722212 load */
    /* @4722220 constant */
    /* @4722224 cmp */
    /* @4722228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4722252;
    /* @4722232 load */
    /* @4722240 constant */
    /* @4722244 cmp */
    /* @4722248 b */
    p4722256_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4722256;
    L_4722252: ;
    /* @4722252 constant */
    p4722256_0 = VAL(0);
    L_4722256: ;
    /* @4722256 bf */
    if (!TRUTH(p4722256_0)) goto L_4722420;
    /* @4722260 constant */
    /* @4722264 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4722272 constant */
    /* @4722276 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722284 constant */
    /* @4722288 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4722296 constant */
    /* @4722300 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722308 constant */
    /* @4722312 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4722320 constant */
    /* @4722324 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4722332 constant */
    /* @4722336 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4722344 constant */
    /* @4722348 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4722356 constant */
    /* @4722360 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4722368 constant */
    /* @4722372 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4722380 constant */
    /* @4722384 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4722392 constant */
    /* @4722396 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4722404 constant */
    /* @4722408 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4722416 b */
    goto L_4737316;
    L_4722420: ;
    /* @4722420 load */
    /* @4722428 constant */
    /* @4722432 cmp */
    /* @4722436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgun") == VAL(1)))) goto L_4722640;
    /* @4722440 load */
    /* @4722448 constant */
    /* @4722452 cmp */
    /* @4722456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0)))) goto L_4722640;
    /* @4722460 load */
    /* @4722468 constant */
    /* @4722472 cmp */
    /* @4722476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4722640;
    /* @4722480 load */
    /* @4722488 constant */
    /* @4722492 cmp */
    /* @4722496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4722640;
    /* @4722500 load */
    /* @4722508 constant */
    /* @4722512 cmp */
    /* @4722516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4722640;
    /* @4722520 load */
    /* @4722528 constant */
    /* @4722532 cmp */
    /* @4722536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4722640;
    /* @4722540 load */
    /* @4722548 constant */
    /* @4722552 cmp */
    /* @4722556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4722640;
    /* @4722560 load */
    /* @4722568 constant */
    /* @4722572 cmp */
    /* @4722576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4722640;
    /* @4722580 load */
    /* @4722588 constant */
    /* @4722592 cmp */
    /* @4722596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4722640;
    /* @4722600 load */
    /* @4722608 constant */
    /* @4722612 cmp */
    /* @4722616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4722640;
    /* @4722620 load */
    /* @4722628 constant */
    /* @4722632 cmp */
    /* @4722636 b */
    p4722644_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4722644;
    L_4722640: ;
    /* @4722640 constant */
    p4722644_0 = VAL(0);
    L_4722644: ;
    /* @4722644 bf */
    if (!TRUTH(p4722644_0)) goto L_4722808;
    /* @4722648 constant */
    /* @4722652 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4722660 constant */
    /* @4722664 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722672 constant */
    /* @4722676 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4722684 constant */
    /* @4722688 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722696 constant */
    /* @4722700 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4722708 constant */
    /* @4722712 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4722720 constant */
    /* @4722724 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4722732 constant */
    /* @4722736 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4722744 constant */
    /* @4722748 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4722756 constant */
    /* @4722760 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4722768 constant */
    /* @4722772 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4722780 constant */
    /* @4722784 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4722792 constant */
    /* @4722796 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4722804 b */
    goto L_4737316;
    L_4722808: ;
    /* @4722808 load */
    /* @4722816 constant */
    /* @4722820 cmp */
    /* @4722824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4722848;
    /* @4722828 load */
    /* @4722836 constant */
    /* @4722840 cmp */
    /* @4722844 b */
    p4722852_0 = NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(1));
    goto L_4722852;
    L_4722848: ;
    /* @4722848 constant */
    p4722852_0 = VAL(0);
    L_4722852: ;
    /* @4722852 bf */
    if (!TRUTH(p4722852_0)) goto L_4723016;
    /* @4722856 constant */
    /* @4722860 store */
    GM_WRITE(vm, -5, "rocket", VAL(1));
    /* @4722868 constant */
    /* @4722872 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4722880 constant */
    /* @4722884 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722892 constant */
    /* @4722896 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4722904 constant */
    /* @4722908 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4722916 constant */
    /* @4722920 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4722928 constant */
    /* @4722932 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4722940 constant */
    /* @4722944 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4722952 constant */
    /* @4722956 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4722964 constant */
    /* @4722968 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4722976 constant */
    /* @4722980 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4722988 constant */
    /* @4722992 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4723000 constant */
    /* @4723004 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4723012 b */
    goto L_4737316;
    L_4723016: ;
    /* @4723016 load */
    /* @4723024 constant */
    /* @4723028 cmp */
    /* @4723032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4723076;
    /* @4723036 load */
    /* @4723044 constant */
    /* @4723048 cmp */
    /* @4723052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4723076;
    /* @4723056 load */
    /* @4723064 constant */
    /* @4723068 cmp */
    /* @4723072 b */
    p4723080_0 = NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(1));
    goto L_4723080;
    L_4723076: ;
    /* @4723076 constant */
    p4723080_0 = VAL(0);
    L_4723080: ;
    /* @4723080 bf */
    if (!TRUTH(p4723080_0)) goto L_4723244;
    /* @4723084 constant */
    /* @4723088 store */
    GM_WRITE(vm, -5, "icegun", VAL(1));
    /* @4723096 constant */
    /* @4723100 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4723108 constant */
    /* @4723112 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723120 constant */
    /* @4723124 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4723132 constant */
    /* @4723136 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723144 constant */
    /* @4723148 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4723156 constant */
    /* @4723160 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4723168 constant */
    /* @4723172 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4723180 constant */
    /* @4723184 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4723192 constant */
    /* @4723196 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4723204 constant */
    /* @4723208 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4723216 constant */
    /* @4723220 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4723228 constant */
    /* @4723232 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4723240 b */
    goto L_4737316;
    L_4723244: ;
    /* @4723244 load */
    /* @4723252 constant */
    /* @4723256 cmp */
    /* @4723260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4723324;
    /* @4723264 load */
    /* @4723272 constant */
    /* @4723276 cmp */
    /* @4723280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4723324;
    /* @4723284 load */
    /* @4723292 constant */
    /* @4723296 cmp */
    /* @4723300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4723324;
    /* @4723304 load */
    /* @4723312 constant */
    /* @4723316 cmp */
    /* @4723320 b */
    p4723328_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1));
    goto L_4723328;
    L_4723324: ;
    /* @4723324 constant */
    p4723328_0 = VAL(0);
    L_4723328: ;
    /* @4723328 bf */
    if (!TRUTH(p4723328_0)) goto L_4723492;
    /* @4723332 constant */
    /* @4723336 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4723344 constant */
    /* @4723348 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4723356 constant */
    /* @4723360 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723368 constant */
    /* @4723372 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4723380 constant */
    /* @4723384 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723392 constant */
    /* @4723396 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4723404 constant */
    /* @4723408 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4723416 constant */
    /* @4723420 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4723428 constant */
    /* @4723432 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4723440 constant */
    /* @4723444 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4723452 constant */
    /* @4723456 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4723464 constant */
    /* @4723468 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4723476 constant */
    /* @4723480 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4723488 b */
    goto L_4737316;
    L_4723492: ;
    /* @4723492 load */
    /* @4723500 constant */
    /* @4723504 cmp */
    /* @4723508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4723592;
    /* @4723512 load */
    /* @4723520 constant */
    /* @4723524 cmp */
    /* @4723528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4723592;
    /* @4723532 load */
    /* @4723540 constant */
    /* @4723544 cmp */
    /* @4723548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4723592;
    /* @4723552 load */
    /* @4723560 constant */
    /* @4723564 cmp */
    /* @4723568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4723592;
    /* @4723572 load */
    /* @4723580 constant */
    /* @4723584 cmp */
    /* @4723588 b */
    p4723596_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4723596;
    L_4723592: ;
    /* @4723592 constant */
    p4723596_0 = VAL(0);
    L_4723596: ;
    /* @4723596 bf */
    if (!TRUTH(p4723596_0)) goto L_4723760;
    /* @4723600 constant */
    /* @4723604 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4723612 constant */
    /* @4723616 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4723624 constant */
    /* @4723628 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723636 constant */
    /* @4723640 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4723648 constant */
    /* @4723652 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723660 constant */
    /* @4723664 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4723672 constant */
    /* @4723676 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4723684 constant */
    /* @4723688 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4723696 constant */
    /* @4723700 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4723708 constant */
    /* @4723712 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4723720 constant */
    /* @4723724 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4723732 constant */
    /* @4723736 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4723744 constant */
    /* @4723748 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4723756 b */
    goto L_4737316;
    L_4723760: ;
    /* @4723760 load */
    /* @4723768 constant */
    /* @4723772 cmp */
    /* @4723776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4723880;
    /* @4723780 load */
    /* @4723788 constant */
    /* @4723792 cmp */
    /* @4723796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4723880;
    /* @4723800 load */
    /* @4723808 constant */
    /* @4723812 cmp */
    /* @4723816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4723880;
    /* @4723820 load */
    /* @4723828 constant */
    /* @4723832 cmp */
    /* @4723836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4723880;
    /* @4723840 load */
    /* @4723848 constant */
    /* @4723852 cmp */
    /* @4723856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4723880;
    /* @4723860 load */
    /* @4723868 constant */
    /* @4723872 cmp */
    /* @4723876 b */
    p4723884_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4723884;
    L_4723880: ;
    /* @4723880 constant */
    p4723884_0 = VAL(0);
    L_4723884: ;
    /* @4723884 bf */
    if (!TRUTH(p4723884_0)) goto L_4724048;
    /* @4723888 constant */
    /* @4723892 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4723900 constant */
    /* @4723904 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4723912 constant */
    /* @4723916 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723924 constant */
    /* @4723928 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4723936 constant */
    /* @4723940 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4723948 constant */
    /* @4723952 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4723960 constant */
    /* @4723964 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4723972 constant */
    /* @4723976 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4723984 constant */
    /* @4723988 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4723996 constant */
    /* @4724000 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4724008 constant */
    /* @4724012 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4724020 constant */
    /* @4724024 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4724032 constant */
    /* @4724036 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4724044 b */
    goto L_4737316;
    L_4724048: ;
    /* @4724048 load */
    /* @4724056 constant */
    /* @4724060 cmp */
    /* @4724064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4724188;
    /* @4724068 load */
    /* @4724076 constant */
    /* @4724080 cmp */
    /* @4724084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4724188;
    /* @4724088 load */
    /* @4724096 constant */
    /* @4724100 cmp */
    /* @4724104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4724188;
    /* @4724108 load */
    /* @4724116 constant */
    /* @4724120 cmp */
    /* @4724124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4724188;
    /* @4724128 load */
    /* @4724136 constant */
    /* @4724140 cmp */
    /* @4724144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4724188;
    /* @4724148 load */
    /* @4724156 constant */
    /* @4724160 cmp */
    /* @4724164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4724188;
    /* @4724168 load */
    /* @4724176 constant */
    /* @4724180 cmp */
    /* @4724184 b */
    p4724192_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4724192;
    L_4724188: ;
    /* @4724188 constant */
    p4724192_0 = VAL(0);
    L_4724192: ;
    /* @4724192 bf */
    if (!TRUTH(p4724192_0)) goto L_4724356;
    /* @4724196 constant */
    /* @4724200 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4724208 constant */
    /* @4724212 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4724220 constant */
    /* @4724224 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724232 constant */
    /* @4724236 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4724244 constant */
    /* @4724248 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724256 constant */
    /* @4724260 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4724268 constant */
    /* @4724272 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4724280 constant */
    /* @4724284 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4724292 constant */
    /* @4724296 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4724304 constant */
    /* @4724308 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4724316 constant */
    /* @4724320 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4724328 constant */
    /* @4724332 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4724340 constant */
    /* @4724344 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4724352 b */
    goto L_4737316;
    L_4724356: ;
    /* @4724356 load */
    /* @4724364 constant */
    /* @4724368 cmp */
    /* @4724372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4724516;
    /* @4724376 load */
    /* @4724384 constant */
    /* @4724388 cmp */
    /* @4724392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4724516;
    /* @4724396 load */
    /* @4724404 constant */
    /* @4724408 cmp */
    /* @4724412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4724516;
    /* @4724416 load */
    /* @4724424 constant */
    /* @4724428 cmp */
    /* @4724432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4724516;
    /* @4724436 load */
    /* @4724444 constant */
    /* @4724448 cmp */
    /* @4724452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4724516;
    /* @4724456 load */
    /* @4724464 constant */
    /* @4724468 cmp */
    /* @4724472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4724516;
    /* @4724476 load */
    /* @4724484 constant */
    /* @4724488 cmp */
    /* @4724492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4724516;
    /* @4724496 load */
    /* @4724504 constant */
    /* @4724508 cmp */
    /* @4724512 b */
    p4724520_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4724520;
    L_4724516: ;
    /* @4724516 constant */
    p4724520_0 = VAL(0);
    L_4724520: ;
    /* @4724520 bf */
    if (!TRUTH(p4724520_0)) goto L_4724684;
    /* @4724524 constant */
    /* @4724528 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4724536 constant */
    /* @4724540 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724548 constant */
    /* @4724552 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4724560 constant */
    /* @4724564 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724572 constant */
    /* @4724576 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4724584 constant */
    /* @4724588 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4724596 constant */
    /* @4724600 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4724608 constant */
    /* @4724612 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4724620 constant */
    /* @4724624 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4724632 constant */
    /* @4724636 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4724644 constant */
    /* @4724648 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4724656 constant */
    /* @4724660 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4724668 constant */
    /* @4724672 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4724680 b */
    goto L_4737316;
    L_4724684: ;
    /* @4724684 load */
    /* @4724692 constant */
    /* @4724696 cmp */
    /* @4724700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4724864;
    /* @4724704 load */
    /* @4724712 constant */
    /* @4724716 cmp */
    /* @4724720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4724864;
    /* @4724724 load */
    /* @4724732 constant */
    /* @4724736 cmp */
    /* @4724740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4724864;
    /* @4724744 load */
    /* @4724752 constant */
    /* @4724756 cmp */
    /* @4724760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4724864;
    /* @4724764 load */
    /* @4724772 constant */
    /* @4724776 cmp */
    /* @4724780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4724864;
    /* @4724784 load */
    /* @4724792 constant */
    /* @4724796 cmp */
    /* @4724800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4724864;
    /* @4724804 load */
    /* @4724812 constant */
    /* @4724816 cmp */
    /* @4724820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4724864;
    /* @4724824 load */
    /* @4724832 constant */
    /* @4724836 cmp */
    /* @4724840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4724864;
    /* @4724844 load */
    /* @4724852 constant */
    /* @4724856 cmp */
    /* @4724860 b */
    p4724868_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4724868;
    L_4724864: ;
    /* @4724864 constant */
    p4724868_0 = VAL(0);
    L_4724868: ;
    /* @4724868 bf */
    if (!TRUTH(p4724868_0)) goto L_4725032;
    /* @4724872 constant */
    /* @4724876 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4724884 constant */
    /* @4724888 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724896 constant */
    /* @4724900 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4724908 constant */
    /* @4724912 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4724920 constant */
    /* @4724924 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4724932 constant */
    /* @4724936 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4724944 constant */
    /* @4724948 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4724956 constant */
    /* @4724960 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4724968 constant */
    /* @4724972 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4724980 constant */
    /* @4724984 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4724992 constant */
    /* @4724996 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4725004 constant */
    /* @4725008 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4725016 constant */
    /* @4725020 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4725028 b */
    goto L_4737316;
    L_4725032: ;
    /* @4725032 load */
    /* @4725040 constant */
    /* @4725044 cmp */
    /* @4725048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4725232;
    /* @4725052 load */
    /* @4725060 constant */
    /* @4725064 cmp */
    /* @4725068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4725232;
    /* @4725072 load */
    /* @4725080 constant */
    /* @4725084 cmp */
    /* @4725088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4725232;
    /* @4725092 load */
    /* @4725100 constant */
    /* @4725104 cmp */
    /* @4725108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4725232;
    /* @4725112 load */
    /* @4725120 constant */
    /* @4725124 cmp */
    /* @4725128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4725232;
    /* @4725132 load */
    /* @4725140 constant */
    /* @4725144 cmp */
    /* @4725148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4725232;
    /* @4725152 load */
    /* @4725160 constant */
    /* @4725164 cmp */
    /* @4725168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4725232;
    /* @4725172 load */
    /* @4725180 constant */
    /* @4725184 cmp */
    /* @4725188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4725232;
    /* @4725192 load */
    /* @4725200 constant */
    /* @4725204 cmp */
    /* @4725208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4725232;
    /* @4725212 load */
    /* @4725220 constant */
    /* @4725224 cmp */
    /* @4725228 b */
    p4725236_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4725236;
    L_4725232: ;
    /* @4725232 constant */
    p4725236_0 = VAL(0);
    L_4725236: ;
    /* @4725236 bf */
    if (!TRUTH(p4725236_0)) goto L_4725400;
    /* @4725240 constant */
    /* @4725244 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4725252 constant */
    /* @4725256 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725264 constant */
    /* @4725268 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4725276 constant */
    /* @4725280 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725288 constant */
    /* @4725292 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4725300 constant */
    /* @4725304 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4725312 constant */
    /* @4725316 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4725324 constant */
    /* @4725328 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4725336 constant */
    /* @4725340 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4725348 constant */
    /* @4725352 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4725360 constant */
    /* @4725364 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4725372 constant */
    /* @4725376 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4725384 constant */
    /* @4725388 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4725396 b */
    goto L_4737316;
    L_4725400: ;
    /* @4725400 load */
    /* @4725408 constant */
    /* @4725412 cmp */
    /* @4725416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4725580;
    /* @4725420 load */
    /* @4725428 constant */
    /* @4725432 cmp */
    /* @4725436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0)))) goto L_4725580;
    /* @4725440 load */
    /* @4725448 constant */
    /* @4725452 cmp */
    /* @4725456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4725580;
    /* @4725460 load */
    /* @4725468 constant */
    /* @4725472 cmp */
    /* @4725476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4725580;
    /* @4725480 load */
    /* @4725488 constant */
    /* @4725492 cmp */
    /* @4725496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4725580;
    /* @4725500 load */
    /* @4725508 constant */
    /* @4725512 cmp */
    /* @4725516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4725580;
    /* @4725520 load */
    /* @4725528 constant */
    /* @4725532 cmp */
    /* @4725536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4725580;
    /* @4725540 load */
    /* @4725548 constant */
    /* @4725552 cmp */
    /* @4725556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4725580;
    /* @4725560 load */
    /* @4725568 constant */
    /* @4725572 cmp */
    /* @4725576 b */
    p4725584_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0));
    goto L_4725584;
    L_4725580: ;
    /* @4725580 constant */
    p4725584_0 = VAL(0);
    L_4725584: ;
    /* @4725584 bf */
    if (!TRUTH(p4725584_0)) goto L_4725748;
    /* @4725588 constant */
    /* @4725592 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4725600 constant */
    /* @4725604 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725612 constant */
    /* @4725616 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4725624 constant */
    /* @4725628 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725636 constant */
    /* @4725640 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4725648 constant */
    /* @4725652 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4725660 constant */
    /* @4725664 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4725672 constant */
    /* @4725676 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4725684 constant */
    /* @4725688 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4725696 constant */
    /* @4725700 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4725708 constant */
    /* @4725712 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4725720 constant */
    /* @4725724 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4725732 constant */
    /* @4725736 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4725744 b */
    goto L_4737316;
    L_4725748: ;
    /* @4725748 load */
    /* @4725756 constant */
    /* @4725760 cmp */
    /* @4725764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4725788;
    /* @4725768 load */
    /* @4725776 constant */
    /* @4725780 cmp */
    /* @4725784 b */
    p4725792_0 = NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(1));
    goto L_4725792;
    L_4725788: ;
    /* @4725788 constant */
    p4725792_0 = VAL(0);
    L_4725792: ;
    /* @4725792 bf */
    if (!TRUTH(p4725792_0)) goto L_4725956;
    /* @4725796 constant */
    /* @4725800 store */
    GM_WRITE(vm, -5, "icegun", VAL(1));
    /* @4725808 constant */
    /* @4725812 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4725820 constant */
    /* @4725824 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725832 constant */
    /* @4725836 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4725844 constant */
    /* @4725848 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4725856 constant */
    /* @4725860 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4725868 constant */
    /* @4725872 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4725880 constant */
    /* @4725884 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4725892 constant */
    /* @4725896 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4725904 constant */
    /* @4725908 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4725916 constant */
    /* @4725920 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4725928 constant */
    /* @4725932 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4725940 constant */
    /* @4725944 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4725952 b */
    goto L_4737316;
    L_4725956: ;
    /* @4725956 load */
    /* @4725964 constant */
    /* @4725968 cmp */
    /* @4725972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4726016;
    /* @4725976 load */
    /* @4725984 constant */
    /* @4725988 cmp */
    /* @4725992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4726016;
    /* @4725996 load */
    /* @4726004 constant */
    /* @4726008 cmp */
    /* @4726012 b */
    p4726020_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1));
    goto L_4726020;
    L_4726016: ;
    /* @4726016 constant */
    p4726020_0 = VAL(0);
    L_4726020: ;
    /* @4726020 bf */
    if (!TRUTH(p4726020_0)) goto L_4726184;
    /* @4726024 constant */
    /* @4726028 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4726036 constant */
    /* @4726040 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4726048 constant */
    /* @4726052 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726060 constant */
    /* @4726064 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4726072 constant */
    /* @4726076 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4726084 constant */
    /* @4726088 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726096 constant */
    /* @4726100 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4726108 constant */
    /* @4726112 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4726120 constant */
    /* @4726124 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4726132 constant */
    /* @4726136 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4726144 constant */
    /* @4726148 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4726156 constant */
    /* @4726160 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4726168 constant */
    /* @4726172 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4726180 b */
    goto L_4737316;
    L_4726184: ;
    /* @4726184 load */
    /* @4726192 constant */
    /* @4726196 cmp */
    /* @4726200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4726264;
    /* @4726204 load */
    /* @4726212 constant */
    /* @4726216 cmp */
    /* @4726220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4726264;
    /* @4726224 load */
    /* @4726232 constant */
    /* @4726236 cmp */
    /* @4726240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4726264;
    /* @4726244 load */
    /* @4726252 constant */
    /* @4726256 cmp */
    /* @4726260 b */
    p4726268_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4726268;
    L_4726264: ;
    /* @4726264 constant */
    p4726268_0 = VAL(0);
    L_4726268: ;
    /* @4726268 bf */
    if (!TRUTH(p4726268_0)) goto L_4726432;
    /* @4726272 constant */
    /* @4726276 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4726284 constant */
    /* @4726288 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4726296 constant */
    /* @4726300 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726308 constant */
    /* @4726312 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4726320 constant */
    /* @4726324 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4726332 constant */
    /* @4726336 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726344 constant */
    /* @4726348 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4726356 constant */
    /* @4726360 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4726368 constant */
    /* @4726372 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4726380 constant */
    /* @4726384 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4726392 constant */
    /* @4726396 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4726404 constant */
    /* @4726408 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4726416 constant */
    /* @4726420 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4726428 b */
    goto L_4737316;
    L_4726432: ;
    /* @4726432 load */
    /* @4726440 constant */
    /* @4726444 cmp */
    /* @4726448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4726532;
    /* @4726452 load */
    /* @4726460 constant */
    /* @4726464 cmp */
    /* @4726468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4726532;
    /* @4726472 load */
    /* @4726480 constant */
    /* @4726484 cmp */
    /* @4726488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4726532;
    /* @4726492 load */
    /* @4726500 constant */
    /* @4726504 cmp */
    /* @4726508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4726532;
    /* @4726512 load */
    /* @4726520 constant */
    /* @4726524 cmp */
    /* @4726528 b */
    p4726536_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4726536;
    L_4726532: ;
    /* @4726532 constant */
    p4726536_0 = VAL(0);
    L_4726536: ;
    /* @4726536 bf */
    if (!TRUTH(p4726536_0)) goto L_4726700;
    /* @4726540 constant */
    /* @4726544 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4726552 constant */
    /* @4726556 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4726564 constant */
    /* @4726568 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726576 constant */
    /* @4726580 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4726588 constant */
    /* @4726592 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4726600 constant */
    /* @4726604 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726612 constant */
    /* @4726616 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4726624 constant */
    /* @4726628 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4726636 constant */
    /* @4726640 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4726648 constant */
    /* @4726652 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4726660 constant */
    /* @4726664 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4726672 constant */
    /* @4726676 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4726684 constant */
    /* @4726688 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4726696 b */
    goto L_4737316;
    L_4726700: ;
    /* @4726700 load */
    /* @4726708 constant */
    /* @4726712 cmp */
    /* @4726716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4726820;
    /* @4726720 load */
    /* @4726728 constant */
    /* @4726732 cmp */
    /* @4726736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4726820;
    /* @4726740 load */
    /* @4726748 constant */
    /* @4726752 cmp */
    /* @4726756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4726820;
    /* @4726760 load */
    /* @4726768 constant */
    /* @4726772 cmp */
    /* @4726776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4726820;
    /* @4726780 load */
    /* @4726788 constant */
    /* @4726792 cmp */
    /* @4726796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4726820;
    /* @4726800 load */
    /* @4726808 constant */
    /* @4726812 cmp */
    /* @4726816 b */
    p4726824_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4726824;
    L_4726820: ;
    /* @4726820 constant */
    p4726824_0 = VAL(0);
    L_4726824: ;
    /* @4726824 bf */
    if (!TRUTH(p4726824_0)) goto L_4726988;
    /* @4726828 constant */
    /* @4726832 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4726840 constant */
    /* @4726844 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4726852 constant */
    /* @4726856 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726864 constant */
    /* @4726868 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4726876 constant */
    /* @4726880 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4726888 constant */
    /* @4726892 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4726900 constant */
    /* @4726904 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4726912 constant */
    /* @4726916 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4726924 constant */
    /* @4726928 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4726936 constant */
    /* @4726940 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4726948 constant */
    /* @4726952 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4726960 constant */
    /* @4726964 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4726972 constant */
    /* @4726976 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4726984 b */
    goto L_4737316;
    L_4726988: ;
    /* @4726988 load */
    /* @4726996 constant */
    /* @4727000 cmp */
    /* @4727004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4727128;
    /* @4727008 load */
    /* @4727016 constant */
    /* @4727020 cmp */
    /* @4727024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4727128;
    /* @4727028 load */
    /* @4727036 constant */
    /* @4727040 cmp */
    /* @4727044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4727128;
    /* @4727048 load */
    /* @4727056 constant */
    /* @4727060 cmp */
    /* @4727064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4727128;
    /* @4727068 load */
    /* @4727076 constant */
    /* @4727080 cmp */
    /* @4727084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4727128;
    /* @4727088 load */
    /* @4727096 constant */
    /* @4727100 cmp */
    /* @4727104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4727128;
    /* @4727108 load */
    /* @4727116 constant */
    /* @4727120 cmp */
    /* @4727124 b */
    p4727132_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4727132;
    L_4727128: ;
    /* @4727128 constant */
    p4727132_0 = VAL(0);
    L_4727132: ;
    /* @4727132 bf */
    if (!TRUTH(p4727132_0)) goto L_4727296;
    /* @4727136 constant */
    /* @4727140 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4727148 constant */
    /* @4727152 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727160 constant */
    /* @4727164 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4727172 constant */
    /* @4727176 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727184 constant */
    /* @4727188 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4727196 constant */
    /* @4727200 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4727208 constant */
    /* @4727212 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4727220 constant */
    /* @4727224 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4727232 constant */
    /* @4727236 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4727244 constant */
    /* @4727248 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4727256 constant */
    /* @4727260 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4727268 constant */
    /* @4727272 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4727280 constant */
    /* @4727284 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4727292 b */
    goto L_4737316;
    L_4727296: ;
    /* @4727296 load */
    /* @4727304 constant */
    /* @4727308 cmp */
    /* @4727312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4727456;
    /* @4727316 load */
    /* @4727324 constant */
    /* @4727328 cmp */
    /* @4727332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4727456;
    /* @4727336 load */
    /* @4727344 constant */
    /* @4727348 cmp */
    /* @4727352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4727456;
    /* @4727356 load */
    /* @4727364 constant */
    /* @4727368 cmp */
    /* @4727372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4727456;
    /* @4727376 load */
    /* @4727384 constant */
    /* @4727388 cmp */
    /* @4727392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4727456;
    /* @4727396 load */
    /* @4727404 constant */
    /* @4727408 cmp */
    /* @4727412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4727456;
    /* @4727416 load */
    /* @4727424 constant */
    /* @4727428 cmp */
    /* @4727432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4727456;
    /* @4727436 load */
    /* @4727444 constant */
    /* @4727448 cmp */
    /* @4727452 b */
    p4727460_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4727460;
    L_4727456: ;
    /* @4727456 constant */
    p4727460_0 = VAL(0);
    L_4727460: ;
    /* @4727460 bf */
    if (!TRUTH(p4727460_0)) goto L_4727624;
    /* @4727464 constant */
    /* @4727468 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4727476 constant */
    /* @4727480 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727488 constant */
    /* @4727492 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4727500 constant */
    /* @4727504 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727512 constant */
    /* @4727516 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4727524 constant */
    /* @4727528 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4727536 constant */
    /* @4727540 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4727548 constant */
    /* @4727552 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4727560 constant */
    /* @4727564 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4727572 constant */
    /* @4727576 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4727584 constant */
    /* @4727588 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4727596 constant */
    /* @4727600 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4727608 constant */
    /* @4727612 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4727620 b */
    goto L_4737316;
    L_4727624: ;
    /* @4727624 load */
    /* @4727632 constant */
    /* @4727636 cmp */
    /* @4727640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4727804;
    /* @4727644 load */
    /* @4727652 constant */
    /* @4727656 cmp */
    /* @4727660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4727804;
    /* @4727664 load */
    /* @4727672 constant */
    /* @4727676 cmp */
    /* @4727680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4727804;
    /* @4727684 load */
    /* @4727692 constant */
    /* @4727696 cmp */
    /* @4727700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4727804;
    /* @4727704 load */
    /* @4727712 constant */
    /* @4727716 cmp */
    /* @4727720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4727804;
    /* @4727724 load */
    /* @4727732 constant */
    /* @4727736 cmp */
    /* @4727740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4727804;
    /* @4727744 load */
    /* @4727752 constant */
    /* @4727756 cmp */
    /* @4727760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4727804;
    /* @4727764 load */
    /* @4727772 constant */
    /* @4727776 cmp */
    /* @4727780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4727804;
    /* @4727784 load */
    /* @4727792 constant */
    /* @4727796 cmp */
    /* @4727800 b */
    p4727808_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4727808;
    L_4727804: ;
    /* @4727804 constant */
    p4727808_0 = VAL(0);
    L_4727808: ;
    /* @4727808 bf */
    if (!TRUTH(p4727808_0)) goto L_4727972;
    /* @4727812 constant */
    /* @4727816 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4727824 constant */
    /* @4727828 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727836 constant */
    /* @4727840 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4727848 constant */
    /* @4727852 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4727860 constant */
    /* @4727864 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4727872 constant */
    /* @4727876 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4727884 constant */
    /* @4727888 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4727896 constant */
    /* @4727900 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4727908 constant */
    /* @4727912 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4727920 constant */
    /* @4727924 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4727932 constant */
    /* @4727936 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4727944 constant */
    /* @4727948 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4727956 constant */
    /* @4727960 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4727968 b */
    goto L_4737316;
    L_4727972: ;
    /* @4727972 load */
    /* @4727980 constant */
    /* @4727984 cmp */
    /* @4727988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocket") == VAL(1)))) goto L_4728152;
    /* @4727992 load */
    /* @4728000 constant */
    /* @4728004 cmp */
    /* @4728008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0)))) goto L_4728152;
    /* @4728012 load */
    /* @4728020 constant */
    /* @4728024 cmp */
    /* @4728028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4728152;
    /* @4728032 load */
    /* @4728040 constant */
    /* @4728044 cmp */
    /* @4728048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4728152;
    /* @4728052 load */
    /* @4728060 constant */
    /* @4728064 cmp */
    /* @4728068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4728152;
    /* @4728072 load */
    /* @4728080 constant */
    /* @4728084 cmp */
    /* @4728088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4728152;
    /* @4728092 load */
    /* @4728100 constant */
    /* @4728104 cmp */
    /* @4728108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4728152;
    /* @4728112 load */
    /* @4728120 constant */
    /* @4728124 cmp */
    /* @4728128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4728152;
    /* @4728132 load */
    /* @4728140 constant */
    /* @4728144 cmp */
    /* @4728148 b */
    p4728156_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4728156;
    L_4728152: ;
    /* @4728152 constant */
    p4728156_0 = VAL(0);
    L_4728156: ;
    /* @4728156 bf */
    if (!TRUTH(p4728156_0)) goto L_4728320;
    /* @4728160 constant */
    /* @4728164 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4728172 constant */
    /* @4728176 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728184 constant */
    /* @4728188 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4728196 constant */
    /* @4728200 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728208 constant */
    /* @4728212 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4728220 constant */
    /* @4728224 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4728232 constant */
    /* @4728236 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4728244 constant */
    /* @4728248 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4728256 constant */
    /* @4728260 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4728268 constant */
    /* @4728272 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4728280 constant */
    /* @4728284 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4728292 constant */
    /* @4728296 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4728304 constant */
    /* @4728308 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4728316 b */
    goto L_4737316;
    L_4728320: ;
    /* @4728320 load */
    /* @4728328 constant */
    /* @4728332 cmp */
    /* @4728336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4728360;
    /* @4728340 load */
    /* @4728348 constant */
    /* @4728352 cmp */
    /* @4728356 b */
    p4728364_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1));
    goto L_4728364;
    L_4728360: ;
    /* @4728360 constant */
    p4728364_0 = VAL(0);
    L_4728364: ;
    /* @4728364 bf */
    if (!TRUTH(p4728364_0)) goto L_4728528;
    /* @4728368 constant */
    /* @4728372 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4728380 constant */
    /* @4728384 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4728392 constant */
    /* @4728396 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728404 constant */
    /* @4728408 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4728416 constant */
    /* @4728420 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4728428 constant */
    /* @4728432 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728440 constant */
    /* @4728444 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4728452 constant */
    /* @4728456 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4728464 constant */
    /* @4728468 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4728476 constant */
    /* @4728480 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4728488 constant */
    /* @4728492 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4728500 constant */
    /* @4728504 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4728512 constant */
    /* @4728516 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4728524 b */
    goto L_4737316;
    L_4728528: ;
    /* @4728528 load */
    /* @4728536 constant */
    /* @4728540 cmp */
    /* @4728544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4728588;
    /* @4728548 load */
    /* @4728556 constant */
    /* @4728560 cmp */
    /* @4728564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4728588;
    /* @4728568 load */
    /* @4728576 constant */
    /* @4728580 cmp */
    /* @4728584 b */
    p4728592_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4728592;
    L_4728588: ;
    /* @4728588 constant */
    p4728592_0 = VAL(0);
    L_4728592: ;
    /* @4728592 bf */
    if (!TRUTH(p4728592_0)) goto L_4728756;
    /* @4728596 constant */
    /* @4728600 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4728608 constant */
    /* @4728612 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4728620 constant */
    /* @4728624 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728632 constant */
    /* @4728636 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4728644 constant */
    /* @4728648 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4728656 constant */
    /* @4728660 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728668 constant */
    /* @4728672 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4728680 constant */
    /* @4728684 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4728692 constant */
    /* @4728696 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4728704 constant */
    /* @4728708 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4728716 constant */
    /* @4728720 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4728728 constant */
    /* @4728732 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4728740 constant */
    /* @4728744 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4728752 b */
    goto L_4737316;
    L_4728756: ;
    /* @4728756 load */
    /* @4728764 constant */
    /* @4728768 cmp */
    /* @4728772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4728836;
    /* @4728776 load */
    /* @4728784 constant */
    /* @4728788 cmp */
    /* @4728792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4728836;
    /* @4728796 load */
    /* @4728804 constant */
    /* @4728808 cmp */
    /* @4728812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4728836;
    /* @4728816 load */
    /* @4728824 constant */
    /* @4728828 cmp */
    /* @4728832 b */
    p4728840_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4728840;
    L_4728836: ;
    /* @4728836 constant */
    p4728840_0 = VAL(0);
    L_4728840: ;
    /* @4728840 bf */
    if (!TRUTH(p4728840_0)) goto L_4729004;
    /* @4728844 constant */
    /* @4728848 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4728856 constant */
    /* @4728860 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4728868 constant */
    /* @4728872 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728880 constant */
    /* @4728884 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4728892 constant */
    /* @4728896 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4728904 constant */
    /* @4728908 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4728916 constant */
    /* @4728920 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4728928 constant */
    /* @4728932 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4728940 constant */
    /* @4728944 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4728952 constant */
    /* @4728956 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4728964 constant */
    /* @4728968 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4728976 constant */
    /* @4728980 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4728988 constant */
    /* @4728992 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4729000 b */
    goto L_4737316;
    L_4729004: ;
    /* @4729004 load */
    /* @4729012 constant */
    /* @4729016 cmp */
    /* @4729020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4729104;
    /* @4729024 load */
    /* @4729032 constant */
    /* @4729036 cmp */
    /* @4729040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4729104;
    /* @4729044 load */
    /* @4729052 constant */
    /* @4729056 cmp */
    /* @4729060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4729104;
    /* @4729064 load */
    /* @4729072 constant */
    /* @4729076 cmp */
    /* @4729080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4729104;
    /* @4729084 load */
    /* @4729092 constant */
    /* @4729096 cmp */
    /* @4729100 b */
    p4729108_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4729108;
    L_4729104: ;
    /* @4729104 constant */
    p4729108_0 = VAL(0);
    L_4729108: ;
    /* @4729108 bf */
    if (!TRUTH(p4729108_0)) goto L_4729272;
    /* @4729112 constant */
    /* @4729116 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4729124 constant */
    /* @4729128 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4729136 constant */
    /* @4729140 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729148 constant */
    /* @4729152 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4729160 constant */
    /* @4729164 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4729172 constant */
    /* @4729176 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729184 constant */
    /* @4729188 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4729196 constant */
    /* @4729200 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4729208 constant */
    /* @4729212 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4729220 constant */
    /* @4729224 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4729232 constant */
    /* @4729236 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4729244 constant */
    /* @4729248 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4729256 constant */
    /* @4729260 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4729268 b */
    goto L_4737316;
    L_4729272: ;
    /* @4729272 load */
    /* @4729280 constant */
    /* @4729284 cmp */
    /* @4729288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4729392;
    /* @4729292 load */
    /* @4729300 constant */
    /* @4729304 cmp */
    /* @4729308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4729392;
    /* @4729312 load */
    /* @4729320 constant */
    /* @4729324 cmp */
    /* @4729328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4729392;
    /* @4729332 load */
    /* @4729340 constant */
    /* @4729344 cmp */
    /* @4729348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4729392;
    /* @4729352 load */
    /* @4729360 constant */
    /* @4729364 cmp */
    /* @4729368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4729392;
    /* @4729372 load */
    /* @4729380 constant */
    /* @4729384 cmp */
    /* @4729388 b */
    p4729396_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4729396;
    L_4729392: ;
    /* @4729392 constant */
    p4729396_0 = VAL(0);
    L_4729396: ;
    /* @4729396 bf */
    if (!TRUTH(p4729396_0)) goto L_4729560;
    /* @4729400 constant */
    /* @4729404 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4729412 constant */
    /* @4729416 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729424 constant */
    /* @4729428 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4729436 constant */
    /* @4729440 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729448 constant */
    /* @4729452 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4729460 constant */
    /* @4729464 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4729472 constant */
    /* @4729476 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4729484 constant */
    /* @4729488 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4729496 constant */
    /* @4729500 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4729508 constant */
    /* @4729512 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4729520 constant */
    /* @4729524 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4729532 constant */
    /* @4729536 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4729544 constant */
    /* @4729548 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4729556 b */
    goto L_4737316;
    L_4729560: ;
    /* @4729560 load */
    /* @4729568 constant */
    /* @4729572 cmp */
    /* @4729576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4729700;
    /* @4729580 load */
    /* @4729588 constant */
    /* @4729592 cmp */
    /* @4729596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4729700;
    /* @4729600 load */
    /* @4729608 constant */
    /* @4729612 cmp */
    /* @4729616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4729700;
    /* @4729620 load */
    /* @4729628 constant */
    /* @4729632 cmp */
    /* @4729636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4729700;
    /* @4729640 load */
    /* @4729648 constant */
    /* @4729652 cmp */
    /* @4729656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4729700;
    /* @4729660 load */
    /* @4729668 constant */
    /* @4729672 cmp */
    /* @4729676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4729700;
    /* @4729680 load */
    /* @4729688 constant */
    /* @4729692 cmp */
    /* @4729696 b */
    p4729704_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4729704;
    L_4729700: ;
    /* @4729700 constant */
    p4729704_0 = VAL(0);
    L_4729704: ;
    /* @4729704 bf */
    if (!TRUTH(p4729704_0)) goto L_4729868;
    /* @4729708 constant */
    /* @4729712 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4729720 constant */
    /* @4729724 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729732 constant */
    /* @4729736 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4729744 constant */
    /* @4729748 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4729756 constant */
    /* @4729760 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4729768 constant */
    /* @4729772 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4729780 constant */
    /* @4729784 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4729792 constant */
    /* @4729796 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4729804 constant */
    /* @4729808 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4729816 constant */
    /* @4729820 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4729828 constant */
    /* @4729832 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4729840 constant */
    /* @4729844 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4729852 constant */
    /* @4729856 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4729864 b */
    goto L_4737316;
    L_4729868: ;
    /* @4729868 load */
    /* @4729876 constant */
    /* @4729880 cmp */
    /* @4729884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4730028;
    /* @4729888 load */
    /* @4729896 constant */
    /* @4729900 cmp */
    /* @4729904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4730028;
    /* @4729908 load */
    /* @4729916 constant */
    /* @4729920 cmp */
    /* @4729924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4730028;
    /* @4729928 load */
    /* @4729936 constant */
    /* @4729940 cmp */
    /* @4729944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4730028;
    /* @4729948 load */
    /* @4729956 constant */
    /* @4729960 cmp */
    /* @4729964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4730028;
    /* @4729968 load */
    /* @4729976 constant */
    /* @4729980 cmp */
    /* @4729984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4730028;
    /* @4729988 load */
    /* @4729996 constant */
    /* @4730000 cmp */
    /* @4730004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4730028;
    /* @4730008 load */
    /* @4730016 constant */
    /* @4730020 cmp */
    /* @4730024 b */
    p4730032_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4730032;
    L_4730028: ;
    /* @4730028 constant */
    p4730032_0 = VAL(0);
    L_4730032: ;
    /* @4730032 bf */
    if (!TRUTH(p4730032_0)) goto L_4730196;
    /* @4730036 constant */
    /* @4730040 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4730048 constant */
    /* @4730052 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730060 constant */
    /* @4730064 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4730072 constant */
    /* @4730076 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730084 constant */
    /* @4730088 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4730096 constant */
    /* @4730100 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4730108 constant */
    /* @4730112 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4730120 constant */
    /* @4730124 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4730132 constant */
    /* @4730136 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4730144 constant */
    /* @4730148 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4730156 constant */
    /* @4730160 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4730168 constant */
    /* @4730172 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4730180 constant */
    /* @4730184 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4730192 b */
    goto L_4737316;
    L_4730196: ;
    /* @4730196 load */
    /* @4730204 constant */
    /* @4730208 cmp */
    /* @4730212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegun") == VAL(1)))) goto L_4730356;
    /* @4730216 load */
    /* @4730224 constant */
    /* @4730228 cmp */
    /* @4730232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0)))) goto L_4730356;
    /* @4730236 load */
    /* @4730244 constant */
    /* @4730248 cmp */
    /* @4730252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4730356;
    /* @4730256 load */
    /* @4730264 constant */
    /* @4730268 cmp */
    /* @4730272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4730356;
    /* @4730276 load */
    /* @4730284 constant */
    /* @4730288 cmp */
    /* @4730292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4730356;
    /* @4730296 load */
    /* @4730304 constant */
    /* @4730308 cmp */
    /* @4730312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4730356;
    /* @4730316 load */
    /* @4730324 constant */
    /* @4730328 cmp */
    /* @4730332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4730356;
    /* @4730336 load */
    /* @4730344 constant */
    /* @4730348 cmp */
    /* @4730352 b */
    p4730360_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4730360;
    L_4730356: ;
    /* @4730356 constant */
    p4730360_0 = VAL(0);
    L_4730360: ;
    /* @4730360 bf */
    if (!TRUTH(p4730360_0)) goto L_4730524;
    /* @4730364 constant */
    /* @4730368 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4730376 constant */
    /* @4730380 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730388 constant */
    /* @4730392 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4730400 constant */
    /* @4730404 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730412 constant */
    /* @4730416 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4730424 constant */
    /* @4730428 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4730436 constant */
    /* @4730440 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4730448 constant */
    /* @4730452 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4730460 constant */
    /* @4730464 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4730472 constant */
    /* @4730476 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4730484 constant */
    /* @4730488 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4730496 constant */
    /* @4730500 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4730508 constant */
    /* @4730512 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4730520 b */
    goto L_4737316;
    L_4730524: ;
    /* @4730524 load */
    /* @4730532 constant */
    /* @4730536 cmp */
    /* @4730540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4730564;
    /* @4730544 load */
    /* @4730552 constant */
    /* @4730556 cmp */
    /* @4730560 b */
    p4730568_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1));
    goto L_4730568;
    L_4730564: ;
    /* @4730564 constant */
    p4730568_0 = VAL(0);
    L_4730568: ;
    /* @4730568 bf */
    if (!TRUTH(p4730568_0)) goto L_4730732;
    /* @4730572 constant */
    /* @4730576 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4730584 constant */
    /* @4730588 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4730596 constant */
    /* @4730600 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730608 constant */
    /* @4730612 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4730620 constant */
    /* @4730624 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4730632 constant */
    /* @4730636 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730644 constant */
    /* @4730648 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4730656 constant */
    /* @4730660 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4730668 constant */
    /* @4730672 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4730680 constant */
    /* @4730684 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4730692 constant */
    /* @4730696 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4730704 constant */
    /* @4730708 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4730716 constant */
    /* @4730720 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4730728 b */
    goto L_4737316;
    L_4730732: ;
    /* @4730732 load */
    /* @4730740 constant */
    /* @4730744 cmp */
    /* @4730748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4730792;
    /* @4730752 load */
    /* @4730760 constant */
    /* @4730764 cmp */
    /* @4730768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4730792;
    /* @4730772 load */
    /* @4730780 constant */
    /* @4730784 cmp */
    /* @4730788 b */
    p4730796_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4730796;
    L_4730792: ;
    /* @4730792 constant */
    p4730796_0 = VAL(0);
    L_4730796: ;
    /* @4730796 bf */
    if (!TRUTH(p4730796_0)) goto L_4730960;
    /* @4730800 constant */
    /* @4730804 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4730812 constant */
    /* @4730816 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4730824 constant */
    /* @4730828 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730836 constant */
    /* @4730840 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4730848 constant */
    /* @4730852 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4730860 constant */
    /* @4730864 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4730872 constant */
    /* @4730876 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4730884 constant */
    /* @4730888 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4730896 constant */
    /* @4730900 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4730908 constant */
    /* @4730912 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4730920 constant */
    /* @4730924 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4730932 constant */
    /* @4730936 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4730944 constant */
    /* @4730948 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4730956 b */
    goto L_4737316;
    L_4730960: ;
    /* @4730960 load */
    /* @4730968 constant */
    /* @4730972 cmp */
    /* @4730976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4731040;
    /* @4730980 load */
    /* @4730988 constant */
    /* @4730992 cmp */
    /* @4730996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4731040;
    /* @4731000 load */
    /* @4731008 constant */
    /* @4731012 cmp */
    /* @4731016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4731040;
    /* @4731020 load */
    /* @4731028 constant */
    /* @4731032 cmp */
    /* @4731036 b */
    p4731044_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4731044;
    L_4731040: ;
    /* @4731040 constant */
    p4731044_0 = VAL(0);
    L_4731044: ;
    /* @4731044 bf */
    if (!TRUTH(p4731044_0)) goto L_4731208;
    /* @4731048 constant */
    /* @4731052 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4731060 constant */
    /* @4731064 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4731072 constant */
    /* @4731076 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731084 constant */
    /* @4731088 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4731096 constant */
    /* @4731100 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4731108 constant */
    /* @4731112 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731120 constant */
    /* @4731124 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4731132 constant */
    /* @4731136 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4731144 constant */
    /* @4731148 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4731156 constant */
    /* @4731160 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4731168 constant */
    /* @4731172 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4731180 constant */
    /* @4731184 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4731192 constant */
    /* @4731196 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4731204 b */
    goto L_4737316;
    L_4731208: ;
    /* @4731208 load */
    /* @4731216 constant */
    /* @4731220 cmp */
    /* @4731224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4731308;
    /* @4731228 load */
    /* @4731236 constant */
    /* @4731240 cmp */
    /* @4731244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4731308;
    /* @4731248 load */
    /* @4731256 constant */
    /* @4731260 cmp */
    /* @4731264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4731308;
    /* @4731268 load */
    /* @4731276 constant */
    /* @4731280 cmp */
    /* @4731284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4731308;
    /* @4731288 load */
    /* @4731296 constant */
    /* @4731300 cmp */
    /* @4731304 b */
    p4731312_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4731312;
    L_4731308: ;
    /* @4731308 constant */
    p4731312_0 = VAL(0);
    L_4731312: ;
    /* @4731312 bf */
    if (!TRUTH(p4731312_0)) goto L_4731476;
    /* @4731316 constant */
    /* @4731320 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4731328 constant */
    /* @4731332 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731340 constant */
    /* @4731344 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4731352 constant */
    /* @4731356 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731364 constant */
    /* @4731368 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4731376 constant */
    /* @4731380 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4731388 constant */
    /* @4731392 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4731400 constant */
    /* @4731404 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4731412 constant */
    /* @4731416 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4731424 constant */
    /* @4731428 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4731436 constant */
    /* @4731440 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4731448 constant */
    /* @4731452 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4731460 constant */
    /* @4731464 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4731472 b */
    goto L_4737316;
    L_4731476: ;
    /* @4731476 load */
    /* @4731484 constant */
    /* @4731488 cmp */
    /* @4731492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4731596;
    /* @4731496 load */
    /* @4731504 constant */
    /* @4731508 cmp */
    /* @4731512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4731596;
    /* @4731516 load */
    /* @4731524 constant */
    /* @4731528 cmp */
    /* @4731532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4731596;
    /* @4731536 load */
    /* @4731544 constant */
    /* @4731548 cmp */
    /* @4731552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4731596;
    /* @4731556 load */
    /* @4731564 constant */
    /* @4731568 cmp */
    /* @4731572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4731596;
    /* @4731576 load */
    /* @4731584 constant */
    /* @4731588 cmp */
    /* @4731592 b */
    p4731600_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4731600;
    L_4731596: ;
    /* @4731596 constant */
    p4731600_0 = VAL(0);
    L_4731600: ;
    /* @4731600 bf */
    if (!TRUTH(p4731600_0)) goto L_4731764;
    /* @4731604 constant */
    /* @4731608 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4731616 constant */
    /* @4731620 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731628 constant */
    /* @4731632 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4731640 constant */
    /* @4731644 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731652 constant */
    /* @4731656 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4731664 constant */
    /* @4731668 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4731676 constant */
    /* @4731680 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4731688 constant */
    /* @4731692 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4731700 constant */
    /* @4731704 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4731712 constant */
    /* @4731716 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4731724 constant */
    /* @4731728 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4731736 constant */
    /* @4731740 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4731748 constant */
    /* @4731752 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4731760 b */
    goto L_4737316;
    L_4731764: ;
    /* @4731764 load */
    /* @4731772 constant */
    /* @4731776 cmp */
    /* @4731780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4731904;
    /* @4731784 load */
    /* @4731792 constant */
    /* @4731796 cmp */
    /* @4731800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4731904;
    /* @4731804 load */
    /* @4731812 constant */
    /* @4731816 cmp */
    /* @4731820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4731904;
    /* @4731824 load */
    /* @4731832 constant */
    /* @4731836 cmp */
    /* @4731840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4731904;
    /* @4731844 load */
    /* @4731852 constant */
    /* @4731856 cmp */
    /* @4731860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4731904;
    /* @4731864 load */
    /* @4731872 constant */
    /* @4731876 cmp */
    /* @4731880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4731904;
    /* @4731884 load */
    /* @4731892 constant */
    /* @4731896 cmp */
    /* @4731900 b */
    p4731908_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4731908;
    L_4731904: ;
    /* @4731904 constant */
    p4731908_0 = VAL(0);
    L_4731908: ;
    /* @4731908 bf */
    if (!TRUTH(p4731908_0)) goto L_4732072;
    /* @4731912 constant */
    /* @4731916 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4731924 constant */
    /* @4731928 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731936 constant */
    /* @4731940 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4731948 constant */
    /* @4731952 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4731960 constant */
    /* @4731964 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4731972 constant */
    /* @4731976 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4731984 constant */
    /* @4731988 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4731996 constant */
    /* @4732000 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4732008 constant */
    /* @4732012 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4732020 constant */
    /* @4732024 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4732032 constant */
    /* @4732036 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4732044 constant */
    /* @4732048 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4732056 constant */
    /* @4732060 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4732068 b */
    goto L_4737316;
    L_4732072: ;
    /* @4732072 load */
    /* @4732080 constant */
    /* @4732084 cmp */
    /* @4732088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4732212;
    /* @4732092 load */
    /* @4732100 constant */
    /* @4732104 cmp */
    /* @4732108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0)))) goto L_4732212;
    /* @4732112 load */
    /* @4732120 constant */
    /* @4732124 cmp */
    /* @4732128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4732212;
    /* @4732132 load */
    /* @4732140 constant */
    /* @4732144 cmp */
    /* @4732148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4732212;
    /* @4732152 load */
    /* @4732160 constant */
    /* @4732164 cmp */
    /* @4732168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4732212;
    /* @4732172 load */
    /* @4732180 constant */
    /* @4732184 cmp */
    /* @4732188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4732212;
    /* @4732192 load */
    /* @4732200 constant */
    /* @4732204 cmp */
    /* @4732208 b */
    p4732216_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4732216;
    L_4732212: ;
    /* @4732212 constant */
    p4732216_0 = VAL(0);
    L_4732216: ;
    /* @4732216 bf */
    if (!TRUTH(p4732216_0)) goto L_4732380;
    /* @4732220 constant */
    /* @4732224 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4732232 constant */
    /* @4732236 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732244 constant */
    /* @4732248 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4732256 constant */
    /* @4732260 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732268 constant */
    /* @4732272 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4732280 constant */
    /* @4732284 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4732292 constant */
    /* @4732296 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4732304 constant */
    /* @4732308 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4732316 constant */
    /* @4732320 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4732328 constant */
    /* @4732332 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4732340 constant */
    /* @4732344 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4732352 constant */
    /* @4732356 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4732364 constant */
    /* @4732368 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4732376 b */
    goto L_4737316;
    L_4732380: ;
    /* @4732380 load */
    /* @4732388 constant */
    /* @4732392 cmp */
    /* @4732396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4732420;
    /* @4732400 load */
    /* @4732408 constant */
    /* @4732412 cmp */
    /* @4732416 b */
    p4732424_0 = NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1));
    goto L_4732424;
    L_4732420: ;
    /* @4732420 constant */
    p4732424_0 = VAL(0);
    L_4732424: ;
    /* @4732424 bf */
    if (!TRUTH(p4732424_0)) goto L_4732588;
    /* @4732428 constant */
    /* @4732432 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4732440 constant */
    /* @4732444 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732452 constant */
    /* @4732456 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4732464 constant */
    /* @4732468 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732476 constant */
    /* @4732480 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4732488 constant */
    /* @4732492 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4732500 constant */
    /* @4732504 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4732512 constant */
    /* @4732516 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4732524 constant */
    /* @4732528 store */
    GM_WRITE(vm, -5, "bladegun", VAL(1));
    /* @4732536 constant */
    /* @4732540 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4732548 constant */
    /* @4732552 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4732560 constant */
    /* @4732564 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4732572 constant */
    /* @4732576 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4732584 b */
    goto L_4737316;
    L_4732588: ;
    /* @4732588 load */
    /* @4732596 constant */
    /* @4732600 cmp */
    /* @4732604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4732648;
    /* @4732608 load */
    /* @4732616 constant */
    /* @4732620 cmp */
    /* @4732624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4732648;
    /* @4732628 load */
    /* @4732636 constant */
    /* @4732640 cmp */
    /* @4732644 b */
    p4732652_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4732652;
    L_4732648: ;
    /* @4732648 constant */
    p4732652_0 = VAL(0);
    L_4732652: ;
    /* @4732652 bf */
    if (!TRUTH(p4732652_0)) goto L_4732816;
    /* @4732656 constant */
    /* @4732660 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4732668 constant */
    /* @4732672 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732680 constant */
    /* @4732684 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4732692 constant */
    /* @4732696 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732704 constant */
    /* @4732708 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4732716 constant */
    /* @4732720 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4732728 constant */
    /* @4732732 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4732740 constant */
    /* @4732744 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4732752 constant */
    /* @4732756 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4732764 constant */
    /* @4732768 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4732776 constant */
    /* @4732780 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4732788 constant */
    /* @4732792 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4732800 constant */
    /* @4732804 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4732812 b */
    goto L_4737316;
    L_4732816: ;
    /* @4732816 load */
    /* @4732824 constant */
    /* @4732828 cmp */
    /* @4732832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4732896;
    /* @4732836 load */
    /* @4732844 constant */
    /* @4732848 cmp */
    /* @4732852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4732896;
    /* @4732856 load */
    /* @4732864 constant */
    /* @4732868 cmp */
    /* @4732872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4732896;
    /* @4732876 load */
    /* @4732884 constant */
    /* @4732888 cmp */
    /* @4732892 b */
    p4732900_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4732900;
    L_4732896: ;
    /* @4732896 constant */
    p4732900_0 = VAL(0);
    L_4732900: ;
    /* @4732900 bf */
    if (!TRUTH(p4732900_0)) goto L_4733064;
    /* @4732904 constant */
    /* @4732908 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4732916 constant */
    /* @4732920 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732928 constant */
    /* @4732932 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4732940 constant */
    /* @4732944 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4732952 constant */
    /* @4732956 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4732964 constant */
    /* @4732968 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4732976 constant */
    /* @4732980 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4732988 constant */
    /* @4732992 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4733000 constant */
    /* @4733004 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4733012 constant */
    /* @4733016 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4733024 constant */
    /* @4733028 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4733036 constant */
    /* @4733040 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4733048 constant */
    /* @4733052 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4733060 b */
    goto L_4737316;
    L_4733064: ;
    /* @4733064 load */
    /* @4733072 constant */
    /* @4733076 cmp */
    /* @4733080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4733164;
    /* @4733084 load */
    /* @4733092 constant */
    /* @4733096 cmp */
    /* @4733100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4733164;
    /* @4733104 load */
    /* @4733112 constant */
    /* @4733116 cmp */
    /* @4733120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4733164;
    /* @4733124 load */
    /* @4733132 constant */
    /* @4733136 cmp */
    /* @4733140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4733164;
    /* @4733144 load */
    /* @4733152 constant */
    /* @4733156 cmp */
    /* @4733160 b */
    p4733168_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4733168;
    L_4733164: ;
    /* @4733164 constant */
    p4733168_0 = VAL(0);
    L_4733168: ;
    /* @4733168 bf */
    if (!TRUTH(p4733168_0)) goto L_4733332;
    /* @4733172 constant */
    /* @4733176 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4733184 constant */
    /* @4733188 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733196 constant */
    /* @4733200 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4733208 constant */
    /* @4733212 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733220 constant */
    /* @4733224 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4733232 constant */
    /* @4733236 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4733244 constant */
    /* @4733248 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4733256 constant */
    /* @4733260 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4733268 constant */
    /* @4733272 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4733280 constant */
    /* @4733284 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4733292 constant */
    /* @4733296 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4733304 constant */
    /* @4733308 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4733316 constant */
    /* @4733320 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4733328 b */
    goto L_4737316;
    L_4733332: ;
    /* @4733332 load */
    /* @4733340 constant */
    /* @4733344 cmp */
    /* @4733348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4733452;
    /* @4733352 load */
    /* @4733360 constant */
    /* @4733364 cmp */
    /* @4733368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4733452;
    /* @4733372 load */
    /* @4733380 constant */
    /* @4733384 cmp */
    /* @4733388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4733452;
    /* @4733392 load */
    /* @4733400 constant */
    /* @4733404 cmp */
    /* @4733408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4733452;
    /* @4733412 load */
    /* @4733420 constant */
    /* @4733424 cmp */
    /* @4733428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4733452;
    /* @4733432 load */
    /* @4733440 constant */
    /* @4733444 cmp */
    /* @4733448 b */
    p4733456_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4733456;
    L_4733452: ;
    /* @4733452 constant */
    p4733456_0 = VAL(0);
    L_4733456: ;
    /* @4733456 bf */
    if (!TRUTH(p4733456_0)) goto L_4733620;
    /* @4733460 constant */
    /* @4733464 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4733472 constant */
    /* @4733476 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733484 constant */
    /* @4733488 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4733496 constant */
    /* @4733500 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733508 constant */
    /* @4733512 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4733520 constant */
    /* @4733524 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4733532 constant */
    /* @4733536 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4733544 constant */
    /* @4733548 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4733556 constant */
    /* @4733560 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4733568 constant */
    /* @4733572 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4733580 constant */
    /* @4733584 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4733592 constant */
    /* @4733596 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4733604 constant */
    /* @4733608 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4733616 b */
    goto L_4737316;
    L_4733620: ;
    /* @4733620 load */
    /* @4733628 constant */
    /* @4733632 cmp */
    /* @4733636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bow") == VAL(1)))) goto L_4733740;
    /* @4733640 load */
    /* @4733648 constant */
    /* @4733652 cmp */
    /* @4733656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(0)))) goto L_4733740;
    /* @4733660 load */
    /* @4733668 constant */
    /* @4733672 cmp */
    /* @4733676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4733740;
    /* @4733680 load */
    /* @4733688 constant */
    /* @4733692 cmp */
    /* @4733696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4733740;
    /* @4733700 load */
    /* @4733708 constant */
    /* @4733712 cmp */
    /* @4733716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4733740;
    /* @4733720 load */
    /* @4733728 constant */
    /* @4733732 cmp */
    /* @4733736 b */
    p4733744_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4733744;
    L_4733740: ;
    /* @4733740 constant */
    p4733744_0 = VAL(0);
    L_4733744: ;
    /* @4733744 bf */
    if (!TRUTH(p4733744_0)) goto L_4733908;
    /* @4733748 constant */
    /* @4733752 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4733760 constant */
    /* @4733764 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733772 constant */
    /* @4733776 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4733784 constant */
    /* @4733788 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733796 constant */
    /* @4733800 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4733808 constant */
    /* @4733812 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4733820 constant */
    /* @4733824 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4733832 constant */
    /* @4733836 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4733844 constant */
    /* @4733848 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4733856 constant */
    /* @4733860 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4733868 constant */
    /* @4733872 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4733880 constant */
    /* @4733884 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4733892 constant */
    /* @4733896 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4733904 b */
    goto L_4737316;
    L_4733908: ;
    /* @4733908 load */
    /* @4733916 constant */
    /* @4733920 cmp */
    /* @4733924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4733948;
    /* @4733928 load */
    /* @4733936 constant */
    /* @4733940 cmp */
    /* @4733944 b */
    p4733952_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1));
    goto L_4733952;
    L_4733948: ;
    /* @4733948 constant */
    p4733952_0 = VAL(0);
    L_4733952: ;
    /* @4733952 bf */
    if (!TRUTH(p4733952_0)) goto L_4734116;
    /* @4733956 constant */
    /* @4733960 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4733968 constant */
    /* @4733972 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4733980 constant */
    /* @4733984 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4733992 constant */
    /* @4733996 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734004 constant */
    /* @4734008 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4734016 constant */
    /* @4734020 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4734028 constant */
    /* @4734032 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4734040 constant */
    /* @4734044 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4734052 constant */
    /* @4734056 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4734064 constant */
    /* @4734068 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4734076 constant */
    /* @4734080 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4734088 constant */
    /* @4734092 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4734100 constant */
    /* @4734104 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4734112 b */
    goto L_4737316;
    L_4734116: ;
    /* @4734116 load */
    /* @4734124 constant */
    /* @4734128 cmp */
    /* @4734132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4734176;
    /* @4734136 load */
    /* @4734144 constant */
    /* @4734148 cmp */
    /* @4734152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4734176;
    /* @4734156 load */
    /* @4734164 constant */
    /* @4734168 cmp */
    /* @4734172 b */
    p4734180_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4734180;
    L_4734176: ;
    /* @4734176 constant */
    p4734180_0 = VAL(0);
    L_4734180: ;
    /* @4734180 bf */
    if (!TRUTH(p4734180_0)) goto L_4734344;
    /* @4734184 constant */
    /* @4734188 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4734196 constant */
    /* @4734200 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734208 constant */
    /* @4734212 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4734220 constant */
    /* @4734224 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734232 constant */
    /* @4734236 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4734244 constant */
    /* @4734248 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4734256 constant */
    /* @4734260 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4734268 constant */
    /* @4734272 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4734280 constant */
    /* @4734284 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4734292 constant */
    /* @4734296 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4734304 constant */
    /* @4734308 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4734316 constant */
    /* @4734320 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4734328 constant */
    /* @4734332 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4734340 b */
    goto L_4737316;
    L_4734344: ;
    /* @4734344 load */
    /* @4734352 constant */
    /* @4734356 cmp */
    /* @4734360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4734424;
    /* @4734364 load */
    /* @4734372 constant */
    /* @4734376 cmp */
    /* @4734380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4734424;
    /* @4734384 load */
    /* @4734392 constant */
    /* @4734396 cmp */
    /* @4734400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4734424;
    /* @4734404 load */
    /* @4734412 constant */
    /* @4734416 cmp */
    /* @4734420 b */
    p4734428_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4734428;
    L_4734424: ;
    /* @4734424 constant */
    p4734428_0 = VAL(0);
    L_4734428: ;
    /* @4734428 bf */
    if (!TRUTH(p4734428_0)) goto L_4734592;
    /* @4734432 constant */
    /* @4734436 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4734444 constant */
    /* @4734448 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734456 constant */
    /* @4734460 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4734468 constant */
    /* @4734472 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734480 constant */
    /* @4734484 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4734492 constant */
    /* @4734496 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4734504 constant */
    /* @4734508 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4734516 constant */
    /* @4734520 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4734528 constant */
    /* @4734532 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4734540 constant */
    /* @4734544 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4734552 constant */
    /* @4734556 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4734564 constant */
    /* @4734568 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4734576 constant */
    /* @4734580 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4734588 b */
    goto L_4737316;
    L_4734592: ;
    /* @4734592 load */
    /* @4734600 constant */
    /* @4734604 cmp */
    /* @4734608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4734692;
    /* @4734612 load */
    /* @4734620 constant */
    /* @4734624 cmp */
    /* @4734628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4734692;
    /* @4734632 load */
    /* @4734640 constant */
    /* @4734644 cmp */
    /* @4734648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4734692;
    /* @4734652 load */
    /* @4734660 constant */
    /* @4734664 cmp */
    /* @4734668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4734692;
    /* @4734672 load */
    /* @4734680 constant */
    /* @4734684 cmp */
    /* @4734688 b */
    p4734696_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4734696;
    L_4734692: ;
    /* @4734692 constant */
    p4734696_0 = VAL(0);
    L_4734696: ;
    /* @4734696 bf */
    if (!TRUTH(p4734696_0)) goto L_4734860;
    /* @4734700 constant */
    /* @4734704 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4734712 constant */
    /* @4734716 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734724 constant */
    /* @4734728 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4734736 constant */
    /* @4734740 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734748 constant */
    /* @4734752 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4734760 constant */
    /* @4734764 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4734772 constant */
    /* @4734776 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4734784 constant */
    /* @4734788 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4734796 constant */
    /* @4734800 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4734808 constant */
    /* @4734812 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4734820 constant */
    /* @4734824 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4734832 constant */
    /* @4734836 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4734844 constant */
    /* @4734848 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4734856 b */
    goto L_4737316;
    L_4734860: ;
    /* @4734860 load */
    /* @4734868 constant */
    /* @4734872 cmp */
    /* @4734876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegun") == VAL(1)))) goto L_4734960;
    /* @4734880 load */
    /* @4734888 constant */
    /* @4734892 cmp */
    /* @4734896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0)))) goto L_4734960;
    /* @4734900 load */
    /* @4734908 constant */
    /* @4734912 cmp */
    /* @4734916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4734960;
    /* @4734920 load */
    /* @4734928 constant */
    /* @4734932 cmp */
    /* @4734936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4734960;
    /* @4734940 load */
    /* @4734948 constant */
    /* @4734952 cmp */
    /* @4734956 b */
    p4734964_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4734964;
    L_4734960: ;
    /* @4734960 constant */
    p4734964_0 = VAL(0);
    L_4734964: ;
    /* @4734964 bf */
    if (!TRUTH(p4734964_0)) goto L_4735128;
    /* @4734968 constant */
    /* @4734972 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4734980 constant */
    /* @4734984 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4734992 constant */
    /* @4734996 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4735004 constant */
    /* @4735008 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735016 constant */
    /* @4735020 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4735028 constant */
    /* @4735032 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4735040 constant */
    /* @4735044 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4735052 constant */
    /* @4735056 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4735064 constant */
    /* @4735068 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4735076 constant */
    /* @4735080 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4735088 constant */
    /* @4735092 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4735100 constant */
    /* @4735104 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4735112 constant */
    /* @4735116 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4735124 b */
    goto L_4737316;
    L_4735128: ;
    /* @4735128 load */
    /* @4735136 constant */
    /* @4735140 cmp */
    /* @4735144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_4735168;
    /* @4735148 load */
    /* @4735156 constant */
    /* @4735160 cmp */
    /* @4735164 b */
    p4735172_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1));
    goto L_4735172;
    L_4735168: ;
    /* @4735168 constant */
    p4735172_0 = VAL(0);
    L_4735172: ;
    /* @4735172 bf */
    if (!TRUTH(p4735172_0)) goto L_4735336;
    /* @4735176 constant */
    /* @4735180 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4735188 constant */
    /* @4735192 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735200 constant */
    /* @4735204 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4735212 constant */
    /* @4735216 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735224 constant */
    /* @4735228 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4735236 constant */
    /* @4735240 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4735248 constant */
    /* @4735252 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4735260 constant */
    /* @4735264 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4735272 constant */
    /* @4735276 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4735284 constant */
    /* @4735288 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4735296 constant */
    /* @4735300 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4735308 constant */
    /* @4735312 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4735320 constant */
    /* @4735324 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4735332 b */
    goto L_4737316;
    L_4735336: ;
    /* @4735336 load */
    /* @4735344 constant */
    /* @4735348 cmp */
    /* @4735352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_4735396;
    /* @4735356 load */
    /* @4735364 constant */
    /* @4735368 cmp */
    /* @4735372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4735396;
    /* @4735376 load */
    /* @4735384 constant */
    /* @4735388 cmp */
    /* @4735392 b */
    p4735400_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4735400;
    L_4735396: ;
    /* @4735396 constant */
    p4735400_0 = VAL(0);
    L_4735400: ;
    /* @4735400 bf */
    if (!TRUTH(p4735400_0)) goto L_4735564;
    /* @4735404 constant */
    /* @4735408 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4735416 constant */
    /* @4735420 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735428 constant */
    /* @4735432 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4735440 constant */
    /* @4735444 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735452 constant */
    /* @4735456 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4735464 constant */
    /* @4735468 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4735476 constant */
    /* @4735480 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4735488 constant */
    /* @4735492 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4735500 constant */
    /* @4735504 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4735512 constant */
    /* @4735516 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4735524 constant */
    /* @4735528 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4735536 constant */
    /* @4735540 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4735548 constant */
    /* @4735552 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4735560 b */
    goto L_4737316;
    L_4735564: ;
    /* @4735564 load */
    /* @4735572 constant */
    /* @4735576 cmp */
    /* @4735580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_4735644;
    /* @4735584 load */
    /* @4735592 constant */
    /* @4735596 cmp */
    /* @4735600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4735644;
    /* @4735604 load */
    /* @4735612 constant */
    /* @4735616 cmp */
    /* @4735620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4735644;
    /* @4735624 load */
    /* @4735632 constant */
    /* @4735636 cmp */
    /* @4735640 b */
    p4735648_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4735648;
    L_4735644: ;
    /* @4735644 constant */
    p4735648_0 = VAL(0);
    L_4735648: ;
    /* @4735648 bf */
    if (!TRUTH(p4735648_0)) goto L_4735812;
    /* @4735652 constant */
    /* @4735656 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4735664 constant */
    /* @4735668 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735676 constant */
    /* @4735680 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4735688 constant */
    /* @4735692 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735700 constant */
    /* @4735704 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4735712 constant */
    /* @4735716 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4735724 constant */
    /* @4735728 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4735736 constant */
    /* @4735740 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4735748 constant */
    /* @4735752 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4735760 constant */
    /* @4735764 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4735772 constant */
    /* @4735776 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4735784 constant */
    /* @4735788 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4735796 constant */
    /* @4735800 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4735808 b */
    goto L_4737316;
    L_4735812: ;
    /* @4735812 load */
    /* @4735820 constant */
    /* @4735824 cmp */
    /* @4735828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrower") == VAL(1)))) goto L_4735892;
    /* @4735832 load */
    /* @4735840 constant */
    /* @4735844 cmp */
    /* @4735848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0)))) goto L_4735892;
    /* @4735852 load */
    /* @4735860 constant */
    /* @4735864 cmp */
    /* @4735868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4735892;
    /* @4735872 load */
    /* @4735880 constant */
    /* @4735884 cmp */
    /* @4735888 b */
    p4735896_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4735896;
    L_4735892: ;
    /* @4735892 constant */
    p4735896_0 = VAL(0);
    L_4735896: ;
    /* @4735896 bf */
    if (!TRUTH(p4735896_0)) goto L_4736060;
    /* @4735900 constant */
    /* @4735904 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4735912 constant */
    /* @4735916 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735924 constant */
    /* @4735928 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4735936 constant */
    /* @4735940 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4735948 constant */
    /* @4735952 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4735960 constant */
    /* @4735964 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4735972 constant */
    /* @4735976 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4735984 constant */
    /* @4735988 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4735996 constant */
    /* @4736000 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4736008 constant */
    /* @4736012 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4736020 constant */
    /* @4736024 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4736032 constant */
    /* @4736036 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4736044 constant */
    /* @4736048 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4736056 b */
    goto L_4737316;
    L_4736060: ;
    /* @4736060 load */
    /* @4736068 constant */
    /* @4736072 cmp */
    /* @4736076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_4736100;
    /* @4736080 load */
    /* @4736088 constant */
    /* @4736092 cmp */
    /* @4736096 b */
    p4736104_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1));
    goto L_4736104;
    L_4736100: ;
    /* @4736100 constant */
    p4736104_0 = VAL(0);
    L_4736104: ;
    /* @4736104 bf */
    if (!TRUTH(p4736104_0)) goto L_4736268;
    /* @4736108 constant */
    /* @4736112 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4736120 constant */
    /* @4736124 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736132 constant */
    /* @4736136 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4736144 constant */
    /* @4736148 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736156 constant */
    /* @4736160 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4736168 constant */
    /* @4736172 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4736180 constant */
    /* @4736184 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4736192 constant */
    /* @4736196 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4736204 constant */
    /* @4736208 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4736216 constant */
    /* @4736220 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4736228 constant */
    /* @4736232 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4736240 constant */
    /* @4736244 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4736252 constant */
    /* @4736256 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4736264 b */
    goto L_4737316;
    L_4736268: ;
    /* @4736268 load */
    /* @4736276 constant */
    /* @4736280 cmp */
    /* @4736284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_4736328;
    /* @4736288 load */
    /* @4736296 constant */
    /* @4736300 cmp */
    /* @4736304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4736328;
    /* @4736308 load */
    /* @4736316 constant */
    /* @4736320 cmp */
    /* @4736324 b */
    p4736332_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4736332;
    L_4736328: ;
    /* @4736328 constant */
    p4736332_0 = VAL(0);
    L_4736332: ;
    /* @4736332 bf */
    if (!TRUTH(p4736332_0)) goto L_4736496;
    /* @4736336 constant */
    /* @4736340 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4736348 constant */
    /* @4736352 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736360 constant */
    /* @4736364 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4736372 constant */
    /* @4736376 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736384 constant */
    /* @4736388 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4736396 constant */
    /* @4736400 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4736408 constant */
    /* @4736412 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4736420 constant */
    /* @4736424 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4736432 constant */
    /* @4736436 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4736444 constant */
    /* @4736448 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4736456 constant */
    /* @4736460 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4736468 constant */
    /* @4736472 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4736480 constant */
    /* @4736484 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4736492 b */
    goto L_4737316;
    L_4736496: ;
    /* @4736496 load */
    /* @4736504 constant */
    /* @4736508 cmp */
    /* @4736512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerang") == VAL(1)))) goto L_4736556;
    /* @4736516 load */
    /* @4736524 constant */
    /* @4736528 cmp */
    /* @4736532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0)))) goto L_4736556;
    /* @4736536 load */
    /* @4736544 constant */
    /* @4736548 cmp */
    /* @4736552 b */
    p4736560_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4736560;
    L_4736556: ;
    /* @4736556 constant */
    p4736560_0 = VAL(0);
    L_4736560: ;
    /* @4736560 bf */
    if (!TRUTH(p4736560_0)) goto L_4736724;
    /* @4736564 constant */
    /* @4736568 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4736576 constant */
    /* @4736580 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736588 constant */
    /* @4736592 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4736600 constant */
    /* @4736604 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736612 constant */
    /* @4736616 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4736624 constant */
    /* @4736628 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4736636 constant */
    /* @4736640 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4736648 constant */
    /* @4736652 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4736660 constant */
    /* @4736664 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4736672 constant */
    /* @4736676 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4736684 constant */
    /* @4736688 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4736696 constant */
    /* @4736700 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4736708 constant */
    /* @4736712 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4736720 b */
    goto L_4737316;
    L_4736724: ;
    /* @4736724 load */
    /* @4736732 constant */
    /* @4736736 cmp */
    /* @4736740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegun") == VAL(1)))) goto L_4736764;
    /* @4736744 load */
    /* @4736752 constant */
    /* @4736756 cmp */
    /* @4736760 b */
    p4736768_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1));
    goto L_4736768;
    L_4736764: ;
    /* @4736764 constant */
    p4736768_0 = VAL(0);
    L_4736768: ;
    /* @4736768 bf */
    if (!TRUTH(p4736768_0)) goto L_4736932;
    /* @4736772 constant */
    /* @4736776 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4736784 constant */
    /* @4736788 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736796 constant */
    /* @4736800 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4736808 constant */
    /* @4736812 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4736820 constant */
    /* @4736824 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4736832 constant */
    /* @4736836 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4736844 constant */
    /* @4736848 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4736856 constant */
    /* @4736860 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4736868 constant */
    /* @4736872 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4736880 constant */
    /* @4736884 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4736892 constant */
    /* @4736896 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4736904 constant */
    /* @4736908 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4736916 constant */
    /* @4736920 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4736928 b */
    goto L_4737316;
    L_4736932: ;
    /* @4736932 load */
    /* @4736940 constant */
    /* @4736944 cmp */
    /* @4736948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegun") == VAL(1)))) goto L_4736972;
    /* @4736952 load */
    /* @4736960 constant */
    /* @4736964 cmp */
    /* @4736968 b */
    p4736976_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4736976;
    L_4736972: ;
    /* @4736972 constant */
    p4736976_0 = VAL(0);
    L_4736976: ;
    /* @4736976 bf */
    if (!TRUTH(p4736976_0)) goto L_4737140;
    /* @4736980 constant */
    /* @4736984 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4736992 constant */
    /* @4736996 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4737004 constant */
    /* @4737008 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4737016 constant */
    /* @4737020 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4737028 constant */
    /* @4737032 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4737040 constant */
    /* @4737044 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4737052 constant */
    /* @4737056 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4737064 constant */
    /* @4737068 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4737076 constant */
    /* @4737080 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4737088 constant */
    /* @4737092 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4737100 constant */
    /* @4737104 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4737112 constant */
    /* @4737116 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4737124 constant */
    /* @4737128 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4737136 b */
    goto L_4737316;
    L_4737140: ;
    /* @4737140 load */
    /* @4737148 constant */
    /* @4737152 cmp */
    /* @4737156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgun") == VAL(1)))) goto L_4737316;
    /* @4737160 constant */
    /* @4737164 store */
    GM_WRITE(vm, -5, "pistol", VAL(1));
    /* @4737172 constant */
    /* @4737176 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4737184 constant */
    /* @4737188 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4737196 constant */
    /* @4737200 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4737208 constant */
    /* @4737212 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4737220 constant */
    /* @4737224 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4737232 constant */
    /* @4737236 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4737244 constant */
    /* @4737248 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4737256 constant */
    /* @4737260 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4737268 constant */
    /* @4737272 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4737280 constant */
    /* @4737284 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4737292 constant */
    /* @4737296 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4737304 constant */
    /* @4737308 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    L_4737316: ;
    /* @4737316 constant */
    /* @4737320 cast */
    /* @4737324 load */
    /* @4737332 load */
    /* @4737340 constant */
    /* @4737344 sub */
    /* @4737348 call */
    GM_SITE(vm, 519, 4737348);
    /* @4737356 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, 0, "x") - VAL(16)), GM_READ(vm, 0, "y"), VAL(105)));
    L_4737360: ;
    return;
}
