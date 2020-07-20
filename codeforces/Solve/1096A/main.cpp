#include <cstdio>

int t, x, y;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &x, &y);
        printf("%d %d\n", x, x + x);
    }
}