#include<stdio.h>
int main()
{
	int a,b,i,c,k=0,sum=0;
	scanf("%d%d",&a,&b);
	for(i=b-a;i>=0;i--)
	{c=b-i;
	printf("%5d",c);
	k++;
	if(k==5)
	{
		printf("\n");
		k=0;            //控制每行数字个数
	}
	sum=sum+c;
	}
	printf("\n");
	printf("Sum=%d",sum);
	return 0;
}
