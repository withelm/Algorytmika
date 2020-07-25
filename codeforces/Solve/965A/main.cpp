#include <cstdio>

int k, n, s, p;

int main()
{
    scanf("%d%d%d%d", &k, &n, &s, &p);
    int ns = n / s + (n % s != 0);
    printf("%d\n", (ns * k) / p + ((ns * k) % p != 0));
}