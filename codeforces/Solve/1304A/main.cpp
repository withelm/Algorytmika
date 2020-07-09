#include <cstdio>

int t, x, y, a, b;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        
        y -= x;
        x = 0;

        if (y % (a + b) == 0) {
            printf("%d\n", y / (a + b));
        } else {
            puts("-1");
        }
    }
}