#include <cstdio>

int w;

int main()
{
    scanf("%d", &w);
    if (w > 3 && w%2 == 0)
        printf("YES");
    else 
        printf("NO");
}