#include <cstdio>

const int MX = 1e4 + 100;
int t[MX];
int n;
int result;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
    }
    for(int i = 1; i < n - 1; i++) {
        if (t[i - 1] < t[i] && t[i] > t[i + 1])
            ++result;
        if (t[i - 1] > t[i] && t[i] < t[i + 1])
            ++result;
    }
    printf("%d\n", result);
} 