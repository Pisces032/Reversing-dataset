#include<stdio.h>
int main(){
    int i,j,k,a,b,sum=0;
    scanf("%d %d",&a,&b);
    for(i=a,j=1;i<=b;i++,j++){
        printf("%5d",i);
        if(j%5==0){
            printf("\n");
        }
    }
    printf("\n");
    for(k=a;k<=b;k++)
        sum=sum+k;
    printf("Sum = %d",sum);
    return 0;
}

/*
PTA中说a.c: In function ‘main’:
a.c:4:5: warning: ignoring return value of ‘scanf’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
    4 |     scanf("%d %d",&a,&b);
      |     ^~~~~~~~~~~~~~~~~~~~
格式错？
*/