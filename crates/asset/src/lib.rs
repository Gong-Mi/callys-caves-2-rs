use std::collections::HashMap;
use std::fs::File;
use std::io::{Read, Seek, SeekFrom};
use std::path::Path;
use byteorder::{LittleEndian, ReadBytesExt};
use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct RoomObjectInstance {
    pub x: i32,
    pub y: i32,
    pub object_id: i32,
    pub instance_id: i32,
    pub creation_code_id: i32,
    pub scale_x: f32,
    pub scale_y: f32,
    pub color: u32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct RoomTileInstance {
    pub x: i32,
    pub y: i32,
    pub bg_id: i32,
    pub src_x: i32,
    pub src_y: i32,
    pub width: i32,
    pub height: i32,
    pub depth: i32,
    pub id: i32,
    pub scale_x: f32,
    pub scale_y: f32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct RoomData {
    pub name: String,
    pub caption: String,
    pub width: u32,
    pub height: u32,
    pub speed: u32,
    pub persistent: bool,
    pub objects: Vec<RoomObjectInstance>,
    pub tiles: Vec<RoomTileInstance>,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct GameObjectInfo {
    pub id: usize,
    pub name: String,
    pub sprite_id: i32,
    pub visible: bool,
    pub solid: bool,
    pub depth: i32,
    pub persistent: bool,
    pub parent_id: i32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct TpagItem {
    pub x: u16,
    pub y: u16,
    pub w: u16,
    pub h: u16,
    pub rx: i16,
    pub ry: i16,
    pub bw: u16,
    pub bh: u16,
    pub sw: u16,
    pub sh: u16,
    pub tex_id: u16,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SpriteData {
    pub id: usize,
    pub name: String,
    pub width: u32,
    pub height: u32,
    pub origin_x: i32,
    pub origin_y: i32,
    pub tpag_indices: Vec<u32>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub struct WarpTarget {
    pub room_index: usize,
    pub x: i32,
    pub y: i32,
    pub unlocked: bool,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct AudioData {
    /// Stable resource identifier: the entry index in the AUDO pointer table.
    pub id: usize,
    /// Absolute offset of the RIFF header in game.droid.
    pub file_offset: u64,
    /// Complete RIFF/WAVE file, including its 12-byte RIFF header.
    pub wav_bytes: Vec<u8>,
}

pub struct GameDroidAsset {
    pub game_name: String,
    pub string_table: Vec<String>,
    pub object_names: Vec<String>,
    pub objects: Vec<GameObjectInfo>,
    pub rooms: Vec<RoomData>,
    pub sprites: HashMap<usize, SpriteData>,
    pub tpag_items: HashMap<usize, TpagItem>,
    pub warp_targets: HashMap<i32, WarpTarget>,
    pub audio: Vec<AudioData>,
}

fn invalid_data(message: impl Into<String>) -> std::io::Error {
    std::io::Error::new(std::io::ErrorKind::InvalidData, message.into())
}

fn parse_audio_chunk(
    file: &mut File,
    chunk_pos: u64,
    chunk_size: u32,
    file_len: u64,
) -> std::io::Result<Vec<AudioData>> {
    let chunk_end = chunk_pos
        .checked_add(u64::from(chunk_size))
        .ok_or_else(|| invalid_data("AUDO chunk range overflows"))?;
    if chunk_end > file_len || chunk_size < 4 {
        return Err(invalid_data("AUDO chunk is outside the file"));
    }

    file.seek(SeekFrom::Start(chunk_pos))?;
    let count = file.read_u32::<LittleEndian>()?;
    let table_size = u64::from(count)
        .checked_mul(4)
        .and_then(|size| size.checked_add(4))
        .ok_or_else(|| invalid_data("AUDO pointer table size overflows"))?;
    if table_size > u64::from(chunk_size) {
        return Err(invalid_data("AUDO pointer table exceeds chunk bounds"));
    }

    let mut offsets = Vec::with_capacity(count as usize);
    for _ in 0..count {
        offsets.push(file.read_u32::<LittleEndian>()?);
    }

    let records_start = chunk_pos + table_size;
    let mut audio = Vec::with_capacity(count as usize);
    for (id, &raw_offset) in offsets.iter().enumerate() {
        let record_pos = u64::from(raw_offset);
        let wav_pos = record_pos
            .checked_add(4)
            .ok_or_else(|| invalid_data(format!("AUDO entry {id} offset overflows")))?;
        if record_pos < records_start || wav_pos > chunk_end {
            return Err(invalid_data(format!(
                "AUDO entry {id} record is outside chunk bounds"
            )));
        }

        file.seek(SeekFrom::Start(record_pos))?;
        let wav_len = u64::from(file.read_u32::<LittleEndian>()?);
        let wav_end = wav_pos
            .checked_add(wav_len)
            .ok_or_else(|| invalid_data(format!("AUDO entry {id} length overflows")))?;
        if wav_len < 12 || wav_end > chunk_end {
            return Err(invalid_data(format!(
                "AUDO entry {id} WAV exceeds chunk bounds"
            )));
        }
        if offsets.iter().enumerate().any(|(other_id, &other_offset)| {
            other_id != id
                && u64::from(other_offset) >= record_pos
                && u64::from(other_offset) < wav_end
        }) {
            return Err(invalid_data(format!(
                "AUDO entry {id} overlaps another record"
            )));
        }

        let wav_len_usize = usize::try_from(wav_len)
            .map_err(|_| invalid_data(format!("AUDO entry {id} is too large")))?;
        let mut wav_bytes = vec![0; wav_len_usize];
        file.read_exact(&mut wav_bytes)?;
        if &wav_bytes[0..4] != b"RIFF" || &wav_bytes[8..12] != b"WAVE" {
            return Err(invalid_data(format!(
                "AUDO entry {id} is not a RIFF/WAVE file"
            )));
        }
        let riff_payload_len =
            u32::from_le_bytes(wav_bytes[4..8].try_into().expect("four-byte RIFF size"));
        if u64::from(riff_payload_len) + 8 != wav_len {
            return Err(invalid_data(format!(
                "AUDO entry {id} RIFF length does not match its record"
            )));
        }

        audio.push(AudioData {
            id,
            file_offset: wav_pos,
            wav_bytes,
        });
    }
    Ok(audio)
}

fn read_null_string(file: &mut File, offset: u64, max_file_len: u64) -> std::io::Result<String> {
    if offset == 0 || offset >= max_file_len || offset == u32::MAX as u64 {
        return Ok(String::new());
    }
    if file.seek(SeekFrom::Start(offset)).is_err() {
        return Ok(String::new());
    }
    let mut buf = Vec::new();
    let mut b = [0u8; 1];
    while file.read_exact(&mut b).is_ok() {
        if b[0] == 0 || buf.len() > 8192 {
            break;
        }
        buf.push(b[0]);
    }
    Ok(String::from_utf8_lossy(&buf).to_string())
}

impl GameDroidAsset {
    pub fn parse<P: AsRef<Path>>(path: P) -> Result<Self, Box<dyn std::error::Error>> {
        let mut file = File::open(path)?;
        let file_len = file.metadata()?.len();

        let mut form_header = [0u8; 4];
        file.read_exact(&mut form_header)?;
        if &form_header != b"FORM" {
            return Err("Not a valid FORM IFF file".into());
        }

        let form_len = file.read_u32::<LittleEndian>()?;

        let mut chunks: HashMap<String, (u64, u32)> = HashMap::new();
        while file.stream_position()? < (form_len + 8) as u64 {
            let pos = file.stream_position()?;
            let mut name_buf = [0u8; 4];
            if file.read_exact(&mut name_buf).is_err() {
                break;
            }
            let chunk_size = file.read_u32::<LittleEndian>()?;
            let chunk_name = String::from_utf8_lossy(&name_buf).to_string();
            chunks.insert(chunk_name, (pos + 8, chunk_size));
            let padded_size = (chunk_size + 3) & !3;
            file.seek(SeekFrom::Start(pos + 8 + padded_size as u64))?;
        }

        let audio = match chunks.get("AUDO") {
            Some(&(pos, size)) => parse_audio_chunk(&mut file, pos, size, file_len)?,
            None => Vec::new(),
        };

        // Parse STRG
        let mut strings = Vec::new();
        if let Some(&(pos, _size)) = chunks.get("STRG") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for &off in &offsets {
                if let Ok(s) = read_null_string(&mut file, off as u64, file_len) {
                    strings.push(s);
                }
            }
        }

        // Parse TPAG
        let mut tpag_items = HashMap::new();
        if let Some(&(pos, _size)) = chunks.get("TPAG") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for &off in &offsets {
                if (off as u64) < file_len && file.seek(SeekFrom::Start(off as u64)).is_ok() {
                    let x = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let y = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let w = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let h = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let rx = file.read_i16::<LittleEndian>().unwrap_or(0);
                    let ry = file.read_i16::<LittleEndian>().unwrap_or(0);
                    let bw = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let bh = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let sw = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let sh = file.read_u16::<LittleEndian>().unwrap_or(0);
                    let tex_id = file.read_u16::<LittleEndian>().unwrap_or(0);

                    // SPRT frames contain absolute TPAG record pointers.
                    tpag_items.insert(off as usize, TpagItem {
                        x, y, w, h, rx, ry, bw, bh, sw, sh, tex_id
                    });
                }
            }
        }

        // Parse SPRT
        let mut sprites = HashMap::new();
        if let Some(&(pos, _size)) = chunks.get("SPRT") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for (idx, &off) in offsets.iter().enumerate() {
                let spr_pos = off as u64;
                if spr_pos < file_len && file.seek(SeekFrom::Start(spr_pos)).is_ok() {
                    let name_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let width = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let height = file.read_u32::<LittleEndian>().unwrap_or(0);

                    // bbox (4*i32) + transparent/smooth/preload/bbox mode/smask (5*u32)
                    // = 36 bytes before origin_x/origin_y.
                    let _ = file.seek(SeekFrom::Current(36));
                    let origin_x = file.read_i32::<LittleEndian>().unwrap_or(0);
                    let origin_y = file.read_i32::<LittleEndian>().unwrap_or(0);
                    let tcount = file.read_u32::<LittleEndian>().unwrap_or(0).min(500);

                    let mut tpag_indices = Vec::with_capacity(tcount as usize);
                    for _ in 0..tcount {
                        if let Ok(t_idx) = file.read_u32::<LittleEndian>() {
                            tpag_indices.push(t_idx);
                        }
                    }

                    let sname = read_null_string(&mut file, name_off as u64, file_len)
                        .unwrap_or_else(|_| format!("spr_{}", idx));

                    sprites.insert(idx, SpriteData {
                        id: idx,
                        name: sname,
                        width,
                        height,
                        origin_x,
                        origin_y,
                        tpag_indices,
                    });
                }
            }
        }

        // Parse OBJT
        let mut objects = Vec::new();
        let mut object_names = Vec::new();
        if let Some(&(pos, _size)) = chunks.get("OBJT") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for (idx, &off) in offsets.iter().enumerate() {
                let obj_abs_pos = off as u64;
                if obj_abs_pos >= file_len || file.seek(SeekFrom::Start(obj_abs_pos)).is_err() {
                    continue;
                }
                let name_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                let sprite_id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                let visible = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let solid = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let depth = file.read_i32::<LittleEndian>().unwrap_or(0);
                let persistent = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let parent_id = file.read_i32::<LittleEndian>().unwrap_or(-1);

                let name = read_null_string(&mut file, name_off as u64, file_len)
                    .unwrap_or_else(|_| format!("obj_{}", idx));
                object_names.push(name.clone());
                objects.push(GameObjectInfo {
                    id: idx,
                    name,
                    sprite_id,
                    visible,
                    solid,
                    depth,
                    persistent,
                    parent_id,
                });
            }
        }

        // Parse ROOM
        let mut rooms = Vec::new();
        if let Some(&(pos, _size)) = chunks.get("ROOM") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for (r_idx, &off) in offsets.iter().enumerate() {
                let room_abs_pos = off as u64;
                if room_abs_pos >= file_len || file.seek(SeekFrom::Start(room_abs_pos)).is_err() {
                    continue;
                }
                let name_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                let caption_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                let width = file.read_u32::<LittleEndian>().unwrap_or(0);
                let height = file.read_u32::<LittleEndian>().unwrap_or(0);
                let speed = file.read_u32::<LittleEndian>().unwrap_or(30);
                let persistent = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;

                let room_name = read_null_string(&mut file, name_off as u64, file_len)
                    .unwrap_or_else(|_| format!("room_{}", r_idx));
                let room_caption = if caption_off != 0 && caption_off != u32::MAX {
                    read_null_string(&mut file, caption_off as u64, file_len).unwrap_or_default()
                } else {
                    String::new()
                };

                if file.seek(SeekFrom::Start(room_abs_pos + 6 * 4)).is_ok() {
                    let _color = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let _show_color = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let _creation_code = file.read_i32::<LittleEndian>().unwrap_or(-1);
                    let _flags = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let _bg_offset = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let _views_offset = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let obj_offset = file.read_u32::<LittleEndian>().unwrap_or(0);
                    let tiles_offset = file.read_u32::<LittleEndian>().unwrap_or(0);

                    let mut room_objs = Vec::new();
                    if obj_offset != 0 && obj_offset != u32::MAX {
                        let obj_list_pos = obj_offset as u64;
                        if obj_list_pos < file_len && file.seek(SeekFrom::Start(obj_list_pos)).is_ok() {
                            if let Ok(raw_count) = file.read_u32::<LittleEndian>() {
                                let obj_count = raw_count.min(5000);
                                let mut inst_offsets = Vec::with_capacity(obj_count as usize);
                                for _ in 0..obj_count {
                                    if let Ok(o) = file.read_u32::<LittleEndian>() {
                                        inst_offsets.push(o);
                                    }
                                }
                                for &inst_off in &inst_offsets {
                                    let inst_abs_pos = inst_off as u64;
                                    if inst_abs_pos >= file_len || file.seek(SeekFrom::Start(inst_abs_pos)).is_err() {
                                        continue;
                                    }
                                    let x = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let y = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let object_id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                                    let instance_id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                                    let creation_code_id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                                    let scale_x = file.read_f32::<LittleEndian>().unwrap_or(1.0);
                                    let scale_y = file.read_f32::<LittleEndian>().unwrap_or(1.0);
                                    let color = file.read_u32::<LittleEndian>().unwrap_or(0xFFFFFFFF);
                                    room_objs.push(RoomObjectInstance {
                                        x, y, object_id, instance_id, creation_code_id, scale_x, scale_y, color
                                    });
                                }
                            }
                        }
                    }

                    let mut room_tiles = Vec::new();
                    if tiles_offset != 0 && tiles_offset != u32::MAX {
                        let tile_list_pos = tiles_offset as u64;
                        if tile_list_pos < file_len && file.seek(SeekFrom::Start(tile_list_pos)).is_ok() {
                            if let Ok(raw_count) = file.read_u32::<LittleEndian>() {
                                let tile_count = raw_count.min(10000);
                                let mut tile_offsets = Vec::with_capacity(tile_count as usize);
                                for _ in 0..tile_count {
                                    if let Ok(o) = file.read_u32::<LittleEndian>() {
                                        tile_offsets.push(o);
                                    }
                                }
                                for &tile_off in &tile_offsets {
                                    let tile_abs_pos = tile_off as u64;
                                    if tile_abs_pos >= file_len || file.seek(SeekFrom::Start(tile_abs_pos)).is_err() {
                                        continue;
                                    }
                                    let x = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let y = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let bg_id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                                    let src_x = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let src_y = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let width = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let height = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let depth = file.read_i32::<LittleEndian>().unwrap_or(0);
                                    let id = file.read_i32::<LittleEndian>().unwrap_or(-1);
                                    let scale_x = file.read_f32::<LittleEndian>().unwrap_or(1.0);
                                    let scale_y = file.read_f32::<LittleEndian>().unwrap_or(1.0);
                                    room_tiles.push(RoomTileInstance {
                                        x, y, bg_id, src_x, src_y, width, height, depth, id, scale_x, scale_y
                                    });
                                }
                            }
                        }
                    }

                    rooms.push(RoomData {
                        name: room_name,
                        caption: room_caption,
                        width,
                        height,
                        speed,
                        persistent,
                        objects: room_objs,
                        tiles: room_tiles,
                    });
                }
            }
        }

        // Room creation code stores compact 12-byte assignments for the
        // destination room, spawn x/y and optional unlocked flag.
        let mut warp_targets = HashMap::new();
        if let Some(&(pos, _size)) = chunks.get("CODE") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for (code_id, &off) in offsets.iter().enumerate() {
                if off as u64 + 20 > file_len || file.seek(SeekFrom::Start(off as u64)).is_err() {
                    continue;
                }
                let name_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                let length = file.read_u32::<LittleEndian>().unwrap_or(0);
                let _locals = file.read_u32::<LittleEndian>().unwrap_or(0);
                let relative = file.read_i32::<LittleEndian>().unwrap_or(0);
                let _unknown = file.read_u32::<LittleEndian>().unwrap_or(0);
                let name = read_null_string(&mut file, name_off as u64, file_len).unwrap_or_default();
                if !name.starts_with("gml_RoomCC_") || !(36..=48).contains(&length) || length % 12 != 0 {
                    continue;
                }
                let bytecode_pos = off as i64 + 12 + relative as i64;
                if bytecode_pos < 0 || bytecode_pos as u64 + length as u64 > file_len {
                    continue;
                }
                file.seek(SeekFrom::Start(bytecode_pos as u64))?;
                let mut code = vec![0u8; length as usize];
                file.read_exact(&mut code)?;
                let mut values = Vec::new();
                for instruction in code.chunks_exact(12) {
                    if instruction[2] != 0x0f || instruction[3] != 0x84 {
                        values.clear();
                        break;
                    }
                    values.push(i16::from_le_bytes([instruction[0], instruction[1]]) as i32);
                }
                if values.len() >= 3 && values[0] >= 0 && (values[0] as usize) < rooms.len() {
                    warp_targets.insert(code_id as i32, WarpTarget {
                        room_index: values[0] as usize,
                        x: values[1],
                        y: values[2],
                        unlocked: values.get(3).copied() == Some(1),
                    });
                }
            }
        }

        Ok(Self {
            game_name: strings.first().cloned().unwrap_or_else(|| "CallysCaves2".into()),
            string_table: strings,
            object_names,
            objects,
            rooms,
            sprites,
            tpag_items,
            warp_targets,
            audio,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::Write;

    #[test]
    fn test_audio_records_cannot_overlap() {
        let path = std::env::temp_dir().join(format!(
            "callys-asset-audo-overlap-{}",
            std::process::id()
        ));
        let mut bytes = vec![0u8; 64];
        bytes[0..4].copy_from_slice(&2u32.to_le_bytes());
        bytes[4..8].copy_from_slice(&12u32.to_le_bytes());
        bytes[8..12].copy_from_slice(&28u32.to_le_bytes());
        bytes[12..16].copy_from_slice(&24u32.to_le_bytes());
        bytes[16..20].copy_from_slice(b"RIFF");
        bytes[20..24].copy_from_slice(&16u32.to_le_bytes());
        bytes[24..28].copy_from_slice(b"WAVE");
        bytes[28..32].copy_from_slice(&12u32.to_le_bytes());
        bytes[32..36].copy_from_slice(b"RIFF");
        bytes[36..40].copy_from_slice(&4u32.to_le_bytes());
        bytes[40..44].copy_from_slice(b"WAVE");

        let mut file = File::create(&path).expect("create malformed AUDO fixture");
        file.write_all(&bytes).expect("write malformed AUDO fixture");
        drop(file);
        let mut file = File::open(&path).expect("open malformed AUDO fixture");
        let error = parse_audio_chunk(&mut file, 0, bytes.len() as u32, bytes.len() as u64)
            .expect_err("overlapping AUDO records must be rejected");
        std::fs::remove_file(path).expect("remove malformed AUDO fixture");
        assert!(error.to_string().contains("overlaps"), "{error}");
    }

    #[test]
    fn test_parse_game_droid() {
        // Try multiple candidate paths so the test works on both local Termux
        // and on CI runners (which don't have the original APK).
        let candidates = [
            "assets/game.droid",
            "../../assets/game.droid",
            "/data/data/com.termux/files/usr/tmp/cally_caves_2/apk/assets/game.droid",
            "test_assets/game.droid",
            "../test_assets/game.droid",
            "../../test_assets/game.droid",
            "../../../test_assets/game.droid",
        ];
        let mut found = None;
        for path in &candidates {
            if std::path::Path::new(path).exists() {
                found = Some(*path);
                break;
            }
        }
        let path = match found {
            Some(p) => p,
            None => {
                eprintln!("Skipping test_parse_game_droid: no game.droid found in candidate paths.");
                eprintln!("Candidates: {:?}", candidates);
                return;
            }
        };
        let asset = GameDroidAsset::parse(path).expect("Failed to parse game.droid");
        assert_eq!(asset.rooms.len(), 114);
        assert_eq!(asset.rooms[0].name, "rm_town");
        assert_eq!(asset.rooms[1].name, "rm_level1");
        assert!(!asset.objects.is_empty());
        assert!(!asset.sprites.is_empty());
        assert!(!asset.tpag_items.is_empty());
        assert_eq!(asset.audio.len(), 29);
        for (expected_id, audio) in asset.audio.iter().enumerate() {
            assert_eq!(audio.id, expected_id);
            assert_eq!(&audio.wav_bytes[0..4], b"RIFF");
            assert_eq!(&audio.wav_bytes[8..12], b"WAVE");
            let riff_payload_len = u32::from_le_bytes(
                audio.wav_bytes[4..8].try_into().expect("RIFF size field"),
            ) as usize;
            assert_eq!(riff_payload_len + 8, audio.wav_bytes.len());
        }
        assert_eq!(asset.rooms[0].objects.len(), 170);
        assert_eq!(
            asset.warp_targets.get(&804),
            Some(&WarpTarget { room_index: 1, x: 128, y: 492, unlocked: true }),
        );
        assert_eq!(
            asset.warp_targets.get(&806),
            Some(&WarpTarget { room_index: 0, x: 832, y: 480, unlocked: true }),
        );
        for sprite in asset.sprites.values() {
            for frame_ptr in &sprite.tpag_indices {
                assert!(
                    asset.tpag_items.contains_key(&(*frame_ptr as usize)),
                    "sprite {} references missing TPAG pointer {}",
                    sprite.name,
                    frame_ptr
                );
            }
        }
        println!(
            "Test passed! Rooms={}, Objects={}, Sprites={}, TPAG={}",
            asset.rooms.len(),
            asset.objects.len(),
            asset.sprites.len(),
            asset.tpag_items.len()
        );
    }
}
