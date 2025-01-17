/**
 * Copyright (c) 2014 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 *
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 * This file contains the source code for a sample application to blink LEDs.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <nrfx_log.h>
#include <libraries/log/nrf_log_ctrl.h>
#include <libraries/log/nrf_log_default_backends.h>
#include "nrf_delay.h"
#include "boards.h"
#include "pin.h"

//#include <vector>

/**
 * @brief Function for application main entry.
 */
int main(void)
{
  /* Configure board. */
  bsp_board_init(BSP_INIT_LEDS);

    for (const int &pin : INPUTS) {
        nrf_gpio_cfg_input(pin, NRF_GPIO_PIN_PULLUP);
    }

    for(const int &pin : OUTPUTS){
        nrf_gpio_cfg_output(pin);
    }

    nrf_gpio_range_cfg_output(22,23);
  NRF_LOG_INIT(nullptr);
  NRF_LOG_DEFAULT_BACKENDS_INIT();

  /* Toggle LEDs. */
  while (true)
  {
    NRF_LOG_PROCESS();

      for (const int &pin : INPUTS) {
          int back = nrf_gpio_pin_read(pin);
          printf("pin %d is %d",pin,back);
      }

        nrf_gpio_pin_toggle(LCD_BACKLIGHT_HIGH_OUT);
        nrf_delay_ms(400);

      nrf_gpio_pin_write(VIBRATOR_OUT,0);
      nrf_delay_ms(40);
      nrf_gpio_pin_toggle(VIBRATOR_OUT);
      nrf_delay_ms(400);

    NRF_LOG_INFO("coucou\n");
    NRF_LOG_FLUSH();
  }
}

/**
 *@}
 **/
