#include <stdio.h>
int main() {
	int n,a,b[10]={0},i;
	scanf("%d",&n);
	while (n!=0){
		a=n%10;
		n=(n-a)/10;
		switch(a){
			case 0:b[0]++;break;
			case 1:b[1]++;break;
			case 2:b[2]++;break;
			case 3:b[3]++;break;
			case 4:b[4]++;break;
			case 5:b[5]++;break;
			case 6:b[6]++;break;
			case 7:b[7]++;break;
			case 8:b[8]++;break;
			case 9:b[9]++;break;
		}
	}	
	for (i=0;i<10;i++){
		if (b[i]!=0) printf("%d:%d\n",i,b[i]);
	}
	return 0;
}