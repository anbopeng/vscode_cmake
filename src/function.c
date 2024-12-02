#include "stdio.h"
#include "stdint.h"

void check_endian(void)
{
	  uint32_t token = 0x12345678;
	  uint8_t *p_byte = NULL;
	  p_byte = (uint8_t*)&token;
	  if(*p_byte == 0x12)
				printf("It is a big endian system!\r\n");

	  if(*p_byte == 0x78)
				printf("It is a little endian system!\r\n");


}