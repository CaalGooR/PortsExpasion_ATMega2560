#include "74LS259.h"
#include <avr/io.h>

volatile static uint8_t *current_port;
volatile static uint8_t A0,A1,A2,_E,PIN_D;

void Config74XX259(uint8_t *port, uint8_t D, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t _G)
{ 
    A0 = S0;
    A1 = S1;
    A2 = S2;
    _E = _G;
    PIN_D = D;
    *port = (7<<PF0) | (3<<PF3); // DDRx 
    port++;
    *port |= (1<<_E); 
    current_port =(uint8_t *) port; // PORTx
} 

void wrBit_74LS259(uint8_t data, uint8_t nbit)
{
    *current_port |= (1<<_E);
    *current_port &= ~(1<<A0 | 1<<A1 | 1<<A2);
    *current_port |= (((nbit&4)>>2)<<A2) | (((nbit&2)>>1)<<A1) | ((nbit&1)<<A0); //
    
    if (data&1)
        *current_port |= 1<<PIN_D;
    else
        *current_port &= ~(1<<PIN_D);

    *current_port &= ~(1<<_E);
}

void wrByte_74LS259 (uint8_t byte)
{
    static uint8_t i;
    for(i = 0;i<8;i++)
        wrBit_74LS259(byte>>i,i);
}