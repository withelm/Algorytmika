#include <cstdio>

int n, k, x, a, result;

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    for(int i = 0; i < n - k; i++) {
        scanf("%d", &a);
        result += a;
    }
    result += k * x;
    printf("%d\n", result);
}