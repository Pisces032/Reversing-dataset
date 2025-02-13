#include<stdio.h>
int main()
{
	int N,hangshu,lieshu,i,j;
	char C;
	scanf("%d %c",&N,&C);
	lieshu=N;
	if(N%2==0)hangshu=N/2;
	if(N%2!=0)hangshu =N/2+1;
	for(i=0;i<hangshu;i++)
		for(j=0;j<lieshu;j++)
		{
			printf("%c",C);
			if(j==lieshu-1)printf("\n");
		}
	return 0;
}
