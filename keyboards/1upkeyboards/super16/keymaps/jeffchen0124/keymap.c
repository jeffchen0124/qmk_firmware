/* Copyright 2019 MechMerlin
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

enum combos {
  COMBO_TOGGLE_LAYER_0,
  COMBO_TOGGLE_LAYER_1
};

const uint16_t PROGMEM layer1_on_combo[] = {KC_PAST, KC_PSLS, KC_PPLS, KC_PMNS, COMBO_END};
const uint16_t PROGMEM layer0_on_combo[] = {KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_NUMLOCK, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_TOGGLE_LAYER_0] = COMBO_ACTION(layer0_on_combo),
  [COMBO_TOGGLE_LAYER_1] = COMBO_ACTION(layer1_on_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_TOGGLE_LAYER_0:
      if (pressed) {
        layer_move(0);
      }
      break;
    case COMBO_TOGGLE_LAYER_1:
      if (pressed) {
        layer_move(1);
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x4( /* Base */
    KC_P7,    KC_P8,       KC_P9,      KC_PAST,
    KC_P4,    KC_P5,       KC_P6,      KC_PSLS,
    KC_P1,    KC_P2,       KC_P3,      KC_PPLS,
    KC_P0,    KC_PENT,     KC_PDOT,    KC_PMNS
  ),

  [1] = LAYOUT_ortho_4x4( /* Toggle */
    KC_INSERT,    KC_HOME,     KC_AUDIO_VOL_UP,        KC_MEDIA_NEXT_TRACK,
    KC_DELETE,    KC_END,      KC_AUDIO_VOL_DOWN,      KC_MEDIA_PREV_TRACK,
    KC_PGUP,      KC_UP,       KC_PGDOWN,              KC_MEDIA_PLAY_PAUSE,
    KC_LEFT,      KC_DOWN,     KC_RIGHT,               KC_NUMLOCK
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_CUSTOM_NUMPAD_4x4);
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}