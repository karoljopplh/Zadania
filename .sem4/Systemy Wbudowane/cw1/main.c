/*
 * GccApplication2.c
 *
 * Created: 03.03.2025 11:50:28
 * Author : karl23
 */
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define diodyDDR DDRA
#define diody PORTA
#define dioda 4
uint8_t i;
int main(void)
{
	diodyDDR =0xff;
	diody = 0b10110011;
	_delay_ms(1000);
	diody &= ~(1<<dioda); //zerowaniu bitu
	_delay_ms(1000);
	diody |= (1<<dioda); //ustawianie bitu
	_delay_ms(1000);
	diody ^= (1<<dioda);
	while (1)
	{
	}
}

