#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

#define SPI_PORT PORTB
#define SPI_PIN PINB
#define SPI_DDR DDRB
#define SPI_MOSI PB5
#define SPI_MISO PB6
#define SPI_SCLK PB7

void spi_init(void);
uint8_t spi_transfer(uint8_t data);

#endif
