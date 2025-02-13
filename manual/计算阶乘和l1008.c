#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	scanf("%d",&a);
	for(;a>0;a--)
	{
		b=a;
		for(int i=1;i<a;i++)
		{
			b*=i;
		}
		c+=b;
	}
	printf("%d",c);
	return 0;
}
