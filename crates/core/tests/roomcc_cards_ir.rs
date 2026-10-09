//! The complete RoomCC creation-code population: all 551 shipped card bodies
//! (218 obj_warpanywhere door cards, 330 obj_maptile fog cards, the two
//! rm_ending cast binds CODE 1022/1023, and the one EMPTY card CODE 866)
//! execute under the VM with their shipped field effects asserted - the
//! census's largest never-named block (373 RoomCC ids) becomes named evidence
//! in one sweep. The expected table is generated straight from the bundle's
//! bytecode (constant -> store warproom/warpx/warpy/unlocked; load
//! <flag>visited -> cmp -> instance_destroy -> store goto), never from room
//! names.
//!
//! Semantics pinned here that no suite owned before:
//! - every door card stores `unlocked` except CODE 803 (rm_town -> rm_level16,
//!   the one locked secret door: the field keeps its 0 default - matching the
//!   asset inspector's `unlocked=false` row);
//! - every fog card reads as `if (!visited) instance_destroy(); goto = N;` -
//!   the bf lands ON the store, so `goto` is written unconditionally and the
//!   destroyed tile still carries it (dead fields remain readable); the card
//!   pairs are run both ways per tile;
//! - the card is dispatched on a live instance of ITS OWN placement object via
//!   code_vm::execute, the same entry load_room_from_data uses.
use callys_core::code_vm::{execute, load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const WARP: i32 = 69;
const MAPTILE: i32 = 160;

// (code, room, warproom, warpx, warpy, shipped_unlocked)
const DOORS: [(i32, &str, f64, f64, f64, f64); 218] = [
    (803, "rm_town", 23.0, 64.0, 384.0, 0.0), // CODE 803
    (804, "rm_town", 1.0, 128.0, 492.0, 1.0), // CODE 804
    (805, "rm_level1", 2.0, 128.0, 492.0, 1.0), // CODE 805
    (806, "rm_level1", 0.0, 832.0, 480.0, 1.0), // CODE 806
    (807, "rm_level2", 3.0, 128.0, 140.0, 1.0), // CODE 807
    (808, "rm_level2", 1.0, 1856.0, 1164.0, 1.0), // CODE 808
    (809, "rm_level3", 2.0, 1888.0, 1164.0, 1.0), // CODE 809
    (810, "rm_level3", 4.0, 128.0, 524.0, 1.0), // CODE 810
    (811, "rm_level4", 3.0, 1824.0, 492.0, 1.0), // CODE 811
    (812, "rm_level4", 5.0, 160.0, 300.0, 1.0), // CODE 812
    (813, "rm_level5", 4.0, 1888.0, 524.0, 1.0), // CODE 813
    (814, "rm_level5", 6.0, 1856.0, 1164.0, 1.0), // CODE 814
    (815, "rm_level5", 7.0, 128.0, 364.0, 1.0), // CODE 815
    (816, "rm_level6", 5.0, 128.0, 1164.0, 1.0), // CODE 816
    (817, "rm_level7", 5.0, 1888.0, 1164.0, 1.0), // CODE 817
    (818, "rm_level7", 8.0, 160.0, 428.0, 1.0), // CODE 818
    (819, "rm_level8", 7.0, 1888.0, 140.0, 1.0), // CODE 819
    (820, "rm_level8", 9.0, 128.0, 1132.0, 1.0), // CODE 820
    (821, "rm_level8a", 10.0, 160.0, 140.0, 1.0), // CODE 821
    (822, "rm_level8a", 8.0, 1888.0, 236.0, 1.0), // CODE 822
    (823, "rm_boss1", 9.0, 1888.0, 1164.0, 1.0), // CODE 823
    (824, "rm_boss1", 11.0, 128.0, 524.0, 1.0), // CODE 824
    (825, "rm_level9", 10.0, 1120.0, 364.0, 1.0), // CODE 825
    (826, "rm_level9", 12.0, 224.0, 140.0, 1.0), // CODE 826
    (827, "rm_level9a", 13.0, 1888.0, 172.0, 1.0), // CODE 827
    (828, "rm_level9a", 11.0, 1920.0, 204.0, 1.0), // CODE 828
    (829, "rm_level10", 12.0, 128.0, 1164.0, 1.0), // CODE 829
    (830, "rm_level10", 14.0, 160.0, 1164.0, 1.0), // CODE 830
    (831, "rm_level11", 13.0, 1888.0, 492.0, 1.0), // CODE 831
    (832, "rm_level11", 15.0, 128.0, 172.0, 1.0), // CODE 832
    (833, "rm_level11a", 14.0, 864.0, 172.0, 1.0), // CODE 833
    (834, "rm_level11a", 16.0, 128.0, 204.0, 1.0), // CODE 834
    (835, "rm_level12", 15.0, 1856.0, 1164.0, 1.0), // CODE 835
    (836, "rm_level12", 17.0, 128.0, 268.0, 1.0), // CODE 836
    (837, "rm_level13", 16.0, 1888.0, 524.0, 1.0), // CODE 837
    (838, "rm_level13", 18.0, 128.0, 236.0, 1.0), // CODE 838
    (839, "rm_level13a", 19.0, 128.0, 236.0, 1.0), // CODE 839
    (840, "rm_level13a", 17.0, 864.0, 1164.0, 1.0), // CODE 840
    (841, "rm_level14", 18.0, 1888.0, 524.0, 1.0), // CODE 841
    (842, "rm_level14", 20.0, 256.0, 204.0, 1.0), // CODE 842
    (843, "rm_level14a", 21.0, 160.0, 684.0, 1.0), // CODE 843
    (844, "rm_level14a", 19.0, 512.0, 1420.0, 1.0), // CODE 844
    (845, "rm_level15", 20.0, 1856.0, 364.0, 1.0), // CODE 845
    (846, "rm_level15", 22.0, 128.0, 204.0, 1.0), // CODE 846
    (847, "rm_level15a", 23.0, 128.0, 204.0, 1.0), // CODE 847
    (848, "rm_level15a", 21.0, 1888.0, 684.0, 1.0), // CODE 848
    (849, "rm_level16", 22.0, 1888.0, 364.0, 1.0), // CODE 849
    (850, "rm_level16", 24.0, 128.0, 108.0, 1.0), // CODE 850
    (851, "rm_level16a", 25.0, 128.0, 204.0, 1.0), // CODE 851
    (852, "rm_level16a", 23.0, 1760.0, 1164.0, 1.0), // CODE 852
    (853, "rm_level17", 24.0, 672.0, 1484.0, 1.0), // CODE 853
    (854, "rm_level17", 26.0, 128.0, 204.0, 1.0), // CODE 854
    (855, "rm_level17a", 25.0, 1920.0, 1164.0, 1.0), // CODE 855
    (856, "rm_level17a", 27.0, 128.0, 140.0, 1.0), // CODE 856
    (857, "rm_boss2", 26.0, 352.0, 1484.0, 1.0), // CODE 857
    (858, "rm_boss2", 28.0, 128.0, 204.0, 1.0), // CODE 858
    (859, "room31", 27.0, 1152.0, 364.0, 1.0), // CODE 859
    (860, "room31", 29.0, 128.0, 236.0, 1.0), // CODE 860
    (861, "room32", 30.0, 128.0, 1164.0, 1.0), // CODE 861
    (862, "room32", 28.0, 1888.0, 684.0, 1.0), // CODE 862
    (863, "room33", 29.0, 1888.0, 236.0, 1.0), // CODE 863
    (864, "room33", 31.0, 128.0, 204.0, 1.0), // CODE 864
    (865, "room34", 32.0, 128.0, 268.0, 1.0), // CODE 865
    (867, "room34", 30.0, 896.0, 140.0, 1.0), // CODE 867
    (868, "room35", 31.0, 1440.0, 172.0, 1.0), // CODE 868
    (869, "room35", 33.0, 160.0, 204.0, 1.0), // CODE 869
    (870, "room36", 34.0, 128.0, 1932.0, 1.0), // CODE 870
    (871, "room36", 32.0, 1888.0, 236.0, 1.0), // CODE 871
    (872, "room37", 35.0, 128.0, 428.0, 1.0), // CODE 872
    (873, "room37", 33.0, 1888.0, 684.0, 1.0), // CODE 873
    (874, "room38", 36.0, 160.0, 204.0, 1.0), // CODE 874
    (875, "room38", 34.0, 512.0, 172.0, 1.0), // CODE 875
    (876, "room39", 35.0, 1888.0, 460.0, 1.0), // CODE 876
    (877, "room39", 37.0, 128.0, 140.0, 1.0), // CODE 877
    (878, "room40", 38.0, 128.0, 204.0, 1.0), // CODE 878
    (879, "room40", 36.0, 1888.0, 172.0, 1.0), // CODE 879
    (880, "room41", 39.0, 128.0, 204.0, 1.0), // CODE 880
    (881, "room41", 37.0, 1888.0, 524.0, 1.0), // CODE 881
    (882, "room42", 38.0, 1920.0, 204.0, 1.0), // CODE 882
    (883, "room42", 40.0, 160.0, 1164.0, 1.0), // CODE 883
    (884, "room43", 41.0, 128.0, 204.0, 1.0), // CODE 884
    (885, "room43", 39.0, 1888.0, 1164.0, 1.0), // CODE 885
    (886, "room44", 40.0, 864.0, 172.0, 1.0), // CODE 886
    (887, "room44", 42.0, 128.0, 204.0, 1.0), // CODE 887
    (888, "room45", 41.0, 2656.0, 204.0, 1.0), // CODE 888
    (889, "room45", 43.0, 576.0, 204.0, 1.0), // CODE 889
    (890, "room46", 44.0, 1120.0, 76.0, 1.0), // CODE 890
    (891, "room46", 42.0, 128.0, 524.0, 1.0), // CODE 891
    (892, "room47", 45.0, 128.0, 204.0, 1.0), // CODE 892
    (893, "room47", 43.0, 128.0, 204.0, 1.0), // CODE 893
    (894, "room48", 44.0, 1152.0, 524.0, 1.0), // CODE 894
    (895, "room48", 46.0, 128.0, 108.0, 1.0), // CODE 895
    (896, "room49", 45.0, 1408.0, 684.0, 1.0), // CODE 896
    (897, "room49", 47.0, 128.0, 140.0, 1.0), // CODE 897
    (898, "room50", 48.0, 128.0, 108.0, 1.0), // CODE 898
    (899, "room50", 46.0, 512.0, 908.0, 1.0), // CODE 899
    (900, "rm_boss3", 47.0, 992.0, 620.0, 1.0), // CODE 900
    (901, "rm_boss3", 49.0, 128.0, 300.0, 1.0), // CODE 901
    (902, "room51", 48.0, 1152.0, 364.0, 1.0), // CODE 902
    (903, "room51", 50.0, 128.0, 268.0, 1.0), // CODE 903
    (904, "room52", 49.0, 1920.0, 332.0, 1.0), // CODE 904
    (905, "room52", 51.0, 128.0, 140.0, 1.0), // CODE 905
    (906, "room53", 52.0, 128.0, 204.0, 1.0), // CODE 906
    (907, "room53", 50.0, 640.0, 268.0, 1.0), // CODE 907
    (908, "room54", 53.0, 128.0, 204.0, 1.0), // CODE 908
    (909, "room54", 51.0, 480.0, 1484.0, 1.0), // CODE 909
    (910, "room55", 54.0, 128.0, 140.0, 1.0), // CODE 910
    (911, "room55", 52.0, 1760.0, 1164.0, 1.0), // CODE 911
    (912, "room56", 53.0, 640.0, 684.0, 1.0), // CODE 912
    (913, "room56", 55.0, 608.0, 556.0, 1.0), // CODE 913
    (914, "room57", 54.0, 640.0, 1164.0, 1.0), // CODE 914
    (915, "room57", 56.0, 128.0, 300.0, 1.0), // CODE 915
    (916, "room58", 55.0, 1376.0, 908.0, 1.0), // CODE 916
    (917, "room58", 57.0, 128.0, 364.0, 1.0), // CODE 917
    (918, "room59", 56.0, 1920.0, 268.0, 1.0), // CODE 918
    (919, "room59", 58.0, 128.0, 204.0, 1.0), // CODE 919
    (920, "room60", 57.0, 672.0, 364.0, 1.0), // CODE 920
    (921, "room60", 59.0, 128.0, 204.0, 1.0), // CODE 921
    (922, "room61", 58.0, 1888.0, 364.0, 1.0), // CODE 922
    (923, "room61", 60.0, 128.0, 140.0, 1.0), // CODE 923
    (924, "room62", 59.0, 1920.0, 172.0, 1.0), // CODE 924
    (925, "room62", 61.0, 128.0, 108.0, 1.0), // CODE 925
    (926, "room63", 60.0, 640.0, 1164.0, 1.0), // CODE 926
    (927, "room63", 62.0, 1664.0, 620.0, 1.0), // CODE 927
    (928, "room64", 61.0, 128.0, 524.0, 1.0), // CODE 928
    (929, "room64", 63.0, 128.0, 204.0, 1.0), // CODE 929
    (930, "room65", 62.0, 1920.0, 684.0, 1.0), // CODE 930
    (931, "room65", 64.0, 128.0, 140.0, 1.0), // CODE 931
    (932, "rm_boss4", 63.0, 2432.0, 236.0, 1.0), // CODE 932
    (933, "rm_boss4", 65.0, 128.0, 108.0, 1.0), // CODE 933
    (934, "room66", 64.0, 1152.0, 364.0, 1.0), // CODE 934
    (935, "room66", 66.0, 128.0, 204.0, 1.0), // CODE 935
    (936, "room67", 65.0, 352.0, 1164.0, 1.0), // CODE 936
    (937, "room67", 67.0, 128.0, 108.0, 1.0), // CODE 937
    (938, "room68", 66.0, 1920.0, 268.0, 1.0), // CODE 938
    (939, "room68", 68.0, 672.0, 364.0, 1.0), // CODE 939
    (940, "room69", 69.0, 1920.0, 172.0, 1.0), // CODE 940
    (941, "room69", 67.0, 128.0, 1164.0, 1.0), // CODE 941
    (942, "room70", 70.0, 128.0, 684.0, 1.0), // CODE 942
    (943, "room70", 68.0, 128.0, 204.0, 1.0), // CODE 943
    (944, "room71", 69.0, 1920.0, 620.0, 1.0), // CODE 944
    (945, "room71", 71.0, 128.0, 192.0, 1.0), // CODE 945
    (946, "room72", 70.0, 896.0, 140.0, 1.0), // CODE 946
    (947, "room72", 72.0, 448.0, 684.0, 1.0), // CODE 947
    (948, "room73", 73.0, 128.0, 108.0, 1.0), // CODE 948
    (949, "room73", 71.0, 2240.0, 364.0, 1.0), // CODE 949
    (950, "room74", 72.0, 1920.0, 236.0, 1.0), // CODE 950
    (951, "room74", 74.0, 128.0, 204.0, 1.0), // CODE 951
    (952, "room75", 73.0, 1408.0, 684.0, 1.0), // CODE 952
    (953, "room75", 75.0, 672.0, 684.0, 1.0), // CODE 953
    (954, "room76", 76.0, 128.0, 204.0, 1.0), // CODE 954
    (955, "room76", 74.0, 320.0, 1420.0, 1.0), // CODE 955
    (956, "room77", 75.0, 1344.0, 1100.0, 1.0), // CODE 956
    (957, "room77", 77.0, 128.0, 172.0, 1.0), // CODE 957
    (958, "room78", 76.0, 1920.0, 108.0, 1.0), // CODE 958
    (959, "room78", 78.0, 128.0, 108.0, 1.0), // CODE 959
    (960, "room79", 77.0, 1152.0, 204.0, 1.0), // CODE 960
    (961, "room79", 79.0, 128.0, 204.0, 1.0), // CODE 961
    (962, "room80", 78.0, 1440.0, 524.0, 1.0), // CODE 962
    (963, "room80", 80.0, 128.0, 204.0, 1.0), // CODE 963
    (964, "room81", 79.0, 896.0, 204.0, 1.0), // CODE 964
    (965, "room81", 81.0, 128.0, 204.0, 1.0), // CODE 965
    (966, "room82", 80.0, 1152.0, 364.0, 1.0), // CODE 966
    (967, "room82", 82.0, 128.0, 140.0, 1.0), // CODE 967
    (968, "rm_boss5", 81.0, 1440.0, 204.0, 1.0), // CODE 968
    (969, "rm_boss5", 83.0, 128.0, 204.0, 1.0), // CODE 969
    (970, "room83", 82.0, 1152.0, 364.0, 1.0), // CODE 970
    (971, "room83", 84.0, 128.0, 108.0, 1.0), // CODE 971
    (972, "room84", 83.0, 1920.0, 236.0, 1.0), // CODE 972
    (973, "room84", 85.0, 128.0, 204.0, 1.0), // CODE 973
    (974, "room85", 84.0, 352.0, 1484.0, 1.0), // CODE 974
    (975, "room85", 86.0, 128.0, 204.0, 1.0), // CODE 975
    (976, "room86", 85.0, 1408.0, 364.0, 1.0), // CODE 976
    (977, "room86", 87.0, 128.0, 204.0, 1.0), // CODE 977
    (978, "room87", 86.0, 1152.0, 1164.0, 1.0), // CODE 978
    (979, "room87", 88.0, 128.0, 204.0, 1.0), // CODE 979
    (980, "room88", 87.0, 1920.0, 364.0, 1.0), // CODE 980
    (981, "room88", 89.0, 1888.0, 204.0, 1.0), // CODE 981
    (982, "room89", 88.0, 128.0, 1164.0, 1.0), // CODE 982
    (983, "room89", 90.0, 672.0, 108.0, 1.0), // CODE 983
    (984, "room90", 89.0, 128.0, 204.0, 1.0), // CODE 984
    (985, "room90", 91.0, 128.0, 76.0, 1.0), // CODE 985
    (986, "room91", 90.0, 1440.0, 108.0, 1.0), // CODE 986
    (987, "room91", 92.0, 128.0, 140.0, 1.0), // CODE 987
    (988, "room92", 91.0, 512.0, 684.0, 1.0), // CODE 988
    (989, "room92", 93.0, 128.0, 108.0, 1.0), // CODE 989
    (990, "room93", 92.0, 896.0, 140.0, 1.0), // CODE 990
    (991, "room93", 94.0, 128.0, 140.0, 1.0), // CODE 991
    (992, "room94", 95.0, 128.0, 108.0, 1.0), // CODE 992
    (993, "room94", 93.0, 1120.0, 684.0, 1.0), // CODE 993
    (994, "room95", 94.0, 1888.0, 140.0, 1.0), // CODE 994
    (995, "room95", 96.0, 128.0, 204.0, 1.0), // CODE 995
    (996, "room96", 95.0, 1120.0, 1164.0, 1.0), // CODE 996
    (997, "room96", 97.0, 128.0, 172.0, 1.0), // CODE 997
    (998, "room97", 96.0, 1440.0, 108.0, 1.0), // CODE 998
    (999, "room97", 98.0, 128.0, 204.0, 1.0), // CODE 999
    (1000, "room98", 97.0, 512.0, 172.0, 1.0), // CODE 1000
    (1001, "room98", 99.0, 128.0, 204.0, 1.0), // CODE 1001
    (1002, "room99", 98.0, 320.0, 1420.0, 1.0), // CODE 1002
    (1003, "room99", 100.0, 128.0, 204.0, 1.0), // CODE 1003
    (1004, "room100", 99.0, 1920.0, 236.0, 1.0), // CODE 1004
    (1005, "room100", 101.0, 128.0, 204.0, 1.0), // CODE 1005
    (1006, "room101", 100.0, 864.0, 140.0, 1.0), // CODE 1006
    (1007, "room101", 102.0, 128.0, 204.0, 1.0), // CODE 1007
    (1008, "room102", 101.0, 1856.0, 236.0, 1.0), // CODE 1008
    (1009, "room102", 103.0, 128.0, 204.0, 1.0), // CODE 1009
    (1010, "room103", 104.0, 128.0, 140.0, 1.0), // CODE 1010
    (1011, "room103", 102.0, 672.0, 684.0, 1.0), // CODE 1011
    (1012, "rm_boss6", 103.0, 1408.0, 364.0, 1.0), // CODE 1012
    (1013, "rm_challenge1", 104.0, 128.0, 140.0, 1.0), // CODE 1013
    (1014, "rm_challenge1", 106.0, 128.0, 140.0, 1.0), // CODE 1014
    (1015, "rm_challenge2", 105.0, 1376.0, 908.0, 1.0), // CODE 1015
    (1016, "rm_challenge2", 107.0, 128.0, 140.0, 1.0), // CODE 1016
    (1017, "rm_challenge3", 106.0, 1888.0, 332.0, 1.0), // CODE 1017
    (1018, "rm_challenge3", 108.0, 128.0, 140.0, 1.0), // CODE 1018
    (1019, "rm_challenge4", 107.0, 1216.0, 492.0, 1.0), // CODE 1019
    (1020, "rm_challenge4", 109.0, 128.0, 428.0, 1.0), // CODE 1020
    (1021, "rm_challenge5", 108.0, 1376.0, 1164.0, 1.0), // CODE 1021
];

// (code, room, visited flag, goto)
const TILES: [(i32, &str, &str, f64); 330] = [
    (1024, "rm_map", "room94visited", 94.0), // CODE 1024
    (1025, "rm_map", "room42visited", 39.0), // CODE 1025
    (1026, "rm_map", "room43visited", 40.0), // CODE 1026
    (1027, "rm_map", "room91visited", 91.0), // CODE 1027
    (1028, "rm_map", "room45visited", 42.0), // CODE 1028
    (1029, "rm_map", "room95visited", 95.0), // CODE 1029
    (1030, "rm_map", "room92visited", 92.0), // CODE 1030
    (1031, "rm_map", "room44visited", 41.0), // CODE 1031
    (1032, "rm_map", "room93visited", 93.0), // CODE 1032
    (1033, "rm_map", "room46visited", 43.0), // CODE 1033
    (1034, "rm_map", "room47visited", 44.0), // CODE 1034
    (1035, "rm_map", "room40visited", 37.0), // CODE 1035
    (1036, "rm_map", "room89visited", 89.0), // CODE 1036
    (1037, "rm_map", "room88visited", 88.0), // CODE 1037
    (1038, "rm_map", "room41visited", 38.0), // CODE 1038
    (1039, "rm_map", "boss4visited", 64.0), // CODE 1039
    (1040, "rm_map", "room39visited", 36.0), // CODE 1040
    (1041, "rm_map", "room78visited", 77.0), // CODE 1041
    (1042, "rm_map", "room90visited", 90.0), // CODE 1042
    (1043, "rm_map", "room103visited", 103.0), // CODE 1043
    (1044, "rm_map", "room96visited", 96.0), // CODE 1044
    (1045, "rm_map", "room48visited", 45.0), // CODE 1045
    (1046, "rm_map", "room97visited", 97.0), // CODE 1046
    (1047, "rm_map", "room49visited", 46.0), // CODE 1047
    (1048, "rm_map", "room98visited", 98.0), // CODE 1048
    (1049, "rm_map", "room50visited", 47.0), // CODE 1049
    (1050, "rm_map", "room99visited", 99.0), // CODE 1050
    (1051, "rm_map", "boss3visited", 48.0), // CODE 1051
    (1052, "rm_map", "room100visited", 100.0), // CODE 1052
    (1053, "rm_map", "room51visited", 49.0), // CODE 1053
    (1054, "rm_map", "room101visited", 101.0), // CODE 1054
    (1055, "rm_map", "room52visited", 50.0), // CODE 1055
    (1056, "rm_map", "room102visited", 102.0), // CODE 1056
    (1057, "rm_map", "room53visited", 51.0), // CODE 1057
    (1058, "rm_map", "boss6visited", 104.0), // CODE 1058
    (1059, "rm_map", "room54visited", 52.0), // CODE 1059
    (1060, "rm_map", "level1visited", 1.0), // CODE 1060
    (1061, "rm_map", "room55visited", 53.0), // CODE 1061
    (1062, "rm_map", "level2visited", 2.0), // CODE 1062
    (1063, "rm_map", "room56visited", 54.0), // CODE 1063
    (1064, "rm_map", "level3visited", 3.0), // CODE 1064
    (1065, "rm_map", "room57visited", 55.0), // CODE 1065
    (1066, "rm_map", "level4visited", 4.0), // CODE 1066
    (1067, "rm_map", "room58visited", 56.0), // CODE 1067
    (1068, "rm_map", "level5visited", 5.0), // CODE 1068
    (1069, "rm_map", "room59visited", 57.0), // CODE 1069
    (1070, "rm_map", "level6visited", 6.0), // CODE 1070
    (1071, "rm_map", "room60visited", 58.0), // CODE 1071
    (1072, "rm_map", "level7visited", 7.0), // CODE 1072
    (1073, "rm_map", "room61visited", 59.0), // CODE 1073
    (1074, "rm_map", "level8visited", 8.0), // CODE 1074
    (1075, "rm_map", "room62visited", 60.0), // CODE 1075
    (1076, "rm_map", "level8avisited", 9.0), // CODE 1076
    (1077, "rm_map", "room63visited", 61.0), // CODE 1077
    (1078, "rm_map", "boss1visited", 10.0), // CODE 1078
    (1079, "rm_map", "room64visited", 62.0), // CODE 1079
    (1080, "rm_map", "level9visited", 11.0), // CODE 1080
    (1081, "rm_map", "room65visited", 63.0), // CODE 1081
    (1082, "rm_map", "level9avisited", 12.0), // CODE 1082
    (1083, "rm_map", "level10visited", 13.0), // CODE 1083
    (1084, "rm_map", "room66visited", 65.0), // CODE 1084
    (1085, "rm_map", "level11visited", 14.0), // CODE 1085
    (1086, "rm_map", "room67visited", 66.0), // CODE 1086
    (1087, "rm_map", "level11avisited", 15.0), // CODE 1087
    (1088, "rm_map", "room68visited", 67.0), // CODE 1088
    (1089, "rm_map", "level12visited", 16.0), // CODE 1089
    (1090, "rm_map", "room69visited", 68.0), // CODE 1090
    (1091, "rm_map", "level13visited", 17.0), // CODE 1091
    (1092, "rm_map", "room70visited", 69.0), // CODE 1092
    (1093, "rm_map", "level13avisited", 18.0), // CODE 1093
    (1094, "rm_map", "room71visited", 70.0), // CODE 1094
    (1095, "rm_map", "level14visited", 19.0), // CODE 1095
    (1096, "rm_map", "room72visited", 71.0), // CODE 1096
    (1097, "rm_map", "level14avisited", 20.0), // CODE 1097
    (1098, "rm_map", "room73visited", 72.0), // CODE 1098
    (1099, "rm_map", "level15visited", 21.0), // CODE 1099
    (1100, "rm_map", "room74visited", 73.0), // CODE 1100
    (1101, "rm_map", "level15avisited", 22.0), // CODE 1101
    (1102, "rm_map", "room75visited", 74.0), // CODE 1102
    (1103, "rm_map", "level16visited", 23.0), // CODE 1103
    (1104, "rm_map", "room76visited", 75.0), // CODE 1104
    (1105, "rm_map", "level16avisited", 24.0), // CODE 1105
    (1106, "rm_map", "room77visited", 76.0), // CODE 1106
    (1107, "rm_map", "level17visited", 25.0), // CODE 1107
    (1108, "rm_map", "level17avisited", 26.0), // CODE 1108
    (1109, "rm_map", "room79visited", 78.0), // CODE 1109
    (1110, "rm_map", "boss2visited", 27.0), // CODE 1110
    (1111, "rm_map", "room80visited", 79.0), // CODE 1111
    (1112, "rm_map", "room31visited", 28.0), // CODE 1112
    (1113, "rm_map", "room81visited", 80.0), // CODE 1113
    (1114, "rm_map", "room32visited", 29.0), // CODE 1114
    (1115, "rm_map", "room82visited", 81.0), // CODE 1115
    (1116, "rm_map", "room33visited", 30.0), // CODE 1116
    (1117, "rm_map", "boss5visited", 82.0), // CODE 1117
    (1118, "rm_map", "room34visited", 31.0), // CODE 1118
    (1119, "rm_map", "room83visited", 83.0), // CODE 1119
    (1120, "rm_map", "room35visited", 32.0), // CODE 1120
    (1121, "rm_map", "room84visited", 84.0), // CODE 1121
    (1122, "rm_map", "room36visited", 33.0), // CODE 1122
    (1123, "rm_map", "room85visited", 85.0), // CODE 1123
    (1124, "rm_map", "room37visited", 34.0), // CODE 1124
    (1125, "rm_map", "room86visited", 86.0), // CODE 1125
    (1126, "rm_map", "room38visited", 35.0), // CODE 1126
    (1127, "rm_map", "room87visited", 87.0), // CODE 1127
    (1128, "rm_map", "levelchallenge1visited", 105.0), // CODE 1128
    (1129, "rm_map", "levelchallenge2visited", 106.0), // CODE 1129
    (1130, "rm_map", "levelchallenge3visited", 107.0), // CODE 1130
    (1131, "rm_map", "levelchallenge4visited", 108.0), // CODE 1131
    (1132, "rm_map", "levelchallenge5visited", 109.0), // CODE 1132
    (1133, "rm_mapview3", "room94visited", 94.0), // CODE 1133
    (1134, "rm_mapview3", "room42visited", 39.0), // CODE 1134
    (1135, "rm_mapview3", "room43visited", 40.0), // CODE 1135
    (1136, "rm_mapview3", "room91visited", 91.0), // CODE 1136
    (1137, "rm_mapview3", "room45visited", 42.0), // CODE 1137
    (1138, "rm_mapview3", "room95visited", 95.0), // CODE 1138
    (1139, "rm_mapview3", "room92visited", 92.0), // CODE 1139
    (1140, "rm_mapview3", "room44visited", 41.0), // CODE 1140
    (1141, "rm_mapview3", "room93visited", 93.0), // CODE 1141
    (1142, "rm_mapview3", "room46visited", 43.0), // CODE 1142
    (1143, "rm_mapview3", "room47visited", 44.0), // CODE 1143
    (1144, "rm_mapview3", "room96visited", 96.0), // CODE 1144
    (1145, "rm_mapview3", "room48visited", 45.0), // CODE 1145
    (1146, "rm_mapview3", "room97visited", 97.0), // CODE 1146
    (1147, "rm_mapview3", "room49visited", 46.0), // CODE 1147
    (1148, "rm_mapview3", "room98visited", 98.0), // CODE 1148
    (1149, "rm_mapview3", "room50visited", 47.0), // CODE 1149
    (1150, "rm_mapview3", "room99visited", 99.0), // CODE 1150
    (1151, "rm_mapview3", "boss3visited", 48.0), // CODE 1151
    (1152, "rm_mapview3", "room100visited", 100.0), // CODE 1152
    (1153, "rm_mapview3", "room51visited", 49.0), // CODE 1153
    (1154, "rm_mapview3", "room101visited", 101.0), // CODE 1154
    (1155, "rm_mapview3", "room52visited", 50.0), // CODE 1155
    (1156, "rm_mapview3", "room102visited", 102.0), // CODE 1156
    (1157, "rm_mapview3", "room53visited", 51.0), // CODE 1157
    (1158, "rm_mapview3", "boss6visited", 104.0), // CODE 1158
    (1159, "rm_mapview3", "room54visited", 52.0), // CODE 1159
    (1160, "rm_mapview3", "level1visited", 1.0), // CODE 1160
    (1161, "rm_mapview3", "room55visited", 53.0), // CODE 1161
    (1162, "rm_mapview3", "level2visited", 2.0), // CODE 1162
    (1163, "rm_mapview3", "room56visited", 54.0), // CODE 1163
    (1164, "rm_mapview3", "level3visited", 3.0), // CODE 1164
    (1165, "rm_mapview3", "room57visited", 55.0), // CODE 1165
    (1166, "rm_mapview3", "level4visited", 4.0), // CODE 1166
    (1167, "rm_mapview3", "room58visited", 56.0), // CODE 1167
    (1168, "rm_mapview3", "level5visited", 5.0), // CODE 1168
    (1169, "rm_mapview3", "room59visited", 57.0), // CODE 1169
    (1170, "rm_mapview3", "level6visited", 6.0), // CODE 1170
    (1171, "rm_mapview3", "room60visited", 58.0), // CODE 1171
    (1172, "rm_mapview3", "level7visited", 7.0), // CODE 1172
    (1173, "rm_mapview3", "room61visited", 59.0), // CODE 1173
    (1174, "rm_mapview3", "level8visited", 8.0), // CODE 1174
    (1175, "rm_mapview3", "room62visited", 60.0), // CODE 1175
    (1176, "rm_mapview3", "level8avisited", 9.0), // CODE 1176
    (1177, "rm_mapview3", "room63visited", 61.0), // CODE 1177
    (1178, "rm_mapview3", "boss1visited", 10.0), // CODE 1178
    (1179, "rm_mapview3", "room64visited", 62.0), // CODE 1179
    (1180, "rm_mapview3", "level9visited", 11.0), // CODE 1180
    (1181, "rm_mapview3", "room65visited", 63.0), // CODE 1181
    (1182, "rm_mapview3", "level9avisited", 12.0), // CODE 1182
    (1183, "rm_mapview3", "level10visited", 13.0), // CODE 1183
    (1184, "rm_mapview3", "room66visited", 65.0), // CODE 1184
    (1185, "rm_mapview3", "level11visited", 14.0), // CODE 1185
    (1186, "rm_mapview3", "room67visited", 66.0), // CODE 1186
    (1187, "rm_mapview3", "level11avisited", 15.0), // CODE 1187
    (1188, "rm_mapview3", "room68visited", 67.0), // CODE 1188
    (1189, "rm_mapview3", "level12visited", 16.0), // CODE 1189
    (1190, "rm_mapview3", "room69visited", 68.0), // CODE 1190
    (1191, "rm_mapview3", "level13visited", 17.0), // CODE 1191
    (1192, "rm_mapview3", "room70visited", 69.0), // CODE 1192
    (1193, "rm_mapview3", "level13avisited", 18.0), // CODE 1193
    (1194, "rm_mapview3", "room71visited", 70.0), // CODE 1194
    (1195, "rm_mapview3", "level14visited", 19.0), // CODE 1195
    (1196, "rm_mapview3", "room72visited", 71.0), // CODE 1196
    (1197, "rm_mapview3", "level14avisited", 20.0), // CODE 1197
    (1198, "rm_mapview3", "room73visited", 72.0), // CODE 1198
    (1199, "rm_mapview3", "level15visited", 21.0), // CODE 1199
    (1200, "rm_mapview3", "room74visited", 73.0), // CODE 1200
    (1201, "rm_mapview3", "level15avisited", 22.0), // CODE 1201
    (1202, "rm_mapview3", "room75visited", 74.0), // CODE 1202
    (1203, "rm_mapview3", "level16visited", 23.0), // CODE 1203
    (1204, "rm_mapview3", "room76visited", 75.0), // CODE 1204
    (1205, "rm_mapview3", "level16avisited", 24.0), // CODE 1205
    (1206, "rm_mapview3", "room77visited", 76.0), // CODE 1206
    (1207, "rm_mapview3", "level17visited", 25.0), // CODE 1207
    (1208, "rm_mapview3", "level17avisited", 26.0), // CODE 1208
    (1209, "rm_mapview3", "room79visited", 78.0), // CODE 1209
    (1210, "rm_mapview3", "boss2visited", 27.0), // CODE 1210
    (1211, "rm_mapview3", "room80visited", 79.0), // CODE 1211
    (1212, "rm_mapview3", "room31visited", 28.0), // CODE 1212
    (1213, "rm_mapview3", "room81visited", 80.0), // CODE 1213
    (1214, "rm_mapview3", "room32visited", 29.0), // CODE 1214
    (1215, "rm_mapview3", "room82visited", 81.0), // CODE 1215
    (1216, "rm_mapview3", "room33visited", 30.0), // CODE 1216
    (1217, "rm_mapview3", "boss5visited", 82.0), // CODE 1217
    (1218, "rm_mapview3", "room34visited", 31.0), // CODE 1218
    (1219, "rm_mapview3", "room83visited", 83.0), // CODE 1219
    (1220, "rm_mapview3", "room35visited", 32.0), // CODE 1220
    (1221, "rm_mapview3", "room84visited", 84.0), // CODE 1221
    (1222, "rm_mapview3", "room36visited", 33.0), // CODE 1222
    (1223, "rm_mapview3", "room85visited", 85.0), // CODE 1223
    (1224, "rm_mapview3", "room37visited", 34.0), // CODE 1224
    (1225, "rm_mapview3", "room86visited", 86.0), // CODE 1225
    (1226, "rm_mapview3", "room38visited", 35.0), // CODE 1226
    (1227, "rm_mapview3", "room87visited", 87.0), // CODE 1227
    (1228, "rm_mapview3", "room39visited", 36.0), // CODE 1228
    (1229, "rm_mapview3", "room88visited", 88.0), // CODE 1229
    (1230, "rm_mapview3", "room40visited", 37.0), // CODE 1230
    (1231, "rm_mapview3", "room89visited", 89.0), // CODE 1231
    (1232, "rm_mapview3", "room41visited", 38.0), // CODE 1232
    (1233, "rm_mapview3", "boss4visited", 64.0), // CODE 1233
    (1234, "rm_mapview3", "room78visited", 77.0), // CODE 1234
    (1235, "rm_mapview3", "room90visited", 90.0), // CODE 1235
    (1236, "rm_mapview3", "room103visited", 103.0), // CODE 1236
    (1237, "rm_mapview3", "levelchallenge1visited", 105.0), // CODE 1237
    (1238, "rm_mapview3", "levelchallenge2visited", 106.0), // CODE 1238
    (1239, "rm_mapview3", "levelchallenge3visited", 107.0), // CODE 1239
    (1240, "rm_mapview3", "levelchallenge4visited", 108.0), // CODE 1240
    (1241, "rm_mapview3", "levelchallenge5visited", 109.0), // CODE 1241
    (1242, "rm_mapview0", "room94visited", 94.0), // CODE 1242
    (1243, "rm_mapview0", "room42visited", 39.0), // CODE 1243
    (1244, "rm_mapview0", "room43visited", 40.0), // CODE 1244
    (1245, "rm_mapview0", "room91visited", 91.0), // CODE 1245
    (1246, "rm_mapview0", "room45visited", 42.0), // CODE 1246
    (1247, "rm_mapview0", "room95visited", 95.0), // CODE 1247
    (1248, "rm_mapview0", "room92visited", 92.0), // CODE 1248
    (1249, "rm_mapview0", "room44visited", 41.0), // CODE 1249
    (1250, "rm_mapview0", "room93visited", 93.0), // CODE 1250
    (1251, "rm_mapview0", "room46visited", 43.0), // CODE 1251
    (1252, "rm_mapview0", "room47visited", 44.0), // CODE 1252
    (1253, "rm_mapview0", "room96visited", 96.0), // CODE 1253
    (1254, "rm_mapview0", "room48visited", 45.0), // CODE 1254
    (1255, "rm_mapview0", "room97visited", 97.0), // CODE 1255
    (1256, "rm_mapview0", "room49visited", 46.0), // CODE 1256
    (1257, "rm_mapview0", "room98visited", 98.0), // CODE 1257
    (1258, "rm_mapview0", "room50visited", 47.0), // CODE 1258
    (1259, "rm_mapview0", "room99visited", 99.0), // CODE 1259
    (1260, "rm_mapview0", "boss3visited", 48.0), // CODE 1260
    (1261, "rm_mapview0", "room100visited", 100.0), // CODE 1261
    (1262, "rm_mapview0", "room51visited", 49.0), // CODE 1262
    (1263, "rm_mapview0", "room101visited", 101.0), // CODE 1263
    (1264, "rm_mapview0", "room52visited", 50.0), // CODE 1264
    (1265, "rm_mapview0", "room102visited", 102.0), // CODE 1265
    (1266, "rm_mapview0", "room53visited", 51.0), // CODE 1266
    (1267, "rm_mapview0", "room54visited", 52.0), // CODE 1267
    (1268, "rm_mapview0", "level1visited", 1.0), // CODE 1268
    (1269, "rm_mapview0", "room55visited", 53.0), // CODE 1269
    (1270, "rm_mapview0", "level2visited", 2.0), // CODE 1270
    (1271, "rm_mapview0", "room56visited", 54.0), // CODE 1271
    (1272, "rm_mapview0", "level3visited", 3.0), // CODE 1272
    (1273, "rm_mapview0", "room57visited", 55.0), // CODE 1273
    (1274, "rm_mapview0", "level4visited", 4.0), // CODE 1274
    (1275, "rm_mapview0", "room58visited", 56.0), // CODE 1275
    (1276, "rm_mapview0", "level5visited", 5.0), // CODE 1276
    (1277, "rm_mapview0", "room59visited", 57.0), // CODE 1277
    (1278, "rm_mapview0", "level6visited", 6.0), // CODE 1278
    (1279, "rm_mapview0", "room60visited", 58.0), // CODE 1279
    (1280, "rm_mapview0", "level7visited", 7.0), // CODE 1280
    (1281, "rm_mapview0", "room61visited", 59.0), // CODE 1281
    (1282, "rm_mapview0", "level8visited", 8.0), // CODE 1282
    (1283, "rm_mapview0", "room62visited", 60.0), // CODE 1283
    (1284, "rm_mapview0", "level8avisited", 9.0), // CODE 1284
    (1285, "rm_mapview0", "room63visited", 61.0), // CODE 1285
    (1286, "rm_mapview0", "boss1visited", 10.0), // CODE 1286
    (1287, "rm_mapview0", "room64visited", 62.0), // CODE 1287
    (1288, "rm_mapview0", "level9visited", 11.0), // CODE 1288
    (1289, "rm_mapview0", "room65visited", 63.0), // CODE 1289
    (1290, "rm_mapview0", "level9avisited", 12.0), // CODE 1290
    (1291, "rm_mapview0", "level10visited", 13.0), // CODE 1291
    (1292, "rm_mapview0", "room66visited", 65.0), // CODE 1292
    (1293, "rm_mapview0", "level11visited", 14.0), // CODE 1293
    (1294, "rm_mapview0", "room67visited", 66.0), // CODE 1294
    (1295, "rm_mapview0", "level11avisited", 15.0), // CODE 1295
    (1296, "rm_mapview0", "room68visited", 67.0), // CODE 1296
    (1297, "rm_mapview0", "level12visited", 16.0), // CODE 1297
    (1298, "rm_mapview0", "room69visited", 68.0), // CODE 1298
    (1299, "rm_mapview0", "level13visited", 17.0), // CODE 1299
    (1300, "rm_mapview0", "room70visited", 69.0), // CODE 1300
    (1301, "rm_mapview0", "level13avisited", 18.0), // CODE 1301
    (1302, "rm_mapview0", "room71visited", 70.0), // CODE 1302
    (1303, "rm_mapview0", "level14visited", 19.0), // CODE 1303
    (1304, "rm_mapview0", "room72visited", 71.0), // CODE 1304
    (1305, "rm_mapview0", "level14avisited", 20.0), // CODE 1305
    (1306, "rm_mapview0", "room73visited", 72.0), // CODE 1306
    (1307, "rm_mapview0", "level15visited", 21.0), // CODE 1307
    (1308, "rm_mapview0", "room74visited", 73.0), // CODE 1308
    (1309, "rm_mapview0", "level15avisited", 22.0), // CODE 1309
    (1310, "rm_mapview0", "room75visited", 74.0), // CODE 1310
    (1311, "rm_mapview0", "level16visited", 23.0), // CODE 1311
    (1312, "rm_mapview0", "room76visited", 75.0), // CODE 1312
    (1313, "rm_mapview0", "level16avisited", 24.0), // CODE 1313
    (1314, "rm_mapview0", "room77visited", 76.0), // CODE 1314
    (1315, "rm_mapview0", "level17visited", 25.0), // CODE 1315
    (1316, "rm_mapview0", "level17avisited", 26.0), // CODE 1316
    (1317, "rm_mapview0", "room79visited", 78.0), // CODE 1317
    (1318, "rm_mapview0", "boss2visited", 27.0), // CODE 1318
    (1319, "rm_mapview0", "room80visited", 79.0), // CODE 1319
    (1320, "rm_mapview0", "room31visited", 28.0), // CODE 1320
    (1321, "rm_mapview0", "room81visited", 80.0), // CODE 1321
    (1322, "rm_mapview0", "room32visited", 29.0), // CODE 1322
    (1323, "rm_mapview0", "room82visited", 81.0), // CODE 1323
    (1324, "rm_mapview0", "room33visited", 30.0), // CODE 1324
    (1325, "rm_mapview0", "boss5visited", 82.0), // CODE 1325
    (1326, "rm_mapview0", "room34visited", 31.0), // CODE 1326
    (1327, "rm_mapview0", "room83visited", 83.0), // CODE 1327
    (1328, "rm_mapview0", "room35visited", 32.0), // CODE 1328
    (1329, "rm_mapview0", "room84visited", 84.0), // CODE 1329
    (1330, "rm_mapview0", "room36visited", 33.0), // CODE 1330
    (1331, "rm_mapview0", "room85visited", 85.0), // CODE 1331
    (1332, "rm_mapview0", "room37visited", 34.0), // CODE 1332
    (1333, "rm_mapview0", "room86visited", 86.0), // CODE 1333
    (1334, "rm_mapview0", "room38visited", 35.0), // CODE 1334
    (1335, "rm_mapview0", "room87visited", 87.0), // CODE 1335
    (1336, "rm_mapview0", "room39visited", 36.0), // CODE 1336
    (1337, "rm_mapview0", "room88visited", 88.0), // CODE 1337
    (1338, "rm_mapview0", "room40visited", 37.0), // CODE 1338
    (1339, "rm_mapview0", "room89visited", 89.0), // CODE 1339
    (1340, "rm_mapview0", "room41visited", 38.0), // CODE 1340
    (1341, "rm_mapview0", "boss4visited", 64.0), // CODE 1341
    (1342, "rm_mapview0", "room78visited", 77.0), // CODE 1342
    (1343, "rm_mapview0", "room90visited", 90.0), // CODE 1343
    (1344, "rm_mapview0", "room103visited", 103.0), // CODE 1344
    (1345, "rm_mapview0", "boss6visited", 104.0), // CODE 1345
    (1346, "rm_mapview0", "boss6visited", 104.0), // CODE 1346
    (1347, "rm_mapview0", "boss6visited", 104.0), // CODE 1347
    (1348, "rm_mapview0", "boss6visited", 104.0), // CODE 1348
    (1349, "rm_mapview0", "levelchallenge1visited", 105.0), // CODE 1349
    (1350, "rm_mapview0", "levelchallenge2visited", 106.0), // CODE 1350
    (1351, "rm_mapview0", "levelchallenge3visited", 107.0), // CODE 1351
    (1352, "rm_mapview0", "levelchallenge4visited", 108.0), // CODE 1352
    (1353, "rm_mapview0", "levelchallenge5visited", 109.0), // CODE 1353
];

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances.get(&id).and_then(|i| i.fields.get(name)).copied()
}

