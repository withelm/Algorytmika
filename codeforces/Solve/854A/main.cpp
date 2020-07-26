#include <cstdio>

int n;
int a, b;

static inline int gcd(int a, int b)
{
    if (b != 0) return gcd(b, a % b);
    return a;
}

int main()
{
    scanf("%d", &n);
    a = n / 2;
    b = n / 2 + (n % 2);
    while(gcd(a, b) != 1) {
        --a;
        ++b;
    }
    printf("%d %d", a, b);
}