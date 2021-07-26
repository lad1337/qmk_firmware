/* Copyright 2020 yushakobo
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
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
#    include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST, _MOVE };

// clang-format off
enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST, 
    BACKLIT, 
    EISU, 
    MOVE, 
    RGBRST,
    RGBLAYER,
};

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

// Macros
#define KC_MO(x) LALT(x)
#define KC_PAPP LGUI(KC_TAB)
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Z  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | ESC  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |ctl   |adjust| Alt  | EISU  | CMD |Lower |Space |Space |Raise | MOVE | Left | Down |  Up  |Right |
     * `-------------------------------------------------------------------------------------------------'
     */

    [_QWERTY] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, ADJUST, KC_LALT, EISU, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, MOVE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Lower
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      KC_CAPS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_LPRN, KC_RPRN, KC_F12, _______, _______, KC_HOME, KC_END, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Raise
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_CAPS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, _______, _______, KC_F12, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|RGBLAY|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT(
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      _______, RESET, RGBRST, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, RGBLAYER, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD),
    /* MOVE
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |      |      |      |      |      |             |      |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |P_APP |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |T_LEFT|T_DOWN|T_UP  |T_RIGH|      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_MOVE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_TAB, LSFT(KC_ENT), _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_MO(KC_H), KC_MO(KC_J), KC_MO(KC_K), KC_MO(KC_L), _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )

};

// clang-format on

#ifdef AUDIO_ENABLE

float tone_qwerty[][2]    = SONG(QWERTY_SOUND);
float tone_dvorak[][2]    = SONG(DVORAK_SOUND);
float tone_colemak[][2]   = SONG(COLEMAK_SOUND);
float tone_plover[][2]    = SONG(PLOVER_SOUND);
float tone_plover_gb[][2] = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]    = SONG(MUSIC_SCALE_SOUND);
#endif
#ifdef OLED_DRIVER_ENABLE
uint16_t oled_timer;
#endif

// define variables for reactive RGB
bool RGB_LAYER_SWITCH = false;
int  RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void layer_rgb(uint8_t layer) {
    if (!RGB_LAYER_SWITCH) return;
    if (IS_LAYER_ON(layer)) {
        rgblight_mode_noeeprom(23);
    } else {
        rgblight_reload_from_eeprom();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    oled_timer = timer_read();
#endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                layer_rgb(_LOWER);
            } else {
                layer_off(_LOWER);
                layer_rgb(_LOWER);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                layer_rgb(_RAISE);
            } else {
                layer_off(_RAISE);
                layer_rgb(_RAISE);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
                layer_rgb(_ADJUST);
            } else {
                layer_off(_ADJUST);
                layer_rgb(_ADJUST);
            }
            return false;
            break;
            // led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
        case RGB_MOD:
            if (record->event.pressed) {
                rgblight_mode(RGB_current_mode);
                rgblight_step();
                RGB_current_mode = rgblight_get_mode();
            }
            return false;
            break;
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_sethsv(255, 0, 3 * RGBLIGHT_VAL_STEP);
                rgblight_enable();
                RGB_current_mode = rgblight_get_mode();
            }
            break;
        case MOVE:
            if (record->event.pressed) {
                layer_on(_MOVE);
                layer_rgb(_MOVE);
                SEND_STRING(SS_DOWN(X_RGUI));
            } else {
                layer_off(_MOVE);
                layer_rgb(_MOVE);
                SEND_STRING(SS_UP(X_RGUI));
            }
            return false;
            break;
        case RGBLAYER:
            if (record->event.pressed) {
                RGB_LAYER_SWITCH = !RGB_LAYER_SWITCH;
            }
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
void keyboard_post_init_user(void) {
    wait_ms(1000);
    oled_init(OLED_ROTATION_270);
}
void render_rgbled_status(void) {
    char buf[30];
    if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
        snprintf(buf, sizeof(buf), "  %2d\nH %3dS %3dL %3d", rgblight_get_mode(), rgblight_get_hue() / RGBLIGHT_HUE_STEP, rgblight_get_sat() / RGBLIGHT_SAT_STEP, rgblight_get_val() / RGBLIGHT_VAL_STEP);
    } else {
        snprintf(buf, sizeof(buf), "                   ");
    }
    oled_write(buf, false);
}
static const char PROGMEM dot[]           = {0x07, 0};
static const char PROGMEM arrow_right[]   = {0x10, 0};
static const char PROGMEM arrow_left[]    = {0x11, 0};
static const char PROGMEM arrow_up[]      = {0x1E, 0};
static const char PROGMEM arrow_down[]    = {0x1F, 0};
static const char PROGMEM arrow_up_down[] = {0x17, 0};

void oled_task_user(void) {
    uint16_t timer = timer_elapsed(oled_timer);
    if (timer > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(is_keyboard_master() ? arrow_right : arrow_left, false);
            break;
        case _LOWER:
            oled_write_P(arrow_down, false);
            break;
        case _RAISE:
            oled_write_P(arrow_up, false);
            break;
        case _ADJUST:
            oled_write_P(dot, false);
            break;
        case _MOVE:
            oled_write_P(arrow_up_down, false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("?"), false);
    }

    render_rgbled_status();
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_write_P(PSTR("\n"), false);

    if (is_keyboard_master()) {
        char buf[10];
        snprintf(buf, sizeof(buf), "T  %2d", (uint16_t)round((OLED_TIMEOUT - timer) / 1000));
        oled_write(buf, false);
    }
}
#endif

#ifdef AUDIO_ENABLE
void startup_user() {
    _delay_ms(20);  // gets rid of tick
}

void shutdown_user() {
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void) { music_scale_user(); }

void music_scale_user(void) { PLAY_SONG(music_scale); }
#endif
