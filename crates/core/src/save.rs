use crate::{Checkpoint, GameWorld, WeaponType};
use serde::{Deserialize, Serialize};
use std::error::Error;
use std::fmt;

pub const CURRENT_SAVE_VERSION: u32 = 2;

#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
pub struct SaveData {
    pub format_version: u32,
    pub current_room: usize,
    pub checkpoint: Checkpoint,
    pub max_health: i32,
    pub gems: u32,
    pub coins: u32,
    pub current_weapon: WeaponType,
    pub unlocked_weapons: Vec<WeaponType>,
    pub collected_instance_ids: Vec<i32>,
}

#[derive(Debug)]
pub enum SaveError {
    InvalidJson(serde_json::Error),
    UnsupportedVersion { found: u32, supported: u32 },
}

impl fmt::Display for SaveError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::InvalidJson(error) => write!(formatter, "invalid save data: {error}"),
            Self::UnsupportedVersion { found, supported } => write!(
                formatter,
                "unsupported save format version {found}; supported version is {supported}"
            ),
        }
    }
}

impl Error for SaveError {
    fn source(&self) -> Option<&(dyn Error + 'static)> {
        match self {
            Self::InvalidJson(error) => Some(error),
            Self::UnsupportedVersion { .. } => None,
        }
    }
}

impl From<serde_json::Error> for SaveError {
    fn from(error: serde_json::Error) -> Self {
        Self::InvalidJson(error)
    }
}

impl SaveData {
    pub fn from_world(world: &GameWorld) -> Self {
        Self {
            format_version: CURRENT_SAVE_VERSION,
            current_room: world.current_room_index,
            checkpoint: world.checkpoint,
            max_health: world.player.max_health,
            gems: world.player.gems,
            coins: world.player.coins,
            current_weapon: world.player.current_weapon,
            unlocked_weapons: world.player.unlocked_weapons.clone(),
            collected_instance_ids: world.collected_instance_ids.iter().copied().collect(),
        }
    }

    pub fn to_json(&self) -> Result<String, SaveError> {
        let mut normalized = self.clone();
        normalized.collected_instance_ids.sort_unstable();
        normalized.collected_instance_ids.dedup();
        Ok(serde_json::to_string(&normalized)?)
    }

    pub fn from_json(json: &str) -> Result<Self, SaveError> {
        #[derive(Deserialize)]
        struct VersionHeader {
            format_version: u32,
        }

        #[derive(Deserialize)]
        struct SaveDataV1 {
            current_room: usize,
            checkpoint: Checkpoint,
            max_health: i32,
            gems: u32,
            coins: u32,
            current_weapon: WeaponType,
            unlocked_weapons: Vec<WeaponType>,
        }

        let header: VersionHeader = serde_json::from_str(json)?;
        let mut save = match header.format_version {
            1 => {
                let legacy: SaveDataV1 = serde_json::from_str(json)?;
                Self {
                    format_version: CURRENT_SAVE_VERSION,
                    current_room: legacy.current_room,
                    checkpoint: legacy.checkpoint,
                    max_health: legacy.max_health,
                    gems: legacy.gems,
                    coins: legacy.coins,
                    current_weapon: legacy.current_weapon,
                    unlocked_weapons: legacy.unlocked_weapons,
                    collected_instance_ids: Vec::new(),
                }
            }
            CURRENT_SAVE_VERSION => serde_json::from_str(json)?,
            found => {
                return Err(SaveError::UnsupportedVersion {
                    found,
                    supported: CURRENT_SAVE_VERSION,
                });
            }
        };
        save.collected_instance_ids.sort_unstable();
        save.collected_instance_ids.dedup();
        Ok(save)
    }
}
