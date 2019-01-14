#include QMK_KEYBOARD_H
#include "keymap.h"
#include "config.h"

extern keymap_config_t keymap_config;
#define _BASE 0
#define _NAVI 2
#define _FUNC 3

enum custom_keycodes {
  VIM_WH = SAFE_RANGE,
  VIM_WJ,
  VIM_WK,
  VIM_WL,
};

#define NAVLEAD LT(_NAVI, KC_LEAD)
#define SFTGUI  RGUI(KC_RSFT)
#define ALTESC  RALT_T(KC_ESC)

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
      KC_MINS,  KC_0,     KC_8,     KC_6,     KC_4,     KC_2,               MO(_FUNC),
      KC_LBRC,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,               KC_LALT,
      KC_GRV,   KC_A,     KC_R,     KC_S,     KC_T,     KC_G,               KC_LGUI,
      KC_QUES,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,               KC_LSPO,
      MO(_FUNC),KC_LCTL,  KC_LGUI,  KC_LEFT,  KC_RIGHT,           KC_TAB,   KC_ENTER,

      MO(_NAVI),          KC_1,     KC_3,     KC_5,     KC_7,     KC_9,     KC_EQL,
      ALTESC,             KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_RBRC,
      KC_RGUI,            KC_K,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
      KC_RSPC,            KC_M,     KC_H,     KC_COMM,  KC_DOT,   KC_SLASH, KC_BSLS,
      KC_SPC,   KC_BSPC,            KC_DOWN,  KC_UP,    KC_RGUI,  KC_QUES,  KC_QUES
),
[_FUNC] = LAYOUT(
      _______,  _______,  KC_F8,    KC_F6,    KC_F4,    KC_F2,             _______,
      _______,  _______,  _______,  _______,  KC_BTN3,  _______,           _______,
      _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,  _______,           _______,
      _______,  _______,  _______,  _______,  _______,            _______, _______,

      _______,            KC_F1,    KC_F3,    KC_F5,    KC_F7,    KC_F9,   _______,
      RESET,              _______,  KC_7,     KC_8,     KC_9,  _______, _______,
      _______,            _______,  KC_4,     KC_5,     KC_6,  _______, _______,
      _______,            _______,  KC_1,     KC_2,     KC_3,  _______, _______,
      _______,  _______,            _______,  KC_0,     _______,  _______, _______
),
[_NAVI] = LAYOUT(
      _______,  _______,  _______,  _______,  _______,  _______,            _______,
      _______,  KC_LCBR,  KC_DLR,   KC_PERC,  KC_EXLM,  _______,            _______,
      _______,  KC_AMPR,  KC_HASH,  KC_AT,    KC_EQL,   _______,            _______,
      _______,  _______,  _______,  KC_CIRC,  KC_LT,    _______,            _______,
      _______,  _______,  _______,  KC_HOME,  KC_END,             _______,  _______,

      _______,            _______,  _______,  _______,  _______,  _______,  _______,
      _______,            _______,  KC_ASTR,  KC_PLUS,  KC_MINS,  KC_RCBR,  _______,
      _______,            _______,  KC_UNDS,  KC_COLN,  KC_PIPE,  KC_DQUO,  _______,
      _______,            _______,  KC_GT,    KC_SCLN,  _______,  _______,  _______,
      _______,  _______,            KC_PGDN,  KC_PGUP,  _______,  _______,  _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char key[2] = " ";
  if (record->event.pressed) {
    switch (keycode) {
      case VIM_WH:
        key[0] = 'h'; goto string_nav;
      case VIM_WJ:
        key[0] = 'j'; goto string_nav;
      case VIM_WK:
        key[0] = 'k'; goto string_nav;
      case VIM_WL:
        key[0] = 'l';
        string_nav:
        SEND_STRING(SS_LCTRL("w"));
        send_string(key);
        break;
    }
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_E) {
      // Anything you can do in a macro.
      SEND_STRING("stone.tickle@gmail.com");
    }
    SEQ_TWO_KEYS(KC_W, KC_W) {
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)));
      SEND_STRING("cd ~/dev/rails/threat-advice/mythreatadvice/"SS_TAP(X_ENTER));
      SEND_STRING(SS_LGUI(SS_TAP(X_ENTER))SS_LGUI(SS_TAP(X_ENTER)));
    }
  }
}
