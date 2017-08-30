#include <stdint.h>
#include <avr/io.h>
#include <avr/cpufunc.h>
#include "spi.h"

void spi_init(void)
{
    SPI_DDR |= _BV(SPI_MOSI) | _BV(SPI_SCLK);
    SPI_DDR &= ~_BV(SPI_MISO);

    // Set SCLK to low
    SPI_PORT &= ~_BV(SPI_SCLK);
}

/* Implementation of SPI Mode 0 transfer with MSB first */
uint8_t spi_transfer(uint8_t data)
{
    uint8_t input = 0;

    for (int i = 0; i < 8; ++i) {
        input <<= 1;

        // Write bit to slave
        if (data & 0x80)
            SPI_PORT |= _BV(SPI_MOSI);
        else
            SPI_PORT &= ~_BV(SPI_MOSI);
        data <<= 1;

        // Wait some time and raise SCLK
        _NOP();
        SPI_PORT |= _BV(SPI_SCLK);

        // Read bit from slave
        input |= (SPI_PIN & _BV(SPI_MISO)) >> SPI_MISO;

        // Wait some time and set SCLK to low
        _NOP();
        SPI_PORT &= ~_BV(SPI_SCLK);
    }

    return input;
}
