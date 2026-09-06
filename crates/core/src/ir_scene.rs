//! Headless event host for a bounded IR scene, NOT GameWorld or a full GM runner.
//! Event bodies come exclusively from CODE IR/OBJT bindings. No intro timers or
//! coordinates are hand-translated here. External instances are explicitly inert.
use crate::code_vm::{self, Bundle, Host};
use serde::Serialize;
use std::collections::BTreeMap;

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
    pub current_font: f64, pub draw_color: i32,
    pub view_visible: [bool; 8],
    pub ini_open_file: Option<String>,
    pub ini_data: BTreeMap<(String, String, String), f64>,
    pub other_instance: Option<i32>,
    pub room_tiles: Vec<callys_asset::RoomTileInstance>,
    pub target_room_warp: Option<usize>,
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
            current_font: 0.0, draw_color: -1,
            view_visible: [true, false, false, false, false, false, false, false],
            ini_open_file: None,
            ini_data: BTreeMap::new(),
            other_instance: None,
            room_tiles: Vec::new(),
            target_room_warp: None,
            next_id: 0, site: (0, 0), depth: 0,
        }
    }
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
        for (n,v) in [("x",x),("y",y),("sprite_index",obj.sprite as f64),("image_index",0.0),
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
        if ids.len()!=1 {return Err(format!("read requires exactly one receiver, got {}",ids.len()));}
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
            | "part_system_create" | "part_type_create" => Some(0),
            "instance_deactivate_all" | "instance_activate_object" | "instance_exists"
            | "mouse_check_button_pressed" | "device_mouse_x" | "device_mouse_y" | "mouse_clear"
            | "audio_is_playing" | "audio_stop_sound" | "draw_set_font" | "draw_set_color"
            | "string" | "application_surface_enable" | "device_mouse_dbclick_enable"
            | "file_exists" | "ini_open" | "distance_to_object" | "sign" | "room_goto" => Some(1),
            "device_mouse_check_button" | "device_mouse_check_button_pressed"
            | "device_mouse_check_button_released" | "irandom_range" | "min" | "max" | "random_range"
            | "part_type_alpha1" | "part_type_shape" => Some(2),
            "instance_create" | "audio_play_sound" | "instance_place" | "place_meeting"
            | "draw_text" | "AdColony_Init" | "ini_read_real" | "ini_write_real"
            | "part_type_color2" | "part_type_gravity" | "part_type_life" => Some(3),
            "draw_sprite" => Some(4),
            "collision_point" | "part_type_direction" | "part_type_size" | "part_type_speed" => Some(5),
            "part_type_orientation" => Some(6),
            "draw_sprite_ext" => Some(9),
            "draw_healthbar" => Some(11),
            "choose" => None,
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
            "draw_sprite_ext" => { self.draw(id, a)?; Ok(0.0) }
            "draw_sprite" => {
                self.draw(id, &[a[0], a[1], a[2], a[3], 1.0, 1.0, 0.0, -1.0, 1.0])?;
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
            "choose" => Ok(a[0]),
            "randomize" => Ok(0.0),
            "irandom_range" => Ok(a[0]),
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
            "random_range" => Ok(a[0]),
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
            _ => Err(format!("unsupported builtin {n}")),
        }
    }
}
