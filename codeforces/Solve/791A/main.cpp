#include <cstdio>

int a, b;
int n;

int main()
{
    scanf("%d%d", &a, &b);
    while (a <= b)
    {
        ++n;
        a *= 3;
        b *= 2;
    }
    printf("%d", n);
    
}