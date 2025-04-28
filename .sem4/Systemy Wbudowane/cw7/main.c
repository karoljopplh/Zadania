#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define magistralaDDR DDRB
#define magistrala PORTB
#define sterowanieDDR DDRC
#define sterowanie PORTC
#define RS 0
#define E 1

#define SCK 7
#define MOSI 5
#define SS 4
#define SPI_DDR DDRB
#define SPI PORTB
static const PROGMEM uint8_t digits[][8]={//wiersze cyfr
	{0x0e,0x11,0x13,0x15,0x19,0x11,0x0e,0x00},//0
	{0x04,0x0c,0x14,0x04,0x04,0x04,0x1f,0x00},//1
	{0x0e,0x11,0x01,0x02,0x04,0x08,0x1f,0x00},//2
	{0x1F,0x02,0x04,0x02,0x01,0x11,0x0e,0x00},//3
	{0x02,0x06,0x0a,0x12,0x1f,0x02,0x02,0x00},//4
	{0x1f,0x10,0x1e,0x01,0x01,0x11,0x0e,0x00},//5
	{0x06,0x08,0x10,0x1e,0x11,0x11,0x0e,0x00},//6
	{0x1f,0x01,0x02,0x04,0x08,0x08,0x08,0x00},//7
	{0x0e,0x11,0x11,0x0e,0x11,0x11,0x0e,0x00},//8
	{0x0e,0x11,0x11,0x0f,0x01,0x02,0x0c,0x00},//9
	{0x0e,0x11,0x10,0x10,0x10,0x11,0x0e,0x00}//10 - 'C'
};

volatile uint8_t dane[]={0,0,0,0};
volatile uint8_t pokaz=0;
volatile uint16_t wynik=0;


void SPI_init(void)
{
	SPI_DDR |= (1<<SCK)|(1<<MOSI)|(1<<SS);
	SPCR |= (1<<SPE)|(1<<MSTR);
}
void SPI_sendbyte(uint8_t dane)
{
	SPDR = dane;
	while(!(SPSR & (1<<SPIF)));
}

void MAX7219_data(uint8_t adres,uint8_t data1,uint8_t data2,uint8_t data3,uint8_t data4)
{
	SPI &= ~(1<<SS);
	SPI_sendbyte(adres);
	SPI_sendbyte(data1);
	SPI_sendbyte(adres);
	SPI_sendbyte(data2);
	SPI_sendbyte(adres);
	SPI_sendbyte(data3);
	SPI_sendbyte(adres);
	SPI_sendbyte(data4);
	SPI |= (1<<SS);
}

void MAX7219_clear()
{
	for (uint8_t i=0;i<8;i++)
	{
		MAX7219_data(i+1,0,0,0,0);
	}
}
void Matrix_init(void)
{
	MAX7219_clear();
	MAX7219_data(0x09,0,0,0,0);
	MAX7219_data(0x0a,15,15,15,15);
	MAX7219_data(0x0b,7,7,7,7);
	MAX7219_data(0x0c,1,1,1,1);
	MAX7219_data(0x0f,0,0,0,0);
}

void Matrix_show(uint8_t *number)
{
	uint8_t data[4];
	for (uint8_t i=0;i<8;i++)
	{
		for (uint8_t j=0;j<4;j++)
		{
			data[j] = pgm_read_byte(&(digits[number[j]][i]));
		}
		MAX7219_data(i+1,data[0]<<2,data[1]<<2,data[2]<<2,data[3]<<2);
	}
}

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
	ADCSRA |= (1<<ADSC);//start ADC
}

ISR(ADC_vect)
{
	wynik = ADC;
	pokaz = 1;
}

int main(void)
{
	uint8_t tab[]={2,0,2,5};
	SPI_init();
	Matrix_init();
	Matrix_show(tab);
	
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
	
	ADMUX = (1<<REFS1)|(1<<REFS0)|(1<<MUX0);
	//Vref=2,56V, kanal to PA1
	ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2);
	//wlaczenie adc i przerwanie i zegar clk/16
	
	while(1)
	{
		if(pokaz==1)
		{
			wynik*=2,5;
			
			dane[0]=(wynik%1000)/100;
			dane[1]=((wynik%1000)%100)/10;
			dane[2]=((wynik%1000)%100)%10;
			dane[3]=10;
			
			MAX7219_data(8,0,1,0,0);
			
			
			Matrix_show(dane);
			
//			sterowanie &= ~(1<<RS);
//			ZapisLCD(0x80);
//			sterowanie |= (1<<RS);
//			ZapisLCD(dane[0]+'0');
//			ZapisLCD(dane[1]+'0');
//			ZapisLCD(dane[2]+'0');
//			ZapisLCD(',');
//			ZapisLCD(dane[3]+'0');
//			ZapisLCD(0xdf);
//			ZapisLCD('C');
			pokaz=0;
		}
	}
}