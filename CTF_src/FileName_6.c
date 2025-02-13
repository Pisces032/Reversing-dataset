#include <stdio.h>
#include <stdint.h>

//���ܺ���
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

//���ܺ���
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
	// vΪҪ�ӽ��ܵ����ݣ�����32λ�޷�������
	uint32_t v[2] = { 1,2 };
	// kΪ�ӽ�����Կ��4��32λ�޷�����������Կ����Ϊ128λ
	uint32_t k[4] = { 1,2,3,4 };
	int n = sizeof(v) / sizeof(uint32_t);
	printf("����ǰԭʼ���ݣ�0x%x 0x%x\n", v[0], v[1]);
	encrypt(v, k);
	printf("���ܺ�����ݣ�0x%x 0x%x\n", v[0], v[1]);
	decrypt(v, k);
	printf("���ܺ�����ݣ�0x%x 0x%x\n", v[0], v[1]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizeof(uint32_t) / sizeof(uint8_t); j++)
		{
			printf("%c", (v[i] >> (j * 8)) & 0xFF);
		}
	}
	printf("\n");
	return 0;
}
