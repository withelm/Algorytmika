#include <cstdio>

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) 
        printf("%c", 'a' + (i % k));
}