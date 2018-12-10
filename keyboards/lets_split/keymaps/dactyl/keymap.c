#include QMK_KEYBOARD_H
#include "keymap.h"
#include "config.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _VIM  1
#define _FUNC 2

qk_tap_dance_action_t tap_dance_actions[] = {};

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
      KC_MINS,   KC_0,    KC_8,        KC_6,        KC_4,      KC_2,               KC_LGUI,
      KC_LBRC,   KC_Q,    KC_W,        KC_F,        KC_P,      KC_B,               KC_LCTL,
      KC_GRV,    KC_A,    KC_R,        KC_S,        KC_T,      KC_G,               KC_QUES,
      KC_QUES,   KC_Z,    KC_X,        KC_C,        KC_D,      KC_V,               KC_LSPO,
      KC_QUES,   KC_QUES, KC_QUES,     KC_LEFT,     KC_RIGHT,            KC_ENTER, KC_TAB,

      KC_QUES,            KC_1,        KC_3,        KC_5,      KC_7,     KC_9,     KC_EQL,
      KC_ESC,             KC_J,        KC_L,        KC_U,      KC_Y,     KC_SCLN,  KC_RBRC,
      KC_RALT,            KC_K,        KC_N,        KC_E,      KC_I,     KC_O,     KC_QUOT,
      KC_RSPC,            KC_M,        KC_H,        KC_COMM,   KC_DOT,   KC_SLASH, KC_BSLS,
      KC_BSPC,   KC_SPC,               KC_DOWN,     KC_UP,     KC_QUES,  KC_QUES,  KC_QUES
),

[_FUNC] = LAYOUT(
      KC_MINS,   KC_0,    KC_8,        KC_6,        KC_4,      KC_2,               KC_LGUI,
      KC_LBRC,   KC_Q,    KC_W,        KC_F,        KC_P,      KC_B,               KC_LCTL,
      KC_GRV,    KC_A,    KC_R,        KC_S,        KC_T,      KC_G,               KC_QUES,
      KC_QUES,   KC_Z,    KC_X,        KC_C,        KC_D,      KC_V,               KC_LSPO,
      KC_QUES,   KC_QUES, KC_QUES,     KC_LEFT,     KC_RIGHT,            KC_ENTER, KC_TAB,

      KC_QUES,            KC_1,        KC_3,        KC_5,      KC_7,     KC_9,     KC_EQL,
      KC_ESC,             KC_J,        KC_L,        KC_U,      KC_Y,     KC_SCLN,  KC_RBRC,
      KC_RALT,            KC_K,        KC_N,        KC_E,      KC_I,     KC_O,     KC_QUOT,
      KC_RSPC,            KC_M,        KC_H,        KC_COMM,   KC_DOT,   KC_SLASH, KC_BSLS,
      KC_BSPC,   KC_SPC,               KC_DOWN,     KC_UP,     KC_QUES,  KC_QUES,  KC_QUES
)

[_VIM] = LAYOUT(
      KC_MINS,   KC_0,    KC_8,        KC_6,        KC_4,      KC_2,               KC_LGUI,
      KC_LBRC,   KC_Q,    KC_W,        KC_F,        KC_P,      KC_B,               KC_LCTL,
      KC_GRV,    KC_A,    KC_R,        KC_S,        KC_T,      KC_G,               KC_QUES,
      KC_QUES,   KC_Z,    KC_X,        KC_C,        KC_D,      KC_V,               KC_LSPO,
      KC_QUES,   KC_QUES, KC_QUES,     KC_LEFT,     KC_RIGHT,            KC_ENTER, KC_TAB,

      KC_QUES,            KC_1,        KC_3,        KC_5,      KC_7,     KC_9,     KC_EQL,
      KC_ESC,             KC_J,        KC_L,        KC_U,      KC_Y,     KC_SCLN,  KC_RBRC,
      KC_RALT,            KC_K,        KC_N,        KC_E,      KC_I,     KC_O,     KC_QUOT,
      KC_RSPC,            KC_M,        KC_H,        KC_COMM,   KC_DOT,   KC_SLASH, KC_BSLS,
      KC_BSPC,   KC_SPC,               KC_DOWN,     KC_UP,     KC_QUES,  KC_QUES,  KC_QUES
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}
