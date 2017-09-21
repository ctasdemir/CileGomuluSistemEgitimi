#ifndef __UART_BUFFER_H
#define __UART_BUFFER_H
#include <stdint.h>


#define BUFFER_SIZE 256

typedef struct UART_Buffer_Type{
	uint32_t buffer[BUFFER_SIZE];
	uint32_t head_pointer;
	uint32_t tail_pointer;
}UART_Buffer_t;


extern volatile  UART_Buffer_t UART_BufferRX;
extern volatile  UART_Buffer_t UART_BufferTX;


void UART_send_string(char* string, int size);
int UART_read_char(void);
void UART_send_char(char ch);
int UART_bytes_to_read(void);

#endif
