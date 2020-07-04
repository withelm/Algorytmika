#include <cstdio>

int n;
int p,v,t;
int result;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d", &p,&v,&t);
        if (p+v+t > 1)
            ++result;
    }
    printf("%d", result);
    
}