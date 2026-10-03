impl Host for Scene {
    fn instruction(&mut self,code:usize,offset:usize){self.site=(code,offset);self.executed.push(self.site);}
    /// GMS `+` with a string operand. The shipped sites pair a literal with a
    /// `string()` result ("+" + string(global.coinpickup)); both sides resolve
    /// through the pool and the joined text becomes a fresh reference so the
    /// consumer (draw_text) still sees one string value.
    fn string_concat(&mut self, b: &Bundle, lhs: f64, rhs: f64) -> Result<f64, String> {
        let text = format!("{}{}", self.arg_text(b, lhs), self.arg_text(b, rhs));
        Ok(self.alloc_string(b, text))
    }
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
        if s == -1 && n == "score" && index.is_none() { return Ok(self.score); }
        if s == -5 {
            if index.is_some(){return Err("global arrays unsupported".into());}
            return Ok(self.globals.get(n).copied().unwrap_or(0.0));
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
        let ids=self.select_for_access(id,s);
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
        if s == -1 && n == "score" && index.is_none() { self.score = value; return Ok(()); }
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
        let ids=self.select_for_access(id,s);
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
            | "room_restart" | "game_restart" => Some(0),
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
            "draw_sprite" | "point_direction" | "d3d_set_fog" | "mp_potential_step" => Some(4),
            "collision_point" | "part_type_direction" | "part_type_size" | "part_type_speed"
            | "instance_activate_region" | "instance_deactivate_region"
            | "part_particles_create" => Some(5),
            // GMS collision_line(x1,y1,x2,y2,obj,prec,notme) - the original's
            // only call site (obj_shooter2 Alarm 1, CODE 108) passes all seven.
            "collision_line" => Some(7),
            "part_type_orientation" => Some(6),
            "draw_text_color" | "draw_background_ext" => Some(8),
            "draw_sprite_ext" => Some(9),
            "draw_healthbar" => Some(11),
            "choose" | "ds_map_find_value" | "ds_map_replace" | "ds_map_destroy"
            | "ds_map_secure_save" | "ds_map_create" | "iap_purchase_details" | "iap_acquire"
            // Platform stubs whose original call sites carry arguments the SDK
            // signatures need but this client ignores: ads_disable is called
            // with one arg from obj_poisoniap Other_66 and shop_leave_rating
            // with four from obj_firstpause Create. Accept any arity instead of
            // raising on a call that has nothing to do here.
            | "ads_disable" | "shop_leave_rating" => None,
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
                let voice = self.call_audio_play(a[0], a[1], a[2] >= 0.5);
                Ok(voice)
            }
            "audio_is_playing" => Ok(if self.audio_is_playing_sound(a[0]) { 1.0 } else { 0.0 }),
            "audio_stop_sound" => {
                self.call_audio_stop_sound(a[0]);
                Ok(0.0)
            }
            "audio_sound_gain" => {
                self.call_audio_sound_gain(a[0], a[1], a[2]);
                Ok(0.0)
            }
            "audio_stop_all" => {
                self.call_audio_stop_all();
                Ok(0.0)
            }
            "audio_pause_all" => {
                self.call_audio_pause_all();
                Ok(0.0)
            }
            "audio_resume_all" => {
                self.call_audio_resume_all();
                Ok(0.0)
            }
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
                let px = a[0]; let py = a[1]; let s = int(a[2])?;
                let prec = a[3] >= 0.5;
                let notme = a[4] >= 0.5;
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
                        if prec && self.mask_hit(tid, px, py) == Some(false) { continue; }
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
            "string" => {
                // GMS string(x): a string reference stays itself (str1 flows
                // through string() into the death screen); a number formats.
                if pool_index(a[0]).is_some() { return Ok(a[0]); }
                Ok(self.alloc_string(b, gm_real_text(a[0])))
            }
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
            "draw_text" => {
                let x = a[0]; let y = a[1];
                let text = self.arg_text(b, a[2]);
                self.texts.push(TextCommand {
                    code: self.site.0, offset: self.site.1, instance: id, view: self.view,
                    x, y, text, color: self.draw_color, alpha: self.draw_alpha,
                    font: self.current_font as i32,
                });
                Ok(0.0)
            }
            "draw_healthbar" => {
                let x1 = a[0]; let y1 = a[1]; let x2 = a[2]; let y2 = a[3];
                let amount = a[4];
                let back_col = int(a[5])?;
                let min_col = int(a[6])?;
                let max_col = int(a[7])?;
                self.healthbars.push(HealthbarCommand {
                    code: self.site.0, offset: self.site.1, instance: id, view: self.view,
                    x1, y1, x2, y2, amount, back_col, min_col, max_col,
                });
                Ok(0.0)
            }
            // Platform inert by design: surface is always enabled in this
            // client and double-tap scaling carries no original state.
            "application_surface_enable" => Ok(0.0),
            "action_current_room" => Ok(self.current_room),
            "room_goto" => {
                let target = a[0] as usize;
                self.target_room_warp = Some(target);
                Ok(0.0)
            },
            "device_mouse_dbclick_enable" => Ok(0.0), // touch device has no double-tap zoom
            "file_exists" => {
                let name = self.arg_text(b, a[0]);
                let exists = if let Some(dir) = &self.ini_disk_dir {
                    dir.join(&name).is_file()
                } else {
                    self.ini_data.keys().any(|(f, _, _)| f == &name)
                };
                Ok(if exists { 1.0 } else { 0.0 })
            },
            "file_delete" => {
                let name = self.arg_text(b, a[0]);
                if let Some(dir) = &self.ini_disk_dir {
                    let _ = std::fs::remove_file(dir.join(&name));
                }
                self.ini_data.retain(|&(ref f, _, _), _| f != &name);
                Ok(1.0)
            },
            "ini_open" => {
                let name = self.arg_text(b, a[0]);
                if let Some(dir) = &self.ini_disk_dir {
                    // Re-open flushes nothing here: the original ini_open on an
                    // already-open file abandons pending writes; a fresh load
                    // from disk keeps this boundary honest. Cache entries for a
                    // different open file stay untouched.
                    self.ini_data.retain(|(f, _, _), _| f != &name);
                    let path = dir.join(&name);
                    if let Ok(text) = std::fs::read_to_string(&path) {
                        let mut current_sec = "Save".to_string();
                        for line in text.lines() {
                            let line = line.trim();
                            if line.starts_with('[') && line.ends_with(']') {
                                current_sec = line[1..line.len()-1].trim().to_string();
                                continue;
                            }
                            if !line.contains('=') { continue; }
                            let (key, value) = line.split_once('=').unwrap();
                            self.ini_data.insert((name.clone(), current_sec.clone(), key.trim().to_string()), value.trim().parse::<f64>().unwrap_or(0.0));
                        }
                    }
                }
                self.ini_open_file = Some(name);
                Ok(0.0)
            }
            "ini_close" => {
                if let (Some(dir), Some(name)) = (&self.ini_disk_dir, &self.ini_open_file.clone()) {
                    // Group keys by section under standard INI format [Section]
                    let mut by_sec: BTreeMap<String, Vec<(&str, f64)>> = BTreeMap::new();
                    for ((f, sec, key), value) in &self.ini_data {
                        if f == name {
                            by_sec.entry(sec.clone()).or_default().push((key.as_str(), *value));
                        }
                    }
                    if !by_sec.is_empty() {
                        let mut lines = String::new();
                        for (sec, entries) in by_sec {
                            lines.push_str(&format!("[{sec}]\n"));
                            for (key, val) in entries {
                                lines.push_str(&format!("{key}={}\n", format_gm_real(val)));
                            }
                        }
                        let _ = std::fs::create_dir_all(dir);
                        let _ = std::fs::write(dir.join(name), lines);
                    }
                }
                self.ini_open_file = None;
                Ok(0.0)
            }
            "ini_read_real" => {
                let def_val = a[2];
                let sec = self.arg_text(b, a[0]);
                let key = self.arg_text(b, a[1]);
                let file = self.ini_open_file.clone().unwrap_or_default();
                let val = self.ini_data.get(&(file, sec, key)).copied().unwrap_or(def_val);
                Ok(val)
            }
            "ini_write_real" => {
                let val = a[2];
                let sec = self.arg_text(b, a[0]);
                let key = self.arg_text(b, a[1]);
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
                // F_DistanceToObject @0x10ad88 starts at 1e6, then uses
                // WithObjIterator (objects include descendants). FindDist
                // @0x10ac9c rejects self and target +0x68/+0x69, NOT caller
                // flags, and measures inclusive bbox gaps, never origin gaps.
                let selector = int(a[0])?;
                let targets = match selector {
                    -3 => self.instances.keys().copied().collect(), // all
                    s if s < -3 => Vec::new(), // noone / absent special object
                    s => self.select(id, s)?,
                };
                let mut min_dist: f64 = 1_000_000.0;
                if let Some((left,right,top,bottom)) = self.distance_bounds_for_instance(id) {
                    for tid in targets {
                        if tid == id || self.instances.get(&tid).map_or(true, |i| !i.alive || !i.active) { continue; }
                        if let Some((tl,tr,tt,tb)) = self.distance_bounds_for_instance(tid) {
                            let dx = (left-tr).max(tl-right).max(0.0) as i32;
                            let dy = (top-tb).max(tt-bottom).max(0.0) as i32;
                            // Original ARM integer mul/mla followed by sqrtf;
                            // promote the resulting f32 to the numeric RValue.
                            let squared = dx.wrapping_mul(dx).wrapping_add(dy.wrapping_mul(dy));
                            let d = (squared as f32).sqrt() as f64;
                            if d < min_dist { min_dist = d; }
                        }
                    }
                }
                Ok(min_dist)
            }
            "place_meeting" => {
                let hit = match self.call(b, id, "instance_place", &[a[0], a[1], a[2]]) {
                    Ok(tid) => tid > 0.0,
                    Err(_) => false,
                };
                Ok(if hit { 1.0 } else { 0.0 })
            }
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
            "draw_text_color" => {
                let x = a[0]; let y = a[1];
                let text = self.arg_text(b, a[2]);
                let color = int(a[3])?;
                let alpha = a[7];
                self.texts.push(TextCommand {
                    code: self.site.0, offset: self.site.1, instance: id, view: self.view,
                    x, y, text, color, alpha,
                    font: self.current_font as i32,
                });
                Ok(0.0)
            }
            "draw_background" => {
                let background = int(a[0])?;
                let x = a[1];
                let y = a[2];
                self.backgrounds.push(BackgroundCommand {
                    code: self.site.0,
                    offset: self.site.1,
                    instance: id,
                    view: self.view,
                    background,
                    x,
                    y,
                    scale_x: 1.0,
                    scale_y: 1.0,
                    rotation: 0.0,
                    color: -1,
                    alpha: self.draw_alpha,
                });
                Ok(0.0)
            }
            "draw_background_ext" => {
                let background = int(a[0])?;
                let x = a[1];
                let y = a[2];
                let scale_x = a[3];
                let scale_y = a[4];
                let rotation = a[5];
                let color = int(a[6])?;
                let alpha = a[7];
                self.backgrounds.push(BackgroundCommand {
                    code: self.site.0,
                    offset: self.site.1,
                    instance: id,
                    view: self.view,
                    background,
                    x,
                    y,
                    scale_x,
                    scale_y,
                    rotation,
                    color,
                    alpha,
                });
                Ok(0.0)
            }
            "ds_map_create" => {
                let mid = self.next_ds_map_id;
                self.next_ds_map_id += 1;
                self.ds_maps.insert(mid, BTreeMap::new());
                Ok(mid as f64)
            }
            "ds_map_destroy" => {
                if !a.is_empty() {
                    let mid = int(a[0])?;
                    self.ds_maps.remove(&mid);
                }
                Ok(0.0)
            }
            "ds_map_replace" => {
                if a.len() >= 3 {
                    let mid = int(a[0])?;
                    let key = self.arg_text(b, a[1]);
                    let val = a[2];
                    self.ds_maps.entry(mid).or_default().insert(key, val);
                }
                Ok(0.0)
            }
            "ds_map_find_value" => {
                if a.len() >= 2 {
                    let mid = int(a[0])?;
                    let key = self.arg_text(b, a[1]);
                    let val = self.ds_maps.get(&mid).and_then(|m| m.get(&key)).copied().unwrap_or(0.0);
                    Ok(val)
                } else {
                    Ok(0.0)
                }
            }
            // Original writes savefile.ini via ds_map_secure_save; the IR
            // save path persists through ini_data instead (Room End CODE 15).
            "ds_map_secure_save" => Ok(1.0),
            "part_system_create" => {
                let id_sys = self.next_particle_system_id;
                self.next_particle_system_id += 1.0;
                self.particle_systems.push(id_sys);
                Ok(id_sys)
            }
            "part_type_create" => {
                let id_ty = self.next_particle_type_id;
                self.next_particle_type_id += 1.0;
                self.particle_types.push((id_ty, ParticleType::default()));
                Ok(id_ty)
            }
            "part_type_size" => {
                let t = self.particle_type_mut(a[0])?;
                t.size_min = a[1]; t.size_max = a[2]; t.size_delta = a[3];
                Ok(0.0)
            }
            "part_type_speed" => {
                let t = self.particle_type_mut(a[0])?;
                t.speed_min = a[1]; t.speed_max = a[2]; t.speed_delta = a[3];
                Ok(0.0)
            }
            "part_type_direction" => {
                let t = self.particle_type_mut(a[0])?;
                t.dir_min = a[1]; t.dir_max = a[2]; t.dir_delta = a[3];
                Ok(0.0)
            }
            "part_type_gravity" => {
                let t = self.particle_type_mut(a[0])?;
                t.grav_amount = a[1]; t.grav_dir = a[2];
                Ok(0.0)
            }
            "part_type_life" => {
                let t = self.particle_type_mut(a[0])?;
                t.life_min = a[1]; t.life_max = a[2];
                Ok(0.0)
            }
            "part_type_color2" => {
                let t = self.particle_type_mut(a[0])?;
                t.color_min = int(a[1])?; t.color_max = int(a[2])?;
                Ok(0.0)
            }
            "part_type_alpha1" => {
                let t = self.particle_type_mut(a[0])?;
                t.alpha = a[1];
                Ok(0.0)
            }
            "part_type_shape" | "part_type_orientation" => Ok(0.0), // shape id / draw angle carry no pixel evidence here
            "part_particles_create" => {
                let sys = a[0];
                let px = a[1]; let py = a[2];
                let ty = a[3];
                let number = int(a[4])?;
                if !self.particle_systems.contains(&sys) {
                    return Err(format!("part_particles_create: unknown particle system {sys}"));
                }
                let t = self.particle_type(ty)?.clone();
                for _ in 0..number {
                    let dir = rand_range(&mut self.rng_seed, t.dir_min, t.dir_max);
                    let spd = rand_range(&mut self.rng_seed, t.speed_min, t.speed_max);
                    let rad = dir * std::f64::consts::PI / 180.0;
                    let life = rand_range(&mut self.rng_seed, t.life_min, t.life_max);
                    self.particles.push(Particle {
                        type_id: ty,
                        x: px, y: py,
                        vx: spd * rad.cos(),
                        vy: -spd * rad.sin(),
                        size: rand_range(&mut self.rng_seed, t.size_min, t.size_max),
                        life,
                        life0: life,
                        // part_type_color2: color blends color_min -> color_max
                        // over the lifetime; at spawn progress is 0.
                        color: t.color_min,
                        color_min: t.color_min,
                        color_max: t.color_max,
                        alpha: t.alpha,
                    });
                }
                Ok(0.0)
            }
            "d3d_set_fog" => {
                let enable = a[0] >= 0.5;
                self.fog_enabled = enable;
                if enable {
                    self.fog_color = int(a[1])?;
                }
                Ok(0.0)
            }
            // Ad/IAP platform domain: original calls AdColony/IAP SDKs that
            // have no equivalent in this client; ads are already disabled.
            | "AdColony_ShowVideo" | "ads_disable"
            | "shop_leave_rating"
            | "iap_purchase_details" | "iap_acquire" => Ok(0.0),
            "collision_line" => {
                let x1 = a[0]; let y1 = a[1]; let x2 = a[2]; let y2 = a[3];
                let s = int(a[4])?;
                // a[5] is `prec` (per-pixel mask test) and a[6] is `notme`.
                // With prec=1 and SPRT mask data the line walks the target's
                // collision bitmap; without mask data (fixture-wired sprites)
                // it falls back to the bounding box.
                let prec = a[5] >= 0.5;
                let notme = a[6] >= 0.5;
                let targets = self.select(id, s)?;
                let mut hit = -4.0;
                for tid in targets {
                    if tid == id && notme { continue; }
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
                    if !line_intersects_box(x1, y1, x2, y2, min_x, max_x, min_y, max_y) {
                        continue;
                    }
                    let passes = if prec {
                        match self.line_mask_hit(tid, x1, y1, x2, y2) {
                            Some(m) => m,
                            // A sprite with no masks behaves as bbox-solid; a
                            // mask-less fixture wiring must not flip results.
                            None => true,
                        }
                    } else {
                        true
                    };
                    if passes {
                        hit = tid as f64;
                        break;
                    }
                }
                Ok(hit)
            }
            "mp_potential_step" => {
                let target_x = a[0]; let target_y = a[1]; let step_size = a[2];
                let check_all = a.get(3).copied().unwrap_or(0.0) >= 0.5;
                let ix = self.self_field(id, "x").unwrap_or(0.0);
                let iy = self.self_field(id, "y").unwrap_or(0.0);
                let spr = self.self_field(id, "sprite_index").unwrap_or(-1.0) as i32;
                let (w, h, ox, oy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                let sx = self.self_field(id, "image_xscale").unwrap_or(1.0);
                let sy = self.self_field(id, "image_yscale").unwrap_or(1.0);

                let base_dir = (-(target_y - iy)).atan2(target_x - ix) * 180.0 / std::f64::consts::PI;
                let base_dir = if base_dir < 0.0 { base_dir + 360.0 } else { base_dir };

                // Angle test order: 0, +10, -10, +20, -20, ..., +90, -90
                let mut chosen = None;
                for step_deg in 0..=9 {
                    for sign in [1.0, -1.0] {
                        let delta = (step_deg as f64) * 10.0 * sign;
                        let cand_dir = (base_dir + delta).rem_euclid(360.0);
                        let rad = cand_dir * std::f64::consts::PI / 180.0;
                        let nx = ix + step_size * rad.cos();
                        let ny = iy - step_size * rad.sin();

                        // Candidate bounding box
                        let bx0 = nx - ox * sx; let by0 = ny - oy * sy;
                        let bx1 = bx0 + w * sx; let by1 = by0 + h * sy;
                        let (b_min_x, b_max_x) = if bx0 < bx1 { (bx0, bx1) } else { (bx1, bx0) };
                        let (b_min_y, b_max_y) = if by0 < by1 { (by0, by1) } else { (by1, by0) };

                        // Check collision with solid instances (par_wall = 34)
                        let mut collides = false;
                        for (&tid, inst) in &self.instances {
                            if tid == id || !inst.alive || !inst.active { continue; }
                            let is_solid = if check_all {
                                true
                            } else {
                                inst.object == 34 || self.object_parents.get(&inst.object).map_or(false, |c| c.contains(&34))
                            };
                            if !is_solid { continue; }

                            let ox_pos = inst.fields.get("x").copied().unwrap_or(0.0);
                            let oy_pos = inst.fields.get("y").copied().unwrap_or(0.0);
                            let ospr = inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
                            let (ow, oh, oox, ooy) = self.sprite_bounds.get(&ospr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
                            let osx = inst.fields.get("image_xscale").copied().unwrap_or(1.0);
                            let osy = inst.fields.get("image_yscale").copied().unwrap_or(1.0);
                            let obx0 = ox_pos - oox * osx; let oby0 = oy_pos - ooy * osy;
                            let obx1 = obx0 + ow * osx; let oby1 = oby0 + oh * osy;
                            let (o_min_x, o_max_x) = if obx0 < obx1 { (obx0, obx1) } else { (obx1, obx0) };
                            let (o_min_y, o_max_y) = if oby0 < oby1 { (oby0, oby1) } else { (oby1, oby0) };

                            if b_min_x < o_max_x && b_max_x > o_min_x && b_min_y < o_max_y && b_max_y > o_min_y {
                                collides = true;
                                break;
                            }
                        }

                        if !collides {
                            chosen = Some((nx, ny, cand_dir));
                            break;
                        }
                        if step_deg == 0 { break; } // don't repeat delta=0 for both signs
                    }
                    if chosen.is_some() { break; }
                }

                if let Some((nx, ny, cand_dir)) = chosen {
                    if let Some(i) = self.instances.get_mut(&id) {
                        i.fields.insert("x".into(), nx);
                        i.fields.insert("y".into(), ny);
                        i.fields.insert("direction".into(), cand_dir);
                        i.fields.insert("speed".into(), step_size);
                    }
                    let dist_sq = (nx - target_x).powi(2) + (ny - target_y).powi(2);
                    Ok(if dist_sq <= step_size.powi(2) { 1.0 } else { 0.0 })
                } else {
                    if let Some(i) = self.instances.get_mut(&id) {
                        i.fields.insert("speed".into(), 0.0);
                    }
                    Ok(0.0)
                }
            }
            "object_exists" => {
                let obj_id = int(a[0])?;
                Ok(if self.call_object_exists(obj_id as f64) { 1.0 } else { 0.0 })
            }
            "random" => {
                let r = next_rand(&mut self.rng_seed);
                Ok(r * a[0])
            }
            "string_format" => {
                // GMS string_format(val, tot, dec): `dec` decimals, padded to
                // `tot` places. The shipped call site renders a 2-digit coin
                // deduction with dec=0, where the pad branch never engages.
                let tot = int(a.get(1).copied().unwrap_or(0.0))?.max(0) as usize;
                let dec = int(a.get(2).copied().unwrap_or(0.0))?.max(0) as usize;
                let text = if pool_index(a[0]).is_some() {
                    self.arg_text(b, a[0])
                } else {
                    format!("{:.*}", dec, a[0])
                };
                Ok(self.alloc_string(b, pad_left(&text, tot)))
            }
            "string_digits" => {
                // GMS strips everything that is not a digit.
                let text: String = self.arg_text(b, a[0]).chars().filter(|c| c.is_ascii_digit()).collect();
                Ok(self.alloc_string(b, text))
            }
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
