#include<stdio.h>
#include<string.h>
int main(){
    char N[1001];
    int count[10]={0};
    scanf("%s",N);
    for(int i=0;N[i]!='\0';i++){
        count[N[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(count[i]>0){
            printf("%d:%d\n",i,count[i]);
        }
    }
    return 0;
}

//�����count[N[i]-'0']++;��-'0'�ĺ���