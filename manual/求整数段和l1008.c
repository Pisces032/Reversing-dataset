#include<stdio.h>
int main()
{
	int a,b,sum=0,i=0;
	scanf("%d %d",&a,&b);
	if (a>b)
	{
		for(;b<=a;b++)
		{
			i++;
			if(i%5==0)
			{
				printf("\n");
			}
			printf("%d ",b);
			sum=sum+b;
		}
		printf("SUM = %d",sum);
	}
	else
	{
		for(;a<=b;a++)
		{	i++;
			if(i%5==0)
			{
				printf("\n");
			}
			printf("%d ",a);
			sum=sum+a;
		}
		printf("\nSUM = %d",sum);
		
	}
	
	return 0;
}
