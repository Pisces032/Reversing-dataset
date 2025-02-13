#include <stdio.h>
int main() {
	int n,m,i,j;int b[1000][2],c[1000];char a[1000][17];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%s%d%d",a[i],&b[i][0],&b[i][1]);
	}
	scanf("%d",&m);
	for (j=0;j<m;j++){
		scanf("%d",&c[j]);
	}
	for (j=0;j<m;j++){
		for (i=0;i<n;i++){
			if (b[i][0]==c[j]) printf("%s %d\n",a[i],b[i][1]);
		}
	}
	return 0;
}