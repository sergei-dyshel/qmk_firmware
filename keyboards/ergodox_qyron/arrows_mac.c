const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LBRC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_EQL,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MINS,
        KC_LCTL,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,

                                                          KC_INS,   KC_VOLU,
                                                                    KC_VOLD,
                                                KC_ENT,   MO(1),    TG(1),

        // right hand
        KC_RBRC,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
        KC_TRNS,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,
                  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
        KC_SLSH,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT,
                            KC_RGUI,  KC_LALT,  KC_LEFT,  KC_DOWN,  KC_RIGHT,

        KC_MPLY,  KC_DEL,
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
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
                KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MPRV,    KC_MNXT,    KC_TRNS,  KC_TRNS,     KC_PGUP, KC_TRNS,
                            KC_TRNS,    KC_TRNS,  KC_HOME,     KC_PGDN, KC_END,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};
