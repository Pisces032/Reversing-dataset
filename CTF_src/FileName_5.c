#include <stdio.h>
#include <string.h>

void rc4_init(unsigned char* s, unsigned char* key, unsigned long len)
{
	int i = 0;
	int j = 0;
	unsigned char k[256] = { 0 };
	unsigned char temp = 0;
	for (i = 0; i < 256; i++)
	{
		s[i] = i;         //0-255赋给s
		k[i] = key[i % len];   //将k重新计算
	}
	for (i = 0; i < 256; i++)
	{
		j = (j + s[i] + k[i]) % 256;    //给j赋
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;    //s[i]和s[j]交换
	}
}

void rc4_crypt(unsigned char* s, unsigned char* data, unsigned long len)
{
	int i = 0, j = 0, t = 0;
	unsigned long k = 0;
	unsigned char temp;
	for (k = 0; k < len; k++)
	{
		i = (i + 1) % 256;            //固定方式生成的i
		j = (j + s[i]) % 256;          //固定方式生成的j
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;             //交换
		t = (s[i] + s[j]) % 256;      //固定方式生成的t
		data[k] ^= s[t];          //异或运算
	}
}

int main()
{
	unsigned char s[256] = { 0 };
	char key[256] = "Flag{This_a_Flag}";
	char data[512] = {228,21,196,237,166,47,86,16,187,19,235,173,117,86,199,187,233,185,204,2,58,80,159,54,144,105,190,125,66,68,202,198,212,36,92,210,185,36,193,24,147,179,234};    //找到规律，小数保留(max117)，大数减去256(min125)
	unsigned long len = strlen(data);
	rc4_init(s, (unsigned char*)key, len);//初始化得到s
	rc4_crypt(s, (unsigned char*)data, len);//解密
	printf("解密后为:%s", (unsigned char*)data);
	return 0;
}