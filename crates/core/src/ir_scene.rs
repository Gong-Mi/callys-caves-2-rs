//! Headless event host for a bounded IR scene, NOT GameWorld or a full GM runner.
//! Event bodies come exclusively from CODE IR/OBJT bindings. No intro timers or
//! coordinates are hand-translated here. External instances are explicitly inert.
use crate::code_vm::{self, Bundle, Host};
use serde::Serialize;
use std::collections::BTreeMap;

#[derive(Debug, Clone)]
pub struct Instance {
    pub object: i32, pub alive: bool, pub active: bool, pub external: bool,
    pub fields: BTreeMap<String, f64>, pub alarms: [i32; 12],
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct DrawCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub sprite: i32, pub frame: f64, pub x: f64, pub y: f64,
    pub scale_x: f64, pub scale_y: f64, pub rotation: f64, pub color: i32, pub alpha: f64,
}
#[derive(Debug, Clone, Serialize)]
pub struct AudioCommand { pub code: usize, pub offset: usize, pub sound: i32, pub priority: f64, pub looping: bool, pub voice: i32 }
#[derive(Debug, Default)]
pub struct Scene {
    pub instances: BTreeMap<i32, Instance>, pub globals: BTreeMap<String, f64>,
    pub draws: Vec<DrawCommand>, pub audio: Vec<AudioCommand>,
    pub executed: Vec<(usize,usize)>,
    pub view: i32, pub view_positions: BTreeMap<i32,(f64,f64)>, pub mouse_pressed: bool,
    next_id: i32, site: (usize,usize), depth: usize,
}
fn int(v:f64)->Result<i32,String> {
    if v.is_finite() && v.fract()==0.0 && v>=i32::MIN as f64 && v<=i32::MAX as f64 {Ok(v as i32)}
    else {Err(format!("expected i32, got {v}"))}
}
impl Scene {
    /// Test/embedding boundary, not an implicit fake room loader.
    pub fn insert_external(&mut self, object:i32)->i32 {
        self.next_id=self.next_id.max(100000)+1; let id=self.next_id;
        self.instances.insert(id,Instance{object,alive:true,active:true,external:true,fields:BTreeMap::new(),alarms:[-1;12]}); id
    }
    pub fn create(&mut self,b:&Bundle,object:i32,x:f64,y:f64)->Result<i32,String> {
        let obj=b.objects.iter().find(|o|o.id==object).ok_or(format!("object {object} not compiled; no fallback Create"))?;
        let id=self.insert_external(object);
        let i=self.instances.get_mut(&id).unwrap(); i.external=false;
        // Named engine defaults only, never default-zero reads of user fields.
        for (n,v) in [("x",x),("y",y),("sprite_index",obj.sprite as f64),("image_index",0.0),
                      ("image_xscale",1.0),("image_yscale",1.0),("image_angle",0.0),
                      ("image_blend",16777215.0),("image_alpha",1.0),("image_speed",1.0)] {
            i.fields.insert(n.into(),v);
        }
        self.dispatch(b,id,0,0)?; Ok(id)
    }
    pub fn dispatch(&mut self,b:&Bundle,id:i32,event_type:i32,subtype:i32)->Result<(),String> {
        if self.depth>=64 {return Err("event recursion budget exhausted".into());}
        let i=self.instances.get(&id).ok_or("unknown instance")?;
        if i.external {return Err("cannot dispatch an externally managed instance".into());}
        let o=b.objects.iter().find(|o|o.id==i.object).ok_or("missing object definition")?;
        let codes=o.events.iter().find(|e|e.event_type==event_type&&e.subtype==subtype).map(|e|e.codes.clone()).unwrap_or_default();
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
        self.mouse_pressed=false; Ok(())
    }
    /// One explicit view pass. Camera positions must be supplied by caller.
    /// OBJT depth determines order; equal-depth creation-id order is provisional.
    pub fn draw_view(&mut self,b:&Bundle,view:i32)->Result<(),String> {
        if !self.view_positions.contains_key(&view) {return Err(format!("view {view} is not configured"));}
        self.view=view;
        let mut ids=Vec::new();
        for (id,i) in &self.instances {
            if i.alive&&i.active&&!i.external {
                let o=b.objects.iter().find(|o|o.id==i.object).ok_or("missing draw object")?;
                if !o.events.iter().any(|e|e.event_type==8&&e.subtype==0) {return Err("default Draw unsupported".into());}
                ids.push((o.depth,*id));
            }
        }
        ids.sort_by_key(|(depth,id)|(std::cmp::Reverse(*depth),*id));
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
        if s<0 {return Err(format!("unsupported instance selector {s}"));}
        Ok(self.instances.iter().filter(|(key,i)|i.alive&&i.active&&(if s>=100000 {**key==s} else {i.object==s})).map(|(id,_)|*id).collect())
    }
    fn read(&mut self,id:i32,s:i32,n:&str,index:Option<i32>)->Result<f64,String> {
        if s == -5 {
            if index.is_some(){return Err("global arrays unsupported".into());}
            return self.globals.get(n).copied().ok_or(format!("undefined global.{n}"));
        }
        if s == -1 && n == "view_current" && index.is_none() {return Ok(self.view as f64);}
        if s == -1 && (n=="view_xview"||n=="view_yview") {
            let view=index.ok_or("view requires array index")?;
            let &(x,y)=self.view_positions.get(&view).ok_or("undefined view")?;return Ok(if n=="view_xview"{x}else{y});
        }
        let ids=self.select(id,s)?;
        if ids.len()!=1 {return Err(format!("read requires exactly one receiver, got {}",ids.len()));}
        let target=ids[0];
        if let Some(idx)=index {
            if n!="alarm"||!(0..12).contains(&idx){return Err(format!("unsupported array {n}[{idx}]"));}
            return Ok(self.instances[&target].alarms[idx as usize] as f64);
        }
        self.self_field(target,n)
    }
    fn write(&mut self,id:i32,s:i32,n:&str,index:Option<i32>,value:f64)->Result<(),String> {
        if !value.is_finite(){return Err("non-finite store".into());}
        if s == -5 {
            if index.is_some(){return Err("global arrays unsupported".into());}
            self.globals.insert(n.into(),value);return Ok(());
        }
        let ids=self.select(id,s)?;
        if ids.is_empty(){return Err(format!("write has no receiver for selector {s}"));}
        for target in ids {
            let i=self.instances.get_mut(&target).ok_or("missing write target")?;
            if let Some(idx)=index {
                if n!="alarm"||!(0..12).contains(&idx){return Err(format!("unsupported array {n}[{idx}]"));}
                i.alarms[idx as usize]=int(value)?;
            } else {i.fields.insert(n.into(),value);}
        } Ok(())
    }
    fn call(&mut self,b:&Bundle,id:i32,n:&str,a:&[f64])->Result<f64,String> {
        let argc=match n {"instance_create"|"audio_play_sound"=>3,"instance_deactivate_all"|"instance_activate_object"|"instance_exists"|"mouse_check_button_pressed"=>1,
            "instance_activate_all"|"instance_destroy"|"draw_self"=>0,"draw_sprite_ext"=>9,_=>return Err(format!("unsupported builtin {n}"))};
        if a.len()!=argc{return Err(format!("{n}: expected {argc} args, got {}",a.len()));}
        match n {
            "instance_create"=>return Ok(self.create(b,int(a[2])?,a[0],a[1])? as f64),
            "instance_deactivate_all"=>for (key,i) in &mut self.instances {if i.alive&&!(a[0]>=0.5&&*key==id){i.active=false;}},
            "instance_activate_all"=>for i in self.instances.values_mut(){if i.alive{i.active=true;}},
            "instance_activate_object"=>{let s=int(a[0])?;if s<0{return Err("negative activation selector unsupported".into());}for (key,i) in &mut self.instances {if i.alive&&(if s>=100000{*key==s}else{i.object==s}){i.active=true;}}},
            "instance_exists"=>return Ok(if self.select(id,int(a[0])?)?.is_empty(){0.0}else{1.0}),
            "instance_destroy"=>self.destroy(b,id)?,
            "mouse_check_button_pressed"=>{if a[0]!=1.0{return Err("only left-button input supported".into());}return Ok(if self.mouse_pressed{1.0}else{0.0});},
            "audio_play_sound"=>{let voice=self.audio.len() as i32+1;self.audio.push(AudioCommand{code:self.site.0,offset:self.site.1,sound:int(a[0])?,priority:a[1],looping:a[2]>=0.5,voice});return Ok(voice as f64);},
            "draw_sprite_ext"=>self.draw(id,a)?,
            "draw_self"=>{
                let fields=["sprite_index","image_index","x","y","image_xscale","image_yscale","image_angle","image_blend","image_alpha"];
                let args=fields.iter().map(|n|self.self_field(id,n)).collect::<Result<Vec<_>,_>>()?;self.draw(id,&args)?;
            }
            _=>unreachable!(),
        } Ok(0.0)
    }
}
