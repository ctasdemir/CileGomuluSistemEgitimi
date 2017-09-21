#include "UART_buffer.h"
#include "main.h"



volatile UART_Buffer_t UART_BufferRX;
volatile UART_Buffer_t UART_BufferTX;

static int UART_is_buffer_empty(__IO UART_Buffer_t* buffer);

void UART_send_char(char ch)
{
	UART_BufferTX.buffer[UART_BufferTX.head_pointer++] = ch;
	if(UART_BufferTX.head_pointer == BUFFER_SIZE)
	{
		UART_BufferTX.head_pointer = 0;
	}
  /* Enable the UART Transmit Data Register Empty Interrupt */
 SET_BIT(USART2->CR1, USART_CR1_TXEIE);
}

int UART_is_buffer_empty(__IO UART_Buffer_t* buffer)
{
	return (buffer->head_pointer == buffer->tail_pointer?1:0);
}

int UART_read_char()
{
	int kar =  0; 
	
	if(UART_is_buffer_empty(&UART_BufferRX) == 1 )
	{
		kar = -1;
	}
	else
	{
		kar = UART_BufferRX.buffer[UART_BufferRX.tail_pointer++];
		
		if ( UART_BufferRX.tail_pointer == BUFFER_SIZE)
		{
			UART_BufferRX.tail_pointer = 0;
		}
	}	
	
	return kar;	
}


void UART_send_string(char* string, int size)
{
	int i;
	
	for(i=0;i<size;i++)
	{
		UART_send_char(string[i]);
	}
}

int UART_bytes_to_read()
{
	return UART_BufferRX.head_pointer - UART_BufferRX.tail_pointer;
}

