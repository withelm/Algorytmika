#include <cstdio>

int t, a, b;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", (b - (a % b)) % b );
    }
}