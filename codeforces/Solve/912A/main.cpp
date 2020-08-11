#include <cstdio>
#include <algorithm>

using namespace std;

long long int a, b, x, y, z;
long long int yellow, blue;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &z);
    yellow += x * 2;
    yellow += y;
    blue += y;
    blue += 3 * z;

    a = max(0LL, yellow - a);
    b = max(0LL, blue - b);
    printf("%lld", a + b);
}