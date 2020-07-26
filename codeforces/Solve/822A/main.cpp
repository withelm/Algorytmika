#include <cstdio>
#include <algorithm>

using namespace std;

long long int a, b;

long long int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int main()
{
    scanf("%lld%lld", &a, &b);
    if (a > b) swap(a, b);
    printf("%lld", factorial(a));
}