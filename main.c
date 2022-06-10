/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "pico/stdlib.h"

#include "stdio.h"
#include "spiRP2040.h"
#include "MCP4921.h"

//what pin is being used for cs?


 

int main() {




//initialize SPI
init_spi_master();
//set bits and mode
spi_mode(0, 16);
//loop

while (5 > 0)
    {

        for (uint16_t countr = 0; countr < 4095; countr+=200)
            {
            write4921(countr);
            //sleep_ms(1);
            }

    }

}
