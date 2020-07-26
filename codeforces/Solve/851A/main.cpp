#include <cstdio>

int n, k ,t;

static inline int solver(int n, int k, int t)
{
    if (t < k) {
        return t;
    }
    if (t >= k && t <= n) {
        return k;
    }
    if (t > n && t <= n + k) {
        return n + k - t;
    }
    return 0;
}

int main()
{
    scanf("%d%d%d", &n, &k, &t);

    printf("%d", solver(n, k, t));
}