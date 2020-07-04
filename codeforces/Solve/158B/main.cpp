#include <cstdio>

const int MX = 10;
int t[MX];

int n, s;
int result;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &s);
        ++t[s];
    }
    result += t[4];
    result += t[3];
    t[1] = max(t[1] - t[3], 0);
    result += t[2] / 2;
    t[2] = t[2] % 2;

    if (t[2] == 1) {
        ++result;
        t[2] = 0;
        t[1] = max(t[1] - 2, 0);
    }
    result += t[1] / 4;
    if (t[1] % 4 > 0)
        ++result;
    printf("%d", result);

}