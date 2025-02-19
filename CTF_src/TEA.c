#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

void encrypt(uint32_t* v, uint32_t* k) {
	uint32_t v0 = v[0], v1 = v[1], sum = 0, i;
	uint32_t delta = 0x9e3779b9;
	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
	for (i = 0; i < 32; i++) {
		sum += delta;
		v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
	}
	v[0] = v0; v[1] = v1;
}
void decrypt(uint32_t* v, uint32_t* k) {
	uint32_t v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i;	//这里的sum是0x9e3779b9*32后截取32位的结果，截取很重要。
	uint32_t delta = 0x9e3779b9;
	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
	for (i = 0; i < 32; i++) {
		v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
		v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		sum -= delta;
	}
	v[0] = v0; v[1] = v1;
}

int main()
{
	uint32_t v[2], k[4]; int i;
	printf("Please input two unsigned intengers:");
	scanf("%u %u\n", &v[0], &v[1]);
	printf("Please input four keys:");
	for (i = 0; i < 4; i++)
	{
		scanf("%u", &k[i]);
	}

	printf("加密前的数据：%u %u\n", v[0], v[1]);	//%u 以十进制形式输出无符号整数 
	encrypt(v, k);
	printf("加密后数据：%u %u\n", v[0], v[1]);
	decrypt(v, k);
	printf("解密后数据：%u %u\n", v[0], v[1]);
	return 0;
}