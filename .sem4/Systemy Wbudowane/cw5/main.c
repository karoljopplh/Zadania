/*
 * GccApplication6.c
 *
 * Created: 14.04.2025 10:14:30
 * Author : karl23
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define magistralaDDR DDRB
#define magistrala PORTB
#define sterowanieDDR DDRC
#define sterowanie PORTC
#define RS 0
#define E 1
volatile uint8_t dane[]={0,0,0,0};
volatile uint8_t pokaz=0;

void ZapisLCD(uint8_t dana)
{
	magistrala = dana;
	sterowanie |= (1<<E);//E=1
	_delay_us(2);
	sterowanie &= ~(1<<E); //E=0
	_delay_us(42);
}

ISR (TIMER1_COMPA_vect)
{
	if(dane[3]++==9)
	{
		dane[3]=0;
	}
	pokaz=1;
}

int main(void)
{
	TCCR1B = (1<<WGM12)|(1<<CS12);//tryb CTC
	OCR1A = 62500;
	TIMSK = (1<<OCIE1A);//wlaczenie przerwania od por wnania Timer1
	sei();
	
	magistralaDDR = 0xFF;
	sterowanieDDR |= (1<<RS)|(1<<E);
	magistrala &= ~(1<<RS);//RS=0 instrukcje
	ZapisLCD(0x38);//magistrala 8-bitowa - entry mode set
	ZapisLCD(0x06);//inkrementacja adresu
	ZapisLCD(0x0F);//wlaczenie wyswietlacza
	ZapisLCD(0x01);//czyszczenie
	_delay_ms(2);
	
	ZapisLCD(0xC0);
	
	sterowanie |= (1<<RS);
	ZapisLCD('W');
	ZapisLCD('S');
	ZapisLCD('T');
	ZapisLCD('I');
	
	while(1)
	{
		if(pokaz=1)
		{
			sterowanie &= ~(1<<RS);
			ZapisLCD(0x80);
			sterowanie |= (1<<RS);
			ZapisLCD(dane[0]+'0');
			ZapisLCD(dane[1]+'0');
			ZapisLCD(dane[2]+'0');
			ZapisLCD(dane[3]+'0');
			pokaz = 0;
		}
	}
}

