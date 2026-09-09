//! Headless event host for a bounded IR scene, NOT GameWorld or a full GM runner.
//! Event bodies come exclusively from CODE IR/OBJT bindings. No intro timers or
//! coordinates are hand-translated here. External instances are explicitly inert.
use crate::code_vm::{self, Bundle, Host};
use serde::Serialize;
use std::collections::{BTreeMap, BTreeSet};

#[derive(Debug, Clone)]
pub struct Instance {
    pub object: i32, pub alive: bool, pub active: bool, pub external: bool,
    pub fields: BTreeMap<String, f64>, pub arrays: BTreeMap<(String, i32), f64>, pub alarms: [i32; 12],
}
#[derive(Debug, Clone, Default)]
pub struct TouchDevice {
    pub x: f64, pub y: f64, pub down: bool, pub pressed: bool, pub released: bool,
}
#[derive(Debug, Clone, Default)]
pub struct SpriteBounds {
    pub width: f64, pub height: f64, pub origin_x: f64, pub origin_y: f64,
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct DrawCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub sprite: i32, pub frame: f64, pub x: f64, pub y: f64,
    pub scale_x: f64, pub scale_y: f64, pub rotation: f64, pub color: i32, pub alpha: f64,
}
#[derive(Debug, Clone, Serialize)]
pub struct AudioCommand { pub code: usize, pub offset: usize, pub sound: i32, pub priority: f64, pub looping: bool, pub voice: i32 }
#[derive(Debug)]
pub struct Scene {
    pub instances: BTreeMap<i32, Instance>, pub globals: BTreeMap<String, f64>,
    pub draws: Vec<DrawCommand>, pub audio: Vec<AudioCommand>,
    pub executed: Vec<(usize,usize)>,
    pub view: i32, pub view_positions: BTreeMap<i32,(f64,f64)>, pub mouse_pressed: bool,
    pub view_ports: BTreeMap<i32,(f64,f64)>,
    pub touch_devices: [TouchDevice; 5],
    pub sprite_bounds: BTreeMap<i32, SpriteBounds>,
    pub object_parents: BTreeMap<i32, Vec<i32>>,
    pub display_width: f64, pub display_height: f64, pub current_room: f64,
    pub room_width: f64, pub room_height: f64,
    pub current_font: f64, pub draw_color: i32, pub draw_alpha: f64,
    pub rng_seed: u64,
    pub view_visible: [bool; 8],
    pub ini_open_file: Option<String>,
    pub ini_data: BTreeMap<(String, String, String), f64>,
    pub other_instance: Option<i32>,
    pub room_tiles: Vec<callys_asset::RoomTileInstance>,
    pub target_room_warp: Option<usize>,
    pub persistent_objects: BTreeSet<i32>,
    next_id: i32, site: (usize,usize), depth: usize,
}
impl Default for Scene {
    fn default() -> Self {
        Self {
            instances: BTreeMap::new(), globals: BTreeMap::new(),
            draws: Vec::new(), audio: Vec::new(), executed: Vec::new(),
            view: 0, view_positions: BTreeMap::new(), mouse_pressed: false,
            view_ports: BTreeMap::new(),
            touch_devices: Default::default(),
            sprite_bounds: BTreeMap::new(),
            object_parents: BTreeMap::new(),
            display_width: 960.0, display_height: 540.0, current_room: 0.0,
            room_width: 1024.0, room_height: 768.0,
            current_font: 0.0, draw_color: -1, draw_alpha: 1.0,
            rng_seed: 0x12345678,
            view_visible: [true, false, false, false, false, false, false, false],
            ini_open_file: None,
            ini_data: BTreeMap::new(),
            other_instance: None,
            room_tiles: Vec::new(),
            target_room_warp: None,
            persistent_objects: BTreeSet::new(),
            next_id: 0, site: (0, 0), depth: 0,
        }
    }
}
fn next_rand(seed: &mut u64) -> f64 {
    *seed = seed.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
    ((*seed >> 11) as f64) / ((1u64 << 53) as f64)
}

fn line_intersects_box(x1: f64, y1: f64, x2: f64, y2: f64, min_x: f64, max_x: f64, min_y: f64, max_y: f64) -> bool {
    let dx = x2 - x1;
    let dy = y2 - y1;
    let mut t0 = 0.0f64;
    let mut t1 = 1.0f64;

    for (p, q) in [
        (-dx, x1 - min_x),
        (dx, max_x - x1),
        (-dy, y1 - min_y),
        (dy, max_y - y1),
    ] {
        if p == 0.0 {
            if q < 0.0 { return false; }
        } else {
            let r = q / p;
            if p < 0.0 {
                if r > t1 { return false; }
                if r > t0 { t0 = r; }
            } else {
                if r < t0 { return false; }
                if r < t1 { t1 = r; }
            }
        }
    }
    t0 <= t1
}

fn int(v:f64)->Result<i32,String> {
    if v.is_finite() && v.fract()==0.0 && v>=i32::MIN as f64 && v<=i32::MAX as f64 {Ok(v as i32)}
    else {Err(format!("expected i32, got {v}"))}
}
impl Scene {
    pub fn init_bundle(&mut self, b: &Bundle) {
        for obj in &b.objects {
            self.object_parents.insert(obj.id, obj.parent_chain.clone());
        }
    }

