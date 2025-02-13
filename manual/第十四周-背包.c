#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_T 1001
#define MAX_M 101
int max(int a, int b) {
    return a > b? a : b;
}
int main() {
    int T, M;
    scanf("%d %d", &T, &M);
    int time[MAX_M];
    int value[MAX_M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &time[i], &value[i]);
    }
    int dp[MAX_M][MAX_T];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = max(dp[i - 1][j], (j >= time[i - 1]? dp[i - 1][j - time[i - 1]] + value[i - 1] : 0));
        }
    }
    printf("%d\n", dp[M][T]);
    return 0;
}