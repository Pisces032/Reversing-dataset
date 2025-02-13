#include <stdio.h>
#include <string.h>

void rc4_init(unsigned char* s, unsigned char* key, unsigned long len)
{
	int i = 0;
	int j = 0;
	unsigned char k[256] = { 0 };
	unsigned char temp = 0;
	for (i = 0; i < 256; i++)
	{
		s[i] = i;         //0-255����s
		k[i] = key[i % len];   //��k���¼���
	}
	for (i = 0; i < 256; i++)
	{
		j = (j + s[i] + k[i]) % 256;    //��j��
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;    //s[i]��s[j]����
	}
}

void rc4_crypt(unsigned char* s, unsigned char* data, unsigned long len)
{
	int i = 0, j = 0, t = 0;
	unsigned long k = 0;
	unsigned char temp;
	for (k = 0; k < len; k++)
	{
		i = (i + 1) % 256;            //�̶���ʽ���ɵ�i
		j = (j + s[i]) % 256;          //�̶���ʽ���ɵ�j
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;             //����
		t = (s[i] + s[j]) % 256;      //�̶���ʽ���ɵ�t
		data[k] ^= s[t];          //�������
	}
}

int main()
{
	unsigned char s[256] = { 0 };
	char key[256] = "Flag{This_a_Flag}";
	char data[512] = {228,21,196,237,166,47,86,16,187,19,235,173,117,86,199,187,233,185,204,2,58,80,159,54,144,105,190,125,66,68,202,198,212,36,92,210,185,36,193,24,147,179,234};    //�ҵ����ɣ�С������(max117)��������ȥ256(min125)
	unsigned long len = strlen(data);
	rc4_init(s, (unsigned char*)key, len);//��ʼ���õ�s
	rc4_crypt(s, (unsigned char*)data, len);//����
	printf("���ܺ�Ϊ:%s", (unsigned char*)data);
	return 0;
}