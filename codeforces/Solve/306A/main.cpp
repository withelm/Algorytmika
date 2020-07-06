#include <cstdio>

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m - (n % m); i++)
        printf("%d ", n / m);
    for (int i = 0; i < n % m; i++)
        printf("%d ", n / m + 1);
}