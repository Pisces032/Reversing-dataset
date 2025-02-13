#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char rus[38] = "§ß§Ö§é§Ö§Ô§à§ß§Ö§é§Ö§Ô§à§ß§Ö§é§Ö§Ô§à";//37
	char key2[26] = "+i&[@Y:g8[&l$f8S8v$Y&e>{";//25
	char key1[38] = { 0 };//37
	char flag[26] = { 0 };
	for (i = 0; i <= strlen(rus); ++i)
		key1[i] = rus[i] - 114;
	printf("%s   %d", key1, strlen(key1));//5m5d5w5d5b5n5m5d5w5d5b5n5m5d5w5d5b5n 37
	for (i = 0; i <= strlen(key2); ++i)
		flag[i] = key2[i] - key1[i] + 112;
	printf("%s", flag);//flag{Russian_is_so_easy}
	return 0;
}