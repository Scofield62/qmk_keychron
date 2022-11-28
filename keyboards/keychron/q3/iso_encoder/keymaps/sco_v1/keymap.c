/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_PASS_FN,
    MAC_VSCODE,
    WIN_BASE_TWO
};


enum {
    TD_SIT,
    TD_UAT,
    TD_PROD,
    TD_NEXT_DESK_MAC,
    TD_PREVIOUS_DESK_MAC,
    TD_NEXT_DESK_WIN,
    TD_PREVIOUS_DESK_WIN,
    TD_TOP_OF_FILE,
    TD_END_OF_FILE,
    TD_PRNT_SCRN_MAC,
    TD_PRNT_SCRN_WIN,
    TD_MAC_LAYERS
};

static uint16_t fullscreen_timer;
bool isFullscreen = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_BRID,  KC_BRIU,  LCMD(KC_F3),    LCTL(KC_UP),    RGB_VAD,  RGB_VAI,  KC_NO,    KC_NO,    KC_NO,    KC_MPRV,  KC_MPLY,  KC_MNXT,    KC_MUTE,  TD(TD_PRNT_SCRN_MAC),    TD(TD_MAC_LAYERS),    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  TD(TD_TOP_OF_FILE),
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   TD(TD_END_OF_FILE),
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
        TD(TD_NEXT_DESK_MAC),  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        TD(TD_PREVIOUS_DESK_MAC),  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  TT(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_iso(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              RESET,    _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  TD(TD_PRNT_SCRN_WIN),  TO(WIN_BASE_TWO),    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
        TD(TD_NEXT_DESK_WIN),  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        TD(TD_PREVIOUS_DESK_WIN),  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_iso(
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,    RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    TT(WIN_PASS_FN),  _______,  _______,  _______),

    [WIN_PASS_FN] = LAYOUT_tkl_f13_iso(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  TD(TD_UAT),  _______,  _______,  TD(TD_PROD),  _______,  _______,              _______,    _______,  _______,
        _______,  RGB_RMOD, TD(TD_SIT),  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                LCTL(LSFT(KC_SPC)),                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [MAC_VSCODE] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,  TD(TD_PRNT_SCRN_MAC),    TD(TD_MAC_LAYERS),    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  TD(TD_TOP_OF_FILE),
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   TD(TD_END_OF_FILE),
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
        TD(TD_NEXT_DESK_MAC),  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        TD(TD_PREVIOUS_DESK_MAC),  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  TT(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    [WIN_BASE_TWO] = LAYOUT_tkl_f13_iso(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  TD(TD_PRNT_SCRN_WIN),  TO(WIN_BASE),    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_PASS_FN]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_VSCODE]   = {ENCODER_CCW_CW(SCMD(KC_SLSH), SCMD(KC_7)) },
    [WIN_BASE_TWO] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(49, 255, 255, 255);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(49, 0, 0, 0);
    }
    switch(get_highest_layer(layer_state|default_layer_state)) {
        // When layer is mac_pass...
        case 4:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(51, 0, 255, 0);
            rgb_matrix_set_color(40, 255, 255, 0);
            rgb_matrix_set_color(43, 255, 0, 0);
            rgb_matrix_set_color(80, 255, 255, 255);
            break;
        default:
            break;
    }
};

#define ACTION_TAP_DANCE_FN_KEYCODE(user_fn, kc) {  \
     .fn = { NULL, user_fn, NULL }, \
     .user_data = (void *)&((qk_tap_dance_pair_t) { kc, 0 }) \
 }

void dance_cpc(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
    uint16_t keycode = pair->kc1;

    char cpcenv[25];
    if(keycode == KC_S)
        strcpy(cpcenv, "sit");
    if(keycode == KC_U)
        strcpy(cpcenv, "uat");
    if(keycode == KC_P)
        strcpy(cpcenv, "prod");
    switch(state->count) {
        case 1:
            SEND_STRING(strcat(cpcenv," service tier"));
            break;
        case 2:
            SEND_STRING(strcat(cpcenv," engine tier"));
            break;
        case 3:
            SEND_STRING(strcat(cpcenv," repositorz tier"));
            break;
        default:
            break;
    }
    SEND_STRING(SS_DELAY(500) SS_LSFT(SS_LCTL(SS_TAP(X_C))));
};

void dance_mac_layers(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            layer_move(MAC_BASE);
            rgb_matrix_reload_from_eeprom();
            break;
        case 2:
            layer_move(MAC_VSCODE);
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
            break;
        default:
            break;
    }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SIT] =  ACTION_TAP_DANCE_FN_KEYCODE(dance_cpc, KC_S),
    [TD_UAT] =  ACTION_TAP_DANCE_FN_KEYCODE(dance_cpc, KC_U),
    [TD_PROD] = ACTION_TAP_DANCE_FN_KEYCODE(dance_cpc, KC_P),
    [TD_NEXT_DESK_MAC] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, LCTL(KC_RIGHT)),
    [TD_PREVIOUS_DESK_MAC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(KC_LEFT)),
    [TD_NEXT_DESK_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, LWIN(LCTL(KC_RIGHT))),
    [TD_PREVIOUS_DESK_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LWIN(LCTL(KC_LEFT))),
    [TD_TOP_OF_FILE] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, LCMD(KC_UP)),
    [TD_END_OF_FILE] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, LCMD(KC_DOWN)),
    [TD_PRNT_SCRN_MAC] = ACTION_TAP_DANCE_DOUBLE(SCMD(KC_3), SCMD(KC_4)),
    [TD_PRNT_SCRN_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, SWIN(KC_S)),
    [TD_MAC_LAYERS] = ACTION_TAP_DANCE_FN(dance_mac_layers)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {
        case KC_UP:
            //Full screen mode shortcut in Mac OS Base
            if (record->event.pressed && IS_LAYER_ON(0)) {
                static bool tapped = false;
                static uint16_t tap_timer = 0;
                if (get_mods() & (MOD_BIT(KC_LCTL) && MOD_BIT(KC_LALT))) {
                    if (tapped && !timer_expired(record->event.time, tap_timer)) {
                        // The key was double tapped.
                        clear_mods();  // If needed, clear the mods.
                        // Do something interesting...
                        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_ENT))));
                        fullscreen_timer = timer_read();
                        isFullscreen = true;
                    }
                    tapped = true;
                    tap_timer = record->event.time + TAPPING_TERM;
                } else {
                    // On an event with any other key, reset the double tap state.
                    tapped = false;
                }
            }
            break;
        case KC_DEL:
            if(record->event.pressed && (IS_LAYER_ON(0) || IS_LAYER_ON(5))) {
                if(get_mods() & MOD_BIT(KC_LCMD)) {
                    SEND_STRING(SS_LCMD(SS_LALT(SS_TAP(X_BSPC))));
                }
            }
            break;
    } 
    return true;  
};