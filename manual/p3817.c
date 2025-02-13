//题目：小A的糖果
#include<stdio.h>
int main() {
    long long n, x, a[100001] = {0}, b = 0;
    scanf("%lld%lld",&n, &x);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] + a[i - 1] > x) {
            b += a[i] + a[i - 1] - x;
            a[i] = a[i] - (a[i - 1] + a[i] - x);
        }
    }
    printf("%lld", b);
    return 0;
}