//题目：帅到没朋友
//结果错误+超时
#include<stdio.h>
int main(void){
    int N,a[100][1001],i,k,j;
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&k);
        a[i][0] = k;
        for(j = 1; j < k + 1; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int M,b[10000];
    scanf("%d",&M);
    for(i = 0; i < M; i++){
        scanf("%d",&b[i]);
    }
    int c[10000] = {0},t = 0, flag = 0, off = 0;
    for(int p =0; p < M; p++, flag = 0){
        for(i = 0; i < N; i++){
            if(a[i][0] == 1 && a[i][1] == b[p]){
                c[t++] = a[i][1];
                break;
            }
            for(j = 1; j < k + 1; j++){
                if(b[p] != a[i][j]) flag = 0;
                else {flag = 1; break;}
            }
            if(flag == 1) break;
        }
        if(flag == 0){
            for(int u = 0; u < t; u++){
            if(c[u] == b[p]) off =1;
            }
        }
        if(off == 1) continue;
        if(flag == 0 ) {
            c[t] = b[p];
            t++;
        }
    }

    if(t){
        for(i = 0; i < t; i++){
        printf("%d",c[i]);
        if((t - i)>1) printf(" ");
        }
    }
    else printf("No one is handsome");
}