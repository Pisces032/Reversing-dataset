#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void Decrypt(unsigned int* EntryData,int* Key)
{
    //�ֱ���������е�ǰ�ĸ��ֽ����4���ֽ�,4���ֽ�Ϊһ��ÿ�μ�������
    unsigned int x = EntryData[0];
    unsigned int y = EntryData[1];

    int sum = -(0x61C88647*32);   //ע������,sum = 32��֮��Ļƽ�ָ�ֵ. ��Ϊ����Ҫ�������.
    //�ܹ�����32�� ��ô����Ҳ����32��
    for (int i = 0; i < 32; ++i)
    {

        // �Ƚ�y�⿪ Ȼ����������ڽ�x
        y -= ((x << 4) + Key[2]) ^ (x + sum) ^ ((x >> 5) + Key[3]);
        x -= ((y << 4) + Key[0]) ^ (y + sum) ^ ((y >> 5) + Key[1]);
        sum += 0x61C88647;
    }
    //�����ܵĽ������д�뵽������
    EntryData[0] = x;
    EntryData[1] = y;
}

int main()
{
    unsigned int enc[3] = { 0x42777AFA,0x781A30CA,0x0 };

    int key[4] = { 12,34,56,78 };

    //Encryptÿ��ֻ�Ǽ���4�ֽ������е�����(Ҳ����ÿ�μ���8���ֽ�) ��������ݶ�.��������forѭ����ѭ������,����Entrypt�ڲ�����32��ѭ��,�����ٶ��ϻ��ǻ��е�Ӱ��.
    Decrypt(enc, key);
    printf("���ܺ����ֵ = %d %d", enc[0],enc[1]);
    system("pause");
}