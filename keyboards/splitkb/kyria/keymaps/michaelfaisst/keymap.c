/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    QWERTY = 0,
    LOWER = 1,
    RAISE = 2,
};


// Aliases for readability
#define SHIFT_SPACE  MT(MOD_LSFT, KC_SPACE)
#define CMD_ENT      MT(MOD_LGUI, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  " '   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |   ↑  |CapsLk|  | Del  |  ↓   |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |Option|Lower |LShift| Cmd  |  | Bspc | Tab  |Raise | Meh  |Hyper |
 *                        |      |      |      |Space | Enter|  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
     KC_ESC  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T   ,                                             KC_Y,      KC_U,  KC_I,    KC_O,   KC_P,    KC_BSLS,
     KC_LCTL , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G   ,                                             KC_H,      KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B   , KC_UP,       KC_CAPS,     KC_DEL,  KC_DOWN, KC_N,      KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                                _______, KC_LALT, MO(LOWER), SHIFT_SPACE, CMD_ENT,     KC_BSPC, KC_TAB,  MO(RAISE), KC_MEH, KC_HYPR
    ),

/*
 * Lower Layer: FN, Media, Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Play   | F1   | F2   | F3   | F4   | VolUp|                              | /    | 7 &  | 8 *  | 9 (  | +    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Next   | F5   | F6   | F7   | F8   | VolDn|                              | *    | 4 $  | 5 %  | 6 ^  | -    | =      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Prev   | F9   | F10  | F11  | F12  | Mute |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | ,    | .      |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LOWER] = LAYOUT(
      KC_MPRV, KC_F1, KC_F2,  KC_F4,   KC_VOLU, _______,                                     KC_PSLS,  KC_7, KC_8, KC_9, KC_PPLS, _______,
      KC_MNXT, KC_F5, KC_F2,  KC_F8,   KC_VOLU, _______,                                     KC_PAST,  KC_4, KC_5, KC_6, KC_PMNS, KC_PEQL,
      KC_MPRV, KC_F6, KC_F11, KC_F12,  KC_MUTE, _______, _______, _______, _______, _______, KC_0,     KC_1, KC_2, KC_3, KC_PCMM, KC_PDOT,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Raise layer: Symbols and navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |   _  |  %   |  $   |  €   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  <   |  >   |  (   |  )   |  &   |                              | Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ^   |  #   |  [   |  ]   |  ~   |      |      |  |      |      |   +  |  -   |  /   |  *   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RAISE] = LAYOUT(
     _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     KC_UNDS, KC_PERC, KC_DLR,  ALGR(KC_5), _______, _______,
     _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_AMPR,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,   _______, _______,
     _______, KC_CIRC, KC_HASH, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR,    _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
