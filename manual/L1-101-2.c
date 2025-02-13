#include<stdio.h>
#include<string.h>
void main(){
    char c[5000],st[100][10];
    int k = 0,N = 0,i = 0, n = 0,t = 0;
    int*m = &n;
    int*q = &t;
    char *strrpl(char *str, char *old, char *new,int*m,int*q);
    scanf("%d",&N);
    getchar();
    for(i = 0; i < N; i++){
        gets(st[i]);
    }
    scanf("%d",&k);
    getchar();
    gets(c);

    for(i  = 0; i < N; i++){
        for(t = 0;t == 0;){
            strrpl(c, st[i], "<censored>",m,q);
        }
    }

    if(n >= k){
        printf("%d\nHe Xie Ni Quan Jia!",n);
    }
    else {
        for(int j = 0; j < strlen(c); j++){
            printf("%c",c[j]);
        }
    }


}  

char *strrpl(char *str, char *old, char *new,int *m,int *q)
{
	char *p = NULL;
	int len = 0;
	char newstr[10000] = {0};

	p = strstr(str,old);
    if(p != NULL){
        len =  p - str;
	    strncpy(newstr, str, len);
	    strcat(newstr, new);
	    strcat(newstr,p+strlen(old));
	    strcpy(str,newstr);
        *m = *m + 1;
        *q = 0;
    }
    else *q = 1;

	return str;
}