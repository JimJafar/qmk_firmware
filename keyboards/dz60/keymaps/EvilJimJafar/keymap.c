#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _CODING 1
#define _NAV 2
#define _NUM 3
#define _RGB 4

/* DZ60 layout using following options (from layouts diagram on KBDfans):
 *  - plate B (2.25u lshift)
 *  - opt 4 (1.75, 1, 1 on rshift)
 *  - opt 9 (2.25, 1.25, 2.75 on space, 5x1u bottom right keys)
 * http://www.keyboard-layout-editor.com/#/gists/c4e5f0c1c0d81692f2852a62867e75e8
 */

#define LAYOUT_b_4_9( \
        K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, \
        K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
        K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
        K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310,       K312, K313, K314, \
        K400, K401,       K403,       K404, K406,       K408,       K410, K411, K412, K413, K414  \
        ) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, K014 }, \
    { K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
    { K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO }, \
    { K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  KC_NO, K312,  K313,  K314 }, \
    { K400,  K401,  KC_NO, K403,  K404,  KC_NO, K406,  KC_NO, K408,  KC_NO, K410,  K411,  K412,  K413,  K414 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: basic qwerty */
    LAYOUT_b_4_9(
       // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------2.0-------|
            KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,      KC_BSPC,
       // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||----------------|
       //
       // |----1.5-----||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|----1.5-----|
             KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC,   KC_BSLS,
       // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
       //
       // |----1.75------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------2.25--------||
             KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,     KC_ENT,
       // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
       //
       // |------2.25--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||----1.75------|--------|--------||
               KC_LSHIFT,      KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  KC_UP, MO(_RGB),
       // |------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------||--------------|--------|--------||
       //
       // |---1.25---|---1.25---||---1.25---||--------2.25--------||---1.25---|------2.75----------||--------|--------|--------|--------|--------|
             KC_CAPS,  KC_LALT,    KC_LGUI,       MO(_CODING),       MO(_NAV),      KC_SPC,          TG(_NUM), KC_MPLY, KC_LEFT, KC_DOWN, KC_RGHT
       // |----------|----------||----------||--------------------||----------|--------------------||--------|--------|--------|--------|--------|
          ),

    [_CODING] = LAYOUT_b_4_9(
         KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_LBRC, _______, _______, KC_RBRC, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,  KC_GRV,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        _______, _______, _______,          _______, _______,          _______,          _______, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [_NAV] = LAYOUT_b_4_9(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_TILD,          _______,
        _______,          _______, _______, _______, _______, _______, KC_PGDN, _______, KC_PGUP, _______, _______, _______, _______,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT_b_4_9(
          TG(_NUM),KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PSLS, KC_PAST,  KC_PMNS,  KC_NO,   KC_NO, KC_BSPC,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,   KC_NO,   KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_NO,          KC_PENT,
          KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P1,   KC_P2,     KC_P3, KC_PEQL, KC_NO,   KC_NO,
          KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,            KC_P0,          KC_PDOT,     KC_NO, KC_NO,   KC_NO,   KC_NO
    ),
    [_RGB] = LAYOUT_b_4_9(
        RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______, _______,          _______,          _______, _______, _______, _______, _______
    )
};
