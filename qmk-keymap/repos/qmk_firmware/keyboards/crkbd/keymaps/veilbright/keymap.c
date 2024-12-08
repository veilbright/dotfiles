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

/*#include <stdbool.h>*/
/*#include <stdint.h>*/
/*#include "action.h"*/
/*#include "keycodes.h"*/
/*#include "keymap_us.h"*/
/*#include "modifiers.h"*/
/*#include "quantum.h"*/
/*#include "quantum_keycodes.h"*/
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
#define FUN_ESC LT(_COMMAND, KC_ESC)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_S LT(_SYM, KC_S)
#define MOUS_BSP LT(_MOUSE, KC_BSPC)
#define COM_ENT LT(_FUN, KC_ENT)

enum layer_names {
  BSE, // base
  _COMMAND,
  _NAV,
  _MOUSE,
  _NUM,
  _SYM,
  _FUN,
};

// Base Layer Symbol Overrides
const key_override_t dot_exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXCLAIM);
const key_override_t dquote_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t comma_slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SLASH);
const key_override_t scolon_bslash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SEMICOLON, KC_BACKSLASH);
const key_override_t ampersand_question_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_QUESTION);

// Symbol Layer Symbol Overrides
const key_override_t grave_tilde_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRAVE, KC_TILDE);
const key_override_t right_cbrace_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_CURLY_BRACE, KC_RIGHT_BRACKET);
const key_override_t right_parenthesis_abracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_PAREN, KC_RIGHT_ANGLE_BRACKET);
const key_override_t at_dollar_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_DOLLAR);
const key_override_t left_cbrace_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET);
const key_override_t left_parenthesis_abracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_LEFT_ANGLE_BRACKET);
const key_override_t colon_hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_HASH);
const key_override_t pipe_underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_UNDERSCORE);
const key_override_t plus_percent_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_PERCENT);
const key_override_t equal_asterisk_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL, KC_ASTERISK);
const key_override_t minus_circumflex_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_CIRCUMFLEX);

const key_override_t *key_overrides[] = {
  &dot_exclamation_override,
  &dquote_quote_override,
  &comma_slash_override,
  &scolon_bslash_override,
  &ampersand_question_override,
  &grave_tilde_override,
  &right_cbrace_bracket_override,
  &right_parenthesis_abracket_override,
  &at_dollar_override,
  &left_cbrace_bracket_override,
  &left_parenthesis_abracket_override,
  &colon_hash_override,
  &pipe_underscore_override,
  &plus_percent_override,
  &equal_asterisk_override,
  &minus_circumflex_override
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BSE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,     KC_Y,     KC_O,     KC_U,     KC_X,     /*|*/ KC_V,     KC_C,     KC_L,     KC_F,     KC_Z,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  LGUI_H,   LALT_I,   LCTL_E,   LSFT_A,   KC_DOT,   /*|*/ KC_G,     SHFT_T,   RCTL_R,   LALT_N,   RGUI_W,   XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    XXXXXXX,  KC_J,     KC_AMPR,  KC_SCLN,  KC_COMM,  KC_DQT,   /*|*/ KC_B,     KC_D,     KC_M,     KC_P,     KC_K,     XXXXXXX,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  FUN_ESC,  NAV_TAB,  NUM_SPC,  /*|*/ SYM_S,    MOUS_BSP, COM_ENT
  ),
  [_FUN] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_F1,    KC_F2,    KC_F3,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,   /*|*/ KC_F4,    KC_F5,    KC_F6,    KC_F7,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_F8,    KC_F9,    _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_F10,   KC_F11,   KC_F12
  ),
  [_NAV] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_HOME,  KC_PGUP,  KC_WH_U,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_END,   KC_PGDN,  KC_WH_D,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_DEL,   KC_BSPC,  _______
  ),
  [_NUM] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_P1,    KC_P2,    KC_P3,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,   /*|*/ KC_P4,   KC_P5,    KC_P6,    KC_P7,    _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_P8,    KC_P9,    _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_P0,    _______,  _______
  ),
  [_SYM] = LAYOUT_split_3x6_3(
    _______,  _______,  KC_COLN,  KC_LCBR,  KC_RCBR,  _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_GRV,   /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  KC_AT,    _______,  /*|*/ _______,  _______,  _______,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  KC_MINS,  KC_EQL,   KC_PLUS,  /*|*/ _______,  _______,  _______
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  _______,  KC_WH_U,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  _______,  KC_WH_D,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_BTN2,  KC_BTN1,  KC_BTN3
  ),
  [_COMMAND] = LAYOUT_split_3x6_3(
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  KC_MPRV,  KC_MNXT,  KC_MUTE,  _______,  QK_BOOT,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ DM_RSTP,  DM_PLY1,  DM_PLY2,  KC_MUTE,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
    _______,  _______,  _______,  _______,  _______,  _______,  /*|*/ _______,  DM_REC1,  DM_REC2,  _______,  _______,  _______,
    /* - - - | - - - - | - - - - | - - - - | - - - - | - - - - -  |  - - - - - | - - - - | - - - - | - - - - | - - - - | - - - */
                                  _______,  _______,  _______,  /*|*/ KC_MPLY,  KC_VOLD,  KC_VOLU
  ),
};
