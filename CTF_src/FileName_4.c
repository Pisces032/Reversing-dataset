#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void Decrypt(uint32_t* data, uint32_t* key)
{
    uint32_t v0 = data[0], v1 = data[1];
    uint32_t delta = 2654435769;
    uint32_t sum = delta * 32; //反过来最后一次的sum，循环32次

    for (int i = 0; i < 32; i++)
    {
        v1 -= ((v0 << 4) + key[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key[3]);
        v0 -= ((v1 << 4) + key[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key[1]);
        sum -= delta;
    }

    data[0] = v0;
    data[1] = v1;
} //解密函数

int main()
{
    uint32_t encryptedData[] = 
    { 3363017039,1247970816,549943836,445086378,
      3606751618,1624361316,3112717362,705210466,
      3343515702,2402214294,4010321577,2743404694 };  //12个
    uint32_t key[] = { 286331153,286331153,286331153,286331153 };

    for (int i = 0; i < 12; i += 2)   
    {
        Decrypt(&encryptedData[i], key);
    }

    printf("%s", encryptedData);

    return 0;
}