    /// Populates the full verified baseline of fresh-start globals defined by
    /// the original GameMaker Other_2 (Game Start) event (CODE 17).
    pub fn init_fresh_start_globals(&mut self) {
        for (k, v) in [
            ("level", 1.0), ("maxhp", 4.0), ("health1", 4.0), ("experience", 0.0),
            ("xptolevelup", 30.0), ("roomstart", 0.0), ("soundmute", 0.0), ("musicmute", 0.0),
            ("haskey", 0.0), ("warplock", 0.0), ("warpfrommap", 0.0), ("ending", 0.0),
            ("coinmultiply", 1.0), ("timeplayed", 0.0), ("gemdropenabled", 1.0),
            ("poisonenabled", 0.0), ("weaponswapped", 0.0), ("firing", 0.0), ("swing", 0.0),
            ("rebuff", 0.0), ("boss1touched", 0.0), ("sword", 0.0),
            ("tjumpactive", 0.0), ("triplejumpbought", 0.0),
            ("strengthupgradebought", 0.0), ("strengthupgrade2bought", 0.0),
            ("energywavebought", 0.0), ("healthregenbought", 0.0),
            ("swordupgradebought", 0.0), ("swordupgrade2bought", 0.0), ("swordupgrade3bought", 0.0),
            ("powerupgradebought", 0.0), ("powerupgrade2bought", 0.0), ("powerupgrade3bought", 0.0),
            ("coinmultiplier2bought", 0.0), ("coinmultiplier5bought", 0.0),
            ("maxhpupgradebought", 0.0), ("maxhpupgrade2bought", 0.0),
            ("drawchange", 0.0), ("drawlevelup", 0.0), ("drawweaponlevelup", 0.0), ("drawweaponchange", 0.0),
            ("drawchangepistol4", 1.0), ("drawchangeshotgun4", 1.0),
            ("drawchangeassaultrifle4", 1.0), ("drawchangerocket4", 1.0),
            ("twentyfivebears", 0.0), ("hitmoney", 0.0),
        ] {
            self.globals.insert(k.into(), v);
        }
        for b in 1..=6 {
            self.globals.insert(format!("boss{b}dead"), 0.0);
            self.globals.insert(format!("levelchallenge{b}visited"), 0.0);
        }
        for i in 1..=16 {
            self.globals.insert(format!("talkedtolloyd{i}"), 0.0);
        }
        for w in [
            "assaultriflelevel", "bladegunlevel", "bombgunlevel", "boomeranglevel", "bowlevel",
            "flamethrowerlevel", "icegunlevel", "laserlevel", "pistollevel", "rocketlevel",
            "shotgunlevel", "spikegunlevel",
        ] {
            self.globals.insert(w.into(), 1.0);
        }
        for (w, bought) in [
            ("pistol", 1.0), ("pistolbought", 1.0),
            ("shotgun", 0.0), ("shotgunbought", 0.0),
            ("assaultrifle", 0.0), ("assaultriflebought", 0.0),
            ("rocket", 0.0), ("rocketbought", 0.0),
            ("laser", 0.0), ("laserbought", 0.0),
            ("icegun", 0.0), ("icegunbought", 0.0),
            ("bladegun", 0.0), ("bladegunbought", 0.0),
            ("flamethrower", 0.0), ("flamethrowerbought", 0.0),
            ("bow", 0.0), ("bowbought", 0.0),
            ("bombgun", 0.0), ("bombgunbought", 0.0),
            ("boomerang", 0.0), ("boomerangbought", 0.0),
            ("spikegun", 0.0), ("spikegunbought", 0.0),
        ] {
            self.globals.insert(w.into(), bought);
        }
        for (w, xp_up) in [
            ("pistol", 46.0), ("shotgun", 115.0), ("assaultrifle", 120.0),
            ("rocket", 80.0), ("laser", 80.0), ("icegun", 60.0),
            ("bow", 62.0), ("flamethrower", 180.0), ("bladegun", 200.0),
            ("boomerang", 250.0), ("spikegun", 64.0), ("bombgun", 160.0),
        ] {
            self.globals.insert(format!("{w}xp"), 0.0);
            self.globals.insert(format!("{w}xptolevelup"), xp_up);
            for lvl in [4, 7, 10] {
                self.globals.insert(format!("drawchange{w}{lvl}"), 1.0);
            }
        }
        for k in ["bearskilled", "knifebanditskilled", "pistolthugskilled", "wolfkilled", "chomperbotkilled"] {
            self.globals.insert(k.into(), 0.0);
        }
    }
    /// Test/embedding boundary, not an implicit fake room loader.
    pub fn insert_external(&mut self, object:i32)->i32 {
        self.next_id=self.next_id.max(200000)+1; let id=self.next_id;
        self.instances.insert(id,Instance{object,alive:true,active:true,external:true,fields:BTreeMap::new(),arrays:BTreeMap::new(),alarms:[-1;12]}); id
    }

    /// Data-driven room loader: instantiates all objects and tiles from RoomData.
    /// Runs each instance's Create event, then if a room_binding exists for that
    /// (room_id, instance_id), executes its creation code in the instance's context.
    pub fn load_room_from_data(
        &mut self,
        bundle: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
    ) -> Result<(), String> {
        self.current_room = room_id as f64;
        self.room_width = room.width as f64;
        self.room_height = room.height as f64;
        self.target_room_warp = None;
        self.room_tiles = room.tiles.clone();
        self.draws.clear();

        // Materialize objects from RoomData
        for inst in &room.objects {
            let obj_id = inst.object_id;
            let x = inst.x as f64;
            let y = inst.y as f64;

            // If a persistent instance already exists and is alive, do not duplicate it
            if (obj_id == 0 || self.persistent_objects.contains(&obj_id))
                && self.instances.values().any(|i| i.object == obj_id && i.alive)
            {
                continue;
            }

            // Instantiate object
            let inst_id = self.create_with_id(bundle, inst.instance_id, obj_id, x, y)?;

            // Apply scale if specified
            if inst.scale_x.is_finite() && inst.scale_x != 0.0 {
                let _ = self.write(inst_id, -1, "image_xscale", None, inst.scale_x as f64);
            }
            if inst.scale_y.is_finite() && inst.scale_y != 0.0 {
                let _ = self.write(inst_id, -1, "image_yscale", None, inst.scale_y as f64);
            }

            // Run creation code if bound
            if let Some(binding) = bundle.room_bindings.iter().find(|b| {
                b.room_id == room_id && (b.instance_id == inst.instance_id || (b.object_id == obj_id && b.code_id == inst.creation_code_id as usize))
            }) {
                code_vm::execute(bundle, binding.code_id, inst_id, self)
                    .map_err(|e| format!("Creation code error: {e}"))?;
            }
        }
        Ok(())
    }

    /// Transitions to a target room: preserves persistent instances (player, UI, etc.)
    /// while clearing transient room instances and loading new geometry and bindings.
    pub fn transition_to_room(
        &mut self,
        bundle: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
    ) -> Result<(), String> {
        self.instances.retain(|_, i| i.alive && (i.object == 0 || i.object == 66 || self.persistent_objects.contains(&i.object)));
        self.load_room_from_data(bundle, room_id, room)
    }

