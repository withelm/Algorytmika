#include <cstdio>

int t, x, n;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &x);
        printf("%d\n", 2 * x);
    }
}