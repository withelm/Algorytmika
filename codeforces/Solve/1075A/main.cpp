#include <cstdio>

long long int n, x, y;

long long int white, black;

int main()
{
    scanf("%lld%lld%lld", &n, &x, &y);
    white = x - 1 + y - 1;
    black = n - x + n - y;

    if (white <= black) {
        puts("White");
    } else {
        puts("Black");
    }
}