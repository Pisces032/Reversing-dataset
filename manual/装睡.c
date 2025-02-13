#include <stdio.h>
#include <string.h>
struct Name{char a[10];int b,c;}p[11];
int main(){
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
		scanf("%s %d %d",p[i].a,&p[i].b,&p[i].c);
	for(i=0;i<n;i++)
		if(p[i].b>20||p[i].b<15||p[i].c<50||p[i].c>70) printf("%s\n",p[i].a);
	getchar();
	getchar();
}