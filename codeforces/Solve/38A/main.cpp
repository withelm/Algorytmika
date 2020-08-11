#include <cstdio>

const int MX = 100 + 10;
int d[MX];
int n, a, b;
int result;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d", d + i);
    }
    scanf("%d%d", &a, &b);

    for(int i = a; i < b; i++) {
        result += d[i];
    }
    printf("%d\n", result);
}