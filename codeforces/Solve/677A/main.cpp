#include <cstdio>

int n, h, a, result;

int main()
{
    scanf("%d%d", &n, &h);
    while(n--) {
        scanf("%d", &a);
        ++result;
        result += a > h;
    }
    printf("%d", result);
}