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
    /// Directly defined events only. Parent events are not copied here.
    pub events: Vec<ObjectEvent>,
    /// Physics fields whose gameplay meaning is not used by this fact layer.
    pub physics_raw: ObjectPhysicsRaw,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct ObjectPhysicsRaw {
    pub enabled: u32,
    pub sensor: u32,
    pub collision_shape: u32,
    pub density_bits: u32,
    pub restitution_bits: u32,
    pub group: u32,
    pub linear_damping_bits: u32,
    pub angular_damping_bits: u32,
    pub vertices: Vec<[u32; 2]>,
    pub friction_bits: u32,
    pub awake: u32,
    pub kinematic: u32,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct ObjectEvent {
    /// Raw GMS event category index from the object's event-list table.
    pub event_type: u32,
    /// Raw subtype stored in the event record (alarm index, collision object ID, etc.).
    pub subtype: i32,
    /// Actions in the exact order of the event's action pointer table.
    pub actions: Vec<ObjectAction>,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct ObjectAction {
    pub order: usize,
    pub library_id: u32,
    pub action_id: u32,
    pub kind: u32,
    pub use_relative_raw: u32,
    pub is_question_raw: u32,
    pub use_apply_to_raw: u32,
    pub execution_type: u32,
    pub function_name: String,
    /// Direct CODE resource index stored at action-record +0x20.
    pub code_id: i32,
    pub code_name: Option<String>,
    pub argument_count: u32,
    pub who: i32,
    pub relative_raw: u32,
    pub is_not_raw: u32,
    /// Final action word; meaning remains unknown for this game.droid format.
    pub unknown_raw: u32,
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
pub enum WarpAuditStatus {
    Decoded(WarpTarget),
    SpecialDynamic { reason: String },
    Unresolved { reason: String },
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct WarpAudit {
    pub source_room_index: usize,
    pub source_room_name: String,
    pub instance_id: i32,
    pub creation_code_id: i32,
    pub creation_code_name: String,
    pub status: WarpAuditStatus,
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

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct SoundData {
    /// Stable resource identifier: the entry index in the SOND pointer table.
    pub id: usize,
    /// Resource name read through the name pointer encoded in the SOND record.
    pub name: String,
    /// AUDO entry identifier encoded in the final word of the SOND record.
    pub audio_id: usize,
}

pub struct GameDroidAsset {
    pub game_name: String,
    pub string_table: Vec<String>,
    pub object_names: Vec<String>,
    pub objects: Vec<GameObjectInfo>,
    pub rooms: Vec<RoomData>,
    pub sprites: HashMap<usize, SpriteData>,
    pub backgrounds: HashMap<usize, BackgroundData>,
    pub tpag_items: HashMap<usize, TpagItem>,
    pub warp_targets: HashMap<i32, WarpTarget>,
    pub warp_audits: Vec<WarpAudit>,
    pub audio: Vec<AudioData>,
    pub sounds: Vec<SoundData>,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct BackgroundData {
    pub id: usize,
    pub name: String,
    pub transparent: bool,
    pub smooth: bool,
    pub preload: bool,
    pub tpag_ptr: usize,
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

fn read_required_null_string(
    file: &mut File,
    offset: u64,
    file_len: u64,
    context: &str,
) -> std::io::Result<String> {
    if offset == 0 || offset == u64::from(u32::MAX) || offset >= file_len {
        return Err(invalid_data(format!("{context} string pointer is outside the file")));
    }
    file.seek(SeekFrom::Start(offset))?;
    let mut bytes = Vec::new();
    loop {
        if file.stream_position()? >= file_len || bytes.len() >= 8192 {
            return Err(invalid_data(format!("{context} string is not terminated")));
        }
        let byte = file.read_u8()?;
        if byte == 0 {
            break;
        }
        bytes.push(byte);
    }
    String::from_utf8(bytes).map_err(|_| invalid_data(format!("{context} string is not UTF-8")))
}

fn parse_sound_chunk(
    file: &mut File,
    chunk_pos: u64,
    chunk_size: u32,
    file_len: u64,
    audio_count: usize,
) -> std::io::Result<Vec<SoundData>> {
    const RECORD_SIZE: u64 = 9 * 4;

    let chunk_end = chunk_pos
        .checked_add(u64::from(chunk_size))
        .ok_or_else(|| invalid_data("SOND chunk range overflows"))?;
    if chunk_end > file_len || chunk_size < 4 {
        return Err(invalid_data("SOND chunk is outside the file"));
    }

    file.seek(SeekFrom::Start(chunk_pos))?;
    let count = file.read_u32::<LittleEndian>()?;
    let table_size = u64::from(count)
        .checked_mul(4)
        .and_then(|size| size.checked_add(4))
        .ok_or_else(|| invalid_data("SOND pointer table size overflows"))?;
    if table_size > u64::from(chunk_size) {
        return Err(invalid_data("SOND pointer table exceeds chunk bounds"));
    }

    let mut offsets = Vec::with_capacity(count as usize);
    for _ in 0..count {
        offsets.push(file.read_u32::<LittleEndian>()?);
    }

    let records_start = chunk_pos + table_size;
    let mut sounds = Vec::with_capacity(count as usize);
    for (id, &raw_offset) in offsets.iter().enumerate() {
        let record_pos = u64::from(raw_offset);
        let record_end = record_pos
            .checked_add(RECORD_SIZE)
            .ok_or_else(|| invalid_data(format!("SOND entry {id} offset overflows")))?;
        if record_pos < records_start || record_end > chunk_end {
            return Err(invalid_data(format!(
                "SOND entry {id} record is outside chunk bounds"
            )));
        }
        if offsets.iter().enumerate().any(|(other_id, &other_offset)| {
            other_id != id
                && u64::from(other_offset) >= record_pos
                && u64::from(other_offset) < record_end
        }) {
            return Err(invalid_data(format!(
                "SOND entry {id} overlaps another record"
            )));
        }

        file.seek(SeekFrom::Start(record_pos))?;
        let name_offset = u64::from(file.read_u32::<LittleEndian>()?);
        file.seek(SeekFrom::Current(7 * 4))?;
        let audio_id = file.read_u32::<LittleEndian>()? as usize;
        if audio_id >= audio_count {
            return Err(invalid_data(format!(
                "SOND entry {id} references missing AUDO entry {audio_id}"
            )));
        }
        let name = read_required_null_string(
            file,
            name_offset,
            file_len,
            &format!("SOND entry {id}"),
        )?;
        sounds.push(SoundData { id, name, audio_id });
    }
    Ok(sounds)
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

fn range_inside(start: u64, length: u64, lower: u64, upper: u64) -> bool {
    start >= lower && start.checked_add(length).is_some_and(|end| end <= upper)
}

fn parse_object_chunk(
    file: &mut File,
    chunk_pos: u64,
    chunk_size: u32,
    file_len: u64,
    code_names: &[Option<String>],
) -> std::io::Result<Vec<GameObjectInfo>> {
    const FIXED_HEADER_THROUGH_VERTEX_COUNT: u64 = 17 * 4;
    const ACTION_RECORD_SIZE: u64 = 14 * 4;

    let chunk_end = chunk_pos
        .checked_add(u64::from(chunk_size))
        .ok_or_else(|| invalid_data("OBJT chunk range overflows"))?;
    if chunk_end > file_len || chunk_size < 4 {
        return Err(invalid_data("OBJT chunk is outside the file"));
    }
    file.seek(SeekFrom::Start(chunk_pos))?;
    let count = file.read_u32::<LittleEndian>()?;
    let table_size = u64::from(count)
        .checked_mul(4)
        .and_then(|size| size.checked_add(4))
        .ok_or_else(|| invalid_data("OBJT pointer table size overflows"))?;
    if table_size > u64::from(chunk_size) {
        return Err(invalid_data("OBJT pointer table exceeds chunk bounds"));
    }
    let records_start = chunk_pos + table_size;
    let mut offsets = Vec::with_capacity(count as usize);
    for _ in 0..count {
        offsets.push(u64::from(file.read_u32::<LittleEndian>()?));
    }
    for (id, &record_pos) in offsets.iter().enumerate() {
        if !range_inside(
            record_pos,
            FIXED_HEADER_THROUGH_VERTEX_COUNT,
            records_start,
            chunk_end,
        ) {
            return Err(invalid_data(format!(
                "OBJT entry {id} object record is outside chunk bounds"
            )));
        }
        if id > 0 && record_pos <= offsets[id - 1] {
            return Err(invalid_data("OBJT object pointers are not strictly increasing"));
        }
    }

    let mut objects = Vec::with_capacity(count as usize);
    for (id, &record_pos) in offsets.iter().enumerate() {
        let record_end = offsets.get(id + 1).copied().unwrap_or(chunk_end);
        file.seek(SeekFrom::Start(record_pos))?;
        let name_offset = u64::from(file.read_u32::<LittleEndian>()?);
        let sprite_id = file.read_i32::<LittleEndian>()?;
        let visible = file.read_u32::<LittleEndian>()? != 0;
        let solid = file.read_u32::<LittleEndian>()? != 0;
        let depth = file.read_i32::<LittleEndian>()?;
        let persistent = file.read_u32::<LittleEndian>()? != 0;
        let parent_id = file.read_i32::<LittleEndian>()?;
        let _texture_mask_id = file.read_i32::<LittleEndian>()?;
        let enabled = file.read_u32::<LittleEndian>()?;
        let sensor = file.read_u32::<LittleEndian>()?;
        let collision_shape = file.read_u32::<LittleEndian>()?;
        let density_bits = file.read_u32::<LittleEndian>()?;
        let restitution_bits = file.read_u32::<LittleEndian>()?;
        let group = file.read_u32::<LittleEndian>()?;
        let linear_damping_bits = file.read_u32::<LittleEndian>()?;
        let angular_damping_bits = file.read_u32::<LittleEndian>()?;
        let vertex_count = file.read_u32::<LittleEndian>()?;
        let variable_tail_size = u64::from(vertex_count)
            .checked_mul(8)
            .and_then(|size| size.checked_add(4 * 4))
            .ok_or_else(|| invalid_data(format!("OBJT entry {id} vertex table overflows")))?;
        let variable_tail_pos = record_pos + FIXED_HEADER_THROUGH_VERTEX_COUNT;
        if !range_inside(variable_tail_pos, variable_tail_size, record_pos, record_end) {
            return Err(invalid_data(format!(
                "OBJT entry {id} vertex/event header exceeds object bounds"
            )));
        }
        let mut vertices = Vec::with_capacity(vertex_count as usize);
        for _ in 0..vertex_count {
            vertices.push([
                file.read_u32::<LittleEndian>()?,
                file.read_u32::<LittleEndian>()?,
            ]);
        }
        let friction_bits = file.read_u32::<LittleEndian>()?;
        let awake = file.read_u32::<LittleEndian>()?;
        let kinematic = file.read_u32::<LittleEndian>()?;
        let event_type_count = file.read_u32::<LittleEndian>()?;
        let event_pointer_table_pos = file.stream_position()?;
        let event_pointer_table_size = u64::from(event_type_count)
            .checked_mul(4)
            .ok_or_else(|| invalid_data(format!("OBJT entry {id} event table overflows")))?;
        if !range_inside(
            event_pointer_table_pos,
            event_pointer_table_size,
            record_pos,
            record_end,
        ) {
            return Err(invalid_data(format!(
                "OBJT entry {id} event pointer table exceeds object bounds"
            )));
        }
        let mut event_list_offsets = Vec::with_capacity(event_type_count as usize);
        for _ in 0..event_type_count {
            event_list_offsets.push(u64::from(file.read_u32::<LittleEndian>()?));
        }
        let object_data_start = event_pointer_table_pos + event_pointer_table_size;
        let mut events = Vec::new();
        for (event_type, event_list_pos) in event_list_offsets.into_iter().enumerate() {
            if !range_inside(event_list_pos, 4, object_data_start, record_end) {
                return Err(invalid_data(format!(
                    "OBJT entry {id} event list is outside object bounds"
                )));
            }
            file.seek(SeekFrom::Start(event_list_pos))?;
            let event_count = file.read_u32::<LittleEndian>()?;
            let event_table_size = u64::from(event_count)
                .checked_mul(4)
                .ok_or_else(|| invalid_data(format!("OBJT entry {id} event list overflows")))?;
            if !range_inside(event_list_pos + 4, event_table_size, event_list_pos, record_end) {
                return Err(invalid_data(format!(
                    "OBJT entry {id} event pointer table exceeds object bounds"
                )));
            }
            let mut event_offsets = Vec::with_capacity(event_count as usize);
            for _ in 0..event_count {
                event_offsets.push(u64::from(file.read_u32::<LittleEndian>()?));
            }
            let event_records_start = event_list_pos + 4 + event_table_size;
            for event_pos in event_offsets {
                if !range_inside(event_pos, 8, event_records_start, record_end) {
                    return Err(invalid_data(format!(
                        "OBJT entry {id} event record is outside object bounds"
                    )));
                }
                file.seek(SeekFrom::Start(event_pos))?;
                let subtype = file.read_i32::<LittleEndian>()?;
                let action_count = file.read_u32::<LittleEndian>()?;
                let action_table_size = u64::from(action_count)
                    .checked_mul(4)
                    .ok_or_else(|| invalid_data(format!("OBJT entry {id} action table overflows")))?;
                if !range_inside(event_pos + 8, action_table_size, event_pos, record_end) {
                    return Err(invalid_data(format!(
                        "OBJT entry {id} action pointer table exceeds object bounds"
                    )));
                }
                let mut action_offsets = Vec::with_capacity(action_count as usize);
                for _ in 0..action_count {
                    action_offsets.push(u64::from(file.read_u32::<LittleEndian>()?));
                }
                let action_records_start = event_pos + 8 + action_table_size;
                let mut actions = Vec::with_capacity(action_count as usize);
                for (order, action_pos) in action_offsets.into_iter().enumerate() {
                    if !range_inside(
                        action_pos,
                        ACTION_RECORD_SIZE,
                        action_records_start,
                        record_end,
                    ) {
                        return Err(invalid_data(format!(
                            "OBJT entry {id} action record is outside object bounds"
                        )));
                    }
                    file.seek(SeekFrom::Start(action_pos))?;
                    let library_id = file.read_u32::<LittleEndian>()?;
                    let action_id = file.read_u32::<LittleEndian>()?;
                    let kind = file.read_u32::<LittleEndian>()?;
                    let use_relative_raw = file.read_u32::<LittleEndian>()?;
                    let is_question_raw = file.read_u32::<LittleEndian>()?;
                    let use_apply_to_raw = file.read_u32::<LittleEndian>()?;
                    let execution_type = file.read_u32::<LittleEndian>()?;
                    let function_name_offset = u64::from(file.read_u32::<LittleEndian>()?);
                    let code_id = file.read_i32::<LittleEndian>()?;
                    let argument_count = file.read_u32::<LittleEndian>()?;
                    let who = file.read_i32::<LittleEndian>()?;
                    let relative_raw = file.read_u32::<LittleEndian>()?;
                    let is_not_raw = file.read_u32::<LittleEndian>()?;
                    let unknown_raw = file.read_u32::<LittleEndian>()?;
                    let function_name = read_required_null_string(
                        file,
                        function_name_offset,
                        file_len,
                        &format!("OBJT entry {id} action {order}"),
                    )?;
                    let code_name = if code_id == -1 {
                        None
                    } else {
                        let code_index = usize::try_from(code_id).map_err(|_| {
                            invalid_data(format!(
                                "OBJT entry {id} action {order} references invalid CODE entry {code_id}"
                            ))
                        })?;
                        Some(
                            code_names
                                .get(code_index)
                                .and_then(|name| name.clone())
                                .ok_or_else(|| {
                                    invalid_data(format!(
                                        "OBJT entry {id} action {order} references missing CODE entry {code_id}"
                                    ))
                                })?,
                        )
                    };
                    actions.push(ObjectAction {
                        order,
                        library_id,
                        action_id,
                        kind,
                        use_relative_raw,
                        is_question_raw,
                        use_apply_to_raw,
                        execution_type,
                        function_name,
                        code_id,
                        code_name,
                        argument_count,
                        who,
                        relative_raw,
                        is_not_raw,
                        unknown_raw,
                    });
                }
                events.push(ObjectEvent {
                    event_type: event_type as u32,
                    subtype,
                    actions,
                });
            }
        }
        let name = read_required_null_string(
            file,
            name_offset,
            file_len,
            &format!("OBJT entry {id}"),
        )?;
        objects.push(GameObjectInfo {
            id,
            name,
            sprite_id,
            visible,
            solid,
            depth,
            persistent,
            parent_id,
            events,
            physics_raw: ObjectPhysicsRaw {
                enabled,
                sensor,
                collision_shape,
                density_bits,
                restitution_bits,
                group,
                linear_damping_bits,
                angular_damping_bits,
                vertices,
                friction_bits,
                awake,
                kinematic,
            },
        });
    }
    Ok(objects)
}

#[derive(Debug)]
struct CodeEntry {
    name: String,
    bytecode_pos: u64,
    bytecode: Vec<u8>,
}

fn parse_code_entries(
    file: &mut File,
    chunk_pos: u64,
    chunk_size: u32,
    file_len: u64,
) -> std::io::Result<Vec<Result<CodeEntry, String>>> {
    let chunk_end = chunk_pos
        .checked_add(u64::from(chunk_size))
        .ok_or_else(|| invalid_data("CODE chunk range overflows"))?;
    if chunk_end > file_len || chunk_size < 4 {
        return Err(invalid_data("CODE chunk is outside the file"));
    }
    file.seek(SeekFrom::Start(chunk_pos))?;
    let count = file.read_u32::<LittleEndian>()?;
    let table_end = chunk_pos
        .checked_add(4 + u64::from(count) * 4)
        .ok_or_else(|| invalid_data("CODE pointer table overflows"))?;
    if table_end > chunk_end {
        return Err(invalid_data("CODE pointer table exceeds chunk bounds"));
    }
    let mut offsets = Vec::with_capacity(count as usize);
    for _ in 0..count {
        offsets.push(file.read_u32::<LittleEndian>()?);
    }

    let mut entries = Vec::with_capacity(count as usize);
    for (code_id, raw_offset) in offsets.into_iter().enumerate() {
        let record_pos = u64::from(raw_offset);
        if record_pos < table_end || record_pos.checked_add(20).is_none_or(|end| end > chunk_end) {
            entries.push(Err(format!("CODE {code_id} record is outside CODE bounds")));
            continue;
        }
        file.seek(SeekFrom::Start(record_pos))?;
        let name_offset = u64::from(file.read_u32::<LittleEndian>()?);
        let bytecode_length = u64::from(file.read_u32::<LittleEndian>()?);
        let _locals_count = file.read_u32::<LittleEndian>()?;
        let relative_offset = i64::from(file.read_i32::<LittleEndian>()?);
        let _unknown = file.read_u32::<LittleEndian>()?;
        let name = read_null_string(file, name_offset, file_len).unwrap_or_default();
        let Some(bytecode_pos) = (record_pos as i64)
            .checked_add(12)
            .and_then(|pos| pos.checked_add(relative_offset))
            .and_then(|pos| u64::try_from(pos).ok())
        else {
            entries.push(Err(format!("CODE {code_id} bytecode offset overflows")));
            continue;
        };
        if bytecode_pos < chunk_pos
            || bytecode_pos
                .checked_add(bytecode_length)
                .is_none_or(|end| end > chunk_end)
        {
            entries.push(Err(format!("CODE {code_id} bytecode is outside CODE bounds")));
            continue;
        }
        file.seek(SeekFrom::Start(bytecode_pos))?;
        let mut bytecode = vec![0; bytecode_length as usize];
        file.read_exact(&mut bytecode)?;
        entries.push(Ok(CodeEntry {
            name,
            bytecode_pos,
            bytecode,
        }));
    }
    Ok(entries)
}

fn parse_variable_references(
    file: &mut File,
    chunk_pos: u64,
    chunk_size: u32,
    file_len: u64,
) -> std::io::Result<HashMap<u64, String>> {
    const HEADER_SIZE: u64 = 12;
    const RECORD_SIZE: u64 = 20;
    let chunk_end = chunk_pos
        .checked_add(u64::from(chunk_size))
        .ok_or_else(|| invalid_data("VARI chunk range overflows"))?;
    if chunk_end > file_len || u64::from(chunk_size) < HEADER_SIZE {
        return Err(invalid_data("VARI chunk is outside the file"));
    }
    file.seek(SeekFrom::Start(chunk_pos))?;
    let count = file.read_u32::<LittleEndian>()?;
    let _max_variable_count = file.read_u32::<LittleEndian>()?;
    let _locals_count = file.read_u32::<LittleEndian>()?;
    let records_end = chunk_pos
        .checked_add(HEADER_SIZE + u64::from(count) * RECORD_SIZE)
        .ok_or_else(|| invalid_data("VARI records overflow"))?;
    if records_end > chunk_end {
        return Err(invalid_data("VARI records exceed chunk bounds"));
    }

    let mut records = Vec::with_capacity(count as usize);
    for _ in 0..count {
        let name_offset = u64::from(file.read_u32::<LittleEndian>()?);
        let _instance_type = file.read_i32::<LittleEndian>()?;
        let _variable_id = file.read_i32::<LittleEndian>()?;
        let occurrence_count = file.read_u32::<LittleEndian>()?;
        let first_occurrence = u64::from(file.read_u32::<LittleEndian>()?);
        records.push((name_offset, occurrence_count, first_occurrence));
    }

    let mut references = HashMap::new();
    for (name_offset, occurrence_count, mut occurrence_pos) in records {
        let name = read_required_null_string(file, name_offset, file_len, "VARI")?;
        for occurrence_index in 0..occurrence_count {
            let reference_pos = occurrence_pos
                .checked_add(4)
                .ok_or_else(|| invalid_data(format!("VARI {name} occurrence overflows")))?;
            if reference_pos.checked_add(4).is_none_or(|end| end > file_len) {
                return Err(invalid_data(format!(
                    "VARI {name} occurrence is outside the file"
                )));
            }
            if let Some(previous) = references.insert(occurrence_pos, name.clone()) {
                if previous != name {
                    return Err(invalid_data(format!(
                        "VARI occurrence belongs to both {previous} and {name}"
                    )));
                }
            }
            if occurrence_index + 1 < occurrence_count {
                file.seek(SeekFrom::Start(reference_pos))?;
                let raw_delta = file.read_u32::<LittleEndian>()? & 0x00ff_ffff;
                let signed_delta = if raw_delta & 0x0080_0000 != 0 {
                    i64::from(raw_delta) - (1_i64 << 24)
                } else {
                    i64::from(raw_delta)
                };
                if signed_delta == 0 {
                    return Err(invalid_data(format!(
                        "VARI {name} occurrence chain has a zero delta"
                    )));
                }
                occurrence_pos = u64::try_from(occurrence_pos as i64 + signed_delta)
                    .map_err(|_| invalid_data(format!("VARI {name} occurrence underflows")))?;
            }
        }
    }
    Ok(references)
}

fn classify_warp_code(
    code_id: i32,
    code_entries: &[Result<CodeEntry, String>],
    variable_references: &HashMap<u64, String>,
    room_count: usize,
) -> (String, WarpAuditStatus) {
    let Some(entry) = usize::try_from(code_id)
        .ok()
        .and_then(|index| code_entries.get(index))
    else {
        return (
            String::new(),
            WarpAuditStatus::Unresolved {
                reason: format!("creation code ID {code_id} is outside CODE"),
            },
        );
    };
    let entry = match entry {
        Ok(entry) => entry,
        Err(reason) => {
            return (
                String::new(),
                WarpAuditStatus::Unresolved {
                    reason: reason.clone(),
                },
            )
        }
    };
    if !entry.name.starts_with("gml_RoomCC_") {
        return (
            entry.name.clone(),
            WarpAuditStatus::Unresolved {
                reason: "creation code is not a gml_RoomCC entry".into(),
            },
        );
    }

    let mut referenced_variables = Vec::new();
    for instruction_offset in (4..entry.bytecode.len()).step_by(4) {
        if let Some(name) = variable_references.get(&(entry.bytecode_pos + instruction_offset as u64)) {
            referenced_variables.push(name.as_str());
        }
    }
    let expected_variable = |name: &&str| matches!(*name, "warproom" | "warpx" | "warpy" | "unlocked");
    let has_warp_variables = referenced_variables.iter().any(expected_variable);

    if !matches!(entry.bytecode.len(), 36 | 48) || entry.bytecode.len() % 12 != 0 {
        let reason = format!(
            "RoomCC has {} byte(s), not the static 3/4-assignment shape",
            entry.bytecode.len()
        );
        return (
            entry.name.clone(),
            if has_warp_variables {
                WarpAuditStatus::SpecialDynamic { reason }
            } else {
                WarpAuditStatus::Unresolved { reason }
            },
        );
    }

    let expected_names = if entry.bytecode.len() == 36 {
        &["warproom", "warpx", "warpy"][..]
    } else {
        &["warproom", "warpx", "warpy", "unlocked"][..]
    };
    let mut values = Vec::with_capacity(expected_names.len());
    for (assignment_index, (instruction, expected_name)) in entry
        .bytecode
        .chunks_exact(12)
        .zip(expected_names.iter())
        .enumerate()
    {
        let assignment_pos = entry.bytecode_pos + assignment_index as u64 * 12 + 4;
        let variable_name = variable_references.get(&assignment_pos).map(String::as_str);
        if variable_name != Some(*expected_name) {
            let reason = format!(
                "assignment {} targets {:?}, expected {} from VARI",
                assignment_index + 1,
                variable_name,
                expected_name
            );
            return (
                entry.name.clone(),
                WarpAuditStatus::Unresolved { reason },
            );
        }
        if instruction[2..4] != [0x0f, 0x84] || instruction[6..8] != [0x25, 0x45] {
            return (
                entry.name.clone(),
                WarpAuditStatus::SpecialDynamic {
                    reason: format!(
                        "{} assignment is not an immediate-i16/pop-variable instruction",
                        expected_name
                    ),
                },
            );
        }
        values.push(i32::from(i16::from_le_bytes([instruction[0], instruction[1]])));
    }

    let room_index = match usize::try_from(values[0]) {
        Ok(index) if index < room_count => index,
        _ => {
            return (
                entry.name.clone(),
                WarpAuditStatus::Unresolved {
                    reason: format!("warproom {} is outside ROOM", values[0]),
                },
            )
        }
    };
    let unlocked = match values.get(3).copied() {
        None | Some(0) => false,
        Some(1) => true,
        Some(value) => {
            return (
                entry.name.clone(),
                WarpAuditStatus::Unresolved {
                    reason: format!("unlocked has non-boolean value {value}"),
                },
            )
        }
    };
    (
        entry.name.clone(),
        WarpAuditStatus::Decoded(WarpTarget {
            room_index,
            x: values[1],
            y: values[2],
            unlocked,
        }),
    )
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
        let sounds = match chunks.get("SOND") {
            Some(&(pos, size)) => {
                parse_sound_chunk(&mut file, pos, size, file_len, audio.len())?
            }
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

        // Parse BGND
        let mut backgrounds = HashMap::new();
        if let Some(&(pos, _size)) = chunks.get("BGND") {
            file.seek(SeekFrom::Start(pos))?;
            let count = file.read_u32::<LittleEndian>()?;
            let mut offsets = Vec::with_capacity(count as usize);
            for _ in 0..count {
                offsets.push(file.read_u32::<LittleEndian>()?);
            }
            for (idx, &off) in offsets.iter().enumerate() {
                let bg_pos = off as u64;
                if bg_pos >= file_len || file.seek(SeekFrom::Start(bg_pos)).is_err() {
                    continue;
                }
                let name_off = file.read_u32::<LittleEndian>().unwrap_or(0);
                let transparent = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let smooth = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let preload = file.read_u32::<LittleEndian>().unwrap_or(0) != 0;
                let tpag_ptr = file.read_u32::<LittleEndian>().unwrap_or(0) as usize;

                let bname = read_null_string(&mut file, name_off as u64, file_len)
                    .unwrap_or_else(|_| format!("bg_{}", idx));

                backgrounds.insert(idx, BackgroundData {
                    id: idx,
                    name: bname,
                    transparent,
                    smooth,
                    preload,
                    tpag_ptr,
                });
            }
        }

        // Parse CODE before OBJT so action CODE references are resolved from the
        // stored numeric field, never inferred from resource-name similarity.
        let code_entries = match chunks.get("CODE") {
            Some(&(pos, size)) => parse_code_entries(&mut file, pos, size, file_len)?,
            None => Vec::new(),
        };
        let code_names: Vec<Option<String>> = code_entries
            .iter()
            .map(|entry| entry.as_ref().ok().map(|entry| entry.name.clone()))
            .collect();

        // Parse OBJT, including direct event lists and ordered action records.
        let objects = match chunks.get("OBJT") {
            Some(&(pos, size)) => {
                parse_object_chunk(&mut file, pos, size, file_len, &code_names)?
            }
            None => Vec::new(),
        };
        let object_names = objects.iter().map(|object| object.name.clone()).collect();

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

        // Audit only creation codes actually referenced by obj_warpanywhere ROOM
        // instances. Static decoding is accepted only when CODE opcodes and the
        // VARI occurrence chains prove the warproom/warpx/warpy[/unlocked]
        // assignment semantics.
        let variable_references = match chunks.get("VARI") {
            Some(&(pos, size)) => parse_variable_references(&mut file, pos, size, file_len)?,
            None => HashMap::new(),
        };
        let warp_object_id = objects
            .iter()
            .find(|object| object.name == "obj_warpanywhere")
            .map(|object| object.id as i32);
        let mut warp_targets = HashMap::new();
        let mut warp_audits = Vec::new();
        if let Some(warp_object_id) = warp_object_id {
            for (source_room_index, room) in rooms.iter().enumerate() {
                for instance in &room.objects {
                    if instance.object_id != warp_object_id {
                        continue;
                    }
                    let (creation_code_name, status) = classify_warp_code(
                        instance.creation_code_id,
                        &code_entries,
                        &variable_references,
                        rooms.len(),
                    );
                    if let WarpAuditStatus::Decoded(target) = &status {
                        warp_targets.insert(instance.creation_code_id, *target);
                    }
                    warp_audits.push(WarpAudit {
                        source_room_index,
                        source_room_name: room.name.clone(),
                        instance_id: instance.instance_id,
                        creation_code_id: instance.creation_code_id,
                        creation_code_name,
                        status,
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
            backgrounds,
            tpag_items,
            warp_targets,
            warp_audits,
            audio,
            sounds,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::Write;

    fn write_sound_fixture(label: &str, bytes: &[u8]) -> std::path::PathBuf {
        let path = std::env::temp_dir().join(format!(
            "callys-asset-sond-{label}-{}",
            std::process::id()
        ));
        let mut file = File::create(&path).expect("create malformed SOND fixture");
        file.write_all(bytes).expect("write malformed SOND fixture");
        path
    }

    fn write_object_fixture(label: &str, bytes: &[u8]) -> std::path::PathBuf {
        let path = std::env::temp_dir().join(format!(
            "callys-asset-objt-{label}-{}",
            std::process::id()
        ));
        let mut file = File::create(&path).expect("create OBJT fixture");
        file.write_all(bytes).expect("write OBJT fixture");
        path
    }

    fn direct_event_fixture() -> Vec<u8> {
        let mut bytes = vec![0u8; 204];
        bytes[0..4].copy_from_slice(&1u32.to_le_bytes());
        bytes[4..8].copy_from_slice(&8u32.to_le_bytes());
        bytes[8..12].copy_from_slice(&200u32.to_le_bytes());
        bytes[12..16].copy_from_slice(&7i32.to_le_bytes());
        bytes[16..20].copy_from_slice(&1u32.to_le_bytes());
        bytes[32..36].copy_from_slice(&(-1i32).to_le_bytes());
        bytes[36..40].copy_from_slice(&(-1i32).to_le_bytes());
        bytes[76..80].copy_from_slice(&0.2f32.to_le_bytes());
        bytes[80..84].copy_from_slice(&1u32.to_le_bytes());
        bytes[88..92].copy_from_slice(&1u32.to_le_bytes());
        bytes[92..96].copy_from_slice(&96u32.to_le_bytes());
        bytes[96..100].copy_from_slice(&1u32.to_le_bytes());
        bytes[100..104].copy_from_slice(&104u32.to_le_bytes());
        bytes[104..108].copy_from_slice(&0i32.to_le_bytes());
        bytes[108..112].copy_from_slice(&1u32.to_le_bytes());
        bytes[112..116].copy_from_slice(&116u32.to_le_bytes());
        for (index, value) in [1u32, 603, 7, 0, 0, 1, 2, 200, 0, 1, u32::MAX, 0, 0, 0]
            .into_iter()
            .enumerate()
        {
            let start = 116 + index * 4;
            bytes[start..start + 4].copy_from_slice(&value.to_le_bytes());
        }
        bytes[200..204].copy_from_slice(b"obj\0");
        bytes
    }

    #[test]
    fn object_events_preserve_direct_type_subtype_action_order_and_code_reference() {
        let bytes = direct_event_fixture();
        let path = write_object_fixture("direct-event", &bytes);
        let mut file = File::open(&path).expect("open OBJT fixture");
        let objects = parse_object_chunk(
            &mut file,
            0,
            200,
            bytes.len() as u64,
            &[Some("gml_Object_obj_Create_0".into())],
        )
        .expect("parse direct OBJT event");
        std::fs::remove_file(path).expect("remove OBJT fixture");

        let object = &objects[0];
        assert_eq!(object.name, "obj");
        assert_eq!(object.events.len(), 1);
        assert_eq!(object.events[0].event_type, 0);
        assert_eq!(object.events[0].subtype, 0);
        assert_eq!(object.events[0].actions.len(), 1);
        let action = &object.events[0].actions[0];
        assert_eq!(action.order, 0);
        assert_eq!(action.code_id, 0);
        assert_eq!(action.code_name.as_deref(), Some("gml_Object_obj_Create_0"));
        assert_eq!(action.unknown_raw, 0);
    }

    #[test]
    fn object_pointer_must_stay_inside_objt_chunk() {
        let mut bytes = vec![0u8; 16];
        bytes[0..4].copy_from_slice(&1u32.to_le_bytes());
        bytes[4..8].copy_from_slice(&16u32.to_le_bytes());
        let path = write_object_fixture("object-pointer", &bytes);
        let mut file = File::open(&path).expect("open malformed OBJT fixture");
        let error = parse_object_chunk(&mut file, 0, 16, 16, &[])
            .expect_err("out-of-bounds OBJT object pointer must be rejected");
        std::fs::remove_file(path).expect("remove malformed OBJT fixture");
        assert!(error.to_string().contains("object record is outside chunk bounds"), "{error}");
    }

    #[test]
    fn object_event_pointer_must_stay_inside_object_record() {
        let mut bytes = direct_event_fixture();
        bytes[92..96].copy_from_slice(&200u32.to_le_bytes());
        let path = write_object_fixture("event-pointer", &bytes);
        let mut file = File::open(&path).expect("open malformed OBJT fixture");
        let error = parse_object_chunk(&mut file, 0, 200, bytes.len() as u64, &[Some("code".into())])
            .expect_err("out-of-bounds event pointer must be rejected");
        std::fs::remove_file(path).expect("remove malformed OBJT fixture");
        assert!(error.to_string().contains("event list is outside object bounds"), "{error}");
    }

    #[test]
    fn object_action_record_must_stay_inside_object_record() {
        let mut bytes = direct_event_fixture();
        bytes[112..116].copy_from_slice(&148u32.to_le_bytes());
        let path = write_object_fixture("action-pointer", &bytes);
        let mut file = File::open(&path).expect("open malformed OBJT fixture");
        let error = parse_object_chunk(&mut file, 0, 200, bytes.len() as u64, &[Some("code".into())])
            .expect_err("truncated action record must be rejected");
        std::fs::remove_file(path).expect("remove malformed OBJT fixture");
        assert!(error.to_string().contains("action record is outside object bounds"), "{error}");
    }

    #[test]
    fn object_action_code_reference_must_exist() {
        let mut bytes = direct_event_fixture();
        bytes[148..152].copy_from_slice(&1u32.to_le_bytes());
        let path = write_object_fixture("code-reference", &bytes);
        let mut file = File::open(&path).expect("open malformed OBJT fixture");
        let error = parse_object_chunk(&mut file, 0, 200, bytes.len() as u64, &[Some("code".into())])
            .expect_err("missing CODE reference must be rejected");
        std::fs::remove_file(path).expect("remove malformed OBJT fixture");
        assert!(error.to_string().contains("references missing CODE entry 1"), "{error}");
    }

    #[test]
    fn test_sound_record_pointer_must_stay_in_chunk() {
        let mut bytes = vec![0u8; 48];
        bytes[0..4].copy_from_slice(&1u32.to_le_bytes());
        bytes[4..8].copy_from_slice(&48u32.to_le_bytes());
        let path = write_sound_fixture("pointer", &bytes);
        let mut file = File::open(&path).expect("open malformed SOND fixture");
        let error = parse_sound_chunk(&mut file, 0, bytes.len() as u32, bytes.len() as u64, 1)
            .expect_err("out-of-bounds SOND record pointer must be rejected");
        std::fs::remove_file(path).expect("remove malformed SOND fixture");
        assert!(error.to_string().contains("record is outside chunk bounds"), "{error}");
    }

    #[test]
    fn test_sound_audio_reference_must_exist() {
        let mut bytes = vec![0u8; 64];
        bytes[0..4].copy_from_slice(&1u32.to_le_bytes());
        bytes[4..8].copy_from_slice(&8u32.to_le_bytes());
        bytes[8..12].copy_from_slice(&60u32.to_le_bytes());
        bytes[40..44].copy_from_slice(&1u32.to_le_bytes());
        bytes[60..64].copy_from_slice(b"snd\0");
        let path = write_sound_fixture("audio-reference", &bytes);
        let mut file = File::open(&path).expect("open malformed SOND fixture");
        let error = parse_sound_chunk(&mut file, 0, 44, bytes.len() as u64, 1)
            .expect_err("invalid AUDO reference must be rejected");
        std::fs::remove_file(path).expect("remove malformed SOND fixture");
        assert!(error.to_string().contains("references missing AUDO entry 1"), "{error}");
    }

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
    fn warp_decoder_rejects_static_constants_with_wrong_variable_semantics() {
        let mut bytecode = vec![0u8; 36];
        for (index, value) in [1_i16, 128, 492].into_iter().enumerate() {
            let offset = index * 12;
            bytecode[offset..offset + 2].copy_from_slice(&value.to_le_bytes());
            bytecode[offset + 2..offset + 4].copy_from_slice(&[0x0f, 0x84]);
            bytecode[offset + 6..offset + 8].copy_from_slice(&[0x25, 0x45]);
        }
        let entries = vec![Ok(CodeEntry {
            name: "gml_RoomCC_test_Create".into(),
            bytecode_pos: 100,
            bytecode,
        })];
        let variable_references = HashMap::from([
            (104, "warpx".into()),
            (116, "warproom".into()),
            (128, "warpy".into()),
        ]);

        let (_, status) = classify_warp_code(0, &entries, &variable_references, 2);
        assert!(
            matches!(status, WarpAuditStatus::Unresolved { ref reason } if reason.contains("expected warproom")),
            "wrong assignment order must not be treated as a decoded or dynamic warp: {status:?}"
        );
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
        let expected_direct_events = [
            (
                "obj_enemy",
                vec![(0, 0, 40), (1, 0, 41), (2, 6, 42), (2, 5, 43), (2, 4, 44), (2, 3, 45), (2, 0, 46), (3, 0, 47), (8, 0, 48)],
            ),
            (
                "obj_enemy2",
                vec![(0, 0, 123), (1, 0, 124), (2, 7, 125), (2, 6, 126), (2, 5, 127), (2, 4, 128), (2, 3, 129), (2, 2, 130), (2, 1, 131), (2, 0, 132), (3, 0, 133), (8, 0, 134)],
            ),
            (
                "obj_knifebandit",
                vec![(0, 0, 49), (1, 0, 50), (2, 6, 51), (2, 5, 52), (2, 4, 53), (2, 3, 54), (2, 0, 55), (3, 0, 56), (8, 0, 57)],
            ),
        ];
        for (object_name, expected) in expected_direct_events {
            let object = asset
                .objects
                .iter()
                .find(|object| object.name == object_name)
                .expect("target OBJT resource");
            assert_eq!(object.parent_id, 11);
            assert_eq!(asset.objects[11].name, "par_enemy");
            assert!(asset.objects[11].events.is_empty());
            let actual: Vec<_> = object
                .events
                .iter()
                .map(|event| {
                    assert_eq!(event.actions.len(), 1);
                    (
                        event.event_type,
                        event.subtype,
                        event.actions[0].code_id,
                    )
                })
                .collect();
            assert_eq!(actual, expected, "direct events for {object_name}");
            for event in &object.events {
                let action = &event.actions[0];
                assert_eq!(action.order, 0);
                assert!(action.code_name.as_deref().is_some_and(|name| {
                    name.starts_with(&format!("gml_Object_{object_name}_"))
                }));
            }
        }
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
        assert_eq!(asset.sounds.len(), 54);
        assert_eq!(asset.sounds[0].id, 0);
        assert_eq!(asset.sounds[0].name, "snd_bee");
        assert_eq!(asset.sounds[0].audio_id, 0);
        assert_eq!(asset.sounds[11].id, 11);
        assert_eq!(asset.sounds[11].name, "snd_shotgun");
        assert_eq!(asset.sounds[11].audio_id, 11);
        assert_eq!(asset.sounds[28].id, 28);
        assert_eq!(asset.sounds[28].name, "snd_weaponlevelup");
        assert_eq!(asset.sounds[28].audio_id, 28);
        assert_eq!(asset.sounds[29].id, 29);
        assert_eq!(asset.sounds[29].name, "mus_egc");
        assert_eq!(asset.sounds[29].audio_id, 28);
        assert_eq!(asset.sounds[53].id, 53);
        assert_eq!(asset.sounds[53].name, "mus_cally3");
        assert_eq!(asset.sounds[53].audio_id, 28);
        for sound in &asset.sounds {
            assert!(
                asset.audio.get(sound.audio_id).is_some(),
                "SOND {} ({}) references missing AUDO {}",
                sound.id,
                sound.name,
                sound.audio_id
            );
        }
        assert_eq!(asset.rooms[0].objects.len(), 170);
        assert_eq!(
            asset.warp_targets.get(&803),
            Some(&WarpTarget { room_index: 23, x: 64, y: 384, unlocked: false }),
        );
        assert_eq!(
            asset.warp_targets.get(&804),
            Some(&WarpTarget { room_index: 1, x: 128, y: 492, unlocked: true }),
        );
        assert_eq!(
            asset.warp_targets.get(&805),
            Some(&WarpTarget { room_index: 2, x: 128, y: 492, unlocked: true }),
        );
        assert_eq!(
            asset.warp_targets.get(&806),
            Some(&WarpTarget { room_index: 0, x: 832, y: 480, unlocked: true }),
        );
        assert_eq!(
            asset.warp_targets.get(&1021),
            Some(&WarpTarget { room_index: 108, x: 1376, y: 1164, unlocked: true }),
        );

        assert_eq!(asset.warp_audits.len(), 218);
        assert_eq!(asset.warp_targets.len(), 218);
        let mut decoded = 0;
        let mut special = 0;
        let mut unresolved = 0;
        for audit in &asset.warp_audits {
            match &audit.status {
                WarpAuditStatus::Decoded(target) => {
                    decoded += 1;
                    assert_eq!(asset.warp_targets.get(&audit.creation_code_id), Some(target));
                    let target_room = &asset.rooms[target.room_index];
                    assert!(target.x >= 0 && target.x <= target_room.width as i32);
                    assert!(target.y >= 0 && target.y <= target_room.height as i32);
                }
                WarpAuditStatus::SpecialDynamic { .. } => special += 1,
                WarpAuditStatus::Unresolved { .. } => unresolved += 1,
            }
        }
        assert_eq!((decoded, special, unresolved), (218, 0, 0));
        let first = &asset.warp_audits[0];
        assert_eq!(first.source_room_index, 0);
        assert_eq!(first.source_room_name, "rm_town");
        assert_eq!(first.instance_id, 100005);
        assert_eq!(first.creation_code_id, 803);

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
