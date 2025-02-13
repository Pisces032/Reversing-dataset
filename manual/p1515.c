//ÌâÄ¿£º ÂÃÐÐ
#include<stdio.h>
 
int dis[40]={0,990,1010,1970, 2030, 2940, 3060,3930, 4060, 4970, 5030, 5990, 6010, 7000};
int ans[40];
 
void qsort(int a[],int l,int r){
	int temp;
	int mid=a[(l+r)/2];
	int i=l;
	int j=r;
	while(i<=j){
		while(a[i]<mid)i++;
		while(a[j]>mid)j--;
		if(i<=j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(i<r)qsort(a,i,r);
	if(j>l)qsort(a,l,j);
}
int main(){
	int a,b,n;
	int m;
	int k=14;
	scanf("%d %d",&a,&b);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		dis[k++]=m;
	}
	qsort(dis,0,k-1);
	ans[0]=1;
	for(int i=1;i<=k-1;i++){
		for(int j=0;j<i;j++){
			if(dis[i]-dis[j]>=a&&dis[i]-dis[j]<=b){
				ans[i]+=ans[j];
			}
		}
	}
	printf("%d\n",ans[k-1]);
}