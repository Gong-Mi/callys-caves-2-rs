//! Complete CODE17 obj_player Other_2, translated from all 1540 GML lines.
//! GML SHA-256: dc640893db3b07c6fe5ce278157d039c7223acea70e4d40133aaf8b83569a23b
//! Original bytecode SHA-256: 4b1f25be1bf7916fd002ea1747e5d5a92e545da6625ad9a290ce0d0f2384da75
//! Regenerate with scripts/generate_player_startup.py; unsupported syntax is fatal.
//! Explicit immediate calls preserve live host side effects and original ordering.
//! This is not original-file INI compatibility or a production startup host.
use crate::original_startup::StartupRuntime;

/// Run the recovered body. Host owns initialized fields, INI and ad policy.
/// Deliberately separate `if`s: >10 clamps AFTER damage branches; fractional
/// levels do not acquire an invented damage default. Never snapshot globals.
pub fn player_other2<R: StartupRuntime>(rt: &mut R) {
    // GML 1: AdColony_Init("app73023f81ce5d4f508a", "vz1aca9f7894b44cec93", "");
    rt.adcolony_init("app73023f81ce5d4f508a", "vz1aca9f7894b44cec93", "");
    // GML 2: global.warpfrommap = 0;
    rt.write_global("warpfrommap", 0.0);
    // GML 3: global.ending = 0;
    rt.write_global("ending", 0.0);
    // GML 4: if (file_exists("savefile.ini"))
    if rt.file_exists("savefile.ini") {
        // GML 5: {
        // GML 6: ini_open("savefile.ini");
        rt.ini_open("savefile.ini");
        // GML 7: global.talkedtolloyd1 = ini_read_real("Save", "talkedtolloyd1", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd1", 0.0);
        rt.write_global("talkedtolloyd1", value);
        // GML 8: global.talkedtolloyd2 = ini_read_real("Save", "talkedtolloyd2", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd2", 0.0);
        rt.write_global("talkedtolloyd2", value);
        // GML 9: global.talkedtolloyd3 = ini_read_real("Save", "talkedtolloyd3", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd3", 0.0);
        rt.write_global("talkedtolloyd3", value);
        // GML 10: global.talkedtolloyd4 = ini_read_real("Save", "talkedtolloyd4", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd4", 0.0);
        rt.write_global("talkedtolloyd4", value);
        // GML 11: global.talkedtolloyd5 = ini_read_real("Save", "talkedtolloyd5", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd5", 0.0);
        rt.write_global("talkedtolloyd5", value);
        // GML 12: global.talkedtolloyd6 = ini_read_real("Save", "talkedtolloyd6", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd6", 0.0);
        rt.write_global("talkedtolloyd6", value);
        // GML 13: global.talkedtolloyd7 = ini_read_real("Save", "talkedtolloyd7", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd7", 0.0);
        rt.write_global("talkedtolloyd7", value);
        // GML 14: global.talkedtolloyd8 = ini_read_real("Save", "talkedtolloyd8", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd8", 0.0);
        rt.write_global("talkedtolloyd8", value);
        // GML 15: global.talkedtolloyd9 = ini_read_real("Save", "talkedtolloyd9", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd9", 0.0);
        rt.write_global("talkedtolloyd9", value);
        // GML 16: global.talkedtolloyd10 = ini_read_real("Save", "talkedtolloyd10", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd10", 0.0);
        rt.write_global("talkedtolloyd10", value);
        // GML 17: global.talkedtolloyd11 = ini_read_real("Save", "talkedtolloyd11", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd11", 0.0);
        rt.write_global("talkedtolloyd11", value);
        // GML 18: global.talkedtolloyd12 = ini_read_real("Save", "talkedtolloyd12", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd12", 0.0);
        rt.write_global("talkedtolloyd12", value);
        // GML 19: global.talkedtolloyd13 = ini_read_real("Save", "talkedtolloyd13", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd13", 0.0);
        rt.write_global("talkedtolloyd13", value);
        // GML 20: global.talkedtolloyd14 = ini_read_real("Save", "talkedtolloyd14", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd14", 0.0);
        rt.write_global("talkedtolloyd14", value);
        // GML 21: global.talkedtolloyd15 = ini_read_real("Save", "talkedtolloyd15", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd15", 0.0);
        rt.write_global("talkedtolloyd15", value);
        // GML 22: global.timeplayed = ini_read_real("Save", "timeplayed", 0);
        let value = rt.ini_read_real("Save", "timeplayed", 0.0);
        rt.write_global("timeplayed", value);
        // GML 23: global.gemdropenabled = ini_read_real("Save", "gemdropenabled", 0);
        let value = rt.ini_read_real("Save", "gemdropenabled", 0.0);
        rt.write_global("gemdropenabled", value);
        // GML 24: global.poisonenabled = ini_read_real("Save", "poisonenabled", 0);
        let value = rt.ini_read_real("Save", "poisonenabled", 0.0);
        rt.write_global("poisonenabled", value);
        // GML 25: global.level = ini_read_real("Save", "current_level", 0);
        let value = rt.ini_read_real("Save", "current_level", 0.0);
        rt.write_global("level", value);
        // GML 26: global.maxhp = ini_read_real("Save", "current_maxhp", 0);
        let value = rt.ini_read_real("Save", "current_maxhp", 0.0);
        rt.write_global("maxhp", value);
        // GML 27: score = ini_read_real("Save", "current_score", 0);
        let value = rt.ini_read_real("Save", "current_score", 0.0);
        rt.write_self("score", value);
        // GML 28: global.boss1dead = ini_read_real("Save", "boss1dead", 0);
        let value = rt.ini_read_real("Save", "boss1dead", 0.0);
        rt.write_global("boss1dead", value);
        // GML 29: global.boss2dead = ini_read_real("Save", "boss2dead", 0);
        let value = rt.ini_read_real("Save", "boss2dead", 0.0);
        rt.write_global("boss2dead", value);
        // GML 30: global.boss3dead = ini_read_real("Save", "boss3dead", 0);
        let value = rt.ini_read_real("Save", "boss3dead", 0.0);
        rt.write_global("boss3dead", value);
        // GML 31: global.boss4dead = ini_read_real("Save", "boss4dead", 0);
        let value = rt.ini_read_real("Save", "boss4dead", 0.0);
        rt.write_global("boss4dead", value);
        // GML 32: global.boss5dead = ini_read_real("Save", "boss5dead", 0);
        let value = rt.ini_read_real("Save", "boss5dead", 0.0);
        rt.write_global("boss5dead", value);
        // GML 33: global.boss6dead = ini_read_real("Save", "boss6dead", 0);
        let value = rt.ini_read_real("Save", "boss6dead", 0.0);
        rt.write_global("boss6dead", value);
        // GML 34: global.xptolevelup = ini_read_real("Save", "xptolevelup", 0);
        let value = rt.ini_read_real("Save", "xptolevelup", 0.0);
        rt.write_global("xptolevelup", value);
        // GML 35: global.pistolbought = ini_read_real("Save", "pistolbought", 0);
        let value = rt.ini_read_real("Save", "pistolbought", 0.0);
        rt.write_global("pistolbought", value);
        // GML 36: global.energywavebought = ini_read_real("Save", "energywavebought", 0);
        let value = rt.ini_read_real("Save", "energywavebought", 0.0);
        rt.write_global("energywavebought", value);
        // GML 37: global.strengthupgradebought = ini_read_real("Save", "strengthupgradebought", 0);
        let value = rt.ini_read_real("Save", "strengthupgradebought", 0.0);
        rt.write_global("strengthupgradebought", value);
        // GML 38: global.strengthupgrade2bought = ini_read_real("Save", "strengthupgrade2bought", 0);
        let value = rt.ini_read_real("Save", "strengthupgrade2bought", 0.0);
        rt.write_global("strengthupgrade2bought", value);
        // GML 39: global.healthregenbought = ini_read_real("Save", "healthregenbought", 0);
        let value = rt.ini_read_real("Save", "healthregenbought", 0.0);
        rt.write_global("healthregenbought", value);
        // GML 40: global.shotgunbought = ini_read_real("Save", "shotgunbought", 0);
        let value = rt.ini_read_real("Save", "shotgunbought", 0.0);
        rt.write_global("shotgunbought", value);
        // GML 41: global.swordupgradebought = ini_read_real("Save", "swordupgradebought", 0);
        let value = rt.ini_read_real("Save", "swordupgradebought", 0.0);
        rt.write_global("swordupgradebought", value);
        // GML 42: global.swordupgrade2bought = ini_read_real("Save", "swordupgrade2bought", 0);
        let value = rt.ini_read_real("Save", "swordupgrade2bought", 0.0);
        rt.write_global("swordupgrade2bought", value);
        // GML 43: global.swordupgrade3bought = ini_read_real("Save", "swordupgrade3bought", 0);
        let value = rt.ini_read_real("Save", "swordupgrade3bought", 0.0);
        rt.write_global("swordupgrade3bought", value);
        // GML 44: global.powerupgradebought = ini_read_real("Save", "powerupgradebought", 0);
        let value = rt.ini_read_real("Save", "powerupgradebought", 0.0);
        rt.write_global("powerupgradebought", value);
        // GML 45: global.powerupgrade2bought = ini_read_real("Save", "powerupgrade2bought", 0);
        let value = rt.ini_read_real("Save", "powerupgrade2bought", 0.0);
        rt.write_global("powerupgrade2bought", value);
        // GML 46: global.powerupgrade3bought = ini_read_real("Save", "powerupgrade3bought", 0);
        let value = rt.ini_read_real("Save", "powerupgrade3bought", 0.0);
        rt.write_global("powerupgrade3bought", value);
        // GML 47: global.assaultriflebought = ini_read_real("Save", "assaultriflebought", 0);
        let value = rt.ini_read_real("Save", "assaultriflebought", 0.0);
        rt.write_global("assaultriflebought", value);
        // GML 48: global.rocketbought = ini_read_real("Save", "rocketbought", 0);
        let value = rt.ini_read_real("Save", "rocketbought", 0.0);
        rt.write_global("rocketbought", value);
        // GML 49: global.laserbought = ini_read_real("Save", "laserbought", 0);
        let value = rt.ini_read_real("Save", "laserbought", 0.0);
        rt.write_global("laserbought", value);
        // GML 50: global.icegunbought = ini_read_real("Save", "icegunbought", 0);
        let value = rt.ini_read_real("Save", "icegunbought", 0.0);
        rt.write_global("icegunbought", value);
        // GML 51: global.bladegunbought = ini_read_real("Save", "bladegunbought", 0);
        let value = rt.ini_read_real("Save", "bladegunbought", 0.0);
        rt.write_global("bladegunbought", value);
        // GML 52: global.flamethrowerbought = ini_read_real("Save", "flamethrowerbought", 0);
        let value = rt.ini_read_real("Save", "flamethrowerbought", 0.0);
        rt.write_global("flamethrowerbought", value);
        // GML 53: global.bowbought = ini_read_real("Save", "bowbought", 0);
        let value = rt.ini_read_real("Save", "bowbought", 0.0);
        rt.write_global("bowbought", value);
        // GML 54: global.bombgunbought = ini_read_real("Save", "bombgunbought", 0);
        let value = rt.ini_read_real("Save", "bombgunbought", 0.0);
        rt.write_global("bombgunbought", value);
        // GML 55: global.bombgunxp = ini_read_real("Save", "bomgunxp", 0);
        let value = rt.ini_read_real("Save", "bomgunxp", 0.0);
        rt.write_global("bombgunxp", value);
        // GML 56: global.bombgunxptolevelup = ini_read_real("Save", "bombgunxptolevelup", 0);
        let value = rt.ini_read_real("Save", "bombgunxptolevelup", 0.0);
        rt.write_global("bombgunxptolevelup", value);
        // GML 57: global.bombgunlevel = ini_read_real("Save", "bombgunlevel", 0);
        let value = rt.ini_read_real("Save", "bombgunlevel", 0.0);
        rt.write_global("bombgunlevel", value);
        // GML 58: global.bladegunxp = ini_read_real("Save", "bladegunxp", 0);
        let value = rt.ini_read_real("Save", "bladegunxp", 0.0);
        rt.write_global("bladegunxp", value);
        // GML 59: global.bladegunxptolevelup = ini_read_real("Save", "bladegunxptolevelup", 0);
        let value = rt.ini_read_real("Save", "bladegunxptolevelup", 0.0);
        rt.write_global("bladegunxptolevelup", value);
        // GML 60: global.flamethrowerxp = ini_read_real("Save", "flamethrowerxp", 0);
        let value = rt.ini_read_real("Save", "flamethrowerxp", 0.0);
        rt.write_global("flamethrowerxp", value);
        // GML 61: global.flamethrowerxptolevelup = ini_read_real("Save", "flamethrowerxptolevelup", 0);
        let value = rt.ini_read_real("Save", "flamethrowerxptolevelup", 0.0);
        rt.write_global("flamethrowerxptolevelup", value);
        // GML 62: global.boomerangbought = ini_read_real("Save", "boomerangbought", 0);
        let value = rt.ini_read_real("Save", "boomerangbought", 0.0);
        rt.write_global("boomerangbought", value);
        // GML 63: global.boomerangxp = ini_read_real("Save", "boomerangxp", 0);
        let value = rt.ini_read_real("Save", "boomerangxp", 0.0);
        rt.write_global("boomerangxp", value);
        // GML 64: global.boomeranglevel = ini_read_real("Save", "boomeranglevel", 0);
        let value = rt.ini_read_real("Save", "boomeranglevel", 0.0);
        rt.write_global("boomeranglevel", value);
        // GML 65: global.boomerangxptolevelup = ini_read_real("Save", "boomerangxptolevelup", 0);
        let value = rt.ini_read_real("Save", "boomerangxptolevelup", 0.0);
        rt.write_global("boomerangxptolevelup", value);
        // GML 66: global.spikegunbought = ini_read_real("Save", "spikegunbought", 0);
        let value = rt.ini_read_real("Save", "spikegunbought", 0.0);
        rt.write_global("spikegunbought", value);
        // GML 67: global.spikegunxp = ini_read_real("Save", "spikegunxp", 0);
        let value = rt.ini_read_real("Save", "spikegunxp", 0.0);
        rt.write_global("spikegunxp", value);
        // GML 68: global.spikegunlevel = ini_read_real("Save", "spikegunlevel", 0);
        let value = rt.ini_read_real("Save", "spikegunlevel", 0.0);
        rt.write_global("spikegunlevel", value);
        // GML 69: global.spikegunxptolevelup = ini_read_real("Save", "spikegunxptolevelup", 0);
        let value = rt.ini_read_real("Save", "spikegunxptolevelup", 0.0);
        rt.write_global("spikegunxptolevelup", value);
        // GML 70: global.bowxp = ini_read_real("Save", "bowxp", 0);
        let value = rt.ini_read_real("Save", "bowxp", 0.0);
        rt.write_global("bowxp", value);
        // GML 71: global.bowxptolevelup = ini_read_real("Save", "bowxptolevelup", 0);
        let value = rt.ini_read_real("Save", "bowxptolevelup", 0.0);
        rt.write_global("bowxptolevelup", value);
        // GML 72: global.sword = ini_read_real("Save", "sword", 0);
        let value = rt.ini_read_real("Save", "sword", 0.0);
        rt.write_global("sword", value);
        // GML 73: global.triplejumpbought = ini_read_real("Save", "triplejumpbought", 0);
        let value = rt.ini_read_real("Save", "triplejumpbought", 0.0);
        rt.write_global("triplejumpbought", value);
        // GML 74: global.tjumpactive = ini_read_real("Save", "triplejumpactive", 0);
        let value = rt.ini_read_real("Save", "triplejumpactive", 0.0);
        rt.write_global("tjumpactive", value);
        // GML 75: global.coinmultiplier2bought = ini_read_real("Save", "coinmultiplier2bought", 0);
        let value = rt.ini_read_real("Save", "coinmultiplier2bought", 0.0);
        rt.write_global("coinmultiplier2bought", value);
        // GML 76: global.coinmultiplier5bought = ini_read_real("Save", "coinmultiplier5bought", 0);
        let value = rt.ini_read_real("Save", "coinmultiplier5bought", 0.0);
        rt.write_global("coinmultiplier5bought", value);
        // GML 77: global.maxhpupgradebought = ini_read_real("Save", "maxhpupgradebought", 0);
        let value = rt.ini_read_real("Save", "maxhpupgradebought", 0.0);
        rt.write_global("maxhpupgradebought", value);
        // GML 78: global.maxhpupgrade2bought = ini_read_real("Save", "maxhpupgrade2bought", 0);
        let value = rt.ini_read_real("Save", "maxhpupgrade2bought", 0.0);
        rt.write_global("maxhpupgrade2bought", value);
        // GML 79: global.drawchangepistol4 = ini_read_real("Save", "drawchangepistol4", 0);
        let value = rt.ini_read_real("Save", "drawchangepistol4", 0.0);
        rt.write_global("drawchangepistol4", value);
        // GML 80: global.drawchangeshotgun4 = ini_read_real("Save", "drawchangeshotgun4", 0);
        let value = rt.ini_read_real("Save", "drawchangeshotgun4", 0.0);
        rt.write_global("drawchangeshotgun4", value);
        // GML 81: global.drawchangeassaultrifle4 = ini_read_real("Save", "drawchangeassaultrifle4", 0);
        let value = rt.ini_read_real("Save", "drawchangeassaultrifle4", 0.0);
        rt.write_global("drawchangeassaultrifle4", value);
        // GML 82: global.drawchangerocket4 = ini_read_real("Save", "drawchangerocket4", 0);
        let value = rt.ini_read_real("Save", "drawchangerocket4", 0.0);
        rt.write_global("drawchangerocket4", value);
        // GML 83: global.drawchangelaser4 = ini_read_real("Save", "drawchangelaser4", 0);
        let value = rt.ini_read_real("Save", "drawchangelaser4", 0.0);
        rt.write_global("drawchangelaser4", value);
        // GML 84: global.drawchangeicegun4 = ini_read_real("Save", "drawchangeicegun4", 0);
        let value = rt.ini_read_real("Save", "drawchangeicegun4", 0.0);
        rt.write_global("drawchangeicegun4", value);
        // GML 85: global.drawchangebow4 = ini_read_real("Save", "drawchangebow4", 0);
        let value = rt.ini_read_real("Save", "drawchangebow4", 0.0);
        rt.write_global("drawchangebow4", value);
        // GML 86: global.drawchangebladegun4 = ini_read_real("Save", "drawchangebladegun4", 0);
        let value = rt.ini_read_real("Save", "drawchangebladegun4", 0.0);
        rt.write_global("drawchangebladegun4", value);
        // GML 87: global.drawchangeflamethrower4 = ini_read_real("Save", "drawchangeflamethrower4", 0);
        let value = rt.ini_read_real("Save", "drawchangeflamethrower4", 0.0);
        rt.write_global("drawchangeflamethrower4", value);
        // GML 88: global.drawchangeboomerang4 = ini_read_real("Save", "drawchangeboomerang4", 0);
        let value = rt.ini_read_real("Save", "drawchangeboomerang4", 0.0);
        rt.write_global("drawchangeboomerang4", value);
        // GML 89: global.drawchangespikegun4 = ini_read_real("Save", "drawchangespikegun4", 0);
        let value = rt.ini_read_real("Save", "drawchangespikegun4", 0.0);
        rt.write_global("drawchangespikegun4", value);
        // GML 90: global.drawchangebombgun4 = ini_read_real("Save", "drawchangebombgun4", 0);
        let value = rt.ini_read_real("Save", "drawchangebombgun4", 0.0);
        rt.write_global("drawchangebombgun4", value);
        // GML 91: global.drawchangepistol7 = ini_read_real("Save", "drawchangepistol7", 0);
        let value = rt.ini_read_real("Save", "drawchangepistol7", 0.0);
        rt.write_global("drawchangepistol7", value);
        // GML 92: global.drawchangeshotgun7 = ini_read_real("Save", "drawchangeshotgun7", 0);
        let value = rt.ini_read_real("Save", "drawchangeshotgun7", 0.0);
        rt.write_global("drawchangeshotgun7", value);
        // GML 93: global.drawchangeassaultrifle7 = ini_read_real("Save", "drawchangeassaultrifle7", 0);
        let value = rt.ini_read_real("Save", "drawchangeassaultrifle7", 0.0);
        rt.write_global("drawchangeassaultrifle7", value);
        // GML 94: global.drawchangerocket7 = ini_read_real("Save", "drawchangerocket7", 0);
        let value = rt.ini_read_real("Save", "drawchangerocket7", 0.0);
        rt.write_global("drawchangerocket7", value);
        // GML 95: global.drawchangelaser7 = ini_read_real("Save", "drawchangelaser7", 0);
        let value = rt.ini_read_real("Save", "drawchangelaser7", 0.0);
        rt.write_global("drawchangelaser7", value);
        // GML 96: global.drawchangeicegun7 = ini_read_real("Save", "drawchangeicegun7", 0);
        let value = rt.ini_read_real("Save", "drawchangeicegun7", 0.0);
        rt.write_global("drawchangeicegun7", value);
        // GML 97: global.drawchangebow7 = ini_read_real("Save", "drawchangebow7", 0);
        let value = rt.ini_read_real("Save", "drawchangebow7", 0.0);
        rt.write_global("drawchangebow7", value);
        // GML 98: global.drawchangebladegun7 = ini_read_real("Save", "drawchangebladegun7", 0);
        let value = rt.ini_read_real("Save", "drawchangebladegun7", 0.0);
        rt.write_global("drawchangebladegun7", value);
        // GML 99: global.drawchangeflamethrower7 = ini_read_real("Save", "drawchangeflamethrower7", 0);
        let value = rt.ini_read_real("Save", "drawchangeflamethrower7", 0.0);
        rt.write_global("drawchangeflamethrower7", value);
        // GML 100: global.drawchangeboomerang7 = ini_read_real("Save", "drawchangeboomerang7", 0);
        let value = rt.ini_read_real("Save", "drawchangeboomerang7", 0.0);
        rt.write_global("drawchangeboomerang7", value);
        // GML 101: global.drawchangespikegun7 = ini_read_real("Save", "drawchangespikegun7", 0);
        let value = rt.ini_read_real("Save", "drawchangespikegun7", 0.0);
        rt.write_global("drawchangespikegun7", value);
        // GML 102: global.drawchangebombgun7 = ini_read_real("Save", "drawchangebombgun7", 0);
        let value = rt.ini_read_real("Save", "drawchangebombgun7", 0.0);
        rt.write_global("drawchangebombgun7", value);
        // GML 103: global.drawchangepistol10 = ini_read_real("Save", "drawchangepistol10", 0);
        let value = rt.ini_read_real("Save", "drawchangepistol10", 0.0);
        rt.write_global("drawchangepistol10", value);
        // GML 104: global.drawchangeshotgun10 = ini_read_real("Save", "drawchangeshotgun10", 0);
        let value = rt.ini_read_real("Save", "drawchangeshotgun10", 0.0);
        rt.write_global("drawchangeshotgun10", value);
        // GML 105: global.drawchangeassaultrifle10 = ini_read_real("Save", "drawchangeassaultrifle10", 0);
        let value = rt.ini_read_real("Save", "drawchangeassaultrifle10", 0.0);
        rt.write_global("drawchangeassaultrifle10", value);
        // GML 106: global.drawchangerocket10 = ini_read_real("Save", "drawchangerocket10", 0);
        let value = rt.ini_read_real("Save", "drawchangerocket10", 0.0);
        rt.write_global("drawchangerocket10", value);
        // GML 107: global.drawchangelaser10 = ini_read_real("Save", "drawchangelaser10", 0);
        let value = rt.ini_read_real("Save", "drawchangelaser10", 0.0);
        rt.write_global("drawchangelaser10", value);
        // GML 108: global.drawchangeicegun10 = ini_read_real("Save", "drawchangeicegun10", 0);
        let value = rt.ini_read_real("Save", "drawchangeicegun10", 0.0);
        rt.write_global("drawchangeicegun10", value);
        // GML 109: global.drawchangebow10 = ini_read_real("Save", "drawchangebow10", 0);
        let value = rt.ini_read_real("Save", "drawchangebow10", 0.0);
        rt.write_global("drawchangebow10", value);
        // GML 110: global.drawchangebladegun10 = ini_read_real("Save", "drawchangebladegun10", 0);
        let value = rt.ini_read_real("Save", "drawchangebladegun10", 0.0);
        rt.write_global("drawchangebladegun10", value);
        // GML 111: global.drawchangeflamethrower10 = ini_read_real("Save", "drawchangeflamethrower10", 0);
        let value = rt.ini_read_real("Save", "drawchangeflamethrower10", 0.0);
        rt.write_global("drawchangeflamethrower10", value);
        // GML 112: global.drawchangeboomerang10 = ini_read_real("Save", "drawchangeboomerang10", 0);
        let value = rt.ini_read_real("Save", "drawchangeboomerang10", 0.0);
        rt.write_global("drawchangeboomerang10", value);
        // GML 113: global.drawchangespikegun10 = ini_read_real("Save", "drawchangespikegun10", 0);
        let value = rt.ini_read_real("Save", "drawchangespikegun10", 0.0);
        rt.write_global("drawchangespikegun10", value);
        // GML 114: global.drawchangebombgun10 = ini_read_real("Save", "drawchangebombgun10", 0);
        let value = rt.ini_read_real("Save", "drawchangebombgun10", 0.0);
        rt.write_global("drawchangebombgun10", value);
        // GML 115: global.experience = ini_read_real("Save", "current_XP", 0);
        let value = rt.ini_read_real("Save", "current_XP", 0.0);
        rt.write_global("experience", value);
        // GML 116: global.haskey = ini_read_real("Save", "haskey", 0);
        let value = rt.ini_read_real("Save", "haskey", 0.0);
        rt.write_global("haskey", value);
        // GML 117: global.pistolxp = ini_read_real("Save", "pistolxp", 0);
        let value = rt.ini_read_real("Save", "pistolxp", 0.0);
        rt.write_global("pistolxp", value);
        // GML 118: global.pistolxptolevelup = ini_read_real("Save", "pistolxptolevelup", 0);
        let value = rt.ini_read_real("Save", "pistolxptolevelup", 0.0);
        rt.write_global("pistolxptolevelup", value);
        // GML 119: global.shotgunxp = ini_read_real("Save", "shotgunxp", 0);
        let value = rt.ini_read_real("Save", "shotgunxp", 0.0);
        rt.write_global("shotgunxp", value);
        // GML 120: global.shotgunxptolevelup = ini_read_real("Save", "shotgunxptolevelup", 0);
        let value = rt.ini_read_real("Save", "shotgunxptolevelup", 0.0);
        rt.write_global("shotgunxptolevelup", value);
        // GML 121: global.assaultriflexp = ini_read_real("Save", "assaultriflexp", 0);
        let value = rt.ini_read_real("Save", "assaultriflexp", 0.0);
        rt.write_global("assaultriflexp", value);
        // GML 122: global.assaultriflexptolevelup = ini_read_real("Save", "assaultriflexptolevelup", 0);
        let value = rt.ini_read_real("Save", "assaultriflexptolevelup", 0.0);
        rt.write_global("assaultriflexptolevelup", value);
        // GML 123: global.rocketxp = ini_read_real("Save", "rocketxp", 0);
        let value = rt.ini_read_real("Save", "rocketxp", 0.0);
        rt.write_global("rocketxp", value);
        // GML 124: global.rocketxptolevelup = ini_read_real("Save", "rocketxptolevelup", 0);
        let value = rt.ini_read_real("Save", "rocketxptolevelup", 0.0);
        rt.write_global("rocketxptolevelup", value);
        // GML 125: global.laserxp = ini_read_real("Save", "laserxp", 0);
        let value = rt.ini_read_real("Save", "laserxp", 0.0);
        rt.write_global("laserxp", value);
        // GML 126: global.laserxptolevelup = ini_read_real("Save", "laserxptolevelup", 0);
        let value = rt.ini_read_real("Save", "laserxptolevelup", 0.0);
        rt.write_global("laserxptolevelup", value);
        // GML 127: global.icegunxp = ini_read_real("Save", "icegunxp", 0);
        let value = rt.ini_read_real("Save", "icegunxp", 0.0);
        rt.write_global("icegunxp", value);
        // GML 128: global.icegunxptolevelup = ini_read_real("Save", "icegunxptolevelup", 0);
        let value = rt.ini_read_real("Save", "icegunxptolevelup", 0.0);
        rt.write_global("icegunxptolevelup", value);
        // GML 129: global.pistollevel = ini_read_real("Save", "pistollevel", 0);
        let value = rt.ini_read_real("Save", "pistollevel", 0.0);
        rt.write_global("pistollevel", value);
        // GML 130: global.shotgunlevel = ini_read_real("Save", "shotgunlevel", 0);
        let value = rt.ini_read_real("Save", "shotgunlevel", 0.0);
        rt.write_global("shotgunlevel", value);
        // GML 131: global.assaultriflelevel = ini_read_real("Save", "assaultriflelevel", 0);
        let value = rt.ini_read_real("Save", "assaultriflelevel", 0.0);
        rt.write_global("assaultriflelevel", value);
        // GML 132: global.rocketlevel = ini_read_real("Save", "rocketlevel", 0);
        let value = rt.ini_read_real("Save", "rocketlevel", 0.0);
        rt.write_global("rocketlevel", value);
        // GML 133: global.laserlevel = ini_read_real("Save", "laserlevel", 0);
        let value = rt.ini_read_real("Save", "laserlevel", 0.0);
        rt.write_global("laserlevel", value);
        // GML 134: global.icegunlevel = ini_read_real("Save", "icegunlevel", 0);
        let value = rt.ini_read_real("Save", "icegunlevel", 0.0);
        rt.write_global("icegunlevel", value);
        // GML 135: global.bowlevel = ini_read_real("Save", "bowlevel", 0);
        let value = rt.ini_read_real("Save", "bowlevel", 0.0);
        rt.write_global("bowlevel", value);
        // GML 136: global.bladegunlevel = ini_read_real("Save", "bladegunlevel", 0);
        let value = rt.ini_read_real("Save", "bladegunlevel", 0.0);
        rt.write_global("bladegunlevel", value);
        // GML 137: global.flamethrowerlevel = ini_read_real("Save", "flamethrowerlevel", 0);
        let value = rt.ini_read_real("Save", "flamethrowerlevel", 0.0);
        rt.write_global("flamethrowerlevel", value);
        // GML 138: global.knifebanditskilled = ini_read_real("Save", "knifebanditskilled", 0);
        let value = rt.ini_read_real("Save", "knifebanditskilled", 0.0);
        rt.write_global("knifebanditskilled", value);
        // GML 139: global.pistolthugskilled = ini_read_real("Save", "pistolthugskilled", 0);
        let value = rt.ini_read_real("Save", "pistolthugskilled", 0.0);
        rt.write_global("pistolthugskilled", value);
        // GML 140: global.chomperbotkilled = ini_read_real("Save", "chomperbotkilled", 0);
        let value = rt.ini_read_real("Save", "chomperbotkilled", 0.0);
        rt.write_global("chomperbotkilled", value);
        // GML 141: global.greenslimeskilled = ini_read_real("Save", "greenslimeskilled", 0);
        let value = rt.ini_read_real("Save", "greenslimeskilled", 0.0);
        rt.write_global("greenslimeskilled", value);
        // GML 142: global.wolfkilled = ini_read_real("Save", "wolfkilled", 0);
        let value = rt.ini_read_real("Save", "wolfkilled", 0.0);
        rt.write_global("wolfkilled", value);
        // GML 143: global.fireslimeskilled = ini_read_real("Save", "fireslimeskilled", 0);
        let value = rt.ini_read_real("Save", "fireslimeskilled", 0.0);
        rt.write_global("fireslimeskilled", value);
        // GML 144: global.hulkingbanditskilled = ini_read_real("Save", "hulkingbanditskilled", 0);
        let value = rt.ini_read_real("Save", "hulkingbanditskilled", 0.0);
        rt.write_global("hulkingbanditskilled", value);
        // GML 145: global.ghostskilled = ini_read_real("Save", "ghostskilled", 0);
        let value = rt.ini_read_real("Save", "ghostskilled", 0.0);
        rt.write_global("ghostskilled", value);
        // GML 146: global.skeletonskilled = ini_read_real("Save", "skeletonskilled", 0);
        let value = rt.ini_read_real("Save", "skeletonskilled", 0.0);
        rt.write_global("skeletonskilled", value);
        // GML 147: global.zombieskilled = ini_read_real("Save", "zombieskilled", 0);
        let value = rt.ini_read_real("Save", "zombieskilled", 0.0);
        rt.write_global("zombieskilled", value);
        // GML 148: global.firehulkskilled = ini_read_real("Save", "firehulkskilled", 0);
        let value = rt.ini_read_real("Save", "firehulkskilled", 0.0);
        rt.write_global("firehulkskilled", value);
        // GML 149: global.batskilled = ini_read_real("Save", "batskilled", 0);
        let value = rt.ini_read_real("Save", "batskilled", 0.0);
        rt.write_global("batskilled", value);
        // GML 150: global.trapskilled = ini_read_real("Save", "trapskilled", 0);
        let value = rt.ini_read_real("Save", "trapskilled", 0.0);
        rt.write_global("trapskilled", value);
        // GML 151: global.bearskilled = ini_read_real("Save", "bearskilled", 0);
        let value = rt.ini_read_real("Save", "bearskilled", 0.0);
        rt.write_global("bearskilled", value);
        // GML 152: global.enemieskilled = ini_read_real("Save", "enemieskilled", 0);
        let value = rt.ini_read_real("Save", "enemieskilled", 0.0);
        rt.write_global("enemieskilled", value);
        // GML 153: global.boughtallguns = ini_read_real("Save", "boughtallguns", 0);
        let value = rt.ini_read_real("Save", "boughtallguns", 0.0);
        rt.write_global("boughtallguns", value);
        // GML 154: global.triplejumpachievement = ini_read_real("Save", "triplejumpachievement", 0);
        let value = rt.ini_read_real("Save", "triplejumpachievement", 0.0);
        rt.write_global("triplejumpachievement", value);
        // GML 155: global.boughtallupgrades = ini_read_real("Save", "boughtallupgrades", 0);
        let value = rt.ini_read_real("Save", "boughtallupgrades", 0.0);
        rt.write_global("boughtallupgrades", value);
        // GML 156: global.boughteverything = ini_read_real("Save", "boughteverything", 0);
        let value = rt.ini_read_real("Save", "boughteverything", 0.0);
        rt.write_global("boughteverything", value);
        // GML 157: global.achievemaxhp = ini_read_real("Save", "achievemaxhp", 0);
        let value = rt.ini_read_real("Save", "achievemaxhp", 0.0);
        rt.write_global("achievemaxhp", value);
        // GML 158: global.getmoney = ini_read_real("Save", "getmoney", 0);
        let value = rt.ini_read_real("Save", "getmoney", 0.0);
        rt.write_global("getmoney", value);
        // GML 159: global.hitmaxlevel = ini_read_real("Save", "hitmaxlevel", 0);
        let value = rt.ini_read_real("Save", "hitmaxlevel", 0.0);
        rt.write_global("hitmaxlevel", value);
        // GML 160: global.weaponswapped = ini_read_real("Save", "weaponswapped", 0);
        let value = rt.ini_read_real("Save", "weaponswapped", 0.0);
        rt.write_global("weaponswapped", value);
        // GML 161: global.coinmultiply = ini_read_real("Save", "coinmultiply", 0);
        let value = rt.ini_read_real("Save", "coinmultiply", 0.0);
        rt.write_global("coinmultiply", value);
        // GML 162: global.roomtownvisited = ini_read_real("Save", "roomtownvisited", 0);
        let value = rt.ini_read_real("Save", "roomtownvisited", 0.0);
        rt.write_global("roomtownvisited", value);
        // GML 163: global.level1visited = ini_read_real("Save", "level1visited", 0);
        let value = rt.ini_read_real("Save", "level1visited", 0.0);
        rt.write_global("level1visited", value);
        // GML 164: global.level2visited = ini_read_real("Save", "level2visited", 0);
        let value = rt.ini_read_real("Save", "level2visited", 0.0);
        rt.write_global("level2visited", value);
        // GML 165: global.level3visited = ini_read_real("Save", "level3visited", 0);
        let value = rt.ini_read_real("Save", "level3visited", 0.0);
        rt.write_global("level3visited", value);
        // GML 166: global.level4visited = ini_read_real("Save", "level4visited", 0);
        let value = rt.ini_read_real("Save", "level4visited", 0.0);
        rt.write_global("level4visited", value);
        // GML 167: global.level5visited = ini_read_real("Save", "level5visited", 0);
        let value = rt.ini_read_real("Save", "level5visited", 0.0);
        rt.write_global("level5visited", value);
        // GML 168: global.level6visited = ini_read_real("Save", "level6visited", 0);
        let value = rt.ini_read_real("Save", "level6visited", 0.0);
        rt.write_global("level6visited", value);
        // GML 169: global.level7visited = ini_read_real("Save", "level7visited", 0);
        let value = rt.ini_read_real("Save", "level7visited", 0.0);
        rt.write_global("level7visited", value);
        // GML 170: global.level8visited = ini_read_real("Save", "level8visited", 0);
        let value = rt.ini_read_real("Save", "level8visited", 0.0);
        rt.write_global("level8visited", value);
        // GML 171: global.level8avisited = ini_read_real("Save", "level8avisited", 0);
        let value = rt.ini_read_real("Save", "level8avisited", 0.0);
        rt.write_global("level8avisited", value);
        // GML 172: global.boss1visited = ini_read_real("Save", "boss1visited", 0);
        let value = rt.ini_read_real("Save", "boss1visited", 0.0);
        rt.write_global("boss1visited", value);
        // GML 173: global.level9visited = ini_read_real("Save", "level9visited", 0);
        let value = rt.ini_read_real("Save", "level9visited", 0.0);
        rt.write_global("level9visited", value);
        // GML 174: global.level9avisited = ini_read_real("Save", "level9avisited", 0);
        let value = rt.ini_read_real("Save", "level9avisited", 0.0);
        rt.write_global("level9avisited", value);
        // GML 175: global.level10visited = ini_read_real("Save", "level10visited", 0);
        let value = rt.ini_read_real("Save", "level10visited", 0.0);
        rt.write_global("level10visited", value);
        // GML 176: global.level11visited = ini_read_real("Save", "level11visited", 0);
        let value = rt.ini_read_real("Save", "level11visited", 0.0);
        rt.write_global("level11visited", value);
        // GML 177: global.level11avisited = ini_read_real("Save", "level11avisited", 0);
        let value = rt.ini_read_real("Save", "level11avisited", 0.0);
        rt.write_global("level11avisited", value);
        // GML 178: global.level12visited = ini_read_real("Save", "level12visited", 0);
        let value = rt.ini_read_real("Save", "level12visited", 0.0);
        rt.write_global("level12visited", value);
        // GML 179: global.level13visited = ini_read_real("Save", "level13visited", 0);
        let value = rt.ini_read_real("Save", "level13visited", 0.0);
        rt.write_global("level13visited", value);
        // GML 180: global.level13avisited = ini_read_real("Save", "level13avisited", 0);
        let value = rt.ini_read_real("Save", "level13avisited", 0.0);
        rt.write_global("level13avisited", value);
        // GML 181: global.level14visited = ini_read_real("Save", "level14visited", 0);
        let value = rt.ini_read_real("Save", "level14visited", 0.0);
        rt.write_global("level14visited", value);
        // GML 182: global.level14avisited = ini_read_real("Save", "level14avisited", 0);
        let value = rt.ini_read_real("Save", "level14avisited", 0.0);
        rt.write_global("level14avisited", value);
        // GML 183: global.level15visited = ini_read_real("Save", "level15visited", 0);
        let value = rt.ini_read_real("Save", "level15visited", 0.0);
        rt.write_global("level15visited", value);
        // GML 184: global.level15avisited = ini_read_real("Save", "level15avisited", 0);
        let value = rt.ini_read_real("Save", "level15avisited", 0.0);
        rt.write_global("level15avisited", value);
        // GML 185: global.level16visited = ini_read_real("Save", "level16visited", 0);
        let value = rt.ini_read_real("Save", "level16visited", 0.0);
        rt.write_global("level16visited", value);
        // GML 186: global.level16avisited = ini_read_real("Save", "level16avisited", 0);
        let value = rt.ini_read_real("Save", "level16avisited", 0.0);
        rt.write_global("level16avisited", value);
        // GML 187: global.level17visited = ini_read_real("Save", "level17visited", 0);
        let value = rt.ini_read_real("Save", "level17visited", 0.0);
        rt.write_global("level17visited", value);
        // GML 188: global.level17avisited = ini_read_real("Save", "level17avisited", 0);
        let value = rt.ini_read_real("Save", "level17avisited", 0.0);
        rt.write_global("level17avisited", value);
        // GML 189: global.boss2visited = ini_read_real("Save", "boss2visited", 0);
        let value = rt.ini_read_real("Save", "boss2visited", 0.0);
        rt.write_global("boss2visited", value);
        // GML 190: global.room31visited = ini_read_real("Save", "room31visited", 0);
        let value = rt.ini_read_real("Save", "room31visited", 0.0);
        rt.write_global("room31visited", value);
        // GML 191: global.room32visited = ini_read_real("Save", "room32visited", 0);
        let value = rt.ini_read_real("Save", "room32visited", 0.0);
        rt.write_global("room32visited", value);
        // GML 192: global.room33visited = ini_read_real("Save", "room33visited", 0);
        let value = rt.ini_read_real("Save", "room33visited", 0.0);
        rt.write_global("room33visited", value);
        // GML 193: global.room34visited = ini_read_real("Save", "room34visited", 0);
        let value = rt.ini_read_real("Save", "room34visited", 0.0);
        rt.write_global("room34visited", value);
        // GML 194: global.room35visited = ini_read_real("Save", "room35visited", 0);
        let value = rt.ini_read_real("Save", "room35visited", 0.0);
        rt.write_global("room35visited", value);
        // GML 195: global.room36visited = ini_read_real("Save", "room36visited", 0);
        let value = rt.ini_read_real("Save", "room36visited", 0.0);
        rt.write_global("room36visited", value);
        // GML 196: global.room37visited = ini_read_real("Save", "room37visited", 0);
        let value = rt.ini_read_real("Save", "room37visited", 0.0);
        rt.write_global("room37visited", value);
        // GML 197: global.room38visited = ini_read_real("Save", "room38visited", 0);
        let value = rt.ini_read_real("Save", "room38visited", 0.0);
        rt.write_global("room38visited", value);
        // GML 198: global.room39visited = ini_read_real("Save", "room39visited", 0);
        let value = rt.ini_read_real("Save", "room39visited", 0.0);
        rt.write_global("room39visited", value);
        // GML 199: global.room40visited = ini_read_real("Save", "room40visited", 0);
        let value = rt.ini_read_real("Save", "room40visited", 0.0);
        rt.write_global("room40visited", value);
        // GML 200: global.room41visited = ini_read_real("Save", "room41visited", 0);
        let value = rt.ini_read_real("Save", "room41visited", 0.0);
        rt.write_global("room41visited", value);
        // GML 201: global.room42visited = ini_read_real("Save", "room42visited", 0);
        let value = rt.ini_read_real("Save", "room42visited", 0.0);
        rt.write_global("room42visited", value);
        // GML 202: global.room43visited = ini_read_real("Save", "room43visited", 0);
        let value = rt.ini_read_real("Save", "room43visited", 0.0);
        rt.write_global("room43visited", value);
        // GML 203: global.room44visited = ini_read_real("Save", "room44visited", 0);
        let value = rt.ini_read_real("Save", "room44visited", 0.0);
        rt.write_global("room44visited", value);
        // GML 204: global.room45visited = ini_read_real("Save", "room45visited", 0);
        let value = rt.ini_read_real("Save", "room45visited", 0.0);
        rt.write_global("room45visited", value);
        // GML 205: global.room46visited = ini_read_real("Save", "room46visited", 0);
        let value = rt.ini_read_real("Save", "room46visited", 0.0);
        rt.write_global("room46visited", value);
        // GML 206: global.room47visited = ini_read_real("Save", "room47visited", 0);
        let value = rt.ini_read_real("Save", "room47visited", 0.0);
        rt.write_global("room47visited", value);
        // GML 207: global.room48visited = ini_read_real("Save", "room48visited", 0);
        let value = rt.ini_read_real("Save", "room48visited", 0.0);
        rt.write_global("room48visited", value);
        // GML 208: global.room49visited = ini_read_real("Save", "room49visited", 0);
        let value = rt.ini_read_real("Save", "room49visited", 0.0);
        rt.write_global("room49visited", value);
        // GML 209: global.room50visited = ini_read_real("Save", "room50visited", 0);
        let value = rt.ini_read_real("Save", "room50visited", 0.0);
        rt.write_global("room50visited", value);
        // GML 210: global.boss3visited = ini_read_real("Save", "boss3visited", 0);
        let value = rt.ini_read_real("Save", "boss3visited", 0.0);
        rt.write_global("boss3visited", value);
        // GML 211: global.room51visited = ini_read_real("Save", "room51visited", 0);
        let value = rt.ini_read_real("Save", "room51visited", 0.0);
        rt.write_global("room51visited", value);
        // GML 212: global.room52visited = ini_read_real("Save", "room52visited", 0);
        let value = rt.ini_read_real("Save", "room52visited", 0.0);
        rt.write_global("room52visited", value);
        // GML 213: global.room53visited = ini_read_real("Save", "room53visited", 0);
        let value = rt.ini_read_real("Save", "room53visited", 0.0);
        rt.write_global("room53visited", value);
        // GML 214: global.room54visited = ini_read_real("Save", "room54visited", 0);
        let value = rt.ini_read_real("Save", "room54visited", 0.0);
        rt.write_global("room54visited", value);
        // GML 215: global.room55visited = ini_read_real("Save", "room55visited", 0);
        let value = rt.ini_read_real("Save", "room55visited", 0.0);
        rt.write_global("room55visited", value);
        // GML 216: global.room56visited = ini_read_real("Save", "room56visited", 0);
        let value = rt.ini_read_real("Save", "room56visited", 0.0);
        rt.write_global("room56visited", value);
        // GML 217: global.room57visited = ini_read_real("Save", "room57visited", 0);
        let value = rt.ini_read_real("Save", "room57visited", 0.0);
        rt.write_global("room57visited", value);
        // GML 218: global.room58visited = ini_read_real("Save", "room58visited", 0);
        let value = rt.ini_read_real("Save", "room58visited", 0.0);
        rt.write_global("room58visited", value);
        // GML 219: global.room59visited = ini_read_real("Save", "room59visited", 0);
        let value = rt.ini_read_real("Save", "room59visited", 0.0);
        rt.write_global("room59visited", value);
        // GML 220: global.room60visited = ini_read_real("Save", "room60visited", 0);
        let value = rt.ini_read_real("Save", "room60visited", 0.0);
        rt.write_global("room60visited", value);
        // GML 221: global.room61visited = ini_read_real("Save", "room61visited", 0);
        let value = rt.ini_read_real("Save", "room61visited", 0.0);
        rt.write_global("room61visited", value);
        // GML 222: global.room62visited = ini_read_real("Save", "room62visited", 0);
        let value = rt.ini_read_real("Save", "room62visited", 0.0);
        rt.write_global("room62visited", value);
        // GML 223: global.room63visited = ini_read_real("Save", "room63visited", 0);
        let value = rt.ini_read_real("Save", "room63visited", 0.0);
        rt.write_global("room63visited", value);
        // GML 224: global.room64visited = ini_read_real("Save", "room64visited", 0);
        let value = rt.ini_read_real("Save", "room64visited", 0.0);
        rt.write_global("room64visited", value);
        // GML 225: global.room65visited = ini_read_real("Save", "room65visited", 0);
        let value = rt.ini_read_real("Save", "room65visited", 0.0);
        rt.write_global("room65visited", value);
        // GML 226: global.boss4visited = ini_read_real("Save", "boss4visited", 0);
        let value = rt.ini_read_real("Save", "boss4visited", 0.0);
        rt.write_global("boss4visited", value);
        // GML 227: global.room66visited = ini_read_real("Save", "room66visited", 0);
        let value = rt.ini_read_real("Save", "room66visited", 0.0);
        rt.write_global("room66visited", value);
        // GML 228: global.room67visited = ini_read_real("Save", "room67visited", 0);
        let value = rt.ini_read_real("Save", "room67visited", 0.0);
        rt.write_global("room67visited", value);
        // GML 229: global.room68visited = ini_read_real("Save", "room68visited", 0);
        let value = rt.ini_read_real("Save", "room68visited", 0.0);
        rt.write_global("room68visited", value);
        // GML 230: global.room69visited = ini_read_real("Save", "room69visited", 0);
        let value = rt.ini_read_real("Save", "room69visited", 0.0);
        rt.write_global("room69visited", value);
        // GML 231: global.room70visited = ini_read_real("Save", "room70visited", 0);
        let value = rt.ini_read_real("Save", "room70visited", 0.0);
        rt.write_global("room70visited", value);
        // GML 232: global.room71visited = ini_read_real("Save", "room71visited", 0);
        let value = rt.ini_read_real("Save", "room71visited", 0.0);
        rt.write_global("room71visited", value);
        // GML 233: global.room72visited = ini_read_real("Save", "room72visited", 0);
        let value = rt.ini_read_real("Save", "room72visited", 0.0);
        rt.write_global("room72visited", value);
        // GML 234: global.room73visited = ini_read_real("Save", "room73visited", 0);
        let value = rt.ini_read_real("Save", "room73visited", 0.0);
        rt.write_global("room73visited", value);
        // GML 235: global.room74visited = ini_read_real("Save", "room74visited", 0);
        let value = rt.ini_read_real("Save", "room74visited", 0.0);
        rt.write_global("room74visited", value);
        // GML 236: global.room75visited = ini_read_real("Save", "room75visited", 0);
        let value = rt.ini_read_real("Save", "room75visited", 0.0);
        rt.write_global("room75visited", value);
        // GML 237: global.room76visited = ini_read_real("Save", "room76visited", 0);
        let value = rt.ini_read_real("Save", "room76visited", 0.0);
        rt.write_global("room76visited", value);
        // GML 238: global.room77visited = ini_read_real("Save", "room77visited", 0);
        let value = rt.ini_read_real("Save", "room77visited", 0.0);
        rt.write_global("room77visited", value);
        // GML 239: global.room78visited = ini_read_real("Save", "room78visited", 0);
        let value = rt.ini_read_real("Save", "room78visited", 0.0);
        rt.write_global("room78visited", value);
        // GML 240: global.room79visited = ini_read_real("Save", "room79visited", 0);
        let value = rt.ini_read_real("Save", "room79visited", 0.0);
        rt.write_global("room79visited", value);
        // GML 241: global.room80visited = ini_read_real("Save", "room80visited", 0);
        let value = rt.ini_read_real("Save", "room80visited", 0.0);
        rt.write_global("room80visited", value);
        // GML 242: global.room81visited = ini_read_real("Save", "room81visited", 0);
        let value = rt.ini_read_real("Save", "room81visited", 0.0);
        rt.write_global("room81visited", value);
        // GML 243: global.room82visited = ini_read_real("Save", "room82visited", 0);
        let value = rt.ini_read_real("Save", "room82visited", 0.0);
        rt.write_global("room82visited", value);
        // GML 244: global.boss5visited = ini_read_real("Save", "boss5visited", 0);
        let value = rt.ini_read_real("Save", "boss5visited", 0.0);
        rt.write_global("boss5visited", value);
        // GML 245: global.room83visited = ini_read_real("Save", "room83visited", 0);
        let value = rt.ini_read_real("Save", "room83visited", 0.0);
        rt.write_global("room83visited", value);
        // GML 246: global.room84visited = ini_read_real("Save", "room84visited", 0);
        let value = rt.ini_read_real("Save", "room84visited", 0.0);
        rt.write_global("room84visited", value);
        // GML 247: global.room85visited = ini_read_real("Save", "room85visited", 0);
        let value = rt.ini_read_real("Save", "room85visited", 0.0);
        rt.write_global("room85visited", value);
        // GML 248: global.room86visited = ini_read_real("Save", "room86visited", 0);
        let value = rt.ini_read_real("Save", "room86visited", 0.0);
        rt.write_global("room86visited", value);
        // GML 249: global.room87visited = ini_read_real("Save", "room87visited", 0);
        let value = rt.ini_read_real("Save", "room87visited", 0.0);
        rt.write_global("room87visited", value);
        // GML 250: global.room88visited = ini_read_real("Save", "room88visited", 0);
        let value = rt.ini_read_real("Save", "room88visited", 0.0);
        rt.write_global("room88visited", value);
        // GML 251: global.room89visited = ini_read_real("Save", "room89visited", 0);
        let value = rt.ini_read_real("Save", "room89visited", 0.0);
        rt.write_global("room89visited", value);
        // GML 252: global.room90visited = ini_read_real("Save", "room90visited", 0);
        let value = rt.ini_read_real("Save", "room90visited", 0.0);
        rt.write_global("room90visited", value);
        // GML 253: global.room91visited = ini_read_real("Save", "room91visited", 0);
        let value = rt.ini_read_real("Save", "room91visited", 0.0);
        rt.write_global("room91visited", value);
        // GML 254: global.room92visited = ini_read_real("Save", "room92visited", 0);
        let value = rt.ini_read_real("Save", "room92visited", 0.0);
        rt.write_global("room92visited", value);
        // GML 255: global.room93visited = ini_read_real("Save", "room93visited", 0);
        let value = rt.ini_read_real("Save", "room93visited", 0.0);
        rt.write_global("room93visited", value);
        // GML 256: global.room94visited = ini_read_real("Save", "room94visited", 0);
        let value = rt.ini_read_real("Save", "room94visited", 0.0);
        rt.write_global("room94visited", value);
        // GML 257: global.room95visited = ini_read_real("Save", "room95visited", 0);
        let value = rt.ini_read_real("Save", "room95visited", 0.0);
        rt.write_global("room95visited", value);
        // GML 258: global.room96visited = ini_read_real("Save", "room96visited", 0);
        let value = rt.ini_read_real("Save", "room96visited", 0.0);
        rt.write_global("room96visited", value);
        // GML 259: global.room97visited = ini_read_real("Save", "room97visited", 0);
        let value = rt.ini_read_real("Save", "room97visited", 0.0);
        rt.write_global("room97visited", value);
        // GML 260: global.room98visited = ini_read_real("Save", "room98visited", 0);
        let value = rt.ini_read_real("Save", "room98visited", 0.0);
        rt.write_global("room98visited", value);
        // GML 261: global.room99visited = ini_read_real("Save", "room99visited", 0);
        let value = rt.ini_read_real("Save", "room99visited", 0.0);
        rt.write_global("room99visited", value);
        // GML 262: global.room100visited = ini_read_real("Save", "room100visited", 0);
        let value = rt.ini_read_real("Save", "room100visited", 0.0);
        rt.write_global("room100visited", value);
        // GML 263: global.room101visited = ini_read_real("Save", "room101visited", 0);
        let value = rt.ini_read_real("Save", "room101visited", 0.0);
        rt.write_global("room101visited", value);
        // GML 264: global.room102visited = ini_read_real("Save", "room102visited", 0);
        let value = rt.ini_read_real("Save", "room102visited", 0.0);
        rt.write_global("room102visited", value);
        // GML 265: global.room103visited = ini_read_real("Save", "room103visited", 0);
        let value = rt.ini_read_real("Save", "room103visited", 0.0);
        rt.write_global("room103visited", value);
        // GML 266: global.boss6visited = ini_read_real("Save", "boss6visited", 0);
        let value = rt.ini_read_real("Save", "boss6visited", 0.0);
        rt.write_global("boss6visited", value);
        // GML 267: global.soundmute = ini_read_real("Save", "soundmute", 0);
        let value = rt.ini_read_real("Save", "soundmute", 0.0);
        rt.write_global("soundmute", value);
        // GML 268: global.musicmute = ini_read_real("Save", "musicmute", 0);
        let value = rt.ini_read_real("Save", "musicmute", 0.0);
        rt.write_global("musicmute", value);
        // GML 269: global.beartouched = ini_read_real("Save", "beartouched", 0);
        let value = rt.ini_read_real("Save", "beartouched", 0.0);
        rt.write_global("beartouched", value);
        // GML 270: global.knifetouched = ini_read_real("Save", "knifetouched", 0);
        let value = rt.ini_read_real("Save", "knifetouched", 0.0);
        rt.write_global("knifetouched", value);
        // GML 271: global.spidertouched = ini_read_real("Save", "spidertouched", 0);
        let value = rt.ini_read_real("Save", "spidertouched", 0.0);
        rt.write_global("spidertouched", value);
        // GML 272: global.battouched = ini_read_real("Save", "battouched", 0);
        let value = rt.ini_read_real("Save", "battouched", 0.0);
        rt.write_global("battouched", value);
        // GML 273: global.wolftouched = ini_read_real("Save", "wolftouched", 0);
        let value = rt.ini_read_real("Save", "wolftouched", 0.0);
        rt.write_global("wolftouched", value);
        // GML 274: global.pistolbandittouched = ini_read_real("Save", "pistolbandittouched", 0);
        let value = rt.ini_read_real("Save", "pistolbandittouched", 0.0);
        rt.write_global("pistolbandittouched", value);
        // GML 275: global.boss1touched = ini_read_real("Save", "boss1touched", 0);
        let value = rt.ini_read_real("Save", "boss1touched", 0.0);
        rt.write_global("boss1touched", value);
        // GML 276: global.turrettouched = ini_read_real("Save", "turrettouched", 0);
        let value = rt.ini_read_real("Save", "turrettouched", 0.0);
        rt.write_global("turrettouched", value);
        // GML 277: global.slimetouched = ini_read_real("Save", "slimetouched", 0);
        let value = rt.ini_read_real("Save", "slimetouched", 0.0);
        rt.write_global("slimetouched", value);
        // GML 278: global.boss2touched = ini_read_real("Save", "boss2touched", 0);
        let value = rt.ini_read_real("Save", "boss2touched", 0.0);
        rt.write_global("boss2touched", value);
        // GML 279: global.zombietouched = ini_read_real("Save", "zombietouched", 0);
        let value = rt.ini_read_real("Save", "zombietouched", 0.0);
        rt.write_global("zombietouched", value);
        // GML 280: global.redslimetouched = ini_read_real("Save", "redslimetouched", 0);
        let value = rt.ini_read_real("Save", "redslimetouched", 0.0);
        rt.write_global("redslimetouched", value);
        // GML 281: global.skeletontouched = ini_read_real("Save", "skeletontouched", 0);
        let value = rt.ini_read_real("Save", "skeletontouched", 0.0);
        rt.write_global("skeletontouched", value);
        // GML 282: global.hulkingbandittouched = ini_read_real("Save", "hulkingbandittouched", 0);
        let value = rt.ini_read_real("Save", "hulkingbandittouched", 0.0);
        rt.write_global("hulkingbandittouched", value);
        // GML 283: global.beetouched = ini_read_real("Save", "beetouched", 0);
        let value = rt.ini_read_real("Save", "beetouched", 0.0);
        rt.write_global("beetouched", value);
        // GML 284: global.boss3touched = ini_read_real("Save", "boss3touched", 0);
        let value = rt.ini_read_real("Save", "boss3touched", 0.0);
        rt.write_global("boss3touched", value);
        // GML 285: global.firehulktouched = ini_read_real("Save", "firehulktouched", 0);
        let value = rt.ini_read_real("Save", "firehulktouched", 0.0);
        rt.write_global("firehulktouched", value);
        // GML 286: global.boss4touched = ini_read_real("Save", "boss4touched", 0);
        let value = rt.ini_read_real("Save", "boss4touched", 0.0);
        rt.write_global("boss4touched", value);
        // GML 287: global.boss5touched = ini_read_real("Save", "boss5touched", 0);
        let value = rt.ini_read_real("Save", "boss5touched", 0.0);
        rt.write_global("boss5touched", value);
        // GML 288: global.boss6touched = ini_read_real("Save", "boss6touched", 0);
        let value = rt.ini_read_real("Save", "boss6touched", 0.0);
        rt.write_global("boss6touched", value);
        // GML 289: ini_close();
        rt.ini_close();
        // GML 290: global.drawchange = 0;
        rt.write_global("drawchange", 0.0);
        // GML 291: global.drawlevelup = 0;
        rt.write_global("drawlevelup", 0.0);
        // GML 292: global.drawweaponlevelup = 0;
        rt.write_global("drawweaponlevelup", 0.0);
        // GML 293: global.drawweaponchange = 0;
        rt.write_global("drawweaponchange", 0.0);
        // GML 294: }
    }
    // GML 295: else if (!file_exists("savefile.ini"))
    else if !rt.file_exists("savefile.ini") {
        // GML 296: {
        // GML 297: global.talkedtolloyd1 = 0;
        rt.write_global("talkedtolloyd1", 0.0);
        // GML 298: global.talkedtolloyd2 = 0;
        rt.write_global("talkedtolloyd2", 0.0);
        // GML 299: global.talkedtolloyd3 = 0;
        rt.write_global("talkedtolloyd3", 0.0);
        // GML 300: global.talkedtolloyd4 = 0;
        rt.write_global("talkedtolloyd4", 0.0);
        // GML 301: global.talkedtolloyd5 = 0;
        rt.write_global("talkedtolloyd5", 0.0);
        // GML 302: global.talkedtolloyd6 = 0;
        rt.write_global("talkedtolloyd6", 0.0);
        // GML 303: global.talkedtolloyd7 = 0;
        rt.write_global("talkedtolloyd7", 0.0);
        // GML 304: global.talkedtolloyd8 = 0;
        rt.write_global("talkedtolloyd8", 0.0);
        // GML 305: global.talkedtolloyd9 = 0;
        rt.write_global("talkedtolloyd9", 0.0);
        // GML 306: global.talkedtolloyd10 = 0;
        rt.write_global("talkedtolloyd10", 0.0);
        // GML 307: global.talkedtolloyd11 = 0;
        rt.write_global("talkedtolloyd11", 0.0);
        // GML 308: global.talkedtolloyd12 = 0;
        rt.write_global("talkedtolloyd12", 0.0);
        // GML 309: global.talkedtolloyd13 = 0;
        rt.write_global("talkedtolloyd13", 0.0);
        // GML 310: global.talkedtolloyd14 = 0;
        rt.write_global("talkedtolloyd14", 0.0);
        // GML 311: global.talkedtolloyd15 = 0;
        rt.write_global("talkedtolloyd15", 0.0);
        // GML 312: global.coinmultiply = 1;
        rt.write_global("coinmultiply", 1.0);
        // GML 313: global.timeplayed = 0;
        rt.write_global("timeplayed", 0.0);
        // GML 314: global.gemdropenabled = 1;
        rt.write_global("gemdropenabled", 1.0);
        // GML 315: global.poisonenabled = 0;
        rt.write_global("poisonenabled", 0.0);
        // GML 316: global.weaponswapped = 0;
        rt.write_global("weaponswapped", 0.0);
        // GML 317: global.haskey = 1;
        rt.write_global("haskey", 1.0);
        // GML 318: global.level = 1;
        rt.write_global("level", 1.0);
        // GML 319: global.maxhp = 4;
        rt.write_global("maxhp", 4.0);
        // GML 320: global.xptolevelup = 30;
        rt.write_global("xptolevelup", 30.0);
        // GML 321: global.health1 = 4;
        rt.write_global("health1", 4.0);
        // GML 322: score = 100;
        rt.write_self("score", 100.0);
        // GML 323: global.boss1dead = 0;
        rt.write_global("boss1dead", 0.0);
        // GML 324: global.boss2dead = 0;
        rt.write_global("boss2dead", 0.0);
        // GML 325: global.boss3dead = 0;
        rt.write_global("boss3dead", 0.0);
        // GML 326: global.boss4dead = 0;
        rt.write_global("boss4dead", 0.0);
        // GML 327: global.boss5dead = 0;
        rt.write_global("boss5dead", 0.0);
        // GML 328: global.boss6dead = 0;
        rt.write_global("boss6dead", 0.0);
        // GML 329: global.strengthupgradebought = 0;
        rt.write_global("strengthupgradebought", 0.0);
        // GML 330: global.strengthupgrade2bought = 0;
        rt.write_global("strengthupgrade2bought", 0.0);
        // GML 331: global.energywavebought = 0;
        rt.write_global("energywavebought", 0.0);
        // GML 332: global.healthregenbought = 0;
        rt.write_global("healthregenbought", 0.0);
        // GML 333: global.swordupgradebought = 0;
        rt.write_global("swordupgradebought", 0.0);
        // GML 334: global.swordupgrade2bought = 0;
        rt.write_global("swordupgrade2bought", 0.0);
        // GML 335: global.swordupgrade3bought = 0;
        rt.write_global("swordupgrade3bought", 0.0);
        // GML 336: global.pistolbought = 1;
        rt.write_global("pistolbought", 1.0);
        // GML 337: global.spikegunbought = 0;
        rt.write_global("spikegunbought", 0.0);
        // GML 338: global.boomerangbought = 0;
        rt.write_global("boomerangbought", 0.0);
        // GML 339: global.shotgunbought = 0;
        rt.write_global("shotgunbought", 0.0);
        // GML 340: global.powerupgradebought = 0;
        rt.write_global("powerupgradebought", 0.0);
        // GML 341: global.powerupgrade2bought = 0;
        rt.write_global("powerupgrade2bought", 0.0);
        // GML 342: global.powerupgrade3bought = 0;
        rt.write_global("powerupgrade3bought", 0.0);
        // GML 343: global.bladegunbought = 0;
        rt.write_global("bladegunbought", 0.0);
        // GML 344: global.flamethrowerbought = 0;
        rt.write_global("flamethrowerbought", 0.0);
        // GML 345: global.bowbought = 0;
        rt.write_global("bowbought", 0.0);
        // GML 346: global.assaultriflebought = 0;
        rt.write_global("assaultriflebought", 0.0);
        // GML 347: global.rocketbought = 0;
        rt.write_global("rocketbought", 0.0);
        // GML 348: global.laserbought = 0;
        rt.write_global("laserbought", 0.0);
        // GML 349: global.icegunbought = 0;
        rt.write_global("icegunbought", 0.0);
        // GML 350: global.bombgunbought = 0;
        rt.write_global("bombgunbought", 0.0);
        // GML 351: global.bombgunxp = 0;
        rt.write_global("bombgunxp", 0.0);
        // GML 352: global.bombgunxptolevelup = 160;
        rt.write_global("bombgunxptolevelup", 160.0);
        // GML 353: global.bombgunlevel = 1;
        rt.write_global("bombgunlevel", 1.0);
        // GML 354: global.sword = 0;
        rt.write_global("sword", 0.0);
        // GML 355: global.triplejumpbought = 0;
        rt.write_global("triplejumpbought", 0.0);
        // GML 356: global.tjumpactive = 0;
        rt.write_global("tjumpactive", 0.0);
        // GML 357: global.coinmultiplier2bought = 0;
        rt.write_global("coinmultiplier2bought", 0.0);
        // GML 358: global.coinmultiplier5bought = 0;
        rt.write_global("coinmultiplier5bought", 0.0);
        // GML 359: global.maxhpupgradebought = 0;
        rt.write_global("maxhpupgradebought", 0.0);
        // GML 360: global.maxhpupgrade2bought = 0;
        rt.write_global("maxhpupgrade2bought", 0.0);
        // GML 361: global.experience = 1;
        rt.write_global("experience", 1.0);
        // GML 362: global.drawchange = 0;
        rt.write_global("drawchange", 0.0);
        // GML 363: global.drawlevelup = 0;
        rt.write_global("drawlevelup", 0.0);
        // GML 364: global.drawweaponlevelup = 0;
        rt.write_global("drawweaponlevelup", 0.0);
        // GML 365: global.drawweaponchange = 0;
        rt.write_global("drawweaponchange", 0.0);
        // GML 366: global.drawchangepistol4 = 1;
        rt.write_global("drawchangepistol4", 1.0);
        // GML 367: global.drawchangeshotgun4 = 1;
        rt.write_global("drawchangeshotgun4", 1.0);
        // GML 368: global.drawchangeassaultrifle4 = 1;
        rt.write_global("drawchangeassaultrifle4", 1.0);
        // GML 369: global.drawchangerocket4 = 1;
        rt.write_global("drawchangerocket4", 1.0);
        // GML 370: global.drawchangelaser4 = 1;
        rt.write_global("drawchangelaser4", 1.0);
        // GML 371: global.drawchangeicegun4 = 1;
        rt.write_global("drawchangeicegun4", 1.0);
        // GML 372: global.drawchangebow4 = 1;
        rt.write_global("drawchangebow4", 1.0);
        // GML 373: global.drawchangebladegun4 = 1;
        rt.write_global("drawchangebladegun4", 1.0);
        // GML 374: global.drawchangeflamethrower4 = 1;
        rt.write_global("drawchangeflamethrower4", 1.0);
        // GML 375: global.drawchangeboomerang4 = 1;
        rt.write_global("drawchangeboomerang4", 1.0);
        // GML 376: global.drawchangespikegun4 = 1;
        rt.write_global("drawchangespikegun4", 1.0);
        // GML 377: global.drawchangebombgun4 = 1;
        rt.write_global("drawchangebombgun4", 1.0);
        // GML 378: global.drawchangepistol7 = 1;
        rt.write_global("drawchangepistol7", 1.0);
        // GML 379: global.drawchangeshotgun7 = 1;
        rt.write_global("drawchangeshotgun7", 1.0);
        // GML 380: global.drawchangeassaultrifle7 = 1;
        rt.write_global("drawchangeassaultrifle7", 1.0);
        // GML 381: global.drawchangerocket7 = 1;
        rt.write_global("drawchangerocket7", 1.0);
        // GML 382: global.drawchangelaser7 = 1;
        rt.write_global("drawchangelaser7", 1.0);
        // GML 383: global.drawchangeicegun7 = 1;
        rt.write_global("drawchangeicegun7", 1.0);
        // GML 384: global.drawchangebow7 = 1;
        rt.write_global("drawchangebow7", 1.0);
        // GML 385: global.drawchangebladegun7 = 1;
        rt.write_global("drawchangebladegun7", 1.0);
        // GML 386: global.drawchangeflamethrower7 = 1;
        rt.write_global("drawchangeflamethrower7", 1.0);
        // GML 387: global.drawchangeboomerang7 = 1;
        rt.write_global("drawchangeboomerang7", 1.0);
        // GML 388: global.drawchangespikegun7 = 1;
        rt.write_global("drawchangespikegun7", 1.0);
        // GML 389: global.drawchangebombgun7 = 1;
        rt.write_global("drawchangebombgun7", 1.0);
        // GML 390: global.drawchangepistol10 = 1;
        rt.write_global("drawchangepistol10", 1.0);
        // GML 391: global.drawchangeshotgun10 = 1;
        rt.write_global("drawchangeshotgun10", 1.0);
        // GML 392: global.drawchangeassaultrifle10 = 1;
        rt.write_global("drawchangeassaultrifle10", 1.0);
        // GML 393: global.drawchangerocket10 = 1;
        rt.write_global("drawchangerocket10", 1.0);
        // GML 394: global.drawchangelaser10 = 1;
        rt.write_global("drawchangelaser10", 1.0);
        // GML 395: global.drawchangeicegun10 = 1;
        rt.write_global("drawchangeicegun10", 1.0);
        // GML 396: global.drawchangebow10 = 1;
        rt.write_global("drawchangebow10", 1.0);
        // GML 397: global.drawchangebladegun10 = 1;
        rt.write_global("drawchangebladegun10", 1.0);
        // GML 398: global.drawchangeflamethrower10 = 1;
        rt.write_global("drawchangeflamethrower10", 1.0);
        // GML 399: global.drawchangeboomerang10 = 1;
        rt.write_global("drawchangeboomerang10", 1.0);
        // GML 400: global.drawchangespikegun10 = 1;
        rt.write_global("drawchangespikegun10", 1.0);
        // GML 401: global.drawchangebombgun10 = 1;
        rt.write_global("drawchangebombgun10", 1.0);
        // GML 402: global.bearskilled = 0;
        rt.write_global("bearskilled", 0.0);
        // GML 403: global.knifebanditskilled = 0;
        rt.write_global("knifebanditskilled", 0.0);
        // GML 404: global.pistolthugskilled = 0;
        rt.write_global("pistolthugskilled", 0.0);
        // GML 405: global.wolfkilled = 0;
        rt.write_global("wolfkilled", 0.0);
        // GML 406: global.chomperbotkilled = 0;
        rt.write_global("chomperbotkilled", 0.0);
        // GML 407: global.greenslimeskilled = 0;
        rt.write_global("greenslimeskilled", 0.0);
        // GML 408: global.fireslimeskilled = 0;
        rt.write_global("fireslimeskilled", 0.0);
        // GML 409: global.hulkingbanditskilled = 0;
        rt.write_global("hulkingbanditskilled", 0.0);
        // GML 410: global.ghostskilled = 0;
        rt.write_global("ghostskilled", 0.0);
        // GML 411: global.skeletonskilled = 0;
        rt.write_global("skeletonskilled", 0.0);
        // GML 412: global.zombieskilled = 0;
        rt.write_global("zombieskilled", 0.0);
        // GML 413: global.firehulkskilled = 0;
        rt.write_global("firehulkskilled", 0.0);
        // GML 414: global.batskilled = 0;
        rt.write_global("batskilled", 0.0);
        // GML 415: global.trapskilled = 0;
        rt.write_global("trapskilled", 0.0);
        // GML 416: global.enemieskilled = 0;
        rt.write_global("enemieskilled", 0.0);
        // GML 417: global.boughtallguns = 0;
        rt.write_global("boughtallguns", 0.0);
        // GML 418: global.triplejumpachievement = 0;
        rt.write_global("triplejumpachievement", 0.0);
        // GML 419: global.boughtallupgrades = 0;
        rt.write_global("boughtallupgrades", 0.0);
        // GML 420: global.boughteverything = 0;
        rt.write_global("boughteverything", 0.0);
        // GML 421: global.achievemaxhp = 0;
        rt.write_global("achievemaxhp", 0.0);
        // GML 422: global.getmoney = 0;
        rt.write_global("getmoney", 0.0);
        // GML 423: global.hitmaxlevel = 0;
        rt.write_global("hitmaxlevel", 0.0);
        // GML 424: global.bladegunxp = 0;
        rt.write_global("bladegunxp", 0.0);
        // GML 425: global.bladegunxptolevelup = 200;
        rt.write_global("bladegunxptolevelup", 200.0);
        // GML 426: global.flamethrowerxp = 0;
        rt.write_global("flamethrowerxp", 0.0);
        // GML 427: global.flamethrowerxptolevelup = 180;
        rt.write_global("flamethrowerxptolevelup", 180.0);
        // GML 428: global.bowxp = 0;
        rt.write_global("bowxp", 0.0);
        // GML 429: global.bowxptolevelup = 62;
        rt.write_global("bowxptolevelup", 62.0);
        // GML 430: global.pistolxp = 0;
        rt.write_global("pistolxp", 0.0);
        // GML 431: global.pistolxptolevelup = 46;
        rt.write_global("pistolxptolevelup", 46.0);
        // GML 432: global.shotgunxp = 0;
        rt.write_global("shotgunxp", 0.0);
        // GML 433: global.shotgunxptolevelup = 115;
        rt.write_global("shotgunxptolevelup", 115.0);
        // GML 434: global.assaultriflexp = 0;
        rt.write_global("assaultriflexp", 0.0);
        // GML 435: global.assaultriflexptolevelup = 120;
        rt.write_global("assaultriflexptolevelup", 120.0);
        // GML 436: global.rocketxp = 0;
        rt.write_global("rocketxp", 0.0);
        // GML 437: global.rocketxptolevelup = 80;
        rt.write_global("rocketxptolevelup", 80.0);
        // GML 438: global.laserxp = 0;
        rt.write_global("laserxp", 0.0);
        // GML 439: global.laserxptolevelup = 80;
        rt.write_global("laserxptolevelup", 80.0);
        // GML 440: global.icegunxp = 0;
        rt.write_global("icegunxp", 0.0);
        // GML 441: global.icegunxptolevelup = 60;
        rt.write_global("icegunxptolevelup", 60.0);
        // GML 442: global.pistollevel = 1;
        rt.write_global("pistollevel", 1.0);
        // GML 443: global.shotgunlevel = 1;
        rt.write_global("shotgunlevel", 1.0);
        // GML 444: global.assaultriflelevel = 1;
        rt.write_global("assaultriflelevel", 1.0);
        // GML 445: global.grenadelevel = 1;
        rt.write_global("grenadelevel", 1.0);
        // GML 446: global.rocketlevel = 1;
        rt.write_global("rocketlevel", 1.0);
        // GML 447: global.laserlevel = 1;
        rt.write_global("laserlevel", 1.0);
        // GML 448: global.icegunlevel = 1;
        rt.write_global("icegunlevel", 1.0);
        // GML 449: global.bowlevel = 1;
        rt.write_global("bowlevel", 1.0);
        // GML 450: global.bladegunlevel = 1;
        rt.write_global("bladegunlevel", 1.0);
        // GML 451: global.flamethrowerlevel = 1;
        rt.write_global("flamethrowerlevel", 1.0);
        // GML 452: global.boomerangxp = 0;
        rt.write_global("boomerangxp", 0.0);
        // GML 453: global.boomeranglevel = 1;
        rt.write_global("boomeranglevel", 1.0);
        // GML 454: global.boomerangxptolevelup = 250;
        rt.write_global("boomerangxptolevelup", 250.0);
        // GML 455: global.spikegunxp = 0;
        rt.write_global("spikegunxp", 0.0);
        // GML 456: global.spikegunlevel = 1;
        rt.write_global("spikegunlevel", 1.0);
        // GML 457: global.spikegunxptolevelup = 64;
        rt.write_global("spikegunxptolevelup", 64.0);
        // GML 458: global.roomtownvisited = 1;
        rt.write_global("roomtownvisited", 1.0);
        // GML 459: global.level1visited = 0;
        rt.write_global("level1visited", 0.0);
        // GML 460: global.level2visited = 0;
        rt.write_global("level2visited", 0.0);
        // GML 461: global.level3visited = 0;
        rt.write_global("level3visited", 0.0);
        // GML 462: global.level4visited = 0;
        rt.write_global("level4visited", 0.0);
        // GML 463: global.level5visited = 0;
        rt.write_global("level5visited", 0.0);
        // GML 464: global.level6visited = 0;
        rt.write_global("level6visited", 0.0);
        // GML 465: global.level7visited = 0;
        rt.write_global("level7visited", 0.0);
        // GML 466: global.level8visited = 0;
        rt.write_global("level8visited", 0.0);
        // GML 467: global.level8avisited = 0;
        rt.write_global("level8avisited", 0.0);
        // GML 468: global.boss1visited = 0;
        rt.write_global("boss1visited", 0.0);
        // GML 469: global.level9visited = 0;
        rt.write_global("level9visited", 0.0);
        // GML 470: global.level9avisited = 0;
        rt.write_global("level9avisited", 0.0);
        // GML 471: global.level10visited = 0;
        rt.write_global("level10visited", 0.0);
        // GML 472: global.level11visited = 0;
        rt.write_global("level11visited", 0.0);
        // GML 473: global.level11avisited = 0;
        rt.write_global("level11avisited", 0.0);
        // GML 474: global.level12visited = 0;
        rt.write_global("level12visited", 0.0);
        // GML 475: global.level13visited = 0;
        rt.write_global("level13visited", 0.0);
        // GML 476: global.level13avisited = 0;
        rt.write_global("level13avisited", 0.0);
        // GML 477: global.level14visited = 0;
        rt.write_global("level14visited", 0.0);
        // GML 478: global.level14avisited = 0;
        rt.write_global("level14avisited", 0.0);
        // GML 479: global.level15visited = 0;
        rt.write_global("level15visited", 0.0);
        // GML 480: global.level15avisited = 0;
        rt.write_global("level15avisited", 0.0);
        // GML 481: global.level16visited = 0;
        rt.write_global("level16visited", 0.0);
        // GML 482: global.level16avisited = 0;
        rt.write_global("level16avisited", 0.0);
        // GML 483: global.level17visited = 0;
        rt.write_global("level17visited", 0.0);
        // GML 484: global.level17avisited = 0;
        rt.write_global("level17avisited", 0.0);
        // GML 485: global.boss2visited = 0;
        rt.write_global("boss2visited", 0.0);
        // GML 486: global.room31visited = 0;
        rt.write_global("room31visited", 0.0);
        // GML 487: global.room32visited = 0;
        rt.write_global("room32visited", 0.0);
        // GML 488: global.room33visited = 0;
        rt.write_global("room33visited", 0.0);
        // GML 489: global.room34visited = 0;
        rt.write_global("room34visited", 0.0);
        // GML 490: global.room35visited = 0;
        rt.write_global("room35visited", 0.0);
        // GML 491: global.room36visited = 0;
        rt.write_global("room36visited", 0.0);
        // GML 492: global.room37visited = 0;
        rt.write_global("room37visited", 0.0);
        // GML 493: global.room38visited = 0;
        rt.write_global("room38visited", 0.0);
        // GML 494: global.room39visited = 0;
        rt.write_global("room39visited", 0.0);
        // GML 495: global.room40visited = 0;
        rt.write_global("room40visited", 0.0);
        // GML 496: global.room41visited = 0;
        rt.write_global("room41visited", 0.0);
        // GML 497: global.room42visited = 0;
        rt.write_global("room42visited", 0.0);
        // GML 498: global.room43visited = 0;
        rt.write_global("room43visited", 0.0);
        // GML 499: global.room44visited = 0;
        rt.write_global("room44visited", 0.0);
        // GML 500: global.room45visited = 0;
        rt.write_global("room45visited", 0.0);
        // GML 501: global.room46visited = 0;
        rt.write_global("room46visited", 0.0);
        // GML 502: global.room47visited = 0;
        rt.write_global("room47visited", 0.0);
        // GML 503: global.room48visited = 0;
        rt.write_global("room48visited", 0.0);
        // GML 504: global.room49visited = 0;
        rt.write_global("room49visited", 0.0);
        // GML 505: global.room50visited = 0;
        rt.write_global("room50visited", 0.0);
        // GML 506: global.boss3visited = 0;
        rt.write_global("boss3visited", 0.0);
        // GML 507: global.room51visited = 0;
        rt.write_global("room51visited", 0.0);
        // GML 508: global.room52visited = 0;
        rt.write_global("room52visited", 0.0);
        // GML 509: global.room53visited = 0;
        rt.write_global("room53visited", 0.0);
        // GML 510: global.room54visited = 0;
        rt.write_global("room54visited", 0.0);
        // GML 511: global.room55visited = 0;
        rt.write_global("room55visited", 0.0);
        // GML 512: global.room56visited = 0;
        rt.write_global("room56visited", 0.0);
        // GML 513: global.room57visited = 0;
        rt.write_global("room57visited", 0.0);
        // GML 514: global.room58visited = 0;
        rt.write_global("room58visited", 0.0);
        // GML 515: global.room59visited = 0;
        rt.write_global("room59visited", 0.0);
        // GML 516: global.room60visited = 0;
        rt.write_global("room60visited", 0.0);
        // GML 517: global.room61visited = 0;
        rt.write_global("room61visited", 0.0);
        // GML 518: global.room62visited = 0;
        rt.write_global("room62visited", 0.0);
        // GML 519: global.room63visited = 0;
        rt.write_global("room63visited", 0.0);
        // GML 520: global.room64visited = 0;
        rt.write_global("room64visited", 0.0);
        // GML 521: global.room65visited = 0;
        rt.write_global("room65visited", 0.0);
        // GML 522: global.boss4visited = 0;
        rt.write_global("boss4visited", 0.0);
        // GML 523: global.room66visited = 0;
        rt.write_global("room66visited", 0.0);
        // GML 524: global.room67visited = 0;
        rt.write_global("room67visited", 0.0);
        // GML 525: global.room68visited = 0;
        rt.write_global("room68visited", 0.0);
        // GML 526: global.room69visited = 0;
        rt.write_global("room69visited", 0.0);
        // GML 527: global.room70visited = 0;
        rt.write_global("room70visited", 0.0);
        // GML 528: global.room71visited = 0;
        rt.write_global("room71visited", 0.0);
        // GML 529: global.room72visited = 0;
        rt.write_global("room72visited", 0.0);
        // GML 530: global.room73visited = 0;
        rt.write_global("room73visited", 0.0);
        // GML 531: global.room74visited = 0;
        rt.write_global("room74visited", 0.0);
        // GML 532: global.room75visited = 0;
        rt.write_global("room75visited", 0.0);
        // GML 533: global.room76visited = 0;
        rt.write_global("room76visited", 0.0);
        // GML 534: global.room77visited = 0;
        rt.write_global("room77visited", 0.0);
        // GML 535: global.room78visited = 0;
        rt.write_global("room78visited", 0.0);
        // GML 536: global.room79visited = 0;
        rt.write_global("room79visited", 0.0);
        // GML 537: global.room80visited = 0;
        rt.write_global("room80visited", 0.0);
        // GML 538: global.room81visited = 0;
        rt.write_global("room81visited", 0.0);
        // GML 539: global.room82visited = 0;
        rt.write_global("room82visited", 0.0);
        // GML 540: global.boss5visited = 0;
        rt.write_global("boss5visited", 0.0);
        // GML 541: global.room83visited = 0;
        rt.write_global("room83visited", 0.0);
        // GML 542: global.room84visited = 0;
        rt.write_global("room84visited", 0.0);
        // GML 543: global.room85visited = 0;
        rt.write_global("room85visited", 0.0);
        // GML 544: global.room86visited = 0;
        rt.write_global("room86visited", 0.0);
        // GML 545: global.room87visited = 0;
        rt.write_global("room87visited", 0.0);
        // GML 546: global.room88visited = 0;
        rt.write_global("room88visited", 0.0);
        // GML 547: global.room89visited = 0;
        rt.write_global("room89visited", 0.0);
        // GML 548: global.room90visited = 0;
        rt.write_global("room90visited", 0.0);
        // GML 549: global.room91visited = 0;
        rt.write_global("room91visited", 0.0);
        // GML 550: global.room92visited = 0;
        rt.write_global("room92visited", 0.0);
        // GML 551: global.room93visited = 0;
        rt.write_global("room93visited", 0.0);
        // GML 552: global.room94visited = 0;
        rt.write_global("room94visited", 0.0);
        // GML 553: global.room95visited = 0;
        rt.write_global("room95visited", 0.0);
        // GML 554: global.room96visited = 0;
        rt.write_global("room96visited", 0.0);
        // GML 555: global.room97visited = 0;
        rt.write_global("room97visited", 0.0);
        // GML 556: global.room98visited = 0;
        rt.write_global("room98visited", 0.0);
        // GML 557: global.room99visited = 0;
        rt.write_global("room99visited", 0.0);
        // GML 558: global.room100visited = 0;
        rt.write_global("room100visited", 0.0);
        // GML 559: global.room101visited = 0;
        rt.write_global("room101visited", 0.0);
        // GML 560: global.room102visited = 0;
        rt.write_global("room102visited", 0.0);
        // GML 561: global.room103visited = 0;
        rt.write_global("room103visited", 0.0);
        // GML 562: global.boss6visited = 0;
        rt.write_global("boss6visited", 0.0);
        // GML 563: global.soundmute = 0;
        rt.write_global("soundmute", 0.0);
        // GML 564: global.musicmute = 0;
        rt.write_global("musicmute", 0.0);
        // GML 565: global.beartouched = 0;
        rt.write_global("beartouched", 0.0);
        // GML 566: global.knifetouched = 0;
        rt.write_global("knifetouched", 0.0);
        // GML 567: global.spidertouched = 0;
        rt.write_global("spidertouched", 0.0);
        // GML 568: global.battouched = 0;
        rt.write_global("battouched", 0.0);
        // GML 569: global.wolftouched = 0;
        rt.write_global("wolftouched", 0.0);
        // GML 570: global.pistolbandittouched = 0;
        rt.write_global("pistolbandittouched", 0.0);
        // GML 571: global.boss1touched = 0;
        rt.write_global("boss1touched", 0.0);
        // GML 572: global.turrettouched = 0;
        rt.write_global("turrettouched", 0.0);
        // GML 573: global.slimetouched = 0;
        rt.write_global("slimetouched", 0.0);
        // GML 574: global.boss2touched = 0;
        rt.write_global("boss2touched", 0.0);
        // GML 575: global.zombietouched = 0;
        rt.write_global("zombietouched", 0.0);
        // GML 576: global.redslimetouched = 0;
        rt.write_global("redslimetouched", 0.0);
        // GML 577: global.skeletontouched = 0;
        rt.write_global("skeletontouched", 0.0);
        // GML 578: global.hulkingbandittouched = 0;
        rt.write_global("hulkingbandittouched", 0.0);
        // GML 579: global.beetouched = 0;
        rt.write_global("beetouched", 0.0);
        // GML 580: global.boss3touched = 0;
        rt.write_global("boss3touched", 0.0);
        // GML 581: global.firehulktouched = 0;
        rt.write_global("firehulktouched", 0.0);
        // GML 582: global.boss4touched = 0;
        rt.write_global("boss4touched", 0.0);
        // GML 583: global.boss5touched = 0;
        rt.write_global("boss5touched", 0.0);
        // GML 584: global.boss6touched = 0;
        rt.write_global("boss6touched", 0.0);
        // GML 585: ini_open("savefile.ini");
        rt.ini_open("savefile.ini");
        // GML 586: ini_write_real("Save", "talkedtolloyd1", global.talkedtolloyd1);
        let value = rt.read_global("talkedtolloyd1");
        rt.ini_write_real("Save", "talkedtolloyd1", value);
        // GML 587: ini_write_real("Save", "talkedtolloyd2", global.talkedtolloyd2);
        let value = rt.read_global("talkedtolloyd2");
        rt.ini_write_real("Save", "talkedtolloyd2", value);
        // GML 588: ini_write_real("Save", "talkedtolloyd3", global.talkedtolloyd3);
        let value = rt.read_global("talkedtolloyd3");
        rt.ini_write_real("Save", "talkedtolloyd3", value);
        // GML 589: ini_write_real("Save", "talkedtolloyd4", global.talkedtolloyd4);
        let value = rt.read_global("talkedtolloyd4");
        rt.ini_write_real("Save", "talkedtolloyd4", value);
        // GML 590: ini_write_real("Save", "talkedtolloyd5", global.talkedtolloyd5);
        let value = rt.read_global("talkedtolloyd5");
        rt.ini_write_real("Save", "talkedtolloyd5", value);
        // GML 591: ini_write_real("Save", "talkedtolloyd6", global.talkedtolloyd6);
        let value = rt.read_global("talkedtolloyd6");
        rt.ini_write_real("Save", "talkedtolloyd6", value);
        // GML 592: ini_write_real("Save", "talkedtolloyd7", global.talkedtolloyd7);
        let value = rt.read_global("talkedtolloyd7");
        rt.ini_write_real("Save", "talkedtolloyd7", value);
        // GML 593: ini_write_real("Save", "talkedtolloyd8", global.talkedtolloyd8);
        let value = rt.read_global("talkedtolloyd8");
        rt.ini_write_real("Save", "talkedtolloyd8", value);
        // GML 594: ini_write_real("Save", "talkedtolloyd9", global.talkedtolloyd9);
        let value = rt.read_global("talkedtolloyd9");
        rt.ini_write_real("Save", "talkedtolloyd9", value);
        // GML 595: ini_write_real("Save", "talkedtolloyd10", global.talkedtolloyd10);
        let value = rt.read_global("talkedtolloyd10");
        rt.ini_write_real("Save", "talkedtolloyd10", value);
        // GML 596: ini_write_real("Save", "talkedtolloyd11", global.talkedtolloyd11);
        let value = rt.read_global("talkedtolloyd11");
        rt.ini_write_real("Save", "talkedtolloyd11", value);
        // GML 597: ini_write_real("Save", "talkedtolloyd12", global.talkedtolloyd12);
        let value = rt.read_global("talkedtolloyd12");
        rt.ini_write_real("Save", "talkedtolloyd12", value);
        // GML 598: ini_write_real("Save", "talkedtolloyd13", global.talkedtolloyd13);
        let value = rt.read_global("talkedtolloyd13");
        rt.ini_write_real("Save", "talkedtolloyd13", value);
        // GML 599: ini_write_real("Save", "talkedtolloyd14", global.talkedtolloyd14);
        let value = rt.read_global("talkedtolloyd14");
        rt.ini_write_real("Save", "talkedtolloyd14", value);
        // GML 600: ini_write_real("Save", "talkedtolloyd15", global.talkedtolloyd15);
        let value = rt.read_global("talkedtolloyd15");
        rt.ini_write_real("Save", "talkedtolloyd15", value);
        // GML 601: ini_write_real("Save", "bearskilled", global.bearskilled);
        let value = rt.read_global("bearskilled");
        rt.ini_write_real("Save", "bearskilled", value);
        // GML 602: ini_write_real("Save", "current_level", global.level);
        let value = rt.read_global("level");
        rt.ini_write_real("Save", "current_level", value);
        // GML 603: ini_write_real("Save", "current_maxhp", global.maxhp);
        let value = rt.read_global("maxhp");
        rt.ini_write_real("Save", "current_maxhp", value);
        // GML 604: ini_write_real("Save", "current_score", score);
        let value = rt.read_self("score");
        rt.ini_write_real("Save", "current_score", value);
        // GML 605: ini_write_real("Save", "current_XP", global.experience);
        let value = rt.read_global("experience");
        rt.ini_write_real("Save", "current_XP", value);
        // GML 606: ini_write_real("Save", "boss1dead", global.boss1dead);
        let value = rt.read_global("boss1dead");
        rt.ini_write_real("Save", "boss1dead", value);
        // GML 607: ini_write_real("Save", "boss2dead", global.boss2dead);
        let value = rt.read_global("boss2dead");
        rt.ini_write_real("Save", "boss2dead", value);
        // GML 608: ini_write_real("Save", "boss3dead", global.boss3dead);
        let value = rt.read_global("boss3dead");
        rt.ini_write_real("Save", "boss3dead", value);
        // GML 609: ini_write_real("Save", "boss4dead", global.boss4dead);
        let value = rt.read_global("boss4dead");
        rt.ini_write_real("Save", "boss4dead", value);
        // GML 610: ini_write_real("Save", "boss5dead", global.boss5dead);
        let value = rt.read_global("boss5dead");
        rt.ini_write_real("Save", "boss5dead", value);
        // GML 611: ini_write_real("Save", "boss6dead", global.boss6dead);
        let value = rt.read_global("boss6dead");
        rt.ini_write_real("Save", "boss6dead", value);
        // GML 612: ini_write_real("Save", "pistolbought", global.pistolbought);
        let value = rt.read_global("pistolbought");
        rt.ini_write_real("Save", "pistolbought", value);
        // GML 613: ini_write_real("Save", "bombgunbought", global.bombgunbought);
        let value = rt.read_global("bombgunbought");
        rt.ini_write_real("Save", "bombgunbought", value);
        // GML 614: ini_write_real("Save", "bombgunxp", global.bombgunxp);
        let value = rt.read_global("bombgunxp");
        rt.ini_write_real("Save", "bombgunxp", value);
        // GML 615: ini_write_real("Save", "bombgunxptolevelup", global.bombgunxptolevelup);
        let value = rt.read_global("bombgunxptolevelup");
        rt.ini_write_real("Save", "bombgunxptolevelup", value);
        // GML 616: ini_write_real("Save", "bombgunlevel", global.bombgunlevel);
        let value = rt.read_global("bombgunlevel");
        rt.ini_write_real("Save", "bombgunlevel", value);
        // GML 617: ini_write_real("Save", "bladegunbought", global.bladegunbought);
        let value = rt.read_global("bladegunbought");
        rt.ini_write_real("Save", "bladegunbought", value);
        // GML 618: ini_write_real("Save", "flamethrowerbought", global.flamethrowerbought);
        let value = rt.read_global("flamethrowerbought");
        rt.ini_write_real("Save", "flamethrowerbought", value);
        // GML 619: ini_write_real("Save", "bowbought", global.bowbought);
        let value = rt.read_global("bowbought");
        rt.ini_write_real("Save", "bowbought", value);
        // GML 620: ini_write_real("Save", "energywavebought", global.energywavebought);
        let value = rt.read_global("energywavebought");
        rt.ini_write_real("Save", "energywavebought", value);
        // GML 621: ini_write_real("Save", "strengthupgradebought", global.strengthupgradebought);
        let value = rt.read_global("strengthupgradebought");
        rt.ini_write_real("Save", "strengthupgradebought", value);
        // GML 622: ini_write_real("Save", "strengthupgrade2bought", global.strengthupgrade2bought);
        let value = rt.read_global("strengthupgrade2bought");
        rt.ini_write_real("Save", "strengthupgrade2bought", value);
        // GML 623: ini_write_real("Save", "healthregenbought", global.healthregenbought);
        let value = rt.read_global("healthregenbought");
        rt.ini_write_real("Save", "healthregenbought", value);
        // GML 624: ini_write_real("Save", "shotgunbought", global.shotgunbought);
        let value = rt.read_global("shotgunbought");
        rt.ini_write_real("Save", "shotgunbought", value);
        // GML 625: ini_write_real("Save", "swordupgradebought", global.swordupgradebought);
        let value = rt.read_global("swordupgradebought");
        rt.ini_write_real("Save", "swordupgradebought", value);
        // GML 626: ini_write_real("Save", "swordupgrade2bought", global.swordupgrade2bought);
        let value = rt.read_global("swordupgrade2bought");
        rt.ini_write_real("Save", "swordupgrade2bought", value);
        // GML 627: ini_write_real("Save", "swordupgrade3bought", global.swordupgrade3bought);
        let value = rt.read_global("swordupgrade3bought");
        rt.ini_write_real("Save", "swordupgrade3bought", value);
        // GML 628: ini_write_real("Save", "powerupgradebought", global.powerupgradebought);
        let value = rt.read_global("powerupgradebought");
        rt.ini_write_real("Save", "powerupgradebought", value);
        // GML 629: ini_write_real("Save", "powerupgrade2bought", global.powerupgrade2bought);
        let value = rt.read_global("powerupgrade2bought");
        rt.ini_write_real("Save", "powerupgrade2bought", value);
        // GML 630: ini_write_real("Save", "powerupgrade3bought", global.powerupgrade3bought);
        let value = rt.read_global("powerupgrade3bought");
        rt.ini_write_real("Save", "powerupgrade3bought", value);
        // GML 631: ini_write_real("Save", "assaultriflebought", global.assaultriflebought);
        let value = rt.read_global("assaultriflebought");
        rt.ini_write_real("Save", "assaultriflebought", value);
        // GML 632: ini_write_real("Save", "rocketbought", global.rocketbought);
        let value = rt.read_global("rocketbought");
        rt.ini_write_real("Save", "rocketbought", value);
        // GML 633: ini_write_real("Save", "laserbought", global.laserbought);
        let value = rt.read_global("laserbought");
        rt.ini_write_real("Save", "laserbought", value);
        // GML 634: ini_write_real("Save", "icegunbought", global.icegunbought);
        let value = rt.read_global("icegunbought");
        rt.ini_write_real("Save", "icegunbought", value);
        // GML 635: ini_write_real("Save", "sword", global.sword);
        let value = rt.read_global("sword");
        rt.ini_write_real("Save", "sword", value);
        // GML 636: ini_write_real("Save", "bowbought", global.bowbought);
        let value = rt.read_global("bowbought");
        rt.ini_write_real("Save", "bowbought", value);
        // GML 637: ini_write_real("Save", "bladegunbought", global.bladegunbought);
        let value = rt.read_global("bladegunbought");
        rt.ini_write_real("Save", "bladegunbought", value);
        // GML 638: ini_write_real("Save", "triplejumpbought", global.triplejumpbought);
        let value = rt.read_global("triplejumpbought");
        rt.ini_write_real("Save", "triplejumpbought", value);
        // GML 639: ini_write_real("Save", "triplejumpactive", global.tjumpactive);
        let value = rt.read_global("tjumpactive");
        rt.ini_write_real("Save", "triplejumpactive", value);
        // GML 640: ini_write_real("Save", "coinmultiplier2bought", global.coinmultiplier2bought);
        let value = rt.read_global("coinmultiplier2bought");
        rt.ini_write_real("Save", "coinmultiplier2bought", value);
        // GML 641: ini_write_real("Save", "coinmultiplier5bought", global.coinmultiplier5bought);
        let value = rt.read_global("coinmultiplier5bought");
        rt.ini_write_real("Save", "coinmultiplier5bought", value);
        // GML 642: ini_write_real("Save", "maxhpupgradebought", global.maxhpupgradebought);
        let value = rt.read_global("maxhpupgradebought");
        rt.ini_write_real("Save", "maxhpupgradebought", value);
        // GML 643: ini_write_real("Save", "maxhpupgrade2bought", global.maxhpupgrade2bought);
        let value = rt.read_global("maxhpupgrade2bought");
        rt.ini_write_real("Save", "maxhpupgrade2bought", value);
        // GML 644: ini_write_real("Save", "haskey", global.haskey);
        let value = rt.read_global("haskey");
        rt.ini_write_real("Save", "haskey", value);
        // GML 645: ini_write_real("Save", "xptolevelup", global.xptolevelup);
        let value = rt.read_global("xptolevelup");
        rt.ini_write_real("Save", "xptolevelup", value);
        // GML 646: ini_write_real("Save", "pistolxp", global.pistolxp);
        let value = rt.read_global("pistolxp");
        rt.ini_write_real("Save", "pistolxp", value);
        // GML 647: ini_write_real("Save", "pistolxptolevelup", global.pistolxptolevelup);
        let value = rt.read_global("pistolxptolevelup");
        rt.ini_write_real("Save", "pistolxptolevelup", value);
        // GML 648: ini_write_real("Save", "bladegunxp", global.bladegunxp);
        let value = rt.read_global("bladegunxp");
        rt.ini_write_real("Save", "bladegunxp", value);
        // GML 649: ini_write_real("Save", "bladegunxptolevelup", global.bladegunxptolevelup);
        let value = rt.read_global("bladegunxptolevelup");
        rt.ini_write_real("Save", "bladegunxptolevelup", value);
        // GML 650: ini_write_real("Save", "flamethrowerxp", global.flamethrowerxp);
        let value = rt.read_global("flamethrowerxp");
        rt.ini_write_real("Save", "flamethrowerxp", value);
        // GML 651: ini_write_real("Save", "flamethrowerxptolevelup", global.flamethrowerxptolevelup);
        let value = rt.read_global("flamethrowerxptolevelup");
        rt.ini_write_real("Save", "flamethrowerxptolevelup", value);
        // GML 652: ini_write_real("Save", "bowxp", global.bowxp);
        let value = rt.read_global("bowxp");
        rt.ini_write_real("Save", "bowxp", value);
        // GML 653: ini_write_real("Save", "bowxptolevelup", global.bowxptolevelup);
        let value = rt.read_global("bowxptolevelup");
        rt.ini_write_real("Save", "bowxptolevelup", value);
        // GML 654: ini_write_real("Save", "shotgunxp", global.shotgunxp);
        let value = rt.read_global("shotgunxp");
        rt.ini_write_real("Save", "shotgunxp", value);
        // GML 655: ini_write_real("Save", "shotgunxptolevelup", global.shotgunxptolevelup);
        let value = rt.read_global("shotgunxptolevelup");
        rt.ini_write_real("Save", "shotgunxptolevelup", value);
        // GML 656: ini_write_real("Save", "assaultriflexp", global.assaultriflexp);
        let value = rt.read_global("assaultriflexp");
        rt.ini_write_real("Save", "assaultriflexp", value);
        // GML 657: ini_write_real("Save", "assaultriflexptolevelup", global.assaultriflexptolevelup);
        let value = rt.read_global("assaultriflexptolevelup");
        rt.ini_write_real("Save", "assaultriflexptolevelup", value);
        // GML 658: ini_write_real("Save", "rocketxp", global.rocketxp);
        let value = rt.read_global("rocketxp");
        rt.ini_write_real("Save", "rocketxp", value);
        // GML 659: ini_write_real("Save", "rocketxptolevelup", global.rocketxptolevelup);
        let value = rt.read_global("rocketxptolevelup");
        rt.ini_write_real("Save", "rocketxptolevelup", value);
        // GML 660: ini_write_real("Save", "laserxp", global.laserxp);
        let value = rt.read_global("laserxp");
        rt.ini_write_real("Save", "laserxp", value);
        // GML 661: ini_write_real("Save", "laserxptolevelup", global.laserxptolevelup);
        let value = rt.read_global("laserxptolevelup");
        rt.ini_write_real("Save", "laserxptolevelup", value);
        // GML 662: ini_write_real("Save", "icegunxp", global.icegunxp);
        let value = rt.read_global("icegunxp");
        rt.ini_write_real("Save", "icegunxp", value);
        // GML 663: ini_write_real("Save", "icegunxptolevelup", global.icegunxptolevelup);
        let value = rt.read_global("icegunxptolevelup");
        rt.ini_write_real("Save", "icegunxptolevelup", value);
        // GML 664: ini_write_real("Save", "bowxp", global.bowxp);
        let value = rt.read_global("bowxp");
        rt.ini_write_real("Save", "bowxp", value);
        // GML 665: ini_write_real("Save", "bowxptolevelup", global.bowxptolevelup);
        let value = rt.read_global("bowxptolevelup");
        rt.ini_write_real("Save", "bowxptolevelup", value);
        // GML 666: ini_write_real("Save", "pistollevel", global.pistollevel);
        let value = rt.read_global("pistollevel");
        rt.ini_write_real("Save", "pistollevel", value);
        // GML 667: ini_write_real("Save", "shotgunlevel", global.shotgunlevel);
        let value = rt.read_global("shotgunlevel");
        rt.ini_write_real("Save", "shotgunlevel", value);
        // GML 668: ini_write_real("Save", "assaultriflelevel", global.assaultriflelevel);
        let value = rt.read_global("assaultriflelevel");
        rt.ini_write_real("Save", "assaultriflelevel", value);
        // GML 669: ini_write_real("Save", "grenadelevel", global.grenadelevel);
        let value = rt.read_global("grenadelevel");
        rt.ini_write_real("Save", "grenadelevel", value);
        // GML 670: ini_write_real("Save", "rocketlevel", global.rocketlevel);
        let value = rt.read_global("rocketlevel");
        rt.ini_write_real("Save", "rocketlevel", value);
        // GML 671: ini_write_real("Save", "laserlevel", global.laserlevel);
        let value = rt.read_global("laserlevel");
        rt.ini_write_real("Save", "laserlevel", value);
        // GML 672: ini_write_real("Save", "icegunlevel", global.icegunlevel);
        let value = rt.read_global("icegunlevel");
        rt.ini_write_real("Save", "icegunlevel", value);
        // GML 673: ini_write_real("Save", "bowlevel", global.bowlevel);
        let value = rt.read_global("bowlevel");
        rt.ini_write_real("Save", "bowlevel", value);
        // GML 674: ini_write_real("Save", "bladegunlevel", global.bladegunlevel);
        let value = rt.read_global("bladegunlevel");
        rt.ini_write_real("Save", "bladegunlevel", value);
        // GML 675: ini_write_real("Save", "flamethrowerlevel", global.flamethrowerlevel);
        let value = rt.read_global("flamethrowerlevel");
        rt.ini_write_real("Save", "flamethrowerlevel", value);
        // GML 676: ini_write_real("Save", "boomerangbought", global.boomerangbought);
        let value = rt.read_global("boomerangbought");
        rt.ini_write_real("Save", "boomerangbought", value);
        // GML 677: ini_write_real("Save", "boomerangxp", global.boomerangxp);
        let value = rt.read_global("boomerangxp");
        rt.ini_write_real("Save", "boomerangxp", value);
        // GML 678: ini_write_real("Save", "boomeranglevel", global.boomeranglevel);
        let value = rt.read_global("boomeranglevel");
        rt.ini_write_real("Save", "boomeranglevel", value);
        // GML 679: ini_write_real("Save", "boomerangxptolevelup", global.boomerangxptolevelup);
        let value = rt.read_global("boomerangxptolevelup");
        rt.ini_write_real("Save", "boomerangxptolevelup", value);
        // GML 680: ini_write_real("Save", "spikegunbought", global.spikegunbought);
        let value = rt.read_global("spikegunbought");
        rt.ini_write_real("Save", "spikegunbought", value);
        // GML 681: ini_write_real("Save", "spikegunxp", global.spikegunxp);
        let value = rt.read_global("spikegunxp");
        rt.ini_write_real("Save", "spikegunxp", value);
        // GML 682: ini_write_real("Save", "spikegunlevel", global.spikegunlevel);
        let value = rt.read_global("spikegunlevel");
        rt.ini_write_real("Save", "spikegunlevel", value);
        // GML 683: ini_write_real("Save", "spikegunxptolevelup", global.spikegunxptolevelup);
        let value = rt.read_global("spikegunxptolevelup");
        rt.ini_write_real("Save", "spikegunxptolevelup", value);
        // GML 684: ini_write_real("Save", "drawchangepistol4", global.drawchangepistol4);
        let value = rt.read_global("drawchangepistol4");
        rt.ini_write_real("Save", "drawchangepistol4", value);
        // GML 685: ini_write_real("Save", "drawchangeshotgun4", global.drawchangeshotgun4);
        let value = rt.read_global("drawchangeshotgun4");
        rt.ini_write_real("Save", "drawchangeshotgun4", value);
        // GML 686: ini_write_real("Save", "drawchangeassaultrifle4", global.drawchangeassaultrifle4);
        let value = rt.read_global("drawchangeassaultrifle4");
        rt.ini_write_real("Save", "drawchangeassaultrifle4", value);
        // GML 687: ini_write_real("Save", "drawchangerocket4", global.drawchangerocket4);
        let value = rt.read_global("drawchangerocket4");
        rt.ini_write_real("Save", "drawchangerocket4", value);
        // GML 688: ini_write_real("Save", "drawchangelaser4", global.drawchangelaser4);
        let value = rt.read_global("drawchangelaser4");
        rt.ini_write_real("Save", "drawchangelaser4", value);
        // GML 689: ini_write_real("Save", "drawchangeicegun4", global.drawchangeicegun4);
        let value = rt.read_global("drawchangeicegun4");
        rt.ini_write_real("Save", "drawchangeicegun4", value);
        // GML 690: ini_write_real("Save", "drawchangebow4", global.drawchangebow4);
        let value = rt.read_global("drawchangebow4");
        rt.ini_write_real("Save", "drawchangebow4", value);
        // GML 691: ini_write_real("Save", "drawchangebladegun4", global.drawchangebladegun4);
        let value = rt.read_global("drawchangebladegun4");
        rt.ini_write_real("Save", "drawchangebladegun4", value);
        // GML 692: ini_write_real("Save", "drawchangeflamethrower4", global.drawchangeflamethrower4);
        let value = rt.read_global("drawchangeflamethrower4");
        rt.ini_write_real("Save", "drawchangeflamethrower4", value);
        // GML 693: ini_write_real("Save", "drawchangeboomerang4", global.drawchangeboomerang4);
        let value = rt.read_global("drawchangeboomerang4");
        rt.ini_write_real("Save", "drawchangeboomerang4", value);
        // GML 694: ini_write_real("Save", "drawchangespikegun4", global.drawchangespikegun4);
        let value = rt.read_global("drawchangespikegun4");
        rt.ini_write_real("Save", "drawchangespikegun4", value);
        // GML 695: ini_write_real("Save", "drawchangebombgun4", global.drawchangebombgun4);
        let value = rt.read_global("drawchangebombgun4");
        rt.ini_write_real("Save", "drawchangebombgun4", value);
        // GML 696: ini_write_real("Save", "drawchangepistol7", global.drawchangepistol7);
        let value = rt.read_global("drawchangepistol7");
        rt.ini_write_real("Save", "drawchangepistol7", value);
        // GML 697: ini_write_real("Save", "drawchangeshotgun7", global.drawchangeshotgun7);
        let value = rt.read_global("drawchangeshotgun7");
        rt.ini_write_real("Save", "drawchangeshotgun7", value);
        // GML 698: ini_write_real("Save", "drawchangeassaultrifle7", global.drawchangeassaultrifle7);
        let value = rt.read_global("drawchangeassaultrifle7");
        rt.ini_write_real("Save", "drawchangeassaultrifle7", value);
        // GML 699: ini_write_real("Save", "drawchangerocket7", global.drawchangerocket7);
        let value = rt.read_global("drawchangerocket7");
        rt.ini_write_real("Save", "drawchangerocket7", value);
        // GML 700: ini_write_real("Save", "drawchangelaser7", global.drawchangelaser7);
        let value = rt.read_global("drawchangelaser7");
        rt.ini_write_real("Save", "drawchangelaser7", value);
        // GML 701: ini_write_real("Save", "drawchangeicegun7", global.drawchangeicegun7);
        let value = rt.read_global("drawchangeicegun7");
        rt.ini_write_real("Save", "drawchangeicegun7", value);
        // GML 702: ini_write_real("Save", "drawchangebow7", global.drawchangebow7);
        let value = rt.read_global("drawchangebow7");
        rt.ini_write_real("Save", "drawchangebow7", value);
        // GML 703: ini_write_real("Save", "drawchangebladegun7", global.drawchangebladegun7);
        let value = rt.read_global("drawchangebladegun7");
        rt.ini_write_real("Save", "drawchangebladegun7", value);
        // GML 704: ini_write_real("Save", "drawchangeflamethrower7", global.drawchangeflamethrower7);
        let value = rt.read_global("drawchangeflamethrower7");
        rt.ini_write_real("Save", "drawchangeflamethrower7", value);
        // GML 705: ini_write_real("Save", "drawchangeboomerang7", global.drawchangeboomerang7);
        let value = rt.read_global("drawchangeboomerang7");
        rt.ini_write_real("Save", "drawchangeboomerang7", value);
        // GML 706: ini_write_real("Save", "drawchangespikegun7", global.drawchangespikegun7);
        let value = rt.read_global("drawchangespikegun7");
        rt.ini_write_real("Save", "drawchangespikegun7", value);
        // GML 707: ini_write_real("Save", "drawchangebombgun7", global.drawchangebombgun7);
        let value = rt.read_global("drawchangebombgun7");
        rt.ini_write_real("Save", "drawchangebombgun7", value);
        // GML 708: ini_write_real("Save", "drawchangepistol10", global.drawchangepistol10);
        let value = rt.read_global("drawchangepistol10");
        rt.ini_write_real("Save", "drawchangepistol10", value);
        // GML 709: ini_write_real("Save", "drawchangeshotgun10", global.drawchangeshotgun10);
        let value = rt.read_global("drawchangeshotgun10");
        rt.ini_write_real("Save", "drawchangeshotgun10", value);
        // GML 710: ini_write_real("Save", "drawchangeassaultrifle10", global.drawchangeassaultrifle10);
        let value = rt.read_global("drawchangeassaultrifle10");
        rt.ini_write_real("Save", "drawchangeassaultrifle10", value);
        // GML 711: ini_write_real("Save", "drawchangerocket10", global.drawchangerocket10);
        let value = rt.read_global("drawchangerocket10");
        rt.ini_write_real("Save", "drawchangerocket10", value);
        // GML 712: ini_write_real("Save", "drawchangelaser10", global.drawchangelaser10);
        let value = rt.read_global("drawchangelaser10");
        rt.ini_write_real("Save", "drawchangelaser10", value);
        // GML 713: ini_write_real("Save", "drawchangeicegun10", global.drawchangeicegun10);
        let value = rt.read_global("drawchangeicegun10");
        rt.ini_write_real("Save", "drawchangeicegun10", value);
        // GML 714: ini_write_real("Save", "drawchangebow10", global.drawchangebow10);
        let value = rt.read_global("drawchangebow10");
        rt.ini_write_real("Save", "drawchangebow10", value);
        // GML 715: ini_write_real("Save", "drawchangebladegun10", global.drawchangebladegun10);
        let value = rt.read_global("drawchangebladegun10");
        rt.ini_write_real("Save", "drawchangebladegun10", value);
        // GML 716: ini_write_real("Save", "drawchangeflamethrower10", global.drawchangeflamethrower10);
        let value = rt.read_global("drawchangeflamethrower10");
        rt.ini_write_real("Save", "drawchangeflamethrower10", value);
        // GML 717: ini_write_real("Save", "drawchangeboomerang10", global.drawchangeboomerang10);
        let value = rt.read_global("drawchangeboomerang10");
        rt.ini_write_real("Save", "drawchangeboomerang10", value);
        // GML 718: ini_write_real("Save", "drawchangespikegun10", global.drawchangespikegun10);
        let value = rt.read_global("drawchangespikegun10");
        rt.ini_write_real("Save", "drawchangespikegun10", value);
        // GML 719: ini_write_real("Save", "drawchangebombgun10", global.drawchangebombgun10);
        let value = rt.read_global("drawchangebombgun10");
        rt.ini_write_real("Save", "drawchangebombgun10", value);
        // GML 720: ini_write_real("Save", "knifebanditskilled", global.knifebanditskilled);
        let value = rt.read_global("knifebanditskilled");
        rt.ini_write_real("Save", "knifebanditskilled", value);
        // GML 721: ini_write_real("Save", "pistolthugskilled", global.pistolthugskilled);
        let value = rt.read_global("pistolthugskilled");
        rt.ini_write_real("Save", "pistolthugskilled", value);
        // GML 722: ini_write_real("Save", "chomperbotkilled", global.chomperbotkilled);
        let value = rt.read_global("chomperbotkilled");
        rt.ini_write_real("Save", "chomperbotkilled", value);
        // GML 723: ini_write_real("Save", "greenslimeskilled", global.greenslimeskilled);
        let value = rt.read_global("greenslimeskilled");
        rt.ini_write_real("Save", "greenslimeskilled", value);
        // GML 724: ini_write_real("Save", "wolfkilled", global.wolfkilled);
        let value = rt.read_global("wolfkilled");
        rt.ini_write_real("Save", "wolfkilled", value);
        // GML 725: ini_write_real("Save", "fireslimeskilled", global.fireslimeskilled);
        let value = rt.read_global("fireslimeskilled");
        rt.ini_write_real("Save", "fireslimeskilled", value);
        // GML 726: ini_write_real("Save", "hulkingbanditskilled", global.hulkingbanditskilled);
        let value = rt.read_global("hulkingbanditskilled");
        rt.ini_write_real("Save", "hulkingbanditskilled", value);
        // GML 727: ini_write_real("Save", "ghostskilled", global.ghostskilled);
        let value = rt.read_global("ghostskilled");
        rt.ini_write_real("Save", "ghostskilled", value);
        // GML 728: ini_write_real("Save", "skeletonskilled", global.skeletonskilled);
        let value = rt.read_global("skeletonskilled");
        rt.ini_write_real("Save", "skeletonskilled", value);
        // GML 729: ini_write_real("Save", "zombieskilled", global.zombieskilled);
        let value = rt.read_global("zombieskilled");
        rt.ini_write_real("Save", "zombieskilled", value);
        // GML 730: ini_write_real("Save", "firehulkskilled", global.firehulkskilled);
        let value = rt.read_global("firehulkskilled");
        rt.ini_write_real("Save", "firehulkskilled", value);
        // GML 731: ini_write_real("Save", "batskilled", global.batskilled);
        let value = rt.read_global("batskilled");
        rt.ini_write_real("Save", "batskilled", value);
        // GML 732: ini_write_real("Save", "trapskilled", global.trapskilled);
        let value = rt.read_global("trapskilled");
        rt.ini_write_real("Save", "trapskilled", value);
        // GML 733: ini_write_real("Save", "enemieskilled", global.enemieskilled);
        let value = rt.read_global("enemieskilled");
        rt.ini_write_real("Save", "enemieskilled", value);
        // GML 734: ini_write_real("Save", "boughtallguns", global.boughtallguns);
        let value = rt.read_global("boughtallguns");
        rt.ini_write_real("Save", "boughtallguns", value);
        // GML 735: ini_write_real("Save", "triplejumpachievement", global.triplejumpachievement);
        let value = rt.read_global("triplejumpachievement");
        rt.ini_write_real("Save", "triplejumpachievement", value);
        // GML 736: ini_write_real("Save", "boughtallupgrades", global.boughtallupgrades);
        let value = rt.read_global("boughtallupgrades");
        rt.ini_write_real("Save", "boughtallupgrades", value);
        // GML 737: ini_write_real("Save", "boughteverything", global.boughteverything);
        let value = rt.read_global("boughteverything");
        rt.ini_write_real("Save", "boughteverything", value);
        // GML 738: ini_write_real("Save", "achievemaxhp", global.achievemaxhp);
        let value = rt.read_global("achievemaxhp");
        rt.ini_write_real("Save", "achievemaxhp", value);
        // GML 739: ini_write_real("Save", "getmoney", global.getmoney);
        let value = rt.read_global("getmoney");
        rt.ini_write_real("Save", "getmoney", value);
        // GML 740: ini_write_real("Save", "hitmaxlevel", global.hitmaxlevel);
        let value = rt.read_global("hitmaxlevel");
        rt.ini_write_real("Save", "hitmaxlevel", value);
        // GML 741: ini_write_real("Save", "roomtownvisited", global.roomtownvisited);
        let value = rt.read_global("roomtownvisited");
        rt.ini_write_real("Save", "roomtownvisited", value);
        // GML 742: ini_write_real("Save", "level1visited", global.level1visited);
        let value = rt.read_global("level1visited");
        rt.ini_write_real("Save", "level1visited", value);
        // GML 743: ini_write_real("Save", "level2visited", global.level2visited);
        let value = rt.read_global("level2visited");
        rt.ini_write_real("Save", "level2visited", value);
        // GML 744: ini_write_real("Save", "level3visited", global.level3visited);
        let value = rt.read_global("level3visited");
        rt.ini_write_real("Save", "level3visited", value);
        // GML 745: ini_write_real("Save", "level4visited", global.level4visited);
        let value = rt.read_global("level4visited");
        rt.ini_write_real("Save", "level4visited", value);
        // GML 746: ini_write_real("Save", "level5visited", global.level5visited);
        let value = rt.read_global("level5visited");
        rt.ini_write_real("Save", "level5visited", value);
        // GML 747: ini_write_real("Save", "level6visited", global.level6visited);
        let value = rt.read_global("level6visited");
        rt.ini_write_real("Save", "level6visited", value);
        // GML 748: ini_write_real("Save", "level7visited", global.level7visited);
        let value = rt.read_global("level7visited");
        rt.ini_write_real("Save", "level7visited", value);
        // GML 749: ini_write_real("Save", "level8visited", global.level8visited);
        let value = rt.read_global("level8visited");
        rt.ini_write_real("Save", "level8visited", value);
        // GML 750: ini_write_real("Save", "level8avisited", global.level8avisited);
        let value = rt.read_global("level8avisited");
        rt.ini_write_real("Save", "level8avisited", value);
        // GML 751: ini_write_real("Save", "boss1visited", global.boss1visited);
        let value = rt.read_global("boss1visited");
        rt.ini_write_real("Save", "boss1visited", value);
        // GML 752: ini_write_real("Save", "level9visited", global.level9visited);
        let value = rt.read_global("level9visited");
        rt.ini_write_real("Save", "level9visited", value);
        // GML 753: ini_write_real("Save", "level9avisited", global.level9avisited);
        let value = rt.read_global("level9avisited");
        rt.ini_write_real("Save", "level9avisited", value);
        // GML 754: ini_write_real("Save", "level10visited", global.level10visited);
        let value = rt.read_global("level10visited");
        rt.ini_write_real("Save", "level10visited", value);
        // GML 755: ini_write_real("Save", "level11visited", global.level11visited);
        let value = rt.read_global("level11visited");
        rt.ini_write_real("Save", "level11visited", value);
        // GML 756: ini_write_real("Save", "level11avisited", global.level11avisited);
        let value = rt.read_global("level11avisited");
        rt.ini_write_real("Save", "level11avisited", value);
        // GML 757: ini_write_real("Save", "level12visited", global.level12visited);
        let value = rt.read_global("level12visited");
        rt.ini_write_real("Save", "level12visited", value);
        // GML 758: ini_write_real("Save", "level13visited", global.level13visited);
        let value = rt.read_global("level13visited");
        rt.ini_write_real("Save", "level13visited", value);
        // GML 759: ini_write_real("Save", "level13avisited", global.level13avisited);
        let value = rt.read_global("level13avisited");
        rt.ini_write_real("Save", "level13avisited", value);
        // GML 760: ini_write_real("Save", "level14visited", global.level14visited);
        let value = rt.read_global("level14visited");
        rt.ini_write_real("Save", "level14visited", value);
        // GML 761: ini_write_real("Save", "level14avisited", global.level14avisited);
        let value = rt.read_global("level14avisited");
        rt.ini_write_real("Save", "level14avisited", value);
        // GML 762: ini_write_real("Save", "level15visited", global.level15visited);
        let value = rt.read_global("level15visited");
        rt.ini_write_real("Save", "level15visited", value);
        // GML 763: ini_write_real("Save", "level15avisited", global.level15avisited);
        let value = rt.read_global("level15avisited");
        rt.ini_write_real("Save", "level15avisited", value);
        // GML 764: ini_write_real("Save", "level16visited", global.level16visited);
        let value = rt.read_global("level16visited");
        rt.ini_write_real("Save", "level16visited", value);
        // GML 765: ini_write_real("Save", "level16avisited", global.level16avisited);
        let value = rt.read_global("level16avisited");
        rt.ini_write_real("Save", "level16avisited", value);
        // GML 766: ini_write_real("Save", "level17visited", global.level17visited);
        let value = rt.read_global("level17visited");
        rt.ini_write_real("Save", "level17visited", value);
        // GML 767: ini_write_real("Save", "level17avisited", global.level17avisited);
        let value = rt.read_global("level17avisited");
        rt.ini_write_real("Save", "level17avisited", value);
        // GML 768: ini_write_real("Save", "boss2visited", global.boss2visited);
        let value = rt.read_global("boss2visited");
        rt.ini_write_real("Save", "boss2visited", value);
        // GML 769: ini_write_real("Save", "room31visited", global.room31visited);
        let value = rt.read_global("room31visited");
        rt.ini_write_real("Save", "room31visited", value);
        // GML 770: ini_write_real("Save", "room32visited", global.room32visited);
        let value = rt.read_global("room32visited");
        rt.ini_write_real("Save", "room32visited", value);
        // GML 771: ini_write_real("Save", "room33visited", global.room33visited);
        let value = rt.read_global("room33visited");
        rt.ini_write_real("Save", "room33visited", value);
        // GML 772: ini_write_real("Save", "room34visited", global.room34visited);
        let value = rt.read_global("room34visited");
        rt.ini_write_real("Save", "room34visited", value);
        // GML 773: ini_write_real("Save", "room35visited", global.room35visited);
        let value = rt.read_global("room35visited");
        rt.ini_write_real("Save", "room35visited", value);
        // GML 774: ini_write_real("Save", "room36visited", global.room36visited);
        let value = rt.read_global("room36visited");
        rt.ini_write_real("Save", "room36visited", value);
        // GML 775: ini_write_real("Save", "room37visited", global.room37visited);
        let value = rt.read_global("room37visited");
        rt.ini_write_real("Save", "room37visited", value);
        // GML 776: ini_write_real("Save", "room38visited", global.room38visited);
        let value = rt.read_global("room38visited");
        rt.ini_write_real("Save", "room38visited", value);
        // GML 777: ini_write_real("Save", "room39visited", global.room39visited);
        let value = rt.read_global("room39visited");
        rt.ini_write_real("Save", "room39visited", value);
        // GML 778: ini_write_real("Save", "room40visited", global.room40visited);
        let value = rt.read_global("room40visited");
        rt.ini_write_real("Save", "room40visited", value);
        // GML 779: ini_write_real("Save", "room41visited", global.room41visited);
        let value = rt.read_global("room41visited");
        rt.ini_write_real("Save", "room41visited", value);
        // GML 780: ini_write_real("Save", "room42visited", global.room42visited);
        let value = rt.read_global("room42visited");
        rt.ini_write_real("Save", "room42visited", value);
        // GML 781: ini_write_real("Save", "room43visited", global.room43visited);
        let value = rt.read_global("room43visited");
        rt.ini_write_real("Save", "room43visited", value);
        // GML 782: ini_write_real("Save", "room44visited", global.room44visited);
        let value = rt.read_global("room44visited");
        rt.ini_write_real("Save", "room44visited", value);
        // GML 783: ini_write_real("Save", "room45visited", global.room45visited);
        let value = rt.read_global("room45visited");
        rt.ini_write_real("Save", "room45visited", value);
        // GML 784: ini_write_real("Save", "room46visited", global.room46visited);
        let value = rt.read_global("room46visited");
        rt.ini_write_real("Save", "room46visited", value);
        // GML 785: ini_write_real("Save", "room47visited", global.room47visited);
        let value = rt.read_global("room47visited");
        rt.ini_write_real("Save", "room47visited", value);
        // GML 786: ini_write_real("Save", "room48visited", global.room48visited);
        let value = rt.read_global("room48visited");
        rt.ini_write_real("Save", "room48visited", value);
        // GML 787: ini_write_real("Save", "room49visited", global.room49visited);
        let value = rt.read_global("room49visited");
        rt.ini_write_real("Save", "room49visited", value);
        // GML 788: ini_write_real("Save", "room50visited", global.room50visited);
        let value = rt.read_global("room50visited");
        rt.ini_write_real("Save", "room50visited", value);
        // GML 789: ini_write_real("Save", "boss3visited", global.boss3visited);
        let value = rt.read_global("boss3visited");
        rt.ini_write_real("Save", "boss3visited", value);
        // GML 790: ini_write_real("Save", "room51visited", global.room51visited);
        let value = rt.read_global("room51visited");
        rt.ini_write_real("Save", "room51visited", value);
        // GML 791: ini_write_real("Save", "room52visited", global.room52visited);
        let value = rt.read_global("room52visited");
        rt.ini_write_real("Save", "room52visited", value);
        // GML 792: ini_write_real("Save", "room53visited", global.room53visited);
        let value = rt.read_global("room53visited");
        rt.ini_write_real("Save", "room53visited", value);
        // GML 793: ini_write_real("Save", "room54visited", global.room54visited);
        let value = rt.read_global("room54visited");
        rt.ini_write_real("Save", "room54visited", value);
        // GML 794: ini_write_real("Save", "room55visited", global.room55visited);
        let value = rt.read_global("room55visited");
        rt.ini_write_real("Save", "room55visited", value);
        // GML 795: ini_write_real("Save", "room56visited", global.room56visited);
        let value = rt.read_global("room56visited");
        rt.ini_write_real("Save", "room56visited", value);
        // GML 796: ini_write_real("Save", "room57visited", global.room57visited);
        let value = rt.read_global("room57visited");
        rt.ini_write_real("Save", "room57visited", value);
        // GML 797: ini_write_real("Save", "room58visited", global.room58visited);
        let value = rt.read_global("room58visited");
        rt.ini_write_real("Save", "room58visited", value);
        // GML 798: ini_write_real("Save", "room59visited", global.room59visited);
        let value = rt.read_global("room59visited");
        rt.ini_write_real("Save", "room59visited", value);
        // GML 799: ini_write_real("Save", "room60visited", global.room60visited);
        let value = rt.read_global("room60visited");
        rt.ini_write_real("Save", "room60visited", value);
        // GML 800: ini_write_real("Save", "room61visited", global.room61visited);
        let value = rt.read_global("room61visited");
        rt.ini_write_real("Save", "room61visited", value);
        // GML 801: ini_write_real("Save", "room62visited", global.room62visited);
        let value = rt.read_global("room62visited");
        rt.ini_write_real("Save", "room62visited", value);
        // GML 802: ini_write_real("Save", "room63visited", global.room63visited);
        let value = rt.read_global("room63visited");
        rt.ini_write_real("Save", "room63visited", value);
        // GML 803: ini_write_real("Save", "room64visited", global.room64visited);
        let value = rt.read_global("room64visited");
        rt.ini_write_real("Save", "room64visited", value);
        // GML 804: ini_write_real("Save", "room65visited", global.room65visited);
        let value = rt.read_global("room65visited");
        rt.ini_write_real("Save", "room65visited", value);
        // GML 805: ini_write_real("Save", "boss4visited", global.boss4visited);
        let value = rt.read_global("boss4visited");
        rt.ini_write_real("Save", "boss4visited", value);
        // GML 806: ini_write_real("Save", "room66visited", global.room66visited);
        let value = rt.read_global("room66visited");
        rt.ini_write_real("Save", "room66visited", value);
        // GML 807: ini_write_real("Save", "room67visited", global.room67visited);
        let value = rt.read_global("room67visited");
        rt.ini_write_real("Save", "room67visited", value);
        // GML 808: ini_write_real("Save", "room68visited", global.room68visited);
        let value = rt.read_global("room68visited");
        rt.ini_write_real("Save", "room68visited", value);
        // GML 809: ini_write_real("Save", "room69visited", global.room69visited);
        let value = rt.read_global("room69visited");
        rt.ini_write_real("Save", "room69visited", value);
        // GML 810: ini_write_real("Save", "room70visited", global.room70visited);
        let value = rt.read_global("room70visited");
        rt.ini_write_real("Save", "room70visited", value);
        // GML 811: ini_write_real("Save", "room71visited", global.room71visited);
        let value = rt.read_global("room71visited");
        rt.ini_write_real("Save", "room71visited", value);
        // GML 812: ini_write_real("Save", "room72visited", global.room72visited);
        let value = rt.read_global("room72visited");
        rt.ini_write_real("Save", "room72visited", value);
        // GML 813: ini_write_real("Save", "room73visited", global.room73visited);
        let value = rt.read_global("room73visited");
        rt.ini_write_real("Save", "room73visited", value);
        // GML 814: ini_write_real("Save", "room74visited", global.room74visited);
        let value = rt.read_global("room74visited");
        rt.ini_write_real("Save", "room74visited", value);
        // GML 815: ini_write_real("Save", "room75visited", global.room75visited);
        let value = rt.read_global("room75visited");
        rt.ini_write_real("Save", "room75visited", value);
        // GML 816: ini_write_real("Save", "room76visited", global.room76visited);
        let value = rt.read_global("room76visited");
        rt.ini_write_real("Save", "room76visited", value);
        // GML 817: ini_write_real("Save", "room77visited", global.room77visited);
        let value = rt.read_global("room77visited");
        rt.ini_write_real("Save", "room77visited", value);
        // GML 818: ini_write_real("Save", "room78visited", global.room78visited);
        let value = rt.read_global("room78visited");
        rt.ini_write_real("Save", "room78visited", value);
        // GML 819: ini_write_real("Save", "room79visited", global.room79visited);
        let value = rt.read_global("room79visited");
        rt.ini_write_real("Save", "room79visited", value);
        // GML 820: ini_write_real("Save", "room80visited", global.room80visited);
        let value = rt.read_global("room80visited");
        rt.ini_write_real("Save", "room80visited", value);
        // GML 821: ini_write_real("Save", "room81visited", global.room81visited);
        let value = rt.read_global("room81visited");
        rt.ini_write_real("Save", "room81visited", value);
        // GML 822: ini_write_real("Save", "room82visited", global.room82visited);
        let value = rt.read_global("room82visited");
        rt.ini_write_real("Save", "room82visited", value);
        // GML 823: ini_write_real("Save", "boss5visited", global.boss5visited);
        let value = rt.read_global("boss5visited");
        rt.ini_write_real("Save", "boss5visited", value);
        // GML 824: ini_write_real("Save", "room83visited", global.room83visited);
        let value = rt.read_global("room83visited");
        rt.ini_write_real("Save", "room83visited", value);
        // GML 825: ini_write_real("Save", "room84visited", global.room84visited);
        let value = rt.read_global("room84visited");
        rt.ini_write_real("Save", "room84visited", value);
        // GML 826: ini_write_real("Save", "room85visited", global.room85visited);
        let value = rt.read_global("room85visited");
        rt.ini_write_real("Save", "room85visited", value);
        // GML 827: ini_write_real("Save", "room86visited", global.room86visited);
        let value = rt.read_global("room86visited");
        rt.ini_write_real("Save", "room86visited", value);
        // GML 828: ini_write_real("Save", "room87visited", global.room87visited);
        let value = rt.read_global("room87visited");
        rt.ini_write_real("Save", "room87visited", value);
        // GML 829: ini_write_real("Save", "room88visited", global.room88visited);
        let value = rt.read_global("room88visited");
        rt.ini_write_real("Save", "room88visited", value);
        // GML 830: ini_write_real("Save", "room89visited", global.room89visited);
        let value = rt.read_global("room89visited");
        rt.ini_write_real("Save", "room89visited", value);
        // GML 831: ini_write_real("Save", "room90visited", global.room90visited);
        let value = rt.read_global("room90visited");
        rt.ini_write_real("Save", "room90visited", value);
        // GML 832: ini_write_real("Save", "room91visited", global.room91visited);
        let value = rt.read_global("room91visited");
        rt.ini_write_real("Save", "room91visited", value);
        // GML 833: ini_write_real("Save", "room92visited", global.room92visited);
        let value = rt.read_global("room92visited");
        rt.ini_write_real("Save", "room92visited", value);
        // GML 834: ini_write_real("Save", "room93visited", global.room93visited);
        let value = rt.read_global("room93visited");
        rt.ini_write_real("Save", "room93visited", value);
        // GML 835: ini_write_real("Save", "room94visited", global.room94visited);
        let value = rt.read_global("room94visited");
        rt.ini_write_real("Save", "room94visited", value);
        // GML 836: ini_write_real("Save", "room95visited", global.room95visited);
        let value = rt.read_global("room95visited");
        rt.ini_write_real("Save", "room95visited", value);
        // GML 837: ini_write_real("Save", "room96visited", global.room96visited);
        let value = rt.read_global("room96visited");
        rt.ini_write_real("Save", "room96visited", value);
        // GML 838: ini_write_real("Save", "room97visited", global.room97visited);
        let value = rt.read_global("room97visited");
        rt.ini_write_real("Save", "room97visited", value);
        // GML 839: ini_write_real("Save", "room98visited", global.room98visited);
        let value = rt.read_global("room98visited");
        rt.ini_write_real("Save", "room98visited", value);
        // GML 840: ini_write_real("Save", "room99visited", global.room99visited);
        let value = rt.read_global("room99visited");
        rt.ini_write_real("Save", "room99visited", value);
        // GML 841: ini_write_real("Save", "room100visited", global.room100visited);
        let value = rt.read_global("room100visited");
        rt.ini_write_real("Save", "room100visited", value);
        // GML 842: ini_write_real("Save", "room101visited", global.room101visited);
        let value = rt.read_global("room101visited");
        rt.ini_write_real("Save", "room101visited", value);
        // GML 843: ini_write_real("Save", "room102visited", global.room102visited);
        let value = rt.read_global("room102visited");
        rt.ini_write_real("Save", "room102visited", value);
        // GML 844: ini_write_real("Save", "room103visited", global.room103visited);
        let value = rt.read_global("room103visited");
        rt.ini_write_real("Save", "room103visited", value);
        // GML 845: ini_write_real("Save", "boss6visited", global.boss6visited);
        let value = rt.read_global("boss6visited");
        rt.ini_write_real("Save", "boss6visited", value);
        // GML 846: ini_write_real("Save", "soundmute", global.soundmute);
        let value = rt.read_global("soundmute");
        rt.ini_write_real("Save", "soundmute", value);
        // GML 847: ini_write_real("Save", "musicmute", global.musicmute);
        let value = rt.read_global("musicmute");
        rt.ini_write_real("Save", "musicmute", value);
        // GML 848: ini_write_real("Save", "beartouched", global.beartouched);
        let value = rt.read_global("beartouched");
        rt.ini_write_real("Save", "beartouched", value);
        // GML 849: ini_write_real("Save", "knifetouched", global.knifetouched);
        let value = rt.read_global("knifetouched");
        rt.ini_write_real("Save", "knifetouched", value);
        // GML 850: ini_write_real("Save", "spidertouched", global.spidertouched);
        let value = rt.read_global("spidertouched");
        rt.ini_write_real("Save", "spidertouched", value);
        // GML 851: ini_write_real("Save", "battouched", global.battouched);
        let value = rt.read_global("battouched");
        rt.ini_write_real("Save", "battouched", value);
        // GML 852: ini_write_real("Save", "wolftouched", global.wolftouched);
        let value = rt.read_global("wolftouched");
        rt.ini_write_real("Save", "wolftouched", value);
        // GML 853: ini_write_real("Save", "pistolbandittouched", global.pistolbandittouched);
        let value = rt.read_global("pistolbandittouched");
        rt.ini_write_real("Save", "pistolbandittouched", value);
        // GML 854: ini_write_real("Save", "boss1touched", global.boss1touched);
        let value = rt.read_global("boss1touched");
        rt.ini_write_real("Save", "boss1touched", value);
        // GML 855: ini_write_real("Save", "turrettouched", global.turrettouched);
        let value = rt.read_global("turrettouched");
        rt.ini_write_real("Save", "turrettouched", value);
        // GML 856: ini_write_real("Save", "slimetouched", global.slimetouched);
        let value = rt.read_global("slimetouched");
        rt.ini_write_real("Save", "slimetouched", value);
        // GML 857: ini_write_real("Save", "boss2touched", global.boss2touched);
        let value = rt.read_global("boss2touched");
        rt.ini_write_real("Save", "boss2touched", value);
        // GML 858: ini_write_real("Save", "zombietouched", global.zombietouched);
        let value = rt.read_global("zombietouched");
        rt.ini_write_real("Save", "zombietouched", value);
        // GML 859: ini_write_real("Save", "redslimetouched", global.redslimetouched);
        let value = rt.read_global("redslimetouched");
        rt.ini_write_real("Save", "redslimetouched", value);
        // GML 860: ini_write_real("Save", "skeletontouched", global.skeletontouched);
        let value = rt.read_global("skeletontouched");
        rt.ini_write_real("Save", "skeletontouched", value);
        // GML 861: ini_write_real("Save", "hulkingbandittouched", global.hulkingbandittouched);
        let value = rt.read_global("hulkingbandittouched");
        rt.ini_write_real("Save", "hulkingbandittouched", value);
        // GML 862: ini_write_real("Save", "beetouched", global.beetouched);
        let value = rt.read_global("beetouched");
        rt.ini_write_real("Save", "beetouched", value);
        // GML 863: ini_write_real("Save", "boss3touched", global.boss3touched);
        let value = rt.read_global("boss3touched");
        rt.ini_write_real("Save", "boss3touched", value);
        // GML 864: ini_write_real("Save", "firehulktouched", global.firehulktouched);
        let value = rt.read_global("firehulktouched");
        rt.ini_write_real("Save", "firehulktouched", value);
        // GML 865: ini_write_real("Save", "boss4touched", global.boss4touched);
        let value = rt.read_global("boss4touched");
        rt.ini_write_real("Save", "boss4touched", value);
        // GML 866: ini_write_real("Save", "boss5touched", global.boss5touched);
        let value = rt.read_global("boss5touched");
        rt.ini_write_real("Save", "boss5touched", value);
        // GML 867: ini_write_real("Save", "boss6touched", global.boss6touched);
        let value = rt.read_global("boss6touched");
        rt.ini_write_real("Save", "boss6touched", value);
        // GML 868: ini_close();
        rt.ini_close();
        // GML 869: }
    }
    // GML 870: if (file_exists("savefile2.ini"))
    if rt.file_exists("savefile2.ini") {
        // GML 871: {
        // GML 872: ini_open("savefile2.ini");
        rt.ini_open("savefile2.ini");
        // GML 873: global.levelchallenge1visited = ini_read_real("Save", "levelchallenge1visited", 0);
        let value = rt.ini_read_real("Save", "levelchallenge1visited", 0.0);
        rt.write_global("levelchallenge1visited", value);
        // GML 874: global.levelchallenge2visited = ini_read_real("Save", "levelchallenge2visited", 0);
        let value = rt.ini_read_real("Save", "levelchallenge2visited", 0.0);
        rt.write_global("levelchallenge2visited", value);
        // GML 875: global.levelchallenge3visited = ini_read_real("Save", "levelchallenge3visited", 0);
        let value = rt.ini_read_real("Save", "levelchallenge3visited", 0.0);
        rt.write_global("levelchallenge3visited", value);
        // GML 876: global.levelchallenge4visited = ini_read_real("Save", "levelchallenge4visited", 0);
        let value = rt.ini_read_real("Save", "levelchallenge4visited", 0.0);
        rt.write_global("levelchallenge4visited", value);
        // GML 877: global.levelchallenge5visited = ini_read_real("Save", "levelchallenge5visited", 0);
        let value = rt.ini_read_real("Save", "levelchallenge5visited", 0.0);
        rt.write_global("levelchallenge5visited", value);
        // GML 878: global.talkedtolloyd16 = ini_read_real("Save", "talkedtolloyd16", 0);
        let value = rt.ini_read_real("Save", "talkedtolloyd16", 0.0);
        rt.write_global("talkedtolloyd16", value);
        // GML 879: ini_write_real("Save", "levelchallenge1visited", global.levelchallenge1visited);
        let value = rt.read_global("levelchallenge1visited");
        rt.ini_write_real("Save", "levelchallenge1visited", value);
        // GML 880: ini_write_real("Save", "levelchallenge2visited", global.levelchallenge2visited);
        let value = rt.read_global("levelchallenge2visited");
        rt.ini_write_real("Save", "levelchallenge2visited", value);
        // GML 881: ini_write_real("Save", "levelchallenge3visited", global.levelchallenge3visited);
        let value = rt.read_global("levelchallenge3visited");
        rt.ini_write_real("Save", "levelchallenge3visited", value);
        // GML 882: ini_write_real("Save", "levelchallenge4visited", global.levelchallenge4visited);
        let value = rt.read_global("levelchallenge4visited");
        rt.ini_write_real("Save", "levelchallenge4visited", value);
        // GML 883: ini_write_real("Save", "levelchallenge5visited", global.levelchallenge5visited);
        let value = rt.read_global("levelchallenge5visited");
        rt.ini_write_real("Save", "levelchallenge5visited", value);
        // GML 884: ini_write_real("Save", "talkedtolloyd16", global.talkedtolloyd16);
        let value = rt.read_global("talkedtolloyd16");
        rt.ini_write_real("Save", "talkedtolloyd16", value);
        // GML 885: ini_close();
        rt.ini_close();
        // GML 886: }
    }
    // GML 887: else if (!file_exists("savefile2.ini"))
    else if !rt.file_exists("savefile2.ini") {
        // GML 888: {
        // GML 889: global.levelchallenge1visited = 0;
        rt.write_global("levelchallenge1visited", 0.0);
        // GML 890: global.levelchallenge2visited = 0;
        rt.write_global("levelchallenge2visited", 0.0);
        // GML 891: global.levelchallenge3visited = 0;
        rt.write_global("levelchallenge3visited", 0.0);
        // GML 892: global.levelchallenge4visited = 0;
        rt.write_global("levelchallenge4visited", 0.0);
        // GML 893: global.levelchallenge5visited = 0;
        rt.write_global("levelchallenge5visited", 0.0);
        // GML 894: global.talkedtolloyd16 = 0;
        rt.write_global("talkedtolloyd16", 0.0);
        // GML 895: }
    }
    // GML 896: if (file_exists("savefile3.ini"))
    if rt.file_exists("savefile3.ini") {
        // GML 897: {
        // GML 898: ini_open("savefile3.ini");
        rt.ini_open("savefile3.ini");
        // GML 899: global.twentyfivebears = ini_read_real("Save", "twentyfivebears", 0);
        let value = rt.ini_read_real("Save", "twentyfivebears", 0.0);
        rt.write_global("twentyfivebears", value);
        // GML 900: global.onehundredbears = ini_read_real("Save", "onehundredbears", 0);
        let value = rt.ini_read_real("Save", "onehundredbears", 0.0);
        rt.write_global("onehundredbears", value);
        // GML 901: global.twentyfivewolf = ini_read_real("Save", "twentyfivewolf", 0);
        let value = rt.ini_read_real("Save", "twentyfivewolf", 0.0);
        rt.write_global("twentyfivewolf", value);
        // GML 902: global.onehundredwolf = ini_read_real("Save", "onehundredwolf", 0);
        let value = rt.ini_read_real("Save", "onehundredwolf", 0.0);
        rt.write_global("onehundredwolf", value);
        // GML 903: global.twentyfiveknifebandit = ini_read_real("Save", "twentyfiveknifebandit", 0);
        let value = rt.ini_read_real("Save", "twentyfiveknifebandit", 0.0);
        rt.write_global("twentyfiveknifebandit", value);
        // GML 904: global.onehundredknifebandit = ini_read_real("Save", "onehundredknifebandit", 0);
        let value = rt.ini_read_real("Save", "onehundredknifebandit", 0.0);
        rt.write_global("onehundredknifebandit", value);
        // GML 905: global.twentyfivepistolthug = ini_read_real("Save", "twentyfivepistolthug", 0);
        let value = rt.ini_read_real("Save", "twentyfivepistolthug", 0.0);
        rt.write_global("twentyfivepistolthug", value);
        // GML 906: global.onehundredpistolthug = ini_read_real("Save", "onehundredpistolthug", 0);
        let value = rt.ini_read_real("Save", "onehundredpistolthug", 0.0);
        rt.write_global("onehundredpistolthug", value);
        // GML 907: global.twentyfivespiders = ini_read_real("Save", "twentyfivespiders", 0);
        let value = rt.ini_read_real("Save", "twentyfivespiders", 0.0);
        rt.write_global("twentyfivespiders", value);
        // GML 908: global.onehundredspiders = ini_read_real("Save", "onehundredspiders", 0);
        let value = rt.ini_read_real("Save", "onehundredspiders", 0.0);
        rt.write_global("onehundredspiders", value);
        // GML 909: global.twentyfiveslimes = ini_read_real("Save", "twentyfiveslimes", 0);
        let value = rt.ini_read_real("Save", "twentyfiveslimes", 0.0);
        rt.write_global("twentyfiveslimes", value);
        // GML 910: global.onehundredslimes = ini_read_real("Save", "onehundredslimes", 0);
        let value = rt.ini_read_real("Save", "onehundredslimes", 0.0);
        rt.write_global("onehundredslimes", value);
        // GML 911: global.twentyfivefireslimes = ini_read_real("Save", "twentyfivefireslimes", 0);
        let value = rt.ini_read_real("Save", "twentyfivefireslimes", 0.0);
        rt.write_global("twentyfivefireslimes", value);
        // GML 912: global.onehundredfireslimes = ini_read_real("Save", "onehundredfireslimes", 0);
        let value = rt.ini_read_real("Save", "onehundredfireslimes", 0.0);
        rt.write_global("onehundredfireslimes", value);
        // GML 913: global.twentyfivehulking = ini_read_real("Save", "twentyfivehulking", 0);
        let value = rt.ini_read_real("Save", "twentyfivehulking", 0.0);
        rt.write_global("twentyfivehulking", value);
        // GML 914: global.onehundredhulking = ini_read_real("Save", "onehundredhulking", 0);
        let value = rt.ini_read_real("Save", "onehundredhulking", 0.0);
        rt.write_global("onehundredhulking", value);
        // GML 915: global.twentyfiveghost = ini_read_real("Save", "twentyfiveghost", 0);
        let value = rt.ini_read_real("Save", "twentyfiveghost", 0.0);
        rt.write_global("twentyfiveghost", value);
        // GML 916: global.onehundredghost = ini_read_real("Save", "onehundredghost", 0);
        let value = rt.ini_read_real("Save", "onehundredghost", 0.0);
        rt.write_global("onehundredghost", value);
        // GML 917: global.twentyfiveskeleton = ini_read_real("Save", "twentyfiveskeleton", 0);
        let value = rt.ini_read_real("Save", "twentyfiveskeleton", 0.0);
        rt.write_global("twentyfiveskeleton", value);
        // GML 918: global.onehundredskeleton = ini_read_real("Save", "onehundredskeleton", 0);
        let value = rt.ini_read_real("Save", "onehundredskeleton", 0.0);
        rt.write_global("onehundredskeleton", value);
        // GML 919: global.twentyfivezombie = ini_read_real("Save", "twentyfivezombie", 0);
        let value = rt.ini_read_real("Save", "twentyfivezombie", 0.0);
        rt.write_global("twentyfivezombie", value);
        // GML 920: global.onehundredzombie = ini_read_real("Save", "onehundredzombie", 0);
        let value = rt.ini_read_real("Save", "onehundredzombie", 0.0);
        rt.write_global("onehundredzombie", value);
        // GML 921: global.twentyfivebalrog = ini_read_real("Save", "twentyfivebalrog", 0);
        let value = rt.ini_read_real("Save", "twentyfivebalrog", 0.0);
        rt.write_global("twentyfivebalrog", value);
        // GML 922: global.onehundredbalrog = ini_read_real("Save", "onehundredbalrog", 0);
        let value = rt.ini_read_real("Save", "onehundredbalrog", 0.0);
        rt.write_global("onehundredbalrog", value);
        // GML 923: global.twentyfivebat = ini_read_real("Save", "twentyfivebat", 0);
        let value = rt.ini_read_real("Save", "twentyfivebat", 0.0);
        rt.write_global("twentyfivebat", value);
        // GML 924: global.onehundredbat = ini_read_real("Save", "onehundredbat", 0);
        let value = rt.ini_read_real("Save", "onehundredbat", 0.0);
        rt.write_global("onehundredbat", value);
        // GML 925: global.twentyfivetrap = ini_read_real("Save", "twentyfivetrap", 0);
        let value = rt.ini_read_real("Save", "twentyfivetrap", 0.0);
        rt.write_global("twentyfivetrap", value);
        // GML 926: global.onehundredtrap = ini_read_real("Save", "onehundredtrap", 0);
        let value = rt.ini_read_real("Save", "onehundredtrap", 0.0);
        rt.write_global("onehundredtrap", value);
        // GML 927: global.twentyfiveenemies = ini_read_real("Save", "twentyfiveenemies", 0);
        let value = rt.ini_read_real("Save", "twentyfiveenemies", 0.0);
        rt.write_global("twentyfiveenemies", value);
        // GML 928: global.onehundredenemies = ini_read_real("Save", "onehundredenemies", 0);
        let value = rt.ini_read_real("Save", "onehundredenemies", 0.0);
        rt.write_global("onehundredenemies", value);
        // GML 929: global.fivehundredenemies = ini_read_real("Save", "fivehundredenemies", 0);
        let value = rt.ini_read_real("Save", "fivehundredenemies", 0.0);
        rt.write_global("fivehundredenemies", value);
        // GML 930: global.onethousandenemies = ini_read_real("Save", "onethousandenemies", 0);
        let value = rt.ini_read_real("Save", "onethousandenemies", 0.0);
        rt.write_global("onethousandenemies", value);
        // GML 931: global.achievementboughtjump = ini_read_real("Save", "achievementboughtjump", 0);
        let value = rt.ini_read_real("Save", "achievementboughtjump", 0.0);
        rt.write_global("achievementboughtjump", value);
        // GML 932: global.achievmentboughtupgrades = ini_read_real("Save", "achievmentboughtupgrades", 0);
        let value = rt.ini_read_real("Save", "achievmentboughtupgrades", 0.0);
        rt.write_global("achievmentboughtupgrades", value);
        // GML 933: global.hitmaxcallylevel = ini_read_real("Save", "hitmaxcallylevel", 0);
        let value = rt.ini_read_real("Save", "hitmaxcallylevel", 0.0);
        rt.write_global("hitmaxcallylevel", value);
        // GML 934: global.hitmoney = ini_read_real("Save", "hitmoney", 0);
        let value = rt.ini_read_real("Save", "hitmoney", 0.0);
        rt.write_global("hitmoney", value);
        // GML 935: ini_write_real("Save", "twentyfivebears", global.twentyfivebears);
        let value = rt.read_global("twentyfivebears");
        rt.ini_write_real("Save", "twentyfivebears", value);
        // GML 936: ini_write_real("Save", "onehundredbears", global.onehundredbears);
        let value = rt.read_global("onehundredbears");
        rt.ini_write_real("Save", "onehundredbears", value);
        // GML 937: ini_write_real("Save", "twentyfivewolf", global.twentyfivewolf);
        let value = rt.read_global("twentyfivewolf");
        rt.ini_write_real("Save", "twentyfivewolf", value);
        // GML 938: ini_write_real("Save", "onehundredwolf", global.onehundredwolf);
        let value = rt.read_global("onehundredwolf");
        rt.ini_write_real("Save", "onehundredwolf", value);
        // GML 939: ini_write_real("Save", "twentyfiveknifebandit", global.twentyfiveknifebandit);
        let value = rt.read_global("twentyfiveknifebandit");
        rt.ini_write_real("Save", "twentyfiveknifebandit", value);
        // GML 940: ini_write_real("Save", "onehundredknifebandit", global.onehundredknifebandit);
        let value = rt.read_global("onehundredknifebandit");
        rt.ini_write_real("Save", "onehundredknifebandit", value);
        // GML 941: ini_write_real("Save", "twentyfivepistolthug", global.twentyfivepistolthug);
        let value = rt.read_global("twentyfivepistolthug");
        rt.ini_write_real("Save", "twentyfivepistolthug", value);
        // GML 942: ini_write_real("Save", "onehundredpistolthug", global.onehundredpistolthug);
        let value = rt.read_global("onehundredpistolthug");
        rt.ini_write_real("Save", "onehundredpistolthug", value);
        // GML 943: ini_write_real("Save", "twentyfivespiders", global.twentyfivespiders);
        let value = rt.read_global("twentyfivespiders");
        rt.ini_write_real("Save", "twentyfivespiders", value);
        // GML 944: ini_write_real("Save", "onehundredspiders", global.onehundredspiders);
        let value = rt.read_global("onehundredspiders");
        rt.ini_write_real("Save", "onehundredspiders", value);
        // GML 945: ini_write_real("Save", "twentyfiveslimes", global.twentyfiveslimes);
        let value = rt.read_global("twentyfiveslimes");
        rt.ini_write_real("Save", "twentyfiveslimes", value);
        // GML 946: ini_write_real("Save", "onehundredslimes", global.onehundredslimes);
        let value = rt.read_global("onehundredslimes");
        rt.ini_write_real("Save", "onehundredslimes", value);
        // GML 947: ini_write_real("Save", "twentyfivefireslimes", global.twentyfivefireslimes);
        let value = rt.read_global("twentyfivefireslimes");
        rt.ini_write_real("Save", "twentyfivefireslimes", value);
        // GML 948: ini_write_real("Save", "onehundredfireslimes", global.onehundredfireslimes);
        let value = rt.read_global("onehundredfireslimes");
        rt.ini_write_real("Save", "onehundredfireslimes", value);
        // GML 949: ini_write_real("Save", "twentyfivehulking", global.twentyfivehulking);
        let value = rt.read_global("twentyfivehulking");
        rt.ini_write_real("Save", "twentyfivehulking", value);
        // GML 950: ini_write_real("Save", "onehundredhulking", global.onehundredhulking);
        let value = rt.read_global("onehundredhulking");
        rt.ini_write_real("Save", "onehundredhulking", value);
        // GML 951: ini_write_real("Save", "twentyfiveghost", global.twentyfiveghost);
        let value = rt.read_global("twentyfiveghost");
        rt.ini_write_real("Save", "twentyfiveghost", value);
        // GML 952: ini_write_real("Save", "onehundredghost", global.onehundredghost);
        let value = rt.read_global("onehundredghost");
        rt.ini_write_real("Save", "onehundredghost", value);
        // GML 953: ini_write_real("Save", "twentyfiveskeleton", global.twentyfiveskeleton);
        let value = rt.read_global("twentyfiveskeleton");
        rt.ini_write_real("Save", "twentyfiveskeleton", value);
        // GML 954: ini_write_real("Save", "onehundredskeleton", global.onehundredskeleton);
        let value = rt.read_global("onehundredskeleton");
        rt.ini_write_real("Save", "onehundredskeleton", value);
        // GML 955: ini_write_real("Save", "twentyfivezombie", global.twentyfivezombie);
        let value = rt.read_global("twentyfivezombie");
        rt.ini_write_real("Save", "twentyfivezombie", value);
        // GML 956: ini_write_real("Save", "onehundredzombie", global.onehundredzombie);
        let value = rt.read_global("onehundredzombie");
        rt.ini_write_real("Save", "onehundredzombie", value);
        // GML 957: ini_write_real("Save", "twentyfivebalrog", global.twentyfivebalrog);
        let value = rt.read_global("twentyfivebalrog");
        rt.ini_write_real("Save", "twentyfivebalrog", value);
        // GML 958: ini_write_real("Save", "onehundredbalrog", global.onehundredbalrog);
        let value = rt.read_global("onehundredbalrog");
        rt.ini_write_real("Save", "onehundredbalrog", value);
        // GML 959: ini_write_real("Save", "twentyfivebat", global.twentyfivebat);
        let value = rt.read_global("twentyfivebat");
        rt.ini_write_real("Save", "twentyfivebat", value);
        // GML 960: ini_write_real("Save", "onehundredbat", global.onehundredbat);
        let value = rt.read_global("onehundredbat");
        rt.ini_write_real("Save", "onehundredbat", value);
        // GML 961: ini_write_real("Save", "twentyfivetrap", global.twentyfivetrap);
        let value = rt.read_global("twentyfivetrap");
        rt.ini_write_real("Save", "twentyfivetrap", value);
        // GML 962: ini_write_real("Save", "onehundredtrap", global.onehundredtrap);
        let value = rt.read_global("onehundredtrap");
        rt.ini_write_real("Save", "onehundredtrap", value);
        // GML 963: ini_write_real("Save", "twentyfiveenemies", global.twentyfiveenemies);
        let value = rt.read_global("twentyfiveenemies");
        rt.ini_write_real("Save", "twentyfiveenemies", value);
        // GML 964: ini_write_real("Save", "onehundredenemies", global.onehundredenemies);
        let value = rt.read_global("onehundredenemies");
        rt.ini_write_real("Save", "onehundredenemies", value);
        // GML 965: ini_write_real("Save", "fivehundredenemies", global.fivehundredenemies);
        let value = rt.read_global("fivehundredenemies");
        rt.ini_write_real("Save", "fivehundredenemies", value);
        // GML 966: ini_write_real("Save", "onethousandenemies", global.onethousandenemies);
        let value = rt.read_global("onethousandenemies");
        rt.ini_write_real("Save", "onethousandenemies", value);
        // GML 967: ini_write_real("Save", "achievementboughtjump", global.achievementboughtjump);
        let value = rt.read_global("achievementboughtjump");
        rt.ini_write_real("Save", "achievementboughtjump", value);
        // GML 968: ini_write_real("Save", "achievmentboughtupgrades", global.achievmentboughtupgrades);
        let value = rt.read_global("achievmentboughtupgrades");
        rt.ini_write_real("Save", "achievmentboughtupgrades", value);
        // GML 969: ini_write_real("Save", "hitmaxcallylevel", global.hitmaxcallylevel);
        let value = rt.read_global("hitmaxcallylevel");
        rt.ini_write_real("Save", "hitmaxcallylevel", value);
        // GML 970: ini_write_real("Save", "hitmoney", global.hitmoney);
        let value = rt.read_global("hitmoney");
        rt.ini_write_real("Save", "hitmoney", value);
        // GML 971: ini_close();
        rt.ini_close();
        // GML 972: }
    }
    // GML 973: else if (!file_exists("savefile3.ini"))
    else if !rt.file_exists("savefile3.ini") {
        // GML 974: {
        // GML 975: global.twentyfivebears = 0;
        rt.write_global("twentyfivebears", 0.0);
        // GML 976: global.onehundredbears = 0;
        rt.write_global("onehundredbears", 0.0);
        // GML 977: global.twentyfivewolf = 0;
        rt.write_global("twentyfivewolf", 0.0);
        // GML 978: global.onehundredwolf = 0;
        rt.write_global("onehundredwolf", 0.0);
        // GML 979: global.twentyfiveknifebandit = 0;
        rt.write_global("twentyfiveknifebandit", 0.0);
        // GML 980: global.onehundredknifebandit = 0;
        rt.write_global("onehundredknifebandit", 0.0);
        // GML 981: global.twentyfivepistolthug = 0;
        rt.write_global("twentyfivepistolthug", 0.0);
        // GML 982: global.onehundredpistolthug = 0;
        rt.write_global("onehundredpistolthug", 0.0);
        // GML 983: global.twentyfivespiders = 0;
        rt.write_global("twentyfivespiders", 0.0);
        // GML 984: global.onehundredspiders = 0;
        rt.write_global("onehundredspiders", 0.0);
        // GML 985: global.twentyfiveslimes = 0;
        rt.write_global("twentyfiveslimes", 0.0);
        // GML 986: global.onehundredslimes = 0;
        rt.write_global("onehundredslimes", 0.0);
        // GML 987: global.twentyfivefireslimes = 0;
        rt.write_global("twentyfivefireslimes", 0.0);
        // GML 988: global.onehundredfireslimes = 0;
        rt.write_global("onehundredfireslimes", 0.0);
        // GML 989: global.twentyfivehulking = 0;
        rt.write_global("twentyfivehulking", 0.0);
        // GML 990: global.onehundredhulking = 0;
        rt.write_global("onehundredhulking", 0.0);
        // GML 991: global.twentyfiveghost = 0;
        rt.write_global("twentyfiveghost", 0.0);
        // GML 992: global.onehundredghost = 0;
        rt.write_global("onehundredghost", 0.0);
        // GML 993: global.twentyfiveskeleton = 0;
        rt.write_global("twentyfiveskeleton", 0.0);
        // GML 994: global.onehundredskeleton = 0;
        rt.write_global("onehundredskeleton", 0.0);
        // GML 995: global.twentyfivezombie = 0;
        rt.write_global("twentyfivezombie", 0.0);
        // GML 996: global.onehundredzombie = 0;
        rt.write_global("onehundredzombie", 0.0);
        // GML 997: global.twentyfivebalrog = 0;
        rt.write_global("twentyfivebalrog", 0.0);
        // GML 998: global.onehundredbalrog = 0;
        rt.write_global("onehundredbalrog", 0.0);
        // GML 999: global.twentyfivebat = 0;
        rt.write_global("twentyfivebat", 0.0);
        // GML 1000: global.onehundredbat = 0;
        rt.write_global("onehundredbat", 0.0);
        // GML 1001: global.twentyfivetrap = 0;
        rt.write_global("twentyfivetrap", 0.0);
        // GML 1002: global.onehundredtrap = 0;
        rt.write_global("onehundredtrap", 0.0);
        // GML 1003: global.twentyfiveenemies = 0;
        rt.write_global("twentyfiveenemies", 0.0);
        // GML 1004: global.onehundredenemies = 0;
        rt.write_global("onehundredenemies", 0.0);
        // GML 1005: global.fivehundredenemies = 0;
        rt.write_global("fivehundredenemies", 0.0);
        // GML 1006: global.onethousandenemies = 0;
        rt.write_global("onethousandenemies", 0.0);
        // GML 1007: global.achievementboughtjump = 0;
        rt.write_global("achievementboughtjump", 0.0);
        // GML 1008: global.achievmentboughtupgrades = 0;
        rt.write_global("achievmentboughtupgrades", 0.0);
        // GML 1009: global.hitmaxcallylevel = 0;
        rt.write_global("hitmaxcallylevel", 0.0);
        // GML 1010: global.hitmoney = 0;
        rt.write_global("hitmoney", 0.0);
        // GML 1011: }
    }
    // GML 1012: if (global.pistollevel == 1)
    if rt.read_global("pistollevel") == 1.0 {
        // GML 1013: {
        // GML 1014: global.pistoldamage = 1;
        rt.write_global("pistoldamage", 1.0);
        // GML 1015: }
    }
    // GML 1016: if (global.pistollevel == 2)
    if rt.read_global("pistollevel") == 2.0 {
        // GML 1017: {
        // GML 1018: global.pistoldamage = 1.3;
        rt.write_global("pistoldamage", 1.3);
        // GML 1019: }
    }
    // GML 1020: if (global.pistollevel == 3)
    if rt.read_global("pistollevel") == 3.0 {
        // GML 1021: {
        // GML 1022: global.pistoldamage = 1.6;
        rt.write_global("pistoldamage", 1.6);
        // GML 1023: }
    }
    // GML 1024: if (global.pistollevel == 4)
    if rt.read_global("pistollevel") == 4.0 {
        // GML 1025: {
        // GML 1026: global.pistoldamage = 2;
        rt.write_global("pistoldamage", 2.0);
        // GML 1027: }
    }
    // GML 1028: if (global.pistollevel == 5)
    if rt.read_global("pistollevel") == 5.0 {
        // GML 1029: {
        // GML 1030: global.pistoldamage = 2.4;
        rt.write_global("pistoldamage", 2.4);
        // GML 1031: }
    }
    // GML 1032: if (global.pistollevel == 6)
    if rt.read_global("pistollevel") == 6.0 {
        // GML 1033: {
        // GML 1034: global.pistoldamage = 2.8;
        rt.write_global("pistoldamage", 2.8);
        // GML 1035: }
    }
    // GML 1036: if (global.pistollevel == 7)
    if rt.read_global("pistollevel") == 7.0 {
        // GML 1037: {
        // GML 1038: global.pistoldamage = 3.2;
        rt.write_global("pistoldamage", 3.2);
        // GML 1039: }
    }
    // GML 1040: if (global.pistollevel == 8)
    if rt.read_global("pistollevel") == 8.0 {
        // GML 1041: {
        // GML 1042: global.pistoldamage = 3.6;
        rt.write_global("pistoldamage", 3.6);
        // GML 1043: }
    }
    // GML 1044: if (global.pistollevel == 9)
    if rt.read_global("pistollevel") == 9.0 {
        // GML 1045: {
        // GML 1046: global.pistoldamage = 4;
        rt.write_global("pistoldamage", 4.0);
        // GML 1047: }
    }
    // GML 1048: if (global.pistollevel == 10)
    if rt.read_global("pistollevel") == 10.0 {
        // GML 1049: {
        // GML 1050: global.pistoldamage = 5;
        rt.write_global("pistoldamage", 5.0);
        // GML 1051: }
    }
    // GML 1052: if (global.pistollevel > 10)
    if rt.read_global("pistollevel") > 10.0 {
        // GML 1053: {
        // GML 1054: global.pistollevel = 10;
        rt.write_global("pistollevel", 10.0);
        // GML 1055: }
    }
    // GML 1056: if (global.shotgunlevel == 1)
    if rt.read_global("shotgunlevel") == 1.0 {
        // GML 1057: {
        // GML 1058: global.shotgundamage = 0.5;
        rt.write_global("shotgundamage", 0.5);
        // GML 1059: }
    }
    // GML 1060: if (global.shotgunlevel == 2)
    if rt.read_global("shotgunlevel") == 2.0 {
        // GML 1061: {
        // GML 1062: global.shotgundamage = 0.6;
        rt.write_global("shotgundamage", 0.6);
        // GML 1063: }
    }
    // GML 1064: if (global.shotgunlevel == 3)
    if rt.read_global("shotgunlevel") == 3.0 {
        // GML 1065: {
        // GML 1066: global.shotgundamage = 0.7;
        rt.write_global("shotgundamage", 0.7);
        // GML 1067: }
    }
    // GML 1068: if (global.shotgunlevel == 4)
    if rt.read_global("shotgunlevel") == 4.0 {
        // GML 1069: {
        // GML 1070: global.shotgundamage = 0.8;
        rt.write_global("shotgundamage", 0.8);
        // GML 1071: }
    }
    // GML 1072: if (global.shotgunlevel == 5)
    if rt.read_global("shotgunlevel") == 5.0 {
        // GML 1073: {
        // GML 1074: global.shotgundamage = 0.9;
        rt.write_global("shotgundamage", 0.9);
        // GML 1075: }
    }
    // GML 1076: if (global.shotgunlevel == 6)
    if rt.read_global("shotgunlevel") == 6.0 {
        // GML 1077: {
        // GML 1078: global.shotgundamage = 1;
        rt.write_global("shotgundamage", 1.0);
        // GML 1079: }
    }
    // GML 1080: if (global.shotgunlevel == 7)
    if rt.read_global("shotgunlevel") == 7.0 {
        // GML 1081: {
        // GML 1082: global.shotgundamage = 1.1;
        rt.write_global("shotgundamage", 1.1);
        // GML 1083: }
    }
    // GML 1084: if (global.shotgunlevel == 8)
    if rt.read_global("shotgunlevel") == 8.0 {
        // GML 1085: {
        // GML 1086: global.shotgundamage = 1.2;
        rt.write_global("shotgundamage", 1.2);
        // GML 1087: }
    }
    // GML 1088: if (global.shotgunlevel == 9)
    if rt.read_global("shotgunlevel") == 9.0 {
        // GML 1089: {
        // GML 1090: global.shotgundamage = 1.3;
        rt.write_global("shotgundamage", 1.3);
        // GML 1091: }
    }
    // GML 1092: if (global.shotgunlevel == 10)
    if rt.read_global("shotgunlevel") == 10.0 {
        // GML 1093: {
        // GML 1094: global.shotgundamage = 1.5;
        rt.write_global("shotgundamage", 1.5);
        // GML 1095: }
    }
    // GML 1096: if (global.shotgunlevel > 10)
    if rt.read_global("shotgunlevel") > 10.0 {
        // GML 1097: {
        // GML 1098: global.shotgunlevel = 10;
        rt.write_global("shotgunlevel", 10.0);
        // GML 1099: }
    }
    // GML 1100: if (global.assaultriflelevel == 1)
    if rt.read_global("assaultriflelevel") == 1.0 {
        // GML 1101: {
        // GML 1102: global.assaultrifledamage = 0.6;
        rt.write_global("assaultrifledamage", 0.6);
        // GML 1103: }
    }
    // GML 1104: if (global.assaultriflelevel == 2)
    if rt.read_global("assaultriflelevel") == 2.0 {
        // GML 1105: {
        // GML 1106: global.assaultrifledamage = 0.7;
        rt.write_global("assaultrifledamage", 0.7);
        // GML 1107: }
    }
    // GML 1108: if (global.assaultriflelevel == 3)
    if rt.read_global("assaultriflelevel") == 3.0 {
        // GML 1109: {
        // GML 1110: global.assaultrifledamage = 0.8;
        rt.write_global("assaultrifledamage", 0.8);
        // GML 1111: }
    }
    // GML 1112: if (global.assaultriflelevel == 4)
    if rt.read_global("assaultriflelevel") == 4.0 {
        // GML 1113: {
        // GML 1114: global.assaultrifledamage = 1;
        rt.write_global("assaultrifledamage", 1.0);
        // GML 1115: }
    }
    // GML 1116: if (global.assaultriflelevel == 5)
    if rt.read_global("assaultriflelevel") == 5.0 {
        // GML 1117: {
        // GML 1118: global.assaultrifledamage = 1.1;
        rt.write_global("assaultrifledamage", 1.1);
        // GML 1119: }
    }
    // GML 1120: if (global.assaultriflelevel == 6)
    if rt.read_global("assaultriflelevel") == 6.0 {
        // GML 1121: {
        // GML 1122: global.assaultrifledamage = 1.2;
        rt.write_global("assaultrifledamage", 1.2);
        // GML 1123: }
    }
    // GML 1124: if (global.assaultriflelevel == 7)
    if rt.read_global("assaultriflelevel") == 7.0 {
        // GML 1125: {
        // GML 1126: global.assaultrifledamage = 1.4;
        rt.write_global("assaultrifledamage", 1.4);
        // GML 1127: }
    }
    // GML 1128: if (global.assaultriflelevel == 8)
    if rt.read_global("assaultriflelevel") == 8.0 {
        // GML 1129: {
        // GML 1130: global.assaultrifledamage = 1.5;
        rt.write_global("assaultrifledamage", 1.5);
        // GML 1131: }
    }
    // GML 1132: if (global.assaultriflelevel == 9)
    if rt.read_global("assaultriflelevel") == 9.0 {
        // GML 1133: {
        // GML 1134: global.assaultrifledamage = 1.7;
        rt.write_global("assaultrifledamage", 1.7);
        // GML 1135: }
    }
    // GML 1136: if (global.assaultriflelevel == 10)
    if rt.read_global("assaultriflelevel") == 10.0 {
        // GML 1137: {
        // GML 1138: global.assaultrifledamage = 2;
        rt.write_global("assaultrifledamage", 2.0);
        // GML 1139: }
    }
    // GML 1140: if (global.assaultriflelevel > 10)
    if rt.read_global("assaultriflelevel") > 10.0 {
        // GML 1141: {
        // GML 1142: global.assaultriflelevel = 10;
        rt.write_global("assaultriflelevel", 10.0);
        // GML 1143: }
    }
    // GML 1144: if (global.icegunlevel == 1)
    if rt.read_global("icegunlevel") == 1.0 {
        // GML 1145: {
        // GML 1146: global.icegundamage = 1;
        rt.write_global("icegundamage", 1.0);
        // GML 1147: }
    }
    // GML 1148: if (global.icegunlevel == 2)
    if rt.read_global("icegunlevel") == 2.0 {
        // GML 1149: {
        // GML 1150: global.icegundamage = 1.2;
        rt.write_global("icegundamage", 1.2);
        // GML 1151: }
    }
    // GML 1152: if (global.icegunlevel == 3)
    if rt.read_global("icegunlevel") == 3.0 {
        // GML 1153: {
        // GML 1154: global.icegundamage = 1.4;
        rt.write_global("icegundamage", 1.4);
        // GML 1155: }
    }
    // GML 1156: if (global.icegunlevel == 4)
    if rt.read_global("icegunlevel") == 4.0 {
        // GML 1157: {
        // GML 1158: global.icegundamage = 1.7;
        rt.write_global("icegundamage", 1.7);
        // GML 1159: }
    }
    // GML 1160: if (global.icegunlevel == 5)
    if rt.read_global("icegunlevel") == 5.0 {
        // GML 1161: {
        // GML 1162: global.icegundamage = 1.9;
        rt.write_global("icegundamage", 1.9);
        // GML 1163: }
    }
    // GML 1164: if (global.icegunlevel == 6)
    if rt.read_global("icegunlevel") == 6.0 {
        // GML 1165: {
        // GML 1166: global.icegundamage = 2.1;
        rt.write_global("icegundamage", 2.1);
        // GML 1167: }
    }
    // GML 1168: if (global.icegunlevel == 7)
    if rt.read_global("icegunlevel") == 7.0 {
        // GML 1169: {
        // GML 1170: global.icegundamage = 2.4;
        rt.write_global("icegundamage", 2.4);
        // GML 1171: }
    }
    // GML 1172: if (global.icegunlevel == 8)
    if rt.read_global("icegunlevel") == 8.0 {
        // GML 1173: {
        // GML 1174: global.icegundamage = 2.6;
        rt.write_global("icegundamage", 2.6);
        // GML 1175: }
    }
    // GML 1176: if (global.icegunlevel == 9)
    if rt.read_global("icegunlevel") == 9.0 {
        // GML 1177: {
        // GML 1178: global.icegundamage = 2.8;
        rt.write_global("icegundamage", 2.8);
        // GML 1179: }
    }
    // GML 1180: if (global.icegunlevel == 10)
    if rt.read_global("icegunlevel") == 10.0 {
        // GML 1181: {
        // GML 1182: global.icegundamage = 3;
        rt.write_global("icegundamage", 3.0);
        // GML 1183: }
    }
    // GML 1184: if (global.icegunlevel > 10)
    if rt.read_global("icegunlevel") > 10.0 {
        // GML 1185: {
        // GML 1186: global.icegunlevel = 10;
        rt.write_global("icegunlevel", 10.0);
        // GML 1187: }
    }
    // GML 1188: if (global.laserlevel == 1)
    if rt.read_global("laserlevel") == 1.0 {
        // GML 1189: {
        // GML 1190: global.laserdamage = 1.5;
        rt.write_global("laserdamage", 1.5);
        // GML 1191: }
    }
    // GML 1192: if (global.laserlevel == 2)
    if rt.read_global("laserlevel") == 2.0 {
        // GML 1193: {
        // GML 1194: global.laserdamage = 1.6;
        rt.write_global("laserdamage", 1.6);
        // GML 1195: }
    }
    // GML 1196: if (global.laserlevel == 3)
    if rt.read_global("laserlevel") == 3.0 {
        // GML 1197: {
        // GML 1198: global.laserdamage = 1.7;
        rt.write_global("laserdamage", 1.7);
        // GML 1199: }
    }
    // GML 1200: if (global.laserlevel == 4)
    if rt.read_global("laserlevel") == 4.0 {
        // GML 1201: {
        // GML 1202: global.laserdamage = 1.8;
        rt.write_global("laserdamage", 1.8);
        // GML 1203: }
    }
    // GML 1204: if (global.laserlevel == 5)
    if rt.read_global("laserlevel") == 5.0 {
        // GML 1205: {
        // GML 1206: global.laserdamage = 1.9;
        rt.write_global("laserdamage", 1.9);
        // GML 1207: }
    }
    // GML 1208: if (global.laserlevel == 6)
    if rt.read_global("laserlevel") == 6.0 {
        // GML 1209: {
        // GML 1210: global.laserdamage = 2;
        rt.write_global("laserdamage", 2.0);
        // GML 1211: }
    }
    // GML 1212: if (global.laserlevel == 7)
    if rt.read_global("laserlevel") == 7.0 {
        // GML 1213: {
        // GML 1214: global.laserdamage = 2.1;
        rt.write_global("laserdamage", 2.1);
        // GML 1215: }
    }
    // GML 1216: if (global.laserlevel == 8)
    if rt.read_global("laserlevel") == 8.0 {
        // GML 1217: {
        // GML 1218: global.laserdamage = 2.2;
        rt.write_global("laserdamage", 2.2);
        // GML 1219: }
    }
    // GML 1220: if (global.laserlevel == 9)
    if rt.read_global("laserlevel") == 9.0 {
        // GML 1221: {
        // GML 1222: global.laserdamage = 2.3;
        rt.write_global("laserdamage", 2.3);
        // GML 1223: }
    }
    // GML 1224: if (global.laserlevel == 10)
    if rt.read_global("laserlevel") == 10.0 {
        // GML 1225: {
        // GML 1226: global.laserdamage = 2.5;
        rt.write_global("laserdamage", 2.5);
        // GML 1227: }
    }
    // GML 1228: if (global.laserlevel > 10)
    if rt.read_global("laserlevel") > 10.0 {
        // GML 1229: {
        // GML 1230: global.laserlevel = 10;
        rt.write_global("laserlevel", 10.0);
        // GML 1231: }
    }
    // GML 1232: if (global.rocketlevel == 1)
    if rt.read_global("rocketlevel") == 1.0 {
        // GML 1233: {
        // GML 1234: global.rocketdamage = 2.5;
        rt.write_global("rocketdamage", 2.5);
        // GML 1235: }
    }
    // GML 1236: if (global.rocketlevel == 2)
    if rt.read_global("rocketlevel") == 2.0 {
        // GML 1237: {
        // GML 1238: global.rocketdamage = 2.6;
        rt.write_global("rocketdamage", 2.6);
        // GML 1239: }
    }
    // GML 1240: if (global.rocketlevel == 3)
    if rt.read_global("rocketlevel") == 3.0 {
        // GML 1241: {
        // GML 1242: global.rocketdamage = 2.7;
        rt.write_global("rocketdamage", 2.7);
        // GML 1243: }
    }
    // GML 1244: if (global.rocketlevel == 4)
    if rt.read_global("rocketlevel") == 4.0 {
        // GML 1245: {
        // GML 1246: global.rocketdamage = 2.8;
        rt.write_global("rocketdamage", 2.8);
        // GML 1247: }
    }
    // GML 1248: if (global.rocketlevel == 5)
    if rt.read_global("rocketlevel") == 5.0 {
        // GML 1249: {
        // GML 1250: global.rocketdamage = 2.9;
        rt.write_global("rocketdamage", 2.9);
        // GML 1251: }
    }
    // GML 1252: if (global.rocketlevel == 6)
    if rt.read_global("rocketlevel") == 6.0 {
        // GML 1253: {
        // GML 1254: global.rocketdamage = 3;
        rt.write_global("rocketdamage", 3.0);
        // GML 1255: }
    }
    // GML 1256: if (global.rocketlevel == 7)
    if rt.read_global("rocketlevel") == 7.0 {
        // GML 1257: {
        // GML 1258: global.rocketdamage = 3.2;
        rt.write_global("rocketdamage", 3.2);
        // GML 1259: }
    }
    // GML 1260: if (global.rocketlevel == 8)
    if rt.read_global("rocketlevel") == 8.0 {
        // GML 1261: {
        // GML 1262: global.rocketdamage = 3.4;
        rt.write_global("rocketdamage", 3.4);
        // GML 1263: }
    }
    // GML 1264: if (global.rocketlevel == 9)
    if rt.read_global("rocketlevel") == 9.0 {
        // GML 1265: {
        // GML 1266: global.rocketdamage = 3.6;
        rt.write_global("rocketdamage", 3.6);
        // GML 1267: }
    }
    // GML 1268: if (global.rocketlevel == 10)
    if rt.read_global("rocketlevel") == 10.0 {
        // GML 1269: {
        // GML 1270: global.rocketdamage = 4;
        rt.write_global("rocketdamage", 4.0);
        // GML 1271: }
    }
    // GML 1272: if (global.rocketlevel > 10)
    if rt.read_global("rocketlevel") > 10.0 {
        // GML 1273: {
        // GML 1274: global.rocketlevel = 10;
        rt.write_global("rocketlevel", 10.0);
        // GML 1275: }
    }
    // GML 1276: if (global.bowlevel == 1)
    if rt.read_global("bowlevel") == 1.0 {
        // GML 1277: {
        // GML 1278: global.bowdamage = 2;
        rt.write_global("bowdamage", 2.0);
        // GML 1279: }
    }
    // GML 1280: if (global.bowlevel == 2)
    if rt.read_global("bowlevel") == 2.0 {
        // GML 1281: {
        // GML 1282: global.bowdamage = 2.2;
        rt.write_global("bowdamage", 2.2);
        // GML 1283: }
    }
    // GML 1284: if (global.bowlevel == 3)
    if rt.read_global("bowlevel") == 3.0 {
        // GML 1285: {
        // GML 1286: global.bowdamage = 2.4;
        rt.write_global("bowdamage", 2.4);
        // GML 1287: }
    }
    // GML 1288: if (global.bowlevel == 4)
    if rt.read_global("bowlevel") == 4.0 {
        // GML 1289: {
        // GML 1290: global.bowdamage = 2.6;
        rt.write_global("bowdamage", 2.6);
        // GML 1291: }
    }
    // GML 1292: if (global.bowlevel == 5)
    if rt.read_global("bowlevel") == 5.0 {
        // GML 1293: {
        // GML 1294: global.bowdamage = 2.8;
        rt.write_global("bowdamage", 2.8);
        // GML 1295: }
    }
    // GML 1296: if (global.bowlevel == 6)
    if rt.read_global("bowlevel") == 6.0 {
        // GML 1297: {
        // GML 1298: global.bowdamage = 3;
        rt.write_global("bowdamage", 3.0);
        // GML 1299: }
    }
    // GML 1300: if (global.bowlevel == 7)
    if rt.read_global("bowlevel") == 7.0 {
        // GML 1301: {
        // GML 1302: global.bowdamage = 3.2;
        rt.write_global("bowdamage", 3.2);
        // GML 1303: }
    }
    // GML 1304: if (global.bowlevel == 8)
    if rt.read_global("bowlevel") == 8.0 {
        // GML 1305: {
        // GML 1306: global.bowdamage = 3.4;
        rt.write_global("bowdamage", 3.4);
        // GML 1307: }
    }
    // GML 1308: if (global.bowlevel == 9)
    if rt.read_global("bowlevel") == 9.0 {
        // GML 1309: {
        // GML 1310: global.bowdamage = 3.6;
        rt.write_global("bowdamage", 3.6);
        // GML 1311: }
    }
    // GML 1312: if (global.bowlevel == 10)
    if rt.read_global("bowlevel") == 10.0 {
        // GML 1313: {
        // GML 1314: global.bowdamage = 4;
        rt.write_global("bowdamage", 4.0);
        // GML 1315: }
    }
    // GML 1316: if (global.bowlevel > 10)
    if rt.read_global("bowlevel") > 10.0 {
        // GML 1317: {
        // GML 1318: global.bowlevel = 10;
        rt.write_global("bowlevel", 10.0);
        // GML 1319: }
    }
    // GML 1320: if (global.flamethrowerlevel == 1)
    if rt.read_global("flamethrowerlevel") == 1.0 {
        // GML 1321: {
        // GML 1322: global.flamethrowerdamage = 0.3;
        rt.write_global("flamethrowerdamage", 0.3);
        // GML 1323: }
    }
    // GML 1324: if (global.flamethrowerlevel == 2)
    if rt.read_global("flamethrowerlevel") == 2.0 {
        // GML 1325: {
        // GML 1326: global.flamethrowerdamage = 0.5;
        rt.write_global("flamethrowerdamage", 0.5);
        // GML 1327: }
    }
    // GML 1328: if (global.flamethrowerlevel == 3)
    if rt.read_global("flamethrowerlevel") == 3.0 {
        // GML 1329: {
        // GML 1330: global.flamethrowerdamage = 0.7;
        rt.write_global("flamethrowerdamage", 0.7);
        // GML 1331: }
    }
    // GML 1332: if (global.flamethrowerlevel == 4)
    if rt.read_global("flamethrowerlevel") == 4.0 {
        // GML 1333: {
        // GML 1334: global.flamethrowerdamage = 0.9;
        rt.write_global("flamethrowerdamage", 0.9);
        // GML 1335: }
    }
    // GML 1336: if (global.flamethrowerlevel == 5)
    if rt.read_global("flamethrowerlevel") == 5.0 {
        // GML 1337: {
        // GML 1338: global.flamethrowerdamage = 1;
        rt.write_global("flamethrowerdamage", 1.0);
        // GML 1339: }
    }
    // GML 1340: if (global.flamethrowerlevel == 6)
    if rt.read_global("flamethrowerlevel") == 6.0 {
        // GML 1341: {
        // GML 1342: global.flamethrowerdamage = 1.1;
        rt.write_global("flamethrowerdamage", 1.1);
        // GML 1343: }
    }
    // GML 1344: if (global.flamethrowerlevel == 7)
    if rt.read_global("flamethrowerlevel") == 7.0 {
        // GML 1345: {
        // GML 1346: global.flamethrowerdamage = 1.2;
        rt.write_global("flamethrowerdamage", 1.2);
        // GML 1347: }
    }
    // GML 1348: if (global.flamethrowerlevel == 8)
    if rt.read_global("flamethrowerlevel") == 8.0 {
        // GML 1349: {
        // GML 1350: global.flamethrowerdamage = 1.4;
        rt.write_global("flamethrowerdamage", 1.4);
        // GML 1351: }
    }
    // GML 1352: if (global.flamethrowerlevel == 9)
    if rt.read_global("flamethrowerlevel") == 9.0 {
        // GML 1353: {
        // GML 1354: global.flamethrowerdamage = 1.5;
        rt.write_global("flamethrowerdamage", 1.5);
        // GML 1355: }
    }
    // GML 1356: if (global.flamethrowerlevel == 10)
    if rt.read_global("flamethrowerlevel") == 10.0 {
        // GML 1357: {
        // GML 1358: global.flamethrowerdamage = 2;
        rt.write_global("flamethrowerdamage", 2.0);
        // GML 1359: }
    }
    // GML 1360: if (global.flamethrowerlevel > 10)
    if rt.read_global("flamethrowerlevel") > 10.0 {
        // GML 1361: {
        // GML 1362: global.flamethrowerlevel = 10;
        rt.write_global("flamethrowerlevel", 10.0);
        // GML 1363: }
    }
    // GML 1364: if (global.bladegunlevel == 1)
    if rt.read_global("bladegunlevel") == 1.0 {
        // GML 1365: {
        // GML 1366: global.bladegundamage = 1;
        rt.write_global("bladegundamage", 1.0);
        // GML 1367: }
    }
    // GML 1368: if (global.bladegunlevel == 2)
    if rt.read_global("bladegunlevel") == 2.0 {
        // GML 1369: {
        // GML 1370: global.bladegundamage = 1.2;
        rt.write_global("bladegundamage", 1.2);
        // GML 1371: }
    }
    // GML 1372: if (global.bladegunlevel == 3)
    if rt.read_global("bladegunlevel") == 3.0 {
        // GML 1373: {
        // GML 1374: global.bladegundamage = 1.3;
        rt.write_global("bladegundamage", 1.3);
        // GML 1375: }
    }
    // GML 1376: if (global.bladegunlevel == 4)
    if rt.read_global("bladegunlevel") == 4.0 {
        // GML 1377: {
        // GML 1378: global.bladegundamage = 1.5;
        rt.write_global("bladegundamage", 1.5);
        // GML 1379: }
    }
    // GML 1380: if (global.bladegunlevel == 5)
    if rt.read_global("bladegunlevel") == 5.0 {
        // GML 1381: {
        // GML 1382: global.bladegundamage = 1.6;
        rt.write_global("bladegundamage", 1.6);
        // GML 1383: }
    }
    // GML 1384: if (global.bladegunlevel == 6)
    if rt.read_global("bladegunlevel") == 6.0 {
        // GML 1385: {
        // GML 1386: global.bladegundamage = 1.7;
        rt.write_global("bladegundamage", 1.7);
        // GML 1387: }
    }
    // GML 1388: if (global.bladegunlevel == 7)
    if rt.read_global("bladegunlevel") == 7.0 {
        // GML 1389: {
        // GML 1390: global.bladegundamage = 2;
        rt.write_global("bladegundamage", 2.0);
        // GML 1391: }
    }
    // GML 1392: if (global.bladegunlevel == 8)
    if rt.read_global("bladegunlevel") == 8.0 {
        // GML 1393: {
        // GML 1394: global.bladegundamage = 2.1;
        rt.write_global("bladegundamage", 2.1);
        // GML 1395: }
    }
    // GML 1396: if (global.bladegunlevel == 9)
    if rt.read_global("bladegunlevel") == 9.0 {
        // GML 1397: {
        // GML 1398: global.bladegundamage = 2.2;
        rt.write_global("bladegundamage", 2.2);
        // GML 1399: }
    }
    // GML 1400: if (global.bladegunlevel == 10)
    if rt.read_global("bladegunlevel") == 10.0 {
        // GML 1401: {
        // GML 1402: global.bladegundamage = 2.5;
        rt.write_global("bladegundamage", 2.5);
        // GML 1403: }
    }
    // GML 1404: if (global.bladegunlevel > 10)
    if rt.read_global("bladegunlevel") > 10.0 {
        // GML 1405: {
        // GML 1406: global.bladegunlevel = 10;
        rt.write_global("bladegunlevel", 10.0);
        // GML 1407: }
    }
    // GML 1408: if (global.spikegunlevel == 1)
    if rt.read_global("spikegunlevel") == 1.0 {
        // GML 1409: {
        // GML 1410: global.spikegundamage = 1.5;
        rt.write_global("spikegundamage", 1.5);
        // GML 1411: }
    }
    // GML 1412: if (global.spikegunlevel == 2)
    if rt.read_global("spikegunlevel") == 2.0 {
        // GML 1413: {
        // GML 1414: global.spikegundamage = 1.6;
        rt.write_global("spikegundamage", 1.6);
        // GML 1415: }
    }
    // GML 1416: if (global.spikegunlevel == 3)
    if rt.read_global("spikegunlevel") == 3.0 {
        // GML 1417: {
        // GML 1418: global.spikegundamage = 1.7;
        rt.write_global("spikegundamage", 1.7);
        // GML 1419: }
    }
    // GML 1420: if (global.spikegunlevel == 4)
    if rt.read_global("spikegunlevel") == 4.0 {
        // GML 1421: {
        // GML 1422: global.spikegundamage = 1.8;
        rt.write_global("spikegundamage", 1.8);
        // GML 1423: }
    }
    // GML 1424: if (global.spikegunlevel == 5)
    if rt.read_global("spikegunlevel") == 5.0 {
        // GML 1425: {
        // GML 1426: global.spikegundamage = 1.9;
        rt.write_global("spikegundamage", 1.9);
        // GML 1427: }
    }
    // GML 1428: if (global.spikegunlevel == 6)
    if rt.read_global("spikegunlevel") == 6.0 {
        // GML 1429: {
        // GML 1430: global.spikegundamage = 2;
        rt.write_global("spikegundamage", 2.0);
        // GML 1431: }
    }
    // GML 1432: if (global.spikegunlevel == 7)
    if rt.read_global("spikegunlevel") == 7.0 {
        // GML 1433: {
        // GML 1434: global.spikegundamage = 2.2;
        rt.write_global("spikegundamage", 2.2);
        // GML 1435: }
    }
    // GML 1436: if (global.spikegunlevel == 8)
    if rt.read_global("spikegunlevel") == 8.0 {
        // GML 1437: {
        // GML 1438: global.spikegundamage = 2.4;
        rt.write_global("spikegundamage", 2.4);
        // GML 1439: }
    }
    // GML 1440: if (global.spikegunlevel == 9)
    if rt.read_global("spikegunlevel") == 9.0 {
        // GML 1441: {
        // GML 1442: global.spikegundamage = 2.6;
        rt.write_global("spikegundamage", 2.6);
        // GML 1443: }
    }
    // GML 1444: if (global.spikegunlevel == 10)
    if rt.read_global("spikegunlevel") == 10.0 {
        // GML 1445: {
        // GML 1446: global.spikegundamage = 3;
        rt.write_global("spikegundamage", 3.0);
        // GML 1447: }
    }
    // GML 1448: if (global.spikegunlevel > 10)
    if rt.read_global("spikegunlevel") > 10.0 {
        // GML 1449: {
        // GML 1450: global.spikegunlevel = 10;
        rt.write_global("spikegunlevel", 10.0);
        // GML 1451: }
    }
    // GML 1452: if (global.boomeranglevel == 1)
    if rt.read_global("boomeranglevel") == 1.0 {
        // GML 1453: {
        // GML 1454: global.boomerangdamage = 0.1;
        rt.write_global("boomerangdamage", 0.1);
        // GML 1455: }
    }
    // GML 1456: if (global.boomeranglevel == 2)
    if rt.read_global("boomeranglevel") == 2.0 {
        // GML 1457: {
        // GML 1458: global.boomerangdamage = 0.15;
        rt.write_global("boomerangdamage", 0.15);
        // GML 1459: }
    }
    // GML 1460: if (global.boomeranglevel == 3)
    if rt.read_global("boomeranglevel") == 3.0 {
        // GML 1461: {
        // GML 1462: global.boomerangdamage = 0.2;
        rt.write_global("boomerangdamage", 0.2);
        // GML 1463: }
    }
    // GML 1464: if (global.boomeranglevel == 4)
    if rt.read_global("boomeranglevel") == 4.0 {
        // GML 1465: {
        // GML 1466: global.boomerangdamage = 0.3;
        rt.write_global("boomerangdamage", 0.3);
        // GML 1467: }
    }
    // GML 1468: if (global.boomeranglevel == 5)
    if rt.read_global("boomeranglevel") == 5.0 {
        // GML 1469: {
        // GML 1470: global.boomerangdamage = 0.35;
        rt.write_global("boomerangdamage", 0.35);
        // GML 1471: }
    }
    // GML 1472: if (global.boomeranglevel == 6)
    if rt.read_global("boomeranglevel") == 6.0 {
        // GML 1473: {
        // GML 1474: global.boomerangdamage = 0.4;
        rt.write_global("boomerangdamage", 0.4);
        // GML 1475: }
    }
    // GML 1476: if (global.boomeranglevel == 7)
    if rt.read_global("boomeranglevel") == 7.0 {
        // GML 1477: {
        // GML 1478: global.boomerangdamage = 0.5;
        rt.write_global("boomerangdamage", 0.5);
        // GML 1479: }
    }
    // GML 1480: if (global.boomeranglevel == 8)
    if rt.read_global("boomeranglevel") == 8.0 {
        // GML 1481: {
        // GML 1482: global.boomerangdamage = 0.6;
        rt.write_global("boomerangdamage", 0.6);
        // GML 1483: }
    }
    // GML 1484: if (global.boomeranglevel == 9)
    if rt.read_global("boomeranglevel") == 9.0 {
        // GML 1485: {
        // GML 1486: global.boomerangdamage = 0.7;
        rt.write_global("boomerangdamage", 0.7);
        // GML 1487: }
    }
    // GML 1488: if (global.boomeranglevel == 10)
    if rt.read_global("boomeranglevel") == 10.0 {
        // GML 1489: {
        // GML 1490: global.boomerangdamage = 1;
        rt.write_global("boomerangdamage", 1.0);
        // GML 1491: }
    }
    // GML 1492: if (global.boomeranglevel > 10)
    if rt.read_global("boomeranglevel") > 10.0 {
        // GML 1493: {
        // GML 1494: global.boomeranglevel = 10;
        rt.write_global("boomeranglevel", 10.0);
        // GML 1495: }
    }
    // GML 1496: if (global.bombgunlevel == 1)
    if rt.read_global("bombgunlevel") == 1.0 {
        // GML 1497: {
        // GML 1498: global.bombgundamage = 3.5;
        rt.write_global("bombgundamage", 3.5);
        // GML 1499: }
    }
    // GML 1500: if (global.bombgunlevel == 2)
    if rt.read_global("bombgunlevel") == 2.0 {
        // GML 1501: {
        // GML 1502: global.bombgundamage = 3.7;
        rt.write_global("bombgundamage", 3.7);
        // GML 1503: }
    }
    // GML 1504: if (global.bombgunlevel == 3)
    if rt.read_global("bombgunlevel") == 3.0 {
        // GML 1505: {
        // GML 1506: global.bombgundamage = 3.9;
        rt.write_global("bombgundamage", 3.9);
        // GML 1507: }
    }
    // GML 1508: if (global.bombgunlevel == 4)
    if rt.read_global("bombgunlevel") == 4.0 {
        // GML 1509: {
        // GML 1510: global.bombgundamage = 4;
        rt.write_global("bombgundamage", 4.0);
        // GML 1511: }
    }
    // GML 1512: if (global.bombgunlevel == 5)
    if rt.read_global("bombgunlevel") == 5.0 {
        // GML 1513: {
        // GML 1514: global.bombgundamage = 4.1;
        rt.write_global("bombgundamage", 4.1);
        // GML 1515: }
    }
    // GML 1516: if (global.bombgunlevel == 6)
    if rt.read_global("bombgunlevel") == 6.0 {
        // GML 1517: {
        // GML 1518: global.bombgundamage = 4.2;
        rt.write_global("bombgundamage", 4.2);
        // GML 1519: }
    }
    // GML 1520: if (global.bombgunlevel == 7)
    if rt.read_global("bombgunlevel") == 7.0 {
        // GML 1521: {
        // GML 1522: global.bombgundamage = 4.4;
        rt.write_global("bombgundamage", 4.4);
        // GML 1523: }
    }
    // GML 1524: if (global.bombgunlevel == 8)
    if rt.read_global("bombgunlevel") == 8.0 {
        // GML 1525: {
        // GML 1526: global.bombgundamage = 4.5;
        rt.write_global("bombgundamage", 4.5);
        // GML 1527: }
    }
    // GML 1528: if (global.bombgunlevel == 9)
    if rt.read_global("bombgunlevel") == 9.0 {
        // GML 1529: {
        // GML 1530: global.bombgundamage = 4.6;
        rt.write_global("bombgundamage", 4.6);
        // GML 1531: }
    }
    // GML 1532: if (global.bombgunlevel == 10)
    if rt.read_global("bombgunlevel") == 10.0 {
        // GML 1533: {
        // GML 1534: global.bombgundamage = 5;
        rt.write_global("bombgundamage", 5.0);
        // GML 1535: }
    }
    // GML 1536: if (global.bombgunlevel > 10)
    if rt.read_global("bombgunlevel") > 10.0 {
        // GML 1537: {
        // GML 1538: global.bombgunlevel = 10;
        rt.write_global("bombgunlevel", 10.0);
        // GML 1539: }
    }
    // GML 1540: instance_create(x, y, obj_introduction);
    // Original CODE17 offsets 39224/39232: push self.y, then self.x.
    let y = rt.read_self("y");
    let x = rt.read_self("x");
    rt.spawn_named(x, y, "obj_introduction");
}
