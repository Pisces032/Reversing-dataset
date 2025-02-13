#include <stdio.h>
void main(){
	char a[1000],b[1000],i,k=0;
	gets(a);gets(b);
	for(i=0;a[i]!='0';i++){
		if(a[i]!=b[i]){
			k++;
			if(a[i]=='*') a[i]='o';
			else a[i]='*';
			if(a[i+1]=='*') a[i+1]='o';
			else a[i+1]='*';
		}
	}
	printf("%d\n",k);
}
