#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
    char v4[20]; // [rsp+20h] [rbp-60h] BYREF
    char s[224];
    char Str[104] = { 0 }; // [rsp+100h] [rbp+80h] BYREF
    int v6; // [rsp+168h] [rbp+E8h]
    int i; // [rsp+16Ch] [rbp+ECh]
    strcpy(s, "]P_ISRF^PCY[I_YWERYC");
 
    v6 = 20;
  
    for (i = v6 - 1; i >= 0; --i)
         v4[i ]= s[v6 - i - 1];

    for (i = 0; i < v6; ++i)
    {
        if (v4[i] == 89 || v4[i] == 67)
            v4[i] = 155 - v4[i];
    }
    for (i = 0; i < v6; ++i)
            Str[i] = v4[i] ^ 17;
    printf("%s\n", v4);
    printf("%s", Str);
    return 0;
}