#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000];int i;
	gets(s);
	for (i=0;i<strlen(s)-1;i++){
		printf("%c\n",s[i]);
	}
	printf("%c",s[i]);
	return 0;
}
