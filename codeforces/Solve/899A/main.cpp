#include <cstdio>

const int MX = 2 + 10;

int t[MX];
int n, a;
int result;

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        ++t[a];
    }

    if (t[1] >= t[2]) {
        result = t[2];
        result += (t[1] - t[2]) / 3;
    } else {
        result = t[1];
    }
    printf("%d", result);
}