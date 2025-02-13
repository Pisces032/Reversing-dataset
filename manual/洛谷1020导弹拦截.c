#include <stdio.h>
void main(){
	int a[1000],h[1000],i=0,j,d,x,k=1,p;
	while(scanf("%d",&x)==1){
		a[i]=x;i++;}
	h[0]=a[0];
	for(d=1;d<i;d++){
		p=0;
		for(j=0;j<k;j++)
			if(h[j]>=a[d]){
				if(p==0) p=j;
				else if(h[j]<h[p])p=j;
			}
			if (p==0) {h[k]=a[d];k++;}
			else h[p]=a[d];
	}
	printf("%d\n",k);
}
