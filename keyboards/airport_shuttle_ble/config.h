/*
Copyright 2020 KnoblesseOblige
Copyright 2019 yynmt
Copyright 2019 slay-t <slay.tx@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xADAD
#define PRODUCT_ID      0xA154
#define DEVICE_VER      0x0001
#define MANUFACTURER    Aeternus Decorum
#define PRODUCT         Airport Shuttle

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
//#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#define PERMISSIVE_HOLD
#define TAPPING_TERM 175
#define RETRO_TAPPING 750
#define TAP_CODE_DELAY 0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

// From joric wiki
#define BLE_NUS_MIN_INTERVAL 30 // default 60
#define BLE_NUS_MAX_INTERVAL 60 // default 75
#define BLE_HID_MAX_INTERVAL 80 // default 90
#define BLE_HID_SLAVE_LATENCY 10 // default 4

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
