#include<stdio.h>
#include<string.h>
int main(){
	int n,i;char c,a[1000];
	scanf("%d %c",&n,&c);
	getchar();
	gets(a);
	for (i=1;i<=(n-strlen(a));i++){
		printf("%c",c);
	}
	puts(a);
	return 0;
}