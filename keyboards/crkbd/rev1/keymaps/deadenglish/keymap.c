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

enum layer_number {
    _BASE = 0,
    _NUMBER,
    _SYMBOL,
    _NAV,
};

enum mod_keys {
    MDA = MT(MOD_LSFT, KC_A),
    MDS = MT(MOD_LGUI, KC_S),
    MDD = MT(MOD_LALT, KC_D),
    MDF = MT(MOD_LCTL, KC_F),
    MDJ = MT(MOD_RCTL, KC_J),
    MDK = MT(MOD_RALT, KC_K),
    MDL = MT(MOD_RGUI, KC_L),
    MDSC = MT(MOD_RSFT, KC_SCLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |A/LSFT|S/LGUI|D/LALT|F/LCTR|   G  |                    |   H  |J/RCRT|K/RALT|L/RGUI|;/RSFT|  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   `----------------------------'           '------''--------------------'
 *                          | NUM  |  NAV | / Space /       \Enter \  | SYM  |      |
 *                          | MEDIA|      |/       /         \      \ |      |      |
 *                          `----------------------'           '------''------------'

 */

 [_BASE] = LAYOUT(
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,   MDA,    MDS,     MDD,     MDF,     KC_G,                     KC_H,    MDJ,     MDK,     MDL,     MDSC,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            MO(_NUMBER),MO(_NAV),KC_SPC, KC_ENT,MO(_SYMBOL), KC_NO
),
/* NUMBER/MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |   %  |   7  |   8  |   9  |   +  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |                    |   *  |   4  |   5  |   6  |   =  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |-------|    |-------|   /  |   1  |   2  |   3  |   .  | NumL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | / Space /       \Enter \  |  0   |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `----------------------'           '------''------------'
 */
[_NUMBER] = LAYOUT(
    KC_NO, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_NO,                  KC_PERC,   KC_7,    KC_8,    KC_9,  KC_PLUS, KC_BSPC,
    KC_NO, KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_NO,                  KC_ASTR,   KC_4,    KC_5,    KC_6,  KC_EQL,   KC_NO,
    KC_NO, KC_F9,   KC_F10,  KC_F11, KC_F12,     KC_NO,                  KC_SLASH,  KC_1,    KC_2,    KC_3,  KC_DOT,  KC_NUM,
                                  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,  KC_0,  KC_NO
),
/* NAV/F KEYS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |  🔈  |  🔊  |LAlt+4|LAlt+5|                    |      |   w← |      |      |  w←  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | prev | play | next |      |                    |      |   ←  |   ↓  |   ↑  |  ←   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | / Space /       \Enter \  |      |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `----------------------'           '------''------------'

 */
[_NAV] = LAYOUT(
    KC_NO, KC_NO,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,LSG(KC_4),LSG(KC_5),     LALT(KC_LEFT),   KC_NO,   KC_NO,  LALT(KC_RIGHT),   KC_NO,   KC_NO,
    KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,   KC_NO,                     KC_LEFT, KC_DOWN,   KC_UP,  KC_RIGHT,         KC_NO,   KC_NO,
    KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,  KC_NO,            KC_NO,   KC_NO,
                                       KC_NO,   KC_NO, KC_TRNS,  KC_TRNS,   KC_NO,   KC_NO
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   £  |   $  |   %  |                    |   ^  |   &  |   *  |   -  |   =  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |   #  |   /  |   {  |   (  |                    |   )  |   }  |  \  |   _  |    :  |   "  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |   <  |   [  |-------|    |-------|   ]  |   >  |   ,  |   .  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      | LALT | / Space /       \Enter \  |      |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `----------------------'           '------''------------'
 */
[_SYMBOL] = LAYOUT(
    KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR,KC_MINS,  KC_EQL, KC_BSPC,
    KC_NO, KC_GRV, LALT(KC_3),KC_SLASH,KC_LCBR,KC_LPRN,                  KC_RPRN, KC_RCBR, KC_BSLS,KC_UNDS, KC_COLN, KC_DQUO,
    KC_LSFT,   KC_NO,   KC_NO,   KC_NO, KC_LABK, KC_LBRC,               KC_RBRC, KC_RABK, KC_COMM, KC_DOT, KC_QUES,   KC_NO,
                                   KC_NO, KC_LALT,  KC_TRNS, KC_TRNS,  KC_NO,   KC_NO
),
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
