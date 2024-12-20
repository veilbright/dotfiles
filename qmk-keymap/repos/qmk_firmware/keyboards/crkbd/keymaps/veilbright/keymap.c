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

// Left hand Beakl home row
#define LSFT_A LSFT_T(KC_A)
#define LCTL_E LCTL_T(KC_E)
#define LALT_I LALT_T(KC_I)
#define LGUI_H LGUI_T(KC_H)

// Right hand Beakl home row
#define SHFT_T RSFT_T(KC_T)
#define RCTL_R RCTL_T(KC_R)
#define LALT_N RALT_T(KC_N)
#define RGUI_W RGUI_T(KC_W)

// Thumb Layers
#define FUNC_ESC LT(FUNCTION, KC_ESC)
#define NAV_SPC LT(NAVIGATION, KC_SPC)
#define NUM_TAB LT(NUMBER, KC_TAB)
#define SYM_S LT(SYMBOL, KC_S)

// Left hand Symbol thumb row
#define SHFT_TAB LSFT_T(KC_TAB)
#define LCTL_SPC LCTL_T(KC_SPC)
#define LALT_ESC LALT_T(KC_ESC)

enum layers_names {
	BASE,
	FUNCTION,
	NAVIGATION,
	NUMBER,
	SYMBOL,
	MOUSE
};

// Base Layer Symbol Overrides
const key_override_t base_override1 = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXCLAIM);
const key_override_t base_override2 = ko_make_basic(MOD_MASK_SHIFT, KC_SEMICOLON, KC_AT);
const key_override_t base_override3 = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_GRAVE);
const key_override_t base_override4 = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_QUESTION);
const key_override_t base_override5 = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);

// Symbol Layer Symbol Overrides
const key_override_t symbol_override1 = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_HASH);
const key_override_t symbol_override2 = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_AMPERSAND);
const key_override_t symbol_override3 = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH);
const key_override_t symbol_override4 = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_MINUS);
const key_override_t symbol_override5 = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_LT);
const key_override_t symbol_override6 = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_QUOTE);
const key_override_t symbol_override7 = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t symbol_override8 = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_COLON);
const key_override_t symbol_override9 = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_DOUBLE_QUOTE);
const key_override_t symbol_override10 = ko_make_basic(MOD_MASK_SHIFT, KC_GT, KC_GT);
const key_override_t symbol_override11 = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_PLUS);
const key_override_t symbol_override12 = ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX, KC_CIRCUMFLEX);
const key_override_t symbol_override13 = ko_make_basic(MOD_MASK_SHIFT, KC_PERCENT, KC_PERCENT);
const key_override_t symbol_override14 = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_BRACKET, KC_RIGHT_BRACKET);
const key_override_t symbol_override15 = ko_make_basic(MOD_MASK_SHIFT, KC_TILDE, KC_TILDE);
const key_override_t symbol_override16 = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, KC_DOLLAR);

const key_override_t *key_overrides[] = {
	&base_override1,
	&base_override2,
	&base_override3,
	&base_override4,
	&base_override5,
	&symbol_override1,
	&symbol_override2,
	&symbol_override3,
	&symbol_override4,
	&symbol_override5,
	&symbol_override6,
	&symbol_override7,
	&symbol_override8,
	&symbol_override9,
	&symbol_override10,
	&symbol_override11,
	&symbol_override12,
	&symbol_override13,
	&symbol_override14,
	&symbol_override15,
	&symbol_override16
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,     KC_Y,     KC_O,     KC_U,     KC_X,     /*|*/ KC_V,     KC_C,     KC_L,     KC_F,     KC_Z,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  LGUI_H,   LALT_I,   LCTL_E,   LSFT_A,   KC_DOT,   /*|*/ KC_G,     SHFT_T,   RCTL_R,   LALT_N,   RGUI_W,   XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  KC_J,     KC_SCLN,  KC_EQL,   KC_COMM,  KC_LPRN,  /*|*/ KC_B,     KC_D,     KC_M,     KC_P,     KC_K,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  FUNC_ESC, NAV_SPC,  NUM_TAB,  /*|*/ KC_BSPC,  SYM_S,    KC_ENT
  ),
  [FUNCTION] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_F1,    KC_F2,    KC_F3,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_F4,    KC_F5,    KC_F6,    KC_F9,    _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_F7,    KC_F8,    KC_F9,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_F10,   KC_F11,   KC_F12
  ),
  [NAVIGATION] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_HOME,  KC_PGUP,  KC_WH_U,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_END,   KC_PGDN,  KC_WH_D,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_BSPC,  MO(MOUSE),KC_DEL
  ),
  [NUMBER] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_4,     KC_5,     KC_6,     KC_9,     _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ _______,  KC_0,     _______
  ),
  [SYMBOL] = LAYOUT_split_3x6_3(
    _______,  _______,  KC_HASH,  KC_AMPR,  KC_SLSH,  _______,  /*|*/ _______,  KC_UNDS,  KC_PIPE,  KC_ASTR,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  KC_LT,    KC_MINS,  KC_QUOT,  KC_LCBR,  _______,  /*|*/ _______,  KC_COLN,  KC_DQUO,  KC_PLUS,  KC_GT,    _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  KC_CIRC,  KC_PERC,  KC_LBRC,  _______,  /*|*/ _______,  KC_TILD,  KC_DLR,   _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  LALT_ESC, LCTL_SPC, SHFT_TAB, /*|*/ _______,  _______,  _______
  ),
  [MOUSE] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  KC_BTN3,  KC_BTN2,  KC_BTN1,  _______,  /*|*/ KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ _______,  _______,  _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