#[test]
fn every_door_card_stores_its_shipped_warp_triple() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    for (code, _room, warproom, warpx, warpy, unlocked) in DOORS {
        let id = s.create(&b, WARP, 100.0, 100.0).expect("door instance");
        execute(&b, code as usize, id, &mut s).unwrap_or_else(|e| panic!("CODE {code}: {e}"));
        assert_eq!(field(&s, id, "warproom"), Some(warproom), "CODE {code} warproom");
        assert_eq!(field(&s, id, "warpx"), Some(warpx), "CODE {code} warpx");
        assert_eq!(field(&s, id, "warpy"), Some(warpy), "CODE {code} warpy");
        assert_eq!(field(&s, id, "unlocked"), Some(unlocked), "CODE {code} unlocked");
    }
    // The population is complete: the door-card count is the shipped one.
    assert_eq!(DOORS.len(), 218);
}

#[test]
fn every_fog_card_survives_when_visited_and_dies_otherwise() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    for (code, _room, flag, goto) in TILES {
        // Unvisited: the card destroys the tile before storing anything.
        s.globals.insert(flag.into(), 0.0);
        let id = s.create(&b, MAPTILE, 10.0, 10.0).expect("tile instance");
        execute(&b, code as usize, id, &mut s).unwrap_or_else(|e| panic!("CODE {code}: {e}"));
        assert!(!s.instances[&id].alive, "CODE {code}: an unvisited room erases its tile");
        assert_eq!(field(&s, id, "goto"), Some(goto),
            "CODE {code}: the bf lands ON the store - goto is written even on the destroyed path");
        // Visited: the tile lives and carries the shipped goto target.
        s.globals.insert(flag.into(), 1.0);
        let id2 = s.create(&b, MAPTILE, 10.0, 10.0).expect("tile instance 2");
        execute(&b, code as usize, id2, &mut s).unwrap_or_else(|e| panic!("CODE {code} visited: {e}"));
        assert!(s.instances[&id2].alive, "CODE {code}: a visited room keeps its tile");
        assert_eq!(field(&s, id2, "goto"), Some(goto), "CODE {code} goto");
    }
    assert_eq!(TILES.len(), 330);
}

