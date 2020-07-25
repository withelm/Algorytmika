#include <cstdio>

long long int t, s, a, b, c;

int main()
{
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
        long long int result = s / c;
        result += ((s / c) / a) * b;
        printf("%lld\n", result);
    }
}