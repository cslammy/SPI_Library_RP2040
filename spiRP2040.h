/*
port of SPI library, for RP2040 MCU
 */ 


#ifndef SPI_H_
#define SPI_H_


#include "stdint.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"


/* declarations */
void init_spi_master(void);

void spi_mode(uint8_t mode, uint8_t spibits);

void SPI_Transfer(spi_inst_t *spi, uint8_t data8); // CS down, 8 bits, CS UP 

void SPI_TransferTx16(spi_inst_t *spi, uint8_t a, uint8_t b);  //CS low, MSB 8 bits, CSup; CS down, LSB 8 bits, CS high

 

void SPI_TransferTx16_SingleCS(spi_inst_t *spi, uint16_t data_in); // cs low, 2 bytes, cs high);

#endif /* SPI_H_ */