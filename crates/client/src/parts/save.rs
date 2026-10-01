// ============================================================
// Save file I/O
// ============================================================

#[derive(Debug)]
pub enum SaveFileError {
    Io(std::io::Error),
    Data(SaveError),
}

impl fmt::Display for SaveFileError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io(error) => write!(formatter, "save file I/O failed: {error}"),
            Self::Data(error) => write!(formatter, "{error}"),
        }
    }
}

impl std::error::Error for SaveFileError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io(error) => Some(error),
            Self::Data(error) => Some(error),
        }
    }
}

impl From<std::io::Error> for SaveFileError {
    fn from(error: std::io::Error) -> Self {
        Self::Io(error)
    }
}

impl From<SaveError> for SaveFileError {
    fn from(error: SaveError) -> Self {
        Self::Data(error)
    }
}

pub fn save_path_for_asset(droid_path: &Path) -> PathBuf {
    droid_path.with_file_name("save-v2.json")
}

pub fn load_save(path: &Path) -> Result<Option<SaveData>, SaveFileError> {
    let json = match fs::read_to_string(path) {
        Ok(json) => json,
        Err(error) if error.kind() == std::io::ErrorKind::NotFound => return Ok(None),
        Err(error) => return Err(error.into()),
    };
    Ok(Some(SaveData::from_json(&json)?))
}

fn load_save_with_legacy_migration(
    path: &Path,
) -> Result<(Option<SaveData>, Option<String>), SaveFileError> {
    if let Some(save) = load_save(path)? {
        return Ok((Some(save), None));
    }
    if path.file_name().and_then(|name| name.to_str()) != Some("save-v2.json") {
        return Ok((None, None));
    }

    let legacy_path = path.with_file_name("save-v1.json");
    let Some(save) = load_save(&legacy_path)? else {
        return Ok((None, None));
    };
    let diagnostic = write_save_atomic(path, &save)
        .err()
        .map(|error| format!("loaded legacy save but failed to migrate it to v2: {error}"));
    Ok((Some(save), diagnostic))
}

pub fn write_save_atomic(path: &Path, save: &SaveData) -> Result<(), SaveFileError> {
    let json = save.to_json()?;
    let temp_path = path.with_file_name(format!(
        "{}.tmp",
        path.file_name()
            .and_then(|name| name.to_str())
            .unwrap_or("save-v2.json")
    ));
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
        temp.write_all(json.as_bytes())?;
        temp.sync_all()?;
        drop(temp);
        fs::rename(&temp_path, path)?;
        Ok(())
    })() {
        let _ = fs::remove_file(&temp_path);
        return Err(error.into());
    }
    Ok(())
}

