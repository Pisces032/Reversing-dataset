#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	char a2[] = "flag{ed1d665e6516a37ab09f0b7a40}";
	unsigned char Str2[] = {
	0x80, 0xD3, 0x6F, 0xFF, 0x15, 0x03, 0x98, 0x8C, 0xB4, 0x5B, 0x96, 0xC0, 0x59, 0xAC, 0x18, 0xDF,
	0x2D, 0xCE, 0x3F, 0xFB, 0xC4, 0xED, 0xD8, 0xD2, 0xA8, 0x2D, 0xF8, 0x23, 0x9F, 0x22, 0x25, 0xCE, 0
	};
	for (int m = 0; m < 32; m++)
	{
		Str2[m] += a2[m];
	};
	
	srand(32 + 89);
	for (int j = 0; j < 16; j++)
	{
		Str2[j] ^= rand();
	}
	//ע��˳�򣬵ڶ���ѭ������s[0]-s[15]���Ѿ�������������֮��Ľ��
	for (int k = 16; k < 32; k++)
	{
		Str2[k] ^= Str2[k - 16];
	};
	printf("%s\n", Str2); 

	return 0;
}