/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _L0,  // base layer
    _LF1, // fn layer 1
    _LF2, // fn layer 2
    _LC   // ctrl layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_L0] = LAYOUT_tkl_ansi(
        KC_ESC,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,       KC_PSCR, KC_SCRL, KC_BRK,
        KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
        LALT_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN,
        LT(_LC, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_LSFT,                  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,               KC_UP,
        KC_LCTL,         KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(_LF1), KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_LF1] = LAYOUT_tkl_ansi(
        QK_BOOT,             _______,    _______, _______,     _______,      _______,     _______, _______,          _______,             KC_MSTP,              KC_MPLY,          KC_MPRV,       KC_MNXT,           KC_MUTE,  KC_VOLD,  KC_VOLU,
        _______, KC_F1,      KC_F2,      KC_F3,   KC_F4,       KC_F5,        KC_F6,       KC_F7,   KC_F8,            KC_F9,               KC_F10,               KC_F11,           KC_F12,        SGUI(KC_F12),      _______,  _______,  _______,
        KC_TAB,  _______,    _______,    _______, LSFT(KC_F6), LALT(KC_F12), _______,     _______, _______,          _______,             SGUI(LALT(KC_P)),     SGUI(KC_LBRC),    SGUI(KC_RBRC), _______,           _______,  _______,  _______,
        KC_CAPS, SGUI(KC_A), SGUI(KC_F), _______, LALT(KC_F1), _______,      _______,     _______, LALT(LGUI(KC_K)), _______,             _______,              _______,                         KC_MSEL,
        _______,             _______,    _______, LCA(KC_I),   _______,      _______,     _______, _______,          LALT(LGUI(KC_LEFT)), LALT(LGUI(KC_RIGHT)), LALT(LGUI(KC_F)),                _______,                     _______,
        _______, _______,    _______,                                        LCA(KC_SPC),                                                 _______,              MO(_LF2),         _______,       _______,           _______,  _______,  _______
    ),
    [_LF2] = LAYOUT_tkl_ansi(
        _______,            _______, _______, _______,      _______,      _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,
        _______, _______,   _______, _______, _______,      _______,      _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,
        _______, LCA(KC_Q), _______, _______, LALT(KC_F11), SGUI(KC_F12), _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,
        _______, _______,   _______, _______, _______,      _______,      _______, _______, _______, _______, _______, _______,          _______,
        _______,            _______, _______, _______,      _______,      _______, _______, _______, _______, _______, _______,          _______,               _______,
        _______, _______,   _______,                                      _______,                            _______, _______, _______, _______,      _______, _______, _______
    ),
    [_LC] = LAYOUT_tkl_ansi(
        LCTL(KC_ESC),                 LCTL(KC_F1),   LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5), LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8),    LCTL(KC_F9),   LCTL(KC_F10),   LCTL(KC_F11),   LCTL(KC_F12),      _______,       _______,       _______,
        LCTL(KC_GRV),  LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),  LCTL(KC_4),  LCTL(KC_5),  LCTL(KC_6),  LCTL(KC_7),  LCTL(KC_8),  LCTL(KC_9),     LCTL(KC_0),    LCTL(KC_MINUS), LCTL(KC_EQUAL), LCTL(KC_BSPC),     _______,       _______,       _______,
        LCTL(KC_TAB),  LCTL(KC_Q),    LCTL(KC_W),    LCTL(KC_E),  LCTL(KC_R),  LCTL(KC_T),  LCTL(KC_Y),  LCTL(KC_U),  LCTL(KC_I),  LCTL(KC_O),     LCTL(KC_P),    SGUI(KC_LBRC),  SGUI(KC_RBRC),  LCTL(KC_BSLS),     _______,       _______,       _______,
        _______,       LCTL(KC_A),    LCTL(KC_S),    LCTL(KC_D),  LCTL(KC_F),  LCTL(KC_G),  KC_LEFT,     KC_DOWN,     KC_UP,       KC_RGHT,        LCTL(KC_SCLN), LCTL(KC_QUOTE),                 LCTL(KC_ENTER),
        LCTL(KC_LSFT),                LCTL(KC_Z),    LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  LCTL(KC_B),  LCTL(KC_N),  LCTL(KC_M),  LCTL(KC_COMMA), LCTL(KC_DOT),  LCTL(KC_SLASH),                 LCTL(KC_RSFT),                    LCTL(KC_UP),
        KC_LCTL,       LCTL(KC_LALT), LCTL(KC_LGUI),                                        LCTL(KC_SPACE),                                        LCTL(KC_RGUI), LCTL(KC_RALT),  _______,        KC_RCTL,           LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT)
    ),
};