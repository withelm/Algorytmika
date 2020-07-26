#include <cstdio>

int n, mod;

int main()
{
    scanf("%d", &n);
    mod = n % 10;
    if (mod <= 5) {
        n -= mod;
    } else {
        n += 10 - mod;
    }
    printf("%d", n);
}