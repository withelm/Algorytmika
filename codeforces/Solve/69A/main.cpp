#include <cstdio>

int n;
int x, y, z;
int a, b, c;

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d", &x, &y, &z);
        a += x;
        b += y;
        c += z;
    }
    if (a == b && b == c && a == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
}