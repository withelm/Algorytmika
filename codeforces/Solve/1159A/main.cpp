#include <cstdio>

const int MX = 100 + 10;
int n, r;
char word[MX];

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d%s", &n, word);
    for(int i = 0; word[i]; i++) {
        if (word[i] == '+') {
            ++r;
        }
        if (word[i] == '-') {
            --r;
            r = max(r, 0);
        }
    }
    printf("%d", r);
}