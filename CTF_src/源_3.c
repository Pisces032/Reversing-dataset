#include <stdio.h>
#include <stdint.h>

//解密函数
void decrypt(uint32_t* v, uint32_t* k) {
	uint32_t v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i;
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
	// v为要加解密的数据，两个32位无符号整数
	uint32_t v[2] = { 0x284C2234,0x3910C558 };
	// k为加解密密钥，4个32位无符号整数，密钥长度为128位
	uint32_t k[4] = { 0x65736162,0x6F783436,0x61657472,0x61657478 };
	int n = sizeof(v) / sizeof(uint32_t);
	decrypt(v, k);
	printf("解密后的数据：0x%x 0x%x\n", v[0], v[1]);

	printf("\n");
	return 0;
}
//moectf{836153a5-8e00-49bd-9c42-caf30620caaf}