#include <cstdio>

int t, n, m;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        if (n == 1)
            puts("0");
        if (n == 2)
            printf("%d\n", m);
        if (n > 2)
            printf("%d\n", m * 2);
    }
}