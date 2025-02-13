#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#define MAX_LENGTH 1000

int isPositiveInteger(char *str) {
    int len = strlen(str),i,num;
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    num = atoi(str);
    if (num >= 1 && num <= 1000) {
        return 1;
    }
    return 0;
}

int main() {
    char inputA[MAX_LENGTH];
    char inputB[MAX_LENGTH];
    char *ptr = inputA;
    int flagA = 0, flagB = 0;
	int numA;int numB;
    char ch;
    while ((ch = getchar())!= '\n' && ch!= ' ') {
        *ptr++ = ch;
    }
    *ptr = '\0';
    ptr = inputB;
    while ((ch = getchar())!= '\n') {
        *ptr++ = ch;
    }
    *ptr = '\0';

    flagA = isPositiveInteger(inputA);
    flagB = isPositiveInteger(inputB);

    if (flagA) {
        printf("%s", inputA);
    } else {
        printf("?");
    }
    printf(" + ");
    if (flagB) {
        printf("%s", inputB);
    } else {
        printf("?");
    }
    printf(" = ");
    if (flagA && flagB) {
        numA = atoi(inputA);
        numB = atoi(inputB);
        printf("%d", numA + numB);
    } else {
        printf("?");
    }
    printf("\n");
    return 0;
}