#include <cstdio>

int n, a, b;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            b = n / i;
        }
    }
    printf("%d %d", a, b);
}