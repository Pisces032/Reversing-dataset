#include <stdio.h>
#include <string.h>
int main() {
	char a[1000]={0},b[1000]={0};
	int i,k=0;
	gets(a);
	gets(b);
	for (i=0;i<strlen(a)-1;i++){
		if (a[i]!=b[i]){
			a[i]=b[i];
			if (a[i+1]=='o')
				a[i+1]='*';
			else a[i+1]='o';
			k++;
		}
	}
	printf("%d\n",k);
	return 0;
}