/*
 * MCP4921.c
 *
 * Created: 3/22/2021 11:07:45 AM
PUT THESE 2 lines onto main.c {} file but before while(1) loop.


init_spi_master();
spi_mode(0);




 *  Author: audiodiwhy
*/

#include <stdio.h>
#include "MCP4921.h"
#include "spiRP2040.h"

uint8_t MSBwcontrol = 0;

void write4921(uint16_t data4921)

	
    {
	
        // code assumes LDAC (4921 pin 5) tied to ground
		uint16_t data12 = data4921 & 0b0000111111111111; // we only want 12 LSBs
		
		

	
		uint8_t MSB = (data12 >> 8);
		MSB |= (1 << 6) | (1 << 5) | (1 << 4) ; // buffered ref in, gain = ref; no shutdown
 
		MSB &= ~(1 << 7);  // this control must be zero always
 
		uint8_t LSB = data12 & 0x00FF;
		
		uint16_t final = LSB + (MSB << 8); 
		//MCP4921 requires 2 8 bit words sent one after the other--CS down, 16 bits, CS up

        
 		//SPI_TransferTx16_SingleCS(spi0,0b0111101011110101);
        SPI_TransferTx16_SingleCS(spi0,final);
 
		
		
	    // for 4911, you send 2 bytes.  bit 15 is always zero,
	    // bits 14,13,12 are control, 11-10-9-8 are MSBs data 
		//  7 6 5 4 3 2 1 0 are LSB data
	    
	     

	    //send the data.  4921 can eat 16 bit xfers.
	    /*call to spiRP2040.c here */
 

	    
    }

	
	    

