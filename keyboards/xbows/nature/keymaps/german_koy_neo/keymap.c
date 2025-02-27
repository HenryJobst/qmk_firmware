/* Copyright 2020 Shulin Huang <mumu@x-bows.com>
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

#include <keymap_german.h>
#include <keymap_neo2.h>

// Configure the global tapping term (default: 200ms)
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6
#define _LAYER7 7
#define _LAYER8 8

#define _KOY1 _LAYER0
#define _KOY2 _LAYER1
#define _KOY3 _LAYER2
#define _KOY4 _LAYER3
#define _KOY5 _LAYER4
#define _KOY6 _LAYER5

#define _XBOWS _LAYER6
#define _FUNC  _LAYER7

#define _MOUSE _LAYER8

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    LAYER7,
};

// shortcuts
#define K_DOTS RALT(KC_DOT)

// special modifier shortcuts and combinations
#define MO_KOY3 MO(_KOY3)
#define MO_KOY4 MO(_KOY4)
#define MO_FUNC MO(_FUNC)
#define MO_MOUS MO(_MOUSE)

#define MT_AS MT(MOD_LSFT,KC_A)
#define MT_NS MT(MOD_RSFT,KC_N)

#define MT_HS MT(MOD_LSFT,KC_H)
#define MT_SS MT(MOD_RSFT,KC_S)

#define MT_H3 MT(MO_KOY3,KC_H)
#define MT_S3 MT(MO_KOY3,KC_S)

#define MT_U4 MT(MO_KOY4,KC_U)
#define MT_D4 MT(MO_KOY4,KC_D)

#define MT_EC MT(KC_LCTL,KC_E)
#define MT_RC MT(KC_RCTL,KC_R)

#define MT_SPC3 MT(MO_KOY3, KC_SPC)
#define MT_SPC4 MT(MO_KOY4, KC_SPC)
#define MT_SPC8 MT(MO_MOUS, KC_SPC)

/* Common terminology for modifiers
Full Modifier Name 	Abbreviation 	Symbol
Shift               S 	          ⇧
Control 	          C 	          ⎈
Alt/Option 	        A            	⎇
GUI/Win/Command    	G 	          ◆
No modifier/mod-tap _ 	          _

*/

/* Abbreviations for home row mods */

// Layer 1 (Characters):
// Keys Left: H,A,E,I
// Keys Right: T,R,N,S

// Scheme: SCGA/⇧⎈◆⎇
// left-hand
#define LSFT_TH LSFT_T(KC_H)
#define LCTL_TA LCTL_T(KC_A)
#define LGUI_TE LGUI_T(KC_E)
#define LALT_TI LALT_T(KC_I)
// right-hand
#define RALT_TT LALT_T(KC_T)
#define RGUI_TR RGUI_T(KC_R)
#define RCTL_TN RCTL_T(KC_N)
#define RSFT_TS RSFT_T(KC_S)

// Scheme: GACS/◆⎇⎈⇧
// left-hand
#define LGUI_TH LGUI_T(KC_H)
#define LALT_TA LALT_T(KC_A)
#define LCTL_TE LCTL_T(KC_E)
#define LSFT_TI LSFT_T(KC_I)
// right-hand
#define RSFT_TT RSFT_T(KC_T)
#define RCTL_TR RCTL_T(KC_R)
#define RALT_TN LALT_T(KC_N)
#define RGUI_TS RGUI_T(KC_S)

// for Layer 4 (Movement/Numbers):
// Keys: KC_LEFT, KC_DOWN, KC_RGHT, KC_END
// Keys: DE_4, DE_5, DE_6, KC_COMM

// Scheme: SCGA/⇧⎈◆⎇
// left-hand
// no mods for the cursor keys, there will be hold often
//#define LSFT_TLEFT LSFT_T(KC_LEFT)
//#define LCTL_TDOWN LCTL_T(KC_DOWN)
//#define LGUI_TRGHT LGUI_T(KC_RGHT)
#define LALT_TEND  LALT_T(KC_END)
#define LSFT_THOME LSFT_T(KC_HOME) // move shift mod one key to the left
//#define LCTL_TTAB  LCTL_T(KC_TAB)  // move ctrl mod one key down
//#define LGUI_TINS  LGUI_T(KC_INS)  // move gui mod one key down
// right-hand
#define RALT_T4    RALT_T(DE_4)
#define RGUI_T5    RGUI_T(DE_5)
#define RCTL_T6    RCTL_T(DE_6)
#define RSFT_TCOMM RSFT_T(KC_COMM)

