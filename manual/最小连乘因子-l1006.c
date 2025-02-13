#include<stdio.h>
#include<math.h>
int main()
{
	int a,b[100]={0},c=1,m,n=0,v;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		if(a%i==0 && i!=1)
		{
			m=1;
			for(int p=i+1;p<=a;p++)
			{
				if (a%p==0)
				{
					m++;
					b[c-1]=p-1;
					b[c]=p;
					c++;
				}
				else
				{
					if (m>n)
					{
						n=m;
						v=c;
					}
					goto FLAG;
				}
			}
			//TODO
		}
		FLAG://TODO
	}
	printf("%d\n",n);
	for(;v<=v+n;v++)
	{
		printf("%d\n",b[v]);
	}
	return 0;
}
