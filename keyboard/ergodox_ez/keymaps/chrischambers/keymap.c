#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0
#define SYMB 1
#define PLVR 2
#define ARRW 3

#define KC_QUO2 LSFT(KC_QUOT)   // "

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | PLVR |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L1*    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;  : |   L1*  |
 * |--------+------+------+------+------+------|      |           | ARRW |------+------+------+------+------+--------|
 * | Shift* |   Z |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | /  ? | Shift* |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      | Gui  | Alt  |  L1* |                                       |  L1* | Alt  | Gui  |      | Ctrl |
 *   `--------------------'------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       |  Up  |      |      |
 *                                 | Bksp | Del  |------|       |------| Enter|Space |
 *                                 |      |      | PgDn |       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [BASE] = KEYMAP(
    KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(PLVR),
    KC_FN1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_FN2,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
    KC_LCTL,   KC_NO,   KC_LGUI, KC_LALT, KC_FN1,

    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    KC_HOME, KC_END,
    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_PGUP,
    /*-*/      /*-*/    /*-*/    /*-*/    KC_BSPC, KC_DELT, KC_PGDN,

    //

    /*-*/      KC_NO,   KC_6,    KC_7,     KC_8,    KC_9,    KC_0,     KC_NO,
    /*-*/      KC_NO,   KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,     KC_NO,
    /*-*/      /*-*/    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_FN1,
    /*-*/      TG(ARRW),KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_FN3,
    /*-*/      /*-*/    /*-*/    KC_FN1,   KC_RALT, KC_RGUI, KC_NO,    KC_RCTL,

    KC_LEFT,   KC_RGHT,
    KC_UP,
    KC_DOWN,   KC_ENT,  KC_SPC
  ),

/* Keymap 1: Symbol layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  `   |      |  {   |  }   |      |      |           |      |  `   |  '   |  ↑   |  "   |  ~   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  @   |  &   |  (   |  )   |      |------|           |------|  =   |  ←   |  ↓   |  →   |  #   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  \   |  |   |  [   |  ]   |      |      |           |      |  *   |  _   |   -  |   +  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |       |      |      |                                       |      |      |      |      |      |
 *   `----------------------'------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Esc  | Tab  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [SYMB] = KEYMAP(
    KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,
    KC_TRNS,   KC_GRV,  KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_AT,   KC_AMPR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS,   KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/      /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,

    //

    /*-*/      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_TRNS,
    /*-*/      KC_TRNS, KC_GRV,  KC_QUOT, KC_UP,   KC_QUO2, KC_TILD,  KC_TRNS,
    /*-*/      /*-*/    KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_HASH,  KC_TRNS,
    /*-*/      KC_TRNS, KC_ASTR, KC_UNDS, KC_MINS, KC_PLUS, KC_TRNS,  KC_TRNS,
    /*-*/      /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,

    KC_TRNS,   KC_TRNS,
    KC_TRNS,
    KC_TRNS,   KC_ESC, KC_TAB
  ),

/* Keymap 2: Plover Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  q   |  w   |  e   |  r   |  t   |------|           |------|  y   |  u   |  i   |  o   |  p   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  a   |  s   |  d   |  f   |  g   |      |           |      |  h   |  j   |  k   |  l   |  :   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `--------------------'------------'                                        `---------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  c   |  v   |------|       |------|  n   |   m  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [PLVR] = KEYMAP(
    KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
    KC_NO,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_NO,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO,

    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/      /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/      /*-*/    /*-*/    /*-*/    KC_C,    KC_V,    KC_NO,

    //

    /*-*/      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
    /*-*/      KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_NO,
    /*-*/      /*-*/    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
    /*-*/      KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    /*-*/      /*-*/    /*-*/    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
    KC_TRNS,   KC_TRNS,
    KC_TRNS,
    KC_NO,     KC_N,    KC_M
  ),


/* Keymap 4: Arrow Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  ↑   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  ←   |  ↓   |  →   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `--------------------'------------'                                        `---------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [ARRW] = KEYMAP(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,

    //

    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1]    = ACTION_LAYER_ONESHOT(SYMB),    // Sticky Layer Toggle
  [2]    = ACTION_MODS_ONESHOT(MOD_LSFT), // Sticky Left Shift
  [3]    = ACTION_MODS_ONESHOT(MOD_RSFT), // Sticky Right Shift
                                          // (Necessary to distinguish the two so that the default
                                          // 'magic' key combination of lsft+rsft+<key> works
                                          // correctly)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case PLVR:
      ergodox_right_led_2_on();
      break;
    case ARRW:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
};

