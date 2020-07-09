#include <cstdio>

int t, a, b;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        if (a == 1 || b == 1 || (a == 2 && b == 2)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}