#include <cstdio>

int n;

int solver(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    int v = n / 3;
    return v * 2 + (n % 3 != 0);
}

int main()
{
    scanf("%d", &n);
    printf("%d", solver(n));
}