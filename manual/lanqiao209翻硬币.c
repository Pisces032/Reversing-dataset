#include<stdio.h>
#include<string.h>
int main()
{
	int cnt=0,i;
	char s1[1000];
	char s2[1000];
	scanf("%s%s",&s1,&s2);
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]!=s2[i])
		{
			if(s2[i+1]=='*')
			s2[i+1]='o';
			else if(s2[i+1]=='o')
			s2[i+1]='*';
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
