#include QMK_KEYBOARD_H
#include "keymap.h"
#include "config.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _NAVI 2
#define _FUNC 3

qk_tap_dance_action_t tap_dance_actions[] = {};

enum custom_keycodes {
  VIM_WH = SAFE_RANGE,
  VIM_WJ = SAFE_RANGE,
  VIM_WK = SAFE_RANGE,
  VIM_WL = SAFE_RANGE
};

/*    Blank template
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,            _______, _______,

      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,  _______,            _______,  _______,  _______,  _______, _______
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
      KC_MINS,  KC_0,     KC_8,     KC_6,     KC_4,     KC_2,               KC_LGUI,
      KC_LBRC,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,               KC_LCTL,
      KC_GRV,   KC_A,     KC_R,     KC_S,     KC_T,     KC_G,               KC_QUES,
      KC_QUES,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,               KC_LSPO,
      KC_QUES,  MO(_FUNC),MO(_NAVI),KC_LEFT,  KC_RIGHT,           KC_TAB,   KC_ENTER,

      KC_LEAD,            KC_1,     KC_3,     KC_5,     KC_7,     KC_9,     KC_EQL,
      KC_ESC,             KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_RBRC,
      KC_RALT,            KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
      KC_RSPC,            KC_M,     KC_H,     KC_COMM,  KC_DOT,   KC_SLASH, KC_BSLS,
      KC_SPC,   KC_BSPC,            KC_DOWN,  KC_UP,    KC_QUES,  KC_QUES,  KC_QUES
),
[_FUNC] = LAYOUT(
      _______,  _______,  KC_F8,    KC_F6,    KC_F4,    KC_F2,             _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,            _______, _______,

      _______,            KC_F1,    KC_F3,    KC_F5,    KC_F7,    KC_F9,   _______,
      RESET,              _______,  _______,  _______,  _______,  _______, _______,
      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,            _______,  _______,  _______,  _______,  _______, _______,
      _______,  _______,            _______,  _______,  _______,  _______, _______
)
[_NAVI] = LAYOUT(
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  _______,  _______,  KC_HOME,  KC_END,             _______,  _______,

      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,            VIM_WH,   VIM_WJ,   VIM_WK,   VIM_WL,   _______,  _______,
      _______,            KC_H,     KC_J,     KC_K,     KC_L,     _______,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,            KC_PGDN,  KC_PGUP,  _______,  _______,  _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char key[2] = " ";
  if (record->event.pressed) {
    switch (keycode) {
      case VIM_WH:
        key = "h"; goto string_nav;
      case VIM_WJ:
        key = "j"; goto string_nav;
      case VIM_WK:
        key = "k"; goto string_nav;
      case VIM_WL:
        key = "l";
        string_nav:
        SEND_STRING(SS(LCTRL("w")keycode);
        send_string(key);
        break;
    }
  }
  return true;
}
