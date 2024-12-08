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

enum layers_names {
	BSE,
};

// Base Layer Symbol Overrides
const key_override_t dot_exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXCLAIM);
const key_override_t dquote_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t comma_slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SLASH);
const key_override_t scolon_bslash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SEMICOLON, KC_BACKSLASH);
const key_override_t ampersand_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_QUESTION);

const key_override_t *key_overrides[] = {
  &dot_exclamation_override,
  &dquote_quote_override,
  &comma_slash_override,
  &scolon_bslash_override,
  &ampersand_question_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BSE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,     KC_Y,     KC_O,     KC_U,     KC_X,     /*|*/ KC_V,     KC_C,     KC_L,     KC_F,     KC_Z,     QK_BOOT,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  LGUI_H,   LALT_I,   LCTL_E,   LSFT_A,   KC_DOT,   /*|*/ KC_G,     SHFT_T,   RCTL_R,   LALT_N,   RGUI_W,   XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  KC_J,     KC_AMPR,  KC_SCLN,  KC_COMM,  KC_DQT,   /*|*/ KC_B,     KC_D,     KC_M,     KC_P,     KC_K,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  KC_ESC,  KC_SPC,  KC_TAB,  /*|*/ KC_BSPC,    KC_S, KC_ENT
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
