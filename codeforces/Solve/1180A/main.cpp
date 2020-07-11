#include <cstdio>

const int MX = 100 + 10;

int n, l;
int t[MX];

int main()
{
    scanf("%d", &n);
    t[1] = 1;
    l = 4;
    for(int i = 2; i < MX; i++) {
        t[i] = t[i - 1] + l;
        l += 4;
    }
    printf("%d", t[n]);
}