#include "usart.h"

void USART_init(void)
{
	/* Set baud rate */
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)BAUD_PRESCALLER;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_send(uint8_t data)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}void USART_putstring(char* str){
	
	while(*str != 0x00) {    
		USART_send(*str);
		str++;
	}
}

void USART_Flush(void)
{
	unsigned char dummy;
	while (UCSR0A & (1<<RXC0) ) dummy = UDR0;
}