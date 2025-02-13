#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 11
void bubbleSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int findIndex(int num, int sortedArr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        if (sortedArr[i] == num) {
            return i;
        }
    }
    return -1;  
}
int main() {
    char phoneNum[MAX_LENGTH];
	int i;
	int uniqueDigits[10];  
    int uniqueCount = 0;
	//int num = phoneNum[i] - '0';
    //int idx = findIndex(num, uniqueDigits, uniqueCount);
    int digitCount[10] = {0}; 
	scanf("%s", phoneNum); 
    for (i = 0; i < MAX_LENGTH; i++) {
        digitCount[phoneNum[i] - '0']++;
    }
    for (i = 0; i < 10; i++) {
        if (digitCount[i] > 0) {
            uniqueDigits[uniqueCount++] = i;
        }
    }

    bubbleSort(uniqueDigits, uniqueCount);

    printf("int[] arr = new int[]{");
    for (i = 0; i < uniqueCount; i++) {
        printf("%d", uniqueDigits[i]);
        if (i < uniqueCount - 1) {
            printf(",");
        }
    }
    printf("};\n");

    printf("int[] index = new int[]{");
    for (i = 0; i < MAX_LENGTH; i++) {
        int num = phoneNum[i] - '0';
        int idx = findIndex(num, uniqueDigits, uniqueCount);
        printf("%d", idx);
        if (i < MAX_LENGTH - 1) {
            printf(",");
        }
    }
    printf("};\n");

    return 0;
}