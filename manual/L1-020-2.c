//正确的2.0版本
#include <stdio.h>
int main(){
	int a[100000]={0};
	int n,i,m,p,k,t=1,j,f=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++){
			scanf("%d",&p);
			if(m!=1){
				a[p]++;	
			}
		}
	}
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d",&p);
		if(a[p]==0){
			if(f==1){
				printf("%05d",p);
				f=0;
			}else{
				printf(" %05d",p);
			}
			a[p]--;
			t=0;
		}
	}
	if(t){
		printf("No one is handsome");
	}
}
