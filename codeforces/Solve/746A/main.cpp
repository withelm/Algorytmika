#include <cstdio>

int a, b, c, result;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    while(a >= 1 && b >= 2 && c >= 4) {
        result += 1 + 2 + 4;
        a -= 1;
        b -= 2;
        c -= 4;
    }
    printf("%d\n", result);
}