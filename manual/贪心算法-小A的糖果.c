#include <stdio.h>
int main() {
	long long n,x,a[100001]={0},ans=0;
	scanf("%lld%lld",&n,&x);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]+a[i-1]>x){
			ans+=a[i]+a[i-1]-x;
			a[i]=a[i]-(a[i-1]+a[i]-x);
		}
	}
	printf("%lld",ans);
	return 0;
}