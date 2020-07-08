#include <cstdio>

int t, n, m;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        int result = (n / 2) * m;
        if (n % 2 == 1) {
            result += m / 2 + m % 2;
        }
        printf("%d\n", result);
    }
}