#include<stdio.h>
#include<stdint.h>
#define DELTA 0x9e3779b9
#define MX (((z>>5^y<<2)+(y>>3^z<<4))^((sum^y)+(key[(p&3)^e]^z)))
void btea(uint32_t* v, int n, uint32_t const key[4])
{
	uint32_t y, z, sum;
	unsigned p, rounds, e;
	if (n > 1)
	{
		rounds = 6 + 52 / n;	//�������˵��Ԥ����ֵ��n=2��rounds=32
		sum = 0;
		z = v[n - 1];
		do
		{
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p < n - 1; p++)        //ע�������p�Ǵ�0~n-1
			{
				y = v[p + 1];
				z = v[p] += MX;
			}
			y = v[0];
			z = v[n - 1] += MX;        //�����MX�д����p=n-1
		} while (--rounds);
	}
	else if (n < -1)
	{
		n = -n;
		rounds = 6 + 52 / n;
		sum = rounds * DELTA;
		y = v[0];
		do
		{
			e = (sum >> 2) & 3;
			for (p = n - 1; p > 0; p--)    //ע�������p�Ǵ�n-1~0,�������Ƿ�������
			{
				z = v[p - 1];
				y = v[p] -= MX;
			}
			z = v[n - 1];
			y = v[0] -= MX;    //�����MX�д���� p=0
			sum -= DELTA;
		} while (--rounds);
	}
}

int main()
{
	uint32_t v[2] = { 1,2 };
	uint32_t const k[4] = { 2,2,3,4 };
	int n = 2;
	printf("����ǰԭʼ���ݣ�%u %u\n", v[0], v[1]);
	btea(v, n, k);
	printf("���ܺ����ݣ�%u %u\n", v[0], v[1]);
	btea(v, -n, k);
	printf("���ܺ����ݣ�%u %u\n", v[0], v[1]);
	return 0;

}