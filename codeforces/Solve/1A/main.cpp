#include <cstdio>

int n, m, a;

int main()
{
    scanf("%d%d%d", &n, &m, &a);

    long long int n_prime = n / a;
    if (n % a > 0)
        ++n_prime;
    long long int m_prime = m / a;
    if (m % a > 0)
        ++m_prime;

    printf("%lld", n_prime * m_prime);
}