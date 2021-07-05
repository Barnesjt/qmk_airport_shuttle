/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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

#include "encoder.h"
#include <string.h>

#include "nrf.h"
#include "nrf_gpio.h"

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
  #error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(uint8_t))
static uint8_t encoders_pad_a[] = ENCODERS_PAD_A;
static uint8_t encoders_pad_b[] = ENCODERS_PAD_B;

static int8_t encoder_LUT[] = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

static uint8_t encoder_state[NUMBER_OF_ENCODERS] = {0};
static int8_t encoder_value[NUMBER_OF_ENCODERS] = {0};

__attribute__ ((weak))
void encoder_update_user(int8_t index, bool clockwise) { }

__attribute__ ((weak))
void encoder_update_kb(int8_t index, bool clockwise) {
  encoder_update_user(index, clockwise);
}

void encoder_init(void) {
  #if(MCU_FAMILY != NRF52)
    #error This version does not support Encoders for non-NRF52 MCUs
  #else
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    nrf_gpio_cfg_sense_input(encoders_pad_a[i], NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_SENSE_LOW);
    nrf_gpio_cfg_sense_input(encoders_pad_b[i], NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_SENSE_LOW);
    //setPinInputHigh(encoders_pad_a[i]);
    //setPinInputHigh(encoders_pad_b[i]);

    encoder_state[i] = (nrf_gpio_pin_read(encoders_pad_a[i]) << 0) | (nrf_gpio_pin_read(encoders_pad_b[i]) << 1);
    //encoder_state[i] = (readPin(encoders_pad_a[i]) << 0) | (readPin(encoders_pad_b[i]) << 1);
  }
  #endif
}

void encoder_read(void) {
  #if(MCU_FAMILY != NRF52)
    #error This version does not support Encoders for non-NRF52 MCUs
  #else
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    encoder_state[i] <<= 2;
    encoder_state[i] |= (nrf_gpio_pin_read(encoders_pad_a[i]) << 0) | (nrf_gpio_pin_read(encoders_pad_b[i]) << 1);
    //encoder_state[i] |= (readPin(encoders_pad_a[i]) << 0) | (readPin(encoders_pad_b[i]) << 1);
    encoder_value[i] += encoder_LUT[encoder_state[i] & 0xF];
    if (encoder_value[i] >= ENCODER_RESOLUTION) {
        encoder_update_kb(i, COUNTERCLOCKWISE);
    }
    if (encoder_value[i] <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update_kb(i, CLOCKWISE);
    }
    encoder_value[i] %= ENCODER_RESOLUTION;
  }
  #endif
}