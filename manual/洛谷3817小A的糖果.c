#include <stdio.h>
void main(){
	int n,x,a[1000],i,Delt=0,delt=0;
	scanf("%d%d",&n,&x);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(a[0]>x) {Delt=a[0]-x;a[0]-=delt;}
	for(i=1;i<n;i++)
	{
		if(a[i-1]+a[i]>x) 
		{delt=a[i-1]+a[i]-x;a[i]-=delt;Delt+=delt;}
	}
	printf("%d\n",Delt);
}
