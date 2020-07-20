#include <cstdio>
#include <algorithm>

using namespace std;

int q;
long long int n, a, b;

int main()
{
    scanf("%d", &q);
    while(q--) {
        scanf("%lld%lld%lld", &n, &a, &b);
        if (a*2 > b) {
            long long int result = (n / 2) * b;
            result += (n % 2) * a;
            printf("%lld\n", result);
        } else {
            printf("%lld\n", a * n);
        }
    }
}