/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_spanish.h>
#include "quantum.h"

// This section maps keycodes to spanish layout
/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ º │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ' │ ¡ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ ` │ + │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ñ │ ´ │ Ç │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ - │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define ES_MORD KC_GRV  // º
#define ES_1    KC_1    // 1
#define ES_2    KC_2    // 2
#define ES_3    KC_3    // 3
#define ES_4    KC_4    // 4
#define ES_5    KC_5    // 5
#define ES_6    KC_6    // 6
#define ES_7    KC_7    // 7
#define ES_8    KC_8    // 8
#define ES_9    KC_9    // 9
#define ES_0    KC_0    // 0
#define ES_QUOT KC_MINS // '
#define ES_IEXL KC_EQL  // ¡
// Row 2
#define ES_Q    KC_Q    // Q
#define ES_W    KC_W    // W
#define ES_E    KC_E    // E
#define ES_R    KC_R    // R
#define ES_T    KC_T    // T
#define ES_Y    KC_Y    // Y
#define ES_U    KC_U    // U
#define ES_I    KC_I    // I
#define ES_O    KC_O    // O
#define ES_P    KC_P    // P
#define ES_GRV  KC_LBRC // ` (dead)
#define ES_PLUS KC_RBRC // +
// Row 3
#define ES_A    KC_A    // A
#define ES_S    KC_S    // S
#define ES_D    KC_D    // D
#define ES_F    KC_F    // F
#define ES_G    KC_G    // G
#define ES_H    KC_H    // H
#define ES_J    KC_J    // J
#define ES_K    KC_K    // K
#define ES_L    KC_L    // L
#define ES_NTIL KC_SCLN // Ñ
#define ES_ACUT KC_QUOT // ´ (dead)
#define ES_CCED KC_NUHS // Ç
// Row 4
#define ES_LABK KC_NUBS // <
#define ES_Z    KC_Z    // Z
#define ES_X    KC_X    // X
#define ES_C    KC_C    // C
#define ES_V    KC_V    // V
#define ES_B    KC_B    // B
#define ES_N    KC_N    // N
#define ES_M    KC_M    // M
#define ES_COMM KC_COMM // ,
#define ES_DOT  KC_DOT  // .
#define ES_MINS KC_SLSH // -

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ª │ ! │ " │ · │ $ │ % │ & │ / │ ( │ ) │ = │ ? │ ¿ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ^ │ * │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ ¨ │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │   │   │   │   │   │   │   │ ; │ : │ _ │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define ES_FORD S(ES_MORD) // ª
#define ES_EXLM S(ES_1)    // !
#define ES_DQUO S(ES_2)    // "
#define ES_BULT S(ES_3)    // ·
#define ES_DLR  S(ES_4)    // $
#define ES_PERC S(ES_5)    // %
#define ES_AMPR S(ES_6)    // &
#define ES_SLSH S(ES_7)    // /
#define ES_LPRN S(ES_8)    // (
#define ES_RPRN S(ES_9)    // )
#define ES_EQL  S(ES_0)    // =
#define ES_QUES S(ES_QUOT) // ?
#define ES_IQUE S(ES_IEXL) // ¿
// Row 2
#define ES_CIRC S(ES_GRV)  // ^ (dead)
#define ES_ASTR S(ES_PLUS) // *
// Row 3
#define ES_DIAE S(ES_ACUT) // ¨ (dead)
// Row 4
#define ES_RABK S(ES_LABK) // >
#define ES_SCLN S(KC_COMM) // ;
#define ES_COLN S(KC_DOT)  // :
#define ES_UNDS S(ES_MINS) // _

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ \ │ | │ @ │ # │ ~ │ € │ ¬ │   │   │   │   │   │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ [ │ ] │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ { │ } │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define ES_BSLS ALGR(ES_MORD) // (backslash)
#define ES_PIPE ALGR(ES_1)    // |
#define ES_AT   ALGR(ES_2)    // @
#define ES_HASH ALGR(ES_3)    // #
#define ES_TILD ALGR(ES_4)    // ~
#define ES_EURO ALGR(ES_5)    // €
#define ES_NOT  ALGR(ES_6)    // ¬
// Row 2
#define ES_LBRC ALGR(ES_GRV)  // [
#define ES_RBRC ALGR(ES_PLUS) // ]
// Row 3
#define ES_LCBR ALGR(ES_ACUT) // {
#define ES_RCBR ALGR(ES_CCED) // }

