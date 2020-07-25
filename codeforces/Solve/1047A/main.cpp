#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    if ((n - 2) % 3 != 0) {
        printf("1 1 %d", n - 2);
    } else {
        printf("1 2 %d", n - 3);
    }
}