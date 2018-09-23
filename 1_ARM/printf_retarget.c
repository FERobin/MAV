#include <stdio.h>
struct __FILE
{
  int handle;
  /* Whatever you require here. If the only file you are using is */
  /* standard output using printf() for debugging, no file handling */
  /* is required. */
};
/* FILE is typedef’d in stdio.h. */
FILE __stdout;
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 0xFFFF); 
  return ch;
}
int ferror(FILE *f)
{
  /* Your implementation of ferror(). */
  return 0;
}
