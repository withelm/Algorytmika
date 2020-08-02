#include <cstdio>

const char HASH = '#';
const char DOT = '.';

int n, m;

char solver(int x, int y)
{
    if (x % 2 == 0)
        return HASH;
    if (y == m - 1 && x % 4 == 1)
        return HASH;
    if (y == 0 && x % 4 == 3)
        return HASH;
    return DOT;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%c", solver(i, j));
        }
        puts("");
    }
}