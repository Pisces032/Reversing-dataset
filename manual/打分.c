#include <stdio.h>
void main(){
	int n,sum=0,min,max,i,a[1000]={0};
	double average;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{scanf("%d",&a[i]);
	sum+=a[i];}
	max=min=a[0];
	for(i=0;i<n;i++)
		if(max<a[i]) max=a[i];
	for(i=0;i<n;i++)
		if(min>a[i]) min=a[i];
	sum=sum-max-min;
	average=1.0*sum/(n-2);
	printf("%.2lf\n",average);
	getchar();
	getchar();
}