#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  | Del  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc/Gui|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '"/Ctrl|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *    | ~L1 |Up/Ctrl|Down/Alt|Left/L2|Right/Gui|                                | =/L2 |   -  |   [  |   ]  | ~L1 |
 *    `----------------------------------------'                                `---------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |Alt/Esc| LGui |       | Up   |Down/Gui|
 *                               ,-------|-------|------|       |------+--------+-------.
 *                               |       |       | PgUp |       | Home |        |       |
 *                               |Backsps| Space |------|       |------| Enter  | Space |
 *                               |       |       | PgDn |       | End  |        |       |
 *                               `----------------------'       `------------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,        KC_1, KC_2, KC_3, KC_4, KC_5, KC_DELT,
        KC_TAB,        KC_Q, KC_W, KC_E, KC_R, KC_T, TG(SYMB),
        GUI_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, ALL_T(KC_NO),
        KC_FN1,CTL_T(KC_UP), ALT_T(KC_DOWN),LT(MDIA, KC_LEFT),GUI_T(KC_RGHT),
                                                     ALT_T(KC_ESC), KC_LGUI,
                                                                    KC_PGUP,
                                                     KC_BSPC,KC_SPC,KC_PGDN,
        // right hand
        KC_ESC,       KC_6, KC_7,  KC_8,   KC_9,   KC_0,    KC_MINS,
        TG(SYMB),     KC_Y, KC_U,  KC_I,   KC_O,   KC_P,    KC_BSLS,
                      KC_H, KC_J,  KC_K,   KC_L,   KC_SCLN, CTL_T(KC_QUOT),
        MEH_T(KC_NO), KC_N, KC_M,  KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
                            KC_EQL,KC_MINS,KC_LBRC,KC_RBRC, KC_FN1,
        KC_UP,GUI_T(KC_DOWN),
        KC_HOME,
        KC_END,KC_ENT,KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Calc |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
        // left hand
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
        KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
        KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
        KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                 KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_0,   KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_CALC,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Lclk | Rclk |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Fwd   |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                            KC_TRNS, KC_TRNS,
                                                     KC_TRNS,
                                   KC_BTN1, KC_BTN2, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_WBAK, KC_WFWD
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }

    return MACRO_NONE;
};

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

    switch (layer) {
        case SYMB: // green light
            ergodox_right_led_2_on();
            break;
        case MDIA: // blue light
            ergodox_right_led_3_on();
            break;
        default: // none
            break;
    }
};
