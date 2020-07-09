#include <cstdio>

int a, b, c, d;
int x, y, z;
int t;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d %d %d\n", b, c, c);
    }
}