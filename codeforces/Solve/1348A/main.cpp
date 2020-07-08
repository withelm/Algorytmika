#include <cstdio>

int t;
long long int n;

static inline long long int abs(long long int x) 
{
    return x > 0 ? x : -x;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        long long int all_sum = (1 << (n)) - 1 - 1;
        
        long long int half_sum = ((1 << ((n / 2))) - 1 - 1);
        all_sum -= half_sum;
        half_sum += 1 << n;
          
        
        printf("%lld\n", abs(all_sum - half_sum));
        
        
    }
}