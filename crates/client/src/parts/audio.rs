// ============================================================
// Short sound effects
// ============================================================

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum SoundEvent {
    Jump,
    Pistol,
    Shotgun,
    Coin,
    Death,
    WeaponPickup,
}

const SOUND_BINDINGS: [(SoundEvent, &str); 6] = [
    (SoundEvent::Jump, "snd_jump"),
    (SoundEvent::Pistol, "snd_fire"),
    (SoundEvent::Shotgun, "snd_shotgun"),
    (SoundEvent::Coin, "snd_coin"),
    (SoundEvent::Death, "snd_youhavedied"),
    (SoundEvent::WeaponPickup, "snd_pickupstinger"),
];

#[derive(Debug, Clone)]
pub struct SoundCatalog {
    audio_ids: HashMap<SoundEvent, usize>,
}

impl SoundCatalog {
    pub fn from_asset(asset: &GameDroidAsset) -> Result<Self, String> {
        let sounds_by_name: HashMap<&str, usize> = asset
            .sounds
            .iter()
            .map(|sound| (sound.name.as_str(), sound.audio_id))
            .collect();
        let mut audio_ids = HashMap::with_capacity(SOUND_BINDINGS.len());
        for (event, name) in SOUND_BINDINGS {
            let audio_id = sounds_by_name
                .get(name)
                .copied()
                .ok_or_else(|| format!("required SOND resource is missing: {name}"))?;
            if asset.audio.get(audio_id).is_none() {
                return Err(format!(
                    "SOND resource {name} references missing AUDO {audio_id}"
                ));
            }
            audio_ids.insert(event, audio_id);
        }
        Ok(Self { audio_ids })
    }

    pub fn audio_id(&self, event: SoundEvent) -> usize {
        self.audio_ids[&event]
    }
}

pub fn export_required_wavs(
    asset: &GameDroidAsset,
    droid_path: &Path,
) -> Result<Vec<(usize, PathBuf)>, Box<dyn std::error::Error>> {
    let catalog = SoundCatalog::from_asset(asset)?;
    let output_dir = droid_path
        .parent()
        .unwrap_or_else(|| Path::new("."))
        .join("sfx");
    fs::create_dir_all(&output_dir)?;

    let mut exported = Vec::with_capacity(SOUND_BINDINGS.len());
    let mut exported_audio_ids = HashSet::with_capacity(SOUND_BINDINGS.len());
    for (event, _) in SOUND_BINDINGS {
        let audio_id = catalog.audio_id(event);
        if !exported_audio_ids.insert(audio_id) {
            continue;
        }
        let wav = &asset.audio[audio_id].wav_bytes;
        let output_path = output_dir.join(format!("sound_{audio_id}.wav"));
        let already_current = fs::read(&output_path)
            .map(|existing| existing == *wav)
            .unwrap_or(false);
        if !already_current {
            let temp_path = output_dir.join(format!("sound_{audio_id}.wav.tmp"));
            match fs::remove_file(&temp_path) {
                Ok(()) => {}
                Err(error) if error.kind() == std::io::ErrorKind::NotFound => {}
                Err(error) => return Err(error.into()),
            }
            let mut temp = OpenOptions::new()
                .write(true)
                .create_new(true)
                .open(&temp_path)?;
            if let Err(error) = (|| -> Result<(), std::io::Error> {
                temp.write_all(wav)?;
                temp.sync_all()?;
                drop(temp);
                fs::rename(&temp_path, &output_path)?;
                Ok(())
            })() {
                let _ = fs::remove_file(&temp_path);
                return Err(error.into());
            }
        }
        exported.push((audio_id, output_path));
    }
    Ok(exported)
}

