#include <cstdio>

const int MX = 6 + 10 + 14;
int t, n;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if (n - MX > 0) {
            puts("YES");
            if (MX + 6 == n || MX + 10 == n || MX + 14 == n) {
                printf("6 10 15 %d\n", n - MX - 1);
            } else {
            printf("6 10 14 %d\n", n - MX);
            }
        } else {
            puts("NO");
        }
    }
}