#include <cstdio>

long long int n, k;
long long int div, mod;
int main()
{
    scanf("%lld%lld", &n, &k);

    div = n / k;
    mod = n % k;
    
    if (k == 1) {
        if (n % 2 == 0) {
            puts ("NO");
        } else {
            puts("YES");
        }
    } else if (mod == 0) {
        if (div % 2 == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        if (div % 2 == 1)
            puts("YES");
        else 
            puts("NO");
    }
}