# SPI_Library_RP2040
SPI C library for RP2040 MCU and development boards like RP PICO

main.c is used to test the functions.
IC's used to test: 
MCP3201 (SPI read--12 bit ADC)
MCP4921 (SPI write--12 bit DAC)

Note--I wrote this library to make sure I understand the basics of the SPI tools found in the Pcio SDK. You may or may not want to include it in your own code; in some use cases it may make more sense to just incorporate the SDK functions directly rather than use this library. However, I use this library in some of my own C projects, so you will see it elsewhere in this repo.
