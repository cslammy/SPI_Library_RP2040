/*
 * spiRP2040.c
 *

port of Spi3.c and h for AVR.

 */ 



#include "spiRP2040.h"
#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"


//buffers to hold our data
uint16_t data[2]; //16 bits
uint8_t data8[1]; //8 bits


    //set pins
const uint cs_pin = 17;
const uint sck_pin = 18;
const uint mosi_pin = 19;
const uint miso_pin = 16;


//set speed
int spi_speed = 100000000;

//set bits per transfer
uint8_t bits_per_transfer = 16;

void init_spi_master(void)
{
	
	
	 //use spi0
	spi_inst_t *spi=spi0; 
	gpio_init(cs_pin); 
	gpio_set_dir(cs_pin, GPIO_OUT);  // set cs_pin to output
    gpio_put(cs_pin,1); // set cs_pin initially to high
    spi_init(spi,spi_speed);

gpio_set_function(sck_pin, GPIO_FUNC_SPI);
gpio_set_function(mosi_pin, GPIO_FUNC_SPI);
gpio_set_function(miso_pin, GPIO_FUNC_SPI);



}


void spi_mode(uint8_t mode, uint8_t spibits)
{
if (mode == 1)
	{
     spi_set_format(spi0,spibits,0,1,SPI_MSB_FIRST);
	}
if (mode == 2)
	{
     spi_set_format(spi0,spibits,1,0,SPI_MSB_FIRST);
	}
if (mode == 3)
	{
     spi_set_format(spi0,spibits,1,1,SPI_MSB_FIRST);
	}
else
		{
        spi_set_format(spi0,spibits,0,0,SPI_MSB_FIRST); // mode 0
		}
	
}

void SPI_Transfer(spi_inst_t *spi, const uint8_t a) // single 8bit write 
 {
    
	  data8[0] = a;
	  gpio_put (cs_pin,0);	  
	  spi_write_blocking(spi,data8, 1);
      gpio_put (cs_pin,1);

 }
 
void SPI_TransferTx16(spi_inst_t *spi, const uint8_t a,  const uint8_t b)  // 2 8bit sequential writes
 {
	 
	
	  data8[0] = a;
	  //MSB
 
	  gpio_put (cs_pin,0);
	  spi_write_blocking(spi,data8, 1);
      gpio_put (cs_pin,1);
	 

    //LSB
	  data8[0] = b;
	
	  gpio_put (cs_pin,0);
	  spi_write_blocking(spi,data8, 1);
      gpio_put (cs_pin,1);

 }

 
 
void  SPI_TransferTx16_SingleCS(spi_inst_t *spi, const uint16_t data) // cs low, 2 bytes, cs high)
 {
   
	  gpio_put (cs_pin,0);
	  
	  uint16_t data16 = data; // create 16 bit buffer

      spi_write16_blocking(spi,&data16, 1);
	 
	  gpio_put (cs_pin,1);
 }
 
     