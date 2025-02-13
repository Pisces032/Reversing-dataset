#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h> 

char* encode(char *a1, int a2, int a3) {
    char *flag = (char*)malloc(a2 + 1);
    for(int i = 0; i < a2; i++) {
        flag[i] = a1[i] ^ a3;
    }
    flag[a2] = '\0';
    return flag;
} 

int main() {
    char str[] = "pi|}{mksq8}W`i~;Wn8}flW|`;W=mkzm|W8nWp8zu";
    int len = strlen(str);
    int xxorr = 8;
    char *flag = encode(str, len, xxorr);
    char input[100];
    printf("please input your flag£º");
    scanf("%s", input);
    char *result = encode(input, len, xxorr);
    if(strcmp(result, str) == 0)
        printf("right flag!\n");
    else
        printf("²Ë¾Í¶àÁ·\n"); 
    free(flag);
    free(result);
     system("pause");
}

