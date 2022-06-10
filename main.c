/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "pico/stdlib.h"

#include "stdio.h"
#include "spiRP2040.h"
#include "MCP4921.h"




  

int main() {




//initialize SPI
init_spi_master();
//set bits and mode
spi_mode(0);
//loop

while (5 > 0)
    {
        //test 4921
        for (uint16_t countr = 0; countr < 4095; countr+=150)  // fundamental about 13k?
            {
            write4921(countr);
             sleep_us(100); //about 350 hz
            }
        
       
       // test 3 byte write
       /*
       uint8_t b[3];
       b[0] = 0xFF;
       b[1] = 0xF0;
       b[2] = 0x03; 
       
       SPI_TransferTx8_variable_num_words(spi0,b,3);
       */
    }

}
