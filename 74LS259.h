#ifndef _74LS259_H
#define _74LS259_H
#include <inttypes.h>
    void Config74XX259(uint8_t *port, uint8_t D, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t _G); 
    void wr_74LS259(uint8_t data, uint8_t nbit);
    void wrByte_74LS259 (uint8_t byte);
#endif