    /// Computes instance bounding box from position and sprite bounds.
    pub fn bounds_for_instance(&self, id: i32) -> Option<(f64, f64, f64, f64)> {
        let inst = self.instances.get(&id)?;
        let ix = inst.fields.get("x").copied()?;
        let iy = inst.fields.get("y").copied()?;
        let spr = inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
        let (w, h, ox, oy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
        let sx = inst.fields.get("image_xscale").copied().unwrap_or(1.0);
        let sy = inst.fields.get("image_yscale").copied().unwrap_or(1.0);
        let x0 = ix - ox * sx; let y0 = iy - oy * sy;
        let x1 = x0 + w * sx; let y1 = y0 + h * sy;
        let (min_x, max_x) = if x0 < x1 { (x0, x1) } else { (x1, x0) };
        let (min_y, max_y) = if y0 < y1 { (y0, y1) } else { (y1, y0) };
        Some((min_x, max_x, min_y, max_y))
    }

    pub fn create_with_id(&mut self, b: &Bundle, id: i32, object: i32, x: f64, y: f64) -> Result<i32, String> {
        let obj = b.objects.iter().find(|o| o.id == object)
            .ok_or(format!("object {object} not compiled; no fallback Create"))?;
        self.next_id = self.next_id.max(id);
        self.instances.insert(id, Instance {
            object, alive: true, active: true, external: false,
            fields: BTreeMap::new(), arrays: BTreeMap::new(), alarms: [-1; 12],
        });
        let i = self.instances.get_mut(&id).unwrap();
        for (n, v) in [
            ("id", id as f64),
            ("x", x), ("y", y), ("sprite_index", obj.sprite as f64), ("image_index", 0.0),
            ("image_xscale", 1.0), ("image_yscale", 1.0), ("image_angle", 0.0),
            ("image_blend", 16777215.0), ("image_alpha", 1.0), ("image_speed", 1.0),
            ("score", 0.0), ("hspeed", 0.0), ("vspeed", 0.0), ("speed", 0.0),
            ("direction", 0.0), ("friction", 0.0), ("gravity", 0.0), ("gravity_direction", 270.0),
            ("visible", 1.0),
        ] {
            i.fields.insert(n.into(), v);
        }
        self.dispatch(b, id, 0, 0)?;
        Ok(id)
    }
    pub fn create(&mut self,b:&Bundle,object:i32,x:f64,y:f64)->Result<i32,String> {
        let obj=b.objects.iter().find(|o|o.id==object).ok_or(format!("object {object} not compiled; no fallback Create"))?;
        let id=self.insert_external(object);
        let i=self.instances.get_mut(&id).unwrap(); i.external=false;
        // Named engine defaults only, never default-zero reads of user fields.
        for (n,v) in [("id", id as f64), ("x",x),("y",y),("sprite_index",obj.sprite as f64),("image_index",0.0),
                      ("image_xscale",1.0),("image_yscale",1.0),("image_angle",0.0),
                      ("image_blend",16777215.0),("image_alpha",1.0),("image_speed",1.0),
                      ("score",0.0),("hspeed",0.0),("vspeed",0.0),("speed",0.0),
                      ("direction",0.0),("friction",0.0),("gravity",0.0),("gravity_direction",270.0),
                      ("visible",1.0)] {
            i.fields.insert(n.into(),v);
        }
        self.dispatch(b,id,0,0)?; Ok(id)
    }
    pub fn dispatch(&mut self,b:&Bundle,id:i32,event_type:i32,subtype:i32)->Result<(),String> {
        if self.depth>=64 {return Err("event recursion budget exhausted".into());}
        let i=self.instances.get(&id).ok_or("unknown instance")?;
        if i.external {return Err("cannot dispatch an externally managed instance".into());}
        let o=b.objects.iter().find(|o|o.id==i.object).ok_or("missing object definition")?;
        let mut codes = o.events.iter()
            .find(|e| e.event_type == event_type && e.subtype == subtype)
            .map(|e| e.codes.clone());
        if codes.is_none() {
            for &pid in &o.parent_chain {
                if let Some(parent_obj) = b.objects.iter().find(|obj| obj.id == pid) {
                    if let Some(parent_event) = parent_obj.events.iter().find(|e| e.event_type == event_type && e.subtype == subtype) {
                        codes = Some(parent_event.codes.clone());
                        break;
                    }
                }
            }
        }
        let codes = codes.unwrap_or_default();
        self.depth+=1;
        let result=(|| {for code in codes {code_vm::execute(b,code,id,self).map_err(|e|e.to_string())?;} Ok(())})();
        self.depth-=1; result
    }
    pub fn destroy(&mut self,b:&Bundle,id:i32)->Result<(),String> {
        let i=self.instances.get_mut(&id).ok_or("destroy unknown instance")?;
        if !i.alive {return Ok(());}
        // Retain self storage during Destroy; prevent recursive destruction.
        i.alive=false;
        self.dispatch(b,id,1,0)
    }
    /// Bounded scheduler contract: active snapshot; alarm decrement/dispatch,
    /// then Step. New instances enter the next tick. No physics/animation advance.
    pub fn tick(&mut self,b:&Bundle)->Result<(),String> {
        let ids:Vec<_>=self.instances.iter().filter(|(_,i)|i.alive&&i.active&&!i.external).map(|(id,_)|*id).collect();
        for id in &ids {
            for index in 0..12 {
                let i=self.instances.get_mut(id).unwrap();
                if !i.alive||!i.active {break;}
                if i.alarms[index]>0 {
                    i.alarms[index]-=1;
                    if i.alarms[index]==0 { i.alarms[index]=-1; self.dispatch(b,*id,2,index as i32)?; }
                }
            }
        }
        for id in ids { let i=&self.instances[&id]; if i.alive&&i.active {self.dispatch(b,id,3,0)?;} }

        // Event-driven collision dispatch (event_type == 4)
        let colliders: Vec<(i32, i32)> = self.instances.iter()
            .filter(|(_, i)| i.alive && i.active && !i.external)
            .map(|(id, i)| (*id, i.object))
            .collect();

        for (id, obj_id) in colliders {
            if !self.instances.get(&id).map_or(false, |i| i.alive && i.active) {
                continue;
            }
            let mut col_events = Vec::new();
            if let Some(obj) = b.objects.iter().find(|o| o.id == obj_id) {
                for e in &obj.events {
                    if e.event_type == 4 {
                        col_events.push(e.subtype);
                    }
                }
                for &pid in &obj.parent_chain {
                    if let Some(p) = b.objects.iter().find(|o| o.id == pid) {
                        for e in &p.events {
                            if e.event_type == 4 && !col_events.contains(&e.subtype) {
                                col_events.push(e.subtype);
                            }
                        }
                    }
                }
            }
            if col_events.is_empty() { continue; }

            let (a_min_x, a_max_x, a_min_y, a_max_y) = match self.bounds_for_instance(id) {
                Some(bnd) => bnd,
                None => continue,
            };

            for target_obj in col_events {
                let targets = match self.select(id, target_obj) {
                    Ok(t) => t,
                    Err(_) => continue,
                };
                for tid in targets {
                    if tid == id { continue; }
                    if !self.instances.get(&tid).map_or(false, |i| i.alive && i.active) {
                        continue;
                    }
                    if let Some((b_min_x, b_max_x, b_min_y, b_max_y)) = self.bounds_for_instance(tid) {
                        if a_min_x < b_max_x && a_max_x > b_min_x && a_min_y < b_max_y && a_max_y > b_min_y {
                            self.other_instance = Some(tid);
                            let res = self.dispatch(b, id, 4, target_obj);
                            self.other_instance = None;
                            res?;
                            if !self.instances.get(&id).map_or(false, |i| i.alive && i.active) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Standard GameMaker motion integration: gravity, friction, velocity advance
        for i in self.instances.values_mut() {
            if !i.alive || !i.active || i.external { continue; }

            // 1. Gravity integration
            let grav = i.fields.get("gravity").copied().unwrap_or(0.0);
            if grav != 0.0 {
                let grav_dir = i.fields.get("gravity_direction").copied().unwrap_or(270.0);
                let rad = grav_dir * std::f64::consts::PI / 180.0;
                let gh = grav * rad.cos();
                let gv = -grav * rad.sin();
                if let Some(h) = i.fields.get_mut("hspeed") { *h += gh; }
                if let Some(v) = i.fields.get_mut("vspeed") { *v += gv; }
            }

            // 2. Friction integration
            let frict = i.fields.get("friction").copied().unwrap_or(0.0);
            let mut hsp = i.fields.get("hspeed").copied().unwrap_or(0.0);
            let mut vsp = i.fields.get("vspeed").copied().unwrap_or(0.0);
            if frict != 0.0 {
                let spd = (hsp * hsp + vsp * vsp).sqrt();
                if spd > 0.0 {
                    let new_spd = (spd - frict).max(0.0);
                    hsp = hsp * new_spd / spd;
                    vsp = vsp * new_spd / spd;
                    if let Some(h) = i.fields.get_mut("hspeed") { *h = hsp; }
                    if let Some(v) = i.fields.get_mut("vspeed") { *v = vsp; }
                }
            }

            // 3. Position integration
            if hsp != 0.0 {
                if let Some(x) = i.fields.get_mut("x") { *x += hsp; }
            }
            if vsp != 0.0 {
                if let Some(y) = i.fields.get_mut("y") { *y += vsp; }
            }

            // 4. Synchronize speed and direction fields if non-zero
            if hsp != 0.0 || vsp != 0.0 {
                let cur_spd = (hsp * hsp + vsp * vsp).sqrt();
                let mut dir = (-vsp).atan2(hsp) * 180.0 / std::f64::consts::PI;
                if dir < 0.0 { dir += 360.0; }
                i.fields.insert("speed".into(), cur_spd);
                i.fields.insert("direction".into(), dir);
            }
        }

        self.mouse_pressed=false;
        for d in &mut self.touch_devices {
            d.pressed = false;
            d.released = false;
        }
        Ok(())
    }
    /// One explicit view pass. Camera positions must be supplied by caller.
    /// OBJT depth determines order; equal-depth creation-id order is provisional.
    pub fn draw_view(&mut self,b:&Bundle,view:i32)->Result<(),String> {
        if !self.view_positions.contains_key(&view) {return Err(format!("view {view} is not configured"));}
        self.view=view;
        let mut ids=Vec::new();
        let mut default_draws=Vec::new();
        for (id,i) in &self.instances {
            if i.alive&&i.active&&!i.external {
                let o=b.objects.iter().find(|o|o.id==i.object).ok_or("missing draw object")?;
                let has_draw = o.events.iter().any(|e| e.event_type == 8 && e.subtype == 0)
                    || o.parent_chain.iter().any(|&pid| {
                        b.objects.iter().find(|p| p.id == pid)
                            .map_or(false, |p| p.events.iter().any(|e| e.event_type == 8 && e.subtype == 0))
                    });
                if !has_draw {
                    let visible = i.fields.get("visible").copied().unwrap_or(1.0) >= 0.5;
                    if visible {
                        let fields = ["sprite_index","image_index","x","y","image_xscale","image_yscale","image_angle","image_blend","image_alpha"];
                        if let Some(args) = fields.iter().map(|n| i.fields.get(*n).copied()).collect::<Option<Vec<_>>>() {
                            default_draws.push((*id, args));
                        }
                    }
                    continue;
                }
                ids.push((o.depth,*id));
            }
        }
        ids.sort_by_key(|(depth,id)|(std::cmp::Reverse(*depth),*id));
        for (id, args) in default_draws { let _ = self.draw(id, &args); }
        for (_,id) in ids {self.dispatch(b,id,8,0)?;} Ok(())
    }
    fn self_field(&self,id:i32,n:&str)->Result<f64,String> {
        if n == "id" { return Ok(id as f64); }
        self.instances.get(&id).and_then(|i|i.fields.get(n)).copied().ok_or(format!("undefined instance {id}.{n}"))
    }
    fn draw(&mut self,id:i32,args:&[f64])->Result<(),String> {
        self.draws.push(DrawCommand{code:self.site.0,offset:self.site.1,instance:id,view:self.view,
            sprite:int(args[0])?,frame:args[1],x:args[2],y:args[3],scale_x:args[4],scale_y:args[5],
            rotation:args[6],color:int(args[7])?,alpha:args[8]}); Ok(())
    }
}
impl Host for Scene {
    fn instruction(&mut self,code:usize,offset:usize){self.site=(code,offset);self.executed.push(self.site);}
    fn select(&self,id:i32,s:i32)->Result<Vec<i32>,String> {
        if s == -1 {return Ok(vec![id]);}
        if s == -2 {
            if let Some(other_id) = self.other_instance { return Ok(vec![other_id]); }
            return Ok(vec![id]);
        }
        if s<0 {return Err(format!("unsupported instance selector {s}"));}
        Ok(self.instances.iter().filter(|(key,i)| {
            if !i.alive || !i.active { return false; }
            if s >= 100000 {
                **key == s
            } else if i.object == s {
                true
            } else if let Some(chain) = self.object_parents.get(&i.object) {
                chain.contains(&s)
            } else {
                false
            }
        }).map(|(id,_)|*id).collect())
    }
    fn read(&mut self,id:i32,s:i32,n:&str,index:Option<i32>)->Result<f64,String> {
        if s == -5 {
            if index.is_some(){return Err("global arrays unsupported".into());}
            return self.globals.get(n).copied().ok_or(format!("undefined global.{n}"));
        }
        if s == -1 && n == "view_current" && index.is_none() {return Ok(self.view as f64);}
        if s == -1 && (n=="view_xview"||n=="view_yview") {
            let view=index.ok_or("view requires array index")?;
            let &(x,y)=self.view_positions.get(&view).unwrap_or(&(0.0, 0.0));
            return Ok(if n=="view_xview"{x}else{y});
        }
        if s == -1 && (n=="view_wport"||n=="view_hport") {
            let view=index.ok_or("view requires array index")?;
            let &(w,h)=self.view_ports.get(&view).unwrap_or(&(self.display_width, self.display_height));
            return Ok(if n=="view_wport"{w}else{h});
        }
        if s == -1 && n == "view_visible" {
            let view = index.ok_or("view requires array index")? as usize;
            return Ok(if view < 8 && self.view_visible[view] { 1.0 } else { 0.0 });
        }
        if s == -1 && n == "room_width" && index.is_none() { return Ok(self.room_width); }
        if s == -1 && n == "room_height" && index.is_none() { return Ok(self.room_height); }
        if s == -1 && n == "room" && index.is_none() { return Ok(self.current_room); }
        let ids=self.select(id,s)?;
        if ids.is_empty() {return Err(format!("read has no receiver for selector {s}"));}
        let target=ids[0];
        if let Some(idx)=index {
            if n=="alarm" {
                if !(0..12).contains(&idx) { return Err(format!("unsupported alarm index [{idx}]")); }
                return Ok(self.instances[&target].alarms[idx as usize] as f64);
            }
            return Ok(self.instances[&target].arrays.get(&(n.to_string(), idx)).copied().unwrap_or(0.0));
        }
        self.self_field(target,n)
    }
    fn write(&mut self,id:i32,s:i32,n:&str,index:Option<i32>,value:f64)->Result<(),String> {
        if !value.is_finite(){return Err("non-finite store".into());}
        if s == -5 {
            if index.is_some(){return Err("global arrays unsupported".into());}
            self.globals.insert(n.into(),value);return Ok(());
        }
        if s == -1 && n == "view_visible" {
            let view = index.ok_or("view requires array index")? as usize;
            if view < 8 { self.view_visible[view] = value >= 0.5; }
            return Ok(());
        }
        if s == -1 && (n == "view_xview" || n == "view_yview") {
            let view = index.ok_or("view requires array index")?;
            let entry = self.view_positions.entry(view).or_insert((0.0, 0.0));
            if n == "view_xview" { entry.0 = value; } else { entry.1 = value; }
            return Ok(());
        }
        if s == -1 && (n == "view_wport" || n == "view_hport") {
            let view = index.ok_or("view requires array index")?;
            let entry = self.view_ports.entry(view).or_insert((self.display_width, self.display_height));
            if n == "view_wport" { entry.0 = value; } else { entry.1 = value; }
            return Ok(());
        }
        let ids=self.select(id,s)?;
        if ids.is_empty(){return Err(format!("write has no receiver for selector {s}"));}
        for target in ids {
            let i=self.instances.get_mut(&target).ok_or("missing write target")?;
            if let Some(idx)=index {
                if n=="alarm" {
                    if !(0..12).contains(&idx) { return Err(format!("unsupported alarm index [{idx}]")); }
                    i.alarms[idx as usize]=int(value)?;
                } else {
                    i.arrays.insert((n.to_string(), idx), value);
                }
            } else {i.fields.insert(n.into(),value);}
        } Ok(())
    }
    fn call(&mut self,b:&Bundle,id:i32,n:&str,a:&[f64])->Result<f64,String> {
        let expected_argc = match n {
            "instance_activate_all" | "instance_destroy" | "draw_self" | "display_get_width"
            | "display_get_height" | "randomize" | "action_current_room" | "ini_close"
            | "part_system_create" | "part_type_create" | "audio_stop_all" | "audio_pause_all"
            | "audio_resume_all" | "action_kill_object" | "window_get_width" | "window_get_height"
            | "room_restart" | "game_restart" | "ads_disable" | "shop_leave_rating" => Some(0),
            "instance_deactivate_all" | "instance_deactivate_object" | "instance_activate_object" | "instance_exists"
            | "mouse_check_button_pressed" | "device_mouse_x" | "device_mouse_y" | "mouse_clear"
            | "audio_is_playing" | "audio_stop_sound" | "draw_set_font" | "draw_set_color"
            | "string" | "application_surface_enable" | "device_mouse_dbclick_enable"
            | "file_exists" | "ini_open" | "distance_to_object" | "sign" | "room_goto"
            | "instance_number" | "random" | "draw_set_alpha" | "move_bounce_solid"
            | "move_bounce_all" | "string_digits" | "file_delete" | "object_exists"
            | "AdColony_ShowVideo" => Some(1),
            "device_mouse_check_button" | "device_mouse_check_button_pressed"
            | "device_mouse_check_button_released" | "irandom_range" | "min" | "max" | "random_range"
            | "part_type_alpha1" | "part_type_shape" | "motion_set" | "action_bounce" => Some(2),
            "instance_create" | "audio_play_sound" | "audio_sound_gain" | "instance_place" | "place_meeting"
            | "draw_text" | "AdColony_Init" | "ini_read_real" | "ini_write_real"
            | "part_type_color2" | "part_type_gravity" | "part_type_life"
            | "move_towards_point" | "string_format" | "draw_background" => Some(3),
            "draw_sprite" | "point_direction" | "d3d_set_fog" => Some(4),
            "collision_point" | "part_type_direction" | "part_type_size" | "part_type_speed"
            | "instance_activate_region" | "instance_deactivate_region"
            | "part_particles_create" | "collision_line" => Some(5),
            "part_type_orientation" | "mp_potential_step" => Some(6),
            "draw_text_color" | "draw_background_ext" => Some(8),
            "draw_sprite_ext" => Some(9),
            "draw_healthbar" => Some(11),
            "choose" | "ds_map_find_value" | "ds_map_replace" | "ds_map_destroy"
            | "ds_map_secure_save" | "ds_map_create" | "iap_purchase_details" | "iap_acquire" => None,
            _ => return Err(format!("unsupported builtin {n}")),
        };
        if let Some(exp) = expected_argc {
            if a.len() != exp {
                return Err(format!("{n}: expected {exp} args, got {}", a.len()));
            }
        }
        match n {
            "instance_create" => Ok(self.create(b, int(a[2])?, a[0], a[1])? as f64),
            "instance_deactivate_all" => {
                for (key, i) in &mut self.instances {
                    if i.alive && !(a[0] >= 0.5 && *key == id) { i.active = false; }
                }
                Ok(0.0)
            }
            "instance_deactivate_object" => {
                let s = int(a[0])?;
                let ids = self.select(id, s)?;
                for tid in ids {
                    if let Some(inst) = self.instances.get_mut(&tid) {
                        inst.active = false;
                    }
                }
                Ok(0.0)
            }
            "instance_activate_region" => {
                let x0 = a[0]; let y0 = a[1]; let w = a[2]; let h = a[3];
                let x1 = x0 + w; let y1 = y0 + h;
                for inst in self.instances.values_mut() {
                    let ix = inst.fields.get("x").copied().unwrap_or(0.0);
                    let iy = inst.fields.get("y").copied().unwrap_or(0.0);
                    if ix >= x0 && ix <= x1 && iy >= y0 && iy <= y1 {
                        inst.active = true;
                    }
                }
                Ok(0.0)
            }
            "instance_deactivate_region" => Ok(0.0),
            "instance_activate_all" => {
                for i in self.instances.values_mut() { if i.alive { i.active = true; } }
                Ok(0.0)
            }
            "instance_activate_object" => {
                let s = int(a[0])?;
                if s < 0 { return Err("negative activation selector unsupported".into()); }
                for (key, i) in &mut self.instances {
                    if i.alive && (if s >= 100000 { *key == s } else if i.object == s { true } else { self.object_parents.get(&i.object).map_or(false, |c| c.contains(&s)) }) {
                        i.active = true;
                    }
                }
                Ok(0.0)
            }
            "instance_exists" => Ok(if self.select(id, int(a[0])?)?.is_empty() { 0.0 } else { 1.0 }),
            "instance_destroy" => { self.destroy(b, id)?; Ok(0.0) }
            "mouse_check_button_pressed" => {
                if a[0] != 1.0 { return Err("only left-button input supported".into()); }
                Ok(if self.mouse_pressed { 1.0 } else { 0.0 })
            }
            "audio_play_sound" => {
                let voice = self.audio.len() as i32 + 1;
                self.audio.push(AudioCommand {
                    code: self.site.0, offset: self.site.1, sound: int(a[0])?,
                    priority: a[1], looping: a[2] >= 0.5, voice,
                });
                Ok(voice as f64)
            }
            "audio_is_playing" => Ok(0.0),
            "audio_stop_sound" => Ok(0.0),
            "audio_sound_gain" => Ok(0.0),
            "audio_stop_all" => Ok(0.0),
            "audio_pause_all" => Ok(0.0),
            "audio_resume_all" => Ok(0.0),
            "draw_sprite_ext" => { self.draw(id, a)?; Ok(0.0) }
            "draw_sprite" => {
                self.draw(id, &[a[0], a[1], a[2], a[3], 1.0, 1.0, 0.0, -1.0, self.draw_alpha])?;
                Ok(0.0)
            }
            "draw_self" => {
                let fields = ["sprite_index","image_index","x","y","image_xscale","image_yscale","image_angle","image_blend","image_alpha"];
                let args = fields.iter().map(|n| self.self_field(id, n)).collect::<Result<Vec<_>,_>>()?;
                self.draw(id, &args)?;
                Ok(0.0)
            }
            "device_mouse_x" => {
                let dev = int(a[0])? as usize;
                Ok(if dev < 5 { self.touch_devices[dev].x } else { 0.0 })
            }
            "device_mouse_y" => {
                let dev = int(a[0])? as usize;
                Ok(if dev < 5 { self.touch_devices[dev].y } else { 0.0 })
            }
            "device_mouse_check_button" => {
                let dev = int(a[0])? as usize;
                Ok(if dev < 5 && self.touch_devices[dev].down { 1.0 } else { 0.0 })
            }
            "device_mouse_check_button_pressed" => {
                let dev = int(a[0])? as usize;
                Ok(if dev < 5 && self.touch_devices[dev].pressed { 1.0 } else { 0.0 })
            }
            "device_mouse_check_button_released" => {
                let dev = int(a[0])? as usize;
                Ok(if dev < 5 && self.touch_devices[dev].released { 1.0 } else { 0.0 })
            }
            "mouse_clear" => {
                for d in &mut self.touch_devices { d.down = false; d.pressed = false; d.released = false; }
                Ok(0.0)
            }
            "collision_point" => {
                let px = a[0]; let py = a[1]; let s = int(a[2])?; let notme = a[4] >= 0.5;
                let targets = self.select(id, s)?;
                let mut hit = 0.0;
                for tid in targets {
                    if notme && tid == id { continue; }
                    let ix = self.self_field(tid, "x").unwrap_or(0.0);
                    let iy = self.self_field(tid, "y").unwrap_or(0.0);
                    let spr = self.self_field(tid, "sprite_index").unwrap_or(-1.0) as i32;
                    let (w, h, ox, oy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                    let sx = self.self_field(tid, "image_xscale").unwrap_or(1.0);
                    let sy = self.self_field(tid, "image_yscale").unwrap_or(1.0);
                    let x0 = ix - ox * sx; let y0 = iy - oy * sy;
                    let x1 = x0 + w * sx; let y1 = y0 + h * sy;
                    let (min_x, max_x) = if x0 < x1 { (x0, x1) } else { (x1, x0) };
                    let (min_y, max_y) = if y0 < y1 { (y0, y1) } else { (y1, y0) };
                    if px >= min_x && px <= max_x && py >= min_y && py <= max_y {
                        hit = tid as f64;
                        break;
                    }
                }
                Ok(hit)
            }
            "instance_place" => {
                let px = a[0]; let py = a[1]; let s = int(a[2])?;
                let targets = self.select(id, s)?;
                let spr = self.self_field(id, "sprite_index").unwrap_or(-1.0) as i32;
                let (pw, ph, pox, poy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                let psx = self.self_field(id, "image_xscale").unwrap_or(1.0);
                let psy = self.self_field(id, "image_yscale").unwrap_or(1.0);
                let p_x0 = px - pox * psx; let p_y0 = py - poy * psy;
                let p_x1 = p_x0 + pw * psx; let p_y1 = p_y0 + ph * psy;
                let (p_min_x, p_max_x) = if p_x0 < p_x1 { (p_x0, p_x1) } else { (p_x1, p_x0) };
                let (p_min_y, p_max_y) = if p_y0 < p_y1 { (p_y0, p_y1) } else { (p_y1, p_y0) };
                let mut hit = -4.0;
                for tid in targets {
                    if tid == id { continue; }
                    let ix = self.self_field(tid, "x").unwrap_or(0.0);
                    let iy = self.self_field(tid, "y").unwrap_or(0.0);
                    let ispr = self.self_field(tid, "sprite_index").unwrap_or(-1.0) as i32;
                    let (iw, ih, iox, ioy) = self.sprite_bounds.get(&ispr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                    let isx = self.self_field(tid, "image_xscale").unwrap_or(1.0);
                    let isy = self.self_field(tid, "image_yscale").unwrap_or(1.0);
                    let i_x0 = ix - iox * isx; let i_y0 = iy - ioy * isy;
                    let i_x1 = i_x0 + iw * isx; let i_y1 = i_y0 + ih * isy;
                    let (i_min_x, i_max_x) = if i_x0 < i_x1 { (i_x0, i_x1) } else { (i_x1, i_x0) };
                    let (i_min_y, i_max_y) = if i_y0 < i_y1 { (i_y0, i_y1) } else { (i_y1, i_y0) };
                    if p_min_x < i_max_x && p_max_x > i_min_x && p_min_y < i_max_y && p_max_y > i_min_y {
                        hit = tid as f64;
                        break;
                    }
                }
                Ok(hit)
            }
            "display_get_width" => Ok(self.display_width),
            "display_get_height" => Ok(self.display_height),
            "string" => Ok(a[0]),
            "choose" => {
                if a.is_empty() { return Ok(0.0); }
                let r = next_rand(&mut self.rng_seed);
                let idx = ((r * a.len() as f64).floor() as usize).min(a.len() - 1);
                Ok(a[idx])
            }
            "randomize" => {
                self.rng_seed = self.rng_seed.wrapping_add(0x9e3779b97f4a7c15);
                Ok(0.0)
            }
            "irandom_range" => {
                let min = a[0].min(a[1]);
                let max = a[0].max(a[1]);
                let span = (max - min + 1.0).max(1.0);
                let r = next_rand(&mut self.rng_seed);
                Ok((min + (r * span).floor()).min(max))
            }
            "draw_set_font" => { self.current_font = a[0]; Ok(0.0) }
            "draw_set_color" => { self.draw_color = int(a[0])?; Ok(0.0) }
            "draw_text" => Ok(0.0),
            "draw_healthbar" => Ok(0.0),
            "application_surface_enable" => Ok(0.0),
            "action_current_room" => Ok(self.current_room),
            "room_goto" => {
                let target = a[0] as usize;
                self.target_room_warp = Some(target);
                Ok(0.0)
            },
            "device_mouse_dbclick_enable" => Ok(0.0),
            "file_exists" => Ok(1.0),
            "ini_open" => {
                let s_idx = a[0] as usize;
                let name = b.string_table.get(s_idx).cloned().unwrap_or_default();
                self.ini_open_file = Some(name);
                Ok(0.0)
            }
            "ini_close" => {
                self.ini_open_file = None;
                Ok(0.0)
            }
            "ini_read_real" => {
                let sec_idx = a[0] as usize;
                let key_idx = a[1] as usize;
                let def_val = a[2];
                let sec = b.string_table.get(sec_idx).cloned().unwrap_or_default();
                let key = b.string_table.get(key_idx).cloned().unwrap_or_default();
                let file = self.ini_open_file.clone().unwrap_or_default();
                let val = self.ini_data.get(&(file, sec, key)).copied().unwrap_or(def_val);
                Ok(val)
            }
            "ini_write_real" => {
                let sec_idx = a[0] as usize;
                let key_idx = a[1] as usize;
                let val = a[2];
                let sec = b.string_table.get(sec_idx).cloned().unwrap_or_default();
                let key = b.string_table.get(key_idx).cloned().unwrap_or_default();
                let file = self.ini_open_file.clone().unwrap_or_default();
                self.ini_data.insert((file, sec, key), val);
                Ok(0.0)
            }
            "AdColony_Init" => Ok(0.0),
            "sign" => Ok(if a[0] > 0.0 { 1.0 } else if a[0] < 0.0 { -1.0 } else { 0.0 }),
            "min" => Ok(a[0].min(a[1])),
            "max" => Ok(a[0].max(a[1])),
            "random_range" => {
                let min = a[0].min(a[1]);
                let max = a[0].max(a[1]);
                let r = next_rand(&mut self.rng_seed);
                Ok(min + r * (max - min))
            }
            "distance_to_object" => {
                let s = int(a[0])?;
                let targets = self.select(id, s)?;
                let ix = self.self_field(id, "x").unwrap_or(0.0);
                let iy = self.self_field(id, "y").unwrap_or(0.0);
                let mut min_dist = f64::MAX;
                for tid in targets {
                    let tx = self.self_field(tid, "x").unwrap_or(0.0);
                    let ty = self.self_field(tid, "y").unwrap_or(0.0);
                    let d = ((tx - ix).powi(2) + (ty - iy).powi(2)).sqrt();
                    if d < min_dist { min_dist = d; }
                }
                Ok(if min_dist == f64::MAX { 100000.0 } else { min_dist })
            }
            "place_meeting" => {
                let hit = match self.call(b, id, "instance_place", &[a[0], a[1], a[2]]) {
                    Ok(tid) => tid > 0.0,
                    Err(_) => false,
                };
                Ok(if hit { 1.0 } else { 0.0 })
            }
            "part_system_create" | "part_type_create" => Ok(1.0),
            "part_type_alpha1" | "part_type_shape" | "part_type_color2" | "part_type_gravity"
            | "part_type_life" | "part_type_direction" | "part_type_size" | "part_type_speed"
            | "part_type_orientation" => Ok(0.0),
            "motion_set" => {
                let dir = a[0]; let spd = a[1];
                let rad = dir * std::f64::consts::PI / 180.0;
                let hsp = spd * rad.cos();
                let vsp = -spd * rad.sin();
                let i = self.instances.get_mut(&id).ok_or("missing motion_set target")?;
                i.fields.insert("direction".into(), dir);
                i.fields.insert("speed".into(), spd);
                i.fields.insert("hspeed".into(), hsp);
                i.fields.insert("vspeed".into(), vsp);
                Ok(0.0)
            }
            "move_towards_point" => {
                let tx = a[0]; let ty = a[1]; let spd = a[2];
                let ix = self.self_field(id, "x").unwrap_or(0.0);
                let iy = self.self_field(id, "y").unwrap_or(0.0);
                let mut dir = (-(ty - iy)).atan2(tx - ix) * 180.0 / std::f64::consts::PI;
                if dir < 0.0 { dir += 360.0; }
                let rad = dir * std::f64::consts::PI / 180.0;
                let hsp = spd * rad.cos();
                let vsp = -spd * rad.sin();
                let i = self.instances.get_mut(&id).ok_or("missing move_towards_point target")?;
                i.fields.insert("direction".into(), dir);
                i.fields.insert("speed".into(), spd);
                i.fields.insert("hspeed".into(), hsp);
                i.fields.insert("vspeed".into(), vsp);
                Ok(0.0)
            }
            "point_direction" => {
                let x1 = a[0]; let y1 = a[1]; let x2 = a[2]; let y2 = a[3];
                let mut dir = (-(y2 - y1)).atan2(x2 - x1) * 180.0 / std::f64::consts::PI;
                if dir < 0.0 { dir += 360.0; }
                Ok(dir)
            }
            "instance_number" => {
                let obj_id = int(a[0])?;
                let targets = self.select(id, obj_id)?;
                Ok(targets.len() as f64)
            }
            "action_kill_object" => { self.destroy(b, id)?; Ok(0.0) }
            "window_get_width" => Ok(self.display_width),
            "window_get_height" => Ok(self.display_height),
            "draw_set_alpha" => { self.draw_alpha = a[0]; Ok(0.0) }
            "part_particles_create" | "d3d_set_fog" | "draw_text_color"
            | "draw_background_ext" | "draw_background" | "AdColony_ShowVideo" | "ads_disable"
            "collision_line" => {
                let x1 = a[0]; let y1 = a[1]; let x2 = a[2]; let y2 = a[3];
                let s = int(a[4])?;
                let targets = self.select(id, s)?;
                let mut hit = -4.0;
                for tid in targets {
                    if tid == id { continue; }
                    let ix = self.self_field(tid, "x").unwrap_or(0.0);
                    let iy = self.self_field(tid, "y").unwrap_or(0.0);
                    let spr = self.self_field(tid, "sprite_index").unwrap_or(-1.0) as i32;
                    let (w, h, ox, oy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                    let sx = self.self_field(tid, "image_xscale").unwrap_or(1.0);
                    let sy = self.self_field(tid, "image_yscale").unwrap_or(1.0);
                    let bx0 = ix - ox * sx; let by0 = iy - oy * sy;
                    let bx1 = bx0 + w * sx; let by1 = by0 + h * sy;
                    let (min_x, max_x) = if bx0 < bx1 { (bx0, bx1) } else { (bx1, bx0) };
                    let (min_y, max_y) = if by0 < by1 { (by0, by1) } else { (by1, by0) };
                    if line_intersects_box(x1, y1, x2, y2, min_x, max_x, min_y, max_y) {
                        hit = tid as f64;
                        break;
                    }
                }
                Ok(hit)
            }
            "mp_potential_step" => {
                let target_x = a[0]; let target_y = a[1]; let step_size = a[2];
                let ix = self.self_field(id, "x").unwrap_or(0.0);
                let iy = self.self_field(id, "y").unwrap_or(0.0);
                let mut dir = (-(target_y - iy)).atan2(target_x - ix) * 180.0 / std::f64::consts::PI;
                if dir < 0.0 { dir += 360.0; }
                let rad = dir * std::f64::consts::PI / 180.0;
                let nx = ix + step_size * rad.cos();
                let ny = iy - step_size * rad.sin();
                if let Some(i) = self.instances.get_mut(&id) {
                    i.fields.insert("x".into(), nx);
                    i.fields.insert("y".into(), ny);
                    i.fields.insert("direction".into(), dir);
                    i.fields.insert("speed".into(), step_size);
                }
                Ok(1.0)
            }
            | "shop_leave_rating" | "file_delete"
            | "ds_map_find_value" | "ds_map_replace" | "ds_map_destroy" | "ds_map_secure_save"
            | "ds_map_create" | "iap_purchase_details" | "iap_acquire" => Ok(0.0),
            "object_exists" => Ok(1.0),
            "random" => {
                let r = next_rand(&mut self.rng_seed);
                Ok(r * a[0])
            }
            "string_format" | "string_digits" => Ok(a[0]),
            "action_bounce" | "move_bounce_solid" | "move_bounce_all" => {
                if let Some(i) = self.instances.get_mut(&id) {
                    if let Some(h) = i.fields.get_mut("hspeed") { *h = -*h; }
                    if let Some(v) = i.fields.get_mut("vspeed") { *v = -*v; }
                }
                Ok(0.0)
            }
            "room_restart" => {
                self.target_room_warp = Some(self.current_room as usize);
                Ok(0.0)
            }
            "game_restart" => {
                self.target_room_warp = Some(0);
                Ok(0.0)
            }
            _ => Err(format!("unsupported builtin {n}")),
        }
    }
}