// Scheme: GACS/◆⎇⎈⇧
// left-hand
// no mods for the cursor keys, there will be hold often
//#define LGUI_TLEFT LGUI_T(KC_LEFT)
//#define LALT_TDOWN LALT_T(KC_DOWN)
//#define LCTL_TRGHT LCTL_T(KC_RGHT)
#define LSFT_TEND  LSFT_T(KC_END)
// right-hand
#define RSFT_T4    RSFT_T(DE_4)
#define RCTL_T5    RCTL_T(DE_5)
#define RALT_T6    RALT_T(DE_6)
#define RGUI_TCOMM RGUI_T(KC_COMM)

/*
X-Bow Nature
1. Zeile: 15 Tasten
2. Zeile: 14 Tasten
3. Zeile: 15 Tasten
4. Zeile: 15 Tasten
5. Zeile: 14 Tasten
6. Zeile: 13 Tasten
-------------------
Gesamt: 86 Tasten
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */

  [_KOY1] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,      KC_F6,      KC_F7,  KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,   KC_INS,             KC_DEL,
    DE_CIRC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                   KC_6,   KC_7,     KC_8,     KC_9,     KC_0,    NE_MINS,  NE_GRV,   KC_BSPC,
    KC_TAB,   KC_K,     KC_DOT,   KC_O,     KC_COMM,  KC_Z,                   KC_V,   KC_G,     KC_C,     KC_L,     DE_SS,   KC_Y,     DE_ACUT,  KC_RALT,  KC_LNUM,
    // Scheme: SCGA/⇧⎈◆⎇
    // Do not use mod tab GA on left side because of often missuse
    MO_KOY3,  LSFT_TH,  LCTL_TA,  KC_E,     KC_I,     KC_U,       MO_MOUS,    KC_D,   RALT_TT,  RGUI_TR,  RCTL_TN,  RSFT_TS, KC_F,     MO_KOY3,            KC_ENT,
    // Scheme: GACS/◆⎇⎈⇧
    //MO_KOY3,  LGUI_TH,  LALT_TA,  LCTL_TE,  LSFT_TI,  KC_U,       MO_MOUS,    KC_D,   RSFT_TT,  RCTL_TR,  RALT_TN,  RGUI_TS, KC_F,     MO_KOY3,            KC_ENT,
    MO_KOY4,  KC_X,     KC_Q,     DE_ADIA,  DE_UDIA,  DE_ODIA,    KC_ENT,     KC_B,   KC_P,     KC_W,     KC_M,     KC_J,    KC_RSFT,            KC_UP,
    KC_LCTL,  KC_LGUI,  KC_LALT,            MO_KOY3,          KC_SPC, KC_SPC, MO_KOY4,          KC_RALT,            MO_FUNC, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  [_KOY2] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,    _______,    DE_EURO, _______, _______,  _______,  _______, _______,  _______,            _______,
    _______,  DE_DEG,   DE_SECT,  _______,  _______,  _______,                _______, _______, _______,  _______,  _______, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                _______, _______, _______,  _______,  _______, _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______, _______, _______,  _______,  _______, _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______, _______, _______,  _______,  _______, _______,            _______,
    _______,  _______,  _______,            _______,         _______, _______,_______,          _______,            _______, _______,  _______,  _______,  _______),

  [_KOY3] = LAYOUT(
    QK_BOOT,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,     KC_F18,     KC_F19,  KC_F20,  KC_F21,   KC_F22,   KC_F23,  KC_F24,   KC_PAUS,            KC_PSCR,
    XXXXXXX,  XXXXXXX,  DE_SUP2,  DE_SUP3,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  K_DOTS,   DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,                DE_EXLM, DE_LABK, DE_RABK,  DE_EQL,   DE_AMPR, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,    XXXXXXX,    DE_QUES, DE_LPRN, DE_RPRN,  DE_MINS,  DE_COLN, DE_AT,    _______,            _______,
    _______,  DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,     XXXXXXX,    DE_PLUS, DE_PERC, DE_DQUO,  DE_QUOT,  DE_SCLN, _______,            _______,
    _______,  _______,  _______,            _______,         _______, _______,_______,          _______,            _______, _______,  _______,  _______,  _______),

  [_KOY4] = LAYOUT(
    XXXXXXX,  _______,  _______,  _______,  _______,  _______,    _______,    _______, _______, _______,  _______,  _______, _______,  _______,            _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSLS,  KC_PAST, KC_PMNS,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,                XXXXXXX, DE_7,    DE_8,     DE_9,     KC_PPLS, KC_PMNS,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,     XXXXXXX,    XXXXXXX, DE_4,    DE_5,     DE_6,     KC_COMM, KC_PDOT,  XXXXXXX,            XXXXXXX,
    _______,  KC_ESC,   KC_TAB,   KC_INS,   KC_ENT,   KC_UNDO,    XXXXXXX,    KC_COLN, DE_1,    DE_2,     DE_3,     KC_SCLN, XXXXXXX,            XXXXXXX,
    _______,  _______,  _______,            _______,             DE_0, KC_P0,  _______,          _______,            _______, _______,  _______,  _______,  _______),

  [_MOUSE] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WH_U,  XXXXXXX,  XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_MS_U,  KC_BTN2,  XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,  KC_WH_L,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_R,    _______,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_BTN3,  KC_WH_D,  KC_BTN4,  XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,                          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX),

  [_KOY5] = LAYOUT(
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          DE_MICR,        XXXXXXX,          XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,                          XXXXXXX,                  XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX,                          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX),

  [_KOY6] = LAYOUT(
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                  XXXXXXX,
    XXXXXXX,      XXXXXXX,          XXXXXXX,                          XXXXXXX,                  XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX,                          XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX),

  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |--------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */

    [_XBOWS] = LAYOUT(
      KC_ESC,  KC_F1,   KC_F2,    KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7,  KC_F8,  KC_F9,    KC_F10, KC_F11,   KC_F12,   KC_DEL,   KC_PSCR,
      KC_GRV,  KC_1,    KC_2,     KC_3,   KC_4,   KC_5,             KC_6,   KC_7,   KC_8,     KC_9,   KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,     KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,   KC_O,     KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
      KC_CAPS, KC_A,    KC_S,     KC_D,   KC_F,   KC_G,    KC_BSPC, KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGDN,
      KC_LSFT, KC_Z,    KC_X,     KC_C,   KC_V,   KC_B,    KC_ENT,  KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,  KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC, KC_LCTL, KC_LSFT, KC_SPC,         KC_RALT,  MO(_FUNC),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  /* Keymap VANILLA: (FN Layer)
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Reset |  _L0  |      |  _L3  |      |          |      |  _L7  |  Calc  |  MyComp | MPlay  |  Mail |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  V  |     V   |   V   |   V   |   V   |    V      |       V    |    V    |    V   |   V  |   V  |   V  |  V  |  NumLock  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | RGB Tog |  RGB Mod |  RGB Vai | RGB Hui | V  |   V  |            |    V   |    V   |   V  |   V  |   V  |   V  |  V  |   V  | Home |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | V       |  RGB Spd |  RGB Vad | RGB Spi |   V  |   V  |      V      |   V  |    V   |   V  |   V  |   V  |  V  |   V   |  End |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | V |   V  |   V  |   V  |   V  |   V  |       V       |    V  |    V   |  V  |   V  |  V  | Mute |      |  Vol Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | V |  V  |     V   |    V   |   V   |   V   |     V     |    V  |  V  | V |  Mus Prev  |  Vol Down |  Mus Next |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */
    [_FUNC] = LAYOUT(
      QK_BOOT,TO(_KOY1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_XBOWS), XXXXXXX, KC_CALC, KC_MYCM, KC_MSEL, KC_MAIL, NK_TOGG, EE_CLR,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM,
      RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
      _______, RGB_SPD, RGB_VAD, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLU,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT)
};
