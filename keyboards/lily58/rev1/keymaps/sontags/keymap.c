#include QMK_KEYBOARD_H

// Home row mods using Mod-Tap
#define HRM_A LSFT_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LGUI_T(KC_F)
#define HRM_J RGUI_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_SCLN RSFT_T(KC_SCLN)

// Tap dance declarations
enum {
    TD_SPC_MOUSE,
};

// Tap dance state tracking
typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD,
} td_state_t;

static td_state_t td_state = TD_NONE;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
    }
    return TD_NONE;
}

void td_spc_mouse_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(3);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_SPC);
            break;
        default:
            break;
    }
}

void td_spc_mouse_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_HOLD:
            layer_off(3);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_SPC);
            break;
        default:
            break;
    }
    td_state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spc_mouse_finished, td_spc_mouse_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base QWERTY with home-row mods
    [0] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO,   HRM_A,   HRM_S,   HRM_D,   HRM_F,   LT(4,KC_G),                LT(4,KC_H), HRM_J, HRM_K,   HRM_L,   HRM_SCLN,KC_NO,
        KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                                   KC_NO,   KC_NO,   MO(1),   TD(TD_SPC_MOUSE), KC_ENT,  MO(2),   KC_NO,   KC_NO
    ),
    // Layer 1: Function keys and numbers
    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
        KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_NO,   KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_RBRC, KC_NO,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // Layer 2: Symbols and navigation
    [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_NO,                     KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
        KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_PERC, KC_NO,                     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        KC_NO,   KC_TILD, KC_PIPE, KC_BSLS, KC_GRV,  KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // Layer 3: Mouse keys
    [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NO,
        KC_NO,   MS_BTN4, MS_BTN3, MS_BTN2, MS_BTN1, KC_NO,                     KC_NO,   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    // Layer 4: Additional symbols (brackets, quotes, backspace, escape)
    [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_ESC,  KC_MINS, KC_UNDS, KC_LPRN, RSFT(KC_W),                LSFT(KC_E), KC_RPRN, KC_PLUS, KC_EQL, KC_BSPC, KC_NO,
        KC_NO,   KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_TILD, KC_QUOT, KC_DQUO, KC_PSLS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_BSLS, KC_NO,   KC_LCBR, KC_PIPE, KC_NO,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
