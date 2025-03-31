/*
 * GccApplication4.c
 *
 * Created: 31.03.2025 10:44:36
 * Author : karl23
 */ 

/*
 * GccApplication3.c
 *
 * Created: 17.03.2025 10:48:02
 * Author : karl23
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define segmentyDDR DDRA
#define segmenty PORTA
#define cyfraDDR DDRB
#define cyfra PORTB
uint8_t seg7[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82,0xd8, 0x80, 0x90};
uint8_t dane[]={2,0,2,5};

ISR (TIMER1_COMPA_vect)
{
	if(dane[3]++==9)	
	{
		dane[3]=0;
		if(dane[2]++==9)
		{
			dane[2]=0;
			if(dane[1]++==9)
			{
				dane[1]=0;
				if(dane[0]++==9)
				{
					dane[0]=0;
				}
			}
		}
	}
}

ISR (TIMER0_OVF_vect)
{
	static uint8_t i=0;
	cyfra |= (1<<i);
	if(i++==3) i=0;
	segmenty = seg7[dane[i]];
	cyfra &= ~(1<<i);
}

/*
ISR (TIMER1_COMPA_vect)
{
	static uint8_t i = 0;
	if(i++==9) i=0;
	segmenty = seg7[1];
	
}*/
/*
ISR (TIMER1_COMPA_vect)
{
	static uint8_t pong = 0;
	static uint8_t i = 0;
	if(pong)
	{
		if(i--==0) pong = 0;
	}
	else
		if(i++==9) pong = 1;
	segmenty = seg7[1];
}*/

int main(void)
{
	cyfraDDR = 0x0f;
	segmentyDDR = 0xff;
	//segmenty = 0xc0;
	TCCR1B = (1<<WGM12)|(1<<CS12);//tryb CTC
	//i preskaler 256
	OCR1A = 62500;
	TIMSK = (1<<OCIE1A);//wlaczenie przerwania od porównania Timer1
	TCCR0 = (1<<CS00);
	TIMSK |= (1<<TOIE0);//wlaczenie przerwania od przepelnienia Timer0
	sei();//globalne wlaczenie przerwa?
	while(1)
	{
		
	}
	/*
	while(1)
	{
		for(int i = 0; i<10; i++)
		{
			segmenty = seg7[i];
			_delay_ms(1000);
		}
	}
	*/
}

