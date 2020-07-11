#include <cstdio>
#include <algorithm>

using namespace std;

int q;
long long int t[3];
long long int alice;
long long int bob;
long long int last;

static inline long long int min(long long int a, long long int b)
{
    return a < b ? a : b;
}

static inline long long int max(long long int a, long long int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d", &q);
    while(q--) {
        scanf("%lld%lld%lld", t, t + 1, t + 2);
        sort(t, t + 3);

        alice = t[0];
        bob = t[1];
        last = t[2];
        if (bob - alice <= last) {
            last -= bob - alice;
            alice = bob;
            printf("%lld\n", alice + last / 2);
        } else {
            printf("%lld\n", alice + last);
        }
    }
}