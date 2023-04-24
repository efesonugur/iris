#include QMK_KEYBOARD_H
#include "../quantum/keymap_extras/keymap_turkish_q.h"



#define _QWERTY 0
#define _LAYER2 1
#define _LAYER3 2
#define _TURKISH 3
#define _FROW 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LAYER2,
  LAYER3,
  TURKISH,
  FROW,
};

const key_override_t turkish_i_key_override = ko_make_basic(MOD_MASK_SHIFT, TR_IDOT, S(TR_I));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &turkish_i_key_override,
    // ok sağ sol için override eklemek????
    NULL // Null terminate the array of overrides!
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESCAPE,  TR_1,    TR_2,    TR_3,    TR_4,    TR_5,                              TR_6,    TR_7,    TR_8,    TR_9,    TR_0,   KC_CAPS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   TR_Q,    TR_W,    TR_E,    TR_R,    TR_T,                              TR_Y,    TR_U,    TR_IDOT,   TR_O,    TR_P, OSL(TURKISH),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, TR_A,    TR_S,    TR_D,    TR_F,    TR_G,                              TR_H,    TR_J,    TR_K,    TR_L,   TR_COMM,   KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, TR_Z,    TR_X,    TR_C,    TR_V,    TR_B,    KC_DEL,          KC_ENTER,  TR_N,    TR_M,    TR_DOT, TR_ASTR, TR_MINS, OSL(FROW),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_BSPC, KC_LALT,                  TO(LAYER2), KC_SPC, KC_ALGR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,                             XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  XXXXXXX, ALGR(TR_UDIA), ALGR(TR_SCED), XXXXXXX, TR_LPRN, TR_RPRN,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TR_DQUO, ALGR(TR_COMM),XXXXXXX, TR_LBRC,TR_RBRC,                       KC_PAGE_UP, KC_HOME, KC_UP,  KC_END, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TR_LABK, XXXXXXX,  XXXXXXX, TR_LCBR, TR_RCBR, _______,      _______, KC_PAGE_DOWN, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, TO(LAYER3),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   TO(QWERTY), _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             KC_PAST,  KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                             KC_PMNS,  KC_P4,   KC_P5,   KC_P6, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,           KC_BSPC, KC_PPLS,  KC_P1,   KC_P2,   KC_P3, TR_COMM, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   XXXXXXX, XXXXXXX, TO(QWERTY),                  KC_PEQL, XXXXXXX, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_TURKISH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,  TR_UDIA,  TR_I,   TR_ODIA, XXXXXXX,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, ALGR(TR_GBRV), TR_SCED, XXXXXXX, XXXXXXX, TR_GBRV,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, TR_CCED,  XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                           XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX , XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX,         XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, XXXXXXX, _______,                  XXXXXXX ,XXXXXXX ,  XXXXXXX 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};




// RGB addition
/* bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_PURPLE);
                }
            }
        }
    }
    return false;
}  */

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
      rgb_matrix_set_color(34, RGB_RED);
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3: // turkish
                rgb_matrix_set_color(45, RGB_YELLOW);
                break;
            case 2: // layer3
                rgb_matrix_set_color(26, RGB_PURPLE);
                rgb_matrix_set_color(58, RGB_ORANGE);   
                rgb_matrix_set_color(53, RGB_ORANGE);
                rgb_matrix_set_color(54, RGB_ORANGE);
                rgb_matrix_set_color(55, RGB_ORANGE);
                rgb_matrix_set_color(50, RGB_ORANGE);
                rgb_matrix_set_color(49, RGB_ORANGE);
                rgb_matrix_set_color(48, RGB_ORANGE);
                rgb_matrix_set_color(41, RGB_ORANGE);
                rgb_matrix_set_color(42, RGB_ORANGE);
                rgb_matrix_set_color(43, RGB_ORANGE);
                rgb_matrix_set_color(52, RGB_PURPLE);
                rgb_matrix_set_color(51, RGB_PURPLE);
                rgb_matrix_set_color(40, RGB_PURPLE);
                rgb_matrix_set_color(39, RGB_PURPLE);
                break;
            case 1: // layer2
                rgb_matrix_set_color(60, RGB_PURPLE);
                rgb_matrix_set_color(36, RGB_ORANGE);
                rgb_matrix_set_color(37, RGB_ORANGE);
                rgb_matrix_set_color(38, RGB_ORANGE);
                rgb_matrix_set_color(1, RGB_GOLD);
                rgb_matrix_set_color(2, RGB_GOLD);
                rgb_matrix_set_color(3, RGB_GOLD);
                rgb_matrix_set_color(4, RGB_AZURE);
                rgb_matrix_set_color(5, RGB_AZURE);
                rgb_matrix_set_color(55, RGB_PURPLE);
                rgb_matrix_set_color(54, RGB_PURPLE);
                rgb_matrix_set_color(53, RGB_PURPLE);
                rgb_matrix_set_color(49, RGB_PURPLE);
                rgb_matrix_set_color(50, RGB_WHITE);
                rgb_matrix_set_color(48, RGB_WHITE);

                /* rgb_matrix_set_color(7, RGB_YELLOW);
                rgb_matrix_set_color(6, RGB_YELLOW);
                rgb_matrix_set_color(16, RGB_ORANGE);
                rgb_matrix_set_color(17, RGB_ORANGE);
                rgb_matrix_set_color(19, RGB_RED);
                rgb_matrix_set_color(18, RGB_RED); */
                
                /* rgb_matrix_set_color(10, RGB_WHITE);
                rgb_matrix_set_color(9, RGB_WHITE);
                rgb_matrix_set_color(13, RGB_WHITE);
                rgb_matrix_set_color(14, RGB_WHITE);
                rgb_matrix_set_color(22, RGB_WHITE); */

                break;
            case 4:
                for (uint8_t i = 0; i < 6; i++) {
                  rgb_matrix_set_color(i, RGB_PURPLE);
                }
                for (uint8_t i = 34; i < 40; i++) {
                  rgb_matrix_set_color(i, RGB_PURPLE);
                }
                break;
            default:
                break;
    }
    
    return false;
}











/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LAYER2:
      if (record->event.pressed) {
        layer_on(_LAYER2);
        update_tri_layer(_LAYER2, _LAYER3, _TURKISH);
      } else {
        layer_off(_LAYER2);
        update_tri_layer(_LAYER2, _LAYER3, _TURKISH);
      }
      return false;
      break;
    case LAYER3:
      if (record->event.pressed) {
        layer_on(_LAYER3);
        update_tri_layer(_LAYER2, _LAYER3, _TURKISH);
      } else {
        layer_off(_LAYER3);
        update_tri_layer(_LAYER2, _LAYER3, _TURKISH);
      }
      return false;
      break;
   case TURKISH:
      if (record->event.pressed) {
        layer_on(_TURKISH);
      } else {
        layer_off(_TURKISH);
      }
      return false;
      break;
    case FROW:
      if (record->event.pressed) {
        layer_on(_FROW);
      } else {
        layer_off(_FROW);
      }
      return false;
      break;
  }
  return true;
}

 */