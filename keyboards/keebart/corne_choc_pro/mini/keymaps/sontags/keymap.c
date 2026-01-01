#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3_ex2(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_NO,
        KC_NO,        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        LSFT_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), LT(4,KC_G),   KC_NO,
        KC_NO,        LT(4,KC_H),   RGUI_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,
                      KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                      KC_NO,        MO(1),        LT(3,KC_SPC),
                      KC_ENT,       MO(2),        KC_NO
    ),
    [1] = LAYOUT_split_3x5_3_ex2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
        KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,
                 KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_RBRC,
                 KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT_split_3x5_3_ex2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_PERC, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_TILD, KC_PIPE, KC_BSLS, KC_GRV,  KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT_split_3x5_3_ex2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
        MS_BTN4, MS_BTN3, MS_BTN2, MS_BTN1, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [4] = LAYOUT_split_3x5_3_ex2(
        KC_ESC,  KC_MINS, KC_UNDS, KC_LPRN, RSFT(KC_W), KC_NO,
        KC_NO,   LSFT(KC_E), KC_RPRN, KC_PLUS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,
        KC_TILD, KC_QUOT, KC_DQUO, KC_PSLS, KC_NO,
                 KC_NO,   KC_BSLS, KC_NO,   KC_LCBR,    KC_PIPE,
                 KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS
    )
};
