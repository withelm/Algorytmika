#include <cstdio>

long long int n;

long long int calc(long long int n) 
{
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return 1;
    if (n % 4 == 3) return 0;
    return 0;    
}

int main()
{
    scanf("%lld", &n);
    printf("%lld", calc(n));
    
}