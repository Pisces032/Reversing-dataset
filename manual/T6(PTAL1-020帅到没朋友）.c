#include<stdio.h>
int main()
{
	int N,M,i,j,k,a[100][1000],b[10000],flag[10000]={0},t=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i][0]);
		for(j=1;j<a[i][0]+1;j++)
			scanf("%d",&a[i][j]);
		getchar();	
	}   //第一次输入 
	scanf("%d",&M);
	for(i=0;i<M;i++)
		scanf("%d",&b[i]);//第二次输入 
	for(i=0;i<N;i++)
		for(j=1;j<a[i][0]+1;j++)
			for(k=0;k<M;k++)
			{
				if(a[i][0]==1 && a[i][j]==b[k])break;
				if(a[i][j]==b[k])flag[k]++;//flag[k]表示有k个含二人及以上朋友圈 
			}
	for(i=0;i<M;i++)
		for(j=0;j<i;j++)
			if(b[i]==b[j])flag[i]++;//排除掉重复查询的人 
	for(i=0;i<M;i++)
		if(flag[i]==0)
		{
			if(i==M-1)
				{
					printf("%d",b[i]);
					t++;//t为帅到没朋友的人的数量 
				}
			else 
			{
				printf("%d ",b[i]);
				t++;
			}
		}
	if(t==0)printf("No one is handsome");
	return 0;
}
