#include <cstdio>

long long int a, b, k, t;

int main()
{
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld%lld", &a, &b, &k);
        printf("%lld\n", a * (k / 2) - b * (k / 2) + ( (k % 2 == 0) ? 0 : a ));
    }

}