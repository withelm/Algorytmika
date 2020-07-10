#include <cstdio>

int t, a, b;

static inline int min(int x, int y)
{
    return x < y ? x : y;
}

static inline int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        int diff = max(a,b) - min(a,b);
        int result = diff / 5;
        diff %= 5;
        result += diff / 2;
        diff %= 2;
        result += diff;
        
        printf("%d\n", result);

    }
}