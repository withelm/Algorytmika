#include <cstdio>

int n, m, z;

static inline int gcd(int a, int b)
{
    if (b != 0) return gcd(b, a % b);
    return a;
}

static inline int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}

int main()
{
    scanf("%d%d%d", &n, &m, &z);
    printf("%d", z / lcm(n, m));    
}