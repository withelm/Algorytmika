#include <cstdio>

int n, m;

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d%d", &n ,&m);
    if (min(n, m) % 2 == 0) {
        puts("Malvika");
    } else {
        puts("Akshat");
    }
}