#include<stdio.h>
int main()
{
	int A,B,Sum=0,i,flag=0;
	scanf("%d%d",&A,&B);
	for(i=A;i<=B;i++)
	{
		Sum+=i;
		printf("%5d",i);
		flag++;
		if(flag==5)
		{
			if(i==B)continue;
			flag=0;
			printf("\n");
		}
	}
	printf("\nSum = %d",Sum);
	return 0;
	
}
