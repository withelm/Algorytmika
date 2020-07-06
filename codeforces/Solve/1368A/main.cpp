#include <cstdio>

long long int a, b, n;
int t;

int main()
{
    scanf("%d", &t);
    while(t--) {
        int result = 0;
        scanf("%lld%lld%lld", &a, &b, &n);
        while(a <= n && b <= n) {
            if (a < b) {
                a += b;
            } else {
                b += a;
            }
            ++result;
        }
        printf("%d\n", result);
    }
}