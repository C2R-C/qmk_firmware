#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_spanish_dvorak.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SHORTCUTS
};

// Custom keycodes for layer keys
// Dual function escape with left command
#define KC_LGESC LGUI_T(KC_ESC)

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
  RGBRST
//   KC_RACL // right alt / colon
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
   //,---------|----|-----|-----|-----|------|           ,--------------------------------------.
          TAB  | ;  |  ,  |  .  |  P  |  Y   |           |  F  |  G  |  C  |  R  |  L  |  BACK  |
  //|----------+----+-----+-----+-----+------|           |-----+-----+-----+-----+-----+--------|
          SFT  | A  |  O  |  E  |  U  |  I   |           |  D  |  H  |  T  |  N  |  S  |ADJUST/Ñ|
  //|----------+----+--------+--------+------|           |-----+-----+-----+-----+-----+--------|
         CTRL  | '  |  Q  |  J  |  K  |  X   |           |  B  |  M  |  W  |  V  |  Z  |  SUPR  |
  //|----------+------+--------+--------+-------.     .--------+-----+-----+-----+-----+--------'
              |        CMD |   LOWER    | SPACE |     |  ENTER | RAISE/TILDE | SHORTCUTS/ESC |
            //`---------------------------------'     `--------------------------------------'

        */

    [_DVORAK] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.             ,-----------------------------------------------------.
        MT(MOD_LALT, KC_TAB), MT(MOD_RALT, DV_SCLN), LT(_RAISE, DV_COMM), DV_DOT, DV_P, DV_Y,    DV_F,   DV_G,    DV_C,    DV_R,    DV_L,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
        OSM(MOD_LSFT), DV_A,   DV_O,    DV_E,   DV_U,    DV_I,                 DV_D,   DV_H,    DV_T,    DV_N,    DV_S, LT(_ADJUST, DV_NTIL),
        //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|
        OSM(MOD_LCTL), DV_QUOT, DV_Q,   DV_J,   DV_K,    DV_X,                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,   KC_DEL,
        //|--------+--------+--------+--------+--------+--------+----|   |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LGUI, MO(1), KC_SPC,     KC_ENT, LT(_RAISE, DV_ACUT), LT(_SHORTCUTS, KC_ESC)
                                            //`----------------------'   `--------------------------'
        ),

    /*
   //,---------------------------------------.             ,------------------------------------.
         PIPE  |  @  |  ¡  |  {  |  }  |  !  |             |  +  |  4  |  5  |  6  |  \  | BACK |
  //|----------+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+------|
           €   |  #  |  ¿  |  (  |  )  |  ?  |             |  /  |  1  |  2  |  3  |  0  |   -  |
  //|----------+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+------|
           &   |  $  |  %  |  [  |  ]  |  ~  |             |  *  |  7  |  8  |  9  |  ^  | SUPR |
  //|----------+-----+-----+-----+-----+-----+---.    .--------+-----+-----+-----+-----+------'
                   |     CMD     | LOWER | SPACE |    |  = |  ¬  |  ¨  |
               //`-------------------------------'     `---------------'

        */

    [_LOWER] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            DV_PIPE, DV_AT,   DV_IEXL, DV_LCBR, DV_RCBR, DV_EXLM,                     DV_PLUS, DV_4, DV_5, DV_6, DV_BSLS, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            DV_EURO, DV_HASH, DV_IQUE, DV_LPRN, DV_RPRN, DV_QUES,                     KC_PSLS, DV_1, DV_2, DV_3, DV_0, DV_MINS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            DV_AMPR, DV_DLR,  DV_PERC, DV_LBRC, DV_RBRC, DV_TILD,                     KC_PAST, DV_7, DV_8, DV_9, DV_CIRC, KC_DEL,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_TRNS, KC_TRNS, KC_SPC,     KC_PEQL, DV_NOT, DV_DIAE
                                            //`--------------------------'  `--------------------------'
        ),

    /*
    //,--------------------------------------------------.           ,---------------------------------------------.
        VOL +   |   UNDO  | RAISE |   UP  | CAPS  |  ª  |           | RENAME | TERMINAL | LINE UP   | PASTE |    | CONTROL |
  //|-----------+---------+-------+-------+-------+-----|           |--------+----------+-----------+-------+----+---------|
        VOL -   |  REUNDO |  LEFT |  DOWN | RIGHT |  `  |           | EJECUT |          | LINE DOWN |  COPY |    | CTL+SHT |
  //|-----------+---------+-------+-------+-------+-----|           |--------+----------+-----------+-------+----+---------|
                |         |       |   <   |   >   |  º  |           | DEBUG  | MAKE PRO |           |  CUT  |    |   SHIT  |
  //|-----------+---------+-------+-------+-------+-----+--.    .------------+----------+-----------+-------+----+---------'
                         |   CUT   |   COPY  |  PASTE      |    |        | RAISE/TILDE |             |
                       //`---------------------------------'     `-----------------------------------'

        */

    [_RAISE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_VOLU, LCTL(DV_Z), KC_TRNS, KC_UP, KC_CAPS, DV_FORD,      LSFT(KC_F6), LCA(DV_T), LSA(KC_UP), KC_PSTE, KC_NO, OSM(MOD_LCTL),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_VOLD, LCTL(DV_Y), KC_LEFT, KC_DOWN, KC_RGHT, DV_GRV,       LSFT(KC_F10), RALT(DV_H), LSA(KC_DOWN), LCTL(DV_C), KC_NO, LCTL(LSFT(KC_NO)),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_NO,    KC_NO,   KC_NO  , DV_LABK, DV_RABK, DV_MORD,      LSFT(KC_F9), LCTL(KC_F9), KC_NO, LCTL(DV_X), KC_NO, OSM(MOD_LSFT),
        //|--------+--------+--------+--------+--------+--------+----|  |--------+--------+--------+--------+--------+--------+--------|
                                             LCTL(DV_X),LCTL(DV_C), KC_PSTE,    KC_NO, KC_TRNS, KC_NO
                                        //`--------------------------'  `--------------------------'
        ),

    /*
    //,--------------------------------------------------.           ,-------------------------------------------------.
           F1   |  F2     |  F3   |   F4  |  R5   | F6  |           |   F7   |    F8    |    F9     | F10 | F11|  F12  |
  //|-----------+---------+-------+-------+-------+-----|           |--------+----------+-----------+-----+----+-------|
                |         |       |       |       |     |           | XXXXXX |  XXXXX   | XXXXXXXXX |     |    | TRANS |
  //|-----------+---------+-------+-------+-------+-----|           |--------+----------+-----------+-----+----+-------|
        RESET   |         |       |       |       |     |           | XXXXX  | XXXXXXXX |           |     |    |       |
  //|-----------+---------+-------+-------+-------+-----+--.    .------------+----------+-----------+-----+----+-------'
                         |          |      ALT    |        |    |        |    TAB      |             |
                       //`---------------------------------'     `-----------------------------------'

        */

    [_ADJUST] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_BOOT,   RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TRNS, KC_LALT, KC_TRNS,    KC_TRNS, KC_TAB, KC_TRNS
                                            //`--------------------------'  `--------------------------'
        ),

    /*
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          TAB  ,    ¡   ,    !   ,    (   ,   )    ,        ,                             ,    =   ,    *   ,    `   ,   ^   , NAV ATRAS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,    <   ,    >   ,    {   ,   }    ,        ,                        "    ,   /    ,    +   ,    @   ,   #   ,ACTU NAV       ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                ,    ¿   ,    ?   ,    [   , IMPR   , INS    ,                             ,   $    ,    &   ,    |   , MENU  ,FAVO NAV    ,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            WIN/CMD,   ALT  ,  ALTGR,          ,        , SHORTCUT
                                        //`--------------------------'  `--------------------------'

        */

    [_SHORTCUTS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX,                       XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, KC_WBAK,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WREF,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           XXXXXXX, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_INS,                       XXXXXXX, KC_NO, KC_NO, KC_NO, KC_MENU, KC_WFAV,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LGUI, KC_LALT, KC_ALGR,     KC_NO, KC_NO, KC_TRNS
                                            //`--------------------------'  `--------------------------'
        )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM dvorak_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM shortcuts_layer[] = {
        0x20, 0x9b, 0x9c, 0x94, 0x20,
        0x20, 0xbb, 0xbc, 0xb4, 0x20,
        0x20, 0xdb, 0xdc, 0xd4, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_SHORTCUTS)) {
        oled_write_P(shortcuts_layer, false);
    } else {
        oled_write_P(dvorak_layer, false);
    }
}

bool oled_task_user(void) {
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    return false;
}

#endif
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   static uint16_t my_colon_timer;

  switch (keycode) {
         case RALT_T(DV_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(DV_SCLN); // Send DP_SCLN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
   /* case LOWER:
      if (record->event.pressed) {
        layer_on(_NAVIGATE);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _ADJUST);
      } else {
        layer_off(_NAVIGATE);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _ADJUST);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer_RGB(_NAVIGATE, _SYMBOLS, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case KC_RACL:
        if (record->event.pressed) {
          my_colon_timer = timer_read();
          register_code(KC_RALT);
        } else {
          unregister_code(KC_RALT);
          if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
            SEND_STRING(":"); // Change the character(s) to be sent on tap here
          }
        }
        return false; */
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}
