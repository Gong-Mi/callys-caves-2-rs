use crate::{Checkpoint, GameWorld, WeaponType};
use serde::{Deserialize, Serialize};
use std::error::Error;
use std::fmt;

pub const CURRENT_SAVE_VERSION: u32 = 1;

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
        }
    }

    pub fn to_json(&self) -> Result<String, SaveError> {
        Ok(serde_json::to_string(self)?)
    }

    pub fn from_json(json: &str) -> Result<Self, SaveError> {
        #[derive(Deserialize)]
        struct VersionHeader {
            format_version: u32,
        }

        let header: VersionHeader = serde_json::from_str(json)?;
        if header.format_version != CURRENT_SAVE_VERSION {
            return Err(SaveError::UnsupportedVersion {
                found: header.format_version,
                supported: CURRENT_SAVE_VERSION,
            });
        }

        Ok(serde_json::from_str(json)?)
    }
}
