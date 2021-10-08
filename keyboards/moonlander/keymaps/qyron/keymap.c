/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,           KC_RBRC, KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,            KC_MPLY, KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,           KC_SLSH, KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT,
        KC_MUTE, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,          KC_INS,            KC_DEL,           KC_RGUI,  KC_LALT,  KC_LEFT,  KC_DOWN,  KC_RIGHT,
                                            KC_ENT,  MO(1),   TG(1),             KC_CAPS, MO(1),   KC_SPC
    ),

    [SYMB] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,            KC_F12,  KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
        _______, _______, _______, _______, _______, RGB_TOG, _______,           KC_VOLU, _______, _______,  _______,  _______,  _______,  _______,
        _______, _______, _______, _______, _______, _______, _______,           KC_VOLD, _______, _______,  _______,  _______,  _______,  _______,
        _______, _______, _______, _______, _______, _______,                             KC_MPRV, KC_MNXT,  _______,  _______,  _______,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______,  _______,  _______,  _______,  _______,
                                            _______, _______, _______,           _______,_______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ML_LED_1(0);
    ML_LED_2(0);
    ML_LED_3(0);
    ML_LED_4(0);
    ML_LED_5(0);
    ML_LED_6(0);
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
      ML_LED_1(1);
      ML_LED_4(1);
    }
    switch (layer) {
        case 1:
            ML_LED_2(1);
            ML_LED_5(1);
            break;
        /* case 2: */
        /*     ergodox_right_led_3_on(); */
        /*     break; */
        default:
            // none
            break;
    }

};
