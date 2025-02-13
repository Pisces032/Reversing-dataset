#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void Decrypt(unsigned int* EntryData,int* Key)
{
    //分别加密数组中的前四个字节与后4个字节,4个字节为一组每次加密两组
    unsigned int x = EntryData[0];
    unsigned int y = EntryData[1];

    int sum = -(0x61C88647*32);   //注意这里,sum = 32轮之后的黄金分割值. 因为我们要反序解密.
    //总共加密32轮 那么反序也解密32轮
    for (int i = 0; i < 32; ++i)
    {

        // 先将y解开 然后参与运算在解x
        y -= ((x << 4) + Key[2]) ^ (x + sum) ^ ((x >> 5) + Key[3]);
        x -= ((y << 4) + Key[0]) ^ (y + sum) ^ ((y >> 5) + Key[1]);
        sum += 0x61C88647;
    }
    //最后加密的结果重新写入到数组中
    EntryData[0] = x;
    EntryData[1] = y;
}

int main()
{
    unsigned int enc[3] = { 0x42777AFA,0x781A30CA,0x0 };

    int key[4] = { 12,34,56,78 };

    //Encrypt每次只是加密4字节数组中的两组(也就是每次加密8个字节) 如果你数据多.可以来个for循环来循环加密,但是Entrypt内部还有32次循环,所以速度上还是会有点影响.
    Decrypt(enc, key);
    printf("解密后的数值 = %d %d", enc[0],enc[1]);
    system("pause");
}