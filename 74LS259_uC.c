#include <avr/io.h>
#include "74LS259.h"
#include "UART.h"

volatile static uint8_t idx = 0;
char str[20];

int main()
{
	UART_Ini(0,19200,8,0,1);
	sei();
	Config74XX259((uint8_t *) 0x30,PF3,PF0,PF1,PF2,PF4);
	clrscr();
	gotoxy(0,0);
	while (1)
	{
		wrByte_74LS259(idx);
		UART0_puts(itoa(str,idx++,10));
		UART0_puts("\n\r");
		UART0_getch();
	}
	return 0;
}
