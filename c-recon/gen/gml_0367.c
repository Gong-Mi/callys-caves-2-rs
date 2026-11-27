/* generated from CODE 367 (gml_Object_obj_UI_Alarm_1), source start 4219172, end 4224184. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0367(GmVM* vm) {
    /* @4219172 load */
    /* @4219180 constant */
    /* @4219184 cmp */
    /* @4219188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(1)))) goto L_4219204;
    /* @4219192 constant */
    /* @4219196 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(1));
    L_4219204: ;
    /* @4219204 load */
    /* @4219212 constant */
    /* @4219216 cmp */
    /* @4219220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(2)))) goto L_4219244;
    /* @4219224 constant */
    /* @4219236 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(1.3));
    L_4219244: ;
    /* @4219244 load */
    /* @4219252 constant */
    /* @4219256 cmp */
    /* @4219260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(3)))) goto L_4219284;
    /* @4219264 constant */
    /* @4219276 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(1.6));
    L_4219284: ;
    /* @4219284 load */
    /* @4219292 constant */
    /* @4219296 cmp */
    /* @4219300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(4)))) goto L_4219316;
    /* @4219304 constant */
    /* @4219308 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(2));
    L_4219316: ;
    /* @4219316 load */
    /* @4219324 constant */
    /* @4219328 cmp */
    /* @4219332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(5)))) goto L_4219356;
    /* @4219336 constant */
    /* @4219348 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(2.4));
    L_4219356: ;
    /* @4219356 load */
    /* @4219364 constant */
    /* @4219368 cmp */
    /* @4219372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(6)))) goto L_4219396;
    /* @4219376 constant */
    /* @4219388 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(2.8));
    L_4219396: ;
    /* @4219396 load */
    /* @4219404 constant */
    /* @4219408 cmp */
    /* @4219412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(7)))) goto L_4219436;
    /* @4219416 constant */
    /* @4219428 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(3.2));
    L_4219436: ;
    /* @4219436 load */
    /* @4219444 constant */
    /* @4219448 cmp */
    /* @4219452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(8)))) goto L_4219476;
    /* @4219456 constant */
    /* @4219468 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(3.6));
    L_4219476: ;
    /* @4219476 load */
    /* @4219484 constant */
    /* @4219488 cmp */
    /* @4219492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(9)))) goto L_4219508;
    /* @4219496 constant */
    /* @4219500 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(4));
    L_4219508: ;
    /* @4219508 load */
    /* @4219516 constant */
    /* @4219520 cmp */
    /* @4219524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(10)))) goto L_4219540;
    /* @4219528 constant */
    /* @4219532 store */
    GM_WRITE(vm, -5, "pistoldamage", VAL(5));
    L_4219540: ;
    /* @4219540 load */
    /* @4219548 constant */
    /* @4219552 cmp */
    /* @4219556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") > VAL(10)))) goto L_4219572;
    /* @4219560 constant */
    /* @4219564 store */
    GM_WRITE(vm, -5, "pistollevel", VAL(10));
    L_4219572: ;
    /* @4219572 load */
    /* @4219580 constant */
    /* @4219584 cmp */
    /* @4219588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(1)))) goto L_4219612;
    /* @4219592 constant */
    /* @4219604 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(0.5));
    L_4219612: ;
    /* @4219612 load */
    /* @4219620 constant */
    /* @4219624 cmp */
    /* @4219628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(2)))) goto L_4219652;
    /* @4219632 constant */
    /* @4219644 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(0.6));
    L_4219652: ;
    /* @4219652 load */
    /* @4219660 constant */
    /* @4219664 cmp */
    /* @4219668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(3)))) goto L_4219692;
    /* @4219672 constant */
    /* @4219684 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(0.7));
    L_4219692: ;
    /* @4219692 load */
    /* @4219700 constant */
    /* @4219704 cmp */
    /* @4219708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(4)))) goto L_4219732;
    /* @4219712 constant */
    /* @4219724 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(0.8));
    L_4219732: ;
    /* @4219732 load */
    /* @4219740 constant */
    /* @4219744 cmp */
    /* @4219748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(5)))) goto L_4219772;
    /* @4219752 constant */
    /* @4219764 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(0.9));
    L_4219772: ;
    /* @4219772 load */
    /* @4219780 constant */
    /* @4219784 cmp */
    /* @4219788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(6)))) goto L_4219804;
    /* @4219792 constant */
    /* @4219796 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(1));
    L_4219804: ;
    /* @4219804 load */
    /* @4219812 constant */
    /* @4219816 cmp */
    /* @4219820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(7)))) goto L_4219844;
    /* @4219824 constant */
    /* @4219836 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(1.1));
    L_4219844: ;
    /* @4219844 load */
    /* @4219852 constant */
    /* @4219856 cmp */
    /* @4219860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(8)))) goto L_4219884;
    /* @4219864 constant */
    /* @4219876 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(1.2));
    L_4219884: ;
    /* @4219884 load */
    /* @4219892 constant */
    /* @4219896 cmp */
    /* @4219900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(9)))) goto L_4219924;
    /* @4219904 constant */
    /* @4219916 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(1.3));
    L_4219924: ;
    /* @4219924 load */
    /* @4219932 constant */
    /* @4219936 cmp */
    /* @4219940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(10)))) goto L_4219964;
    /* @4219944 constant */
    /* @4219956 store */
    GM_WRITE(vm, -5, "shotgundamage", VAL(1.5));
    L_4219964: ;
    /* @4219964 load */
    /* @4219972 constant */
    /* @4219976 cmp */
    /* @4219980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") > VAL(10)))) goto L_4219996;
    /* @4219984 constant */
    /* @4219988 store */
    GM_WRITE(vm, -5, "shotgunlevel", VAL(10));
    L_4219996: ;
    /* @4219996 load */
    /* @4220004 constant */
    /* @4220008 cmp */
    /* @4220012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(1)))) goto L_4220036;
    /* @4220016 constant */
    /* @4220028 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(0.6));
    L_4220036: ;
    /* @4220036 load */
    /* @4220044 constant */
    /* @4220048 cmp */
    /* @4220052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(2)))) goto L_4220076;
    /* @4220056 constant */
    /* @4220068 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(0.7));
    L_4220076: ;
    /* @4220076 load */
    /* @4220084 constant */
    /* @4220088 cmp */
    /* @4220092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(3)))) goto L_4220116;
    /* @4220096 constant */
    /* @4220108 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(0.8));
    L_4220116: ;
    /* @4220116 load */
    /* @4220124 constant */
    /* @4220128 cmp */
    /* @4220132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(4)))) goto L_4220148;
    /* @4220136 constant */
    /* @4220140 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1));
    L_4220148: ;
    /* @4220148 load */
    /* @4220156 constant */
    /* @4220160 cmp */
    /* @4220164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(5)))) goto L_4220188;
    /* @4220168 constant */
    /* @4220180 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1.1));
    L_4220188: ;
    /* @4220188 load */
    /* @4220196 constant */
    /* @4220200 cmp */
    /* @4220204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(6)))) goto L_4220228;
    /* @4220208 constant */
    /* @4220220 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1.2));
    L_4220228: ;
    /* @4220228 load */
    /* @4220236 constant */
    /* @4220240 cmp */
    /* @4220244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(7)))) goto L_4220268;
    /* @4220248 constant */
    /* @4220260 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1.4));
    L_4220268: ;
    /* @4220268 load */
    /* @4220276 constant */
    /* @4220280 cmp */
    /* @4220284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(8)))) goto L_4220308;
    /* @4220288 constant */
    /* @4220300 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1.5));
    L_4220308: ;
    /* @4220308 load */
    /* @4220316 constant */
    /* @4220320 cmp */
    /* @4220324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(9)))) goto L_4220348;
    /* @4220328 constant */
    /* @4220340 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(1.7));
    L_4220348: ;
    /* @4220348 load */
    /* @4220356 constant */
    /* @4220360 cmp */
    /* @4220364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(10)))) goto L_4220380;
    /* @4220368 constant */
    /* @4220372 store */
    GM_WRITE(vm, -5, "assaultrifledamage", VAL(2));
    L_4220380: ;
    /* @4220380 load */
    /* @4220388 constant */
    /* @4220392 cmp */
    /* @4220396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") > VAL(10)))) goto L_4220412;
    /* @4220400 constant */
    /* @4220404 store */
    GM_WRITE(vm, -5, "assaultriflelevel", VAL(10));
    L_4220412: ;
    /* @4220412 load */
    /* @4220420 constant */
    /* @4220424 cmp */
    /* @4220428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(1)))) goto L_4220444;
    /* @4220432 constant */
    /* @4220436 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(1));
    L_4220444: ;
    /* @4220444 load */
    /* @4220452 constant */
    /* @4220456 cmp */
    /* @4220460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(2)))) goto L_4220484;
    /* @4220464 constant */
    /* @4220476 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(1.2));
    L_4220484: ;
    /* @4220484 load */
    /* @4220492 constant */
    /* @4220496 cmp */
    /* @4220500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(3)))) goto L_4220524;
    /* @4220504 constant */
    /* @4220516 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(1.4));
    L_4220524: ;
    /* @4220524 load */
    /* @4220532 constant */
    /* @4220536 cmp */
    /* @4220540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(4)))) goto L_4220564;
    /* @4220544 constant */
    /* @4220556 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(1.7));
    L_4220564: ;
    /* @4220564 load */
    /* @4220572 constant */
    /* @4220576 cmp */
    /* @4220580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(5)))) goto L_4220604;
    /* @4220584 constant */
    /* @4220596 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(1.9));
    L_4220604: ;
    /* @4220604 load */
    /* @4220612 constant */
    /* @4220616 cmp */
    /* @4220620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(6)))) goto L_4220644;
    /* @4220624 constant */
    /* @4220636 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(2.1));
    L_4220644: ;
    /* @4220644 load */
    /* @4220652 constant */
    /* @4220656 cmp */
    /* @4220660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(7)))) goto L_4220684;
    /* @4220664 constant */
    /* @4220676 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(2.4));
    L_4220684: ;
    /* @4220684 load */
    /* @4220692 constant */
    /* @4220696 cmp */
    /* @4220700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(8)))) goto L_4220724;
    /* @4220704 constant */
    /* @4220716 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(2.6));
    L_4220724: ;
    /* @4220724 load */
    /* @4220732 constant */
    /* @4220736 cmp */
    /* @4220740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(9)))) goto L_4220764;
    /* @4220744 constant */
    /* @4220756 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(2.8));
    L_4220764: ;
    /* @4220764 load */
    /* @4220772 constant */
    /* @4220776 cmp */
    /* @4220780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(10)))) goto L_4220796;
    /* @4220784 constant */
    /* @4220788 store */
    GM_WRITE(vm, -5, "icegundamage", VAL(3));
    L_4220796: ;
    /* @4220796 load */
    /* @4220804 constant */
    /* @4220808 cmp */
    /* @4220812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") > VAL(10)))) goto L_4220828;
    /* @4220816 constant */
    /* @4220820 store */
    GM_WRITE(vm, -5, "icegunlevel", VAL(10));
    L_4220828: ;
    /* @4220828 load */
    /* @4220836 constant */
    /* @4220840 cmp */
    /* @4220844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(1)))) goto L_4220868;
    /* @4220848 constant */
    /* @4220860 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(1.5));
    L_4220868: ;
    /* @4220868 load */
    /* @4220876 constant */
    /* @4220880 cmp */
    /* @4220884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(2)))) goto L_4220908;
    /* @4220888 constant */
    /* @4220900 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(1.6));
    L_4220908: ;
    /* @4220908 load */
    /* @4220916 constant */
    /* @4220920 cmp */
    /* @4220924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(3)))) goto L_4220948;
    /* @4220928 constant */
    /* @4220940 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(1.7));
    L_4220948: ;
    /* @4220948 load */
    /* @4220956 constant */
    /* @4220960 cmp */
    /* @4220964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(4)))) goto L_4220988;
    /* @4220968 constant */
    /* @4220980 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(1.8));
    L_4220988: ;
    /* @4220988 load */
    /* @4220996 constant */
    /* @4221000 cmp */
    /* @4221004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(5)))) goto L_4221028;
    /* @4221008 constant */
    /* @4221020 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(1.9));
    L_4221028: ;
    /* @4221028 load */
    /* @4221036 constant */
    /* @4221040 cmp */
    /* @4221044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(6)))) goto L_4221060;
    /* @4221048 constant */
    /* @4221052 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(2));
    L_4221060: ;
    /* @4221060 load */
    /* @4221068 constant */
    /* @4221072 cmp */
    /* @4221076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(7)))) goto L_4221100;
    /* @4221080 constant */
    /* @4221092 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(2.1));
    L_4221100: ;
    /* @4221100 load */
    /* @4221108 constant */
    /* @4221112 cmp */
    /* @4221116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(8)))) goto L_4221140;
    /* @4221120 constant */
    /* @4221132 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(2.2));
    L_4221140: ;
    /* @4221140 load */
    /* @4221148 constant */
    /* @4221152 cmp */
    /* @4221156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(9)))) goto L_4221180;
    /* @4221160 constant */
    /* @4221172 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(2.3));
    L_4221180: ;
    /* @4221180 load */
    /* @4221188 constant */
    /* @4221192 cmp */
    /* @4221196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(10)))) goto L_4221220;
    /* @4221200 constant */
    /* @4221212 store */
    GM_WRITE(vm, -5, "laserdamage", VAL(2.5));
    L_4221220: ;
    /* @4221220 load */
    /* @4221228 constant */
    /* @4221232 cmp */
    /* @4221236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") > VAL(10)))) goto L_4221252;
    /* @4221240 constant */
    /* @4221244 store */
    GM_WRITE(vm, -5, "laserlevel", VAL(10));
    L_4221252: ;
    /* @4221252 load */
    /* @4221260 constant */
    /* @4221264 cmp */
    /* @4221268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(1)))) goto L_4221292;
    /* @4221272 constant */
    /* @4221284 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(2.5));
    L_4221292: ;
    /* @4221292 load */
    /* @4221300 constant */
    /* @4221304 cmp */
    /* @4221308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(2)))) goto L_4221332;
    /* @4221312 constant */
    /* @4221324 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(2.6));
    L_4221332: ;
    /* @4221332 load */
    /* @4221340 constant */
    /* @4221344 cmp */
    /* @4221348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(3)))) goto L_4221372;
    /* @4221352 constant */
    /* @4221364 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(2.7));
    L_4221372: ;
    /* @4221372 load */
    /* @4221380 constant */
    /* @4221384 cmp */
    /* @4221388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(4)))) goto L_4221412;
    /* @4221392 constant */
    /* @4221404 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(2.8));
    L_4221412: ;
    /* @4221412 load */
    /* @4221420 constant */
    /* @4221424 cmp */
    /* @4221428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(5)))) goto L_4221452;
    /* @4221432 constant */
    /* @4221444 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(2.9));
    L_4221452: ;
    /* @4221452 load */
    /* @4221460 constant */
    /* @4221464 cmp */
    /* @4221468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(6)))) goto L_4221484;
    /* @4221472 constant */
    /* @4221476 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(3));
    L_4221484: ;
    /* @4221484 load */
    /* @4221492 constant */
    /* @4221496 cmp */
    /* @4221500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(7)))) goto L_4221524;
    /* @4221504 constant */
    /* @4221516 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(3.2));
    L_4221524: ;
    /* @4221524 load */
    /* @4221532 constant */
    /* @4221536 cmp */
    /* @4221540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(8)))) goto L_4221564;
    /* @4221544 constant */
    /* @4221556 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(3.4));
    L_4221564: ;
    /* @4221564 load */
    /* @4221572 constant */
    /* @4221576 cmp */
    /* @4221580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(9)))) goto L_4221604;
    /* @4221584 constant */
    /* @4221596 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(3.6));
    L_4221604: ;
    /* @4221604 load */
    /* @4221612 constant */
    /* @4221616 cmp */
    /* @4221620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(10)))) goto L_4221636;
    /* @4221624 constant */
    /* @4221628 store */
    GM_WRITE(vm, -5, "rocketdamage", VAL(4));
    L_4221636: ;
    /* @4221636 load */
    /* @4221644 constant */
    /* @4221648 cmp */
    /* @4221652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") > VAL(10)))) goto L_4221668;
    /* @4221656 constant */
    /* @4221660 store */
    GM_WRITE(vm, -5, "rocketlevel", VAL(10));
    L_4221668: ;
    /* @4221668 load */
    /* @4221676 constant */
    /* @4221680 cmp */
    /* @4221684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(1)))) goto L_4221700;
    /* @4221688 constant */
    /* @4221692 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(2));
    L_4221700: ;
    /* @4221700 load */
    /* @4221708 constant */
    /* @4221712 cmp */
    /* @4221716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(2)))) goto L_4221740;
    /* @4221720 constant */
    /* @4221732 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(2.2));
    L_4221740: ;
    /* @4221740 load */
    /* @4221748 constant */
    /* @4221752 cmp */
    /* @4221756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(3)))) goto L_4221780;
    /* @4221760 constant */
    /* @4221772 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(2.4));
    L_4221780: ;
    /* @4221780 load */
    /* @4221788 constant */
    /* @4221792 cmp */
    /* @4221796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(4)))) goto L_4221820;
    /* @4221800 constant */
    /* @4221812 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(2.6));
    L_4221820: ;
    /* @4221820 load */
    /* @4221828 constant */
    /* @4221832 cmp */
    /* @4221836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(5)))) goto L_4221860;
    /* @4221840 constant */
    /* @4221852 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(2.8));
    L_4221860: ;
    /* @4221860 load */
    /* @4221868 constant */
    /* @4221872 cmp */
    /* @4221876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(6)))) goto L_4221892;
    /* @4221880 constant */
    /* @4221884 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(3));
    L_4221892: ;
    /* @4221892 load */
    /* @4221900 constant */
    /* @4221904 cmp */
    /* @4221908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(7)))) goto L_4221932;
    /* @4221912 constant */
    /* @4221924 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(3.2));
    L_4221932: ;
    /* @4221932 load */
    /* @4221940 constant */
    /* @4221944 cmp */
    /* @4221948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(8)))) goto L_4221972;
    /* @4221952 constant */
    /* @4221964 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(3.4));
    L_4221972: ;
    /* @4221972 load */
    /* @4221980 constant */
    /* @4221984 cmp */
    /* @4221988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(9)))) goto L_4222012;
    /* @4221992 constant */
    /* @4222004 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(3.6));
    L_4222012: ;
    /* @4222012 load */
    /* @4222020 constant */
    /* @4222024 cmp */
    /* @4222028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(10)))) goto L_4222044;
    /* @4222032 constant */
    /* @4222036 store */
    GM_WRITE(vm, -5, "bowdamage", VAL(4));
    L_4222044: ;
    /* @4222044 load */
    /* @4222052 constant */
    /* @4222056 cmp */
    /* @4222060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") > VAL(10)))) goto L_4222076;
    /* @4222064 constant */
    /* @4222068 store */
    GM_WRITE(vm, -5, "bowlevel", VAL(10));
    L_4222076: ;
    /* @4222076 load */
    /* @4222084 constant */
    /* @4222088 cmp */
    /* @4222092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(1)))) goto L_4222116;
    /* @4222096 constant */
    /* @4222108 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(0.3));
    L_4222116: ;
    /* @4222116 load */
    /* @4222124 constant */
    /* @4222128 cmp */
    /* @4222132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(2)))) goto L_4222156;
    /* @4222136 constant */
    /* @4222148 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(0.5));
    L_4222156: ;
    /* @4222156 load */
    /* @4222164 constant */
    /* @4222168 cmp */
    /* @4222172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(3)))) goto L_4222196;
    /* @4222176 constant */
    /* @4222188 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(0.7));
    L_4222196: ;
    /* @4222196 load */
    /* @4222204 constant */
    /* @4222208 cmp */
    /* @4222212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(4)))) goto L_4222236;
    /* @4222216 constant */
    /* @4222228 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(0.9));
    L_4222236: ;
    /* @4222236 load */
    /* @4222244 constant */
    /* @4222248 cmp */
    /* @4222252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(5)))) goto L_4222268;
    /* @4222256 constant */
    /* @4222260 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(1));
    L_4222268: ;
    /* @4222268 load */
    /* @4222276 constant */
    /* @4222280 cmp */
    /* @4222284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(6)))) goto L_4222308;
    /* @4222288 constant */
    /* @4222300 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(1.1));
    L_4222308: ;
    /* @4222308 load */
    /* @4222316 constant */
    /* @4222320 cmp */
    /* @4222324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(7)))) goto L_4222348;
    /* @4222328 constant */
    /* @4222340 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(1.2));
    L_4222348: ;
    /* @4222348 load */
    /* @4222356 constant */
    /* @4222360 cmp */
    /* @4222364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(8)))) goto L_4222388;
    /* @4222368 constant */
    /* @4222380 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(1.4));
    L_4222388: ;
    /* @4222388 load */
    /* @4222396 constant */
    /* @4222400 cmp */
    /* @4222404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(9)))) goto L_4222428;
    /* @4222408 constant */
    /* @4222420 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(1.5));
    L_4222428: ;
    /* @4222428 load */
    /* @4222436 constant */
    /* @4222440 cmp */
    /* @4222444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(10)))) goto L_4222460;
    /* @4222448 constant */
    /* @4222452 store */
    GM_WRITE(vm, -5, "flamethrowerdamage", VAL(2));
    L_4222460: ;
    /* @4222460 load */
    /* @4222468 constant */
    /* @4222472 cmp */
    /* @4222476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") > VAL(10)))) goto L_4222492;
    /* @4222480 constant */
    /* @4222484 store */
    GM_WRITE(vm, -5, "flamethrowerlevel", VAL(10));
    L_4222492: ;
    /* @4222492 load */
    /* @4222500 constant */
    /* @4222504 cmp */
    /* @4222508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(1)))) goto L_4222524;
    /* @4222512 constant */
    /* @4222516 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1));
    L_4222524: ;
    /* @4222524 load */
    /* @4222532 constant */
    /* @4222536 cmp */
    /* @4222540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(2)))) goto L_4222564;
    /* @4222544 constant */
    /* @4222556 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1.2));
    L_4222564: ;
    /* @4222564 load */
    /* @4222572 constant */
    /* @4222576 cmp */
    /* @4222580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(3)))) goto L_4222604;
    /* @4222584 constant */
    /* @4222596 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1.3));
    L_4222604: ;
    /* @4222604 load */
    /* @4222612 constant */
    /* @4222616 cmp */
    /* @4222620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(4)))) goto L_4222644;
    /* @4222624 constant */
    /* @4222636 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1.5));
    L_4222644: ;
    /* @4222644 load */
    /* @4222652 constant */
    /* @4222656 cmp */
    /* @4222660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(5)))) goto L_4222684;
    /* @4222664 constant */
    /* @4222676 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1.6));
    L_4222684: ;
    /* @4222684 load */
    /* @4222692 constant */
    /* @4222696 cmp */
    /* @4222700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(6)))) goto L_4222724;
    /* @4222704 constant */
    /* @4222716 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(1.7));
    L_4222724: ;
    /* @4222724 load */
    /* @4222732 constant */
    /* @4222736 cmp */
    /* @4222740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(7)))) goto L_4222756;
    /* @4222744 constant */
    /* @4222748 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(2));
    L_4222756: ;
    /* @4222756 load */
    /* @4222764 constant */
    /* @4222768 cmp */
    /* @4222772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(8)))) goto L_4222796;
    /* @4222776 constant */
    /* @4222788 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(2.1));
    L_4222796: ;
    /* @4222796 load */
    /* @4222804 constant */
    /* @4222808 cmp */
    /* @4222812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(9)))) goto L_4222836;
    /* @4222816 constant */
    /* @4222828 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(2.2));
    L_4222836: ;
    /* @4222836 load */
    /* @4222844 constant */
    /* @4222848 cmp */
    /* @4222852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(10)))) goto L_4222876;
    /* @4222856 constant */
    /* @4222868 store */
    GM_WRITE(vm, -5, "bladegundamage", VAL(2.5));
    L_4222876: ;
    /* @4222876 load */
    /* @4222884 constant */
    /* @4222888 cmp */
    /* @4222892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") > VAL(10)))) goto L_4222908;
    /* @4222896 constant */
    /* @4222900 store */
    GM_WRITE(vm, -5, "bladegunlevel", VAL(10));
    L_4222908: ;
    /* @4222908 load */
    /* @4222916 constant */
    /* @4222920 cmp */
    /* @4222924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(1)))) goto L_4222948;
    /* @4222928 constant */
    /* @4222940 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(1.5));
    L_4222948: ;
    /* @4222948 load */
    /* @4222956 constant */
    /* @4222960 cmp */
    /* @4222964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(2)))) goto L_4222988;
    /* @4222968 constant */
    /* @4222980 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(1.6));
    L_4222988: ;
    /* @4222988 load */
    /* @4222996 constant */
    /* @4223000 cmp */
    /* @4223004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(3)))) goto L_4223028;
    /* @4223008 constant */
    /* @4223020 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(1.7));
    L_4223028: ;
    /* @4223028 load */
    /* @4223036 constant */
    /* @4223040 cmp */
    /* @4223044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(4)))) goto L_4223068;
    /* @4223048 constant */
    /* @4223060 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(1.8));
    L_4223068: ;
    /* @4223068 load */
    /* @4223076 constant */
    /* @4223080 cmp */
    /* @4223084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(5)))) goto L_4223108;
    /* @4223088 constant */
    /* @4223100 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(1.9));
    L_4223108: ;
    /* @4223108 load */
    /* @4223116 constant */
    /* @4223120 cmp */
    /* @4223124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(6)))) goto L_4223140;
    /* @4223128 constant */
    /* @4223132 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(2));
    L_4223140: ;
    /* @4223140 load */
    /* @4223148 constant */
    /* @4223152 cmp */
    /* @4223156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(7)))) goto L_4223180;
    /* @4223160 constant */
    /* @4223172 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(2.2));
    L_4223180: ;
    /* @4223180 load */
    /* @4223188 constant */
    /* @4223192 cmp */
    /* @4223196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(8)))) goto L_4223220;
    /* @4223200 constant */
    /* @4223212 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(2.4));
    L_4223220: ;
    /* @4223220 load */
    /* @4223228 constant */
    /* @4223232 cmp */
    /* @4223236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(9)))) goto L_4223260;
    /* @4223240 constant */
    /* @4223252 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(2.6));
    L_4223260: ;
    /* @4223260 load */
    /* @4223268 constant */
    /* @4223272 cmp */
    /* @4223276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(10)))) goto L_4223292;
    /* @4223280 constant */
    /* @4223284 store */
    GM_WRITE(vm, -5, "spikegundamage", VAL(3));
    L_4223292: ;
    /* @4223292 load */
    /* @4223300 constant */
    /* @4223304 cmp */
    /* @4223308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") > VAL(10)))) goto L_4223324;
    /* @4223312 constant */
    /* @4223316 store */
    GM_WRITE(vm, -5, "spikegunlevel", VAL(10));
    L_4223324: ;
    /* @4223324 load */
    /* @4223332 constant */
    /* @4223336 cmp */
    /* @4223340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(1)))) goto L_4223364;
    /* @4223344 constant */
    /* @4223356 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.1));
    L_4223364: ;
    /* @4223364 load */
    /* @4223372 constant */
    /* @4223376 cmp */
    /* @4223380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(2)))) goto L_4223404;
    /* @4223384 constant */
    /* @4223396 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.15));
    L_4223404: ;
    /* @4223404 load */
    /* @4223412 constant */
    /* @4223416 cmp */
    /* @4223420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(3)))) goto L_4223444;
    /* @4223424 constant */
    /* @4223436 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.2));
    L_4223444: ;
    /* @4223444 load */
    /* @4223452 constant */
    /* @4223456 cmp */
    /* @4223460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(4)))) goto L_4223484;
    /* @4223464 constant */
    /* @4223476 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.3));
    L_4223484: ;
    /* @4223484 load */
    /* @4223492 constant */
    /* @4223496 cmp */
    /* @4223500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(5)))) goto L_4223524;
    /* @4223504 constant */
    /* @4223516 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.35));
    L_4223524: ;
    /* @4223524 load */
    /* @4223532 constant */
    /* @4223536 cmp */
    /* @4223540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(6)))) goto L_4223564;
    /* @4223544 constant */
    /* @4223556 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.4));
    L_4223564: ;
    /* @4223564 load */
    /* @4223572 constant */
    /* @4223576 cmp */
    /* @4223580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(7)))) goto L_4223604;
    /* @4223584 constant */
    /* @4223596 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.5));
    L_4223604: ;
    /* @4223604 load */
    /* @4223612 constant */
    /* @4223616 cmp */
    /* @4223620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(8)))) goto L_4223644;
    /* @4223624 constant */
    /* @4223636 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.6));
    L_4223644: ;
    /* @4223644 load */
    /* @4223652 constant */
    /* @4223656 cmp */
    /* @4223660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(9)))) goto L_4223684;
    /* @4223664 constant */
    /* @4223676 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(0.7));
    L_4223684: ;
    /* @4223684 load */
    /* @4223692 constant */
    /* @4223696 cmp */
    /* @4223700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(10)))) goto L_4223716;
    /* @4223704 constant */
    /* @4223708 store */
    GM_WRITE(vm, -5, "boomerangdamage", VAL(1));
    L_4223716: ;
    /* @4223716 load */
    /* @4223724 constant */
    /* @4223728 cmp */
    /* @4223732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") > VAL(10)))) goto L_4223748;
    /* @4223736 constant */
    /* @4223740 store */
    GM_WRITE(vm, -5, "boomeranglevel", VAL(10));
    L_4223748: ;
    /* @4223748 load */
    /* @4223756 constant */
    /* @4223760 cmp */
    /* @4223764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(1)))) goto L_4223788;
    /* @4223768 constant */
    /* @4223780 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(3.5));
    L_4223788: ;
    /* @4223788 load */
    /* @4223796 constant */
    /* @4223800 cmp */
    /* @4223804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(2)))) goto L_4223828;
    /* @4223808 constant */
    /* @4223820 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(3.7));
    L_4223828: ;
    /* @4223828 load */
    /* @4223836 constant */
    /* @4223840 cmp */
    /* @4223844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(3)))) goto L_4223868;
    /* @4223848 constant */
    /* @4223860 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(3.9));
    L_4223868: ;
    /* @4223868 load */
    /* @4223876 constant */
    /* @4223880 cmp */
    /* @4223884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(4)))) goto L_4223900;
    /* @4223888 constant */
    /* @4223892 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4));
    L_4223900: ;
    /* @4223900 load */
    /* @4223908 constant */
    /* @4223912 cmp */
    /* @4223916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(5)))) goto L_4223940;
    /* @4223920 constant */
    /* @4223932 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4.1));
    L_4223940: ;
    /* @4223940 load */
    /* @4223948 constant */
    /* @4223952 cmp */
    /* @4223956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(6)))) goto L_4223980;
    /* @4223960 constant */
    /* @4223972 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4.2));
    L_4223980: ;
    /* @4223980 load */
    /* @4223988 constant */
    /* @4223992 cmp */
    /* @4223996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(7)))) goto L_4224020;
    /* @4224000 constant */
    /* @4224012 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4.4));
    L_4224020: ;
    /* @4224020 load */
    /* @4224028 constant */
    /* @4224032 cmp */
    /* @4224036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(8)))) goto L_4224060;
    /* @4224040 constant */
    /* @4224052 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4.5));
    L_4224060: ;
    /* @4224060 load */
    /* @4224068 constant */
    /* @4224072 cmp */
    /* @4224076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(9)))) goto L_4224100;
    /* @4224080 constant */
    /* @4224092 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(4.6));
    L_4224100: ;
    /* @4224100 load */
    /* @4224108 constant */
    /* @4224112 cmp */
    /* @4224116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(10)))) goto L_4224132;
    /* @4224120 constant */
    /* @4224124 store */
    GM_WRITE(vm, -5, "bombgundamage", VAL(5));
    L_4224132: ;
    /* @4224132 load */
    /* @4224140 constant */
    /* @4224144 cmp */
    /* @4224148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") > VAL(10)))) goto L_4224164;
    /* @4224152 constant */
    /* @4224156 store */
    GM_WRITE(vm, -5, "bombgunlevel", VAL(10));
    L_4224164: ;
    /* @4224164 constant */
    /* @4224168 constant */
    /* @4224172 constant */
    /* @4224176 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    L_4224184: ;
    return;
}
