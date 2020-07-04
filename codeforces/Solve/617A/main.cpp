#include <cstdio>

const int MX = 5;
const int t[MX] = {1, 2, 3, 4, 5};

int x;
int result;

int main()
{
    scanf("%d", &x);
    for (int i = MX - 1; i >= 0; i--) {
        if (x / t[i] > 0) {
            result += x / t[i];
            x %= t[i];
        }
    }
    printf("%d", result);
}