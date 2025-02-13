#include<stdio.h>
#include<math.h>
int main(){
	int n,i,a[100000],j,k=1;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++){
		for (j=2;j<sqrt(a[i]);j++){
			if (a[i]%j==0){k=0;break;}
		}
		if (k==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}