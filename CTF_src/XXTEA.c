#include<stdio.h>
#include<stdint.h>
#define DELTA 0x933779b9
#define MX (((z>>5^y<<2)+(y>>3^z<<4))^((sum^y)+(key[(p&3)^e]^z)))
void btea(uint32_t* v, int n, uint32_t const key[4])
{
	uint32_t y, z, sum;
	unsigned p, rounds, e;
	if (n > 1)
	{
		rounds = 6 + 52 / n;	//这里可以说是预定义值，n=2是rounds=32
		sum = 0;
		z = v[n - 1];
		do
		{
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p < n - 1; p++)        //注意这里的p是从0~n-1
			{
				y = v[p + 1];
				z = v[p] += MX;
			}
			y = v[0];
			z = v[n - 1] += MX;        //这里的MX中传入的p=n-1
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
			for (p = n - 1; p > 0; p--)    //注意这里的p是从n-1~0,和上面是反过来的
			{
				z = v[p - 1];
				y = v[p] -= MX;
			}
			z = v[n - 1];
			y = v[0] -= MX;    //这里的MX中传入的 p=0
			sum -= DELTA;
		} while (--rounds);
	}
}

int main()
{
	uint32_t v[2] = { 1,2 };
	uint32_t const k[4] = { 2,2,3,4 };
	int n = 2;
	printf("加密前原始数据：%u %u\n", v[0], v[1]);
	btea(v, n, k);
	printf("加密后数据：%u %u\n", v[0], v[1]);
	btea(v, -n, k);
	printf("解密后数据：%u %u\n", v[0], v[1]);
	return 0;

}