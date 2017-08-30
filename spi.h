#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

void spi_init(void);
uint8_t spi_transfer(uint8_t data);

#endif
