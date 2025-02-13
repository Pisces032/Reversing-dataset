#include<stdio.h>
int main(){
	int n,b[10],c[10],i;char a[10][4];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%s %d %d",a[i],&b[i],&c[i]);
	}
	for (i=0;i<n;i++){
		if (b[i]<15||b[i]>20||c[i]<50||c[i]>70)puts(a[i]);
	}
	return 0; 
}