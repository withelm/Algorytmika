#include <cstdio>

const int LIMIT = 240;
int n, k, result;

int main()
{
    scanf("%d%d", &n, &k);
    k = LIMIT - k;

    for(int i = 1; i <= n; i++) {
        if (i * 5 <= k) {
            ++result;
            k -= i * 5;
        }
    }
    printf("%d", result);

}