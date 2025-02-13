#include<stdio.h>
#include <stdint.h>
int main()
{
	unsigned int enc[11] = { 0xb5073388 , 0xf58ea46f , 0x8cd2d760 , 0x7fc56cda , 0x52bc07da , 0x29054b48 ,
	0x42d74750, 0x11297e95, 0x5cf2821b, 0x747970da, 0x64793c81 };
	for (int i = 0; i < 11; i++)
	{
		enc[i] = (((enc[i] - 0xd3906) ^ 0xdeadbeef) - 0xdeadc0de) * 36018379 & 0xffffffff ;
	};

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < sizeof(uint32_t) / sizeof(uint8_t); j++)
		{
			printf("%c", (enc[i] >> (j * 8)) & 0xFF);
		}
	}
}