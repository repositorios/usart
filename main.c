#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "usart/usart.h"

int main(void)
{
	USART_init();
	
    while(1)
    {
       
	   USART_send(USART_receive());
    }
}