#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

#include "keyboards/ergodox_qyron/current.c"

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
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){

    // uint8_t layer = get_highest_layer(layer_state);

    // ergodox_board_led_off();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();
    // if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK))
    //   ergodox_right_led_1_on();
    // switch (layer) {
    //     case 1:
    //         ergodox_right_led_2_on();
    //         break;
    //     default:
    //         // none
    //         break;
    // }
};

#ifdef ST7565_ENABLE
void st7565_task_user(void) {
    ergodox_infinity_lcd_color(UINT16_MAX / 8, UINT16_MAX / 8, UINT16_MAX / 8);
    if (host_keyboard_led_state().caps_lock) {
        ergodox_infinity_lcd_color(UINT16_MAX / 2, 0, 0); // red
    }
    else if (get_highest_layer(layer_state) == 1) {
        ergodox_infinity_lcd_color(0, 0, UINT16_MAX / 2); // blue
    }
    else if (get_highest_layer(layer_state) == 2) {
        ergodox_infinity_lcd_color(0, UINT16_MAX / 2, 0); // green
    }
    st7565_write_ln(QMK_VERSION, false);
    st7565_write_ln(QMK_BUILDDATE, false);
}

void st7565_on_user(void) {}

void st7565_off_user(void) {}

#endif
