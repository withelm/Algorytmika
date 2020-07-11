#include <cstdio>

int t, a, b, c, d, k;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);
        if (x + y > k) 
            puts("-1");
        else 
            printf("%d %d\n", x, y);
    }
}