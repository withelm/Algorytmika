#include <cstdio>

const int MX = 100 + 10;

int t[MX];
int n, m;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        t[m] = i;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", t[i]);
    }
}