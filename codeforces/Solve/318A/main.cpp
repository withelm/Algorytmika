#include <cstdio>

long long int k, n;

int main()
{
    scanf("%lld%lld", &n, &k);
    if (n % 2 == 0) {
        if ( k <= n / 2) {
            printf ("%lld", k * 2 - 1);
        } else {
            printf ("%lld", 2 * (k - (n / 2)) );
        }
    } else {
        if ( k  <= n / 2 + 1) {
            printf ("%lld", k * 2 - 1);
        } else {
            printf ("%lld", 2 * (k - (n / 2) - 1) );
        }
    }
}