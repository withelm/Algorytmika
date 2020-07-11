#include <cstdio>

int q, n;

int main()
{
    scanf("%d", &q);
    while(q--) 
    {
        scanf("%d", &n);
        if (n <= 4) {
            printf("%d\n", 4 - n);
        } else {
            printf("%d\n", n % 2);
        }
    }
}