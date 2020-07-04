#include <cstdio>

int n, p, q, result;

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &p, &q);
        result += q - p >= 2;
    }
    printf("%d", result);
}