#include <cstdio>

const int DAY_LIMIT = 86400;

int n, t, result, a;

int main()
{
    scanf("%d%d", &n, &t);
    while(n--) {
        if (t <= 0) {
            printf("%d", result);
            return 0;
        }
        scanf("%d", &a);
        t -= DAY_LIMIT - a;
        ++result;
    }
    printf("%d", result);
}