# Death / local left-release contract

Original evidence: `0012__gml_Object_obj_player_Step_0.gml:2375-2387`
and complete object `obj_youhavedied` methods CODE 540..544 from the recovered
1,354-CODE source set. No hand-written death timer/health/respawn rules added.

| CODE | Original method | Runtime evidence |
| --- | --- | --- |
| 12 | player Step health1==1 creates controller, increments playerdied | real town -> level1, health1 injection then original Step |
| 540 | Create: coindeduct 30..99, move player to startx/starty, deactivate others, pause audio, taplock=0/alarm0=70 | `death_restart_ir` checks player position, activation, 70-tick lock |
| 542 | Alarm0: taplock=1 | locked through 69 ticks, open on tick70 |
| 543 | Mouse7: destroy only when taplock==1 | early release consumed, later actual release through client -> tick destroys |
| 541 | Destroy: activate all, health1=4, score deduction, warpfrommap=1, conditional resume audio, room_restart | same-room request, reactivated persistent player, 15 post-restart ticks |
| 544 | Draw: death sprite + coin/deduction, Tap to Continue after unlock | real client Draw text command checked after unlock |

`Mouse_7` means **local LeftReleased**, not pressed or a global screen event.
Independent enum reference: UndertaleModTool `UndertaleModLib/Models/UndertaleGameObject.cs`,
EventSubtypeMouse LeftPressed=4 / LeftReleased=7 / GlobLeftReleased=56.

## New input path

Android ACTION_DOWN remembers the primary pointer id. Only that pointer's
ACTION_UP/ACTION_POINTER_UP enqueues a release; secondary fingers and CANCEL do
not synthesize a click. Letterbox bounds and finite coordinates are validated,
then converted to the existing renderer's 960x540 logical space.
`PointerReleaseQueue` uses a concurrent queue from UI to render thread. JNI calls
run on the render thread before nativeStep, not on the UI thread.
`GameState::pointer_released` adds the existing view-0 origin; `Scene::tick` drains
actual releases after alarms and before Step, dispatching inherited Event6/7 only
to alive, active, non-external instances hit by the existing sprite-origin AABB.
Misses/locked releases are consumed once, never retained until a UI unlocks.

Rust regression was observed RED on unconsumed release, then GREEN with the
scheduler consumer. `mouse_release_ir` checks origin/edges/inheritance, ineligible
instances, one-shot delivery and VM error propagation. The actual Java queue is
compiled/executed by `scripts/test_pointer_release_java.py` in Rust CI.
The separate core test directly invokes Mouse7 and is characterization, not a
claim that the old Android release path worked.

## Coverage and remaining boundaries

Full original Mouse census: 35 direct event bindings, subtype0=15, subtype3=1,
subtype4=2, subtype7=17. This slice routes subtype7 generically; it does not claim
held/no-button/pressed mouse events work or that all 17 UI flows are tested.
Death's five methods are executed, but score/global builtin accounting, Android
pause/resume audio consumption, pixel-perfect sprite masks and all view layouts
remain separate contracts. The current AABB hit policy is not precise mask parity.
The 70-tick boundary is deterministic scheduler evidence, not measured real time.
Java queue execution + javac + Android-feature Rust compilation are not ART/input
injection/device evidence. No APK was installed or app launched for this slice.
A local host death/restart does not establish full combat/health/coin economy or
all-room completion fidelity; health is injected to enter the original death path.
