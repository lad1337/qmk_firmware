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

#undef SSD1306OLED
#undef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 30000
#ifdef OLED_ENABLE
#    define SPLIT_OLED_ENABLE
#endif
#define SPLIT_OLED_ENABLE

//#define OLED_DISABLE_TIMEOUT
#define RGBLIGHT_LAYERS
#undef TAPPING_TERM
#define TAPPING_TERM 300

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS


