#include <cstdio>

long long int n;
int t;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        printf("%lld\n", (n - 1) / 2);
    }
}