/* vim: set colorcolumn=85 */
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "config.h"

extern keymap_config_t keymap_config;
#define _BASE 0
#define _SYM1 1
#define _SYM2 2
#define _FNC1 3
#define _FNC2 4

/*    Blank template
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,            _______,  _______,

      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,            _______,  _______,  _______,  _______,  _______
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,            MO(_FNC1),
		KC_LBRC,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,               KC_LALT,
		_______,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,               KC_LGUI,
		_______,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,               KC_LCTL,
		_______,  KC_LCTL,  _______,  KC_LEFT,  KC_RIGHT,           KC_TAB,   KC_ENTER,

		MO(_SYM1),          _______,  _______,  _______,  _______,  _______,  _______,
		KC_ESC,             KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_RBRC,
		KC_RGUI,            KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_ESC,
		KC_RSFT,            KC_M,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
		KC_SPC,   KC_BSPC,            KC_DOWN,  KC_UP,    _______,  KC_RCTL,  _______
		),
	[_SYM1] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,            MO(_SYM2),
		_______,  KC_LCBR,  KC_DLR,   KC_PERC,  KC_EXLM,  _______,            _______,
		_______,  KC_AMPR,  KC_HASH,  KC_AT,    KC_EQL,   _______,            _______,
		_______,  KC_GRV,   KC_TILD,  KC_CIRC,  KC_LT,    _______,            _______,
		_______,  _______,  _______,  KC_HOME,  KC_END,             _______,  _______,

		_______,            _______,  _______,  _______,  _______,  _______,  _______,
		_______,            _______,  KC_ASTR,  KC_PLUS,  KC_MINS,  KC_RCBR,  _______,
		_______,            _______,  KC_UNDS,  KC_COLN,  KC_PIPE,  KC_DQUO,  _______,
		_______,            _______,  KC_GT,    KC_SCLN,  KC_QUOT,  KC_BSLS,  _______,
		_______,  _______,            KC_PGDN,  KC_PGUP,  _______,  _______,  _______
		),
	[_SYM2] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  KC_LPRN,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  KC_H,     KC_L,               _______,  _______,

		_______,            _______,  _______,  _______,  _______,  _______,  _______,
		_______,            _______,  _______,  _______,  _______,  KC_RPRN,  _______,
		_______,            _______,  _______,  _______,  _______,  _______,  _______,
		_______,            _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,            KC_J,     KC_K,     _______,  _______,  _______
		),
	[_FNC1] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  KC_BTN3,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,            _______,  _______,

		MO(_FNC2),          _______,  _______,  _______,  _______,  _______,  _______,
		RESET,              _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
		_______,            _______,  KC_4,     KC_5,     KC_6,     _______,  RESET,
		_______,            _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
		_______,  _______,            _______,  KC_0,     _______,  _______,  _______
		),
	[_FNC2] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  _______,  _______,  _______,            _______,
		_______,  _______,  _______,  KC_H,     KC_J,               _______,  _______,

		_______,            _______,  KC_F10,   KC_F11,   KC_F12,   _______,  _______,
		_______,            _______,  KC_F7,    KC_F8,    KC_F9,    _______,  _______,
		_______,            _______,  KC_F4,    KC_F5,    KC_F6,    _______,  _______,
		_______,            _______,  KC_F1,    KC_F2,    KC_F3,    _______,  _______,
		_______,  _______,            KC_J,     KC_K,     _______,  _______,  _______
		),
};

uint32_t layer_state_set_user(uint32_t state)
{
	uprintf("new_layer %d\n", biton32(state));

	return state;
}
