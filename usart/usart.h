#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

#include <avr/io.h>

void USART_init(void);
void USART_send(uint8_t data);
uint8_t USART_receive(void);
void USART_putstring(char* str);
void USART_Flush(void);

#endif /* USART_H_ */