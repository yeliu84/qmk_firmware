#include QMK_KEYBOARD_H

enum tokyo60_layers {
    L0,
    L1,
    L2,
    L3,
};

#define AGUI(kc) LALT(LGUI(kc))
#define CGUI(kc) LCTL(LGUI(kc))
#define SAG(kc) LSFT(LALT(LGUI(kc)))
#define SCG(kc) LSFT(LCTL(LGUI(kc)))

/*
#define BL 0
#define FN 1
*/

/*
 * Default HHKB Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BkSpc│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Ctrl │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │█████│Enter│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│█████│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │█████│Shift│ Fn  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│█████│ Alt │ Gui │█████│█████│Space│█████│█████│█████│█████│█████│ Gui │ Alt │█████│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
[BL] = LAYOUT_60_hhkb(
        KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_GRV, \
        KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,      \
        KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      \
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,      KC_RSFT, MO(FN), \
             KC_LALT, KC_LGUI,              KC_SPC,                         KC_RGUI, KC_RALT ),
    1: HHKB Fn layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ Pwr │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Caps │ RGB │RGBfw│RGBrv│BLtog│BLstp│     │     │ Psc │ Slk │ Pus │ Up  │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │ VoD │ VoU │ Mut │ Ejc │     │NP_* │NP_/ │Home │PgUp │Left │Right│█████│NPEnt│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │█████│     │     │     │     │     │NP_+ │NP_- │ End │PgDwn│Down │█████│     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│█████│     │     │█████│█████│█████│     │█████│█████│█████│█████│     │     │█████│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
[FN]= LAYOUT_60_hhkb(
       KC_PWR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL, \
       KC_CAPS, RGB_TOG, RGB_MOD, RGB_RMOD, BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP, KC_TRNS, KC_TRNS,  \
       KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,       KC_PENT,       \
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS,  KC_END, KC_PGDN, KC_DOWN,       KC_TRNS, KC_TRNS, \
             KC_TRNS, KC_TRNS,                   KC_TRNS,                         KC_TRNS, KC_TRNS ),
     */
    [L0] = LAYOUT_60_hhkb(
        KC_GRV,         KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSPC, \
        LALT_T(KC_TAB), KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,      \
        LT(L1, KC_ESC), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,      \
        KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, MO(L2), \
             KC_LALT, KC_LGUI,              KC_SPC,                         KC_RGUI, MO(L3)
    ),
    [L1] = LAYOUT_60_hhkb(
        KC_ESC,     C(KC_1),    C(KC_2),   C(KC_3),   C(KC_4),   C(KC_5),   C(KC_6),   C(KC_7),   C(KC_8),  C(KC_9),     C(KC_0),    C(KC_MINS),    C(KC_EQL), C(KC_BSPC), C(KC_BSPC), \
        C(KC_TAB),  C(KC_Q),    C(KC_W),   C(KC_E),   C(KC_R),   C(KC_T),   C(KC_Y),   C(KC_U),   C(KC_I),  C(KC_O),     C(KC_P),    SGUI(KC_LBRC), SGUI(KC_RBRC), C(KC_BSLS),      \
        _______,    C(KC_A),    C(KC_S),   C(KC_D),   C(KC_F),   C(KC_G),   KC_LEFT,   KC_DOWN,   KC_UP,    KC_RIGHT,    C(KC_SCLN), C(KC_QUOT),                    C(KC_ENT),      \
        KC_LSFT,             C(KC_Z),   C(KC_X),   C(KC_C),   C(KC_V),   C(KC_B),   C(KC_N),   C(KC_M),  C(KC_COMM),  C(KC_DOT),  C(KC_SLSH),          C(KC_RSFT), _______, \
             C(KC_LALT), C(KC_LGUI),              C(KC_SPC),                         C(KC_RGUI), C(KC_RALT)
    ),
    [L2] = LAYOUT_60_hhkb(
        KC_ESC,  KC_F1,         KC_F2,        KC_F3,     KC_F4,       KC_F5,       KC_F6,        KC_F7,     KC_F8,       KC_F9,    KC_F10,     KC_F11,   KC_F12,   _______, SGUI(KC_F12), \
        _______, _______,       _______,      _______,   S(KC_F6),    A(KC_F12),   _______,      _______,   AGUI(KC_I),  _______,  SAG(KC_P),  _______,  _______,  _______,      \
        KC_LCTL, SGUI(KC_A),    SGUI(KC_F),   _______,   A(KC_F1),    _______,     _______,      _______,   AGUI(KC_K),  _______,  _______,    _______,            _______,      \
        _______,                _______,      _______,   LCA(KC_I),   _______,     CGUI(KC_B),   _______,   _______,     _______,  _______,    _______,  _______,  _______, \
             _______, _______,              _______,                         _______, _______
    ),
    [L3] = LAYOUT_60_hhkb(
        KC_ESC,  _______,         _______,        _______,   SCG(KC_4),    SGUI(KC_5),     _______,      _______,   _______,       _______,        _______,        _______,     _______,  _______, _______, \
        _______, LCA(KC_Q),       SCG(KC_W),      _______,   A(KC_F11),    SGUI(KC_F12),   _______,      _______,   _______,       _______,        SCG(KC_P),      _______,     _______,  SGUI(KC_5),      \
        _______, _______,         _______,        _______,   _______,      _______,        _______,      _______,   _______,       _______,        _______,        _______,               _______,      \
        _______,                  _______,        _______,   _______,      _______,        _______,      _______,   _______,       AGUI(KC_LEFT),  AGUI(KC_RIGHT), AGUI(KC_F),  _______,  _______, \
             _______, _______,              _______,                         _______, _______
    ),
};


