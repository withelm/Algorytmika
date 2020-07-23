#include <cstdio>

int n, s;

int main()
{
    scanf("%d%d", &n, &s);
    printf("%d", s / n + (s % n != 0));
}