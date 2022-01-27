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

// config.h esta en lenguaje C

// kb: crkbd
// km: neoncorne

#pragma once

#define OLED_DISABLE_TIMEOUT

// #define USE_MATRIX_I2C
// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define SPLIT_USB_DETECT 

#define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD

#define TAPPING_TERM 400 // el doble pulso del Tap Dance debe hacerse en menos de 400ms

#define OLED_BRIGHTNESS 120

#ifdef RGBLIGHT_ENABLE // si la linea RGBLIGHT_ENABLE = yes esta en rules.mk

    #undef RGBLED_NUM
       
    #define RGBLED_NUM 54 // numero de LEDs en el teclado
    
    #undef RGBLED_SPLIT
    
    #define RGBLED_SPLIT \
        {27,27}
       
    #define RGBLIGHT_EFFECT_BREATHING
    // incluyendo el efecto RGB breathing
    
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // incluyendo el efecto RGB rainbow mood
    
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
               
    #define RGBLIGHT_LIMIT_VAL 110
    // maximo valor para Value en HSV
    
    #define RGBLIGHT_HUE_STEP 5
    // valor del step al modificar Hue
    
    #define RGBLIGHT_SAT_STEP 17
    // valor del step al modificar Saturation
    
    #define RGBLIGHT_VAL_STEP 17
    // valor del step al modificar Value
    
#endif

#define NO_ACTION_MACRO 
// ya que tengo EXTRAFLAGS += -flto en rules.mk

#define NO_ACTION_FUNCTION 
// ya que tengo EXTRAFLAGS += -flto en rules.mk