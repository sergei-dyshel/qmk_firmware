#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LBRC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_EQL,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MINS,
        KC_TRNS,  KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,

                                                          KC_DEL,   KC_VOLU,
                                                                    KC_VOLD,
                                                KC_ENT,   MO(1),    TG(1),

        // right hand
        KC_RBRC,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
        KC_PGUP,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,
                  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
        KC_PGDN,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                            KC_RCTL,  KC_LALT,  KC_RGUI,  KC_RSFT,  KC_TRNS,

        KC_MPLY,  KC_INS,
        KC_MUTE,
        KC_CAPS,  MO(1),    KC_SPC
    ),

[1] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,
        KC_TRNS,  KC_EXLM,  KC_9,     KC_8,     KC_7,     KC_SLSH,  KC_TRNS,
        KC_TRNS,  KC_DOT,   KC_6,     KC_5,     KC_4,     KC_0,
        KC_TRNS,  KC_TRNS,  KC_3,     KC_2,     KC_1,     KC_COLN,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                          KC_TRNS,  KC_TRNS,
                                                                    KC_TRNS,
                                                KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
       KC_F12,  KC_F6,      KC_F7,      KC_F8,    KC_F9,       KC_F10,  KC_TRNS,
       KC_HOME, S(KC_LEFT), S(KC_DOWN), S(KC_UP), S(KC_RIGHT), KC_TRNS, KC_TRNS,
                KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_TRNS, KC_TRNS,
       KC_END,  KC_MPRV,    KC_MNXT,    KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
                            KC_TRNS,    KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK))
      ergodox_right_led_1_on();
    switch (layer) {
        case 1:
            ergodox_right_led_2_on();
            break;
        /* case 2: */
        /*     ergodox_right_led_3_on(); */
        /*     break; */
        default:
            // none
            break;
    }

};
