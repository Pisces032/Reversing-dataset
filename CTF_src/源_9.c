#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t data1 = 0x5F797274;
uint32_t data2 = 0x64726168; //初始的data 值

void encrypt(uint32_t* v, uint32_t* k) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0, i;
    data1 ^= v0;
    data2 ^= v1;
    v0 = data1;
    v1 = data2;
    uint32_t delta = 0x6e75316c;
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
    for (i = 0; i < 32; i++)
    {
        sum += delta;
        v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1) ^ (sum + i);
        v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3) ^ (sum + i);
    }
    data1 = v0;
    data2 = v1;
}


void decrypt(uint32_t* v, uint32_t* k)
{
    uint32_t delta = 0x6e75316c;
    uint32_t v0 = v[0], v1 = v[1], sum = (delta * 32) & 0xffffffff, i;
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
    for (i = 0; i < 32; i++)
    {
        v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3) ^ (sum + (31 - i));
        v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1) ^ (sum + (31 - i));
        sum -= delta;
    }
    v0 = v0 ^ data1;
    v1 = v1 ^ data2;
    v[0] = v0; v[1] = v1;
}


int main()
{
    uint32_t array[] = { 0x9b28ed45, 0x145ec6e9, 0x5b27a6c3, 0xe59e75d5, 0xe82c2500, 0xa4211d92, 0xcd8a4b62, 0xa668f440 };
    uint32_t key[4] = { 0x65766967, 0x756F795F, 0x7075635F, 0x6165745F };
    for (int i = 0; i < 8; i += 2)
    {
        uint32_t temp[2];
        temp[0] = array[i];
        temp[1] = array[i + 1];
        decrypt(temp, key);

        printf("%c%c%c%c%c%c%c%c", *((char*)&temp[0] + 0), *((char*)&temp[0] + 1), *((char*)&temp[0] + 2), *((char*)&temp[0] + 3), *((char*)&temp[1] + 0), *((char*)&temp[1] + 1), *((char*)&temp[1] + 2), *((char*)&temp[1] + 3));
        //更新data
        encrypt(temp, key);
    }
    return 0;
}