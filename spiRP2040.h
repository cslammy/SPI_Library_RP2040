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

//mode is 0,1,2, or 3, SPI mode. 0 is default 
void spi_mode(uint8_t mode);


//send 8 bits to a SPI peripheral
void SPI_TransferTx8(spi_inst_t *spi, uint8_t data8); // CS down, 8 bits, CS UP 

//send 16 bits
void SPI_TransferTx16(spi_inst_t *spi, uint8_t a, uint8_t b);  //CS low, MSB 8 bits, CSup; CS down, LSB 8 bits, CS high

 
//send 16 bits
void SPI_TransferTx16_SingleCS(spi_inst_t *spi, uint16_t data_in); // cs low, 2 bytes, cs high);

void SPI_TransferTx8_variable_num_words(spi_inst_t *spi, const uint8_t a[0], uint8_t numwords);

void SPI_TransferTx16_variable_num_words(spi_inst_t *spi, const uint16_t a[0], uint8_t numwords);// csdown, 16 bit writes, cs up; variable # of bytes before CSup 

//send 8 bits to a SPI peripheral and receive 8 bits from peripheral
uint8_t SPI_TransferTxRx8(spi_inst_t *spi, uint8_t data8); // CS down, 8 bits, CS UP 

//send 16 bits
uint16_t SPI_TransferTxRx16_SingleCS(spi_inst_t *spi, uint16_t data_in); // cs low, 2 bytes, cs high);

#endif /* SPI_H_ */