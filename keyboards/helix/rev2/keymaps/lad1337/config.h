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

#pragma once

// place overrides here

#define RGB_DI_PIN D3
#undef RGBLED_NUM
#define RGBLED_NUM       64 // Number of LEDs
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_SPLIT \
        { 32, 32 }
#define SPLIT_TRANSPORT_MIRROR

#define OLED_TIMEOUT 30000
#define OLED_DISABLE_TIMEOUT
#define RGBLIGHT_LAYERS
#undef TAPPING_TERM
#define TAPPING_TERM 300

// Selection of RGBLIGHT MODE to use.
#if defined(LED_ANIMATIONS)
   #define RGB_MATRIX_KEYPRESSES
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   //#define RGBLIGHT_EFFECT_KNIGHT
   //#define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   //#define RGBLIGHT_EFFECT_ALTERNATING
#endif
