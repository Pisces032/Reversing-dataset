#include<stdio.h>
#include<math.h>
int main(){
    int n,a;
    scanf("%d",&n);
    a=pow(2,n);
    printf("2^%d=%d",n,a);
    return 0;
}

/*
a.c: In function ¡®main¡¯:
a.c:5:5: warning: ignoring return value of ¡®scanf¡¯ declared with attribute ¡®warn_unused_result¡¯ [-Wunused-result]
    5 |     scanf("%d",&n);
      |     ^~~~~~~~~~~~~~
*/