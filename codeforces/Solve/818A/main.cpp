#include <cstdio>

long long int n, k, c, d;

int main()
{
    scanf("%lld%lld", &n, &k);
    c = n / (2 * (k + 1));
    d = c * k;
    printf("%lld %lld %lld", c, d, n - c - d);
}