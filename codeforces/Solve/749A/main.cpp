#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    printf("%d\n", n / 2);
    for(int i = 1; i < n / 2; i++) 
        printf("2 ");
    if (n % 2 == 0)
        printf("2");
    else
        printf("3");
    
}