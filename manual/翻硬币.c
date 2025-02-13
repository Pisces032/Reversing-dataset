#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000
void flipAdjacent(char *coins, int index) {
    if (coins[index] == '*') {coins[index] = 'o';} 
	else {coins[index] = '*';}
    if (coins[index + 1] == '*') {coins[index + 1] = 'o';} 
	else {coins[index + 1] = '*';}
}
int minFlips(char *initial, char *target) {
    int length = strlen(initial);
    int steps = 0,i;
    char current[MAX_LENGTH];
    strcpy(current, initial);
    for (i = 0; i < length - 1; i++) {
        if (current[i]!= target[i]) {
            flipAdjacent(current, i);
            steps++;
        }
    }
    if (strcmp(current, target)!= 0) {
        return -1;
    }
    return steps;
}

int main() {
    char initial[MAX_LENGTH];
    char target[MAX_LENGTH];
	int result;
    scanf("%s", initial);
    scanf("%s", target);
    result = minFlips(initial, target);
    if (result == -1) {
        printf("无法达到目标状态\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}