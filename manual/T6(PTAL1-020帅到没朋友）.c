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
	}   //��һ������ 
	scanf("%d",&M);
	for(i=0;i<M;i++)
		scanf("%d",&b[i]);//�ڶ������� 
	for(i=0;i<N;i++)
		for(j=1;j<a[i][0]+1;j++)
			for(k=0;k<M;k++)
			{
				if(a[i][0]==1 && a[i][j]==b[k])break;
				if(a[i][j]==b[k])flag[k]++;//flag[k]��ʾ��k�������˼���������Ȧ 
			}
	for(i=0;i<M;i++)
		for(j=0;j<i;j++)
			if(b[i]==b[j])flag[i]++;//�ų����ظ���ѯ���� 
	for(i=0;i<M;i++)
		if(flag[i]==0)
		{
			if(i==M-1)
				{
					printf("%d",b[i]);
					t++;//tΪ˧��û���ѵ��˵����� 
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