// shutdown oled
void suspend_power_down_user(void) {
  oled_off();
  if (!is_keyboard_master())
  {
    oled_off();
  }
}


extern keymap_config_t keymap_config;

enum {
  TD_PAC,
  TD_CAPS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PAC] = ACTION_TAP_DANCE_DOUBLE(ES_LABK, ES_RABK),
  [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LSFT_T(KC_ESC),KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RSFT_T(KC_ENT) ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, RSFT_T(KC_SLSH), RCTL_T(ES_QUES),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(1),LALT(KC_TAB),     KC_SPC,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_F5,                         KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, ES_QUES, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ES_GRV, TD(TD_PAC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     KC_SPC,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    ES_FORD, ES_EXLM,   ES_DQUO, ES_BULT,  ES_DLR, ES_PERC,                      ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_F4), XXXXXXX,                      XXXXXXX, ES_ACUT, ES_CCED, ES_PLUS,ALGR(ES_QUOT),XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,S(ES_ACUT),S(ES_CCED),S(ES_PLUS),ALGR(ES_CCED),XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    //return OLED_ROTATION_270;
    return OLED_ROTATION_180;
  } else {
    return OLED_ROTATION_270;
  }
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_ln_P(PSTR("Layer"), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            oled_write_ln_P(PSTR(" "), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  //snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           //record->event.key.row, record->event.key.col,
           //keycode, name);
  snprintf(keylog_str, sizeof(keylog_str), "Key : %c", name);
}

void render_keylock_status(uint8_t led_usb_state) {
  oled_write_P(PSTR("Lock:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("NUM"), led_usb_state & (1 << USB_LED_NUM_LOCK));
  oled_write_P(PSTR("CAPS"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
  oled_write_ln_P(PSTR("SCL"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
  oled_write_ln_P(PSTR(" "), false);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_pattern(void) {
  static const char PROGMEM pattern_1[] = {
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 
    0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 
    0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 
    0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 
    0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 
    0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 
    0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 
    0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 
    0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6, 0x6c, 0x39, 0x93, 0x39, 0x6c, 0xc6, 0x93, 0x39, 0x93, 0xc6
  };
  oled_write_raw_P(pattern_1, 512);
}

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       70

/* advanced settings */
#    define ANIM_FRAME_DURATION 180  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
      anim_timer = timer_read32();
      animate_luna();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
      oled_on();
      anim_sleep = timer_read32();
      
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
      /* clear */
      oled_set_cursor(0,0);
      oled_write("                                                                                                    ", false);
      oled_off();
      oled_set_cursor(LUNA_X,LUNA_Y); 
    }
}

/* KEYBOARD PET END */

bool oled_task_user(void) {
    if (is_keyboard_master()) {
      current_wpm   = get_current_wpm();
      led_usb_state = host_keyboard_led_state();

      oled_render_layer_state();
      //oled_render_keylog();
      //oled_render_windows_logo();
      
      // print caps state
      oled_set_cursor(0, 4);
      oled_write_P(led_usb_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);


      /* wpm counter */
      uint8_t n = get_current_wpm();
      char    wpm_str[4];
      oled_set_cursor(0, 6);
      oled_write("wpm: ", false);
      oled_set_cursor(0, 7);
      wpm_str[3] = '\0';
      wpm_str[2] = '0' + n % 10;
      wpm_str[1] = '0' + (n /= 10) % 10;
      wpm_str[0] = '0' + n / 10;
      oled_write(wpm_str, false);


      render_luna(0, 13);

    } else {
      //oled_render_logo();
      oled_set_cursor(0, 0);
      oled_render_pattern();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //if (record->event.pressed) {
    //set_keylog(keycode, record);
  //}
  switch (keycode)
  {
    /* KEYBOARD PET STATUS START */

    case KC_LCTL:
    case KC_RCTL:
        if (record->event.pressed) {
            isSneaking = true;
        } else {
            isSneaking = false;
        }
        break;
    case KC_SPC:
        if (record->event.pressed) {
            isJumping  = true;
            showedJump = false;
        } else {
            isJumping = false;
        }
        break;

        /* KEYBOARD PET STATUS END */
  }
  return true;
}