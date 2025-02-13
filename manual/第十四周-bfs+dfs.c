#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 105
#define MAX_M 105
int max(int a, int b) {
    return a > b? a : b;
}
int in_matrix(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int matrix[MAX_N][MAX_M];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        int dp[MAX_N][MAX_M];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
            if (j > 0) {
                dp[0][j] = max(dp[0][j], dp[0][j - 1]);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = max(dp[i - 1][j], (j > 0? dp[i][j - 1] : 0));
                int pre_max = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int x = i + dx;
                        int y = j + dy;
                        if (in_matrix(x, y, n, m)) {
                            pre_max = max(pre_max, dp[x][y]);
                        }
                    }
                }
                dp[i][j] = max(dp[i][j], matrix[i][j] + pre_max);
            }
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[n - 1][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}