#[test]
fn the_cast_binds_run_and_execute_the_remaining_cards() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    // rm_ending's two placement binds (CODE 1022 player sprite pin, CODE 1023
    // the still-standing obj_enemy) plus room88's bind run on their own
    // placement objects through the same entry.
    let p = s.create(&b, 0, 500.0, 500.0).expect("player");
    execute(&b, 1022, p, &mut s).expect("CODE 1022");
    assert_eq!(field(&s, p, "sprite_index"), Some(30.0), "the ending pins the player sprite");
    let e = s.create(&b, 14, 200.0, 200.0).expect("enemy");
    execute(&b, 1023, e, &mut s).expect("CODE 1023");
    assert_eq!(field(&s, e, "hspeed"), Some(0.0));
    assert_eq!(field(&s, e, "vspeed"), Some(0.0));
    // Every DOORS/TILES id is unique, and the 548 card ids plus the two binds
    // plus the one EMPTY card CODE 866 (room34's second door placement runs
    // with zero instructions - the materializer simply leaves the instance at
    // its placed state) are exactly the 551 shipped RoomCC bodies.
    execute(&b, 866, s.create(&b, WARP, 1.0, 1.0).expect("empty-card instance"), &mut s)
        .expect("CODE 866: an empty body still enters the VM");
    let mut all: Vec<i32> = DOORS.iter().map(|d| d.0).chain(TILES.iter().map(|t| t.0)).collect();
    all.extend([1022, 1023, 866]);
    let n = all.len();
    all.sort();
    all.dedup();
    assert_eq!(all.len(), n, "the 551 RoomCC ids are distinct");
    assert_eq!(n, 551, "the sweep covers the shipped RoomCC population");
}
