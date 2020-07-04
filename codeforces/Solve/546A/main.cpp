#include <cstdio>

long long int k,n,w;

int main()
{
    scanf("%lld%lld%lld", &k, &n, &w);
    long long int sum = (k + (w * k)) * w / 2;
    if (sum - n > 0) 
        printf("%lld", sum - n);
    else 
        printf("0");
}