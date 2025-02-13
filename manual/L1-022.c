#include <stdio.h>
int main()
{
	int n,i,a[1000],m=0,k=0;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++){
		if (a[i]%2==0)k++;
		else m++;
	}
	printf("%d ",m);
	printf("%d",k);
	return 0;
}
