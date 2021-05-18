#include QMK_KEYBOARD_H

// Declarations
enum {
    Win_1_5,
	Win_2_6,
	Win_3_7,
	Win_4_8,
	Zm_L3_Rec,
	Zm_No_End,
	ZmScr_P_T,
	Tm_No_End
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Switch between Windows applications using the default shortcuts combo of CTRL+Win+[Num]
	[Win_1_5] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_1)), LCTL(LGUI(KC_5))),
	[Win_2_6] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_2)), LCTL(LGUI(KC_6))),
	[Win_3_7] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_3)), LCTL(LGUI(KC_7))),
	[Win_4_8] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_4)), LCTL(LGUI(KC_8))),

	// [Zm_No_Rec] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LALT(KC_C)),	// TD is a safer way to start & end a recording.
	[Zm_No_End] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LALT(KC_Q)),		// TD is a safer way to end the meeting.
	[ZmScr_P_T] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_T), LALT(KC_S)),	// TD is a safer way to screen share so it is not accidentally toggled off. Tap to Pause/Unpause

	[Tm_No_End] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LCTL(LSFT(KC_B)))	// TD is a safer way to end the meeting.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*******************************************************************
 *                         Common (Layer 0)                        *
 *******************************************************************
 * Required Autohotkey scripts
 * Window Always on Top: https://github.com/Brausmith/VMpad/blob/ff55bd2670d466604aa7d8804590dfdd46110483/AutoHotkey/VMpad.ahk
 * Cursor Highlighter: https://www.autohotkey.com/boards/viewtopic.php?t=78701
 *
 * ,---------------------------------------------------------------.
 * |    Layer 3    |    Layer 1    |    Layer 2    |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               | Window On Top |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |   Cursor HL   |
 * |---------------+---------------+---------------+---------------|
 * |   Win 1 & 5   |   Win 2 & 6   |   Win 3 & 7   |   Win 4 & 8   |
 * `---------------------------------------------------------------'
 */
[0] = LAYOUT_ortho_4x4(
	MO(3),			TO(1),			TO(2),			_______,
	_______,		_______,		_______,		MEH(KC_W),
	_______,		_______,		_______,		MEH(KC_C),
	TD(Win_1_5),	TD(Win_2_6),	TD(Win_3_7),	TD(Win_4_8)
),

/*******************************************************************
 *                          Zoom (Layer 1)                         *
 *******************************************************************
 * https://support.zoom.us/hc/en-us/articles/205683899-hot-keys-and-keyboard-for-zoom
 * Alt+C: Start/stop cloud recording
 * Alt+Q: End meeting
 * Alt+H: Display/hide in-meeting chat panel
 * : Q&A Panel ?? *** Still trying to determine if this has a shortcut? ***
 * Alt+Y: Raise/lower hand
 * Alt+A: Mute/unmute audio
 * Alt+V: Start/stop video
 * Alt+T: Pause or resume screen share
 * Alt+S: Launch share screen window and stop screen share
 *
 * ,---------------------------------------------------------------.
 * | Layer 3 . Rec |               |               |  End Meeting  |
 * |---------------+---------------+---------------+---------------|
 * |     Chat      |     Q&A ?     |     Hand      |               |
 * |---------------+---------------+---------------+---------------|
 * |     Mic       |     Camera    |    Screen     |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * `---------------------------------------------------------------'
 */
[1] = LAYOUT_ortho_4x4(
	LT(3,A(KC_C)),	_______,		_______,		TD(Zm_No_End),
	A(KC_H),		XXXXXXX,		A(KC_Y),		_______,
	A(KC_A),		A(KC_V),		TD(ZmScr_P_T),	_______,
	_______,		_______,		_______,		_______
),

/*******************************************************************
 *                        MS Teams (Layer 2)                       *
 *******************************************************************
 * https://support.microsoft.com/en-us/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
 * Ctrl+Shift+B: End meeting
 * Ctrl+Shift+K: Raise or lower your hand
 * Ctrl+Shift+M: Toggle mute
 * Ctrl+Shift+O: Toggle video
 * Ctrl+Shift+E: Start screen share session
 *
 * ,---------------------------------------------------------------.
 * |               |               |               |  End Meeting  |
 * |---------------+---------------+---------------+---------------|
 * |    XXXXXXX    |    XXXXXXX    |     Hand      |               |
 * |---------------+---------------+---------------+---------------|
 * |     Mic       |     Camera    |     Screen    |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * `---------------------------------------------------------------'
 */
[2] = LAYOUT_ortho_4x4(
	_______,		_______,		_______,		TD(Tm_No_End),
	XXXXXXX,		XXXXXXX,		C(S(KC_K)),		_______,
	C(S(KC_M)),		C(S(KC_O)),		C(S(KC_E)),		_______,
	_______,		_______,		_______,		_______
),

/*******************************************************************
 *                    Windows Settings (Layer 3)                   *
 *******************************************************************
 * Access to a few handy Windows Settings.
 *
 * Required Autohotkey scripts
 * All: https://github.com/Brausmith/VMpad/blob/ff55bd2670d466604aa7d8804590dfdd46110483/AutoHotkey/VMpad.ahk
 *
 * ,---------------------------------------------------------------.
 * |               |               |               |     Reset     |
 * |---------------+---------------+---------------+---------------|
 * |    XXXXXXX    |    XXXXXXX    |    XXXXXXX    |    XXXXXXX    |
 * |---------------+---------------+---------------+---------------|
 * | Mic Settings  | Cam Settings  | Disp Settings | Mous Settings |
 * |---------------+---------------+---------------+---------------|
 * |   BL Toggle   |    BL Step    |    XXXXXXX    |    XXXXXXX    |
 * `---------------------------------------------------------------'
 */
[3] = LAYOUT_ortho_4x4(
	_______,		_______,		_______,		RESET,
	XXXXXXX,		XXXXXXX,		XXXXXXX,		XXXXXXX,
	MEH(KC_A),		MEH(KC_V),		MEH(KC_D),		MEH(KC_M),
	BL_TOGG,		BL_STEP,		XXXXXXX,		XXXXXXX
)

};