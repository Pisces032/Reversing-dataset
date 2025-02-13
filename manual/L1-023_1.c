#include <stdio.h>
int main() {
    int n,a[1001],i,odd=0,even=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if (a[i]%2==1) odd++;
		else even++;
	}
	printf("%d %d",odd,even);
}