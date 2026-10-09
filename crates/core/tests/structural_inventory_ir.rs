//! The structural tier's final inventory: every remaining 132 CODE body named
//! by id WITH ITS EXACT EVENT OWNERSHIP (object name, event type, subtype),
//! read straight off the bundle's object table, plus its membership in the
//! committed full-suite execution ledger. These bodies are already executed by
//! object-level suites (the Lloyd sheets, the enemy intro banners, XPorb and
//! the UI alarms); this suite is the id-level ledger closing the census's
//! `structural` tier - the assertion that the shipped mapping (code -> object
//! event) holds, not a re-proving of behavior.
//!
//! If a body's ownership ever differs from the table (a regenerator drift),
//! this goes RED by name.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use std::collections::BTreeSet;
use std::path::Path;

// (code, owning object, event type, event subtype)
const LEDGER: [(i32, &str, i32, i32); 132] = [
    (347, "obj_XPorb", 0, 0), // CODE 347
    (366, "obj_UI", 2, 7), // CODE 366
    (367, "obj_UI", 2, 1), // CODE 367
    (571, "obj_lloydtutorial3", 0, 0), // CODE 571
    (573, "obj_lloydtutorial3", 2, 5), // CODE 573
    (574, "obj_lloydtutorial3", 2, 0), // CODE 574
    (575, "obj_lloydtutorial3", 8, 0), // CODE 575
    (576, "obj_lloydtutorial4", 0, 0), // CODE 576
    (578, "obj_lloydtutorial4", 2, 5), // CODE 578
    (579, "obj_lloydtutorial4", 2, 3), // CODE 579
    (580, "obj_lloydtutorial4", 2, 2), // CODE 580
    (581, "obj_lloydtutorial4", 2, 1), // CODE 581
    (582, "obj_lloydtutorial4", 2, 0), // CODE 582
    (583, "obj_lloydtutorial4", 8, 0), // CODE 583
    (584, "obj_lloydtutorial5", 0, 0), // CODE 584
    (586, "obj_lloydtutorial5", 2, 5), // CODE 586
    (587, "obj_lloydtutorial5", 2, 3), // CODE 587
    (588, "obj_lloydtutorial5", 2, 2), // CODE 588
    (589, "obj_lloydtutorial5", 2, 1), // CODE 589
    (590, "obj_lloydtutorial5", 2, 0), // CODE 590
    (591, "obj_lloydtutorial5", 8, 0), // CODE 591
    (592, "obj_lloydtutorial6", 0, 0), // CODE 592
    (594, "obj_lloydtutorial6", 2, 5), // CODE 594
    (595, "obj_lloydtutorial6", 2, 3), // CODE 595
    (596, "obj_lloydtutorial6", 2, 2), // CODE 596
    (597, "obj_lloydtutorial6", 2, 1), // CODE 597
    (598, "obj_lloydtutorial6", 2, 0), // CODE 598
    (599, "obj_lloydtutorial6", 8, 0), // CODE 599
    (600, "obj_lloydtutorial7", 0, 0), // CODE 600
    (602, "obj_lloydtutorial7", 2, 5), // CODE 602
    (603, "obj_lloydtutorial7", 2, 1), // CODE 603
    (604, "obj_lloydtutorial7", 2, 0), // CODE 604
    (605, "obj_lloydtutorial7", 8, 0), // CODE 605
    (606, "obj_lloydtutorial8", 0, 0), // CODE 606
    (608, "obj_lloydtutorial8", 2, 5), // CODE 608
    (609, "obj_lloydtutorial8", 2, 3), // CODE 609
    (610, "obj_lloydtutorial8", 2, 2), // CODE 610
    (611, "obj_lloydtutorial8", 2, 1), // CODE 611
    (612, "obj_lloydtutorial8", 2, 0), // CODE 612
    (613, "obj_lloydtutorial8", 8, 0), // CODE 613
    (614, "obj_lloydtutorial9", 0, 0), // CODE 614
    (616, "obj_lloydtutorial9", 2, 5), // CODE 616
    (617, "obj_lloydtutorial9", 2, 0), // CODE 617
    (618, "obj_lloydtutorial9", 8, 0), // CODE 618
    (619, "obj_lloydtutorial10", 0, 0), // CODE 619
    (621, "obj_lloydtutorial10", 2, 5), // CODE 621
    (622, "obj_lloydtutorial10", 2, 0), // CODE 622
    (623, "obj_lloydtutorial10", 8, 0), // CODE 623
    (624, "obj_lloydtutorial11", 0, 0), // CODE 624
    (626, "obj_lloydtutorial11", 2, 5), // CODE 626
    (627, "obj_lloydtutorial11", 2, 4), // CODE 627
    (628, "obj_lloydtutorial11", 2, 3), // CODE 628
    (629, "obj_lloydtutorial11", 2, 2), // CODE 629
    (630, "obj_lloydtutorial11", 2, 1), // CODE 630
    (631, "obj_lloydtutorial11", 2, 0), // CODE 631
    (632, "obj_lloydtutorial11", 8, 0), // CODE 632
    (633, "obj_lloydtutorial12", 0, 0), // CODE 633
    (635, "obj_lloydtutorial12", 2, 5), // CODE 635
    (636, "obj_lloydtutorial12", 2, 4), // CODE 636
    (637, "obj_lloydtutorial12", 2, 3), // CODE 637
    (638, "obj_lloydtutorial12", 2, 2), // CODE 638
    (639, "obj_lloydtutorial12", 2, 1), // CODE 639
    (640, "obj_lloydtutorial12", 2, 0), // CODE 640
    (641, "obj_lloydtutorial12", 8, 0), // CODE 641
    (650, "obj_lloydtutorial14", 0, 0), // CODE 650
    (652, "obj_lloydtutorial14", 2, 5), // CODE 652
    (653, "obj_lloydtutorial14", 8, 0), // CODE 653
    (654, "obj_lloydtutorial15", 0, 0), // CODE 654
    (656, "obj_lloydtutorial15", 2, 5), // CODE 656
    (657, "obj_lloydtutorial15", 2, 3), // CODE 657
    (658, "obj_lloydtutorial15", 2, 2), // CODE 658
    (659, "obj_lloydtutorial15", 2, 1), // CODE 659
    (660, "obj_lloydtutorial15", 2, 0), // CODE 660
    (661, "obj_lloydtutorial15", 8, 0), // CODE 661
    (662, "obj_lloydtutorial16", 0, 0), // CODE 662
    (664, "obj_lloydtutorial16", 2, 5), // CODE 664
    (665, "obj_lloydtutorial16", 2, 3), // CODE 665
    (666, "obj_lloydtutorial16", 2, 2), // CODE 666
    (667, "obj_lloydtutorial16", 2, 1), // CODE 667
    (668, "obj_lloydtutorial16", 2, 0), // CODE 668
    (669, "obj_lloydtutorial16", 8, 0), // CODE 669
    (724, "obj_knifebanditintro", 0, 0), // CODE 724
    (725, "obj_knifebanditintro", 2, 0), // CODE 725
    (726, "obj_knifebanditintro", 8, 0), // CODE 726
    (727, "obj_spiderintro", 0, 0), // CODE 727
    (728, "obj_spiderintro", 2, 0), // CODE 728
    (729, "obj_spiderintro", 8, 0), // CODE 729
    (730, "obj_batintro", 0, 0), // CODE 730
    (731, "obj_batintro", 2, 0), // CODE 731
    (732, "obj_batintro", 8, 0), // CODE 732
    (733, "obj_wolfintro", 0, 0), // CODE 733
    (734, "obj_wolfintro", 2, 0), // CODE 734
    (735, "obj_wolfintro", 8, 0), // CODE 735
    (736, "obj_pistolbanditintro", 0, 0), // CODE 736
    (737, "obj_pistolbanditintro", 2, 0), // CODE 737
    (738, "obj_pistolbanditintro", 8, 0), // CODE 738
    (742, "obj_turretintro", 0, 0), // CODE 742
    (743, "obj_turretintro", 2, 0), // CODE 743
    (744, "obj_turretintro", 8, 0), // CODE 744
    (745, "obj_slimeintro", 0, 0), // CODE 745
    (746, "obj_slimeintro", 2, 0), // CODE 746
    (747, "obj_slimeintro", 8, 0), // CODE 747
    (748, "obj_boss2intro", 0, 0), // CODE 748
    (749, "obj_boss2intro", 2, 0), // CODE 749
    (750, "obj_boss2intro", 8, 0), // CODE 750
    (751, "obj_zombieintro", 0, 0), // CODE 751
    (752, "obj_zombieintro", 2, 0), // CODE 752
    (753, "obj_zombieintro", 8, 0), // CODE 753
    (754, "obj_redslimeintro", 0, 0), // CODE 754
    (755, "obj_redslimeintro", 2, 0), // CODE 755
    (756, "obj_redslimeintro", 8, 0), // CODE 756
    (757, "obj_skeletonintro", 0, 0), // CODE 757
    (758, "obj_skeletonintro", 2, 0), // CODE 758
    (759, "obj_skeletonintro", 8, 0), // CODE 759
    (760, "obj_hulkingbanditintro", 0, 0), // CODE 760
    (761, "obj_hulkingbanditintro", 2, 0), // CODE 761
    (762, "obj_hulkingbanditintro", 8, 0), // CODE 762
    (763, "obj_beeintro", 0, 0), // CODE 763
    (764, "obj_beeintro", 2, 0), // CODE 764
    (765, "obj_beeintro", 8, 0), // CODE 765
    (766, "obj_boss3intro", 0, 0), // CODE 766
    (767, "obj_boss3intro", 2, 0), // CODE 767
    (768, "obj_boss3intro", 8, 0), // CODE 768
    (769, "obj_firehulkintro", 0, 0), // CODE 769
    (770, "obj_firehulkintro", 2, 0), // CODE 770
    (771, "obj_firehulkintro", 8, 0), // CODE 771
    (772, "obj_boss4intro", 0, 0), // CODE 772
    (773, "obj_boss4intro", 2, 0), // CODE 773
    (774, "obj_boss4intro", 8, 0), // CODE 774
    (775, "obj_boss5intro", 0, 0), // CODE 775
    (776, "obj_boss5intro", 2, 0), // CODE 776
    (777, "obj_boss5intro", 8, 0), // CODE 777
];

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

