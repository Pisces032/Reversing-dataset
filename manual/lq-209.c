//ÌâÄ¿£º·­Ó²±Ò

#include<stdio.h>
#include<string.h>
int main(){
    char c1[1000],c2[1000];
    gets(c1);
    gets(c2);
    int i,a1[1000],a2[1000];
    int f = 0;
    for(i = 0; i < strlen(c1); i++){
        a1[i] = c1[i] == 'o'?1:-1;
        a2[i] = c2[i] == 'o'?1:-1;
    }
    for(int i = 0; i < strlen(c1); i++){
        if(a1[i] != a2[i]){
            a1[i] = a2[i];
            a1[i + 1] *= -1;
            f++; 
        }
    }
    printf("%d",f);
    return 0;
}

//xxxxxxxxxx
//ooxxxxxxxx
//oxoxxxxxxx
//


//oxxxxoxxxx 
//5