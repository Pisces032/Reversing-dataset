#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned char findPos(const unsigned char* base64_map, unsigned char c)//查找下标所在位置
{
	for (int i = 0; i < strlen((const char*)base64_map); i++)
	{
		if (base64_map[i] == c)
			return i;
	}
}
unsigned char* base64_decode(const unsigned char* code0)
{
	unsigned char* code = (unsigned char*)code0;
	unsigned char base64_map[65] = "8G+cazk2jqb7w01CtoKH4FsrgR3vVmQ9pPhXLAleOd/nB6DfIxMWYiUZ5SEJyNuT";
	long len, str_len, flag = 0;
	unsigned char* res;
	len = strlen((const char*)code);
	if (code[len - 1] == '=')
	{
		if (code[len - 2] == '=')
		{
			flag = 1;
			str_len = len / 4 * 3 - 2;
		}
		else
		{
			flag = 2;
			str_len = len / 4 * 3 - 1;
		}
	}
	else
		str_len = len / 4 * 3;
	res = (unsigned char*)malloc(sizeof(unsigned char) * str_len + 1);
	unsigned char a[4] = { 0 };
	for (int i = 0, j = 0; j < str_len - flag; j += 3, i += 4)
	{
		a[0] = findPos(base64_map, code[i]);		//code[]每一个字符对应base64表中的位置,用位置值反推原始数据值
		a[1] = findPos(base64_map, code[i + 1]);
		a[2] = findPos(base64_map, code[i + 2]);
		a[3] = findPos(base64_map, code[i + 3]);
		res[j] = a[0] | ((a[1] & 0x3) << 6);//第一个字符对应
		res[j + 1] = ((a[1] & 0x3c) >> 2) | ((a[2] & 0xf) << 4);
		res[j + 2] = ((a[3] & 0x3f) << 2) | ((a[2] & 0x30) >> 4);
	}
	switch (flag)
	{
	case 0:break;
	case 1:
	{
		a[0] = findPos(base64_map, code[len - 4]);
		a[1] = findPos(base64_map, code[len - 3]);
		res[str_len - 1] = a[0] | ((a[1] & 0x3) << 6);
		break;
	}
	case 2: {
		a[0] = findPos(base64_map, code[len - 4]);
		a[1] = findPos(base64_map, code[len - 3]);
		a[2] = findPos(base64_map, code[len - 2]);
		res[str_len - 2] = a[0] | ((a[1] & 0x3) << 6);//第一个字符对应
		res[str_len - 1] = ((a[1] & 0x3c) >> 2) | ((a[2] & 0xf) << 4);
		break;
	}
	}
	res[str_len] = '\0';
	return res;
}
int main() {
	unsigned char BaseData[] = "HZ0sMJXqxHgUb2b9RNg+1xw=";
	unsigned char* result = base64_decode(BaseData);//魔改base
	for (int i = 0; i < 17; i++)
		printf("%#x,", result[i]);
	return 0;
}