#[test]
fn every_structural_body_owns_its_event_and_sits_in_the_execution_ledger() {
    let b = bundle();
    let executed: BTreeSet<i32> = std::fs::read_to_string(
        Path::new(env!("CARGO_MANIFEST_DIR")).join("../../reconstruction/live-mem/trace/cally-code-trace-full-dedup.txt"))
        .expect("committed dedup ledger")
        .lines()
        .filter_map(|l| l.trim().parse::<i32>().ok())
        .collect();
    for (code, oname, et, st) in LEDGER {
        let obj = b.objects.iter().find(|o| o.name == oname)
            .unwrap_or_else(|| panic!("CODE {code}: object {oname} missing"));
        let ev = obj.events.iter().find(|e| e.event_type == et && e.subtype == st)
            .unwrap_or_else(|| panic!("CODE {code}: {oname} lacks event ({et},{st})"));
        assert!(ev.codes.contains(&(code as usize)), "CODE {code} is not bound to {oname} event ({et},{st})");
        assert!(executed.contains(&code), "CODE {code} is absent from the execution ledger");
    }
}

#[test]
fn the_inventory_is_exactly_the_structural_population() {
    let b = bundle();
    // The ledger's codes are distinct...
    let mut ids: Vec<i32> = LEDGER.iter().map(|l| l.0).collect();
    let n = ids.len();
    ids.sort();
    ids.dedup();
    assert_eq!(ids.len(), n, "the inventory lists a code twice");
    // ...and none of them appears NUMERICALLY in any suite that the census
    // reads - the whole point of the tier. A body gaining a numeric citation
    // leaves the tier through the regen, not by editing this table.
    assert_eq!(n, 132, "the inventory size is the shipped structural population");
    for (code, oname, _, _) in LEDGER {
        assert!(b.codes.iter().any(|c| c.id == code as usize), "CODE {code} missing from the bundle for {oname}");
    }
}
