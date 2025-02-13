#include<stdio.h>
int main()
{
	int A,B,i,cishu=1;
	scanf("%d:%d",&A,&B);
	if(A>=00 && A<=11)
	{
		if(A<10&&B<10)printf("Only 0%d:0%d.  Too early to Dang.",A,B);
		if(A<10&&B>=10)printf("Only 0%d:%d.  Too early to Dang.",A,B);
		if(A>=10&&B<10)printf("Only %d:0%d.  Too early to Dang.",A,B);
		if(A>10&&B>10)printf("Only %d:%d.  Too early to Dang.",A,B);
	}
	if(A==12 && B==00)
		printf("Only %d:0%d.  Too early to Dang.",A,B);
	else for(i=12;i<=23;i++)
	{
		if(A==12)break;
		if(A==i && B==00)
		{
			cishu=A-12;
			for(i=0;i<cishu;i++)
				printf("Dang");
			break;
		}
		if(A>=13 && B!=00) 
		{
			cishu=A-11;
			for(i=0;i<cishu;i++)
		    	printf("Dang");
			break;
		}
	}
	return 0;
}
