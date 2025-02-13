//题目：别再来这么多猫娘了！！

#include<stdio.h>
#include<string.h>
void main(){
    char c[5000],st[100][10];
    int k = 0,N = 0,i = 0, p = 0, a = 0, n = 0;
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        gets(st[i]);
    }
    gets(c);
    
    for( int j = 0; j < 5000; j++){
        for(i = 0; i < N; i++){
            if(c[j] == st[i][0]){
                for(a = j,p = 1; p < sizeof(st[i] - 1); p++){
                    if(c[a] == st[i][p]) {
                        a++;
                    }
                    else break;
                }
                if(p == sizeof(st[i]) - 1){
                    for(int b = j; b < a; b++){
                        c[i]
                    }
                    n++;
                }
            }
        }
    }

    if(n >= k){
        printf("%d\nHe Xie Ni Quan Jia!\n",n);
    }
    else {
        for(int j = 0; j < 5000; j++){
            printf("%c",c[j]);
        }
    }
}

//替换字符怎么写