#include <cstdio>

int t, a, b;

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        int max_row = max (max(a, b), min(a, b) * 2) ; 
        printf("%d\n", max_row * max_row);
    }
}