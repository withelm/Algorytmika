#include <cstdio>
#include <algorithm>


int a, b, v, result;

static inline int sum(int n)
{
    return (1 + n) * n / 2;
}

int main()
{
    scanf("%d%d", &a, &b);
    
    if (a > b) std::swap(a, b);

    v = b - a;
    result = sum(v / 2);
    result += sum(v / 2 + (v % 2));
    printf("%d", result);
}