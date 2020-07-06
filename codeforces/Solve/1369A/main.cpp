#include <cstdio>

int t,n;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if (n % 4 == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}