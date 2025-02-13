#include<stdio.h>
int main(){
    int a[12]={0};
    int num=0;
    scanf("%d",&num);
    if(num==0)
        printf("ling\n");
    else{
        if(num<0){
            printf("fu ");
            num=-num;
        }
        int i=0;
        while(num>0){
            a[i++]=num%10;
            num/=10;
        }
    int j;
    for(j=i-1;j>=0;j--){
        switch(a[j]){
            case 0:printf("ling");break;
            case 1:printf("yi");break;
            case 2:printf("er");break;
            case 3:printf("san");break;
            case 4:printf("si");break;
            case 5:printf("wu");break;
            case 6:printf("liu");break;
            case 7:printf("qi");break;
            case 8:printf("ba");break;
            case 9:printf("jiu");break;
        }
        if(j>0)
            printf(" ");
    }
    }
    return 0;
}