#include<stdio.h>
int main()
{
	char enc[] = "`agh{^bvuwTooahlYocPtmyiijj|ek'p";
    char a9[16] = { 0 };
    char a8[16] = { 0 };
    char a7[16] = "4180387362590136";
    char a6[16] = "3092606632787947";
    char a5[32] = { 0 };
    char a4[16] = { 0 };
    char a3[16] = { 0 };
    char a2[16] = "7679621386735000";
    char a1[16] = "6329079420771558";
    char flag[32] = { 0 };
	int i, j, k, m;

    for (m = 0; m < 16; ++m)
    {
        a8[m] = enc[m + 16];
    }
    for (k = 0; k < 16; ++k)
    {
        a9[k] = enc[k];
    }
    for (j = 0; j < 16; ++j)
    {
        a9[j] ^= a7[16 - j];
    }
    for (i = 0; i < 16; ++i)
    {
        a8[i] ^= a6[16 - i];
    }
    for (m = 0; m < 16; ++m)
    {
        a9[m] ^= a6[16 - m];
    }
    for (k = 0; k < 16; ++k)
    {
        a8[k] ^= a7[16 - k];
    }
    for (j = 0; j < 16; ++j)
    {
        a9[j] ^= a7[j];
    }
    for (i = 0; i < 16; ++i)
    {
        a8[i] ^= a6[i];
    }
    for (m = 0; m < 16; ++m)
    {
        a9[m] ^= a6[m];
    }
    for (k = 0; k < 16; ++k)
    {
        a8[k] ^= a7[k];
    }
    for (j = 0; j < 16; ++j)
    {
        a5[j + 16] = a9[j];
    }
    for (i = 0; i < 16; ++i)
    {
        a5[i] = a8[i];
    }
    for (j = 0; j < 16; ++j)
    {
        a3[j] = a5[j + 16];
    }
    for (i = 0; i < 16; ++i)
    {
        a4[i] = a5[i];
    }
    for (m = 0; m < 16; ++m)
    {
        a4[m] ^= a2[16 - m];
    }
    for (k = 0; k < 16; ++k)
    {
        a3[k] ^= a1[16 - k];
    }
    for (j = 0; j < 16; ++j)
    {
        a4[j] ^= a1[16 - j];
    }
    for (i = 0; i < 16; ++i)
    {
        a3[i] ^= a2[16 - i];
    }
    for (m = 0; m < 16; ++m)
    {
        a4[m] ^= a2[m];
    }
    for (k = 0; k < 16; ++k)
    {
        a3[k] ^= a1[k];
    }
    for (j = 0; j < 16; ++j)
    {
        a4[j] ^= a1[j];
    }
    for (i = 0; i < 16; ++i)
    {
        a3[i] ^= a2[i];
    }
    for (m = 0; m < 16; ++m)
    {
        flag[m + 16] = a4[m];
    }
    for (k = 0; k < 16; ++k)
    {
        flag[k] = a3[k];
    }
    printf("%s", flag);
}