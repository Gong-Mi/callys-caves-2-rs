-- Behavior database for the Cally's Caves 2 reconstruction.
-- Derived: rebuild with `python3 scripts/build_behavior_db.py`.
-- Cards are the hand-written source of truth (reconstruction/db/cards/*.json);
-- facts are generated from the shipped IR, never hand-edited.
--
-- The point of this schema is the `tier` column: the old ledgers answered
-- "did it run", which is self-consistent by construction. A card answers
-- "what do we claim is true, and what is the strongest evidence for it".

PRAGMA foreign_keys = ON;

-- ---------- facts (generated from full_ir.json / asset) ----------

CREATE TABLE fact_object (
    id          INTEGER PRIMARY KEY,
    name        TEXT NOT NULL,
    persistent  INTEGER NOT NULL,
    depth       REAL,
    sprite      INTEGER
);

CREATE TABLE fact_code (
    id          INTEGER PRIMARY KEY,
    owner_object INTEGER,            -- NULL for the 551 RoomCC room-creation bodies
    event_type  INTEGER,             -- 0 Create, 2 Alarm, 3 Step, 4 Collision,
                                     -- 6 Mouse, 7 Other, 8 Draw, 9 KeyPress, 10 KeyRelease
    subtype     INTEGER,
    instructions INTEGER NOT NULL,
    -- Per-body identity. Any equality claim (C == VM, C == original) must cite this
    -- sha in its BINDING line; a passing log without it is not evidence.
    sha256      TEXT NOT NULL,
    name        TEXT NOT NULL
);

CREATE TABLE fact_builtin_call (
    code_id  INTEGER NOT NULL REFERENCES fact_code(id),
    name     TEXT NOT NULL,
    sites    INTEGER NOT NULL,       -- how many call instructions name it
    PRIMARY KEY (code_id, name)
);

CREATE TABLE fact_room_binding (
    id        INTEGER PRIMARY KEY,   -- RoomCC index (0..550)
    room      INTEGER NOT NULL,
    code_id   INTEGER NOT NULL REFERENCES fact_code(id)
);

-- ---------- cards (hand-written claims) ----------

CREATE TABLE card (
    id                 TEXT PRIMARY KEY,     -- e.g. BOOT-001
    title              TEXT NOT NULL,
    scope_object       TEXT,
    scope_event        TEXT,
    trigger            TEXT NOT NULL,
    preconditions      TEXT NOT NULL,
    effects            TEXT NOT NULL,
    tier               TEXT NOT NULL CHECK (tier IN (
                           'bytecode_anchored',   -- decided by a shipped CODE body
                           'oracle_anchored',     -- measured on the original binary
                           'device_anchored',     -- observed on the real device
                           'test_anchored',       -- rewrite-side test only: self-consistency
                           'host_authored',       -- does not exist in the original
                           'unverified')),
    host_authored      INTEGER NOT NULL DEFAULT 0,
    original_gap       TEXT NOT NULL,        -- what the original does/unknown; required
                                             -- when host_authored=1 or tier='unverified'
    anchor             TEXT NOT NULL,        -- file:line, CODE id, libyoyo address, log line
    notes              TEXT
);

CREATE TABLE card_code (
    card_id TEXT NOT NULL REFERENCES card(id),
    code_id INTEGER NOT NULL,
    PRIMARY KEY (card_id, code_id)
);

CREATE TABLE card_evidence (
    card_id TEXT NOT NULL REFERENCES card(id),
    kind    TEXT NOT NULL CHECK (kind IN ('bytecode','oracle','device','test','contract')),
    ref     TEXT NOT NULL,
    note    TEXT
);

CREATE TABLE card_question (
    card_id  TEXT NOT NULL REFERENCES card(id),
    question TEXT NOT NULL,
    status   TEXT NOT NULL DEFAULT 'open' CHECK (status IN ('open','answered','dropped'))
);

CREATE INDEX card_tier ON card(tier);
CREATE INDEX card_host ON card(host_authored);
CREATE UNIQUE INDEX card_code_once ON card_code(card_id, code_id);
