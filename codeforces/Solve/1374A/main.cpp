#include <cstdio>

int x, y, n;
int t;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &y, &n);
        int x_mod = n % x;
        if (x_mod == y) {
            printf("%d\n", n);
        }
        if (x_mod < y) {
            printf("%d\n", n - x_mod - (x - y));
        }
        if (x_mod > y) {
            printf("%d\n", n - (x_mod - y));
        }
    }
}