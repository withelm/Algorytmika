#include <cstdio>

int w, h, k, result;

int main()
{
    scanf("%d%d%d", &w, &h, &k);
    while(k--) {
        result += (2 * (w + h)) - 4;
        w -= 4;
        h -= 4;
    }
    printf("%d\n", result);
}