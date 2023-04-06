/*
Author: Promise Omiponle
Description: prototypes for methods in uart.c
*/
#include "Common.h"
void uart0_init(void);
unsigned char uart0_getchar(void);
void uart0_putchar(char ch);
void uart0_put(char *ptr_str);
void uart2_init(void);
unsigned char uart2_getchar(void);
void uart2_putchar(char ch);
void uart2_put(char *ptr_str);
BOOLEAN uart0_dataAvailable(void);
BOOLEAN uart2_dataAvailable(void);
