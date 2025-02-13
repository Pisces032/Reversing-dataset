#include<stdio.h>
int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int b[10]={0,0,0,0,0,0,0,0,0,0};
	int c,d;
	scanf("%d",&c);
	for (int i=10;c>=1;i*=10)
	{
		d=c%10;
		for(int q=0;q<10;q++)
		{
			if (d==a[q])
			{
				b[q]++;
			}
		}
		c=c/10;
		
	}
	for (int p=0;p<10;p++)
	{
		if (b[p]!=0)
		{
			printf("%d:%d\n",a[p],b[p]);
		}
	}
	return 0;
}
