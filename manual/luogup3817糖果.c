#include<stdio.h>

int main()
{
    int sum=0,n,x,i;
	long long int a[n];
	scanf("%d%d",&n,&x);
	scanf("%d",&a[0]);
	if(a[0]>x)      //�����һ����������
	{
		sum=sum+a[0]-x; //���ӳԵ���
		a[0]=x;//a[i]>=x,Ҫ�Ե����٣�����a[i]=x;
	}
	for(i=1;i<=n;i++)
	{   
	    scanf("%d",&a[i]);
		if(a[i]+a[i-1]>x)
		{
		    sum+=a[i]+a[i-1]-x;
		    a[i]=x-a[i-1];
		}
	}
	printf("%d",sum);
	return 0;
}
