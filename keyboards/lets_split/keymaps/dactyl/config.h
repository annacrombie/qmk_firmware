/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef MANUFACTURER
#define MANUFACTURER    lattis
#undef PRODUCT
#define PRODUCT         dactyl
#undef DESCRIPTION
#define DESCRIPTION     キーボード

/* key matrix size     */
/* Rows are doubled-up */
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 14
#define MATRIX_COLS 5

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7, F6, F5}
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6 }

#define CATERINA_BOOTLOADER
#define USB_MAX_POWER_CONSUMPTION 50

#define LEADER_TIMEOUT 300

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_RIGHT
// #define MASTER_RIGHT
//#define EE_HANDS

/* ws2812 RGB LED */
//#undef RGBLED_NUM
//#define RGB_DI_PIN D3
//
//#define RGBLED_NUM 50
#endif
