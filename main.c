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
spi_mode(0);
//loop

while (5 > 0)
    {
        /*test 4921
        for (uint16_t countr = 0; countr < 4095; countr+=200)
            {
            write4921(countr);
            //sleep_ms(1);
            }
        */
       uint8_t b[3];
       b[0] = 0xFF;
       b[1] = 0xF0;
       b[2] = 0x03;
       /*test writing 3x 8 bit words */
       SPI_TransferTx8_variable_num_words(spi0,b,3);
    }

}
