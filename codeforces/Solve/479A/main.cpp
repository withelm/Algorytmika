#include <cstdio>

int a, b, c;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d%d%d",&a, &b, &c);
    printf("%d", 
        max(a+b+c,
        max(a+b*c, 
        max(a*b*c,
        max(a*(b+c), (a+b)*c))))
    );
}