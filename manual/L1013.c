#include <stdio.h>
int main() {
	int n,i,j;double s=0,a;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		for (j=1,a=1;j<=i;j++){
			a=a*j;
		}
		s=s+a;
	}
	printf("%.0f",s);
	return 0;
}