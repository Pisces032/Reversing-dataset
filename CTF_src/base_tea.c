#include <stdio.h>
#include <stdint.h>
//解密函数
void decrypt(uint32_t* v, uint32_t* k) {
	uint32_t delta = 0x114514;
	uint32_t v0 = v[0], v1 = v[1], m;
	int sum = 32 * delta;
	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
	for (m = 0; m < 32; ++m) {
		v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
		v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		sum -= delta;
	}
	v[0] = v0; v[1] = v1;
}
int main()
{
	// v为要加解密的数据，两个32位无符号整数
	uint32_t v[10] = { 0x94B1F1E7, 0x21D5D352, 0x5247793D, 0x040D1C97, 0xF36E7F74, 0x9C53F70F, 0x6AEACFD8, 0x6F9F06F4,
	0xEAFD9E2E, 0x32B655F7 };
	// k为加解密密钥，4个32位无符号整数，密钥长度为128位
	uint32_t k[4] = { 0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF11 };
	int i, j;
	for (i = 0; i < 5; i ++)
	{
		decrypt(&v[i*2], k);
	}

	printf("%s",v); //BaseCTF{h3r3_4_cuP_0f_734_f0R_y0U!!!!!!}
}