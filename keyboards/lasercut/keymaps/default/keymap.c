#include QMK_KEYBOARD_H

#define KC_MO(x) LGUI(LALT(x))

#define L_NORMAL 0
#define L_FUNCTION 1
#define L_SYMBOL 2
#define L_SYSTEM 3
#define XXXXX XXXXXXX

enum unicode_names { a_U, A_U, u_U, U_U, o_U, O_U, S_U };

const uint32_t PROGMEM unicode_map[] = {
    [a_U] = 0x00E4, // ä
    [A_U] = 0x00C4, // Ä
    [u_U] = 0x00FC, // ü
    [U_U] = 0x00DC, // Ü
    [o_U] = 0x00F6, // ö
    [O_U] = 0x00D6, // Ö
    [S_U] = 0x00DF, // ß
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_NORMAL] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, MO(L_SYSTEM), LCTL(LGUI(KC_Q)),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT, HYPR(KC_B), HYPR(KC_A),
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_AT,
        KC_LSFT, KC_BSLS, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, OSM(MOD_MEH), KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(L_FUNCTION), LT(L_SYMBOL, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [L_FUNCTION] = LAYOUT(
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, LGUI(LSFT(KC_ENT)), XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_MO(KC_H), KC_MO(KC_J), KC_MO(KC_K), KC_MO(KC_L), XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX,        XXXXX,        XXXXX,        XXXXX,        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX
    ),
    [L_SYMBOL] = LAYOUT(
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XP(u_U, U_U), XXXXX, XP(o_U, O_U), XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XP(a_U, A_U), X(S_U), XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX,        XXXXX,        XXXXX,        XXXXX,        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX
    ),
    [L_SYSTEM] = LAYOUT(
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, DB_TOGG, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, QK_BOOT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
        XXXXX, XXXXX, XXXXX,        XXXXX,        XXXXX,        XXXXX,        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX
    )
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}
