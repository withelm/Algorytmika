#include <cstdio>

const int MX = 50 + 10;
int t[MX];
int n, k;
int result;

int main()
{
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    for(int i = 0; i < n; i++) {
        if (t[i] > 0 && t[i] >= t[k-1])
            ++result;
    }
    printf("%d", result);
}