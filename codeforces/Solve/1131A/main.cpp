#include <cstdio>

int h1,h2,w1,w2;

int main()
{
    scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
    if (w1 == w2) {
        printf("%d", 2 * w1 + 2 * (h1 + h2) + 4);
    } else {
        printf("%d", h1 + w1 + h1 + w1 - w2 + h2 + w2 + h2 + 4);
    }
}