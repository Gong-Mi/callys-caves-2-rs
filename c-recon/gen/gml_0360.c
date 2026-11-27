/* generated from CODE 360 (gml_Object_obj_bg_Create_0), source start 4209768, end 4216204. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0360(GmVM* vm) {
    Val p4211736_0;
    Val p4211776_0;
    Val p4211816_0;
    Val p4211856_0;
    Val p4211896_0;
    Val p4211936_0;
    Val p4211976_0;
    Val p4212016_0;
    Val p4212056_0;
    Val p4212096_0;
    Val p4212136_0;
    Val p4212176_0;
    Val p4212216_0;
    Val p4212256_0;
    Val p4212296_0;
    Val p4212336_0;
    Val p4212376_0;
    Val p4212416_0;
    Val p4212456_0;
    Val p4212496_0;
    Val p4212536_0;
    Val p4212576_0;
    Val p4212616_0;
    Val p4212656_0;
    Val p4212696_0;
    Val p4212736_0;
    Val p4212776_0;
    Val p4212816_0;
    Val p4212856_0;
    Val p4212896_0;
    Val p4212936_0;
    Val p4212976_0;
    Val p4213016_0;
    Val p4213056_0;
    Val p4213096_0;
    Val p4213136_0;
    Val p4213176_0;
    Val p4213216_0;
    Val p4213256_0;
    Val p4213296_0;
    Val p4213336_0;
    Val p4213376_0;
    Val p4213416_0;
    Val p4213456_0;
    Val p4213496_0;
    Val p4213536_0;
    Val p4213576_0;
    Val p4213616_0;
    Val p4213656_0;
    Val p4213696_0;
    Val p4213736_0;
    Val p4213776_0;
    Val p4213816_0;
    Val p4213856_0;
    Val p4213896_0;
    Val p4213936_0;
    Val p4213976_0;
    Val p4214016_0;
    Val p4214056_0;
    Val p4214096_0;
    Val p4214136_0;
    Val p4214176_0;
    Val p4214216_0;
    Val p4214256_0;
    Val p4214296_0;
    Val p4214336_0;
    Val p4214376_0;
    Val p4214416_0;
    Val p4214456_0;
    Val p4214496_0;
    Val p4214536_0;
    Val p4214576_0;
    Val p4214616_0;
    Val p4214656_0;
    Val p4214696_0;
    Val p4214736_0;
    Val p4214776_0;
    Val p4214816_0;
    Val p4214856_0;
    Val p4214896_0;
    Val p4214936_0;
    Val p4214976_0;
    Val p4215016_0;
    Val p4215056_0;
    Val p4215096_0;
    Val p4215136_0;
    Val p4215176_0;
    Val p4215216_0;
    Val p4215256_0;
    Val p4215296_0;
    Val p4215336_0;
    Val p4215376_0;
    Val p4215416_0;
    Val p4215456_0;
    Val p4215496_0;
    Val p4215536_0;
    Val p4215576_0;
    Val p4215616_0;
    Val p4215656_0;
    Val p4215696_0;
    Val p4215736_0;
    Val p4215776_0;
    Val p4215816_0;
    Val p4215856_0;
    Val p4215896_0;
    Val p4215936_0;
    Val p4215976_0;
    Val p4216016_0;
    Val p4216056_0;
    Val p4216096_0;
    Val p4216136_0;
    Val p4216152_0;
    Val p4216168_0;
    Val p4216184_0;
    Val p4216200_0;
    /* @4209768 constant */
    /* @4209772 store */
    GM_WRITE(vm, -1, "drawview0", VAL(0));
    /* @4209780 constant */
    /* @4209784 store */
    GM_WRITE(vm, -1, "drawview1", VAL(0));
    /* @4209792 constant */
    /* @4209796 store */
    GM_WRITE(vm, -1, "drawview3", VAL(0));
    /* @4209804 constant */
    /* @4209808 store */
    GM_WRITE(vm, -1, "drawview4", VAL(0));
    /* @4209816 constant */
    /* @4209820 store */
    GM_WRITE(vm, -1, "drawview5", VAL(0));
    /* @4209828 constant */
    /* @4209832 store */
    GM_WRITE(vm, -1, "drawview6", VAL(0));
    /* @4209840 constant */
    /* @4209844 constant */
    /* @4209848 constant */
    /* @4209852 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(5));
    /* @4209860 constant */
    /* @4209864 constant */
    /* @4209868 constant */
    /* @4209872 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(5));
    /* @4209880 constant */
    /* @4209884 constant */
    /* @4209888 constant */
    /* @4209892 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(1));
    /* @4209900 load */
    /* @4209908 dup */
    /* @4209912 constant */
    /* @4209916 cmp */
    /* @4209920 bt */
    p4211736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(0)))) goto L_4211736;
    /* @4209924 dup */
    /* @4209928 constant */
    /* @4209932 cmp */
    /* @4209936 bt */
    p4211776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_4211776;
    /* @4209940 dup */
    /* @4209944 constant */
    /* @4209948 cmp */
    /* @4209952 bt */
    p4211816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_4211816;
    /* @4209956 dup */
    /* @4209960 constant */
    /* @4209964 cmp */
    /* @4209968 bt */
    p4211856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_4211856;
    /* @4209972 dup */
    /* @4209976 constant */
    /* @4209980 cmp */
    /* @4209984 bt */
    p4211896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_4211896;
    /* @4209988 dup */
    /* @4209992 constant */
    /* @4209996 cmp */
    /* @4210000 bt */
    p4211936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_4211936;
    /* @4210004 dup */
    /* @4210008 constant */
    /* @4210012 cmp */
    /* @4210016 bt */
    p4211976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(6)))) goto L_4211976;
    /* @4210020 dup */
    /* @4210024 constant */
    /* @4210028 cmp */
    /* @4210032 bt */
    p4212016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(7)))) goto L_4212016;
    /* @4210036 dup */
    /* @4210040 constant */
    /* @4210044 cmp */
    /* @4210048 bt */
    p4212056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(8)))) goto L_4212056;
    /* @4210052 dup */
    /* @4210056 constant */
    /* @4210060 cmp */
    /* @4210064 bt */
    p4212096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(9)))) goto L_4212096;
    /* @4210068 dup */
    /* @4210072 constant */
    /* @4210076 cmp */
    /* @4210080 bt */
    p4212136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_4212136;
    /* @4210084 dup */
    /* @4210088 constant */
    /* @4210092 cmp */
    /* @4210096 bt */
    p4212176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(11)))) goto L_4212176;
    /* @4210100 dup */
    /* @4210104 constant */
    /* @4210108 cmp */
    /* @4210112 bt */
    p4212216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(12)))) goto L_4212216;
    /* @4210116 dup */
    /* @4210120 constant */
    /* @4210124 cmp */
    /* @4210128 bt */
    p4212256_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_4212256;
    /* @4210132 dup */
    /* @4210136 constant */
    /* @4210140 cmp */
    /* @4210144 bt */
    p4212296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(14)))) goto L_4212296;
    /* @4210148 dup */
    /* @4210152 constant */
    /* @4210156 cmp */
    /* @4210160 bt */
    p4212336_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_4212336;
    /* @4210164 dup */
    /* @4210168 constant */
    /* @4210172 cmp */
    /* @4210176 bt */
    p4212376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(16)))) goto L_4212376;
    /* @4210180 dup */
    /* @4210184 constant */
    /* @4210188 cmp */
    /* @4210192 bt */
    p4212416_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(17)))) goto L_4212416;
    /* @4210196 dup */
    /* @4210200 constant */
    /* @4210204 cmp */
    /* @4210208 bt */
    p4212456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(18)))) goto L_4212456;
    /* @4210212 dup */
    /* @4210216 constant */
    /* @4210220 cmp */
    /* @4210224 bt */
    p4212496_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(19)))) goto L_4212496;
    /* @4210228 dup */
    /* @4210232 constant */
    /* @4210236 cmp */
    /* @4210240 bt */
    p4212536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(20)))) goto L_4212536;
    /* @4210244 dup */
    /* @4210248 constant */
    /* @4210252 cmp */
    /* @4210256 bt */
    p4212576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(21)))) goto L_4212576;
    /* @4210260 dup */
    /* @4210264 constant */
    /* @4210268 cmp */
    /* @4210272 bt */
    p4212616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(22)))) goto L_4212616;
    /* @4210276 dup */
    /* @4210280 constant */
    /* @4210284 cmp */
    /* @4210288 bt */
    p4212656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(23)))) goto L_4212656;
    /* @4210292 dup */
    /* @4210296 constant */
    /* @4210300 cmp */
    /* @4210304 bt */
    p4212696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(24)))) goto L_4212696;
    /* @4210308 dup */
    /* @4210312 constant */
    /* @4210316 cmp */
    /* @4210320 bt */
    p4212736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(25)))) goto L_4212736;
    /* @4210324 dup */
    /* @4210328 constant */
    /* @4210332 cmp */
    /* @4210336 bt */
    p4212776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(26)))) goto L_4212776;
    /* @4210340 dup */
    /* @4210344 constant */
    /* @4210348 cmp */
    /* @4210352 bt */
    p4212816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_4212816;
    /* @4210356 dup */
    /* @4210360 constant */
    /* @4210364 cmp */
    /* @4210368 bt */
    p4212856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_4212856;
    /* @4210372 dup */
    /* @4210376 constant */
    /* @4210380 cmp */
    /* @4210384 bt */
    p4212896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(29)))) goto L_4212896;
    /* @4210388 dup */
    /* @4210392 constant */
    /* @4210396 cmp */
    /* @4210400 bt */
    p4212936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_4212936;
    /* @4210404 dup */
    /* @4210408 constant */
    /* @4210412 cmp */
    /* @4210416 bt */
    p4212976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(31)))) goto L_4212976;
    /* @4210420 dup */
    /* @4210424 constant */
    /* @4210428 cmp */
    /* @4210432 bt */
    p4213016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_4213016;
    /* @4210436 dup */
    /* @4210440 constant */
    /* @4210444 cmp */
    /* @4210448 bt */
    p4213056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(33)))) goto L_4213056;
    /* @4210452 dup */
    /* @4210456 constant */
    /* @4210460 cmp */
    /* @4210464 bt */
    p4213096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(34)))) goto L_4213096;
    /* @4210468 dup */
    /* @4210472 constant */
    /* @4210476 cmp */
    /* @4210480 bt */
    p4213136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(35)))) goto L_4213136;
    /* @4210484 dup */
    /* @4210488 constant */
    /* @4210492 cmp */
    /* @4210496 bt */
    p4213176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_4213176;
    /* @4210500 dup */
    /* @4210504 constant */
    /* @4210508 cmp */
    /* @4210512 bt */
    p4213216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(37)))) goto L_4213216;
    /* @4210516 dup */
    /* @4210520 constant */
    /* @4210524 cmp */
    /* @4210528 bt */
    p4213256_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(38)))) goto L_4213256;
    /* @4210532 dup */
    /* @4210536 constant */
    /* @4210540 cmp */
    /* @4210544 bt */
    p4213296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_4213296;
    /* @4210548 dup */
    /* @4210552 constant */
    /* @4210556 cmp */
    /* @4210560 bt */
    p4213336_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(40)))) goto L_4213336;
    /* @4210564 dup */
    /* @4210568 constant */
    /* @4210572 cmp */
    /* @4210576 bt */
    p4213376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(41)))) goto L_4213376;
    /* @4210580 dup */
    /* @4210584 constant */
    /* @4210588 cmp */
    /* @4210592 bt */
    p4213416_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(42)))) goto L_4213416;
    /* @4210596 dup */
    /* @4210600 constant */
    /* @4210604 cmp */
    /* @4210608 bt */
    p4213456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(43)))) goto L_4213456;
    /* @4210612 dup */
    /* @4210616 constant */
    /* @4210620 cmp */
    /* @4210624 bt */
    p4213496_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(44)))) goto L_4213496;
    /* @4210628 dup */
    /* @4210632 constant */
    /* @4210636 cmp */
    /* @4210640 bt */
    p4213536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(45)))) goto L_4213536;
    /* @4210644 dup */
    /* @4210648 constant */
    /* @4210652 cmp */
    /* @4210656 bt */
    p4213576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(46)))) goto L_4213576;
    /* @4210660 dup */
    /* @4210664 constant */
    /* @4210668 cmp */
    /* @4210672 bt */
    p4213616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(47)))) goto L_4213616;
    /* @4210676 dup */
    /* @4210680 constant */
    /* @4210684 cmp */
    /* @4210688 bt */
    p4213656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_4213656;
    /* @4210692 dup */
    /* @4210696 constant */
    /* @4210700 cmp */
    /* @4210704 bt */
    p4213696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_4213696;
    /* @4210708 dup */
    /* @4210712 constant */
    /* @4210716 cmp */
    /* @4210720 bt */
    p4213736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(50)))) goto L_4213736;
    /* @4210724 dup */
    /* @4210728 constant */
    /* @4210732 cmp */
    /* @4210736 bt */
    p4213776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(51)))) goto L_4213776;
    /* @4210740 dup */
    /* @4210744 constant */
    /* @4210748 cmp */
    /* @4210752 bt */
    p4213816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(52)))) goto L_4213816;
    /* @4210756 dup */
    /* @4210760 constant */
    /* @4210764 cmp */
    /* @4210768 bt */
    p4213856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(53)))) goto L_4213856;
    /* @4210772 dup */
    /* @4210776 constant */
    /* @4210780 cmp */
    /* @4210784 bt */
    p4213896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(54)))) goto L_4213896;
    /* @4210788 dup */
    /* @4210792 constant */
    /* @4210796 cmp */
    /* @4210800 bt */
    p4213936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(55)))) goto L_4213936;
    /* @4210804 dup */
    /* @4210808 constant */
    /* @4210812 cmp */
    /* @4210816 bt */
    p4213976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(56)))) goto L_4213976;
    /* @4210820 dup */
    /* @4210824 constant */
    /* @4210828 cmp */
    /* @4210832 bt */
    p4214016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(57)))) goto L_4214016;
    /* @4210836 dup */
    /* @4210840 constant */
    /* @4210844 cmp */
    /* @4210848 bt */
    p4214056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(58)))) goto L_4214056;
    /* @4210852 dup */
    /* @4210856 constant */
    /* @4210860 cmp */
    /* @4210864 bt */
    p4214096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(59)))) goto L_4214096;
    /* @4210868 dup */
    /* @4210872 constant */
    /* @4210876 cmp */
    /* @4210880 bt */
    p4214136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(60)))) goto L_4214136;
    /* @4210884 dup */
    /* @4210888 constant */
    /* @4210892 cmp */
    /* @4210896 bt */
    p4214176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(61)))) goto L_4214176;
    /* @4210900 dup */
    /* @4210904 constant */
    /* @4210908 cmp */
    /* @4210912 bt */
    p4214216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(62)))) goto L_4214216;
    /* @4210916 dup */
    /* @4210920 constant */
    /* @4210924 cmp */
    /* @4210928 bt */
    p4214256_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(63)))) goto L_4214256;
    /* @4210932 dup */
    /* @4210936 constant */
    /* @4210940 cmp */
    /* @4210944 bt */
    p4214296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_4214296;
    /* @4210948 dup */
    /* @4210952 constant */
    /* @4210956 cmp */
    /* @4210960 bt */
    p4214336_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(65)))) goto L_4214336;
    /* @4210964 dup */
    /* @4210968 constant */
    /* @4210972 cmp */
    /* @4210976 bt */
    p4214376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(66)))) goto L_4214376;
    /* @4210980 dup */
    /* @4210984 constant */
    /* @4210988 cmp */
    /* @4210992 bt */
    p4214416_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(67)))) goto L_4214416;
    /* @4210996 dup */
    /* @4211000 constant */
    /* @4211004 cmp */
    /* @4211008 bt */
    p4214456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(68)))) goto L_4214456;
    /* @4211012 dup */
    /* @4211016 constant */
    /* @4211020 cmp */
    /* @4211024 bt */
    p4214496_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(69)))) goto L_4214496;
    /* @4211028 dup */
    /* @4211032 constant */
    /* @4211036 cmp */
    /* @4211040 bt */
    p4214536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(70)))) goto L_4214536;
    /* @4211044 dup */
    /* @4211048 constant */
    /* @4211052 cmp */
    /* @4211056 bt */
    p4214576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(71)))) goto L_4214576;
    /* @4211060 dup */
    /* @4211064 constant */
    /* @4211068 cmp */
    /* @4211072 bt */
    p4214616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(72)))) goto L_4214616;
    /* @4211076 dup */
    /* @4211080 constant */
    /* @4211084 cmp */
    /* @4211088 bt */
    p4214656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(73)))) goto L_4214656;
    /* @4211092 dup */
    /* @4211096 constant */
    /* @4211100 cmp */
    /* @4211104 bt */
    p4214696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(74)))) goto L_4214696;
    /* @4211108 dup */
    /* @4211112 constant */
    /* @4211116 cmp */
    /* @4211120 bt */
    p4214736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(75)))) goto L_4214736;
    /* @4211124 dup */
    /* @4211128 constant */
    /* @4211132 cmp */
    /* @4211136 bt */
    p4214776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(76)))) goto L_4214776;
    /* @4211140 dup */
    /* @4211144 constant */
    /* @4211148 cmp */
    /* @4211152 bt */
    p4214816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(77)))) goto L_4214816;
    /* @4211156 dup */
    /* @4211160 constant */
    /* @4211164 cmp */
    /* @4211168 bt */
    p4214856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(78)))) goto L_4214856;
    /* @4211172 dup */
    /* @4211176 constant */
    /* @4211180 cmp */
    /* @4211184 bt */
    p4214896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(79)))) goto L_4214896;
    /* @4211188 dup */
    /* @4211192 constant */
    /* @4211196 cmp */
    /* @4211200 bt */
    p4214936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(80)))) goto L_4214936;
    /* @4211204 dup */
    /* @4211208 constant */
    /* @4211212 cmp */
    /* @4211216 bt */
    p4214976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(81)))) goto L_4214976;
    /* @4211220 dup */
    /* @4211224 constant */
    /* @4211228 cmp */
    /* @4211232 bt */
    p4215016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_4215016;
    /* @4211236 dup */
    /* @4211240 constant */
    /* @4211244 cmp */
    /* @4211248 bt */
    p4215056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(83)))) goto L_4215056;
    /* @4211252 dup */
    /* @4211256 constant */
    /* @4211260 cmp */
    /* @4211264 bt */
    p4215096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(84)))) goto L_4215096;
    /* @4211268 dup */
    /* @4211272 constant */
    /* @4211276 cmp */
    /* @4211280 bt */
    p4215136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(85)))) goto L_4215136;
    /* @4211284 dup */
    /* @4211288 constant */
    /* @4211292 cmp */
    /* @4211296 bt */
    p4215176_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(86)))) goto L_4215176;
    /* @4211300 dup */
    /* @4211304 constant */
    /* @4211308 cmp */
    /* @4211312 bt */
    p4215216_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(87)))) goto L_4215216;
    /* @4211316 dup */
    /* @4211320 constant */
    /* @4211324 cmp */
    /* @4211328 bt */
    p4215256_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(88)))) goto L_4215256;
    /* @4211332 dup */
    /* @4211336 constant */
    /* @4211340 cmp */
    /* @4211344 bt */
    p4215296_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(89)))) goto L_4215296;
    /* @4211348 dup */
    /* @4211352 constant */
    /* @4211356 cmp */
    /* @4211360 bt */
    p4215336_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(90)))) goto L_4215336;
    /* @4211364 dup */
    /* @4211368 constant */
    /* @4211372 cmp */
    /* @4211376 bt */
    p4215376_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(91)))) goto L_4215376;
    /* @4211380 dup */
    /* @4211384 constant */
    /* @4211388 cmp */
    /* @4211392 bt */
    p4215416_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(92)))) goto L_4215416;
    /* @4211396 dup */
    /* @4211400 constant */
    /* @4211404 cmp */
    /* @4211408 bt */
    p4215456_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(93)))) goto L_4215456;
    /* @4211412 dup */
    /* @4211416 constant */
    /* @4211420 cmp */
    /* @4211424 bt */
    p4215496_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(94)))) goto L_4215496;
    /* @4211428 dup */
    /* @4211432 constant */
    /* @4211436 cmp */
    /* @4211440 bt */
    p4215536_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(95)))) goto L_4215536;
    /* @4211444 dup */
    /* @4211448 constant */
    /* @4211452 cmp */
    /* @4211456 bt */
    p4215576_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(96)))) goto L_4215576;
    /* @4211460 dup */
    /* @4211464 constant */
    /* @4211468 cmp */
    /* @4211472 bt */
    p4215616_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(97)))) goto L_4215616;
    /* @4211476 dup */
    /* @4211480 constant */
    /* @4211484 cmp */
    /* @4211488 bt */
    p4215656_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(98)))) goto L_4215656;
    /* @4211492 dup */
    /* @4211496 constant */
    /* @4211500 cmp */
    /* @4211504 bt */
    p4215696_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(99)))) goto L_4215696;
    /* @4211508 dup */
    /* @4211512 constant */
    /* @4211516 cmp */
    /* @4211520 bt */
    p4215736_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(100)))) goto L_4215736;
    /* @4211524 dup */
    /* @4211528 constant */
    /* @4211532 cmp */
    /* @4211536 bt */
    p4215776_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(101)))) goto L_4215776;
    /* @4211540 dup */
    /* @4211544 constant */
    /* @4211548 cmp */
    /* @4211552 bt */
    p4215816_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(102)))) goto L_4215816;
    /* @4211556 dup */
    /* @4211560 constant */
    /* @4211564 cmp */
    /* @4211568 bt */
    p4215856_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(103)))) goto L_4215856;
    /* @4211572 dup */
    /* @4211576 constant */
    /* @4211580 cmp */
    /* @4211584 bt */
    p4215896_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_4215896;
    /* @4211588 dup */
    /* @4211592 constant */
    /* @4211596 cmp */
    /* @4211600 bt */
    p4215936_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(105)))) goto L_4215936;
    /* @4211604 dup */
    /* @4211608 constant */
    /* @4211612 cmp */
    /* @4211616 bt */
    p4215976_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(106)))) goto L_4215976;
    /* @4211620 dup */
    /* @4211624 constant */
    /* @4211628 cmp */
    /* @4211632 bt */
    p4216016_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(107)))) goto L_4216016;
    /* @4211636 dup */
    /* @4211640 constant */
    /* @4211644 cmp */
    /* @4211648 bt */
    p4216056_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(108)))) goto L_4216056;
    /* @4211652 dup */
    /* @4211656 constant */
    /* @4211660 cmp */
    /* @4211664 bt */
    p4216096_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(109)))) goto L_4216096;
    /* @4211668 dup */
    /* @4211672 constant */
    /* @4211676 cmp */
    /* @4211680 bt */
    p4216136_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(111)))) goto L_4216136;
    /* @4211684 dup */
    /* @4211688 constant */
    /* @4211692 cmp */
    /* @4211696 bt */
    p4216152_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(112)))) goto L_4216152;
    /* @4211700 dup */
    /* @4211704 constant */
    /* @4211708 cmp */
    /* @4211712 bt */
    p4216168_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4216168;
    /* @4211716 dup */
    /* @4211720 constant */
    /* @4211724 cmp */
    /* @4211728 bt */
    p4216184_0 = GM_READ(vm, -1, "room");
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4216184;
    /* @4211732 b */
    p4216200_0 = GM_READ(vm, -1, "room");
    goto L_4216200;
    L_4211736: ;
    /* @4211736 constant */
    /* @4211740 store */
    GM_WRITE(vm, -1, "bg", VAL(5));
    /* @4211748 constant */
    /* @4211752 store */
    GM_WRITE(vm, -5, "startx", VAL(416));
    /* @4211760 constant */
    /* @4211764 store */
    GM_WRITE(vm, -5, "starty", VAL(492));
    /* @4211772 b */
    p4216200_0 = p4211736_0;
    goto L_4216200;
    L_4211776: ;
    /* @4211776 constant */
    /* @4211780 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4211788 constant */
    /* @4211792 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4211800 constant */
    /* @4211804 store */
    GM_WRITE(vm, -5, "starty", VAL(492));
    /* @4211812 b */
    p4216200_0 = p4211776_0;
    goto L_4216200;
    L_4211816: ;
    /* @4211816 constant */
    /* @4211820 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4211828 constant */
    /* @4211832 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4211840 constant */
    /* @4211844 store */
    GM_WRITE(vm, -5, "starty", VAL(492));
    /* @4211852 b */
    p4216200_0 = p4211816_0;
    goto L_4216200;
    L_4211856: ;
    /* @4211856 constant */
    /* @4211860 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4211868 constant */
    /* @4211872 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4211880 constant */
    /* @4211884 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4211892 b */
    p4216200_0 = p4211856_0;
    goto L_4216200;
    L_4211896: ;
    /* @4211896 constant */
    /* @4211900 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4211908 constant */
    /* @4211912 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4211920 constant */
    /* @4211924 store */
    GM_WRITE(vm, -5, "starty", VAL(524));
    /* @4211932 b */
    p4216200_0 = p4211896_0;
    goto L_4216200;
    L_4211936: ;
    /* @4211936 constant */
    /* @4211940 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4211948 constant */
    /* @4211952 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4211960 constant */
    /* @4211964 store */
    GM_WRITE(vm, -5, "starty", VAL(300));
    /* @4211972 b */
    p4216200_0 = p4211936_0;
    goto L_4216200;
    L_4211976: ;
    /* @4211976 constant */
    /* @4211980 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4211988 constant */
    /* @4211992 store */
    GM_WRITE(vm, -5, "startx", VAL(1856));
    /* @4212000 constant */
    /* @4212004 store */
    GM_WRITE(vm, -5, "starty", VAL(1164));
    /* @4212012 b */
    p4216200_0 = p4211976_0;
    goto L_4216200;
    L_4212016: ;
    /* @4212016 constant */
    /* @4212020 store */
    GM_WRITE(vm, -1, "bg", VAL(0));
    /* @4212028 constant */
    /* @4212032 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212040 constant */
    /* @4212044 store */
    GM_WRITE(vm, -5, "starty", VAL(364));
    /* @4212052 b */
    p4216200_0 = p4212016_0;
    goto L_4216200;
    L_4212056: ;
    /* @4212056 constant */
    /* @4212060 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212068 constant */
    /* @4212072 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212080 constant */
    /* @4212084 store */
    GM_WRITE(vm, -5, "starty", VAL(428));
    /* @4212092 b */
    p4216200_0 = p4212056_0;
    goto L_4216200;
    L_4212096: ;
    /* @4212096 constant */
    /* @4212100 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212108 constant */
    /* @4212112 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212120 constant */
    /* @4212124 store */
    GM_WRITE(vm, -5, "starty", VAL(1132));
    /* @4212132 b */
    p4216200_0 = p4212096_0;
    goto L_4216200;
    L_4212136: ;
    /* @4212136 constant */
    /* @4212140 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4212148 constant */
    /* @4212152 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212160 constant */
    /* @4212164 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4212172 b */
    p4216200_0 = p4212136_0;
    goto L_4216200;
    L_4212176: ;
    /* @4212176 constant */
    /* @4212180 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4212188 constant */
    /* @4212192 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212200 constant */
    /* @4212204 store */
    GM_WRITE(vm, -5, "starty", VAL(524));
    /* @4212212 b */
    p4216200_0 = p4212176_0;
    goto L_4216200;
    L_4212216: ;
    /* @4212216 constant */
    /* @4212220 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212228 constant */
    /* @4212232 store */
    GM_WRITE(vm, -5, "startx", VAL(224));
    /* @4212240 constant */
    /* @4212244 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4212252 b */
    p4216200_0 = p4212216_0;
    goto L_4216200;
    L_4212256: ;
    /* @4212256 constant */
    /* @4212260 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212268 constant */
    /* @4212272 store */
    GM_WRITE(vm, -5, "startx", VAL(1888));
    /* @4212280 constant */
    /* @4212284 store */
    GM_WRITE(vm, -5, "starty", VAL(172));
    /* @4212292 b */
    p4216200_0 = p4212256_0;
    goto L_4216200;
    L_4212296: ;
    /* @4212296 constant */
    /* @4212300 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4212308 constant */
    /* @4212312 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212320 constant */
    /* @4212324 store */
    GM_WRITE(vm, -5, "starty", VAL(1164));
    /* @4212332 b */
    p4216200_0 = p4212296_0;
    goto L_4216200;
    L_4212336: ;
    /* @4212336 constant */
    /* @4212340 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4212348 constant */
    /* @4212352 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212360 constant */
    /* @4212364 store */
    GM_WRITE(vm, -5, "starty", VAL(172));
    /* @4212372 b */
    p4216200_0 = p4212336_0;
    goto L_4216200;
    L_4212376: ;
    /* @4212376 constant */
    /* @4212380 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212388 constant */
    /* @4212392 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212400 constant */
    /* @4212404 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212412 b */
    p4216200_0 = p4212376_0;
    goto L_4216200;
    L_4212416: ;
    /* @4212416 constant */
    /* @4212420 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212428 constant */
    /* @4212432 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212440 constant */
    /* @4212444 store */
    GM_WRITE(vm, -5, "starty", VAL(268));
    /* @4212452 b */
    p4216200_0 = p4212416_0;
    goto L_4216200;
    L_4212456: ;
    /* @4212456 constant */
    /* @4212460 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4212468 constant */
    /* @4212472 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212480 constant */
    /* @4212484 store */
    GM_WRITE(vm, -5, "starty", VAL(236));
    /* @4212492 b */
    p4216200_0 = p4212456_0;
    goto L_4216200;
    L_4212496: ;
    /* @4212496 constant */
    /* @4212500 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4212508 constant */
    /* @4212512 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212520 constant */
    /* @4212524 store */
    GM_WRITE(vm, -5, "starty", VAL(236));
    /* @4212532 b */
    p4216200_0 = p4212496_0;
    goto L_4216200;
    L_4212536: ;
    /* @4212536 constant */
    /* @4212540 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212548 constant */
    /* @4212552 store */
    GM_WRITE(vm, -5, "startx", VAL(256));
    /* @4212560 constant */
    /* @4212564 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212572 b */
    p4216200_0 = p4212536_0;
    goto L_4216200;
    L_4212576: ;
    /* @4212576 constant */
    /* @4212580 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212588 constant */
    /* @4212592 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212600 constant */
    /* @4212604 store */
    GM_WRITE(vm, -5, "starty", VAL(684));
    /* @4212612 b */
    p4216200_0 = p4212576_0;
    goto L_4216200;
    L_4212616: ;
    /* @4212616 constant */
    /* @4212620 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4212628 constant */
    /* @4212632 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212640 constant */
    /* @4212644 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212652 b */
    p4216200_0 = p4212616_0;
    goto L_4216200;
    L_4212656: ;
    /* @4212656 constant */
    /* @4212660 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4212668 constant */
    /* @4212672 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212680 constant */
    /* @4212684 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212692 b */
    p4216200_0 = p4212656_0;
    goto L_4216200;
    L_4212696: ;
    /* @4212696 constant */
    /* @4212700 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212708 constant */
    /* @4212712 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212720 constant */
    /* @4212724 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4212732 b */
    p4216200_0 = p4212696_0;
    goto L_4216200;
    L_4212736: ;
    /* @4212736 constant */
    /* @4212740 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4212748 constant */
    /* @4212752 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212760 constant */
    /* @4212764 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212772 b */
    p4216200_0 = p4212736_0;
    goto L_4216200;
    L_4212776: ;
    /* @4212776 constant */
    /* @4212780 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212788 constant */
    /* @4212792 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212800 constant */
    /* @4212804 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212812 b */
    p4216200_0 = p4212776_0;
    goto L_4216200;
    L_4212816: ;
    /* @4212816 constant */
    /* @4212820 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4212828 constant */
    /* @4212832 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212840 constant */
    /* @4212844 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4212852 b */
    p4216200_0 = p4212816_0;
    goto L_4216200;
    L_4212856: ;
    /* @4212856 constant */
    /* @4212860 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4212868 constant */
    /* @4212872 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212880 constant */
    /* @4212884 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4212892 b */
    p4216200_0 = p4212856_0;
    goto L_4216200;
    L_4212896: ;
    /* @4212896 constant */
    /* @4212900 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4212908 constant */
    /* @4212912 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212920 constant */
    /* @4212924 store */
    GM_WRITE(vm, -5, "starty", VAL(236));
    /* @4212932 b */
    p4216200_0 = p4212896_0;
    goto L_4216200;
    L_4212936: ;
    /* @4212936 constant */
    /* @4212940 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4212948 constant */
    /* @4212952 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4212960 constant */
    /* @4212964 store */
    GM_WRITE(vm, -5, "starty", VAL(1164));
    /* @4212972 b */
    p4216200_0 = p4212936_0;
    goto L_4216200;
    L_4212976: ;
    /* @4212976 constant */
    /* @4212980 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4212988 constant */
    /* @4212992 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213000 constant */
    /* @4213004 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213012 b */
    p4216200_0 = p4212976_0;
    goto L_4216200;
    L_4213016: ;
    /* @4213016 constant */
    /* @4213020 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213028 constant */
    /* @4213032 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213040 constant */
    /* @4213044 store */
    GM_WRITE(vm, -5, "starty", VAL(268));
    /* @4213052 b */
    p4216200_0 = p4213016_0;
    goto L_4216200;
    L_4213056: ;
    /* @4213056 constant */
    /* @4213060 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4213068 constant */
    /* @4213072 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213080 constant */
    /* @4213084 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213092 b */
    p4216200_0 = p4213056_0;
    goto L_4216200;
    L_4213096: ;
    /* @4213096 constant */
    /* @4213100 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4213108 constant */
    /* @4213112 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213120 constant */
    /* @4213124 store */
    GM_WRITE(vm, -5, "starty", VAL(1932));
    /* @4213132 b */
    p4216200_0 = p4213096_0;
    goto L_4216200;
    L_4213136: ;
    /* @4213136 constant */
    /* @4213140 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4213148 constant */
    /* @4213152 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213160 constant */
    /* @4213164 store */
    GM_WRITE(vm, -5, "starty", VAL(428));
    /* @4213172 b */
    p4216200_0 = p4213136_0;
    goto L_4216200;
    L_4213176: ;
    /* @4213176 constant */
    /* @4213180 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213188 constant */
    /* @4213192 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213200 constant */
    /* @4213204 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213212 b */
    p4216200_0 = p4213176_0;
    goto L_4216200;
    L_4213216: ;
    /* @4213216 constant */
    /* @4213220 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4213228 constant */
    /* @4213232 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213240 constant */
    /* @4213244 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4213252 b */
    p4216200_0 = p4213216_0;
    goto L_4216200;
    L_4213256: ;
    /* @4213256 constant */
    /* @4213260 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4213268 constant */
    /* @4213272 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213280 constant */
    /* @4213284 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213292 b */
    p4216200_0 = p4213256_0;
    goto L_4216200;
    L_4213296: ;
    /* @4213296 constant */
    /* @4213300 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4213308 constant */
    /* @4213312 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213320 constant */
    /* @4213324 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213332 b */
    p4216200_0 = p4213296_0;
    goto L_4216200;
    L_4213336: ;
    /* @4213336 constant */
    /* @4213340 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4213348 constant */
    /* @4213352 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213360 constant */
    /* @4213364 store */
    GM_WRITE(vm, -5, "starty", VAL(1164));
    /* @4213372 b */
    p4216200_0 = p4213336_0;
    goto L_4216200;
    L_4213376: ;
    /* @4213376 constant */
    /* @4213380 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213388 constant */
    /* @4213392 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213400 constant */
    /* @4213404 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213412 b */
    p4216200_0 = p4213376_0;
    goto L_4216200;
    L_4213416: ;
    /* @4213416 constant */
    /* @4213420 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4213428 constant */
    /* @4213432 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213440 constant */
    /* @4213444 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213452 b */
    p4216200_0 = p4213416_0;
    goto L_4216200;
    L_4213456: ;
    /* @4213456 constant */
    /* @4213460 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213468 constant */
    /* @4213472 store */
    GM_WRITE(vm, -5, "startx", VAL(544));
    /* @4213480 constant */
    /* @4213484 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213492 b */
    p4216200_0 = p4213456_0;
    goto L_4216200;
    L_4213496: ;
    /* @4213496 constant */
    /* @4213500 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4213508 constant */
    /* @4213512 store */
    GM_WRITE(vm, -5, "startx", VAL(1120));
    /* @4213520 constant */
    /* @4213524 store */
    GM_WRITE(vm, -5, "starty", VAL(76));
    /* @4213532 b */
    p4216200_0 = p4213496_0;
    goto L_4216200;
    L_4213536: ;
    /* @4213536 constant */
    /* @4213540 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4213548 constant */
    /* @4213552 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213560 constant */
    /* @4213564 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213572 b */
    p4216200_0 = p4213536_0;
    goto L_4216200;
    L_4213576: ;
    /* @4213576 constant */
    /* @4213580 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213588 constant */
    /* @4213592 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213600 constant */
    /* @4213604 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4213612 b */
    p4216200_0 = p4213576_0;
    goto L_4216200;
    L_4213616: ;
    /* @4213616 constant */
    /* @4213620 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4213628 constant */
    /* @4213632 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213640 constant */
    /* @4213644 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4213652 b */
    p4216200_0 = p4213616_0;
    goto L_4216200;
    L_4213656: ;
    /* @4213656 constant */
    /* @4213660 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4213668 constant */
    /* @4213672 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213680 constant */
    /* @4213684 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4213692 b */
    p4216200_0 = p4213656_0;
    goto L_4216200;
    L_4213696: ;
    /* @4213696 constant */
    /* @4213700 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4213708 constant */
    /* @4213712 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213720 constant */
    /* @4213724 store */
    GM_WRITE(vm, -5, "starty", VAL(300));
    /* @4213732 b */
    p4216200_0 = p4213696_0;
    goto L_4216200;
    L_4213736: ;
    /* @4213736 constant */
    /* @4213740 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4213748 constant */
    /* @4213752 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213760 constant */
    /* @4213764 store */
    GM_WRITE(vm, -5, "starty", VAL(268));
    /* @4213772 b */
    p4216200_0 = p4213736_0;
    goto L_4216200;
    L_4213776: ;
    /* @4213776 constant */
    /* @4213780 store */
    GM_WRITE(vm, -1, "bg", VAL(0));
    /* @4213788 constant */
    /* @4213792 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213800 constant */
    /* @4213804 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4213812 b */
    p4216200_0 = p4213776_0;
    goto L_4216200;
    L_4213816: ;
    /* @4213816 constant */
    /* @4213820 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4213828 constant */
    /* @4213832 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213840 constant */
    /* @4213844 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213852 b */
    p4216200_0 = p4213816_0;
    goto L_4216200;
    L_4213856: ;
    /* @4213856 constant */
    /* @4213860 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4213868 constant */
    /* @4213872 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213880 constant */
    /* @4213884 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4213892 b */
    p4216200_0 = p4213856_0;
    goto L_4216200;
    L_4213896: ;
    /* @4213896 constant */
    /* @4213900 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4213908 constant */
    /* @4213912 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4213920 constant */
    /* @4213924 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4213932 b */
    p4216200_0 = p4213896_0;
    goto L_4216200;
    L_4213936: ;
    /* @4213936 constant */
    /* @4213940 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4213948 constant */
    /* @4213952 store */
    GM_WRITE(vm, -5, "startx", VAL(608));
    /* @4213960 constant */
    /* @4213964 store */
    GM_WRITE(vm, -5, "starty", VAL(556));
    /* @4213972 b */
    p4216200_0 = p4213936_0;
    goto L_4216200;
    L_4213976: ;
    /* @4213976 constant */
    /* @4213980 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4213988 constant */
    /* @4213992 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214000 constant */
    /* @4214004 store */
    GM_WRITE(vm, -5, "starty", VAL(300));
    /* @4214012 b */
    p4216200_0 = p4213976_0;
    goto L_4216200;
    L_4214016: ;
    /* @4214016 constant */
    /* @4214020 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214028 constant */
    /* @4214032 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214040 constant */
    /* @4214044 store */
    GM_WRITE(vm, -5, "starty", VAL(364));
    /* @4214052 b */
    p4216200_0 = p4214016_0;
    goto L_4216200;
    L_4214056: ;
    /* @4214056 constant */
    /* @4214060 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214068 constant */
    /* @4214072 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214080 constant */
    /* @4214084 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214092 b */
    p4216200_0 = p4214056_0;
    goto L_4216200;
    L_4214096: ;
    /* @4214096 constant */
    /* @4214100 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4214108 constant */
    /* @4214112 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214120 constant */
    /* @4214124 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214132 b */
    p4216200_0 = p4214096_0;
    goto L_4216200;
    L_4214136: ;
    /* @4214136 constant */
    /* @4214140 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214148 constant */
    /* @4214152 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214160 constant */
    /* @4214164 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4214172 b */
    p4216200_0 = p4214136_0;
    goto L_4216200;
    L_4214176: ;
    /* @4214176 constant */
    /* @4214180 store */
    GM_WRITE(vm, -1, "bg", VAL(0));
    /* @4214188 constant */
    /* @4214192 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214200 constant */
    /* @4214204 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4214212 b */
    p4216200_0 = p4214176_0;
    goto L_4216200;
    L_4214216: ;
    /* @4214216 constant */
    /* @4214220 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214228 constant */
    /* @4214232 store */
    GM_WRITE(vm, -5, "startx", VAL(1664));
    /* @4214240 constant */
    /* @4214244 store */
    GM_WRITE(vm, -5, "starty", VAL(620));
    /* @4214252 b */
    p4216200_0 = p4214216_0;
    goto L_4216200;
    L_4214256: ;
    /* @4214256 constant */
    /* @4214260 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214268 constant */
    /* @4214272 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214280 constant */
    /* @4214284 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214292 b */
    p4216200_0 = p4214256_0;
    goto L_4216200;
    L_4214296: ;
    /* @4214296 constant */
    /* @4214300 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4214308 constant */
    /* @4214312 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214320 constant */
    /* @4214324 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4214332 b */
    p4216200_0 = p4214296_0;
    goto L_4216200;
    L_4214336: ;
    /* @4214336 constant */
    /* @4214340 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214348 constant */
    /* @4214352 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214360 constant */
    /* @4214364 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4214372 b */
    p4216200_0 = p4214336_0;
    goto L_4216200;
    L_4214376: ;
    /* @4214376 constant */
    /* @4214380 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214388 constant */
    /* @4214392 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214400 constant */
    /* @4214404 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214412 b */
    p4216200_0 = p4214376_0;
    goto L_4216200;
    L_4214416: ;
    /* @4214416 constant */
    /* @4214420 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4214428 constant */
    /* @4214432 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214440 constant */
    /* @4214444 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4214452 b */
    p4216200_0 = p4214416_0;
    goto L_4216200;
    L_4214456: ;
    /* @4214456 constant */
    /* @4214460 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214468 constant */
    /* @4214472 store */
    GM_WRITE(vm, -5, "startx", VAL(640));
    /* @4214480 constant */
    /* @4214484 store */
    GM_WRITE(vm, -5, "starty", VAL(364));
    /* @4214492 b */
    p4216200_0 = p4214456_0;
    goto L_4216200;
    L_4214496: ;
    /* @4214496 constant */
    /* @4214500 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214508 constant */
    /* @4214512 store */
    GM_WRITE(vm, -5, "startx", VAL(1888));
    /* @4214520 constant */
    /* @4214524 store */
    GM_WRITE(vm, -5, "starty", VAL(172));
    /* @4214532 b */
    p4216200_0 = p4214496_0;
    goto L_4216200;
    L_4214536: ;
    /* @4214536 constant */
    /* @4214540 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4214548 constant */
    /* @4214552 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214560 constant */
    /* @4214564 store */
    GM_WRITE(vm, -5, "starty", VAL(684));
    /* @4214572 b */
    p4216200_0 = p4214536_0;
    goto L_4216200;
    L_4214576: ;
    /* @4214576 constant */
    /* @4214580 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214588 constant */
    /* @4214592 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214600 constant */
    /* @4214604 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214612 b */
    p4216200_0 = p4214576_0;
    goto L_4216200;
    L_4214616: ;
    /* @4214616 constant */
    /* @4214620 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214628 constant */
    /* @4214632 store */
    GM_WRITE(vm, -5, "startx", VAL(448));
    /* @4214640 constant */
    /* @4214644 store */
    GM_WRITE(vm, -5, "starty", VAL(684));
    /* @4214652 b */
    p4216200_0 = p4214616_0;
    goto L_4216200;
    L_4214656: ;
    /* @4214656 constant */
    /* @4214660 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214668 constant */
    /* @4214672 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214680 constant */
    /* @4214684 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4214692 b */
    p4216200_0 = p4214656_0;
    goto L_4216200;
    L_4214696: ;
    /* @4214696 constant */
    /* @4214700 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4214708 constant */
    /* @4214712 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214720 constant */
    /* @4214724 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214732 b */
    p4216200_0 = p4214696_0;
    goto L_4216200;
    L_4214736: ;
    /* @4214736 constant */
    /* @4214740 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214748 constant */
    /* @4214752 store */
    GM_WRITE(vm, -5, "startx", VAL(672));
    /* @4214760 constant */
    /* @4214764 store */
    GM_WRITE(vm, -5, "starty", VAL(684));
    /* @4214772 b */
    p4216200_0 = p4214736_0;
    goto L_4216200;
    L_4214776: ;
    /* @4214776 constant */
    /* @4214780 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214788 constant */
    /* @4214792 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214800 constant */
    /* @4214804 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214812 b */
    p4216200_0 = p4214776_0;
    goto L_4216200;
    L_4214816: ;
    /* @4214816 constant */
    /* @4214820 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214828 constant */
    /* @4214832 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214840 constant */
    /* @4214844 store */
    GM_WRITE(vm, -5, "starty", VAL(172));
    /* @4214852 b */
    p4216200_0 = p4214816_0;
    goto L_4216200;
    L_4214856: ;
    /* @4214856 constant */
    /* @4214860 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4214868 constant */
    /* @4214872 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214880 constant */
    /* @4214884 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4214892 b */
    p4216200_0 = p4214856_0;
    goto L_4216200;
    L_4214896: ;
    /* @4214896 constant */
    /* @4214900 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4214908 constant */
    /* @4214912 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214920 constant */
    /* @4214924 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214932 b */
    p4216200_0 = p4214896_0;
    goto L_4216200;
    L_4214936: ;
    /* @4214936 constant */
    /* @4214940 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4214948 constant */
    /* @4214952 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4214960 constant */
    /* @4214964 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4214972 b */
    p4216200_0 = p4214936_0;
    goto L_4216200;
    L_4214976: ;
    /* @4214976 constant */
    /* @4214980 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4214988 constant */
    /* @4214992 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215000 constant */
    /* @4215004 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215012 b */
    p4216200_0 = p4214976_0;
    goto L_4216200;
    L_4215016: ;
    /* @4215016 constant */
    /* @4215020 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4215028 constant */
    /* @4215032 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215040 constant */
    /* @4215044 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4215052 b */
    p4216200_0 = p4215016_0;
    goto L_4216200;
    L_4215056: ;
    /* @4215056 constant */
    /* @4215060 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215068 constant */
    /* @4215072 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215080 constant */
    /* @4215084 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215092 b */
    p4216200_0 = p4215056_0;
    goto L_4216200;
    L_4215096: ;
    /* @4215096 constant */
    /* @4215100 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215108 constant */
    /* @4215112 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215120 constant */
    /* @4215124 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4215132 b */
    p4216200_0 = p4215096_0;
    goto L_4216200;
    L_4215136: ;
    /* @4215136 constant */
    /* @4215140 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215148 constant */
    /* @4215152 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215160 constant */
    /* @4215164 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215172 b */
    p4216200_0 = p4215136_0;
    goto L_4216200;
    L_4215176: ;
    /* @4215176 constant */
    /* @4215180 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4215188 constant */
    /* @4215192 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215200 constant */
    /* @4215204 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215212 b */
    p4216200_0 = p4215176_0;
    goto L_4216200;
    L_4215216: ;
    /* @4215216 constant */
    /* @4215220 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215228 constant */
    /* @4215232 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215240 constant */
    /* @4215244 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215252 b */
    p4216200_0 = p4215216_0;
    goto L_4216200;
    L_4215256: ;
    /* @4215256 constant */
    /* @4215260 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215268 constant */
    /* @4215272 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215280 constant */
    /* @4215284 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215292 b */
    p4216200_0 = p4215256_0;
    goto L_4216200;
    L_4215296: ;
    /* @4215296 constant */
    /* @4215300 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215308 constant */
    /* @4215312 store */
    GM_WRITE(vm, -5, "startx", VAL(1888));
    /* @4215320 constant */
    /* @4215324 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215332 b */
    p4216200_0 = p4215296_0;
    goto L_4216200;
    L_4215336: ;
    /* @4215336 constant */
    /* @4215340 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4215348 constant */
    /* @4215352 store */
    GM_WRITE(vm, -5, "startx", VAL(640));
    /* @4215360 constant */
    /* @4215364 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4215372 b */
    p4216200_0 = p4215336_0;
    goto L_4216200;
    L_4215376: ;
    /* @4215376 constant */
    /* @4215380 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215388 constant */
    /* @4215392 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215400 constant */
    /* @4215404 store */
    GM_WRITE(vm, -5, "starty", VAL(76));
    /* @4215412 b */
    p4216200_0 = p4215376_0;
    goto L_4216200;
    L_4215416: ;
    /* @4215416 constant */
    /* @4215420 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215428 constant */
    /* @4215432 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215440 constant */
    /* @4215444 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4215452 b */
    p4216200_0 = p4215416_0;
    goto L_4216200;
    L_4215456: ;
    /* @4215456 constant */
    /* @4215460 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215468 constant */
    /* @4215472 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215480 constant */
    /* @4215484 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4215492 b */
    p4216200_0 = p4215456_0;
    goto L_4216200;
    L_4215496: ;
    /* @4215496 constant */
    /* @4215500 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215508 constant */
    /* @4215512 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215520 constant */
    /* @4215524 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4215532 b */
    p4216200_0 = p4215496_0;
    goto L_4216200;
    L_4215536: ;
    /* @4215536 constant */
    /* @4215540 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215548 constant */
    /* @4215552 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215560 constant */
    /* @4215564 store */
    GM_WRITE(vm, -5, "starty", VAL(108));
    /* @4215572 b */
    p4216200_0 = p4215536_0;
    goto L_4216200;
    L_4215576: ;
    /* @4215576 constant */
    /* @4215580 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215588 constant */
    /* @4215592 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215600 constant */
    /* @4215604 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215612 b */
    p4216200_0 = p4215576_0;
    goto L_4216200;
    L_4215616: ;
    /* @4215616 constant */
    /* @4215620 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215628 constant */
    /* @4215632 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215640 constant */
    /* @4215644 store */
    GM_WRITE(vm, -5, "starty", VAL(172));
    /* @4215652 b */
    p4216200_0 = p4215616_0;
    goto L_4216200;
    L_4215656: ;
    /* @4215656 constant */
    /* @4215660 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215668 constant */
    /* @4215672 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215680 constant */
    /* @4215684 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215692 b */
    p4216200_0 = p4215656_0;
    goto L_4216200;
    L_4215696: ;
    /* @4215696 constant */
    /* @4215700 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4215708 constant */
    /* @4215712 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215720 constant */
    /* @4215724 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215732 b */
    p4216200_0 = p4215696_0;
    goto L_4216200;
    L_4215736: ;
    /* @4215736 constant */
    /* @4215740 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215748 constant */
    /* @4215752 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215760 constant */
    /* @4215764 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215772 b */
    p4216200_0 = p4215736_0;
    goto L_4216200;
    L_4215776: ;
    /* @4215776 constant */
    /* @4215780 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215788 constant */
    /* @4215792 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215800 constant */
    /* @4215804 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215812 b */
    p4216200_0 = p4215776_0;
    goto L_4216200;
    L_4215816: ;
    /* @4215816 constant */
    /* @4215820 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4215828 constant */
    /* @4215832 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215840 constant */
    /* @4215844 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215852 b */
    p4216200_0 = p4215816_0;
    goto L_4216200;
    L_4215856: ;
    /* @4215856 constant */
    /* @4215860 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4215868 constant */
    /* @4215872 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215880 constant */
    /* @4215884 store */
    GM_WRITE(vm, -5, "starty", VAL(204));
    /* @4215892 b */
    p4216200_0 = p4215856_0;
    goto L_4216200;
    L_4215896: ;
    /* @4215896 constant */
    /* @4215900 store */
    GM_WRITE(vm, -1, "bg", VAL(6));
    /* @4215908 constant */
    /* @4215912 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215920 constant */
    /* @4215924 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4215932 b */
    p4216200_0 = p4215896_0;
    goto L_4216200;
    L_4215936: ;
    /* @4215936 constant */
    /* @4215940 store */
    GM_WRITE(vm, -1, "bg", VAL(2));
    /* @4215948 constant */
    /* @4215952 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4215960 constant */
    /* @4215964 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4215972 b */
    p4216200_0 = p4215936_0;
    goto L_4216200;
    L_4215976: ;
    /* @4215976 constant */
    /* @4215980 store */
    GM_WRITE(vm, -1, "bg", VAL(1));
    /* @4215988 constant */
    /* @4215992 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4216000 constant */
    /* @4216004 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4216012 b */
    p4216200_0 = p4215976_0;
    goto L_4216200;
    L_4216016: ;
    /* @4216016 constant */
    /* @4216020 store */
    GM_WRITE(vm, -1, "bg", VAL(4));
    /* @4216028 constant */
    /* @4216032 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4216040 constant */
    /* @4216044 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4216052 b */
    p4216200_0 = p4216016_0;
    goto L_4216200;
    L_4216056: ;
    /* @4216056 constant */
    /* @4216060 store */
    GM_WRITE(vm, -1, "bg", VAL(3));
    /* @4216068 constant */
    /* @4216072 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4216080 constant */
    /* @4216084 store */
    GM_WRITE(vm, -5, "starty", VAL(140));
    /* @4216092 b */
    p4216200_0 = p4216056_0;
    goto L_4216200;
    L_4216096: ;
    /* @4216096 constant */
    /* @4216100 store */
    GM_WRITE(vm, -1, "bg", VAL(7));
    /* @4216108 constant */
    /* @4216112 store */
    GM_WRITE(vm, -5, "startx", VAL(128));
    /* @4216120 constant */
    /* @4216124 store */
    GM_WRITE(vm, -5, "starty", VAL(428));
    /* @4216132 b */
    p4216200_0 = p4216096_0;
    goto L_4216200;
    L_4216136: ;
    /* @4216136 constant */
    /* @4216140 store */
    GM_WRITE(vm, -1, "bg", VAL(5));
    /* @4216148 b */
    p4216200_0 = p4216136_0;
    goto L_4216200;
    L_4216152: ;
    /* @4216152 constant */
    /* @4216156 store */
    GM_WRITE(vm, -1, "bg", VAL(5));
    /* @4216164 b */
    p4216200_0 = p4216152_0;
    goto L_4216200;
    L_4216168: ;
    /* @4216168 constant */
    /* @4216172 store */
    GM_WRITE(vm, -1, "bg", VAL(5));
    /* @4216180 b */
    p4216200_0 = p4216168_0;
    goto L_4216200;
    L_4216184: ;
    /* @4216184 constant */
    /* @4216188 store */
    GM_WRITE(vm, -1, "bg", VAL(5));
    /* @4216196 b */
    p4216200_0 = p4216184_0;
    goto L_4216200;
    L_4216200: ;
    /* @4216200 popz */
    L_4216204: ;
    return;
}
