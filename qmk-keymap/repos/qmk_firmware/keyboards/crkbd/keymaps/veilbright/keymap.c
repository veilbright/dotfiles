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
#define LGUI_H LGUI_T(KC_H)
#define LALT_I LALT_T(KC_I)
#define LCTL_E LCTL_T(KC_E)
#define LSFT_A LSFT_T(KC_A)

// Right hand Beakl home row
#define SHFT_T RSFT_T(KC_T)
#define RCTL_R RCTL_T(KC_R)
#define LALT_N LALT_T(KC_N)
#define RGUI_W RGUI_T(KC_W)

// Thumb Layers
#define FUNC_ESC LT(FUNCTION, KC_ESC)
#define NUM_SPC LT(NUMBER, KC_SPC)
#define NAV_TAB LT(NAVIGATION, KC_TAB)
#define SYM_S LT(SYMBOL, KC_S)

enum layers_names {
	BASE,
	FUNCTION,
	NUMBER,
	NAVIGATION,
	SYMBOL,
	MOUSE
};

// Base Layer Symbol Overrides
const key_override_t dot_plus_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_PLUS);
const key_override_t less_than_percent_override = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_PERCENT);
const key_override_t greater_than_dollar_override = ko_make_basic(MOD_MASK_SHIFT, KC_GT, KC_DOLLAR);
const key_override_t comma_semicolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t equal_minus_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_MINUS);

// Symbol Layer Symbol Overrides
const key_override_t hash_space_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_SPACE);
const key_override_t forward_back_slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH);
const key_override_t curly_braces_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t pipe_ampersand_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_AMPERSAND);
const key_override_t brackets_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_BRACKET, KC_RIGHT_BRACKET);
const key_override_t doublequote_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t parentheses_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
const key_override_t asterisk_exclaim_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_EXCLAIM);
const key_override_t grave_space_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRAVE, KC_SPACE);
const key_override_t colon_tilde_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_TILDE);
const key_override_t circumflex_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX, KC_AT);
const key_override_t underscore_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_QUESTION);

const key_override_t *key_overrides[] = {
	&dot_plus_override,
	&less_than_percent_override,
	&greater_than_dollar_override,
	&comma_semicolon_override,
	&equal_minus_override,
	&hash_space_override,
	&forward_back_slash_override,
	&curly_braces_override,
	&pipe_ampersand_override,
	&brackets_override,
	&doublequote_quote_override,
	&parentheses_override,
	&asterisk_exclaim_override,
	&grave_space_override,
	&colon_tilde_override,
	&circumflex_at_override,
	&underscore_question_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,     KC_Y,     KC_O,     KC_U,     KC_X,     /*|*/ KC_V,     KC_C,     KC_L,     KC_F,     KC_Z,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  LGUI_H,   LALT_I,   LCTL_E,   LSFT_A,   KC_DOT,   /*|*/ KC_G,     SHFT_T,   RCTL_R,   LALT_N,   RGUI_W,   XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  KC_J,     KC_LT,    KC_GT,    KC_COMM,  KC_EQL,   /*|*/ KC_B,     KC_D,     KC_M,     KC_P,     KC_K,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  FUNC_ESC, NUM_SPC,  NAV_TAB,  /*|*/ KC_BSPC,  SYM_S,    KC_ENT
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
  [NUMBER] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_4,     KC_5,     KC_6,     KC_9,     _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ _______,  KC_0,     _______
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
  [SYMBOL] = LAYOUT_split_3x6_3(
    _______,  _______,  KC_HASH,  KC_SLSH,  KC_LCBR,  _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  KC_PIPE,  KC_LBRC,  KC_DQUO,  KC_LPRN,  KC_ASTR,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  KC_GRV,   KC_COLN,  _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  KC_CIRC,  _______,  KC_UNDS,  /*|*/ _______,  _______,  _______
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
