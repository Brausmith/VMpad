#include QMK_KEYBOARD_H

// Declarations
enum {
    Shar_T_P,
	Apps_1_5,
	Apps_2_6,
	Apps_3_7,
	Apps_4_8,
	Win_1_5,
	Win_2_6,
	Win_3_7,
	Win_4_8
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Switch between Windows applications using default shortcuts of CTRL+Win+[Num]
    [Win_1_5] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_1)), LCTL(LGUI(KC_5))),
	[Win_2_6] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_2)), LCTL(LGUI(KC_6))),
	[Win_3_7] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_3)), LCTL(LGUI(KC_7))),
	[Win_4_8] = ACTION_TAP_DANCE_DOUBLE(LCTL(LGUI(KC_4)), LCTL(LGUI(KC_8)))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*******************************************************************
 *                         Common (Layer 0)                        *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |    Layer 1    |    Layer 2    |    Layer 3    |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               | Window to Top |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |   Cursor HL   |
 * |---------------+---------------+---------------+---------------|
 * |   Win 1 & 5   |   Win 2 & 6   |   Win 3 & 7   |   Win 4 & 8   |
 * `---------------------------------------------------------------'
 *
 * Required Autohotkey scripts
 * Window to Top: 
 * Cursor Highlighter: https://www.autohotkey.com/boards/viewtopic.php?t=78701
 */
[0] = LAYOUT_ortho_4x4(
	MO(1),			TO(2),			TO(3),			KC_NO,
	KC_NO,			KC_NO,			KC_NO,			MEH(KC_W),
	KC_NO,			KC_NO,			KC_NO,			MEH(KC_C),
	TD(Win_1_5),	TD(Win_2_6),	TD(Win_3_7),	TD(Win_4_8)
),

/*******************************************************************
 *                    Windows Settings (Layer 1)                   *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |     Trans     |    Layer 4    |    Layer 5    |     Reset     |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * |---------------+---------------+---------------+---------------|
 * | Mic Settings  | Cam Settings  | Disp Settings | Mous Settings |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * `---------------------------------------------------------------'
 *
 * Access to a few handy Windows Settings.
 *
 * Required Autohotkey scripts
 * All: 
 */
[1] = LAYOUT_ortho_4x4(
	KC_TRNS,		MO(4),			MO(5),			RESET,
	KC_NO,			KC_NO,			KC_NO,			KC_NO,
	MEH(KC_A),		MEH(KC_V),		MEH(KC_D),		MEH(KC_M),
	KC_NO,			KC_NO,			KC_NO,			KC_NO
),

/*******************************************************************
 *                          Zoom (Layer 2)                         *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |     Trans     |     Trans     |     Trans     |               |
 * |---------------+---------------+---------------+---------------|
 * |     Chat      |     Q&A       |     Hand      |     Trans     |
 * |---------------+---------------+---------------+---------------|
 * |     Mic       |     Camera    |     Screen    |     Trans     |
 * |---------------+---------------+---------------+---------------|
 * |     Trans     |     Trans     |     Trans     |     Trans     |
 * `---------------------------------------------------------------'
 *
 * https://support.zoom.us/hc/en-us/articles/205683899-hot-keys-and-keyboard-for-zoom
 * Alt+H: Display/hide in-meeting chat panel
 * : Q&A Panel ??
 * Alt+Y: Raise/lower hand
 * Alt+A: Mute/unmute audio
 * Alt+V: Start/stop video
 * Alt+S: Launch share screen window and stop screen share
 * Alt+T: Pause or resume screen share
 * Alt+C: Start/stop cloud recording
 */
[2] = LAYOUT_ortho_4x4(
	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,
	A(KC_H),		KC_NO,			A(KC_Y),		KC_TRNS,
	A(KC_A),		A(KC_V),		A(KC_S),		KC_TRNS,
	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS
),

/*******************************************************************
 *                        MS Teams (Layer 3)                       *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |     Trans     |     Trans     |     Trans     |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |     Hand      |     Trans     |
 * |---------------+---------------+---------------+---------------|
 * |     Mic       |     Camera    |     Screen    |     Trans     |
 * |---------------+---------------+---------------+---------------|
 * |     Trans     |     Trans     |     Trans     |     Trans     |
 * `---------------------------------------------------------------'
 *
 * https://support.microsoft.com/en-us/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
 * Ctrl+Shift+K: Raise or lower your hand
 * Ctrl+Shift+M: Toggle mute
 * Ctrl+Shift+O: Toggle video
 * Ctrl+Shift+E: Start screen share session
 */
[3] = LAYOUT_ortho_4x4(
	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_NO,
	KC_NO,			KC_NO,			C(S(KC_K)),		KC_TRNS,
	C(S(KC_M)),		C(S(KC_O)),		C(S(KC_E)),		KC_TRNS,
	KC_TRNS,		KC_TRNS,		KC_TRNS,		KC_TRNS
),

/*******************************************************************
 *                       Zoom Extras (Layer 4)                     *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |     Trans     |     Trans     |               |  End Meeting  |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * `---------------------------------------------------------------'
 *
 * A safer multi-key combo to end the meeting.
 * Alt+Q: End meeting
 */
[4] = LAYOUT_ortho_4x4(
	KC_TRNS,		KC_TRNS,		KC_NO,			A(KC_Q),
	KC_NO,			KC_NO,			KC_NO,			KC_NO,
	KC_NO,			KC_NO,			KC_NO,			KC_NO,
	KC_NO,			KC_NO,			KC_NO,			KC_NO
),

/*******************************************************************
 *                     MS Teams Extras (Layer 5)                   *
 *******************************************************************
 * ,---------------------------------------------------------------.
 * |     Trans     |               |     Trans     |  End Meeting  |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * |---------------+---------------+---------------+---------------|
 * |               |               |               |               |
 * `---------------------------------------------------------------'
 *
 * A safer multi-key combo to end the meeting.
 * Ctrl+Shift+B: End meeting
 */
[5] = LAYOUT_ortho_4x4(
	KC_TRNS,		KC_NO,			KC_TRNS,		C(S(KC_B)),
	KC_NO,			KC_NO,			KC_NO,			KC_NO,
	KC_NO,			KC_NO,			KC_NO,			KC_NO,
	KC_NO,			KC_NO,			KC_NO,			KC_NO
)

};