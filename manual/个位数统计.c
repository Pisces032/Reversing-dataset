#include<stdio.h>
void main()
{
int a[10]={0};
int i,j;
j=getchar();
while(j!='\n')
	{a[j=j-48]++;
j=getchar();}
for(i=0;i<10;i++)
	if(a[i]!=0)
		printf("%d:%d\n",i,a[i]);
}