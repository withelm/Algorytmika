#include <cstdio>

int n,m;

int main()
{
    scanf("%d%d", &n, &m);
    int result = 0;
    int n_prime = n / 2;

    result += n_prime * m;
    if (n % 2 == 1) {
        result += m / 2;
    }
    printf("%d", result);
}