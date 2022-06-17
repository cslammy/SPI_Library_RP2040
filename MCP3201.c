#include "MCP3201.h"
#include "stdio.h"
#include "spiRP2040.h"

uint16_t inputword = 0xFFFF; // can be anything 16 bits
uint16_t result = 0;
uint16_t rawdataread = 0;  // result of initial read from MCP3201, before bitmoves

      
    
    uint16_t MCP3201read(void)
    {
    rawdataread = SPI_TransferTxRx16_SingleCS(spi0, inputword) ;
    rawdataread = rawdataread << 3;
    result = rawdataread >> 4;
    
    
    return result;
    }
